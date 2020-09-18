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
#include "app_ngap_test_data.h"

int __si_amf_debug_pdu_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUPDUSessionResourceSetupRequest);

void __ngran_ngap_create_and_send_PDUSessionResourceSetup()
{
	SI_AMF_DT_PDU_PDUSessionResourceSetupRequest objPDUSessionResourceSetupRequest;
	memset( &objPDUSessionResourceSetupRequest, 0, sizeof(SI_AMF_DT_PDU_PDUSessionResourceSetupRequest));

	/**/
	objPDUSessionResourceSetupRequest.aMFUENGAPID = 4567;
	objPDUSessionResourceSetupRequest.aMFUENGAPID_isset = 1;
	
	objPDUSessionResourceSetupRequest.rANUENGAPID = 1234321;
	objPDUSessionResourceSetupRequest.rANUENGAPID_isset = 1;

	objPDUSessionResourceSetupRequest.rANPagingPriority = 256;
	objPDUSessionResourceSetupRequest.rANPagingPriority_isset = 1;
	
	__app_ngap_set_UEAggregateMaximumBitRate( &objPDUSessionResourceSetupRequest.uEAggregateMaximumBitRate);
	objPDUSessionResourceSetupRequest.uEAggregateMaximumBitRate_isset = 1;
	
	/**/
	__app_ngap_set_PDUSessionResourceSetupListSUReq( &objPDUSessionResourceSetupRequest.pDUSessionResourceSetupListSUReq);
	objPDUSessionResourceSetupRequest.pDUSessionResourceSetupListSUReq_isset = 1;
	
	__si_amf_debug_pdu_PDUSessionResourceSetupRequest( &objPDUSessionResourceSetupRequest);
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PDUSessionResourceSetupRequest( &objPDUSessionResourceSetupRequest, ngranNode);
}


void __ngran_ngap_create_and_send_PDUSessionResourceReleaseCommand()
{
	SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand objPDUSessionResourceReleaseCommand;
	memset( &objPDUSessionResourceReleaseCommand, 0, sizeof(SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand));

	objPDUSessionResourceReleaseCommand.aMFUENGAPID = 4567;
	objPDUSessionResourceReleaseCommand.aMFUENGAPID_isset = 1;
	
	objPDUSessionResourceReleaseCommand.rANUENGAPID = 1234321;
	objPDUSessionResourceReleaseCommand.rANUENGAPID_isset = 1;
	
	objPDUSessionResourceReleaseCommand.rANPagingPriority = 12;
	objPDUSessionResourceReleaseCommand.rANPagingPriority_isset = 1;

	__app_ngap_set_PDUSessionResourceToReleaseListRelCmd( &objPDUSessionResourceReleaseCommand.pDUSessionResourceToReleaseListRelCmd);
	objPDUSessionResourceReleaseCommand.pDUSessionResourceToReleaseListRelCmd_isset = 1;	
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PDUSessionResourceReleaseCommand( &objPDUSessionResourceReleaseCommand, ngranNode);
}

void __ngran_ngap_create_and_send_PDUSessionResourceModify()
{
	SI_AMF_DT_PDU_PDUSessionResourceModifyRequest objPDUSessionResourceModifyRequest;
	memset( &objPDUSessionResourceModifyRequest, 0, sizeof(SI_AMF_DT_PDU_PDUSessionResourceModifyRequest));
	
	objPDUSessionResourceModifyRequest.aMFUENGAPID = 45678944;
	objPDUSessionResourceModifyRequest.aMFUENGAPID_isset = 1;
	
	objPDUSessionResourceModifyRequest.rANUENGAPID = 1234321;
	objPDUSessionResourceModifyRequest.rANUENGAPID_isset = 1;
	
	objPDUSessionResourceModifyRequest.rANPagingPriority = 15;
	objPDUSessionResourceModifyRequest.rANPagingPriority_isset = 1;
	
	__app_ngap_set_PDUSessionResourceModifyListModReq( &objPDUSessionResourceModifyRequest.pDUSessionResourceModifyListModReq);
	objPDUSessionResourceModifyRequest.pDUSessionResourceModifyListModReq_isset = 1;	
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PDUSessionResourceModifyRequest( &objPDUSessionResourceModifyRequest, ngranNode);	
}

void __ngran_ngap_create_and_send_PDUSessionResourceNotify()
{
	SI_AMF_DT_PDU_PDUSessionResourceNotify objPDUSessionResourceNotify;
	memset( &objPDUSessionResourceNotify, 0, sizeof(SI_AMF_DT_PDU_PDUSessionResourceNotify));
	
	objPDUSessionResourceNotify.aMFUENGAPID = 45678944;
	objPDUSessionResourceNotify.aMFUENGAPID_isset = 1;
	
	objPDUSessionResourceNotify.rANUENGAPID = 1234321;
	objPDUSessionResourceNotify.rANUENGAPID_isset = 1;
	
	__app_ngap_set_PDUSessionResourceNotifyList( &objPDUSessionResourceNotify.pDUSessionResourceNotifyList);
	objPDUSessionResourceNotify.pDUSessionResourceNotifyList_isset = 1;
	
	__app_ngap_set_PDUSessionResourceReleasedListNot( &objPDUSessionResourceNotify.pDUSessionResourceReleasedListNot);
	objPDUSessionResourceNotify.pDUSessionResourceReleasedListNot_isset = 1;
	
	__app_ngap_set_UserLocationInformation( &objPDUSessionResourceNotify.userLocationInformation);
	objPDUSessionResourceNotify.userLocationInformation_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PDUSessionResourceNotify( &objPDUSessionResourceNotify, ngranNode);	
}

void __ngran_ngap_create_and_send_PDUSessionResourceModifyIndication()
{
	SI_AMF_DT_PDU_PDUSessionResourceModifyIndication objPDUSessionResourceModifyIndication;
	memset( &objPDUSessionResourceModifyIndication, 0, sizeof(SI_AMF_DT_PDU_PDUSessionResourceModifyIndication));
	
// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:7292
	objPDUSessionResourceModifyIndication.aMFUENGAPID = 789789;;
	objPDUSessionResourceModifyIndication.aMFUENGAPID_isset = 1;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:7292
	objPDUSessionResourceModifyIndication.rANUENGAPID = 9988988;
	objPDUSessionResourceModifyIndication.rANUENGAPID_isset = 1;	
	
	//
	__app_ngap_set_PDUSessionResourceModifyListModInd( &objPDUSessionResourceModifyIndication.pDUSessionResourceModifyListModInd);
	objPDUSessionResourceModifyIndication.pDUSessionResourceModifyListModInd_isset = 1;
	
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PDUSessionResourceModifyIndication( &objPDUSessionResourceModifyIndication, ngranNode);
}

void __ngran_ngap_pdu_session_management()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 PDU Session Resource Setup:\n");
		printf("2 PDU Session Resource Release:\n");
		printf("3 PDU Session Resource Modify:\n");
		printf("4 PDU Session Resource Notify:\n");
		printf("5 PDU Session Resource Modify Indication:\n");
		printf("6 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 6)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_PDUSessionResourceSetup();
					break;
				case 2:
					__ngran_ngap_create_and_send_PDUSessionResourceReleaseCommand();
					break;
				case 3:
					__ngran_ngap_create_and_send_PDUSessionResourceModify();
					break;
				case 4:
					__ngran_ngap_create_and_send_PDUSessionResourceNotify();
					break;
				case 5:
					__ngran_ngap_create_and_send_PDUSessionResourceModifyIndication();
					break;
				case 6:
					bExit = 1;
					break;
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}


void __ngran_ngap_create_and_send_InitialContextSetup()
{
	SI_AMF_DT_PDU_InitialContextSetupRequest objInitialContextSetupRequest;
	memset( &objInitialContextSetupRequest, 0, sizeof(SI_AMF_DT_PDU_InitialContextSetupRequest));
	
	objInitialContextSetupRequest.aMFUENGAPID = 4567;
	objInitialContextSetupRequest.aMFUENGAPID_isset = 1;
	
	objInitialContextSetupRequest.rANUENGAPID = 1234321;
	objInitialContextSetupRequest.rANUENGAPID_isset = 1;
	
	__app_ngap_set_AMFName( &objInitialContextSetupRequest.oldAMF);
	objInitialContextSetupRequest.oldAMF_isset = 1;
	
	__app_ngap_set_UEAggregateMaximumBitRate( &objInitialContextSetupRequest.uEAggregateMaximumBitRate);
	objInitialContextSetupRequest.uEAggregateMaximumBitRate_isset = 1;
	
	__app_ngap_set_CoreNetworkAssistanceInformationForInactive( &objInitialContextSetupRequest.coreNetworkAssistanceInformationForInactive);
	objInitialContextSetupRequest.coreNetworkAssistanceInformationForInactive_isset = 1;
	
	__app_ngap_set_GUAMI( &objInitialContextSetupRequest.gUAMI);
	objInitialContextSetupRequest.gUAMI_isset = 1;
	
	__app_ngap_set_PDUSessionResourceSetupListCxtReq( &objInitialContextSetupRequest.pDUSessionResourceSetupListCxtReq);
	objInitialContextSetupRequest.pDUSessionResourceSetupListCxtReq_isset = 1;
	
	__app_ngap_set_AllowedNSSAI( &objInitialContextSetupRequest.allowedNSSAI);
	objInitialContextSetupRequest.allowedNSSAI_isset = 1;
	
	__app_ngap_set_UESecurityCapabilities( &objInitialContextSetupRequest.uESecurityCapabilities);
	objInitialContextSetupRequest.uESecurityCapabilities_isset = 1;
	
	__app_ngap_set_SecurityKey( &objInitialContextSetupRequest.securityKey);
	objInitialContextSetupRequest.securityKey_isset = 1;
	
	__app_ngap_set_TraceActivation( &objInitialContextSetupRequest.traceActivation);
	objInitialContextSetupRequest.traceActivation_isset = 1;
	
	__app_ngap_set_MobilityRestrictionList( &objInitialContextSetupRequest.mobilityRestrictionList);
	objInitialContextSetupRequest.mobilityRestrictionList_isset = 1;

	__app_ngap_set_UERadioCapability( &objInitialContextSetupRequest.uERadioCapability);;
	objInitialContextSetupRequest.uERadioCapability_isset = 1;
	
	objInitialContextSetupRequest.indexToRFSP = 254;
	objInitialContextSetupRequest.indexToRFSP_isset = 1;

	__app_ngap_set_EmergencyFallbackIndicator( &objInitialContextSetupRequest.emergencyFallbackIndicator);
	objInitialContextSetupRequest.emergencyFallbackIndicator_isset = 1;

	__app_ngap_set_MaskedIMEISV( &objInitialContextSetupRequest.maskedIMEISV);
	objInitialContextSetupRequest.maskedIMEISV_isset = 1;	
	
	objInitialContextSetupRequest.rRCInactiveTransitionReportRequest = 2;
	objInitialContextSetupRequest.rRCInactiveTransitionReportRequest_isset = 1;
	
	__app_ngap_set_UERadioCapabilityForPaging( &objInitialContextSetupRequest.uERadioCapabilityForPaging);
	objInitialContextSetupRequest.uERadioCapabilityForPaging_isset = 1;
	
	__app_ngap_set_LocationReportingRequestType( &objInitialContextSetupRequest.locationReportingRequestType);
	objInitialContextSetupRequest.locationReportingRequestType_isset = 1;
	
	__app_ngap_set_CNAssistedRANTuning( &objInitialContextSetupRequest.cNAssistedRANTuning);
	objInitialContextSetupRequest.cNAssistedRANTuning_isset = 1;
	
	__si_amf_debug_pdu_InitialContextSetupRequest( &objInitialContextSetupRequest);
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_InitialContextSetupRequest( &objInitialContextSetupRequest, ngranNode);
}

