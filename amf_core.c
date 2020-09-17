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


void __si_amf_copyto_naspdu( SI_ASN_CodingContext * context, SI_AMF_DT_NAS_PDU ** nasPdu)
{
	if(!(*nasPdu))
	{	
		__si_amf_init_NAS_PDU( nasPdu);
	}
	
	(*nasPdu)->data = __si_allocM( context->pos + 1);
	(*nasPdu)->length = context->pos;
	
	memcpy( (*nasPdu)->data, context->buffer, context->pos);
}


void __si_amf_ngap_send_error_indication( unsigned long long int aMFUENGAPID, unsigned long long int rANUENGAPID, uint8_t CauseSelectedChoice , uint16_t causeVal, SI_NGAPNode * ngNode)
{
	SI_AMF_DT_PDU_ErrorIndication objErrorIndication;
	memset( &objErrorIndication, 0, sizeof(SI_AMF_DT_PDU_ErrorIndication));
	
	if( aMFUENGAPID > 0)
	{	
		objErrorIndication.aMFUENGAPID = aMFUENGAPID;
		objErrorIndication.aMFUENGAPID_isset = 1;
	}
	
	objErrorIndication.rANUENGAPID = rANUENGAPID;
	objErrorIndication.rANUENGAPID_isset = 1;
	
	__si_amf_init_Cause( &objErrorIndication.cause);
	objErrorIndication.cause->SelectedChoice = CauseSelectedChoice;

	objErrorIndication.cause_isset = 1;
	
	switch( CauseSelectedChoice)
	{
		case 0:
			objErrorIndication.cause->u.radioNetwork = causeVal;
			break;
		case 1:
			objErrorIndication.cause->u.transport = causeVal;
			break;
		case 2:
			objErrorIndication.cause->u.nas = causeVal;
			break;
		case 3:
			objErrorIndication.cause->u.protocol = causeVal;
			break;
		case 4:
			objErrorIndication.cause->u.misc = causeVal;
			break;
		default:
			objErrorIndication.cause_isset = 1;					//UnSet here if its invalid value
			break;
	}	
	
	__si_ngap_send_ErrorIndication( &objErrorIndication, ngNode);	
}


void __si_amf_ngap_send_DownlinkNASTransport( unsigned long long int aMFUENGAPID, unsigned long long int rANUENGAPID, SI_ASN_CodingContext * context, SI_NGAPNode * ngNode)
{
	SI_AMF_DT_PDU_DownlinkNASTransport objDownlinkNASTransport;
	memset( &objDownlinkNASTransport, 0, sizeof(SI_AMF_DT_PDU_DownlinkNASTransport));
	
	objDownlinkNASTransport.aMFUENGAPID = aMFUENGAPID;
	objDownlinkNASTransport.aMFUENGAPID_isset = 1;
	
	objDownlinkNASTransport.rANUENGAPID = rANUENGAPID;
	objDownlinkNASTransport.rANUENGAPID_isset = 1;
		
	__si_amf_copyto_naspdu( context, &objDownlinkNASTransport.nASPDU);
	objDownlinkNASTransport.nASPDU_isset = 1;
	
	__si_ngap_send_DownlinkNASTransport( &objDownlinkNASTransport, ngNode);
}


void __si_amf_naspdu_send_FGMM_RegistrationReject( unsigned long long int aMFUENGAPID, unsigned long long int rANUENGAPID, uint8_t CauseValue, SI_NGAPNode * ngNode)
{
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	NASPduFGMM_RegistrationReject objRegistrationReject;
	memset( &objRegistrationReject, 0, sizeof(NASPduFGMM_RegistrationReject));

	objRegistrationReject.mFGMMCause.isset = 1;
	objRegistrationReject.mFGMMCause.CauseValue = CauseValue;

	__si_naspdu_fgmm_encodeRegistrationReject( &objRegistrationReject, &context);		

	__si_amf_ngap_send_DownlinkNASTransport( aMFUENGAPID, rANUENGAPID, &context, ngNode);
}






