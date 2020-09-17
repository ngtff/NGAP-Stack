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

#include "sicore.h"
#include "ngap.h"
#include "libNasPdu.h"
#include "libAMFAsn.h"
#include "app_ngap_test_data.h"


/*
void __app_ngap_set_UEAggregateMaximumBitRate( SI_AMF_DT_UEAggregateMaximumBitRate ** uEAggregateMaximumBitRate)
{
	__si_amf_init_UEAggregateMaximumBitRate( uEAggregateMaximumBitRate);
	
	(*uEAggregateMaximumBitRate)->uEAggregateMaximumBitRateDL = 7894512123;
	(*uEAggregateMaximumBitRate)->uEAggregateMaximumBitRateUL = 1472523234;	
}

void __app_ngap_set_SD( SI_AMF_DT_SD ** sD)
{
	__si_amf_init_SD( sD);
	(*sD)->data = (unsigned char *) __si_allocM( 3);
	(*sD)->length = 3;
	(*sD)->data[0] = 0x01;
	(*sD)->data[1] = 0x02;
	(*sD)->data[2] = 0x03;	
}

void __app_ngap_set_STT( SI_AMF_DT_SST ** sST)
{
	__si_amf_init_SST( sST);
	(*sST)->data = (unsigned char *) __si_allocM( 1);
	(*sST)->length = 1;
	(*sST)->data[0] = 0x59;
}

void __app_ngap_set_S_NSSAI( SI_AMF_DT_S_NSSAI ** s_NSSAI)
{
	__si_amf_init_S_NSSAI( s_NSSAI);
	
	SI_AMF_DT_S_NSSAI * objSNSSAI = *s_NSSAI;

	objSNSSAI->isPresent_sD = 1;
	__app_ngap_set_SD( &objSNSSAI->sD);
	__app_ngap_set_STT( &objSNSSAI->sST);
}

void __app_ngap_set_PDUSessionResourceSetupItemSUReq( SI_AMF_DT_PDUSessionResourceSetupItemSUReq ** objItem)
{
	__si_amf_init_PDUSessionResourceSetupItemSUReq( objItem);
	
	(*objItem)->pDUSessionID = 255;
	(*objItem)->isPresent_pDUSessionNAS_PDU = 0;
	
	__app_ngap_set_S_NSSAI( &(*objItem)->s_NSSAI);
	
	__si_amf_init_PDUSessionResourceSetupRequestTransferOctStr( &(*objItem)->pDUSessionResourceSetupRequestTransfer);
}

void __app_ngap_set_PDUSessionResourceSetupListSUReq( SI_AMF_DT_PDUSessionResourceSetupListSUReq ** pDUSessionResourceSetupListSUReq)
{
	int cnt = 2;
	__si_amf_init_PDUSessionResourceSetupListSUReq( pDUSessionResourceSetupListSUReq);
	
	SI_AMF_DT_PDUSessionResourceSetupItemSUReq * objItem = NULL;
	
	int i = 0;
	for( i = 0; i < cnt; i++)
	{	
		__app_ngap_set_PDUSessionResourceSetupItemSUReq( &objItem);
		__si_linked_list_add( (*pDUSessionResourceSetupListSUReq)->PDUSessionResourceSetupItemSUReq, (uint8_t *)objItem);
	}
}

void __app_ngap_set_PLMNIdentity( SI_AMF_DT_PLMNIdentity ** data)
{
	__si_amf_init_PLMNIdentity( data);
	
	SI_AMF_DT_PLMNIdentity * pLMNIdentity = *data;
	
	pLMNIdentity->data = (unsigned char *) __si_allocM(3);
	pLMNIdentity->length = 3;
	pLMNIdentity->data[0] = 0x11;
	pLMNIdentity->data[1] = 0x00;
	pLMNIdentity->data[2] = 0x13;
}

void __app_ngap_set_NR_CGI( SI_AMF_DT_NR_CGI ** data)
{
	__si_amf_init_NR_CGI( data);
	
	SI_AMF_DT_NR_CGI * nR_CGI = *data;
	
	__app_ngap_set_PLMNIdentity( &nR_CGI->pLMNIdentity);
	__app_ngap_set_NRCellIdentity( &nR_CGI->nRCellIdentity);
}

void __app_ngap_set_NRCellIdentity( SI_AMF_DT_NRCellIdentity ** data)
{
	__si_amf_init_NRCellIdentity( data);
	
	SI_AMF_DT_NRCellIdentity * nRCellIdentity  = *data;
	nRCellIdentity->data = (unsigned char *) __si_allocM(5);
	nRCellIdentity->length = 5;
	nRCellIdentity->data[0] = 0x11;
	nRCellIdentity->data[1] = 0x00;
	nRCellIdentity->data[2] = 0x13;	
	nRCellIdentity->data[3] = 0x33;
	nRCellIdentity->data[4] = 0x43;	
}

void __app_ngap_set_TAC( SI_AMF_DT_TAC ** data)
{
	__si_amf_init_TAC( data);
	
	SI_AMF_DT_TAC * tAC = *data;
	tAC->data = (unsigned char *) __si_allocM(2);
	tAC->length = 2;
	tAC->data[0] = 0x11;
	tAC->data[1] = 0x00;	
}

void __app_ngap_set_TAI( SI_AMF_DT_TAI ** data)
{
	__si_amf_init_TAI( data);
	SI_AMF_DT_TAI * tAI = *data;
	
	__app_ngap_set_PLMNIdentity( &tAI->pLMNIdentity);
	__app_ngap_set_TAC( &tAI->tAC);
}

void __app_ngap_set_UserLocationInformationNR( SI_AMF_DT_UserLocationInformationNR ** data)
{
	__si_amf_init_UserLocationInformationNR( data);
	
	SI_AMF_DT_UserLocationInformationNR * userLocationInformationNR = *data;
	
	userLocationInformationNR->isPresent_timeStamp = 0;
	
	//userLocationInformationNR->timeStamp //SI_AMF_DT_TimeStamp	
	
	//SI_AMF_DT_NR_CGI * nR_CGI;
	__app_ngap_set_NR_CGI( &userLocationInformationNR->nR_CGI);

	//SI_AMF_DT_TAI * tAI;	
	__app_ngap_set_TAI( &userLocationInformationNR->tAI);
		
}

void __app_ngap_set_UserLocationInformation( SI_AMF_DT_UserLocationInformation ** data)
{
	__si_amf_init_UserLocationInformation( data);
	
	SI_AMF_DT_UserLocationInformation * userLocationInformation = * data;

	userLocationInformation->SelectedChoice = 1;	
	
	if( userLocationInformation->SelectedChoice == 1)
	{
		__app_ngap_set_UserLocationInformationNR( &userLocationInformation->u.userLocationInformationNR);
	}
	
}

void __app_ngap_set_AMFRegionID( SI_AMF_DT_AMFRegionID ** data)
{
	__si_amf_init_AMFRegionID( data);
	SI_AMF_DT_AMFRegionID * aMFRegionID = *data;
	aMFRegionID->data = (unsigned char *) __si_allocM( 1);
	memcpy( aMFRegionID->data, "\x22", 1);
	aMFRegionID->length = 1;	
}

void __app_ngap_set_AMFSetID( SI_AMF_DT_AMFSetID ** data)
{
	__si_amf_init_AMFSetID( data);
	SI_AMF_DT_AMFSetID * aMFSetID = *data;
	
	aMFSetID->data = (unsigned char *) __si_allocM( 2);
	memcpy( aMFSetID->data, "\x33\x44", 2);
	aMFSetID->length = 2;	
}

void __app_ngap_set_AMFPointer( SI_AMF_DT_AMFPointer ** data)
{
	__si_amf_init_AMFPointer( data);
	
	SI_AMF_DT_AMFPointer * aMFPointer = *data;
	aMFPointer->data = (unsigned char *) __si_allocM( 1);
	memcpy( aMFPointer->data, "x55\x66", 1);
	aMFPointer->length = 1;	
}

void __app_ngap_set_GUAMI( SI_AMF_DT_GUAMI ** data)
{
	__si_amf_init_GUAMI( data);
	
	SI_AMF_DT_GUAMI * gUAMI = *data;
	
	__app_ngap_set_PLMNIdentity( &gUAMI->pLMNIdentity);
	__app_ngap_set_AMFRegionID( &gUAMI->aMFRegionID);
	__app_ngap_set_AMFSetID( &gUAMI->aMFSetID);
	__app_ngap_set_AMFPointer( &gUAMI->aMFPointer);
}

void __app_ngap_set_UE_NGAP_ID_pair( SI_AMF_DT_UE_NGAP_ID_pair ** data)
{
	__si_amf_init_UE_NGAP_ID_pair( data);
	SI_AMF_DT_UE_NGAP_ID_pair * uE_NGAP_ID_pair = *data;
	
	uE_NGAP_ID_pair->aMF_UE_NGAP_ID = 456456;
	uE_NGAP_ID_pair->rAN_UE_NGAP_ID = 789789;
}

void __app_ngap_set_UE_NGAP_IDs( SI_AMF_DT_UE_NGAP_IDs ** data)
{
	__si_amf_init_UE_NGAP_IDs( data);
	SI_AMF_DT_UE_NGAP_IDs * uENGAPIDs = *data;
	
	uENGAPIDs->SelectedChoice = 0;
	
	if( uENGAPIDs->SelectedChoice == 0)
	{	
		__app_ngap_set_UE_NGAP_ID_pair( &uENGAPIDs->u.uE_NGAP_ID_pair);
	}
	else
	{	
		uENGAPIDs->u.aMF_UE_NGAP_ID = 87581;
	}
}

void __app_ngap_set_Cause( SI_AMF_DT_Cause ** data)
{
	__si_amf_init_Cause( data);
	(*data)->SelectedChoice = 4;
	(*data)->u.misc = CauseMisc_om_intervention_val;
	
	//objNGReset.cause->SelectedChoice = 3;
	//objNGReset.cause->u.protocol = CauseProtocol_abstract_syntax_error_ignore_and_notify_val;
}

void __app_ngap_set_SecurityKey( SI_AMF_DT_SecurityKey ** data)
{
	__si_amf_init_SecurityKey( data);
	
	SI_AMF_DT_SecurityKey * securityKey = *data;
	
	securityKey->data =  (unsigned char *) __si_allocM( 33);
	securityKey->length = 33;
	securityKey->data[2] = 0x02;
}

void __app_ngap_set_MessageIdentifier( SI_AMF_DT_MessageIdentifier ** data)
{
	__si_amf_init_MessageIdentifier( data);
	
	SI_AMF_DT_MessageIdentifier * messageIdentifier = *data;
	
	messageIdentifier->data = (unsigned char *) __si_allocM(2);
	messageIdentifier->length = 2;
	messageIdentifier->data[0] = 0x01;
	messageIdentifier->data[1] = 0x02;
}

void __app_ngap_set_SerialNumber( SI_AMF_DT_SerialNumber ** data)
{
	__si_amf_init_SerialNumber( data);
	
	SI_AMF_DT_SerialNumber * serialNumber = *data;
	
	serialNumber->data = (unsigned char *) __si_allocM(2);
	serialNumber->length = 2;
	serialNumber->data[0] = 0x03;
	serialNumber->data[1] = 0x04;	
}

void __app_ngap_set_EUTRA_CGI( SI_AMF_DT_EUTRA_CGI ** data)
{
	__si_amf_init_EUTRA_CGI( data);
	
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI = *data;
	
	__app_ngap_set_PLMNIdentity( &eUTRA_CGI->pLMNIdentity);
	__app_ngap_set_EUTRACellIdentity( &eUTRA_CGI->eUTRACellIdentity);
}

void __app_ngap_set_EUTRACellIdentity( SI_AMF_DT_EUTRACellIdentity ** data)
{
	SI_AMF_DT_EUTRACellIdentity * eUTRACellIdentity = *data;
	
	eUTRACellIdentity->data = (unsigned char *) __si_allocM( 4);
	eUTRACellIdentity->data[0] = 0x55;
	eUTRACellIdentity->data[1] = 0x66;
	eUTRACellIdentity->data[2] = 0x77;
	eUTRACellIdentity->data[3] = 0x88;
	eUTRACellIdentity->length = 4;
}

void __app_ngap_set_CellIDBroadcastEUTRA_Item( SI_AMF_DT_CellIDBroadcastEUTRA_Item ** data)
{
	__si_amf_init_CellIDBroadcastEUTRA_Item( data);
	SI_AMF_DT_CellIDBroadcastEUTRA_Item * objItem = *data;
	
	__app_ngap_set_EUTRA_CGI( &objItem->eUTRA_CGI);
	
}

void __app_ngap_set_CellIDBroadcastEUTRA( SI_AMF_DT_CellIDBroadcastEUTRA ** data)
{
	__si_amf_init_CellIDBroadcastEUTRA( data);
	
	SI_AMF_DT_CellIDBroadcastEUTRA * cellIDBroadcastEUTRA = *data;
	
	SI_AMF_DT_CellIDBroadcastEUTRA_Item * objItem = NULL;
	__app_ngap_set_CellIDBroadcastEUTRA_Item( &objItem);
	
	__si_linked_list_add( cellIDBroadcastEUTRA->CellIDBroadcastEUTRA_Item, (uint8_t *)objItem);
}

void __app_ngap_set_BroadcastCompletedAreaList( SI_AMF_DT_BroadcastCompletedAreaList ** data)
{
	__si_amf_init_BroadcastCompletedAreaList( data);
	
	SI_AMF_DT_BroadcastCompletedAreaList * broadcastCompletedAreaList = *data;
	
	broadcastCompletedAreaList->SelectedChoice = 0;
	
	__app_ngap_set_CellIDBroadcastEUTRA( &broadcastCompletedAreaList->u.cellIDBroadcastEUTRA);
}

void __app_ngap_set_EmergencyFallbackIndicator( SI_AMF_DT_EmergencyFallbackIndicator ** data)
{
	__si_amf_init_EmergencyFallbackIndicator( data);
	
	SI_AMF_DT_EmergencyFallbackIndicator * emergencyFallbackIndicator = *data;
	
	emergencyFallbackIndicator->selected_eemergencyFallbackRequestIndicator = 0;
	emergencyFallbackIndicator->selected_eemergencyServiceTargetCN = 1;
	emergencyFallbackIndicator->isPresent_emergencyServiceTargetCN = 1;
}

void __app_ngap_set_CNAssistedRANTuning( SI_AMF_DT_CNAssistedRANTuning ** data)
{
	__si_amf_init_CNAssistedRANTuning( data);
	
	SI_AMF_DT_CNAssistedRANTuning * cNAssistedRANTuning = *data;
	cNAssistedRANTuning->isPresent_expectedUEBehaviour = 0;
}

void __app_ngap_set_FiveG_TMSI( SI_AMF_DT_FiveG_TMSI ** data)
{
	__si_amf_init_FiveG_TMSI( data);
	
	SI_AMF_DT_FiveG_TMSI * fiveG_TMSI = *data;
	
	fiveG_TMSI->data = (unsigned char *) __si_allocM( 5);
	memcpy( fiveG_TMSI->data, "\x01\x02\x03\x04\x05", 5);
	fiveG_TMSI->length = 5;	
}

void __app_ngap_set_FiveG_S_TMSI( SI_AMF_DT_FiveG_S_TMSI ** data)
{
	__si_amf_init_FiveG_S_TMSI( data);
	
	SI_AMF_DT_FiveG_S_TMSI * fiveG_S_TMSI = *data;

	__app_ngap_set_AMFSetID( &fiveG_S_TMSI->aMFSetID);
	__app_ngap_set_AMFPointer( &fiveG_S_TMSI->aMFPointer);
	__app_ngap_set_FiveG_TMSI( &fiveG_S_TMSI->fiveG_TMSI);
}

void __app_ngap_set_UEPagingIdentity( SI_AMF_DT_UEPagingIdentity ** data)
{
	__si_amf_init_UEPagingIdentity( data);
	SI_AMF_DT_UEPagingIdentity * uEPagingIdentity = *data;
	
	uEPagingIdentity->SelectedChoice = 0;
	__app_ngap_set_FiveG_S_TMSI( &uEPagingIdentity->u.fiveG_S_TMSI);
}
*/




//-- SEQUENCE_OF, AdditionalDLUPTNLInformationForHOList
void __app_ngap_set_AdditionalDLUPTNLInformationForHOList( SI_AMF_DT_AdditionalDLUPTNLInformationForHOList ** data)
{
	__si_amf_init_AdditionalDLUPTNLInformationForHOList( data);
	SI_AMF_DT_AdditionalDLUPTNLInformationForHOList * additionalDLUPTNLInformationForHOList = *data;
	
	SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem * objItem = NULL;

	__app_ngap_set_AdditionalDLUPTNLInformationForHOItem( &objItem);
	__si_linked_list_add( (*data)->AdditionalDLUPTNLInformationForHOItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AdditionalDLUPTNLInformationForHOItem
void __app_ngap_set_AdditionalDLUPTNLInformationForHOItem( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem ** data)
{
	__si_amf_init_AdditionalDLUPTNLInformationForHOItem( data);
	SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem * additionalDLUPTNLInformationForHOItem = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &additionalDLUPTNLInformationForHOItem->additionalDL_NGU_UP_TNLInformation);

	__app_ngap_set_QosFlowListWithDataForwarding( &additionalDLUPTNLInformationForHOItem->additionalQosFlowSetupResponseList);

	__app_ngap_set_UPTransportLayerInformation( &additionalDLUPTNLInformationForHOItem->additionalDLForwardingUPTNLInformation);
	additionalDLUPTNLInformationForHOItem->isPresent_additionalDLForwardingUPTNLInformation = 1;
}


//-- CONTAINER, AdditionalDLUPTNLInformationForHOItem-ExtIEs
void __app_ngap_set_AdditionalDLUPTNLInformationForHOItem_ExtIEs( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs ** data)
{
	__si_amf_init_AdditionalDLUPTNLInformationForHOItem_ExtIEs( data);
	SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs * additionalDLUPTNLInformationForHOItem_ExtIEs = *data;
	
}


//-- SEQUENCE, AllocationAndRetentionPriority
void __app_ngap_set_AllocationAndRetentionPriority( SI_AMF_DT_AllocationAndRetentionPriority ** data)
{
	__si_amf_init_AllocationAndRetentionPriority( data);
	SI_AMF_DT_AllocationAndRetentionPriority * allocationAndRetentionPriority = *data;
	
	allocationAndRetentionPriority->priorityLevelARP = __si_core_getU64RANDRange( 1, 15);
	allocationAndRetentionPriority->selected_epre_emptionCapability = 0;
	allocationAndRetentionPriority->selected_epre_emptionVulnerability = 0;
}


//-- CONTAINER, AllocationAndRetentionPriority-ExtIEs
void __app_ngap_set_AllocationAndRetentionPriority_ExtIEs( SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs ** data)
{
	__si_amf_init_AllocationAndRetentionPriority_ExtIEs( data);
	SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs * allocationAndRetentionPriority_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AllowedNSSAI
void __app_ngap_set_AllowedNSSAI( SI_AMF_DT_AllowedNSSAI ** data)
{
	__si_amf_init_AllowedNSSAI( data);
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI = *data;
	
	SI_AMF_DT_AllowedNSSAI_Item * objItem = NULL;

	__app_ngap_set_AllowedNSSAI_Item( &objItem);
	__si_linked_list_add( (*data)->AllowedNSSAI_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, AllowedNSSAI-Item
void __app_ngap_set_AllowedNSSAI_Item( SI_AMF_DT_AllowedNSSAI_Item ** data)
{
	__si_amf_init_AllowedNSSAI_Item( data);
	SI_AMF_DT_AllowedNSSAI_Item * allowedNSSAI_Item = *data;
	
	__app_ngap_set_S_NSSAI( &allowedNSSAI_Item->s_NSSAI);
}


//-- CONTAINER, AllowedNSSAI-Item-ExtIEs
void __app_ngap_set_AllowedNSSAI_Item_ExtIEs( SI_AMF_DT_AllowedNSSAI_Item_ExtIEs ** data)
{
	__si_amf_init_AllowedNSSAI_Item_ExtIEs( data);
	SI_AMF_DT_AllowedNSSAI_Item_ExtIEs * allowedNSSAI_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AllowedTACs
void __app_ngap_set_AllowedTACs( SI_AMF_DT_AllowedTACs ** data)
{
	__si_amf_init_AllowedTACs( data);
	SI_AMF_DT_AllowedTACs * allowedTACs = *data;
	
	SI_AMF_DT_TAC * objItem = NULL;

	__app_ngap_set_TAC( &objItem);
	__si_linked_list_add( (*data)->TAC, (uint8_t *)objItem);
}


//-- PrintableString, AMFName
void __app_ngap_set_AMFName( SI_AMF_DT_AMFName ** data)
{
	__si_amf_init_AMFName( data);
	SI_AMF_DT_AMFName * aMFName = *data;
	
	aMFName->data = (unsigned char *) __si_allocM(150);
	aMFName->length = 150;
	__si_core_fill_dummy_data( aMFName->data, aMFName->length);
}


//-- CHOICE, AMFPagingTarget
void __app_ngap_set_AMFPagingTarget( SI_AMF_DT_AMFPagingTarget ** data)
{
	__si_amf_init_AMFPagingTarget( data);
	SI_AMF_DT_AMFPagingTarget * aMFPagingTarget = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_GlobalRANNodeID( &(*data)->u.globalRANNodeID);

}


//-- CONTAINER, AMFPagingTarget-ExtIEs
void __app_ngap_set_AMFPagingTarget_ExtIEs( SI_AMF_DT_AMFPagingTarget_ExtIEs ** data)
{
	__si_amf_init_AMFPagingTarget_ExtIEs( data);
	SI_AMF_DT_AMFPagingTarget_ExtIEs * aMFPagingTarget_ExtIEs = *data;
	
}


//-- BITSTRING, AMFPointer
void __app_ngap_set_AMFPointer( SI_AMF_DT_AMFPointer ** data)
{
	__si_amf_init_AMFPointer( data);
	SI_AMF_DT_AMFPointer * aMFPointer = *data;
	
	//BITSIZE = 6  , BIT STRING(SIZE(6))
	aMFPointer->data = (unsigned char *) __si_allocM(2);
	aMFPointer->length = 2;
	aMFPointer->bitslen = 6;
	__si_core_fill_dummy_data( aMFPointer->data, aMFPointer->length);
}


//-- BITSTRING, AMFRegionID
void __app_ngap_set_AMFRegionID( SI_AMF_DT_AMFRegionID ** data)
{
	__si_amf_init_AMFRegionID( data);
	SI_AMF_DT_AMFRegionID * aMFRegionID = *data;
	
	//BITSIZE = 8  , BIT STRING(SIZE(8))
	aMFRegionID->data = (unsigned char *) __si_allocM(2);
	aMFRegionID->length = 2;
	aMFRegionID->bitslen = 8;
	__si_core_fill_dummy_data( aMFRegionID->data, aMFRegionID->length);
}


//-- BITSTRING, AMFSetID
void __app_ngap_set_AMFSetID( SI_AMF_DT_AMFSetID ** data)
{
	__si_amf_init_AMFSetID( data);
	SI_AMF_DT_AMFSetID * aMFSetID = *data;
	
	//BITSIZE = 10  , BIT STRING(SIZE(10))
	aMFSetID->data = (unsigned char *) __si_allocM(3);
	aMFSetID->length = 3;
	aMFSetID->bitslen = 10;
	__si_core_fill_dummy_data( aMFSetID->data, aMFSetID->length);
}


//-- SEQUENCE_OF, AMF-TNLAssociationSetupList
void __app_ngap_set_AMF_TNLAssociationSetupList( SI_AMF_DT_AMF_TNLAssociationSetupList ** data)
{
	__si_amf_init_AMF_TNLAssociationSetupList( data);
	SI_AMF_DT_AMF_TNLAssociationSetupList * aMF_TNLAssociationSetupList = *data;
	
	SI_AMF_DT_AMF_TNLAssociationSetupItem * objItem = NULL;

	__app_ngap_set_AMF_TNLAssociationSetupItem( &objItem);
	__si_linked_list_add( (*data)->AMF_TNLAssociationSetupItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AMF-TNLAssociationSetupItem
void __app_ngap_set_AMF_TNLAssociationSetupItem( SI_AMF_DT_AMF_TNLAssociationSetupItem ** data)
{
	__si_amf_init_AMF_TNLAssociationSetupItem( data);
	SI_AMF_DT_AMF_TNLAssociationSetupItem * aMF_TNLAssociationSetupItem = *data;
	
	__app_ngap_set_CPTransportLayerInformation( &aMF_TNLAssociationSetupItem->aMF_TNLAssociationAddress);
}


//-- CONTAINER, AMF-TNLAssociationSetupItem-ExtIEs
void __app_ngap_set_AMF_TNLAssociationSetupItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs ** data)
{
	__si_amf_init_AMF_TNLAssociationSetupItem_ExtIEs( data);
	SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs * aMF_TNLAssociationSetupItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AMF-TNLAssociationToAddList
void __app_ngap_set_AMF_TNLAssociationToAddList( SI_AMF_DT_AMF_TNLAssociationToAddList ** data)
{
	__si_amf_init_AMF_TNLAssociationToAddList( data);
	SI_AMF_DT_AMF_TNLAssociationToAddList * aMF_TNLAssociationToAddList = *data;
	
	SI_AMF_DT_AMF_TNLAssociationToAddItem * objItem = NULL;

	__app_ngap_set_AMF_TNLAssociationToAddItem( &objItem);
	__si_linked_list_add( (*data)->AMF_TNLAssociationToAddItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AMF-TNLAssociationToAddItem
void __app_ngap_set_AMF_TNLAssociationToAddItem( SI_AMF_DT_AMF_TNLAssociationToAddItem ** data)
{
	__si_amf_init_AMF_TNLAssociationToAddItem( data);
	SI_AMF_DT_AMF_TNLAssociationToAddItem * aMF_TNLAssociationToAddItem = *data;
	
	__app_ngap_set_CPTransportLayerInformation( &aMF_TNLAssociationToAddItem->aMF_TNLAssociationAddress);

	aMF_TNLAssociationToAddItem->selected_etNLAssociationUsage = 0;
	aMF_TNLAssociationToAddItem->tNLAddressWeightFactor = __si_core_getU64RANDRange( 0, 255);
}


//-- CONTAINER, AMF-TNLAssociationToAddItem-ExtIEs
void __app_ngap_set_AMF_TNLAssociationToAddItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs ** data)
{
	__si_amf_init_AMF_TNLAssociationToAddItem_ExtIEs( data);
	SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs * aMF_TNLAssociationToAddItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AMF-TNLAssociationToRemoveList
void __app_ngap_set_AMF_TNLAssociationToRemoveList( SI_AMF_DT_AMF_TNLAssociationToRemoveList ** data)
{
	__si_amf_init_AMF_TNLAssociationToRemoveList( data);
	SI_AMF_DT_AMF_TNLAssociationToRemoveList * aMF_TNLAssociationToRemoveList = *data;
	
	SI_AMF_DT_AMF_TNLAssociationToRemoveItem * objItem = NULL;

	__app_ngap_set_AMF_TNLAssociationToRemoveItem( &objItem);
	__si_linked_list_add( (*data)->AMF_TNLAssociationToRemoveItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AMF-TNLAssociationToRemoveItem
void __app_ngap_set_AMF_TNLAssociationToRemoveItem( SI_AMF_DT_AMF_TNLAssociationToRemoveItem ** data)
{
	__si_amf_init_AMF_TNLAssociationToRemoveItem( data);
	SI_AMF_DT_AMF_TNLAssociationToRemoveItem * aMF_TNLAssociationToRemoveItem = *data;
	
	__app_ngap_set_CPTransportLayerInformation( &aMF_TNLAssociationToRemoveItem->aMF_TNLAssociationAddress);
}


//-- CONTAINER, AMF-TNLAssociationToRemoveItem-ExtIEs
void __app_ngap_set_AMF_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs ** data)
{
	__si_amf_init_AMF_TNLAssociationToRemoveItem_ExtIEs( data);
	SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs * aMF_TNLAssociationToRemoveItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AMF-TNLAssociationToUpdateList
void __app_ngap_set_AMF_TNLAssociationToUpdateList( SI_AMF_DT_AMF_TNLAssociationToUpdateList ** data)
{
	__si_amf_init_AMF_TNLAssociationToUpdateList( data);
	SI_AMF_DT_AMF_TNLAssociationToUpdateList * aMF_TNLAssociationToUpdateList = *data;
	
	SI_AMF_DT_AMF_TNLAssociationToUpdateItem * objItem = NULL;

	__app_ngap_set_AMF_TNLAssociationToUpdateItem( &objItem);
	__si_linked_list_add( (*data)->AMF_TNLAssociationToUpdateItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AMF-TNLAssociationToUpdateItem
void __app_ngap_set_AMF_TNLAssociationToUpdateItem( SI_AMF_DT_AMF_TNLAssociationToUpdateItem ** data)
{
	__si_amf_init_AMF_TNLAssociationToUpdateItem( data);
	SI_AMF_DT_AMF_TNLAssociationToUpdateItem * aMF_TNLAssociationToUpdateItem = *data;
	
	__app_ngap_set_CPTransportLayerInformation( &aMF_TNLAssociationToUpdateItem->aMF_TNLAssociationAddress);

	aMF_TNLAssociationToUpdateItem->selected_etNLAssociationUsage = 0;
	aMF_TNLAssociationToUpdateItem->tNLAddressWeightFactor = __si_core_getU64RANDRange( 0, 255);
}


//-- CONTAINER, AMF-TNLAssociationToUpdateItem-ExtIEs
void __app_ngap_set_AMF_TNLAssociationToUpdateItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs ** data)
{
	__si_amf_init_AMF_TNLAssociationToUpdateItem_ExtIEs( data);
	SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs * aMF_TNLAssociationToUpdateItem_ExtIEs = *data;
	
}


//-- INTEGER, AMF-UE-NGAP-ID
void __app_ngap_set_AMF_UE_NGAP_ID( SI_AMF_DT_AMF_UE_NGAP_ID ** data)
{
	SI_AMF_DT_AMF_UE_NGAP_ID * aMF_UE_NGAP_ID = *data;
	
	//MIN = 0, MAX = 1099511627775
	aMF_UE_NGAP_ID->data = __si_core_getU64RANDRange( 0, 1099511627775);
}


//-- SEQUENCE, AreaOfInterest
void __app_ngap_set_AreaOfInterest( SI_AMF_DT_AreaOfInterest ** data)
{
	__si_amf_init_AreaOfInterest( data);
	SI_AMF_DT_AreaOfInterest * areaOfInterest = *data;
	
	__app_ngap_set_AreaOfInterestTAIList( &areaOfInterest->areaOfInterestTAIList);
	areaOfInterest->isPresent_areaOfInterestTAIList = 1;

	__app_ngap_set_AreaOfInterestCellList( &areaOfInterest->areaOfInterestCellList);
	areaOfInterest->isPresent_areaOfInterestCellList = 1;

	__app_ngap_set_AreaOfInterestRANNodeList( &areaOfInterest->areaOfInterestRANNodeList);
	areaOfInterest->isPresent_areaOfInterestRANNodeList = 1;
}


//-- CONTAINER, AreaOfInterest-ExtIEs
void __app_ngap_set_AreaOfInterest_ExtIEs( SI_AMF_DT_AreaOfInterest_ExtIEs ** data)
{
	__si_amf_init_AreaOfInterest_ExtIEs( data);
	SI_AMF_DT_AreaOfInterest_ExtIEs * areaOfInterest_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AreaOfInterestCellList
void __app_ngap_set_AreaOfInterestCellList( SI_AMF_DT_AreaOfInterestCellList ** data)
{
	__si_amf_init_AreaOfInterestCellList( data);
	SI_AMF_DT_AreaOfInterestCellList * areaOfInterestCellList = *data;
	
	SI_AMF_DT_AreaOfInterestCellItem * objItem = NULL;

	__app_ngap_set_AreaOfInterestCellItem( &objItem);
	__si_linked_list_add( (*data)->AreaOfInterestCellItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AreaOfInterestCellItem
void __app_ngap_set_AreaOfInterestCellItem( SI_AMF_DT_AreaOfInterestCellItem ** data)
{
	__si_amf_init_AreaOfInterestCellItem( data);
	SI_AMF_DT_AreaOfInterestCellItem * areaOfInterestCellItem = *data;
	
	__app_ngap_set_NGRAN_CGI( &areaOfInterestCellItem->nGRAN_CGI);
}


//-- CONTAINER, AreaOfInterestCellItem-ExtIEs
void __app_ngap_set_AreaOfInterestCellItem_ExtIEs( SI_AMF_DT_AreaOfInterestCellItem_ExtIEs ** data)
{
	__si_amf_init_AreaOfInterestCellItem_ExtIEs( data);
	SI_AMF_DT_AreaOfInterestCellItem_ExtIEs * areaOfInterestCellItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AreaOfInterestList
void __app_ngap_set_AreaOfInterestList( SI_AMF_DT_AreaOfInterestList ** data)
{
	__si_amf_init_AreaOfInterestList( data);
	SI_AMF_DT_AreaOfInterestList * areaOfInterestList = *data;
	
	SI_AMF_DT_AreaOfInterestItem * objItem = NULL;

	__app_ngap_set_AreaOfInterestItem( &objItem);
	__si_linked_list_add( (*data)->AreaOfInterestItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AreaOfInterestItem
void __app_ngap_set_AreaOfInterestItem( SI_AMF_DT_AreaOfInterestItem ** data)
{
	__si_amf_init_AreaOfInterestItem( data);
	SI_AMF_DT_AreaOfInterestItem * areaOfInterestItem = *data;
	
	__app_ngap_set_AreaOfInterest( &areaOfInterestItem->areaOfInterest);

	areaOfInterestItem->locationReportingReferenceID = __si_core_getU64RANDRange( 1, 64);
}


//-- CONTAINER, AreaOfInterestItem-ExtIEs
void __app_ngap_set_AreaOfInterestItem_ExtIEs( SI_AMF_DT_AreaOfInterestItem_ExtIEs ** data)
{
	__si_amf_init_AreaOfInterestItem_ExtIEs( data);
	SI_AMF_DT_AreaOfInterestItem_ExtIEs * areaOfInterestItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AreaOfInterestRANNodeList
void __app_ngap_set_AreaOfInterestRANNodeList( SI_AMF_DT_AreaOfInterestRANNodeList ** data)
{
	__si_amf_init_AreaOfInterestRANNodeList( data);
	SI_AMF_DT_AreaOfInterestRANNodeList * areaOfInterestRANNodeList = *data;
	
	SI_AMF_DT_AreaOfInterestRANNodeItem * objItem = NULL;

	__app_ngap_set_AreaOfInterestRANNodeItem( &objItem);
	__si_linked_list_add( (*data)->AreaOfInterestRANNodeItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AreaOfInterestRANNodeItem
void __app_ngap_set_AreaOfInterestRANNodeItem( SI_AMF_DT_AreaOfInterestRANNodeItem ** data)
{
	__si_amf_init_AreaOfInterestRANNodeItem( data);
	SI_AMF_DT_AreaOfInterestRANNodeItem * areaOfInterestRANNodeItem = *data;
	
	__app_ngap_set_GlobalRANNodeID( &areaOfInterestRANNodeItem->globalRANNodeID);
}


//-- CONTAINER, AreaOfInterestRANNodeItem-ExtIEs
void __app_ngap_set_AreaOfInterestRANNodeItem_ExtIEs( SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs ** data)
{
	__si_amf_init_AreaOfInterestRANNodeItem_ExtIEs( data);
	SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs * areaOfInterestRANNodeItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AreaOfInterestTAIList
void __app_ngap_set_AreaOfInterestTAIList( SI_AMF_DT_AreaOfInterestTAIList ** data)
{
	__si_amf_init_AreaOfInterestTAIList( data);
	SI_AMF_DT_AreaOfInterestTAIList * areaOfInterestTAIList = *data;
	
	SI_AMF_DT_AreaOfInterestTAIItem * objItem = NULL;

	__app_ngap_set_AreaOfInterestTAIItem( &objItem);
	__si_linked_list_add( (*data)->AreaOfInterestTAIItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AreaOfInterestTAIItem
void __app_ngap_set_AreaOfInterestTAIItem( SI_AMF_DT_AreaOfInterestTAIItem ** data)
{
	__si_amf_init_AreaOfInterestTAIItem( data);
	SI_AMF_DT_AreaOfInterestTAIItem * areaOfInterestTAIItem = *data;
	
	__app_ngap_set_TAI( &areaOfInterestTAIItem->tAI);
}


//-- CONTAINER, AreaOfInterestTAIItem-ExtIEs
void __app_ngap_set_AreaOfInterestTAIItem_ExtIEs( SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs ** data)
{
	__si_amf_init_AreaOfInterestTAIItem_ExtIEs( data);
	SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs * areaOfInterestTAIItem_ExtIEs = *data;
	
}


//-- SEQUENCE, AssistanceDataForPaging
void __app_ngap_set_AssistanceDataForPaging( SI_AMF_DT_AssistanceDataForPaging ** data)
{
	__si_amf_init_AssistanceDataForPaging( data);
	SI_AMF_DT_AssistanceDataForPaging * assistanceDataForPaging = *data;
	
	__app_ngap_set_AssistanceDataForRecommendedCells( &assistanceDataForPaging->assistanceDataForRecommendedCells);
	assistanceDataForPaging->isPresent_assistanceDataForRecommendedCells = 1;

	__app_ngap_set_PagingAttemptInformation( &assistanceDataForPaging->pagingAttemptInformation);
	assistanceDataForPaging->isPresent_pagingAttemptInformation = 1;
}


//-- CONTAINER, AssistanceDataForPaging-ExtIEs
void __app_ngap_set_AssistanceDataForPaging_ExtIEs( SI_AMF_DT_AssistanceDataForPaging_ExtIEs ** data)
{
	__si_amf_init_AssistanceDataForPaging_ExtIEs( data);
	SI_AMF_DT_AssistanceDataForPaging_ExtIEs * assistanceDataForPaging_ExtIEs = *data;
	
}


//-- SEQUENCE, AssistanceDataForRecommendedCells
void __app_ngap_set_AssistanceDataForRecommendedCells( SI_AMF_DT_AssistanceDataForRecommendedCells ** data)
{
	__si_amf_init_AssistanceDataForRecommendedCells( data);
	SI_AMF_DT_AssistanceDataForRecommendedCells * assistanceDataForRecommendedCells = *data;
	
	__app_ngap_set_RecommendedCellsForPaging( &assistanceDataForRecommendedCells->recommendedCellsForPaging);
}


//-- CONTAINER, AssistanceDataForRecommendedCells-ExtIEs
void __app_ngap_set_AssistanceDataForRecommendedCells_ExtIEs( SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs ** data)
{
	__si_amf_init_AssistanceDataForRecommendedCells_ExtIEs( data);
	SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs * assistanceDataForRecommendedCells_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, AssociatedQosFlowList
void __app_ngap_set_AssociatedQosFlowList( SI_AMF_DT_AssociatedQosFlowList ** data)
{
	__si_amf_init_AssociatedQosFlowList( data);
	SI_AMF_DT_AssociatedQosFlowList * associatedQosFlowList = *data;
	
	SI_AMF_DT_AssociatedQosFlowItem * objItem = NULL;

	__app_ngap_set_AssociatedQosFlowItem( &objItem);
	__si_linked_list_add( (*data)->AssociatedQosFlowItem, (uint8_t *)objItem);
}


//-- SEQUENCE, AssociatedQosFlowItem
void __app_ngap_set_AssociatedQosFlowItem( SI_AMF_DT_AssociatedQosFlowItem ** data)
{
	__si_amf_init_AssociatedQosFlowItem( data);
	SI_AMF_DT_AssociatedQosFlowItem * associatedQosFlowItem = *data;
	
	associatedQosFlowItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	associatedQosFlowItem->selected_eqosFlowMappingIndication = 0;
}


//-- CONTAINER, AssociatedQosFlowItem-ExtIEs
void __app_ngap_set_AssociatedQosFlowItem_ExtIEs( SI_AMF_DT_AssociatedQosFlowItem_ExtIEs ** data)
{
	__si_amf_init_AssociatedQosFlowItem_ExtIEs( data);
	SI_AMF_DT_AssociatedQosFlowItem_ExtIEs * associatedQosFlowItem_ExtIEs = *data;
	
}


//-- INTEGER, AveragingWindow
void __app_ngap_set_AveragingWindow( SI_AMF_DT_AveragingWindow ** data)
{
	SI_AMF_DT_AveragingWindow * averagingWindow = *data;
	
	//MIN = 0, MAX = 4095
	averagingWindow->data = __si_core_getU64RANDRange( 0, 4095);
}


//-- INTEGER, BitRate
void __app_ngap_set_BitRate( SI_AMF_DT_BitRate ** data)
{
	SI_AMF_DT_BitRate * bitRate = *data;
	
	//MIN = 0, MAX = 4000000000000
	bitRate->data = __si_core_getU64RANDRange( 0, 4000000000000);
}


//-- CHOICE, BroadcastCancelledAreaList
void __app_ngap_set_BroadcastCancelledAreaList( SI_AMF_DT_BroadcastCancelledAreaList ** data)
{
	__si_amf_init_BroadcastCancelledAreaList( data);
	SI_AMF_DT_BroadcastCancelledAreaList * broadcastCancelledAreaList = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_CellIDCancelledEUTRA( &(*data)->u.cellIDCancelledEUTRA);

}


//-- CONTAINER, BroadcastCancelledAreaList-ExtIEs
void __app_ngap_set_BroadcastCancelledAreaList_ExtIEs( SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs ** data)
{
	__si_amf_init_BroadcastCancelledAreaList_ExtIEs( data);
	SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs * broadcastCancelledAreaList_ExtIEs = *data;
	
}


//-- CHOICE, BroadcastCompletedAreaList
void __app_ngap_set_BroadcastCompletedAreaList( SI_AMF_DT_BroadcastCompletedAreaList ** data)
{
	__si_amf_init_BroadcastCompletedAreaList( data);
	SI_AMF_DT_BroadcastCompletedAreaList * broadcastCompletedAreaList = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_CellIDBroadcastEUTRA( &(*data)->u.cellIDBroadcastEUTRA);

}


//-- CONTAINER, BroadcastCompletedAreaList-ExtIEs
void __app_ngap_set_BroadcastCompletedAreaList_ExtIEs( SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs ** data)
{
	__si_amf_init_BroadcastCompletedAreaList_ExtIEs( data);
	SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs * broadcastCompletedAreaList_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, BroadcastPLMNList
void __app_ngap_set_BroadcastPLMNList( SI_AMF_DT_BroadcastPLMNList ** data)
{
	__si_amf_init_BroadcastPLMNList( data);
	SI_AMF_DT_BroadcastPLMNList * broadcastPLMNList = *data;
	
	SI_AMF_DT_BroadcastPLMNItem * objItem = NULL;

	__app_ngap_set_BroadcastPLMNItem( &objItem);
	__si_linked_list_add( (*data)->BroadcastPLMNItem, (uint8_t *)objItem);
}


//-- SEQUENCE, BroadcastPLMNItem
void __app_ngap_set_BroadcastPLMNItem( SI_AMF_DT_BroadcastPLMNItem ** data)
{
	__si_amf_init_BroadcastPLMNItem( data);
	SI_AMF_DT_BroadcastPLMNItem * broadcastPLMNItem = *data;
	
	__app_ngap_set_PLMNIdentity( &broadcastPLMNItem->pLMNIdentity);

	__app_ngap_set_SliceSupportList( &broadcastPLMNItem->tAISliceSupportList);
}


//-- CONTAINER, BroadcastPLMNItem-ExtIEs
void __app_ngap_set_BroadcastPLMNItem_ExtIEs( SI_AMF_DT_BroadcastPLMNItem_ExtIEs ** data)
{
	__si_amf_init_BroadcastPLMNItem_ExtIEs( data);
	SI_AMF_DT_BroadcastPLMNItem_ExtIEs * broadcastPLMNItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CancelledCellsInEAI-EUTRA
void __app_ngap_set_CancelledCellsInEAI_EUTRA( SI_AMF_DT_CancelledCellsInEAI_EUTRA ** data)
{
	__si_amf_init_CancelledCellsInEAI_EUTRA( data);
	SI_AMF_DT_CancelledCellsInEAI_EUTRA * cancelledCellsInEAI_EUTRA = *data;
	
	SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item * objItem = NULL;

	__app_ngap_set_CancelledCellsInEAI_EUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->CancelledCellsInEAI_EUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CancelledCellsInEAI-EUTRA-Item
void __app_ngap_set_CancelledCellsInEAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item ** data)
{
	__si_amf_init_CancelledCellsInEAI_EUTRA_Item( data);
	SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item * cancelledCellsInEAI_EUTRA_Item = *data;
	
	__app_ngap_set_EUTRA_CGI( &cancelledCellsInEAI_EUTRA_Item->eUTRA_CGI);

	cancelledCellsInEAI_EUTRA_Item->numberOfBroadcasts = __si_core_getU64RANDRange( 0, 65535);
}


//-- CONTAINER, CancelledCellsInEAI-EUTRA-Item-ExtIEs
void __app_ngap_set_CancelledCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_CancelledCellsInEAI_EUTRA_Item_ExtIEs( data);
	SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs * cancelledCellsInEAI_EUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CancelledCellsInEAI-NR
void __app_ngap_set_CancelledCellsInEAI_NR( SI_AMF_DT_CancelledCellsInEAI_NR ** data)
{
	__si_amf_init_CancelledCellsInEAI_NR( data);
	SI_AMF_DT_CancelledCellsInEAI_NR * cancelledCellsInEAI_NR = *data;
	
	SI_AMF_DT_CancelledCellsInEAI_NR_Item * objItem = NULL;

	__app_ngap_set_CancelledCellsInEAI_NR_Item( &objItem);
	__si_linked_list_add( (*data)->CancelledCellsInEAI_NR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CancelledCellsInEAI-NR-Item
void __app_ngap_set_CancelledCellsInEAI_NR_Item( SI_AMF_DT_CancelledCellsInEAI_NR_Item ** data)
{
	__si_amf_init_CancelledCellsInEAI_NR_Item( data);
	SI_AMF_DT_CancelledCellsInEAI_NR_Item * cancelledCellsInEAI_NR_Item = *data;
	
	__app_ngap_set_NR_CGI( &cancelledCellsInEAI_NR_Item->nR_CGI);

	cancelledCellsInEAI_NR_Item->numberOfBroadcasts = __si_core_getU64RANDRange( 0, 65535);
}


//-- CONTAINER, CancelledCellsInEAI-NR-Item-ExtIEs
void __app_ngap_set_CancelledCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs ** data)
{
	__si_amf_init_CancelledCellsInEAI_NR_Item_ExtIEs( data);
	SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs * cancelledCellsInEAI_NR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CancelledCellsInTAI-EUTRA
void __app_ngap_set_CancelledCellsInTAI_EUTRA( SI_AMF_DT_CancelledCellsInTAI_EUTRA ** data)
{
	__si_amf_init_CancelledCellsInTAI_EUTRA( data);
	SI_AMF_DT_CancelledCellsInTAI_EUTRA * cancelledCellsInTAI_EUTRA = *data;
	
	SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item * objItem = NULL;

	__app_ngap_set_CancelledCellsInTAI_EUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->CancelledCellsInTAI_EUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CancelledCellsInTAI-EUTRA-Item
void __app_ngap_set_CancelledCellsInTAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item ** data)
{
	__si_amf_init_CancelledCellsInTAI_EUTRA_Item( data);
	SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item * cancelledCellsInTAI_EUTRA_Item = *data;
	
	__app_ngap_set_EUTRA_CGI( &cancelledCellsInTAI_EUTRA_Item->eUTRA_CGI);

	cancelledCellsInTAI_EUTRA_Item->numberOfBroadcasts = __si_core_getU64RANDRange( 0, 65535);
}


//-- CONTAINER, CancelledCellsInTAI-EUTRA-Item-ExtIEs
void __app_ngap_set_CancelledCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_CancelledCellsInTAI_EUTRA_Item_ExtIEs( data);
	SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs * cancelledCellsInTAI_EUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CancelledCellsInTAI-NR
void __app_ngap_set_CancelledCellsInTAI_NR( SI_AMF_DT_CancelledCellsInTAI_NR ** data)
{
	__si_amf_init_CancelledCellsInTAI_NR( data);
	SI_AMF_DT_CancelledCellsInTAI_NR * cancelledCellsInTAI_NR = *data;
	
	SI_AMF_DT_CancelledCellsInTAI_NR_Item * objItem = NULL;

	__app_ngap_set_CancelledCellsInTAI_NR_Item( &objItem);
	__si_linked_list_add( (*data)->CancelledCellsInTAI_NR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CancelledCellsInTAI-NR-Item
void __app_ngap_set_CancelledCellsInTAI_NR_Item( SI_AMF_DT_CancelledCellsInTAI_NR_Item ** data)
{
	__si_amf_init_CancelledCellsInTAI_NR_Item( data);
	SI_AMF_DT_CancelledCellsInTAI_NR_Item * cancelledCellsInTAI_NR_Item = *data;
	
	__app_ngap_set_NR_CGI( &cancelledCellsInTAI_NR_Item->nR_CGI);

	cancelledCellsInTAI_NR_Item->numberOfBroadcasts = __si_core_getU64RANDRange( 0, 65535);
}


//-- CONTAINER, CancelledCellsInTAI-NR-Item-ExtIEs
void __app_ngap_set_CancelledCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs ** data)
{
	__si_amf_init_CancelledCellsInTAI_NR_Item_ExtIEs( data);
	SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs * cancelledCellsInTAI_NR_Item_ExtIEs = *data;
	
}


//-- CHOICE, Cause
void __app_ngap_set_Cause( SI_AMF_DT_Cause ** data)
{
	__si_amf_init_Cause( data);
	SI_AMF_DT_Cause * cause = *data;
	
	(*data)->SelectedChoice = 1;

	//(*data)->u.radioNetwork = 0;
	(*data)->u.transport = 1;

}


//-- CONTAINER, Cause-ExtIEs
void __app_ngap_set_Cause_ExtIEs( SI_AMF_DT_Cause_ExtIEs ** data)
{
	__si_amf_init_Cause_ExtIEs( data);
	SI_AMF_DT_Cause_ExtIEs * cause_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CellIDBroadcastEUTRA
void __app_ngap_set_CellIDBroadcastEUTRA( SI_AMF_DT_CellIDBroadcastEUTRA ** data)
{
	__si_amf_init_CellIDBroadcastEUTRA( data);
	SI_AMF_DT_CellIDBroadcastEUTRA * cellIDBroadcastEUTRA = *data;
	
	SI_AMF_DT_CellIDBroadcastEUTRA_Item * objItem = NULL;

	__app_ngap_set_CellIDBroadcastEUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->CellIDBroadcastEUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CellIDBroadcastEUTRA-Item
void __app_ngap_set_CellIDBroadcastEUTRA_Item( SI_AMF_DT_CellIDBroadcastEUTRA_Item ** data)
{
	__si_amf_init_CellIDBroadcastEUTRA_Item( data);
	SI_AMF_DT_CellIDBroadcastEUTRA_Item * cellIDBroadcastEUTRA_Item = *data;
	
	__app_ngap_set_EUTRA_CGI( &cellIDBroadcastEUTRA_Item->eUTRA_CGI);
}


//-- CONTAINER, CellIDBroadcastEUTRA-Item-ExtIEs
void __app_ngap_set_CellIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_CellIDBroadcastEUTRA_Item_ExtIEs( data);
	SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs * cellIDBroadcastEUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CellIDBroadcastNR
void __app_ngap_set_CellIDBroadcastNR( SI_AMF_DT_CellIDBroadcastNR ** data)
{
	__si_amf_init_CellIDBroadcastNR( data);
	SI_AMF_DT_CellIDBroadcastNR * cellIDBroadcastNR = *data;
	
	SI_AMF_DT_CellIDBroadcastNR_Item * objItem = NULL;

	__app_ngap_set_CellIDBroadcastNR_Item( &objItem);
	__si_linked_list_add( (*data)->CellIDBroadcastNR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CellIDBroadcastNR-Item
void __app_ngap_set_CellIDBroadcastNR_Item( SI_AMF_DT_CellIDBroadcastNR_Item ** data)
{
	__si_amf_init_CellIDBroadcastNR_Item( data);
	SI_AMF_DT_CellIDBroadcastNR_Item * cellIDBroadcastNR_Item = *data;
	
	__app_ngap_set_NR_CGI( &cellIDBroadcastNR_Item->nR_CGI);
}


//-- CONTAINER, CellIDBroadcastNR-Item-ExtIEs
void __app_ngap_set_CellIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs ** data)
{
	__si_amf_init_CellIDBroadcastNR_Item_ExtIEs( data);
	SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs * cellIDBroadcastNR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CellIDCancelledEUTRA
void __app_ngap_set_CellIDCancelledEUTRA( SI_AMF_DT_CellIDCancelledEUTRA ** data)
{
	__si_amf_init_CellIDCancelledEUTRA( data);
	SI_AMF_DT_CellIDCancelledEUTRA * cellIDCancelledEUTRA = *data;
	
	SI_AMF_DT_CellIDCancelledEUTRA_Item * objItem = NULL;

	__app_ngap_set_CellIDCancelledEUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->CellIDCancelledEUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CellIDCancelledEUTRA-Item
void __app_ngap_set_CellIDCancelledEUTRA_Item( SI_AMF_DT_CellIDCancelledEUTRA_Item ** data)
{
	__si_amf_init_CellIDCancelledEUTRA_Item( data);
	SI_AMF_DT_CellIDCancelledEUTRA_Item * cellIDCancelledEUTRA_Item = *data;
	
	__app_ngap_set_EUTRA_CGI( &cellIDCancelledEUTRA_Item->eUTRA_CGI);

	cellIDCancelledEUTRA_Item->numberOfBroadcasts = __si_core_getU64RANDRange( 0, 65535);
}


//-- CONTAINER, CellIDCancelledEUTRA-Item-ExtIEs
void __app_ngap_set_CellIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_CellIDCancelledEUTRA_Item_ExtIEs( data);
	SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs * cellIDCancelledEUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CellIDCancelledNR
void __app_ngap_set_CellIDCancelledNR( SI_AMF_DT_CellIDCancelledNR ** data)
{
	__si_amf_init_CellIDCancelledNR( data);
	SI_AMF_DT_CellIDCancelledNR * cellIDCancelledNR = *data;
	
	SI_AMF_DT_CellIDCancelledNR_Item * objItem = NULL;

	__app_ngap_set_CellIDCancelledNR_Item( &objItem);
	__si_linked_list_add( (*data)->CellIDCancelledNR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CellIDCancelledNR-Item
void __app_ngap_set_CellIDCancelledNR_Item( SI_AMF_DT_CellIDCancelledNR_Item ** data)
{
	__si_amf_init_CellIDCancelledNR_Item( data);
	SI_AMF_DT_CellIDCancelledNR_Item * cellIDCancelledNR_Item = *data;
	
	__app_ngap_set_NR_CGI( &cellIDCancelledNR_Item->nR_CGI);

	cellIDCancelledNR_Item->numberOfBroadcasts = __si_core_getU64RANDRange( 0, 65535);
}


//-- CONTAINER, CellIDCancelledNR-Item-ExtIEs
void __app_ngap_set_CellIDCancelledNR_Item_ExtIEs( SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs ** data)
{
	__si_amf_init_CellIDCancelledNR_Item_ExtIEs( data);
	SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs * cellIDCancelledNR_Item_ExtIEs = *data;
	
}


//-- CHOICE, CellIDListForRestart
void __app_ngap_set_CellIDListForRestart( SI_AMF_DT_CellIDListForRestart ** data)
{
	__si_amf_init_CellIDListForRestart( data);
	SI_AMF_DT_CellIDListForRestart * cellIDListForRestart = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_EUTRA_CGIList( &(*data)->u.eUTRA_CGIListforRestart);

}


//-- CONTAINER, CellIDListForRestart-ExtIEs
void __app_ngap_set_CellIDListForRestart_ExtIEs( SI_AMF_DT_CellIDListForRestart_ExtIEs ** data)
{
	__si_amf_init_CellIDListForRestart_ExtIEs( data);
	SI_AMF_DT_CellIDListForRestart_ExtIEs * cellIDListForRestart_ExtIEs = *data;
	
}


//-- SEQUENCE, CellType
void __app_ngap_set_CellType( SI_AMF_DT_CellType ** data)
{
	__si_amf_init_CellType( data);
	SI_AMF_DT_CellType * cellType = *data;
	
	cellType->selected_ecellSize = 0;
}


//-- CONTAINER, CellType-ExtIEs
void __app_ngap_set_CellType_ExtIEs( SI_AMF_DT_CellType_ExtIEs ** data)
{
	__si_amf_init_CellType_ExtIEs( data);
	SI_AMF_DT_CellType_ExtIEs * cellType_ExtIEs = *data;
	
}


//-- SEQUENCE, CNAssistedRANTuning
void __app_ngap_set_CNAssistedRANTuning( SI_AMF_DT_CNAssistedRANTuning ** data)
{
	__si_amf_init_CNAssistedRANTuning( data);
	SI_AMF_DT_CNAssistedRANTuning * cNAssistedRANTuning = *data;
	
	__app_ngap_set_ExpectedUEBehaviour( &cNAssistedRANTuning->expectedUEBehaviour);
	cNAssistedRANTuning->isPresent_expectedUEBehaviour = 1;
}


//-- CONTAINER, CNAssistedRANTuning-ExtIEs
void __app_ngap_set_CNAssistedRANTuning_ExtIEs( SI_AMF_DT_CNAssistedRANTuning_ExtIEs ** data)
{
	__si_amf_init_CNAssistedRANTuning_ExtIEs( data);
	SI_AMF_DT_CNAssistedRANTuning_ExtIEs * cNAssistedRANTuning_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CNTypeRestrictionsForEquivalent
void __app_ngap_set_CNTypeRestrictionsForEquivalent( SI_AMF_DT_CNTypeRestrictionsForEquivalent ** data)
{
	__si_amf_init_CNTypeRestrictionsForEquivalent( data);
	SI_AMF_DT_CNTypeRestrictionsForEquivalent * cNTypeRestrictionsForEquivalent = *data;
	
	SI_AMF_DT_CNTypeRestrictionsForEquivalentItem * objItem = NULL;

	__app_ngap_set_CNTypeRestrictionsForEquivalentItem( &objItem);
	__si_linked_list_add( (*data)->CNTypeRestrictionsForEquivalentItem, (uint8_t *)objItem);
}


//-- SEQUENCE, CNTypeRestrictionsForEquivalentItem
void __app_ngap_set_CNTypeRestrictionsForEquivalentItem( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem ** data)
{
	__si_amf_init_CNTypeRestrictionsForEquivalentItem( data);
	SI_AMF_DT_CNTypeRestrictionsForEquivalentItem * cNTypeRestrictionsForEquivalentItem = *data;
	
	__app_ngap_set_PLMNIdentity( &cNTypeRestrictionsForEquivalentItem->plmnIdentity);

	cNTypeRestrictionsForEquivalentItem->selected_ecn_Type = 0;
}


//-- CONTAINER, CNTypeRestrictionsForEquivalentItem-ExtIEs
void __app_ngap_set_CNTypeRestrictionsForEquivalentItem_ExtIEs( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs ** data)
{
	__si_amf_init_CNTypeRestrictionsForEquivalentItem_ExtIEs( data);
	SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs * cNTypeRestrictionsForEquivalentItem_ExtIEs = *data;
	
}


//-- OCTETSTRING, CommonNetworkInstance
void __app_ngap_set_CommonNetworkInstance( SI_AMF_DT_CommonNetworkInstance ** data)
{
	__si_amf_init_CommonNetworkInstance( data);
	SI_AMF_DT_CommonNetworkInstance * commonNetworkInstance = *data;
	
	commonNetworkInstance->data = (unsigned char *) __si_allocM(0);
	commonNetworkInstance->length = 0;
	__si_core_fill_dummy_data( commonNetworkInstance->data, commonNetworkInstance->length);
}


//-- SEQUENCE_OF, CompletedCellsInEAI-EUTRA
void __app_ngap_set_CompletedCellsInEAI_EUTRA( SI_AMF_DT_CompletedCellsInEAI_EUTRA ** data)
{
	__si_amf_init_CompletedCellsInEAI_EUTRA( data);
	SI_AMF_DT_CompletedCellsInEAI_EUTRA * completedCellsInEAI_EUTRA = *data;
	
	SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item * objItem = NULL;

	__app_ngap_set_CompletedCellsInEAI_EUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->CompletedCellsInEAI_EUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CompletedCellsInEAI-EUTRA-Item
void __app_ngap_set_CompletedCellsInEAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item ** data)
{
	__si_amf_init_CompletedCellsInEAI_EUTRA_Item( data);
	SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item * completedCellsInEAI_EUTRA_Item = *data;
	
	__app_ngap_set_EUTRA_CGI( &completedCellsInEAI_EUTRA_Item->eUTRA_CGI);
}


//-- CONTAINER, CompletedCellsInEAI-EUTRA-Item-ExtIEs
void __app_ngap_set_CompletedCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_CompletedCellsInEAI_EUTRA_Item_ExtIEs( data);
	SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs * completedCellsInEAI_EUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CompletedCellsInEAI-NR
void __app_ngap_set_CompletedCellsInEAI_NR( SI_AMF_DT_CompletedCellsInEAI_NR ** data)
{
	__si_amf_init_CompletedCellsInEAI_NR( data);
	SI_AMF_DT_CompletedCellsInEAI_NR * completedCellsInEAI_NR = *data;
	
	SI_AMF_DT_CompletedCellsInEAI_NR_Item * objItem = NULL;

	__app_ngap_set_CompletedCellsInEAI_NR_Item( &objItem);
	__si_linked_list_add( (*data)->CompletedCellsInEAI_NR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CompletedCellsInEAI-NR-Item
void __app_ngap_set_CompletedCellsInEAI_NR_Item( SI_AMF_DT_CompletedCellsInEAI_NR_Item ** data)
{
	__si_amf_init_CompletedCellsInEAI_NR_Item( data);
	SI_AMF_DT_CompletedCellsInEAI_NR_Item * completedCellsInEAI_NR_Item = *data;
	
	__app_ngap_set_NR_CGI( &completedCellsInEAI_NR_Item->nR_CGI);
}


//-- CONTAINER, CompletedCellsInEAI-NR-Item-ExtIEs
void __app_ngap_set_CompletedCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs ** data)
{
	__si_amf_init_CompletedCellsInEAI_NR_Item_ExtIEs( data);
	SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs * completedCellsInEAI_NR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CompletedCellsInTAI-EUTRA
void __app_ngap_set_CompletedCellsInTAI_EUTRA( SI_AMF_DT_CompletedCellsInTAI_EUTRA ** data)
{
	__si_amf_init_CompletedCellsInTAI_EUTRA( data);
	SI_AMF_DT_CompletedCellsInTAI_EUTRA * completedCellsInTAI_EUTRA = *data;
	
	SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item * objItem = NULL;

	__app_ngap_set_CompletedCellsInTAI_EUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->CompletedCellsInTAI_EUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CompletedCellsInTAI-EUTRA-Item
void __app_ngap_set_CompletedCellsInTAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item ** data)
{
	__si_amf_init_CompletedCellsInTAI_EUTRA_Item( data);
	SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item * completedCellsInTAI_EUTRA_Item = *data;
	
	__app_ngap_set_EUTRA_CGI( &completedCellsInTAI_EUTRA_Item->eUTRA_CGI);
}


//-- CONTAINER, CompletedCellsInTAI-EUTRA-Item-ExtIEs
void __app_ngap_set_CompletedCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_CompletedCellsInTAI_EUTRA_Item_ExtIEs( data);
	SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs * completedCellsInTAI_EUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CompletedCellsInTAI-NR
void __app_ngap_set_CompletedCellsInTAI_NR( SI_AMF_DT_CompletedCellsInTAI_NR ** data)
{
	__si_amf_init_CompletedCellsInTAI_NR( data);
	SI_AMF_DT_CompletedCellsInTAI_NR * completedCellsInTAI_NR = *data;
	
	SI_AMF_DT_CompletedCellsInTAI_NR_Item * objItem = NULL;

	__app_ngap_set_CompletedCellsInTAI_NR_Item( &objItem);
	__si_linked_list_add( (*data)->CompletedCellsInTAI_NR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, CompletedCellsInTAI-NR-Item
void __app_ngap_set_CompletedCellsInTAI_NR_Item( SI_AMF_DT_CompletedCellsInTAI_NR_Item ** data)
{
	__si_amf_init_CompletedCellsInTAI_NR_Item( data);
	SI_AMF_DT_CompletedCellsInTAI_NR_Item * completedCellsInTAI_NR_Item = *data;
	
	__app_ngap_set_NR_CGI( &completedCellsInTAI_NR_Item->nR_CGI);
}


//-- CONTAINER, CompletedCellsInTAI-NR-Item-ExtIEs
void __app_ngap_set_CompletedCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs ** data)
{
	__si_amf_init_CompletedCellsInTAI_NR_Item_ExtIEs( data);
	SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs * completedCellsInTAI_NR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE, CoreNetworkAssistanceInformationForInactive
void __app_ngap_set_CoreNetworkAssistanceInformationForInactive( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive ** data)
{
	__si_amf_init_CoreNetworkAssistanceInformationForInactive( data);
	SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * coreNetworkAssistanceInformationForInactive = *data;
	
	__app_ngap_set_UEIdentityIndexValue( &coreNetworkAssistanceInformationForInactive->uEIdentityIndexValue);

	coreNetworkAssistanceInformationForInactive->selected_euESpecificDRX = 1;
	__app_ngap_set_PeriodicRegistrationUpdateTimer( &coreNetworkAssistanceInformationForInactive->periodicRegistrationUpdateTimer);

	coreNetworkAssistanceInformationForInactive->selected_emICOModeIndication = 1;
	__app_ngap_set_TAIListForInactive( &coreNetworkAssistanceInformationForInactive->tAIListForInactive);

	__app_ngap_set_ExpectedUEBehaviour( &coreNetworkAssistanceInformationForInactive->expectedUEBehaviour);
	coreNetworkAssistanceInformationForInactive->isPresent_expectedUEBehaviour = 1;
}


//-- CONTAINER, CoreNetworkAssistanceInformationForInactive-ExtIEs
void __app_ngap_set_CoreNetworkAssistanceInformationForInactive_ExtIEs( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs ** data)
{
	__si_amf_init_CoreNetworkAssistanceInformationForInactive_ExtIEs( data);
	SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs * coreNetworkAssistanceInformationForInactive_ExtIEs = *data;
	
}


//-- INTEGER, COUNTValueForPDCP-SN12INT
void __app_ngap_set_COUNTValueForPDCP_SN12INT( SI_AMF_DT_COUNTValueForPDCP_SN12INT ** data)
{
	SI_AMF_DT_COUNTValueForPDCP_SN12INT * cOUNTValueForPDCP_SN12INT = *data;
	
	//MIN = 0, MAX = 4095
	cOUNTValueForPDCP_SN12INT->data = __si_core_getU64RANDRange( 0, 4095);
}


//-- INTEGER, COUNTValueForPDCP-SN12INT2
void __app_ngap_set_COUNTValueForPDCP_SN12INT2( SI_AMF_DT_COUNTValueForPDCP_SN12INT2 ** data)
{
	SI_AMF_DT_COUNTValueForPDCP_SN12INT2 * cOUNTValueForPDCP_SN12INT2 = *data;
	
	//MIN = 0, MAX = 1048575
	cOUNTValueForPDCP_SN12INT2->data = __si_core_getU64RANDRange( 0, 1048575);
}


//-- SEQUENCE, COUNTValueForPDCP-SN12
void __app_ngap_set_COUNTValueForPDCP_SN12( SI_AMF_DT_COUNTValueForPDCP_SN12 ** data)
{
	__si_amf_init_COUNTValueForPDCP_SN12( data);
	SI_AMF_DT_COUNTValueForPDCP_SN12 * cOUNTValueForPDCP_SN12 = *data;
	
	cOUNTValueForPDCP_SN12->pDCP_SN12 = 4095; 			//__si_core_getU64RANDRange( 0, 4095);
	cOUNTValueForPDCP_SN12->hFN_PDCP_SN12 = 1048575; 	//__si_core_getU64RANDRange( 0, 1048575);
}


//-- CONTAINER, COUNTValueForPDCP-SN12-ExtIEs
void __app_ngap_set_COUNTValueForPDCP_SN12_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs ** data)
{
	__si_amf_init_COUNTValueForPDCP_SN12_ExtIEs( data);
	SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs * cOUNTValueForPDCP_SN12_ExtIEs = *data;
	
}


//-- INTEGER, COUNTValueForPDCP-SN18INT
void __app_ngap_set_COUNTValueForPDCP_SN18INT( SI_AMF_DT_COUNTValueForPDCP_SN18INT ** data)
{
	SI_AMF_DT_COUNTValueForPDCP_SN18INT * cOUNTValueForPDCP_SN18INT = *data;
	
	//MIN = 0, MAX = 262143
	cOUNTValueForPDCP_SN18INT->data = __si_core_getU64RANDRange( 0, 262143);
}


//-- INTEGER, COUNTValueForPDCP-SN18INT2
void __app_ngap_set_COUNTValueForPDCP_SN18INT2( SI_AMF_DT_COUNTValueForPDCP_SN18INT2 ** data)
{
	SI_AMF_DT_COUNTValueForPDCP_SN18INT2 * cOUNTValueForPDCP_SN18INT2 = *data;
	
	//MIN = 0, MAX = 16383
	cOUNTValueForPDCP_SN18INT2->data = __si_core_getU64RANDRange( 0, 16383);
}


//-- SEQUENCE, COUNTValueForPDCP-SN18
void __app_ngap_set_COUNTValueForPDCP_SN18( SI_AMF_DT_COUNTValueForPDCP_SN18 ** data)
{
	__si_amf_init_COUNTValueForPDCP_SN18( data);
	SI_AMF_DT_COUNTValueForPDCP_SN18 * cOUNTValueForPDCP_SN18 = *data;
	
	cOUNTValueForPDCP_SN18->pDCP_SN18 = __si_core_getU64RANDRange( 0, 262143);
	cOUNTValueForPDCP_SN18->hFN_PDCP_SN18 = __si_core_getU64RANDRange( 0, 16383);
}


//-- CONTAINER, COUNTValueForPDCP-SN18-ExtIEs
void __app_ngap_set_COUNTValueForPDCP_SN18_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs ** data)
{
	__si_amf_init_COUNTValueForPDCP_SN18_ExtIEs( data);
	SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs * cOUNTValueForPDCP_SN18_ExtIEs = *data;
	
}


//-- CHOICE, CPTransportLayerInformation
void __app_ngap_set_CPTransportLayerInformation( SI_AMF_DT_CPTransportLayerInformation ** data)
{
	__si_amf_init_CPTransportLayerInformation( data);
	SI_AMF_DT_CPTransportLayerInformation * cPTransportLayerInformation = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_TransportLayerAddress( &(*data)->u.endpointIPAddress);

}


//-- CONTAINER, CPTransportLayerInformation-ExtIEs
void __app_ngap_set_CPTransportLayerInformation_ExtIEs( SI_AMF_DT_CPTransportLayerInformation_ExtIEs ** data)
{
	__si_amf_init_CPTransportLayerInformation_ExtIEs( data);
	SI_AMF_DT_CPTransportLayerInformation_ExtIEs * cPTransportLayerInformation_ExtIEs = *data;
	
}


//-- INTEGER, CriticalityDiagnosticsCriticality
void __app_ngap_set_CriticalityDiagnosticsCriticality( SI_AMF_DT_CriticalityDiagnosticsCriticality ** data)
{
	SI_AMF_DT_CriticalityDiagnosticsCriticality * criticalityDiagnosticsCriticality = *data;
	
	//MIN = 0, MAX = 1048575
	criticalityDiagnosticsCriticality->data = __si_core_getU64RANDRange( 0, 1048575);
}


//-- INTEGER, CriticalityDiagnosticsProcedureCode
void __app_ngap_set_CriticalityDiagnosticsProcedureCode( SI_AMF_DT_CriticalityDiagnosticsProcedureCode ** data)
{
	SI_AMF_DT_CriticalityDiagnosticsProcedureCode * criticalityDiagnosticsProcedureCode = *data;
	
	//MIN = 0, MAX = 1048575
	criticalityDiagnosticsProcedureCode->data = __si_core_getU64RANDRange( 0, 1048575);
}


//-- INTEGER, CriticalityDiagnosticsTriggeringMessage
void __app_ngap_set_CriticalityDiagnosticsTriggeringMessage( SI_AMF_DT_CriticalityDiagnosticsTriggeringMessage ** data)
{
	SI_AMF_DT_CriticalityDiagnosticsTriggeringMessage * criticalityDiagnosticsTriggeringMessage = *data;
	
	//MIN = 0, MAX = 1048575
	criticalityDiagnosticsTriggeringMessage->data = __si_core_getU64RANDRange( 0, 1048575);
}


//-- SEQUENCE, CriticalityDiagnostics
void __app_ngap_set_CriticalityDiagnostics( SI_AMF_DT_CriticalityDiagnostics ** data)
{
	__si_amf_init_CriticalityDiagnostics( data);
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics = *data;
	
	criticalityDiagnostics->procedureCode = __si_core_getU64RANDRange( 0, 1048575);
	criticalityDiagnostics->triggeringMessage = __si_core_getU64RANDRange( 0, 1048575);
	criticalityDiagnostics->procedureCriticality = __si_core_getU64RANDRange( 0, 1048575);
	__app_ngap_set_CriticalityDiagnostics_IE_List( &criticalityDiagnostics->iEsCriticalityDiagnostics);
	criticalityDiagnostics->isPresent_iEsCriticalityDiagnostics = 1;
}


//-- CONTAINER, CriticalityDiagnostics-ExtIEs
void __app_ngap_set_CriticalityDiagnostics_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_ExtIEs ** data)
{
	__si_amf_init_CriticalityDiagnostics_ExtIEs( data);
	SI_AMF_DT_CriticalityDiagnostics_ExtIEs * criticalityDiagnostics_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, CriticalityDiagnostics-IE-List
void __app_ngap_set_CriticalityDiagnostics_IE_List( SI_AMF_DT_CriticalityDiagnostics_IE_List ** data)
{
	__si_amf_init_CriticalityDiagnostics_IE_List( data);
	SI_AMF_DT_CriticalityDiagnostics_IE_List * criticalityDiagnostics_IE_List = *data;
	
	SI_AMF_DT_CriticalityDiagnostics_IE_Item * objItem = NULL;

	__app_ngap_set_CriticalityDiagnostics_IE_Item( &objItem);
	__si_linked_list_add( (*data)->CriticalityDiagnostics_IE_Item, (uint8_t *)objItem);
}


//-- INTEGER, CriticalityDiagnostics-IE-Item-ProtocolIE-ID
void __app_ngap_set_CriticalityDiagnostics_IE_Item_ProtocolIE_ID( SI_AMF_DT_CriticalityDiagnostics_IE_Item_ProtocolIE_ID ** data)
{
	SI_AMF_DT_CriticalityDiagnostics_IE_Item_ProtocolIE_ID * criticalityDiagnostics_IE_Item_ProtocolIE_ID = *data;
	
	//MIN = 0, MAX = 1048575
	criticalityDiagnostics_IE_Item_ProtocolIE_ID->data = __si_core_getU64RANDRange( 0, 1048575);
}


//-- INTEGER, CriticalityDiagnostics-IE-Item-Criticality
void __app_ngap_set_CriticalityDiagnostics_IE_Item_Criticality( SI_AMF_DT_CriticalityDiagnostics_IE_Item_Criticality ** data)
{
	SI_AMF_DT_CriticalityDiagnostics_IE_Item_Criticality * criticalityDiagnostics_IE_Item_Criticality = *data;
	
	//MIN = 0, MAX = 1048575
	criticalityDiagnostics_IE_Item_Criticality->data = __si_core_getU64RANDRange( 0, 1048575);
}


//-- SEQUENCE, CriticalityDiagnostics-IE-Item
void __app_ngap_set_CriticalityDiagnostics_IE_Item( SI_AMF_DT_CriticalityDiagnostics_IE_Item ** data)
{
	__si_amf_init_CriticalityDiagnostics_IE_Item( data);
	SI_AMF_DT_CriticalityDiagnostics_IE_Item * criticalityDiagnostics_IE_Item = *data;
	
	criticalityDiagnostics_IE_Item->iECriticality = __si_core_getU64RANDRange( 0, 1048575);
	criticalityDiagnostics_IE_Item->iE_ID = __si_core_getU64RANDRange( 0, 1048575);
	criticalityDiagnostics_IE_Item->selected_etypeOfError = 0;
}


//-- CONTAINER, CriticalityDiagnostics-IE-Item-ExtIEs
void __app_ngap_set_CriticalityDiagnostics_IE_Item_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs ** data)
{
	__si_amf_init_CriticalityDiagnostics_IE_Item_ExtIEs( data);
	SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs * criticalityDiagnostics_IE_Item_ExtIEs = *data;
	
}


//-- BITSTRING, DataCodingScheme
void __app_ngap_set_DataCodingScheme( SI_AMF_DT_DataCodingScheme ** data)
{
	__si_amf_init_DataCodingScheme( data);
	SI_AMF_DT_DataCodingScheme * dataCodingScheme = *data;
	
	//BITSIZE = 8  , BIT STRING(SIZE(8))
	dataCodingScheme->data = (unsigned char *) __si_allocM(2);
	dataCodingScheme->length = 2;
	dataCodingScheme->bitslen = 8;
	__si_core_fill_dummy_data( dataCodingScheme->data, dataCodingScheme->length);
}


//-- SEQUENCE_OF, DataForwardingResponseDRBList
void __app_ngap_set_DataForwardingResponseDRBList( SI_AMF_DT_DataForwardingResponseDRBList ** data)
{
	__si_amf_init_DataForwardingResponseDRBList( data);
	SI_AMF_DT_DataForwardingResponseDRBList * dataForwardingResponseDRBList = *data;
	
	SI_AMF_DT_DataForwardingResponseDRBItem * objItem = NULL;

	__app_ngap_set_DataForwardingResponseDRBItem( &objItem);
	__si_linked_list_add( (*data)->DataForwardingResponseDRBItem, (uint8_t *)objItem);
}


//-- SEQUENCE, DataForwardingResponseDRBItem
void __app_ngap_set_DataForwardingResponseDRBItem( SI_AMF_DT_DataForwardingResponseDRBItem ** data)
{
	__si_amf_init_DataForwardingResponseDRBItem( data);
	SI_AMF_DT_DataForwardingResponseDRBItem * dataForwardingResponseDRBItem = *data;
	
	dataForwardingResponseDRBItem->dRB_ID = __si_core_getU64RANDRange( 1, 32);
	__app_ngap_set_UPTransportLayerInformation( &dataForwardingResponseDRBItem->dLForwardingUP_TNLInformation);
	dataForwardingResponseDRBItem->isPresent_dLForwardingUP_TNLInformation = 1;

	__app_ngap_set_UPTransportLayerInformation( &dataForwardingResponseDRBItem->uLForwardingUP_TNLInformation);
	dataForwardingResponseDRBItem->isPresent_uLForwardingUP_TNLInformation = 1;
}


//-- CONTAINER, DataForwardingResponseDRBItem-ExtIEs
void __app_ngap_set_DataForwardingResponseDRBItem_ExtIEs( SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs ** data)
{
	__si_amf_init_DataForwardingResponseDRBItem_ExtIEs( data);
	SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs * dataForwardingResponseDRBItem_ExtIEs = *data;
	
}


//-- INTEGER, DRB-ID
void __app_ngap_set_DRB_ID( SI_AMF_DT_DRB_ID ** data)
{
	SI_AMF_DT_DRB_ID * dRB_ID = *data;
	
	//MIN = 1, MAX = 32
	dRB_ID->data = __si_core_getU64RANDRange( 1, 32);
}


//-- SEQUENCE_OF, DRBsSubjectToStatusTransferList
void __app_ngap_set_DRBsSubjectToStatusTransferList( SI_AMF_DT_DRBsSubjectToStatusTransferList ** data)
{
	__si_amf_init_DRBsSubjectToStatusTransferList( data);
	SI_AMF_DT_DRBsSubjectToStatusTransferList * dRBsSubjectToStatusTransferList = *data;
	
	SI_AMF_DT_DRBsSubjectToStatusTransferItem * objItem = NULL;

	__app_ngap_set_DRBsSubjectToStatusTransferItem( &objItem);
	__si_linked_list_add( (*data)->DRBsSubjectToStatusTransferItem, (uint8_t *)objItem);
}


//-- SEQUENCE, DRBsSubjectToStatusTransferItem
void __app_ngap_set_DRBsSubjectToStatusTransferItem( SI_AMF_DT_DRBsSubjectToStatusTransferItem ** data)
{
	__si_amf_init_DRBsSubjectToStatusTransferItem( data);
	SI_AMF_DT_DRBsSubjectToStatusTransferItem * dRBsSubjectToStatusTransferItem = *data;
	
	dRBsSubjectToStatusTransferItem->dRB_ID = __si_core_getU64RANDRange( 1, 32);
	__app_ngap_set_DRBStatusUL( &dRBsSubjectToStatusTransferItem->dRBStatusUL);

	__app_ngap_set_DRBStatusDL( &dRBsSubjectToStatusTransferItem->dRBStatusDL);
}


//-- CONTAINER, DRBsSubjectToStatusTransferItem-ExtIEs
void __app_ngap_set_DRBsSubjectToStatusTransferItem_ExtIEs( SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs ** data)
{
	__si_amf_init_DRBsSubjectToStatusTransferItem_ExtIEs( data);
	SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs * dRBsSubjectToStatusTransferItem_ExtIEs = *data;
	
}


//-- CHOICE, DRBStatusDL
void __app_ngap_set_DRBStatusDL( SI_AMF_DT_DRBStatusDL ** data)
{
	__si_amf_init_DRBStatusDL( data);
	SI_AMF_DT_DRBStatusDL * dRBStatusDL = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_DRBStatusDL12( &(*data)->u.dRBStatusDL12);

}


//-- CONTAINER, DRBStatusDL-ExtIEs
void __app_ngap_set_DRBStatusDL_ExtIEs( SI_AMF_DT_DRBStatusDL_ExtIEs ** data)
{
	__si_amf_init_DRBStatusDL_ExtIEs( data);
	SI_AMF_DT_DRBStatusDL_ExtIEs * dRBStatusDL_ExtIEs = *data;
	
}


//-- SEQUENCE, DRBStatusDL12
void __app_ngap_set_DRBStatusDL12( SI_AMF_DT_DRBStatusDL12 ** data)
{
	__si_amf_init_DRBStatusDL12( data);
	SI_AMF_DT_DRBStatusDL12 * dRBStatusDL12 = *data;
	
	__app_ngap_set_COUNTValueForPDCP_SN12( &dRBStatusDL12->dL_COUNTValue);
}


//-- CONTAINER, DRBStatusDL12-ExtIEs
void __app_ngap_set_DRBStatusDL12_ExtIEs( SI_AMF_DT_DRBStatusDL12_ExtIEs ** data)
{
	__si_amf_init_DRBStatusDL12_ExtIEs( data);
	SI_AMF_DT_DRBStatusDL12_ExtIEs * dRBStatusDL12_ExtIEs = *data;
	
}


//-- SEQUENCE, DRBStatusDL18
void __app_ngap_set_DRBStatusDL18( SI_AMF_DT_DRBStatusDL18 ** data)
{
	__si_amf_init_DRBStatusDL18( data);
	SI_AMF_DT_DRBStatusDL18 * dRBStatusDL18 = *data;
	
	__app_ngap_set_COUNTValueForPDCP_SN18( &dRBStatusDL18->dL_COUNTValue);
}


//-- CONTAINER, DRBStatusDL18-ExtIEs
void __app_ngap_set_DRBStatusDL18_ExtIEs( SI_AMF_DT_DRBStatusDL18_ExtIEs ** data)
{
	__si_amf_init_DRBStatusDL18_ExtIEs( data);
	SI_AMF_DT_DRBStatusDL18_ExtIEs * dRBStatusDL18_ExtIEs = *data;
	
}


//-- CHOICE, DRBStatusUL
void __app_ngap_set_DRBStatusUL( SI_AMF_DT_DRBStatusUL ** data)
{
	__si_amf_init_DRBStatusUL( data);
	SI_AMF_DT_DRBStatusUL * dRBStatusUL = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_DRBStatusUL12( &(*data)->u.dRBStatusUL12);

}


//-- CONTAINER, DRBStatusUL-ExtIEs
void __app_ngap_set_DRBStatusUL_ExtIEs( SI_AMF_DT_DRBStatusUL_ExtIEs ** data)
{
	__si_amf_init_DRBStatusUL_ExtIEs( data);
	SI_AMF_DT_DRBStatusUL_ExtIEs * dRBStatusUL_ExtIEs = *data;
	
}


//-- BITSTRING, DRBStatusUL12ReceiveStatusOfUL-PDCP-SDUs
void __app_ngap_set_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs ** data)
{
	__si_amf_init_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( data);
	SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs * dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs = *data;
	
	//BITSIZE = 2048  , BIT STRING(SIZE(1..2048))
	dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs->data = (unsigned char *) __si_allocM(257);
	dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs->length = 257;
	dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs->bitslen = 200;
	//__si_core_fill_dummy_data( dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs->data, dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs->length);
	memset( dRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs->data, 0, 257);
}


//-- SEQUENCE, DRBStatusUL12
void __app_ngap_set_DRBStatusUL12( SI_AMF_DT_DRBStatusUL12 ** data)
{
	__si_amf_init_DRBStatusUL12( data);
	SI_AMF_DT_DRBStatusUL12 * dRBStatusUL12 = *data;
	
	__app_ngap_set_COUNTValueForPDCP_SN12( &dRBStatusUL12->uL_COUNTValue);

	__app_ngap_set_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( &dRBStatusUL12->receiveStatusOfUL_PDCP_SDUs);
	dRBStatusUL12->isPresent_receiveStatusOfUL_PDCP_SDUs = 1;
}


//-- CONTAINER, DRBStatusUL12-ExtIEs
void __app_ngap_set_DRBStatusUL12_ExtIEs( SI_AMF_DT_DRBStatusUL12_ExtIEs ** data)
{
	__si_amf_init_DRBStatusUL12_ExtIEs( data);
	SI_AMF_DT_DRBStatusUL12_ExtIEs * dRBStatusUL12_ExtIEs = *data;
	
}


//-- BITSTRING, DRBStatusUL18ReceiveStatusOfUL-PDCP-SDUs
void __app_ngap_set_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs ** data)
{
	__si_amf_init_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( data);
	SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs * dRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs = *data;
	
	//BITSIZE = 131072  , BIT STRING(SIZE(1..131072))
	dRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs->data = (unsigned char *) __si_allocM(16385);
	dRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs->length = 16385;
	dRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs->bitslen = 131072;
	__si_core_fill_dummy_data( dRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs->data, dRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs->length);
}


//-- SEQUENCE, DRBStatusUL18
void __app_ngap_set_DRBStatusUL18( SI_AMF_DT_DRBStatusUL18 ** data)
{
	__si_amf_init_DRBStatusUL18( data);
	SI_AMF_DT_DRBStatusUL18 * dRBStatusUL18 = *data;
	
	__app_ngap_set_COUNTValueForPDCP_SN18( &dRBStatusUL18->uL_COUNTValue);

	__app_ngap_set_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( &dRBStatusUL18->receiveStatusOfUL_PDCP_SDUs);
	dRBStatusUL18->isPresent_receiveStatusOfUL_PDCP_SDUs = 1;
}


//-- CONTAINER, DRBStatusUL18-ExtIEs
void __app_ngap_set_DRBStatusUL18_ExtIEs( SI_AMF_DT_DRBStatusUL18_ExtIEs ** data)
{
	__si_amf_init_DRBStatusUL18_ExtIEs( data);
	SI_AMF_DT_DRBStatusUL18_ExtIEs * dRBStatusUL18_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, DRBsToQosFlowsMappingList
void __app_ngap_set_DRBsToQosFlowsMappingList( SI_AMF_DT_DRBsToQosFlowsMappingList ** data)
{
	__si_amf_init_DRBsToQosFlowsMappingList( data);
	SI_AMF_DT_DRBsToQosFlowsMappingList * dRBsToQosFlowsMappingList = *data;
	
	SI_AMF_DT_DRBsToQosFlowsMappingItem * objItem = NULL;

	__app_ngap_set_DRBsToQosFlowsMappingItem( &objItem);
	__si_linked_list_add( (*data)->DRBsToQosFlowsMappingItem, (uint8_t *)objItem);
}


//-- SEQUENCE, DRBsToQosFlowsMappingItem
void __app_ngap_set_DRBsToQosFlowsMappingItem( SI_AMF_DT_DRBsToQosFlowsMappingItem ** data)
{
	__si_amf_init_DRBsToQosFlowsMappingItem( data);
	SI_AMF_DT_DRBsToQosFlowsMappingItem * dRBsToQosFlowsMappingItem = *data;
	
	dRBsToQosFlowsMappingItem->dRB_ID = __si_core_getU64RANDRange( 1, 32);
	__app_ngap_set_AssociatedQosFlowList( &dRBsToQosFlowsMappingItem->associatedQosFlowList);
}


//-- CONTAINER, DRBsToQosFlowsMappingItem-ExtIEs
void __app_ngap_set_DRBsToQosFlowsMappingItem_ExtIEs( SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs ** data)
{
	__si_amf_init_DRBsToQosFlowsMappingItem_ExtIEs( data);
	SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs * dRBsToQosFlowsMappingItem_ExtIEs = *data;
	
}


//-- SEQUENCE, Dynamic5QIDescriptor
void __app_ngap_set_Dynamic5QIDescriptor( SI_AMF_DT_Dynamic5QIDescriptor ** data)
{
	__si_amf_init_Dynamic5QIDescriptor( data);
	SI_AMF_DT_Dynamic5QIDescriptor * dynamic5QIDescriptor = *data;
	
	dynamic5QIDescriptor->priorityLevelQos = __si_core_getU64RANDRange( 1, 127);
	dynamic5QIDescriptor->packetDelayBudget = __si_core_getU64RANDRange( 0, 1023);
	__app_ngap_set_PacketErrorRate( &dynamic5QIDescriptor->packetErrorRate);

	dynamic5QIDescriptor->fiveQI = __si_core_getU64RANDRange( 0, 255);
	dynamic5QIDescriptor->selected_edelayCritical = 0;
	dynamic5QIDescriptor->averagingWindow = __si_core_getU64RANDRange( 0, 4095);
	dynamic5QIDescriptor->maximumDataBurstVolume = __si_core_getU64RANDRange( 0, 4095);
}


//-- CONTAINER, Dynamic5QIDescriptor-ExtIEs
void __app_ngap_set_Dynamic5QIDescriptor_ExtIEs( SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs ** data)
{
	__si_amf_init_Dynamic5QIDescriptor_ExtIEs( data);
	SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs * dynamic5QIDescriptor_ExtIEs = *data;
	
}


//-- OCTETSTRING, EmergencyAreaID
void __app_ngap_set_EmergencyAreaID( SI_AMF_DT_EmergencyAreaID ** data)
{
	__si_amf_init_EmergencyAreaID( data);
	SI_AMF_DT_EmergencyAreaID * emergencyAreaID = *data;
	
	emergencyAreaID->data = (unsigned char *) __si_allocM(3);
	emergencyAreaID->length = 3;
	__si_core_fill_dummy_data( emergencyAreaID->data, emergencyAreaID->length);
}


//-- SEQUENCE_OF, EmergencyAreaIDBroadcastEUTRA
void __app_ngap_set_EmergencyAreaIDBroadcastEUTRA( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA ** data)
{
	__si_amf_init_EmergencyAreaIDBroadcastEUTRA( data);
	SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA * emergencyAreaIDBroadcastEUTRA = *data;
	
	SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item * objItem = NULL;

	__app_ngap_set_EmergencyAreaIDBroadcastEUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->EmergencyAreaIDBroadcastEUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, EmergencyAreaIDBroadcastEUTRA-Item
void __app_ngap_set_EmergencyAreaIDBroadcastEUTRA_Item( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item ** data)
{
	__si_amf_init_EmergencyAreaIDBroadcastEUTRA_Item( data);
	SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item * emergencyAreaIDBroadcastEUTRA_Item = *data;
	
	__app_ngap_set_EmergencyAreaID( &emergencyAreaIDBroadcastEUTRA_Item->emergencyAreaID);

	__app_ngap_set_CompletedCellsInEAI_EUTRA( &emergencyAreaIDBroadcastEUTRA_Item->completedCellsInEAI_EUTRA);
}


//-- CONTAINER, EmergencyAreaIDBroadcastEUTRA-Item-ExtIEs
void __app_ngap_set_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( data);
	SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs * emergencyAreaIDBroadcastEUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, EmergencyAreaIDBroadcastNR
void __app_ngap_set_EmergencyAreaIDBroadcastNR( SI_AMF_DT_EmergencyAreaIDBroadcastNR ** data)
{
	__si_amf_init_EmergencyAreaIDBroadcastNR( data);
	SI_AMF_DT_EmergencyAreaIDBroadcastNR * emergencyAreaIDBroadcastNR = *data;
	
	SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item * objItem = NULL;

	__app_ngap_set_EmergencyAreaIDBroadcastNR_Item( &objItem);
	__si_linked_list_add( (*data)->EmergencyAreaIDBroadcastNR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, EmergencyAreaIDBroadcastNR-Item
void __app_ngap_set_EmergencyAreaIDBroadcastNR_Item( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item ** data)
{
	__si_amf_init_EmergencyAreaIDBroadcastNR_Item( data);
	SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item * emergencyAreaIDBroadcastNR_Item = *data;
	
	__app_ngap_set_EmergencyAreaID( &emergencyAreaIDBroadcastNR_Item->emergencyAreaID);

	__app_ngap_set_CompletedCellsInEAI_NR( &emergencyAreaIDBroadcastNR_Item->completedCellsInEAI_NR);
}


//-- CONTAINER, EmergencyAreaIDBroadcastNR-Item-ExtIEs
void __app_ngap_set_EmergencyAreaIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs ** data)
{
	__si_amf_init_EmergencyAreaIDBroadcastNR_Item_ExtIEs( data);
	SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs * emergencyAreaIDBroadcastNR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, EmergencyAreaIDCancelledEUTRA
void __app_ngap_set_EmergencyAreaIDCancelledEUTRA( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA ** data)
{
	__si_amf_init_EmergencyAreaIDCancelledEUTRA( data);
	SI_AMF_DT_EmergencyAreaIDCancelledEUTRA * emergencyAreaIDCancelledEUTRA = *data;
	
	SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item * objItem = NULL;

	__app_ngap_set_EmergencyAreaIDCancelledEUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->EmergencyAreaIDCancelledEUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, EmergencyAreaIDCancelledEUTRA-Item
void __app_ngap_set_EmergencyAreaIDCancelledEUTRA_Item( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item ** data)
{
	__si_amf_init_EmergencyAreaIDCancelledEUTRA_Item( data);
	SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item * emergencyAreaIDCancelledEUTRA_Item = *data;
	
	__app_ngap_set_EmergencyAreaID( &emergencyAreaIDCancelledEUTRA_Item->emergencyAreaID);

	__app_ngap_set_CancelledCellsInEAI_EUTRA( &emergencyAreaIDCancelledEUTRA_Item->cancelledCellsInEAI_EUTRA);
}


//-- CONTAINER, EmergencyAreaIDCancelledEUTRA-Item-ExtIEs
void __app_ngap_set_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( data);
	SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs * emergencyAreaIDCancelledEUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, EmergencyAreaIDCancelledNR
void __app_ngap_set_EmergencyAreaIDCancelledNR( SI_AMF_DT_EmergencyAreaIDCancelledNR ** data)
{
	__si_amf_init_EmergencyAreaIDCancelledNR( data);
	SI_AMF_DT_EmergencyAreaIDCancelledNR * emergencyAreaIDCancelledNR = *data;
	
	SI_AMF_DT_EmergencyAreaIDCancelledNR_Item * objItem = NULL;

	__app_ngap_set_EmergencyAreaIDCancelledNR_Item( &objItem);
	__si_linked_list_add( (*data)->EmergencyAreaIDCancelledNR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, EmergencyAreaIDCancelledNR-Item
void __app_ngap_set_EmergencyAreaIDCancelledNR_Item( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item ** data)
{
	__si_amf_init_EmergencyAreaIDCancelledNR_Item( data);
	SI_AMF_DT_EmergencyAreaIDCancelledNR_Item * emergencyAreaIDCancelledNR_Item = *data;
	
	__app_ngap_set_EmergencyAreaID( &emergencyAreaIDCancelledNR_Item->emergencyAreaID);

	__app_ngap_set_CancelledCellsInEAI_NR( &emergencyAreaIDCancelledNR_Item->cancelledCellsInEAI_NR);
}


//-- CONTAINER, EmergencyAreaIDCancelledNR-Item-ExtIEs
void __app_ngap_set_EmergencyAreaIDCancelledNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs ** data)
{
	__si_amf_init_EmergencyAreaIDCancelledNR_Item_ExtIEs( data);
	SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs * emergencyAreaIDCancelledNR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, EmergencyAreaIDList
void __app_ngap_set_EmergencyAreaIDList( SI_AMF_DT_EmergencyAreaIDList ** data)
{
	__si_amf_init_EmergencyAreaIDList( data);
	SI_AMF_DT_EmergencyAreaIDList * emergencyAreaIDList = *data;
	
	SI_AMF_DT_EmergencyAreaID * objItem = NULL;

	__app_ngap_set_EmergencyAreaID( &objItem);
	__si_linked_list_add( (*data)->EmergencyAreaID, (uint8_t *)objItem);
}


//-- SEQUENCE_OF, EmergencyAreaIDListForRestart
void __app_ngap_set_EmergencyAreaIDListForRestart( SI_AMF_DT_EmergencyAreaIDListForRestart ** data)
{
	__si_amf_init_EmergencyAreaIDListForRestart( data);
	SI_AMF_DT_EmergencyAreaIDListForRestart * emergencyAreaIDListForRestart = *data;
	
	SI_AMF_DT_EmergencyAreaID * objItem = NULL;

	__app_ngap_set_EmergencyAreaID( &objItem);
	__si_linked_list_add( (*data)->EmergencyAreaID, (uint8_t *)objItem);
}


//-- SEQUENCE, EmergencyFallbackIndicator
void __app_ngap_set_EmergencyFallbackIndicator( SI_AMF_DT_EmergencyFallbackIndicator ** data)
{
	__si_amf_init_EmergencyFallbackIndicator( data);
	SI_AMF_DT_EmergencyFallbackIndicator * emergencyFallbackIndicator = *data;
	
	emergencyFallbackIndicator->selected_eemergencyFallbackRequestIndicator = 0;
	emergencyFallbackIndicator->selected_eemergencyServiceTargetCN = 0;
}


//-- CONTAINER, EmergencyFallbackIndicator-ExtIEs
void __app_ngap_set_EmergencyFallbackIndicator_ExtIEs( SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs ** data)
{
	__si_amf_init_EmergencyFallbackIndicator_ExtIEs( data);
	SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs * emergencyFallbackIndicator_ExtIEs = *data;
	
}


//-- OCTETSTRING, EN-DCSONConfigurationTransfer
void __app_ngap_set_EN_DCSONConfigurationTransfer( SI_AMF_DT_EN_DCSONConfigurationTransfer ** data)
{
	__si_amf_init_EN_DCSONConfigurationTransfer( data);
	SI_AMF_DT_EN_DCSONConfigurationTransfer * eN_DCSONConfigurationTransfer = *data;
	
	eN_DCSONConfigurationTransfer->data = (unsigned char *) __si_allocM(1);
	eN_DCSONConfigurationTransfer->length = 1;
	//__si_core_fill_dummy_data( eN_DCSONConfigurationTransfer->data, eN_DCSONConfigurationTransfer->length);
	memset( eN_DCSONConfigurationTransfer->data, 0, 1);
}


//-- SEQUENCE, EndpointIPAddressAndPort
void __app_ngap_set_EndpointIPAddressAndPort( SI_AMF_DT_EndpointIPAddressAndPort ** data)
{
	__si_amf_init_EndpointIPAddressAndPort( data);
	SI_AMF_DT_EndpointIPAddressAndPort * endpointIPAddressAndPort = *data;
	
	__app_ngap_set_TransportLayerAddress( &endpointIPAddressAndPort->endpointIPAddress);

	__app_ngap_set_PortNumber( &endpointIPAddressAndPort->portNumber);
}


//-- CONTAINER, EndpointIPAddressAndPort-ExtIEs
void __app_ngap_set_EndpointIPAddressAndPort_ExtIEs( SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs ** data)
{
	__si_amf_init_EndpointIPAddressAndPort_ExtIEs( data);
	SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs * endpointIPAddressAndPort_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, EquivalentPLMNs
void __app_ngap_set_EquivalentPLMNs( SI_AMF_DT_EquivalentPLMNs ** data)
{
	__si_amf_init_EquivalentPLMNs( data);
	SI_AMF_DT_EquivalentPLMNs * equivalentPLMNs = *data;
	
	SI_AMF_DT_PLMNIdentity * objItem = NULL;

	__app_ngap_set_PLMNIdentity( &objItem);
	__si_linked_list_add( (*data)->PLMNIdentity, (uint8_t *)objItem);
}


//-- OCTETSTRING, EPS-TAC
void __app_ngap_set_EPS_TAC( SI_AMF_DT_EPS_TAC ** data)
{
	__si_amf_init_EPS_TAC( data);
	SI_AMF_DT_EPS_TAC * ePS_TAC = *data;
	
	ePS_TAC->data = (unsigned char *) __si_allocM(2);
	ePS_TAC->length = 2;
	__si_core_fill_dummy_data( ePS_TAC->data, ePS_TAC->length);
}


//-- SEQUENCE, EPS-TAI
void __app_ngap_set_EPS_TAI( SI_AMF_DT_EPS_TAI ** data)
{
	__si_amf_init_EPS_TAI( data);
	SI_AMF_DT_EPS_TAI * ePS_TAI = *data;
	
	__app_ngap_set_PLMNIdentity( &ePS_TAI->pLMNIdentity);

	__app_ngap_set_EPS_TAC( &ePS_TAI->ePS_TAC);
}


//-- CONTAINER, EPS-TAI-ExtIEs
void __app_ngap_set_EPS_TAI_ExtIEs( SI_AMF_DT_EPS_TAI_ExtIEs ** data)
{
	__si_amf_init_EPS_TAI_ExtIEs( data);
	SI_AMF_DT_EPS_TAI_ExtIEs * ePS_TAI_ExtIEs = *data;
	
}


//-- INTEGER, E-RAB-ID
void __app_ngap_set_E_RAB_ID( SI_AMF_DT_E_RAB_ID ** data)
{
	SI_AMF_DT_E_RAB_ID * e_RAB_ID = *data;
	
	//MIN = 0, MAX = 15
	e_RAB_ID->data = __si_core_getU64RANDRange( 0, 15);
}


//-- SEQUENCE_OF, E-RABInformationList
void __app_ngap_set_E_RABInformationList( SI_AMF_DT_E_RABInformationList ** data)
{
	__si_amf_init_E_RABInformationList( data);
	SI_AMF_DT_E_RABInformationList * e_RABInformationList = *data;
	
	SI_AMF_DT_E_RABInformationItem * objItem = NULL;

	__app_ngap_set_E_RABInformationItem( &objItem);
	__si_linked_list_add( (*data)->E_RABInformationItem, (uint8_t *)objItem);
}


//-- SEQUENCE, E-RABInformationItem
void __app_ngap_set_E_RABInformationItem( SI_AMF_DT_E_RABInformationItem ** data)
{
	__si_amf_init_E_RABInformationItem( data);
	SI_AMF_DT_E_RABInformationItem * e_RABInformationItem = *data;
	
	e_RABInformationItem->e_RAB_ID = __si_core_getU64RANDRange( 0, 15);
	e_RABInformationItem->selected_edLForwarding = 0;
}


//-- CONTAINER, E-RABInformationItem-ExtIEs
void __app_ngap_set_E_RABInformationItem_ExtIEs( SI_AMF_DT_E_RABInformationItem_ExtIEs ** data)
{
	__si_amf_init_E_RABInformationItem_ExtIEs( data);
	SI_AMF_DT_E_RABInformationItem_ExtIEs * e_RABInformationItem_ExtIEs = *data;
	
}


//-- BITSTRING, EUTRACellIdentity
void __app_ngap_set_EUTRACellIdentity( SI_AMF_DT_EUTRACellIdentity ** data)
{
	__si_amf_init_EUTRACellIdentity( data);
	SI_AMF_DT_EUTRACellIdentity * eUTRACellIdentity = *data;
	
	//BITSIZE = 28  , BIT STRING(SIZE(28))
	eUTRACellIdentity->data = (unsigned char *) __si_allocM(5);
	eUTRACellIdentity->length = 5;
	eUTRACellIdentity->bitslen = 28;
	__si_core_fill_dummy_data( eUTRACellIdentity->data, eUTRACellIdentity->length);
}


//-- SEQUENCE, EUTRA-CGI
void __app_ngap_set_EUTRA_CGI( SI_AMF_DT_EUTRA_CGI ** data)
{
	__si_amf_init_EUTRA_CGI( data);
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI = *data;
	
	__app_ngap_set_PLMNIdentity( &eUTRA_CGI->pLMNIdentity);

	__app_ngap_set_EUTRACellIdentity( &eUTRA_CGI->eUTRACellIdentity);
}


//-- CONTAINER, EUTRA-CGI-ExtIEs
void __app_ngap_set_EUTRA_CGI_ExtIEs( SI_AMF_DT_EUTRA_CGI_ExtIEs ** data)
{
	__si_amf_init_EUTRA_CGI_ExtIEs( data);
	SI_AMF_DT_EUTRA_CGI_ExtIEs * eUTRA_CGI_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, EUTRA-CGIList
void __app_ngap_set_EUTRA_CGIList( SI_AMF_DT_EUTRA_CGIList ** data)
{
	__si_amf_init_EUTRA_CGIList( data);
	SI_AMF_DT_EUTRA_CGIList * eUTRA_CGIList = *data;
	
	SI_AMF_DT_EUTRA_CGI * objItem = NULL;

	__app_ngap_set_EUTRA_CGI( &objItem);
	__si_linked_list_add( (*data)->EUTRA_CGI, (uint8_t *)objItem);
}


//-- SEQUENCE_OF, EUTRA-CGIListForWarning
void __app_ngap_set_EUTRA_CGIListForWarning( SI_AMF_DT_EUTRA_CGIListForWarning ** data)
{
	__si_amf_init_EUTRA_CGIListForWarning( data);
	SI_AMF_DT_EUTRA_CGIListForWarning * eUTRA_CGIListForWarning = *data;
	
	SI_AMF_DT_EUTRA_CGI * objItem = NULL;

	__app_ngap_set_EUTRA_CGI( &objItem);
	__si_linked_list_add( (*data)->EUTRA_CGI, (uint8_t *)objItem);
}


//-- BITSTRING, EUTRAencryptionAlgorithms
void __app_ngap_set_EUTRAencryptionAlgorithms( SI_AMF_DT_EUTRAencryptionAlgorithms ** data)
{
	__si_amf_init_EUTRAencryptionAlgorithms( data);
	SI_AMF_DT_EUTRAencryptionAlgorithms * eUTRAencryptionAlgorithms = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16,...))
	eUTRAencryptionAlgorithms->data = (unsigned char *) __si_allocM(3);
	eUTRAencryptionAlgorithms->length = 3;
	eUTRAencryptionAlgorithms->bitslen = 16;
	//memset( eUTRAencryptionAlgorithms->data, 0, 3);
	__si_core_fill_dummy_data( eUTRAencryptionAlgorithms->data, eUTRAencryptionAlgorithms->length);
	eUTRAencryptionAlgorithms->data[0] = 0x50;
}


//-- BITSTRING, EUTRAintegrityProtectionAlgorithms
void __app_ngap_set_EUTRAintegrityProtectionAlgorithms( SI_AMF_DT_EUTRAintegrityProtectionAlgorithms ** data)
{
	__si_amf_init_EUTRAintegrityProtectionAlgorithms( data);
	SI_AMF_DT_EUTRAintegrityProtectionAlgorithms * eUTRAintegrityProtectionAlgorithms = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16,...))
	eUTRAintegrityProtectionAlgorithms->data = (unsigned char *) __si_allocM(3);
	//eUTRAintegrityProtectionAlgorithms->length = 3;
	//eUTRAintegrityProtectionAlgorithms->bitslen = 16;
	eUTRAintegrityProtectionAlgorithms->length = 3;
	eUTRAintegrityProtectionAlgorithms->bitslen = 16;	
	__si_core_fill_dummy_data( eUTRAintegrityProtectionAlgorithms->data, eUTRAintegrityProtectionAlgorithms->length);
	//memset( eUTRAintegrityProtectionAlgorithms->data, 0, 3);
}


//-- INTEGER, ExpectedActivityPeriod
void __app_ngap_set_ExpectedActivityPeriod( SI_AMF_DT_ExpectedActivityPeriod ** data)
{
	SI_AMF_DT_ExpectedActivityPeriod * expectedActivityPeriod = *data;
	
	//MIN = 1, MAX = 30
	expectedActivityPeriod->data = __si_core_getU64RANDRange( 1, 30);
}


//-- INTEGER, ExpectedIdlePeriod
void __app_ngap_set_ExpectedIdlePeriod( SI_AMF_DT_ExpectedIdlePeriod ** data)
{
	SI_AMF_DT_ExpectedIdlePeriod * expectedIdlePeriod = *data;
	
	//MIN = 1, MAX = 30
	expectedIdlePeriod->data = __si_core_getU64RANDRange( 1, 30);
}


//-- SEQUENCE, ExpectedUEActivityBehaviour
void __app_ngap_set_ExpectedUEActivityBehaviour( SI_AMF_DT_ExpectedUEActivityBehaviour ** data)
{
	__si_amf_init_ExpectedUEActivityBehaviour( data);
	SI_AMF_DT_ExpectedUEActivityBehaviour * expectedUEActivityBehaviour = *data;
	
	expectedUEActivityBehaviour->expectedActivityPeriod = 15;	//__si_core_getU64RANDRange( 1, 30);
	expectedUEActivityBehaviour->isPresent_expectedActivityPeriod = 0;
	
	expectedUEActivityBehaviour->expectedIdlePeriod = 15; //__si_core_getU64RANDRange( 1, 30);
	expectedUEActivityBehaviour->isPresent_expectedIdlePeriod = 0;
	
	expectedUEActivityBehaviour->selected_esourceOfUEActivityBehaviourInformation = 1;
	expectedUEActivityBehaviour->isPresent_sourceOfUEActivityBehaviourInformation = 1;
}


//-- CONTAINER, ExpectedUEActivityBehaviour-ExtIEs
void __app_ngap_set_ExpectedUEActivityBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs ** data)
{
	__si_amf_init_ExpectedUEActivityBehaviour_ExtIEs( data);
	SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs * expectedUEActivityBehaviour_ExtIEs = *data;
	
}


//-- SEQUENCE, ExpectedUEBehaviour
void __app_ngap_set_ExpectedUEBehaviour( SI_AMF_DT_ExpectedUEBehaviour ** data)
{
	__si_amf_init_ExpectedUEBehaviour( data);
	SI_AMF_DT_ExpectedUEBehaviour * expectedUEBehaviour = *data;
	
	__app_ngap_set_ExpectedUEActivityBehaviour( &expectedUEBehaviour->expectedUEActivityBehaviour);
	expectedUEBehaviour->isPresent_expectedUEActivityBehaviour = 1;

	expectedUEBehaviour->selected_eexpectedHOInterval = 4;
	expectedUEBehaviour->isPresent_expectedHOInterval = 1;
	
	expectedUEBehaviour->selected_eexpectedUEMobility = 1;
	expectedUEBehaviour->isPresent_expectedUEMobility = 1;
	
	__app_ngap_set_ExpectedUEMovingTrajectory( &expectedUEBehaviour->expectedUEMovingTrajectory);
	expectedUEBehaviour->isPresent_expectedUEMovingTrajectory = 1;
}


//-- CONTAINER, ExpectedUEBehaviour-ExtIEs
void __app_ngap_set_ExpectedUEBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEBehaviour_ExtIEs ** data)
{
	__si_amf_init_ExpectedUEBehaviour_ExtIEs( data);
	SI_AMF_DT_ExpectedUEBehaviour_ExtIEs * expectedUEBehaviour_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, ExpectedUEMovingTrajectory
void __app_ngap_set_ExpectedUEMovingTrajectory( SI_AMF_DT_ExpectedUEMovingTrajectory ** data)
{
	__si_amf_init_ExpectedUEMovingTrajectory( data);
	SI_AMF_DT_ExpectedUEMovingTrajectory * expectedUEMovingTrajectory = *data;
	
	SI_AMF_DT_ExpectedUEMovingTrajectoryItem * objItem = NULL;

	__app_ngap_set_ExpectedUEMovingTrajectoryItem( &objItem);
	__si_linked_list_add( (*data)->ExpectedUEMovingTrajectoryItem, (uint8_t *)objItem);
}


//-- INTEGER, ExpectedUEMovingTrajectoryItemTime
void __app_ngap_set_ExpectedUEMovingTrajectoryItemTime( SI_AMF_DT_ExpectedUEMovingTrajectoryItemTime ** data)
{
	SI_AMF_DT_ExpectedUEMovingTrajectoryItemTime * expectedUEMovingTrajectoryItemTime = *data;
	
	//MIN = 0, MAX = 4095
	expectedUEMovingTrajectoryItemTime->data = __si_core_getU64RANDRange( 0, 4095);
}


//-- SEQUENCE, ExpectedUEMovingTrajectoryItem
void __app_ngap_set_ExpectedUEMovingTrajectoryItem( SI_AMF_DT_ExpectedUEMovingTrajectoryItem ** data)
{
	__si_amf_init_ExpectedUEMovingTrajectoryItem( data);
	SI_AMF_DT_ExpectedUEMovingTrajectoryItem * expectedUEMovingTrajectoryItem = *data;
	
	__app_ngap_set_NGRAN_CGI( &expectedUEMovingTrajectoryItem->nGRAN_CGI);

	expectedUEMovingTrajectoryItem->timeStayedInCell = __si_core_getU64RANDRange( 0, 4095);
	expectedUEMovingTrajectoryItem->isPresent_timeStayedInCell = 1;
}


//-- CONTAINER, ExpectedUEMovingTrajectoryItem-ExtIEs
void __app_ngap_set_ExpectedUEMovingTrajectoryItem_ExtIEs( SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs ** data)
{
	__si_amf_init_ExpectedUEMovingTrajectoryItem_ExtIEs( data);
	SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs * expectedUEMovingTrajectoryItem_ExtIEs = *data;
	
}


//-- SEQUENCE, FiveG-S-TMSI
void __app_ngap_set_FiveG_S_TMSI( SI_AMF_DT_FiveG_S_TMSI ** data)
{
	__si_amf_init_FiveG_S_TMSI( data);
	SI_AMF_DT_FiveG_S_TMSI * fiveG_S_TMSI = *data;
	
	__app_ngap_set_AMFSetID( &fiveG_S_TMSI->aMFSetID);

	__app_ngap_set_AMFPointer( &fiveG_S_TMSI->aMFPointer);

	__app_ngap_set_FiveG_TMSI( &fiveG_S_TMSI->fiveG_TMSI);
}


//-- CONTAINER, FiveG-S-TMSI-ExtIEs
void __app_ngap_set_FiveG_S_TMSI_ExtIEs( SI_AMF_DT_FiveG_S_TMSI_ExtIEs ** data)
{
	__si_amf_init_FiveG_S_TMSI_ExtIEs( data);
	SI_AMF_DT_FiveG_S_TMSI_ExtIEs * fiveG_S_TMSI_ExtIEs = *data;
	
}


//-- OCTETSTRING, FiveG-TMSI
void __app_ngap_set_FiveG_TMSI( SI_AMF_DT_FiveG_TMSI ** data)
{
	__si_amf_init_FiveG_TMSI( data);
	SI_AMF_DT_FiveG_TMSI * fiveG_TMSI = *data;
	
	fiveG_TMSI->data = (unsigned char *) __si_allocM(4);
	fiveG_TMSI->length = 4;
	__si_core_fill_dummy_data( fiveG_TMSI->data, fiveG_TMSI->length);
}


//-- INTEGER, FiveQI
void __app_ngap_set_FiveQI( SI_AMF_DT_FiveQI ** data)
{
	SI_AMF_DT_FiveQI * fiveQI = *data;
	
	//MIN = 0, MAX = 255
	fiveQI->data = __si_core_getU64RANDRange( 0, 255);
}


//-- SEQUENCE_OF, ForbiddenAreaInformation
void __app_ngap_set_ForbiddenAreaInformation( SI_AMF_DT_ForbiddenAreaInformation ** data)
{
	__si_amf_init_ForbiddenAreaInformation( data);
	SI_AMF_DT_ForbiddenAreaInformation * forbiddenAreaInformation = *data;
	
	SI_AMF_DT_ForbiddenAreaInformation_Item * objItem = NULL;

	__app_ngap_set_ForbiddenAreaInformation_Item( &objItem);
	__si_linked_list_add( (*data)->ForbiddenAreaInformation_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, ForbiddenAreaInformation-Item
void __app_ngap_set_ForbiddenAreaInformation_Item( SI_AMF_DT_ForbiddenAreaInformation_Item ** data)
{
	__si_amf_init_ForbiddenAreaInformation_Item( data);
	SI_AMF_DT_ForbiddenAreaInformation_Item * forbiddenAreaInformation_Item = *data;
	
	__app_ngap_set_PLMNIdentity( &forbiddenAreaInformation_Item->pLMNIdentity);

	__app_ngap_set_ForbiddenTACs( &forbiddenAreaInformation_Item->forbiddenTACs);
}


//-- CONTAINER, ForbiddenAreaInformation-Item-ExtIEs
void __app_ngap_set_ForbiddenAreaInformation_Item_ExtIEs( SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs ** data)
{
	__si_amf_init_ForbiddenAreaInformation_Item_ExtIEs( data);
	SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs * forbiddenAreaInformation_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, ForbiddenTACs
void __app_ngap_set_ForbiddenTACs( SI_AMF_DT_ForbiddenTACs ** data)
{
	__si_amf_init_ForbiddenTACs( data);
	SI_AMF_DT_ForbiddenTACs * forbiddenTACs = *data;
	
	SI_AMF_DT_TAC * objItem = NULL;

	__app_ngap_set_TAC( &objItem);
	__si_linked_list_add( (*data)->TAC, (uint8_t *)objItem);
}


//-- SEQUENCE, GBR-QosInformation
void __app_ngap_set_GBR_QosInformation( SI_AMF_DT_GBR_QosInformation ** data)
{
	__si_amf_init_GBR_QosInformation( data);
	SI_AMF_DT_GBR_QosInformation * gBR_QosInformation = *data;
	
	gBR_QosInformation->maximumFlowBitRateDL = __si_core_getU64RANDRange( 0, 4000000000000);
	gBR_QosInformation->maximumFlowBitRateUL = __si_core_getU64RANDRange( 0, 4000000000000);
	gBR_QosInformation->guaranteedFlowBitRateDL = __si_core_getU64RANDRange( 0, 4000000000000);
	gBR_QosInformation->guaranteedFlowBitRateUL = __si_core_getU64RANDRange( 0, 4000000000000);
	gBR_QosInformation->selected_enotificationControl = 0;
	gBR_QosInformation->maximumPacketLossRateDL = __si_core_getU64RANDRange( 0, 1000);
	gBR_QosInformation->maximumPacketLossRateUL = __si_core_getU64RANDRange( 0, 1000);
}


//-- CONTAINER, GBR-QosInformation-ExtIEs
void __app_ngap_set_GBR_QosInformation_ExtIEs( SI_AMF_DT_GBR_QosInformation_ExtIEs ** data)
{
	__si_amf_init_GBR_QosInformation_ExtIEs( data);
	SI_AMF_DT_GBR_QosInformation_ExtIEs * gBR_QosInformation_ExtIEs = *data;
	
}


//-- SEQUENCE, GlobalGNB-ID
void __app_ngap_set_GlobalGNB_ID( SI_AMF_DT_GlobalGNB_ID ** data)
{
	__si_amf_init_GlobalGNB_ID( data);
	SI_AMF_DT_GlobalGNB_ID * globalGNB_ID = *data;
	
	__app_ngap_set_PLMNIdentity( &globalGNB_ID->pLMNIdentity);

	__app_ngap_set_GNB_ID( &globalGNB_ID->gNB_ID);
}


//-- CONTAINER, GlobalGNB-ID-ExtIEs
void __app_ngap_set_GlobalGNB_ID_ExtIEs( SI_AMF_DT_GlobalGNB_ID_ExtIEs ** data)
{
	__si_amf_init_GlobalGNB_ID_ExtIEs( data);
	SI_AMF_DT_GlobalGNB_ID_ExtIEs * globalGNB_ID_ExtIEs = *data;
	
}


//-- SEQUENCE, GlobalN3IWF-ID
void __app_ngap_set_GlobalN3IWF_ID( SI_AMF_DT_GlobalN3IWF_ID ** data)
{
	__si_amf_init_GlobalN3IWF_ID( data);
	SI_AMF_DT_GlobalN3IWF_ID * globalN3IWF_ID = *data;
	
	__app_ngap_set_PLMNIdentity( &globalN3IWF_ID->pLMNIdentity);

	__app_ngap_set_N3IWF_ID( &globalN3IWF_ID->n3IWF_ID);
}


//-- CONTAINER, GlobalN3IWF-ID-ExtIEs
void __app_ngap_set_GlobalN3IWF_ID_ExtIEs( SI_AMF_DT_GlobalN3IWF_ID_ExtIEs ** data)
{
	__si_amf_init_GlobalN3IWF_ID_ExtIEs( data);
	SI_AMF_DT_GlobalN3IWF_ID_ExtIEs * globalN3IWF_ID_ExtIEs = *data;
	
}


//-- SEQUENCE, GlobalNgENB-ID
void __app_ngap_set_GlobalNgENB_ID( SI_AMF_DT_GlobalNgENB_ID ** data)
{
	__si_amf_init_GlobalNgENB_ID( data);
	SI_AMF_DT_GlobalNgENB_ID * globalNgENB_ID = *data;
	
	__app_ngap_set_PLMNIdentity( &globalNgENB_ID->pLMNIdentity);

	__app_ngap_set_NgENB_ID( &globalNgENB_ID->ngENB_ID);
}


//-- CONTAINER, GlobalNgENB-ID-ExtIEs
void __app_ngap_set_GlobalNgENB_ID_ExtIEs( SI_AMF_DT_GlobalNgENB_ID_ExtIEs ** data)
{
	__si_amf_init_GlobalNgENB_ID_ExtIEs( data);
	SI_AMF_DT_GlobalNgENB_ID_ExtIEs * globalNgENB_ID_ExtIEs = *data;
	
}


//-- CHOICE, GlobalRANNodeID
void __app_ngap_set_GlobalRANNodeID( SI_AMF_DT_GlobalRANNodeID ** data)
{
	__si_amf_init_GlobalRANNodeID( data);
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_GlobalGNB_ID( &(*data)->u.globalGNB_ID);

}


//-- CONTAINER, GlobalRANNodeID-ExtIEs
void __app_ngap_set_GlobalRANNodeID_ExtIEs( SI_AMF_DT_GlobalRANNodeID_ExtIEs ** data)
{
	__si_amf_init_GlobalRANNodeID_ExtIEs( data);
	SI_AMF_DT_GlobalRANNodeID_ExtIEs * globalRANNodeID_ExtIEs = *data;
	
}


//-- BITSTRING, GNB-IDBS
void __app_ngap_set_GNB_IDBS( SI_AMF_DT_GNB_IDBS ** data)
{
	__si_amf_init_GNB_IDBS( data);
	SI_AMF_DT_GNB_IDBS * gNB_IDBS = *data;
	
	//BITSIZE = 32  , BIT STRING(SIZE(22..32))
	gNB_IDBS->data = (unsigned char *) __si_allocM(5);
	gNB_IDBS->length = 5;
	gNB_IDBS->bitslen = 32;
	__si_core_fill_dummy_data( gNB_IDBS->data, gNB_IDBS->length);
}


//-- CHOICE, GNB-ID
void __app_ngap_set_GNB_ID( SI_AMF_DT_GNB_ID ** data)
{
	__si_amf_init_GNB_ID( data);
	SI_AMF_DT_GNB_ID * gNB_ID = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_GNB_IDBS( &(*data)->u.gNB_ID);

}


//-- CONTAINER, GNB-ID-ExtIEs
void __app_ngap_set_GNB_ID_ExtIEs( SI_AMF_DT_GNB_ID_ExtIEs ** data)
{
	__si_amf_init_GNB_ID_ExtIEs( data);
	SI_AMF_DT_GNB_ID_ExtIEs * gNB_ID_ExtIEs = *data;
	
}


//-- OCTETSTRING, GTP-TEID
void __app_ngap_set_GTP_TEID( SI_AMF_DT_GTP_TEID ** data)
{
	__si_amf_init_GTP_TEID( data);
	SI_AMF_DT_GTP_TEID * gTP_TEID = *data;
	
	gTP_TEID->data = (unsigned char *) __si_allocM(4);
	gTP_TEID->length = 4;
	__si_core_fill_dummy_data( gTP_TEID->data, gTP_TEID->length);
}


//-- SEQUENCE, GTPTunnel
void __app_ngap_set_GTPTunnel( SI_AMF_DT_GTPTunnel ** data)
{
	__si_amf_init_GTPTunnel( data);
	SI_AMF_DT_GTPTunnel * gTPTunnel = *data;
	
	__app_ngap_set_TransportLayerAddress( &gTPTunnel->transportLayerAddress);

	__app_ngap_set_GTP_TEID( &gTPTunnel->gTP_TEID);
}


//-- CONTAINER, GTPTunnel-ExtIEs
void __app_ngap_set_GTPTunnel_ExtIEs( SI_AMF_DT_GTPTunnel_ExtIEs ** data)
{
	__si_amf_init_GTPTunnel_ExtIEs( data);
	SI_AMF_DT_GTPTunnel_ExtIEs * gTPTunnel_ExtIEs = *data;
	
}


//-- SEQUENCE, GUAMI
void __app_ngap_set_GUAMI( SI_AMF_DT_GUAMI ** data)
{
	__si_amf_init_GUAMI( data);
	SI_AMF_DT_GUAMI * gUAMI = *data;
	
	__app_ngap_set_PLMNIdentity( &gUAMI->pLMNIdentity);

	__app_ngap_set_AMFRegionID( &gUAMI->aMFRegionID);

	__app_ngap_set_AMFSetID( &gUAMI->aMFSetID);

	__app_ngap_set_AMFPointer( &gUAMI->aMFPointer);
}


//-- CONTAINER, GUAMI-ExtIEs
void __app_ngap_set_GUAMI_ExtIEs( SI_AMF_DT_GUAMI_ExtIEs ** data)
{
	__si_amf_init_GUAMI_ExtIEs( data);
	SI_AMF_DT_GUAMI_ExtIEs * gUAMI_ExtIEs = *data;
	
}


//-- SEQUENCE, HandoverCommandTransfer
void __app_ngap_set_HandoverCommandTransfer( SI_AMF_DT_HandoverCommandTransfer ** data)
{
	__si_amf_init_HandoverCommandTransfer( data);
	SI_AMF_DT_HandoverCommandTransfer * handoverCommandTransfer = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &handoverCommandTransfer->dLForwardingUP_TNLInformation);
	handoverCommandTransfer->isPresent_dLForwardingUP_TNLInformation = 1;

	__app_ngap_set_QosFlowToBeForwardedList( &handoverCommandTransfer->qosFlowToBeForwardedList);
	handoverCommandTransfer->isPresent_qosFlowToBeForwardedList = 1;

	__app_ngap_set_DataForwardingResponseDRBList( &handoverCommandTransfer->dataForwardingResponseDRBList);
	handoverCommandTransfer->isPresent_dataForwardingResponseDRBList = 1;
}


//-- CONTAINER, HandoverCommandTransfer-ExtIEs
void __app_ngap_set_HandoverCommandTransfer_ExtIEs( SI_AMF_DT_HandoverCommandTransfer_ExtIEs ** data)
{
	__si_amf_init_HandoverCommandTransfer_ExtIEs( data);
	SI_AMF_DT_HandoverCommandTransfer_ExtIEs * handoverCommandTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, HandoverPreparationUnsuccessfulTransfer
void __app_ngap_set_HandoverPreparationUnsuccessfulTransfer( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer ** data)
{
	__si_amf_init_HandoverPreparationUnsuccessfulTransfer( data);
	SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer * handoverPreparationUnsuccessfulTransfer = *data;
	
	__app_ngap_set_Cause( &handoverPreparationUnsuccessfulTransfer->cause);
}


//-- CONTAINER, HandoverPreparationUnsuccessfulTransfer-ExtIEs
void __app_ngap_set_HandoverPreparationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs ** data)
{
	__si_amf_init_HandoverPreparationUnsuccessfulTransfer_ExtIEs( data);
	SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs * handoverPreparationUnsuccessfulTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, HandoverRequestAcknowledgeTransfer
void __app_ngap_set_HandoverRequestAcknowledgeTransfer( SI_AMF_DT_HandoverRequestAcknowledgeTransfer ** data)
{
	__si_amf_init_HandoverRequestAcknowledgeTransfer( data);
	SI_AMF_DT_HandoverRequestAcknowledgeTransfer * handoverRequestAcknowledgeTransfer = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &handoverRequestAcknowledgeTransfer->dL_NGU_UP_TNLInformation);

	__app_ngap_set_UPTransportLayerInformation( &handoverRequestAcknowledgeTransfer->dLForwardingUP_TNLInformation);
	handoverRequestAcknowledgeTransfer->isPresent_dLForwardingUP_TNLInformation = 1;

	__app_ngap_set_SecurityResult( &handoverRequestAcknowledgeTransfer->securityResult);
	handoverRequestAcknowledgeTransfer->isPresent_securityResult = 1;

	__app_ngap_set_QosFlowListWithDataForwarding( &handoverRequestAcknowledgeTransfer->qosFlowSetupResponseList);

	__app_ngap_set_QosFlowListWithCause( &handoverRequestAcknowledgeTransfer->qosFlowFailedToSetupList);
	handoverRequestAcknowledgeTransfer->isPresent_qosFlowFailedToSetupList = 1;

	__app_ngap_set_DataForwardingResponseDRBList( &handoverRequestAcknowledgeTransfer->dataForwardingResponseDRBList);
	handoverRequestAcknowledgeTransfer->isPresent_dataForwardingResponseDRBList = 1;
}


//-- CONTAINER, HandoverRequestAcknowledgeTransfer-ExtIEs
void __app_ngap_set_HandoverRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs ** data)
{
	__si_amf_init_HandoverRequestAcknowledgeTransfer_ExtIEs( data);
	SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs * handoverRequestAcknowledgeTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, HandoverRequiredTransfer
void __app_ngap_set_HandoverRequiredTransfer( SI_AMF_DT_HandoverRequiredTransfer ** data)
{
	__si_amf_init_HandoverRequiredTransfer( data);
	SI_AMF_DT_HandoverRequiredTransfer * handoverRequiredTransfer = *data;
	
	handoverRequiredTransfer->selected_edirectForwardingPathAvailability = 0;
}


//-- CONTAINER, HandoverRequiredTransfer-ExtIEs
void __app_ngap_set_HandoverRequiredTransfer_ExtIEs( SI_AMF_DT_HandoverRequiredTransfer_ExtIEs ** data)
{
	__si_amf_init_HandoverRequiredTransfer_ExtIEs( data);
	SI_AMF_DT_HandoverRequiredTransfer_ExtIEs * handoverRequiredTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, HandoverResourceAllocationUnsuccessfulTransfer
void __app_ngap_set_HandoverResourceAllocationUnsuccessfulTransfer( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer ** data)
{
	__si_amf_init_HandoverResourceAllocationUnsuccessfulTransfer( data);
	SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer * handoverResourceAllocationUnsuccessfulTransfer = *data;
	
	__app_ngap_set_Cause( &handoverResourceAllocationUnsuccessfulTransfer->cause);

	__app_ngap_set_CriticalityDiagnostics( &handoverResourceAllocationUnsuccessfulTransfer->criticalityDiagnostics);
	handoverResourceAllocationUnsuccessfulTransfer->isPresent_criticalityDiagnostics = 1;
}


//-- CONTAINER, HandoverResourceAllocationUnsuccessfulTransfer-ExtIEs
void __app_ngap_set_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs ** data)
{
	__si_amf_init_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( data);
	SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs * handoverResourceAllocationUnsuccessfulTransfer_ExtIEs = *data;
	
}


//-- INTEGER, IndexToRFSP
void __app_ngap_set_IndexToRFSP( SI_AMF_DT_IndexToRFSP ** data)
{
	SI_AMF_DT_IndexToRFSP * indexToRFSP = *data;
	
	//MIN = 1, MAX = 256
	indexToRFSP->data = __si_core_getU64RANDRange( 1, 256);
}


//-- SEQUENCE, InfoOnRecommendedCellsAndRANNodesForPaging
void __app_ngap_set_InfoOnRecommendedCellsAndRANNodesForPaging( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging ** data)
{
	__si_amf_init_InfoOnRecommendedCellsAndRANNodesForPaging( data);
	SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging * infoOnRecommendedCellsAndRANNodesForPaging = *data;
	
	__app_ngap_set_RecommendedCellsForPaging( &infoOnRecommendedCellsAndRANNodesForPaging->recommendedCellsForPaging);

	__app_ngap_set_RecommendedRANNodesForPaging( &infoOnRecommendedCellsAndRANNodesForPaging->recommendRANNodesForPaging);
}


//-- CONTAINER, InfoOnRecommendedCellsAndRANNodesForPaging-ExtIEs
void __app_ngap_set_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs ** data)
{
	__si_amf_init_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( data);
	SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs * infoOnRecommendedCellsAndRANNodesForPaging_ExtIEs = *data;
	
}


//-- INTEGER, IntendedNumberOfPagingAttempts
void __app_ngap_set_IntendedNumberOfPagingAttempts( SI_AMF_DT_IntendedNumberOfPagingAttempts ** data)
{
	SI_AMF_DT_IntendedNumberOfPagingAttempts * intendedNumberOfPagingAttempts = *data;
	
	//MIN = 1, MAX = 16
	intendedNumberOfPagingAttempts->data = __si_core_getU64RANDRange( 1, 16);
}


//-- BITSTRING, InterfacesToTrace
void __app_ngap_set_InterfacesToTrace( SI_AMF_DT_InterfacesToTrace ** data)
{
	__si_amf_init_InterfacesToTrace( data);
	SI_AMF_DT_InterfacesToTrace * interfacesToTrace = *data;
	
	//BITSIZE = 8  , BIT STRING(SIZE(8))
	interfacesToTrace->data = (unsigned char *) __si_allocM(2);
	interfacesToTrace->length = 2;
	interfacesToTrace->bitslen = 8;
	__si_core_fill_dummy_data( interfacesToTrace->data, interfacesToTrace->length);
}


//-- CHOICE, LastVisitedCellInformation
void __app_ngap_set_LastVisitedCellInformation( SI_AMF_DT_LastVisitedCellInformation ** data)
{
	__si_amf_init_LastVisitedCellInformation( data);
	SI_AMF_DT_LastVisitedCellInformation * lastVisitedCellInformation = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_LastVisitedNGRANCellInformation( &(*data)->u.nGRANCell);

}


//-- CONTAINER, LastVisitedCellInformation-ExtIEs
void __app_ngap_set_LastVisitedCellInformation_ExtIEs( SI_AMF_DT_LastVisitedCellInformation_ExtIEs ** data)
{
	__si_amf_init_LastVisitedCellInformation_ExtIEs( data);
	SI_AMF_DT_LastVisitedCellInformation_ExtIEs * lastVisitedCellInformation_ExtIEs = *data;
	
}


//-- SEQUENCE, LastVisitedCellItem
void __app_ngap_set_LastVisitedCellItem( SI_AMF_DT_LastVisitedCellItem ** data)
{
	__si_amf_init_LastVisitedCellItem( data);
	SI_AMF_DT_LastVisitedCellItem * lastVisitedCellItem = *data;
	
	__app_ngap_set_LastVisitedCellInformation( &lastVisitedCellItem->lastVisitedCellInformation);
}


//-- CONTAINER, LastVisitedCellItem-ExtIEs
void __app_ngap_set_LastVisitedCellItem_ExtIEs( SI_AMF_DT_LastVisitedCellItem_ExtIEs ** data)
{
	__si_amf_init_LastVisitedCellItem_ExtIEs( data);
	SI_AMF_DT_LastVisitedCellItem_ExtIEs * lastVisitedCellItem_ExtIEs = *data;
	
}


//-- OCTETSTRING, LastVisitedEUTRANCellInformation
void __app_ngap_set_LastVisitedEUTRANCellInformation( SI_AMF_DT_LastVisitedEUTRANCellInformation ** data)
{
	__si_amf_init_LastVisitedEUTRANCellInformation( data);
	SI_AMF_DT_LastVisitedEUTRANCellInformation * lastVisitedEUTRANCellInformation = *data;
	
	lastVisitedEUTRANCellInformation->data = (unsigned char *) __si_allocM(0);
	lastVisitedEUTRANCellInformation->length = 0;
	__si_core_fill_dummy_data( lastVisitedEUTRANCellInformation->data, lastVisitedEUTRANCellInformation->length);
}


//-- OCTETSTRING, LastVisitedGERANCellInformation
void __app_ngap_set_LastVisitedGERANCellInformation( SI_AMF_DT_LastVisitedGERANCellInformation ** data)
{
	__si_amf_init_LastVisitedGERANCellInformation( data);
	SI_AMF_DT_LastVisitedGERANCellInformation * lastVisitedGERANCellInformation = *data;
	
	lastVisitedGERANCellInformation->data = (unsigned char *) __si_allocM(0);
	lastVisitedGERANCellInformation->length = 0;
	__si_core_fill_dummy_data( lastVisitedGERANCellInformation->data, lastVisitedGERANCellInformation->length);
}


//-- SEQUENCE, LastVisitedNGRANCellInformation
void __app_ngap_set_LastVisitedNGRANCellInformation( SI_AMF_DT_LastVisitedNGRANCellInformation ** data)
{
	__si_amf_init_LastVisitedNGRANCellInformation( data);
	SI_AMF_DT_LastVisitedNGRANCellInformation * lastVisitedNGRANCellInformation = *data;
	
	__app_ngap_set_NGRAN_CGI( &lastVisitedNGRANCellInformation->globalCellID);

	__app_ngap_set_CellType( &lastVisitedNGRANCellInformation->cellType);

	lastVisitedNGRANCellInformation->timeUEStayedInCell = __si_core_getU64RANDRange( 0, 4095);
	lastVisitedNGRANCellInformation->timeUEStayedInCellEnhancedGranularity = __si_core_getU64RANDRange( 0, 40950);
	__app_ngap_set_Cause( &lastVisitedNGRANCellInformation->hOCauseValue);
	lastVisitedNGRANCellInformation->isPresent_hOCauseValue = 1;
}


//-- CONTAINER, LastVisitedNGRANCellInformation-ExtIEs
void __app_ngap_set_LastVisitedNGRANCellInformation_ExtIEs( SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs ** data)
{
	__si_amf_init_LastVisitedNGRANCellInformation_ExtIEs( data);
	SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs * lastVisitedNGRANCellInformation_ExtIEs = *data;
	
}


//-- OCTETSTRING, LastVisitedUTRANCellInformation
void __app_ngap_set_LastVisitedUTRANCellInformation( SI_AMF_DT_LastVisitedUTRANCellInformation ** data)
{
	__si_amf_init_LastVisitedUTRANCellInformation( data);
	SI_AMF_DT_LastVisitedUTRANCellInformation * lastVisitedUTRANCellInformation = *data;
	
	lastVisitedUTRANCellInformation->data = (unsigned char *) __si_allocM(0);
	lastVisitedUTRANCellInformation->length = 0;
	__si_core_fill_dummy_data( lastVisitedUTRANCellInformation->data, lastVisitedUTRANCellInformation->length);
}


//-- INTEGER, LocationReportingReferenceID
void __app_ngap_set_LocationReportingReferenceID( SI_AMF_DT_LocationReportingReferenceID ** data)
{
	SI_AMF_DT_LocationReportingReferenceID * locationReportingReferenceID = *data;
	
	//MIN = 1, MAX = 64
	locationReportingReferenceID->data = __si_core_getU64RANDRange( 1, 64);
}


//-- SEQUENCE, LocationReportingRequestType
void __app_ngap_set_LocationReportingRequestType( SI_AMF_DT_LocationReportingRequestType ** data)
{
	__si_amf_init_LocationReportingRequestType( data);
	SI_AMF_DT_LocationReportingRequestType * locationReportingRequestType = *data;
	
	locationReportingRequestType->selected_eeventType = 5;
	locationReportingRequestType->selected_ereportArea = 0;
	__app_ngap_set_AreaOfInterestList( &locationReportingRequestType->areaOfInterestList);
	locationReportingRequestType->isPresent_areaOfInterestList = 1;

	locationReportingRequestType->locationReportingReferenceIDToBeCancelled = __si_core_getU64RANDRange( 1, 64);
}


//-- CONTAINER, LocationReportingRequestType-ExtIEs
void __app_ngap_set_LocationReportingRequestType_ExtIEs( SI_AMF_DT_LocationReportingRequestType_ExtIEs ** data)
{
	__si_amf_init_LocationReportingRequestType_ExtIEs( data);
	SI_AMF_DT_LocationReportingRequestType_ExtIEs * locationReportingRequestType_ExtIEs = *data;
	
}


//-- BITSTRING, MaskedIMEISV
void __app_ngap_set_MaskedIMEISV( SI_AMF_DT_MaskedIMEISV ** data)
{
	__si_amf_init_MaskedIMEISV( data);
	SI_AMF_DT_MaskedIMEISV * maskedIMEISV = *data;
	
	//BITSIZE = 64  , BIT STRING(SIZE(64))
	maskedIMEISV->data = (unsigned char *) __si_allocM(9);
	maskedIMEISV->length = 9;
	maskedIMEISV->bitslen = 64;
	__si_core_fill_dummy_data( maskedIMEISV->data, maskedIMEISV->length);
}


//-- INTEGER, MaximumDataBurstVolume
void __app_ngap_set_MaximumDataBurstVolume( SI_AMF_DT_MaximumDataBurstVolume ** data)
{
	SI_AMF_DT_MaximumDataBurstVolume * maximumDataBurstVolume = *data;
	
	//MIN = 0, MAX = 4095
	maximumDataBurstVolume->data = __si_core_getU64RANDRange( 0, 4095);
}


//-- BITSTRING, MessageIdentifier
void __app_ngap_set_MessageIdentifier( SI_AMF_DT_MessageIdentifier ** data)
{
	__si_amf_init_MessageIdentifier( data);
	SI_AMF_DT_MessageIdentifier * messageIdentifier = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16))
	messageIdentifier->data = (unsigned char *) __si_allocM(3);
	messageIdentifier->length = 3;
	messageIdentifier->bitslen = 16;
	__si_core_fill_dummy_data( messageIdentifier->data, messageIdentifier->length);
}


//-- SEQUENCE, MobilityRestrictionList
void __app_ngap_set_MobilityRestrictionList( SI_AMF_DT_MobilityRestrictionList ** data)
{
	__si_amf_init_MobilityRestrictionList( data);
	SI_AMF_DT_MobilityRestrictionList * mobilityRestrictionList = *data;
	
	__app_ngap_set_PLMNIdentity( &mobilityRestrictionList->servingPLMN);

	__app_ngap_set_EquivalentPLMNs( &mobilityRestrictionList->equivalentPLMNs);
	mobilityRestrictionList->isPresent_equivalentPLMNs = 1;

	__app_ngap_set_RATRestrictions( &mobilityRestrictionList->rATRestrictions);
	mobilityRestrictionList->isPresent_rATRestrictions = 1;

	__app_ngap_set_ForbiddenAreaInformation( &mobilityRestrictionList->forbiddenAreaInformation);
	mobilityRestrictionList->isPresent_forbiddenAreaInformation = 1;

	__app_ngap_set_ServiceAreaInformation( &mobilityRestrictionList->serviceAreaInformation);
	mobilityRestrictionList->isPresent_serviceAreaInformation = 1;
}


//-- CONTAINER, MobilityRestrictionList-ExtIEs
void __app_ngap_set_MobilityRestrictionList_ExtIEs( SI_AMF_DT_MobilityRestrictionList_ExtIEs ** data)
{
	__si_amf_init_MobilityRestrictionList_ExtIEs( data);
	SI_AMF_DT_MobilityRestrictionList_ExtIEs * mobilityRestrictionList_ExtIEs = *data;
	
}


//-- BITSTRING, N3IWF-IDBS
void __app_ngap_set_N3IWF_IDBS( SI_AMF_DT_N3IWF_IDBS ** data)
{
	__si_amf_init_N3IWF_IDBS( data);
	SI_AMF_DT_N3IWF_IDBS * n3IWF_IDBS = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16))
	n3IWF_IDBS->data = (unsigned char *) __si_allocM(3);
	n3IWF_IDBS->length = 3;
	n3IWF_IDBS->bitslen = 16;
	__si_core_fill_dummy_data( n3IWF_IDBS->data, n3IWF_IDBS->length);
}


//-- CHOICE, N3IWF-ID
void __app_ngap_set_N3IWF_ID( SI_AMF_DT_N3IWF_ID ** data)
{
	__si_amf_init_N3IWF_ID( data);
	SI_AMF_DT_N3IWF_ID * n3IWF_ID = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_N3IWF_IDBS( &(*data)->u.n3IWF_ID);

}


//-- CONTAINER, N3IWF-ID-ExtIEs
void __app_ngap_set_N3IWF_ID_ExtIEs( SI_AMF_DT_N3IWF_ID_ExtIEs ** data)
{
	__si_amf_init_N3IWF_ID_ExtIEs( data);
	SI_AMF_DT_N3IWF_ID_ExtIEs * n3IWF_ID_ExtIEs = *data;
	
}


//-- OCTETSTRING, NAS-PDU
void __app_ngap_set_NAS_PDU( SI_AMF_DT_NAS_PDU ** data)
{
	__si_amf_init_NAS_PDU( data);
	SI_AMF_DT_NAS_PDU * nAS_PDU = *data;
	
	nAS_PDU->data = (unsigned char *) __si_allocM(0);
	nAS_PDU->length = 0;
	__si_core_fill_dummy_data( nAS_PDU->data, nAS_PDU->length);
}


//-- OCTETSTRING, NASSecurityParametersFromNGRAN
void __app_ngap_set_NASSecurityParametersFromNGRAN( SI_AMF_DT_NASSecurityParametersFromNGRAN ** data)
{
	__si_amf_init_NASSecurityParametersFromNGRAN( data);
	SI_AMF_DT_NASSecurityParametersFromNGRAN * nASSecurityParametersFromNGRAN = *data;
	
	nASSecurityParametersFromNGRAN->data = (unsigned char *) __si_allocM(0);
	nASSecurityParametersFromNGRAN->length = 0;
	__si_core_fill_dummy_data( nASSecurityParametersFromNGRAN->data, nASSecurityParametersFromNGRAN->length);
}


//-- INTEGER, NetworkInstance
void __app_ngap_set_NetworkInstance( SI_AMF_DT_NetworkInstance ** data)
{
	SI_AMF_DT_NetworkInstance * networkInstance = *data;
	
	//MIN = 1, MAX = 256
	networkInstance->data = __si_core_getU64RANDRange( 1, 256);
}


//-- INTEGER, NextHopChainingCount
void __app_ngap_set_NextHopChainingCount( SI_AMF_DT_NextHopChainingCount ** data)
{
	SI_AMF_DT_NextHopChainingCount * nextHopChainingCount = *data;
	
	//MIN = 0, MAX = 7
	nextHopChainingCount->data = __si_core_getU64RANDRange( 0, 7);
}


//-- BITSTRING, NgENB-IDmacroNgENB-ID
void __app_ngap_set_NgENB_IDmacroNgENB_ID( SI_AMF_DT_NgENB_IDmacroNgENB_ID ** data)
{
	__si_amf_init_NgENB_IDmacroNgENB_ID( data);
	SI_AMF_DT_NgENB_IDmacroNgENB_ID * ngENB_IDmacroNgENB_ID = *data;
	
	//BITSIZE = 20  , BIT STRING(SIZE(20))
	ngENB_IDmacroNgENB_ID->data = (unsigned char *) __si_allocM(4);
	ngENB_IDmacroNgENB_ID->length = 4;
	ngENB_IDmacroNgENB_ID->bitslen = 20;
	__si_core_fill_dummy_data( ngENB_IDmacroNgENB_ID->data, ngENB_IDmacroNgENB_ID->length);
}


//-- BITSTRING, NgENB-IDshortMacroNgENB-ID
void __app_ngap_set_NgENB_IDshortMacroNgENB_ID( SI_AMF_DT_NgENB_IDshortMacroNgENB_ID ** data)
{
	__si_amf_init_NgENB_IDshortMacroNgENB_ID( data);
	SI_AMF_DT_NgENB_IDshortMacroNgENB_ID * ngENB_IDshortMacroNgENB_ID = *data;
	
	//BITSIZE = 18  , BIT STRING(SIZE(18))
	ngENB_IDshortMacroNgENB_ID->data = (unsigned char *) __si_allocM(4);
	ngENB_IDshortMacroNgENB_ID->length = 4;
	ngENB_IDshortMacroNgENB_ID->bitslen = 18;
	__si_core_fill_dummy_data( ngENB_IDshortMacroNgENB_ID->data, ngENB_IDshortMacroNgENB_ID->length);
}


//-- BITSTRING, NgENB-IDlongMacroNgENB-ID
void __app_ngap_set_NgENB_IDlongMacroNgENB_ID( SI_AMF_DT_NgENB_IDlongMacroNgENB_ID ** data)
{
	__si_amf_init_NgENB_IDlongMacroNgENB_ID( data);
	SI_AMF_DT_NgENB_IDlongMacroNgENB_ID * ngENB_IDlongMacroNgENB_ID = *data;
	
	//BITSIZE = 21  , BIT STRING(SIZE(21))
	ngENB_IDlongMacroNgENB_ID->data = (unsigned char *) __si_allocM(4);
	ngENB_IDlongMacroNgENB_ID->length = 4;
	ngENB_IDlongMacroNgENB_ID->bitslen = 21;
	__si_core_fill_dummy_data( ngENB_IDlongMacroNgENB_ID->data, ngENB_IDlongMacroNgENB_ID->length);
}


//-- CHOICE, NgENB-ID
void __app_ngap_set_NgENB_ID( SI_AMF_DT_NgENB_ID ** data)
{
	__si_amf_init_NgENB_ID( data);
	SI_AMF_DT_NgENB_ID * ngENB_ID = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_NgENB_IDmacroNgENB_ID( &(*data)->u.macroNgENB_ID);

}


//-- CONTAINER, NgENB-ID-ExtIEs
void __app_ngap_set_NgENB_ID_ExtIEs( SI_AMF_DT_NgENB_ID_ExtIEs ** data)
{
	__si_amf_init_NgENB_ID_ExtIEs( data);
	SI_AMF_DT_NgENB_ID_ExtIEs * ngENB_ID_ExtIEs = *data;
	
}


//-- CHOICE, NGRAN-CGI
void __app_ngap_set_NGRAN_CGI( SI_AMF_DT_NGRAN_CGI ** data)
{
	__si_amf_init_NGRAN_CGI( data);
	SI_AMF_DT_NGRAN_CGI * nGRAN_CGI = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_NR_CGI( &(*data)->u.nR_CGI);

}


//-- CONTAINER, NGRAN-CGI-ExtIEs
void __app_ngap_set_NGRAN_CGI_ExtIEs( SI_AMF_DT_NGRAN_CGI_ExtIEs ** data)
{
	__si_amf_init_NGRAN_CGI_ExtIEs( data);
	SI_AMF_DT_NGRAN_CGI_ExtIEs * nGRAN_CGI_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, NGRAN-TNLAssociationToRemoveList
void __app_ngap_set_NGRAN_TNLAssociationToRemoveList( SI_AMF_DT_NGRAN_TNLAssociationToRemoveList ** data)
{
	__si_amf_init_NGRAN_TNLAssociationToRemoveList( data);
	SI_AMF_DT_NGRAN_TNLAssociationToRemoveList * nGRAN_TNLAssociationToRemoveList = *data;
	
	SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem * objItem = NULL;

	__app_ngap_set_NGRAN_TNLAssociationToRemoveItem( &objItem);
	__si_linked_list_add( (*data)->NGRAN_TNLAssociationToRemoveItem, (uint8_t *)objItem);
}


//-- SEQUENCE, NGRAN-TNLAssociationToRemoveItem
void __app_ngap_set_NGRAN_TNLAssociationToRemoveItem( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem ** data)
{
	__si_amf_init_NGRAN_TNLAssociationToRemoveItem( data);
	SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem * nGRAN_TNLAssociationToRemoveItem = *data;
	
	__app_ngap_set_CPTransportLayerInformation( &nGRAN_TNLAssociationToRemoveItem->tNLAssociationTransportLayerAddress);

	__app_ngap_set_CPTransportLayerInformation( &nGRAN_TNLAssociationToRemoveItem->tNLAssociationTransportLayerAddressAMF);
	nGRAN_TNLAssociationToRemoveItem->isPresent_tNLAssociationTransportLayerAddressAMF = 1;
}


//-- CONTAINER, NGRAN-TNLAssociationToRemoveItem-ExtIEs
void __app_ngap_set_NGRAN_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs ** data)
{
	__si_amf_init_NGRAN_TNLAssociationToRemoveItem_ExtIEs( data);
	SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs * nGRAN_TNLAssociationToRemoveItem_ExtIEs = *data;
	
}


//-- OCTETSTRING, NGRANTraceID
void __app_ngap_set_NGRANTraceID( SI_AMF_DT_NGRANTraceID ** data)
{
	__si_amf_init_NGRANTraceID( data);
	SI_AMF_DT_NGRANTraceID * nGRANTraceID = *data;
	
	nGRANTraceID->data = (unsigned char *) __si_allocM(8);
	nGRANTraceID->length = 8;
	__si_core_fill_dummy_data( nGRANTraceID->data, nGRANTraceID->length);
	memset( nGRANTraceID->data, 0, 3);
}


//-- SEQUENCE, NonDynamic5QIDescriptor
void __app_ngap_set_NonDynamic5QIDescriptor( SI_AMF_DT_NonDynamic5QIDescriptor ** data)
{
	__si_amf_init_NonDynamic5QIDescriptor( data);
	SI_AMF_DT_NonDynamic5QIDescriptor * nonDynamic5QIDescriptor = *data;
	
	nonDynamic5QIDescriptor->fiveQI = __si_core_getU64RANDRange( 0, 255);
	nonDynamic5QIDescriptor->priorityLevelQos = __si_core_getU64RANDRange( 1, 127);
	nonDynamic5QIDescriptor->averagingWindow = __si_core_getU64RANDRange( 0, 4095);
	nonDynamic5QIDescriptor->maximumDataBurstVolume = __si_core_getU64RANDRange( 0, 4095);
}


//-- CONTAINER, NonDynamic5QIDescriptor-ExtIEs
void __app_ngap_set_NonDynamic5QIDescriptor_ExtIEs( SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs ** data)
{
	__si_amf_init_NonDynamic5QIDescriptor_ExtIEs( data);
	SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs * nonDynamic5QIDescriptor_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, NotAllowedTACs
void __app_ngap_set_NotAllowedTACs( SI_AMF_DT_NotAllowedTACs ** data)
{
	__si_amf_init_NotAllowedTACs( data);
	SI_AMF_DT_NotAllowedTACs * notAllowedTACs = *data;
	
	SI_AMF_DT_TAC * objItem = NULL;

	__app_ngap_set_TAC( &objItem);
	__si_linked_list_add( (*data)->TAC, (uint8_t *)objItem);
}


//-- BITSTRING, NRCellIdentity
void __app_ngap_set_NRCellIdentity( SI_AMF_DT_NRCellIdentity ** data)
{
	__si_amf_init_NRCellIdentity( data);
	SI_AMF_DT_NRCellIdentity * nRCellIdentity = *data;
	
	//BITSIZE = 36  , BIT STRING(SIZE(36))
	nRCellIdentity->data = (unsigned char *) __si_allocM(6);
	nRCellIdentity->length = 6;
	nRCellIdentity->bitslen = 36;
	__si_core_fill_dummy_data( nRCellIdentity->data, nRCellIdentity->length);
}


//-- SEQUENCE, NR-CGI
void __app_ngap_set_NR_CGI( SI_AMF_DT_NR_CGI ** data)
{
	__si_amf_init_NR_CGI( data);
	SI_AMF_DT_NR_CGI * nR_CGI = *data;
	
	__app_ngap_set_PLMNIdentity( &nR_CGI->pLMNIdentity);

	__app_ngap_set_NRCellIdentity( &nR_CGI->nRCellIdentity);
}


//-- CONTAINER, NR-CGI-ExtIEs
void __app_ngap_set_NR_CGI_ExtIEs( SI_AMF_DT_NR_CGI_ExtIEs ** data)
{
	__si_amf_init_NR_CGI_ExtIEs( data);
	SI_AMF_DT_NR_CGI_ExtIEs * nR_CGI_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, NR-CGIList
void __app_ngap_set_NR_CGIList( SI_AMF_DT_NR_CGIList ** data)
{
	__si_amf_init_NR_CGIList( data);
	SI_AMF_DT_NR_CGIList * nR_CGIList = *data;
	
	SI_AMF_DT_NR_CGI * objItem = NULL;

	__app_ngap_set_NR_CGI( &objItem);
	__si_linked_list_add( (*data)->NR_CGI, (uint8_t *)objItem);
}


//-- SEQUENCE_OF, NR-CGIListForWarning
void __app_ngap_set_NR_CGIListForWarning( SI_AMF_DT_NR_CGIListForWarning ** data)
{
	__si_amf_init_NR_CGIListForWarning( data);
	SI_AMF_DT_NR_CGIListForWarning * nR_CGIListForWarning = *data;
	
	SI_AMF_DT_NR_CGI * objItem = NULL;

	__app_ngap_set_NR_CGI( &objItem);
	__si_linked_list_add( (*data)->NR_CGI, (uint8_t *)objItem);
}


//-- BITSTRING, NRencryptionAlgorithms
void __app_ngap_set_NRencryptionAlgorithms( SI_AMF_DT_NRencryptionAlgorithms ** data)
{
	__si_amf_init_NRencryptionAlgorithms( data);
	SI_AMF_DT_NRencryptionAlgorithms * nRencryptionAlgorithms = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16,...))
	nRencryptionAlgorithms->data = (unsigned char *) __si_allocM(3);
	nRencryptionAlgorithms->length = 3;
	nRencryptionAlgorithms->bitslen = 16;
	memset( nRencryptionAlgorithms->data, 0, 3);
	//__si_core_fill_dummy_data( nRencryptionAlgorithms->data, nRencryptionAlgorithms->length);
}


//-- BITSTRING, NRintegrityProtectionAlgorithms
void __app_ngap_set_NRintegrityProtectionAlgorithms( SI_AMF_DT_NRintegrityProtectionAlgorithms ** data)
{
	__si_amf_init_NRintegrityProtectionAlgorithms( data);
	SI_AMF_DT_NRintegrityProtectionAlgorithms * nRintegrityProtectionAlgorithms = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16,...))
	nRintegrityProtectionAlgorithms->data = (unsigned char *) __si_allocM(3);
	nRintegrityProtectionAlgorithms->length = 3;
	nRintegrityProtectionAlgorithms->bitslen = 16;
	//__si_core_fill_dummy_data( nRintegrityProtectionAlgorithms->data, nRintegrityProtectionAlgorithms->length);
	memset( nRintegrityProtectionAlgorithms->data, 0, 3);
}


//-- OCTETSTRING, NRPPa-PDU
void __app_ngap_set_NRPPa_PDU( SI_AMF_DT_NRPPa_PDU ** data)
{
	__si_amf_init_NRPPa_PDU( data);
	SI_AMF_DT_NRPPa_PDU * nRPPa_PDU = *data;
	
	nRPPa_PDU->data = (unsigned char *) __si_allocM(0);
	nRPPa_PDU->length = 0;
	__si_core_fill_dummy_data( nRPPa_PDU->data, nRPPa_PDU->length);
}


//-- INTEGER, NumberOfBroadcasts
void __app_ngap_set_NumberOfBroadcasts( SI_AMF_DT_NumberOfBroadcasts ** data)
{
	SI_AMF_DT_NumberOfBroadcasts * numberOfBroadcasts = *data;
	
	//MIN = 0, MAX = 65535
	numberOfBroadcasts->data = __si_core_getU64RANDRange( 0, 65535);
}


//-- INTEGER, NumberOfBroadcastsRequested
void __app_ngap_set_NumberOfBroadcastsRequested( SI_AMF_DT_NumberOfBroadcastsRequested ** data)
{
	SI_AMF_DT_NumberOfBroadcastsRequested * numberOfBroadcastsRequested = *data;
	
	//MIN = 0, MAX = 65535
	numberOfBroadcastsRequested->data = __si_core_getU64RANDRange( 0, 65535);
}


//-- CHOICE, OverloadResponse
void __app_ngap_set_OverloadResponse( SI_AMF_DT_OverloadResponse ** data)
{
	__si_amf_init_OverloadResponse( data);
	SI_AMF_DT_OverloadResponse * overloadResponse = *data;
	
	(*data)->SelectedChoice = 0;

	(*data)->u.overloadAction = 0;

}


//-- CONTAINER, OverloadResponse-ExtIEs
void __app_ngap_set_OverloadResponse_ExtIEs( SI_AMF_DT_OverloadResponse_ExtIEs ** data)
{
	__si_amf_init_OverloadResponse_ExtIEs( data);
	SI_AMF_DT_OverloadResponse_ExtIEs * overloadResponse_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, OverloadStartNSSAIList
void __app_ngap_set_OverloadStartNSSAIList( SI_AMF_DT_OverloadStartNSSAIList ** data)
{
	__si_amf_init_OverloadStartNSSAIList( data);
	SI_AMF_DT_OverloadStartNSSAIList * overloadStartNSSAIList = *data;
	
	SI_AMF_DT_OverloadStartNSSAIItem * objItem = NULL;

	__app_ngap_set_OverloadStartNSSAIItem( &objItem);
	__si_linked_list_add( (*data)->OverloadStartNSSAIItem, (uint8_t *)objItem);
}


//-- SEQUENCE, OverloadStartNSSAIItem
void __app_ngap_set_OverloadStartNSSAIItem( SI_AMF_DT_OverloadStartNSSAIItem ** data)
{
	__si_amf_init_OverloadStartNSSAIItem( data);
	SI_AMF_DT_OverloadStartNSSAIItem * overloadStartNSSAIItem = *data;
	
	__app_ngap_set_SliceOverloadList( &overloadStartNSSAIItem->sliceOverloadList);

	__app_ngap_set_OverloadResponse( &overloadStartNSSAIItem->sliceOverloadResponse);
	overloadStartNSSAIItem->isPresent_sliceOverloadResponse = 1;

	overloadStartNSSAIItem->sliceTrafficLoadReductionIndication = __si_core_getU64RANDRange( 1, 99);
}


//-- CONTAINER, OverloadStartNSSAIItem-ExtIEs
void __app_ngap_set_OverloadStartNSSAIItem_ExtIEs( SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs ** data)
{
	__si_amf_init_OverloadStartNSSAIItem_ExtIEs( data);
	SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs * overloadStartNSSAIItem_ExtIEs = *data;
	
}


//-- INTEGER, PacketDelayBudget
void __app_ngap_set_PacketDelayBudget( SI_AMF_DT_PacketDelayBudget ** data)
{
	SI_AMF_DT_PacketDelayBudget * packetDelayBudget = *data;
	
	//MIN = 0, MAX = 1023
	packetDelayBudget->data = __si_core_getU64RANDRange( 0, 1023);
}


//-- INTEGER, PacketErrorRateInt
void __app_ngap_set_PacketErrorRateInt( SI_AMF_DT_PacketErrorRateInt ** data)
{
	SI_AMF_DT_PacketErrorRateInt * packetErrorRateInt = *data;
	
	//MIN = 0, MAX = 9
	packetErrorRateInt->data = __si_core_getU64RANDRange( 0, 9);
}


//-- SEQUENCE, PacketErrorRate
void __app_ngap_set_PacketErrorRate( SI_AMF_DT_PacketErrorRate ** data)
{
	__si_amf_init_PacketErrorRate( data);
	SI_AMF_DT_PacketErrorRate * packetErrorRate = *data;
	
	packetErrorRate->pERScalar = __si_core_getU64RANDRange( 0, 9);
	packetErrorRate->pERExponent = __si_core_getU64RANDRange( 0, 9);
}


//-- CONTAINER, PacketErrorRate-ExtIEs
void __app_ngap_set_PacketErrorRate_ExtIEs( SI_AMF_DT_PacketErrorRate_ExtIEs ** data)
{
	__si_amf_init_PacketErrorRate_ExtIEs( data);
	SI_AMF_DT_PacketErrorRate_ExtIEs * packetErrorRate_ExtIEs = *data;
	
}


//-- INTEGER, PacketLossRate
void __app_ngap_set_PacketLossRate( SI_AMF_DT_PacketLossRate ** data)
{
	SI_AMF_DT_PacketLossRate * packetLossRate = *data;
	
	//MIN = 0, MAX = 1000
	packetLossRate->data = __si_core_getU64RANDRange( 0, 1000);
}



//-- SEQUENCE, PagingAttemptInformation
void __app_ngap_set_PagingAttemptInformation( SI_AMF_DT_PagingAttemptInformation ** data)
{
	__si_amf_init_PagingAttemptInformation( data);
	SI_AMF_DT_PagingAttemptInformation * pagingAttemptInformation = *data;
	
	pagingAttemptInformation->pagingAttemptCount = __si_core_getU64RANDRange( 1, 16);
	pagingAttemptInformation->intendedNumberOfPagingAttempts = __si_core_getU64RANDRange( 1, 16);
	pagingAttemptInformation->selected_enextPagingAreaScope = 1;
}



//-- CONTAINER, PagingAttemptInformation-ExtIEs
void __app_ngap_set_PagingAttemptInformation_ExtIEs( SI_AMF_DT_PagingAttemptInformation_ExtIEs ** data)
{
	__si_amf_init_PagingAttemptInformation_ExtIEs( data);
	SI_AMF_DT_PagingAttemptInformation_ExtIEs * pagingAttemptInformation_ExtIEs = *data;
	
}


//-- INTEGER, PagingAttemptCount
void __app_ngap_set_PagingAttemptCount( SI_AMF_DT_PagingAttemptCount ** data)
{
	SI_AMF_DT_PagingAttemptCount * pagingAttemptCount = *data;
	
	//MIN = 1, MAX = 16
	pagingAttemptCount->data = __si_core_getU64RANDRange( 1, 16);
}


//-- SEQUENCE, PathSwitchRequestAcknowledgeTransfer
void __app_ngap_set_PathSwitchRequestAcknowledgeTransfer( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer ** data)
{
	__si_amf_init_PathSwitchRequestAcknowledgeTransfer( data);
	SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer * pathSwitchRequestAcknowledgeTransfer = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &pathSwitchRequestAcknowledgeTransfer->uL_NGU_UP_TNLInformation);
	pathSwitchRequestAcknowledgeTransfer->isPresent_uL_NGU_UP_TNLInformation = 1;

	__app_ngap_set_SecurityIndication( &pathSwitchRequestAcknowledgeTransfer->securityIndication);
	pathSwitchRequestAcknowledgeTransfer->isPresent_securityIndication = 1;
}


//-- CONTAINER, PathSwitchRequestAcknowledgeTransfer-ExtIEs
void __app_ngap_set_PathSwitchRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs ** data)
{
	__si_amf_init_PathSwitchRequestAcknowledgeTransfer_ExtIEs( data);
	SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs * pathSwitchRequestAcknowledgeTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PathSwitchRequestSetupFailedTransfer
void __app_ngap_set_PathSwitchRequestSetupFailedTransfer( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer ** data)
{
	__si_amf_init_PathSwitchRequestSetupFailedTransfer( data);
	SI_AMF_DT_PathSwitchRequestSetupFailedTransfer * pathSwitchRequestSetupFailedTransfer = *data;
	
	__app_ngap_set_Cause( &pathSwitchRequestSetupFailedTransfer->cause);
}


//-- CONTAINER, PathSwitchRequestSetupFailedTransfer-ExtIEs
void __app_ngap_set_PathSwitchRequestSetupFailedTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs ** data)
{
	__si_amf_init_PathSwitchRequestSetupFailedTransfer_ExtIEs( data);
	SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs * pathSwitchRequestSetupFailedTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PathSwitchRequestTransfer
void __app_ngap_set_PathSwitchRequestTransfer( SI_AMF_DT_PathSwitchRequestTransfer ** data)
{
	__si_amf_init_PathSwitchRequestTransfer( data);
	SI_AMF_DT_PathSwitchRequestTransfer * pathSwitchRequestTransfer = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &pathSwitchRequestTransfer->dL_NGU_UP_TNLInformation);

	pathSwitchRequestTransfer->selected_edL_NGU_TNLInformationReused = 0;
	__app_ngap_set_UserPlaneSecurityInformation( &pathSwitchRequestTransfer->userPlaneSecurityInformation);
	pathSwitchRequestTransfer->isPresent_userPlaneSecurityInformation = 1;

	__app_ngap_set_QosFlowAcceptedList( &pathSwitchRequestTransfer->qosFlowAcceptedList);
}


//-- CONTAINER, PathSwitchRequestTransfer-ExtIEs
void __app_ngap_set_PathSwitchRequestTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs ** data)
{
	__si_amf_init_PathSwitchRequestTransfer_ExtIEs( data);
	SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs * pathSwitchRequestTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PathSwitchRequestUnsuccessfulTransfer
void __app_ngap_set_PathSwitchRequestUnsuccessfulTransfer( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer ** data)
{
	__si_amf_init_PathSwitchRequestUnsuccessfulTransfer( data);
	SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer * pathSwitchRequestUnsuccessfulTransfer = *data;
	
	__app_ngap_set_Cause( &pathSwitchRequestUnsuccessfulTransfer->cause);
}


//-- CONTAINER, PathSwitchRequestUnsuccessfulTransfer-ExtIEs
void __app_ngap_set_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs ** data)
{
	__si_amf_init_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( data);
	SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs * pathSwitchRequestUnsuccessfulTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionAggregateMaximumBitRate
void __app_ngap_set_PDUSessionAggregateMaximumBitRate( SI_AMF_DT_PDUSessionAggregateMaximumBitRate ** data)
{
	__si_amf_init_PDUSessionAggregateMaximumBitRate( data);
	SI_AMF_DT_PDUSessionAggregateMaximumBitRate * pDUSessionAggregateMaximumBitRate = *data;
	
	pDUSessionAggregateMaximumBitRate->pDUSessionAggregateMaximumBitRateDL = __si_core_getU64RANDRange( 0, 4000000000000);
	pDUSessionAggregateMaximumBitRate->pDUSessionAggregateMaximumBitRateUL = __si_core_getU64RANDRange( 0, 4000000000000);
}


//-- CONTAINER, PDUSessionAggregateMaximumBitRate-ExtIEs
void __app_ngap_set_PDUSessionAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs ** data)
{
	__si_amf_init_PDUSessionAggregateMaximumBitRate_ExtIEs( data);
	SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs * pDUSessionAggregateMaximumBitRate_ExtIEs = *data;
	
}


//-- INTEGER, PDUSessionID
void __app_ngap_set_PDUSessionID( SI_AMF_DT_PDUSessionID ** data)
{
	SI_AMF_DT_PDUSessionID * pDUSessionID = *data;
	
	//MIN = 0, MAX = 255
	pDUSessionID->data = __si_core_getU64RANDRange( 0, 255);
}


//-- SEQUENCE_OF, PDUSessionResourceAdmittedList
void __app_ngap_set_PDUSessionResourceAdmittedList( SI_AMF_DT_PDUSessionResourceAdmittedList ** data)
{
	__si_amf_init_PDUSessionResourceAdmittedList( data);
	SI_AMF_DT_PDUSessionResourceAdmittedList * pDUSessionResourceAdmittedList = *data;
	
	SI_AMF_DT_PDUSessionResourceAdmittedItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceAdmittedItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceAdmittedItem, (uint8_t *)objItem);
}


//-- OCTETSTRING, HandoverRequestAcknowledgeTransferOctStr
void __app_ngap_set_HandoverRequestAcknowledgeTransferOctStr( SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr ** data)
{
	__si_amf_init_HandoverRequestAcknowledgeTransferOctStr( data);
	SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr * handoverRequestAcknowledgeTransferOctStr = *data;
	
	handoverRequestAcknowledgeTransferOctStr->data = (unsigned char *) __si_allocM(0);
	handoverRequestAcknowledgeTransferOctStr->length = 0;
	__si_core_fill_dummy_data( handoverRequestAcknowledgeTransferOctStr->data, handoverRequestAcknowledgeTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceAdmittedItem
void __app_ngap_set_PDUSessionResourceAdmittedItem( SI_AMF_DT_PDUSessionResourceAdmittedItem ** data)
{
	__si_amf_init_PDUSessionResourceAdmittedItem( data);
	SI_AMF_DT_PDUSessionResourceAdmittedItem * pDUSessionResourceAdmittedItem = *data;
	
	pDUSessionResourceAdmittedItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_HandoverRequestAcknowledgeTransferOctStr( &pDUSessionResourceAdmittedItem->handoverRequestAcknowledgeTransfer);
}


//-- CONTAINER, PDUSessionResourceAdmittedItem-ExtIEs
void __app_ngap_set_PDUSessionResourceAdmittedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceAdmittedItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs * pDUSessionResourceAdmittedItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToModifyListModCfm
void __app_ngap_set_PDUSessionResourceFailedToModifyListModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm ** data)
{
	__si_amf_init_PDUSessionResourceFailedToModifyListModCfm( data);
	SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm * pDUSessionResourceFailedToModifyListModCfm = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToModifyItemModCfm( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToModifyItemModCfm, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr
void __app_ngap_set_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr * pDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr = *data;
	
	pDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr->data, pDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceFailedToModifyItemModCfm
void __app_ngap_set_PDUSessionResourceFailedToModifyItemModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm ** data)
{
	__si_amf_init_PDUSessionResourceFailedToModifyItemModCfm( data);
	SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm * pDUSessionResourceFailedToModifyItemModCfm = *data;
	
	pDUSessionResourceFailedToModifyItemModCfm->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( &pDUSessionResourceFailedToModifyItemModCfm->pDUSessionResourceModifyIndicationUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToModifyItemModCfm-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs * pDUSessionResourceFailedToModifyItemModCfm_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToModifyListModRes
void __app_ngap_set_PDUSessionResourceFailedToModifyListModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes ** data)
{
	__si_amf_init_PDUSessionResourceFailedToModifyListModRes( data);
	SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes * pDUSessionResourceFailedToModifyListModRes = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToModifyItemModRes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToModifyItemModRes, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceModifyUnsuccessfulTransferOctStr
void __app_ngap_set_PDUSessionResourceModifyUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceModifyUnsuccessfulTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr * pDUSessionResourceModifyUnsuccessfulTransferOctStr = *data;
	
	pDUSessionResourceModifyUnsuccessfulTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceModifyUnsuccessfulTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceModifyUnsuccessfulTransferOctStr->data, pDUSessionResourceModifyUnsuccessfulTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceFailedToModifyItemModRes
void __app_ngap_set_PDUSessionResourceFailedToModifyItemModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes ** data)
{
	__si_amf_init_PDUSessionResourceFailedToModifyItemModRes( data);
	SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes * pDUSessionResourceFailedToModifyItemModRes = *data;
	
	pDUSessionResourceFailedToModifyItemModRes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceModifyUnsuccessfulTransferOctStr( &pDUSessionResourceFailedToModifyItemModRes->pDUSessionResourceModifyUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToModifyItemModRes-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs * pDUSessionResourceFailedToModifyItemModRes_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToSetupListCxtFail
void __app_ngap_set_PDUSessionResourceFailedToSetupListCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupListCxtFail( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail * pDUSessionResourceFailedToSetupListCxtFail = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToSetupItemCxtFail( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToSetupItemCxtFail, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceSetupUnsuccessfulTransferOctStr
void __app_ngap_set_PDUSessionResourceSetupUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceSetupUnsuccessfulTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * pDUSessionResourceSetupUnsuccessfulTransferOctStr = *data;
	
	pDUSessionResourceSetupUnsuccessfulTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceSetupUnsuccessfulTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceSetupUnsuccessfulTransferOctStr->data, pDUSessionResourceSetupUnsuccessfulTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceFailedToSetupItemCxtFail
void __app_ngap_set_PDUSessionResourceFailedToSetupItemCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemCxtFail( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail * pDUSessionResourceFailedToSetupItemCxtFail = *data;
	
	pDUSessionResourceFailedToSetupItemCxtFail->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceSetupUnsuccessfulTransferOctStr( &pDUSessionResourceFailedToSetupItemCxtFail->pDUSessionResourceSetupUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToSetupItemCxtFail-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs * pDUSessionResourceFailedToSetupItemCxtFail_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToSetupListCxtRes
void __app_ngap_set_PDUSessionResourceFailedToSetupListCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupListCxtRes( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes * pDUSessionResourceFailedToSetupListCxtRes = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToSetupItemCxtRes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToSetupItemCxtRes, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceFailedToSetupItemCxtRes
void __app_ngap_set_PDUSessionResourceFailedToSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemCxtRes( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes * pDUSessionResourceFailedToSetupItemCxtRes = *data;
	
	pDUSessionResourceFailedToSetupItemCxtRes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceSetupUnsuccessfulTransferOctStr( &pDUSessionResourceFailedToSetupItemCxtRes->pDUSessionResourceSetupUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToSetupItemCxtRes-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs * pDUSessionResourceFailedToSetupItemCxtRes_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToSetupListHOAck
void __app_ngap_set_PDUSessionResourceFailedToSetupListHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupListHOAck( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck * pDUSessionResourceFailedToSetupListHOAck = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToSetupItemHOAck( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToSetupItemHOAck, (uint8_t *)objItem);
}


//-- OCTETSTRING, HandoverResourceAllocationUnsuccessfulTransferOctStr
void __app_ngap_set_HandoverResourceAllocationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr ** data)
{
	__si_amf_init_HandoverResourceAllocationUnsuccessfulTransferOctStr( data);
	SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr * handoverResourceAllocationUnsuccessfulTransferOctStr = *data;
	
	handoverResourceAllocationUnsuccessfulTransferOctStr->data = (unsigned char *) __si_allocM(0);
	handoverResourceAllocationUnsuccessfulTransferOctStr->length = 0;
	__si_core_fill_dummy_data( handoverResourceAllocationUnsuccessfulTransferOctStr->data, handoverResourceAllocationUnsuccessfulTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceFailedToSetupItemHOAck
void __app_ngap_set_PDUSessionResourceFailedToSetupItemHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemHOAck( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck * pDUSessionResourceFailedToSetupItemHOAck = *data;
	
	pDUSessionResourceFailedToSetupItemHOAck->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_HandoverResourceAllocationUnsuccessfulTransferOctStr( &pDUSessionResourceFailedToSetupItemHOAck->handoverResourceAllocationUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToSetupItemHOAck-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs * pDUSessionResourceFailedToSetupItemHOAck_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToSetupListPSReq
void __app_ngap_set_PDUSessionResourceFailedToSetupListPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupListPSReq( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq * pDUSessionResourceFailedToSetupListPSReq = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToSetupItemPSReq( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToSetupItemPSReq, (uint8_t *)objItem);
}


//-- OCTETSTRING, PathSwitchRequestSetupFailedTransferOctStr
void __app_ngap_set_PathSwitchRequestSetupFailedTransferOctStr( SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr ** data)
{
	__si_amf_init_PathSwitchRequestSetupFailedTransferOctStr( data);
	SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr * pathSwitchRequestSetupFailedTransferOctStr = *data;
	
	pathSwitchRequestSetupFailedTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pathSwitchRequestSetupFailedTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pathSwitchRequestSetupFailedTransferOctStr->data, pathSwitchRequestSetupFailedTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceFailedToSetupItemPSReq
void __app_ngap_set_PDUSessionResourceFailedToSetupItemPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemPSReq( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq * pDUSessionResourceFailedToSetupItemPSReq = *data;
	
	pDUSessionResourceFailedToSetupItemPSReq->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PathSwitchRequestSetupFailedTransferOctStr( &pDUSessionResourceFailedToSetupItemPSReq->pathSwitchRequestSetupFailedTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToSetupItemPSReq-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs * pDUSessionResourceFailedToSetupItemPSReq_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceFailedToSetupListSURes
void __app_ngap_set_PDUSessionResourceFailedToSetupListSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupListSURes( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes * pDUSessionResourceFailedToSetupListSURes = *data;
	
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceFailedToSetupItemSURes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceFailedToSetupItemSURes, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceFailedToSetupItemSURes
void __app_ngap_set_PDUSessionResourceFailedToSetupItemSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemSURes( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes * pDUSessionResourceFailedToSetupItemSURes = *data;
	
	pDUSessionResourceFailedToSetupItemSURes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceSetupUnsuccessfulTransferOctStr( &pDUSessionResourceFailedToSetupItemSURes->pDUSessionResourceSetupUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceFailedToSetupItemSURes-ExtIEs
void __app_ngap_set_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs * pDUSessionResourceFailedToSetupItemSURes_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceHandoverList
void __app_ngap_set_PDUSessionResourceHandoverList( SI_AMF_DT_PDUSessionResourceHandoverList ** data)
{
	__si_amf_init_PDUSessionResourceHandoverList( data);
	SI_AMF_DT_PDUSessionResourceHandoverList * pDUSessionResourceHandoverList = *data;
	
	SI_AMF_DT_PDUSessionResourceHandoverItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceHandoverItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceHandoverItem, (uint8_t *)objItem);
}


//-- OCTETSTRING, HandoverCommandTransferOctStr
void __app_ngap_set_HandoverCommandTransferOctStr( SI_AMF_DT_HandoverCommandTransferOctStr ** data)
{
	__si_amf_init_HandoverCommandTransferOctStr( data);
	SI_AMF_DT_HandoverCommandTransferOctStr * handoverCommandTransferOctStr = *data;
	
	handoverCommandTransferOctStr->data = (unsigned char *) __si_allocM(0);
	handoverCommandTransferOctStr->length = 0;
	__si_core_fill_dummy_data( handoverCommandTransferOctStr->data, handoverCommandTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceHandoverItem
void __app_ngap_set_PDUSessionResourceHandoverItem( SI_AMF_DT_PDUSessionResourceHandoverItem ** data)
{
	__si_amf_init_PDUSessionResourceHandoverItem( data);
	SI_AMF_DT_PDUSessionResourceHandoverItem * pDUSessionResourceHandoverItem = *data;
	
	pDUSessionResourceHandoverItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_HandoverCommandTransferOctStr( &pDUSessionResourceHandoverItem->handoverCommandTransfer);
}


//-- CONTAINER, PDUSessionResourceHandoverItem-ExtIEs
void __app_ngap_set_PDUSessionResourceHandoverItem_ExtIEs( SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceHandoverItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs * pDUSessionResourceHandoverItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceInformationList
void __app_ngap_set_PDUSessionResourceInformationList( SI_AMF_DT_PDUSessionResourceInformationList ** data)
{
	__si_amf_init_PDUSessionResourceInformationList( data);
	SI_AMF_DT_PDUSessionResourceInformationList * pDUSessionResourceInformationList = *data;
	
	SI_AMF_DT_PDUSessionResourceInformationItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceInformationItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceInformationItem, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceInformationItem
void __app_ngap_set_PDUSessionResourceInformationItem( SI_AMF_DT_PDUSessionResourceInformationItem ** data)
{
	__si_amf_init_PDUSessionResourceInformationItem( data);
	SI_AMF_DT_PDUSessionResourceInformationItem * pDUSessionResourceInformationItem = *data;
	
	pDUSessionResourceInformationItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_QosFlowInformationList( &pDUSessionResourceInformationItem->qosFlowInformationList);

	__app_ngap_set_DRBsToQosFlowsMappingList( &pDUSessionResourceInformationItem->dRBsToQosFlowsMappingList);
	pDUSessionResourceInformationItem->isPresent_dRBsToQosFlowsMappingList = 1;
}


//-- CONTAINER, PDUSessionResourceInformationItem-ExtIEs
void __app_ngap_set_PDUSessionResourceInformationItem_ExtIEs( SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceInformationItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs * pDUSessionResourceInformationItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceListCxtRelCpl
void __app_ngap_set_PDUSessionResourceListCxtRelCpl( SI_AMF_DT_PDUSessionResourceListCxtRelCpl ** data)
{
	__si_amf_init_PDUSessionResourceListCxtRelCpl( data);
	SI_AMF_DT_PDUSessionResourceListCxtRelCpl * pDUSessionResourceListCxtRelCpl = *data;
	
	SI_AMF_DT_PDUSessionResourceItemCxtRelCpl * objItem = NULL;

	__app_ngap_set_PDUSessionResourceItemCxtRelCpl( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceItemCxtRelCpl, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceItemCxtRelCpl
void __app_ngap_set_PDUSessionResourceItemCxtRelCpl( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl ** data)
{
	__si_amf_init_PDUSessionResourceItemCxtRelCpl( data);
	SI_AMF_DT_PDUSessionResourceItemCxtRelCpl * pDUSessionResourceItemCxtRelCpl = *data;
	
	pDUSessionResourceItemCxtRelCpl->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
}


//-- OCTETSTRING, PDUSessionResourceReleaseResponseTransferOctStr
void __app_ngap_set_PDUSessionResourceReleaseResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceReleaseResponseTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr * pDUSessionResourceReleaseResponseTransferOctStr = *data;
	
	pDUSessionResourceReleaseResponseTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceReleaseResponseTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceReleaseResponseTransferOctStr->data, pDUSessionResourceReleaseResponseTransferOctStr->length);
}


//-- CONTAINER, PDUSessionResourceItemCxtRelCpl-ExtIEs
void __app_ngap_set_PDUSessionResourceItemCxtRelCpl_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceItemCxtRelCpl_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs * pDUSessionResourceItemCxtRelCpl_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceListCxtRelReq
void __app_ngap_set_PDUSessionResourceListCxtRelReq( SI_AMF_DT_PDUSessionResourceListCxtRelReq ** data)
{
	__si_amf_init_PDUSessionResourceListCxtRelReq( data);
	SI_AMF_DT_PDUSessionResourceListCxtRelReq * pDUSessionResourceListCxtRelReq = *data;
	
	SI_AMF_DT_PDUSessionResourceItemCxtRelReq * objItem = NULL;

	__app_ngap_set_PDUSessionResourceItemCxtRelReq( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceItemCxtRelReq, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceItemCxtRelReq
void __app_ngap_set_PDUSessionResourceItemCxtRelReq( SI_AMF_DT_PDUSessionResourceItemCxtRelReq ** data)
{
	__si_amf_init_PDUSessionResourceItemCxtRelReq( data);
	SI_AMF_DT_PDUSessionResourceItemCxtRelReq * pDUSessionResourceItemCxtRelReq = *data;
	
	pDUSessionResourceItemCxtRelReq->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
}


//-- CONTAINER, PDUSessionResourceItemCxtRelReq-ExtIEs
void __app_ngap_set_PDUSessionResourceItemCxtRelReq_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceItemCxtRelReq_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs * pDUSessionResourceItemCxtRelReq_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceListHORqd
void __app_ngap_set_PDUSessionResourceListHORqd( SI_AMF_DT_PDUSessionResourceListHORqd ** data)
{
	__si_amf_init_PDUSessionResourceListHORqd( data);
	SI_AMF_DT_PDUSessionResourceListHORqd * pDUSessionResourceListHORqd = *data;
	
	SI_AMF_DT_PDUSessionResourceItemHORqd * objItem = NULL;

	__app_ngap_set_PDUSessionResourceItemHORqd( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceItemHORqd, (uint8_t *)objItem);
}


//-- OCTETSTRING, HandoverRequiredTransferOctStr
void __app_ngap_set_HandoverRequiredTransferOctStr( SI_AMF_DT_HandoverRequiredTransferOctStr ** data)
{
	__si_amf_init_HandoverRequiredTransferOctStr( data);
	SI_AMF_DT_HandoverRequiredTransferOctStr * handoverRequiredTransferOctStr = *data;
	
	handoverRequiredTransferOctStr->data = (unsigned char *) __si_allocM(0);
	handoverRequiredTransferOctStr->length = 0;
	__si_core_fill_dummy_data( handoverRequiredTransferOctStr->data, handoverRequiredTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceItemHORqd
void __app_ngap_set_PDUSessionResourceItemHORqd( SI_AMF_DT_PDUSessionResourceItemHORqd ** data)
{
	__si_amf_init_PDUSessionResourceItemHORqd( data);
	SI_AMF_DT_PDUSessionResourceItemHORqd * pDUSessionResourceItemHORqd = *data;
	
	pDUSessionResourceItemHORqd->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_HandoverRequiredTransferOctStr( &pDUSessionResourceItemHORqd->handoverRequiredTransfer);
}


//-- CONTAINER, PDUSessionResourceItemHORqd-ExtIEs
void __app_ngap_set_PDUSessionResourceItemHORqd_ExtIEs( SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceItemHORqd_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs * pDUSessionResourceItemHORqd_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceModifyConfirmTransfer
void __app_ngap_set_PDUSessionResourceModifyConfirmTransfer( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer ** data)
{
	__si_amf_init_PDUSessionResourceModifyConfirmTransfer( data);
	SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer * pDUSessionResourceModifyConfirmTransfer = *data;
	
	__app_ngap_set_QosFlowModifyConfirmList( &pDUSessionResourceModifyConfirmTransfer->qosFlowModifyConfirmList);

	__app_ngap_set_UPTransportLayerInformation( &pDUSessionResourceModifyConfirmTransfer->uLNGU_UP_TNLInformation);

	__app_ngap_set_UPTransportLayerInformationPairList( &pDUSessionResourceModifyConfirmTransfer->additionalNG_UUPTNLInformation);
	pDUSessionResourceModifyConfirmTransfer->isPresent_additionalNG_UUPTNLInformation = 1;

	__app_ngap_set_QosFlowListWithCause( &pDUSessionResourceModifyConfirmTransfer->qosFlowFailedToModifyList);
	pDUSessionResourceModifyConfirmTransfer->isPresent_qosFlowFailedToModifyList = 1;
}


//-- CONTAINER, PDUSessionResourceModifyConfirmTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyConfirmTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyConfirmTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs * pDUSessionResourceModifyConfirmTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceModifyIndicationUnsuccessfulTransfer
void __app_ngap_set_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer ** data)
{
	__si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( data);
	SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer * pDUSessionResourceModifyIndicationUnsuccessfulTransfer = *data;
	
	__app_ngap_set_Cause( &pDUSessionResourceModifyIndicationUnsuccessfulTransfer->cause);
}


//-- CONTAINER, PDUSessionResourceModifyIndicationUnsuccessfulTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs * pDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceModifyRequestTransfer
void __app_ngap_set_PDUSessionResourceModifyRequestTransfer( SI_AMF_DT_PDUSessionResourceModifyRequestTransfer ** data)
{
	__si_amf_init_PDUSessionResourceModifyRequestTransfer( data);
	SI_AMF_DT_PDUSessionResourceModifyRequestTransfer * pDUSessionResourceModifyRequestTransfer = *data;
	
}


//-- CONTAINER, PDUSessionResourceModifyRequestTransferIEs
void __app_ngap_set_PDUSessionResourceModifyRequestTransferIEs( SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyRequestTransferIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs * pDUSessionResourceModifyRequestTransferIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceModifyResponseTransfer
void __app_ngap_set_PDUSessionResourceModifyResponseTransfer( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer ** data)
{
	__si_amf_init_PDUSessionResourceModifyResponseTransfer( data);
	SI_AMF_DT_PDUSessionResourceModifyResponseTransfer * pDUSessionResourceModifyResponseTransfer = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &pDUSessionResourceModifyResponseTransfer->dL_NGU_UP_TNLInformation);
	pDUSessionResourceModifyResponseTransfer->isPresent_dL_NGU_UP_TNLInformation = 1;

	__app_ngap_set_UPTransportLayerInformation( &pDUSessionResourceModifyResponseTransfer->uL_NGU_UP_TNLInformation);
	pDUSessionResourceModifyResponseTransfer->isPresent_uL_NGU_UP_TNLInformation = 1;

	__app_ngap_set_QosFlowAddOrModifyResponseList( &pDUSessionResourceModifyResponseTransfer->qosFlowAddOrModifyResponseList);
	pDUSessionResourceModifyResponseTransfer->isPresent_qosFlowAddOrModifyResponseList = 1;

	__app_ngap_set_QosFlowPerTNLInformationList( &pDUSessionResourceModifyResponseTransfer->additionalDLQosFlowPerTNLInformation);
	pDUSessionResourceModifyResponseTransfer->isPresent_additionalDLQosFlowPerTNLInformation = 1;

	__app_ngap_set_QosFlowListWithCause( &pDUSessionResourceModifyResponseTransfer->qosFlowFailedToAddOrModifyList);
	pDUSessionResourceModifyResponseTransfer->isPresent_qosFlowFailedToAddOrModifyList = 1;
}


//-- CONTAINER, PDUSessionResourceModifyResponseTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyResponseTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs * pDUSessionResourceModifyResponseTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceModifyIndicationTransfer
void __app_ngap_set_PDUSessionResourceModifyIndicationTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer ** data)
{
	__si_amf_init_PDUSessionResourceModifyIndicationTransfer( data);
	SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer * pDUSessionResourceModifyIndicationTransfer = *data;
	
	__app_ngap_set_QosFlowPerTNLInformation( &pDUSessionResourceModifyIndicationTransfer->dLQosFlowPerTNLInformation);

	__app_ngap_set_QosFlowPerTNLInformationList( &pDUSessionResourceModifyIndicationTransfer->additionalDLQosFlowPerTNLInformation);
	pDUSessionResourceModifyIndicationTransfer->isPresent_additionalDLQosFlowPerTNLInformation = 1;
}


//-- CONTAINER, PDUSessionResourceModifyIndicationTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyIndicationTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyIndicationTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs * pDUSessionResourceModifyIndicationTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceModifyListModCfm
void __app_ngap_set_PDUSessionResourceModifyListModCfm( SI_AMF_DT_PDUSessionResourceModifyListModCfm ** data)
{
	__si_amf_init_PDUSessionResourceModifyListModCfm( data);
	SI_AMF_DT_PDUSessionResourceModifyListModCfm * pDUSessionResourceModifyListModCfm = *data;
	
	SI_AMF_DT_PDUSessionResourceModifyItemModCfm * objItem = NULL;

	__app_ngap_set_PDUSessionResourceModifyItemModCfm( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceModifyItemModCfm, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceModifyConfirmTransferOctStr
void __app_ngap_set_PDUSessionResourceModifyConfirmTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceModifyConfirmTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr * pDUSessionResourceModifyConfirmTransferOctStr = *data;
	
	pDUSessionResourceModifyConfirmTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceModifyConfirmTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceModifyConfirmTransferOctStr->data, pDUSessionResourceModifyConfirmTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceModifyItemModCfm
void __app_ngap_set_PDUSessionResourceModifyItemModCfm( SI_AMF_DT_PDUSessionResourceModifyItemModCfm ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModCfm( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModCfm * pDUSessionResourceModifyItemModCfm = *data;
	
	pDUSessionResourceModifyItemModCfm->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceModifyConfirmTransferOctStr( &pDUSessionResourceModifyItemModCfm->pDUSessionResourceModifyConfirmTransfer);
}


//-- CONTAINER, PDUSessionResourceModifyItemModCfm-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModCfm_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs * pDUSessionResourceModifyItemModCfm_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceModifyListModInd
void __app_ngap_set_PDUSessionResourceModifyListModInd( SI_AMF_DT_PDUSessionResourceModifyListModInd ** data)
{
	__si_amf_init_PDUSessionResourceModifyListModInd( data);
	SI_AMF_DT_PDUSessionResourceModifyListModInd * pDUSessionResourceModifyListModInd = *data;
	
	SI_AMF_DT_PDUSessionResourceModifyItemModInd * objItem = NULL;

	__app_ngap_set_PDUSessionResourceModifyItemModInd( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceModifyItemModInd, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceModifyIndicationTransferOctStr
void __app_ngap_set_PDUSessionResourceModifyIndicationTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceModifyIndicationTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr * pDUSessionResourceModifyIndicationTransferOctStr = *data;
	
	pDUSessionResourceModifyIndicationTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceModifyIndicationTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceModifyIndicationTransferOctStr->data, pDUSessionResourceModifyIndicationTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceModifyItemModInd
void __app_ngap_set_PDUSessionResourceModifyItemModInd( SI_AMF_DT_PDUSessionResourceModifyItemModInd ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModInd( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModInd * pDUSessionResourceModifyItemModInd = *data;
	
	pDUSessionResourceModifyItemModInd->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceModifyIndicationTransferOctStr( &pDUSessionResourceModifyItemModInd->pDUSessionResourceModifyIndicationTransfer);
}


//-- CONTAINER, PDUSessionResourceModifyItemModInd-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyItemModInd_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModInd_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs * pDUSessionResourceModifyItemModInd_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceModifyListModReq
void __app_ngap_set_PDUSessionResourceModifyListModReq( SI_AMF_DT_PDUSessionResourceModifyListModReq ** data)
{
	__si_amf_init_PDUSessionResourceModifyListModReq( data);
	SI_AMF_DT_PDUSessionResourceModifyListModReq * pDUSessionResourceModifyListModReq = *data;
	
	SI_AMF_DT_PDUSessionResourceModifyItemModReq * objItem = NULL;

	__app_ngap_set_PDUSessionResourceModifyItemModReq( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceModifyItemModReq, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceModifyRequestTransferOctStr
void __app_ngap_set_PDUSessionResourceModifyRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceModifyRequestTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr * pDUSessionResourceModifyRequestTransferOctStr = *data;
	
	pDUSessionResourceModifyRequestTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceModifyRequestTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceModifyRequestTransferOctStr->data, pDUSessionResourceModifyRequestTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceModifyItemModReq
void __app_ngap_set_PDUSessionResourceModifyItemModReq( SI_AMF_DT_PDUSessionResourceModifyItemModReq ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModReq( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModReq * pDUSessionResourceModifyItemModReq = *data;
	
	pDUSessionResourceModifyItemModReq->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_NAS_PDU( &pDUSessionResourceModifyItemModReq->nAS_PDU);
	pDUSessionResourceModifyItemModReq->isPresent_nAS_PDU = 1;

	__app_ngap_set_PDUSessionResourceModifyRequestTransferOctStr( &pDUSessionResourceModifyItemModReq->pDUSessionResourceModifyRequestTransfer);
}


//-- CONTAINER, PDUSessionResourceModifyItemModReq-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyItemModReq_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModReq_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs * pDUSessionResourceModifyItemModReq_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceModifyListModRes
void __app_ngap_set_PDUSessionResourceModifyListModRes( SI_AMF_DT_PDUSessionResourceModifyListModRes ** data)
{
	__si_amf_init_PDUSessionResourceModifyListModRes( data);
	SI_AMF_DT_PDUSessionResourceModifyListModRes * pDUSessionResourceModifyListModRes = *data;
	
	SI_AMF_DT_PDUSessionResourceModifyItemModRes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceModifyItemModRes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceModifyItemModRes, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceModifyResponseTransferOctStr
void __app_ngap_set_PDUSessionResourceModifyResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceModifyResponseTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr * pDUSessionResourceModifyResponseTransferOctStr = *data;
	
	pDUSessionResourceModifyResponseTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceModifyResponseTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceModifyResponseTransferOctStr->data, pDUSessionResourceModifyResponseTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceModifyItemModRes
void __app_ngap_set_PDUSessionResourceModifyItemModRes( SI_AMF_DT_PDUSessionResourceModifyItemModRes ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModRes( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModRes * pDUSessionResourceModifyItemModRes = *data;
	
	pDUSessionResourceModifyItemModRes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceModifyResponseTransferOctStr( &pDUSessionResourceModifyItemModRes->pDUSessionResourceModifyResponseTransfer);
}


//-- CONTAINER, PDUSessionResourceModifyItemModRes-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyItemModRes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs * pDUSessionResourceModifyItemModRes_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceModifyUnsuccessfulTransfer
void __app_ngap_set_PDUSessionResourceModifyUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer ** data)
{
	__si_amf_init_PDUSessionResourceModifyUnsuccessfulTransfer( data);
	SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer * pDUSessionResourceModifyUnsuccessfulTransfer = *data;
	
	__app_ngap_set_Cause( &pDUSessionResourceModifyUnsuccessfulTransfer->cause);

	__app_ngap_set_CriticalityDiagnostics( &pDUSessionResourceModifyUnsuccessfulTransfer->criticalityDiagnostics);
	pDUSessionResourceModifyUnsuccessfulTransfer->isPresent_criticalityDiagnostics = 1;
}


//-- CONTAINER, PDUSessionResourceModifyUnsuccessfulTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs * pDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceNotifyList
void __app_ngap_set_PDUSessionResourceNotifyList( SI_AMF_DT_PDUSessionResourceNotifyList ** data)
{
	__si_amf_init_PDUSessionResourceNotifyList( data);
	SI_AMF_DT_PDUSessionResourceNotifyList * pDUSessionResourceNotifyList = *data;
	
	SI_AMF_DT_PDUSessionResourceNotifyItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceNotifyItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceNotifyItem, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceNotifyTransferOctStr
void __app_ngap_set_PDUSessionResourceNotifyTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceNotifyTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr * pDUSessionResourceNotifyTransferOctStr = *data;
	
	pDUSessionResourceNotifyTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceNotifyTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceNotifyTransferOctStr->data, pDUSessionResourceNotifyTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceNotifyItem
void __app_ngap_set_PDUSessionResourceNotifyItem( SI_AMF_DT_PDUSessionResourceNotifyItem ** data)
{
	__si_amf_init_PDUSessionResourceNotifyItem( data);
	SI_AMF_DT_PDUSessionResourceNotifyItem * pDUSessionResourceNotifyItem = *data;
	
	pDUSessionResourceNotifyItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceNotifyTransferOctStr( &pDUSessionResourceNotifyItem->pDUSessionResourceNotifyTransfer);
}


//-- CONTAINER, PDUSessionResourceNotifyItem-ExtIEs
void __app_ngap_set_PDUSessionResourceNotifyItem_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceNotifyItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs * pDUSessionResourceNotifyItem_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceNotifyReleasedTransfer
void __app_ngap_set_PDUSessionResourceNotifyReleasedTransfer( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer ** data)
{
	__si_amf_init_PDUSessionResourceNotifyReleasedTransfer( data);
	SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer * pDUSessionResourceNotifyReleasedTransfer = *data;
	
	__app_ngap_set_Cause( &pDUSessionResourceNotifyReleasedTransfer->cause);
}


//-- CONTAINER, PDUSessionResourceNotifyReleasedTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs * pDUSessionResourceNotifyReleasedTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceNotifyTransfer
void __app_ngap_set_PDUSessionResourceNotifyTransfer( SI_AMF_DT_PDUSessionResourceNotifyTransfer ** data)
{
	__si_amf_init_PDUSessionResourceNotifyTransfer( data);
	SI_AMF_DT_PDUSessionResourceNotifyTransfer * pDUSessionResourceNotifyTransfer = *data;
	
	__app_ngap_set_QosFlowNotifyList( &pDUSessionResourceNotifyTransfer->qosFlowNotifyList);
	pDUSessionResourceNotifyTransfer->isPresent_qosFlowNotifyList = 1;

	__app_ngap_set_QosFlowListWithCause( &pDUSessionResourceNotifyTransfer->qosFlowReleasedList);
	pDUSessionResourceNotifyTransfer->isPresent_qosFlowReleasedList = 1;
}


//-- CONTAINER, PDUSessionResourceNotifyTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceNotifyTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceNotifyTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs * pDUSessionResourceNotifyTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceReleaseCommandTransfer
void __app_ngap_set_PDUSessionResourceReleaseCommandTransfer( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer ** data)
{
	__si_amf_init_PDUSessionResourceReleaseCommandTransfer( data);
	SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer * pDUSessionResourceReleaseCommandTransfer = *data;
	
	__app_ngap_set_Cause( &pDUSessionResourceReleaseCommandTransfer->cause);
}


//-- CONTAINER, PDUSessionResourceReleaseCommandTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceReleaseCommandTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceReleaseCommandTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs * pDUSessionResourceReleaseCommandTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceReleasedListNot
void __app_ngap_set_PDUSessionResourceReleasedListNot( SI_AMF_DT_PDUSessionResourceReleasedListNot ** data)
{
	__si_amf_init_PDUSessionResourceReleasedListNot( data);
	SI_AMF_DT_PDUSessionResourceReleasedListNot * pDUSessionResourceReleasedListNot = *data;
	
	SI_AMF_DT_PDUSessionResourceReleasedItemNot * objItem = NULL;

	__app_ngap_set_PDUSessionResourceReleasedItemNot( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceReleasedItemNot, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceNotifyReleasedTransferOctStr
void __app_ngap_set_PDUSessionResourceNotifyReleasedTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceNotifyReleasedTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr * pDUSessionResourceNotifyReleasedTransferOctStr = *data;
	
	pDUSessionResourceNotifyReleasedTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceNotifyReleasedTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceNotifyReleasedTransferOctStr->data, pDUSessionResourceNotifyReleasedTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceReleasedItemNot
void __app_ngap_set_PDUSessionResourceReleasedItemNot( SI_AMF_DT_PDUSessionResourceReleasedItemNot ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemNot( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemNot * pDUSessionResourceReleasedItemNot = *data;
	
	pDUSessionResourceReleasedItemNot->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceNotifyReleasedTransferOctStr( &pDUSessionResourceReleasedItemNot->pDUSessionResourceNotifyReleasedTransfer);
}


//-- CONTAINER, PDUSessionResourceReleasedItemNot-ExtIEs
void __app_ngap_set_PDUSessionResourceReleasedItemNot_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemNot_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs * pDUSessionResourceReleasedItemNot_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceReleasedListPSAck
void __app_ngap_set_PDUSessionResourceReleasedListPSAck( SI_AMF_DT_PDUSessionResourceReleasedListPSAck ** data)
{
	__si_amf_init_PDUSessionResourceReleasedListPSAck( data);
	SI_AMF_DT_PDUSessionResourceReleasedListPSAck * pDUSessionResourceReleasedListPSAck = *data;
	
	SI_AMF_DT_PDUSessionResourceReleasedItemPSAck * objItem = NULL;

	__app_ngap_set_PDUSessionResourceReleasedItemPSAck( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceReleasedItemPSAck, (uint8_t *)objItem);
}


//-- OCTETSTRING, PathSwitchRequestUnsuccessfulTransferOctStr
void __app_ngap_set_PathSwitchRequestUnsuccessfulTransferOctStr( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr ** data)
{
	__si_amf_init_PathSwitchRequestUnsuccessfulTransferOctStr( data);
	SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr * pathSwitchRequestUnsuccessfulTransferOctStr = *data;
	
	pathSwitchRequestUnsuccessfulTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pathSwitchRequestUnsuccessfulTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pathSwitchRequestUnsuccessfulTransferOctStr->data, pathSwitchRequestUnsuccessfulTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceReleasedItemPSAck
void __app_ngap_set_PDUSessionResourceReleasedItemPSAck( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemPSAck( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemPSAck * pDUSessionResourceReleasedItemPSAck = *data;
	
	pDUSessionResourceReleasedItemPSAck->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PathSwitchRequestUnsuccessfulTransferOctStr( &pDUSessionResourceReleasedItemPSAck->pathSwitchRequestUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceReleasedItemPSAck-ExtIEs
void __app_ngap_set_PDUSessionResourceReleasedItemPSAck_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemPSAck_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs * pDUSessionResourceReleasedItemPSAck_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceReleasedListPSFail
void __app_ngap_set_PDUSessionResourceReleasedListPSFail( SI_AMF_DT_PDUSessionResourceReleasedListPSFail ** data)
{
	__si_amf_init_PDUSessionResourceReleasedListPSFail( data);
	SI_AMF_DT_PDUSessionResourceReleasedListPSFail * pDUSessionResourceReleasedListPSFail = *data;
	
	SI_AMF_DT_PDUSessionResourceReleasedItemPSFail * objItem = NULL;

	__app_ngap_set_PDUSessionResourceReleasedItemPSFail( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceReleasedItemPSFail, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceReleasedItemPSFail
void __app_ngap_set_PDUSessionResourceReleasedItemPSFail( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemPSFail( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemPSFail * pDUSessionResourceReleasedItemPSFail = *data;
	
	pDUSessionResourceReleasedItemPSFail->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PathSwitchRequestUnsuccessfulTransferOctStr( &pDUSessionResourceReleasedItemPSFail->pathSwitchRequestUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceReleasedItemPSFail-ExtIEs
void __app_ngap_set_PDUSessionResourceReleasedItemPSFail_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemPSFail_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs * pDUSessionResourceReleasedItemPSFail_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceReleasedListRelRes
void __app_ngap_set_PDUSessionResourceReleasedListRelRes( SI_AMF_DT_PDUSessionResourceReleasedListRelRes ** data)
{
	__si_amf_init_PDUSessionResourceReleasedListRelRes( data);
	SI_AMF_DT_PDUSessionResourceReleasedListRelRes * pDUSessionResourceReleasedListRelRes = *data;
	
	SI_AMF_DT_PDUSessionResourceReleasedItemRelRes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceReleasedItemRelRes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceReleasedItemRelRes, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceReleasedItemRelRes
void __app_ngap_set_PDUSessionResourceReleasedItemRelRes( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemRelRes( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemRelRes * pDUSessionResourceReleasedItemRelRes = *data;
	
	pDUSessionResourceReleasedItemRelRes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceReleaseResponseTransferOctStr( &pDUSessionResourceReleasedItemRelRes->pDUSessionResourceReleaseResponseTransfer);
}


//-- CONTAINER, PDUSessionResourceReleasedItemRelRes-ExtIEs
void __app_ngap_set_PDUSessionResourceReleasedItemRelRes_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceReleasedItemRelRes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs * pDUSessionResourceReleasedItemRelRes_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceReleaseResponseTransfer
void __app_ngap_set_PDUSessionResourceReleaseResponseTransfer( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer ** data)
{
	__si_amf_init_PDUSessionResourceReleaseResponseTransfer( data);
	SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer * pDUSessionResourceReleaseResponseTransfer = *data;
	
}


//-- CONTAINER, PDUSessionResourceReleaseResponseTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceReleaseResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceReleaseResponseTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs * pDUSessionResourceReleaseResponseTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSecondaryRATUsageList
void __app_ngap_set_PDUSessionResourceSecondaryRATUsageList( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList ** data)
{
	__si_amf_init_PDUSessionResourceSecondaryRATUsageList( data);
	SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList * pDUSessionResourceSecondaryRATUsageList = *data;
	
	SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSecondaryRATUsageItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSecondaryRATUsageItem, (uint8_t *)objItem);
}


//-- OCTETSTRING, SecondaryRATDataUsageReportTransferOctStr
void __app_ngap_set_SecondaryRATDataUsageReportTransferOctStr( SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr ** data)
{
	__si_amf_init_SecondaryRATDataUsageReportTransferOctStr( data);
	SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr * secondaryRATDataUsageReportTransferOctStr = *data;
	
	secondaryRATDataUsageReportTransferOctStr->data = (unsigned char *) __si_allocM(0);
	secondaryRATDataUsageReportTransferOctStr->length = 0;
	__si_core_fill_dummy_data( secondaryRATDataUsageReportTransferOctStr->data, secondaryRATDataUsageReportTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceSecondaryRATUsageItem
void __app_ngap_set_PDUSessionResourceSecondaryRATUsageItem( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem ** data)
{
	__si_amf_init_PDUSessionResourceSecondaryRATUsageItem( data);
	SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem * pDUSessionResourceSecondaryRATUsageItem = *data;
	
	pDUSessionResourceSecondaryRATUsageItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_SecondaryRATDataUsageReportTransferOctStr( &pDUSessionResourceSecondaryRATUsageItem->secondaryRATDataUsageReportTransfer);
}


//-- CONTAINER, PDUSessionResourceSecondaryRATUsageItem-ExtIEs
void __app_ngap_set_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs * pDUSessionResourceSecondaryRATUsageItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSetupListCxtReq
void __app_ngap_set_PDUSessionResourceSetupListCxtReq( SI_AMF_DT_PDUSessionResourceSetupListCxtReq ** data)
{
	__si_amf_init_PDUSessionResourceSetupListCxtReq( data);
	SI_AMF_DT_PDUSessionResourceSetupListCxtReq * pDUSessionResourceSetupListCxtReq = *data;
	
	SI_AMF_DT_PDUSessionResourceSetupItemCxtReq * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSetupItemCxtReq( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSetupItemCxtReq, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceSetupRequestTransferOctStr
void __app_ngap_set_PDUSessionResourceSetupRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceSetupRequestTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * pDUSessionResourceSetupRequestTransferOctStr = *data;
	
	pDUSessionResourceSetupRequestTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceSetupRequestTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceSetupRequestTransferOctStr->data, pDUSessionResourceSetupRequestTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceSetupItemCxtReq
void __app_ngap_set_PDUSessionResourceSetupItemCxtReq( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemCxtReq( data);
	SI_AMF_DT_PDUSessionResourceSetupItemCxtReq * pDUSessionResourceSetupItemCxtReq = *data;
	
	pDUSessionResourceSetupItemCxtReq->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_NAS_PDU( &pDUSessionResourceSetupItemCxtReq->nAS_PDU);
	pDUSessionResourceSetupItemCxtReq->isPresent_nAS_PDU = 1;

	__app_ngap_set_S_NSSAI( &pDUSessionResourceSetupItemCxtReq->s_NSSAI);

	__app_ngap_set_PDUSessionResourceSetupRequestTransferOctStr( &pDUSessionResourceSetupItemCxtReq->pDUSessionResourceSetupRequestTransfer);
}


//-- CONTAINER, PDUSessionResourceSetupItemCxtReq-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupItemCxtReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemCxtReq_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs * pDUSessionResourceSetupItemCxtReq_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSetupListCxtRes
void __app_ngap_set_PDUSessionResourceSetupListCxtRes( SI_AMF_DT_PDUSessionResourceSetupListCxtRes ** data)
{
	__si_amf_init_PDUSessionResourceSetupListCxtRes( data);
	SI_AMF_DT_PDUSessionResourceSetupListCxtRes * pDUSessionResourceSetupListCxtRes = *data;
	
	SI_AMF_DT_PDUSessionResourceSetupItemCxtRes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSetupItemCxtRes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSetupItemCxtRes, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceSetupResponseTransferOctStr
void __app_ngap_set_PDUSessionResourceSetupResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceSetupResponseTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr * pDUSessionResourceSetupResponseTransferOctStr = *data;
	
	pDUSessionResourceSetupResponseTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceSetupResponseTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceSetupResponseTransferOctStr->data, pDUSessionResourceSetupResponseTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceSetupItemCxtRes
void __app_ngap_set_PDUSessionResourceSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemCxtRes( data);
	SI_AMF_DT_PDUSessionResourceSetupItemCxtRes * pDUSessionResourceSetupItemCxtRes = *data;
	
	pDUSessionResourceSetupItemCxtRes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceSetupResponseTransferOctStr( &pDUSessionResourceSetupItemCxtRes->pDUSessionResourceSetupResponseTransfer);
}


//-- CONTAINER, PDUSessionResourceSetupItemCxtRes-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemCxtRes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs * pDUSessionResourceSetupItemCxtRes_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSetupListHOReq
void __app_ngap_set_PDUSessionResourceSetupListHOReq( SI_AMF_DT_PDUSessionResourceSetupListHOReq ** data)
{
	__si_amf_init_PDUSessionResourceSetupListHOReq( data);
	SI_AMF_DT_PDUSessionResourceSetupListHOReq * pDUSessionResourceSetupListHOReq = *data;
	
	SI_AMF_DT_PDUSessionResourceSetupItemHOReq * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSetupItemHOReq( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSetupItemHOReq, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceSetupItemHOReq
void __app_ngap_set_PDUSessionResourceSetupItemHOReq( SI_AMF_DT_PDUSessionResourceSetupItemHOReq ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemHOReq( data);
	SI_AMF_DT_PDUSessionResourceSetupItemHOReq * pDUSessionResourceSetupItemHOReq = *data;
	
	pDUSessionResourceSetupItemHOReq->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_S_NSSAI( &pDUSessionResourceSetupItemHOReq->s_NSSAI);

	__app_ngap_set_PDUSessionResourceSetupRequestTransferOctStr( &pDUSessionResourceSetupItemHOReq->handoverRequestTransfer);
}


//-- CONTAINER, PDUSessionResourceSetupItemHOReq-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupItemHOReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemHOReq_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs * pDUSessionResourceSetupItemHOReq_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSetupListSUReq
void __app_ngap_set_PDUSessionResourceSetupListSUReq( SI_AMF_DT_PDUSessionResourceSetupListSUReq ** data)
{
	__si_amf_init_PDUSessionResourceSetupListSUReq( data);
	SI_AMF_DT_PDUSessionResourceSetupListSUReq * pDUSessionResourceSetupListSUReq = *data;
	
	SI_AMF_DT_PDUSessionResourceSetupItemSUReq * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSetupItemSUReq( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSetupItemSUReq, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceSetupItemSUReq
void __app_ngap_set_PDUSessionResourceSetupItemSUReq( SI_AMF_DT_PDUSessionResourceSetupItemSUReq ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemSUReq( data);
	SI_AMF_DT_PDUSessionResourceSetupItemSUReq * pDUSessionResourceSetupItemSUReq = *data;
	
	pDUSessionResourceSetupItemSUReq->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_NAS_PDU( &pDUSessionResourceSetupItemSUReq->pDUSessionNAS_PDU);
	pDUSessionResourceSetupItemSUReq->isPresent_pDUSessionNAS_PDU = 1;

	__app_ngap_set_S_NSSAI( &pDUSessionResourceSetupItemSUReq->s_NSSAI);

	__app_ngap_set_PDUSessionResourceSetupRequestTransferOctStr( &pDUSessionResourceSetupItemSUReq->pDUSessionResourceSetupRequestTransfer);
}


//-- CONTAINER, PDUSessionResourceSetupItemSUReq-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupItemSUReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemSUReq_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs * pDUSessionResourceSetupItemSUReq_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSetupListSURes
void __app_ngap_set_PDUSessionResourceSetupListSURes( SI_AMF_DT_PDUSessionResourceSetupListSURes ** data)
{
	__si_amf_init_PDUSessionResourceSetupListSURes( data);
	SI_AMF_DT_PDUSessionResourceSetupListSURes * pDUSessionResourceSetupListSURes = *data;
	
	SI_AMF_DT_PDUSessionResourceSetupItemSURes * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSetupItemSURes( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSetupItemSURes, (uint8_t *)objItem);
}


//-- SEQUENCE, PDUSessionResourceSetupItemSURes
void __app_ngap_set_PDUSessionResourceSetupItemSURes( SI_AMF_DT_PDUSessionResourceSetupItemSURes ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemSURes( data);
	SI_AMF_DT_PDUSessionResourceSetupItemSURes * pDUSessionResourceSetupItemSURes = *data;
	
	pDUSessionResourceSetupItemSURes->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceSetupResponseTransferOctStr( &pDUSessionResourceSetupItemSURes->pDUSessionResourceSetupResponseTransfer);
}


//-- CONTAINER, PDUSessionResourceSetupItemSURes-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupItemSURes_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs * pDUSessionResourceSetupItemSURes_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceSetupRequestTransfer
void __app_ngap_set_PDUSessionResourceSetupRequestTransfer( SI_AMF_DT_PDUSessionResourceSetupRequestTransfer ** data)
{
	__si_amf_init_PDUSessionResourceSetupRequestTransfer( data);
	SI_AMF_DT_PDUSessionResourceSetupRequestTransfer * pDUSessionResourceSetupRequestTransfer = *data;
	
}


//-- SEQUENCE, PDUSessionResourceSetupResponseTransfer
void __app_ngap_set_PDUSessionResourceSetupResponseTransfer( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer ** data)
{
	__si_amf_init_PDUSessionResourceSetupResponseTransfer( data);
	SI_AMF_DT_PDUSessionResourceSetupResponseTransfer * pDUSessionResourceSetupResponseTransfer = *data;
	
	__app_ngap_set_QosFlowPerTNLInformation( &pDUSessionResourceSetupResponseTransfer->dLQosFlowPerTNLInformation);

	__app_ngap_set_QosFlowPerTNLInformationList( &pDUSessionResourceSetupResponseTransfer->additionalDLQosFlowPerTNLInformation);
	pDUSessionResourceSetupResponseTransfer->isPresent_additionalDLQosFlowPerTNLInformation = 1;

	__app_ngap_set_SecurityResult( &pDUSessionResourceSetupResponseTransfer->securityResult);
	pDUSessionResourceSetupResponseTransfer->isPresent_securityResult = 1;

	__app_ngap_set_QosFlowListWithCause( &pDUSessionResourceSetupResponseTransfer->qosFlowFailedToSetupList);
	pDUSessionResourceSetupResponseTransfer->isPresent_qosFlowFailedToSetupList = 1;
}


//-- CONTAINER, PDUSessionResourceSetupResponseTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupResponseTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs * pDUSessionResourceSetupResponseTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionResourceSetupUnsuccessfulTransfer
void __app_ngap_set_PDUSessionResourceSetupUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer ** data)
{
	__si_amf_init_PDUSessionResourceSetupUnsuccessfulTransfer( data);
	SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer * pDUSessionResourceSetupUnsuccessfulTransfer = *data;
	
	__app_ngap_set_Cause( &pDUSessionResourceSetupUnsuccessfulTransfer->cause);

	__app_ngap_set_CriticalityDiagnostics( &pDUSessionResourceSetupUnsuccessfulTransfer->criticalityDiagnostics);
	pDUSessionResourceSetupUnsuccessfulTransfer->isPresent_criticalityDiagnostics = 1;
}


//-- CONTAINER, PDUSessionResourceSetupUnsuccessfulTransfer-ExtIEs
void __app_ngap_set_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs * pDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceSwitchedList
void __app_ngap_set_PDUSessionResourceSwitchedList( SI_AMF_DT_PDUSessionResourceSwitchedList ** data)
{
	__si_amf_init_PDUSessionResourceSwitchedList( data);
	SI_AMF_DT_PDUSessionResourceSwitchedList * pDUSessionResourceSwitchedList = *data;
	
	SI_AMF_DT_PDUSessionResourceSwitchedItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceSwitchedItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceSwitchedItem, (uint8_t *)objItem);
}


//-- OCTETSTRING, PathSwitchRequestAcknowledgeTransferOctStr
void __app_ngap_set_PathSwitchRequestAcknowledgeTransferOctStr( SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr ** data)
{
	__si_amf_init_PathSwitchRequestAcknowledgeTransferOctStr( data);
	SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr * pathSwitchRequestAcknowledgeTransferOctStr = *data;
	
	pathSwitchRequestAcknowledgeTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pathSwitchRequestAcknowledgeTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pathSwitchRequestAcknowledgeTransferOctStr->data, pathSwitchRequestAcknowledgeTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceSwitchedItem
void __app_ngap_set_PDUSessionResourceSwitchedItem( SI_AMF_DT_PDUSessionResourceSwitchedItem ** data)
{
	__si_amf_init_PDUSessionResourceSwitchedItem( data);
	SI_AMF_DT_PDUSessionResourceSwitchedItem * pDUSessionResourceSwitchedItem = *data;
	
	pDUSessionResourceSwitchedItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PathSwitchRequestAcknowledgeTransferOctStr( &pDUSessionResourceSwitchedItem->pathSwitchRequestAcknowledgeTransfer);
}


//-- CONTAINER, PDUSessionResourceSwitchedItem-ExtIEs
void __app_ngap_set_PDUSessionResourceSwitchedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceSwitchedItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs * pDUSessionResourceSwitchedItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceToBeSwitchedDLList
void __app_ngap_set_PDUSessionResourceToBeSwitchedDLList( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList ** data)
{
	__si_amf_init_PDUSessionResourceToBeSwitchedDLList( data);
	SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList * pDUSessionResourceToBeSwitchedDLList = *data;
	
	SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem * objItem = NULL;

	__app_ngap_set_PDUSessionResourceToBeSwitchedDLItem( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceToBeSwitchedDLItem, (uint8_t *)objItem);
}


//-- OCTETSTRING, PathSwitchRequestTransferOctStr
void __app_ngap_set_PathSwitchRequestTransferOctStr( SI_AMF_DT_PathSwitchRequestTransferOctStr ** data)
{
	__si_amf_init_PathSwitchRequestTransferOctStr( data);
	SI_AMF_DT_PathSwitchRequestTransferOctStr * pathSwitchRequestTransferOctStr = *data;
	
	pathSwitchRequestTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pathSwitchRequestTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pathSwitchRequestTransferOctStr->data, pathSwitchRequestTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceToBeSwitchedDLItem
void __app_ngap_set_PDUSessionResourceToBeSwitchedDLItem( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem ** data)
{
	__si_amf_init_PDUSessionResourceToBeSwitchedDLItem( data);
	SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem * pDUSessionResourceToBeSwitchedDLItem = *data;
	
	pDUSessionResourceToBeSwitchedDLItem->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PathSwitchRequestTransferOctStr( &pDUSessionResourceToBeSwitchedDLItem->pathSwitchRequestTransfer);
}


//-- CONTAINER, PDUSessionResourceToBeSwitchedDLItem-ExtIEs
void __app_ngap_set_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs * pDUSessionResourceToBeSwitchedDLItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceToReleaseListHOCmd
void __app_ngap_set_PDUSessionResourceToReleaseListHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd ** data)
{
	__si_amf_init_PDUSessionResourceToReleaseListHOCmd( data);
	SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd * pDUSessionResourceToReleaseListHOCmd = *data;
	
	SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd * objItem = NULL;

	__app_ngap_set_PDUSessionResourceToReleaseItemHOCmd( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceToReleaseItemHOCmd, (uint8_t *)objItem);
}


//-- OCTETSTRING, HandoverPreparationUnsuccessfulTransferOctStr
void __app_ngap_set_HandoverPreparationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr ** data)
{
	__si_amf_init_HandoverPreparationUnsuccessfulTransferOctStr( data);
	SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr * handoverPreparationUnsuccessfulTransferOctStr = *data;
	
	handoverPreparationUnsuccessfulTransferOctStr->data = (unsigned char *) __si_allocM(0);
	handoverPreparationUnsuccessfulTransferOctStr->length = 0;
	__si_core_fill_dummy_data( handoverPreparationUnsuccessfulTransferOctStr->data, handoverPreparationUnsuccessfulTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceToReleaseItemHOCmd
void __app_ngap_set_PDUSessionResourceToReleaseItemHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd ** data)
{
	__si_amf_init_PDUSessionResourceToReleaseItemHOCmd( data);
	SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd * pDUSessionResourceToReleaseItemHOCmd = *data;
	
	pDUSessionResourceToReleaseItemHOCmd->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_HandoverPreparationUnsuccessfulTransferOctStr( &pDUSessionResourceToReleaseItemHOCmd->handoverPreparationUnsuccessfulTransfer);
}


//-- CONTAINER, PDUSessionResourceToReleaseItemHOCmd-ExtIEs
void __app_ngap_set_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs * pDUSessionResourceToReleaseItemHOCmd_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, PDUSessionResourceToReleaseListRelCmd
void __app_ngap_set_PDUSessionResourceToReleaseListRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd ** data)
{
	__si_amf_init_PDUSessionResourceToReleaseListRelCmd( data);
	SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd * pDUSessionResourceToReleaseListRelCmd = *data;
	
	SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd * objItem = NULL;

	__app_ngap_set_PDUSessionResourceToReleaseItemRelCmd( &objItem);
	__si_linked_list_add( (*data)->PDUSessionResourceToReleaseItemRelCmd, (uint8_t *)objItem);
}


//-- OCTETSTRING, PDUSessionResourceReleaseCommandTransferOctStr
void __app_ngap_set_PDUSessionResourceReleaseCommandTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr ** data)
{
	__si_amf_init_PDUSessionResourceReleaseCommandTransferOctStr( data);
	SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr * pDUSessionResourceReleaseCommandTransferOctStr = *data;
	
	pDUSessionResourceReleaseCommandTransferOctStr->data = (unsigned char *) __si_allocM(0);
	pDUSessionResourceReleaseCommandTransferOctStr->length = 0;
	__si_core_fill_dummy_data( pDUSessionResourceReleaseCommandTransferOctStr->data, pDUSessionResourceReleaseCommandTransferOctStr->length);
}


//-- SEQUENCE, PDUSessionResourceToReleaseItemRelCmd
void __app_ngap_set_PDUSessionResourceToReleaseItemRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd ** data)
{
	__si_amf_init_PDUSessionResourceToReleaseItemRelCmd( data);
	SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd * pDUSessionResourceToReleaseItemRelCmd = *data;
	
	pDUSessionResourceToReleaseItemRelCmd->pDUSessionID = __si_core_getU64RANDRange( 0, 255);
	__app_ngap_set_PDUSessionResourceReleaseCommandTransferOctStr( &pDUSessionResourceToReleaseItemRelCmd->pDUSessionResourceReleaseCommandTransfer);
}


//-- CONTAINER, PDUSessionResourceToReleaseItemRelCmd-ExtIEs
void __app_ngap_set_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs ** data)
{
	__si_amf_init_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( data);
	SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs * pDUSessionResourceToReleaseItemRelCmd_ExtIEs = *data;
	
}


//-- SEQUENCE, PDUSessionUsageReport
void __app_ngap_set_PDUSessionUsageReport( SI_AMF_DT_PDUSessionUsageReport ** data)
{
	__si_amf_init_PDUSessionUsageReport( data);
	SI_AMF_DT_PDUSessionUsageReport * pDUSessionUsageReport = *data;
	
	pDUSessionUsageReport->selected_erATType = 0;
	__app_ngap_set_VolumeTimedReportList( &pDUSessionUsageReport->pDUSessionTimedReportList);
}


//-- CONTAINER, PDUSessionUsageReport-ExtIEs
void __app_ngap_set_PDUSessionUsageReport_ExtIEs( SI_AMF_DT_PDUSessionUsageReport_ExtIEs ** data)
{
	__si_amf_init_PDUSessionUsageReport_ExtIEs( data);
	SI_AMF_DT_PDUSessionUsageReport_ExtIEs * pDUSessionUsageReport_ExtIEs = *data;
	
}


//-- BITSTRING, PeriodicRegistrationUpdateTimer
void __app_ngap_set_PeriodicRegistrationUpdateTimer( SI_AMF_DT_PeriodicRegistrationUpdateTimer ** data)
{
	__si_amf_init_PeriodicRegistrationUpdateTimer( data);
	SI_AMF_DT_PeriodicRegistrationUpdateTimer * periodicRegistrationUpdateTimer = *data;
	
	//BITSIZE = 8  , BIT STRING(SIZE(8))
	periodicRegistrationUpdateTimer->data = (unsigned char *) __si_allocM(2);
	periodicRegistrationUpdateTimer->length = 2;
	periodicRegistrationUpdateTimer->bitslen = 8;
	__si_core_fill_dummy_data( periodicRegistrationUpdateTimer->data, periodicRegistrationUpdateTimer->length);
}


//-- OCTETSTRING, PLMNIdentity
void __app_ngap_set_PLMNIdentity( SI_AMF_DT_PLMNIdentity ** data)
{
	__si_amf_init_PLMNIdentity( data);
	SI_AMF_DT_PLMNIdentity * pLMNIdentity = *data;
	
	pLMNIdentity->data = (unsigned char *) __si_allocM(3);
	pLMNIdentity->length = 3;
	memset( pLMNIdentity->data, 0, 3);
	/*
	int i = 0;
	for( i = 0; i < pLMNIdentity->length; i++)
	{
		pLMNIdentity->data[i] = __si_core_getU8RANDRange( 0, 50);
	}
	*/
}


//-- SEQUENCE_OF, PLMNSupportList
void __app_ngap_set_PLMNSupportList( SI_AMF_DT_PLMNSupportList ** data)
{
	__si_amf_init_PLMNSupportList( data);
	SI_AMF_DT_PLMNSupportList * pLMNSupportList = *data;
	
	SI_AMF_DT_PLMNSupportItem * objItem = NULL;

	__app_ngap_set_PLMNSupportItem( &objItem);
	__si_linked_list_add( (*data)->PLMNSupportItem, (uint8_t *)objItem);
}


//-- SEQUENCE, PLMNSupportItem
void __app_ngap_set_PLMNSupportItem( SI_AMF_DT_PLMNSupportItem ** data)
{
	__si_amf_init_PLMNSupportItem( data);
	SI_AMF_DT_PLMNSupportItem * pLMNSupportItem = *data;
	
	__app_ngap_set_PLMNIdentity( &pLMNSupportItem->pLMNIdentity);

	__app_ngap_set_SliceSupportList( &pLMNSupportItem->sliceSupportList);
}


//-- CONTAINER, PLMNSupportItem-ExtIEs
void __app_ngap_set_PLMNSupportItem_ExtIEs( SI_AMF_DT_PLMNSupportItem_ExtIEs ** data)
{
	__si_amf_init_PLMNSupportItem_ExtIEs( data);
	SI_AMF_DT_PLMNSupportItem_ExtIEs * pLMNSupportItem_ExtIEs = *data;
	
}


//-- OCTETSTRING, PortNumber
void __app_ngap_set_PortNumber( SI_AMF_DT_PortNumber ** data)
{
	__si_amf_init_PortNumber( data);
	SI_AMF_DT_PortNumber * portNumber = *data;
	
	portNumber->data = (unsigned char *) __si_allocM(2);
	portNumber->length = 2;
	__si_core_fill_dummy_data( portNumber->data, portNumber->length);
}


//-- INTEGER, PriorityLevelARP
void __app_ngap_set_PriorityLevelARP( SI_AMF_DT_PriorityLevelARP ** data)
{
	SI_AMF_DT_PriorityLevelARP * priorityLevelARP = *data;
	
	//MIN = 1, MAX = 15
	priorityLevelARP->data = __si_core_getU64RANDRange( 1, 15);
}


//-- INTEGER, PriorityLevelQos
void __app_ngap_set_PriorityLevelQos( SI_AMF_DT_PriorityLevelQos ** data)
{
	SI_AMF_DT_PriorityLevelQos * priorityLevelQos = *data;
	
	//MIN = 1, MAX = 127
	priorityLevelQos->data = __si_core_getU64RANDRange( 1, 127);
}


//-- CHOICE, PWSFailedCellIDList
void __app_ngap_set_PWSFailedCellIDList( SI_AMF_DT_PWSFailedCellIDList ** data)
{
	__si_amf_init_PWSFailedCellIDList( data);
	SI_AMF_DT_PWSFailedCellIDList * pWSFailedCellIDList = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_EUTRA_CGIList( &(*data)->u.eUTRA_CGI_PWSFailedList);

}


//-- CONTAINER, PWSFailedCellIDList-ExtIEs
void __app_ngap_set_PWSFailedCellIDList_ExtIEs( SI_AMF_DT_PWSFailedCellIDList_ExtIEs ** data)
{
	__si_amf_init_PWSFailedCellIDList_ExtIEs( data);
	SI_AMF_DT_PWSFailedCellIDList_ExtIEs * pWSFailedCellIDList_ExtIEs = *data;
	
}


//-- CHOICE, QosCharacteristics
void __app_ngap_set_QosCharacteristics( SI_AMF_DT_QosCharacteristics ** data)
{
	__si_amf_init_QosCharacteristics( data);
	SI_AMF_DT_QosCharacteristics * qosCharacteristics = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_NonDynamic5QIDescriptor( &(*data)->u.nonDynamic5QI);

}


//-- CONTAINER, QosCharacteristics-ExtIEs
void __app_ngap_set_QosCharacteristics_ExtIEs( SI_AMF_DT_QosCharacteristics_ExtIEs ** data)
{
	__si_amf_init_QosCharacteristics_ExtIEs( data);
	SI_AMF_DT_QosCharacteristics_ExtIEs * qosCharacteristics_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowAcceptedList
void __app_ngap_set_QosFlowAcceptedList( SI_AMF_DT_QosFlowAcceptedList ** data)
{
	__si_amf_init_QosFlowAcceptedList( data);
	SI_AMF_DT_QosFlowAcceptedList * qosFlowAcceptedList = *data;
	
	SI_AMF_DT_QosFlowAcceptedItem * objItem = NULL;

	__app_ngap_set_QosFlowAcceptedItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowAcceptedItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowAcceptedItem
void __app_ngap_set_QosFlowAcceptedItem( SI_AMF_DT_QosFlowAcceptedItem ** data)
{
	__si_amf_init_QosFlowAcceptedItem( data);
	SI_AMF_DT_QosFlowAcceptedItem * qosFlowAcceptedItem = *data;
	
	qosFlowAcceptedItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
}


//-- CONTAINER, QosFlowAcceptedItem-ExtIEs
void __app_ngap_set_QosFlowAcceptedItem_ExtIEs( SI_AMF_DT_QosFlowAcceptedItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowAcceptedItem_ExtIEs( data);
	SI_AMF_DT_QosFlowAcceptedItem_ExtIEs * qosFlowAcceptedItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowAddOrModifyRequestList
void __app_ngap_set_QosFlowAddOrModifyRequestList( SI_AMF_DT_QosFlowAddOrModifyRequestList ** data)
{
	__si_amf_init_QosFlowAddOrModifyRequestList( data);
	SI_AMF_DT_QosFlowAddOrModifyRequestList * qosFlowAddOrModifyRequestList = *data;
	
	SI_AMF_DT_QosFlowAddOrModifyRequestItem * objItem = NULL;

	__app_ngap_set_QosFlowAddOrModifyRequestItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowAddOrModifyRequestItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowAddOrModifyRequestItem
void __app_ngap_set_QosFlowAddOrModifyRequestItem( SI_AMF_DT_QosFlowAddOrModifyRequestItem ** data)
{
	__si_amf_init_QosFlowAddOrModifyRequestItem( data);
	SI_AMF_DT_QosFlowAddOrModifyRequestItem * qosFlowAddOrModifyRequestItem = *data;
	
	qosFlowAddOrModifyRequestItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	__app_ngap_set_QosFlowLevelQosParameters( &qosFlowAddOrModifyRequestItem->qosFlowLevelQosParameters);
	qosFlowAddOrModifyRequestItem->isPresent_qosFlowLevelQosParameters = 1;

	qosFlowAddOrModifyRequestItem->e_RAB_ID = __si_core_getU64RANDRange( 0, 15);
}


//-- CONTAINER, QosFlowAddOrModifyRequestItem-ExtIEs
void __app_ngap_set_QosFlowAddOrModifyRequestItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowAddOrModifyRequestItem_ExtIEs( data);
	SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs * qosFlowAddOrModifyRequestItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowAddOrModifyResponseList
void __app_ngap_set_QosFlowAddOrModifyResponseList( SI_AMF_DT_QosFlowAddOrModifyResponseList ** data)
{
	__si_amf_init_QosFlowAddOrModifyResponseList( data);
	SI_AMF_DT_QosFlowAddOrModifyResponseList * qosFlowAddOrModifyResponseList = *data;
	
	SI_AMF_DT_QosFlowAddOrModifyResponseItem * objItem = NULL;

	__app_ngap_set_QosFlowAddOrModifyResponseItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowAddOrModifyResponseItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowAddOrModifyResponseItem
void __app_ngap_set_QosFlowAddOrModifyResponseItem( SI_AMF_DT_QosFlowAddOrModifyResponseItem ** data)
{
	__si_amf_init_QosFlowAddOrModifyResponseItem( data);
	SI_AMF_DT_QosFlowAddOrModifyResponseItem * qosFlowAddOrModifyResponseItem = *data;
	
	qosFlowAddOrModifyResponseItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
}


//-- CONTAINER, QosFlowAddOrModifyResponseItem-ExtIEs
void __app_ngap_set_QosFlowAddOrModifyResponseItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowAddOrModifyResponseItem_ExtIEs( data);
	SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs * qosFlowAddOrModifyResponseItem_ExtIEs = *data;
	
}


//-- INTEGER, QosFlowIdentifier
void __app_ngap_set_QosFlowIdentifier( SI_AMF_DT_QosFlowIdentifier ** data)
{
	SI_AMF_DT_QosFlowIdentifier * qosFlowIdentifier = *data;
	
	//MIN = 0, MAX = 63
	qosFlowIdentifier->data = __si_core_getU64RANDRange( 0, 63);
}


//-- SEQUENCE_OF, QosFlowInformationList
void __app_ngap_set_QosFlowInformationList( SI_AMF_DT_QosFlowInformationList ** data)
{
	__si_amf_init_QosFlowInformationList( data);
	SI_AMF_DT_QosFlowInformationList * qosFlowInformationList = *data;
	
	SI_AMF_DT_QosFlowInformationItem * objItem = NULL;

	__app_ngap_set_QosFlowInformationItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowInformationItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowInformationItem
void __app_ngap_set_QosFlowInformationItem( SI_AMF_DT_QosFlowInformationItem ** data)
{
	__si_amf_init_QosFlowInformationItem( data);
	SI_AMF_DT_QosFlowInformationItem * qosFlowInformationItem = *data;
	
	qosFlowInformationItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	qosFlowInformationItem->selected_edLForwarding = 0;
}


//-- CONTAINER, QosFlowInformationItem-ExtIEs
void __app_ngap_set_QosFlowInformationItem_ExtIEs( SI_AMF_DT_QosFlowInformationItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowInformationItem_ExtIEs( data);
	SI_AMF_DT_QosFlowInformationItem_ExtIEs * qosFlowInformationItem_ExtIEs = *data;
	
}


//-- SEQUENCE, QosFlowLevelQosParameters
void __app_ngap_set_QosFlowLevelQosParameters( SI_AMF_DT_QosFlowLevelQosParameters ** data)
{
	__si_amf_init_QosFlowLevelQosParameters( data);
	SI_AMF_DT_QosFlowLevelQosParameters * qosFlowLevelQosParameters = *data;
	
	__app_ngap_set_QosCharacteristics( &qosFlowLevelQosParameters->qosCharacteristics);

	__app_ngap_set_AllocationAndRetentionPriority( &qosFlowLevelQosParameters->allocationAndRetentionPriority);

	__app_ngap_set_GBR_QosInformation( &qosFlowLevelQosParameters->gBR_QosInformation);
	qosFlowLevelQosParameters->isPresent_gBR_QosInformation = 1;

	qosFlowLevelQosParameters->selected_ereflectiveQosAttribute = 0;
	qosFlowLevelQosParameters->selected_eadditionalQosFlowInformation = 0;
}


//-- CONTAINER, QosFlowLevelQosParameters-ExtIEs
void __app_ngap_set_QosFlowLevelQosParameters_ExtIEs( SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs ** data)
{
	__si_amf_init_QosFlowLevelQosParameters_ExtIEs( data);
	SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs * qosFlowLevelQosParameters_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowListWithCause
void __app_ngap_set_QosFlowListWithCause( SI_AMF_DT_QosFlowListWithCause ** data)
{
	__si_amf_init_QosFlowListWithCause( data);
	SI_AMF_DT_QosFlowListWithCause * qosFlowListWithCause = *data;
	
	SI_AMF_DT_QosFlowWithCauseItem * objItem = NULL;

	__app_ngap_set_QosFlowWithCauseItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowWithCauseItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowWithCauseItem
void __app_ngap_set_QosFlowWithCauseItem( SI_AMF_DT_QosFlowWithCauseItem ** data)
{
	__si_amf_init_QosFlowWithCauseItem( data);
	SI_AMF_DT_QosFlowWithCauseItem * qosFlowWithCauseItem = *data;
	
	qosFlowWithCauseItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	__app_ngap_set_Cause( &qosFlowWithCauseItem->cause);
}


//-- CONTAINER, QosFlowWithCauseItem-ExtIEs
void __app_ngap_set_QosFlowWithCauseItem_ExtIEs( SI_AMF_DT_QosFlowWithCauseItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowWithCauseItem_ExtIEs( data);
	SI_AMF_DT_QosFlowWithCauseItem_ExtIEs * qosFlowWithCauseItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowModifyConfirmList
void __app_ngap_set_QosFlowModifyConfirmList( SI_AMF_DT_QosFlowModifyConfirmList ** data)
{
	__si_amf_init_QosFlowModifyConfirmList( data);
	SI_AMF_DT_QosFlowModifyConfirmList * qosFlowModifyConfirmList = *data;
	
	SI_AMF_DT_QosFlowModifyConfirmItem * objItem = NULL;

	__app_ngap_set_QosFlowModifyConfirmItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowModifyConfirmItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowModifyConfirmItem
void __app_ngap_set_QosFlowModifyConfirmItem( SI_AMF_DT_QosFlowModifyConfirmItem ** data)
{
	__si_amf_init_QosFlowModifyConfirmItem( data);
	SI_AMF_DT_QosFlowModifyConfirmItem * qosFlowModifyConfirmItem = *data;
	
	qosFlowModifyConfirmItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
}


//-- CONTAINER, QosFlowModifyConfirmItem-ExtIEs
void __app_ngap_set_QosFlowModifyConfirmItem_ExtIEs( SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowModifyConfirmItem_ExtIEs( data);
	SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs * qosFlowModifyConfirmItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowNotifyList
void __app_ngap_set_QosFlowNotifyList( SI_AMF_DT_QosFlowNotifyList ** data)
{
	__si_amf_init_QosFlowNotifyList( data);
	SI_AMF_DT_QosFlowNotifyList * qosFlowNotifyList = *data;
	
	SI_AMF_DT_QosFlowNotifyItem * objItem = NULL;

	__app_ngap_set_QosFlowNotifyItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowNotifyItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowNotifyItem
void __app_ngap_set_QosFlowNotifyItem( SI_AMF_DT_QosFlowNotifyItem ** data)
{
	__si_amf_init_QosFlowNotifyItem( data);
	SI_AMF_DT_QosFlowNotifyItem * qosFlowNotifyItem = *data;
	
	qosFlowNotifyItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	qosFlowNotifyItem->selected_enotificationCause = 0;
}


//-- CONTAINER, QosFlowNotifyItem-ExtIEs
void __app_ngap_set_QosFlowNotifyItem_ExtIEs( SI_AMF_DT_QosFlowNotifyItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowNotifyItem_ExtIEs( data);
	SI_AMF_DT_QosFlowNotifyItem_ExtIEs * qosFlowNotifyItem_ExtIEs = *data;
	
}


//-- SEQUENCE, QosFlowPerTNLInformation
void __app_ngap_set_QosFlowPerTNLInformation( SI_AMF_DT_QosFlowPerTNLInformation ** data)
{
	__si_amf_init_QosFlowPerTNLInformation( data);
	SI_AMF_DT_QosFlowPerTNLInformation * qosFlowPerTNLInformation = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &qosFlowPerTNLInformation->uPTransportLayerInformation);

	__app_ngap_set_AssociatedQosFlowList( &qosFlowPerTNLInformation->associatedQosFlowList);
}


//-- CONTAINER, QosFlowPerTNLInformation-ExtIEs
void __app_ngap_set_QosFlowPerTNLInformation_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs ** data)
{
	__si_amf_init_QosFlowPerTNLInformation_ExtIEs( data);
	SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs * qosFlowPerTNLInformation_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowPerTNLInformationList
void __app_ngap_set_QosFlowPerTNLInformationList( SI_AMF_DT_QosFlowPerTNLInformationList ** data)
{
	__si_amf_init_QosFlowPerTNLInformationList( data);
	SI_AMF_DT_QosFlowPerTNLInformationList * qosFlowPerTNLInformationList = *data;
	
	SI_AMF_DT_QosFlowPerTNLInformationItem * objItem = NULL;

	__app_ngap_set_QosFlowPerTNLInformationItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowPerTNLInformationItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowPerTNLInformationItem
void __app_ngap_set_QosFlowPerTNLInformationItem( SI_AMF_DT_QosFlowPerTNLInformationItem ** data)
{
	__si_amf_init_QosFlowPerTNLInformationItem( data);
	SI_AMF_DT_QosFlowPerTNLInformationItem * qosFlowPerTNLInformationItem = *data;
	
	__app_ngap_set_QosFlowPerTNLInformation( &qosFlowPerTNLInformationItem->qosFlowPerTNLInformation);
}


//-- CONTAINER, QosFlowPerTNLInformationItem-ExtIEs
void __app_ngap_set_QosFlowPerTNLInformationItem_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowPerTNLInformationItem_ExtIEs( data);
	SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs * qosFlowPerTNLInformationItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowSetupRequestList
void __app_ngap_set_QosFlowSetupRequestList( SI_AMF_DT_QosFlowSetupRequestList ** data)
{
	__si_amf_init_QosFlowSetupRequestList( data);
	SI_AMF_DT_QosFlowSetupRequestList * qosFlowSetupRequestList = *data;
	
	SI_AMF_DT_QosFlowSetupRequestItem * objItem = NULL;

	__app_ngap_set_QosFlowSetupRequestItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowSetupRequestItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowSetupRequestItem
void __app_ngap_set_QosFlowSetupRequestItem( SI_AMF_DT_QosFlowSetupRequestItem ** data)
{
	__si_amf_init_QosFlowSetupRequestItem( data);
	SI_AMF_DT_QosFlowSetupRequestItem * qosFlowSetupRequestItem = *data;
	
	qosFlowSetupRequestItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	__app_ngap_set_QosFlowLevelQosParameters( &qosFlowSetupRequestItem->qosFlowLevelQosParameters);

	qosFlowSetupRequestItem->e_RAB_ID = __si_core_getU64RANDRange( 0, 15);
}


//-- CONTAINER, QosFlowSetupRequestItem-ExtIEs
void __app_ngap_set_QosFlowSetupRequestItem_ExtIEs( SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowSetupRequestItem_ExtIEs( data);
	SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs * qosFlowSetupRequestItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowListWithDataForwarding
void __app_ngap_set_QosFlowListWithDataForwarding( SI_AMF_DT_QosFlowListWithDataForwarding ** data)
{
	__si_amf_init_QosFlowListWithDataForwarding( data);
	SI_AMF_DT_QosFlowListWithDataForwarding * qosFlowListWithDataForwarding = *data;
	
	SI_AMF_DT_QosFlowItemWithDataForwarding * objItem = NULL;

	__app_ngap_set_QosFlowItemWithDataForwarding( &objItem);
	__si_linked_list_add( (*data)->QosFlowItemWithDataForwarding, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowItemWithDataForwarding
void __app_ngap_set_QosFlowItemWithDataForwarding( SI_AMF_DT_QosFlowItemWithDataForwarding ** data)
{
	__si_amf_init_QosFlowItemWithDataForwarding( data);
	SI_AMF_DT_QosFlowItemWithDataForwarding * qosFlowItemWithDataForwarding = *data;
	
	qosFlowItemWithDataForwarding->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	qosFlowItemWithDataForwarding->selected_edataForwardingAccepted = 0;
}


//-- CONTAINER, QosFlowItemWithDataForwarding-ExtIEs
void __app_ngap_set_QosFlowItemWithDataForwarding_ExtIEs( SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs ** data)
{
	__si_amf_init_QosFlowItemWithDataForwarding_ExtIEs( data);
	SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs * qosFlowItemWithDataForwarding_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowSetupResponseListSURes
void __app_ngap_set_QosFlowSetupResponseListSURes( SI_AMF_DT_QosFlowSetupResponseListSURes ** data)
{
	__si_amf_init_QosFlowSetupResponseListSURes( data);
	SI_AMF_DT_QosFlowSetupResponseListSURes * qosFlowSetupResponseListSURes = *data;
	
	SI_AMF_DT_QosFlowSetupResponseItemSURes * objItem = NULL;

	__app_ngap_set_QosFlowSetupResponseItemSURes( &objItem);
	__si_linked_list_add( (*data)->QosFlowSetupResponseItemSURes, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowSetupResponseItemSURes
void __app_ngap_set_QosFlowSetupResponseItemSURes( SI_AMF_DT_QosFlowSetupResponseItemSURes ** data)
{
	__si_amf_init_QosFlowSetupResponseItemSURes( data);
	SI_AMF_DT_QosFlowSetupResponseItemSURes * qosFlowSetupResponseItemSURes = *data;
	
	qosFlowSetupResponseItemSURes->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
}


//-- CONTAINER, QosFlowSetupResponseItemSURes-ExtIEs
void __app_ngap_set_QosFlowSetupResponseItemSURes_ExtIEs( SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs ** data)
{
	__si_amf_init_QosFlowSetupResponseItemSURes_ExtIEs( data);
	SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs * qosFlowSetupResponseItemSURes_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QosFlowToBeForwardedList
void __app_ngap_set_QosFlowToBeForwardedList( SI_AMF_DT_QosFlowToBeForwardedList ** data)
{
	__si_amf_init_QosFlowToBeForwardedList( data);
	SI_AMF_DT_QosFlowToBeForwardedList * qosFlowToBeForwardedList = *data;
	
	SI_AMF_DT_QosFlowToBeForwardedItem * objItem = NULL;

	__app_ngap_set_QosFlowToBeForwardedItem( &objItem);
	__si_linked_list_add( (*data)->QosFlowToBeForwardedItem, (uint8_t *)objItem);
}


//-- SEQUENCE, QosFlowToBeForwardedItem
void __app_ngap_set_QosFlowToBeForwardedItem( SI_AMF_DT_QosFlowToBeForwardedItem ** data)
{
	__si_amf_init_QosFlowToBeForwardedItem( data);
	SI_AMF_DT_QosFlowToBeForwardedItem * qosFlowToBeForwardedItem = *data;
	
	qosFlowToBeForwardedItem->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
}


//-- CONTAINER, QosFlowToBeForwardedItem-ExtIEs
void __app_ngap_set_QosFlowToBeForwardedItem_ExtIEs( SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs ** data)
{
	__si_amf_init_QosFlowToBeForwardedItem_ExtIEs( data);
	SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs * qosFlowToBeForwardedItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, QoSFlowsUsageReportList
void __app_ngap_set_QoSFlowsUsageReportList( SI_AMF_DT_QoSFlowsUsageReportList ** data)
{
	__si_amf_init_QoSFlowsUsageReportList( data);
	SI_AMF_DT_QoSFlowsUsageReportList * qoSFlowsUsageReportList = *data;
	
	SI_AMF_DT_QoSFlowsUsageReport_Item * objItem = NULL;

	__app_ngap_set_QoSFlowsUsageReport_Item( &objItem);
	__si_linked_list_add( (*data)->QoSFlowsUsageReport_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, QoSFlowsUsageReport-Item
void __app_ngap_set_QoSFlowsUsageReport_Item( SI_AMF_DT_QoSFlowsUsageReport_Item ** data)
{
	__si_amf_init_QoSFlowsUsageReport_Item( data);
	SI_AMF_DT_QoSFlowsUsageReport_Item * qoSFlowsUsageReport_Item = *data;
	
	qoSFlowsUsageReport_Item->qosFlowIdentifier = __si_core_getU64RANDRange( 0, 63);
	qoSFlowsUsageReport_Item->selected_erATType = 0;
	__app_ngap_set_VolumeTimedReportList( &qoSFlowsUsageReport_Item->qoSFlowsTimedReportList);
}


//-- CONTAINER, QoSFlowsUsageReport-Item-ExtIEs
void __app_ngap_set_QoSFlowsUsageReport_Item_ExtIEs( SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs ** data)
{
	__si_amf_init_QoSFlowsUsageReport_Item_ExtIEs( data);
	SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs * qoSFlowsUsageReport_Item_ExtIEs = *data;
	
}


//-- PrintableString, RANNodeName
void __app_ngap_set_RANNodeName( SI_AMF_DT_RANNodeName ** data)
{
	__si_amf_init_RANNodeName( data);
	SI_AMF_DT_RANNodeName * rANNodeName = *data;
	
	rANNodeName->data = (unsigned char *) __si_allocM(150);
	rANNodeName->length = 150;
	__si_core_fill_dummy_data( rANNodeName->data, rANNodeName->length);
}


//-- INTEGER, RANPagingPriority
void __app_ngap_set_RANPagingPriority( SI_AMF_DT_RANPagingPriority ** data)
{
	SI_AMF_DT_RANPagingPriority * rANPagingPriority = *data;
	
	//MIN = 1, MAX = 256
	rANPagingPriority->data = __si_core_getU64RANDRange( 1, 256);
}


//-- SEQUENCE, RANStatusTransfer-TransparentContainer
void __app_ngap_set_RANStatusTransfer_TransparentContainer( SI_AMF_DT_RANStatusTransfer_TransparentContainer ** data)
{
	__si_amf_init_RANStatusTransfer_TransparentContainer( data);
	SI_AMF_DT_RANStatusTransfer_TransparentContainer * rANStatusTransfer_TransparentContainer = *data;
	
	__app_ngap_set_DRBsSubjectToStatusTransferList( &rANStatusTransfer_TransparentContainer->dRBsSubjectToStatusTransferList);
}


//-- CONTAINER, RANStatusTransfer-TransparentContainer-ExtIEs
void __app_ngap_set_RANStatusTransfer_TransparentContainer_ExtIEs( SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs ** data)
{
	__si_amf_init_RANStatusTransfer_TransparentContainer_ExtIEs( data);
	SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs * rANStatusTransfer_TransparentContainer_ExtIEs = *data;
	
}


//-- INTEGER, RAN-UE-NGAP-ID
void __app_ngap_set_RAN_UE_NGAP_ID( SI_AMF_DT_RAN_UE_NGAP_ID ** data)
{
	SI_AMF_DT_RAN_UE_NGAP_ID * rAN_UE_NGAP_ID = *data;
	
	//MIN = 0, MAX = 4294967295
	rAN_UE_NGAP_ID->data = __si_core_getU64RANDRange( 0, 4294967295);
}


//-- SEQUENCE_OF, RATRestrictions
void __app_ngap_set_RATRestrictions( SI_AMF_DT_RATRestrictions ** data)
{
	__si_amf_init_RATRestrictions( data);
	SI_AMF_DT_RATRestrictions * rATRestrictions = *data;
	
	SI_AMF_DT_RATRestrictions_Item * objItem = NULL;

	__app_ngap_set_RATRestrictions_Item( &objItem);
	__si_linked_list_add( (*data)->RATRestrictions_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, RATRestrictions-Item
void __app_ngap_set_RATRestrictions_Item( SI_AMF_DT_RATRestrictions_Item ** data)
{
	__si_amf_init_RATRestrictions_Item( data);
	SI_AMF_DT_RATRestrictions_Item * rATRestrictions_Item = *data;
	
	__app_ngap_set_PLMNIdentity( &rATRestrictions_Item->pLMNIdentity);

	__app_ngap_set_RATRestrictionInformation( &rATRestrictions_Item->rATRestrictionInformation);
}


//-- CONTAINER, RATRestrictions-Item-ExtIEs
void __app_ngap_set_RATRestrictions_Item_ExtIEs( SI_AMF_DT_RATRestrictions_Item_ExtIEs ** data)
{
	__si_amf_init_RATRestrictions_Item_ExtIEs( data);
	SI_AMF_DT_RATRestrictions_Item_ExtIEs * rATRestrictions_Item_ExtIEs = *data;
	
}


//-- BITSTRING, RATRestrictionInformation
void __app_ngap_set_RATRestrictionInformation( SI_AMF_DT_RATRestrictionInformation ** data)
{
	__si_amf_init_RATRestrictionInformation( data);
	SI_AMF_DT_RATRestrictionInformation * rATRestrictionInformation = *data;
	
	//BITSIZE = 8  , BIT STRING(SIZE(8,...))
	rATRestrictionInformation->data = (unsigned char *) __si_allocM(2);
	rATRestrictionInformation->length = 2;
	rATRestrictionInformation->bitslen = 8;
	//__si_core_fill_dummy_data( rATRestrictionInformation->data, rATRestrictionInformation->length);
	rATRestrictionInformation->data[0] = 0x00;
}


//-- SEQUENCE, RecommendedCellsForPaging
void __app_ngap_set_RecommendedCellsForPaging( SI_AMF_DT_RecommendedCellsForPaging ** data)
{
	__si_amf_init_RecommendedCellsForPaging( data);
	SI_AMF_DT_RecommendedCellsForPaging * recommendedCellsForPaging = *data;
	
	__app_ngap_set_RecommendedCellList( &recommendedCellsForPaging->recommendedCellList);
}


//-- CONTAINER, RecommendedCellsForPaging-ExtIEs
void __app_ngap_set_RecommendedCellsForPaging_ExtIEs( SI_AMF_DT_RecommendedCellsForPaging_ExtIEs ** data)
{
	__si_amf_init_RecommendedCellsForPaging_ExtIEs( data);
	SI_AMF_DT_RecommendedCellsForPaging_ExtIEs * recommendedCellsForPaging_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, RecommendedCellList
void __app_ngap_set_RecommendedCellList( SI_AMF_DT_RecommendedCellList ** data)
{
	__si_amf_init_RecommendedCellList( data);
	SI_AMF_DT_RecommendedCellList * recommendedCellList = *data;
	
	SI_AMF_DT_RecommendedCellItem * objItem = NULL;

	__app_ngap_set_RecommendedCellItem( &objItem);
	__si_linked_list_add( (*data)->RecommendedCellItem, (uint8_t *)objItem);
}


//-- INTEGER, RecommendedCellItemTime
void __app_ngap_set_RecommendedCellItemTime( SI_AMF_DT_RecommendedCellItemTime ** data)
{
	SI_AMF_DT_RecommendedCellItemTime * recommendedCellItemTime = *data;
	
	//MIN = 0, MAX = 4095
	recommendedCellItemTime->data = __si_core_getU64RANDRange( 0, 4095);
}


//-- SEQUENCE, RecommendedCellItem
void __app_ngap_set_RecommendedCellItem( SI_AMF_DT_RecommendedCellItem ** data)
{
	__si_amf_init_RecommendedCellItem( data);
	SI_AMF_DT_RecommendedCellItem * recommendedCellItem = *data;
	
	__app_ngap_set_NGRAN_CGI( &recommendedCellItem->nGRAN_CGI);

	recommendedCellItem->timeStayedInCell = __si_core_getU64RANDRange( 0, 4095);
}


//-- CONTAINER, RecommendedCellItem-ExtIEs
void __app_ngap_set_RecommendedCellItem_ExtIEs( SI_AMF_DT_RecommendedCellItem_ExtIEs ** data)
{
	__si_amf_init_RecommendedCellItem_ExtIEs( data);
	SI_AMF_DT_RecommendedCellItem_ExtIEs * recommendedCellItem_ExtIEs = *data;
	
}


//-- SEQUENCE, RecommendedRANNodesForPaging
void __app_ngap_set_RecommendedRANNodesForPaging( SI_AMF_DT_RecommendedRANNodesForPaging ** data)
{
	__si_amf_init_RecommendedRANNodesForPaging( data);
	SI_AMF_DT_RecommendedRANNodesForPaging * recommendedRANNodesForPaging = *data;
	
	__app_ngap_set_RecommendedRANNodeList( &recommendedRANNodesForPaging->recommendedRANNodeList);
}


//-- CONTAINER, RecommendedRANNodesForPaging-ExtIEs
void __app_ngap_set_RecommendedRANNodesForPaging_ExtIEs( SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs ** data)
{
	__si_amf_init_RecommendedRANNodesForPaging_ExtIEs( data);
	SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs * recommendedRANNodesForPaging_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, RecommendedRANNodeList
void __app_ngap_set_RecommendedRANNodeList( SI_AMF_DT_RecommendedRANNodeList ** data)
{
	__si_amf_init_RecommendedRANNodeList( data);
	SI_AMF_DT_RecommendedRANNodeList * recommendedRANNodeList = *data;
	
	SI_AMF_DT_RecommendedRANNodeItem * objItem = NULL;

	__app_ngap_set_RecommendedRANNodeItem( &objItem);
	__si_linked_list_add( (*data)->RecommendedRANNodeItem, (uint8_t *)objItem);
}


//-- SEQUENCE, RecommendedRANNodeItem
void __app_ngap_set_RecommendedRANNodeItem( SI_AMF_DT_RecommendedRANNodeItem ** data)
{
	__si_amf_init_RecommendedRANNodeItem( data);
	SI_AMF_DT_RecommendedRANNodeItem * recommendedRANNodeItem = *data;
	
	__app_ngap_set_AMFPagingTarget( &recommendedRANNodeItem->aMFPagingTarget);
}


//-- CONTAINER, RecommendedRANNodeItem-ExtIEs
void __app_ngap_set_RecommendedRANNodeItem_ExtIEs( SI_AMF_DT_RecommendedRANNodeItem_ExtIEs ** data)
{
	__si_amf_init_RecommendedRANNodeItem_ExtIEs( data);
	SI_AMF_DT_RecommendedRANNodeItem_ExtIEs * recommendedRANNodeItem_ExtIEs = *data;
	
}


//-- INTEGER, ReferenceID
void __app_ngap_set_ReferenceID( SI_AMF_DT_ReferenceID ** data)
{
	SI_AMF_DT_ReferenceID * referenceID = *data;
	
	//MIN = 1, MAX = 64
	referenceID->data = __si_core_getU64RANDRange( 1, 64);
}


//-- INTEGER, RelativeAMFCapacity
void __app_ngap_set_RelativeAMFCapacity( SI_AMF_DT_RelativeAMFCapacity ** data)
{
	SI_AMF_DT_RelativeAMFCapacity * relativeAMFCapacity = *data;
	
	//MIN = 0, MAX = 255
	relativeAMFCapacity->data = __si_core_getU64RANDRange( 0, 255);
}


//-- INTEGER, RepetitionPeriod
void __app_ngap_set_RepetitionPeriod( SI_AMF_DT_RepetitionPeriod ** data)
{
	SI_AMF_DT_RepetitionPeriod * repetitionPeriod = *data;
	
	//MIN = 0, MAX = 131071
	repetitionPeriod->data = __si_core_getU64RANDRange( 0, 131071);
}


//-- CHOICE, ResetType
void __app_ngap_set_ResetType( SI_AMF_DT_ResetType ** data)
{
	__si_amf_init_ResetType( data);
	SI_AMF_DT_ResetType * resetType = *data;
	
	(*data)->SelectedChoice = 0;

	//(*data)->u.nG_Interface = 1;
	__app_ngap_set_UE_associatedLogicalNG_connectionList( &(*data)->u.partOfNG_Interface);
}


//-- CONTAINER, ResetType-ExtIEs
void __app_ngap_set_ResetType_ExtIEs( SI_AMF_DT_ResetType_ExtIEs ** data)
{
	__si_amf_init_ResetType_ExtIEs( data);
	SI_AMF_DT_ResetType_ExtIEs * resetType_ExtIEs = *data;
	
}


//-- OCTETSTRING, RoutingID
void __app_ngap_set_RoutingID( SI_AMF_DT_RoutingID ** data)
{
	__si_amf_init_RoutingID( data);
	SI_AMF_DT_RoutingID * routingID = *data;
	
	routingID->data = (unsigned char *) __si_allocM(0);
	routingID->length = 0;
	__si_core_fill_dummy_data( routingID->data, routingID->length);
}


//-- OCTETSTRING, RRCContainer
void __app_ngap_set_RRCContainer( SI_AMF_DT_RRCContainer ** data)
{
	__si_amf_init_RRCContainer( data);
	SI_AMF_DT_RRCContainer * rRCContainer = *data;
	
	rRCContainer->data = (unsigned char *) __si_allocM(0);
	rRCContainer->length = 0;
	__si_core_fill_dummy_data( rRCContainer->data, rRCContainer->length);
}


//-- SEQUENCE_OF, SCTP-TLAs
void __app_ngap_set_SCTP_TLAs( SI_AMF_DT_SCTP_TLAs ** data)
{
	__si_amf_init_SCTP_TLAs( data);
	SI_AMF_DT_SCTP_TLAs * sCTP_TLAs = *data;
	
	SI_AMF_DT_TransportLayerAddress * objItem = NULL;

	__app_ngap_set_TransportLayerAddress( &objItem);
	__si_linked_list_add( (*data)->TransportLayerAddress, (uint8_t *)objItem);
}


//-- OCTETSTRING, SD
void __app_ngap_set_SD( SI_AMF_DT_SD ** data)
{
	__si_amf_init_SD( data);
	SI_AMF_DT_SD * sD = *data;
	
	sD->data = (unsigned char *) __si_allocM(3);
	sD->length = 3;
	__si_core_fill_dummy_data( sD->data, sD->length);
}


//-- SEQUENCE, SecondaryRATUsageInformation
void __app_ngap_set_SecondaryRATUsageInformation( SI_AMF_DT_SecondaryRATUsageInformation ** data)
{
	__si_amf_init_SecondaryRATUsageInformation( data);
	SI_AMF_DT_SecondaryRATUsageInformation * secondaryRATUsageInformation = *data;
	
	__app_ngap_set_PDUSessionUsageReport( &secondaryRATUsageInformation->pDUSessionUsageReport);
	secondaryRATUsageInformation->isPresent_pDUSessionUsageReport = 1;

	__app_ngap_set_QoSFlowsUsageReportList( &secondaryRATUsageInformation->qosFlowsUsageReportList);
	secondaryRATUsageInformation->isPresent_qosFlowsUsageReportList = 1;
}


//-- CONTAINER, SecondaryRATUsageInformation-ExtIEs
void __app_ngap_set_SecondaryRATUsageInformation_ExtIEs( SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs ** data)
{
	__si_amf_init_SecondaryRATUsageInformation_ExtIEs( data);
	SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs * secondaryRATUsageInformation_ExtIEs = *data;
	
}


//-- SEQUENCE, SecondaryRATDataUsageReportTransfer
void __app_ngap_set_SecondaryRATDataUsageReportTransfer( SI_AMF_DT_SecondaryRATDataUsageReportTransfer ** data)
{
	__si_amf_init_SecondaryRATDataUsageReportTransfer( data);
	SI_AMF_DT_SecondaryRATDataUsageReportTransfer * secondaryRATDataUsageReportTransfer = *data;
	
	__app_ngap_set_SecondaryRATUsageInformation( &secondaryRATDataUsageReportTransfer->secondaryRATUsageInformation);
	secondaryRATDataUsageReportTransfer->isPresent_secondaryRATUsageInformation = 1;
}


//-- CONTAINER, SecondaryRATDataUsageReportTransfer-ExtIEs
void __app_ngap_set_SecondaryRATDataUsageReportTransfer_ExtIEs( SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs ** data)
{
	__si_amf_init_SecondaryRATDataUsageReportTransfer_ExtIEs( data);
	SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs * secondaryRATDataUsageReportTransfer_ExtIEs = *data;
	
}


//-- SEQUENCE, SecurityContext
void __app_ngap_set_SecurityContext( SI_AMF_DT_SecurityContext ** data)
{
	__si_amf_init_SecurityContext( data);
	SI_AMF_DT_SecurityContext * securityContext = *data;
	
	securityContext->nextHopChainingCount = __si_core_getU64RANDRange( 0, 7);
	__app_ngap_set_SecurityKey( &securityContext->nextHopNH);
}


//-- CONTAINER, SecurityContext-ExtIEs
void __app_ngap_set_SecurityContext_ExtIEs( SI_AMF_DT_SecurityContext_ExtIEs ** data)
{
	__si_amf_init_SecurityContext_ExtIEs( data);
	SI_AMF_DT_SecurityContext_ExtIEs * securityContext_ExtIEs = *data;
	
}


//-- SEQUENCE, SecurityIndication
void __app_ngap_set_SecurityIndication( SI_AMF_DT_SecurityIndication ** data)
{
	__si_amf_init_SecurityIndication( data);
	SI_AMF_DT_SecurityIndication * securityIndication = *data;
	
	securityIndication->selected_eintegrityProtectionIndication = 0;
	securityIndication->selected_econfidentialityProtectionIndication = 0;
	securityIndication->selected_emaximumIntegrityProtectedDataRate_UL = 0;
}


//-- CONTAINER, SecurityIndication-ExtIEs
void __app_ngap_set_SecurityIndication_ExtIEs( SI_AMF_DT_SecurityIndication_ExtIEs ** data)
{
	__si_amf_init_SecurityIndication_ExtIEs( data);
	SI_AMF_DT_SecurityIndication_ExtIEs * securityIndication_ExtIEs = *data;
	
}


//-- BITSTRING, SecurityKey
void __app_ngap_set_SecurityKey( SI_AMF_DT_SecurityKey ** data)
{
	__si_amf_init_SecurityKey( data);
	SI_AMF_DT_SecurityKey * securityKey = *data;
	
	//BITSIZE = 256  , BIT STRING(SIZE(256))
	securityKey->data = (unsigned char *) __si_allocM(33);
	securityKey->length = 33;
	securityKey->bitslen = 256;
	__si_core_fill_dummy_data( securityKey->data, securityKey->length);
}


//-- SEQUENCE, SecurityResult
void __app_ngap_set_SecurityResult( SI_AMF_DT_SecurityResult ** data)
{
	__si_amf_init_SecurityResult( data);
	SI_AMF_DT_SecurityResult * securityResult = *data;
	
	securityResult->selected_eintegrityProtectionResult = 0;
	securityResult->selected_econfidentialityProtectionResult = 0;
}


//-- CONTAINER, SecurityResult-ExtIEs
void __app_ngap_set_SecurityResult_ExtIEs( SI_AMF_DT_SecurityResult_ExtIEs ** data)
{
	__si_amf_init_SecurityResult_ExtIEs( data);
	SI_AMF_DT_SecurityResult_ExtIEs * securityResult_ExtIEs = *data;
	
}


//-- BITSTRING, SerialNumber
void __app_ngap_set_SerialNumber( SI_AMF_DT_SerialNumber ** data)
{
	__si_amf_init_SerialNumber( data);
	SI_AMF_DT_SerialNumber * serialNumber = *data;
	
	//BITSIZE = 16  , BIT STRING(SIZE(16))
	serialNumber->data = (unsigned char *) __si_allocM(3);
	serialNumber->length = 3;
	serialNumber->bitslen = 16;
	__si_core_fill_dummy_data( serialNumber->data, serialNumber->length);
}


//-- SEQUENCE_OF, ServedGUAMIList
void __app_ngap_set_ServedGUAMIList( SI_AMF_DT_ServedGUAMIList ** data)
{
	__si_amf_init_ServedGUAMIList( data);
	SI_AMF_DT_ServedGUAMIList * servedGUAMIList = *data;
	
	SI_AMF_DT_ServedGUAMIItem * objItem = NULL;

	__app_ngap_set_ServedGUAMIItem( &objItem);
	__si_linked_list_add( (*data)->ServedGUAMIItem, (uint8_t *)objItem);
}


//-- SEQUENCE, ServedGUAMIItem
void __app_ngap_set_ServedGUAMIItem( SI_AMF_DT_ServedGUAMIItem ** data)
{
	__si_amf_init_ServedGUAMIItem( data);
	SI_AMF_DT_ServedGUAMIItem * servedGUAMIItem = *data;
	
	__app_ngap_set_GUAMI( &servedGUAMIItem->gUAMI);

	__app_ngap_set_AMFName( &servedGUAMIItem->backupAMFName);
	servedGUAMIItem->isPresent_backupAMFName = 1;
}


//-- CONTAINER, ServedGUAMIItem-ExtIEs
void __app_ngap_set_ServedGUAMIItem_ExtIEs( SI_AMF_DT_ServedGUAMIItem_ExtIEs ** data)
{
	__si_amf_init_ServedGUAMIItem_ExtIEs( data);
	SI_AMF_DT_ServedGUAMIItem_ExtIEs * servedGUAMIItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, ServiceAreaInformation
void __app_ngap_set_ServiceAreaInformation( SI_AMF_DT_ServiceAreaInformation ** data)
{
	__si_amf_init_ServiceAreaInformation( data);
	SI_AMF_DT_ServiceAreaInformation * serviceAreaInformation = *data;
	
	SI_AMF_DT_ServiceAreaInformation_Item * objItem = NULL;

	__app_ngap_set_ServiceAreaInformation_Item( &objItem);
	__si_linked_list_add( (*data)->ServiceAreaInformation_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, ServiceAreaInformation-Item
void __app_ngap_set_ServiceAreaInformation_Item( SI_AMF_DT_ServiceAreaInformation_Item ** data)
{
	__si_amf_init_ServiceAreaInformation_Item( data);
	SI_AMF_DT_ServiceAreaInformation_Item * serviceAreaInformation_Item = *data;
	
	__app_ngap_set_PLMNIdentity( &serviceAreaInformation_Item->pLMNIdentity);

	__app_ngap_set_AllowedTACs( &serviceAreaInformation_Item->allowedTACs);
	serviceAreaInformation_Item->isPresent_allowedTACs = 1;

	__app_ngap_set_NotAllowedTACs( &serviceAreaInformation_Item->notAllowedTACs);
	serviceAreaInformation_Item->isPresent_notAllowedTACs = 1;
}


//-- CONTAINER, ServiceAreaInformation-Item-ExtIEs
void __app_ngap_set_ServiceAreaInformation_Item_ExtIEs( SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs ** data)
{
	__si_amf_init_ServiceAreaInformation_Item_ExtIEs( data);
	SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs * serviceAreaInformation_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, SliceOverloadList
void __app_ngap_set_SliceOverloadList( SI_AMF_DT_SliceOverloadList ** data)
{
	__si_amf_init_SliceOverloadList( data);
	SI_AMF_DT_SliceOverloadList * sliceOverloadList = *data;
	
	SI_AMF_DT_SliceOverloadItem * objItem = NULL;

	__app_ngap_set_SliceOverloadItem( &objItem);
	__si_linked_list_add( (*data)->SliceOverloadItem, (uint8_t *)objItem);
}


//-- SEQUENCE, SliceOverloadItem
void __app_ngap_set_SliceOverloadItem( SI_AMF_DT_SliceOverloadItem ** data)
{
	__si_amf_init_SliceOverloadItem( data);
	SI_AMF_DT_SliceOverloadItem * sliceOverloadItem = *data;
	
	__app_ngap_set_S_NSSAI( &sliceOverloadItem->s_NSSAI);
}


//-- CONTAINER, SliceOverloadItem-ExtIEs
void __app_ngap_set_SliceOverloadItem_ExtIEs( SI_AMF_DT_SliceOverloadItem_ExtIEs ** data)
{
	__si_amf_init_SliceOverloadItem_ExtIEs( data);
	SI_AMF_DT_SliceOverloadItem_ExtIEs * sliceOverloadItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, SliceSupportList
void __app_ngap_set_SliceSupportList( SI_AMF_DT_SliceSupportList ** data)
{
	__si_amf_init_SliceSupportList( data);
	SI_AMF_DT_SliceSupportList * sliceSupportList = *data;
	
	SI_AMF_DT_SliceSupportItem * objItem = NULL;

	__app_ngap_set_SliceSupportItem( &objItem);
	__si_linked_list_add( (*data)->SliceSupportItem, (uint8_t *)objItem);
}


//-- SEQUENCE, SliceSupportItem
void __app_ngap_set_SliceSupportItem( SI_AMF_DT_SliceSupportItem ** data)
{
	__si_amf_init_SliceSupportItem( data);
	SI_AMF_DT_SliceSupportItem * sliceSupportItem = *data;
	
	__app_ngap_set_S_NSSAI( &sliceSupportItem->s_NSSAI);
}


//-- CONTAINER, SliceSupportItem-ExtIEs
void __app_ngap_set_SliceSupportItem_ExtIEs( SI_AMF_DT_SliceSupportItem_ExtIEs ** data)
{
	__si_amf_init_SliceSupportItem_ExtIEs( data);
	SI_AMF_DT_SliceSupportItem_ExtIEs * sliceSupportItem_ExtIEs = *data;
	
}


//-- SEQUENCE, S-NSSAI
void __app_ngap_set_S_NSSAI( SI_AMF_DT_S_NSSAI ** data)
{
	__si_amf_init_S_NSSAI( data);
	SI_AMF_DT_S_NSSAI * s_NSSAI = *data;
	
	__app_ngap_set_SST( &s_NSSAI->sST);

	__app_ngap_set_SD( &s_NSSAI->sD);
	s_NSSAI->isPresent_sD = 1;
}


//-- CONTAINER, S-NSSAI-ExtIEs
void __app_ngap_set_S_NSSAI_ExtIEs( SI_AMF_DT_S_NSSAI_ExtIEs ** data)
{
	__si_amf_init_S_NSSAI_ExtIEs( data);
	SI_AMF_DT_S_NSSAI_ExtIEs * s_NSSAI_ExtIEs = *data;
	
}


//-- SEQUENCE, SONConfigurationTransfer
void __app_ngap_set_SONConfigurationTransfer( SI_AMF_DT_SONConfigurationTransfer ** data)
{
	__si_amf_init_SONConfigurationTransfer( data);
	SI_AMF_DT_SONConfigurationTransfer * sONConfigurationTransfer = *data;
	
	__app_ngap_set_TargetRANNodeID( &sONConfigurationTransfer->targetRANNodeID);

	__app_ngap_set_SourceRANNodeID( &sONConfigurationTransfer->sourceRANNodeID);

	__app_ngap_set_SONInformation( &sONConfigurationTransfer->sONInformation);

	__app_ngap_set_XnTNLConfigurationInfo( &sONConfigurationTransfer->xnTNLConfigurationInfo);
	sONConfigurationTransfer->isPresent_xnTNLConfigurationInfo = 1;
}


//-- CONTAINER, SONConfigurationTransfer-ExtIEs
void __app_ngap_set_SONConfigurationTransfer_ExtIEs( SI_AMF_DT_SONConfigurationTransfer_ExtIEs ** data)
{
	__si_amf_init_SONConfigurationTransfer_ExtIEs( data);
	SI_AMF_DT_SONConfigurationTransfer_ExtIEs * sONConfigurationTransfer_ExtIEs = *data;
	
}


//-- CHOICE, SONInformation
void __app_ngap_set_SONInformation( SI_AMF_DT_SONInformation ** data)
{
	__si_amf_init_SONInformation( data);
	SI_AMF_DT_SONInformation * sONInformation = *data;
	
	(*data)->SelectedChoice = 0;

	(*data)->u.sONInformationRequest = 0;
	//sONInformationRequest

	//SI_AMF_DT_SONInformationReply sONInformationReply
	//__app_ngap_set_SONInformationReply( &(*data)->u.sONInformationReply);
	//(*data)->u.sONInformationReply->isPresent_xnTNLConfigurationInfo
}


//-- CONTAINER, SONInformation-ExtIEs
void __app_ngap_set_SONInformation_ExtIEs( SI_AMF_DT_SONInformation_ExtIEs ** data)
{
	__si_amf_init_SONInformation_ExtIEs( data);
	SI_AMF_DT_SONInformation_ExtIEs * sONInformation_ExtIEs = *data;
	
}


//-- SEQUENCE, SONInformationReply
void __app_ngap_set_SONInformationReply( SI_AMF_DT_SONInformationReply ** data)
{
	__si_amf_init_SONInformationReply( data);
	SI_AMF_DT_SONInformationReply * sONInformationReply = *data;
	
	__app_ngap_set_XnTNLConfigurationInfo( &sONInformationReply->xnTNLConfigurationInfo);
	sONInformationReply->isPresent_xnTNLConfigurationInfo = 1;
}


//-- CONTAINER, SONInformationReply-ExtIEs
void __app_ngap_set_SONInformationReply_ExtIEs( SI_AMF_DT_SONInformationReply_ExtIEs ** data)
{
	__si_amf_init_SONInformationReply_ExtIEs( data);
	SI_AMF_DT_SONInformationReply_ExtIEs * sONInformationReply_ExtIEs = *data;
	
}


//-- SEQUENCE, SourceNGRANNode-ToTargetNGRANNode-TransparentContainer
void __app_ngap_set_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer ** data)
{
	__si_amf_init_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( data);
	SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer * sourceNGRANNode_ToTargetNGRANNode_TransparentContainer = *data;
	
	__app_ngap_set_RRCContainer( &sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->rRCContainer);

	__app_ngap_set_PDUSessionResourceInformationList( &sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->pDUSessionResourceInformationList);
	sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->isPresent_pDUSessionResourceInformationList = 1;

	__app_ngap_set_E_RABInformationList( &sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->e_RABInformationList);
	sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->isPresent_e_RABInformationList = 1;

	__app_ngap_set_NGRAN_CGI( &sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->targetCell_ID);

	sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->indexToRFSP = __si_core_getU64RANDRange( 1, 256);
	__app_ngap_set_UEHistoryInformation( &sourceNGRANNode_ToTargetNGRANNode_TransparentContainer->uEHistoryInformation);
}


//-- CONTAINER, SourceNGRANNode-ToTargetNGRANNode-TransparentContainer-ExtIEs
void __app_ngap_set_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs ** data)
{
	__si_amf_init_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( data);
	SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs * sourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs = *data;
	
}


//-- SEQUENCE, SourceRANNodeID
void __app_ngap_set_SourceRANNodeID( SI_AMF_DT_SourceRANNodeID ** data)
{
	__si_amf_init_SourceRANNodeID( data);
	SI_AMF_DT_SourceRANNodeID * sourceRANNodeID = *data;
	
	__app_ngap_set_GlobalRANNodeID( &sourceRANNodeID->globalRANNodeID);

	__app_ngap_set_TAI( &sourceRANNodeID->selectedTAI);
}


//-- CONTAINER, SourceRANNodeID-ExtIEs
void __app_ngap_set_SourceRANNodeID_ExtIEs( SI_AMF_DT_SourceRANNodeID_ExtIEs ** data)
{
	__si_amf_init_SourceRANNodeID_ExtIEs( data);
	SI_AMF_DT_SourceRANNodeID_ExtIEs * sourceRANNodeID_ExtIEs = *data;
	
}


//-- OCTETSTRING, SourceToTarget-TransparentContainer
void __app_ngap_set_SourceToTarget_TransparentContainer( SI_AMF_DT_SourceToTarget_TransparentContainer ** data)
{
	__si_amf_init_SourceToTarget_TransparentContainer( data);
	SI_AMF_DT_SourceToTarget_TransparentContainer * sourceToTarget_TransparentContainer = *data;
	
	sourceToTarget_TransparentContainer->data = (unsigned char *) __si_allocM(0);
	sourceToTarget_TransparentContainer->length = 0;
	__si_core_fill_dummy_data( sourceToTarget_TransparentContainer->data, sourceToTarget_TransparentContainer->length);
}


//-- SEQUENCE, SourceToTarget-AMFInformationReroute
void __app_ngap_set_SourceToTarget_AMFInformationReroute( SI_AMF_DT_SourceToTarget_AMFInformationReroute ** data)
{
	__si_amf_init_SourceToTarget_AMFInformationReroute( data);
	SI_AMF_DT_SourceToTarget_AMFInformationReroute * sourceToTarget_AMFInformationReroute = *data;
	
	__app_ngap_set_ConfiguredNSSAI( &sourceToTarget_AMFInformationReroute->configuredNSSAI);
	sourceToTarget_AMFInformationReroute->isPresent_configuredNSSAI = 1;

	__app_ngap_set_RejectedNSSAIinPLMN( &sourceToTarget_AMFInformationReroute->rejectedNSSAIinPLMN);
	sourceToTarget_AMFInformationReroute->isPresent_rejectedNSSAIinPLMN = 1;

	__app_ngap_set_RejectedNSSAIinTA( &sourceToTarget_AMFInformationReroute->rejectedNSSAIinTA);
	sourceToTarget_AMFInformationReroute->isPresent_rejectedNSSAIinTA = 1;
}


//-- CONTAINER, SourceToTarget-AMFInformationReroute-ExtIEs
void __app_ngap_set_SourceToTarget_AMFInformationReroute_ExtIEs( SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs ** data)
{
	__si_amf_init_SourceToTarget_AMFInformationReroute_ExtIEs( data);
	SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs * sourceToTarget_AMFInformationReroute_ExtIEs = *data;
	
}


//-- OCTETSTRING, ConfiguredNSSAI
void __app_ngap_set_ConfiguredNSSAI( SI_AMF_DT_ConfiguredNSSAI ** data)
{
	__si_amf_init_ConfiguredNSSAI( data);
	SI_AMF_DT_ConfiguredNSSAI * configuredNSSAI = *data;
	
	configuredNSSAI->data = (unsigned char *) __si_allocM(128);
	configuredNSSAI->length = 128;
	__si_core_fill_dummy_data( configuredNSSAI->data, configuredNSSAI->length);
}


//-- OCTETSTRING, RejectedNSSAIinPLMN
void __app_ngap_set_RejectedNSSAIinPLMN( SI_AMF_DT_RejectedNSSAIinPLMN ** data)
{
	__si_amf_init_RejectedNSSAIinPLMN( data);
	SI_AMF_DT_RejectedNSSAIinPLMN * rejectedNSSAIinPLMN = *data;
	
	rejectedNSSAIinPLMN->data = (unsigned char *) __si_allocM(32);
	rejectedNSSAIinPLMN->length = 32;
	__si_core_fill_dummy_data( rejectedNSSAIinPLMN->data, rejectedNSSAIinPLMN->length);
}


//-- OCTETSTRING, RejectedNSSAIinTA
void __app_ngap_set_RejectedNSSAIinTA( SI_AMF_DT_RejectedNSSAIinTA ** data)
{
	__si_amf_init_RejectedNSSAIinTA( data);
	SI_AMF_DT_RejectedNSSAIinTA * rejectedNSSAIinTA = *data;
	
	rejectedNSSAIinTA->data = (unsigned char *) __si_allocM(32);
	rejectedNSSAIinTA->length = 32;
	__si_core_fill_dummy_data( rejectedNSSAIinTA->data, rejectedNSSAIinTA->length);
}


//-- OCTETSTRING, SST
void __app_ngap_set_SST( SI_AMF_DT_SST ** data)
{
	__si_amf_init_SST( data);
	SI_AMF_DT_SST * sST = *data;
	
	sST->data = (unsigned char *) __si_allocM(1);
	sST->length = 1;
	__si_core_fill_dummy_data( sST->data, sST->length);
}


//-- SEQUENCE_OF, SupportedTAList
void __app_ngap_set_SupportedTAList( SI_AMF_DT_SupportedTAList ** data)
{
	__si_amf_init_SupportedTAList( data);
	SI_AMF_DT_SupportedTAList * supportedTAList = *data;
	
	SI_AMF_DT_SupportedTAItem * objItem = NULL;

	__app_ngap_set_SupportedTAItem( &objItem);
	__si_linked_list_add( (*data)->SupportedTAItem, (uint8_t *)objItem);
}


//-- SEQUENCE, SupportedTAItem
void __app_ngap_set_SupportedTAItem( SI_AMF_DT_SupportedTAItem ** data)
{
	__si_amf_init_SupportedTAItem( data);
	SI_AMF_DT_SupportedTAItem * supportedTAItem = *data;
	
	__app_ngap_set_TAC( &supportedTAItem->tAC);

	__app_ngap_set_BroadcastPLMNList( &supportedTAItem->broadcastPLMNList);
}


//-- CONTAINER, SupportedTAItem-ExtIEs
void __app_ngap_set_SupportedTAItem_ExtIEs( SI_AMF_DT_SupportedTAItem_ExtIEs ** data)
{
	__si_amf_init_SupportedTAItem_ExtIEs( data);
	SI_AMF_DT_SupportedTAItem_ExtIEs * supportedTAItem_ExtIEs = *data;
	
}


//-- OCTETSTRING, TAC
void __app_ngap_set_TAC( SI_AMF_DT_TAC ** data)
{
	__si_amf_init_TAC( data);
	SI_AMF_DT_TAC * tAC = *data;
	
	tAC->data = (unsigned char *) __si_allocM(3);
	tAC->length = 3;
	__si_core_fill_dummy_data( tAC->data, tAC->length);
}


//-- SEQUENCE, TAI
void __app_ngap_set_TAI( SI_AMF_DT_TAI ** data)
{
	__si_amf_init_TAI( data);
	SI_AMF_DT_TAI * tAI = *data;
	
	__app_ngap_set_PLMNIdentity( &tAI->pLMNIdentity);

	__app_ngap_set_TAC( &tAI->tAC);
}


//-- CONTAINER, TAI-ExtIEs
void __app_ngap_set_TAI_ExtIEs( SI_AMF_DT_TAI_ExtIEs ** data)
{
	__si_amf_init_TAI_ExtIEs( data);
	SI_AMF_DT_TAI_ExtIEs * tAI_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAIBroadcastEUTRA
void __app_ngap_set_TAIBroadcastEUTRA( SI_AMF_DT_TAIBroadcastEUTRA ** data)
{
	__si_amf_init_TAIBroadcastEUTRA( data);
	SI_AMF_DT_TAIBroadcastEUTRA * tAIBroadcastEUTRA = *data;
	
	SI_AMF_DT_TAIBroadcastEUTRA_Item * objItem = NULL;

	__app_ngap_set_TAIBroadcastEUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->TAIBroadcastEUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, TAIBroadcastEUTRA-Item
void __app_ngap_set_TAIBroadcastEUTRA_Item( SI_AMF_DT_TAIBroadcastEUTRA_Item ** data)
{
	__si_amf_init_TAIBroadcastEUTRA_Item( data);
	SI_AMF_DT_TAIBroadcastEUTRA_Item * tAIBroadcastEUTRA_Item = *data;
	
	__app_ngap_set_TAI( &tAIBroadcastEUTRA_Item->tAI);

	__app_ngap_set_CompletedCellsInTAI_EUTRA( &tAIBroadcastEUTRA_Item->completedCellsInTAI_EUTRA);
}


//-- CONTAINER, TAIBroadcastEUTRA-Item-ExtIEs
void __app_ngap_set_TAIBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_TAIBroadcastEUTRA_Item_ExtIEs( data);
	SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs * tAIBroadcastEUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAIBroadcastNR
void __app_ngap_set_TAIBroadcastNR( SI_AMF_DT_TAIBroadcastNR ** data)
{
	__si_amf_init_TAIBroadcastNR( data);
	SI_AMF_DT_TAIBroadcastNR * tAIBroadcastNR = *data;
	
	SI_AMF_DT_TAIBroadcastNR_Item * objItem = NULL;

	__app_ngap_set_TAIBroadcastNR_Item( &objItem);
	__si_linked_list_add( (*data)->TAIBroadcastNR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, TAIBroadcastNR-Item
void __app_ngap_set_TAIBroadcastNR_Item( SI_AMF_DT_TAIBroadcastNR_Item ** data)
{
	__si_amf_init_TAIBroadcastNR_Item( data);
	SI_AMF_DT_TAIBroadcastNR_Item * tAIBroadcastNR_Item = *data;
	
	__app_ngap_set_TAI( &tAIBroadcastNR_Item->tAI);

	__app_ngap_set_CompletedCellsInTAI_NR( &tAIBroadcastNR_Item->completedCellsInTAI_NR);
}


//-- CONTAINER, TAIBroadcastNR-Item-ExtIEs
void __app_ngap_set_TAIBroadcastNR_Item_ExtIEs( SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs ** data)
{
	__si_amf_init_TAIBroadcastNR_Item_ExtIEs( data);
	SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs * tAIBroadcastNR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAICancelledEUTRA
void __app_ngap_set_TAICancelledEUTRA( SI_AMF_DT_TAICancelledEUTRA ** data)
{
	__si_amf_init_TAICancelledEUTRA( data);
	SI_AMF_DT_TAICancelledEUTRA * tAICancelledEUTRA = *data;
	
	SI_AMF_DT_TAICancelledEUTRA_Item * objItem = NULL;

	__app_ngap_set_TAICancelledEUTRA_Item( &objItem);
	__si_linked_list_add( (*data)->TAICancelledEUTRA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, TAICancelledEUTRA-Item
void __app_ngap_set_TAICancelledEUTRA_Item( SI_AMF_DT_TAICancelledEUTRA_Item ** data)
{
	__si_amf_init_TAICancelledEUTRA_Item( data);
	SI_AMF_DT_TAICancelledEUTRA_Item * tAICancelledEUTRA_Item = *data;
	
	__app_ngap_set_TAI( &tAICancelledEUTRA_Item->tAI);

	__app_ngap_set_CancelledCellsInTAI_EUTRA( &tAICancelledEUTRA_Item->cancelledCellsInTAI_EUTRA);
}


//-- CONTAINER, TAICancelledEUTRA-Item-ExtIEs
void __app_ngap_set_TAICancelledEUTRA_Item_ExtIEs( SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs ** data)
{
	__si_amf_init_TAICancelledEUTRA_Item_ExtIEs( data);
	SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs * tAICancelledEUTRA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAICancelledNR
void __app_ngap_set_TAICancelledNR( SI_AMF_DT_TAICancelledNR ** data)
{
	__si_amf_init_TAICancelledNR( data);
	SI_AMF_DT_TAICancelledNR * tAICancelledNR = *data;
	
	SI_AMF_DT_TAICancelledNR_Item * objItem = NULL;

	__app_ngap_set_TAICancelledNR_Item( &objItem);
	__si_linked_list_add( (*data)->TAICancelledNR_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, TAICancelledNR-Item
void __app_ngap_set_TAICancelledNR_Item( SI_AMF_DT_TAICancelledNR_Item ** data)
{
	__si_amf_init_TAICancelledNR_Item( data);
	SI_AMF_DT_TAICancelledNR_Item * tAICancelledNR_Item = *data;
	
	__app_ngap_set_TAI( &tAICancelledNR_Item->tAI);

	__app_ngap_set_CancelledCellsInTAI_NR( &tAICancelledNR_Item->cancelledCellsInTAI_NR);
}


//-- CONTAINER, TAICancelledNR-Item-ExtIEs
void __app_ngap_set_TAICancelledNR_Item_ExtIEs( SI_AMF_DT_TAICancelledNR_Item_ExtIEs ** data)
{
	__si_amf_init_TAICancelledNR_Item_ExtIEs( data);
	SI_AMF_DT_TAICancelledNR_Item_ExtIEs * tAICancelledNR_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAIListForInactive
void __app_ngap_set_TAIListForInactive( SI_AMF_DT_TAIListForInactive ** data)
{
	__si_amf_init_TAIListForInactive( data);
	SI_AMF_DT_TAIListForInactive * tAIListForInactive = *data;
	
	SI_AMF_DT_TAIListForInactiveItem * objItem = NULL;

	__app_ngap_set_TAIListForInactiveItem( &objItem);
	__si_linked_list_add( (*data)->TAIListForInactiveItem, (uint8_t *)objItem);
}


//-- SEQUENCE, TAIListForInactiveItem
void __app_ngap_set_TAIListForInactiveItem( SI_AMF_DT_TAIListForInactiveItem ** data)
{
	__si_amf_init_TAIListForInactiveItem( data);
	SI_AMF_DT_TAIListForInactiveItem * tAIListForInactiveItem = *data;
	
	__app_ngap_set_TAI( &tAIListForInactiveItem->tAI);
}


//-- CONTAINER, TAIListForInactiveItem-ExtIEs
void __app_ngap_set_TAIListForInactiveItem_ExtIEs( SI_AMF_DT_TAIListForInactiveItem_ExtIEs ** data)
{
	__si_amf_init_TAIListForInactiveItem_ExtIEs( data);
	SI_AMF_DT_TAIListForInactiveItem_ExtIEs * tAIListForInactiveItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAIListForPaging
void __app_ngap_set_TAIListForPaging( SI_AMF_DT_TAIListForPaging ** data)
{
	__si_amf_init_TAIListForPaging( data);
	SI_AMF_DT_TAIListForPaging * tAIListForPaging = *data;
	
	SI_AMF_DT_TAIListForPagingItem * objItem = NULL;

	__app_ngap_set_TAIListForPagingItem( &objItem);
	__si_linked_list_add( (*data)->TAIListForPagingItem, (uint8_t *)objItem);
}


//-- SEQUENCE, TAIListForPagingItem
void __app_ngap_set_TAIListForPagingItem( SI_AMF_DT_TAIListForPagingItem ** data)
{
	__si_amf_init_TAIListForPagingItem( data);
	SI_AMF_DT_TAIListForPagingItem * tAIListForPagingItem = *data;
	
	__app_ngap_set_TAI( &tAIListForPagingItem->tAI);
}


//-- CONTAINER, TAIListForPagingItem-ExtIEs
void __app_ngap_set_TAIListForPagingItem_ExtIEs( SI_AMF_DT_TAIListForPagingItem_ExtIEs ** data)
{
	__si_amf_init_TAIListForPagingItem_ExtIEs( data);
	SI_AMF_DT_TAIListForPagingItem_ExtIEs * tAIListForPagingItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, TAIListForRestart
void __app_ngap_set_TAIListForRestart( SI_AMF_DT_TAIListForRestart ** data)
{
	__si_amf_init_TAIListForRestart( data);
	SI_AMF_DT_TAIListForRestart * tAIListForRestart = *data;
	
	SI_AMF_DT_TAI * objItem = NULL;

	__app_ngap_set_TAI( &objItem);
	__si_linked_list_add( (*data)->TAI, (uint8_t *)objItem);
}


//-- SEQUENCE_OF, TAIListForWarning
void __app_ngap_set_TAIListForWarning( SI_AMF_DT_TAIListForWarning ** data)
{
	__si_amf_init_TAIListForWarning( data);
	SI_AMF_DT_TAIListForWarning * tAIListForWarning = *data;
	
	SI_AMF_DT_TAI * objItem = NULL;

	__app_ngap_set_TAI( &objItem);
	__si_linked_list_add( (*data)->TAI, (uint8_t *)objItem);
}


//-- SEQUENCE, TargeteNB-ID
void __app_ngap_set_TargeteNB_ID( SI_AMF_DT_TargeteNB_ID ** data)
{
	__si_amf_init_TargeteNB_ID( data);
	SI_AMF_DT_TargeteNB_ID * targeteNB_ID = *data;
	
	__app_ngap_set_GlobalNgENB_ID( &targeteNB_ID->globalENB_ID);

	__app_ngap_set_EPS_TAI( &targeteNB_ID->selected_EPS_TAI);
}


//-- CONTAINER, TargeteNB-ID-ExtIEs
void __app_ngap_set_TargeteNB_ID_ExtIEs( SI_AMF_DT_TargeteNB_ID_ExtIEs ** data)
{
	__si_amf_init_TargeteNB_ID_ExtIEs( data);
	SI_AMF_DT_TargeteNB_ID_ExtIEs * targeteNB_ID_ExtIEs = *data;
	
}


//-- CHOICE, TargetID
void __app_ngap_set_TargetID( SI_AMF_DT_TargetID ** data)
{
	__si_amf_init_TargetID( data);
	SI_AMF_DT_TargetID * targetID = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_TargetRANNodeID( &(*data)->u.targetRANNodeID);

}


//-- CONTAINER, TargetID-ExtIEs
void __app_ngap_set_TargetID_ExtIEs( SI_AMF_DT_TargetID_ExtIEs ** data)
{
	__si_amf_init_TargetID_ExtIEs( data);
	SI_AMF_DT_TargetID_ExtIEs * targetID_ExtIEs = *data;
	
}


//-- SEQUENCE, TargetNGRANNode-ToSourceNGRANNode-TransparentContainer
void __app_ngap_set_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer ** data)
{
	__si_amf_init_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( data);
	SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer * targetNGRANNode_ToSourceNGRANNode_TransparentContainer = *data;
	
	__app_ngap_set_RRCContainer( &targetNGRANNode_ToSourceNGRANNode_TransparentContainer->rRCContainer);
}


//-- CONTAINER, TargetNGRANNode-ToSourceNGRANNode-TransparentContainer-ExtIEs
void __app_ngap_set_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs ** data)
{
	__si_amf_init_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( data);
	SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs * targetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs = *data;
	
}


//-- SEQUENCE, TargetRANNodeID
void __app_ngap_set_TargetRANNodeID( SI_AMF_DT_TargetRANNodeID ** data)
{
	__si_amf_init_TargetRANNodeID( data);
	SI_AMF_DT_TargetRANNodeID * targetRANNodeID = *data;
	
	__app_ngap_set_GlobalRANNodeID( &targetRANNodeID->globalRANNodeID);

	__app_ngap_set_TAI( &targetRANNodeID->selectedTAI);
}


//-- CONTAINER, TargetRANNodeID-ExtIEs
void __app_ngap_set_TargetRANNodeID_ExtIEs( SI_AMF_DT_TargetRANNodeID_ExtIEs ** data)
{
	__si_amf_init_TargetRANNodeID_ExtIEs( data);
	SI_AMF_DT_TargetRANNodeID_ExtIEs * targetRANNodeID_ExtIEs = *data;
	
}


//-- OCTETSTRING, TargetToSource-TransparentContainer
void __app_ngap_set_TargetToSource_TransparentContainer( SI_AMF_DT_TargetToSource_TransparentContainer ** data)
{
	__si_amf_init_TargetToSource_TransparentContainer( data);
	SI_AMF_DT_TargetToSource_TransparentContainer * targetToSource_TransparentContainer = *data;
	
	targetToSource_TransparentContainer->data = (unsigned char *) __si_allocM(0);
	targetToSource_TransparentContainer->length = 0;
	__si_core_fill_dummy_data( targetToSource_TransparentContainer->data, targetToSource_TransparentContainer->length);
}


//-- OCTETSTRING, TimeStamp
void __app_ngap_set_TimeStamp( SI_AMF_DT_TimeStamp ** data)
{
	__si_amf_init_TimeStamp( data);
	SI_AMF_DT_TimeStamp * timeStamp = *data;
	
	timeStamp->data = (unsigned char *) __si_allocM(4);
	timeStamp->length = 4;
	__si_core_fill_dummy_data( timeStamp->data, timeStamp->length);
}


//-- INTEGER, TimeUEStayedInCell
void __app_ngap_set_TimeUEStayedInCell( SI_AMF_DT_TimeUEStayedInCell ** data)
{
	SI_AMF_DT_TimeUEStayedInCell * timeUEStayedInCell = *data;
	
	//MIN = 0, MAX = 4095
	timeUEStayedInCell->data = __si_core_getU64RANDRange( 0, 4095);
}


//-- INTEGER, TimeUEStayedInCellEnhancedGranularity
void __app_ngap_set_TimeUEStayedInCellEnhancedGranularity( SI_AMF_DT_TimeUEStayedInCellEnhancedGranularity ** data)
{
	SI_AMF_DT_TimeUEStayedInCellEnhancedGranularity * timeUEStayedInCellEnhancedGranularity = *data;
	
	//MIN = 0, MAX = 40950
	timeUEStayedInCellEnhancedGranularity->data = __si_core_getU64RANDRange( 0, 40950);
}


//-- INTEGER, TNLAddressWeightFactor
void __app_ngap_set_TNLAddressWeightFactor( SI_AMF_DT_TNLAddressWeightFactor ** data)
{
	SI_AMF_DT_TNLAddressWeightFactor * tNLAddressWeightFactor = *data;
	
	//MIN = 0, MAX = 255
	tNLAddressWeightFactor->data = __si_core_getU64RANDRange( 0, 255);
}


//-- SEQUENCE_OF, TNLAssociationList
void __app_ngap_set_TNLAssociationList( SI_AMF_DT_TNLAssociationList ** data)
{
	__si_amf_init_TNLAssociationList( data);
	SI_AMF_DT_TNLAssociationList * tNLAssociationList = *data;
	
	SI_AMF_DT_TNLAssociationItem * objItem = NULL;

	__app_ngap_set_TNLAssociationItem( &objItem);
	__si_linked_list_add( (*data)->TNLAssociationItem, (uint8_t *)objItem);
}


//-- SEQUENCE, TNLAssociationItem
void __app_ngap_set_TNLAssociationItem( SI_AMF_DT_TNLAssociationItem ** data)
{
	__si_amf_init_TNLAssociationItem( data);
	SI_AMF_DT_TNLAssociationItem * tNLAssociationItem = *data;
	
	__app_ngap_set_CPTransportLayerInformation( &tNLAssociationItem->tNLAssociationAddress);

	__app_ngap_set_Cause( &tNLAssociationItem->cause);
}


//-- CONTAINER, TNLAssociationItem-ExtIEs
void __app_ngap_set_TNLAssociationItem_ExtIEs( SI_AMF_DT_TNLAssociationItem_ExtIEs ** data)
{
	__si_amf_init_TNLAssociationItem_ExtIEs( data);
	SI_AMF_DT_TNLAssociationItem_ExtIEs * tNLAssociationItem_ExtIEs = *data;
	
}


//-- SEQUENCE, TraceActivation
void __app_ngap_set_TraceActivation( SI_AMF_DT_TraceActivation ** data)
{
	__si_amf_init_TraceActivation( data);
	SI_AMF_DT_TraceActivation * traceActivation = *data;
	
	__app_ngap_set_NGRANTraceID( &traceActivation->nGRANTraceID);

	__app_ngap_set_InterfacesToTrace( &traceActivation->interfacesToTrace);

	traceActivation->selected_etraceDepth = 2;
	__app_ngap_set_TransportLayerAddress( &traceActivation->traceCollectionEntityIPAddress);
}


//-- CONTAINER, TraceActivation-ExtIEs
void __app_ngap_set_TraceActivation_ExtIEs( SI_AMF_DT_TraceActivation_ExtIEs ** data)
{
	__si_amf_init_TraceActivation_ExtIEs( data);
	SI_AMF_DT_TraceActivation_ExtIEs * traceActivation_ExtIEs = *data;
	
}


//-- INTEGER, TrafficLoadReductionIndication
void __app_ngap_set_TrafficLoadReductionIndication( SI_AMF_DT_TrafficLoadReductionIndication ** data)
{
	SI_AMF_DT_TrafficLoadReductionIndication * trafficLoadReductionIndication = *data;
	
	//MIN = 1, MAX = 99
	trafficLoadReductionIndication->data = __si_core_getU64RANDRange( 1, 99);
}


//-- BITSTRING, TransportLayerAddress
void __app_ngap_set_TransportLayerAddress( SI_AMF_DT_TransportLayerAddress ** data)
{
	__si_amf_init_TransportLayerAddress( data);
	SI_AMF_DT_TransportLayerAddress * transportLayerAddress = *data;
	
	//BITSIZE = 160  , BIT STRING(SIZE(1..160,...))
	transportLayerAddress->data = (unsigned char *) __si_allocM(21);
	transportLayerAddress->length = 20;
	transportLayerAddress->bitslen = 160;
	//transportLayerAddress->length = 25;
	//transportLayerAddress->bitslen = 200;
	__si_core_fill_dummy_data( transportLayerAddress->data, transportLayerAddress->length);
}


//-- SEQUENCE, UEAggregateMaximumBitRate
void __app_ngap_set_UEAggregateMaximumBitRate( SI_AMF_DT_UEAggregateMaximumBitRate ** data)
{
	__si_amf_init_UEAggregateMaximumBitRate( data);
	SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate = *data;
	
	uEAggregateMaximumBitRate->uEAggregateMaximumBitRateDL = __si_core_getU64RANDRange( 0, 4000000000000);
	uEAggregateMaximumBitRate->uEAggregateMaximumBitRateUL = __si_core_getU64RANDRange( 0, 4000000000000);
}


//-- CONTAINER, UEAggregateMaximumBitRate-ExtIEs
void __app_ngap_set_UEAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs ** data)
{
	__si_amf_init_UEAggregateMaximumBitRate_ExtIEs( data);
	SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs * uEAggregateMaximumBitRate_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UE-associatedLogicalNG-connectionList
void __app_ngap_set_UE_associatedLogicalNG_connectionList( SI_AMF_DT_UE_associatedLogicalNG_connectionList ** data)
{
	__si_amf_init_UE_associatedLogicalNG_connectionList( data);
	SI_AMF_DT_UE_associatedLogicalNG_connectionList * uE_associatedLogicalNG_connectionList = *data;
	
	SI_AMF_DT_UE_associatedLogicalNG_connectionItem * objItem = NULL;

	__app_ngap_set_UE_associatedLogicalNG_connectionItem( &objItem);
	__si_linked_list_add( (*data)->UE_associatedLogicalNG_connectionItem, (uint8_t *)objItem);
}


//-- SEQUENCE, UE-associatedLogicalNG-connectionItem
void __app_ngap_set_UE_associatedLogicalNG_connectionItem( SI_AMF_DT_UE_associatedLogicalNG_connectionItem ** data)
{
	__si_amf_init_UE_associatedLogicalNG_connectionItem( data);
	SI_AMF_DT_UE_associatedLogicalNG_connectionItem * uE_associatedLogicalNG_connectionItem = *data;
	
	uE_associatedLogicalNG_connectionItem->aMF_UE_NGAP_ID = __si_core_getU64RANDRange( 0, 1099511627775);
	uE_associatedLogicalNG_connectionItem->rAN_UE_NGAP_ID = __si_core_getU64RANDRange( 0, 4294967295);
}


//-- CONTAINER, UE-associatedLogicalNG-connectionItem-ExtIEs
void __app_ngap_set_UE_associatedLogicalNG_connectionItem_ExtIEs( SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs ** data)
{
	__si_amf_init_UE_associatedLogicalNG_connectionItem_ExtIEs( data);
	SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs * uE_associatedLogicalNG_connectionItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UEHistoryInformation
void __app_ngap_set_UEHistoryInformation( SI_AMF_DT_UEHistoryInformation ** data)
{
	__si_amf_init_UEHistoryInformation( data);
	SI_AMF_DT_UEHistoryInformation * uEHistoryInformation = *data;
	
	SI_AMF_DT_LastVisitedCellItem * objItem = NULL;

	__app_ngap_set_LastVisitedCellItem( &objItem);
	__si_linked_list_add( (*data)->LastVisitedCellItem, (uint8_t *)objItem);
}


//-- BITSTRING, UEIdentityIndexValueIL
void __app_ngap_set_UEIdentityIndexValueIL( SI_AMF_DT_UEIdentityIndexValueIL ** data)
{
	__si_amf_init_UEIdentityIndexValueIL( data);
	SI_AMF_DT_UEIdentityIndexValueIL * uEIdentityIndexValueIL = *data;
	
	//BITSIZE = 10  , BIT STRING(SIZE(10))
	uEIdentityIndexValueIL->data = (unsigned char *) __si_allocM(3);
	uEIdentityIndexValueIL->length = 3;
	uEIdentityIndexValueIL->bitslen = 10;
	memset(uEIdentityIndexValueIL->data, 0, 3);
	//__si_core_fill_dummy_data( uEIdentityIndexValueIL->data, uEIdentityIndexValueIL->length);
}


//-- CHOICE, UEIdentityIndexValue
void __app_ngap_set_UEIdentityIndexValue( SI_AMF_DT_UEIdentityIndexValue ** data)
{
	__si_amf_init_UEIdentityIndexValue( data);
	SI_AMF_DT_UEIdentityIndexValue * uEIdentityIndexValue = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_UEIdentityIndexValueIL( &(*data)->u.indexLength10);

}


//-- CONTAINER, UEIdentityIndexValue-ExtIEs
void __app_ngap_set_UEIdentityIndexValue_ExtIEs( SI_AMF_DT_UEIdentityIndexValue_ExtIEs ** data)
{
	__si_amf_init_UEIdentityIndexValue_ExtIEs( data);
	SI_AMF_DT_UEIdentityIndexValue_ExtIEs * uEIdentityIndexValue_ExtIEs = *data;
	
}


//-- CHOICE, UE-NGAP-IDs
void __app_ngap_set_UE_NGAP_IDs( SI_AMF_DT_UE_NGAP_IDs ** data)
{
	__si_amf_init_UE_NGAP_IDs( data);
	SI_AMF_DT_UE_NGAP_IDs * uE_NGAP_IDs = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_UE_NGAP_ID_pair( &(*data)->u.uE_NGAP_ID_pair);

}


//-- CONTAINER, UE-NGAP-IDs-ExtIEs
void __app_ngap_set_UE_NGAP_IDs_ExtIEs( SI_AMF_DT_UE_NGAP_IDs_ExtIEs ** data)
{
	__si_amf_init_UE_NGAP_IDs_ExtIEs( data);
	SI_AMF_DT_UE_NGAP_IDs_ExtIEs * uE_NGAP_IDs_ExtIEs = *data;
	
}


//-- SEQUENCE, UE-NGAP-ID-pair
void __app_ngap_set_UE_NGAP_ID_pair( SI_AMF_DT_UE_NGAP_ID_pair ** data)
{
	__si_amf_init_UE_NGAP_ID_pair( data);
	SI_AMF_DT_UE_NGAP_ID_pair * uE_NGAP_ID_pair = *data;
	
	uE_NGAP_ID_pair->aMF_UE_NGAP_ID = __si_core_getU64RANDRange( 0, 1099511627775);
	uE_NGAP_ID_pair->rAN_UE_NGAP_ID = __si_core_getU64RANDRange( 0, 4294967295);
}


//-- CONTAINER, UE-NGAP-ID-pair-ExtIEs
void __app_ngap_set_UE_NGAP_ID_pair_ExtIEs( SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs ** data)
{
	__si_amf_init_UE_NGAP_ID_pair_ExtIEs( data);
	SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs * uE_NGAP_ID_pair_ExtIEs = *data;
	
}


//-- CHOICE, UEPagingIdentity
void __app_ngap_set_UEPagingIdentity( SI_AMF_DT_UEPagingIdentity ** data)
{
	__si_amf_init_UEPagingIdentity( data);
	SI_AMF_DT_UEPagingIdentity * uEPagingIdentity = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_FiveG_S_TMSI( &(*data)->u.fiveG_S_TMSI);

}


//-- CONTAINER, UEPagingIdentity-ExtIEs
void __app_ngap_set_UEPagingIdentity_ExtIEs( SI_AMF_DT_UEPagingIdentity_ExtIEs ** data)
{
	__si_amf_init_UEPagingIdentity_ExtIEs( data);
	SI_AMF_DT_UEPagingIdentity_ExtIEs * uEPagingIdentity_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UEPresenceInAreaOfInterestList
void __app_ngap_set_UEPresenceInAreaOfInterestList( SI_AMF_DT_UEPresenceInAreaOfInterestList ** data)
{
	__si_amf_init_UEPresenceInAreaOfInterestList( data);
	SI_AMF_DT_UEPresenceInAreaOfInterestList * uEPresenceInAreaOfInterestList = *data;
	
	SI_AMF_DT_UEPresenceInAreaOfInterestItem * objItem = NULL;

	__app_ngap_set_UEPresenceInAreaOfInterestItem( &objItem);
	__si_linked_list_add( (*data)->UEPresenceInAreaOfInterestItem, (uint8_t *)objItem);
}


//-- SEQUENCE, UEPresenceInAreaOfInterestItem
void __app_ngap_set_UEPresenceInAreaOfInterestItem( SI_AMF_DT_UEPresenceInAreaOfInterestItem ** data)
{
	__si_amf_init_UEPresenceInAreaOfInterestItem( data);
	SI_AMF_DT_UEPresenceInAreaOfInterestItem * uEPresenceInAreaOfInterestItem = *data;
	
	uEPresenceInAreaOfInterestItem->locationReportingReferenceID = __si_core_getU64RANDRange( 1, 64);
	uEPresenceInAreaOfInterestItem->selected_euEPresence = 0;
}


//-- CONTAINER, UEPresenceInAreaOfInterestItem-ExtIEs
void __app_ngap_set_UEPresenceInAreaOfInterestItem_ExtIEs( SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs ** data)
{
	__si_amf_init_UEPresenceInAreaOfInterestItem_ExtIEs( data);
	SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs * uEPresenceInAreaOfInterestItem_ExtIEs = *data;
	
}


//-- OCTETSTRING, UERadioCapability
void __app_ngap_set_UERadioCapability( SI_AMF_DT_UERadioCapability ** data)
{
	__si_amf_init_UERadioCapability( data);
	SI_AMF_DT_UERadioCapability * uERadioCapability = *data;
	
	uERadioCapability->data = (unsigned char *) __si_allocM(2);
	uERadioCapability->length = 2;
	memset( uERadioCapability->data, 0, 2);
	//__si_core_fill_dummy_data( uERadioCapability->data, uERadioCapability->length);
}


//-- SEQUENCE, UERadioCapabilityForPaging
void __app_ngap_set_UERadioCapabilityForPaging( SI_AMF_DT_UERadioCapabilityForPaging ** data)
{
	__si_amf_init_UERadioCapabilityForPaging( data);
	SI_AMF_DT_UERadioCapabilityForPaging * uERadioCapabilityForPaging = *data;
	
	__app_ngap_set_UERadioCapabilityForPagingOfNR( &uERadioCapabilityForPaging->uERadioCapabilityForPagingOfNR);
	uERadioCapabilityForPaging->isPresent_uERadioCapabilityForPagingOfNR = 0;

	__app_ngap_set_UERadioCapabilityForPagingOfEUTRA( &uERadioCapabilityForPaging->uERadioCapabilityForPagingOfEUTRA);
	uERadioCapabilityForPaging->isPresent_uERadioCapabilityForPagingOfEUTRA = 0;
}


//-- CONTAINER, UERadioCapabilityForPaging-ExtIEs
void __app_ngap_set_UERadioCapabilityForPaging_ExtIEs( SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs ** data)
{
	__si_amf_init_UERadioCapabilityForPaging_ExtIEs( data);
	SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs * uERadioCapabilityForPaging_ExtIEs = *data;
	
}


//-- OCTETSTRING, UERadioCapabilityForPagingOfNR
void __app_ngap_set_UERadioCapabilityForPagingOfNR( SI_AMF_DT_UERadioCapabilityForPagingOfNR ** data)
{
	__si_amf_init_UERadioCapabilityForPagingOfNR( data);
	SI_AMF_DT_UERadioCapabilityForPagingOfNR * uERadioCapabilityForPagingOfNR = *data;
	
	uERadioCapabilityForPagingOfNR->data = (unsigned char *) __si_allocM(5);
	uERadioCapabilityForPagingOfNR->length = 2;
	memset( uERadioCapabilityForPagingOfNR->data, 0, 5);
	//__si_core_fill_dummy_data( uERadioCapabilityForPagingOfNR->data, uERadioCapabilityForPagingOfNR->length);
}


//-- OCTETSTRING, UERadioCapabilityForPagingOfEUTRA
void __app_ngap_set_UERadioCapabilityForPagingOfEUTRA( SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA ** data)
{
	__si_amf_init_UERadioCapabilityForPagingOfEUTRA( data);
	SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA * uERadioCapabilityForPagingOfEUTRA = *data;
	
	uERadioCapabilityForPagingOfEUTRA->data = (unsigned char *) __si_allocM(5);
	uERadioCapabilityForPagingOfEUTRA->length = 2;
	memset( uERadioCapabilityForPagingOfEUTRA->data, 0, 5);
	//__si_core_fill_dummy_data( uERadioCapabilityForPagingOfEUTRA->data, uERadioCapabilityForPagingOfEUTRA->length);
}


//-- SEQUENCE, UESecurityCapabilities
void __app_ngap_set_UESecurityCapabilities( SI_AMF_DT_UESecurityCapabilities ** data)
{
	__si_amf_init_UESecurityCapabilities( data);
	SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities = *data;
	
	__app_ngap_set_NRencryptionAlgorithms( &uESecurityCapabilities->nRencryptionAlgorithms);

	__app_ngap_set_NRintegrityProtectionAlgorithms( &uESecurityCapabilities->nRintegrityProtectionAlgorithms);

	__app_ngap_set_EUTRAencryptionAlgorithms( &uESecurityCapabilities->eUTRAencryptionAlgorithms);

	__app_ngap_set_EUTRAintegrityProtectionAlgorithms( &uESecurityCapabilities->eUTRAintegrityProtectionAlgorithms);
}


//-- CONTAINER, UESecurityCapabilities-ExtIEs
void __app_ngap_set_UESecurityCapabilities_ExtIEs( SI_AMF_DT_UESecurityCapabilities_ExtIEs ** data)
{
	__si_amf_init_UESecurityCapabilities_ExtIEs( data);
	SI_AMF_DT_UESecurityCapabilities_ExtIEs * uESecurityCapabilities_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UL-NGU-UP-TNLModifyList
void __app_ngap_set_UL_NGU_UP_TNLModifyList( SI_AMF_DT_UL_NGU_UP_TNLModifyList ** data)
{
	__si_amf_init_UL_NGU_UP_TNLModifyList( data);
	SI_AMF_DT_UL_NGU_UP_TNLModifyList * uL_NGU_UP_TNLModifyList = *data;
	
	SI_AMF_DT_UL_NGU_UP_TNLModifyItem * objItem = NULL;

	__app_ngap_set_UL_NGU_UP_TNLModifyItem( &objItem);
	__si_linked_list_add( (*data)->UL_NGU_UP_TNLModifyItem, (uint8_t *)objItem);
}


//-- SEQUENCE, UL-NGU-UP-TNLModifyItem
void __app_ngap_set_UL_NGU_UP_TNLModifyItem( SI_AMF_DT_UL_NGU_UP_TNLModifyItem ** data)
{
	__si_amf_init_UL_NGU_UP_TNLModifyItem( data);
	SI_AMF_DT_UL_NGU_UP_TNLModifyItem * uL_NGU_UP_TNLModifyItem = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &uL_NGU_UP_TNLModifyItem->uL_NGU_UP_TNLInformation);

	__app_ngap_set_UPTransportLayerInformation( &uL_NGU_UP_TNLModifyItem->dL_NGU_UP_TNLInformation);
}


//-- CONTAINER, UL-NGU-UP-TNLModifyItem-ExtIEs
void __app_ngap_set_UL_NGU_UP_TNLModifyItem_ExtIEs( SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs ** data)
{
	__si_amf_init_UL_NGU_UP_TNLModifyItem_ExtIEs( data);
	SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs * uL_NGU_UP_TNLModifyItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UnavailableGUAMIList
void __app_ngap_set_UnavailableGUAMIList( SI_AMF_DT_UnavailableGUAMIList ** data)
{
	__si_amf_init_UnavailableGUAMIList( data);
	SI_AMF_DT_UnavailableGUAMIList * unavailableGUAMIList = *data;
	
	SI_AMF_DT_UnavailableGUAMIItem * objItem = NULL;

	__app_ngap_set_UnavailableGUAMIItem( &objItem);
	__si_linked_list_add( (*data)->UnavailableGUAMIItem, (uint8_t *)objItem);
}


//-- SEQUENCE, UnavailableGUAMIItem
void __app_ngap_set_UnavailableGUAMIItem( SI_AMF_DT_UnavailableGUAMIItem ** data)
{
	__si_amf_init_UnavailableGUAMIItem( data);
	SI_AMF_DT_UnavailableGUAMIItem * unavailableGUAMIItem = *data;
	
	__app_ngap_set_GUAMI( &unavailableGUAMIItem->gUAMI);

	unavailableGUAMIItem->selected_etimerApproachForGUAMIRemoval = 0;
	__app_ngap_set_AMFName( &unavailableGUAMIItem->backupAMFName);
	unavailableGUAMIItem->isPresent_backupAMFName = 1;
}


//-- CONTAINER, UnavailableGUAMIItem-ExtIEs
void __app_ngap_set_UnavailableGUAMIItem_ExtIEs( SI_AMF_DT_UnavailableGUAMIItem_ExtIEs ** data)
{
	__si_amf_init_UnavailableGUAMIItem_ExtIEs( data);
	SI_AMF_DT_UnavailableGUAMIItem_ExtIEs * unavailableGUAMIItem_ExtIEs = *data;
	
}


//-- CHOICE, UPTransportLayerInformation
void __app_ngap_set_UPTransportLayerInformation( SI_AMF_DT_UPTransportLayerInformation ** data)
{
	__si_amf_init_UPTransportLayerInformation( data);
	SI_AMF_DT_UPTransportLayerInformation * uPTransportLayerInformation = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_GTPTunnel( &(*data)->u.gTPTunnel);

}


//-- CONTAINER, UPTransportLayerInformation-ExtIEs
void __app_ngap_set_UPTransportLayerInformation_ExtIEs( SI_AMF_DT_UPTransportLayerInformation_ExtIEs ** data)
{
	__si_amf_init_UPTransportLayerInformation_ExtIEs( data);
	SI_AMF_DT_UPTransportLayerInformation_ExtIEs * uPTransportLayerInformation_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UPTransportLayerInformationList
void __app_ngap_set_UPTransportLayerInformationList( SI_AMF_DT_UPTransportLayerInformationList ** data)
{
	__si_amf_init_UPTransportLayerInformationList( data);
	SI_AMF_DT_UPTransportLayerInformationList * uPTransportLayerInformationList = *data;
	
	SI_AMF_DT_UPTransportLayerInformationItem * objItem = NULL;

	__app_ngap_set_UPTransportLayerInformationItem( &objItem);
	__si_linked_list_add( (*data)->UPTransportLayerInformationItem, (uint8_t *)objItem);
}


//-- SEQUENCE, UPTransportLayerInformationItem
void __app_ngap_set_UPTransportLayerInformationItem( SI_AMF_DT_UPTransportLayerInformationItem ** data)
{
	__si_amf_init_UPTransportLayerInformationItem( data);
	SI_AMF_DT_UPTransportLayerInformationItem * uPTransportLayerInformationItem = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &uPTransportLayerInformationItem->nGU_UP_TNLInformation);
}


//-- CONTAINER, UPTransportLayerInformationItem-ExtIEs
void __app_ngap_set_UPTransportLayerInformationItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs ** data)
{
	__si_amf_init_UPTransportLayerInformationItem_ExtIEs( data);
	SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs * uPTransportLayerInformationItem_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, UPTransportLayerInformationPairList
void __app_ngap_set_UPTransportLayerInformationPairList( SI_AMF_DT_UPTransportLayerInformationPairList ** data)
{
	__si_amf_init_UPTransportLayerInformationPairList( data);
	SI_AMF_DT_UPTransportLayerInformationPairList * uPTransportLayerInformationPairList = *data;
	
	SI_AMF_DT_UPTransportLayerInformationPairItem * objItem = NULL;

	__app_ngap_set_UPTransportLayerInformationPairItem( &objItem);
	__si_linked_list_add( (*data)->UPTransportLayerInformationPairItem, (uint8_t *)objItem);
}


//-- SEQUENCE, UPTransportLayerInformationPairItem
void __app_ngap_set_UPTransportLayerInformationPairItem( SI_AMF_DT_UPTransportLayerInformationPairItem ** data)
{
	__si_amf_init_UPTransportLayerInformationPairItem( data);
	SI_AMF_DT_UPTransportLayerInformationPairItem * uPTransportLayerInformationPairItem = *data;
	
	__app_ngap_set_UPTransportLayerInformation( &uPTransportLayerInformationPairItem->uL_NGU_UP_TNLInformation);

	__app_ngap_set_UPTransportLayerInformation( &uPTransportLayerInformationPairItem->dL_NGU_UP_TNLInformation);
}


//-- CONTAINER, UPTransportLayerInformationPairItem-ExtIEs
void __app_ngap_set_UPTransportLayerInformationPairItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs ** data)
{
	__si_amf_init_UPTransportLayerInformationPairItem_ExtIEs( data);
	SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs * uPTransportLayerInformationPairItem_ExtIEs = *data;
	
}


//-- CHOICE, UserLocationInformation
void __app_ngap_set_UserLocationInformation( SI_AMF_DT_UserLocationInformation ** data)
{
	__si_amf_init_UserLocationInformation( data);
	SI_AMF_DT_UserLocationInformation * userLocationInformation = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_UserLocationInformationEUTRA( &(*data)->u.userLocationInformationEUTRA);

}


//-- CONTAINER, UserLocationInformation-ExtIEs
void __app_ngap_set_UserLocationInformation_ExtIEs( SI_AMF_DT_UserLocationInformation_ExtIEs ** data)
{
	__si_amf_init_UserLocationInformation_ExtIEs( data);
	SI_AMF_DT_UserLocationInformation_ExtIEs * userLocationInformation_ExtIEs = *data;
	
}


//-- SEQUENCE, UserLocationInformationEUTRA
void __app_ngap_set_UserLocationInformationEUTRA( SI_AMF_DT_UserLocationInformationEUTRA ** data)
{
	__si_amf_init_UserLocationInformationEUTRA( data);
	SI_AMF_DT_UserLocationInformationEUTRA * userLocationInformationEUTRA = *data;
	
	__app_ngap_set_EUTRA_CGI( &userLocationInformationEUTRA->eUTRA_CGI);

	__app_ngap_set_TAI( &userLocationInformationEUTRA->tAI);

	__app_ngap_set_TimeStamp( &userLocationInformationEUTRA->timeStamp);
	userLocationInformationEUTRA->isPresent_timeStamp = 1;
}


//-- CONTAINER, UserLocationInformationEUTRA-ExtIEs
void __app_ngap_set_UserLocationInformationEUTRA_ExtIEs( SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs ** data)
{
	__si_amf_init_UserLocationInformationEUTRA_ExtIEs( data);
	SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs * userLocationInformationEUTRA_ExtIEs = *data;
	
}


//-- SEQUENCE, UserLocationInformationN3IWF
void __app_ngap_set_UserLocationInformationN3IWF( SI_AMF_DT_UserLocationInformationN3IWF ** data)
{
	__si_amf_init_UserLocationInformationN3IWF( data);
	SI_AMF_DT_UserLocationInformationN3IWF * userLocationInformationN3IWF = *data;
	
	__app_ngap_set_TransportLayerAddress( &userLocationInformationN3IWF->iPAddress);

	__app_ngap_set_PortNumber( &userLocationInformationN3IWF->portNumber);
}


//-- CONTAINER, UserLocationInformationN3IWF-ExtIEs
void __app_ngap_set_UserLocationInformationN3IWF_ExtIEs( SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs ** data)
{
	__si_amf_init_UserLocationInformationN3IWF_ExtIEs( data);
	SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs * userLocationInformationN3IWF_ExtIEs = *data;
	
}


//-- SEQUENCE, UserLocationInformationNR
void __app_ngap_set_UserLocationInformationNR( SI_AMF_DT_UserLocationInformationNR ** data)
{
	__si_amf_init_UserLocationInformationNR( data);
	SI_AMF_DT_UserLocationInformationNR * userLocationInformationNR = *data;
	
	__app_ngap_set_NR_CGI( &userLocationInformationNR->nR_CGI);

	__app_ngap_set_TAI( &userLocationInformationNR->tAI);

	__app_ngap_set_TimeStamp( &userLocationInformationNR->timeStamp);
	userLocationInformationNR->isPresent_timeStamp = 1;
}


//-- CONTAINER, UserLocationInformationNR-ExtIEs
void __app_ngap_set_UserLocationInformationNR_ExtIEs( SI_AMF_DT_UserLocationInformationNR_ExtIEs ** data)
{
	__si_amf_init_UserLocationInformationNR_ExtIEs( data);
	SI_AMF_DT_UserLocationInformationNR_ExtIEs * userLocationInformationNR_ExtIEs = *data;
	
}


//-- SEQUENCE, UserPlaneSecurityInformation
void __app_ngap_set_UserPlaneSecurityInformation( SI_AMF_DT_UserPlaneSecurityInformation ** data)
{
	__si_amf_init_UserPlaneSecurityInformation( data);
	SI_AMF_DT_UserPlaneSecurityInformation * userPlaneSecurityInformation = *data;
	
	__app_ngap_set_SecurityResult( &userPlaneSecurityInformation->securityResult);

	__app_ngap_set_SecurityIndication( &userPlaneSecurityInformation->securityIndication);
}


//-- CONTAINER, UserPlaneSecurityInformation-ExtIEs
void __app_ngap_set_UserPlaneSecurityInformation_ExtIEs( SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs ** data)
{
	__si_amf_init_UserPlaneSecurityInformation_ExtIEs( data);
	SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs * userPlaneSecurityInformation_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, VolumeTimedReportList
void __app_ngap_set_VolumeTimedReportList( SI_AMF_DT_VolumeTimedReportList ** data)
{
	__si_amf_init_VolumeTimedReportList( data);
	SI_AMF_DT_VolumeTimedReportList * volumeTimedReportList = *data;
	
	SI_AMF_DT_VolumeTimedReport_Item * objItem = NULL;

	__app_ngap_set_VolumeTimedReport_Item( &objItem);
	__si_linked_list_add( (*data)->VolumeTimedReport_Item, (uint8_t *)objItem);
}


//-- OCTETSTRING, VolumeTimedReport-ItemTimeStamp
void __app_ngap_set_VolumeTimedReport_ItemTimeStamp( SI_AMF_DT_VolumeTimedReport_ItemTimeStamp ** data)
{
	__si_amf_init_VolumeTimedReport_ItemTimeStamp( data);
	SI_AMF_DT_VolumeTimedReport_ItemTimeStamp * volumeTimedReport_ItemTimeStamp = *data;
	
	volumeTimedReport_ItemTimeStamp->data = (unsigned char *) __si_allocM(4);
	volumeTimedReport_ItemTimeStamp->length = 4;
	__si_core_fill_dummy_data( volumeTimedReport_ItemTimeStamp->data, volumeTimedReport_ItemTimeStamp->length);
}


//-- INTEGER, VolumeTimedReport-ItemUsageCount
void __app_ngap_set_VolumeTimedReport_ItemUsageCount( SI_AMF_DT_VolumeTimedReport_ItemUsageCount ** data)
{
	SI_AMF_DT_VolumeTimedReport_ItemUsageCount * volumeTimedReport_ItemUsageCount = *data;
	
	//MIN = 0, MAX = 18446744073709552000
	volumeTimedReport_ItemUsageCount->data = __si_core_getU64RANDRange( 0, 18446744073709551615U);
}


//-- SEQUENCE, VolumeTimedReport-Item
void __app_ngap_set_VolumeTimedReport_Item( SI_AMF_DT_VolumeTimedReport_Item ** data)
{
	__si_amf_init_VolumeTimedReport_Item( data);
	SI_AMF_DT_VolumeTimedReport_Item * volumeTimedReport_Item = *data;
	
	__app_ngap_set_VolumeTimedReport_ItemTimeStamp( &volumeTimedReport_Item->startTimeStamp);

	__app_ngap_set_VolumeTimedReport_ItemTimeStamp( &volumeTimedReport_Item->endTimeStamp);

	volumeTimedReport_Item->usageCountUL = __si_core_getU64RANDRange( 0, 18446744073709551615U);;
	volumeTimedReport_Item->usageCountDL = __si_core_getU64RANDRange( 0, 18446744073709551615U);;
}


//-- CONTAINER, VolumeTimedReport-Item-ExtIEs
void __app_ngap_set_VolumeTimedReport_Item_ExtIEs( SI_AMF_DT_VolumeTimedReport_Item_ExtIEs ** data)
{
	__si_amf_init_VolumeTimedReport_Item_ExtIEs( data);
	SI_AMF_DT_VolumeTimedReport_Item_ExtIEs * volumeTimedReport_Item_ExtIEs = *data;
	
}


//-- OCTETSTRING, WarningAreaCoordinates
void __app_ngap_set_WarningAreaCoordinates( SI_AMF_DT_WarningAreaCoordinates ** data)
{
	__si_amf_init_WarningAreaCoordinates( data);
	SI_AMF_DT_WarningAreaCoordinates * warningAreaCoordinates = *data;
	
	warningAreaCoordinates->data = (unsigned char *) __si_allocM(10);
	warningAreaCoordinates->length = 10;
	memset( warningAreaCoordinates->data, 0, 10);
	//__si_core_fill_dummy_data( warningAreaCoordinates->data, warningAreaCoordinates->length);
}


//-- CHOICE, WarningAreaList
void __app_ngap_set_WarningAreaList( SI_AMF_DT_WarningAreaList ** data)
{
	__si_amf_init_WarningAreaList( data);
	SI_AMF_DT_WarningAreaList * warningAreaList = *data;
	
	(*data)->SelectedChoice = 0;

	__app_ngap_set_EUTRA_CGIListForWarning( &(*data)->u.eUTRA_CGIListForWarning);

}


//-- CONTAINER, WarningAreaList-ExtIEs
void __app_ngap_set_WarningAreaList_ExtIEs( SI_AMF_DT_WarningAreaList_ExtIEs ** data)
{
	__si_amf_init_WarningAreaList_ExtIEs( data);
	SI_AMF_DT_WarningAreaList_ExtIEs * warningAreaList_ExtIEs = *data;
	
}


//-- OCTETSTRING, WarningMessageContents
void __app_ngap_set_WarningMessageContents( SI_AMF_DT_WarningMessageContents ** data)
{
	__si_amf_init_WarningMessageContents( data);
	SI_AMF_DT_WarningMessageContents * warningMessageContents = *data;
	
	warningMessageContents->data = (unsigned char *) __si_allocM(20);
	warningMessageContents->length = 20;
	//__si_core_fill_dummy_data( warningMessageContents->data, warningMessageContents->length);
	memset( warningMessageContents->data, 0, 20);
}


//-- OCTETSTRING, WarningSecurityInfo
void __app_ngap_set_WarningSecurityInfo( SI_AMF_DT_WarningSecurityInfo ** data)
{
	__si_amf_init_WarningSecurityInfo( data);
	SI_AMF_DT_WarningSecurityInfo * warningSecurityInfo = *data;
	
	warningSecurityInfo->data = (unsigned char *) __si_allocM(50);
	warningSecurityInfo->length = 50;
	__si_core_fill_dummy_data( warningSecurityInfo->data, warningSecurityInfo->length);
}


//-- OCTETSTRING, WarningType
void __app_ngap_set_WarningType( SI_AMF_DT_WarningType ** data)
{
	__si_amf_init_WarningType( data);
	SI_AMF_DT_WarningType * warningType = *data;
	
	warningType->data = (unsigned char *) __si_allocM(2);
	warningType->length = 2;
	__si_core_fill_dummy_data( warningType->data, warningType->length);
}


//-- SEQUENCE_OF, XnExtTLAs
void __app_ngap_set_XnExtTLAs( SI_AMF_DT_XnExtTLAs ** data)
{
	__si_amf_init_XnExtTLAs( data);
	SI_AMF_DT_XnExtTLAs * xnExtTLAs = *data;
	
	SI_AMF_DT_XnExtTLA_Item * objItem = NULL;

	__app_ngap_set_XnExtTLA_Item( &objItem);
	__si_linked_list_add( (*data)->XnExtTLA_Item, (uint8_t *)objItem);
}


//-- SEQUENCE, XnExtTLA-Item
void __app_ngap_set_XnExtTLA_Item( SI_AMF_DT_XnExtTLA_Item ** data)
{
	__si_amf_init_XnExtTLA_Item( data);
	SI_AMF_DT_XnExtTLA_Item * xnExtTLA_Item = *data;
	
	__app_ngap_set_TransportLayerAddress( &xnExtTLA_Item->iPsecTLA);
	xnExtTLA_Item->isPresent_iPsecTLA = 1;

	__app_ngap_set_XnGTP_TLAs( &xnExtTLA_Item->gTP_TLAs);
	xnExtTLA_Item->isPresent_gTP_TLAs = 1;
}


//-- CONTAINER, XnExtTLA-Item-ExtIEs
void __app_ngap_set_XnExtTLA_Item_ExtIEs( SI_AMF_DT_XnExtTLA_Item_ExtIEs ** data)
{
	__si_amf_init_XnExtTLA_Item_ExtIEs( data);
	SI_AMF_DT_XnExtTLA_Item_ExtIEs * xnExtTLA_Item_ExtIEs = *data;
	
}


//-- SEQUENCE_OF, XnGTP-TLAs
void __app_ngap_set_XnGTP_TLAs( SI_AMF_DT_XnGTP_TLAs ** data)
{
	__si_amf_init_XnGTP_TLAs( data);
	SI_AMF_DT_XnGTP_TLAs * xnGTP_TLAs = *data;
	
	SI_AMF_DT_TransportLayerAddress * objItem = NULL;

	__app_ngap_set_TransportLayerAddress( &objItem);
	__si_linked_list_add( (*data)->TransportLayerAddress, (uint8_t *)objItem);
}


//-- SEQUENCE_OF, XnTLAs
void __app_ngap_set_XnTLAs( SI_AMF_DT_XnTLAs ** data)
{
	__si_amf_init_XnTLAs( data);
	SI_AMF_DT_XnTLAs * xnTLAs = *data;
	
	SI_AMF_DT_TransportLayerAddress * objItem = NULL;

	__app_ngap_set_TransportLayerAddress( &objItem);
	__si_linked_list_add( (*data)->TransportLayerAddress, (uint8_t *)objItem);
}


//-- SEQUENCE, XnTNLConfigurationInfo
void __app_ngap_set_XnTNLConfigurationInfo( SI_AMF_DT_XnTNLConfigurationInfo ** data)
{
	__si_amf_init_XnTNLConfigurationInfo( data);
	SI_AMF_DT_XnTNLConfigurationInfo * xnTNLConfigurationInfo = *data;
	
	__app_ngap_set_XnTLAs( &xnTNLConfigurationInfo->xnTransportLayerAddresses);

	__app_ngap_set_XnExtTLAs( &xnTNLConfigurationInfo->xnExtendedTransportLayerAddresses);
	xnTNLConfigurationInfo->isPresent_xnExtendedTransportLayerAddresses = 0;
}


//-- CONTAINER, XnTNLConfigurationInfo-ExtIEs
void __app_ngap_set_XnTNLConfigurationInfo_ExtIEs( SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs ** data)
{
	__si_amf_init_XnTNLConfigurationInfo_ExtIEs( data);
	SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs * xnTNLConfigurationInfo_ExtIEs = *data;
	
}