void __ngran_ngap_create_and_send_UEContextReleaseRequest()
{
	SI_AMF_DT_PDU_UEContextReleaseRequest objUEContextReleaseRequest;
	memset( &objUEContextReleaseRequest, 0, sizeof(SI_AMF_DT_PDU_UEContextReleaseRequest));
	
	objUEContextReleaseRequest.aMFUENGAPID = 56321;
	objUEContextReleaseRequest.aMFUENGAPID_isset = 1;
	
	objUEContextReleaseRequest.rANUENGAPID = 56321;
	objUEContextReleaseRequest.rANUENGAPID_isset = 1;	
	
	__app_ngap_set_PDUSessionResourceListCxtRelReq( &objUEContextReleaseRequest.pDUSessionResourceListCxtRelReq);
	objUEContextReleaseRequest.pDUSessionResourceListCxtRelReq_isset = 1;

	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UEContextReleaseRequest( &objUEContextReleaseRequest, ngranNode);	
}

void __ngran_ngap_create_and_send_UEContextReleaseCommand()
{
	SI_AMF_DT_PDU_UEContextReleaseCommand objUEContextReleaseCommand;
	memset( &objUEContextReleaseCommand, 0, sizeof(SI_AMF_DT_PDU_UEContextReleaseCommand));
	
	__app_ngap_set_UE_NGAP_IDs( &objUEContextReleaseCommand.uENGAPIDs);
	objUEContextReleaseCommand.uENGAPIDs_isset = 1;	

	__app_ngap_set_Cause( &objUEContextReleaseCommand.cause);
	objUEContextReleaseCommand.cause_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UEContextReleaseCommand( &objUEContextReleaseCommand, ngranNode);	
}

void __ngran_ngap_create_and_send_UEContextModificationRequest()
{
	SI_AMF_DT_PDU_UEContextModificationRequest objUEContextModificationRequest;
	memset( &objUEContextModificationRequest, 0, sizeof(SI_AMF_DT_PDU_UEContextModificationRequest));
	
	objUEContextModificationRequest.aMFUENGAPID = 456456456;
	objUEContextModificationRequest.aMFUENGAPID_isset = 1;
	
	objUEContextModificationRequest.rANUENGAPID = 456844;
	objUEContextModificationRequest.rANUENGAPID_isset = 1;
	
	objUEContextModificationRequest.rANPagingPriority = 34;
	objUEContextModificationRequest.rANPagingPriority_isset = 1;
	
	//SI_AMF_DT_SecurityKey * securityKey;
	__app_ngap_set_SecurityKey( &objUEContextModificationRequest.securityKey);
	objUEContextModificationRequest.securityKey_isset = 1;

	objUEContextModificationRequest.indexToRFSP = 51;
	objUEContextModificationRequest.indexToRFSP_isset = 1;
	
	//SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate;
	__app_ngap_set_UEAggregateMaximumBitRate( &objUEContextModificationRequest.uEAggregateMaximumBitRate);
	objUEContextModificationRequest.uEAggregateMaximumBitRate_isset = 1;
	
	//SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities;
	__app_ngap_set_UESecurityCapabilities( &objUEContextModificationRequest.uESecurityCapabilities);
	objUEContextModificationRequest.uESecurityCapabilities_isset = 1;
	
	//SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * coreNetworkAssistanceInformationForInactive;
	__app_ngap_set_CoreNetworkAssistanceInformationForInactive( &objUEContextModificationRequest.coreNetworkAssistanceInformationForInactive);
	objUEContextModificationRequest.coreNetworkAssistanceInformationForInactive_isset = 1;
	
	//SI_AMF_DT_EmergencyFallbackIndicator * emergencyFallbackIndicator;
	__app_ngap_set_EmergencyFallbackIndicator( &objUEContextModificationRequest.emergencyFallbackIndicator);
	objUEContextModificationRequest.emergencyFallbackIndicator_isset = 1;
	
	objUEContextModificationRequest.newAMFUENGAPID = 5454555;
	objUEContextModificationRequest.newAMFUENGAPID_isset = 1;
	
	objUEContextModificationRequest.rRCInactiveTransitionReportRequest = 1;
	objUEContextModificationRequest.rRCInactiveTransitionReportRequest_isset = 1;

	__app_ngap_set_GUAMI( &objUEContextModificationRequest.newGUAMI);
	objUEContextModificationRequest.newGUAMI_isset = 1;
	
	__app_ngap_set_CNAssistedRANTuning( &objUEContextModificationRequest.cNAssistedRANTuning);
	objUEContextModificationRequest.cNAssistedRANTuning_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UEContextModificationRequest( &objUEContextModificationRequest, ngranNode);	
}



void __ngran_ngap_ue_context_management()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Initial Context Setup:\n");
		printf("2 UE Context Release Request:\n");
		printf("3 UE Context Release:\n");
		printf("4 UE Context Modification:\n");
		printf("5 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 5)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_InitialContextSetup();
					break;
				case 2:
					__ngran_ngap_create_and_send_UEContextReleaseRequest();
					break;
				case 3:
					__ngran_ngap_create_and_send_UEContextReleaseCommand();
					break;
				case 4:
					__ngran_ngap_create_and_send_UEContextModificationRequest();
					break;
				case 5:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_ngap_create_and_send_HandoverRequired()
{
	SI_AMF_DT_PDU_HandoverRequired objHandoverRequired;
	memset( &objHandoverRequired, 0, sizeof(SI_AMF_DT_PDU_HandoverRequired));
	
	objHandoverRequired.aMFUENGAPID = 47854785;
	objHandoverRequired.aMFUENGAPID_isset = 1;
	
	objHandoverRequired.rANUENGAPID = 587458745;
	objHandoverRequired.rANUENGAPID_isset = 1;
	
	objHandoverRequired.handoverType = 2;
	objHandoverRequired.handoverType_isset = 1;
	
	__app_ngap_set_Cause( &objHandoverRequired.cause);
	objHandoverRequired.cause_isset = 1;
	
	__app_ngap_set_TargetID( &objHandoverRequired.targetID);
	objHandoverRequired.targetID_isset = 1;
	
	objHandoverRequired.directForwardingPathAvailability = 0;
	objHandoverRequired.directForwardingPathAvailability_isset = 1;
	
	__app_ngap_set_PDUSessionResourceListHORqd( &objHandoverRequired.pDUSessionResourceListHORqd);
	objHandoverRequired.pDUSessionResourceListHORqd_isset = 1;
	
	__app_ngap_set_SourceToTarget_TransparentContainer( &objHandoverRequired.sourceToTargetTransparentContainer);
	objHandoverRequired.sourceToTargetTransparentContainer_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_HandoverRequired( &objHandoverRequired, ngranNode);	
}

void __ngran_ngap_create_and_send_HandoverRequest()
{
	SI_AMF_DT_PDU_HandoverRequest objHandoverRequest;
	memset( &objHandoverRequest, 0, sizeof(SI_AMF_DT_PDU_HandoverRequest));
	
	objHandoverRequest.aMFUENGAPID = 456456;
	objHandoverRequest.aMFUENGAPID_isset = 1;
	
	objHandoverRequest.handoverType = 2;
	objHandoverRequest.handoverType_isset = 1;
	
	__app_ngap_set_Cause( &objHandoverRequest.cause);
	objHandoverRequest.cause_isset = 1;
	
	__app_ngap_set_UEAggregateMaximumBitRate( &objHandoverRequest.uEAggregateMaximumBitRate);
	objHandoverRequest.uEAggregateMaximumBitRate_isset = 1;	
	
	__app_ngap_set_CoreNetworkAssistanceInformationForInactive( &objHandoverRequest.coreNetworkAssistanceInformationForInactive);
	objHandoverRequest.coreNetworkAssistanceInformationForInactive_isset = 1;
	
	__app_ngap_set_UESecurityCapabilities( &objHandoverRequest.uESecurityCapabilities);
	objHandoverRequest.uESecurityCapabilities_isset = 1;
	
	__app_ngap_set_SecurityContext( &objHandoverRequest.securityContext);
	objHandoverRequest.securityContext_isset = 1;	

	objHandoverRequest.newSecurityContextInd = 0;
	objHandoverRequest.newSecurityContextInd_isset = 1;
	
	__app_ngap_set_PDUSessionResourceSetupListHOReq( &objHandoverRequest.pDUSessionResourceSetupListHOReq);
	objHandoverRequest.pDUSessionResourceSetupListHOReq_isset = 1;
	
	__app_ngap_set_AllowedNSSAI( &objHandoverRequest.allowedNSSAI);
	objHandoverRequest.allowedNSSAI_isset = 1;	
	
	__app_ngap_set_TraceActivation( &objHandoverRequest.traceActivation);
	objHandoverRequest.traceActivation_isset = 1;	

	__app_ngap_set_MaskedIMEISV( &objHandoverRequest.maskedIMEISV);
	objHandoverRequest.maskedIMEISV_isset = 1;
	
	__app_ngap_set_SourceToTarget_TransparentContainer( &objHandoverRequest.sourceToTargetTransparentContainer);
	objHandoverRequest.sourceToTargetTransparentContainer_isset = 1;	
	
	__app_ngap_set_MobilityRestrictionList( &objHandoverRequest.mobilityRestrictionList);
	objHandoverRequest.mobilityRestrictionList_isset = 1;	
	
	__app_ngap_set_LocationReportingRequestType( &objHandoverRequest.locationReportingRequestType);
	objHandoverRequest.locationReportingRequestType_isset = 1;
	
	objHandoverRequest.rRCInactiveTransitionReportRequest = 0;
	objHandoverRequest.rRCInactiveTransitionReportRequest_isset = 1;

	__app_ngap_set_GUAMI( &objHandoverRequest.gUAMI);
	objHandoverRequest.gUAMI_isset = 1;
	
	__app_ngap_set_CNAssistedRANTuning( &objHandoverRequest.cNAssistedRANTuning);
	objHandoverRequest.cNAssistedRANTuning_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_HandoverRequest( &objHandoverRequest, ngranNode);	
}

void __ngran_ngap_create_and_send_HandoverNotify()
{
	SI_AMF_DT_PDU_HandoverNotify objHandoverNotify;
	memset( &objHandoverNotify, 0, sizeof(SI_AMF_DT_PDU_HandoverNotify));
	
	objHandoverNotify.aMFUENGAPID = 54321;
	objHandoverNotify.aMFUENGAPID_isset = 1;
	
	objHandoverNotify.rANUENGAPID = 23521;
	objHandoverNotify.rANUENGAPID_isset = 1;

	__app_ngap_set_UserLocationInformation( &objHandoverNotify.userLocationInformation);
	objHandoverNotify.userLocationInformation_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_HandoverNotify( &objHandoverNotify, ngranNode);	
}

void __ngran_ngap_create_and_send_PathSwitchRequest()
{
	SI_AMF_DT_PDU_PathSwitchRequest objPathSwitchRequest;
	memset( &objPathSwitchRequest, 0, sizeof(SI_AMF_DT_PDU_PathSwitchRequest));
	
	objPathSwitchRequest.rANUENGAPID = 456456;
	objPathSwitchRequest.rANUENGAPID_isset = 1;
	
	objPathSwitchRequest.sourceAMFUENGAPID = 15151561;
	objPathSwitchRequest.sourceAMFUENGAPID_isset = 1;
	
	__app_ngap_set_UserLocationInformation( &objPathSwitchRequest.userLocationInformation);
	objPathSwitchRequest.userLocationInformation_isset = 1;
	
	__app_ngap_set_UESecurityCapabilities( &objPathSwitchRequest.uESecurityCapabilities);
	objPathSwitchRequest.uESecurityCapabilities_isset = 1;
	
	__app_ngap_set_PDUSessionResourceToBeSwitchedDLList( &objPathSwitchRequest.pDUSessionResourceToBeSwitchedDLList);
	objPathSwitchRequest.pDUSessionResourceToBeSwitchedDLList_isset = 1;

	__app_ngap_set_PDUSessionResourceFailedToSetupListPSReq( &objPathSwitchRequest.pDUSessionResourceFailedToSetupListPSReq);
	objPathSwitchRequest.pDUSessionResourceFailedToSetupListPSReq_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PathSwitchRequest( &objPathSwitchRequest, ngranNode);	
}

void __ngran_ngap_create_and_send_HandoverCancellation()
{
	SI_AMF_DT_PDU_HandoverCancel objHandoverCancellation;
	memset( &objHandoverCancellation, 0, sizeof(SI_AMF_DT_PDU_HandoverCancel));
	
	objHandoverCancellation.aMFUENGAPID = 47854785;
	objHandoverCancellation.aMFUENGAPID_isset = 1;
	
	objHandoverCancellation.rANUENGAPID = 587458745;
	objHandoverCancellation.rANUENGAPID_isset = 1;
	
	__app_ngap_set_Cause( &objHandoverCancellation.cause);
	objHandoverCancellation.cause_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_HandoverCancel( &objHandoverCancellation, ngranNode);	
}

void __ngran_ngap_create_and_send_UplinkRANStatusTransfer()
{
	SI_AMF_DT_PDU_UplinkRANStatusTransfer objUplinkRANStatusTransfer;
	memset( &objUplinkRANStatusTransfer, 0, sizeof(SI_AMF_DT_PDU_UplinkRANStatusTransfer));
	
	objUplinkRANStatusTransfer.aMFUENGAPID = 47854785;
	objUplinkRANStatusTransfer.aMFUENGAPID_isset = 1;
	
	objUplinkRANStatusTransfer.rANUENGAPID = 587458745;
	objUplinkRANStatusTransfer.rANUENGAPID_isset = 1;
	
	__app_ngap_set_RANStatusTransfer_TransparentContainer( &objUplinkRANStatusTransfer.rANStatusTransferTransparentContainer);
	objUplinkRANStatusTransfer.rANStatusTransferTransparentContainer_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UplinkRANStatusTransfer( &objUplinkRANStatusTransfer, ngranNode);	
}

void __ngran_ngap_create_and_send_DownlinkRANStatusTransfer()
{
	SI_AMF_DT_PDU_DownlinkRANStatusTransfer objDownlinkRANStatusTransfer;
	memset( &objDownlinkRANStatusTransfer, 0, sizeof(SI_AMF_DT_PDU_DownlinkRANStatusTransfer));
	
	objDownlinkRANStatusTransfer.aMFUENGAPID = 47854785;
	objDownlinkRANStatusTransfer.aMFUENGAPID_isset = 1;
	
	objDownlinkRANStatusTransfer.rANUENGAPID = 587458745;
	objDownlinkRANStatusTransfer.rANUENGAPID_isset = 1;
	
	__app_ngap_set_RANStatusTransfer_TransparentContainer( &objDownlinkRANStatusTransfer.rANStatusTransferTransparentContainer);
	objDownlinkRANStatusTransfer.rANStatusTransferTransparentContainer_isset = 1;
	
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_DownlinkRANStatusTransfer( &objDownlinkRANStatusTransfer, ngranNode);	
}

void __ngran_ngap_ue_mobility_management()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Handover Preparation:\n");
		printf("2 Handover Request:\n");
		printf("3 Handover Notification:\n");
		printf("4 Path Switch Request:\n");
		printf("5 Handover Cancellation:\n");
		printf("6 Uplink RAN Status Transfer:\n");
		printf("7 Downlink RAN Status Transfer:\n");
		printf("8 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 8)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_HandoverRequired();
					break;
				case 2:
					__ngran_ngap_create_and_send_HandoverRequest();
					break;
				case 3:
					__ngran_ngap_create_and_send_HandoverNotify();
					break;
				case 4:
					__ngran_ngap_create_and_send_PathSwitchRequest();
					break;
				case 5:
					__ngran_ngap_create_and_send_HandoverCancellation();
					break;
				case 6:
					__ngran_ngap_create_and_send_UplinkRANStatusTransfer();
					break;
				case 7:
					__ngran_ngap_create_and_send_DownlinkRANStatusTransfer();
					break;
				case 8:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}	
}

