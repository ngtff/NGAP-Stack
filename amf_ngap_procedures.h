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

#ifndef APP_AMF_PROCEDURES_H
#define APP_AMF_PROCEDURES_H

#include "sicore.h"
#include "libAMFAsn.h"
#include "libNasPdu.h"
#include "ngap.h"

// PDU Session Management Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUSessionResourceSetupRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUSessionResourceSetupResponse, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUSessionResourceReleaseCommand, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUSessionResourceReleaseResponse, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUSessionResourceModifyRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUSessionResourceModifyResponse, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUSessionResourceNotify, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUSessionResourceModifyIndication, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUSessionResourceModifyConfirm, SI_NGAPNode * ngNode);
// PDU Session Management Procedures -------------------------------------------------------------------------------------------------------------------------------------

// UE Context Management Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objInitialContextSetupRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objInitialContextSetupResponse, SI_NGAPNode * ngNode);
void amf_ngap_procedure_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objInitialContextSetupFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_NGAPNode * ngNode);

void amf_ngap_procedure_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objUEContextModificationRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objUEContextModificationResponse, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objUEContextModificationFailure, SI_NGAPNode * ngNode);
// UE Context Management Procedures -------------------------------------------------------------------------------------------------------------------------------------

// UE Mobility Management Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objHandoverRequired, SI_NGAPNode * ngNode);
void amf_ngap_procedure_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objHandoverCommand, SI_NGAPNode * ngNode);
void amf_ngap_procedure_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objHandoverPreparationFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objHandoverRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objHandoverRequestAcknowledge, SI_NGAPNode * ngNode);
void amf_ngap_procedure_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objHandoverFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objHandoverNotify, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPathSwitchRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPathSwitchRequestAcknowledge, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPathSwitchRequestFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objHandoverCancel, SI_NGAPNode * ngNode);
void amf_ngap_procedure_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objHandoverCancelAcknowledge, SI_NGAPNode * ngNode);

void amf_ngap_procedure_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objUplinkRANStatusTransfer, SI_NGAPNode * ngNode);
void amf_ngap_procedure_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objDownlinkRANStatusTransfer, SI_NGAPNode * ngNode);
// UE Mobility Management Procedures -------------------------------------------------------------------------------------------------------------------------------------

// Paging Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_Paging( SI_AMF_DT_PDU_Paging * objPaging, SI_NGAPNode * ngNode);
// Paging Procedures -------------------------------------------------------------------------------------------------------------------------------------

// Transport of NAS Messages Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objInitialUEMessage, SI_NGAPNode * ngNode);
void amf_ngap_procedure_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objDownlinkNASTransport, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objUplinkNASTransport, SI_NGAPNode * ngNode);
void amf_ngap_procedure_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objNASNonDeliveryIndication, SI_NGAPNode * ngNode);
void amf_ngap_procedure_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objRerouteNASRequest, SI_NGAPNode * ngNode);
// Transport of NAS Messages Procedures -------------------------------------------------------------------------------------------------------------------------------------

// Interface Management Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objNGSetupRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objNGSetupResponse, SI_NGAPNode * ngNode);
void amf_ngap_procedure_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objNGSetupFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objRANConfigurationUpdate, SI_NGAPNode * ngNode);
void amf_ngap_procedure_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objRANConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode);
void amf_ngap_procedure_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objRANConfigurationUpdateFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objAMFConfigurationUpdate, SI_NGAPNode * ngNode);
void amf_ngap_procedure_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objAMFConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode);
void amf_ngap_procedure_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objAMFConfigurationUpdateFailure, SI_NGAPNode * ngNode);

void amf_ngap_procedure_NGReset( SI_AMF_DT_PDU_NGReset * objNGReset, SI_NGAPNode * ngNode);
void amf_ngap_procedure_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objNGResetAcknowledge, SI_NGAPNode * ngNode);

void amf_ngap_procedure_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objErrorIndication, SI_NGAPNode * ngNode);

void amf_ngap_procedure_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objAMFStatusIndication, SI_NGAPNode * ngNode);
// Interface Management Procedures -------------------------------------------------------------------------------------------------------------------------------------

//Configuration Transfer Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objUplinkRANConfigurationTransfer, SI_NGAPNode * ngNode);
void amf_ngap_procedure_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objDownlinkRANConfigurationTransfer, SI_NGAPNode * ngNode);
//Configuration Transfer Procedures -------------------------------------------------------------------------------------------------------------------------------------

//Warning Message Transmission Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objWriteReplaceWarningRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objWriteReplaceWarningResponse, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPWSCancelRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPWSCancelResponse, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPWSRestartIndication, SI_NGAPNode * ngNode);

void amf_ngap_procedure_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPWSFailureIndication, SI_NGAPNode * ngNode);
//Warning Message Transmission Procedures -------------------------------------------------------------------------------------------------------------------------------------

//NRPPa Transport Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objDownlinkUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objUplinkUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);

void amf_ngap_procedure_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objDownlinkNonUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objUplinkNonUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
//NRPPa Transport Procedures -------------------------------------------------------------------------------------------------------------------------------------

//Trace Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_TraceStart( SI_AMF_DT_PDU_TraceStart * objTraceStart, SI_NGAPNode * ngNode);
void amf_ngap_procedure_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objTraceFailureIndication, SI_NGAPNode * ngNode);
void amf_ngap_procedure_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_NGAPNode * ngNode);
void amf_ngap_procedure_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_NGAPNode * ngNode);
//Trace Procedures -------------------------------------------------------------------------------------------------------------------------------------

//Location Reporting Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objLocationReportingControl, SI_NGAPNode * ngNode);
void amf_ngap_procedure_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objLocationReportingFailureIndication, SI_NGAPNode * ngNode);
void amf_ngap_procedure_LocationReport( SI_AMF_DT_PDU_LocationReport * objLocationReport, SI_NGAPNode * ngNode);
//Location Reporting Procedures -------------------------------------------------------------------------------------------------------------------------------------

//UE TNLA Binding Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objUETNLABindingReleaseRequest, SI_NGAPNode * ngNode);
//UE TNLA Binding Procedures -------------------------------------------------------------------------------------------------------------------------------------

//UE Capability Management Procedures -------------------------------------------------------------------------------------------------------------------------------------
void amf_ngap_procedure_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objUERadioCapabilityInfoIndication, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objUERadioCapabilityCheckRequest, SI_NGAPNode * ngNode);
void amf_ngap_procedure_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objUERadioCapabilityCheckResponse, SI_NGAPNode * ngNode);
//UE Capability Management Procedures -------------------------------------------------------------------------------------------------------------------------------------

#endif