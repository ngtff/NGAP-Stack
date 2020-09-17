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

#ifndef AMF_H
#define AMF_H

#include "sicore.h"
#include "libAMFAsn.h"
#include "libNasPdu.h"
#include "ngap.h"

typedef struct __si_ran_client SI_RAN_Client;
typedef struct __si_session SI_Session;








void __si_ngap_setup_ngran( SI_NGAPNode * ngNode, char * ranName, char * nodekey, char * plmnId, double nodetype, char * nodeId);
SI_RAN_Client * __si_ngap_get_ngran( SI_NGAPNode * ngNode);


SI_Session * __si_node_allocate_new_sesson();
SI_Session * __si_node_get_ue_session_by__mm_ue_id( unsigned long long int MM_UE_ID);

SI_Session * __si_ngap_get_ue_session( SI_NGAPNode * ngNode, unsigned long long int AN_UE_ID);
uint8_t __si_ngap_set_ue_session( SI_NGAPNode * ngNode, SI_Session * ueSession, unsigned long long int AN_UE_ID);



void __si_node_config_get_amf_name( char * amfName, unsigned int * len);
void __si_node_config_get_amf_pointer( char * amfPointer, unsigned int * len);
void __si_node_config_get_amf_setid( char * amfSetId, unsigned int * len);
void __si_node_config_get_amf_regionid( char * amfRegionId, unsigned int * len);
void __si_node_config_get_plmnId( char * plmnId, unsigned int * len);
uint8_t __si_node_config_get_AMFCapacity();


// AMF CONFIG
void __si_amf_config_set_plmn( SI_AMF_DT_PLMNIdentity ** objPLMNIdentity);
void __si_amf_config_set_amf_name( SI_AMF_DT_AMFName ** aMFName);
void __si_amf_config_set_amf_pointer( SI_AMF_DT_AMFPointer ** objAMFPointer);
void __si_amf_config_set_amf_setid( SI_AMF_DT_AMFSetID ** objAMFSetID);
void __si_amf_config_set_amf_regionid( SI_AMF_DT_AMFRegionID ** objAMFRegionID);

void __si_amf_config_set_guami( SI_AMF_DT_GUAMI ** objGUAMI);



//AMF 
void __si_amf_copyto_naspdu( SI_ASN_CodingContext * context, SI_AMF_DT_NAS_PDU ** nasPdu);

void __si_amf_ngap_send_error_indication( unsigned long long int aMFUENGAPID, unsigned long long int rANUENGAPID, uint8_t CauseSelectedChoice , uint16_t causeVal, SI_NGAPNode * ngNode);

void __si_amf_naspdu_send_FGMM_RegistrationReject( unsigned long long int aMFUENGAPID, unsigned long long int rANUENGAPID, uint8_t CauseValue, SI_NGAPNode * ngNode);


#endif