void __ngran_ngap_paging()
{
	SI_AMF_DT_PDU_Paging objPaging;
	memset( &objPaging, 0, sizeof(SI_AMF_DT_PDU_Paging));
	
	
	__app_ngap_set_UEPagingIdentity( &objPaging.uEPagingIdentity);
	objPaging.uEPagingIdentity_isset = 1;
	
	objPaging.pagingDRX = 3;
	objPaging.pagingDRX_isset = 1;
	
	__app_ngap_set_TAIListForPaging( &objPaging.tAIListForPaging);
	objPaging.tAIListForPaging_isset = 1;
	
	objPaging.pagingPriority = PagingPriority_priolevel2_val;
	objPaging.pagingPriority_isset = 1;
	
	//failed, the content of IE is required
	__app_ngap_set_UERadioCapabilityForPaging( &objPaging.uERadioCapabilityForPaging);
	objPaging.uERadioCapabilityForPaging_isset = 1;
	
	
	objPaging.pagingOrigin = PagingOrigin_non_3gpp_val;
	objPaging.pagingOrigin_isset = 1;	
	
	__app_ngap_set_AssistanceDataForPaging( &objPaging.assistanceDataForPaging);
	objPaging.assistanceDataForPaging_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_Paging( &objPaging, ngranNode);	
}


void __ngran_naspdu_create_RegistrationRequest( SI_ASN_CodingContext * context)
{
	__si_asn_memset( context);	
	
	NASPduFGMM_RegistrationRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_RegistrationRequest));

	objRequest.b1.TSC = 1;
	objRequest.b1.ngKSI = 2;
	objRequest.b1.FOR = 1;
	objRequest.b1.FGSRegistrationType = 2;
	
	objRequest.mFGSMobileIdentity.isset = 1;
	objRequest.mFGSMobileIdentity.Length = 11;
	//2 5G-GUTI
	objRequest.mFGSMobileIdentity.data[0] = 242;
	
	//MCC
	objRequest.mFGSMobileIdentity.data[1] = 0x04;
	objRequest.mFGSMobileIdentity.data[2] = 0xF4;
	objRequest.mFGSMobileIdentity.data[3] = 0x01;
	
	//AMF Region ID
	objRequest.mFGSMobileIdentity.data[4] = 33;
	
	//AMF SET ID
	objRequest.mFGSMobileIdentity.data[5] = 233;	
	objRequest.mFGSMobileIdentity.data[6] = 7;
	
	objRequest.mFGSMobileIdentity.data[7] = 8;
	objRequest.mFGSMobileIdentity.data[8] = 9;
	objRequest.mFGSMobileIdentity.data[9] = 10;
	objRequest.mFGSMobileIdentity.data[10] = 11;
	
	objRequest.mNASKeySetIdentifier.isset = 1;
	objRequest.mNASKeySetIdentifier.b1.Identifier = 2;
	
	objRequest.mFGMMCapability.isset = 1;
	objRequest.mFGMMCapability.Length = 0;
	objRequest.mFGMMCapability.b1.HOAttach = 1;
	memcpy( &objRequest.mFGMMCapability.data, "\x10\x20", 2);
	
	__si_naspdu_fgmm_encodeRegistrationRequest( &objRequest, context);
}

void __ngran_ngap_create_and_send_InitialUEMessage()
{
	SI_AMF_DT_PDU_InitialUEMessage objInitialUEMessage;
	memset( &objInitialUEMessage, 0, sizeof(SI_AMF_DT_PDU_InitialUEMessage));
	
	objInitialUEMessage.rANUENGAPID = 456456;
	objInitialUEMessage.rANUENGAPID_isset = 1;

	SI_ASN_CodingContext context;
	__ngran_naspdu_create_RegistrationRequest( &context);
	
	if( context.pos > 0)
	{
		printf( "context.pos=%d\n", context.pos);
		
		__si_amf_copyto_naspdu( &context, &objInitialUEMessage.nASPDU);
		objInitialUEMessage.nASPDU_isset = 1;
	}

	__app_ngap_set_UserLocationInformation( &objInitialUEMessage.userLocationInformation);
	objInitialUEMessage.userLocationInformation_isset = 1;
	
	objInitialUEMessage.rRCEstablishmentCause = 0;
	objInitialUEMessage.rRCEstablishmentCause_isset = 1;
	
	__app_ngap_set_FiveG_S_TMSI( &objInitialUEMessage.fiveGSTMSI);
	objInitialUEMessage.fiveGSTMSI_isset = 1;
	
	__app_ngap_set_AMFSetID( &objInitialUEMessage.aMFSetID);
	objInitialUEMessage.aMFSetID_isset = 1;
	
	objInitialUEMessage.uEContextRequest = 0;
	objInitialUEMessage.uEContextRequest_isset = 1;
	
	__app_ngap_set_AllowedNSSAI( &objInitialUEMessage.allowedNSSAI);
	objInitialUEMessage.allowedNSSAI_isset = 1;

	__app_ngap_set_SourceToTarget_AMFInformationReroute( &objInitialUEMessage.sourceToTargetAMFInformationReroute);
	objInitialUEMessage.sourceToTargetAMFInformationReroute_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_InitialUEMessage( &objInitialUEMessage, ngranNode);	
}

void __ngran_ngap_create_and_send_DownlinkNASTransport()
{
	SI_AMF_DT_PDU_DownlinkNASTransport objDownlinkNASTransport;
	memset( &objDownlinkNASTransport, 0, sizeof(SI_AMF_DT_PDU_DownlinkNASTransport));
	
	objDownlinkNASTransport.aMFUENGAPID = 454545;
	objDownlinkNASTransport.aMFUENGAPID_isset = 1;
	
	objDownlinkNASTransport.rANUENGAPID = 654654;
	objDownlinkNASTransport.rANUENGAPID_isset = 1;
	
	__app_ngap_set_AMFName( &objDownlinkNASTransport.oldAMF);
	objDownlinkNASTransport.oldAMF_isset = 1;
	
	objDownlinkNASTransport.rANPagingPriority = 2;
	objDownlinkNASTransport.rANPagingPriority_isset = 1;
	
	__app_ngap_set_MobilityRestrictionList( &objDownlinkNASTransport.mobilityRestrictionList);
	objDownlinkNASTransport.mobilityRestrictionList_isset = 1;
	
	objDownlinkNASTransport.indexToRFSP = 159;
	objDownlinkNASTransport.indexToRFSP_isset = 1;
	
	__app_ngap_set_UEAggregateMaximumBitRate( &objDownlinkNASTransport.uEAggregateMaximumBitRate);
	objDownlinkNASTransport.uEAggregateMaximumBitRate_isset = 1;
	
	__app_ngap_set_AllowedNSSAI( &objDownlinkNASTransport.allowedNSSAI);
	objDownlinkNASTransport.allowedNSSAI_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_DownlinkNASTransport( &objDownlinkNASTransport, ngranNode);	
}

void __ngran_ngap_create_and_send_UplinkNASTransport()
{
	SI_AMF_DT_PDU_UplinkNASTransport objUplinkNASTransport;
	memset( &objUplinkNASTransport, 0, sizeof(SI_AMF_DT_PDU_UplinkNASTransport));
	
	objUplinkNASTransport.aMFUENGAPID = 789654321;
	objUplinkNASTransport.aMFUENGAPID_isset = 1;
	
	objUplinkNASTransport.rANUENGAPID = 147258369;
	objUplinkNASTransport.rANUENGAPID_isset = 1;
	
	__app_ngap_set_UserLocationInformation( &objUplinkNASTransport.userLocationInformation);
	objUplinkNASTransport.userLocationInformation_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UplinkNASTransport( &objUplinkNASTransport, ngranNode);	
}

void __ngran_ngap_create_and_send_NASNonDeliveryIndication()
{
	SI_AMF_DT_PDU_NASNonDeliveryIndication objNASNonDeliveryIndication;
	memset( &objNASNonDeliveryIndication, 0, sizeof(SI_AMF_DT_PDU_NASNonDeliveryIndication));
	
	objNASNonDeliveryIndication.aMFUENGAPID = 45632145;
	objNASNonDeliveryIndication.aMFUENGAPID_isset = 1;
	
	objNASNonDeliveryIndication.rANUENGAPID = 58745698;
	objNASNonDeliveryIndication.rANUENGAPID_isset = 1;
	
	__app_ngap_set_Cause( &objNASNonDeliveryIndication.cause);
	objNASNonDeliveryIndication.cause_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_NASNonDeliveryIndication( &objNASNonDeliveryIndication, ngranNode);	
}

