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

void amf_ngap_procedure_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objNGSetupRequest, SI_NGAPNode * ngNode)
{
	__si_log( SI_STK_LOG, 0, SI_LOG_DEBUG, "received NGSetupRequest message <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
	
	__si_amf_debug_pdu_NGSetupRequest( objNGSetupRequest);
	
	if( objNGSetupRequest->globalRANNodeID_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "globalRANNodeID Not Received in NGSetupRequest, sending failure <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	if( objNGSetupRequest->rANNodeName_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "rANNodeName Not Received in NGSetupRequest, sending failure <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	/*
	if( objNGSetupRequest->supportedTAList_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "supportedTAList Not Received in NGSetupRequest, sending failure <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	*/
	
	if( objNGSetupRequest->defaultPagingDRX_isset == 0)
	{
		__si_log( SI_STK_LOG, 0, SI_LOG_CRITICAL, "defaultPagingDRX Not Received in NGSetupRequest, sending failure <%s|%s|%d>", __FILE__, __FUNCTION__, __LINE__);
		goto send_ie_missing_error;
	}
	
	char plmnId[4] = {0,0,0,0};
	int enbType = 0;
	char nodeId[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int nodeIdlen = 0;
	double nodetype = -1;
	
	if( objNGSetupRequest->globalRANNodeID->SelectedChoice == GlobalRANNodeID_globalGNB_ID_val)
	{
		memcpy( plmnId, objNGSetupRequest->globalRANNodeID->u.globalGNB_ID->pLMNIdentity->data, 3);
		
		if( objNGSetupRequest->globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->bitslen > 0)
		{
			nodeIdlen = objNGSetupRequest->globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->length;
			memcpy( nodeId, objNGSetupRequest->globalRANNodeID->u.globalGNB_ID->gNB_ID->u.gNB_ID->data, nodeIdlen);
			
			nodetype = 0;
		}
	}
	else if( objNGSetupRequest->globalRANNodeID->SelectedChoice == GlobalRANNodeID_globalNgENB_ID_val)
	{
		memcpy( plmnId, objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->pLMNIdentity->data, 3);
		
		if( objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->SelectedChoice == 0)
		{
			if( objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.macroNgENB_ID->bitslen > 0)
			{
				nodeIdlen = objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.macroNgENB_ID->length;
				memcpy( nodeId, objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.macroNgENB_ID->data, nodeIdlen);
				
				nodetype = 1.1;
			}
		}
		else if( objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->SelectedChoice == 1)
		{
			if( objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.shortMacroNgENB_ID->bitslen > 0)
			{
				nodeIdlen = objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.shortMacroNgENB_ID->length;
				memcpy( nodeId, objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.shortMacroNgENB_ID->data, nodeIdlen);
				
				nodetype = 1.2;
			}
		}
		else if( objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->SelectedChoice == 2)
		{
			if( objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.longMacroNgENB_ID->bitslen > 0)
			{
				nodeIdlen = objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.longMacroNgENB_ID->length;
				memcpy( nodeId, objNGSetupRequest->globalRANNodeID->u.globalNgENB_ID->ngENB_ID->u.longMacroNgENB_ID->data, nodeIdlen);
				
				nodetype = 1.3;
			}
		}
	}
	else if( objNGSetupRequest->globalRANNodeID->SelectedChoice == GlobalRANNodeID_globalN3IWF_ID_val)
	{
		memcpy( plmnId, objNGSetupRequest->globalRANNodeID->u.globalN3IWF_ID->pLMNIdentity->data, 3);
		
		if( objNGSetupRequest->globalRANNodeID->u.globalN3IWF_ID->n3IWF_ID->u.n3IWF_ID->bitslen > 0)
		{
			nodeIdlen = objNGSetupRequest->globalRANNodeID->u.globalN3IWF_ID->n3IWF_ID->u.n3IWF_ID->length;
			memcpy( nodeId, objNGSetupRequest->globalRANNodeID->u.globalN3IWF_ID->n3IWF_ID->u.n3IWF_ID->data, nodeIdlen);
			
			nodetype = 2.2;
		}
	}
	
	char nodekey[40];
	memset( nodekey, 0, sizeof(nodekey));
	sprintf( nodekey, "%s-%s-%0.1f", plmnId, nodeId, nodetype);
	
	__si_ngap_setup_ngran( ngNode, objNGSetupRequest->rANNodeName->data, nodekey, plmnId, nodetype, nodeId);
	
		
	SI_AMF_DT_PDU_NGSetupResponse objNGSetupResponse;
	memset( &objNGSetupResponse, 0, sizeof(SI_AMF_DT_PDU_NGSetupResponse));
	
	objNGSetupResponse.aMFName_isset = 1;
	__si_amf_config_set_amf_name( &objNGSetupResponse.aMFName);
	
	
	objNGSetupResponse.servedGUAMIList_isset = 1;
	__si_amf_init_ServedGUAMIList( &objNGSetupResponse.servedGUAMIList);
	
	SI_AMF_DT_ServedGUAMIItem * objItem = (SI_AMF_DT_ServedGUAMIItem *) __si_allocM( sizeof( SI_AMF_DT_ServedGUAMIItem));
	memset( objItem, 0, sizeof( SI_AMF_DT_ServedGUAMIItem));
	
	__si_amf_config_set_guami( &objItem->gUAMI);
	
	__si_linked_list_add( objNGSetupResponse.servedGUAMIList->ServedGUAMIItem, (uint8_t *) objItem);
	
	
	objNGSetupResponse.pLMNSupportList_isset = 0;
	__si_amf_init_PLMNSupportList( &objNGSetupResponse.pLMNSupportList);
	
	SI_AMF_DT_PLMNSupportItem * objPLMNSupportItem = (SI_AMF_DT_PLMNSupportItem *) __si_allocM( sizeof( SI_AMF_DT_PLMNSupportItem));
	memset( objPLMNSupportItem, 0, sizeof( SI_AMF_DT_PLMNSupportItem));
	
	/*
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;
	SI_AMF_DT_SliceSupportList * sliceSupportList;
	*/
	
	__si_amf_config_set_plmn( &objPLMNSupportItem->pLMNIdentity);
	
	__si_amf_init_SliceSupportList( &objPLMNSupportItem->sliceSupportList);
	
	__si_linked_list_add( objNGSetupResponse.pLMNSupportList->PLMNSupportItem, (uint8_t *) objPLMNSupportItem);
	
	/*
	// ID = id-ServedGUAMIList, PRESENCE = mandatory L:7292
	SI_AMF_DT_ServedGUAMIList * servedGUAMIList;
	int servedGUAMIList_isset;	
	
	// ID = id-PLMNSupportList, PRESENCE = mandatory L:7292
	SI_AMF_DT_PLMNSupportList * pLMNSupportList;
	int pLMNSupportList_isset;	
	*/
	
	objNGSetupResponse.relativeAMFCapacity = 75;
	objNGSetupResponse.relativeAMFCapacity_isset = 1;
	
	__si_ngap_send_NGSetupResponse( &objNGSetupResponse, ngNode);

	return;

	//Missing IE Error Handling	
	send_ie_missing_error:
	{
		SI_AMF_DT_PDU_NGSetupFailure * oNGSetupFailure = (SI_AMF_DT_PDU_NGSetupFailure *)  __si_allocM( sizeof( SI_AMF_DT_PDU_NGSetupFailure));
		memset( oNGSetupFailure, 0, sizeof( SI_AMF_DT_PDU_NGSetupFailure));
		
		oNGSetupFailure->cause_isset = 1;
		__si_amf_init_Cause( &oNGSetupFailure->cause);
		oNGSetupFailure->cause->SelectedChoice = 3;
		oNGSetupFailure->cause->u.protocol = CauseProtocol_abstract_syntax_error_falsely_constructed_message_val;
		
		__si_ngap_send_NGSetupFailure( oNGSetupFailure, ngNode);
	}
}

void amf_ngap_procedure_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objNGSetupResponse, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objNGSetupFailure, SI_NGAPNode * ngNode)
{
}


void amf_ngap_procedure_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objRANConfigurationUpdate, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objRANConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objRANConfigurationUpdateFailure, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objAMFConfigurationUpdate, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objAMFConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objAMFConfigurationUpdateFailure, SI_NGAPNode * ngNode)
{
}


void amf_ngap_procedure_NGReset( SI_AMF_DT_PDU_NGReset * objNGReset, SI_NGAPNode * ngNode)
{
	__si_amf_debug_pdu_NGReset( objNGReset);
}

void amf_ngap_procedure_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objNGResetAcknowledge, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objErrorIndication, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objAMFStatusIndication, SI_NGAPNode * ngNode)
{
}
