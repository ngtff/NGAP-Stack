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
#include <math.h> 

#include "amf.h"

void __si_amf_config_set_amf_name( SI_AMF_DT_AMFName ** aMFName)
{
	__si_amf_init_AMFName( aMFName);
	(*aMFName)->data =  __si_allocM( 150);
	__si_node_config_get_amf_name( (*aMFName)->data, &(*aMFName)->length);
}

void __si_amf_config_set_plmn( SI_AMF_DT_PLMNIdentity ** objPLMNIdentity)
{
	__si_amf_init_PLMNIdentity( objPLMNIdentity);
	(*objPLMNIdentity)->data = (unsigned char *) __si_allocM( 3);
	__si_node_config_get_plmnId( (*objPLMNIdentity)->data, &(*objPLMNIdentity)->length);
}

void __si_amf_config_set_amf_regionid( SI_AMF_DT_AMFRegionID ** objAMFRegionID)
{
	__si_amf_init_AMFRegionID( objAMFRegionID);
	(*objAMFRegionID)->data = (unsigned char *) __si_allocM( 1);
	__si_node_config_get_amf_regionid( (*objAMFRegionID)->data, &(*objAMFRegionID)->length);	
}

void __si_amf_config_set_amf_setid( SI_AMF_DT_AMFSetID ** objAMFSetID)
{
	__si_amf_init_AMFSetID( objAMFSetID);
	(*objAMFSetID)->data = (unsigned char *) __si_allocM( 2);
	__si_node_config_get_amf_setid( (*objAMFSetID)->data, &(*objAMFSetID)->length); 	
}

void __si_amf_config_set_amf_pointer( SI_AMF_DT_AMFPointer ** objAMFPointer)
{
	__si_amf_init_AMFPointer( objAMFPointer);
	(*objAMFPointer)->data = (unsigned char *) __si_allocM( 1);
	__si_node_config_get_amf_pointer( (*objAMFPointer)->data, &(*objAMFPointer)->length);	
}

void __si_amf_config_set_guami( SI_AMF_DT_GUAMI ** objGUAMI)
{
	__si_amf_init_GUAMI( objGUAMI);
	__si_amf_config_set_plmn( &(*objGUAMI)->pLMNIdentity);
	__si_amf_config_set_amf_regionid( &(*objGUAMI)->aMFRegionID);
	__si_amf_config_set_amf_setid( &(*objGUAMI)->aMFSetID);
	__si_amf_config_set_amf_pointer( &(*objGUAMI)->aMFPointer);
}