void __ngran_ngap_create_and_send_RerouteNASRequest()
{
	SI_AMF_DT_PDU_RerouteNASRequest objRerouteNASRequest;
	memset( &objRerouteNASRequest, 0, sizeof(SI_AMF_DT_PDU_RerouteNASRequest));
	
	objRerouteNASRequest.rANUENGAPID = 555555555;
	objRerouteNASRequest.rANUENGAPID_isset = 1;
	
	objRerouteNASRequest.aMFUENGAPID = 222222222;
	objRerouteNASRequest.aMFUENGAPID_isset = 1;
	
	__app_ngap_set_AMFSetID( &objRerouteNASRequest.aMFSetID);
	objRerouteNASRequest.aMFSetID_isset = 1;
	
	__app_ngap_set_AllowedNSSAI( &objRerouteNASRequest.allowedNSSAI);
	objRerouteNASRequest.allowedNSSAI_isset = 1;
	
	__app_ngap_set_SourceToTarget_AMFInformationReroute( &objRerouteNASRequest.sourceToTargetAMFInformationReroute);
	objRerouteNASRequest.sourceToTargetAMFInformationReroute_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_RerouteNASRequest( &objRerouteNASRequest, ngranNode);	
}

void __ngran_ngap_transport_of_nas_messages()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Initial UE Message:\n");
		printf("2 Downlink NAS Transport:\n");
		printf("3 Uplink NAS Transport:\n");
		printf("4 NAS Non Delivery Indication:\n");
		printf("5 Reroute NAS Request:\n");
		printf("6 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 6)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_InitialUEMessage();
					break;
				case 2:
					__ngran_ngap_create_and_send_DownlinkNASTransport();
					break;
				case 3:
					__ngran_ngap_create_and_send_UplinkNASTransport();
					break;
				case 4:
					__ngran_ngap_create_and_send_NASNonDeliveryIndication();
					break;
				case 5:
					__ngran_ngap_create_and_send_RerouteNASRequest();
					break;
				case 6:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_ngap_create_and_send_NGSetupRequest()
{
	char sNodeName[20];
	memset( sNodeName, 0, sizeof(sNodeName));
	strcpy( sNodeName, "NG-Ran-1");
	
	char eNB_ID_Type[30];
	memset( eNB_ID_Type, 0, sizeof( eNB_ID_Type));
	strcpy( eNB_ID_Type, "GlobalGNB-ID");
	// strcpy( eNB_ID_Type, "GlobalNgENB-ID");
	// strcpy( eNB_ID_Type, "GlobalN3IWF-ID");
	
	
	SI_AMF_DT_PDU_NGSetupRequest objNGSetupRequest;
	memset( &objNGSetupRequest, 0, sizeof(SI_AMF_DT_PDU_NGSetupRequest));
	
	objNGSetupRequest.rANNodeName = (SI_AMF_DT_RANNodeName *) __si_allocM( sizeof( SI_AMF_DT_RANNodeName));
	objNGSetupRequest.rANNodeName->data = (unsigned char *) __si_allocM( strlen(sNodeName) + 1 );
	objNGSetupRequest.rANNodeName->length = strlen(sNodeName);
	memcpy( objNGSetupRequest.rANNodeName->data, sNodeName, objNGSetupRequest.rANNodeName->length);
	objNGSetupRequest.rANNodeName_isset = 1;

	__si_amf_init_GlobalRANNodeID( &objNGSetupRequest.globalRANNodeID);

	if( strcmp( "GlobalGNB-ID", eNB_ID_Type) == 0)
	{
		objNGSetupRequest.globalRANNodeID->SelectedChoice = 0;//GlobalRANNodeID_globalGNB_ID_val;
		
		__si_amf_init_GlobalGNB_ID( &objNGSetupRequest.globalRANNodeID->u.globalGNB_ID);
		__si_amf_init_PLMNIdentity( &objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->pLMNIdentity);							// SI_AMF_DT_PLMNIdentity
		__si_amf_init_GNB_ID(       &objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID);								// SI_AMF_DT_GNB_ID
		__si_amf_init_GNB_IDBS(     &objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID);
		
		objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->pLMNIdentity->data = (unsigned char *) __si_allocM( 3);
		memcpy( objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->pLMNIdentity->data, "\x09\x71\x0F", 3); 
		objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->pLMNIdentity->length = 3;		
		
		objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID->SelectedChoice = 0;
		
		objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->data = (unsigned char *) __si_allocM( 3);
		memcpy( objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->data, "123", 3);
		objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->length = 3;
		objNGSetupRequest.globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->bitslen = 24;
		
		objNGSetupRequest.globalRANNodeID_isset = 1;
	}
	else if( strcmp( "GlobalNgENB-ID", eNB_ID_Type) == 0)
	{
		objNGSetupRequest.globalRANNodeID->SelectedChoice = GlobalRANNodeID_globalNgENB_ID_val;

		__si_amf_init_GlobalNgENB_ID( &objNGSetupRequest.globalRANNodeID->u.globalNgENB_ID);
		__si_amf_init_NgENB_ID( &objNGSetupRequest.globalRANNodeID->u.globalNgENB_ID->ngENB_ID);
		
		
		objNGSetupRequest.globalRANNodeID_isset = 1;
	}
	else if( strcmp( "GlobalN3IWF-ID", eNB_ID_Type) == 0)
	{
		objNGSetupRequest.globalRANNodeID->SelectedChoice = GlobalRANNodeID_globalN3IWF_ID_val;
		
		__si_amf_init_GlobalN3IWF_ID( &objNGSetupRequest.globalRANNodeID->u.globalN3IWF_ID);
		__si_amf_init_PLMNIdentity(   &objNGSetupRequest.globalRANNodeID->u.globalN3IWF_ID->pLMNIdentity);	
		__si_amf_init_N3IWF_ID(       &objNGSetupRequest.globalRANNodeID->u.globalN3IWF_ID->n3IWF_ID);								// SI_AMF_DT_GNB_ID
		__si_amf_init_N3IWF_IDBS(     &objNGSetupRequest.globalRANNodeID->u.globalN3IWF_ID->n3IWF_ID->u.n3IWF_ID);
		
		
		objNGSetupRequest.globalRANNodeID_isset = 1;
	}

	objNGSetupRequest.defaultPagingDRX = 3;
	objNGSetupRequest.defaultPagingDRX_isset = 1;	
	
	objNGSetupRequest.uERetentionInformation = 0;
	objNGSetupRequest.uERetentionInformation_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	int sts = __si_ngap_send_NGSetupRequest( &objNGSetupRequest, ngranNode);
}

void __ngran_ngap_create_and_send_RANConfigurationUpdate()
{
	SI_AMF_DT_PDU_RANConfigurationUpdate objRANConfigurationUpdate;
	memset( &objRANConfigurationUpdate, 0, sizeof(SI_AMF_DT_PDU_RANConfigurationUpdate));
	
	__app_ngap_set_RANNodeName( &objRANConfigurationUpdate.rANNodeName);
	objRANConfigurationUpdate.rANNodeName_isset = 1;
	
	__app_ngap_set_SupportedTAList( &objRANConfigurationUpdate.supportedTAList);
	objRANConfigurationUpdate.supportedTAList_isset = 1;
	
	objRANConfigurationUpdate.defaultPagingDRX = 1;
	objRANConfigurationUpdate.defaultPagingDRX_isset = 1;
	
	__app_ngap_set_GlobalRANNodeID( &objRANConfigurationUpdate.globalRANNodeID);
	objRANConfigurationUpdate.globalRANNodeID_isset = 1;
	
	__app_ngap_set_NGRAN_TNLAssociationToRemoveList( &objRANConfigurationUpdate.nGRANTNLAssociationToRemoveList);
	objRANConfigurationUpdate.nGRANTNLAssociationToRemoveList_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_RANConfigurationUpdate( &objRANConfigurationUpdate, ngranNode);	
}

void __ngran_ngap_create_and_send_AMFConfigurationUpdate()
{
	SI_AMF_DT_PDU_AMFConfigurationUpdate objAMFConfigurationUpdate;
	memset( &objAMFConfigurationUpdate, 0, sizeof(SI_AMF_DT_PDU_AMFConfigurationUpdate));
	
	__app_ngap_set_AMFName( &objAMFConfigurationUpdate.aMFName);
	objAMFConfigurationUpdate.aMFName_isset = 1;
	
	__app_ngap_set_ServedGUAMIList( &objAMFConfigurationUpdate.servedGUAMIList);
	objAMFConfigurationUpdate.servedGUAMIList_isset = 1;
	
	objAMFConfigurationUpdate.relativeAMFCapacity = 152;
	objAMFConfigurationUpdate.relativeAMFCapacity_isset = 1;
	
	__app_ngap_set_PLMNSupportList( &objAMFConfigurationUpdate.pLMNSupportList);
	objAMFConfigurationUpdate.pLMNSupportList_isset = 1;
	
	__app_ngap_set_AMF_TNLAssociationToAddList( &objAMFConfigurationUpdate.aMFTNLAssociationToAddList);
	objAMFConfigurationUpdate.aMFTNLAssociationToAddList_isset = 1;
	
	__app_ngap_set_AMF_TNLAssociationToRemoveList( &objAMFConfigurationUpdate.aMFTNLAssociationToRemoveList);
	objAMFConfigurationUpdate.aMFTNLAssociationToRemoveList_isset = 1;
	
	__app_ngap_set_AMF_TNLAssociationToUpdateList( &objAMFConfigurationUpdate.aMFTNLAssociationToUpdateList);
	objAMFConfigurationUpdate.aMFTNLAssociationToUpdateList_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_AMFConfigurationUpdate( &objAMFConfigurationUpdate, ngranNode);	
}

void __ngran_ngap_create_and_send_NGReset()
{
	SI_AMF_DT_PDU_NGReset objNGReset;
	memset( &objNGReset, 0, sizeof(SI_AMF_DT_PDU_NGReset));
	
	__app_ngap_set_Cause( &objNGReset.cause);
	objNGReset.cause_isset = 1;
	
	__app_ngap_set_ResetType( &objNGReset.resetType);
	objNGReset.resetType_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_NGReset( &objNGReset, ngranNode);	
}

void __ngran_ngap_create_and_send_ErrorIndication()
{
	SI_AMF_DT_PDU_ErrorIndication objErrorIndication;
	memset( &objErrorIndication, 0, sizeof(SI_AMF_DT_PDU_ErrorIndication));
	
	objErrorIndication.aMFUENGAPID = 456123;
	objErrorIndication.aMFUENGAPID_isset = 1;
	
	objErrorIndication.rANUENGAPID = 456456;
	objErrorIndication.rANUENGAPID_isset = 1;
	
	__app_ngap_set_Cause( &objErrorIndication.cause);
	objErrorIndication.cause_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_ErrorIndication( &objErrorIndication, ngranNode);
}

void __ngran_ngap_create_and_send_AMFStatusIndication()
{
	SI_AMF_DT_PDU_AMFStatusIndication objAMFStatusIndication;
	memset( &objAMFStatusIndication, 0, sizeof(SI_AMF_DT_PDU_AMFStatusIndication));
	
	__app_ngap_set_UnavailableGUAMIList( &objAMFStatusIndication.unavailableGUAMIList);
	objAMFStatusIndication.unavailableGUAMIList_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_AMFStatusIndication( &objAMFStatusIndication, ngranNode);	
}

void __ngran_ngap_interface_management()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 NG Setup:\n");
		printf("2 RAN Configuration Update:\n");
		printf("3 AMF Configuration Update:\n");
		printf("4 NG Reset:\n");
		printf("5 Error Indication:\n");
		printf("6 AMF Status Indication:\n");
		printf("7 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 7)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_NGSetupRequest();
					break;
				case 2:
					__ngran_ngap_create_and_send_RANConfigurationUpdate();
					break;
				case 3:
					__ngran_ngap_create_and_send_AMFConfigurationUpdate();
					break;
				case 4:
					__ngran_ngap_create_and_send_NGReset();
					break;
				case 5:
					__ngran_ngap_create_and_send_ErrorIndication();
					break;
				case 6:
					__ngran_ngap_create_and_send_AMFStatusIndication();
					break;	
				case 7:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}	
}

