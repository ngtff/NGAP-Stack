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

void __si_node_start_ngamf( int argc, char* argv[]);
void __si_core_wait();
void com_ngap_set_message_handler();



int main( int argc, char* argv[])
{
	__si_node_start_ngamf( argc, argv);
	com_ngap_set_message_handler();
	
	__si_core_wait();
	return 0;
}





