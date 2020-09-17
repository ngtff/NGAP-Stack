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

#include "amf.h"

void amf_ngap_procedure_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objInitialUEMessage, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received InitialUEMessage message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	__si_amf_debug_pdu_InitialUEMessage( objInitialUEMessage);
	
	if( objInitialUEMessage->rANUENGAPID_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "rANUENGAPID Not Received in InitialUEMessage, sending ErrorIndication <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	if( objInitialUEMessage->nASPDU_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "nASPDU Not Received in InitialUEMessage, sending ErrorIndication <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}

	if( objInitialUEMessage->userLocationInformation_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "userLocationInformation Not Received in InitialUEMessage, sending ErrorIndication <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	if( objInitialUEMessage->rRCEstablishmentCause_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "rRCEstablishmentCause Not Received in InitialUEMessage, sending ErrorIndication <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	//we will only reveive registration request here (at least for now)
	
	SI_NASPduDecode decodePdu;
	memset( &decodePdu, 0, sizeof(SI_NASPduDecode));
	int nasPduSts = __si_naspdu_DecodeFGMessage( &decodePdu, objInitialUEMessage->nASPDU->data, objInitialUEMessage->nASPDU->length);
	
	if( nasPduSts == 0)
	{
		printf( "nasPduSts=%d iStatus=%d msg-type=%d mandatory-decoded=%d mmType=%d protocol-discriminator=%d\n", 
				nasPduSts, 
				decodePdu.iStatus,
				decodePdu.MessageType,
				decodePdu.iMandatoryDecoded,
				decodePdu.MMType,
				decodePdu.ProtocolDiscriminator
			);
		
		if( SI_5GS_MM_REGISTRATION_REQUEST == decodePdu.MessageType)
		{
			__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "Received SI_5GS_MM_REGISTRATION_REQUEST NAS Message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
			
			NASPduFGMM_RegistrationRequest * objRequest = (NASPduFGMM_RegistrationRequest *) decodePdu.messageObj;
			
			if(!objRequest)
			{
				__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "Failed., Error in decoding NAS Message, found decoded Object NULL for MessageType=%d <%s|%s|%d>", 
					decodePdu.MessageType, __FILE__, __FUNCTION__, __LINE__);
				goto send_ie_missing_error;				
			}
			
			
			__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PD=%u PSIOrSHT=%u MessageType=%u 5GS Registration-Type=%u FOR=%u ngKSI=%u TSC=%u <%s|%s|%d>", 
					objRequest->pHeader.ProtocolDiscriminator, objRequest->pHeader.PSIOrSHT, objRequest->pHeader.MessageType, 
					objRequest->b1.FGSRegistrationType, objRequest->b1.FOR, objRequest->b1.ngKSI, objRequest->b1.TSC,
				__FILE__, __FUNCTION__, __LINE__);

			if( objRequest->mFGSMobileIdentity.isset == 0)
			{
				goto send_nas_ie_missing_error;
			}
			
			SI_Session * ueSession = __si_ngap_get_ue_session( ngNode, objInitialUEMessage->rANUENGAPID);
			
			if(ueSession)
			{
				//TODO: already having session validate it with received data
				
				//for now send error
				goto send_nas_protocol_error;
			}
			
			ueSession = __si_node_allocate_new_sesson();
			__si_ngap_set_ue_session( ngNode, ueSession, objInitialUEMessage->rANUENGAPID);
			
			
			uint8_t typeOfId = ( objRequest->mFGSMobileIdentity.data[0] & 0x07);
			uint8_t OddEven = ( objRequest->mFGSMobileIdentity.data[0] & 0x08) >> 3;
			
			printf( "typeOfId=%u OddEven=%u\n", typeOfId, OddEven);
			
			//__si_print_buffer( objRequest->mFGSMobileIdentity.data, objRequest->mFGSMobileIdentity.Length);
			
			
			//NASPdu_FGSMobileIdentity mFGSMobileIdentity;
			//NASPdu_NASKeySetIdentifier mNASKeySetIdentifier;
			//NASPdu_FGMMCapability mFGMMCapability;
			
			//objRequest->mNASKeySetIdentifier
			//objRequest->mFGMMCapability
			
			
			
			printf("EOProcess\n");
		}
		else
		{
			__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "Failed., NOT Received SI_5GS_MM_REGISTRATION_REQUEST NAS Message=%d <%s|%s|%d>", 
				decodePdu.MessageType, __FILE__, __FUNCTION__, __LINE__);
			goto send_ie_missing_error;			
		}
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "decoding of NAS Message failed <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	
	return;
	
	send_nas_protocol_error:
	{
		__si_amf_naspdu_send_FGMM_RegistrationReject( 0, objInitialUEMessage->rANUENGAPID, 111, ngNode);
	}
	return;
	
	send_nas_ie_missing_error:
	{
		__si_amf_naspdu_send_FGMM_RegistrationReject( 0, objInitialUEMessage->rANUENGAPID, 96, ngNode);
	}
	return;
	
	//Missing IE Error Handling	
	send_ie_missing_error:
	{
		__si_amf_ngap_send_error_indication( 0, objInitialUEMessage->rANUENGAPID, 3, CauseProtocol_abstract_syntax_error_falsely_constructed_message_val, ngNode);
	}
	return;
}

void amf_ngap_procedure_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objDownlinkNASTransport, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objUplinkNASTransport, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objNASNonDeliveryIndication, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objRerouteNASRequest, SI_NGAPNode * ngNode)
{
}