void __ngran_ngap_create_and_send_UplinkRANConfigurationTransfer()
{
	SI_AMF_DT_PDU_UplinkRANConfigurationTransfer objUplinkRANConfigurationTransfer;
	memset( &objUplinkRANConfigurationTransfer, 0, sizeof(SI_AMF_DT_PDU_UplinkRANConfigurationTransfer));
	
	//failed
	__app_ngap_set_SONConfigurationTransfer( &objUplinkRANConfigurationTransfer.sONConfigurationTransferUL);
	objUplinkRANConfigurationTransfer.sONConfigurationTransferUL_isset = 0;
	
	//failed, data content required
	__app_ngap_set_EN_DCSONConfigurationTransfer( &objUplinkRANConfigurationTransfer.eNDCSONConfigurationTransferUL);
	objUplinkRANConfigurationTransfer.eNDCSONConfigurationTransferUL_isset = 0;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UplinkRANConfigurationTransfer( &objUplinkRANConfigurationTransfer, ngranNode);	
}

void __ngran_ngap_create_and_send_DownlinkRANConfigurationTransfer()
{
	SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer objDownlinkRANConfigurationTransfer;
	memset( &objDownlinkRANConfigurationTransfer, 0, sizeof(SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer));
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_DownlinkRANConfigurationTransfer( &objDownlinkRANConfigurationTransfer, ngranNode);	
}


void __ngran_ngap_configuration_transfer()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Uplink RAN Configuration Transfer:\n");
		printf("2 Downlink RAN Configuration Transfer:\n");
		printf("3 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 3)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_UplinkRANConfigurationTransfer();
					break;
				case 2:
					__ngran_ngap_create_and_send_DownlinkRANConfigurationTransfer();
					break;
				case 3:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}		
}

void __ngran_ngap_create_and_send_WriteReplaceWarning()
{
	SI_AMF_DT_PDU_WriteReplaceWarningRequest objWriteReplaceWarning;
	memset( &objWriteReplaceWarning, 0, sizeof(SI_AMF_DT_PDU_WriteReplaceWarningRequest));
	
	__app_ngap_set_MessageIdentifier( &objWriteReplaceWarning.messageIdentifier);
	objWriteReplaceWarning.messageIdentifier_isset = 1;
	
	__app_ngap_set_SerialNumber( &objWriteReplaceWarning.serialNumber);
	objWriteReplaceWarning.serialNumber_isset = 1;
	
	__app_ngap_set_WarningAreaList( &objWriteReplaceWarning.warningAreaList);
	objWriteReplaceWarning.warningAreaList_isset = 1;
	
	objWriteReplaceWarning.repetitionPeriod = 5;
	objWriteReplaceWarning.repetitionPeriod_isset = 1;

	objWriteReplaceWarning.numberOfBroadcastsRequested = 5;
	objWriteReplaceWarning.numberOfBroadcastsRequested_isset = 1;
	
	__app_ngap_set_WarningType( &objWriteReplaceWarning.warningType);
	objWriteReplaceWarning.warningType_isset = 1;
	
	__app_ngap_set_WarningSecurityInfo( &objWriteReplaceWarning.warningSecurityInfo);
	objWriteReplaceWarning.warningSecurityInfo_isset = 1;
	
	__app_ngap_set_DataCodingScheme( &objWriteReplaceWarning.dataCodingScheme);
	objWriteReplaceWarning.dataCodingScheme_isset = 1;
	
	__app_ngap_set_WarningMessageContents( &objWriteReplaceWarning.warningMessageContents);
	objWriteReplaceWarning.warningMessageContents_isset = 1;
	
	objWriteReplaceWarning.concurrentWarningMessageInd = 0;
	objWriteReplaceWarning.concurrentWarningMessageInd_isset = 1;

	__app_ngap_set_WarningAreaCoordinates( &objWriteReplaceWarning.warningAreaCoordinates);
	objWriteReplaceWarning.warningAreaCoordinates_isset = 1;
	
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_WriteReplaceWarningRequest( &objWriteReplaceWarning, ngranNode);	
}

void __ngran_ngap_create_and_send_WriteReplaceWarningResponse()
{
	SI_AMF_DT_PDU_WriteReplaceWarningResponse objWriteReplaceWarningResponse;
	memset( &objWriteReplaceWarningResponse, 0, sizeof(SI_AMF_DT_PDU_WriteReplaceWarningResponse));
	
	__app_ngap_set_MessageIdentifier( &objWriteReplaceWarningResponse.messageIdentifier);
	objWriteReplaceWarningResponse.messageIdentifier_isset = 1;
	
	__app_ngap_set_SerialNumber( &objWriteReplaceWarningResponse.serialNumber);
	objWriteReplaceWarningResponse.serialNumber_isset = 1;
	
	__app_ngap_set_BroadcastCompletedAreaList( &objWriteReplaceWarningResponse.broadcastCompletedAreaList);
	objWriteReplaceWarningResponse.broadcastCompletedAreaList_isset = 1;

	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_WriteReplaceWarningResponse( &objWriteReplaceWarningResponse, ngranNode);	
}

void __ngran_ngap_create_and_send_PWSCancel()
{
	SI_AMF_DT_PDU_PWSCancelRequest objPWSCancel;
	memset( &objPWSCancel, 0, sizeof(SI_AMF_DT_PDU_PWSCancelRequest));
	
	
	__app_ngap_set_MessageIdentifier( &objPWSCancel.messageIdentifier);
	objPWSCancel.messageIdentifier_isset = 1;
	
	__app_ngap_set_SerialNumber( &objPWSCancel.serialNumber);
	objPWSCancel.serialNumber_isset = 1;
	
	__app_ngap_set_WarningAreaList( &objPWSCancel.warningAreaList);
	objPWSCancel.warningAreaList_isset = 1;
	
	objPWSCancel.cancelAllWarningMessages = 0;
	objPWSCancel.cancelAllWarningMessages_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PWSCancelRequest( &objPWSCancel, ngranNode);	
}

void __ngran_ngap_create_and_send_PWSRestartIndication()
{
	SI_AMF_DT_PDU_PWSRestartIndication objPWSRestartIndication;
	memset( &objPWSRestartIndication, 0, sizeof(SI_AMF_DT_PDU_PWSRestartIndication));
	
	__app_ngap_set_CellIDListForRestart( &objPWSRestartIndication.cellIDListForRestart);
	objPWSRestartIndication.cellIDListForRestart_isset = 1;
	
	__app_ngap_set_GlobalRANNodeID( &objPWSRestartIndication.globalRANNodeID);
	objPWSRestartIndication.globalRANNodeID_isset = 1;
	
	__app_ngap_set_TAIListForRestart( &objPWSRestartIndication.tAIListForRestart);
	objPWSRestartIndication.tAIListForRestart_isset = 1;
	
	__app_ngap_set_EmergencyAreaIDListForRestart( &objPWSRestartIndication.emergencyAreaIDListForRestart);
	objPWSRestartIndication.emergencyAreaIDListForRestart_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PWSRestartIndication( &objPWSRestartIndication, ngranNode);	
}

void __ngran_ngap_create_and_send_PWSFailureIndication()
{
	SI_AMF_DT_PDU_PWSFailureIndication objPWSFailureIndication;
	memset( &objPWSFailureIndication, 0, sizeof(SI_AMF_DT_PDU_PWSFailureIndication));
	
	__app_ngap_set_PWSFailedCellIDList( &objPWSFailureIndication.pWSFailedCellIDList);
	objPWSFailureIndication.pWSFailedCellIDList_isset = 1;
	
	__app_ngap_set_GlobalRANNodeID( &objPWSFailureIndication.globalRANNodeID);
	objPWSFailureIndication.globalRANNodeID_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_PWSFailureIndication( &objPWSFailureIndication, ngranNode);
}

