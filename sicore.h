#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <error.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <net/if.h> 
#include <resolv.h>

#ifndef SIRIK_DISCORE_H
#define SIRIK_DISCORE_H

#define SI_STREAM_STRUCT_SIZE				1024
#define LOG_MEDIA_LOWER_LIMIT   1
#define LOG_MEDIA_FILE          1
#define LOG_MEDIA_CONSOLE       2
#define LOG_MEDIA_IDE           3
#define LOG_MEDIA_NEW_CONSOLE   4
#define LOG_MEDIA_UPPER_LIMIT   4

#define SI_LOG_LOWER_LIMIT   1
#define SI_LOG_CRITICAL      1
#define SI_LOG_ERROR         2
#define SI_LOG_WARNING       3
#define SI_LOG_INFO          4
#define SI_LOG_NORMAL        4
#define SI_LOG_DEBUG         5
#define SI_LOG_UPPER_LIMIT   5

#define SI_STK_LOG      	0
#define SI_PER_LOG      	1
#define SI_APP_LOG      	2
#define SI_BUF_LOG1      	3
#define SI_CUS_LOG2      	4
#define SI_CUS_LOG3      	5

typedef struct __si_asn_coding_context
{
	uint8_t buffer[2000];
	uint16_t pos;
	uint16_t len;
	uint8_t usedBits;
	uint16_t ieStartPos;
	uint16_t ieLastLen;
	uint32_t iError;
	
	int16_t ieMaxReadBytes;
	int16_t ieCurrPos;
} SI_ASN_CodingContext;

void __si_asn_memset( SI_ASN_CodingContext * context);

void __si_log( uint32_t mLogType, uint32_t mLogCat, uint32_t mLogLevel, char* mLogMessage, ...);
typedef struct __si_ngap_node SI_NGAPNode;
typedef void (*fp_ngap_app_messahe_handler)( uint8_t procedureCode, uint8_t messageType, void * msg, SI_NGAPNode * ngNode);
void __si_ngap_set_app_messahe_handler( fp_ngap_app_messahe_handler handler);

uint8_t * __si_allocM( size_t size);
void __si_freeM( uint8_t * ptr);

typedef struct __si_linked_list SI_LinkedList;
void __si_linked_list_add( SI_LinkedList *, uint8_t *);
uint64_t __si_core_getU64RANDRange( uint64_t min, uint64_t max);
void __si_core_fill_dummy_data( unsigned char * data, int len);
void __si_print_buffer( char * buff, int len);
uint8_t __si_core_getU8RANDRange( uint8_t min, uint8_t max);

#endif