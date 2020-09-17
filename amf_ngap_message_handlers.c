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

#include "sicore.h"
#include "libAMFAsn.h"
#include "libNasPdu.h"
#include "ngap.h"
#include "amf_ngap_procedures.h"

void com_ngap_log_hex( u_char * buffer, uint32_t len, char * key, int line)
{
	int i = 0;
	int iIndex = 0;
	int iDumpSize = len * 7;
	char sDump[iDumpSize];
	memset( sDump, 0, sizeof(sDump));
	
	for( i = 0; i < len; i++)
	{
		sprintf( &sDump[iIndex], "0x%02X,", buffer[i]);
		iIndex += 5;
	}
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "%s LEN=%u DATA=[%s] <%d>", key, len, sDump, line); 
	
}



void com_ngap_log_FGSMCause( NASPdu_FGSMCause * mFGSMCause)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "FGSMCause isset=%u CauseValue=%u <%s|%s|%d>", mFGSMCause->isset, 
		mFGSMCause->CauseValue, __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_FGMMCause( NASPdu_FGMMCause * mFGMMCause)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "FGMMCause isset=%u CauseValue=%u <%s|%s|%d>", mFGMMCause->isset, 
		mFGMMCause->CauseValue, __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPdu_FGSMobileIdentity( NASPdu_FGSMobileIdentity * mFGSMobileIdentity)
{
	if( mFGSMobileIdentity->isset == 1)
	{
		com_ngap_log_hex( mFGSMobileIdentity->data, mFGSMobileIdentity->Length, "FGSMobileIdentity", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "FGSMobileIdentity UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	}
}

void com_ngap_log_NASPdu_FGSRegistrationResult( NASPdu_FGSRegistrationResult * oFGSRegistrationResult)
{
	if( oFGSRegistrationResult->isset == 1)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "FGSRegistrationResult Length=%u SMSAllowed=%u ResultValue=%u Spare=%u <%s|%s|%d>", 
				oFGSRegistrationResult->Length, oFGSRegistrationResult->b1.SMSAllowed, 
				oFGSRegistrationResult->b1.FGSRegistrationResultValue,
				oFGSRegistrationResult->b1.Spare,
			__FILE__, __FUNCTION__, __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "FGSRegistrationResult UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	}
}

void com_ngap_log_NASPdu_PayloadContainer( NASPdu_PayloadContainer * oPayloadContainer)
{
	if( oPayloadContainer->isset == 1)
	{
		com_ngap_log_hex( oPayloadContainer->data, oPayloadContainer->Length, "PayloadContainer", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PayloadContainer UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_FGMM_UESecurityCapability( NASPdu_FGMM_UESecurityCapability * oUESecurityCapability)
{
	if( oUESecurityCapability->isset == 1)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "UESecurityCapability Length=%u %02X %02X %02X %02X <%s|%s|%d>",
				oUESecurityCapability->Length, *( uint8_t *) &oUESecurityCapability->b1, *( uint8_t *) &oUESecurityCapability->b2,
				*( uint8_t *) &oUESecurityCapability->b3, *( uint8_t *) &oUESecurityCapability->b4,				
			__FILE__, __FUNCTION__, __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "UESecurityCapability UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}	
}

void com_ngap_log_NASPdu_AuthenticationFailureParameter( NASPdu_AuthenticationFailureParameter * oAuthenticationFailureParameter)
{
	if( oAuthenticationFailureParameter->isset == 1)
	{
		com_ngap_log_hex( oAuthenticationFailureParameter->data, oAuthenticationFailureParameter->Length, "AuthenticationFailureParameter", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationFailureParameter UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_FGMMABBA( NASPdu_FGMMABBA * oFGMMABBA)
{
	if( oFGMMABBA->isset == 1)
	{
		com_ngap_log_hex( oFGMMABBA->data, oFGMMABBA->Length, "FGMMABBA", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "FGMMABBA UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_AuthenticationResponseParameter( NASPdu_AuthenticationResponseParameter * oAuthenticationResponseParameter)
{
	if( oAuthenticationResponseParameter->isset == 1)
	{
		com_ngap_log_hex( oAuthenticationResponseParameter->data, oAuthenticationResponseParameter->Length, "AuthenticationResponseParameter", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationResponseParameter UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_AuthenticationParameterRAND( NASPdu_AuthenticationParameterRAND * oAuthenticationParameterRAND)
{
	if( oAuthenticationParameterRAND->isset == 1)
	{
		com_ngap_log_hex( oAuthenticationParameterRAND->data, 16, "AuthenticationParameterRAND", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationParameterRAND UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_AuthenticationParameterAUTN( NASPdu_AuthenticationParameterAUTN * oAuthenticationParameterAUTN)
{
	if( oAuthenticationParameterAUTN->isset == 1)
	{
		com_ngap_log_hex( oAuthenticationParameterAUTN->data, 16, "AuthenticationParameterAUTN", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationParameterAUTN UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_EAPMessage( NASPdu_EAPMessage * oEAPMessage)
{
	if( oEAPMessage->isset == 1)
	{
		com_ngap_log_hex( oEAPMessage->data, oEAPMessage->Length, "EAPMessage", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "EAPMessage UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPduFGSM_Status( NASPduFGSM_Status * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "SM_Status <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGSMCause( &objRequest->mFGSMCause);
}

void com_ngap_log_NASPduFGMM_RegistrationRequest( NASPduFGMM_RegistrationRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "RegistrationRequest TSC=%u ngKSI=%u FOR=%u FGSRegistrationType=%u <%s|%s|%d>", 
			objRequest->b1.TSC, 
			objRequest->b1.ngKSI, objRequest->b1.FOR, objRequest->b1.FGSRegistrationType, 
		__FILE__, __FUNCTION__, __LINE__);
		
	com_ngap_log_NASPdu_FGSMobileIdentity( &objRequest->mFGSMobileIdentity);	
}

void com_ngap_log_NASPduFGMM_RegistrationAccept( NASPduFGMM_RegistrationAccept * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "RegistrationRequest <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_NASPdu_FGSRegistrationResult( &objRequest->mFGSRegistrationResult);
}

void com_ngap_log_NASPduFGMM_RegistrationComplete( NASPduFGMM_RegistrationComplete * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "RegistrationComplete <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_RegistrationReject( NASPduFGMM_RegistrationReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "RegistrationReject <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGMMCause( &objRequest->mFGMMCause);
}

void com_ngap_log_NASPduFGMM_ULNASTransport( NASPduFGMM_ULNASTransport * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "ULNASTransport PayloadContainerType=%u <%s|%s|%d>", 
		objRequest->b1.PayloadContainerType, __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_PayloadContainer( &objRequest->mPayloadContainer);
}

void com_ngap_log_NASPduFGMM_DLNASTransport( NASPduFGMM_DLNASTransport * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "DLNASTransport PayloadContainerType=%u <%s|%s|%d>", 
		objRequest->b1.PayloadContainerType, __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_PayloadContainer( &objRequest->mPayloadContainer);	
}

void com_ngap_log_NASPduFGMM_DeregistrationRequestUEI( NASPduFGMM_DeregistrationRequestUEI * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "DeregistrationRequestUEI DeRegistrationType=%u ngKSI=%u TSC=%u <%s|%s|%d>", 
		objRequest->b1.DeRegistrationType, objRequest->b1.ngKSI, objRequest->b1.TSC, __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_FGSMobileIdentity( &objRequest->mFGSMobileIdentity);
}

void com_ngap_log_NASPduFGMM_DeregistrationAcceptUEI( NASPduFGMM_DeregistrationAcceptUEI * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "DeregistrationAcceptUEI <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_DeregistrationRequestUET( NASPduFGMM_DeregistrationRequestUET * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "DeregistrationRequestUET AccessType=%u SwitchOff=%u <%s|%s|%d>", 
		objRequest->b1.DeRegistrationType_AccessType, objRequest->b1.DeRegistrationType_SwitchOff, __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_DeregistrationAcceptUET( NASPduFGMM_DeregistrationAcceptUET * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "DeregistrationAcceptUET <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_ServiceRequest( NASPduFGMM_ServiceRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "ServiceRequest TSC=%u ngKSI=%u ServiceType=%u <%s|%s|%d>",
			objRequest->b1.TSC, objRequest->b1.ngKSI, objRequest->b1.ServiceType,
		__FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_NASPdu_FGSMobileIdentity( &objRequest->m5GSTMSI);
}

void com_ngap_log_NASPduFGMM_ServiceAccept( NASPduFGMM_ServiceAccept * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "ServiceAccept <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_ServiceReject( NASPduFGMM_ServiceReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "ServiceReject <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGMMCause( &objRequest->mFGMMCause);
}

void com_ngap_log_NASPduFGMM_ConfigurationUpdateCommand( NASPduFGMM_ConfigurationUpdateCommand * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "ConfigurationUpdateCommand <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_ConfigurationUpdateComplete( NASPduFGMM_ConfigurationUpdateComplete * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "ConfigurationUpdateComplete <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_AuthenticationRequest( NASPduFGMM_AuthenticationRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationRequest ngKSI=%u <%s|%s|%d>", objRequest->b1.ngKSI, __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_FGMMABBA( &objRequest->mABBA);
	com_ngap_log_NASPdu_AuthenticationParameterRAND( &objRequest->mAuthenticationParameterRAND);
	com_ngap_log_NASPdu_AuthenticationParameterAUTN( &objRequest->mAuthenticationParameterAUTN);
	com_ngap_log_NASPdu_EAPMessage( &objRequest->mEAPMessage);
}

void com_ngap_log_NASPduFGMM_AuthenticationResponse( NASPduFGMM_AuthenticationResponse * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationResponse <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_AuthenticationResponseParameter( &objRequest->mAuthenticationResponseParameter);
	com_ngap_log_NASPdu_EAPMessage( &objRequest->mEAPMessage);
}

void com_ngap_log_NASPduFGMM_AuthenticationResult( NASPduFGMM_AuthenticationResult * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationResult ngKSI=%u <%s|%s|%d>", objRequest->b1.ngKSI, __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_FGMMABBA( &objRequest->mABBA);
	com_ngap_log_NASPdu_EAPMessage( &objRequest->mEAPMessage);	
}

void com_ngap_log_NASPduFGMM_AuthenticationFailure( NASPduFGMM_AuthenticationFailure * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationFailure <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_FGMMCause( &objRequest->mFGMMCause);
	com_ngap_log_NASPdu_AuthenticationFailureParameter( &objRequest->mAuthenticationFailureParameter);	
}

void com_ngap_log_NASPduFGMM_AuthenticationReject( NASPduFGMM_AuthenticationReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "AuthenticationReject <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_NASPdu_EAPMessage( &objRequest->mEAPMessage);
}

void com_ngap_log_NASPduFGMM_IdentityRequest( NASPduFGMM_IdentityRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "IdentityRequest FGSIdentityType=%u <%s|%s|%d>", objRequest->b1.FGSIdentityType, __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_IdentityResponse( NASPduFGMM_IdentityResponse * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "IdentityResponse <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_NASPdu_FGSMobileIdentity( &objRequest->mMobileIdentity);
}

void com_ngap_log_NASPduFGMM_Notification( NASPduFGMM_Notification * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "Notification AccessType=%u <%s|%s|%d>", objRequest->b1.AccessType, __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_NotificationResponse( NASPduFGMM_NotificationResponse * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "NotificationResponse <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_SecurityModeCommand( NASPduFGMM_SecurityModeCommand * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "SecurityModeCommand TypeOfCipheringAlgorithm=%u TSC=%u ngKSI=%u <%s|%s|%d>", 
		objRequest->mNASSecurityAlgorithms.b1.TypeOfCipheringAlgorithm, objRequest->b1.TSC, objRequest->b1.ngKSI, 
	__FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_FGMM_UESecurityCapability( &objRequest->mUESecurityCapability);
}

void com_ngap_log_NASPduFGMM_SecurityModeComplete( NASPduFGMM_SecurityModeComplete * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "SecurityModeComplete <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_log_NASPduFGMM_SecurityModeReject( NASPduFGMM_SecurityModeReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "SecurityModeReject <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGMMCause( &objRequest->mFGMMCause);
}

void com_ngap_log_NASPduFGMM_5GMMStatus( NASPduFGMM_5GMMStatus * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "5GMMStatus <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGMMCause( &objRequest->mFGMMCause);
}



void com_ngap_log_mm_nas_message( SI_NASPduDecode * decodePdu)
{
	switch( decodePdu->MessageType)
	{
		case SI_5GS_MM_REGISTRATION_REQUEST:
			com_ngap_log_NASPduFGMM_RegistrationRequest( (NASPduFGMM_RegistrationRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_REGISTRATION_ACCEPT:
			com_ngap_log_NASPduFGMM_RegistrationAccept( (NASPduFGMM_RegistrationAccept *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_REGISTRATION_COMPLETE:
			com_ngap_log_NASPduFGMM_RegistrationComplete( (NASPduFGMM_RegistrationComplete *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_REGISTRATION_REJECT:
			com_ngap_log_NASPduFGMM_RegistrationReject( (NASPduFGMM_RegistrationReject *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_UE_ORGIN_DE_REGISTRATION_REQUEST:
			com_ngap_log_NASPduFGMM_DeregistrationRequestUEI( (NASPduFGMM_DeregistrationRequestUEI *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_UE_ORGIN_DE_REGISTRATION_ACCEPT:
			com_ngap_log_NASPduFGMM_DeregistrationAcceptUEI( (NASPduFGMM_DeregistrationAcceptUEI *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_UE_TERMI_DE_REGISTRATION_REQUEST:
			com_ngap_log_NASPduFGMM_DeregistrationRequestUET( (NASPduFGMM_DeregistrationRequestUET *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_UE_TERMI_DE_REGISTRATION_ACCEPT:
			com_ngap_log_NASPduFGMM_DeregistrationAcceptUET( (NASPduFGMM_DeregistrationAcceptUET *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_SERVICE_REQUEST:
			com_ngap_log_NASPduFGMM_ServiceRequest( (NASPduFGMM_ServiceRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_SERVICE_REJECT:
			com_ngap_log_NASPduFGMM_ServiceReject( (NASPduFGMM_ServiceReject *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_SERVICE_ACCEPT:
			com_ngap_log_NASPduFGMM_ServiceAccept( (NASPduFGMM_ServiceAccept *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_CONFIGURATION_UPDATE_COMMAND:
			com_ngap_log_NASPduFGMM_ConfigurationUpdateCommand( (NASPduFGMM_ConfigurationUpdateCommand *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_CONFIGURATION_UPDATE_COMPLETE:
			com_ngap_log_NASPduFGMM_ConfigurationUpdateComplete( (NASPduFGMM_ConfigurationUpdateComplete *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_AUTHENTICATION_REQUEST:
			com_ngap_log_NASPduFGMM_AuthenticationRequest( (NASPduFGMM_AuthenticationRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_AUTHENTICATION_RESPONSE:
			com_ngap_log_NASPduFGMM_AuthenticationResponse( (NASPduFGMM_AuthenticationResponse *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_AUTHENTICATION_REJECT:
			com_ngap_log_NASPduFGMM_AuthenticationReject( (NASPduFGMM_AuthenticationReject *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_AUTHENTICATION_FAILURE:
			com_ngap_log_NASPduFGMM_AuthenticationFailure( (NASPduFGMM_AuthenticationFailure *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_AUTHENTICATION_RESULT:
			com_ngap_log_NASPduFGMM_AuthenticationResult( (NASPduFGMM_AuthenticationResult *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_IDENTITY_REQUEST:
			com_ngap_log_NASPduFGMM_IdentityRequest( (NASPduFGMM_IdentityRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_IDENTITY_RESPONSE:
			com_ngap_log_NASPduFGMM_IdentityResponse( (NASPduFGMM_IdentityResponse *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_SECURITY_MODE_COMMAND:
			com_ngap_log_NASPduFGMM_SecurityModeCommand( (NASPduFGMM_SecurityModeCommand *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_SECURITY_MODE_COMPLETE:
			com_ngap_log_NASPduFGMM_SecurityModeComplete( (NASPduFGMM_SecurityModeComplete *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_SECURITY_MODE_REJECT:
			com_ngap_log_NASPduFGMM_SecurityModeReject( (NASPduFGMM_SecurityModeReject *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_STATUS:
			com_ngap_log_NASPduFGMM_5GMMStatus( (NASPduFGMM_5GMMStatus *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_NOTIFICATION:
			com_ngap_log_NASPduFGMM_Notification( (NASPduFGMM_Notification *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_NOTIFICATION_RESPONSE:
			com_ngap_log_NASPduFGMM_NotificationResponse( (NASPduFGMM_NotificationResponse *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_UL_NAS_TRANSPORT:
			com_ngap_log_NASPduFGMM_ULNASTransport( (NASPduFGMM_ULNASTransport *)decodePdu->messageObj);
			break;
		case SI_5GS_MM_DL_NAS_TRANSPORT:
			com_ngap_log_NASPduFGMM_DLNASTransport( (NASPduFGMM_DLNASTransport *)decodePdu->messageObj);
			break;
		default:
			__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "received invalid mt=%u <%s|%s|%d>", decodePdu->MessageType, __FILE__, __FUNCTION__, __LINE__);
			break;
	}
	
}

void com_ngap_log_NASPdu_IntegrityProtectionMaximumDataRate( NASPdu_IntegrityProtectionMaximumDataRate * oIntegrityProtectionMaximumDataRate)
{
	if( oIntegrityProtectionMaximumDataRate->isset == 1)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "5GMMStatus Uplink=%u Downlink=%u <%s|%s|%d>", 
			oIntegrityProtectionMaximumDataRate->MaximumDataRatePerUEForUserPlaneIntegrityProtection_Uplink,
			oIntegrityProtectionMaximumDataRate->MaximumDataRatePerUEForUserPlaneIntegrityProtection_Downlink,
		__FILE__, __FUNCTION__, __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "IntegrityProtectionMaximumDataRate UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_QosRules( NASPdu_QosRules * oQosRules)
{
	if( oQosRules->isset == 1)
	{
		com_ngap_log_hex( oQosRules->data, oQosRules->Length, "QosRules", __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "QosRules UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);	
	}
}

void com_ngap_log_NASPdu_SessionAMBR( NASPdu_SessionAMBR * oSessionAMBR)
{
	if( oSessionAMBR->isset == 1)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "Length=%u UnitDownlink=%u Downlink=%u UnitUplink=%u Uplink=%u <%s|%s|%d>", 
			oSessionAMBR->Length, oSessionAMBR->UnitForSessionAMBRForDownlink, oSessionAMBR->SessionAMBRForDownlink,
			oSessionAMBR->UnitForSessionAMBRForUplink, oSessionAMBR->SessionAMBRForUplink,
		__FILE__, __FUNCTION__, __LINE__);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "SessionAMBR UnSet <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	}
}


void com_ngap_log_NASPduFGSM_PDUSessionEstablishmentRequest( NASPduFGSM_PDUSessionEstablishmentRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionEstablishmentRequest PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);
	
	com_ngap_log_NASPdu_IntegrityProtectionMaximumDataRate( &objRequest->mIntegrityProtectionMaximumDataRate);
}

void com_ngap_log_NASPduFGSM_PDUSessionEstablishmentAccept( NASPduFGSM_PDUSessionEstablishmentAccept * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionEstablishmentAccept PDUSessionId=%u ProcedureTransactionIdentity=%u PDUSessionType=%u SSCMode=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity, objRequest->b1.PDUSessionType, objRequest->b1.SSCMode,
	__FILE__, __FUNCTION__, __LINE__);	
	
	com_ngap_log_NASPdu_QosRules( &objRequest->mAuthorizedQoSRules);
	com_ngap_log_NASPdu_SessionAMBR( &objRequest->mSessionAMBR);
}

void com_ngap_log_NASPduFGSM_PDUSessionEstablishmentReject( NASPduFGSM_PDUSessionEstablishmentReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionEstablishmentReject PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
	com_ngap_log_FGSMCause( &objRequest->mFGSMCause);
}

void com_ngap_log_NASPduFGSM_PDUSessionAuthenticationCommand( NASPduFGSM_PDUSessionAuthenticationCommand * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionAuthenticationCommand PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
	com_ngap_log_NASPdu_EAPMessage( &objRequest->mEAPMessage);
}

void com_ngap_log_NASPduFGSM_PDUSessionAuthenticationComplete( NASPduFGSM_PDUSessionAuthenticationComplete * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionAuthenticationComplete PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
	com_ngap_log_NASPdu_EAPMessage( &objRequest->mEAPMessage);
}

void com_ngap_log_NASPduFGSM_PDUSessionAuthenticationResult( NASPduFGSM_PDUSessionAuthenticationResult * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionAuthenticationResult PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
}

void com_ngap_log_NASPduFGSM_PDUSessionModificationRequest( NASPduFGSM_PDUSessionModificationRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionModificationRequest PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
}

void com_ngap_log_NASPduFGSM_PDUSessionModificationReject( NASPduFGSM_PDUSessionModificationReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionModificationReject PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGSMCause( &objRequest->mFGSMCause);
}

void com_ngap_log_NASPduFGSM_PDUSessionModificationCommand( NASPduFGSM_PDUSessionModificationCommand * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionModificationCommand PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
}

void com_ngap_log_NASPduFGSM_PDUSessionModificationComplete( NASPduFGSM_PDUSessionModificationComplete * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionModificationComplete PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
}

void com_ngap_log_NASPduFGSM_PDUSessionModificationCommandReject( NASPduFGSM_PDUSessionModificationCommandReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionModificationCommandReject PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);
	com_ngap_log_FGSMCause( &objRequest->mFGSMCause);
}

void com_ngap_log_NASPduFGSM_PDUSessionReleaseRequest( NASPduFGSM_PDUSessionReleaseRequest * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionReleaseRequest PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
}

void com_ngap_log_NASPduFGSM_PDUSessionReleaseReject( NASPduFGSM_PDUSessionReleaseReject * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionReleaseReject PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
	com_ngap_log_FGSMCause( &objRequest->mFGSMCause);
}

void com_ngap_log_NASPduFGSM_PDUSessionReleaseCommand( NASPduFGSM_PDUSessionReleaseCommand * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionReleaseCommand PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
	com_ngap_log_FGSMCause( &objRequest->mFGSMCause);
}

void com_ngap_log_NASPduFGSM_PDUSessionReleaseComplete( NASPduFGSM_PDUSessionReleaseComplete * objRequest)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "PDUSessionReleaseComplete PDUSessionId=%u ProcedureTransactionIdentity=%u <%s|%s|%d>", 
		objRequest->pHeader.PDUSessionId, objRequest->pHeader.ProcedureTransactionIdentity,
	__FILE__, __FUNCTION__, __LINE__);	
}

// __si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "5GMMStatus <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
void com_ngap_log_sm_nas_message( SI_NASPduDecode * decodePdu)
{
	switch( decodePdu->MessageType)
	{
		case SI_5GS_SM_PDU_SESSION_ESTABLISHMENT_REQUEST:
			com_ngap_log_NASPduFGSM_PDUSessionEstablishmentRequest( (NASPduFGSM_PDUSessionEstablishmentRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_ESTABLISHMENT_ACCEPT:
			com_ngap_log_NASPduFGSM_PDUSessionEstablishmentAccept( (NASPduFGSM_PDUSessionEstablishmentAccept *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_ESTABLISHMENT_REJECT:
			com_ngap_log_NASPduFGSM_PDUSessionEstablishmentReject( (NASPduFGSM_PDUSessionEstablishmentReject *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_AUTHENTICATION_COMMAND:
			com_ngap_log_NASPduFGSM_PDUSessionAuthenticationCommand( (NASPduFGSM_PDUSessionAuthenticationCommand *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_AUTHENTICATION_COMPLETE:
			com_ngap_log_NASPduFGSM_PDUSessionAuthenticationComplete( (NASPduFGSM_PDUSessionAuthenticationComplete *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_AUTHENTICATION_RESULT:
			com_ngap_log_NASPduFGSM_PDUSessionAuthenticationResult( (NASPduFGSM_PDUSessionAuthenticationResult *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_MODIFICATION_REQUEST:
			com_ngap_log_NASPduFGSM_PDUSessionModificationRequest( (NASPduFGSM_PDUSessionModificationRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_MODIFICATION_REJECT:
			com_ngap_log_NASPduFGSM_PDUSessionModificationReject( (NASPduFGSM_PDUSessionModificationReject *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_MODIFICATION_COMMAND:
			com_ngap_log_NASPduFGSM_PDUSessionModificationCommand( (NASPduFGSM_PDUSessionModificationCommand *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_MODIFICATION_COMPLETE:
			com_ngap_log_NASPduFGSM_PDUSessionModificationComplete( (NASPduFGSM_PDUSessionModificationComplete *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_MODIFICATION_COMMAND_REJECT:
			com_ngap_log_NASPduFGSM_PDUSessionModificationCommandReject( (NASPduFGSM_PDUSessionModificationCommandReject *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_RELEASE_REQUEST:
			com_ngap_log_NASPduFGSM_PDUSessionReleaseRequest( (NASPduFGSM_PDUSessionReleaseRequest *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_RELEASE_REJECT:
			com_ngap_log_NASPduFGSM_PDUSessionReleaseReject( (NASPduFGSM_PDUSessionReleaseReject *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_RELEASE_COMMAND:
			com_ngap_log_NASPduFGSM_PDUSessionReleaseCommand( (NASPduFGSM_PDUSessionReleaseCommand *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_PDU_SESSION_RELEASE_COMPLETE:
			com_ngap_log_NASPduFGSM_PDUSessionReleaseComplete( (NASPduFGSM_PDUSessionReleaseComplete *)decodePdu->messageObj);
			break;
		case SI_5GS_SM_STATUS:
			com_ngap_log_NASPduFGSM_Status( (NASPduFGSM_Status *)decodePdu->messageObj);
			break;
		default:
			__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "received invalid mt=%u <%s|%s|%d>", decodePdu->MessageType, __FILE__, __FUNCTION__, __LINE__);
			break;
	}
}

void com_ngap_log_nas_message( SI_NASPduDecode * decodePdu)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "epd=%u mt=%u sts=%u pos=%u len=%u man-decoded=%u uns-eid=%u <%s|%s|%d>", 
		decodePdu->ProtocolDiscriminator, decodePdu->MessageType, 
		decodePdu->iStatus, decodePdu->pos, decodePdu->length, decodePdu->iMandatoryDecoded, decodePdu->iUnSuccessfulElementId, __FILE__, __FUNCTION__, __LINE__);
		
	if( decodePdu->ProtocolDiscriminator == SI_5GS_SM_EPD)
	{
		com_ngap_log_sm_nas_message( decodePdu);
	}
	else if( decodePdu->ProtocolDiscriminator == SI_5GS_MM_EPD)
	{
		com_ngap_log_mm_nas_message( decodePdu);
	}
	else
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "received invalid epd=%u <%s|%s|%d>", decodePdu->ProtocolDiscriminator, __FILE__, __FUNCTION__, __LINE__);
	}
}


void com_ngap_handler_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objAMFConfigurationUpdate, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received AMFConfigurationUpdate message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_AMFConfigurationUpdate( objAMFConfigurationUpdate, ngNode);
}

void com_ngap_handler_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objAMFConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received AMFConfigurationUpdateAcknowledge message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_AMFConfigurationUpdateAcknowledge( objAMFConfigurationUpdateAcknowledge, ngNode);
}

void com_ngap_handler_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objAMFConfigurationUpdateFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received AMFConfigurationUpdateFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_AMFConfigurationUpdateFailure( objAMFConfigurationUpdateFailure, ngNode);
}

void com_ngap_handler_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objAMFStatusIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received AMFStatusIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_AMFStatusIndication( objAMFStatusIndication, ngNode);
}

void com_ngap_handler_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received CellTrafficTrace message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_CellTrafficTrace( objCellTrafficTrace, ngNode);
}

void com_ngap_handler_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received DeactivateTrace message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_DeactivateTrace( objDeactivateTrace, ngNode);
}

void com_ngap_handler_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objDownlinkNASTransport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received DownlinkNASTransport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_DownlinkNASTransport( objDownlinkNASTransport, ngNode);
}

void com_ngap_handler_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objDownlinkNonUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received DownlinkNonUEAssociatedNRPPaTransport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_DownlinkNonUEAssociatedNRPPaTransport( objDownlinkNonUEAssociatedNRPPaTransport, ngNode);
}

void com_ngap_handler_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objDownlinkRANConfigurationTransfer, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received DownlinkRANConfigurationTransfer message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_DownlinkRANConfigurationTransfer( objDownlinkRANConfigurationTransfer, ngNode);
}

void com_ngap_handler_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objDownlinkRANStatusTransfer, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received DownlinkRANStatusTransfer message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_DownlinkRANStatusTransfer( objDownlinkRANStatusTransfer, ngNode);
}

void com_ngap_handler_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objDownlinkUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received DownlinkUEAssociatedNRPPaTransport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_DownlinkUEAssociatedNRPPaTransport( objDownlinkUEAssociatedNRPPaTransport, ngNode);
}

void com_ngap_handler_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objErrorIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received ErrorIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_ErrorIndication( objErrorIndication, ngNode);
}

void com_ngap_handler_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objHandoverCancel, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverCancel message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverCancel( objHandoverCancel, ngNode);
}

void com_ngap_handler_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objHandoverCancelAcknowledge, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverCancelAcknowledge message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverCancelAcknowledge( objHandoverCancelAcknowledge, ngNode);
}

void com_ngap_handler_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objHandoverNotify, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverNotify message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverNotify( objHandoverNotify, ngNode);
}

void com_ngap_handler_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objHandoverRequired, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverRequired message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverRequired( objHandoverRequired, ngNode);
}

void com_ngap_handler_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objHandoverCommand, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverCommand message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverCommand( objHandoverCommand, ngNode);
}

void com_ngap_handler_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objHandoverPreparationFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverPreparationFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverPreparationFailure( objHandoverPreparationFailure, ngNode);
}

void com_ngap_handler_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objHandoverRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverRequest( objHandoverRequest, ngNode);
}

void com_ngap_handler_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objHandoverRequestAcknowledge, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverRequestAcknowledge message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverRequestAcknowledge( objHandoverRequestAcknowledge, ngNode);
}

void com_ngap_handler_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objHandoverFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received HandoverFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_HandoverFailure( objHandoverFailure, ngNode);
}

void com_ngap_handler_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objInitialContextSetupRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received InitialContextSetupRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_InitialContextSetupRequest( objInitialContextSetupRequest, ngNode);
}

void com_ngap_handler_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objInitialContextSetupResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received InitialContextSetupResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_InitialContextSetupResponse( objInitialContextSetupResponse, ngNode);
}

void com_ngap_handler_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objInitialContextSetupFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received InitialContextSetupFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_InitialContextSetupFailure( objInitialContextSetupFailure, ngNode);
}

void com_ngap_handler_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objInitialUEMessage, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received InitialUEMessage message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_InitialUEMessage( objInitialUEMessage, ngNode);
	
	/*
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "nASPDU_isset=%d len=%d", objInitialUEMessage->nASPDU_isset, objInitialUEMessage->nASPDU->length);
	
	if( objInitialUEMessage->nASPDU_isset == 1)
	{
		SI_NASPduDecode decodePdu;
		__si_naspdu_DecodeFGMessage( &decodePdu, objInitialUEMessage->nASPDU->data, objInitialUEMessage->nASPDU->length);
		
		com_ngap_log_nas_message( &decodePdu);
	}
	*/
}

void com_ngap_handler_LocationReport( SI_AMF_DT_PDU_LocationReport * objLocationReport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received LocationReport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_LocationReport( objLocationReport, ngNode);
}

void com_ngap_handler_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objLocationReportingControl, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received LocationReportingControl message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_LocationReportingControl( objLocationReportingControl, ngNode);
}

void com_ngap_handler_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objLocationReportingFailureIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received LocationReportingFailureIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_LocationReportingFailureIndication( objLocationReportingFailureIndication, ngNode);
}

void com_ngap_handler_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objNASNonDeliveryIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NASNonDeliveryIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_NASNonDeliveryIndication( objNASNonDeliveryIndication, ngNode);
}

void com_ngap_handler_NGReset( SI_AMF_DT_PDU_NGReset * objNGReset, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NGReset message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_NGReset( objNGReset, ngNode);
}

void com_ngap_handler_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objNGResetAcknowledge, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NGResetAcknowledge message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_NGResetAcknowledge( objNGResetAcknowledge, ngNode);
}

void com_ngap_handler_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objNGSetupRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NGSetupRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_NGSetupRequest( objNGSetupRequest, ngNode);
}

void com_ngap_handler_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objNGSetupResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NGSetupResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_NGSetupResponse( objNGSetupResponse, ngNode);
}

void com_ngap_handler_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objNGSetupFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NGSetupFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_NGSetupFailure( objNGSetupFailure, ngNode);
}

void com_ngap_handler_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objOverloadStart, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received OverloadStart message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_handler_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objOverloadStop, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received OverloadStop message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_handler_Paging( SI_AMF_DT_PDU_Paging * objPaging, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received Paging message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_Paging( objPaging, ngNode);
}

void com_ngap_handler_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPathSwitchRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PathSwitchRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PathSwitchRequest( objPathSwitchRequest, ngNode);
}

void com_ngap_handler_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPathSwitchRequestAcknowledge, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PathSwitchRequestAcknowledge message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PathSwitchRequestAcknowledge( objPathSwitchRequestAcknowledge, ngNode);
}

void com_ngap_handler_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPathSwitchRequestFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PathSwitchRequestFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PathSwitchRequestFailure( objPathSwitchRequestFailure, ngNode);
}

void com_ngap_handler_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUSessionResourceModifyRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceModifyRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceModifyRequest( objPDUSessionResourceModifyRequest, ngNode);
}

void com_ngap_handler_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUSessionResourceModifyResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceModifyResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceModifyResponse( objPDUSessionResourceModifyResponse, ngNode);
}

void com_ngap_handler_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUSessionResourceModifyIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceModifyIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceModifyIndication( objPDUSessionResourceModifyIndication, ngNode);
}

void com_ngap_handler_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUSessionResourceModifyConfirm, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceModifyConfirm message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceModifyConfirm( objPDUSessionResourceModifyConfirm, ngNode);
}

void com_ngap_handler_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUSessionResourceNotify, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceNotify message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceNotify( objPDUSessionResourceNotify, ngNode);
}

void com_ngap_handler_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUSessionResourceReleaseCommand, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceReleaseCommand message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceReleaseCommand( objPDUSessionResourceReleaseCommand, ngNode);
}

void com_ngap_handler_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUSessionResourceReleaseResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceReleaseResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceReleaseResponse( objPDUSessionResourceReleaseResponse, ngNode);
}

void com_ngap_handler_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUSessionResourceSetupRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceSetupRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	
	/*
	printf("aMFUENGAPID_isset=%u AMF-UE-NGAP-ID=%llu\n", objPDUSessionResourceSetupRequest->aMFUENGAPID_isset, objPDUSessionResourceSetupRequest->aMFUENGAPID);
	
	if( objPDUSessionResourceSetupRequest->aMFUENGAPID_isset == 1)
	{
		printf("AMF-UE-NGAP-ID=%llu\n", objPDUSessionResourceSetupRequest->aMFUENGAPID);
	}
	
	if( objPDUSessionResourceSetupRequest->rANUENGAPID_isset == 1)
	{
		printf("RAN-UE-NGAP-ID=%llu\n", objPDUSessionResourceSetupRequest->rANUENGAPID);
	}
	*/
	
	amf_ngap_procedure_PDUSessionResourceSetupRequest( objPDUSessionResourceSetupRequest, ngNode);
}

void com_ngap_handler_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUSessionResourceSetupResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PDUSessionResourceSetupResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PDUSessionResourceSetupResponse( objPDUSessionResourceSetupResponse, ngNode);
}

void com_ngap_handler_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPrivateMessage, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PrivateMessage message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_handler_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPWSCancelRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PWSCancelRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PWSCancelRequest( objPWSCancelRequest, ngNode);
}

void com_ngap_handler_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPWSCancelResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PWSCancelResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PWSCancelResponse( objPWSCancelResponse, ngNode);
}

void com_ngap_handler_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPWSFailureIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PWSFailureIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PWSFailureIndication( objPWSFailureIndication, ngNode);
}

void com_ngap_handler_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPWSRestartIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received PWSRestartIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_PWSRestartIndication( objPWSRestartIndication, ngNode);
}

void com_ngap_handler_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objRANConfigurationUpdate, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received RANConfigurationUpdate message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_RANConfigurationUpdate( objRANConfigurationUpdate, ngNode);
}

void com_ngap_handler_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objRANConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received RANConfigurationUpdateAcknowledge message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_RANConfigurationUpdateAcknowledge( objRANConfigurationUpdateAcknowledge, ngNode);
}

void com_ngap_handler_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objRANConfigurationUpdateFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received RANConfigurationUpdateFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_RANConfigurationUpdateFailure( objRANConfigurationUpdateFailure, ngNode);
}

void com_ngap_handler_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objRerouteNASRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received RerouteNASRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_RerouteNASRequest( objRerouteNASRequest, ngNode);
}

void com_ngap_handler_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objRRCInactiveTransitionReport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received RRCInactiveTransitionReport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_handler_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objSecondaryRATDataUsageReport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received SecondaryRATDataUsageReport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
}

void com_ngap_handler_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objTraceFailureIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received TraceFailureIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_TraceFailureIndication( objTraceFailureIndication, ngNode);
}

void com_ngap_handler_TraceStart( SI_AMF_DT_PDU_TraceStart * objTraceStart, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received TraceStart message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_TraceStart( objTraceStart, ngNode);
}

void com_ngap_handler_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objUEContextModificationRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UEContextModificationRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UEContextModificationRequest( objUEContextModificationRequest, ngNode);
}

void com_ngap_handler_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objUEContextModificationResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UEContextModificationResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UEContextModificationResponse( objUEContextModificationResponse, ngNode);
}

void com_ngap_handler_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objUEContextModificationFailure, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UEContextModificationFailure message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UEContextModificationFailure( objUEContextModificationFailure, ngNode);
}

void com_ngap_handler_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UEContextReleaseCommand message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UEContextReleaseCommand( objUEContextReleaseCommand, ngNode);
}

void com_ngap_handler_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UEContextReleaseComplete message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UEContextReleaseComplete( objUEContextReleaseComplete, ngNode);
}

void com_ngap_handler_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UEContextReleaseRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UEContextReleaseRequest( objUEContextReleaseRequest, ngNode);
}

void com_ngap_handler_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objUERadioCapabilityCheckRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UERadioCapabilityCheckRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UERadioCapabilityCheckRequest( objUERadioCapabilityCheckRequest, ngNode);
}

void com_ngap_handler_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objUERadioCapabilityCheckResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UERadioCapabilityCheckResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UERadioCapabilityCheckResponse( objUERadioCapabilityCheckResponse, ngNode);
}

void com_ngap_handler_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objUERadioCapabilityInfoIndication, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UERadioCapabilityInfoIndication message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UERadioCapabilityInfoIndication( objUERadioCapabilityInfoIndication, ngNode);
}

void com_ngap_handler_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objUETNLABindingReleaseRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UETNLABindingReleaseRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UETNLABindingReleaseRequest( objUETNLABindingReleaseRequest, ngNode);
}

void com_ngap_handler_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objUplinkNASTransport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UplinkNASTransport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UplinkNASTransport( objUplinkNASTransport, ngNode);
}

void com_ngap_handler_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objUplinkNonUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UplinkNonUEAssociatedNRPPaTransport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UplinkNonUEAssociatedNRPPaTransport( objUplinkNonUEAssociatedNRPPaTransport, ngNode);
}

void com_ngap_handler_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objUplinkRANConfigurationTransfer, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UplinkRANConfigurationTransfer message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UplinkRANConfigurationTransfer( objUplinkRANConfigurationTransfer, ngNode);
}

void com_ngap_handler_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objUplinkRANStatusTransfer, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UplinkRANStatusTransfer message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UplinkRANStatusTransfer( objUplinkRANStatusTransfer, ngNode);
}

void com_ngap_handler_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objUplinkUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received UplinkUEAssociatedNRPPaTransport message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_UplinkUEAssociatedNRPPaTransport( objUplinkUEAssociatedNRPPaTransport, ngNode);
}

void com_ngap_handler_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objWriteReplaceWarningRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received WriteReplaceWarningRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_WriteReplaceWarningRequest( objWriteReplaceWarningRequest, ngNode);
}

void com_ngap_handler_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objWriteReplaceWarningResponse, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received WriteReplaceWarningResponse message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	amf_ngap_procedure_WriteReplaceWarningResponse( objWriteReplaceWarningResponse, ngNode);
}



void com_ngap_handler_initiating_message( uint8_t procedureCode, void * msg, SI_NGAPNode * ngNode)
{
	switch( procedureCode)
	{
		case 0:
			com_ngap_handler_AMFConfigurationUpdate( (SI_AMF_DT_PDU_AMFConfigurationUpdate *)msg, ngNode);
			break;
		case 1:
			com_ngap_handler_AMFStatusIndication( (SI_AMF_DT_PDU_AMFStatusIndication *)msg, ngNode);
			break;
		case 2:
			com_ngap_handler_CellTrafficTrace( (SI_AMF_DT_PDU_CellTrafficTrace *)msg, ngNode);
			break;
		case 3:
			com_ngap_handler_DeactivateTrace( (SI_AMF_DT_PDU_DeactivateTrace *)msg, ngNode);
			break;
		case 4:
			com_ngap_handler_DownlinkNASTransport( (SI_AMF_DT_PDU_DownlinkNASTransport *)msg, ngNode);
			break;
		case 5:
			com_ngap_handler_DownlinkNonUEAssociatedNRPPaTransport( (SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport *)msg, ngNode);
			break;
		case 6:
			com_ngap_handler_DownlinkRANConfigurationTransfer( (SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer *)msg, ngNode);
			break;
		case 7:
			com_ngap_handler_DownlinkRANStatusTransfer( (SI_AMF_DT_PDU_DownlinkRANStatusTransfer *)msg, ngNode);
			break;
		case 8:
			com_ngap_handler_DownlinkUEAssociatedNRPPaTransport( (SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport *)msg, ngNode);
			break;
		case 9:
			com_ngap_handler_ErrorIndication( (SI_AMF_DT_PDU_ErrorIndication *)msg, ngNode);
			break;
		case 10:
			com_ngap_handler_HandoverCancel( (SI_AMF_DT_PDU_HandoverCancel *)msg, ngNode);
			break;
		case 11:
			com_ngap_handler_HandoverNotify( (SI_AMF_DT_PDU_HandoverNotify *)msg, ngNode);
			break;
		case 12:
			com_ngap_handler_HandoverRequired( (SI_AMF_DT_PDU_HandoverRequired *)msg, ngNode);
			break;
		case 13:
			com_ngap_handler_HandoverRequest( (SI_AMF_DT_PDU_HandoverRequest *)msg, ngNode);
			break;
		case 14:
			com_ngap_handler_InitialContextSetupRequest( (SI_AMF_DT_PDU_InitialContextSetupRequest *)msg, ngNode);
			break;
		case 15:
			com_ngap_handler_InitialUEMessage( (SI_AMF_DT_PDU_InitialUEMessage *)msg, ngNode);
			break;
		case 18:
			com_ngap_handler_LocationReport( (SI_AMF_DT_PDU_LocationReport *)msg, ngNode);
			break;
		case 16:
			com_ngap_handler_LocationReportingControl( (SI_AMF_DT_PDU_LocationReportingControl *)msg, ngNode);
			break;
		case 17:
			com_ngap_handler_LocationReportingFailureIndication( (SI_AMF_DT_PDU_LocationReportingFailureIndication *)msg, ngNode);
			break;
		case 19:
			com_ngap_handler_NASNonDeliveryIndication( (SI_AMF_DT_PDU_NASNonDeliveryIndication *)msg, ngNode);
			break;
		case 20:
			com_ngap_handler_NGReset( (SI_AMF_DT_PDU_NGReset *)msg, ngNode);
			break;
		case 21:
			com_ngap_handler_NGSetupRequest( (SI_AMF_DT_PDU_NGSetupRequest *)msg, ngNode);
			break;
		case 22:
			com_ngap_handler_OverloadStart( (SI_AMF_DT_PDU_OverloadStart *)msg, ngNode);
			break;
		case 23:
			com_ngap_handler_OverloadStop( (SI_AMF_DT_PDU_OverloadStop *)msg, ngNode);
			break;
		case 24:
			com_ngap_handler_Paging( (SI_AMF_DT_PDU_Paging *)msg, ngNode);
			break;
		case 25:
			com_ngap_handler_PathSwitchRequest( (SI_AMF_DT_PDU_PathSwitchRequest *)msg, ngNode);
			break;
		case 26:
			com_ngap_handler_PDUSessionResourceModifyRequest( (SI_AMF_DT_PDU_PDUSessionResourceModifyRequest *)msg, ngNode);
			break;
		case 27:
			com_ngap_handler_PDUSessionResourceModifyIndication( (SI_AMF_DT_PDU_PDUSessionResourceModifyIndication *)msg, ngNode);
			break;
		case 30:
			com_ngap_handler_PDUSessionResourceNotify( (SI_AMF_DT_PDU_PDUSessionResourceNotify *)msg, ngNode);
			break;
		case 28:
			com_ngap_handler_PDUSessionResourceReleaseCommand( (SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand *)msg, ngNode);
			break;
		case 29:
			com_ngap_handler_PDUSessionResourceSetupRequest( (SI_AMF_DT_PDU_PDUSessionResourceSetupRequest *)msg, ngNode);
			break;
		case 31:
			com_ngap_handler_PrivateMessage( (SI_AMF_DT_PDU_PrivateMessage *)msg, ngNode);
			break;
		case 32:
			com_ngap_handler_PWSCancelRequest( (SI_AMF_DT_PDU_PWSCancelRequest *)msg, ngNode);
			break;
		case 33:
			com_ngap_handler_PWSFailureIndication( (SI_AMF_DT_PDU_PWSFailureIndication *)msg, ngNode);
			break;
		case 34:
			com_ngap_handler_PWSRestartIndication( (SI_AMF_DT_PDU_PWSRestartIndication *)msg, ngNode);
			break;
		case 35:
			com_ngap_handler_RANConfigurationUpdate( (SI_AMF_DT_PDU_RANConfigurationUpdate *)msg, ngNode);
			break;
		case 36:
			com_ngap_handler_RerouteNASRequest( (SI_AMF_DT_PDU_RerouteNASRequest *)msg, ngNode);
			break;
		case 37:
			com_ngap_handler_RRCInactiveTransitionReport( (SI_AMF_DT_PDU_RRCInactiveTransitionReport *)msg, ngNode);
			break;
		case 52:
			com_ngap_handler_SecondaryRATDataUsageReport( (SI_AMF_DT_PDU_SecondaryRATDataUsageReport *)msg, ngNode);
			break;
		case 38:
			com_ngap_handler_TraceFailureIndication( (SI_AMF_DT_PDU_TraceFailureIndication *)msg, ngNode);
			break;
		case 39:
			com_ngap_handler_TraceStart( (SI_AMF_DT_PDU_TraceStart *)msg, ngNode);
			break;
		case 40:
			com_ngap_handler_UEContextModificationRequest( (SI_AMF_DT_PDU_UEContextModificationRequest *)msg, ngNode);
			break;
		case 41:
			com_ngap_handler_UEContextReleaseCommand( (SI_AMF_DT_PDU_UEContextReleaseCommand *)msg, ngNode);
			break;
		case 42:
			com_ngap_handler_UEContextReleaseRequest( (SI_AMF_DT_PDU_UEContextReleaseRequest *)msg, ngNode);
			break;
		case 43:
			com_ngap_handler_UERadioCapabilityCheckRequest( (SI_AMF_DT_PDU_UERadioCapabilityCheckRequest *)msg, ngNode);
			break;
		case 44:
			com_ngap_handler_UERadioCapabilityInfoIndication( (SI_AMF_DT_PDU_UERadioCapabilityInfoIndication *)msg, ngNode);
			break;
		case 45:
			com_ngap_handler_UETNLABindingReleaseRequest( (SI_AMF_DT_PDU_UETNLABindingReleaseRequest *)msg, ngNode);
			break;
		case 46:
			com_ngap_handler_UplinkNASTransport( (SI_AMF_DT_PDU_UplinkNASTransport *)msg, ngNode);
			break;
		case 47:
			com_ngap_handler_UplinkNonUEAssociatedNRPPaTransport( (SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport *)msg, ngNode);
			break;
		case 48:
			com_ngap_handler_UplinkRANConfigurationTransfer( (SI_AMF_DT_PDU_UplinkRANConfigurationTransfer *)msg, ngNode);
			break;
		case 49:
			com_ngap_handler_UplinkRANStatusTransfer( (SI_AMF_DT_PDU_UplinkRANStatusTransfer *)msg, ngNode);
			break;
		case 50:
			com_ngap_handler_UplinkUEAssociatedNRPPaTransport( (SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport *)msg, ngNode);
			break;
		case 51:
			com_ngap_handler_WriteReplaceWarningRequest( (SI_AMF_DT_PDU_WriteReplaceWarningRequest *)msg, ngNode);
			break;
		default:
			break;
	}
}

void com_ngap_handler_successful_message( uint8_t procedureCode, void * msg, SI_NGAPNode * ngNode)
{
	switch( procedureCode)
	{
		case 0:
			com_ngap_handler_AMFConfigurationUpdateAcknowledge( (SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge *)msg, ngNode);
			break;
		case 10:
			com_ngap_handler_HandoverCancelAcknowledge( (SI_AMF_DT_PDU_HandoverCancelAcknowledge *)msg, ngNode);
			break;
		case 12:
			com_ngap_handler_HandoverCommand( (SI_AMF_DT_PDU_HandoverCommand *)msg, ngNode);
			break;
		case 13:
			com_ngap_handler_HandoverRequestAcknowledge( (SI_AMF_DT_PDU_HandoverRequestAcknowledge *)msg, ngNode);
			break;
		case 14:
			com_ngap_handler_InitialContextSetupResponse( (SI_AMF_DT_PDU_InitialContextSetupResponse *)msg, ngNode);
			break;
		case 20:
			com_ngap_handler_NGResetAcknowledge( (SI_AMF_DT_PDU_NGResetAcknowledge *)msg, ngNode);
			break;
		case 21:
			com_ngap_handler_NGSetupResponse( (SI_AMF_DT_PDU_NGSetupResponse *)msg, ngNode);
			break;
		case 25:
			com_ngap_handler_PathSwitchRequestAcknowledge( (SI_AMF_DT_PDU_PathSwitchRequestAcknowledge *)msg, ngNode);
			break;
		case 26:
			com_ngap_handler_PDUSessionResourceModifyResponse( (SI_AMF_DT_PDU_PDUSessionResourceModifyResponse *)msg, ngNode);
			break;
		case 27:
			com_ngap_handler_PDUSessionResourceModifyConfirm( (SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm *)msg, ngNode);
			break;
		case 28:
			com_ngap_handler_PDUSessionResourceReleaseResponse( (SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse *)msg, ngNode);
			break;
		case 29:
			com_ngap_handler_PDUSessionResourceSetupResponse( (SI_AMF_DT_PDU_PDUSessionResourceSetupResponse *)msg, ngNode);
			break;
		case 32:
			com_ngap_handler_PWSCancelResponse( (SI_AMF_DT_PDU_PWSCancelResponse *)msg, ngNode);
			break;
		case 35:
			com_ngap_handler_RANConfigurationUpdateAcknowledge( (SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge *)msg, ngNode);
			break;
		case 40:
			com_ngap_handler_UEContextModificationResponse( (SI_AMF_DT_PDU_UEContextModificationResponse *)msg, ngNode);
			break;
		case 41:
			com_ngap_handler_UEContextReleaseComplete( (SI_AMF_DT_PDU_UEContextReleaseComplete *)msg, ngNode);
			break;
		case 43:
			com_ngap_handler_UERadioCapabilityCheckResponse( (SI_AMF_DT_PDU_UERadioCapabilityCheckResponse *)msg, ngNode);
			break;
		case 51:
			com_ngap_handler_WriteReplaceWarningResponse( (SI_AMF_DT_PDU_WriteReplaceWarningResponse *)msg, ngNode);
			break;
		default:
			break;
	}
}

void com_ngap_handler_unsuccessful_message( uint8_t procedureCode, void * msg, SI_NGAPNode * ngNode)
{
	switch( procedureCode)
	{
		case 0:
			com_ngap_handler_AMFConfigurationUpdateFailure( (SI_AMF_DT_PDU_AMFConfigurationUpdateFailure *)msg, ngNode);
			break;
		case 12:
			com_ngap_handler_HandoverPreparationFailure( (SI_AMF_DT_PDU_HandoverPreparationFailure *)msg, ngNode);
			break;
		case 13:
			com_ngap_handler_HandoverFailure( (SI_AMF_DT_PDU_HandoverFailure *)msg, ngNode);
			break;
		case 14:
			com_ngap_handler_InitialContextSetupFailure( (SI_AMF_DT_PDU_InitialContextSetupFailure *)msg, ngNode);
			break;
		case 21:
			com_ngap_handler_NGSetupFailure( (SI_AMF_DT_PDU_NGSetupFailure *)msg, ngNode);
			break;
		case 25:
			com_ngap_handler_PathSwitchRequestFailure( (SI_AMF_DT_PDU_PathSwitchRequestFailure *)msg, ngNode);
			break;
		case 35:
			com_ngap_handler_RANConfigurationUpdateFailure( (SI_AMF_DT_PDU_RANConfigurationUpdateFailure *)msg, ngNode);
			break;
		case 40:
			com_ngap_handler_UEContextModificationFailure( (SI_AMF_DT_PDU_UEContextModificationFailure *)msg, ngNode);
			break;		
		default:
			break;
	}
}

void com_ngap_handler_message( uint8_t procedureCode, uint8_t messageType, void * msg, SI_NGAPNode * ngNode)
{
	switch( messageType)
	{
		case 0:
			com_ngap_handler_initiating_message( procedureCode, msg, ngNode);
			break;
		case 1:
			com_ngap_handler_successful_message( procedureCode, msg, ngNode);
			break;
		case 2:
			com_ngap_handler_unsuccessful_message( procedureCode, msg, ngNode);
			break;
		default:
			break;
	}
}

void com_ngap_set_message_handler()
{
	__si_ngap_set_app_messahe_handler( com_ngap_handler_message);
}