void __ngran_ngap_warning_message_transfer()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Write-Replace Warning:\n");
		printf("2 PWS Cancel:\n");
		printf("3 PWS Restart Indication:\n");
		printf("4 PWS Failure Indication:\n");
		printf("5 Write-Replace Warning Response:\n");
		printf("6 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 6)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_WriteReplaceWarning();
					break;
				case 2:
					__ngran_ngap_create_and_send_PWSCancel();
					break;
				case 3:
					__ngran_ngap_create_and_send_PWSRestartIndication();
					break;
				case 4:
					__ngran_ngap_create_and_send_PWSFailureIndication();
					break;
				case 5:
					__ngran_ngap_create_and_send_WriteReplaceWarningResponse();
					break;					
				case 6:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_ngap_nrppa_transfer()
{

}

void __ngran_ngap_create_and_send_TraceStart()
{
	SI_AMF_DT_PDU_TraceStart objTraceStart;
	memset( &objTraceStart, 0, sizeof(SI_AMF_DT_PDU_TraceStart));
	
	objTraceStart.aMFUENGAPID = 78978978;
	objTraceStart.aMFUENGAPID_isset = 1;
	
	objTraceStart.rANUENGAPID = 45645645;
	objTraceStart.rANUENGAPID_isset = 1;
	
	__app_ngap_set_TraceActivation( &objTraceStart.traceActivation);
	objTraceStart.traceActivation_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_TraceStart( &objTraceStart, ngranNode);	
}

void __ngran_ngap_create_and_send_TraceFailureIndication()
{
	SI_AMF_DT_PDU_TraceFailureIndication objTraceFailureIndication;
	memset( &objTraceFailureIndication, 0, sizeof(SI_AMF_DT_PDU_TraceFailureIndication));
	
	objTraceFailureIndication.aMFUENGAPID = 147852;
	objTraceFailureIndication.aMFUENGAPID_isset = 1;
	
	objTraceFailureIndication.rANUENGAPID = 456456;
	objTraceFailureIndication.rANUENGAPID_isset = 1;
	
	__app_ngap_set_NGRANTraceID( &objTraceFailureIndication.nGRANTraceID);
	objTraceFailureIndication.nGRANTraceID_isset = 1;
	
	__app_ngap_set_Cause( &objTraceFailureIndication.cause);
	objTraceFailureIndication.cause_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_TraceFailureIndication( &objTraceFailureIndication, ngranNode);	
}

void __ngran_ngap_create_and_send_DeactivateTrace()
{
	SI_AMF_DT_PDU_DeactivateTrace objDeactivateTrace;
	memset( &objDeactivateTrace, 0, sizeof(SI_AMF_DT_PDU_DeactivateTrace));
	
	objDeactivateTrace.aMFUENGAPID = 456123;
	objDeactivateTrace.aMFUENGAPID_isset = 1;
	
	objDeactivateTrace.rANUENGAPID = 14963;
	objDeactivateTrace.rANUENGAPID_isset = 1;
	
	__app_ngap_set_NGRANTraceID( &objDeactivateTrace.nGRANTraceID);
	objDeactivateTrace.nGRANTraceID_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_DeactivateTrace( &objDeactivateTrace, ngranNode);	
}

void __ngran_ngap_create_and_send_CellTrafficTrace()
{
	SI_AMF_DT_PDU_CellTrafficTrace objCellTrafficTrace;
	memset( &objCellTrafficTrace, 0, sizeof(SI_AMF_DT_PDU_CellTrafficTrace));
	
	objCellTrafficTrace.aMFUENGAPID = 456123;
	objCellTrafficTrace.aMFUENGAPID_isset = 1;
	
	objCellTrafficTrace.rANUENGAPID = 14963;
	objCellTrafficTrace.rANUENGAPID_isset = 1;
	
	__app_ngap_set_NGRANTraceID( &objCellTrafficTrace.nGRANTraceID);
	objCellTrafficTrace.nGRANTraceID_isset = 1;	
	
	__app_ngap_set_NGRAN_CGI( &objCellTrafficTrace.nGRANCGI);
	objCellTrafficTrace.nGRANCGI_isset = 1;
	
	__app_ngap_set_TransportLayerAddress( &objCellTrafficTrace.traceCollectionEntityIPAddress);
	objCellTrafficTrace.traceCollectionEntityIPAddress_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_CellTrafficTrace( &objCellTrafficTrace, ngranNode);	
}

void __ngran_ngap_trace()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Trace Start:\n");
		printf("2 Trace Failure Indication:\n");
		printf("3 Deactivate Trace:\n");
		printf("4 Cell Traffic Trace:\n");
		printf("5 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 5)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_TraceStart();
					break;
				case 2:
					__ngran_ngap_create_and_send_TraceFailureIndication();
					break;
				case 3:
					__ngran_ngap_create_and_send_DeactivateTrace();
					break;
				case 4:
					__ngran_ngap_create_and_send_CellTrafficTrace();
					break;	
				case 5:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_ngap_create_and_send_LocationReportingControl()
{
	SI_AMF_DT_PDU_LocationReportingControl objLocationReportingControl;
	memset( &objLocationReportingControl, 0, sizeof(SI_AMF_DT_PDU_LocationReportingControl));
	
	objLocationReportingControl.aMFUENGAPID = 147852;
	objLocationReportingControl.aMFUENGAPID_isset = 1;
	
	objLocationReportingControl.rANUENGAPID = 258741;
	objLocationReportingControl.rANUENGAPID_isset = 1;
	
	__app_ngap_set_LocationReportingRequestType( &objLocationReportingControl.locationReportingRequestType);
	objLocationReportingControl.locationReportingRequestType_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_LocationReportingControl( &objLocationReportingControl, ngranNode);	
}

void __ngran_ngap_create_and_send_LocationReportFailureIndication()
{
	SI_AMF_DT_PDU_LocationReportingFailureIndication objLocationReportFailureIndication;
	memset( &objLocationReportFailureIndication, 0, sizeof(SI_AMF_DT_PDU_LocationReportingFailureIndication));
	
	objLocationReportFailureIndication.aMFUENGAPID = 456456;
	objLocationReportFailureIndication.aMFUENGAPID_isset = 1;
	
	objLocationReportFailureIndication.rANUENGAPID = 654136;
	objLocationReportFailureIndication.rANUENGAPID_isset = 1;
	
	__app_ngap_set_Cause( &objLocationReportFailureIndication.cause);
	objLocationReportFailureIndication.cause_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_LocationReportingFailureIndication( &objLocationReportFailureIndication, ngranNode);	
}

void __ngran_ngap_create_and_send_LocationReport()
{
	SI_AMF_DT_PDU_LocationReport objLocationReport;
	memset( &objLocationReport, 0, sizeof(SI_AMF_DT_PDU_LocationReport));
	
	objLocationReport.aMFUENGAPID = 456456;
	objLocationReport.aMFUENGAPID_isset = 1;
	
	objLocationReport.rANUENGAPID = 789789;
	objLocationReport.rANUENGAPID_isset = 1;
	
	__app_ngap_set_UserLocationInformation( &objLocationReport.userLocationInformation);
	objLocationReport.userLocationInformation_isset = 1;
	
	__app_ngap_set_UEPresenceInAreaOfInterestList( &objLocationReport.uEPresenceInAreaOfInterestList);
	objLocationReport.uEPresenceInAreaOfInterestList_isset = 1;
	
	__app_ngap_set_LocationReportingRequestType( &objLocationReport.locationReportingRequestType);
	objLocationReport.locationReportingRequestType_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_LocationReport( &objLocationReport, ngranNode);	
}

void __ngran_ngap_location_reporting()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 Location Reporting Control:\n");
		printf("2 Location Report Failure Indication:\n");
		printf("3 Location Report:\n");
		printf("4 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 4)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_LocationReportingControl();
					break;
				case 2:
					__ngran_ngap_create_and_send_LocationReportFailureIndication();
					break;
				case 3:
					__ngran_ngap_create_and_send_LocationReport();
					break;
				case 4:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_ngap_ue_tnla_binding()
{
	SI_AMF_DT_PDU_UETNLABindingReleaseRequest objUETNLABindingReleaseRequest;
	memset( &objUETNLABindingReleaseRequest, 0, sizeof(SI_AMF_DT_PDU_UETNLABindingReleaseRequest));
	
	objUETNLABindingReleaseRequest.aMFUENGAPID = 258963;
	objUETNLABindingReleaseRequest.aMFUENGAPID_isset = 1;
	
	objUETNLABindingReleaseRequest.rANUENGAPID = 456123;
	objUETNLABindingReleaseRequest.rANUENGAPID_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UETNLABindingReleaseRequest( &objUETNLABindingReleaseRequest, ngranNode);
}

void __ngran_ngap_create_and_send_UERadioCapabilityInfoIndication()
{
	SI_AMF_DT_PDU_UERadioCapabilityInfoIndication objUECapabilityInfoIndication;
	memset( &objUECapabilityInfoIndication, 0, sizeof(SI_AMF_DT_PDU_UERadioCapabilityInfoIndication));
	
	objUECapabilityInfoIndication.aMFUENGAPID = 456321;
	objUECapabilityInfoIndication.aMFUENGAPID_isset = 1;
	
	objUECapabilityInfoIndication.rANUENGAPID = 147852;
	objUECapabilityInfoIndication.rANUENGAPID_isset = 1;
	
	//failed -> fixed
	__app_ngap_set_UERadioCapability( &objUECapabilityInfoIndication.uERadioCapability);
	objUECapabilityInfoIndication.uERadioCapability_isset = 1;
	
	//failed, the content of IE is required
	__app_ngap_set_UERadioCapabilityForPaging( &objUECapabilityInfoIndication.uERadioCapabilityForPaging);
	objUECapabilityInfoIndication.uERadioCapabilityForPaging_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UERadioCapabilityInfoIndication( &objUECapabilityInfoIndication, ngranNode);	
}

void __ngran_ngap_create_and_send_UERadioCapabilityCheck()
{
	SI_AMF_DT_PDU_UERadioCapabilityCheckRequest objUERadioCapabilityCheck;
	memset( &objUERadioCapabilityCheck, 0, sizeof(SI_AMF_DT_PDU_UERadioCapabilityCheckRequest));
	
	objUERadioCapabilityCheck.aMFUENGAPID = 456321;
	objUERadioCapabilityCheck.aMFUENGAPID_isset = 1;
	
	objUERadioCapabilityCheck.rANUENGAPID = 123654;
	objUERadioCapabilityCheck.rANUENGAPID_isset = 1;
	
	//failed -> fixed
	__app_ngap_set_UERadioCapability( &objUERadioCapabilityCheck.uERadioCapability);
	objUERadioCapabilityCheck.uERadioCapability_isset = 1;
	
	SI_NGAPNode * ngranNode = __si_ngap_get_amf_connection();
	__si_ngap_send_UERadioCapabilityCheckRequest( &objUERadioCapabilityCheck, ngranNode);	
}

void __ngran_ngap_ue_capability_management()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	uint32_t bExit = 0;
	
	while(1)
	{
		printf("1 UE Radio Capability Info Indication:\n");
		printf("2 UE Radio Capability Check:\n");
		printf("3 exit:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 3)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_create_and_send_UERadioCapabilityInfoIndication();
					break;
				case 2:
					__ngran_ngap_create_and_send_UERadioCapabilityCheck();
					break;
				case 3:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_nas_mm_send_msg( SI_ASN_CodingContext * context)
{
	if( context->pos == 0)
		return;
	
	SI_AMF_DT_PDU_InitialUEMessage objInitialUEMessage;
	memset( &objInitialUEMessage, 0, sizeof(SI_AMF_DT_PDU_InitialUEMessage));
	
	objInitialUEMessage.rANUENGAPID = 789654;
	objInitialUEMessage.rANUENGAPID_isset = 1;
	
	__si_amf_init_NAS_PDU( &objInitialUEMessage.nASPDU);
	objInitialUEMessage.nASPDU->data = (unsigned char *) &context->buffer;
	objInitialUEMessage.nASPDU->length = context->pos;
	
	objInitialUEMessage.nASPDU_isset = 1;
	
	__si_ngap_send_InitialUEMessage( &objInitialUEMessage, __si_ngap_get_amf_connection());	
}


void __ngran_nas_mmm_AuthenticationRequest()
{
	NASPduFGMM_AuthenticationRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_AuthenticationRequest));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.ngKSI = 2;
	
	objRequest.mABBA.isset = 1;
	objRequest.mABBA.Length = 4;
	memcpy( objRequest.mABBA.data, "\x10\x13\x14\x15", 4);

	objRequest.mAuthenticationParameterRAND.isset = 1;
	memcpy( objRequest.mAuthenticationParameterRAND.data, "\x09\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x06\x07", 17);
	
	objRequest.mAuthenticationParameterAUTN.isset = 1;
	objRequest.mAuthenticationParameterAUTN.Length = 16;
	memcpy( objRequest.mAuthenticationParameterAUTN.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 16);
	
	objRequest.mEAPMessage.isset = 1;	
	objRequest.mEAPMessage.Length = 0;
	memcpy( objRequest.mEAPMessage.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 16);
	
	__si_naspdu_fgmm_encodeAuthenticationRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_AuthenticationResponse()
{
	NASPduFGMM_AuthenticationResponse objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_AuthenticationResponse));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mAuthenticationResponseParameter.isset = 1;
	objRequest.mAuthenticationResponseParameter.Length = 16;
	memcpy( objRequest.mAuthenticationResponseParameter.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 16);

	objRequest.mEAPMessage.isset = 1;	
	objRequest.mEAPMessage.Length = 0;
	memcpy( objRequest.mEAPMessage.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 16);
	
	__si_naspdu_fgmm_encodeAuthenticationResponse( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_AuthenticationResult()
{
	NASPduFGMM_AuthenticationResult objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_AuthenticationResult));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.ngKSI = 2;

	objRequest.mEAPMessage.isset = 1;	
	objRequest.mEAPMessage.Length = 0;
	memcpy( objRequest.mEAPMessage.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 16);

	objRequest.mABBA.isset = 1;
	objRequest.mABBA.Length = 4;
	memcpy( objRequest.mABBA.data, "\x10\x13\x14\x15", 4);
	
	__si_naspdu_fgmm_encodeAuthenticationResult( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_AuthenticationFailure()
{
	NASPduFGMM_AuthenticationFailure objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_AuthenticationFailure));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mFGMMCause.isset = 1;
	objRequest.mFGMMCause.CauseValue = 92;
	
	objRequest.mAuthenticationFailureParameter.isset = 1;
	objRequest.mAuthenticationFailureParameter.Length = 14;
	memcpy( objRequest.mAuthenticationFailureParameter.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 14);
	
	__si_naspdu_fgmm_encodeAuthenticationFailure( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_AuthenticationReject()
{
	NASPduFGMM_AuthenticationReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_AuthenticationReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);
	
	objRequest.mEAPMessage.isset = 1;	
	objRequest.mEAPMessage.Length = 0;
	memcpy( objRequest.mEAPMessage.data, "\x10\x10\x13\x14\x15\x16\x17\x18\x15\x13\x09\x05\x12\x10\x05\x66\x57", 16);	

	__si_naspdu_fgmm_encodeAuthenticationReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_RegistrationRequest()
{
	NASPduFGMM_RegistrationRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_RegistrationRequest));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.TSC = 1;
	objRequest.b1.ngKSI = 2;
	objRequest.b1.FOR = 1;
	objRequest.b1.FGSRegistrationType = 2;
	
	objRequest.mFGSMobileIdentity.isset = 1;
	objRequest.mFGSMobileIdentity.Length = 11;
	//2 5G-GUTI
	objRequest.mFGSMobileIdentity.data[0] = 242;
	
	//MCC
	objRequest.mFGSMobileIdentity.data[1] = 0x04;
	objRequest.mFGSMobileIdentity.data[2] = 0xF4;
	objRequest.mFGSMobileIdentity.data[3] = 0x01;
	
	//AMF Region ID
	objRequest.mFGSMobileIdentity.data[4] = 33;
	
	//AMF SET ID
	objRequest.mFGSMobileIdentity.data[5] = 233;	
	objRequest.mFGSMobileIdentity.data[6] = 7;
	
	objRequest.mFGSMobileIdentity.data[7] = 8;
	objRequest.mFGSMobileIdentity.data[8] = 9;
	objRequest.mFGSMobileIdentity.data[9] = 10;
	objRequest.mFGSMobileIdentity.data[10] = 11;
	
	objRequest.mNASKeySetIdentifier.isset = 1;
	objRequest.mNASKeySetIdentifier.b1.Identifier = 2;
	
	objRequest.mFGMMCapability.isset = 1;
	objRequest.mFGMMCapability.Length = 0;
	objRequest.mFGMMCapability.b1.HOAttach = 1;
	memcpy( &objRequest.mFGMMCapability.data, "\x10\x20", 2);
	
	__si_naspdu_fgmm_encodeRegistrationRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_RegistrationAccept()
{
	NASPduFGMM_RegistrationAccept objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_RegistrationAccept));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	//NASPdu_FGSRegistrationResult mFGSRegistrationResult;
	objRequest.mFGSRegistrationResult.isset = 1;
	objRequest.mFGSRegistrationResult.Length = 1;
	objRequest.mFGSRegistrationResult.b1.FGSRegistrationResultValue = 1;
	objRequest.mFGSRegistrationResult.b1.SMSAllowed = 1;

	__si_naspdu_fgmm_encodeRegistrationAccept( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_RegistrationComplete()
{
	NASPduFGMM_RegistrationComplete objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_RegistrationComplete));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeRegistrationComplete( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_RegistrationReject()
{
	NASPduFGMM_RegistrationReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_RegistrationReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mFGMMCause.isset = 1;
	objRequest.mFGMMCause.CauseValue = 92;

	__si_naspdu_fgmm_encodeRegistrationReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_ULNASTransport()
{
	NASPduFGMM_ULNASTransport objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_ULNASTransport));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.PayloadContainerType = 2;
	
	objRequest.mPayloadContainer.isset = 1;
	objRequest.mPayloadContainer.Length = 5;
	memcpy( objRequest.mPayloadContainer.data, "\x65\x66\x67\x68\x69", 5);
	
	__si_naspdu_fgmm_encodeULNASTransport( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_DLNASTransport()
{
	NASPduFGMM_DLNASTransport objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_DLNASTransport));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.PayloadContainerType = 4;
	
	objRequest.mPayloadContainer.isset = 1;
	objRequest.mPayloadContainer.Length = 5;
	memcpy( objRequest.mPayloadContainer.data, "\x74\x70\x71\x72\x73", 5);

	__si_naspdu_fgmm_encodeDLNASTransport( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_DeRegistrationRequestUEO()
{
	NASPduFGMM_DeregistrationRequestUEI objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_DeregistrationRequestUEI));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.TSC = 1;
	objRequest.b1.ngKSI = 2;
	objRequest.b1.DeRegistrationType = 1;

	objRequest.mFGSMobileIdentity.isset = 1;
	objRequest.mFGSMobileIdentity.Length = 11;
	//2 5G-GUTI
	objRequest.mFGSMobileIdentity.data[0] = 242;
	
	//MCC
	objRequest.mFGSMobileIdentity.data[1] = 0x04;
	objRequest.mFGSMobileIdentity.data[2] = 0xF4;
	objRequest.mFGSMobileIdentity.data[3] = 0x01;
	
	//AMF Region ID
	objRequest.mFGSMobileIdentity.data[4] = 33;
	
	//AMF SET ID
	objRequest.mFGSMobileIdentity.data[5] = 233;	
	objRequest.mFGSMobileIdentity.data[6] = 7;
	
	objRequest.mFGSMobileIdentity.data[7] = 8;
	objRequest.mFGSMobileIdentity.data[8] = 9;
	objRequest.mFGSMobileIdentity.data[9] = 10;
	objRequest.mFGSMobileIdentity.data[9] = 11;

	__si_naspdu_fgmm_encodeDeregistrationRequestUEI( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_DeRegistrationAcceptUEO()
{
	NASPduFGMM_DeregistrationAcceptUEI objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_DeregistrationAcceptUEI));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeDeregistrationAcceptUEI( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_DeRegistrationRequestUET()
{
	NASPduFGMM_DeregistrationRequestUET objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_DeregistrationRequestUET));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.DeRegistrationType_AccessType = 3;
	objRequest.b1.DeRegistrationType_SwitchOff = 1;

	__si_naspdu_fgmm_encodeDeregistrationRequestUET( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_DeRegistrationAcceptUET()
{
	NASPduFGMM_DeregistrationAcceptUET objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_DeregistrationAcceptUET));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeDeregistrationAcceptUET( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_ServiceRequest()
{
	NASPduFGMM_ServiceRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_ServiceRequest));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.TSC = 1;
	objRequest.b1.ngKSI = 5;
	objRequest.b1.ServiceType = 2;

	objRequest.m5GSTMSI.isset = 1;
	objRequest.m5GSTMSI.Length = 11;
	//2 5G-GUTI
	objRequest.m5GSTMSI.data[0] = 242;
	
	//MCC
	objRequest.m5GSTMSI.data[1] = 0x04;
	objRequest.m5GSTMSI.data[2] = 0xF4;
	objRequest.m5GSTMSI.data[3] = 0x01;
	
	//AMF Region ID
	objRequest.m5GSTMSI.data[4] = 33;
	
	//AMF SET ID
	objRequest.m5GSTMSI.data[5] = 233;	
	objRequest.m5GSTMSI.data[6] = 7;
	
	objRequest.m5GSTMSI.data[7] = 8;
	objRequest.m5GSTMSI.data[8] = 9;
	objRequest.m5GSTMSI.data[9] = 10;
	objRequest.m5GSTMSI.data[9] = 11;

	__si_naspdu_fgmm_encodeServiceRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_ServiceAccept()
{
	NASPduFGMM_ServiceAccept objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_ServiceAccept));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeServiceAccept( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_ServiceReject()
{
	NASPduFGMM_ServiceReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_ServiceReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mFGMMCause.isset = 1;
	objRequest.mFGMMCause.CauseValue = 27;

	__si_naspdu_fgmm_encodeServiceReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_ConfigurationUpdateCommand()
{
	NASPduFGMM_ConfigurationUpdateCommand objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_ConfigurationUpdateCommand));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeConfigurationUpdateCommand( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_ConfigurationUpdateComplete()
{
	NASPduFGMM_ConfigurationUpdateComplete objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_ConfigurationUpdateComplete));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeConfigurationUpdateComplete( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_IdentityRequest()
{
	NASPduFGMM_IdentityRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_IdentityRequest));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.FGSIdentityType = 2;
	
	__si_naspdu_fgmm_encodeIdentityRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_IdentityResponse()
{
	NASPduFGMM_IdentityResponse objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_IdentityResponse));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mMobileIdentity.isset = 1;
	objRequest.mMobileIdentity.Length = 11;
	//2 5G-GUTI
	objRequest.mMobileIdentity.data[0] = 242;
	
	//MCC
	objRequest.mMobileIdentity.data[1] = 0x04;
	objRequest.mMobileIdentity.data[2] = 0xF4;
	objRequest.mMobileIdentity.data[3] = 0x01;
	
	//AMF Region ID
	objRequest.mMobileIdentity.data[4] = 33;
	
	//AMF SET ID
	objRequest.mMobileIdentity.data[5] = 233;	
	objRequest.mMobileIdentity.data[6] = 7;
	
	objRequest.mMobileIdentity.data[7] = 8;
	objRequest.mMobileIdentity.data[8] = 9;
	objRequest.mMobileIdentity.data[9] = 10;
	objRequest.mMobileIdentity.data[9] = 11;

	__si_naspdu_fgmm_encodeIdentityResponse( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_Notification()
{
	NASPduFGMM_Notification objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_Notification));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.b1.AccessType = 1;

	__si_naspdu_fgmm_encodeNotification( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_NotificationResponse()
{
	NASPduFGMM_NotificationResponse objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_NotificationResponse));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeNotificationResponse( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_SecurityModeCommand()
{
	NASPduFGMM_SecurityModeCommand objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_SecurityModeCommand));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mNASSecurityAlgorithms.isset = 1;
	objRequest.mNASSecurityAlgorithms.b1.TypeOfCipheringAlgorithm = 9;
	
	objRequest.b1.TSC = 1;
	objRequest.b1.ngKSI = 3;

	objRequest.mUESecurityCapability.isset = 1;
	objRequest.mUESecurityCapability.b1.FGEA3 = 1;
	objRequest.mUESecurityCapability.b2.FGIA6 = 1;
	objRequest.mUESecurityCapability.b3.EGEA5 = 1;

	__si_naspdu_fgmm_encodeSecurityModeCommand( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_SecurityModeComplete()
{
	NASPduFGMM_SecurityModeComplete objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_SecurityModeComplete));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	__si_naspdu_fgmm_encodeSecurityModeComplete( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_mmm_SecurityModeReject()
{
	NASPduFGMM_SecurityModeReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_SecurityModeReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.mFGMMCause.isset = 1;
	objRequest.mFGMMCause.CauseValue = 27;
	
	__si_naspdu_fgmm_encodeSecurityModeReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}

void __ngran_nas_mmm_SecurityProtected5GSNASMessage()
{
	//NASPduFGSM_PDUSessionEstablishmentRequest objRequest;
	//memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionEstablishmentRequest));
}

void __ngran_nas_mmm_5GMMStatus()
{
	NASPduFGMM_5GMMStatus objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGMM_5GMMStatus));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);
	
	objRequest.mFGMMCause.CauseValue = 3;
	objRequest.mFGMMCause.isset = 1;
	
	__si_naspdu_fgmm_encode5GMMStatus( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}


void __ngran_nas_mmm()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;
	uint32_t bExit = 0;
	
	while(1)
	{
		printf(" 1 AUTHENTICATION REQUEST:                    2 AUTHENTICATION RESPONSE                  3 AUTHENTICATION RESULT\n");
		printf(" 4 AUTHENTICATION FAILURE:                    5 AUTHENTICATION REJECT                    6 REGISTRATION REQUEST\n");
		printf(" 7 REGISTRATION ACCEPT:                       8 REGISTRATION COMPLETE                    9 REGISTRATION REJECT\n");
		printf("10 UL NAS TRANSPORT:                         11 DL NAS TRANSPORT                        12 DEREGISTRATION REQUEST( UR O)\n");
		printf("13 DEREGISTRATION ACCEPT (UE O):             14 DEREGISTRATION REQUEST (UE T)           15 DEREGISTRATION ACCEPT\n");		
		printf("16 SERVICE REQUEST:                          17 SERVICE ACCEPT                          18 SERVICE REJECT\n");
		printf("19 CONFIGURATION UPDATE COMMAND:             20 CONFIGURATION UPDATE COMPLETE           21 IDENTITY REQUEST\n");
		printf("22 IDENTITY RESPONSE:                        23 NOTIFICATION                            24 NOTIFICATION RESPONSE\n");
		printf("25 SECURITY MODE COMMAND:                    26 SECURITY MODE COMPLETE                  27 SECURITY MODE REJECT\n");
		printf("28 SECURITY PROTECTED 5GS NAS MESSAGE:       29 5GMM STATUS                             30 EXIT\n");
		
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);
		
		if( selected >= 1 && selected <= 30)
		{
			switch(selected)
			{
				case 1:
					__ngran_nas_mmm_AuthenticationRequest();
					break;
				case 2:
					__ngran_nas_mmm_AuthenticationResponse();
					break;
				case 3:
					__ngran_nas_mmm_AuthenticationResult();
					break;
				case 4:
					__ngran_nas_mmm_AuthenticationFailure();
					break;
				case 5:
					__ngran_nas_mmm_AuthenticationReject();
					break;
				case 6:
					__ngran_nas_mmm_RegistrationRequest();
					break;
				case 7:
					__ngran_nas_mmm_RegistrationAccept();
					break;
				case 8:
					__ngran_nas_mmm_RegistrationComplete();
					break;
				case 9:
					__ngran_nas_mmm_RegistrationReject();
					break;
				case 10:
					__ngran_nas_mmm_ULNASTransport();
					break;
				case 11:
					__ngran_nas_mmm_DLNASTransport();
					break;
				case 12:
					__ngran_nas_mmm_DeRegistrationRequestUEO();
					break;
				case 13:
					__ngran_nas_mmm_DeRegistrationAcceptUEO();
					break;
				case 14:
					__ngran_nas_mmm_DeRegistrationRequestUET();
					break;
				case 15:
					__ngran_nas_mmm_DeRegistrationAcceptUET();
					break;
				case 16:
					__ngran_nas_mmm_ServiceRequest();
					break;
				case 17:
					__ngran_nas_mmm_ServiceAccept();
					break;
				case 18:
					__ngran_nas_mmm_ServiceReject();
					break;
				case 19:
					__ngran_nas_mmm_ConfigurationUpdateCommand();
					break;
				case 20:
					__ngran_nas_mmm_ConfigurationUpdateComplete();
					break;
				case 21:
					__ngran_nas_mmm_IdentityRequest();
					break;
				case 22:
					__ngran_nas_mmm_IdentityResponse();
					break;
				case 23:
					__ngran_nas_mmm_Notification();
					break;
				case 24:
					__ngran_nas_mmm_NotificationResponse();
					break;
				case 25:
					__ngran_nas_mmm_SecurityModeCommand();
					break;
				case 26:
					__ngran_nas_mmm_SecurityModeComplete();
					break;
				case 27:
					__ngran_nas_mmm_SecurityModeReject();
					break;
				case 28:
					__ngran_nas_mmm_SecurityProtected5GSNASMessage();
					break;
				case 29:
					__ngran_nas_mmm_5GMMStatus();
					break;
				case 30:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_nas_smm_PDUSessionEstablishmentRequest()
{
	NASPduFGSM_PDUSessionEstablishmentRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionEstablishmentRequest));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mIntegrityProtectionMaximumDataRate.isset = 1;
	objRequest.mIntegrityProtectionMaximumDataRate.MaximumDataRatePerUEForUserPlaneIntegrityProtection_Uplink = 0;
	objRequest.mIntegrityProtectionMaximumDataRate.MaximumDataRatePerUEForUserPlaneIntegrityProtection_Downlink = 255;
	
	__si_naspdu_fgsm_encodePDUSessionEstablishmentRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionEstablishmentAccept()
{
	NASPduFGSM_PDUSessionEstablishmentAccept objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionEstablishmentAccept));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.b1.PDUSessionType = 1;
	objRequest.b1.SSCMode = 2;
	
	objRequest.mAuthorizedQoSRules.isset = 1;
	objRequest.mAuthorizedQoSRules.Length = 0;
	
	objRequest.mSessionAMBR.isset = 1;
	objRequest.mSessionAMBR.UnitForSessionAMBRForDownlink = 3;
	objRequest.mSessionAMBR.SessionAMBRForDownlink = 23;
	objRequest.mSessionAMBR.UnitForSessionAMBRForUplink = 6;
	objRequest.mSessionAMBR.SessionAMBRForUplink = 26;
	
	__si_naspdu_fgsm_encodePDUSessionEstablishmentAccept( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionEstablishmentReject()
{
	NASPduFGSM_PDUSessionEstablishmentReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionEstablishmentReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;
	
	__si_naspdu_fgsm_encodePDUSessionEstablishmentReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}

void __ngran_nas_smm_PDUSessionAuthenticationCommand()
{
	NASPduFGSM_PDUSessionAuthenticationCommand objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionAuthenticationCommand));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 5;
	objRequest.pHeader.ProcedureTransactionIdentity = 55;
	
	objRequest.mEAPMessage.isset = 1;
	objRequest.mEAPMessage.Length = 0;
	
	__si_naspdu_fgsm_encodePDUSessionAuthenticationCommand( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionAuthenticationComplete()
{
	NASPduFGSM_PDUSessionAuthenticationComplete objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionAuthenticationComplete));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mEAPMessage.isset = 1;
	objRequest.mEAPMessage.Length = 0;
	
	__si_naspdu_fgsm_encodePDUSessionAuthenticationComplete( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}

void __ngran_nas_smm_PDUSessionAuthenticationResult()
{
	NASPduFGSM_PDUSessionAuthenticationResult objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionAuthenticationResult));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mEAPMessage.isset = 1;
	objRequest.mEAPMessage.Length = 0;
	
	
	__si_naspdu_fgsm_encodePDUSessionAuthenticationResult( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}

