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

#ifndef SIRIK_PNGAP_H
#define SIRIK_PNGAP_H

#include "libNasPdu.h"
#include "libAMFAsn.h"

typedef struct __si_ngap_node SI_NGAPNode; 
SI_NGAPNode * __si_ngap_get_amf_connection();

int __si_ngap_create_and_send_NGSetupRequest( SI_NGAPNode * ngNode);

typedef void (*fp_ngap_app_messahe_handler)( uint8_t procedureCode, uint8_t messageType, void * msg, SI_NGAPNode * ngNode);

void __si_ngap_set_app_messahe_handler( fp_ngap_app_messahe_handler handler);

int __si_ngap_send_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objAMFConfigurationUpdate, SI_NGAPNode * ngNode);
int __si_ngap_send_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objAMFConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode);
int __si_ngap_send_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objAMFConfigurationUpdateFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objAMFStatusIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_NGAPNode * ngNode);
int __si_ngap_send_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_NGAPNode * ngNode);
int __si_ngap_send_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objDownlinkNASTransport, SI_NGAPNode * ngNode);
int __si_ngap_send_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objDownlinkNonUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
int __si_ngap_send_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objDownlinkRANConfigurationTransfer, SI_NGAPNode * ngNode);
int __si_ngap_send_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objDownlinkRANStatusTransfer, SI_NGAPNode * ngNode);
int __si_ngap_send_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objDownlinkUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
int __si_ngap_send_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objErrorIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objHandoverCancel, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objHandoverCancelAcknowledge, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objHandoverNotify, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objHandoverRequired, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objHandoverCommand, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objHandoverPreparationFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objHandoverRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objHandoverRequestAcknowledge, SI_NGAPNode * ngNode);
int __si_ngap_send_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objHandoverFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objInitialContextSetupRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objInitialContextSetupResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objInitialContextSetupFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objInitialUEMessage, SI_NGAPNode * ngNode);
int __si_ngap_send_LocationReport( SI_AMF_DT_PDU_LocationReport * objLocationReport, SI_NGAPNode * ngNode);
int __si_ngap_send_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objLocationReportingControl, SI_NGAPNode * ngNode);
int __si_ngap_send_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objLocationReportingFailureIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objNASNonDeliveryIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_NGReset( SI_AMF_DT_PDU_NGReset * objNGReset, SI_NGAPNode * ngNode);
int __si_ngap_send_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objNGResetAcknowledge, SI_NGAPNode * ngNode);
int __si_ngap_send_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objNGSetupRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objNGSetupResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objNGSetupFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objOverloadStart, SI_NGAPNode * ngNode);
int __si_ngap_send_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objOverloadStop, SI_NGAPNode * ngNode);
int __si_ngap_send_Paging( SI_AMF_DT_PDU_Paging * objPaging, SI_NGAPNode * ngNode);
int __si_ngap_send_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPathSwitchRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPathSwitchRequestAcknowledge, SI_NGAPNode * ngNode);
int __si_ngap_send_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPathSwitchRequestFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUSessionResourceModifyRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUSessionResourceModifyResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUSessionResourceModifyIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUSessionResourceModifyConfirm, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUSessionResourceNotify, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUSessionResourceReleaseCommand, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUSessionResourceReleaseResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUSessionResourceSetupRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUSessionResourceSetupResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPrivateMessage, SI_NGAPNode * ngNode);
int __si_ngap_send_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPWSCancelRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPWSCancelResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPWSFailureIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPWSRestartIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objRANConfigurationUpdate, SI_NGAPNode * ngNode);
int __si_ngap_send_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objRANConfigurationUpdateAcknowledge, SI_NGAPNode * ngNode);
int __si_ngap_send_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objRANConfigurationUpdateFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objRerouteNASRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objRRCInactiveTransitionReport, SI_NGAPNode * ngNode);
int __si_ngap_send_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objSecondaryRATDataUsageReport, SI_NGAPNode * ngNode);
int __si_ngap_send_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objTraceFailureIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_TraceStart( SI_AMF_DT_PDU_TraceStart * objTraceStart, SI_NGAPNode * ngNode);
int __si_ngap_send_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objUEContextModificationRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objUEContextModificationResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objUEContextModificationFailure, SI_NGAPNode * ngNode);
int __si_ngap_send_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_NGAPNode * ngNode);
int __si_ngap_send_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete, SI_NGAPNode * ngNode);
int __si_ngap_send_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objUERadioCapabilityCheckRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objUERadioCapabilityCheckResponse, SI_NGAPNode * ngNode);
int __si_ngap_send_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objUERadioCapabilityInfoIndication, SI_NGAPNode * ngNode);
int __si_ngap_send_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objUETNLABindingReleaseRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objUplinkNASTransport, SI_NGAPNode * ngNode);
int __si_ngap_send_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objUplinkNonUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
int __si_ngap_send_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objUplinkRANConfigurationTransfer, SI_NGAPNode * ngNode);
int __si_ngap_send_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objUplinkRANStatusTransfer, SI_NGAPNode * ngNode);
int __si_ngap_send_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objUplinkUEAssociatedNRPPaTransport, SI_NGAPNode * ngNode);
int __si_ngap_send_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objWriteReplaceWarningRequest, SI_NGAPNode * ngNode);
int __si_ngap_send_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objWriteReplaceWarningResponse, SI_NGAPNode * ngNode);



#endif

