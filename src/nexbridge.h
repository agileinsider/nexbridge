#ifndef __NEXBRIDGE_H__
#define __NEXBRIDGE_H__

#include <syslog.h>
#include <stdio.h>

typedef struct {
	int is_daemon;
	int server_port;
	char tty_port[255];
	char address[255];
	char svc_name[255];
	int timeout;
	int max_conn;
} config;

extern config conf;

#define LOG(msg, ...) \
	{ if(conf.is_daemon) { \
		openlog("svcdd",LOG_PID,LOG_DAEMON);\
		syslog(LOG_INFO,msg, ## __VA_ARGS__);\
		closelog();\
	} else { \
		fprintf(stderr,"LOG: ");\
		fprintf(stderr, msg,  ## __VA_ARGS__);\
		fprintf(stderr,"\n");\
	}}\


#define LOG_DBG(msg, ...) \
	{ if(conf.is_daemon) { \
		openlog("svcdd",LOG_PID,LOG_DAEMON); \
		syslog(LOG_DEBUG,msg, ## __VA_ARGS__); \
		closelog(); \
	} else { \
		fprintf(stderr,"DBG: ");\
		fprintf(stderr, msg,  ## __VA_ARGS__);\
		fprintf(stderr,"\n");\
	}}\
	
#endif /*__NEXBRIDGE_H__*/