void __ngran_nas_smm_PDUSessionModificationRequest()
{
	NASPduFGSM_PDUSessionModificationRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionModificationRequest));

	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	__si_naspdu_fgsm_encodePDUSessionModificationRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}

void __ngran_nas_smm_PDUSessionModificationReject()
{
	NASPduFGSM_PDUSessionModificationReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionModificationReject));

	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;
	
	__si_naspdu_fgsm_encodePDUSessionModificationReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);
}

void __ngran_nas_smm_PDUSessionModificationCommand()
{
	NASPduFGSM_PDUSessionModificationCommand objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionModificationCommand));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;
	
	__si_naspdu_fgsm_encodePDUSessionModificationCommand( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionModificationComplete()
{
	NASPduFGSM_PDUSessionModificationComplete objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionModificationComplete));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	__si_naspdu_fgsm_encodePDUSessionModificationComplete( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionModificationCommandReject()
{
	NASPduFGSM_PDUSessionModificationCommandReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionModificationCommandReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);
	
	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;	
	
	__si_naspdu_fgsm_encodePDUSessionModificationCommandReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionReleaseRequest()
{
	NASPduFGSM_PDUSessionReleaseRequest objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionReleaseRequest));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;	
	
	__si_naspdu_fgsm_encodePDUSessionReleaseRequest( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionReleaseReject()
{
	NASPduFGSM_PDUSessionReleaseReject objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionReleaseReject));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;	
	
	__si_naspdu_fgsm_encodePDUSessionReleaseReject( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionReleaseCommand()
{
	NASPduFGSM_PDUSessionReleaseCommand objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionReleaseCommand));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;
	
	__si_naspdu_fgsm_encodePDUSessionReleaseCommand( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_PDUSessionReleaseComplete()
{
	NASPduFGSM_PDUSessionReleaseComplete objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_PDUSessionReleaseComplete));
	
	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;
	
	__si_naspdu_fgsm_encodePDUSessionReleaseComplete( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm_5GSMStatus()
{
	NASPduFGSM_Status objRequest;
	memset( &objRequest, 0, sizeof(NASPduFGSM_Status));

	SI_ASN_CodingContext context;
	__si_asn_memset( &context);

	objRequest.pHeader.PDUSessionId = 1;
	objRequest.pHeader.ProcedureTransactionIdentity = 101;
	
	objRequest.mFGSMCause.isset = 1;
	objRequest.mFGSMCause.CauseValue = 47;

	__si_naspdu_fgsm_encodeStatus( &objRequest, &context);
	__ngran_nas_mm_send_msg( &context);	
}

void __ngran_nas_smm()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;
	uint32_t bExit = 0;
	
	while(1)
	{
		printf(" 1 PDU SESSION ESTABLISHMENT REQUEST:         2 PDU SESSION ESTABLISHMENT ACCEPT         3 PDU SESSION ESTABLISHMENT REJECT\n");
		printf(" 4 PDU SESSION AUTHENTICATION COMMAND:        5 PDU SESSION AUTHENTICATION COMPLETE      6 PDU SESSION AUTHENTICATION RESULT\n");
		printf(" 7 PDU SESSION MODIFICATION REQUEST:          8 PDU SESSION MODIFICATION REJECT          9 PDU SESSION MODIFICATION COMMAND\n");
		printf("10 PDU SESSION MODIFICATION COMPLETE:        11 PDU SESSION MODIFICATION COMMAND REJECT 12 PDU SESSION RELEASE REQUEST\n");
		printf("13 PDU SESSION RELEASE REJECT:               14 PDU SESSION RELEASE COMMAND             15 PDU SESSION RELEASE COMPLETE\n");		
		printf("16 5GSM STATUS:                              17 EXIT\n");
		
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);
		
		if( selected >= 1 && selected <= 17)
		{
			switch(selected)
			{
				case 1:
					__ngran_nas_smm_PDUSessionEstablishmentRequest();
					break;
				case 2:
					__ngran_nas_smm_PDUSessionEstablishmentAccept();
					break;
				case 3:
					__ngran_nas_smm_PDUSessionEstablishmentReject();
					break;
				case 4:
					__ngran_nas_smm_PDUSessionAuthenticationCommand();
					break;
				case 5:
					__ngran_nas_smm_PDUSessionAuthenticationComplete();
					break;
				case 6:
					__ngran_nas_smm_PDUSessionAuthenticationResult();
					break;
				case 7:
					__ngran_nas_smm_PDUSessionModificationRequest();
					break;
				case 8:
					__ngran_nas_smm_PDUSessionModificationReject();
					break;
				case 9:
					__ngran_nas_smm_PDUSessionModificationCommand();
					break;
				case 10:
					__ngran_nas_smm_PDUSessionModificationComplete();
					break;
				case 11:
					__ngran_nas_smm_PDUSessionModificationCommandReject();
					break;
				case 12:
					__ngran_nas_smm_PDUSessionReleaseRequest();
					break;
				case 13:
					__ngran_nas_smm_PDUSessionReleaseReject();
					break;
				case 14:
					__ngran_nas_smm_PDUSessionReleaseCommand();
					break;
				case 15:
					__ngran_nas_smm_PDUSessionReleaseComplete();
					break;
				case 16:
					__ngran_nas_smm_5GSMStatus();
					break;					
				case 17:
					bExit = 1;
					break;	
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
		
		if( bExit == 1)
			break;
	}
}

void __ngran_ngap_procedures_menu()
{
	system("clear");
	
	char option[5];
	uint32_t selected = 0;	
	
	while(1)
	{
		printf(" 1 PDU Session Management:\n");
		printf(" 2 UE Context Management:\n");
		printf(" 3 UE Mobility Management:\n");
		printf(" 4 Paging:\n");
		printf(" 5 Transport of NAS Messages:\n");
		printf(" 6 Interface Management:\n");
		printf(" 7 Configuration Transfer:\n");
		printf(" 8 Warning Message Transmission:\n");
		printf(" 9 NRPPa Transport:\n");
		printf("10 Trace:\n");
		printf("11 Location Reporting:\n");
		printf("12 UE TNLA Binding:\n");
		printf("13 UE Capability Management:\n");
		printf("14 5GS Mobility Management Messages:\n");
		printf("15 5GS Session Management Messages:\n");
		printf("\n");
		
		printf("please select option:");
		scanf( "%s", option);
		selected = atoi( option);

		if( selected >= 1 && selected <= 15)
		{
			switch(selected)
			{
				case 1:
					__ngran_ngap_pdu_session_management();
					break;
				case 2:
					__ngran_ngap_ue_context_management();
					break;
				case 3:
					__ngran_ngap_ue_mobility_management();
					break;
				case 4:
					__ngran_ngap_paging();
					break;
				case 5:
					__ngran_ngap_transport_of_nas_messages();
					break;
				case 6:
					__ngran_ngap_interface_management();
					break;
				case 7:
					__ngran_ngap_configuration_transfer();
					break;
				case 8:
					__ngran_ngap_warning_message_transfer();
					break;
				case 9:
					__ngran_ngap_nrppa_transfer();
					break;
				case 10:
					__ngran_ngap_trace();
					break;
				case 11:
					__ngran_ngap_location_reporting();
					break;
				case 12:
					__ngran_ngap_ue_tnla_binding();
					break;
				case 13:
					__ngran_ngap_ue_capability_management();
					break;
				case 14:
					__ngran_nas_mmm();
					break;
				case 15:
					__ngran_nas_smm();
					break;
				default:
					break;
			}
		}
		else
		{
			printf("Invalid Option Selected[%d]\n\n", selected);
		}
	}
}

void __si_node_start_ngran( int argc, char* argv[]);
void __si_core_wait();
void com_ngap_set_message_handler();

int __si_conver_str_to_hex( char * hexout, char * hexstrin);

int main( int argc, char* argv[])
{
	__si_node_start_ngran( argc, argv);
	com_ngap_set_message_handler();
	
	__ngran_ngap_procedures_menu();
	
	__si_core_wait();
	
	return 0;
}




