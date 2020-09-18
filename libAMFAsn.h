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

//#include "sirik_core.h"
//#include "libAsn.h"

#ifndef SIRIK_AMF_ASN_H
#define SIRIK_AMF_ASN_H

void __si_amf_debug_pdu( uint8_t * buffer, int len);











#define id_AMFConfigurationUpdate_ProcedureCode                                  0
#define id_AMFStatusIndication_ProcedureCode                                     1
#define id_CellTrafficTrace_ProcedureCode                                        2
#define id_DeactivateTrace_ProcedureCode                                         3
#define id_DownlinkNASTransport_ProcedureCode                                    4
#define id_DownlinkNonUEAssociatedNRPPaTransport_ProcedureCode                   5
#define id_DownlinkRANConfigurationTransfer_ProcedureCode                        6
#define id_DownlinkRANStatusTransfer_ProcedureCode                               7
#define id_DownlinkUEAssociatedNRPPaTransport_ProcedureCode                      8
#define id_ErrorIndication_ProcedureCode                                         9
#define id_HandoverCancel_ProcedureCode                                          10
#define id_HandoverNotification_ProcedureCode                                    11
#define id_HandoverPreparation_ProcedureCode                                     12
#define id_HandoverResourceAllocation_ProcedureCode                              13
#define id_InitialContextSetup_ProcedureCode                                     14
#define id_InitialUEMessage_ProcedureCode                                        15
#define id_LocationReportingControl_ProcedureCode                                16
#define id_LocationReportingFailureIndication_ProcedureCode                      17
#define id_LocationReport_ProcedureCode                                          18
#define id_NASNonDeliveryIndication_ProcedureCode                                19
#define id_NGReset_ProcedureCode                                                 20
#define id_NGSetup_ProcedureCode                                                 21
#define id_OverloadStart_ProcedureCode                                           22
#define id_OverloadStop_ProcedureCode                                            23
#define id_Paging_ProcedureCode                                                  24
#define id_PathSwitchRequest_ProcedureCode                                       25
#define id_PDUSessionResourceModify_ProcedureCode                                26
#define id_PDUSessionResourceModifyIndication_ProcedureCode                      27
#define id_PDUSessionResourceRelease_ProcedureCode                               28
#define id_PDUSessionResourceSetup_ProcedureCode                                 29
#define id_PDUSessionResourceNotify_ProcedureCode                                30
#define id_PrivateMessage_ProcedureCode                                          31
#define id_PWSCancel_ProcedureCode                                               32
#define id_PWSFailureIndication_ProcedureCode                                    33
#define id_PWSRestartIndication_ProcedureCode                                    34
#define id_RANConfigurationUpdate_ProcedureCode                                  35
#define id_RerouteNASRequest_ProcedureCode                                       36
#define id_RRCInactiveTransitionReport_ProcedureCode                             37
#define id_TraceFailureIndication_ProcedureCode                                  38
#define id_TraceStart_ProcedureCode                                              39
#define id_UEContextModification_ProcedureCode                                   40
#define id_UEContextRelease_ProcedureCode                                        41
#define id_UEContextReleaseRequest_ProcedureCode                                 42
#define id_UERadioCapabilityCheck_ProcedureCode                                  43
#define id_UERadioCapabilityInfoIndication_ProcedureCode                         44
#define id_UETNLABindingRelease_ProcedureCode                                    45
#define id_UplinkNASTransport_ProcedureCode                                      46
#define id_UplinkNonUEAssociatedNRPPaTransport_ProcedureCode                     47
#define id_UplinkRANConfigurationTransfer_ProcedureCode                          48
#define id_UplinkRANStatusTransfer_ProcedureCode                                 49
#define id_UplinkUEAssociatedNRPPaTransport_ProcedureCode                        50
#define id_WriteReplaceWarning_ProcedureCode                                     51
#define id_SecondaryRATDataUsageReport_ProcedureCode                             52



#define id_AllowedNSSAI_ProtocolIEs                                              0
#define id_AMFName_ProtocolIEs                                                   1
#define id_AMFOverloadResponse_ProtocolIEs                                       2
#define id_AMFSetID_ProtocolIEs                                                  3
#define id_AMF_TNLAssociationFailedToSetupList_ProtocolIEs                       4
#define id_AMF_TNLAssociationSetupList_ProtocolIEs                               5
#define id_AMF_TNLAssociationToAddList_ProtocolIEs                               6
#define id_AMF_TNLAssociationToRemoveList_ProtocolIEs                            7
#define id_AMF_TNLAssociationToUpdateList_ProtocolIEs                            8
#define id_AMFTrafficLoadReductionIndication_ProtocolIEs                         9
#define id_AMF_UE_NGAP_ID_ProtocolIEs                                            10
#define id_AssistanceDataForPaging_ProtocolIEs                                   11
#define id_BroadcastCancelledAreaList_ProtocolIEs                                12
#define id_BroadcastCompletedAreaList_ProtocolIEs                                13
#define id_CancelAllWarningMessages_ProtocolIEs                                  14
#define id_Cause_ProtocolIEs                                                     15
#define id_CellIDListForRestart_ProtocolIEs                                      16
#define id_ConcurrentWarningMessageInd_ProtocolIEs                               17
#define id_CoreNetworkAssistanceInformationForInactive_ProtocolIEs               18
#define id_CriticalityDiagnostics_ProtocolIEs                                    19
#define id_DataCodingScheme_ProtocolIEs                                          20
#define id_DefaultPagingDRX_ProtocolIEs                                          21
#define id_DirectForwardingPathAvailability_ProtocolIEs                          22
#define id_EmergencyAreaIDListForRestart_ProtocolIEs                             23
#define id_EmergencyFallbackIndicator_ProtocolIEs                                24
#define id_EUTRA_CGI_ProtocolIEs                                                 25
#define id_FiveG_S_TMSI_ProtocolIEs                                              26
#define id_GlobalRANNodeID_ProtocolIEs                                           27
#define id_GUAMI_ProtocolIEs                                                     28
#define id_HandoverType_ProtocolIEs                                              29
#define id_IMSVoiceSupportIndicator_ProtocolIEs                                  30
#define id_IndexToRFSP_ProtocolIEs                                               31
#define id_InfoOnRecommendedCellsAndRANNodesForPaging_ProtocolIEs                32
#define id_LocationReportingRequestType_ProtocolIEs                              33
#define id_MaskedIMEISV_ProtocolIEs                                              34
#define id_MessageIdentifier_ProtocolIEs                                         35
#define id_MobilityRestrictionList_ProtocolIEs                                   36
#define id_NASC_ProtocolIEs                                                      37
#define id_NAS_PDU_ProtocolIEs                                                   38
#define id_NASSecurityParametersFromNGRAN_ProtocolIEs                            39
#define id_NewAMF_UE_NGAP_ID_ProtocolIEs                                         40
#define id_NewSecurityContextInd_ProtocolIEs                                     41
#define id_NGAP_Message_ProtocolIEs                                              42
#define id_NGRAN_CGI_ProtocolIEs                                                 43
#define id_NGRANTraceID_ProtocolIEs                                              44
#define id_NR_CGI_ProtocolIEs                                                    45
#define id_NRPPa_PDU_ProtocolIEs                                                 46
#define id_NumberOfBroadcastsRequested_ProtocolIEs                               47
#define id_OldAMF_ProtocolIEs                                                    48
#define id_OverloadStartNSSAIList_ProtocolIEs                                    49
#define id_PagingDRX_ProtocolIEs                                                 50
#define id_PagingOrigin_ProtocolIEs                                              51
#define id_PagingPriority_ProtocolIEs                                            52
#define id_PDUSessionResourceAdmittedList_ProtocolIEs                            53
#define id_PDUSessionResourceFailedToModifyListModRes_ProtocolIEs                54
#define id_PDUSessionResourceFailedToSetupListCxtRes_ProtocolIEs                 55
#define id_PDUSessionResourceFailedToSetupListHOAck_ProtocolIEs                  56
#define id_PDUSessionResourceFailedToSetupListPSReq_ProtocolIEs                  57
#define id_PDUSessionResourceFailedToSetupListSURes_ProtocolIEs                  58
#define id_PDUSessionResourceHandoverList_ProtocolIEs                            59
#define id_PDUSessionResourceListCxtRelCpl_ProtocolIEs                           60
#define id_PDUSessionResourceListHORqd_ProtocolIEs                               61
#define id_PDUSessionResourceModifyListModCfm_ProtocolIEs                        62
#define id_PDUSessionResourceModifyListModInd_ProtocolIEs                        63
#define id_PDUSessionResourceModifyListModReq_ProtocolIEs                        64
#define id_PDUSessionResourceModifyListModRes_ProtocolIEs                        65
#define id_PDUSessionResourceNotifyList_ProtocolIEs                              66
#define id_PDUSessionResourceReleasedListNot_ProtocolIEs                         67
#define id_PDUSessionResourceReleasedListPSAck_ProtocolIEs                       68
#define id_PDUSessionResourceReleasedListPSFail_ProtocolIEs                      69
#define id_PDUSessionResourceReleasedListRelRes_ProtocolIEs                      70
#define id_PDUSessionResourceSetupListCxtReq_ProtocolIEs                         71
#define id_PDUSessionResourceSetupListCxtRes_ProtocolIEs                         72
#define id_PDUSessionResourceSetupListHOReq_ProtocolIEs                          73
#define id_PDUSessionResourceSetupListSUReq_ProtocolIEs                          74
#define id_PDUSessionResourceSetupListSURes_ProtocolIEs                          75
#define id_PDUSessionResourceToBeSwitchedDLList_ProtocolIEs                      76
#define id_PDUSessionResourceSwitchedList_ProtocolIEs                            77
#define id_PDUSessionResourceToReleaseListHOCmd_ProtocolIEs                      78
#define id_PDUSessionResourceToReleaseListRelCmd_ProtocolIEs                     79
#define id_PLMNSupportList_ProtocolIEs                                           80
#define id_PWSFailedCellIDList_ProtocolIEs                                       81
#define id_RANNodeName_ProtocolIEs                                               82
#define id_RANPagingPriority_ProtocolIEs                                         83
#define id_RANStatusTransfer_TransparentContainer_ProtocolIEs                    84
#define id_RAN_UE_NGAP_ID_ProtocolIEs                                            85
#define id_RelativeAMFCapacity_ProtocolIEs                                       86
#define id_RepetitionPeriod_ProtocolIEs                                          87
#define id_ResetType_ProtocolIEs                                                 88
#define id_RoutingID_ProtocolIEs                                                 89
#define id_RRCEstablishmentCause_ProtocolIEs                                     90
#define id_RRCInactiveTransitionReportRequest_ProtocolIEs                        91
#define id_RRCState_ProtocolIEs                                                  92
#define id_SecurityContext_ProtocolIEs                                           93
#define id_SecurityKey_ProtocolIEs                                               94
#define id_SerialNumber_ProtocolIEs                                              95
#define id_ServedGUAMIList_ProtocolIEs                                           96
#define id_SliceSupportList_ProtocolIEs                                          97
#define id_SONConfigurationTransferDL_ProtocolIEs                                98
#define id_SONConfigurationTransferUL_ProtocolIEs                                99
#define id_SourceAMF_UE_NGAP_ID_ProtocolIEs                                      100
#define id_SourceToTarget_TransparentContainer_ProtocolIEs                       101
#define id_SupportedTAList_ProtocolIEs                                           102
#define id_TAIListForPaging_ProtocolIEs                                          103
#define id_TAIListForRestart_ProtocolIEs                                         104
#define id_TargetID_ProtocolIEs                                                  105
#define id_TargetToSource_TransparentContainer_ProtocolIEs                       106
#define id_TimeToWait_ProtocolIEs                                                107
#define id_TraceActivation_ProtocolIEs                                           108
#define id_TraceCollectionEntityIPAddress_ProtocolIEs                            109
#define id_UEAggregateMaximumBitRate_ProtocolIEs                                 110
#define id_UE_associatedLogicalNG_connectionList_ProtocolIEs                     111
#define id_UEContextRequest_ProtocolIEs                                          112
#define id_UE_NGAP_IDs_ProtocolIEs                                               114
#define id_UEPagingIdentity_ProtocolIEs                                          115
#define id_UEPresenceInAreaOfInterestList_ProtocolIEs                            116
#define id_UERadioCapability_ProtocolIEs                                         117
#define id_UERadioCapabilityForPaging_ProtocolIEs                                118
#define id_UESecurityCapabilities_ProtocolIEs                                    119
#define id_UnavailableGUAMIList_ProtocolIEs                                      120
#define id_UserLocationInformation_ProtocolIEs                                   121
#define id_WarningAreaList_ProtocolIEs                                           122
#define id_WarningMessageContents_ProtocolIEs                                    123
#define id_WarningSecurityInfo_ProtocolIEs                                       124
#define id_WarningType_ProtocolIEs                                               125
#define id_AdditionalUL_NGU_UP_TNLInformation_ProtocolIEs                        126
#define id_DataForwardingNotPossible_ProtocolIEs                                 127
#define id_DL_NGU_UP_TNLInformation_ProtocolIEs                                  128
#define id_NetworkInstance_ProtocolIEs                                           129
#define id_PDUSessionAggregateMaximumBitRate_ProtocolIEs                         130
#define id_PDUSessionResourceFailedToModifyListModCfm_ProtocolIEs                131
#define id_PDUSessionResourceFailedToSetupListCxtFail_ProtocolIEs                132
#define id_PDUSessionResourceListCxtRelReq_ProtocolIEs                           133
#define id_PDUSessionType_ProtocolIEs                                            134
#define id_QosFlowAddOrModifyRequestList_ProtocolIEs                             135
#define id_QosFlowSetupRequestList_ProtocolIEs                                   136
#define id_QosFlowToReleaseList_ProtocolIEs                                      137
#define id_SecurityIndication_ProtocolIEs                                        138
#define id_UL_NGU_UP_TNLInformation_ProtocolIEs                                  139
#define id_UL_NGU_UP_TNLModifyList_ProtocolIEs                                   140
#define id_WarningAreaCoordinates_ProtocolIEs                                    141
#define id_PDUSessionResourceSecondaryRATUsageList_ProtocolIEs                   142
#define id_HandoverFlag_ProtocolIEs                                              143
#define id_SecondaryRATUsageInformation_ProtocolIEs                              144
#define id_PDUSessionResourceReleaseResponseTransfer_ProtocolIEs                 145
#define id_RedirectionVoiceFallback_ProtocolIEs                                  146
#define id_UERetentionInformation_ProtocolIEs                                    147
#define id_S_NSSAI_ProtocolIEs                                                   148
#define id_PSCellInformation_ProtocolIEs                                         149
#define id_LastEUTRAN_PLMNIdentity_ProtocolIEs                                   150
#define id_MaximumIntegrityProtectedDataRate_DL_ProtocolIEs                      151
#define id_AdditionalDLForwardingUPTNLInformation_ProtocolIEs                    152
#define id_AdditionalDLUPTNLInformationForHOList_ProtocolIEs                     153
#define id_AdditionalNGU_UP_TNLInformation_ProtocolIEs                           154
#define id_AdditionalDLQosFlowPerTNLInformation_ProtocolIEs                      155
#define id_SecurityResult_ProtocolIEs                                            156
#define id_ENDC_SONConfigurationTransferDL_ProtocolIEs                           157
#define id_ENDC_SONConfigurationTransferUL_ProtocolIEs                           158
#define id_OldAssociatedQosFlowList_ULendmarkerexpected_ProtocolIEs              159
#define id_CNTypeRestrictionsForEquivalent_ProtocolIEs                           160
#define id_CNTypeRestrictionsForServing_ProtocolIEs                              161
#define id_NewGUAMI_ProtocolIEs                                                  162
#define id_ULForwarding_ProtocolIEs                                              163
#define id_ULForwardingUP_TNLInformation_ProtocolIEs                             164
#define id_CNAssistedRANTuning_ProtocolIEs                                       165
#define id_CommonNetworkInstance_ProtocolIEs                                     166
#define id_NGRAN_TNLAssociationToRemoveList_ProtocolIEs                          167
#define id_TNLAssociationTransportLayerAddressNGRAN_ProtocolIEs                  168
#define id_EndpointIPAddressAndPort_ProtocolIEs                                  169
#define id_LocationReportingAdditionalInfo_ProtocolIEs                           170
#define id_SourceToTarget_AMFInformationReroute_ProtocolIEs                      171
#define id_AdditionalULForwardingUPTNLInformation_ProtocolIEs                    172
#define id_SCTP_TLAs_ProtocolIEs                                                 173



#define maxnoofAllowedAreas_const                                                16
#define maxnoofAllowedS_NSSAIs_const                                             8
#define maxnoofBPLMNs_const                                                      12
#define maxnoofCellIDforWarning_const                                            65535
#define maxnoofCellinAoI_const                                                   256
#define maxnoofCellinEAI_const                                                   65535
#define maxnoofCellinTAI_const                                                   65535
#define maxnoofCellsingNB_const                                                  16384
#define maxnoofCellsinngeNB_const                                                256
#define maxnoofCellsinUEHistoryInfo_const                                        16
#define maxnoofCellsUEMovingTrajectory_const                                     16
#define maxnoofDRBs_const                                                        32
#define maxnoofEmergencyAreaID_const                                             65535
#define maxnoofEAIforRestart_const                                               256
#define maxnoofEPLMNs_const                                                      15
#define maxnoofEPLMNsPlusOne_const                                               16
#define maxnoofE_RABs_const                                                      256
#define maxnoofErrors_const                                                      256
#define maxnoofForbTACs_const                                                    4096
#define maxnoofMultiConnectivity_const                                           4
#define maxnoofMultiConnectivityMinusOne_const                                   3
#define maxnoofNGConnectionsToReset_const                                        65536
#define maxnoofPDUSessions_const                                                 256
#define maxnoofPLMNs_const                                                       12
#define maxnoofQosFlows_const                                                    64
#define maxnoofRANNodeinAoI_const                                                64
#define maxnoofRecommendedCells_const                                            16
#define maxnoofRecommendedRANNodes_const                                         16
#define maxnoofAoI_const                                                         64
#define maxnoofServedGUAMIs_const                                                256
#define maxnoofSliceItems_const                                                  1024
#define maxnoofTACs_const                                                        256
#define maxnoofTAIforInactive_const                                              16
#define maxnoofTAIforPaging_const                                                16
#define maxnoofTAIforRestart_const                                               2048
#define maxnoofTAIforWarning_const                                               65535
#define maxnoofTAIinAoI_const                                                    16
#define maxnoofTimePeriods_const                                                 2
#define maxnoofTNLAssociations_const                                             32
#define maxnoofXnExtTLAs_const                                                   16
#define maxnoofXnGTP_TLAs_const                                                  16
#define maxnoofXnTLAs_const                                                      2



#define UserLocationInformation_userLocationInformationEUTRA_val                 0
#define UserLocationInformation_userLocationInformationNR_val                    1
#define UserLocationInformation_userLocationInformationN3IWF_val                 2
#define UserLocationInformation_choice_Extensions_val                            3

#define UEIdentityIndexValue_indexLength10_val                                   0
#define UEIdentityIndexValue_choice_Extensions_val                               1

#define Cause_radioNetwork_val                                                   0
#define Cause_transport_val                                                      1
#define Cause_nas_val                                                            2
#define Cause_protocol_val                                                       3
#define Cause_misc_val                                                           4
#define Cause_choice_Extensions_val                                              5

#define UE_NGAP_IDs_uE_NGAP_ID_pair_val                                          0
#define UE_NGAP_IDs_aMF_UE_NGAP_ID_val                                           1
#define UE_NGAP_IDs_choice_Extensions_val                                        2

#define GNB_ID_gNB_ID_val                                                        0
#define GNB_ID_choice_Extensions_val                                             1

#define NgENB_ID_macroNgENB_ID_val                                               0
#define NgENB_ID_shortMacroNgENB_ID_val                                          1
#define NgENB_ID_longMacroNgENB_ID_val                                           2
#define NgENB_ID_choice_Extensions_val                                           3

#define N3IWF_ID_n3IWF_ID_val                                                    0
#define N3IWF_ID_choice_Extensions_val                                           1

#define GlobalRANNodeID_globalGNB_ID_val                                         0
#define GlobalRANNodeID_globalNgENB_ID_val                                       1
#define GlobalRANNodeID_globalN3IWF_ID_val                                       2
#define GlobalRANNodeID_choice_Extensions_val                                    3

#define TargetID_targetRANNodeID_val                                             0
#define TargetID_targeteNB_ID_val                                                1
#define TargetID_choice_Extensions_val                                           2

#define UEPagingIdentity_fiveG_S_TMSI_val                                        0
#define UEPagingIdentity_choice_Extensions_val                                   1

#define ResetType_nG_Interface_val                                               0
#define ResetType_partOfNG_Interface_val                                         1
#define ResetType_choice_Extensions_val                                          2

#define OverloadResponse_overloadAction_val                                      0
#define OverloadResponse_choice_Extensions_val                                   1

#define SONInformation_sONInformationRequest_val                                 0
#define SONInformation_sONInformationReply_val                                   1
#define SONInformation_choice_Extensions_val                                     2

#define WarningAreaList_eUTRA_CGIListForWarning_val                              0
#define WarningAreaList_nR_CGIListForWarning_val                                 1
#define WarningAreaList_tAIListForWarning_val                                    2
#define WarningAreaList_emergencyAreaIDList_val                                  3
#define WarningAreaList_choice_Extensions_val                                    4

#define BroadcastCompletedAreaList_cellIDBroadcastEUTRA_val                      0
#define BroadcastCompletedAreaList_tAIBroadcastEUTRA_val                         1
#define BroadcastCompletedAreaList_emergencyAreaIDBroadcastEUTRA_val             2
#define BroadcastCompletedAreaList_cellIDBroadcastNR_val                         3
#define BroadcastCompletedAreaList_tAIBroadcastNR_val                            4
#define BroadcastCompletedAreaList_emergencyAreaIDBroadcastNR_val                5
#define BroadcastCompletedAreaList_choice_Extensions_val                         6

#define BroadcastCancelledAreaList_cellIDCancelledEUTRA_val                      0
#define BroadcastCancelledAreaList_tAICancelledEUTRA_val                         1
#define BroadcastCancelledAreaList_emergencyAreaIDCancelledEUTRA_val             2
#define BroadcastCancelledAreaList_cellIDCancelledNR_val                         3
#define BroadcastCancelledAreaList_tAICancelledNR_val                            4
#define BroadcastCancelledAreaList_emergencyAreaIDCancelledNR_val                5
#define BroadcastCancelledAreaList_choice_Extensions_val                         6

#define CellIDListForRestart_eUTRA_CGIListforRestart_val                         0
#define CellIDListForRestart_nR_CGIListforRestart_val                            1
#define CellIDListForRestart_choice_Extensions_val                               2

#define PWSFailedCellIDList_eUTRA_CGI_PWSFailedList_val                          0
#define PWSFailedCellIDList_nR_CGI_PWSFailedList_val                             1
#define PWSFailedCellIDList_choice_Extensions_val                                2

#define NGRAN_CGI_nR_CGI_val                                                     0
#define NGRAN_CGI_eUTRA_CGI_val                                                  1
#define NGRAN_CGI_choice_Extensions_val                                          2

// AdditionalDLUPTNLInformationForHOList
//SEQUENCE OF AdditionalDLUPTNLInformationForHOItem, MIN=1, MAX=maxnoofMultiConnectivityMinusOne  ADT=0  DT=2
typedef struct __si_amf_dt_AdditionalDLUPTNLInformationForHOList
{
	SI_LinkedList * AdditionalDLUPTNLInformationForHOItem;
} SI_AMF_DT_AdditionalDLUPTNLInformationForHOList;


// TransportLayerAddress
// BITSTRING,BIT STRING(SIZE(1..160,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_TransportLayerAddress
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_TransportLayerAddress;

// GTP-TEID
// OCTETSTRING,OCTET STRING(SIZE(4))
// ADT=0  DT=2
typedef struct __si_amf_dt_GTP_TEID
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_GTP_TEID;

// GTPTunnel
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_GTPTunnel
{
	SI_AMF_DT_TransportLayerAddress * transportLayerAddress;

	SI_AMF_DT_GTP_TEID * gTP_TEID;

} SI_AMF_DT_GTPTunnel;


// UPTransportLayerInformation
// ADT=0  DT=1
typedef struct __si_amf_dt_UPTransportLayerInformation
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_GTPTunnel * gTPTunnel;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_UPTransportLayerInformation;


// QosFlowListWithDataForwarding
//SEQUENCE OF QosFlowItemWithDataForwarding, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowListWithDataForwarding
{
	SI_LinkedList * QosFlowItemWithDataForwarding;
} SI_AMF_DT_QosFlowListWithDataForwarding;


// AdditionalDLUPTNLInformationForHOItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AdditionalDLUPTNLInformationForHOItem
{
	SI_AMF_DT_UPTransportLayerInformation * additionalDL_NGU_UP_TNLInformation;

	SI_AMF_DT_QosFlowListWithDataForwarding * additionalQosFlowSetupResponseList;

	SI_AMF_DT_UPTransportLayerInformation * additionalDLForwardingUPTNLInformation;
	int isPresent_additionalDLForwardingUPTNLInformation;

} SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem;


// AdditionalDLUPTNLInformationForHOItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AdditionalDLUPTNLInformationForHOItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs;


//TODO: DataType -><- Got NULL

// AdditionalQosFlowInformation
// ADT=0  DT=1
typedef enum __si_amf_dt_AdditionalQosFlowInformation
{
	AdditionalQosFlowInformation_more_likely_val
} SI_AMF_DT_AdditionalQosFlowInformation;


// PriorityLevelARP
// INTEGER,INTEGER(1..15),MIN=1,MAX=15
// ADT=0  DT=2
typedef struct __si_amf_dt_PriorityLevelARP
{
	unsigned long long int data;
} SI_AMF_DT_PriorityLevelARP;

// Pre-emptionCapability
// ADT=0  DT=1
typedef enum __si_amf_dt_Pre_emptionCapability
{
	Pre_emptionCapability_shall_not_trigger_pre_emption_val,
	Pre_emptionCapability_may_trigger_pre_emption_val
} SI_AMF_DT_Pre_emptionCapability;


// Pre-emptionVulnerability
// ADT=0  DT=1
typedef enum __si_amf_dt_Pre_emptionVulnerability
{
	Pre_emptionVulnerability_not_pre_emptable_val,
	Pre_emptionVulnerability_pre_emptable_val
} SI_AMF_DT_Pre_emptionVulnerability;


// AllocationAndRetentionPriority
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AllocationAndRetentionPriority
{
	unsigned long long int priorityLevelARP;

	uint8_t selected_epre_emptionCapability;
	int extSelected_epre_emptionCapability;

	uint8_t selected_epre_emptionVulnerability;
	int extSelected_epre_emptionVulnerability;

} SI_AMF_DT_AllocationAndRetentionPriority;


// AllocationAndRetentionPriority-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AllocationAndRetentionPriority_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs;


// AllowedNSSAI
//SEQUENCE OF AllowedNSSAI-Item, MIN=1, MAX=maxnoofAllowedS-NSSAIs  ADT=0  DT=2
typedef struct __si_amf_dt_AllowedNSSAI
{
	SI_LinkedList * AllowedNSSAI_Item;
} SI_AMF_DT_AllowedNSSAI;


// SST
// OCTETSTRING,OCTET STRING(SIZE(1))
// ADT=0  DT=2
typedef struct __si_amf_dt_SST
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_SST;

// SD
// OCTETSTRING,OCTET STRING(SIZE(3))
// ADT=0  DT=2
typedef struct __si_amf_dt_SD
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_SD;

// S-NSSAI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_S_NSSAI
{
	SI_AMF_DT_SST * sST;

	SI_AMF_DT_SD * sD;
	int isPresent_sD;

} SI_AMF_DT_S_NSSAI;


// AllowedNSSAI-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AllowedNSSAI_Item
{
	SI_AMF_DT_S_NSSAI * s_NSSAI;

} SI_AMF_DT_AllowedNSSAI_Item;


// AllowedNSSAI-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AllowedNSSAI_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AllowedNSSAI_Item_ExtIEs;


// AllowedTACs
//SEQUENCE OF TAC, MIN=1, MAX=maxnoofAllowedAreas  ADT=0  DT=2
typedef struct __si_amf_dt_AllowedTACs
{
	SI_LinkedList * TAC;
} SI_AMF_DT_AllowedTACs;


// AMFName
// PrintableString,PrintableString(SIZE(1..150,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_AMFName
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_AMFName;

// PLMNIdentity
// OCTETSTRING,OCTET STRING(SIZE(3))
// ADT=0  DT=2
typedef struct __si_amf_dt_PLMNIdentity
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PLMNIdentity;

// GNB-IDBS
// BITSTRING,BIT STRING(SIZE(22..32))
// ADT=0  DT=2
typedef struct __si_amf_dt_GNB_IDBS
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_GNB_IDBS;

// GNB-ID
// ADT=0  DT=1
typedef struct __si_amf_dt_GNB_ID
{
	union 
	{
		// ParserName = BITSTRING;
		SI_AMF_DT_GNB_IDBS * gNB_ID;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_GNB_ID;


// GlobalGNB-ID
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_GlobalGNB_ID
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_GNB_ID * gNB_ID;

} SI_AMF_DT_GlobalGNB_ID;


// NgENB-IDmacroNgENB-ID
// BITSTRING,BIT STRING(SIZE(20))
// ADT=0  DT=2
typedef struct __si_amf_dt_NgENB_IDmacroNgENB_ID
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_NgENB_IDmacroNgENB_ID;

// NgENB-IDshortMacroNgENB-ID
// BITSTRING,BIT STRING(SIZE(18))
// ADT=0  DT=2
typedef struct __si_amf_dt_NgENB_IDshortMacroNgENB_ID
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_NgENB_IDshortMacroNgENB_ID;

// NgENB-IDlongMacroNgENB-ID
// BITSTRING,BIT STRING(SIZE(21))
// ADT=0  DT=2
typedef struct __si_amf_dt_NgENB_IDlongMacroNgENB_ID
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_NgENB_IDlongMacroNgENB_ID;

// NgENB-ID
// ADT=0  DT=1
typedef struct __si_amf_dt_NgENB_ID
{
	union 
	{
		// ParserName = BITSTRING;
		SI_AMF_DT_NgENB_IDmacroNgENB_ID * macroNgENB_ID;

		// ParserName = BITSTRING;
		SI_AMF_DT_NgENB_IDshortMacroNgENB_ID * shortMacroNgENB_ID;

		// ParserName = BITSTRING;
		SI_AMF_DT_NgENB_IDlongMacroNgENB_ID * longMacroNgENB_ID;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_NgENB_ID;


// GlobalNgENB-ID
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_GlobalNgENB_ID
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_NgENB_ID * ngENB_ID;

} SI_AMF_DT_GlobalNgENB_ID;


// N3IWF-IDBS
// BITSTRING,BIT STRING(SIZE(16))
// ADT=0  DT=2
typedef struct __si_amf_dt_N3IWF_IDBS
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_N3IWF_IDBS;

// N3IWF-ID
// ADT=0  DT=1
typedef struct __si_amf_dt_N3IWF_ID
{
	union 
	{
		// ParserName = BITSTRING;
		SI_AMF_DT_N3IWF_IDBS * n3IWF_ID;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_N3IWF_ID;


// GlobalN3IWF-ID
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_GlobalN3IWF_ID
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_N3IWF_ID * n3IWF_ID;

} SI_AMF_DT_GlobalN3IWF_ID;


// GlobalRANNodeID
// ADT=0  DT=1
typedef struct __si_amf_dt_GlobalRANNodeID
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_GlobalGNB_ID * globalGNB_ID;

		// ParserName = SEQUENCE;
		SI_AMF_DT_GlobalNgENB_ID * globalNgENB_ID;

		// ParserName = SEQUENCE;
		SI_AMF_DT_GlobalN3IWF_ID * globalN3IWF_ID;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_GlobalRANNodeID;


// TAC
// OCTETSTRING,OCTET STRING(SIZE(3))
// ADT=0  DT=2
typedef struct __si_amf_dt_TAC
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_TAC;

// TAI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAI
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_TAC * tAC;

} SI_AMF_DT_TAI;


// AMFPagingTarget
// ADT=0  DT=1
typedef struct __si_amf_dt_AMFPagingTarget
{
	union 
	{
		// ParserName = CHOICE;
		SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;

		// ParserName = SEQUENCE;
		SI_AMF_DT_TAI * tAI;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_AMFPagingTarget;


// AMFPagingTarget-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_AMFPagingTarget_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AMFPagingTarget_ExtIEs;


// AMFPointer
// BITSTRING,BIT STRING(SIZE(6))
// ADT=0  DT=2
typedef struct __si_amf_dt_AMFPointer
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_AMFPointer;

// AMFRegionID
// BITSTRING,BIT STRING(SIZE(8))
// ADT=0  DT=2
typedef struct __si_amf_dt_AMFRegionID
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_AMFRegionID;

// AMFSetID
// BITSTRING,BIT STRING(SIZE(10))
// ADT=0  DT=2
typedef struct __si_amf_dt_AMFSetID
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_AMFSetID;

// AMF-TNLAssociationSetupList
//SEQUENCE OF AMF-TNLAssociationSetupItem, MIN=1, MAX=maxnoofTNLAssociations  ADT=0  DT=2
typedef struct __si_amf_dt_AMF_TNLAssociationSetupList
{
	SI_LinkedList * AMF_TNLAssociationSetupItem;
} SI_AMF_DT_AMF_TNLAssociationSetupList;


// CPTransportLayerInformation
// ADT=0  DT=1
typedef struct __si_amf_dt_CPTransportLayerInformation
{
	union 
	{
		// ParserName = BITSTRING;
		SI_AMF_DT_TransportLayerAddress * endpointIPAddress;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_CPTransportLayerInformation;


// AMF-TNLAssociationSetupItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AMF_TNLAssociationSetupItem
{
	SI_AMF_DT_CPTransportLayerInformation * aMF_TNLAssociationAddress;

} SI_AMF_DT_AMF_TNLAssociationSetupItem;


// AMF-TNLAssociationSetupItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AMF_TNLAssociationSetupItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs;


// AMF-TNLAssociationToAddList
//SEQUENCE OF AMF-TNLAssociationToAddItem, MIN=1, MAX=maxnoofTNLAssociations  ADT=0  DT=2
typedef struct __si_amf_dt_AMF_TNLAssociationToAddList
{
	SI_LinkedList * AMF_TNLAssociationToAddItem;
} SI_AMF_DT_AMF_TNLAssociationToAddList;


// TNLAssociationUsage
// ADT=0  DT=1
typedef enum __si_amf_dt_TNLAssociationUsage
{
	TNLAssociationUsage_ue_val,
	TNLAssociationUsage_non_ue_val,
	TNLAssociationUsage_both_val
} SI_AMF_DT_TNLAssociationUsage;


// TNLAddressWeightFactor
// INTEGER,INTEGER(0..255),MIN=0,MAX=255
// ADT=0  DT=2
typedef struct __si_amf_dt_TNLAddressWeightFactor
{
	unsigned long long int data;
} SI_AMF_DT_TNLAddressWeightFactor;

// AMF-TNLAssociationToAddItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AMF_TNLAssociationToAddItem
{
	SI_AMF_DT_CPTransportLayerInformation * aMF_TNLAssociationAddress;

	uint8_t selected_etNLAssociationUsage;
	int extSelected_etNLAssociationUsage;
	int isPresent_tNLAssociationUsage;

	unsigned long long int tNLAddressWeightFactor;

} SI_AMF_DT_AMF_TNLAssociationToAddItem;


// AMF-TNLAssociationToAddItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AMF_TNLAssociationToAddItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs;


// AMF-TNLAssociationToRemoveList
//SEQUENCE OF AMF-TNLAssociationToRemoveItem, MIN=1, MAX=maxnoofTNLAssociations  ADT=0  DT=2
typedef struct __si_amf_dt_AMF_TNLAssociationToRemoveList
{
	SI_LinkedList * AMF_TNLAssociationToRemoveItem;
} SI_AMF_DT_AMF_TNLAssociationToRemoveList;


// AMF-TNLAssociationToRemoveItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AMF_TNLAssociationToRemoveItem
{
	SI_AMF_DT_CPTransportLayerInformation * aMF_TNLAssociationAddress;

} SI_AMF_DT_AMF_TNLAssociationToRemoveItem;


// AMF-TNLAssociationToRemoveItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AMF_TNLAssociationToRemoveItem_ExtIEs
{
	// Got Success L:2926
	//CPTransportLayerInformation,  optional
	SI_AMF_DT_CPTransportLayerInformation * tNLAssociationTransportLayerAddressNGRAN;
	int isPresent_tNLAssociationTransportLayerAddressNGRAN;

} SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs;


// AMF-TNLAssociationToUpdateList
//SEQUENCE OF AMF-TNLAssociationToUpdateItem, MIN=1, MAX=maxnoofTNLAssociations  ADT=0  DT=2
typedef struct __si_amf_dt_AMF_TNLAssociationToUpdateList
{
	SI_LinkedList * AMF_TNLAssociationToUpdateItem;
} SI_AMF_DT_AMF_TNLAssociationToUpdateList;


// AMF-TNLAssociationToUpdateItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AMF_TNLAssociationToUpdateItem
{
	SI_AMF_DT_CPTransportLayerInformation * aMF_TNLAssociationAddress;

	uint8_t selected_etNLAssociationUsage;
	int extSelected_etNLAssociationUsage;
	int isPresent_tNLAssociationUsage;

	unsigned long long int tNLAddressWeightFactor;
	int isPresent_tNLAddressWeightFactor;

} SI_AMF_DT_AMF_TNLAssociationToUpdateItem;


// AMF-TNLAssociationToUpdateItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AMF_TNLAssociationToUpdateItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs;


// AMF-UE-NGAP-ID
// INTEGER,INTEGER(0..1099511627775),MIN=0,MAX=1099511627775
// ADT=0  DT=2
typedef struct __si_amf_dt_AMF_UE_NGAP_ID
{
	unsigned long long int data;
} SI_AMF_DT_AMF_UE_NGAP_ID;

// AreaOfInterestTAIList
//SEQUENCE OF AreaOfInterestTAIItem, MIN=1, MAX=maxnoofTAIinAoI  ADT=0  DT=2
typedef struct __si_amf_dt_AreaOfInterestTAIList
{
	SI_LinkedList * AreaOfInterestTAIItem;
} SI_AMF_DT_AreaOfInterestTAIList;


// AreaOfInterestCellList
//SEQUENCE OF AreaOfInterestCellItem, MIN=1, MAX=maxnoofCellinAoI  ADT=0  DT=2
typedef struct __si_amf_dt_AreaOfInterestCellList
{
	SI_LinkedList * AreaOfInterestCellItem;
} SI_AMF_DT_AreaOfInterestCellList;


// AreaOfInterestRANNodeList
//SEQUENCE OF AreaOfInterestRANNodeItem, MIN=1, MAX=maxnoofRANNodeinAoI  ADT=0  DT=2
typedef struct __si_amf_dt_AreaOfInterestRANNodeList
{
	SI_LinkedList * AreaOfInterestRANNodeItem;
} SI_AMF_DT_AreaOfInterestRANNodeList;


// AreaOfInterest
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AreaOfInterest
{
	SI_AMF_DT_AreaOfInterestTAIList * areaOfInterestTAIList;
	int isPresent_areaOfInterestTAIList;

	SI_AMF_DT_AreaOfInterestCellList * areaOfInterestCellList;
	int isPresent_areaOfInterestCellList;

	SI_AMF_DT_AreaOfInterestRANNodeList * areaOfInterestRANNodeList;
	int isPresent_areaOfInterestRANNodeList;

} SI_AMF_DT_AreaOfInterest;


// AreaOfInterest-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AreaOfInterest_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AreaOfInterest_ExtIEs;


// NRCellIdentity
// BITSTRING,BIT STRING(SIZE(36))
// ADT=0  DT=2
typedef struct __si_amf_dt_NRCellIdentity
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_NRCellIdentity;

// NR-CGI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_NR_CGI
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_NRCellIdentity * nRCellIdentity;

} SI_AMF_DT_NR_CGI;


// EUTRACellIdentity
// BITSTRING,BIT STRING(SIZE(28))
// ADT=0  DT=2
typedef struct __si_amf_dt_EUTRACellIdentity
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_EUTRACellIdentity;

// EUTRA-CGI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EUTRA_CGI
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_EUTRACellIdentity * eUTRACellIdentity;

} SI_AMF_DT_EUTRA_CGI;


// NGRAN-CGI
// ADT=0  DT=1
typedef struct __si_amf_dt_NGRAN_CGI
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_NR_CGI * nR_CGI;

		// ParserName = SEQUENCE;
		SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_NGRAN_CGI;


// AreaOfInterestCellItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AreaOfInterestCellItem
{
	SI_AMF_DT_NGRAN_CGI * nGRAN_CGI;

} SI_AMF_DT_AreaOfInterestCellItem;


// AreaOfInterestCellItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AreaOfInterestCellItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AreaOfInterestCellItem_ExtIEs;


// AreaOfInterestList
//SEQUENCE OF AreaOfInterestItem, MIN=1, MAX=maxnoofAoI  ADT=0  DT=2
typedef struct __si_amf_dt_AreaOfInterestList
{
	SI_LinkedList * AreaOfInterestItem;
} SI_AMF_DT_AreaOfInterestList;


// LocationReportingReferenceID
// INTEGER,INTEGER(1..64,...),MIN=1,MAX=64
// ADT=0  DT=2
typedef struct __si_amf_dt_LocationReportingReferenceID
{
	unsigned long long int data;
} SI_AMF_DT_LocationReportingReferenceID;

// AreaOfInterestItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AreaOfInterestItem
{
	SI_AMF_DT_AreaOfInterest * areaOfInterest;

	unsigned long long int locationReportingReferenceID;

} SI_AMF_DT_AreaOfInterestItem;


// AreaOfInterestItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AreaOfInterestItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AreaOfInterestItem_ExtIEs;


// AreaOfInterestRANNodeItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AreaOfInterestRANNodeItem
{
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;

} SI_AMF_DT_AreaOfInterestRANNodeItem;


// AreaOfInterestRANNodeItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AreaOfInterestRANNodeItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs;


// AreaOfInterestTAIItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AreaOfInterestTAIItem
{
	SI_AMF_DT_TAI * tAI;

} SI_AMF_DT_AreaOfInterestTAIItem;


// AreaOfInterestTAIItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AreaOfInterestTAIItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs;


// RecommendedCellList
//SEQUENCE OF RecommendedCellItem, MIN=1, MAX=maxnoofRecommendedCells  ADT=0  DT=2
typedef struct __si_amf_dt_RecommendedCellList
{
	SI_LinkedList * RecommendedCellItem;
} SI_AMF_DT_RecommendedCellList;


// RecommendedCellsForPaging
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_RecommendedCellsForPaging
{
	SI_AMF_DT_RecommendedCellList * recommendedCellList;

} SI_AMF_DT_RecommendedCellsForPaging;


// AssistanceDataForRecommendedCells
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AssistanceDataForRecommendedCells
{
	SI_AMF_DT_RecommendedCellsForPaging * recommendedCellsForPaging;

} SI_AMF_DT_AssistanceDataForRecommendedCells;


// PagingAttemptCount
// INTEGER,INTEGER(1..16,...),MIN=1,MAX=16
// ADT=0  DT=2
typedef struct __si_amf_dt_PagingAttemptCount
{
	unsigned long long int data;
} SI_AMF_DT_PagingAttemptCount;

// IntendedNumberOfPagingAttempts
// INTEGER,INTEGER(1..16,...),MIN=1,MAX=16
// ADT=0  DT=2
typedef struct __si_amf_dt_IntendedNumberOfPagingAttempts
{
	unsigned long long int data;
} SI_AMF_DT_IntendedNumberOfPagingAttempts;

// NextPagingAreaScope
// ADT=0  DT=1
typedef enum __si_amf_dt_NextPagingAreaScope
{
	NextPagingAreaScope_same_val,
	NextPagingAreaScope_changed_val
} SI_AMF_DT_NextPagingAreaScope;


// PagingAttemptInformation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PagingAttemptInformation
{
	unsigned long long int pagingAttemptCount;

	unsigned long long int intendedNumberOfPagingAttempts;

	uint8_t selected_enextPagingAreaScope;
	int extSelected_enextPagingAreaScope;
	int isPresent_nextPagingAreaScope;

} SI_AMF_DT_PagingAttemptInformation;


// AssistanceDataForPaging
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AssistanceDataForPaging
{
	SI_AMF_DT_AssistanceDataForRecommendedCells * assistanceDataForRecommendedCells;
	int isPresent_assistanceDataForRecommendedCells;

	SI_AMF_DT_PagingAttemptInformation * pagingAttemptInformation;
	int isPresent_pagingAttemptInformation;

} SI_AMF_DT_AssistanceDataForPaging;


// AssistanceDataForPaging-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AssistanceDataForPaging_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AssistanceDataForPaging_ExtIEs;


// AssistanceDataForRecommendedCells-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AssistanceDataForRecommendedCells_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs;


// AssociatedQosFlowList
//SEQUENCE OF AssociatedQosFlowItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_AssociatedQosFlowList
{
	SI_LinkedList * AssociatedQosFlowItem;
} SI_AMF_DT_AssociatedQosFlowList;


// AssociatedQosFlowItemQosFlowMappingIndication
// ADT=0  DT=1
typedef enum __si_amf_dt_AssociatedQosFlowItemQosFlowMappingIndication
{
	AssociatedQosFlowItemQosFlowMappingIndication_ul_val,
	AssociatedQosFlowItemQosFlowMappingIndication_dl_val
} SI_AMF_DT_AssociatedQosFlowItemQosFlowMappingIndication;


// QosFlowIdentifier
// INTEGER,INTEGER(0..63,...),MIN=0,MAX=63
// ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowIdentifier
{
	unsigned long long int data;
} SI_AMF_DT_QosFlowIdentifier;

// AssociatedQosFlowItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_AssociatedQosFlowItem
{
	unsigned long long int qosFlowIdentifier;

	uint8_t selected_eqosFlowMappingIndication;
	int extSelected_eqosFlowMappingIndication;
	int isPresent_qosFlowMappingIndication;

} SI_AMF_DT_AssociatedQosFlowItem;


// AssociatedQosFlowItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_AssociatedQosFlowItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_AssociatedQosFlowItem_ExtIEs;


// AveragingWindow
// INTEGER,INTEGER(0..4095,...),MIN=0,MAX=4095
// ADT=0  DT=2
typedef struct __si_amf_dt_AveragingWindow
{
	unsigned long long int data;
} SI_AMF_DT_AveragingWindow;

// BitRate
// INTEGER,INTEGER(0..4000000000000,...),MIN=0,MAX=4000000000000
// ADT=0  DT=2
typedef struct __si_amf_dt_BitRate
{
	unsigned long long int data;
} SI_AMF_DT_BitRate;

// CellIDCancelledEUTRA
//SEQUENCE OF CellIDCancelledEUTRA-Item, MIN=1, MAX=maxnoofCellIDforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_CellIDCancelledEUTRA
{
	SI_LinkedList * CellIDCancelledEUTRA_Item;
} SI_AMF_DT_CellIDCancelledEUTRA;


// TAICancelledEUTRA
//SEQUENCE OF TAICancelledEUTRA-Item, MIN=1, MAX=maxnoofTAIforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_TAICancelledEUTRA
{
	SI_LinkedList * TAICancelledEUTRA_Item;
} SI_AMF_DT_TAICancelledEUTRA;


// EmergencyAreaIDCancelledEUTRA
//SEQUENCE OF EmergencyAreaIDCancelledEUTRA-Item, MIN=1, MAX=maxnoofEmergencyAreaID  ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaIDCancelledEUTRA
{
	SI_LinkedList * EmergencyAreaIDCancelledEUTRA_Item;
} SI_AMF_DT_EmergencyAreaIDCancelledEUTRA;


// CellIDCancelledNR
//SEQUENCE OF CellIDCancelledNR-Item, MIN=1, MAX=maxnoofCellIDforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_CellIDCancelledNR
{
	SI_LinkedList * CellIDCancelledNR_Item;
} SI_AMF_DT_CellIDCancelledNR;


// TAICancelledNR
//SEQUENCE OF TAICancelledNR-Item, MIN=1, MAX=maxnoofTAIforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_TAICancelledNR
{
	SI_LinkedList * TAICancelledNR_Item;
} SI_AMF_DT_TAICancelledNR;


// EmergencyAreaIDCancelledNR
//SEQUENCE OF EmergencyAreaIDCancelledNR-Item, MIN=1, MAX=maxnoofEmergencyAreaID  ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaIDCancelledNR
{
	SI_LinkedList * EmergencyAreaIDCancelledNR_Item;
} SI_AMF_DT_EmergencyAreaIDCancelledNR;


// BroadcastCancelledAreaList
// ADT=0  DT=1
typedef struct __si_amf_dt_BroadcastCancelledAreaList
{
	union 
	{
		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_CellIDCancelledEUTRA * cellIDCancelledEUTRA;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_TAICancelledEUTRA * tAICancelledEUTRA;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EmergencyAreaIDCancelledEUTRA * emergencyAreaIDCancelledEUTRA;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_CellIDCancelledNR * cellIDCancelledNR;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_TAICancelledNR * tAICancelledNR;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EmergencyAreaIDCancelledNR * emergencyAreaIDCancelledNR;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_BroadcastCancelledAreaList;


// BroadcastCancelledAreaList-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_BroadcastCancelledAreaList_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs;


// CellIDBroadcastEUTRA
//SEQUENCE OF CellIDBroadcastEUTRA-Item, MIN=1, MAX=maxnoofCellIDforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_CellIDBroadcastEUTRA
{
	SI_LinkedList * CellIDBroadcastEUTRA_Item;
} SI_AMF_DT_CellIDBroadcastEUTRA;


// TAIBroadcastEUTRA
//SEQUENCE OF TAIBroadcastEUTRA-Item, MIN=1, MAX=maxnoofTAIforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_TAIBroadcastEUTRA
{
	SI_LinkedList * TAIBroadcastEUTRA_Item;
} SI_AMF_DT_TAIBroadcastEUTRA;


// EmergencyAreaIDBroadcastEUTRA
//SEQUENCE OF EmergencyAreaIDBroadcastEUTRA-Item, MIN=1, MAX=maxnoofEmergencyAreaID  ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaIDBroadcastEUTRA
{
	SI_LinkedList * EmergencyAreaIDBroadcastEUTRA_Item;
} SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA;


// CellIDBroadcastNR
//SEQUENCE OF CellIDBroadcastNR-Item, MIN=1, MAX=maxnoofCellIDforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_CellIDBroadcastNR
{
	SI_LinkedList * CellIDBroadcastNR_Item;
} SI_AMF_DT_CellIDBroadcastNR;


// TAIBroadcastNR
//SEQUENCE OF TAIBroadcastNR-Item, MIN=1, MAX=maxnoofTAIforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_TAIBroadcastNR
{
	SI_LinkedList * TAIBroadcastNR_Item;
} SI_AMF_DT_TAIBroadcastNR;


// EmergencyAreaIDBroadcastNR
//SEQUENCE OF EmergencyAreaIDBroadcastNR-Item, MIN=1, MAX=maxnoofEmergencyAreaID  ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaIDBroadcastNR
{
	SI_LinkedList * EmergencyAreaIDBroadcastNR_Item;
} SI_AMF_DT_EmergencyAreaIDBroadcastNR;


// BroadcastCompletedAreaList
// ADT=0  DT=1
typedef struct __si_amf_dt_BroadcastCompletedAreaList
{
	union 
	{
		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_CellIDBroadcastEUTRA * cellIDBroadcastEUTRA;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_TAIBroadcastEUTRA * tAIBroadcastEUTRA;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA * emergencyAreaIDBroadcastEUTRA;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_CellIDBroadcastNR * cellIDBroadcastNR;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_TAIBroadcastNR * tAIBroadcastNR;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EmergencyAreaIDBroadcastNR * emergencyAreaIDBroadcastNR;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_BroadcastCompletedAreaList;


// BroadcastCompletedAreaList-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_BroadcastCompletedAreaList_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs;


// BroadcastPLMNList
//SEQUENCE OF BroadcastPLMNItem, MIN=1, MAX=maxnoofBPLMNs  ADT=0  DT=2
typedef struct __si_amf_dt_BroadcastPLMNList
{
	SI_LinkedList * BroadcastPLMNItem;
} SI_AMF_DT_BroadcastPLMNList;


// SliceSupportList
//SEQUENCE OF SliceSupportItem, MIN=1, MAX=maxnoofSliceItems  ADT=0  DT=2
typedef struct __si_amf_dt_SliceSupportList
{
	SI_LinkedList * SliceSupportItem;
} SI_AMF_DT_SliceSupportList;


// BroadcastPLMNItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_BroadcastPLMNItem
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_SliceSupportList * tAISliceSupportList;

} SI_AMF_DT_BroadcastPLMNItem;


// BroadcastPLMNItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_BroadcastPLMNItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_BroadcastPLMNItem_ExtIEs;


// CancelAllWarningMessages
// ADT=0  DT=1
typedef enum __si_amf_dt_CancelAllWarningMessages
{
	CancelAllWarningMessages_true_val
} SI_AMF_DT_CancelAllWarningMessages;


// CancelledCellsInEAI-EUTRA
//SEQUENCE OF CancelledCellsInEAI-EUTRA-Item, MIN=1, MAX=maxnoofCellinEAI  ADT=0  DT=2
typedef struct __si_amf_dt_CancelledCellsInEAI_EUTRA
{
	SI_LinkedList * CancelledCellsInEAI_EUTRA_Item;
} SI_AMF_DT_CancelledCellsInEAI_EUTRA;


// NumberOfBroadcasts
// INTEGER,INTEGER(0..65535),MIN=0,MAX=65535
// ADT=0  DT=2
typedef struct __si_amf_dt_NumberOfBroadcasts
{
	unsigned long long int data;
} SI_AMF_DT_NumberOfBroadcasts;

// CancelledCellsInEAI-EUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CancelledCellsInEAI_EUTRA_Item
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

	unsigned long long int numberOfBroadcasts;

} SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item;


// CancelledCellsInEAI-EUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CancelledCellsInEAI_EUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs;


// CancelledCellsInEAI-NR
//SEQUENCE OF CancelledCellsInEAI-NR-Item, MIN=1, MAX=maxnoofCellinEAI  ADT=0  DT=2
typedef struct __si_amf_dt_CancelledCellsInEAI_NR
{
	SI_LinkedList * CancelledCellsInEAI_NR_Item;
} SI_AMF_DT_CancelledCellsInEAI_NR;


// CancelledCellsInEAI-NR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CancelledCellsInEAI_NR_Item
{
	SI_AMF_DT_NR_CGI * nR_CGI;

	unsigned long long int numberOfBroadcasts;

} SI_AMF_DT_CancelledCellsInEAI_NR_Item;


// CancelledCellsInEAI-NR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CancelledCellsInEAI_NR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs;


// CancelledCellsInTAI-EUTRA
//SEQUENCE OF CancelledCellsInTAI-EUTRA-Item, MIN=1, MAX=maxnoofCellinTAI  ADT=0  DT=2
typedef struct __si_amf_dt_CancelledCellsInTAI_EUTRA
{
	SI_LinkedList * CancelledCellsInTAI_EUTRA_Item;
} SI_AMF_DT_CancelledCellsInTAI_EUTRA;


// CancelledCellsInTAI-EUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CancelledCellsInTAI_EUTRA_Item
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

	unsigned long long int numberOfBroadcasts;

} SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item;


// CancelledCellsInTAI-EUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CancelledCellsInTAI_EUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs;


// CancelledCellsInTAI-NR
//SEQUENCE OF CancelledCellsInTAI-NR-Item, MIN=1, MAX=maxnoofCellinTAI  ADT=0  DT=2
typedef struct __si_amf_dt_CancelledCellsInTAI_NR
{
	SI_LinkedList * CancelledCellsInTAI_NR_Item;
} SI_AMF_DT_CancelledCellsInTAI_NR;


// CancelledCellsInTAI-NR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CancelledCellsInTAI_NR_Item
{
	SI_AMF_DT_NR_CGI * nR_CGI;

	unsigned long long int numberOfBroadcasts;

} SI_AMF_DT_CancelledCellsInTAI_NR_Item;


// CancelledCellsInTAI-NR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CancelledCellsInTAI_NR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs;


// CauseRadioNetwork
// ADT=0  DT=1
typedef enum __si_amf_dt_CauseRadioNetwork
{
	CauseRadioNetwork_unspecified_val,
	CauseRadioNetwork_txnrelocoverall_expiry_val,
	CauseRadioNetwork_successful_handover_val,
	CauseRadioNetwork_release_due_to_ngran_generated_reason_val,
	CauseRadioNetwork_release_due_to_5gc_generated_reason_val,
	CauseRadioNetwork_handover_cancelled_val,
	CauseRadioNetwork_partial_handover_val,
	CauseRadioNetwork_ho_failure_in_target_5GC_ngran_node_or_target_system_val,
	CauseRadioNetwork_ho_target_not_allowed_val,
	CauseRadioNetwork_tngrelocoverall_expiry_val,
	CauseRadioNetwork_tngrelocprep_expiry_val,
	CauseRadioNetwork_cell_not_available_val,
	CauseRadioNetwork_unknown_targetID_val,
	CauseRadioNetwork_no_radio_resources_available_in_target_cell_val,
	CauseRadioNetwork_unknown_local_UE_NGAP_ID_val,
	CauseRadioNetwork_inconsistent_remote_UE_NGAP_ID_val,
	CauseRadioNetwork_handover_desirable_for_radio_reason_val,
	CauseRadioNetwork_time_critical_handover_val,
	CauseRadioNetwork_resource_optimisation_handover_val,
	CauseRadioNetwork_reduce_load_in_serving_cell_val,
	CauseRadioNetwork_user_inactivity_val,
	CauseRadioNetwork_radio_connection_with_ue_lost_val,
	CauseRadioNetwork_radio_resources_not_available_val,
	CauseRadioNetwork_invalid_qos_combination_val,
	CauseRadioNetwork_failure_in_radio_interface_procedure_val,
	CauseRadioNetwork_interaction_with_other_procedure_val,
	CauseRadioNetwork_unknown_PDU_session_ID_val,
	CauseRadioNetwork_unkown_qos_flow_ID_val,
	CauseRadioNetwork_multiple_PDU_session_ID_instances_val,
	CauseRadioNetwork_multiple_qos_flow_ID_instances_val,
	CauseRadioNetwork_encryption_and_or_integrity_protection_algorithms_not_supported_val,
	CauseRadioNetwork_ng_intra_system_handover_triggered_val,
	CauseRadioNetwork_ng_inter_system_handover_triggered_val,
	CauseRadioNetwork_xn_handover_triggered_val,
	CauseRadioNetwork_not_supported_5QI_value_val,
	CauseRadioNetwork_ue_context_transfer_val,
	CauseRadioNetwork_ims_voice_eps_fallback_or_rat_fallback_triggered_val,
	CauseRadioNetwork_up_integrity_protection_not_possible_val,
	CauseRadioNetwork_up_confidentiality_protection_not_possible_val,
	CauseRadioNetwork_slice_not_supported_val,
	CauseRadioNetwork_ue_in_rrc_inactive_state_not_reachable_val,
	CauseRadioNetwork_redirection_val,
	CauseRadioNetwork_resources_not_available_for_the_slice_val,
	CauseRadioNetwork_ue_max_integrity_protected_data_rate_reason_val,
	CauseRadioNetwork_release_due_to_cn_detected_mobility_val,
	CauseRadioNetwork_n26_interface_not_available_val_ext,
	CauseRadioNetwork_release_due_to_pre_emption_val_ext,
	CauseRadioNetwork_multiple_location_reporting_reference_ID_instances_val_ext
} SI_AMF_DT_CauseRadioNetwork;


// CauseTransport
// ADT=0  DT=1
typedef enum __si_amf_dt_CauseTransport
{
	CauseTransport_transport_resource_unavailable_val,
	CauseTransport_unspecified_val
} SI_AMF_DT_CauseTransport;


// CauseNas
// ADT=0  DT=1
typedef enum __si_amf_dt_CauseNas
{
	CauseNas_normal_release_val,
	CauseNas_authentication_failure_val,
	CauseNas_deregister_val,
	CauseNas_unspecified_val
} SI_AMF_DT_CauseNas;


// CauseProtocol
// ADT=0  DT=1
typedef enum __si_amf_dt_CauseProtocol
{
	CauseProtocol_transfer_syntax_error_val,
	CauseProtocol_abstract_syntax_error_reject_val,
	CauseProtocol_abstract_syntax_error_ignore_and_notify_val,
	CauseProtocol_message_not_compatible_with_receiver_state_val,
	CauseProtocol_semantic_error_val,
	CauseProtocol_abstract_syntax_error_falsely_constructed_message_val,
	CauseProtocol_unspecified_val
} SI_AMF_DT_CauseProtocol;


// CauseMisc
// ADT=0  DT=1
typedef enum __si_amf_dt_CauseMisc
{
	CauseMisc_control_processing_overload_val,
	CauseMisc_not_enough_user_plane_processing_resources_val,
	CauseMisc_hardware_failure_val,
	CauseMisc_om_intervention_val,
	CauseMisc_unknown_PLMN_val,
	CauseMisc_unspecified_val
} SI_AMF_DT_CauseMisc;


// Cause
// ADT=0  DT=1
typedef struct __si_amf_dt_Cause
{
	union 
	{
		// ParserName = ENUMERATED;
		uint8_t radioNetwork;

		// ParserName = ENUMERATED;
		uint8_t transport;

		// ParserName = ENUMERATED;
		uint8_t nas;

		// ParserName = ENUMERATED;
		uint8_t protocol;

		// ParserName = ENUMERATED;
		uint8_t misc;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_Cause;


// Cause-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_Cause_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_Cause_ExtIEs;


// CellIDBroadcastEUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CellIDBroadcastEUTRA_Item
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

} SI_AMF_DT_CellIDBroadcastEUTRA_Item;


// CellIDBroadcastEUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CellIDBroadcastEUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs;


// CellIDBroadcastNR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CellIDBroadcastNR_Item
{
	SI_AMF_DT_NR_CGI * nR_CGI;

} SI_AMF_DT_CellIDBroadcastNR_Item;


// CellIDBroadcastNR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CellIDBroadcastNR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs;


// CellIDCancelledEUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CellIDCancelledEUTRA_Item
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

	unsigned long long int numberOfBroadcasts;

} SI_AMF_DT_CellIDCancelledEUTRA_Item;


// CellIDCancelledEUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CellIDCancelledEUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs;


// CellIDCancelledNR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CellIDCancelledNR_Item
{
	SI_AMF_DT_NR_CGI * nR_CGI;

	unsigned long long int numberOfBroadcasts;

} SI_AMF_DT_CellIDCancelledNR_Item;


// CellIDCancelledNR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CellIDCancelledNR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs;


// EUTRA-CGIList
//SEQUENCE OF EUTRA-CGI, MIN=1, MAX=maxnoofCellsinngeNB  ADT=0  DT=2
typedef struct __si_amf_dt_EUTRA_CGIList
{
	SI_LinkedList * EUTRA_CGI;
} SI_AMF_DT_EUTRA_CGIList;


// NR-CGIList
//SEQUENCE OF NR-CGI, MIN=1, MAX=maxnoofCellsingNB  ADT=0  DT=2
typedef struct __si_amf_dt_NR_CGIList
{
	SI_LinkedList * NR_CGI;
} SI_AMF_DT_NR_CGIList;


// CellIDListForRestart
// ADT=0  DT=1
typedef struct __si_amf_dt_CellIDListForRestart
{
	union 
	{
		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EUTRA_CGIList * eUTRA_CGIListforRestart;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_NR_CGIList * nR_CGIListforRestart;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_CellIDListForRestart;


// CellIDListForRestart-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_CellIDListForRestart_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CellIDListForRestart_ExtIEs;


// CellSize
// ADT=0  DT=1
typedef enum __si_amf_dt_CellSize
{
	CellSize_verysmall_val,
	CellSize_small_val,
	CellSize_medium_val,
	CellSize_large_val
} SI_AMF_DT_CellSize;


// CellType
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CellType
{
	uint8_t selected_ecellSize;
	int extSelected_ecellSize;

} SI_AMF_DT_CellType;


// CellType-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CellType_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CellType_ExtIEs;


// ExpectedActivityPeriod
// INTEGER,INTEGER(1..30|40|50|60|80|100|120|150|180|181,...),MIN=1,MAX=30
// ADT=0  DT=2
typedef struct __si_amf_dt_ExpectedActivityPeriod
{
	unsigned long long int data;
} SI_AMF_DT_ExpectedActivityPeriod;

// ExpectedIdlePeriod
// INTEGER,INTEGER(1..30|40|50|60|80|100|120|150|180|181,...),MIN=1,MAX=30
// ADT=0  DT=2
typedef struct __si_amf_dt_ExpectedIdlePeriod
{
	unsigned long long int data;
} SI_AMF_DT_ExpectedIdlePeriod;

// SourceOfUEActivityBehaviourInformation
// ADT=0  DT=1
typedef enum __si_amf_dt_SourceOfUEActivityBehaviourInformation
{
	SourceOfUEActivityBehaviourInformation_subscription_information_val,
	SourceOfUEActivityBehaviourInformation_statistics_val
} SI_AMF_DT_SourceOfUEActivityBehaviourInformation;


// ExpectedUEActivityBehaviour
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_ExpectedUEActivityBehaviour
{
	unsigned long long int expectedActivityPeriod;
	int isPresent_expectedActivityPeriod;

	unsigned long long int expectedIdlePeriod;
	int isPresent_expectedIdlePeriod;

	uint8_t selected_esourceOfUEActivityBehaviourInformation;
	int extSelected_esourceOfUEActivityBehaviourInformation;
	int isPresent_sourceOfUEActivityBehaviourInformation;

} SI_AMF_DT_ExpectedUEActivityBehaviour;


// ExpectedHOInterval
// ADT=0  DT=1
typedef enum __si_amf_dt_ExpectedHOInterval
{
	ExpectedHOInterval_sec15_val,
	ExpectedHOInterval_sec30_val,
	ExpectedHOInterval_sec60_val,
	ExpectedHOInterval_sec90_val,
	ExpectedHOInterval_sec120_val,
	ExpectedHOInterval_sec180_val,
	ExpectedHOInterval_long_time_val
} SI_AMF_DT_ExpectedHOInterval;


// ExpectedUEMobility
// ADT=0  DT=1
typedef enum __si_amf_dt_ExpectedUEMobility
{
	ExpectedUEMobility_stationary_val,
	ExpectedUEMobility_mobile_val
} SI_AMF_DT_ExpectedUEMobility;


// ExpectedUEMovingTrajectory
//SEQUENCE OF ExpectedUEMovingTrajectoryItem, MIN=1, MAX=maxnoofCellsUEMovingTrajectory  ADT=0  DT=2
typedef struct __si_amf_dt_ExpectedUEMovingTrajectory
{
	SI_LinkedList * ExpectedUEMovingTrajectoryItem;
} SI_AMF_DT_ExpectedUEMovingTrajectory;


// ExpectedUEBehaviour
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_ExpectedUEBehaviour
{
	SI_AMF_DT_ExpectedUEActivityBehaviour * expectedUEActivityBehaviour;
	int isPresent_expectedUEActivityBehaviour;

	uint8_t selected_eexpectedHOInterval;
	int extSelected_eexpectedHOInterval;
	int isPresent_expectedHOInterval;

	uint8_t selected_eexpectedUEMobility;
	int extSelected_eexpectedUEMobility;
	int isPresent_expectedUEMobility;

	SI_AMF_DT_ExpectedUEMovingTrajectory * expectedUEMovingTrajectory;
	int isPresent_expectedUEMovingTrajectory;

} SI_AMF_DT_ExpectedUEBehaviour;


// CNAssistedRANTuning
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CNAssistedRANTuning
{
	SI_AMF_DT_ExpectedUEBehaviour * expectedUEBehaviour;
	int isPresent_expectedUEBehaviour;

} SI_AMF_DT_CNAssistedRANTuning;


// CNAssistedRANTuning-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CNAssistedRANTuning_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CNAssistedRANTuning_ExtIEs;


// CNTypeRestrictionsForEquivalent
//SEQUENCE OF CNTypeRestrictionsForEquivalentItem, MIN=1, MAX=maxnoofEPLMNs  ADT=0  DT=2
typedef struct __si_amf_dt_CNTypeRestrictionsForEquivalent
{
	SI_LinkedList * CNTypeRestrictionsForEquivalentItem;
} SI_AMF_DT_CNTypeRestrictionsForEquivalent;


// CNTypeRestrictionsForEquivalentItemCNType
// ADT=0  DT=1
typedef enum __si_amf_dt_CNTypeRestrictionsForEquivalentItemCNType
{
	CNTypeRestrictionsForEquivalentItemCNType_epc_forbidden_val,
	CNTypeRestrictionsForEquivalentItemCNType_fiveGC_forbidden_val
} SI_AMF_DT_CNTypeRestrictionsForEquivalentItemCNType;


// CNTypeRestrictionsForEquivalentItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CNTypeRestrictionsForEquivalentItem
{
	SI_AMF_DT_PLMNIdentity * plmnIdentity;

	uint8_t selected_ecn_Type;
	int extSelected_ecn_Type;

} SI_AMF_DT_CNTypeRestrictionsForEquivalentItem;


// CNTypeRestrictionsForEquivalentItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CNTypeRestrictionsForEquivalentItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs;


// CNTypeRestrictionsForServing
// ADT=0  DT=1
typedef enum __si_amf_dt_CNTypeRestrictionsForServing
{
	CNTypeRestrictionsForServing_epc_forbidden_val
} SI_AMF_DT_CNTypeRestrictionsForServing;


// CommonNetworkInstance
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_CommonNetworkInstance
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_CommonNetworkInstance;

// CompletedCellsInEAI-EUTRA
//SEQUENCE OF CompletedCellsInEAI-EUTRA-Item, MIN=1, MAX=maxnoofCellinEAI  ADT=0  DT=2
typedef struct __si_amf_dt_CompletedCellsInEAI_EUTRA
{
	SI_LinkedList * CompletedCellsInEAI_EUTRA_Item;
} SI_AMF_DT_CompletedCellsInEAI_EUTRA;


// CompletedCellsInEAI-EUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CompletedCellsInEAI_EUTRA_Item
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

} SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item;


// CompletedCellsInEAI-EUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CompletedCellsInEAI_EUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs;


// CompletedCellsInEAI-NR
//SEQUENCE OF CompletedCellsInEAI-NR-Item, MIN=1, MAX=maxnoofCellinEAI  ADT=0  DT=2
typedef struct __si_amf_dt_CompletedCellsInEAI_NR
{
	SI_LinkedList * CompletedCellsInEAI_NR_Item;
} SI_AMF_DT_CompletedCellsInEAI_NR;


// CompletedCellsInEAI-NR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CompletedCellsInEAI_NR_Item
{
	SI_AMF_DT_NR_CGI * nR_CGI;

} SI_AMF_DT_CompletedCellsInEAI_NR_Item;


// CompletedCellsInEAI-NR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CompletedCellsInEAI_NR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs;


// CompletedCellsInTAI-EUTRA
//SEQUENCE OF CompletedCellsInTAI-EUTRA-Item, MIN=1, MAX=maxnoofCellinTAI  ADT=0  DT=2
typedef struct __si_amf_dt_CompletedCellsInTAI_EUTRA
{
	SI_LinkedList * CompletedCellsInTAI_EUTRA_Item;
} SI_AMF_DT_CompletedCellsInTAI_EUTRA;


// CompletedCellsInTAI-EUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CompletedCellsInTAI_EUTRA_Item
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

} SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item;


// CompletedCellsInTAI-EUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CompletedCellsInTAI_EUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs;


// CompletedCellsInTAI-NR
//SEQUENCE OF CompletedCellsInTAI-NR-Item, MIN=1, MAX=maxnoofCellinTAI  ADT=0  DT=2
typedef struct __si_amf_dt_CompletedCellsInTAI_NR
{
	SI_LinkedList * CompletedCellsInTAI_NR_Item;
} SI_AMF_DT_CompletedCellsInTAI_NR;


// CompletedCellsInTAI-NR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CompletedCellsInTAI_NR_Item
{
	SI_AMF_DT_NR_CGI * nR_CGI;

} SI_AMF_DT_CompletedCellsInTAI_NR_Item;


// CompletedCellsInTAI-NR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CompletedCellsInTAI_NR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs;


// ConcurrentWarningMessageInd
// ADT=0  DT=1
typedef enum __si_amf_dt_ConcurrentWarningMessageInd
{
	ConcurrentWarningMessageInd_true_val
} SI_AMF_DT_ConcurrentWarningMessageInd;


// ConfidentialityProtectionIndication
// ADT=0  DT=1
typedef enum __si_amf_dt_ConfidentialityProtectionIndication
{
	ConfidentialityProtectionIndication_required_val,
	ConfidentialityProtectionIndication_preferred_val,
	ConfidentialityProtectionIndication_not_needed_val
} SI_AMF_DT_ConfidentialityProtectionIndication;


// ConfidentialityProtectionResult
// ADT=0  DT=1
typedef enum __si_amf_dt_ConfidentialityProtectionResult
{
	ConfidentialityProtectionResult_performed_val,
	ConfidentialityProtectionResult_not_performed_val
} SI_AMF_DT_ConfidentialityProtectionResult;


// UEIdentityIndexValueIL
// BITSTRING,BIT STRING(SIZE(10))
// ADT=0  DT=2
typedef struct __si_amf_dt_UEIdentityIndexValueIL
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_UEIdentityIndexValueIL;

// UEIdentityIndexValue
// ADT=0  DT=1
typedef struct __si_amf_dt_UEIdentityIndexValue
{
	union 
	{
		// ParserName = BITSTRING;
		SI_AMF_DT_UEIdentityIndexValueIL * indexLength10;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_UEIdentityIndexValue;


// PagingDRX
// ADT=0  DT=1
typedef enum __si_amf_dt_PagingDRX
{
	PagingDRX_v32_val,
	PagingDRX_v64_val,
	PagingDRX_v128_val,
	PagingDRX_v256_val
} SI_AMF_DT_PagingDRX;


// PeriodicRegistrationUpdateTimer
// BITSTRING,BIT STRING(SIZE(8))
// ADT=0  DT=2
typedef struct __si_amf_dt_PeriodicRegistrationUpdateTimer
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_PeriodicRegistrationUpdateTimer;

// MICOModeIndication
// ADT=0  DT=1
typedef enum __si_amf_dt_MICOModeIndication
{
	MICOModeIndication_true_val
} SI_AMF_DT_MICOModeIndication;


// TAIListForInactive
//SEQUENCE OF TAIListForInactiveItem, MIN=1, MAX=maxnoofTAIforInactive  ADT=0  DT=2
typedef struct __si_amf_dt_TAIListForInactive
{
	SI_LinkedList * TAIListForInactiveItem;
} SI_AMF_DT_TAIListForInactive;


// CoreNetworkAssistanceInformationForInactive
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CoreNetworkAssistanceInformationForInactive
{
	SI_AMF_DT_UEIdentityIndexValue * uEIdentityIndexValue;

	uint8_t selected_euESpecificDRX;
	int extSelected_euESpecificDRX;
	int isPresent_uESpecificDRX;

	SI_AMF_DT_PeriodicRegistrationUpdateTimer * periodicRegistrationUpdateTimer;

	uint8_t selected_emICOModeIndication;
	int extSelected_emICOModeIndication;
	int isPresent_mICOModeIndication;

	SI_AMF_DT_TAIListForInactive * tAIListForInactive;

	SI_AMF_DT_ExpectedUEBehaviour * expectedUEBehaviour;
	int isPresent_expectedUEBehaviour;

} SI_AMF_DT_CoreNetworkAssistanceInformationForInactive;


// CoreNetworkAssistanceInformationForInactive-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CoreNetworkAssistanceInformationForInactive_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs;


// COUNTValueForPDCP-SN12INT
// INTEGER,INTEGER(0..4095),MIN=0,MAX=4095
// ADT=0  DT=2
typedef struct __si_amf_dt_COUNTValueForPDCP_SN12INT
{
	unsigned long long int data;
} SI_AMF_DT_COUNTValueForPDCP_SN12INT;

// COUNTValueForPDCP-SN12INT2
// INTEGER,INTEGER(0..1048575),MIN=0,MAX=1048575
// ADT=0  DT=2
typedef struct __si_amf_dt_COUNTValueForPDCP_SN12INT2
{
	unsigned long long int data;
} SI_AMF_DT_COUNTValueForPDCP_SN12INT2;

// COUNTValueForPDCP-SN12
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_COUNTValueForPDCP_SN12
{
	unsigned long long int pDCP_SN12;

	unsigned long long int hFN_PDCP_SN12;

} SI_AMF_DT_COUNTValueForPDCP_SN12;


// COUNTValueForPDCP-SN12-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_COUNTValueForPDCP_SN12_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs;


// COUNTValueForPDCP-SN18INT
// INTEGER,INTEGER(0..262143),MIN=0,MAX=262143
// ADT=0  DT=2
typedef struct __si_amf_dt_COUNTValueForPDCP_SN18INT
{
	unsigned long long int data;
} SI_AMF_DT_COUNTValueForPDCP_SN18INT;

// COUNTValueForPDCP-SN18INT2
// INTEGER,INTEGER(0..16383),MIN=0,MAX=16383
// ADT=0  DT=2
typedef struct __si_amf_dt_COUNTValueForPDCP_SN18INT2
{
	unsigned long long int data;
} SI_AMF_DT_COUNTValueForPDCP_SN18INT2;

// COUNTValueForPDCP-SN18
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_COUNTValueForPDCP_SN18
{
	unsigned long long int pDCP_SN18;

	unsigned long long int hFN_PDCP_SN18;

} SI_AMF_DT_COUNTValueForPDCP_SN18;


// COUNTValueForPDCP-SN18-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_COUNTValueForPDCP_SN18_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs;


// PortNumber
// OCTETSTRING,OCTET STRING(SIZE(2))
// ADT=0  DT=2
typedef struct __si_amf_dt_PortNumber
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PortNumber;

// EndpointIPAddressAndPort
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EndpointIPAddressAndPort
{
	SI_AMF_DT_TransportLayerAddress * endpointIPAddress;

	SI_AMF_DT_PortNumber * portNumber;

} SI_AMF_DT_EndpointIPAddressAndPort;


// CPTransportLayerInformation-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_CPTransportLayerInformation_ExtIEs
{
	// Got Success L:2926
	//EndpointIPAddressAndPort,  mandatory
	SI_AMF_DT_EndpointIPAddressAndPort * endpointIPAddressAndPort;
	int isPresent_endpointIPAddressAndPort;

} SI_AMF_DT_CPTransportLayerInformation_ExtIEs;


// CriticalityDiagnosticsCriticality
// INTEGER,INTEGER(0..1048575),MIN=0,MAX=1048575
// ADT=0  DT=2
typedef struct __si_amf_dt_CriticalityDiagnosticsCriticality
{
	unsigned long long int data;
} SI_AMF_DT_CriticalityDiagnosticsCriticality;

// CriticalityDiagnosticsProcedureCode
// INTEGER,INTEGER(0..1048575),MIN=0,MAX=1048575
// ADT=0  DT=2
typedef struct __si_amf_dt_CriticalityDiagnosticsProcedureCode
{
	unsigned long long int data;
} SI_AMF_DT_CriticalityDiagnosticsProcedureCode;

// CriticalityDiagnosticsTriggeringMessage
// INTEGER,INTEGER(0..1048575),MIN=0,MAX=1048575
// ADT=0  DT=2
typedef struct __si_amf_dt_CriticalityDiagnosticsTriggeringMessage
{
	unsigned long long int data;
} SI_AMF_DT_CriticalityDiagnosticsTriggeringMessage;

// CriticalityDiagnostics-IE-List
//SEQUENCE OF CriticalityDiagnostics-IE-Item, MIN=1, MAX=maxnoofErrors  ADT=0  DT=2
typedef struct __si_amf_dt_CriticalityDiagnostics_IE_List
{
	SI_LinkedList * CriticalityDiagnostics_IE_Item;
} SI_AMF_DT_CriticalityDiagnostics_IE_List;


// CriticalityDiagnostics
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CriticalityDiagnostics
{
	unsigned long long int procedureCode;
	int isPresent_procedureCode;

	unsigned long long int triggeringMessage;
	int isPresent_triggeringMessage;

	unsigned long long int procedureCriticality;
	int isPresent_procedureCriticality;

	SI_AMF_DT_CriticalityDiagnostics_IE_List * iEsCriticalityDiagnostics;
	int isPresent_iEsCriticalityDiagnostics;

} SI_AMF_DT_CriticalityDiagnostics;


// CriticalityDiagnostics-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CriticalityDiagnostics_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CriticalityDiagnostics_ExtIEs;


// CriticalityDiagnostics-IE-Item-ProtocolIE-ID
// INTEGER,INTEGER(0..1048575),MIN=0,MAX=1048575
// ADT=0  DT=2
typedef struct __si_amf_dt_CriticalityDiagnostics_IE_Item_ProtocolIE_ID
{
	unsigned long long int data;
} SI_AMF_DT_CriticalityDiagnostics_IE_Item_ProtocolIE_ID;

// CriticalityDiagnostics-IE-Item-Criticality
// INTEGER,INTEGER(0..1048575),MIN=0,MAX=1048575
// ADT=0  DT=2
typedef struct __si_amf_dt_CriticalityDiagnostics_IE_Item_Criticality
{
	unsigned long long int data;
} SI_AMF_DT_CriticalityDiagnostics_IE_Item_Criticality;

// TypeOfError
// ADT=0  DT=1
typedef enum __si_amf_dt_TypeOfError
{
	TypeOfError_not_understood_val,
	TypeOfError_missing_val
} SI_AMF_DT_TypeOfError;


// CriticalityDiagnostics-IE-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_CriticalityDiagnostics_IE_Item
{
	unsigned long long int iECriticality;

	unsigned long long int iE_ID;

	uint8_t selected_etypeOfError;
	int extSelected_etypeOfError;

} SI_AMF_DT_CriticalityDiagnostics_IE_Item;


// CriticalityDiagnostics-IE-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_CriticalityDiagnostics_IE_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs;


// DataCodingScheme
// BITSTRING,BIT STRING(SIZE(8))
// ADT=0  DT=2
typedef struct __si_amf_dt_DataCodingScheme
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_DataCodingScheme;

// DataForwardingAccepted
// ADT=0  DT=1
typedef enum __si_amf_dt_DataForwardingAccepted
{
	DataForwardingAccepted_data_forwarding_accepted_val
} SI_AMF_DT_DataForwardingAccepted;


// DataForwardingNotPossible
// ADT=0  DT=1
typedef enum __si_amf_dt_DataForwardingNotPossible
{
	DataForwardingNotPossible_data_forwarding_not_possible_val
} SI_AMF_DT_DataForwardingNotPossible;


// DataForwardingResponseDRBList
//SEQUENCE OF DataForwardingResponseDRBItem, MIN=1, MAX=maxnoofDRBs  ADT=0  DT=2
typedef struct __si_amf_dt_DataForwardingResponseDRBList
{
	SI_LinkedList * DataForwardingResponseDRBItem;
} SI_AMF_DT_DataForwardingResponseDRBList;


// DRB-ID
// INTEGER,INTEGER(1..32,...),MIN=1,MAX=32
// ADT=0  DT=2
typedef struct __si_amf_dt_DRB_ID
{
	unsigned long long int data;
} SI_AMF_DT_DRB_ID;

// DataForwardingResponseDRBItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DataForwardingResponseDRBItem
{
	unsigned long long int dRB_ID;

	SI_AMF_DT_UPTransportLayerInformation * dLForwardingUP_TNLInformation;
	int isPresent_dLForwardingUP_TNLInformation;

	SI_AMF_DT_UPTransportLayerInformation * uLForwardingUP_TNLInformation;
	int isPresent_uLForwardingUP_TNLInformation;

} SI_AMF_DT_DataForwardingResponseDRBItem;


// DataForwardingResponseDRBItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DataForwardingResponseDRBItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs;


// DelayCritical
// ADT=0  DT=1
typedef enum __si_amf_dt_DelayCritical
{
	DelayCritical_delay_critical_val,
	DelayCritical_non_delay_critical_val
} SI_AMF_DT_DelayCritical;


// DLForwarding
// ADT=0  DT=1
typedef enum __si_amf_dt_DLForwarding
{
	DLForwarding_dl_forwarding_proposed_val
} SI_AMF_DT_DLForwarding;


// DL-NGU-TNLInformationReused
// ADT=0  DT=1
typedef enum __si_amf_dt_DL_NGU_TNLInformationReused
{
	DL_NGU_TNLInformationReused_true_val
} SI_AMF_DT_DL_NGU_TNLInformationReused;


// DirectForwardingPathAvailability
// ADT=0  DT=1
typedef enum __si_amf_dt_DirectForwardingPathAvailability
{
	DirectForwardingPathAvailability_direct_path_available_val
} SI_AMF_DT_DirectForwardingPathAvailability;


// DRBsSubjectToStatusTransferList
//SEQUENCE OF DRBsSubjectToStatusTransferItem, MIN=1, MAX=maxnoofDRBs  ADT=0  DT=2
typedef struct __si_amf_dt_DRBsSubjectToStatusTransferList
{
	SI_LinkedList * DRBsSubjectToStatusTransferItem;
} SI_AMF_DT_DRBsSubjectToStatusTransferList;


// DRBStatusUL12ReceiveStatusOfUL-PDCP-SDUs
// BITSTRING,BIT STRING(SIZE(1..2048))
// ADT=0  DT=2
typedef struct __si_amf_dt_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs;

// DRBStatusUL12
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DRBStatusUL12
{
	SI_AMF_DT_COUNTValueForPDCP_SN12 * uL_COUNTValue;

	SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs * receiveStatusOfUL_PDCP_SDUs;
	int isPresent_receiveStatusOfUL_PDCP_SDUs;

} SI_AMF_DT_DRBStatusUL12;


// DRBStatusUL18ReceiveStatusOfUL-PDCP-SDUs
// BITSTRING,BIT STRING(SIZE(1..131072))
// ADT=0  DT=2
typedef struct __si_amf_dt_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs;

// DRBStatusUL18
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DRBStatusUL18
{
	SI_AMF_DT_COUNTValueForPDCP_SN18 * uL_COUNTValue;

	SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs * receiveStatusOfUL_PDCP_SDUs;
	int isPresent_receiveStatusOfUL_PDCP_SDUs;

} SI_AMF_DT_DRBStatusUL18;


// DRBStatusUL
// ADT=0  DT=1
typedef struct __si_amf_dt_DRBStatusUL
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_DRBStatusUL12 * dRBStatusUL12;

		// ParserName = SEQUENCE;
		SI_AMF_DT_DRBStatusUL18 * dRBStatusUL18;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_DRBStatusUL;


// DRBStatusDL12
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DRBStatusDL12
{
	SI_AMF_DT_COUNTValueForPDCP_SN12 * dL_COUNTValue;

} SI_AMF_DT_DRBStatusDL12;


// DRBStatusDL18
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DRBStatusDL18
{
	SI_AMF_DT_COUNTValueForPDCP_SN18 * dL_COUNTValue;

} SI_AMF_DT_DRBStatusDL18;


// DRBStatusDL
// ADT=0  DT=1
typedef struct __si_amf_dt_DRBStatusDL
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_DRBStatusDL12 * dRBStatusDL12;

		// ParserName = SEQUENCE;
		SI_AMF_DT_DRBStatusDL18 * dRBStatusDL18;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_DRBStatusDL;


// DRBsSubjectToStatusTransferItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DRBsSubjectToStatusTransferItem
{
	unsigned long long int dRB_ID;

	SI_AMF_DT_DRBStatusUL * dRBStatusUL;

	SI_AMF_DT_DRBStatusDL * dRBStatusDL;

} SI_AMF_DT_DRBsSubjectToStatusTransferItem;


// DRBsSubjectToStatusTransferItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DRBsSubjectToStatusTransferItem_ExtIEs
{
	// Got Success L:2926
	//AssociatedQosFlowList,  optional
	SI_AMF_DT_AssociatedQosFlowList * oldAssociatedQosFlowListULendmarkerexpected;
	int isPresent_oldAssociatedQosFlowListULendmarkerexpected;

} SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs;


// DRBStatusDL-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_DRBStatusDL_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBStatusDL_ExtIEs;


// DRBStatusDL12-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DRBStatusDL12_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBStatusDL12_ExtIEs;


// DRBStatusDL18-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DRBStatusDL18_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBStatusDL18_ExtIEs;


// DRBStatusUL-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_DRBStatusUL_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBStatusUL_ExtIEs;


// DRBStatusUL12-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DRBStatusUL12_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBStatusUL12_ExtIEs;


// DRBStatusUL18-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DRBStatusUL18_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBStatusUL18_ExtIEs;


// DRBsToQosFlowsMappingList
//SEQUENCE OF DRBsToQosFlowsMappingItem, MIN=1, MAX=maxnoofDRBs  ADT=0  DT=2
typedef struct __si_amf_dt_DRBsToQosFlowsMappingList
{
	SI_LinkedList * DRBsToQosFlowsMappingItem;
} SI_AMF_DT_DRBsToQosFlowsMappingList;


// DRBsToQosFlowsMappingItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_DRBsToQosFlowsMappingItem
{
	unsigned long long int dRB_ID;

	SI_AMF_DT_AssociatedQosFlowList * associatedQosFlowList;

} SI_AMF_DT_DRBsToQosFlowsMappingItem;


// DRBsToQosFlowsMappingItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_DRBsToQosFlowsMappingItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs;


// PriorityLevelQos
// INTEGER,INTEGER(1..127,...),MIN=1,MAX=127
// ADT=0  DT=2
typedef struct __si_amf_dt_PriorityLevelQos
{
	unsigned long long int data;
} SI_AMF_DT_PriorityLevelQos;

// PacketDelayBudget
// INTEGER,INTEGER(0..1023,...),MIN=0,MAX=1023
// ADT=0  DT=2
typedef struct __si_amf_dt_PacketDelayBudget
{
	unsigned long long int data;
} SI_AMF_DT_PacketDelayBudget;

// PacketErrorRateInt
// INTEGER,INTEGER(0..9,...),MIN=0,MAX=9
// ADT=0  DT=2
typedef struct __si_amf_dt_PacketErrorRateInt
{
	unsigned long long int data;
} SI_AMF_DT_PacketErrorRateInt;

// PacketErrorRate
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PacketErrorRate
{
	unsigned long long int pERScalar;

	unsigned long long int pERExponent;

} SI_AMF_DT_PacketErrorRate;


// FiveQI
// INTEGER,INTEGER(0..255,...),MIN=0,MAX=255
// ADT=0  DT=2
typedef struct __si_amf_dt_FiveQI
{
	unsigned long long int data;
} SI_AMF_DT_FiveQI;

// MaximumDataBurstVolume
// INTEGER,INTEGER(0..4095,...),MIN=0,MAX=4095
// ADT=0  DT=2
typedef struct __si_amf_dt_MaximumDataBurstVolume
{
	unsigned long long int data;
} SI_AMF_DT_MaximumDataBurstVolume;

// Dynamic5QIDescriptor
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_Dynamic5QIDescriptor
{
	unsigned long long int priorityLevelQos;

	unsigned long long int packetDelayBudget;

	SI_AMF_DT_PacketErrorRate * packetErrorRate;

	unsigned long long int fiveQI;
	int isPresent_fiveQI;

	uint8_t selected_edelayCritical;
	int extSelected_edelayCritical;
	int isPresent_delayCritical;

	unsigned long long int averagingWindow;
	int isPresent_averagingWindow;

	unsigned long long int maximumDataBurstVolume;
	int isPresent_maximumDataBurstVolume;

} SI_AMF_DT_Dynamic5QIDescriptor;


// Dynamic5QIDescriptor-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_Dynamic5QIDescriptor_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs;


// EmergencyAreaID
// OCTETSTRING,OCTET STRING(SIZE(3))
// ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaID
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_EmergencyAreaID;

// EmergencyAreaIDBroadcastEUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EmergencyAreaIDBroadcastEUTRA_Item
{
	SI_AMF_DT_EmergencyAreaID * emergencyAreaID;

	SI_AMF_DT_CompletedCellsInEAI_EUTRA * completedCellsInEAI_EUTRA;

} SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item;


// EmergencyAreaIDBroadcastEUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs;


// EmergencyAreaIDBroadcastNR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EmergencyAreaIDBroadcastNR_Item
{
	SI_AMF_DT_EmergencyAreaID * emergencyAreaID;

	SI_AMF_DT_CompletedCellsInEAI_NR * completedCellsInEAI_NR;

} SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item;


// EmergencyAreaIDBroadcastNR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EmergencyAreaIDBroadcastNR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs;


// EmergencyAreaIDCancelledEUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EmergencyAreaIDCancelledEUTRA_Item
{
	SI_AMF_DT_EmergencyAreaID * emergencyAreaID;

	SI_AMF_DT_CancelledCellsInEAI_EUTRA * cancelledCellsInEAI_EUTRA;

} SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item;


// EmergencyAreaIDCancelledEUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs;


// EmergencyAreaIDCancelledNR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EmergencyAreaIDCancelledNR_Item
{
	SI_AMF_DT_EmergencyAreaID * emergencyAreaID;

	SI_AMF_DT_CancelledCellsInEAI_NR * cancelledCellsInEAI_NR;

} SI_AMF_DT_EmergencyAreaIDCancelledNR_Item;


// EmergencyAreaIDCancelledNR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EmergencyAreaIDCancelledNR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs;


// EmergencyAreaIDList
//SEQUENCE OF EmergencyAreaID, MIN=1, MAX=maxnoofEmergencyAreaID  ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaIDList
{
	SI_LinkedList * EmergencyAreaID;
} SI_AMF_DT_EmergencyAreaIDList;


// EmergencyAreaIDListForRestart
//SEQUENCE OF EmergencyAreaID, MIN=1, MAX=maxnoofEAIforRestart  ADT=0  DT=2
typedef struct __si_amf_dt_EmergencyAreaIDListForRestart
{
	SI_LinkedList * EmergencyAreaID;
} SI_AMF_DT_EmergencyAreaIDListForRestart;


// EmergencyFallbackRequestIndicator
// ADT=0  DT=1
typedef enum __si_amf_dt_EmergencyFallbackRequestIndicator
{
	EmergencyFallbackRequestIndicator_emergency_fallback_requested_val
} SI_AMF_DT_EmergencyFallbackRequestIndicator;


// EmergencyServiceTargetCN
// ADT=0  DT=1
typedef enum __si_amf_dt_EmergencyServiceTargetCN
{
	EmergencyServiceTargetCN_fiveGC_val,
	EmergencyServiceTargetCN_epc_val
} SI_AMF_DT_EmergencyServiceTargetCN;


// EmergencyFallbackIndicator
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EmergencyFallbackIndicator
{
	uint8_t selected_eemergencyFallbackRequestIndicator;
	int extSelected_eemergencyFallbackRequestIndicator;

	uint8_t selected_eemergencyServiceTargetCN;
	int extSelected_eemergencyServiceTargetCN;
	int isPresent_emergencyServiceTargetCN;

} SI_AMF_DT_EmergencyFallbackIndicator;


// EmergencyFallbackIndicator-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EmergencyFallbackIndicator_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs;


// EN-DCSONConfigurationTransfer
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_EN_DCSONConfigurationTransfer
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_EN_DCSONConfigurationTransfer;

// EndpointIPAddressAndPort-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EndpointIPAddressAndPort_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs;


// EquivalentPLMNs
//SEQUENCE OF PLMNIdentity, MIN=1, MAX=maxnoofEPLMNs  ADT=0  DT=2
typedef struct __si_amf_dt_EquivalentPLMNs
{
	SI_LinkedList * PLMNIdentity;
} SI_AMF_DT_EquivalentPLMNs;


// EPS-TAC
// OCTETSTRING,OCTET STRING(SIZE(2))
// ADT=0  DT=2
typedef struct __si_amf_dt_EPS_TAC
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_EPS_TAC;

// EPS-TAI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_EPS_TAI
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_EPS_TAC * ePS_TAC;

} SI_AMF_DT_EPS_TAI;


// EPS-TAI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EPS_TAI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EPS_TAI_ExtIEs;


// E-RAB-ID
// INTEGER,INTEGER(0..15,...),MIN=0,MAX=15
// ADT=0  DT=2
typedef struct __si_amf_dt_E_RAB_ID
{
	unsigned long long int data;
} SI_AMF_DT_E_RAB_ID;

// E-RABInformationList
//SEQUENCE OF E-RABInformationItem, MIN=1, MAX=maxnoofE-RABs  ADT=0  DT=2
typedef struct __si_amf_dt_E_RABInformationList
{
	SI_LinkedList * E_RABInformationItem;
} SI_AMF_DT_E_RABInformationList;


// E-RABInformationItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_E_RABInformationItem
{
	unsigned long long int e_RAB_ID;

	uint8_t selected_edLForwarding;
	int extSelected_edLForwarding;
	int isPresent_dLForwarding;

} SI_AMF_DT_E_RABInformationItem;


// E-RABInformationItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_E_RABInformationItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_E_RABInformationItem_ExtIEs;


// EUTRA-CGI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_EUTRA_CGI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_EUTRA_CGI_ExtIEs;


// EUTRA-CGIListForWarning
//SEQUENCE OF EUTRA-CGI, MIN=1, MAX=maxnoofCellIDforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_EUTRA_CGIListForWarning
{
	SI_LinkedList * EUTRA_CGI;
} SI_AMF_DT_EUTRA_CGIListForWarning;


// EUTRAencryptionAlgorithms
// BITSTRING,BIT STRING(SIZE(16,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_EUTRAencryptionAlgorithms
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_EUTRAencryptionAlgorithms;

// EUTRAintegrityProtectionAlgorithms
// BITSTRING,BIT STRING(SIZE(16,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_EUTRAintegrityProtectionAlgorithms
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_EUTRAintegrityProtectionAlgorithms;

// EventType
// ADT=0  DT=1
typedef enum __si_amf_dt_EventType
{
	EventType_direct_val,
	EventType_change_of_serve_cell_val,
	EventType_ue_presence_in_area_of_interest_val,
	EventType_stop_change_of_serve_cell_val,
	EventType_stop_ue_presence_in_area_of_interest_val,
	EventType_cancel_location_reporting_for_the_ue_val
} SI_AMF_DT_EventType;


// ExpectedUEActivityBehaviour-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_ExpectedUEActivityBehaviour_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs;


// ExpectedUEBehaviour-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_ExpectedUEBehaviour_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ExpectedUEBehaviour_ExtIEs;


// ExpectedUEMovingTrajectoryItemTime
// INTEGER,INTEGER(0..4095),MIN=0,MAX=4095
// ADT=0  DT=2
typedef struct __si_amf_dt_ExpectedUEMovingTrajectoryItemTime
{
	unsigned long long int data;
} SI_AMF_DT_ExpectedUEMovingTrajectoryItemTime;

// ExpectedUEMovingTrajectoryItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_ExpectedUEMovingTrajectoryItem
{
	SI_AMF_DT_NGRAN_CGI * nGRAN_CGI;

	unsigned long long int timeStayedInCell;
	int isPresent_timeStayedInCell;

} SI_AMF_DT_ExpectedUEMovingTrajectoryItem;


// ExpectedUEMovingTrajectoryItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_ExpectedUEMovingTrajectoryItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs;


// FiveG-TMSI
// OCTETSTRING,OCTET STRING(SIZE(4))
// ADT=0  DT=2
typedef struct __si_amf_dt_FiveG_TMSI
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_FiveG_TMSI;

// FiveG-S-TMSI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_FiveG_S_TMSI
{
	SI_AMF_DT_AMFSetID * aMFSetID;

	SI_AMF_DT_AMFPointer * aMFPointer;

	SI_AMF_DT_FiveG_TMSI * fiveG_TMSI;

} SI_AMF_DT_FiveG_S_TMSI;


// FiveG-S-TMSI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_FiveG_S_TMSI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_FiveG_S_TMSI_ExtIEs;


// ForbiddenAreaInformation
//SEQUENCE OF ForbiddenAreaInformation-Item, MIN=1, MAX= maxnoofEPLMNsPlusOne  ADT=0  DT=2
typedef struct __si_amf_dt_ForbiddenAreaInformation
{
	SI_LinkedList * ForbiddenAreaInformation_Item;
} SI_AMF_DT_ForbiddenAreaInformation;


// ForbiddenTACs
//SEQUENCE OF TAC, MIN=1, MAX=maxnoofForbTACs  ADT=0  DT=2
typedef struct __si_amf_dt_ForbiddenTACs
{
	SI_LinkedList * TAC;
} SI_AMF_DT_ForbiddenTACs;


// ForbiddenAreaInformation-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_ForbiddenAreaInformation_Item
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_ForbiddenTACs * forbiddenTACs;

} SI_AMF_DT_ForbiddenAreaInformation_Item;


// ForbiddenAreaInformation-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_ForbiddenAreaInformation_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs;


// NotificationControl
// ADT=0  DT=1
typedef enum __si_amf_dt_NotificationControl
{
	NotificationControl_notification_requested_val
} SI_AMF_DT_NotificationControl;


// PacketLossRate
// INTEGER,INTEGER(0..1000,...),MIN=0,MAX=1000
// ADT=0  DT=2
typedef struct __si_amf_dt_PacketLossRate
{
	unsigned long long int data;
} SI_AMF_DT_PacketLossRate;

// GBR-QosInformation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_GBR_QosInformation
{
	unsigned long long int maximumFlowBitRateDL;

	unsigned long long int maximumFlowBitRateUL;

	unsigned long long int guaranteedFlowBitRateDL;

	unsigned long long int guaranteedFlowBitRateUL;

	uint8_t selected_enotificationControl;
	int extSelected_enotificationControl;
	int isPresent_notificationControl;

	unsigned long long int maximumPacketLossRateDL;
	int isPresent_maximumPacketLossRateDL;

	unsigned long long int maximumPacketLossRateUL;
	int isPresent_maximumPacketLossRateUL;

} SI_AMF_DT_GBR_QosInformation;


// GBR-QosInformation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_GBR_QosInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GBR_QosInformation_ExtIEs;


// GlobalGNB-ID-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_GlobalGNB_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GlobalGNB_ID_ExtIEs;


// GlobalN3IWF-ID-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_GlobalN3IWF_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GlobalN3IWF_ID_ExtIEs;


// GlobalNgENB-ID-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_GlobalNgENB_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GlobalNgENB_ID_ExtIEs;


// GlobalRANNodeID-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_GlobalRANNodeID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GlobalRANNodeID_ExtIEs;


// GNB-ID-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_GNB_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GNB_ID_ExtIEs;


// GTPTunnel-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_GTPTunnel_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GTPTunnel_ExtIEs;


// GUAMI
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_GUAMI
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_AMFRegionID * aMFRegionID;

	SI_AMF_DT_AMFSetID * aMFSetID;

	SI_AMF_DT_AMFPointer * aMFPointer;

} SI_AMF_DT_GUAMI;


// GUAMI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_GUAMI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_GUAMI_ExtIEs;


// QosFlowToBeForwardedList
//SEQUENCE OF QosFlowToBeForwardedItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowToBeForwardedList
{
	SI_LinkedList * QosFlowToBeForwardedItem;
} SI_AMF_DT_QosFlowToBeForwardedList;


// HandoverCommandTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_HandoverCommandTransfer
{
	SI_AMF_DT_UPTransportLayerInformation * dLForwardingUP_TNLInformation;
	int isPresent_dLForwardingUP_TNLInformation;

	SI_AMF_DT_QosFlowToBeForwardedList * qosFlowToBeForwardedList;
	int isPresent_qosFlowToBeForwardedList;

	SI_AMF_DT_DataForwardingResponseDRBList * dataForwardingResponseDRBList;
	int isPresent_dataForwardingResponseDRBList;

} SI_AMF_DT_HandoverCommandTransfer;


// QosFlowPerTNLInformationList
//SEQUENCE OF QosFlowPerTNLInformationItem, MIN=1, MAX=maxnoofMultiConnectivityMinusOne  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowPerTNLInformationList
{
	SI_LinkedList * QosFlowPerTNLInformationItem;
} SI_AMF_DT_QosFlowPerTNLInformationList;


// UPTransportLayerInformationList
//SEQUENCE OF UPTransportLayerInformationItem, MIN=1, MAX=maxnoofMultiConnectivityMinusOne  ADT=0  DT=2
typedef struct __si_amf_dt_UPTransportLayerInformationList
{
	SI_LinkedList * UPTransportLayerInformationItem;
} SI_AMF_DT_UPTransportLayerInformationList;


// HandoverCommandTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_HandoverCommandTransfer_ExtIEs
{
	// Got Success L:2926
	//QosFlowPerTNLInformationList,  optional
	SI_AMF_DT_QosFlowPerTNLInformationList * additionalDLForwardingUPTNLInformation;
	int isPresent_additionalDLForwardingUPTNLInformation;

	//UPTransportLayerInformation,  optional
	SI_AMF_DT_UPTransportLayerInformation * uLForwardingUPTNLInformation;
	int isPresent_uLForwardingUPTNLInformation;

	//UPTransportLayerInformationList,  optional
	SI_AMF_DT_UPTransportLayerInformationList * additionalULForwardingUPTNLInformation;
	int isPresent_additionalULForwardingUPTNLInformation;

} SI_AMF_DT_HandoverCommandTransfer_ExtIEs;


// HandoverFlag
// ADT=0  DT=1
typedef enum __si_amf_dt_HandoverFlag
{
	HandoverFlag_handover_preparation_val
} SI_AMF_DT_HandoverFlag;


// HandoverPreparationUnsuccessfulTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_HandoverPreparationUnsuccessfulTransfer
{
	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer;


// HandoverPreparationUnsuccessfulTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_HandoverPreparationUnsuccessfulTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs;


// IntegrityProtectionResult
// ADT=0  DT=1
typedef enum __si_amf_dt_IntegrityProtectionResult
{
	IntegrityProtectionResult_performed_val,
	IntegrityProtectionResult_not_performed_val
} SI_AMF_DT_IntegrityProtectionResult;


// SecurityResult
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SecurityResult
{
	uint8_t selected_eintegrityProtectionResult;
	int extSelected_eintegrityProtectionResult;

	uint8_t selected_econfidentialityProtectionResult;
	int extSelected_econfidentialityProtectionResult;

} SI_AMF_DT_SecurityResult;


// QosFlowListWithCause
//SEQUENCE OF QosFlowWithCauseItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowListWithCause
{
	SI_LinkedList * QosFlowWithCauseItem;
} SI_AMF_DT_QosFlowListWithCause;


// HandoverRequestAcknowledgeTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_HandoverRequestAcknowledgeTransfer
{
	SI_AMF_DT_UPTransportLayerInformation * dL_NGU_UP_TNLInformation;

	SI_AMF_DT_UPTransportLayerInformation * dLForwardingUP_TNLInformation;
	int isPresent_dLForwardingUP_TNLInformation;

	SI_AMF_DT_SecurityResult * securityResult;
	int isPresent_securityResult;

	SI_AMF_DT_QosFlowListWithDataForwarding * qosFlowSetupResponseList;

	SI_AMF_DT_QosFlowListWithCause * qosFlowFailedToSetupList;
	int isPresent_qosFlowFailedToSetupList;

	SI_AMF_DT_DataForwardingResponseDRBList * dataForwardingResponseDRBList;
	int isPresent_dataForwardingResponseDRBList;

} SI_AMF_DT_HandoverRequestAcknowledgeTransfer;


// HandoverRequestAcknowledgeTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_HandoverRequestAcknowledgeTransfer_ExtIEs
{
	// Got Success L:2926
	//AdditionalDLUPTNLInformationForHOList,  optional
	SI_AMF_DT_AdditionalDLUPTNLInformationForHOList * additionalDLUPTNLInformationForHOList;
	int isPresent_additionalDLUPTNLInformationForHOList;

	//UPTransportLayerInformation,  optional
	SI_AMF_DT_UPTransportLayerInformation * uLForwardingUPTNLInformation;
	int isPresent_uLForwardingUPTNLInformation;

	//UPTransportLayerInformationList,  optional
	SI_AMF_DT_UPTransportLayerInformationList * additionalULForwardingUPTNLInformation;
	int isPresent_additionalULForwardingUPTNLInformation;

} SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs;


// HandoverRequiredTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_HandoverRequiredTransfer
{
	uint8_t selected_edirectForwardingPathAvailability;
	int extSelected_edirectForwardingPathAvailability;
	int isPresent_directForwardingPathAvailability;

} SI_AMF_DT_HandoverRequiredTransfer;


// HandoverRequiredTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_HandoverRequiredTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_HandoverRequiredTransfer_ExtIEs;


// HandoverResourceAllocationUnsuccessfulTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_HandoverResourceAllocationUnsuccessfulTransfer
{
	SI_AMF_DT_Cause * cause;

	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int isPresent_criticalityDiagnostics;

} SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer;


// HandoverResourceAllocationUnsuccessfulTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs;


// HandoverType
// ADT=0  DT=1
typedef enum __si_amf_dt_HandoverType
{
	HandoverType_intra5gs_val,
	HandoverType_fivegs_to_eps_val,
	HandoverType_eps_to_5gs_val
} SI_AMF_DT_HandoverType;


// IMSVoiceSupportIndicator
// ADT=0  DT=1
typedef enum __si_amf_dt_IMSVoiceSupportIndicator
{
	IMSVoiceSupportIndicator_supported_val,
	IMSVoiceSupportIndicator_not_supported_val
} SI_AMF_DT_IMSVoiceSupportIndicator;


// IndexToRFSP
// INTEGER,INTEGER(1..256,...),MIN=1,MAX=256
// ADT=0  DT=2
typedef struct __si_amf_dt_IndexToRFSP
{
	unsigned long long int data;
} SI_AMF_DT_IndexToRFSP;

// RecommendedRANNodeList
//SEQUENCE OF RecommendedRANNodeItem, MIN=1, MAX=maxnoofRecommendedRANNodes  ADT=0  DT=2
typedef struct __si_amf_dt_RecommendedRANNodeList
{
	SI_LinkedList * RecommendedRANNodeItem;
} SI_AMF_DT_RecommendedRANNodeList;


// RecommendedRANNodesForPaging
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_RecommendedRANNodesForPaging
{
	SI_AMF_DT_RecommendedRANNodeList * recommendedRANNodeList;

} SI_AMF_DT_RecommendedRANNodesForPaging;


// InfoOnRecommendedCellsAndRANNodesForPaging
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_InfoOnRecommendedCellsAndRANNodesForPaging
{
	SI_AMF_DT_RecommendedCellsForPaging * recommendedCellsForPaging;

	SI_AMF_DT_RecommendedRANNodesForPaging * recommendRANNodesForPaging;

} SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging;


// InfoOnRecommendedCellsAndRANNodesForPaging-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs;


// IntegrityProtectionIndication
// ADT=0  DT=1
typedef enum __si_amf_dt_IntegrityProtectionIndication
{
	IntegrityProtectionIndication_required_val,
	IntegrityProtectionIndication_preferred_val,
	IntegrityProtectionIndication_not_needed_val
} SI_AMF_DT_IntegrityProtectionIndication;


// InterfacesToTrace
// BITSTRING,BIT STRING(SIZE(8))
// ADT=0  DT=2
typedef struct __si_amf_dt_InterfacesToTrace
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_InterfacesToTrace;

// TimeUEStayedInCell
// INTEGER,INTEGER(0..4095),MIN=0,MAX=4095
// ADT=0  DT=2
typedef struct __si_amf_dt_TimeUEStayedInCell
{
	unsigned long long int data;
} SI_AMF_DT_TimeUEStayedInCell;

// TimeUEStayedInCellEnhancedGranularity
// INTEGER,INTEGER(0..40950),MIN=0,MAX=40950
// ADT=0  DT=2
typedef struct __si_amf_dt_TimeUEStayedInCellEnhancedGranularity
{
	unsigned long long int data;
} SI_AMF_DT_TimeUEStayedInCellEnhancedGranularity;

// LastVisitedNGRANCellInformation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_LastVisitedNGRANCellInformation
{
	SI_AMF_DT_NGRAN_CGI * globalCellID;

	SI_AMF_DT_CellType * cellType;

	unsigned long long int timeUEStayedInCell;

	unsigned long long int timeUEStayedInCellEnhancedGranularity;
	int isPresent_timeUEStayedInCellEnhancedGranularity;

	SI_AMF_DT_Cause * hOCauseValue;
	int isPresent_hOCauseValue;

} SI_AMF_DT_LastVisitedNGRANCellInformation;


// LastVisitedEUTRANCellInformation
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_LastVisitedEUTRANCellInformation
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_LastVisitedEUTRANCellInformation;

// LastVisitedUTRANCellInformation
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_LastVisitedUTRANCellInformation
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_LastVisitedUTRANCellInformation;

// LastVisitedGERANCellInformation
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_LastVisitedGERANCellInformation
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_LastVisitedGERANCellInformation;

// LastVisitedCellInformation
// ADT=0  DT=1
typedef struct __si_amf_dt_LastVisitedCellInformation
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_LastVisitedNGRANCellInformation * nGRANCell;

		// ParserName = OCTETSTRING;
		SI_AMF_DT_LastVisitedEUTRANCellInformation * eUTRANCell;

		// ParserName = OCTETSTRING;
		SI_AMF_DT_LastVisitedUTRANCellInformation * uTRANCell;

		// ParserName = OCTETSTRING;
		SI_AMF_DT_LastVisitedGERANCellInformation * gERANCell;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_LastVisitedCellInformation;


// LastVisitedCellInformation-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_LastVisitedCellInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_LastVisitedCellInformation_ExtIEs;


// LastVisitedCellItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_LastVisitedCellItem
{
	SI_AMF_DT_LastVisitedCellInformation * lastVisitedCellInformation;

} SI_AMF_DT_LastVisitedCellItem;


// LastVisitedCellItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_LastVisitedCellItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_LastVisitedCellItem_ExtIEs;


// LastVisitedNGRANCellInformation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_LastVisitedNGRANCellInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs;


// LocationReportingAdditionalInfo
// ADT=0  DT=1
typedef enum __si_amf_dt_LocationReportingAdditionalInfo
{
	LocationReportingAdditionalInfo_includePSCell_val
} SI_AMF_DT_LocationReportingAdditionalInfo;


// ReportArea
// ADT=0  DT=1
typedef enum __si_amf_dt_ReportArea
{
	ReportArea_cell_val
} SI_AMF_DT_ReportArea;


// LocationReportingRequestType
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_LocationReportingRequestType
{
	uint8_t selected_eeventType;
	int extSelected_eeventType;

	uint8_t selected_ereportArea;
	int extSelected_ereportArea;

	SI_AMF_DT_AreaOfInterestList * areaOfInterestList;
	int isPresent_areaOfInterestList;

	unsigned long long int locationReportingReferenceIDToBeCancelled;
	int isPresent_locationReportingReferenceIDToBeCancelled;

} SI_AMF_DT_LocationReportingRequestType;


// LocationReportingRequestType-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_LocationReportingRequestType_ExtIEs
{
	// Got Success L:2926
	//LocationReportingAdditionalInfo,  optional
	int selected_elocationReportingAdditionalInfo;
	int isPresent_locationReportingAdditionalInfo;

} SI_AMF_DT_LocationReportingRequestType_ExtIEs;


// MaskedIMEISV
// BITSTRING,BIT STRING(SIZE(64))
// ADT=0  DT=2
typedef struct __si_amf_dt_MaskedIMEISV
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_MaskedIMEISV;

// MessageIdentifier
// BITSTRING,BIT STRING(SIZE(16))
// ADT=0  DT=2
typedef struct __si_amf_dt_MessageIdentifier
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_MessageIdentifier;

// MaximumIntegrityProtectedDataRate
// ADT=0  DT=1
typedef enum __si_amf_dt_MaximumIntegrityProtectedDataRate
{
	MaximumIntegrityProtectedDataRate_bitrate64kbs_val,
	MaximumIntegrityProtectedDataRate_maximum_UE_rate_val
} SI_AMF_DT_MaximumIntegrityProtectedDataRate;


// RATRestrictions
//SEQUENCE OF RATRestrictions-Item, MIN=1, MAX=maxnoofEPLMNsPlusOne  ADT=0  DT=2
typedef struct __si_amf_dt_RATRestrictions
{
	SI_LinkedList * RATRestrictions_Item;
} SI_AMF_DT_RATRestrictions;


// ServiceAreaInformation
//SEQUENCE OF ServiceAreaInformation-Item, MIN=1, MAX= maxnoofEPLMNsPlusOne  ADT=0  DT=2
typedef struct __si_amf_dt_ServiceAreaInformation
{
	SI_LinkedList * ServiceAreaInformation_Item;
} SI_AMF_DT_ServiceAreaInformation;


// MobilityRestrictionList
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_MobilityRestrictionList
{
	SI_AMF_DT_PLMNIdentity * servingPLMN;

	SI_AMF_DT_EquivalentPLMNs * equivalentPLMNs;
	int isPresent_equivalentPLMNs;

	SI_AMF_DT_RATRestrictions * rATRestrictions;
	int isPresent_rATRestrictions;

	SI_AMF_DT_ForbiddenAreaInformation * forbiddenAreaInformation;
	int isPresent_forbiddenAreaInformation;

	SI_AMF_DT_ServiceAreaInformation * serviceAreaInformation;
	int isPresent_serviceAreaInformation;

} SI_AMF_DT_MobilityRestrictionList;


// MobilityRestrictionList-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_MobilityRestrictionList_ExtIEs
{
	// Got Success L:2926
	//PLMNIdentity,  optional
	SI_AMF_DT_PLMNIdentity * lastEUTRANPLMNIdentity;
	int isPresent_lastEUTRANPLMNIdentity;

	//CNTypeRestrictionsForServing,  optional
	int selected_ecNTypeRestrictionsForServing;
	int isPresent_cNTypeRestrictionsForServing;

	//CNTypeRestrictionsForEquivalent,  optional
	SI_AMF_DT_CNTypeRestrictionsForEquivalent * cNTypeRestrictionsForEquivalent;
	int isPresent_cNTypeRestrictionsForEquivalent;

} SI_AMF_DT_MobilityRestrictionList_ExtIEs;


// N3IWF-ID-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_N3IWF_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_N3IWF_ID_ExtIEs;


// NAS-PDU
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_NAS_PDU
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_NAS_PDU;

// NASSecurityParametersFromNGRAN
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_NASSecurityParametersFromNGRAN
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_NASSecurityParametersFromNGRAN;

// NetworkInstance
// INTEGER,INTEGER(1..256,...),MIN=1,MAX=256
// ADT=0  DT=2
typedef struct __si_amf_dt_NetworkInstance
{
	unsigned long long int data;
} SI_AMF_DT_NetworkInstance;

// NewSecurityContextInd
// ADT=0  DT=1
typedef enum __si_amf_dt_NewSecurityContextInd
{
	NewSecurityContextInd_true_val
} SI_AMF_DT_NewSecurityContextInd;


// NextHopChainingCount
// INTEGER,INTEGER(0..7),MIN=0,MAX=7
// ADT=0  DT=2
typedef struct __si_amf_dt_NextHopChainingCount
{
	unsigned long long int data;
} SI_AMF_DT_NextHopChainingCount;

// NgENB-ID-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_NgENB_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_NgENB_ID_ExtIEs;


// NGRAN-CGI-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_NGRAN_CGI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_NGRAN_CGI_ExtIEs;


// NGRAN-TNLAssociationToRemoveList
//SEQUENCE OF NGRAN-TNLAssociationToRemoveItem, MIN=1, MAX=maxnoofTNLAssociations  ADT=0  DT=2
typedef struct __si_amf_dt_NGRAN_TNLAssociationToRemoveList
{
	SI_LinkedList * NGRAN_TNLAssociationToRemoveItem;
} SI_AMF_DT_NGRAN_TNLAssociationToRemoveList;


// NGRAN-TNLAssociationToRemoveItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_NGRAN_TNLAssociationToRemoveItem
{
	SI_AMF_DT_CPTransportLayerInformation * tNLAssociationTransportLayerAddress;

	SI_AMF_DT_CPTransportLayerInformation * tNLAssociationTransportLayerAddressAMF;
	int isPresent_tNLAssociationTransportLayerAddressAMF;

} SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem;


// NGRAN-TNLAssociationToRemoveItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_NGRAN_TNLAssociationToRemoveItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs;


// NGRANTraceID
// OCTETSTRING,OCTET STRING(SIZE(8))
// ADT=0  DT=2
typedef struct __si_amf_dt_NGRANTraceID
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_NGRANTraceID;

// NonDynamic5QIDescriptor
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_NonDynamic5QIDescriptor
{
	unsigned long long int fiveQI;

	unsigned long long int priorityLevelQos;
	int isPresent_priorityLevelQos;

	unsigned long long int averagingWindow;
	int isPresent_averagingWindow;

	unsigned long long int maximumDataBurstVolume;
	int isPresent_maximumDataBurstVolume;

} SI_AMF_DT_NonDynamic5QIDescriptor;


// NonDynamic5QIDescriptor-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_NonDynamic5QIDescriptor_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs;


// NotAllowedTACs
//SEQUENCE OF TAC, MIN=1, MAX=maxnoofAllowedAreas  ADT=0  DT=2
typedef struct __si_amf_dt_NotAllowedTACs
{
	SI_LinkedList * TAC;
} SI_AMF_DT_NotAllowedTACs;


// NotificationCause
// ADT=0  DT=1
typedef enum __si_amf_dt_NotificationCause
{
	NotificationCause_fulfilled_val,
	NotificationCause_not_fulfilled_val
} SI_AMF_DT_NotificationCause;


// NR-CGI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_NR_CGI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_NR_CGI_ExtIEs;


// NR-CGIListForWarning
//SEQUENCE OF NR-CGI, MIN=1, MAX=maxnoofCellIDforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_NR_CGIListForWarning
{
	SI_LinkedList * NR_CGI;
} SI_AMF_DT_NR_CGIListForWarning;


// NRencryptionAlgorithms
// BITSTRING,BIT STRING(SIZE(16,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_NRencryptionAlgorithms
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_NRencryptionAlgorithms;

// NRintegrityProtectionAlgorithms
// BITSTRING,BIT STRING(SIZE(16,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_NRintegrityProtectionAlgorithms
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_NRintegrityProtectionAlgorithms;

// NRPPa-PDU
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_NRPPa_PDU
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_NRPPa_PDU;

// NumberOfBroadcastsRequested
// INTEGER,INTEGER(0..65535),MIN=0,MAX=65535
// ADT=0  DT=2
typedef struct __si_amf_dt_NumberOfBroadcastsRequested
{
	unsigned long long int data;
} SI_AMF_DT_NumberOfBroadcastsRequested;

// OverloadAction
// ADT=0  DT=1
typedef enum __si_amf_dt_OverloadAction
{
	OverloadAction_reject_non_emergency_mo_dt_val,
	OverloadAction_reject_rrc_cr_signalling_val,
	OverloadAction_permit_emergency_sessions_and_mobile_terminated_services_only_val,
	OverloadAction_permit_high_priority_sessions_and_mobile_terminated_services_only_val
} SI_AMF_DT_OverloadAction;


// OverloadResponse
// ADT=0  DT=1
typedef struct __si_amf_dt_OverloadResponse
{
	union 
	{
		// ParserName = ENUMERATED;
		uint8_t overloadAction;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_OverloadResponse;


// OverloadResponse-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_OverloadResponse_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_OverloadResponse_ExtIEs;


// OverloadStartNSSAIList
//SEQUENCE OF OverloadStartNSSAIItem, MIN=1, MAX=maxnoofSliceItems  ADT=0  DT=2
typedef struct __si_amf_dt_OverloadStartNSSAIList
{
	SI_LinkedList * OverloadStartNSSAIItem;
} SI_AMF_DT_OverloadStartNSSAIList;


// SliceOverloadList
//SEQUENCE OF SliceOverloadItem, MIN=1, MAX=maxnoofSliceItems  ADT=0  DT=2
typedef struct __si_amf_dt_SliceOverloadList
{
	SI_LinkedList * SliceOverloadItem;
} SI_AMF_DT_SliceOverloadList;


// TrafficLoadReductionIndication
// INTEGER,INTEGER(1..99),MIN=1,MAX=99
// ADT=0  DT=2
typedef struct __si_amf_dt_TrafficLoadReductionIndication
{
	unsigned long long int data;
} SI_AMF_DT_TrafficLoadReductionIndication;

// OverloadStartNSSAIItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_OverloadStartNSSAIItem
{
	SI_AMF_DT_SliceOverloadList * sliceOverloadList;

	SI_AMF_DT_OverloadResponse * sliceOverloadResponse;
	int isPresent_sliceOverloadResponse;

	unsigned long long int sliceTrafficLoadReductionIndication;
	int isPresent_sliceTrafficLoadReductionIndication;

} SI_AMF_DT_OverloadStartNSSAIItem;


// OverloadStartNSSAIItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_OverloadStartNSSAIItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs;


// PacketErrorRate-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PacketErrorRate_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PacketErrorRate_ExtIEs;


// PagingAttemptInformation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PagingAttemptInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PagingAttemptInformation_ExtIEs;


// PagingOrigin
// ADT=0  DT=1
typedef enum __si_amf_dt_PagingOrigin
{
	PagingOrigin_non_3gpp_val
} SI_AMF_DT_PagingOrigin;


// PagingPriority
// ADT=0  DT=1
typedef enum __si_amf_dt_PagingPriority
{
	PagingPriority_priolevel1_val,
	PagingPriority_priolevel2_val,
	PagingPriority_priolevel3_val,
	PagingPriority_priolevel4_val,
	PagingPriority_priolevel5_val,
	PagingPriority_priolevel6_val,
	PagingPriority_priolevel7_val,
	PagingPriority_priolevel8_val
} SI_AMF_DT_PagingPriority;


// SecurityIndication
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SecurityIndication
{
	uint8_t selected_eintegrityProtectionIndication;
	int extSelected_eintegrityProtectionIndication;

	uint8_t selected_econfidentialityProtectionIndication;
	int extSelected_econfidentialityProtectionIndication;

	uint8_t selected_emaximumIntegrityProtectedDataRate_UL;
	int extSelected_emaximumIntegrityProtectedDataRate_UL;
	int isPresent_maximumIntegrityProtectedDataRate_UL;

} SI_AMF_DT_SecurityIndication;


// PathSwitchRequestAcknowledgeTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PathSwitchRequestAcknowledgeTransfer
{
	SI_AMF_DT_UPTransportLayerInformation * uL_NGU_UP_TNLInformation;
	int isPresent_uL_NGU_UP_TNLInformation;

	SI_AMF_DT_SecurityIndication * securityIndication;
	int isPresent_securityIndication;

} SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer;


// UPTransportLayerInformationPairList
//SEQUENCE OF UPTransportLayerInformationPairItem, MIN=1, MAX=maxnoofMultiConnectivityMinusOne  ADT=0  DT=2
typedef struct __si_amf_dt_UPTransportLayerInformationPairList
{
	SI_LinkedList * UPTransportLayerInformationPairItem;
} SI_AMF_DT_UPTransportLayerInformationPairList;


// PathSwitchRequestAcknowledgeTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PathSwitchRequestAcknowledgeTransfer_ExtIEs
{
	// Got Success L:2926
	//UPTransportLayerInformationPairList,  optional
	SI_AMF_DT_UPTransportLayerInformationPairList * additionalNGUUPTNLInformation;
	int isPresent_additionalNGUUPTNLInformation;

} SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs;


// PathSwitchRequestSetupFailedTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PathSwitchRequestSetupFailedTransfer
{
	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_PathSwitchRequestSetupFailedTransfer;


// PathSwitchRequestSetupFailedTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PathSwitchRequestSetupFailedTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs;


// UserPlaneSecurityInformation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UserPlaneSecurityInformation
{
	SI_AMF_DT_SecurityResult * securityResult;

	SI_AMF_DT_SecurityIndication * securityIndication;

} SI_AMF_DT_UserPlaneSecurityInformation;


// QosFlowAcceptedList
//SEQUENCE OF QosFlowAcceptedItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowAcceptedList
{
	SI_LinkedList * QosFlowAcceptedItem;
} SI_AMF_DT_QosFlowAcceptedList;


// PathSwitchRequestTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PathSwitchRequestTransfer
{
	SI_AMF_DT_UPTransportLayerInformation * dL_NGU_UP_TNLInformation;

	uint8_t selected_edL_NGU_TNLInformationReused;
	int extSelected_edL_NGU_TNLInformationReused;
	int isPresent_dL_NGU_TNLInformationReused;

	SI_AMF_DT_UserPlaneSecurityInformation * userPlaneSecurityInformation;
	int isPresent_userPlaneSecurityInformation;

	SI_AMF_DT_QosFlowAcceptedList * qosFlowAcceptedList;

} SI_AMF_DT_PathSwitchRequestTransfer;


// PathSwitchRequestTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PathSwitchRequestTransfer_ExtIEs
{
	// Got Success L:2926
	//QosFlowPerTNLInformationList,  optional
	SI_AMF_DT_QosFlowPerTNLInformationList * additionalDLQosFlowPerTNLInformation;
	int isPresent_additionalDLQosFlowPerTNLInformation;

} SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs;


// PathSwitchRequestUnsuccessfulTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PathSwitchRequestUnsuccessfulTransfer
{
	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer;


// PathSwitchRequestUnsuccessfulTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PathSwitchRequestUnsuccessfulTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs;


// PDUSessionAggregateMaximumBitRate
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionAggregateMaximumBitRate
{
	unsigned long long int pDUSessionAggregateMaximumBitRateDL;

	unsigned long long int pDUSessionAggregateMaximumBitRateUL;

} SI_AMF_DT_PDUSessionAggregateMaximumBitRate;


// PDUSessionAggregateMaximumBitRate-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionAggregateMaximumBitRate_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs;


// PDUSessionID
// INTEGER,INTEGER(0..255),MIN=0,MAX=255
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionID
{
	unsigned long long int data;
} SI_AMF_DT_PDUSessionID;

// PDUSessionResourceAdmittedList
//SEQUENCE OF PDUSessionResourceAdmittedItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceAdmittedList
{
	SI_LinkedList * PDUSessionResourceAdmittedItem;
} SI_AMF_DT_PDUSessionResourceAdmittedList;


// HandoverRequestAcknowledgeTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_HandoverRequestAcknowledgeTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr;

// PDUSessionResourceAdmittedItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceAdmittedItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr * handoverRequestAcknowledgeTransfer;

} SI_AMF_DT_PDUSessionResourceAdmittedItem;


// PDUSessionResourceAdmittedItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceAdmittedItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs;


// PDUSessionResourceFailedToModifyListModCfm
//SEQUENCE OF PDUSessionResourceFailedToModifyItemModCfm, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToModifyListModCfm
{
	SI_LinkedList * PDUSessionResourceFailedToModifyItemModCfm;
} SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm;


// PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr;

// PDUSessionResourceFailedToModifyItemModCfm
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToModifyItemModCfm
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr * pDUSessionResourceModifyIndicationUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm;


// PDUSessionResourceFailedToModifyItemModCfm-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs;


// PDUSessionResourceFailedToModifyListModRes
//SEQUENCE OF PDUSessionResourceFailedToModifyItemModRes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToModifyListModRes
{
	SI_LinkedList * PDUSessionResourceFailedToModifyItemModRes;
} SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes;


// PDUSessionResourceModifyUnsuccessfulTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyUnsuccessfulTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr;

// PDUSessionResourceFailedToModifyItemModRes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToModifyItemModRes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr * pDUSessionResourceModifyUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes;


// PDUSessionResourceFailedToModifyItemModRes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToModifyItemModRes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs;


// PDUSessionResourceFailedToSetupListCxtFail
//SEQUENCE OF PDUSessionResourceFailedToSetupItemCxtFail, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupListCxtFail
{
	SI_LinkedList * PDUSessionResourceFailedToSetupItemCxtFail;
} SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail;


// PDUSessionResourceSetupUnsuccessfulTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupUnsuccessfulTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr;

// PDUSessionResourceFailedToSetupItemCxtFail
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemCxtFail
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * pDUSessionResourceSetupUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail;


// PDUSessionResourceFailedToSetupItemCxtFail-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs;


// PDUSessionResourceFailedToSetupListCxtRes
//SEQUENCE OF PDUSessionResourceFailedToSetupItemCxtRes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupListCxtRes
{
	SI_LinkedList * PDUSessionResourceFailedToSetupItemCxtRes;
} SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes;


// PDUSessionResourceFailedToSetupItemCxtRes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemCxtRes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * pDUSessionResourceSetupUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes;


// PDUSessionResourceFailedToSetupItemCxtRes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs;


// PDUSessionResourceFailedToSetupListHOAck
//SEQUENCE OF PDUSessionResourceFailedToSetupItemHOAck, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupListHOAck
{
	SI_LinkedList * PDUSessionResourceFailedToSetupItemHOAck;
} SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck;


// HandoverResourceAllocationUnsuccessfulTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_HandoverResourceAllocationUnsuccessfulTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr;

// PDUSessionResourceFailedToSetupItemHOAck
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemHOAck
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr * handoverResourceAllocationUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck;


// PDUSessionResourceFailedToSetupItemHOAck-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs;


// PDUSessionResourceFailedToSetupListPSReq
//SEQUENCE OF PDUSessionResourceFailedToSetupItemPSReq, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupListPSReq
{
	SI_LinkedList * PDUSessionResourceFailedToSetupItemPSReq;
} SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq;


// PathSwitchRequestSetupFailedTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PathSwitchRequestSetupFailedTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr;

// PDUSessionResourceFailedToSetupItemPSReq
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemPSReq
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr * pathSwitchRequestSetupFailedTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq;


// PDUSessionResourceFailedToSetupItemPSReq-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs;


// PDUSessionResourceFailedToSetupListSURes
//SEQUENCE OF PDUSessionResourceFailedToSetupItemSURes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupListSURes
{
	SI_LinkedList * PDUSessionResourceFailedToSetupItemSURes;
} SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes;


// PDUSessionResourceFailedToSetupItemSURes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemSURes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * pDUSessionResourceSetupUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes;


// PDUSessionResourceFailedToSetupItemSURes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceFailedToSetupItemSURes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs;


// PDUSessionResourceHandoverList
//SEQUENCE OF PDUSessionResourceHandoverItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceHandoverList
{
	SI_LinkedList * PDUSessionResourceHandoverItem;
} SI_AMF_DT_PDUSessionResourceHandoverList;


// HandoverCommandTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_HandoverCommandTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_HandoverCommandTransferOctStr;

// PDUSessionResourceHandoverItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceHandoverItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_HandoverCommandTransferOctStr * handoverCommandTransfer;

} SI_AMF_DT_PDUSessionResourceHandoverItem;


// PDUSessionResourceHandoverItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceHandoverItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs;


// PDUSessionResourceInformationList
//SEQUENCE OF PDUSessionResourceInformationItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceInformationList
{
	SI_LinkedList * PDUSessionResourceInformationItem;
} SI_AMF_DT_PDUSessionResourceInformationList;


// QosFlowInformationList
//SEQUENCE OF QosFlowInformationItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowInformationList
{
	SI_LinkedList * QosFlowInformationItem;
} SI_AMF_DT_QosFlowInformationList;


// PDUSessionResourceInformationItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceInformationItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_QosFlowInformationList * qosFlowInformationList;

	SI_AMF_DT_DRBsToQosFlowsMappingList * dRBsToQosFlowsMappingList;
	int isPresent_dRBsToQosFlowsMappingList;

} SI_AMF_DT_PDUSessionResourceInformationItem;


// PDUSessionResourceInformationItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceInformationItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs;


// PDUSessionResourceListCxtRelCpl
//SEQUENCE OF PDUSessionResourceItemCxtRelCpl, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceListCxtRelCpl
{
	SI_LinkedList * PDUSessionResourceItemCxtRelCpl;
} SI_AMF_DT_PDUSessionResourceListCxtRelCpl;


// PDUSessionResourceItemCxtRelCpl
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceItemCxtRelCpl
{
	unsigned long long int pDUSessionID;

} SI_AMF_DT_PDUSessionResourceItemCxtRelCpl;


// PDUSessionResourceReleaseResponseTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceReleaseResponseTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr;

// PDUSessionResourceItemCxtRelCpl-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceItemCxtRelCpl_ExtIEs
{
	// Got Success L:2926
	//PDUSessionResourceReleaseResponseTransferOctStr,  optional
	SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr * pDUSessionResourceReleaseResponseTransfer;
	int isPresent_pDUSessionResourceReleaseResponseTransfer;

} SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs;


// PDUSessionResourceListCxtRelReq
//SEQUENCE OF PDUSessionResourceItemCxtRelReq, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceListCxtRelReq
{
	SI_LinkedList * PDUSessionResourceItemCxtRelReq;
} SI_AMF_DT_PDUSessionResourceListCxtRelReq;


// PDUSessionResourceItemCxtRelReq
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceItemCxtRelReq
{
	unsigned long long int pDUSessionID;

} SI_AMF_DT_PDUSessionResourceItemCxtRelReq;


// PDUSessionResourceItemCxtRelReq-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceItemCxtRelReq_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs;


// PDUSessionResourceListHORqd
//SEQUENCE OF PDUSessionResourceItemHORqd, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceListHORqd
{
	SI_LinkedList * PDUSessionResourceItemHORqd;
} SI_AMF_DT_PDUSessionResourceListHORqd;


// HandoverRequiredTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_HandoverRequiredTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_HandoverRequiredTransferOctStr;

// PDUSessionResourceItemHORqd
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceItemHORqd
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_HandoverRequiredTransferOctStr * handoverRequiredTransfer;

} SI_AMF_DT_PDUSessionResourceItemHORqd;


// PDUSessionResourceItemHORqd-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceItemHORqd_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs;


// QosFlowModifyConfirmList
//SEQUENCE OF QosFlowModifyConfirmItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowModifyConfirmList
{
	SI_LinkedList * QosFlowModifyConfirmItem;
} SI_AMF_DT_QosFlowModifyConfirmList;


// PDUSessionResourceModifyConfirmTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyConfirmTransfer
{
	SI_AMF_DT_QosFlowModifyConfirmList * qosFlowModifyConfirmList;

	SI_AMF_DT_UPTransportLayerInformation * uLNGU_UP_TNLInformation;

	SI_AMF_DT_UPTransportLayerInformationPairList * additionalNG_UUPTNLInformation;
	int isPresent_additionalNG_UUPTNLInformation;

	SI_AMF_DT_QosFlowListWithCause * qosFlowFailedToModifyList;
	int isPresent_qosFlowFailedToModifyList;

} SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer;


// PDUSessionResourceModifyConfirmTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyConfirmTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs;


// PDUSessionResourceModifyIndicationUnsuccessfulTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyIndicationUnsuccessfulTransfer
{
	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer;


// PDUSessionResourceModifyIndicationUnsuccessfulTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs;


// PDUSessionResourceModifyRequestTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyRequestTransfer
{
} SI_AMF_DT_PDUSessionResourceModifyRequestTransfer;


// UL-NGU-UP-TNLModifyList
//SEQUENCE OF UL-NGU-UP-TNLModifyItem, MIN=1, MAX=maxnoofMultiConnectivity  ADT=0  DT=2
typedef struct __si_amf_dt_UL_NGU_UP_TNLModifyList
{
	SI_LinkedList * UL_NGU_UP_TNLModifyItem;
} SI_AMF_DT_UL_NGU_UP_TNLModifyList;


// QosFlowAddOrModifyRequestList
//SEQUENCE OF QosFlowAddOrModifyRequestItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowAddOrModifyRequestList
{
	SI_LinkedList * QosFlowAddOrModifyRequestItem;
} SI_AMF_DT_QosFlowAddOrModifyRequestList;


// PDUSessionResourceModifyRequestTransferIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyRequestTransferIEs
{
	// Got Success L:2926
	//PDUSessionAggregateMaximumBitRate,  optional
	SI_AMF_DT_PDUSessionAggregateMaximumBitRate * pDUSessionAggregateMaximumBitRate;
	int isPresent_pDUSessionAggregateMaximumBitRate;

	//UL-NGU-UP-TNLModifyList,  optional
	SI_AMF_DT_UL_NGU_UP_TNLModifyList * uLNGUUPTNLModifyList;
	int isPresent_uLNGUUPTNLModifyList;

	//NetworkInstance,  optional
	unsigned long long int networkInstance;
	int isPresent_networkInstance;

	//QosFlowAddOrModifyRequestList,  optional
	SI_AMF_DT_QosFlowAddOrModifyRequestList * qosFlowAddOrModifyRequestList;
	int isPresent_qosFlowAddOrModifyRequestList;

	//QosFlowListWithCause,  optional
	SI_AMF_DT_QosFlowListWithCause * qosFlowToReleaseList;
	int isPresent_qosFlowToReleaseList;

	//UPTransportLayerInformationList,  optional
	SI_AMF_DT_UPTransportLayerInformationList * additionalULNGUUPTNLInformation;
	int isPresent_additionalULNGUUPTNLInformation;

	//CommonNetworkInstance,  optional
	SI_AMF_DT_CommonNetworkInstance * commonNetworkInstance;
	int isPresent_commonNetworkInstance;

} SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs;


// QosFlowAddOrModifyResponseList
//SEQUENCE OF QosFlowAddOrModifyResponseItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowAddOrModifyResponseList
{
	SI_LinkedList * QosFlowAddOrModifyResponseItem;
} SI_AMF_DT_QosFlowAddOrModifyResponseList;


// PDUSessionResourceModifyResponseTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyResponseTransfer
{
	SI_AMF_DT_UPTransportLayerInformation * dL_NGU_UP_TNLInformation;
	int isPresent_dL_NGU_UP_TNLInformation;

	SI_AMF_DT_UPTransportLayerInformation * uL_NGU_UP_TNLInformation;
	int isPresent_uL_NGU_UP_TNLInformation;

	SI_AMF_DT_QosFlowAddOrModifyResponseList * qosFlowAddOrModifyResponseList;
	int isPresent_qosFlowAddOrModifyResponseList;

	SI_AMF_DT_QosFlowPerTNLInformationList * additionalDLQosFlowPerTNLInformation;
	int isPresent_additionalDLQosFlowPerTNLInformation;

	SI_AMF_DT_QosFlowListWithCause * qosFlowFailedToAddOrModifyList;
	int isPresent_qosFlowFailedToAddOrModifyList;

} SI_AMF_DT_PDUSessionResourceModifyResponseTransfer;


// PDUSessionResourceModifyResponseTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyResponseTransfer_ExtIEs
{
	// Got Success L:2926
	//UPTransportLayerInformationPairList,  optional
	SI_AMF_DT_UPTransportLayerInformationPairList * additionalNGUUPTNLInformation;
	int isPresent_additionalNGUUPTNLInformation;

} SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs;


// QosFlowPerTNLInformation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowPerTNLInformation
{
	SI_AMF_DT_UPTransportLayerInformation * uPTransportLayerInformation;

	SI_AMF_DT_AssociatedQosFlowList * associatedQosFlowList;

} SI_AMF_DT_QosFlowPerTNLInformation;


// PDUSessionResourceModifyIndicationTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyIndicationTransfer
{
	SI_AMF_DT_QosFlowPerTNLInformation * dLQosFlowPerTNLInformation;

	SI_AMF_DT_QosFlowPerTNLInformationList * additionalDLQosFlowPerTNLInformation;
	int isPresent_additionalDLQosFlowPerTNLInformation;

} SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer;


// PDUSessionUsageReportRatType
// ADT=0  DT=1
typedef enum __si_amf_dt_PDUSessionUsageReportRatType
{
	PDUSessionUsageReportRatType_nr_val,
	PDUSessionUsageReportRatType_eutra_val
} SI_AMF_DT_PDUSessionUsageReportRatType;


// VolumeTimedReportList
//SEQUENCE OF VolumeTimedReport-Item, MIN=1, MAX=maxnoofTimePeriods  ADT=0  DT=2
typedef struct __si_amf_dt_VolumeTimedReportList
{
	SI_LinkedList * VolumeTimedReport_Item;
} SI_AMF_DT_VolumeTimedReportList;


// PDUSessionUsageReport
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionUsageReport
{
	uint8_t selected_erATType;
	int extSelected_erATType;

	SI_AMF_DT_VolumeTimedReportList * pDUSessionTimedReportList;

} SI_AMF_DT_PDUSessionUsageReport;


// QoSFlowsUsageReportList
//SEQUENCE OF QoSFlowsUsageReport-Item, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QoSFlowsUsageReportList
{
	SI_LinkedList * QoSFlowsUsageReport_Item;
} SI_AMF_DT_QoSFlowsUsageReportList;


// SecondaryRATUsageInformation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SecondaryRATUsageInformation
{
	SI_AMF_DT_PDUSessionUsageReport * pDUSessionUsageReport;
	int isPresent_pDUSessionUsageReport;

	SI_AMF_DT_QoSFlowsUsageReportList * qosFlowsUsageReportList;
	int isPresent_qosFlowsUsageReportList;

} SI_AMF_DT_SecondaryRATUsageInformation;


// PDUSessionResourceModifyIndicationTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyIndicationTransfer_ExtIEs
{
	// Got Success L:2926
	//SecondaryRATUsageInformation,  optional
	SI_AMF_DT_SecondaryRATUsageInformation * secondaryRATUsageInformation;
	int isPresent_secondaryRATUsageInformation;

	//SecurityResult,  optional
	SI_AMF_DT_SecurityResult * securityResult;
	int isPresent_securityResult;

} SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs;


// PDUSessionResourceModifyListModCfm
//SEQUENCE OF PDUSessionResourceModifyItemModCfm, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyListModCfm
{
	SI_LinkedList * PDUSessionResourceModifyItemModCfm;
} SI_AMF_DT_PDUSessionResourceModifyListModCfm;


// PDUSessionResourceModifyConfirmTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyConfirmTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr;

// PDUSessionResourceModifyItemModCfm
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModCfm
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr * pDUSessionResourceModifyConfirmTransfer;

} SI_AMF_DT_PDUSessionResourceModifyItemModCfm;


// PDUSessionResourceModifyItemModCfm-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModCfm_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs;


// PDUSessionResourceModifyListModInd
//SEQUENCE OF PDUSessionResourceModifyItemModInd, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyListModInd
{
	SI_LinkedList * PDUSessionResourceModifyItemModInd;
} SI_AMF_DT_PDUSessionResourceModifyListModInd;


// PDUSessionResourceModifyIndicationTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyIndicationTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr;

// PDUSessionResourceModifyItemModInd
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModInd
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr * pDUSessionResourceModifyIndicationTransfer;

} SI_AMF_DT_PDUSessionResourceModifyItemModInd;


// PDUSessionResourceModifyItemModInd-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModInd_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs;


// PDUSessionResourceModifyListModReq
//SEQUENCE OF PDUSessionResourceModifyItemModReq, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyListModReq
{
	SI_LinkedList * PDUSessionResourceModifyItemModReq;
} SI_AMF_DT_PDUSessionResourceModifyListModReq;


// PDUSessionResourceModifyRequestTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyRequestTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr;

// PDUSessionResourceModifyItemModReq
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModReq
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_NAS_PDU * nAS_PDU;
	int isPresent_nAS_PDU;

	SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr * pDUSessionResourceModifyRequestTransfer;

} SI_AMF_DT_PDUSessionResourceModifyItemModReq;


// PDUSessionResourceModifyItemModReq-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModReq_ExtIEs
{
	// Got Success L:2926
	//S-NSSAI,  optional
	SI_AMF_DT_S_NSSAI * sNSSAI;
	int isPresent_sNSSAI;

} SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs;


// PDUSessionResourceModifyListModRes
//SEQUENCE OF PDUSessionResourceModifyItemModRes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyListModRes
{
	SI_LinkedList * PDUSessionResourceModifyItemModRes;
} SI_AMF_DT_PDUSessionResourceModifyListModRes;


// PDUSessionResourceModifyResponseTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceModifyResponseTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr;

// PDUSessionResourceModifyItemModRes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModRes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr * pDUSessionResourceModifyResponseTransfer;

} SI_AMF_DT_PDUSessionResourceModifyItemModRes;


// PDUSessionResourceModifyItemModRes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyItemModRes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs;


// PDUSessionResourceModifyUnsuccessfulTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceModifyUnsuccessfulTransfer
{
	SI_AMF_DT_Cause * cause;

	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int isPresent_criticalityDiagnostics;

} SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer;


// PDUSessionResourceModifyUnsuccessfulTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs;


// PDUSessionResourceNotifyList
//SEQUENCE OF PDUSessionResourceNotifyItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceNotifyList
{
	SI_LinkedList * PDUSessionResourceNotifyItem;
} SI_AMF_DT_PDUSessionResourceNotifyList;


// PDUSessionResourceNotifyTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceNotifyTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr;

// PDUSessionResourceNotifyItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceNotifyItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr * pDUSessionResourceNotifyTransfer;

} SI_AMF_DT_PDUSessionResourceNotifyItem;


// PDUSessionResourceNotifyItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceNotifyItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs;


// PDUSessionResourceNotifyReleasedTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceNotifyReleasedTransfer
{
	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer;


// PDUSessionResourceNotifyReleasedTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceNotifyReleasedTransfer_ExtIEs
{
	// Got Success L:2926
	//SecondaryRATUsageInformation,  optional
	SI_AMF_DT_SecondaryRATUsageInformation * secondaryRATUsageInformation;
	int isPresent_secondaryRATUsageInformation;

} SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs;


// QosFlowNotifyList
//SEQUENCE OF QosFlowNotifyItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowNotifyList
{
	SI_LinkedList * QosFlowNotifyItem;
} SI_AMF_DT_QosFlowNotifyList;


// PDUSessionResourceNotifyTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceNotifyTransfer
{
	SI_AMF_DT_QosFlowNotifyList * qosFlowNotifyList;
	int isPresent_qosFlowNotifyList;

	SI_AMF_DT_QosFlowListWithCause * qosFlowReleasedList;
	int isPresent_qosFlowReleasedList;

} SI_AMF_DT_PDUSessionResourceNotifyTransfer;


// PDUSessionResourceNotifyTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceNotifyTransfer_ExtIEs
{
	// Got Success L:2926
	//SecondaryRATUsageInformation,  optional
	SI_AMF_DT_SecondaryRATUsageInformation * secondaryRATUsageInformation;
	int isPresent_secondaryRATUsageInformation;

} SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs;


// PDUSessionResourceReleaseCommandTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceReleaseCommandTransfer
{
	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer;


// PDUSessionResourceReleaseCommandTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceReleaseCommandTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs;


// PDUSessionResourceReleasedListNot
//SEQUENCE OF PDUSessionResourceReleasedItemNot, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceReleasedListNot
{
	SI_LinkedList * PDUSessionResourceReleasedItemNot;
} SI_AMF_DT_PDUSessionResourceReleasedListNot;


// PDUSessionResourceNotifyReleasedTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceNotifyReleasedTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr;

// PDUSessionResourceReleasedItemNot
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemNot
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr * pDUSessionResourceNotifyReleasedTransfer;

} SI_AMF_DT_PDUSessionResourceReleasedItemNot;


// PDUSessionResourceReleasedItemNot-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemNot_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs;


// PDUSessionResourceReleasedListPSAck
//SEQUENCE OF PDUSessionResourceReleasedItemPSAck, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceReleasedListPSAck
{
	SI_LinkedList * PDUSessionResourceReleasedItemPSAck;
} SI_AMF_DT_PDUSessionResourceReleasedListPSAck;


// PathSwitchRequestUnsuccessfulTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PathSwitchRequestUnsuccessfulTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr;

// PDUSessionResourceReleasedItemPSAck
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemPSAck
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr * pathSwitchRequestUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceReleasedItemPSAck;


// PDUSessionResourceReleasedItemPSAck-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemPSAck_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs;


// PDUSessionResourceReleasedListPSFail
//SEQUENCE OF PDUSessionResourceReleasedItemPSFail, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceReleasedListPSFail
{
	SI_LinkedList * PDUSessionResourceReleasedItemPSFail;
} SI_AMF_DT_PDUSessionResourceReleasedListPSFail;


// PDUSessionResourceReleasedItemPSFail
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemPSFail
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr * pathSwitchRequestUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceReleasedItemPSFail;


// PDUSessionResourceReleasedItemPSFail-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemPSFail_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs;


// PDUSessionResourceReleasedListRelRes
//SEQUENCE OF PDUSessionResourceReleasedItemRelRes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceReleasedListRelRes
{
	SI_LinkedList * PDUSessionResourceReleasedItemRelRes;
} SI_AMF_DT_PDUSessionResourceReleasedListRelRes;


// PDUSessionResourceReleasedItemRelRes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemRelRes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr * pDUSessionResourceReleaseResponseTransfer;

} SI_AMF_DT_PDUSessionResourceReleasedItemRelRes;


// PDUSessionResourceReleasedItemRelRes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceReleasedItemRelRes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs;


// PDUSessionResourceReleaseResponseTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceReleaseResponseTransfer
{
} SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer;


// PDUSessionResourceReleaseResponseTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceReleaseResponseTransfer_ExtIEs
{
	// Got Success L:2926
	//SecondaryRATUsageInformation,  optional
	SI_AMF_DT_SecondaryRATUsageInformation * secondaryRATUsageInformation;
	int isPresent_secondaryRATUsageInformation;

} SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs;


// PDUSessionResourceSecondaryRATUsageList
//SEQUENCE OF PDUSessionResourceSecondaryRATUsageItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSecondaryRATUsageList
{
	SI_LinkedList * PDUSessionResourceSecondaryRATUsageItem;
} SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList;


// SecondaryRATDataUsageReportTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_SecondaryRATDataUsageReportTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr;

// PDUSessionResourceSecondaryRATUsageItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSecondaryRATUsageItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr * secondaryRATDataUsageReportTransfer;

} SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem;


// PDUSessionResourceSecondaryRATUsageItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSecondaryRATUsageItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs;


// PDUSessionResourceSetupListCxtReq
//SEQUENCE OF PDUSessionResourceSetupItemCxtReq, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupListCxtReq
{
	SI_LinkedList * PDUSessionResourceSetupItemCxtReq;
} SI_AMF_DT_PDUSessionResourceSetupListCxtReq;


// PDUSessionResourceSetupRequestTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupRequestTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr;

// PDUSessionResourceSetupItemCxtReq
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupItemCxtReq
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_NAS_PDU * nAS_PDU;
	int isPresent_nAS_PDU;

	SI_AMF_DT_S_NSSAI * s_NSSAI;

	SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * pDUSessionResourceSetupRequestTransfer;

} SI_AMF_DT_PDUSessionResourceSetupItemCxtReq;


// PDUSessionResourceSetupItemCxtReq-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupItemCxtReq_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs;


// PDUSessionResourceSetupListCxtRes
//SEQUENCE OF PDUSessionResourceSetupItemCxtRes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupListCxtRes
{
	SI_LinkedList * PDUSessionResourceSetupItemCxtRes;
} SI_AMF_DT_PDUSessionResourceSetupListCxtRes;


// PDUSessionResourceSetupResponseTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupResponseTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr;

// PDUSessionResourceSetupItemCxtRes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupItemCxtRes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr * pDUSessionResourceSetupResponseTransfer;

} SI_AMF_DT_PDUSessionResourceSetupItemCxtRes;


// PDUSessionResourceSetupItemCxtRes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupItemCxtRes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs;


// PDUSessionResourceSetupListHOReq
//SEQUENCE OF PDUSessionResourceSetupItemHOReq, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupListHOReq
{
	SI_LinkedList * PDUSessionResourceSetupItemHOReq;
} SI_AMF_DT_PDUSessionResourceSetupListHOReq;


// PDUSessionResourceSetupItemHOReq
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupItemHOReq
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_S_NSSAI * s_NSSAI;

	SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * handoverRequestTransfer;

} SI_AMF_DT_PDUSessionResourceSetupItemHOReq;


// PDUSessionResourceSetupItemHOReq-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupItemHOReq_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs;


// PDUSessionResourceSetupListSUReq
//SEQUENCE OF PDUSessionResourceSetupItemSUReq, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupListSUReq
{
	SI_LinkedList * PDUSessionResourceSetupItemSUReq;
} SI_AMF_DT_PDUSessionResourceSetupListSUReq;


// PDUSessionResourceSetupItemSUReq
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupItemSUReq
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_NAS_PDU * pDUSessionNAS_PDU;
	int isPresent_pDUSessionNAS_PDU;

	SI_AMF_DT_S_NSSAI * s_NSSAI;

	SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * pDUSessionResourceSetupRequestTransfer;

} SI_AMF_DT_PDUSessionResourceSetupItemSUReq;


// PDUSessionResourceSetupItemSUReq-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupItemSUReq_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs;


// PDUSessionResourceSetupListSURes
//SEQUENCE OF PDUSessionResourceSetupItemSURes, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSetupListSURes
{
	SI_LinkedList * PDUSessionResourceSetupItemSURes;
} SI_AMF_DT_PDUSessionResourceSetupListSURes;


// PDUSessionResourceSetupItemSURes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupItemSURes
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr * pDUSessionResourceSetupResponseTransfer;

} SI_AMF_DT_PDUSessionResourceSetupItemSURes;


// PDUSessionResourceSetupItemSURes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupItemSURes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs;


// PDUSessionResourceSetupRequestTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupRequestTransfer
{
} SI_AMF_DT_PDUSessionResourceSetupRequestTransfer;


// PDUSessionResourceSetupResponseTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupResponseTransfer
{
	SI_AMF_DT_QosFlowPerTNLInformation * dLQosFlowPerTNLInformation;

	SI_AMF_DT_QosFlowPerTNLInformationList * additionalDLQosFlowPerTNLInformation;
	int isPresent_additionalDLQosFlowPerTNLInformation;

	SI_AMF_DT_SecurityResult * securityResult;
	int isPresent_securityResult;

	SI_AMF_DT_QosFlowListWithCause * qosFlowFailedToSetupList;
	int isPresent_qosFlowFailedToSetupList;

} SI_AMF_DT_PDUSessionResourceSetupResponseTransfer;


// PDUSessionResourceSetupResponseTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupResponseTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs;


// PDUSessionResourceSetupUnsuccessfulTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSetupUnsuccessfulTransfer
{
	SI_AMF_DT_Cause * cause;

	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int isPresent_criticalityDiagnostics;

} SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer;


// PDUSessionResourceSetupUnsuccessfulTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs;


// PDUSessionResourceSwitchedList
//SEQUENCE OF PDUSessionResourceSwitchedItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceSwitchedList
{
	SI_LinkedList * PDUSessionResourceSwitchedItem;
} SI_AMF_DT_PDUSessionResourceSwitchedList;


// PathSwitchRequestAcknowledgeTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PathSwitchRequestAcknowledgeTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr;

// PDUSessionResourceSwitchedItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceSwitchedItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr * pathSwitchRequestAcknowledgeTransfer;

} SI_AMF_DT_PDUSessionResourceSwitchedItem;


// PDUSessionResourceSwitchedItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceSwitchedItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs;


// PDUSessionResourceToBeSwitchedDLList
//SEQUENCE OF PDUSessionResourceToBeSwitchedDLItem, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceToBeSwitchedDLList
{
	SI_LinkedList * PDUSessionResourceToBeSwitchedDLItem;
} SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList;


// PathSwitchRequestTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PathSwitchRequestTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PathSwitchRequestTransferOctStr;

// PDUSessionResourceToBeSwitchedDLItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceToBeSwitchedDLItem
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PathSwitchRequestTransferOctStr * pathSwitchRequestTransfer;

} SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem;


// PDUSessionResourceToBeSwitchedDLItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceToBeSwitchedDLItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs;


// PDUSessionResourceToReleaseListHOCmd
//SEQUENCE OF PDUSessionResourceToReleaseItemHOCmd, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceToReleaseListHOCmd
{
	SI_LinkedList * PDUSessionResourceToReleaseItemHOCmd;
} SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd;


// HandoverPreparationUnsuccessfulTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_HandoverPreparationUnsuccessfulTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr;

// PDUSessionResourceToReleaseItemHOCmd
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceToReleaseItemHOCmd
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr * handoverPreparationUnsuccessfulTransfer;

} SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd;


// PDUSessionResourceToReleaseItemHOCmd-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceToReleaseItemHOCmd_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs;


// PDUSessionResourceToReleaseListRelCmd
//SEQUENCE OF PDUSessionResourceToReleaseItemRelCmd, MIN=1, MAX=maxnoofPDUSessions  ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceToReleaseListRelCmd
{
	SI_LinkedList * PDUSessionResourceToReleaseItemRelCmd;
} SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd;


// PDUSessionResourceReleaseCommandTransferOctStr
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_PDUSessionResourceReleaseCommandTransferOctStr
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr;

// PDUSessionResourceToReleaseItemRelCmd
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PDUSessionResourceToReleaseItemRelCmd
{
	unsigned long long int pDUSessionID;

	SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr * pDUSessionResourceReleaseCommandTransfer;

} SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd;


// PDUSessionResourceToReleaseItemRelCmd-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionResourceToReleaseItemRelCmd_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs;


// PDUSessionType
// ADT=0  DT=1
typedef enum __si_amf_dt_PDUSessionType
{
	PDUSessionType_ipv4_val,
	PDUSessionType_ipv6_val,
	PDUSessionType_ipv4v6_val,
	PDUSessionType_ethernet_val,
	PDUSessionType_unstructured_val
} SI_AMF_DT_PDUSessionType;


// PDUSessionUsageReport-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PDUSessionUsageReport_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PDUSessionUsageReport_ExtIEs;


// PLMNSupportList
//SEQUENCE OF PLMNSupportItem, MIN=1, MAX=maxnoofPLMNs  ADT=0  DT=2
typedef struct __si_amf_dt_PLMNSupportList
{
	SI_LinkedList * PLMNSupportItem;
} SI_AMF_DT_PLMNSupportList;


// PLMNSupportItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_PLMNSupportItem
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_SliceSupportList * sliceSupportList;

} SI_AMF_DT_PLMNSupportItem;


// PLMNSupportItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_PLMNSupportItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PLMNSupportItem_ExtIEs;


// PWSFailedCellIDList
// ADT=0  DT=1
typedef struct __si_amf_dt_PWSFailedCellIDList
{
	union 
	{
		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EUTRA_CGIList * eUTRA_CGI_PWSFailedList;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_NR_CGIList * nR_CGI_PWSFailedList;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_PWSFailedCellIDList;


// PWSFailedCellIDList-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_PWSFailedCellIDList_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_PWSFailedCellIDList_ExtIEs;


// QosCharacteristics
// ADT=0  DT=1
typedef struct __si_amf_dt_QosCharacteristics
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_NonDynamic5QIDescriptor * nonDynamic5QI;

		// ParserName = SEQUENCE;
		SI_AMF_DT_Dynamic5QIDescriptor * dynamic5QI;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_QosCharacteristics;


// QosCharacteristics-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_QosCharacteristics_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosCharacteristics_ExtIEs;


// QosFlowAcceptedItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowAcceptedItem
{
	unsigned long long int qosFlowIdentifier;

} SI_AMF_DT_QosFlowAcceptedItem;


// QosFlowAcceptedItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowAcceptedItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowAcceptedItem_ExtIEs;


// ReflectiveQosAttribute
// ADT=0  DT=1
typedef enum __si_amf_dt_ReflectiveQosAttribute
{
	ReflectiveQosAttribute_subject_to_val
} SI_AMF_DT_ReflectiveQosAttribute;


// QosFlowLevelQosParameters
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowLevelQosParameters
{
	SI_AMF_DT_QosCharacteristics * qosCharacteristics;

	SI_AMF_DT_AllocationAndRetentionPriority * allocationAndRetentionPriority;

	SI_AMF_DT_GBR_QosInformation * gBR_QosInformation;
	int isPresent_gBR_QosInformation;

	uint8_t selected_ereflectiveQosAttribute;
	int extSelected_ereflectiveQosAttribute;
	int isPresent_reflectiveQosAttribute;

	uint8_t selected_eadditionalQosFlowInformation;
	int extSelected_eadditionalQosFlowInformation;
	int isPresent_additionalQosFlowInformation;

} SI_AMF_DT_QosFlowLevelQosParameters;


// QosFlowAddOrModifyRequestItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowAddOrModifyRequestItem
{
	unsigned long long int qosFlowIdentifier;

	SI_AMF_DT_QosFlowLevelQosParameters * qosFlowLevelQosParameters;
	int isPresent_qosFlowLevelQosParameters;

	unsigned long long int e_RAB_ID;
	int isPresent_e_RAB_ID;

} SI_AMF_DT_QosFlowAddOrModifyRequestItem;


// QosFlowAddOrModifyRequestItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowAddOrModifyRequestItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs;


// QosFlowAddOrModifyResponseItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowAddOrModifyResponseItem
{
	unsigned long long int qosFlowIdentifier;

} SI_AMF_DT_QosFlowAddOrModifyResponseItem;


// QosFlowAddOrModifyResponseItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowAddOrModifyResponseItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs;


// QosFlowInformationItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowInformationItem
{
	unsigned long long int qosFlowIdentifier;

	uint8_t selected_edLForwarding;
	int extSelected_edLForwarding;
	int isPresent_dLForwarding;

} SI_AMF_DT_QosFlowInformationItem;


// ULForwarding
// ADT=0  DT=1
typedef enum __si_amf_dt_ULForwarding
{
	ULForwarding_ul_forwarding_proposed_val
} SI_AMF_DT_ULForwarding;


// QosFlowInformationItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowInformationItem_ExtIEs
{
	// Got Success L:2926
	//ULForwarding,  optional
	int selected_euLForwarding;
	int isPresent_uLForwarding;

} SI_AMF_DT_QosFlowInformationItem_ExtIEs;


// QosFlowLevelQosParameters-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowLevelQosParameters_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs;


// QosFlowWithCauseItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowWithCauseItem
{
	unsigned long long int qosFlowIdentifier;

	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_QosFlowWithCauseItem;


// QosFlowWithCauseItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowWithCauseItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowWithCauseItem_ExtIEs;


// QosFlowModifyConfirmItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowModifyConfirmItem
{
	unsigned long long int qosFlowIdentifier;

} SI_AMF_DT_QosFlowModifyConfirmItem;


// QosFlowModifyConfirmItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowModifyConfirmItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs;


// QosFlowNotifyItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowNotifyItem
{
	unsigned long long int qosFlowIdentifier;

	uint8_t selected_enotificationCause;
	int extSelected_enotificationCause;

} SI_AMF_DT_QosFlowNotifyItem;


// QosFlowNotifyItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowNotifyItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowNotifyItem_ExtIEs;


// QosFlowPerTNLInformation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowPerTNLInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs;


// QosFlowPerTNLInformationItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowPerTNLInformationItem
{
	SI_AMF_DT_QosFlowPerTNLInformation * qosFlowPerTNLInformation;

} SI_AMF_DT_QosFlowPerTNLInformationItem;


// QosFlowPerTNLInformationItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowPerTNLInformationItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs;


// QosFlowSetupRequestList
//SEQUENCE OF QosFlowSetupRequestItem, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowSetupRequestList
{
	SI_LinkedList * QosFlowSetupRequestItem;
} SI_AMF_DT_QosFlowSetupRequestList;


// QosFlowSetupRequestItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowSetupRequestItem
{
	unsigned long long int qosFlowIdentifier;

	SI_AMF_DT_QosFlowLevelQosParameters * qosFlowLevelQosParameters;

	unsigned long long int e_RAB_ID;
	int isPresent_e_RAB_ID;

} SI_AMF_DT_QosFlowSetupRequestItem;


// QosFlowSetupRequestItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowSetupRequestItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs;


// QosFlowItemWithDataForwarding
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowItemWithDataForwarding
{
	unsigned long long int qosFlowIdentifier;

	uint8_t selected_edataForwardingAccepted;
	int extSelected_edataForwardingAccepted;
	int isPresent_dataForwardingAccepted;

} SI_AMF_DT_QosFlowItemWithDataForwarding;


// QosFlowItemWithDataForwarding-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowItemWithDataForwarding_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs;


// QosFlowSetupResponseListSURes
//SEQUENCE OF QosFlowSetupResponseItemSURes, MIN=1, MAX=maxnoofQosFlows  ADT=0  DT=2
typedef struct __si_amf_dt_QosFlowSetupResponseListSURes
{
	SI_LinkedList * QosFlowSetupResponseItemSURes;
} SI_AMF_DT_QosFlowSetupResponseListSURes;


// QosFlowSetupResponseItemSURes
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowSetupResponseItemSURes
{
	unsigned long long int qosFlowIdentifier;

} SI_AMF_DT_QosFlowSetupResponseItemSURes;


// QosFlowSetupResponseItemSURes-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowSetupResponseItemSURes_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs;


// QosFlowToBeForwardedItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QosFlowToBeForwardedItem
{
	unsigned long long int qosFlowIdentifier;

} SI_AMF_DT_QosFlowToBeForwardedItem;


// QosFlowToBeForwardedItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QosFlowToBeForwardedItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs;


// QoSFlowsUsageReport-ItemRatType
// ADT=0  DT=1
typedef enum __si_amf_dt_QoSFlowsUsageReport_ItemRatType
{
	QoSFlowsUsageReport_ItemRatType_nr_val,
	QoSFlowsUsageReport_ItemRatType_eutra_val
} SI_AMF_DT_QoSFlowsUsageReport_ItemRatType;


// QoSFlowsUsageReport-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_QoSFlowsUsageReport_Item
{
	unsigned long long int qosFlowIdentifier;

	uint8_t selected_erATType;
	int extSelected_erATType;

	SI_AMF_DT_VolumeTimedReportList * qoSFlowsTimedReportList;

} SI_AMF_DT_QoSFlowsUsageReport_Item;


// QoSFlowsUsageReport-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_QoSFlowsUsageReport_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs;


// RANNodeName
// PrintableString,PrintableString(SIZE(1..150,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_RANNodeName
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_RANNodeName;

// RANPagingPriority
// INTEGER,INTEGER(1..256),MIN=1,MAX=256
// ADT=0  DT=2
typedef struct __si_amf_dt_RANPagingPriority
{
	unsigned long long int data;
} SI_AMF_DT_RANPagingPriority;

// RANStatusTransfer-TransparentContainer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_RANStatusTransfer_TransparentContainer
{
	SI_AMF_DT_DRBsSubjectToStatusTransferList * dRBsSubjectToStatusTransferList;

} SI_AMF_DT_RANStatusTransfer_TransparentContainer;


// RANStatusTransfer-TransparentContainer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_RANStatusTransfer_TransparentContainer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs;


// RAN-UE-NGAP-ID
// INTEGER,INTEGER(0..4294967295),MIN=0,MAX=4294967295
// ADT=0  DT=2
typedef struct __si_amf_dt_RAN_UE_NGAP_ID
{
	unsigned long long int data;
} SI_AMF_DT_RAN_UE_NGAP_ID;

// RATRestrictionInformation
// BITSTRING,BIT STRING(SIZE(8,...))
// ADT=0  DT=2
typedef struct __si_amf_dt_RATRestrictionInformation
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_RATRestrictionInformation;

// RATRestrictions-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_RATRestrictions_Item
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_RATRestrictionInformation * rATRestrictionInformation;

} SI_AMF_DT_RATRestrictions_Item;


// RATRestrictions-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_RATRestrictions_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_RATRestrictions_Item_ExtIEs;


// RecommendedCellsForPaging-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_RecommendedCellsForPaging_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_RecommendedCellsForPaging_ExtIEs;


// RecommendedCellItemTime
// INTEGER,INTEGER(0..4095),MIN=0,MAX=4095
// ADT=0  DT=2
typedef struct __si_amf_dt_RecommendedCellItemTime
{
	unsigned long long int data;
} SI_AMF_DT_RecommendedCellItemTime;

// RecommendedCellItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_RecommendedCellItem
{
	SI_AMF_DT_NGRAN_CGI * nGRAN_CGI;

	unsigned long long int timeStayedInCell;
	int isPresent_timeStayedInCell;

} SI_AMF_DT_RecommendedCellItem;


// RecommendedCellItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_RecommendedCellItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_RecommendedCellItem_ExtIEs;


// RecommendedRANNodesForPaging-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_RecommendedRANNodesForPaging_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs;


// RecommendedRANNodeItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_RecommendedRANNodeItem
{
	SI_AMF_DT_AMFPagingTarget * aMFPagingTarget;

} SI_AMF_DT_RecommendedRANNodeItem;


// RecommendedRANNodeItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_RecommendedRANNodeItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_RecommendedRANNodeItem_ExtIEs;


// ReferenceID
// INTEGER,INTEGER(1..64,...),MIN=1,MAX=64
// ADT=0  DT=2
typedef struct __si_amf_dt_ReferenceID
{
	unsigned long long int data;
} SI_AMF_DT_ReferenceID;

// RelativeAMFCapacity
// INTEGER,INTEGER(0..255),MIN=0,MAX=255
// ADT=0  DT=2
typedef struct __si_amf_dt_RelativeAMFCapacity
{
	unsigned long long int data;
} SI_AMF_DT_RelativeAMFCapacity;

// RepetitionPeriod
// INTEGER,INTEGER(0..131071),MIN=0,MAX=131071
// ADT=0  DT=2
typedef struct __si_amf_dt_RepetitionPeriod
{
	unsigned long long int data;
} SI_AMF_DT_RepetitionPeriod;

// ResetAll
// ADT=0  DT=1
typedef enum __si_amf_dt_ResetAll
{
	ResetAll_reset_all_val
} SI_AMF_DT_ResetAll;


// UE-associatedLogicalNG-connectionList
//SEQUENCE OF UE-associatedLogicalNG-connectionItem, MIN=1, MAX=maxnoofNGConnectionsToReset  ADT=0  DT=2
typedef struct __si_amf_dt_UE_associatedLogicalNG_connectionList
{
	SI_LinkedList * UE_associatedLogicalNG_connectionItem;
} SI_AMF_DT_UE_associatedLogicalNG_connectionList;


// ResetType
// ADT=0  DT=1
typedef struct __si_amf_dt_ResetType
{
	union 
	{
		// ParserName = ENUMERATED;
		uint8_t nG_Interface;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_UE_associatedLogicalNG_connectionList * partOfNG_Interface;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_ResetType;


// ResetType-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_ResetType_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ResetType_ExtIEs;


// RoutingID
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_RoutingID
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_RoutingID;

// RRCContainer
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_RRCContainer
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_RRCContainer;

// RRCEstablishmentCause
// ADT=0  DT=1
typedef enum __si_amf_dt_RRCEstablishmentCause
{
	RRCEstablishmentCause_emergency_val,
	RRCEstablishmentCause_highPriorityAccess_val,
	RRCEstablishmentCause_mt_Access_val,
	RRCEstablishmentCause_mo_Signalling_val,
	RRCEstablishmentCause_mo_Data_val,
	RRCEstablishmentCause_mo_VoiceCall_val,
	RRCEstablishmentCause_mo_VideoCall_val,
	RRCEstablishmentCause_mo_SMS_val,
	RRCEstablishmentCause_mps_PriorityAccess_val,
	RRCEstablishmentCause_mcs_PriorityAccess_val,
	RRCEstablishmentCause_notAvailable_val_ext
} SI_AMF_DT_RRCEstablishmentCause;


// RRCInactiveTransitionReportRequest
// ADT=0  DT=1
typedef enum __si_amf_dt_RRCInactiveTransitionReportRequest
{
	RRCInactiveTransitionReportRequest_subsequent_state_transition_report_val,
	RRCInactiveTransitionReportRequest_single_rrc_connected_state_report_val,
	RRCInactiveTransitionReportRequest_cancel_report_val
} SI_AMF_DT_RRCInactiveTransitionReportRequest;


// RRCState
// ADT=0  DT=1
typedef enum __si_amf_dt_RRCState
{
	RRCState_inactive_val,
	RRCState_connected_val
} SI_AMF_DT_RRCState;


// SCTP-TLAs
//SEQUENCE OF TransportLayerAddress, MIN=1, MAX=maxnoofXnTLAs  ADT=0  DT=2
typedef struct __si_amf_dt_SCTP_TLAs
{
	SI_LinkedList * TransportLayerAddress;
} SI_AMF_DT_SCTP_TLAs;


// SecondaryRATUsageInformation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SecondaryRATUsageInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs;


// SecondaryRATDataUsageReportTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SecondaryRATDataUsageReportTransfer
{
	SI_AMF_DT_SecondaryRATUsageInformation * secondaryRATUsageInformation;
	int isPresent_secondaryRATUsageInformation;

} SI_AMF_DT_SecondaryRATDataUsageReportTransfer;


// SecondaryRATDataUsageReportTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SecondaryRATDataUsageReportTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs;


// SecurityKey
// BITSTRING,BIT STRING(SIZE(256))
// ADT=0  DT=2
typedef struct __si_amf_dt_SecurityKey
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_SecurityKey;

// SecurityContext
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SecurityContext
{
	unsigned long long int nextHopChainingCount;

	SI_AMF_DT_SecurityKey * nextHopNH;

} SI_AMF_DT_SecurityContext;


// SecurityContext-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SecurityContext_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SecurityContext_ExtIEs;


// SecurityIndication-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SecurityIndication_ExtIEs
{
	// Got Success L:2926
	//MaximumIntegrityProtectedDataRate,  optional
	int selected_emaximumIntegrityProtectedDataRateDL;
	int isPresent_maximumIntegrityProtectedDataRateDL;

} SI_AMF_DT_SecurityIndication_ExtIEs;


// SecurityResult-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SecurityResult_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SecurityResult_ExtIEs;


// SerialNumber
// BITSTRING,BIT STRING(SIZE(16))
// ADT=0  DT=2
typedef struct __si_amf_dt_SerialNumber
{
	unsigned char * data;
	unsigned int length;
	int bitslen;
} SI_AMF_DT_SerialNumber;

// ServedGUAMIList
//SEQUENCE OF ServedGUAMIItem, MIN=1, MAX=maxnoofServedGUAMIs  ADT=0  DT=2
typedef struct __si_amf_dt_ServedGUAMIList
{
	SI_LinkedList * ServedGUAMIItem;
} SI_AMF_DT_ServedGUAMIList;


// ServedGUAMIItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_ServedGUAMIItem
{
	SI_AMF_DT_GUAMI * gUAMI;

	SI_AMF_DT_AMFName * backupAMFName;
	int isPresent_backupAMFName;

} SI_AMF_DT_ServedGUAMIItem;


// ServedGUAMIItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_ServedGUAMIItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ServedGUAMIItem_ExtIEs;


// ServiceAreaInformation-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_ServiceAreaInformation_Item
{
	SI_AMF_DT_PLMNIdentity * pLMNIdentity;

	SI_AMF_DT_AllowedTACs * allowedTACs;
	int isPresent_allowedTACs;

	SI_AMF_DT_NotAllowedTACs * notAllowedTACs;
	int isPresent_notAllowedTACs;

} SI_AMF_DT_ServiceAreaInformation_Item;


// ServiceAreaInformation-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_ServiceAreaInformation_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs;


// SliceOverloadItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SliceOverloadItem
{
	SI_AMF_DT_S_NSSAI * s_NSSAI;

} SI_AMF_DT_SliceOverloadItem;


// SliceOverloadItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SliceOverloadItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SliceOverloadItem_ExtIEs;


// SliceSupportItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SliceSupportItem
{
	SI_AMF_DT_S_NSSAI * s_NSSAI;

} SI_AMF_DT_SliceSupportItem;


// SliceSupportItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SliceSupportItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SliceSupportItem_ExtIEs;


// S-NSSAI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_S_NSSAI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_S_NSSAI_ExtIEs;


// TargetRANNodeID
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TargetRANNodeID
{
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;

	SI_AMF_DT_TAI * selectedTAI;

} SI_AMF_DT_TargetRANNodeID;


// SourceRANNodeID
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SourceRANNodeID
{
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;

	SI_AMF_DT_TAI * selectedTAI;

} SI_AMF_DT_SourceRANNodeID;


// SONInformationRequest
// ADT=0  DT=1
typedef enum __si_amf_dt_SONInformationRequest
{
	SONInformationRequest_xn_TNL_configuration_info_val
} SI_AMF_DT_SONInformationRequest;


// XnTLAs
//SEQUENCE OF TransportLayerAddress, MIN=1, MAX=maxnoofXnTLAs  ADT=0  DT=2
typedef struct __si_amf_dt_XnTLAs
{
	SI_LinkedList * TransportLayerAddress;
} SI_AMF_DT_XnTLAs;


// XnExtTLAs
//SEQUENCE OF XnExtTLA-Item, MIN=1, MAX=maxnoofXnExtTLAs  ADT=0  DT=2
typedef struct __si_amf_dt_XnExtTLAs
{
	SI_LinkedList * XnExtTLA_Item;
} SI_AMF_DT_XnExtTLAs;


// XnTNLConfigurationInfo
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_XnTNLConfigurationInfo
{
	SI_AMF_DT_XnTLAs * xnTransportLayerAddresses;

	SI_AMF_DT_XnExtTLAs * xnExtendedTransportLayerAddresses;
	int isPresent_xnExtendedTransportLayerAddresses;

} SI_AMF_DT_XnTNLConfigurationInfo;


// SONInformationReply
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SONInformationReply
{
	SI_AMF_DT_XnTNLConfigurationInfo * xnTNLConfigurationInfo;
	int isPresent_xnTNLConfigurationInfo;

} SI_AMF_DT_SONInformationReply;


// SONInformation
// ADT=0  DT=1
typedef struct __si_amf_dt_SONInformation
{
	union 
	{
		// ParserName = ENUMERATED;
		uint8_t sONInformationRequest;

		// ParserName = SEQUENCE;
		SI_AMF_DT_SONInformationReply * sONInformationReply;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_SONInformation;


// SONConfigurationTransfer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SONConfigurationTransfer
{
	SI_AMF_DT_TargetRANNodeID * targetRANNodeID;

	SI_AMF_DT_SourceRANNodeID * sourceRANNodeID;

	SI_AMF_DT_SONInformation * sONInformation;

	SI_AMF_DT_XnTNLConfigurationInfo * xnTNLConfigurationInfo;
	int isPresent_xnTNLConfigurationInfo;

} SI_AMF_DT_SONConfigurationTransfer;


// SONConfigurationTransfer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SONConfigurationTransfer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SONConfigurationTransfer_ExtIEs;


// SONInformation-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_SONInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SONInformation_ExtIEs;


// SONInformationReply-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SONInformationReply_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SONInformationReply_ExtIEs;


// UEHistoryInformation
//SEQUENCE OF LastVisitedCellItem, MIN=1, MAX=maxnoofCellsinUEHistoryInfo  ADT=0  DT=2
typedef struct __si_amf_dt_UEHistoryInformation
{
	SI_LinkedList * LastVisitedCellItem;
} SI_AMF_DT_UEHistoryInformation;


// SourceNGRANNode-ToTargetNGRANNode-TransparentContainer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer
{
	SI_AMF_DT_RRCContainer * rRCContainer;

	SI_AMF_DT_PDUSessionResourceInformationList * pDUSessionResourceInformationList;
	int isPresent_pDUSessionResourceInformationList;

	SI_AMF_DT_E_RABInformationList * e_RABInformationList;
	int isPresent_e_RABInformationList;

	SI_AMF_DT_NGRAN_CGI * targetCell_ID;

	unsigned long long int indexToRFSP;
	int isPresent_indexToRFSP;

	SI_AMF_DT_UEHistoryInformation * uEHistoryInformation;

} SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer;


// SourceNGRANNode-ToTargetNGRANNode-TransparentContainer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs;


// SourceRANNodeID-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SourceRANNodeID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SourceRANNodeID_ExtIEs;


// SourceToTarget-TransparentContainer
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_SourceToTarget_TransparentContainer
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_SourceToTarget_TransparentContainer;

// ConfiguredNSSAI
// OCTETSTRING,OCTET STRING(SIZE(128))
// ADT=0  DT=2
typedef struct __si_amf_dt_ConfiguredNSSAI
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_ConfiguredNSSAI;

// RejectedNSSAIinPLMN
// OCTETSTRING,OCTET STRING(SIZE(32))
// ADT=0  DT=2
typedef struct __si_amf_dt_RejectedNSSAIinPLMN
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_RejectedNSSAIinPLMN;

// RejectedNSSAIinTA
// OCTETSTRING,OCTET STRING(SIZE(32))
// ADT=0  DT=2
typedef struct __si_amf_dt_RejectedNSSAIinTA
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_RejectedNSSAIinTA;

// SourceToTarget-AMFInformationReroute
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SourceToTarget_AMFInformationReroute
{
	SI_AMF_DT_ConfiguredNSSAI * configuredNSSAI;
	int isPresent_configuredNSSAI;

	SI_AMF_DT_RejectedNSSAIinPLMN * rejectedNSSAIinPLMN;
	int isPresent_rejectedNSSAIinPLMN;

	SI_AMF_DT_RejectedNSSAIinTA * rejectedNSSAIinTA;
	int isPresent_rejectedNSSAIinTA;

} SI_AMF_DT_SourceToTarget_AMFInformationReroute;


// SourceToTarget-AMFInformationReroute-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SourceToTarget_AMFInformationReroute_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs;


// SupportedTAList
//SEQUENCE OF SupportedTAItem, MIN=1, MAX=maxnoofTACs  ADT=0  DT=2
typedef struct __si_amf_dt_SupportedTAList
{
	SI_LinkedList * SupportedTAItem;
} SI_AMF_DT_SupportedTAList;


// SupportedTAItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_SupportedTAItem
{
	SI_AMF_DT_TAC * tAC;

	SI_AMF_DT_BroadcastPLMNList * broadcastPLMNList;

} SI_AMF_DT_SupportedTAItem;


// SupportedTAItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_SupportedTAItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_SupportedTAItem_ExtIEs;


// TAI-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAI_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAI_ExtIEs;


// TAIBroadcastEUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAIBroadcastEUTRA_Item
{
	SI_AMF_DT_TAI * tAI;

	SI_AMF_DT_CompletedCellsInTAI_EUTRA * completedCellsInTAI_EUTRA;

} SI_AMF_DT_TAIBroadcastEUTRA_Item;


// TAIBroadcastEUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAIBroadcastEUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs;


// TAIBroadcastNR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAIBroadcastNR_Item
{
	SI_AMF_DT_TAI * tAI;

	SI_AMF_DT_CompletedCellsInTAI_NR * completedCellsInTAI_NR;

} SI_AMF_DT_TAIBroadcastNR_Item;


// TAIBroadcastNR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAIBroadcastNR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs;


// TAICancelledEUTRA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAICancelledEUTRA_Item
{
	SI_AMF_DT_TAI * tAI;

	SI_AMF_DT_CancelledCellsInTAI_EUTRA * cancelledCellsInTAI_EUTRA;

} SI_AMF_DT_TAICancelledEUTRA_Item;


// TAICancelledEUTRA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAICancelledEUTRA_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs;


// TAICancelledNR-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAICancelledNR_Item
{
	SI_AMF_DT_TAI * tAI;

	SI_AMF_DT_CancelledCellsInTAI_NR * cancelledCellsInTAI_NR;

} SI_AMF_DT_TAICancelledNR_Item;


// TAICancelledNR-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAICancelledNR_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAICancelledNR_Item_ExtIEs;


// TAIListForInactiveItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAIListForInactiveItem
{
	SI_AMF_DT_TAI * tAI;

} SI_AMF_DT_TAIListForInactiveItem;


// TAIListForInactiveItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAIListForInactiveItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAIListForInactiveItem_ExtIEs;


// TAIListForPaging
//SEQUENCE OF TAIListForPagingItem, MIN=1, MAX=maxnoofTAIforPaging  ADT=0  DT=2
typedef struct __si_amf_dt_TAIListForPaging
{
	SI_LinkedList * TAIListForPagingItem;
} SI_AMF_DT_TAIListForPaging;


// TAIListForPagingItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TAIListForPagingItem
{
	SI_AMF_DT_TAI * tAI;

} SI_AMF_DT_TAIListForPagingItem;


// TAIListForPagingItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TAIListForPagingItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TAIListForPagingItem_ExtIEs;


// TAIListForRestart
//SEQUENCE OF TAI, MIN=1, MAX=maxnoofTAIforRestart  ADT=0  DT=2
typedef struct __si_amf_dt_TAIListForRestart
{
	SI_LinkedList * TAI;
} SI_AMF_DT_TAIListForRestart;


// TAIListForWarning
//SEQUENCE OF TAI, MIN=1, MAX=maxnoofTAIforWarning  ADT=0  DT=2
typedef struct __si_amf_dt_TAIListForWarning
{
	SI_LinkedList * TAI;
} SI_AMF_DT_TAIListForWarning;


// TargeteNB-ID
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TargeteNB_ID
{
	SI_AMF_DT_GlobalNgENB_ID * globalENB_ID;

	SI_AMF_DT_EPS_TAI * selected_EPS_TAI;

} SI_AMF_DT_TargeteNB_ID;


// TargeteNB-ID-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TargeteNB_ID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TargeteNB_ID_ExtIEs;


// TargetID
// ADT=0  DT=1
typedef struct __si_amf_dt_TargetID
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_TargetRANNodeID * targetRANNodeID;

		// ParserName = SEQUENCE;
		SI_AMF_DT_TargeteNB_ID * targeteNB_ID;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_TargetID;


// TargetID-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_TargetID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TargetID_ExtIEs;


// TargetNGRANNode-ToSourceNGRANNode-TransparentContainer
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer
{
	SI_AMF_DT_RRCContainer * rRCContainer;

} SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer;


// TargetNGRANNode-ToSourceNGRANNode-TransparentContainer-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs;


// TargetRANNodeID-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TargetRANNodeID_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TargetRANNodeID_ExtIEs;


// TargetToSource-TransparentContainer
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_TargetToSource_TransparentContainer
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_TargetToSource_TransparentContainer;

// TimerApproachForGUAMIRemoval
// ADT=0  DT=1
typedef enum __si_amf_dt_TimerApproachForGUAMIRemoval
{
	TimerApproachForGUAMIRemoval_apply_timer_val
} SI_AMF_DT_TimerApproachForGUAMIRemoval;


// TimeStamp
// OCTETSTRING,OCTET STRING(SIZE(4))
// ADT=0  DT=2
typedef struct __si_amf_dt_TimeStamp
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_TimeStamp;

// TimeToWait
// ADT=0  DT=1
typedef enum __si_amf_dt_TimeToWait
{
	TimeToWait_v1s_val,
	TimeToWait_v2s_val,
	TimeToWait_v5s_val,
	TimeToWait_v10s_val,
	TimeToWait_v20s_val,
	TimeToWait_v60s_val
} SI_AMF_DT_TimeToWait;


// TNLAssociationList
//SEQUENCE OF TNLAssociationItem, MIN=1, MAX=maxnoofTNLAssociations  ADT=0  DT=2
typedef struct __si_amf_dt_TNLAssociationList
{
	SI_LinkedList * TNLAssociationItem;
} SI_AMF_DT_TNLAssociationList;


// TNLAssociationItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TNLAssociationItem
{
	SI_AMF_DT_CPTransportLayerInformation * tNLAssociationAddress;

	SI_AMF_DT_Cause * cause;

} SI_AMF_DT_TNLAssociationItem;


// TNLAssociationItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TNLAssociationItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TNLAssociationItem_ExtIEs;


// TraceDepth
// ADT=0  DT=1
typedef enum __si_amf_dt_TraceDepth
{
	TraceDepth_minimum_val,
	TraceDepth_medium_val,
	TraceDepth_maximum_val,
	TraceDepth_minimumWithoutVendorSpecificExtension_val,
	TraceDepth_mediumWithoutVendorSpecificExtension_val,
	TraceDepth_maximumWithoutVendorSpecificExtension_val
} SI_AMF_DT_TraceDepth;


// TraceActivation
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_TraceActivation
{
	SI_AMF_DT_NGRANTraceID * nGRANTraceID;

	SI_AMF_DT_InterfacesToTrace * interfacesToTrace;

	uint8_t selected_etraceDepth;
	int extSelected_etraceDepth;

	SI_AMF_DT_TransportLayerAddress * traceCollectionEntityIPAddress;

} SI_AMF_DT_TraceActivation;


// TraceActivation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_TraceActivation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_TraceActivation_ExtIEs;


// UEAggregateMaximumBitRate
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UEAggregateMaximumBitRate
{
	unsigned long long int uEAggregateMaximumBitRateDL;

	unsigned long long int uEAggregateMaximumBitRateUL;

} SI_AMF_DT_UEAggregateMaximumBitRate;


// UEAggregateMaximumBitRate-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UEAggregateMaximumBitRate_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs;


// UE-associatedLogicalNG-connectionItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UE_associatedLogicalNG_connectionItem
{
	unsigned long long int aMF_UE_NGAP_ID;
	int isPresent_aMF_UE_NGAP_ID;

	unsigned long long int rAN_UE_NGAP_ID;
	int isPresent_rAN_UE_NGAP_ID;

} SI_AMF_DT_UE_associatedLogicalNG_connectionItem;


// UE-associatedLogicalNG-connectionItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UE_associatedLogicalNG_connectionItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs;


// UEContextRequest
// ADT=0  DT=1
typedef enum __si_amf_dt_UEContextRequest
{
	UEContextRequest_requested_val
} SI_AMF_DT_UEContextRequest;


// UEIdentityIndexValue-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_UEIdentityIndexValue_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UEIdentityIndexValue_ExtIEs;


// UE-NGAP-ID-pair
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UE_NGAP_ID_pair
{
	unsigned long long int aMF_UE_NGAP_ID;

	unsigned long long int rAN_UE_NGAP_ID;

} SI_AMF_DT_UE_NGAP_ID_pair;


// UE-NGAP-IDs
// ADT=0  DT=1
typedef struct __si_amf_dt_UE_NGAP_IDs
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_UE_NGAP_ID_pair * uE_NGAP_ID_pair;

		// ParserName = INTEGER;
		unsigned long long int aMF_UE_NGAP_ID;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_UE_NGAP_IDs;


// UE-NGAP-IDs-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_UE_NGAP_IDs_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UE_NGAP_IDs_ExtIEs;


// UE-NGAP-ID-pair-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UE_NGAP_ID_pair_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs;


// UEPagingIdentity
// ADT=0  DT=1
typedef struct __si_amf_dt_UEPagingIdentity
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_FiveG_S_TMSI * fiveG_S_TMSI;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_UEPagingIdentity;


// UEPagingIdentity-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_UEPagingIdentity_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UEPagingIdentity_ExtIEs;


// UEPresence
// ADT=0  DT=1
typedef enum __si_amf_dt_UEPresence
{
	UEPresence_in_val,
	UEPresence_out_val,
	UEPresence_unknown_val
} SI_AMF_DT_UEPresence;


// UEPresenceInAreaOfInterestList
//SEQUENCE OF UEPresenceInAreaOfInterestItem, MIN=1, MAX=maxnoofAoI  ADT=0  DT=2
typedef struct __si_amf_dt_UEPresenceInAreaOfInterestList
{
	SI_LinkedList * UEPresenceInAreaOfInterestItem;
} SI_AMF_DT_UEPresenceInAreaOfInterestList;


// UEPresenceInAreaOfInterestItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UEPresenceInAreaOfInterestItem
{
	unsigned long long int locationReportingReferenceID;

	uint8_t selected_euEPresence;
	int extSelected_euEPresence;

} SI_AMF_DT_UEPresenceInAreaOfInterestItem;


// UEPresenceInAreaOfInterestItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UEPresenceInAreaOfInterestItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs;


// UERadioCapability
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_UERadioCapability
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_UERadioCapability;

// UERadioCapabilityForPagingOfNR
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_UERadioCapabilityForPagingOfNR
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_UERadioCapabilityForPagingOfNR;

// UERadioCapabilityForPagingOfEUTRA
// OCTETSTRING,OCTET STRING
// ADT=0  DT=2
typedef struct __si_amf_dt_UERadioCapabilityForPagingOfEUTRA
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA;

// UERadioCapabilityForPaging
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UERadioCapabilityForPaging
{
	SI_AMF_DT_UERadioCapabilityForPagingOfNR * uERadioCapabilityForPagingOfNR;
	int isPresent_uERadioCapabilityForPagingOfNR;

	SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA * uERadioCapabilityForPagingOfEUTRA;
	int isPresent_uERadioCapabilityForPagingOfEUTRA;

} SI_AMF_DT_UERadioCapabilityForPaging;


// UERadioCapabilityForPaging-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UERadioCapabilityForPaging_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs;


// UERetentionInformation
// ADT=0  DT=1
typedef enum __si_amf_dt_UERetentionInformation
{
	UERetentionInformation_ues_retained_val
} SI_AMF_DT_UERetentionInformation;


// UESecurityCapabilities
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UESecurityCapabilities
{
	SI_AMF_DT_NRencryptionAlgorithms * nRencryptionAlgorithms;

	SI_AMF_DT_NRintegrityProtectionAlgorithms * nRintegrityProtectionAlgorithms;

	SI_AMF_DT_EUTRAencryptionAlgorithms * eUTRAencryptionAlgorithms;

	SI_AMF_DT_EUTRAintegrityProtectionAlgorithms * eUTRAintegrityProtectionAlgorithms;

} SI_AMF_DT_UESecurityCapabilities;


// UESecurityCapabilities-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UESecurityCapabilities_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UESecurityCapabilities_ExtIEs;


// UL-NGU-UP-TNLModifyItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UL_NGU_UP_TNLModifyItem
{
	SI_AMF_DT_UPTransportLayerInformation * uL_NGU_UP_TNLInformation;

	SI_AMF_DT_UPTransportLayerInformation * dL_NGU_UP_TNLInformation;

} SI_AMF_DT_UL_NGU_UP_TNLModifyItem;


// UL-NGU-UP-TNLModifyItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UL_NGU_UP_TNLModifyItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs;


// UnavailableGUAMIList
//SEQUENCE OF UnavailableGUAMIItem, MIN=1, MAX=maxnoofServedGUAMIs  ADT=0  DT=2
typedef struct __si_amf_dt_UnavailableGUAMIList
{
	SI_LinkedList * UnavailableGUAMIItem;
} SI_AMF_DT_UnavailableGUAMIList;


// UnavailableGUAMIItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UnavailableGUAMIItem
{
	SI_AMF_DT_GUAMI * gUAMI;

	uint8_t selected_etimerApproachForGUAMIRemoval;
	int extSelected_etimerApproachForGUAMIRemoval;
	int isPresent_timerApproachForGUAMIRemoval;

	SI_AMF_DT_AMFName * backupAMFName;
	int isPresent_backupAMFName;

} SI_AMF_DT_UnavailableGUAMIItem;


// UnavailableGUAMIItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UnavailableGUAMIItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UnavailableGUAMIItem_ExtIEs;


// UPTransportLayerInformation-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_UPTransportLayerInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UPTransportLayerInformation_ExtIEs;


// UPTransportLayerInformationItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UPTransportLayerInformationItem
{
	SI_AMF_DT_UPTransportLayerInformation * nGU_UP_TNLInformation;

} SI_AMF_DT_UPTransportLayerInformationItem;


// UPTransportLayerInformationItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UPTransportLayerInformationItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs;


// UPTransportLayerInformationPairItem
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UPTransportLayerInformationPairItem
{
	SI_AMF_DT_UPTransportLayerInformation * uL_NGU_UP_TNLInformation;

	SI_AMF_DT_UPTransportLayerInformation * dL_NGU_UP_TNLInformation;

} SI_AMF_DT_UPTransportLayerInformationPairItem;


// UPTransportLayerInformationPairItem-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UPTransportLayerInformationPairItem_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs;


// UserLocationInformationEUTRA
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UserLocationInformationEUTRA
{
	SI_AMF_DT_EUTRA_CGI * eUTRA_CGI;

	SI_AMF_DT_TAI * tAI;

	SI_AMF_DT_TimeStamp * timeStamp;
	int isPresent_timeStamp;

} SI_AMF_DT_UserLocationInformationEUTRA;


// UserLocationInformationNR
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UserLocationInformationNR
{
	SI_AMF_DT_NR_CGI * nR_CGI;

	SI_AMF_DT_TAI * tAI;

	SI_AMF_DT_TimeStamp * timeStamp;
	int isPresent_timeStamp;

} SI_AMF_DT_UserLocationInformationNR;


// UserLocationInformationN3IWF
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_UserLocationInformationN3IWF
{
	SI_AMF_DT_TransportLayerAddress * iPAddress;

	SI_AMF_DT_PortNumber * portNumber;

} SI_AMF_DT_UserLocationInformationN3IWF;


// UserLocationInformation
// ADT=0  DT=1
typedef struct __si_amf_dt_UserLocationInformation
{
	union 
	{
		// ParserName = SEQUENCE;
		SI_AMF_DT_UserLocationInformationEUTRA * userLocationInformationEUTRA;

		// ParserName = SEQUENCE;
		SI_AMF_DT_UserLocationInformationNR * userLocationInformationNR;

		// ParserName = SEQUENCE;
		SI_AMF_DT_UserLocationInformationN3IWF * userLocationInformationN3IWF;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_UserLocationInformation;


// UserLocationInformation-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_UserLocationInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UserLocationInformation_ExtIEs;


// UserLocationInformationEUTRA-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UserLocationInformationEUTRA_ExtIEs
{
	// Got Success L:2926
	//NGRAN-CGI,  optional
	SI_AMF_DT_NGRAN_CGI * pSCellInformation;
	int isPresent_pSCellInformation;

} SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs;


// UserLocationInformationN3IWF-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UserLocationInformationN3IWF_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs;


// UserLocationInformationNR-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UserLocationInformationNR_ExtIEs
{
	// Got Success L:2926
	//NGRAN-CGI,  optional
	SI_AMF_DT_NGRAN_CGI * pSCellInformation;
	int isPresent_pSCellInformation;

} SI_AMF_DT_UserLocationInformationNR_ExtIEs;


// UserPlaneSecurityInformation-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_UserPlaneSecurityInformation_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs;


// VolumeTimedReport-ItemTimeStamp
// OCTETSTRING,OCTET STRING(SIZE(4))
// ADT=0  DT=2
typedef struct __si_amf_dt_VolumeTimedReport_ItemTimeStamp
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_VolumeTimedReport_ItemTimeStamp;

// VolumeTimedReport-ItemUsageCount
// INTEGER,INTEGER(0..18446744073709551615),MIN=0,MAX=18446744073709552000
// ADT=0  DT=2
typedef struct __si_amf_dt_VolumeTimedReport_ItemUsageCount
{
	unsigned long long int data;
} SI_AMF_DT_VolumeTimedReport_ItemUsageCount;

// VolumeTimedReport-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_VolumeTimedReport_Item
{
	SI_AMF_DT_VolumeTimedReport_ItemTimeStamp * startTimeStamp;

	SI_AMF_DT_VolumeTimedReport_ItemTimeStamp * endTimeStamp;

	unsigned long long int usageCountUL;

	unsigned long long int usageCountDL;

} SI_AMF_DT_VolumeTimedReport_Item;


// VolumeTimedReport-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_VolumeTimedReport_Item_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_VolumeTimedReport_Item_ExtIEs;


// WarningAreaCoordinates
// OCTETSTRING,OCTET STRING(SIZE(1..1024))
// ADT=0  DT=2
typedef struct __si_amf_dt_WarningAreaCoordinates
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_WarningAreaCoordinates;

// WarningAreaList
// ADT=0  DT=1
typedef struct __si_amf_dt_WarningAreaList
{
	union 
	{
		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EUTRA_CGIListForWarning * eUTRA_CGIListForWarning;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_NR_CGIListForWarning * nR_CGIListForWarning;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_TAIListForWarning * tAIListForWarning;

		// ParserName = SEQUENCE_OF;
		SI_AMF_DT_EmergencyAreaIDList * emergencyAreaIDList;

	} u;

	// should be 0 based index of filled structure
	uint8_t SelectedChoice; 
} SI_AMF_DT_WarningAreaList;


// WarningAreaList-ExtIEs
// ADT=2  DT=3 Container
typedef struct __si_amf_dt_WarningAreaList_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_WarningAreaList_ExtIEs;


// WarningMessageContents
// OCTETSTRING,OCTET STRING(SIZE(1..9600))
// ADT=0  DT=2
typedef struct __si_amf_dt_WarningMessageContents
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_WarningMessageContents;

// WarningSecurityInfo
// OCTETSTRING,OCTET STRING(SIZE(50))
// ADT=0  DT=2
typedef struct __si_amf_dt_WarningSecurityInfo
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_WarningSecurityInfo;

// WarningType
// OCTETSTRING,OCTET STRING(SIZE(2))
// ADT=0  DT=2
typedef struct __si_amf_dt_WarningType
{
	unsigned char * data;
	unsigned int length;
} SI_AMF_DT_WarningType;

// XnGTP-TLAs
//SEQUENCE OF TransportLayerAddress, MIN=1, MAX=maxnoofXnGTP-TLAs  ADT=0  DT=2
typedef struct __si_amf_dt_XnGTP_TLAs
{
	SI_LinkedList * TransportLayerAddress;
} SI_AMF_DT_XnGTP_TLAs;


// XnExtTLA-Item
// ONLY-SEQUENCE ADT=0  DT=1
typedef struct __si_amf_dt_XnExtTLA_Item
{
	SI_AMF_DT_TransportLayerAddress * iPsecTLA;
	int isPresent_iPsecTLA;

	SI_AMF_DT_XnGTP_TLAs * gTP_TLAs;
	int isPresent_gTP_TLAs;

} SI_AMF_DT_XnExtTLA_Item;


// XnExtTLA-Item-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_XnExtTLA_Item_ExtIEs
{
	// Got Success L:2926
	//SCTP-TLAs,  optional
	SI_AMF_DT_SCTP_TLAs * sCTPTLAs;
	int isPresent_sCTPTLAs;

} SI_AMF_DT_XnExtTLA_Item_ExtIEs;


// XnTNLConfigurationInfo-ExtIEs
// ADT=1  DT=3 Container
typedef struct __si_amf_dt_XnTNLConfigurationInfo_ExtIEs
{
	// Got Failed L:2919
	// {...}
	// {}
} SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs;


void __si_amf_init_AdditionalDLUPTNLInformationForHOList( SI_AMF_DT_AdditionalDLUPTNLInformationForHOList ** data);

void __si_amf_debug_AdditionalDLUPTNLInformationForHOList( char * key, SI_AMF_DT_AdditionalDLUPTNLInformationForHOList * data, int lvl);

void __si_amf_memfree_AdditionalDLUPTNLInformationForHOList( SI_AMF_DT_AdditionalDLUPTNLInformationForHOList * data);

int __si_amf_Encode_AdditionalDLUPTNLInformationForHOList( SI_AMF_DT_AdditionalDLUPTNLInformationForHOList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TransportLayerAddress( SI_AMF_DT_TransportLayerAddress ** data);

void __si_amf_init_TransportLayerAddress2( SI_AMF_DT_TransportLayerAddress ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_TransportLayerAddress( char * key, SI_AMF_DT_TransportLayerAddress * data, int lvl);

void __si_amf_memfree_TransportLayerAddress( SI_AMF_DT_TransportLayerAddress * data);

int __si_amf_Encode_TransportLayerAddress( SI_AMF_DT_TransportLayerAddress * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GTP_TEID( SI_AMF_DT_GTP_TEID ** data);

void __si_amf_init_GTP_TEID2( SI_AMF_DT_GTP_TEID ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_GTP_TEID( char * key, SI_AMF_DT_GTP_TEID * data, int lvl);

void __si_amf_memfree_GTP_TEID( SI_AMF_DT_GTP_TEID * data);

int __si_amf_Encode_GTP_TEID( SI_AMF_DT_GTP_TEID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GTPTunnel( SI_AMF_DT_GTPTunnel ** data);

void __si_amf_debug_GTPTunnel( char * key, SI_AMF_DT_GTPTunnel * data, int lvl);

void __si_amf_memfree_GTPTunnel( SI_AMF_DT_GTPTunnel * data);

int __si_amf_Encode_GTPTunnel( SI_AMF_DT_GTPTunnel * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformation( SI_AMF_DT_UPTransportLayerInformation ** data);

void __si_amf_debug_UPTransportLayerInformation( char * key, SI_AMF_DT_UPTransportLayerInformation * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformation( SI_AMF_DT_UPTransportLayerInformation * data);

int __si_amf_Encode_UPTransportLayerInformation( SI_AMF_DT_UPTransportLayerInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowListWithDataForwarding( SI_AMF_DT_QosFlowListWithDataForwarding ** data);

void __si_amf_debug_QosFlowListWithDataForwarding( char * key, SI_AMF_DT_QosFlowListWithDataForwarding * data, int lvl);

void __si_amf_memfree_QosFlowListWithDataForwarding( SI_AMF_DT_QosFlowListWithDataForwarding * data);

int __si_amf_Encode_QosFlowListWithDataForwarding( SI_AMF_DT_QosFlowListWithDataForwarding * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AdditionalDLUPTNLInformationForHOItem( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem ** data);

void __si_amf_debug_AdditionalDLUPTNLInformationForHOItem( char * key, SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem * data, int lvl);

void __si_amf_memfree_AdditionalDLUPTNLInformationForHOItem( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem * data);

int __si_amf_Encode_AdditionalDLUPTNLInformationForHOItem( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AdditionalDLUPTNLInformationForHOItem_ExtIEs( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs ** data);

void __si_amf_debug_AdditionalDLUPTNLInformationForHOItem_ExtIEs( char * key, SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AdditionalDLUPTNLInformationForHOItem_ExtIEs( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AdditionalDLUPTNLInformationForHOItem_ExtIEs( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

//TODO: DataType -><- Got NULL

void __si_amf_debug_AdditionalQosFlowInformation( char * key, uint8_t eAdditionalQosFlowInformation, int lvl);

int __si_amf_Encode_AdditionalQosFlowInformation( uint8_t eAdditionalQosFlowInformation, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PriorityLevelARP( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PriorityLevelARP( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_Pre_emptionCapability( char * key, uint8_t ePre_emptionCapability, int lvl);

int __si_amf_Encode_Pre_emptionCapability( uint8_t ePre_emptionCapability, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_Pre_emptionVulnerability( char * key, uint8_t ePre_emptionVulnerability, int lvl);

int __si_amf_Encode_Pre_emptionVulnerability( uint8_t ePre_emptionVulnerability, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AllocationAndRetentionPriority( SI_AMF_DT_AllocationAndRetentionPriority ** data);

void __si_amf_debug_AllocationAndRetentionPriority( char * key, SI_AMF_DT_AllocationAndRetentionPriority * data, int lvl);

void __si_amf_memfree_AllocationAndRetentionPriority( SI_AMF_DT_AllocationAndRetentionPriority * data);

int __si_amf_Encode_AllocationAndRetentionPriority( SI_AMF_DT_AllocationAndRetentionPriority * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AllocationAndRetentionPriority_ExtIEs( SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs ** data);

void __si_amf_debug_AllocationAndRetentionPriority_ExtIEs( char * key, SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs * data, int lvl);

void __si_amf_memfree_AllocationAndRetentionPriority_ExtIEs( SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AllocationAndRetentionPriority_ExtIEs( SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AllowedNSSAI( SI_AMF_DT_AllowedNSSAI ** data);

void __si_amf_debug_AllowedNSSAI( char * key, SI_AMF_DT_AllowedNSSAI * data, int lvl);

void __si_amf_memfree_AllowedNSSAI( SI_AMF_DT_AllowedNSSAI * data);

int __si_amf_Encode_AllowedNSSAI( SI_AMF_DT_AllowedNSSAI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SST( SI_AMF_DT_SST ** data);

void __si_amf_init_SST2( SI_AMF_DT_SST ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_SST( char * key, SI_AMF_DT_SST * data, int lvl);

void __si_amf_memfree_SST( SI_AMF_DT_SST * data);

int __si_amf_Encode_SST( SI_AMF_DT_SST * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SD( SI_AMF_DT_SD ** data);

void __si_amf_init_SD2( SI_AMF_DT_SD ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_SD( char * key, SI_AMF_DT_SD * data, int lvl);

void __si_amf_memfree_SD( SI_AMF_DT_SD * data);

int __si_amf_Encode_SD( SI_AMF_DT_SD * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_S_NSSAI( SI_AMF_DT_S_NSSAI ** data);

void __si_amf_debug_S_NSSAI( char * key, SI_AMF_DT_S_NSSAI * data, int lvl);

void __si_amf_memfree_S_NSSAI( SI_AMF_DT_S_NSSAI * data);

int __si_amf_Encode_S_NSSAI( SI_AMF_DT_S_NSSAI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AllowedNSSAI_Item( SI_AMF_DT_AllowedNSSAI_Item ** data);

void __si_amf_debug_AllowedNSSAI_Item( char * key, SI_AMF_DT_AllowedNSSAI_Item * data, int lvl);

void __si_amf_memfree_AllowedNSSAI_Item( SI_AMF_DT_AllowedNSSAI_Item * data);

int __si_amf_Encode_AllowedNSSAI_Item( SI_AMF_DT_AllowedNSSAI_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AllowedNSSAI_Item_ExtIEs( SI_AMF_DT_AllowedNSSAI_Item_ExtIEs ** data);

void __si_amf_debug_AllowedNSSAI_Item_ExtIEs( char * key, SI_AMF_DT_AllowedNSSAI_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_AllowedNSSAI_Item_ExtIEs( SI_AMF_DT_AllowedNSSAI_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AllowedNSSAI_Item_ExtIEs( SI_AMF_DT_AllowedNSSAI_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AllowedTACs( SI_AMF_DT_AllowedTACs ** data);

void __si_amf_debug_AllowedTACs( char * key, SI_AMF_DT_AllowedTACs * data, int lvl);

void __si_amf_memfree_AllowedTACs( SI_AMF_DT_AllowedTACs * data);

int __si_amf_Encode_AllowedTACs( SI_AMF_DT_AllowedTACs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMFName( SI_AMF_DT_AMFName ** data);

void __si_amf_init_AMFName2( SI_AMF_DT_AMFName ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_AMFName( char * key, SI_AMF_DT_AMFName * data, int lvl);

void __si_amf_memfree_AMFName( SI_AMF_DT_AMFName * data);

int __si_amf_Encode_AMFName( SI_AMF_DT_AMFName * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PLMNIdentity( SI_AMF_DT_PLMNIdentity ** data);

void __si_amf_init_PLMNIdentity2( SI_AMF_DT_PLMNIdentity ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PLMNIdentity( char * key, SI_AMF_DT_PLMNIdentity * data, int lvl);

void __si_amf_memfree_PLMNIdentity( SI_AMF_DT_PLMNIdentity * data);

int __si_amf_Encode_PLMNIdentity( SI_AMF_DT_PLMNIdentity * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GNB_IDBS( SI_AMF_DT_GNB_IDBS ** data);

void __si_amf_init_GNB_IDBS2( SI_AMF_DT_GNB_IDBS ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_GNB_IDBS( char * key, SI_AMF_DT_GNB_IDBS * data, int lvl);

void __si_amf_memfree_GNB_IDBS( SI_AMF_DT_GNB_IDBS * data);

int __si_amf_Encode_GNB_IDBS( SI_AMF_DT_GNB_IDBS * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GNB_ID( SI_AMF_DT_GNB_ID ** data);

void __si_amf_debug_GNB_ID( char * key, SI_AMF_DT_GNB_ID * data, int lvl);

void __si_amf_memfree_GNB_ID( SI_AMF_DT_GNB_ID * data);

int __si_amf_Encode_GNB_ID( SI_AMF_DT_GNB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalGNB_ID( SI_AMF_DT_GlobalGNB_ID ** data);

void __si_amf_debug_GlobalGNB_ID( char * key, SI_AMF_DT_GlobalGNB_ID * data, int lvl);

void __si_amf_memfree_GlobalGNB_ID( SI_AMF_DT_GlobalGNB_ID * data);

int __si_amf_Encode_GlobalGNB_ID( SI_AMF_DT_GlobalGNB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NgENB_IDmacroNgENB_ID( SI_AMF_DT_NgENB_IDmacroNgENB_ID ** data);

void __si_amf_init_NgENB_IDmacroNgENB_ID2( SI_AMF_DT_NgENB_IDmacroNgENB_ID ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_NgENB_IDmacroNgENB_ID( char * key, SI_AMF_DT_NgENB_IDmacroNgENB_ID * data, int lvl);

void __si_amf_memfree_NgENB_IDmacroNgENB_ID( SI_AMF_DT_NgENB_IDmacroNgENB_ID * data);

int __si_amf_Encode_NgENB_IDmacroNgENB_ID( SI_AMF_DT_NgENB_IDmacroNgENB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NgENB_IDshortMacroNgENB_ID( SI_AMF_DT_NgENB_IDshortMacroNgENB_ID ** data);

void __si_amf_init_NgENB_IDshortMacroNgENB_ID2( SI_AMF_DT_NgENB_IDshortMacroNgENB_ID ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_NgENB_IDshortMacroNgENB_ID( char * key, SI_AMF_DT_NgENB_IDshortMacroNgENB_ID * data, int lvl);

void __si_amf_memfree_NgENB_IDshortMacroNgENB_ID( SI_AMF_DT_NgENB_IDshortMacroNgENB_ID * data);

int __si_amf_Encode_NgENB_IDshortMacroNgENB_ID( SI_AMF_DT_NgENB_IDshortMacroNgENB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NgENB_IDlongMacroNgENB_ID( SI_AMF_DT_NgENB_IDlongMacroNgENB_ID ** data);

void __si_amf_init_NgENB_IDlongMacroNgENB_ID2( SI_AMF_DT_NgENB_IDlongMacroNgENB_ID ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_NgENB_IDlongMacroNgENB_ID( char * key, SI_AMF_DT_NgENB_IDlongMacroNgENB_ID * data, int lvl);

void __si_amf_memfree_NgENB_IDlongMacroNgENB_ID( SI_AMF_DT_NgENB_IDlongMacroNgENB_ID * data);

int __si_amf_Encode_NgENB_IDlongMacroNgENB_ID( SI_AMF_DT_NgENB_IDlongMacroNgENB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NgENB_ID( SI_AMF_DT_NgENB_ID ** data);

void __si_amf_debug_NgENB_ID( char * key, SI_AMF_DT_NgENB_ID * data, int lvl);

void __si_amf_memfree_NgENB_ID( SI_AMF_DT_NgENB_ID * data);

int __si_amf_Encode_NgENB_ID( SI_AMF_DT_NgENB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalNgENB_ID( SI_AMF_DT_GlobalNgENB_ID ** data);

void __si_amf_debug_GlobalNgENB_ID( char * key, SI_AMF_DT_GlobalNgENB_ID * data, int lvl);

void __si_amf_memfree_GlobalNgENB_ID( SI_AMF_DT_GlobalNgENB_ID * data);

int __si_amf_Encode_GlobalNgENB_ID( SI_AMF_DT_GlobalNgENB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_N3IWF_IDBS( SI_AMF_DT_N3IWF_IDBS ** data);

void __si_amf_init_N3IWF_IDBS2( SI_AMF_DT_N3IWF_IDBS ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_N3IWF_IDBS( char * key, SI_AMF_DT_N3IWF_IDBS * data, int lvl);

void __si_amf_memfree_N3IWF_IDBS( SI_AMF_DT_N3IWF_IDBS * data);

int __si_amf_Encode_N3IWF_IDBS( SI_AMF_DT_N3IWF_IDBS * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_N3IWF_ID( SI_AMF_DT_N3IWF_ID ** data);

void __si_amf_debug_N3IWF_ID( char * key, SI_AMF_DT_N3IWF_ID * data, int lvl);

void __si_amf_memfree_N3IWF_ID( SI_AMF_DT_N3IWF_ID * data);

int __si_amf_Encode_N3IWF_ID( SI_AMF_DT_N3IWF_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalN3IWF_ID( SI_AMF_DT_GlobalN3IWF_ID ** data);

void __si_amf_debug_GlobalN3IWF_ID( char * key, SI_AMF_DT_GlobalN3IWF_ID * data, int lvl);

void __si_amf_memfree_GlobalN3IWF_ID( SI_AMF_DT_GlobalN3IWF_ID * data);

int __si_amf_Encode_GlobalN3IWF_ID( SI_AMF_DT_GlobalN3IWF_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalRANNodeID( SI_AMF_DT_GlobalRANNodeID ** data);

void __si_amf_debug_GlobalRANNodeID( char * key, SI_AMF_DT_GlobalRANNodeID * data, int lvl);

void __si_amf_memfree_GlobalRANNodeID( SI_AMF_DT_GlobalRANNodeID * data);

int __si_amf_Encode_GlobalRANNodeID( SI_AMF_DT_GlobalRANNodeID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAC( SI_AMF_DT_TAC ** data);

void __si_amf_init_TAC2( SI_AMF_DT_TAC ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_TAC( char * key, SI_AMF_DT_TAC * data, int lvl);

void __si_amf_memfree_TAC( SI_AMF_DT_TAC * data);

int __si_amf_Encode_TAC( SI_AMF_DT_TAC * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAI( SI_AMF_DT_TAI ** data);

void __si_amf_debug_TAI( char * key, SI_AMF_DT_TAI * data, int lvl);

void __si_amf_memfree_TAI( SI_AMF_DT_TAI * data);

int __si_amf_Encode_TAI( SI_AMF_DT_TAI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMFPagingTarget( SI_AMF_DT_AMFPagingTarget ** data);

void __si_amf_debug_AMFPagingTarget( char * key, SI_AMF_DT_AMFPagingTarget * data, int lvl);

void __si_amf_memfree_AMFPagingTarget( SI_AMF_DT_AMFPagingTarget * data);

int __si_amf_Encode_AMFPagingTarget( SI_AMF_DT_AMFPagingTarget * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMFPagingTarget_ExtIEs( SI_AMF_DT_AMFPagingTarget_ExtIEs ** data);

void __si_amf_debug_AMFPagingTarget_ExtIEs( char * key, SI_AMF_DT_AMFPagingTarget_ExtIEs * data, int lvl);

void __si_amf_memfree_AMFPagingTarget_ExtIEs( SI_AMF_DT_AMFPagingTarget_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_AMFPagingTarget_ExtIEs( SI_AMF_DT_AMFPagingTarget_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMFPointer( SI_AMF_DT_AMFPointer ** data);

void __si_amf_init_AMFPointer2( SI_AMF_DT_AMFPointer ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_AMFPointer( char * key, SI_AMF_DT_AMFPointer * data, int lvl);

void __si_amf_memfree_AMFPointer( SI_AMF_DT_AMFPointer * data);

int __si_amf_Encode_AMFPointer( SI_AMF_DT_AMFPointer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMFRegionID( SI_AMF_DT_AMFRegionID ** data);

void __si_amf_init_AMFRegionID2( SI_AMF_DT_AMFRegionID ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_AMFRegionID( char * key, SI_AMF_DT_AMFRegionID * data, int lvl);

void __si_amf_memfree_AMFRegionID( SI_AMF_DT_AMFRegionID * data);

int __si_amf_Encode_AMFRegionID( SI_AMF_DT_AMFRegionID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMFSetID( SI_AMF_DT_AMFSetID ** data);

void __si_amf_init_AMFSetID2( SI_AMF_DT_AMFSetID ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_AMFSetID( char * key, SI_AMF_DT_AMFSetID * data, int lvl);

void __si_amf_memfree_AMFSetID( SI_AMF_DT_AMFSetID * data);

int __si_amf_Encode_AMFSetID( SI_AMF_DT_AMFSetID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationSetupList( SI_AMF_DT_AMF_TNLAssociationSetupList ** data);

void __si_amf_debug_AMF_TNLAssociationSetupList( char * key, SI_AMF_DT_AMF_TNLAssociationSetupList * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationSetupList( SI_AMF_DT_AMF_TNLAssociationSetupList * data);

int __si_amf_Encode_AMF_TNLAssociationSetupList( SI_AMF_DT_AMF_TNLAssociationSetupList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CPTransportLayerInformation( SI_AMF_DT_CPTransportLayerInformation ** data);

void __si_amf_debug_CPTransportLayerInformation( char * key, SI_AMF_DT_CPTransportLayerInformation * data, int lvl);

void __si_amf_memfree_CPTransportLayerInformation( SI_AMF_DT_CPTransportLayerInformation * data);

int __si_amf_Encode_CPTransportLayerInformation( SI_AMF_DT_CPTransportLayerInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationSetupItem( SI_AMF_DT_AMF_TNLAssociationSetupItem ** data);

void __si_amf_debug_AMF_TNLAssociationSetupItem( char * key, SI_AMF_DT_AMF_TNLAssociationSetupItem * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationSetupItem( SI_AMF_DT_AMF_TNLAssociationSetupItem * data);

int __si_amf_Encode_AMF_TNLAssociationSetupItem( SI_AMF_DT_AMF_TNLAssociationSetupItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationSetupItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs ** data);

void __si_amf_debug_AMF_TNLAssociationSetupItem_ExtIEs( char * key, SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationSetupItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AMF_TNLAssociationSetupItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToAddList( SI_AMF_DT_AMF_TNLAssociationToAddList ** data);

void __si_amf_debug_AMF_TNLAssociationToAddList( char * key, SI_AMF_DT_AMF_TNLAssociationToAddList * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToAddList( SI_AMF_DT_AMF_TNLAssociationToAddList * data);

int __si_amf_Encode_AMF_TNLAssociationToAddList( SI_AMF_DT_AMF_TNLAssociationToAddList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TNLAssociationUsage( char * key, uint8_t eTNLAssociationUsage, int lvl);

int __si_amf_Encode_TNLAssociationUsage( uint8_t eTNLAssociationUsage, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TNLAddressWeightFactor( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_TNLAddressWeightFactor( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToAddItem( SI_AMF_DT_AMF_TNLAssociationToAddItem ** data);

void __si_amf_debug_AMF_TNLAssociationToAddItem( char * key, SI_AMF_DT_AMF_TNLAssociationToAddItem * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToAddItem( SI_AMF_DT_AMF_TNLAssociationToAddItem * data);

int __si_amf_Encode_AMF_TNLAssociationToAddItem( SI_AMF_DT_AMF_TNLAssociationToAddItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToAddItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs ** data);

void __si_amf_debug_AMF_TNLAssociationToAddItem_ExtIEs( char * key, SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToAddItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AMF_TNLAssociationToAddItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToRemoveList( SI_AMF_DT_AMF_TNLAssociationToRemoveList ** data);

void __si_amf_debug_AMF_TNLAssociationToRemoveList( char * key, SI_AMF_DT_AMF_TNLAssociationToRemoveList * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToRemoveList( SI_AMF_DT_AMF_TNLAssociationToRemoveList * data);

int __si_amf_Encode_AMF_TNLAssociationToRemoveList( SI_AMF_DT_AMF_TNLAssociationToRemoveList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToRemoveItem( SI_AMF_DT_AMF_TNLAssociationToRemoveItem ** data);

void __si_amf_debug_AMF_TNLAssociationToRemoveItem( char * key, SI_AMF_DT_AMF_TNLAssociationToRemoveItem * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToRemoveItem( SI_AMF_DT_AMF_TNLAssociationToRemoveItem * data);

int __si_amf_Encode_AMF_TNLAssociationToRemoveItem( SI_AMF_DT_AMF_TNLAssociationToRemoveItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs ** data);

void __si_amf_debug_AMF_TNLAssociationToRemoveItem_ExtIEs( char * key, SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AMF_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToUpdateList( SI_AMF_DT_AMF_TNLAssociationToUpdateList ** data);

void __si_amf_debug_AMF_TNLAssociationToUpdateList( char * key, SI_AMF_DT_AMF_TNLAssociationToUpdateList * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToUpdateList( SI_AMF_DT_AMF_TNLAssociationToUpdateList * data);

int __si_amf_Encode_AMF_TNLAssociationToUpdateList( SI_AMF_DT_AMF_TNLAssociationToUpdateList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToUpdateItem( SI_AMF_DT_AMF_TNLAssociationToUpdateItem ** data);

void __si_amf_debug_AMF_TNLAssociationToUpdateItem( char * key, SI_AMF_DT_AMF_TNLAssociationToUpdateItem * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToUpdateItem( SI_AMF_DT_AMF_TNLAssociationToUpdateItem * data);

int __si_amf_Encode_AMF_TNLAssociationToUpdateItem( SI_AMF_DT_AMF_TNLAssociationToUpdateItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AMF_TNLAssociationToUpdateItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs ** data);

void __si_amf_debug_AMF_TNLAssociationToUpdateItem_ExtIEs( char * key, SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AMF_TNLAssociationToUpdateItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AMF_TNLAssociationToUpdateItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_AMF_UE_NGAP_ID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_AMF_UE_NGAP_ID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestTAIList( SI_AMF_DT_AreaOfInterestTAIList ** data);

void __si_amf_debug_AreaOfInterestTAIList( char * key, SI_AMF_DT_AreaOfInterestTAIList * data, int lvl);

void __si_amf_memfree_AreaOfInterestTAIList( SI_AMF_DT_AreaOfInterestTAIList * data);

int __si_amf_Encode_AreaOfInterestTAIList( SI_AMF_DT_AreaOfInterestTAIList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestCellList( SI_AMF_DT_AreaOfInterestCellList ** data);

void __si_amf_debug_AreaOfInterestCellList( char * key, SI_AMF_DT_AreaOfInterestCellList * data, int lvl);

void __si_amf_memfree_AreaOfInterestCellList( SI_AMF_DT_AreaOfInterestCellList * data);

int __si_amf_Encode_AreaOfInterestCellList( SI_AMF_DT_AreaOfInterestCellList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestRANNodeList( SI_AMF_DT_AreaOfInterestRANNodeList ** data);

void __si_amf_debug_AreaOfInterestRANNodeList( char * key, SI_AMF_DT_AreaOfInterestRANNodeList * data, int lvl);

void __si_amf_memfree_AreaOfInterestRANNodeList( SI_AMF_DT_AreaOfInterestRANNodeList * data);

int __si_amf_Encode_AreaOfInterestRANNodeList( SI_AMF_DT_AreaOfInterestRANNodeList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterest( SI_AMF_DT_AreaOfInterest ** data);

void __si_amf_debug_AreaOfInterest( char * key, SI_AMF_DT_AreaOfInterest * data, int lvl);

void __si_amf_memfree_AreaOfInterest( SI_AMF_DT_AreaOfInterest * data);

int __si_amf_Encode_AreaOfInterest( SI_AMF_DT_AreaOfInterest * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterest_ExtIEs( SI_AMF_DT_AreaOfInterest_ExtIEs ** data);

void __si_amf_debug_AreaOfInterest_ExtIEs( char * key, SI_AMF_DT_AreaOfInterest_ExtIEs * data, int lvl);

void __si_amf_memfree_AreaOfInterest_ExtIEs( SI_AMF_DT_AreaOfInterest_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AreaOfInterest_ExtIEs( SI_AMF_DT_AreaOfInterest_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NRCellIdentity( SI_AMF_DT_NRCellIdentity ** data);

void __si_amf_init_NRCellIdentity2( SI_AMF_DT_NRCellIdentity ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_NRCellIdentity( char * key, SI_AMF_DT_NRCellIdentity * data, int lvl);

void __si_amf_memfree_NRCellIdentity( SI_AMF_DT_NRCellIdentity * data);

int __si_amf_Encode_NRCellIdentity( SI_AMF_DT_NRCellIdentity * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NR_CGI( SI_AMF_DT_NR_CGI ** data);

void __si_amf_debug_NR_CGI( char * key, SI_AMF_DT_NR_CGI * data, int lvl);

void __si_amf_memfree_NR_CGI( SI_AMF_DT_NR_CGI * data);

int __si_amf_Encode_NR_CGI( SI_AMF_DT_NR_CGI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRACellIdentity( SI_AMF_DT_EUTRACellIdentity ** data);

void __si_amf_init_EUTRACellIdentity2( SI_AMF_DT_EUTRACellIdentity ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_EUTRACellIdentity( char * key, SI_AMF_DT_EUTRACellIdentity * data, int lvl);

void __si_amf_memfree_EUTRACellIdentity( SI_AMF_DT_EUTRACellIdentity * data);

int __si_amf_Encode_EUTRACellIdentity( SI_AMF_DT_EUTRACellIdentity * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRA_CGI( SI_AMF_DT_EUTRA_CGI ** data);

void __si_amf_debug_EUTRA_CGI( char * key, SI_AMF_DT_EUTRA_CGI * data, int lvl);

void __si_amf_memfree_EUTRA_CGI( SI_AMF_DT_EUTRA_CGI * data);

int __si_amf_Encode_EUTRA_CGI( SI_AMF_DT_EUTRA_CGI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NGRAN_CGI( SI_AMF_DT_NGRAN_CGI ** data);

void __si_amf_debug_NGRAN_CGI( char * key, SI_AMF_DT_NGRAN_CGI * data, int lvl);

void __si_amf_memfree_NGRAN_CGI( SI_AMF_DT_NGRAN_CGI * data);

int __si_amf_Encode_NGRAN_CGI( SI_AMF_DT_NGRAN_CGI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestCellItem( SI_AMF_DT_AreaOfInterestCellItem ** data);

void __si_amf_debug_AreaOfInterestCellItem( char * key, SI_AMF_DT_AreaOfInterestCellItem * data, int lvl);

void __si_amf_memfree_AreaOfInterestCellItem( SI_AMF_DT_AreaOfInterestCellItem * data);

int __si_amf_Encode_AreaOfInterestCellItem( SI_AMF_DT_AreaOfInterestCellItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestCellItem_ExtIEs( SI_AMF_DT_AreaOfInterestCellItem_ExtIEs ** data);

void __si_amf_debug_AreaOfInterestCellItem_ExtIEs( char * key, SI_AMF_DT_AreaOfInterestCellItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AreaOfInterestCellItem_ExtIEs( SI_AMF_DT_AreaOfInterestCellItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AreaOfInterestCellItem_ExtIEs( SI_AMF_DT_AreaOfInterestCellItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestList( SI_AMF_DT_AreaOfInterestList ** data);

void __si_amf_debug_AreaOfInterestList( char * key, SI_AMF_DT_AreaOfInterestList * data, int lvl);

void __si_amf_memfree_AreaOfInterestList( SI_AMF_DT_AreaOfInterestList * data);

int __si_amf_Encode_AreaOfInterestList( SI_AMF_DT_AreaOfInterestList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_LocationReportingReferenceID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_LocationReportingReferenceID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestItem( SI_AMF_DT_AreaOfInterestItem ** data);

void __si_amf_debug_AreaOfInterestItem( char * key, SI_AMF_DT_AreaOfInterestItem * data, int lvl);

void __si_amf_memfree_AreaOfInterestItem( SI_AMF_DT_AreaOfInterestItem * data);

int __si_amf_Encode_AreaOfInterestItem( SI_AMF_DT_AreaOfInterestItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestItem_ExtIEs( SI_AMF_DT_AreaOfInterestItem_ExtIEs ** data);

void __si_amf_debug_AreaOfInterestItem_ExtIEs( char * key, SI_AMF_DT_AreaOfInterestItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AreaOfInterestItem_ExtIEs( SI_AMF_DT_AreaOfInterestItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AreaOfInterestItem_ExtIEs( SI_AMF_DT_AreaOfInterestItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestRANNodeItem( SI_AMF_DT_AreaOfInterestRANNodeItem ** data);

void __si_amf_debug_AreaOfInterestRANNodeItem( char * key, SI_AMF_DT_AreaOfInterestRANNodeItem * data, int lvl);

void __si_amf_memfree_AreaOfInterestRANNodeItem( SI_AMF_DT_AreaOfInterestRANNodeItem * data);

int __si_amf_Encode_AreaOfInterestRANNodeItem( SI_AMF_DT_AreaOfInterestRANNodeItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestRANNodeItem_ExtIEs( SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs ** data);

void __si_amf_debug_AreaOfInterestRANNodeItem_ExtIEs( char * key, SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AreaOfInterestRANNodeItem_ExtIEs( SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AreaOfInterestRANNodeItem_ExtIEs( SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestTAIItem( SI_AMF_DT_AreaOfInterestTAIItem ** data);

void __si_amf_debug_AreaOfInterestTAIItem( char * key, SI_AMF_DT_AreaOfInterestTAIItem * data, int lvl);

void __si_amf_memfree_AreaOfInterestTAIItem( SI_AMF_DT_AreaOfInterestTAIItem * data);

int __si_amf_Encode_AreaOfInterestTAIItem( SI_AMF_DT_AreaOfInterestTAIItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AreaOfInterestTAIItem_ExtIEs( SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs ** data);

void __si_amf_debug_AreaOfInterestTAIItem_ExtIEs( char * key, SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AreaOfInterestTAIItem_ExtIEs( SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AreaOfInterestTAIItem_ExtIEs( SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedCellList( SI_AMF_DT_RecommendedCellList ** data);

void __si_amf_debug_RecommendedCellList( char * key, SI_AMF_DT_RecommendedCellList * data, int lvl);

void __si_amf_memfree_RecommendedCellList( SI_AMF_DT_RecommendedCellList * data);

int __si_amf_Encode_RecommendedCellList( SI_AMF_DT_RecommendedCellList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedCellsForPaging( SI_AMF_DT_RecommendedCellsForPaging ** data);

void __si_amf_debug_RecommendedCellsForPaging( char * key, SI_AMF_DT_RecommendedCellsForPaging * data, int lvl);

void __si_amf_memfree_RecommendedCellsForPaging( SI_AMF_DT_RecommendedCellsForPaging * data);

int __si_amf_Encode_RecommendedCellsForPaging( SI_AMF_DT_RecommendedCellsForPaging * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssistanceDataForRecommendedCells( SI_AMF_DT_AssistanceDataForRecommendedCells ** data);

void __si_amf_debug_AssistanceDataForRecommendedCells( char * key, SI_AMF_DT_AssistanceDataForRecommendedCells * data, int lvl);

void __si_amf_memfree_AssistanceDataForRecommendedCells( SI_AMF_DT_AssistanceDataForRecommendedCells * data);

int __si_amf_Encode_AssistanceDataForRecommendedCells( SI_AMF_DT_AssistanceDataForRecommendedCells * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PagingAttemptCount( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PagingAttemptCount( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_IntendedNumberOfPagingAttempts( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_IntendedNumberOfPagingAttempts( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NextPagingAreaScope( char * key, uint8_t eNextPagingAreaScope, int lvl);

int __si_amf_Encode_NextPagingAreaScope( uint8_t eNextPagingAreaScope, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PagingAttemptInformation( SI_AMF_DT_PagingAttemptInformation ** data);

void __si_amf_debug_PagingAttemptInformation( char * key, SI_AMF_DT_PagingAttemptInformation * data, int lvl);

void __si_amf_memfree_PagingAttemptInformation( SI_AMF_DT_PagingAttemptInformation * data);

int __si_amf_Encode_PagingAttemptInformation( SI_AMF_DT_PagingAttemptInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssistanceDataForPaging( SI_AMF_DT_AssistanceDataForPaging ** data);

void __si_amf_debug_AssistanceDataForPaging( char * key, SI_AMF_DT_AssistanceDataForPaging * data, int lvl);

void __si_amf_memfree_AssistanceDataForPaging( SI_AMF_DT_AssistanceDataForPaging * data);

int __si_amf_Encode_AssistanceDataForPaging( SI_AMF_DT_AssistanceDataForPaging * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssistanceDataForPaging_ExtIEs( SI_AMF_DT_AssistanceDataForPaging_ExtIEs ** data);

void __si_amf_debug_AssistanceDataForPaging_ExtIEs( char * key, SI_AMF_DT_AssistanceDataForPaging_ExtIEs * data, int lvl);

void __si_amf_memfree_AssistanceDataForPaging_ExtIEs( SI_AMF_DT_AssistanceDataForPaging_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AssistanceDataForPaging_ExtIEs( SI_AMF_DT_AssistanceDataForPaging_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssistanceDataForRecommendedCells_ExtIEs( SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs ** data);

void __si_amf_debug_AssistanceDataForRecommendedCells_ExtIEs( char * key, SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs * data, int lvl);

void __si_amf_memfree_AssistanceDataForRecommendedCells_ExtIEs( SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AssistanceDataForRecommendedCells_ExtIEs( SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssociatedQosFlowList( SI_AMF_DT_AssociatedQosFlowList ** data);

void __si_amf_debug_AssociatedQosFlowList( char * key, SI_AMF_DT_AssociatedQosFlowList * data, int lvl);

void __si_amf_memfree_AssociatedQosFlowList( SI_AMF_DT_AssociatedQosFlowList * data);

int __si_amf_Encode_AssociatedQosFlowList( SI_AMF_DT_AssociatedQosFlowList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_AssociatedQosFlowItemQosFlowMappingIndication( char * key, uint8_t eAssociatedQosFlowItemQosFlowMappingIndication, int lvl);

int __si_amf_Encode_AssociatedQosFlowItemQosFlowMappingIndication( uint8_t eAssociatedQosFlowItemQosFlowMappingIndication, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_QosFlowIdentifier( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_QosFlowIdentifier( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssociatedQosFlowItem( SI_AMF_DT_AssociatedQosFlowItem ** data);

void __si_amf_debug_AssociatedQosFlowItem( char * key, SI_AMF_DT_AssociatedQosFlowItem * data, int lvl);

void __si_amf_memfree_AssociatedQosFlowItem( SI_AMF_DT_AssociatedQosFlowItem * data);

int __si_amf_Encode_AssociatedQosFlowItem( SI_AMF_DT_AssociatedQosFlowItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_AssociatedQosFlowItem_ExtIEs( SI_AMF_DT_AssociatedQosFlowItem_ExtIEs ** data);

void __si_amf_debug_AssociatedQosFlowItem_ExtIEs( char * key, SI_AMF_DT_AssociatedQosFlowItem_ExtIEs * data, int lvl);

void __si_amf_memfree_AssociatedQosFlowItem_ExtIEs( SI_AMF_DT_AssociatedQosFlowItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_AssociatedQosFlowItem_ExtIEs( SI_AMF_DT_AssociatedQosFlowItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_AveragingWindow( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_AveragingWindow( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_BitRate( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_BitRate( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDCancelledEUTRA( SI_AMF_DT_CellIDCancelledEUTRA ** data);

void __si_amf_debug_CellIDCancelledEUTRA( char * key, SI_AMF_DT_CellIDCancelledEUTRA * data, int lvl);

void __si_amf_memfree_CellIDCancelledEUTRA( SI_AMF_DT_CellIDCancelledEUTRA * data);

int __si_amf_Encode_CellIDCancelledEUTRA( SI_AMF_DT_CellIDCancelledEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAICancelledEUTRA( SI_AMF_DT_TAICancelledEUTRA ** data);

void __si_amf_debug_TAICancelledEUTRA( char * key, SI_AMF_DT_TAICancelledEUTRA * data, int lvl);

void __si_amf_memfree_TAICancelledEUTRA( SI_AMF_DT_TAICancelledEUTRA * data);

int __si_amf_Encode_TAICancelledEUTRA( SI_AMF_DT_TAICancelledEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDCancelledEUTRA( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA ** data);

void __si_amf_debug_EmergencyAreaIDCancelledEUTRA( char * key, SI_AMF_DT_EmergencyAreaIDCancelledEUTRA * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDCancelledEUTRA( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA * data);

int __si_amf_Encode_EmergencyAreaIDCancelledEUTRA( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDCancelledNR( SI_AMF_DT_CellIDCancelledNR ** data);

void __si_amf_debug_CellIDCancelledNR( char * key, SI_AMF_DT_CellIDCancelledNR * data, int lvl);

void __si_amf_memfree_CellIDCancelledNR( SI_AMF_DT_CellIDCancelledNR * data);

int __si_amf_Encode_CellIDCancelledNR( SI_AMF_DT_CellIDCancelledNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAICancelledNR( SI_AMF_DT_TAICancelledNR ** data);

void __si_amf_debug_TAICancelledNR( char * key, SI_AMF_DT_TAICancelledNR * data, int lvl);

void __si_amf_memfree_TAICancelledNR( SI_AMF_DT_TAICancelledNR * data);

int __si_amf_Encode_TAICancelledNR( SI_AMF_DT_TAICancelledNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDCancelledNR( SI_AMF_DT_EmergencyAreaIDCancelledNR ** data);

void __si_amf_debug_EmergencyAreaIDCancelledNR( char * key, SI_AMF_DT_EmergencyAreaIDCancelledNR * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDCancelledNR( SI_AMF_DT_EmergencyAreaIDCancelledNR * data);

int __si_amf_Encode_EmergencyAreaIDCancelledNR( SI_AMF_DT_EmergencyAreaIDCancelledNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastCancelledAreaList( SI_AMF_DT_BroadcastCancelledAreaList ** data);

void __si_amf_debug_BroadcastCancelledAreaList( char * key, SI_AMF_DT_BroadcastCancelledAreaList * data, int lvl);

void __si_amf_memfree_BroadcastCancelledAreaList( SI_AMF_DT_BroadcastCancelledAreaList * data);

int __si_amf_Encode_BroadcastCancelledAreaList( SI_AMF_DT_BroadcastCancelledAreaList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastCancelledAreaList_ExtIEs( SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs ** data);

void __si_amf_debug_BroadcastCancelledAreaList_ExtIEs( char * key, SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs * data, int lvl);

void __si_amf_memfree_BroadcastCancelledAreaList_ExtIEs( SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_BroadcastCancelledAreaList_ExtIEs( SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDBroadcastEUTRA( SI_AMF_DT_CellIDBroadcastEUTRA ** data);

void __si_amf_debug_CellIDBroadcastEUTRA( char * key, SI_AMF_DT_CellIDBroadcastEUTRA * data, int lvl);

void __si_amf_memfree_CellIDBroadcastEUTRA( SI_AMF_DT_CellIDBroadcastEUTRA * data);

int __si_amf_Encode_CellIDBroadcastEUTRA( SI_AMF_DT_CellIDBroadcastEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIBroadcastEUTRA( SI_AMF_DT_TAIBroadcastEUTRA ** data);

void __si_amf_debug_TAIBroadcastEUTRA( char * key, SI_AMF_DT_TAIBroadcastEUTRA * data, int lvl);

void __si_amf_memfree_TAIBroadcastEUTRA( SI_AMF_DT_TAIBroadcastEUTRA * data);

int __si_amf_Encode_TAIBroadcastEUTRA( SI_AMF_DT_TAIBroadcastEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDBroadcastEUTRA( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA ** data);

void __si_amf_debug_EmergencyAreaIDBroadcastEUTRA( char * key, SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDBroadcastEUTRA( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA * data);

int __si_amf_Encode_EmergencyAreaIDBroadcastEUTRA( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDBroadcastNR( SI_AMF_DT_CellIDBroadcastNR ** data);

void __si_amf_debug_CellIDBroadcastNR( char * key, SI_AMF_DT_CellIDBroadcastNR * data, int lvl);

void __si_amf_memfree_CellIDBroadcastNR( SI_AMF_DT_CellIDBroadcastNR * data);

int __si_amf_Encode_CellIDBroadcastNR( SI_AMF_DT_CellIDBroadcastNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIBroadcastNR( SI_AMF_DT_TAIBroadcastNR ** data);

void __si_amf_debug_TAIBroadcastNR( char * key, SI_AMF_DT_TAIBroadcastNR * data, int lvl);

void __si_amf_memfree_TAIBroadcastNR( SI_AMF_DT_TAIBroadcastNR * data);

int __si_amf_Encode_TAIBroadcastNR( SI_AMF_DT_TAIBroadcastNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDBroadcastNR( SI_AMF_DT_EmergencyAreaIDBroadcastNR ** data);

void __si_amf_debug_EmergencyAreaIDBroadcastNR( char * key, SI_AMF_DT_EmergencyAreaIDBroadcastNR * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDBroadcastNR( SI_AMF_DT_EmergencyAreaIDBroadcastNR * data);

int __si_amf_Encode_EmergencyAreaIDBroadcastNR( SI_AMF_DT_EmergencyAreaIDBroadcastNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastCompletedAreaList( SI_AMF_DT_BroadcastCompletedAreaList ** data);

void __si_amf_debug_BroadcastCompletedAreaList( char * key, SI_AMF_DT_BroadcastCompletedAreaList * data, int lvl);

void __si_amf_memfree_BroadcastCompletedAreaList( SI_AMF_DT_BroadcastCompletedAreaList * data);

int __si_amf_Encode_BroadcastCompletedAreaList( SI_AMF_DT_BroadcastCompletedAreaList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastCompletedAreaList_ExtIEs( SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs ** data);

void __si_amf_debug_BroadcastCompletedAreaList_ExtIEs( char * key, SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs * data, int lvl);

void __si_amf_memfree_BroadcastCompletedAreaList_ExtIEs( SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_BroadcastCompletedAreaList_ExtIEs( SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastPLMNList( SI_AMF_DT_BroadcastPLMNList ** data);

void __si_amf_debug_BroadcastPLMNList( char * key, SI_AMF_DT_BroadcastPLMNList * data, int lvl);

void __si_amf_memfree_BroadcastPLMNList( SI_AMF_DT_BroadcastPLMNList * data);

int __si_amf_Encode_BroadcastPLMNList( SI_AMF_DT_BroadcastPLMNList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SliceSupportList( SI_AMF_DT_SliceSupportList ** data);

void __si_amf_debug_SliceSupportList( char * key, SI_AMF_DT_SliceSupportList * data, int lvl);

void __si_amf_memfree_SliceSupportList( SI_AMF_DT_SliceSupportList * data);

int __si_amf_Encode_SliceSupportList( SI_AMF_DT_SliceSupportList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastPLMNItem( SI_AMF_DT_BroadcastPLMNItem ** data);

void __si_amf_debug_BroadcastPLMNItem( char * key, SI_AMF_DT_BroadcastPLMNItem * data, int lvl);

void __si_amf_memfree_BroadcastPLMNItem( SI_AMF_DT_BroadcastPLMNItem * data);

int __si_amf_Encode_BroadcastPLMNItem( SI_AMF_DT_BroadcastPLMNItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_BroadcastPLMNItem_ExtIEs( SI_AMF_DT_BroadcastPLMNItem_ExtIEs ** data);

void __si_amf_debug_BroadcastPLMNItem_ExtIEs( char * key, SI_AMF_DT_BroadcastPLMNItem_ExtIEs * data, int lvl);

void __si_amf_memfree_BroadcastPLMNItem_ExtIEs( SI_AMF_DT_BroadcastPLMNItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_BroadcastPLMNItem_ExtIEs( SI_AMF_DT_BroadcastPLMNItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CancelAllWarningMessages( char * key, uint8_t eCancelAllWarningMessages, int lvl);

int __si_amf_Encode_CancelAllWarningMessages( uint8_t eCancelAllWarningMessages, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInEAI_EUTRA( SI_AMF_DT_CancelledCellsInEAI_EUTRA ** data);

void __si_amf_debug_CancelledCellsInEAI_EUTRA( char * key, SI_AMF_DT_CancelledCellsInEAI_EUTRA * data, int lvl);

void __si_amf_memfree_CancelledCellsInEAI_EUTRA( SI_AMF_DT_CancelledCellsInEAI_EUTRA * data);

int __si_amf_Encode_CancelledCellsInEAI_EUTRA( SI_AMF_DT_CancelledCellsInEAI_EUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NumberOfBroadcasts( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_NumberOfBroadcasts( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInEAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item ** data);

void __si_amf_debug_CancelledCellsInEAI_EUTRA_Item( char * key, SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item * data, int lvl);

void __si_amf_memfree_CancelledCellsInEAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item * data);

int __si_amf_Encode_CancelledCellsInEAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs ** data);

void __si_amf_debug_CancelledCellsInEAI_EUTRA_Item_ExtIEs( char * key, SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CancelledCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CancelledCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInEAI_NR( SI_AMF_DT_CancelledCellsInEAI_NR ** data);

void __si_amf_debug_CancelledCellsInEAI_NR( char * key, SI_AMF_DT_CancelledCellsInEAI_NR * data, int lvl);

void __si_amf_memfree_CancelledCellsInEAI_NR( SI_AMF_DT_CancelledCellsInEAI_NR * data);

int __si_amf_Encode_CancelledCellsInEAI_NR( SI_AMF_DT_CancelledCellsInEAI_NR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInEAI_NR_Item( SI_AMF_DT_CancelledCellsInEAI_NR_Item ** data);

void __si_amf_debug_CancelledCellsInEAI_NR_Item( char * key, SI_AMF_DT_CancelledCellsInEAI_NR_Item * data, int lvl);

void __si_amf_memfree_CancelledCellsInEAI_NR_Item( SI_AMF_DT_CancelledCellsInEAI_NR_Item * data);

int __si_amf_Encode_CancelledCellsInEAI_NR_Item( SI_AMF_DT_CancelledCellsInEAI_NR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs ** data);

void __si_amf_debug_CancelledCellsInEAI_NR_Item_ExtIEs( char * key, SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CancelledCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CancelledCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInTAI_EUTRA( SI_AMF_DT_CancelledCellsInTAI_EUTRA ** data);

void __si_amf_debug_CancelledCellsInTAI_EUTRA( char * key, SI_AMF_DT_CancelledCellsInTAI_EUTRA * data, int lvl);

void __si_amf_memfree_CancelledCellsInTAI_EUTRA( SI_AMF_DT_CancelledCellsInTAI_EUTRA * data);

int __si_amf_Encode_CancelledCellsInTAI_EUTRA( SI_AMF_DT_CancelledCellsInTAI_EUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInTAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item ** data);

void __si_amf_debug_CancelledCellsInTAI_EUTRA_Item( char * key, SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item * data, int lvl);

void __si_amf_memfree_CancelledCellsInTAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item * data);

int __si_amf_Encode_CancelledCellsInTAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs ** data);

void __si_amf_debug_CancelledCellsInTAI_EUTRA_Item_ExtIEs( char * key, SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CancelledCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CancelledCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInTAI_NR( SI_AMF_DT_CancelledCellsInTAI_NR ** data);

void __si_amf_debug_CancelledCellsInTAI_NR( char * key, SI_AMF_DT_CancelledCellsInTAI_NR * data, int lvl);

void __si_amf_memfree_CancelledCellsInTAI_NR( SI_AMF_DT_CancelledCellsInTAI_NR * data);

int __si_amf_Encode_CancelledCellsInTAI_NR( SI_AMF_DT_CancelledCellsInTAI_NR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInTAI_NR_Item( SI_AMF_DT_CancelledCellsInTAI_NR_Item ** data);

void __si_amf_debug_CancelledCellsInTAI_NR_Item( char * key, SI_AMF_DT_CancelledCellsInTAI_NR_Item * data, int lvl);

void __si_amf_memfree_CancelledCellsInTAI_NR_Item( SI_AMF_DT_CancelledCellsInTAI_NR_Item * data);

int __si_amf_Encode_CancelledCellsInTAI_NR_Item( SI_AMF_DT_CancelledCellsInTAI_NR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CancelledCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs ** data);

void __si_amf_debug_CancelledCellsInTAI_NR_Item_ExtIEs( char * key, SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CancelledCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CancelledCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CauseRadioNetwork( char * key, uint8_t eCauseRadioNetwork, int lvl);

int __si_amf_Encode_CauseRadioNetwork( uint8_t eCauseRadioNetwork, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CauseTransport( char * key, uint8_t eCauseTransport, int lvl);

int __si_amf_Encode_CauseTransport( uint8_t eCauseTransport, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CauseNas( char * key, uint8_t eCauseNas, int lvl);

int __si_amf_Encode_CauseNas( uint8_t eCauseNas, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CauseProtocol( char * key, uint8_t eCauseProtocol, int lvl);

int __si_amf_Encode_CauseProtocol( uint8_t eCauseProtocol, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CauseMisc( char * key, uint8_t eCauseMisc, int lvl);

int __si_amf_Encode_CauseMisc( uint8_t eCauseMisc, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_Cause( SI_AMF_DT_Cause ** data);

void __si_amf_debug_Cause( char * key, SI_AMF_DT_Cause * data, int lvl);

void __si_amf_memfree_Cause( SI_AMF_DT_Cause * data);

int __si_amf_Encode_Cause( SI_AMF_DT_Cause * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_Cause_ExtIEs( SI_AMF_DT_Cause_ExtIEs ** data);

void __si_amf_debug_Cause_ExtIEs( char * key, SI_AMF_DT_Cause_ExtIEs * data, int lvl);

void __si_amf_memfree_Cause_ExtIEs( SI_AMF_DT_Cause_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_Cause_ExtIEs( SI_AMF_DT_Cause_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDBroadcastEUTRA_Item( SI_AMF_DT_CellIDBroadcastEUTRA_Item ** data);

void __si_amf_debug_CellIDBroadcastEUTRA_Item( char * key, SI_AMF_DT_CellIDBroadcastEUTRA_Item * data, int lvl);

void __si_amf_memfree_CellIDBroadcastEUTRA_Item( SI_AMF_DT_CellIDBroadcastEUTRA_Item * data);

int __si_amf_Encode_CellIDBroadcastEUTRA_Item( SI_AMF_DT_CellIDBroadcastEUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs ** data);

void __si_amf_debug_CellIDBroadcastEUTRA_Item_ExtIEs( char * key, SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CellIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CellIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDBroadcastNR_Item( SI_AMF_DT_CellIDBroadcastNR_Item ** data);

void __si_amf_debug_CellIDBroadcastNR_Item( char * key, SI_AMF_DT_CellIDBroadcastNR_Item * data, int lvl);

void __si_amf_memfree_CellIDBroadcastNR_Item( SI_AMF_DT_CellIDBroadcastNR_Item * data);

int __si_amf_Encode_CellIDBroadcastNR_Item( SI_AMF_DT_CellIDBroadcastNR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs ** data);

void __si_amf_debug_CellIDBroadcastNR_Item_ExtIEs( char * key, SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CellIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CellIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDCancelledEUTRA_Item( SI_AMF_DT_CellIDCancelledEUTRA_Item ** data);

void __si_amf_debug_CellIDCancelledEUTRA_Item( char * key, SI_AMF_DT_CellIDCancelledEUTRA_Item * data, int lvl);

void __si_amf_memfree_CellIDCancelledEUTRA_Item( SI_AMF_DT_CellIDCancelledEUTRA_Item * data);

int __si_amf_Encode_CellIDCancelledEUTRA_Item( SI_AMF_DT_CellIDCancelledEUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs ** data);

void __si_amf_debug_CellIDCancelledEUTRA_Item_ExtIEs( char * key, SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CellIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CellIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDCancelledNR_Item( SI_AMF_DT_CellIDCancelledNR_Item ** data);

void __si_amf_debug_CellIDCancelledNR_Item( char * key, SI_AMF_DT_CellIDCancelledNR_Item * data, int lvl);

void __si_amf_memfree_CellIDCancelledNR_Item( SI_AMF_DT_CellIDCancelledNR_Item * data);

int __si_amf_Encode_CellIDCancelledNR_Item( SI_AMF_DT_CellIDCancelledNR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDCancelledNR_Item_ExtIEs( SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs ** data);

void __si_amf_debug_CellIDCancelledNR_Item_ExtIEs( char * key, SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CellIDCancelledNR_Item_ExtIEs( SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CellIDCancelledNR_Item_ExtIEs( SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRA_CGIList( SI_AMF_DT_EUTRA_CGIList ** data);

void __si_amf_debug_EUTRA_CGIList( char * key, SI_AMF_DT_EUTRA_CGIList * data, int lvl);

void __si_amf_memfree_EUTRA_CGIList( SI_AMF_DT_EUTRA_CGIList * data);

int __si_amf_Encode_EUTRA_CGIList( SI_AMF_DT_EUTRA_CGIList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NR_CGIList( SI_AMF_DT_NR_CGIList ** data);

void __si_amf_debug_NR_CGIList( char * key, SI_AMF_DT_NR_CGIList * data, int lvl);

void __si_amf_memfree_NR_CGIList( SI_AMF_DT_NR_CGIList * data);

int __si_amf_Encode_NR_CGIList( SI_AMF_DT_NR_CGIList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDListForRestart( SI_AMF_DT_CellIDListForRestart ** data);

void __si_amf_debug_CellIDListForRestart( char * key, SI_AMF_DT_CellIDListForRestart * data, int lvl);

void __si_amf_memfree_CellIDListForRestart( SI_AMF_DT_CellIDListForRestart * data);

int __si_amf_Encode_CellIDListForRestart( SI_AMF_DT_CellIDListForRestart * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellIDListForRestart_ExtIEs( SI_AMF_DT_CellIDListForRestart_ExtIEs ** data);

void __si_amf_debug_CellIDListForRestart_ExtIEs( char * key, SI_AMF_DT_CellIDListForRestart_ExtIEs * data, int lvl);

void __si_amf_memfree_CellIDListForRestart_ExtIEs( SI_AMF_DT_CellIDListForRestart_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_CellIDListForRestart_ExtIEs( SI_AMF_DT_CellIDListForRestart_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CellSize( char * key, uint8_t eCellSize, int lvl);

int __si_amf_Encode_CellSize( uint8_t eCellSize, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellType( SI_AMF_DT_CellType ** data);

void __si_amf_debug_CellType( char * key, SI_AMF_DT_CellType * data, int lvl);

void __si_amf_memfree_CellType( SI_AMF_DT_CellType * data);

int __si_amf_Encode_CellType( SI_AMF_DT_CellType * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CellType_ExtIEs( SI_AMF_DT_CellType_ExtIEs ** data);

void __si_amf_debug_CellType_ExtIEs( char * key, SI_AMF_DT_CellType_ExtIEs * data, int lvl);

void __si_amf_memfree_CellType_ExtIEs( SI_AMF_DT_CellType_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CellType_ExtIEs( SI_AMF_DT_CellType_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ExpectedActivityPeriod( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_ExpectedActivityPeriod( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ExpectedIdlePeriod( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_ExpectedIdlePeriod( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_SourceOfUEActivityBehaviourInformation( char * key, uint8_t eSourceOfUEActivityBehaviourInformation, int lvl);

int __si_amf_Encode_SourceOfUEActivityBehaviourInformation( uint8_t eSourceOfUEActivityBehaviourInformation, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEActivityBehaviour( SI_AMF_DT_ExpectedUEActivityBehaviour ** data);

void __si_amf_debug_ExpectedUEActivityBehaviour( char * key, SI_AMF_DT_ExpectedUEActivityBehaviour * data, int lvl);

void __si_amf_memfree_ExpectedUEActivityBehaviour( SI_AMF_DT_ExpectedUEActivityBehaviour * data);

int __si_amf_Encode_ExpectedUEActivityBehaviour( SI_AMF_DT_ExpectedUEActivityBehaviour * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ExpectedHOInterval( char * key, uint8_t eExpectedHOInterval, int lvl);

int __si_amf_Encode_ExpectedHOInterval( uint8_t eExpectedHOInterval, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ExpectedUEMobility( char * key, uint8_t eExpectedUEMobility, int lvl);

int __si_amf_Encode_ExpectedUEMobility( uint8_t eExpectedUEMobility, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEMovingTrajectory( SI_AMF_DT_ExpectedUEMovingTrajectory ** data);

void __si_amf_debug_ExpectedUEMovingTrajectory( char * key, SI_AMF_DT_ExpectedUEMovingTrajectory * data, int lvl);

void __si_amf_memfree_ExpectedUEMovingTrajectory( SI_AMF_DT_ExpectedUEMovingTrajectory * data);

int __si_amf_Encode_ExpectedUEMovingTrajectory( SI_AMF_DT_ExpectedUEMovingTrajectory * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEBehaviour( SI_AMF_DT_ExpectedUEBehaviour ** data);

void __si_amf_debug_ExpectedUEBehaviour( char * key, SI_AMF_DT_ExpectedUEBehaviour * data, int lvl);

void __si_amf_memfree_ExpectedUEBehaviour( SI_AMF_DT_ExpectedUEBehaviour * data);

int __si_amf_Encode_ExpectedUEBehaviour( SI_AMF_DT_ExpectedUEBehaviour * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CNAssistedRANTuning( SI_AMF_DT_CNAssistedRANTuning ** data);

void __si_amf_debug_CNAssistedRANTuning( char * key, SI_AMF_DT_CNAssistedRANTuning * data, int lvl);

void __si_amf_memfree_CNAssistedRANTuning( SI_AMF_DT_CNAssistedRANTuning * data);

int __si_amf_Encode_CNAssistedRANTuning( SI_AMF_DT_CNAssistedRANTuning * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CNAssistedRANTuning_ExtIEs( SI_AMF_DT_CNAssistedRANTuning_ExtIEs ** data);

void __si_amf_debug_CNAssistedRANTuning_ExtIEs( char * key, SI_AMF_DT_CNAssistedRANTuning_ExtIEs * data, int lvl);

void __si_amf_memfree_CNAssistedRANTuning_ExtIEs( SI_AMF_DT_CNAssistedRANTuning_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CNAssistedRANTuning_ExtIEs( SI_AMF_DT_CNAssistedRANTuning_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CNTypeRestrictionsForEquivalent( SI_AMF_DT_CNTypeRestrictionsForEquivalent ** data);

void __si_amf_debug_CNTypeRestrictionsForEquivalent( char * key, SI_AMF_DT_CNTypeRestrictionsForEquivalent * data, int lvl);

void __si_amf_memfree_CNTypeRestrictionsForEquivalent( SI_AMF_DT_CNTypeRestrictionsForEquivalent * data);

int __si_amf_Encode_CNTypeRestrictionsForEquivalent( SI_AMF_DT_CNTypeRestrictionsForEquivalent * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CNTypeRestrictionsForEquivalentItemCNType( char * key, uint8_t eCNTypeRestrictionsForEquivalentItemCNType, int lvl);

int __si_amf_Encode_CNTypeRestrictionsForEquivalentItemCNType( uint8_t eCNTypeRestrictionsForEquivalentItemCNType, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CNTypeRestrictionsForEquivalentItem( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem ** data);

void __si_amf_debug_CNTypeRestrictionsForEquivalentItem( char * key, SI_AMF_DT_CNTypeRestrictionsForEquivalentItem * data, int lvl);

void __si_amf_memfree_CNTypeRestrictionsForEquivalentItem( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem * data);

int __si_amf_Encode_CNTypeRestrictionsForEquivalentItem( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CNTypeRestrictionsForEquivalentItem_ExtIEs( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs ** data);

void __si_amf_debug_CNTypeRestrictionsForEquivalentItem_ExtIEs( char * key, SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs * data, int lvl);

void __si_amf_memfree_CNTypeRestrictionsForEquivalentItem_ExtIEs( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CNTypeRestrictionsForEquivalentItem_ExtIEs( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CNTypeRestrictionsForServing( char * key, uint8_t eCNTypeRestrictionsForServing, int lvl);

int __si_amf_Encode_CNTypeRestrictionsForServing( uint8_t eCNTypeRestrictionsForServing, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CommonNetworkInstance( SI_AMF_DT_CommonNetworkInstance ** data);

void __si_amf_init_CommonNetworkInstance2( SI_AMF_DT_CommonNetworkInstance ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_CommonNetworkInstance( char * key, SI_AMF_DT_CommonNetworkInstance * data, int lvl);

void __si_amf_memfree_CommonNetworkInstance( SI_AMF_DT_CommonNetworkInstance * data);

int __si_amf_Encode_CommonNetworkInstance( SI_AMF_DT_CommonNetworkInstance * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInEAI_EUTRA( SI_AMF_DT_CompletedCellsInEAI_EUTRA ** data);

void __si_amf_debug_CompletedCellsInEAI_EUTRA( char * key, SI_AMF_DT_CompletedCellsInEAI_EUTRA * data, int lvl);

void __si_amf_memfree_CompletedCellsInEAI_EUTRA( SI_AMF_DT_CompletedCellsInEAI_EUTRA * data);

int __si_amf_Encode_CompletedCellsInEAI_EUTRA( SI_AMF_DT_CompletedCellsInEAI_EUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInEAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item ** data);

void __si_amf_debug_CompletedCellsInEAI_EUTRA_Item( char * key, SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item * data, int lvl);

void __si_amf_memfree_CompletedCellsInEAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item * data);

int __si_amf_Encode_CompletedCellsInEAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs ** data);

void __si_amf_debug_CompletedCellsInEAI_EUTRA_Item_ExtIEs( char * key, SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CompletedCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CompletedCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInEAI_NR( SI_AMF_DT_CompletedCellsInEAI_NR ** data);

void __si_amf_debug_CompletedCellsInEAI_NR( char * key, SI_AMF_DT_CompletedCellsInEAI_NR * data, int lvl);

void __si_amf_memfree_CompletedCellsInEAI_NR( SI_AMF_DT_CompletedCellsInEAI_NR * data);

int __si_amf_Encode_CompletedCellsInEAI_NR( SI_AMF_DT_CompletedCellsInEAI_NR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInEAI_NR_Item( SI_AMF_DT_CompletedCellsInEAI_NR_Item ** data);

void __si_amf_debug_CompletedCellsInEAI_NR_Item( char * key, SI_AMF_DT_CompletedCellsInEAI_NR_Item * data, int lvl);

void __si_amf_memfree_CompletedCellsInEAI_NR_Item( SI_AMF_DT_CompletedCellsInEAI_NR_Item * data);

int __si_amf_Encode_CompletedCellsInEAI_NR_Item( SI_AMF_DT_CompletedCellsInEAI_NR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs ** data);

void __si_amf_debug_CompletedCellsInEAI_NR_Item_ExtIEs( char * key, SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CompletedCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CompletedCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInTAI_EUTRA( SI_AMF_DT_CompletedCellsInTAI_EUTRA ** data);

void __si_amf_debug_CompletedCellsInTAI_EUTRA( char * key, SI_AMF_DT_CompletedCellsInTAI_EUTRA * data, int lvl);

void __si_amf_memfree_CompletedCellsInTAI_EUTRA( SI_AMF_DT_CompletedCellsInTAI_EUTRA * data);

int __si_amf_Encode_CompletedCellsInTAI_EUTRA( SI_AMF_DT_CompletedCellsInTAI_EUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInTAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item ** data);

void __si_amf_debug_CompletedCellsInTAI_EUTRA_Item( char * key, SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item * data, int lvl);

void __si_amf_memfree_CompletedCellsInTAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item * data);

int __si_amf_Encode_CompletedCellsInTAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs ** data);

void __si_amf_debug_CompletedCellsInTAI_EUTRA_Item_ExtIEs( char * key, SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CompletedCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CompletedCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInTAI_NR( SI_AMF_DT_CompletedCellsInTAI_NR ** data);

void __si_amf_debug_CompletedCellsInTAI_NR( char * key, SI_AMF_DT_CompletedCellsInTAI_NR * data, int lvl);

void __si_amf_memfree_CompletedCellsInTAI_NR( SI_AMF_DT_CompletedCellsInTAI_NR * data);

int __si_amf_Encode_CompletedCellsInTAI_NR( SI_AMF_DT_CompletedCellsInTAI_NR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInTAI_NR_Item( SI_AMF_DT_CompletedCellsInTAI_NR_Item ** data);

void __si_amf_debug_CompletedCellsInTAI_NR_Item( char * key, SI_AMF_DT_CompletedCellsInTAI_NR_Item * data, int lvl);

void __si_amf_memfree_CompletedCellsInTAI_NR_Item( SI_AMF_DT_CompletedCellsInTAI_NR_Item * data);

int __si_amf_Encode_CompletedCellsInTAI_NR_Item( SI_AMF_DT_CompletedCellsInTAI_NR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CompletedCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs ** data);

void __si_amf_debug_CompletedCellsInTAI_NR_Item_ExtIEs( char * key, SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CompletedCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CompletedCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ConcurrentWarningMessageInd( char * key, uint8_t eConcurrentWarningMessageInd, int lvl);

int __si_amf_Encode_ConcurrentWarningMessageInd( uint8_t eConcurrentWarningMessageInd, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ConfidentialityProtectionIndication( char * key, uint8_t eConfidentialityProtectionIndication, int lvl);

int __si_amf_Encode_ConfidentialityProtectionIndication( uint8_t eConfidentialityProtectionIndication, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ConfidentialityProtectionResult( char * key, uint8_t eConfidentialityProtectionResult, int lvl);

int __si_amf_Encode_ConfidentialityProtectionResult( uint8_t eConfidentialityProtectionResult, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEIdentityIndexValueIL( SI_AMF_DT_UEIdentityIndexValueIL ** data);

void __si_amf_init_UEIdentityIndexValueIL2( SI_AMF_DT_UEIdentityIndexValueIL ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_UEIdentityIndexValueIL( char * key, SI_AMF_DT_UEIdentityIndexValueIL * data, int lvl);

void __si_amf_memfree_UEIdentityIndexValueIL( SI_AMF_DT_UEIdentityIndexValueIL * data);

int __si_amf_Encode_UEIdentityIndexValueIL( SI_AMF_DT_UEIdentityIndexValueIL * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEIdentityIndexValue( SI_AMF_DT_UEIdentityIndexValue ** data);

void __si_amf_debug_UEIdentityIndexValue( char * key, SI_AMF_DT_UEIdentityIndexValue * data, int lvl);

void __si_amf_memfree_UEIdentityIndexValue( SI_AMF_DT_UEIdentityIndexValue * data);

int __si_amf_Encode_UEIdentityIndexValue( SI_AMF_DT_UEIdentityIndexValue * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PagingDRX( char * key, uint8_t ePagingDRX, int lvl);

int __si_amf_Encode_PagingDRX( uint8_t ePagingDRX, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PeriodicRegistrationUpdateTimer( SI_AMF_DT_PeriodicRegistrationUpdateTimer ** data);

void __si_amf_init_PeriodicRegistrationUpdateTimer2( SI_AMF_DT_PeriodicRegistrationUpdateTimer ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_PeriodicRegistrationUpdateTimer( char * key, SI_AMF_DT_PeriodicRegistrationUpdateTimer * data, int lvl);

void __si_amf_memfree_PeriodicRegistrationUpdateTimer( SI_AMF_DT_PeriodicRegistrationUpdateTimer * data);

int __si_amf_Encode_PeriodicRegistrationUpdateTimer( SI_AMF_DT_PeriodicRegistrationUpdateTimer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_MICOModeIndication( char * key, uint8_t eMICOModeIndication, int lvl);

int __si_amf_Encode_MICOModeIndication( uint8_t eMICOModeIndication, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForInactive( SI_AMF_DT_TAIListForInactive ** data);

void __si_amf_debug_TAIListForInactive( char * key, SI_AMF_DT_TAIListForInactive * data, int lvl);

void __si_amf_memfree_TAIListForInactive( SI_AMF_DT_TAIListForInactive * data);

int __si_amf_Encode_TAIListForInactive( SI_AMF_DT_TAIListForInactive * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CoreNetworkAssistanceInformationForInactive( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive ** data);

void __si_amf_debug_CoreNetworkAssistanceInformationForInactive( char * key, SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * data, int lvl);

void __si_amf_memfree_CoreNetworkAssistanceInformationForInactive( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * data);

int __si_amf_Encode_CoreNetworkAssistanceInformationForInactive( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CoreNetworkAssistanceInformationForInactive_ExtIEs( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs ** data);

void __si_amf_debug_CoreNetworkAssistanceInformationForInactive_ExtIEs( char * key, SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs * data, int lvl);

void __si_amf_memfree_CoreNetworkAssistanceInformationForInactive_ExtIEs( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CoreNetworkAssistanceInformationForInactive_ExtIEs( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_COUNTValueForPDCP_SN12INT( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_COUNTValueForPDCP_SN12INT( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_COUNTValueForPDCP_SN12INT2( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_COUNTValueForPDCP_SN12INT2( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_COUNTValueForPDCP_SN12( SI_AMF_DT_COUNTValueForPDCP_SN12 ** data);

void __si_amf_debug_COUNTValueForPDCP_SN12( char * key, SI_AMF_DT_COUNTValueForPDCP_SN12 * data, int lvl);

void __si_amf_memfree_COUNTValueForPDCP_SN12( SI_AMF_DT_COUNTValueForPDCP_SN12 * data);

int __si_amf_Encode_COUNTValueForPDCP_SN12( SI_AMF_DT_COUNTValueForPDCP_SN12 * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_COUNTValueForPDCP_SN12_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs ** data);

void __si_amf_debug_COUNTValueForPDCP_SN12_ExtIEs( char * key, SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs * data, int lvl);

void __si_amf_memfree_COUNTValueForPDCP_SN12_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_COUNTValueForPDCP_SN12_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_COUNTValueForPDCP_SN18INT( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_COUNTValueForPDCP_SN18INT( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_COUNTValueForPDCP_SN18INT2( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_COUNTValueForPDCP_SN18INT2( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_COUNTValueForPDCP_SN18( SI_AMF_DT_COUNTValueForPDCP_SN18 ** data);

void __si_amf_debug_COUNTValueForPDCP_SN18( char * key, SI_AMF_DT_COUNTValueForPDCP_SN18 * data, int lvl);

void __si_amf_memfree_COUNTValueForPDCP_SN18( SI_AMF_DT_COUNTValueForPDCP_SN18 * data);

int __si_amf_Encode_COUNTValueForPDCP_SN18( SI_AMF_DT_COUNTValueForPDCP_SN18 * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_COUNTValueForPDCP_SN18_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs ** data);

void __si_amf_debug_COUNTValueForPDCP_SN18_ExtIEs( char * key, SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs * data, int lvl);

void __si_amf_memfree_COUNTValueForPDCP_SN18_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_COUNTValueForPDCP_SN18_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PortNumber( SI_AMF_DT_PortNumber ** data);

void __si_amf_init_PortNumber2( SI_AMF_DT_PortNumber ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PortNumber( char * key, SI_AMF_DT_PortNumber * data, int lvl);

void __si_amf_memfree_PortNumber( SI_AMF_DT_PortNumber * data);

int __si_amf_Encode_PortNumber( SI_AMF_DT_PortNumber * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EndpointIPAddressAndPort( SI_AMF_DT_EndpointIPAddressAndPort ** data);

void __si_amf_debug_EndpointIPAddressAndPort( char * key, SI_AMF_DT_EndpointIPAddressAndPort * data, int lvl);

void __si_amf_memfree_EndpointIPAddressAndPort( SI_AMF_DT_EndpointIPAddressAndPort * data);

int __si_amf_Encode_EndpointIPAddressAndPort( SI_AMF_DT_EndpointIPAddressAndPort * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CPTransportLayerInformation_ExtIEs( SI_AMF_DT_CPTransportLayerInformation_ExtIEs ** data);

void __si_amf_debug_CPTransportLayerInformation_ExtIEs( char * key, SI_AMF_DT_CPTransportLayerInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_CPTransportLayerInformation_ExtIEs( SI_AMF_DT_CPTransportLayerInformation_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_CPTransportLayerInformation_ExtIEs( SI_AMF_DT_CPTransportLayerInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CriticalityDiagnosticsCriticality( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_CriticalityDiagnosticsCriticality( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CriticalityDiagnosticsProcedureCode( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_CriticalityDiagnosticsProcedureCode( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CriticalityDiagnosticsTriggeringMessage( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_CriticalityDiagnosticsTriggeringMessage( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CriticalityDiagnostics_IE_List( SI_AMF_DT_CriticalityDiagnostics_IE_List ** data);

void __si_amf_debug_CriticalityDiagnostics_IE_List( char * key, SI_AMF_DT_CriticalityDiagnostics_IE_List * data, int lvl);

void __si_amf_memfree_CriticalityDiagnostics_IE_List( SI_AMF_DT_CriticalityDiagnostics_IE_List * data);

int __si_amf_Encode_CriticalityDiagnostics_IE_List( SI_AMF_DT_CriticalityDiagnostics_IE_List * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CriticalityDiagnostics( SI_AMF_DT_CriticalityDiagnostics ** data);

void __si_amf_debug_CriticalityDiagnostics( char * key, SI_AMF_DT_CriticalityDiagnostics * data, int lvl);

void __si_amf_memfree_CriticalityDiagnostics( SI_AMF_DT_CriticalityDiagnostics * data);

int __si_amf_Encode_CriticalityDiagnostics( SI_AMF_DT_CriticalityDiagnostics * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CriticalityDiagnostics_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_ExtIEs ** data);

void __si_amf_debug_CriticalityDiagnostics_ExtIEs( char * key, SI_AMF_DT_CriticalityDiagnostics_ExtIEs * data, int lvl);

void __si_amf_memfree_CriticalityDiagnostics_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CriticalityDiagnostics_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CriticalityDiagnostics_IE_Item_ProtocolIE_ID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_CriticalityDiagnostics_IE_Item_ProtocolIE_ID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_CriticalityDiagnostics_IE_Item_Criticality( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_CriticalityDiagnostics_IE_Item_Criticality( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TypeOfError( char * key, uint8_t eTypeOfError, int lvl);

int __si_amf_Encode_TypeOfError( uint8_t eTypeOfError, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CriticalityDiagnostics_IE_Item( SI_AMF_DT_CriticalityDiagnostics_IE_Item ** data);

void __si_amf_debug_CriticalityDiagnostics_IE_Item( char * key, SI_AMF_DT_CriticalityDiagnostics_IE_Item * data, int lvl);

void __si_amf_memfree_CriticalityDiagnostics_IE_Item( SI_AMF_DT_CriticalityDiagnostics_IE_Item * data);

int __si_amf_Encode_CriticalityDiagnostics_IE_Item( SI_AMF_DT_CriticalityDiagnostics_IE_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_CriticalityDiagnostics_IE_Item_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs ** data);

void __si_amf_debug_CriticalityDiagnostics_IE_Item_ExtIEs( char * key, SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_CriticalityDiagnostics_IE_Item_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_CriticalityDiagnostics_IE_Item_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DataCodingScheme( SI_AMF_DT_DataCodingScheme ** data);

void __si_amf_init_DataCodingScheme2( SI_AMF_DT_DataCodingScheme ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_DataCodingScheme( char * key, SI_AMF_DT_DataCodingScheme * data, int lvl);

void __si_amf_memfree_DataCodingScheme( SI_AMF_DT_DataCodingScheme * data);

int __si_amf_Encode_DataCodingScheme( SI_AMF_DT_DataCodingScheme * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DataForwardingAccepted( char * key, uint8_t eDataForwardingAccepted, int lvl);

int __si_amf_Encode_DataForwardingAccepted( uint8_t eDataForwardingAccepted, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DataForwardingNotPossible( char * key, uint8_t eDataForwardingNotPossible, int lvl);

int __si_amf_Encode_DataForwardingNotPossible( uint8_t eDataForwardingNotPossible, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DataForwardingResponseDRBList( SI_AMF_DT_DataForwardingResponseDRBList ** data);

void __si_amf_debug_DataForwardingResponseDRBList( char * key, SI_AMF_DT_DataForwardingResponseDRBList * data, int lvl);

void __si_amf_memfree_DataForwardingResponseDRBList( SI_AMF_DT_DataForwardingResponseDRBList * data);

int __si_amf_Encode_DataForwardingResponseDRBList( SI_AMF_DT_DataForwardingResponseDRBList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DRB_ID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_DRB_ID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DataForwardingResponseDRBItem( SI_AMF_DT_DataForwardingResponseDRBItem ** data);

void __si_amf_debug_DataForwardingResponseDRBItem( char * key, SI_AMF_DT_DataForwardingResponseDRBItem * data, int lvl);

void __si_amf_memfree_DataForwardingResponseDRBItem( SI_AMF_DT_DataForwardingResponseDRBItem * data);

int __si_amf_Encode_DataForwardingResponseDRBItem( SI_AMF_DT_DataForwardingResponseDRBItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DataForwardingResponseDRBItem_ExtIEs( SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs ** data);

void __si_amf_debug_DataForwardingResponseDRBItem_ExtIEs( char * key, SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs * data, int lvl);

void __si_amf_memfree_DataForwardingResponseDRBItem_ExtIEs( SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DataForwardingResponseDRBItem_ExtIEs( SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DelayCritical( char * key, uint8_t eDelayCritical, int lvl);

int __si_amf_Encode_DelayCritical( uint8_t eDelayCritical, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DLForwarding( char * key, uint8_t eDLForwarding, int lvl);

int __si_amf_Encode_DLForwarding( uint8_t eDLForwarding, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DL_NGU_TNLInformationReused( char * key, uint8_t eDL_NGU_TNLInformationReused, int lvl);

int __si_amf_Encode_DL_NGU_TNLInformationReused( uint8_t eDL_NGU_TNLInformationReused, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_DirectForwardingPathAvailability( char * key, uint8_t eDirectForwardingPathAvailability, int lvl);

int __si_amf_Encode_DirectForwardingPathAvailability( uint8_t eDirectForwardingPathAvailability, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBsSubjectToStatusTransferList( SI_AMF_DT_DRBsSubjectToStatusTransferList ** data);

void __si_amf_debug_DRBsSubjectToStatusTransferList( char * key, SI_AMF_DT_DRBsSubjectToStatusTransferList * data, int lvl);

void __si_amf_memfree_DRBsSubjectToStatusTransferList( SI_AMF_DT_DRBsSubjectToStatusTransferList * data);

int __si_amf_Encode_DRBsSubjectToStatusTransferList( SI_AMF_DT_DRBsSubjectToStatusTransferList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs ** data);

void __si_amf_init_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs2( SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( char * key, SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs * data, int lvl);

void __si_amf_memfree_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs * data);

int __si_amf_Encode_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL12( SI_AMF_DT_DRBStatusUL12 ** data);

void __si_amf_debug_DRBStatusUL12( char * key, SI_AMF_DT_DRBStatusUL12 * data, int lvl);

void __si_amf_memfree_DRBStatusUL12( SI_AMF_DT_DRBStatusUL12 * data);

int __si_amf_Encode_DRBStatusUL12( SI_AMF_DT_DRBStatusUL12 * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs ** data);

void __si_amf_init_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs2( SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( char * key, SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs * data, int lvl);

void __si_amf_memfree_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs * data);

int __si_amf_Encode_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL18( SI_AMF_DT_DRBStatusUL18 ** data);

void __si_amf_debug_DRBStatusUL18( char * key, SI_AMF_DT_DRBStatusUL18 * data, int lvl);

void __si_amf_memfree_DRBStatusUL18( SI_AMF_DT_DRBStatusUL18 * data);

int __si_amf_Encode_DRBStatusUL18( SI_AMF_DT_DRBStatusUL18 * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL( SI_AMF_DT_DRBStatusUL ** data);

void __si_amf_debug_DRBStatusUL( char * key, SI_AMF_DT_DRBStatusUL * data, int lvl);

void __si_amf_memfree_DRBStatusUL( SI_AMF_DT_DRBStatusUL * data);

int __si_amf_Encode_DRBStatusUL( SI_AMF_DT_DRBStatusUL * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusDL12( SI_AMF_DT_DRBStatusDL12 ** data);

void __si_amf_debug_DRBStatusDL12( char * key, SI_AMF_DT_DRBStatusDL12 * data, int lvl);

void __si_amf_memfree_DRBStatusDL12( SI_AMF_DT_DRBStatusDL12 * data);

int __si_amf_Encode_DRBStatusDL12( SI_AMF_DT_DRBStatusDL12 * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusDL18( SI_AMF_DT_DRBStatusDL18 ** data);

void __si_amf_debug_DRBStatusDL18( char * key, SI_AMF_DT_DRBStatusDL18 * data, int lvl);

void __si_amf_memfree_DRBStatusDL18( SI_AMF_DT_DRBStatusDL18 * data);

int __si_amf_Encode_DRBStatusDL18( SI_AMF_DT_DRBStatusDL18 * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusDL( SI_AMF_DT_DRBStatusDL ** data);

void __si_amf_debug_DRBStatusDL( char * key, SI_AMF_DT_DRBStatusDL * data, int lvl);

void __si_amf_memfree_DRBStatusDL( SI_AMF_DT_DRBStatusDL * data);

int __si_amf_Encode_DRBStatusDL( SI_AMF_DT_DRBStatusDL * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBsSubjectToStatusTransferItem( SI_AMF_DT_DRBsSubjectToStatusTransferItem ** data);

void __si_amf_debug_DRBsSubjectToStatusTransferItem( char * key, SI_AMF_DT_DRBsSubjectToStatusTransferItem * data, int lvl);

void __si_amf_memfree_DRBsSubjectToStatusTransferItem( SI_AMF_DT_DRBsSubjectToStatusTransferItem * data);

int __si_amf_Encode_DRBsSubjectToStatusTransferItem( SI_AMF_DT_DRBsSubjectToStatusTransferItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBsSubjectToStatusTransferItem_ExtIEs( SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs ** data);

void __si_amf_debug_DRBsSubjectToStatusTransferItem_ExtIEs( char * key, SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBsSubjectToStatusTransferItem_ExtIEs( SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DRBsSubjectToStatusTransferItem_ExtIEs( SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusDL_ExtIEs( SI_AMF_DT_DRBStatusDL_ExtIEs ** data);

void __si_amf_debug_DRBStatusDL_ExtIEs( char * key, SI_AMF_DT_DRBStatusDL_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBStatusDL_ExtIEs( SI_AMF_DT_DRBStatusDL_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_DRBStatusDL_ExtIEs( SI_AMF_DT_DRBStatusDL_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusDL12_ExtIEs( SI_AMF_DT_DRBStatusDL12_ExtIEs ** data);

void __si_amf_debug_DRBStatusDL12_ExtIEs( char * key, SI_AMF_DT_DRBStatusDL12_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBStatusDL12_ExtIEs( SI_AMF_DT_DRBStatusDL12_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DRBStatusDL12_ExtIEs( SI_AMF_DT_DRBStatusDL12_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusDL18_ExtIEs( SI_AMF_DT_DRBStatusDL18_ExtIEs ** data);

void __si_amf_debug_DRBStatusDL18_ExtIEs( char * key, SI_AMF_DT_DRBStatusDL18_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBStatusDL18_ExtIEs( SI_AMF_DT_DRBStatusDL18_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DRBStatusDL18_ExtIEs( SI_AMF_DT_DRBStatusDL18_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL_ExtIEs( SI_AMF_DT_DRBStatusUL_ExtIEs ** data);

void __si_amf_debug_DRBStatusUL_ExtIEs( char * key, SI_AMF_DT_DRBStatusUL_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBStatusUL_ExtIEs( SI_AMF_DT_DRBStatusUL_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_DRBStatusUL_ExtIEs( SI_AMF_DT_DRBStatusUL_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL12_ExtIEs( SI_AMF_DT_DRBStatusUL12_ExtIEs ** data);

void __si_amf_debug_DRBStatusUL12_ExtIEs( char * key, SI_AMF_DT_DRBStatusUL12_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBStatusUL12_ExtIEs( SI_AMF_DT_DRBStatusUL12_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DRBStatusUL12_ExtIEs( SI_AMF_DT_DRBStatusUL12_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBStatusUL18_ExtIEs( SI_AMF_DT_DRBStatusUL18_ExtIEs ** data);

void __si_amf_debug_DRBStatusUL18_ExtIEs( char * key, SI_AMF_DT_DRBStatusUL18_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBStatusUL18_ExtIEs( SI_AMF_DT_DRBStatusUL18_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DRBStatusUL18_ExtIEs( SI_AMF_DT_DRBStatusUL18_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBsToQosFlowsMappingList( SI_AMF_DT_DRBsToQosFlowsMappingList ** data);

void __si_amf_debug_DRBsToQosFlowsMappingList( char * key, SI_AMF_DT_DRBsToQosFlowsMappingList * data, int lvl);

void __si_amf_memfree_DRBsToQosFlowsMappingList( SI_AMF_DT_DRBsToQosFlowsMappingList * data);

int __si_amf_Encode_DRBsToQosFlowsMappingList( SI_AMF_DT_DRBsToQosFlowsMappingList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBsToQosFlowsMappingItem( SI_AMF_DT_DRBsToQosFlowsMappingItem ** data);

void __si_amf_debug_DRBsToQosFlowsMappingItem( char * key, SI_AMF_DT_DRBsToQosFlowsMappingItem * data, int lvl);

void __si_amf_memfree_DRBsToQosFlowsMappingItem( SI_AMF_DT_DRBsToQosFlowsMappingItem * data);

int __si_amf_Encode_DRBsToQosFlowsMappingItem( SI_AMF_DT_DRBsToQosFlowsMappingItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_DRBsToQosFlowsMappingItem_ExtIEs( SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs ** data);

void __si_amf_debug_DRBsToQosFlowsMappingItem_ExtIEs( char * key, SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs * data, int lvl);

void __si_amf_memfree_DRBsToQosFlowsMappingItem_ExtIEs( SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_DRBsToQosFlowsMappingItem_ExtIEs( SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PriorityLevelQos( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PriorityLevelQos( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PacketDelayBudget( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PacketDelayBudget( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PacketErrorRateInt( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PacketErrorRateInt( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PacketErrorRate( SI_AMF_DT_PacketErrorRate ** data);

void __si_amf_debug_PacketErrorRate( char * key, SI_AMF_DT_PacketErrorRate * data, int lvl);

void __si_amf_memfree_PacketErrorRate( SI_AMF_DT_PacketErrorRate * data);

int __si_amf_Encode_PacketErrorRate( SI_AMF_DT_PacketErrorRate * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_FiveQI( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_FiveQI( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_MaximumDataBurstVolume( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_MaximumDataBurstVolume( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_Dynamic5QIDescriptor( SI_AMF_DT_Dynamic5QIDescriptor ** data);

void __si_amf_debug_Dynamic5QIDescriptor( char * key, SI_AMF_DT_Dynamic5QIDescriptor * data, int lvl);

void __si_amf_memfree_Dynamic5QIDescriptor( SI_AMF_DT_Dynamic5QIDescriptor * data);

int __si_amf_Encode_Dynamic5QIDescriptor( SI_AMF_DT_Dynamic5QIDescriptor * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_Dynamic5QIDescriptor_ExtIEs( SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs ** data);

void __si_amf_debug_Dynamic5QIDescriptor_ExtIEs( char * key, SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs * data, int lvl);

void __si_amf_memfree_Dynamic5QIDescriptor_ExtIEs( SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_Dynamic5QIDescriptor_ExtIEs( SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaID( SI_AMF_DT_EmergencyAreaID ** data);

void __si_amf_init_EmergencyAreaID2( SI_AMF_DT_EmergencyAreaID ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_EmergencyAreaID( char * key, SI_AMF_DT_EmergencyAreaID * data, int lvl);

void __si_amf_memfree_EmergencyAreaID( SI_AMF_DT_EmergencyAreaID * data);

int __si_amf_Encode_EmergencyAreaID( SI_AMF_DT_EmergencyAreaID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDBroadcastEUTRA_Item( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item ** data);

void __si_amf_debug_EmergencyAreaIDBroadcastEUTRA_Item( char * key, SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDBroadcastEUTRA_Item( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item * data);

int __si_amf_Encode_EmergencyAreaIDBroadcastEUTRA_Item( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs ** data);

void __si_amf_debug_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( char * key, SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDBroadcastNR_Item( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item ** data);

void __si_amf_debug_EmergencyAreaIDBroadcastNR_Item( char * key, SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDBroadcastNR_Item( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item * data);

int __si_amf_Encode_EmergencyAreaIDBroadcastNR_Item( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs ** data);

void __si_amf_debug_EmergencyAreaIDBroadcastNR_Item_ExtIEs( char * key, SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EmergencyAreaIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDCancelledEUTRA_Item( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item ** data);

void __si_amf_debug_EmergencyAreaIDCancelledEUTRA_Item( char * key, SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDCancelledEUTRA_Item( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item * data);

int __si_amf_Encode_EmergencyAreaIDCancelledEUTRA_Item( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs ** data);

void __si_amf_debug_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( char * key, SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDCancelledNR_Item( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item ** data);

void __si_amf_debug_EmergencyAreaIDCancelledNR_Item( char * key, SI_AMF_DT_EmergencyAreaIDCancelledNR_Item * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDCancelledNR_Item( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item * data);

int __si_amf_Encode_EmergencyAreaIDCancelledNR_Item( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDCancelledNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs ** data);

void __si_amf_debug_EmergencyAreaIDCancelledNR_Item_ExtIEs( char * key, SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDCancelledNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EmergencyAreaIDCancelledNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDList( SI_AMF_DT_EmergencyAreaIDList ** data);

void __si_amf_debug_EmergencyAreaIDList( char * key, SI_AMF_DT_EmergencyAreaIDList * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDList( SI_AMF_DT_EmergencyAreaIDList * data);

int __si_amf_Encode_EmergencyAreaIDList( SI_AMF_DT_EmergencyAreaIDList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyAreaIDListForRestart( SI_AMF_DT_EmergencyAreaIDListForRestart ** data);

void __si_amf_debug_EmergencyAreaIDListForRestart( char * key, SI_AMF_DT_EmergencyAreaIDListForRestart * data, int lvl);

void __si_amf_memfree_EmergencyAreaIDListForRestart( SI_AMF_DT_EmergencyAreaIDListForRestart * data);

int __si_amf_Encode_EmergencyAreaIDListForRestart( SI_AMF_DT_EmergencyAreaIDListForRestart * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_EmergencyFallbackRequestIndicator( char * key, uint8_t eEmergencyFallbackRequestIndicator, int lvl);

int __si_amf_Encode_EmergencyFallbackRequestIndicator( uint8_t eEmergencyFallbackRequestIndicator, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_EmergencyServiceTargetCN( char * key, uint8_t eEmergencyServiceTargetCN, int lvl);

int __si_amf_Encode_EmergencyServiceTargetCN( uint8_t eEmergencyServiceTargetCN, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyFallbackIndicator( SI_AMF_DT_EmergencyFallbackIndicator ** data);

void __si_amf_debug_EmergencyFallbackIndicator( char * key, SI_AMF_DT_EmergencyFallbackIndicator * data, int lvl);

void __si_amf_memfree_EmergencyFallbackIndicator( SI_AMF_DT_EmergencyFallbackIndicator * data);

int __si_amf_Encode_EmergencyFallbackIndicator( SI_AMF_DT_EmergencyFallbackIndicator * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EmergencyFallbackIndicator_ExtIEs( SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs ** data);

void __si_amf_debug_EmergencyFallbackIndicator_ExtIEs( char * key, SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs * data, int lvl);

void __si_amf_memfree_EmergencyFallbackIndicator_ExtIEs( SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EmergencyFallbackIndicator_ExtIEs( SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EN_DCSONConfigurationTransfer( SI_AMF_DT_EN_DCSONConfigurationTransfer ** data);

void __si_amf_init_EN_DCSONConfigurationTransfer2( SI_AMF_DT_EN_DCSONConfigurationTransfer ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_EN_DCSONConfigurationTransfer( char * key, SI_AMF_DT_EN_DCSONConfigurationTransfer * data, int lvl);

void __si_amf_memfree_EN_DCSONConfigurationTransfer( SI_AMF_DT_EN_DCSONConfigurationTransfer * data);

int __si_amf_Encode_EN_DCSONConfigurationTransfer( SI_AMF_DT_EN_DCSONConfigurationTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EndpointIPAddressAndPort_ExtIEs( SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs ** data);

void __si_amf_debug_EndpointIPAddressAndPort_ExtIEs( char * key, SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs * data, int lvl);

void __si_amf_memfree_EndpointIPAddressAndPort_ExtIEs( SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EndpointIPAddressAndPort_ExtIEs( SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EquivalentPLMNs( SI_AMF_DT_EquivalentPLMNs ** data);

void __si_amf_debug_EquivalentPLMNs( char * key, SI_AMF_DT_EquivalentPLMNs * data, int lvl);

void __si_amf_memfree_EquivalentPLMNs( SI_AMF_DT_EquivalentPLMNs * data);

int __si_amf_Encode_EquivalentPLMNs( SI_AMF_DT_EquivalentPLMNs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EPS_TAC( SI_AMF_DT_EPS_TAC ** data);

void __si_amf_init_EPS_TAC2( SI_AMF_DT_EPS_TAC ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_EPS_TAC( char * key, SI_AMF_DT_EPS_TAC * data, int lvl);

void __si_amf_memfree_EPS_TAC( SI_AMF_DT_EPS_TAC * data);

int __si_amf_Encode_EPS_TAC( SI_AMF_DT_EPS_TAC * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EPS_TAI( SI_AMF_DT_EPS_TAI ** data);

void __si_amf_debug_EPS_TAI( char * key, SI_AMF_DT_EPS_TAI * data, int lvl);

void __si_amf_memfree_EPS_TAI( SI_AMF_DT_EPS_TAI * data);

int __si_amf_Encode_EPS_TAI( SI_AMF_DT_EPS_TAI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EPS_TAI_ExtIEs( SI_AMF_DT_EPS_TAI_ExtIEs ** data);

void __si_amf_debug_EPS_TAI_ExtIEs( char * key, SI_AMF_DT_EPS_TAI_ExtIEs * data, int lvl);

void __si_amf_memfree_EPS_TAI_ExtIEs( SI_AMF_DT_EPS_TAI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EPS_TAI_ExtIEs( SI_AMF_DT_EPS_TAI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_E_RAB_ID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_E_RAB_ID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_E_RABInformationList( SI_AMF_DT_E_RABInformationList ** data);

void __si_amf_debug_E_RABInformationList( char * key, SI_AMF_DT_E_RABInformationList * data, int lvl);

void __si_amf_memfree_E_RABInformationList( SI_AMF_DT_E_RABInformationList * data);

int __si_amf_Encode_E_RABInformationList( SI_AMF_DT_E_RABInformationList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_E_RABInformationItem( SI_AMF_DT_E_RABInformationItem ** data);

void __si_amf_debug_E_RABInformationItem( char * key, SI_AMF_DT_E_RABInformationItem * data, int lvl);

void __si_amf_memfree_E_RABInformationItem( SI_AMF_DT_E_RABInformationItem * data);

int __si_amf_Encode_E_RABInformationItem( SI_AMF_DT_E_RABInformationItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_E_RABInformationItem_ExtIEs( SI_AMF_DT_E_RABInformationItem_ExtIEs ** data);

void __si_amf_debug_E_RABInformationItem_ExtIEs( char * key, SI_AMF_DT_E_RABInformationItem_ExtIEs * data, int lvl);

void __si_amf_memfree_E_RABInformationItem_ExtIEs( SI_AMF_DT_E_RABInformationItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_E_RABInformationItem_ExtIEs( SI_AMF_DT_E_RABInformationItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRA_CGI_ExtIEs( SI_AMF_DT_EUTRA_CGI_ExtIEs ** data);

void __si_amf_debug_EUTRA_CGI_ExtIEs( char * key, SI_AMF_DT_EUTRA_CGI_ExtIEs * data, int lvl);

void __si_amf_memfree_EUTRA_CGI_ExtIEs( SI_AMF_DT_EUTRA_CGI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_EUTRA_CGI_ExtIEs( SI_AMF_DT_EUTRA_CGI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRA_CGIListForWarning( SI_AMF_DT_EUTRA_CGIListForWarning ** data);

void __si_amf_debug_EUTRA_CGIListForWarning( char * key, SI_AMF_DT_EUTRA_CGIListForWarning * data, int lvl);

void __si_amf_memfree_EUTRA_CGIListForWarning( SI_AMF_DT_EUTRA_CGIListForWarning * data);

int __si_amf_Encode_EUTRA_CGIListForWarning( SI_AMF_DT_EUTRA_CGIListForWarning * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRAencryptionAlgorithms( SI_AMF_DT_EUTRAencryptionAlgorithms ** data);

void __si_amf_init_EUTRAencryptionAlgorithms2( SI_AMF_DT_EUTRAencryptionAlgorithms ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_EUTRAencryptionAlgorithms( char * key, SI_AMF_DT_EUTRAencryptionAlgorithms * data, int lvl);

void __si_amf_memfree_EUTRAencryptionAlgorithms( SI_AMF_DT_EUTRAencryptionAlgorithms * data);

int __si_amf_Encode_EUTRAencryptionAlgorithms( SI_AMF_DT_EUTRAencryptionAlgorithms * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_EUTRAintegrityProtectionAlgorithms( SI_AMF_DT_EUTRAintegrityProtectionAlgorithms ** data);

void __si_amf_init_EUTRAintegrityProtectionAlgorithms2( SI_AMF_DT_EUTRAintegrityProtectionAlgorithms ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_EUTRAintegrityProtectionAlgorithms( char * key, SI_AMF_DT_EUTRAintegrityProtectionAlgorithms * data, int lvl);

void __si_amf_memfree_EUTRAintegrityProtectionAlgorithms( SI_AMF_DT_EUTRAintegrityProtectionAlgorithms * data);

int __si_amf_Encode_EUTRAintegrityProtectionAlgorithms( SI_AMF_DT_EUTRAintegrityProtectionAlgorithms * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_EventType( char * key, uint8_t eEventType, int lvl);

int __si_amf_Encode_EventType( uint8_t eEventType, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEActivityBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs ** data);

void __si_amf_debug_ExpectedUEActivityBehaviour_ExtIEs( char * key, SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs * data, int lvl);

void __si_amf_memfree_ExpectedUEActivityBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_ExpectedUEActivityBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEBehaviour_ExtIEs ** data);

void __si_amf_debug_ExpectedUEBehaviour_ExtIEs( char * key, SI_AMF_DT_ExpectedUEBehaviour_ExtIEs * data, int lvl);

void __si_amf_memfree_ExpectedUEBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEBehaviour_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_ExpectedUEBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEBehaviour_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ExpectedUEMovingTrajectoryItemTime( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_ExpectedUEMovingTrajectoryItemTime( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEMovingTrajectoryItem( SI_AMF_DT_ExpectedUEMovingTrajectoryItem ** data);

void __si_amf_debug_ExpectedUEMovingTrajectoryItem( char * key, SI_AMF_DT_ExpectedUEMovingTrajectoryItem * data, int lvl);

void __si_amf_memfree_ExpectedUEMovingTrajectoryItem( SI_AMF_DT_ExpectedUEMovingTrajectoryItem * data);

int __si_amf_Encode_ExpectedUEMovingTrajectoryItem( SI_AMF_DT_ExpectedUEMovingTrajectoryItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ExpectedUEMovingTrajectoryItem_ExtIEs( SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs ** data);

void __si_amf_debug_ExpectedUEMovingTrajectoryItem_ExtIEs( char * key, SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs * data, int lvl);

void __si_amf_memfree_ExpectedUEMovingTrajectoryItem_ExtIEs( SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_ExpectedUEMovingTrajectoryItem_ExtIEs( SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_FiveG_TMSI( SI_AMF_DT_FiveG_TMSI ** data);

void __si_amf_init_FiveG_TMSI2( SI_AMF_DT_FiveG_TMSI ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_FiveG_TMSI( char * key, SI_AMF_DT_FiveG_TMSI * data, int lvl);

void __si_amf_memfree_FiveG_TMSI( SI_AMF_DT_FiveG_TMSI * data);

int __si_amf_Encode_FiveG_TMSI( SI_AMF_DT_FiveG_TMSI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_FiveG_S_TMSI( SI_AMF_DT_FiveG_S_TMSI ** data);

void __si_amf_debug_FiveG_S_TMSI( char * key, SI_AMF_DT_FiveG_S_TMSI * data, int lvl);

void __si_amf_memfree_FiveG_S_TMSI( SI_AMF_DT_FiveG_S_TMSI * data);

int __si_amf_Encode_FiveG_S_TMSI( SI_AMF_DT_FiveG_S_TMSI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_FiveG_S_TMSI_ExtIEs( SI_AMF_DT_FiveG_S_TMSI_ExtIEs ** data);

void __si_amf_debug_FiveG_S_TMSI_ExtIEs( char * key, SI_AMF_DT_FiveG_S_TMSI_ExtIEs * data, int lvl);

void __si_amf_memfree_FiveG_S_TMSI_ExtIEs( SI_AMF_DT_FiveG_S_TMSI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_FiveG_S_TMSI_ExtIEs( SI_AMF_DT_FiveG_S_TMSI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ForbiddenAreaInformation( SI_AMF_DT_ForbiddenAreaInformation ** data);

void __si_amf_debug_ForbiddenAreaInformation( char * key, SI_AMF_DT_ForbiddenAreaInformation * data, int lvl);

void __si_amf_memfree_ForbiddenAreaInformation( SI_AMF_DT_ForbiddenAreaInformation * data);

int __si_amf_Encode_ForbiddenAreaInformation( SI_AMF_DT_ForbiddenAreaInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ForbiddenTACs( SI_AMF_DT_ForbiddenTACs ** data);

void __si_amf_debug_ForbiddenTACs( char * key, SI_AMF_DT_ForbiddenTACs * data, int lvl);

void __si_amf_memfree_ForbiddenTACs( SI_AMF_DT_ForbiddenTACs * data);

int __si_amf_Encode_ForbiddenTACs( SI_AMF_DT_ForbiddenTACs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ForbiddenAreaInformation_Item( SI_AMF_DT_ForbiddenAreaInformation_Item ** data);

void __si_amf_debug_ForbiddenAreaInformation_Item( char * key, SI_AMF_DT_ForbiddenAreaInformation_Item * data, int lvl);

void __si_amf_memfree_ForbiddenAreaInformation_Item( SI_AMF_DT_ForbiddenAreaInformation_Item * data);

int __si_amf_Encode_ForbiddenAreaInformation_Item( SI_AMF_DT_ForbiddenAreaInformation_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ForbiddenAreaInformation_Item_ExtIEs( SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs ** data);

void __si_amf_debug_ForbiddenAreaInformation_Item_ExtIEs( char * key, SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_ForbiddenAreaInformation_Item_ExtIEs( SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_ForbiddenAreaInformation_Item_ExtIEs( SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NotificationControl( char * key, uint8_t eNotificationControl, int lvl);

int __si_amf_Encode_NotificationControl( uint8_t eNotificationControl, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PacketLossRate( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PacketLossRate( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GBR_QosInformation( SI_AMF_DT_GBR_QosInformation ** data);

void __si_amf_debug_GBR_QosInformation( char * key, SI_AMF_DT_GBR_QosInformation * data, int lvl);

void __si_amf_memfree_GBR_QosInformation( SI_AMF_DT_GBR_QosInformation * data);

int __si_amf_Encode_GBR_QosInformation( SI_AMF_DT_GBR_QosInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GBR_QosInformation_ExtIEs( SI_AMF_DT_GBR_QosInformation_ExtIEs ** data);

void __si_amf_debug_GBR_QosInformation_ExtIEs( char * key, SI_AMF_DT_GBR_QosInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_GBR_QosInformation_ExtIEs( SI_AMF_DT_GBR_QosInformation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_GBR_QosInformation_ExtIEs( SI_AMF_DT_GBR_QosInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalGNB_ID_ExtIEs( SI_AMF_DT_GlobalGNB_ID_ExtIEs ** data);

void __si_amf_debug_GlobalGNB_ID_ExtIEs( char * key, SI_AMF_DT_GlobalGNB_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_GlobalGNB_ID_ExtIEs( SI_AMF_DT_GlobalGNB_ID_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_GlobalGNB_ID_ExtIEs( SI_AMF_DT_GlobalGNB_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalN3IWF_ID_ExtIEs( SI_AMF_DT_GlobalN3IWF_ID_ExtIEs ** data);

void __si_amf_debug_GlobalN3IWF_ID_ExtIEs( char * key, SI_AMF_DT_GlobalN3IWF_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_GlobalN3IWF_ID_ExtIEs( SI_AMF_DT_GlobalN3IWF_ID_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_GlobalN3IWF_ID_ExtIEs( SI_AMF_DT_GlobalN3IWF_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalNgENB_ID_ExtIEs( SI_AMF_DT_GlobalNgENB_ID_ExtIEs ** data);

void __si_amf_debug_GlobalNgENB_ID_ExtIEs( char * key, SI_AMF_DT_GlobalNgENB_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_GlobalNgENB_ID_ExtIEs( SI_AMF_DT_GlobalNgENB_ID_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_GlobalNgENB_ID_ExtIEs( SI_AMF_DT_GlobalNgENB_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GlobalRANNodeID_ExtIEs( SI_AMF_DT_GlobalRANNodeID_ExtIEs ** data);

void __si_amf_debug_GlobalRANNodeID_ExtIEs( char * key, SI_AMF_DT_GlobalRANNodeID_ExtIEs * data, int lvl);

void __si_amf_memfree_GlobalRANNodeID_ExtIEs( SI_AMF_DT_GlobalRANNodeID_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_GlobalRANNodeID_ExtIEs( SI_AMF_DT_GlobalRANNodeID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GNB_ID_ExtIEs( SI_AMF_DT_GNB_ID_ExtIEs ** data);

void __si_amf_debug_GNB_ID_ExtIEs( char * key, SI_AMF_DT_GNB_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_GNB_ID_ExtIEs( SI_AMF_DT_GNB_ID_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_GNB_ID_ExtIEs( SI_AMF_DT_GNB_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GTPTunnel_ExtIEs( SI_AMF_DT_GTPTunnel_ExtIEs ** data);

void __si_amf_debug_GTPTunnel_ExtIEs( char * key, SI_AMF_DT_GTPTunnel_ExtIEs * data, int lvl);

void __si_amf_memfree_GTPTunnel_ExtIEs( SI_AMF_DT_GTPTunnel_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_GTPTunnel_ExtIEs( SI_AMF_DT_GTPTunnel_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GUAMI( SI_AMF_DT_GUAMI ** data);

void __si_amf_debug_GUAMI( char * key, SI_AMF_DT_GUAMI * data, int lvl);

void __si_amf_memfree_GUAMI( SI_AMF_DT_GUAMI * data);

int __si_amf_Encode_GUAMI( SI_AMF_DT_GUAMI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_GUAMI_ExtIEs( SI_AMF_DT_GUAMI_ExtIEs ** data);

void __si_amf_debug_GUAMI_ExtIEs( char * key, SI_AMF_DT_GUAMI_ExtIEs * data, int lvl);

void __si_amf_memfree_GUAMI_ExtIEs( SI_AMF_DT_GUAMI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_GUAMI_ExtIEs( SI_AMF_DT_GUAMI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowToBeForwardedList( SI_AMF_DT_QosFlowToBeForwardedList ** data);

void __si_amf_debug_QosFlowToBeForwardedList( char * key, SI_AMF_DT_QosFlowToBeForwardedList * data, int lvl);

void __si_amf_memfree_QosFlowToBeForwardedList( SI_AMF_DT_QosFlowToBeForwardedList * data);

int __si_amf_Encode_QosFlowToBeForwardedList( SI_AMF_DT_QosFlowToBeForwardedList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverCommandTransfer( SI_AMF_DT_HandoverCommandTransfer ** data);

void __si_amf_debug_HandoverCommandTransfer( char * key, SI_AMF_DT_HandoverCommandTransfer * data, int lvl);

void __si_amf_memfree_HandoverCommandTransfer( SI_AMF_DT_HandoverCommandTransfer * data);

int __si_amf_Encode_HandoverCommandTransfer( SI_AMF_DT_HandoverCommandTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowPerTNLInformationList( SI_AMF_DT_QosFlowPerTNLInformationList ** data);

void __si_amf_debug_QosFlowPerTNLInformationList( char * key, SI_AMF_DT_QosFlowPerTNLInformationList * data, int lvl);

void __si_amf_memfree_QosFlowPerTNLInformationList( SI_AMF_DT_QosFlowPerTNLInformationList * data);

int __si_amf_Encode_QosFlowPerTNLInformationList( SI_AMF_DT_QosFlowPerTNLInformationList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformationList( SI_AMF_DT_UPTransportLayerInformationList ** data);

void __si_amf_debug_UPTransportLayerInformationList( char * key, SI_AMF_DT_UPTransportLayerInformationList * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformationList( SI_AMF_DT_UPTransportLayerInformationList * data);

int __si_amf_Encode_UPTransportLayerInformationList( SI_AMF_DT_UPTransportLayerInformationList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverCommandTransfer_ExtIEs( SI_AMF_DT_HandoverCommandTransfer_ExtIEs ** data);

void __si_amf_debug_HandoverCommandTransfer_ExtIEs( char * key, SI_AMF_DT_HandoverCommandTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_HandoverCommandTransfer_ExtIEs( SI_AMF_DT_HandoverCommandTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_HandoverCommandTransfer_ExtIEs( SI_AMF_DT_HandoverCommandTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_HandoverFlag( char * key, uint8_t eHandoverFlag, int lvl);

int __si_amf_Encode_HandoverFlag( uint8_t eHandoverFlag, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverPreparationUnsuccessfulTransfer( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer ** data);

void __si_amf_debug_HandoverPreparationUnsuccessfulTransfer( char * key, SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer * data, int lvl);

void __si_amf_memfree_HandoverPreparationUnsuccessfulTransfer( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer * data);

int __si_amf_Encode_HandoverPreparationUnsuccessfulTransfer( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverPreparationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs ** data);

void __si_amf_debug_HandoverPreparationUnsuccessfulTransfer_ExtIEs( char * key, SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_HandoverPreparationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_HandoverPreparationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_IntegrityProtectionResult( char * key, uint8_t eIntegrityProtectionResult, int lvl);

int __si_amf_Encode_IntegrityProtectionResult( uint8_t eIntegrityProtectionResult, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityResult( SI_AMF_DT_SecurityResult ** data);

void __si_amf_debug_SecurityResult( char * key, SI_AMF_DT_SecurityResult * data, int lvl);

void __si_amf_memfree_SecurityResult( SI_AMF_DT_SecurityResult * data);

int __si_amf_Encode_SecurityResult( SI_AMF_DT_SecurityResult * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowListWithCause( SI_AMF_DT_QosFlowListWithCause ** data);

void __si_amf_debug_QosFlowListWithCause( char * key, SI_AMF_DT_QosFlowListWithCause * data, int lvl);

void __si_amf_memfree_QosFlowListWithCause( SI_AMF_DT_QosFlowListWithCause * data);

int __si_amf_Encode_QosFlowListWithCause( SI_AMF_DT_QosFlowListWithCause * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverRequestAcknowledgeTransfer( SI_AMF_DT_HandoverRequestAcknowledgeTransfer ** data);

void __si_amf_debug_HandoverRequestAcknowledgeTransfer( char * key, SI_AMF_DT_HandoverRequestAcknowledgeTransfer * data, int lvl);

void __si_amf_memfree_HandoverRequestAcknowledgeTransfer( SI_AMF_DT_HandoverRequestAcknowledgeTransfer * data);

int __si_amf_Encode_HandoverRequestAcknowledgeTransfer( SI_AMF_DT_HandoverRequestAcknowledgeTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs ** data);

void __si_amf_debug_HandoverRequestAcknowledgeTransfer_ExtIEs( char * key, SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_HandoverRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_HandoverRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverRequiredTransfer( SI_AMF_DT_HandoverRequiredTransfer ** data);

void __si_amf_debug_HandoverRequiredTransfer( char * key, SI_AMF_DT_HandoverRequiredTransfer * data, int lvl);

void __si_amf_memfree_HandoverRequiredTransfer( SI_AMF_DT_HandoverRequiredTransfer * data);

int __si_amf_Encode_HandoverRequiredTransfer( SI_AMF_DT_HandoverRequiredTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverRequiredTransfer_ExtIEs( SI_AMF_DT_HandoverRequiredTransfer_ExtIEs ** data);

void __si_amf_debug_HandoverRequiredTransfer_ExtIEs( char * key, SI_AMF_DT_HandoverRequiredTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_HandoverRequiredTransfer_ExtIEs( SI_AMF_DT_HandoverRequiredTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_HandoverRequiredTransfer_ExtIEs( SI_AMF_DT_HandoverRequiredTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverResourceAllocationUnsuccessfulTransfer( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer ** data);

void __si_amf_debug_HandoverResourceAllocationUnsuccessfulTransfer( char * key, SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer * data, int lvl);

void __si_amf_memfree_HandoverResourceAllocationUnsuccessfulTransfer( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer * data);

int __si_amf_Encode_HandoverResourceAllocationUnsuccessfulTransfer( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs ** data);

void __si_amf_debug_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( char * key, SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_HandoverType( char * key, uint8_t eHandoverType, int lvl);

int __si_amf_Encode_HandoverType( uint8_t eHandoverType, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_IMSVoiceSupportIndicator( char * key, uint8_t eIMSVoiceSupportIndicator, int lvl);

int __si_amf_Encode_IMSVoiceSupportIndicator( uint8_t eIMSVoiceSupportIndicator, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_IndexToRFSP( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_IndexToRFSP( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedRANNodeList( SI_AMF_DT_RecommendedRANNodeList ** data);

void __si_amf_debug_RecommendedRANNodeList( char * key, SI_AMF_DT_RecommendedRANNodeList * data, int lvl);

void __si_amf_memfree_RecommendedRANNodeList( SI_AMF_DT_RecommendedRANNodeList * data);

int __si_amf_Encode_RecommendedRANNodeList( SI_AMF_DT_RecommendedRANNodeList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedRANNodesForPaging( SI_AMF_DT_RecommendedRANNodesForPaging ** data);

void __si_amf_debug_RecommendedRANNodesForPaging( char * key, SI_AMF_DT_RecommendedRANNodesForPaging * data, int lvl);

void __si_amf_memfree_RecommendedRANNodesForPaging( SI_AMF_DT_RecommendedRANNodesForPaging * data);

int __si_amf_Encode_RecommendedRANNodesForPaging( SI_AMF_DT_RecommendedRANNodesForPaging * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_InfoOnRecommendedCellsAndRANNodesForPaging( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging ** data);

void __si_amf_debug_InfoOnRecommendedCellsAndRANNodesForPaging( char * key, SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging * data, int lvl);

void __si_amf_memfree_InfoOnRecommendedCellsAndRANNodesForPaging( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging * data);

int __si_amf_Encode_InfoOnRecommendedCellsAndRANNodesForPaging( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs ** data);

void __si_amf_debug_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( char * key, SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs * data, int lvl);

void __si_amf_memfree_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_IntegrityProtectionIndication( char * key, uint8_t eIntegrityProtectionIndication, int lvl);

int __si_amf_Encode_IntegrityProtectionIndication( uint8_t eIntegrityProtectionIndication, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_InterfacesToTrace( SI_AMF_DT_InterfacesToTrace ** data);

void __si_amf_init_InterfacesToTrace2( SI_AMF_DT_InterfacesToTrace ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_InterfacesToTrace( char * key, SI_AMF_DT_InterfacesToTrace * data, int lvl);

void __si_amf_memfree_InterfacesToTrace( SI_AMF_DT_InterfacesToTrace * data);

int __si_amf_Encode_InterfacesToTrace( SI_AMF_DT_InterfacesToTrace * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TimeUEStayedInCell( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_TimeUEStayedInCell( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TimeUEStayedInCellEnhancedGranularity( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_TimeUEStayedInCellEnhancedGranularity( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedNGRANCellInformation( SI_AMF_DT_LastVisitedNGRANCellInformation ** data);

void __si_amf_debug_LastVisitedNGRANCellInformation( char * key, SI_AMF_DT_LastVisitedNGRANCellInformation * data, int lvl);

void __si_amf_memfree_LastVisitedNGRANCellInformation( SI_AMF_DT_LastVisitedNGRANCellInformation * data);

int __si_amf_Encode_LastVisitedNGRANCellInformation( SI_AMF_DT_LastVisitedNGRANCellInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedEUTRANCellInformation( SI_AMF_DT_LastVisitedEUTRANCellInformation ** data);

void __si_amf_init_LastVisitedEUTRANCellInformation2( SI_AMF_DT_LastVisitedEUTRANCellInformation ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_LastVisitedEUTRANCellInformation( char * key, SI_AMF_DT_LastVisitedEUTRANCellInformation * data, int lvl);

void __si_amf_memfree_LastVisitedEUTRANCellInformation( SI_AMF_DT_LastVisitedEUTRANCellInformation * data);

int __si_amf_Encode_LastVisitedEUTRANCellInformation( SI_AMF_DT_LastVisitedEUTRANCellInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedUTRANCellInformation( SI_AMF_DT_LastVisitedUTRANCellInformation ** data);

void __si_amf_init_LastVisitedUTRANCellInformation2( SI_AMF_DT_LastVisitedUTRANCellInformation ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_LastVisitedUTRANCellInformation( char * key, SI_AMF_DT_LastVisitedUTRANCellInformation * data, int lvl);

void __si_amf_memfree_LastVisitedUTRANCellInformation( SI_AMF_DT_LastVisitedUTRANCellInformation * data);

int __si_amf_Encode_LastVisitedUTRANCellInformation( SI_AMF_DT_LastVisitedUTRANCellInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedGERANCellInformation( SI_AMF_DT_LastVisitedGERANCellInformation ** data);

void __si_amf_init_LastVisitedGERANCellInformation2( SI_AMF_DT_LastVisitedGERANCellInformation ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_LastVisitedGERANCellInformation( char * key, SI_AMF_DT_LastVisitedGERANCellInformation * data, int lvl);

void __si_amf_memfree_LastVisitedGERANCellInformation( SI_AMF_DT_LastVisitedGERANCellInformation * data);

int __si_amf_Encode_LastVisitedGERANCellInformation( SI_AMF_DT_LastVisitedGERANCellInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedCellInformation( SI_AMF_DT_LastVisitedCellInformation ** data);

void __si_amf_debug_LastVisitedCellInformation( char * key, SI_AMF_DT_LastVisitedCellInformation * data, int lvl);

void __si_amf_memfree_LastVisitedCellInformation( SI_AMF_DT_LastVisitedCellInformation * data);

int __si_amf_Encode_LastVisitedCellInformation( SI_AMF_DT_LastVisitedCellInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedCellInformation_ExtIEs( SI_AMF_DT_LastVisitedCellInformation_ExtIEs ** data);

void __si_amf_debug_LastVisitedCellInformation_ExtIEs( char * key, SI_AMF_DT_LastVisitedCellInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_LastVisitedCellInformation_ExtIEs( SI_AMF_DT_LastVisitedCellInformation_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_LastVisitedCellInformation_ExtIEs( SI_AMF_DT_LastVisitedCellInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedCellItem( SI_AMF_DT_LastVisitedCellItem ** data);

void __si_amf_debug_LastVisitedCellItem( char * key, SI_AMF_DT_LastVisitedCellItem * data, int lvl);

void __si_amf_memfree_LastVisitedCellItem( SI_AMF_DT_LastVisitedCellItem * data);

int __si_amf_Encode_LastVisitedCellItem( SI_AMF_DT_LastVisitedCellItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedCellItem_ExtIEs( SI_AMF_DT_LastVisitedCellItem_ExtIEs ** data);

void __si_amf_debug_LastVisitedCellItem_ExtIEs( char * key, SI_AMF_DT_LastVisitedCellItem_ExtIEs * data, int lvl);

void __si_amf_memfree_LastVisitedCellItem_ExtIEs( SI_AMF_DT_LastVisitedCellItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_LastVisitedCellItem_ExtIEs( SI_AMF_DT_LastVisitedCellItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LastVisitedNGRANCellInformation_ExtIEs( SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs ** data);

void __si_amf_debug_LastVisitedNGRANCellInformation_ExtIEs( char * key, SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_LastVisitedNGRANCellInformation_ExtIEs( SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_LastVisitedNGRANCellInformation_ExtIEs( SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_LocationReportingAdditionalInfo( char * key, uint8_t eLocationReportingAdditionalInfo, int lvl);

int __si_amf_Encode_LocationReportingAdditionalInfo( uint8_t eLocationReportingAdditionalInfo, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ReportArea( char * key, uint8_t eReportArea, int lvl);

int __si_amf_Encode_ReportArea( uint8_t eReportArea, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LocationReportingRequestType( SI_AMF_DT_LocationReportingRequestType ** data);

void __si_amf_debug_LocationReportingRequestType( char * key, SI_AMF_DT_LocationReportingRequestType * data, int lvl);

void __si_amf_memfree_LocationReportingRequestType( SI_AMF_DT_LocationReportingRequestType * data);

int __si_amf_Encode_LocationReportingRequestType( SI_AMF_DT_LocationReportingRequestType * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_LocationReportingRequestType_ExtIEs( SI_AMF_DT_LocationReportingRequestType_ExtIEs ** data);

void __si_amf_debug_LocationReportingRequestType_ExtIEs( char * key, SI_AMF_DT_LocationReportingRequestType_ExtIEs * data, int lvl);

void __si_amf_memfree_LocationReportingRequestType_ExtIEs( SI_AMF_DT_LocationReportingRequestType_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_LocationReportingRequestType_ExtIEs( SI_AMF_DT_LocationReportingRequestType_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_MaskedIMEISV( SI_AMF_DT_MaskedIMEISV ** data);

void __si_amf_init_MaskedIMEISV2( SI_AMF_DT_MaskedIMEISV ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_MaskedIMEISV( char * key, SI_AMF_DT_MaskedIMEISV * data, int lvl);

void __si_amf_memfree_MaskedIMEISV( SI_AMF_DT_MaskedIMEISV * data);

int __si_amf_Encode_MaskedIMEISV( SI_AMF_DT_MaskedIMEISV * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_MessageIdentifier( SI_AMF_DT_MessageIdentifier ** data);

void __si_amf_init_MessageIdentifier2( SI_AMF_DT_MessageIdentifier ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_MessageIdentifier( char * key, SI_AMF_DT_MessageIdentifier * data, int lvl);

void __si_amf_memfree_MessageIdentifier( SI_AMF_DT_MessageIdentifier * data);

int __si_amf_Encode_MessageIdentifier( SI_AMF_DT_MessageIdentifier * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_MaximumIntegrityProtectedDataRate( char * key, uint8_t eMaximumIntegrityProtectedDataRate, int lvl);

int __si_amf_Encode_MaximumIntegrityProtectedDataRate( uint8_t eMaximumIntegrityProtectedDataRate, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RATRestrictions( SI_AMF_DT_RATRestrictions ** data);

void __si_amf_debug_RATRestrictions( char * key, SI_AMF_DT_RATRestrictions * data, int lvl);

void __si_amf_memfree_RATRestrictions( SI_AMF_DT_RATRestrictions * data);

int __si_amf_Encode_RATRestrictions( SI_AMF_DT_RATRestrictions * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ServiceAreaInformation( SI_AMF_DT_ServiceAreaInformation ** data);

void __si_amf_debug_ServiceAreaInformation( char * key, SI_AMF_DT_ServiceAreaInformation * data, int lvl);

void __si_amf_memfree_ServiceAreaInformation( SI_AMF_DT_ServiceAreaInformation * data);

int __si_amf_Encode_ServiceAreaInformation( SI_AMF_DT_ServiceAreaInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_MobilityRestrictionList( SI_AMF_DT_MobilityRestrictionList ** data);

void __si_amf_debug_MobilityRestrictionList( char * key, SI_AMF_DT_MobilityRestrictionList * data, int lvl);

void __si_amf_memfree_MobilityRestrictionList( SI_AMF_DT_MobilityRestrictionList * data);

int __si_amf_Encode_MobilityRestrictionList( SI_AMF_DT_MobilityRestrictionList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_MobilityRestrictionList_ExtIEs( SI_AMF_DT_MobilityRestrictionList_ExtIEs ** data);

void __si_amf_debug_MobilityRestrictionList_ExtIEs( char * key, SI_AMF_DT_MobilityRestrictionList_ExtIEs * data, int lvl);

void __si_amf_memfree_MobilityRestrictionList_ExtIEs( SI_AMF_DT_MobilityRestrictionList_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_MobilityRestrictionList_ExtIEs( SI_AMF_DT_MobilityRestrictionList_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_N3IWF_ID_ExtIEs( SI_AMF_DT_N3IWF_ID_ExtIEs ** data);

void __si_amf_debug_N3IWF_ID_ExtIEs( char * key, SI_AMF_DT_N3IWF_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_N3IWF_ID_ExtIEs( SI_AMF_DT_N3IWF_ID_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_N3IWF_ID_ExtIEs( SI_AMF_DT_N3IWF_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NAS_PDU( SI_AMF_DT_NAS_PDU ** data);

void __si_amf_init_NAS_PDU2( SI_AMF_DT_NAS_PDU ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_NAS_PDU( char * key, SI_AMF_DT_NAS_PDU * data, int lvl);

void __si_amf_memfree_NAS_PDU( SI_AMF_DT_NAS_PDU * data);

int __si_amf_Encode_NAS_PDU( SI_AMF_DT_NAS_PDU * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NASSecurityParametersFromNGRAN( SI_AMF_DT_NASSecurityParametersFromNGRAN ** data);

void __si_amf_init_NASSecurityParametersFromNGRAN2( SI_AMF_DT_NASSecurityParametersFromNGRAN ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_NASSecurityParametersFromNGRAN( char * key, SI_AMF_DT_NASSecurityParametersFromNGRAN * data, int lvl);

void __si_amf_memfree_NASSecurityParametersFromNGRAN( SI_AMF_DT_NASSecurityParametersFromNGRAN * data);

int __si_amf_Encode_NASSecurityParametersFromNGRAN( SI_AMF_DT_NASSecurityParametersFromNGRAN * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NetworkInstance( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_NetworkInstance( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NewSecurityContextInd( char * key, uint8_t eNewSecurityContextInd, int lvl);

int __si_amf_Encode_NewSecurityContextInd( uint8_t eNewSecurityContextInd, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NextHopChainingCount( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_NextHopChainingCount( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NgENB_ID_ExtIEs( SI_AMF_DT_NgENB_ID_ExtIEs ** data);

void __si_amf_debug_NgENB_ID_ExtIEs( char * key, SI_AMF_DT_NgENB_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_NgENB_ID_ExtIEs( SI_AMF_DT_NgENB_ID_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_NgENB_ID_ExtIEs( SI_AMF_DT_NgENB_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NGRAN_CGI_ExtIEs( SI_AMF_DT_NGRAN_CGI_ExtIEs ** data);

void __si_amf_debug_NGRAN_CGI_ExtIEs( char * key, SI_AMF_DT_NGRAN_CGI_ExtIEs * data, int lvl);

void __si_amf_memfree_NGRAN_CGI_ExtIEs( SI_AMF_DT_NGRAN_CGI_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_NGRAN_CGI_ExtIEs( SI_AMF_DT_NGRAN_CGI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NGRAN_TNLAssociationToRemoveList( SI_AMF_DT_NGRAN_TNLAssociationToRemoveList ** data);

void __si_amf_debug_NGRAN_TNLAssociationToRemoveList( char * key, SI_AMF_DT_NGRAN_TNLAssociationToRemoveList * data, int lvl);

void __si_amf_memfree_NGRAN_TNLAssociationToRemoveList( SI_AMF_DT_NGRAN_TNLAssociationToRemoveList * data);

int __si_amf_Encode_NGRAN_TNLAssociationToRemoveList( SI_AMF_DT_NGRAN_TNLAssociationToRemoveList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NGRAN_TNLAssociationToRemoveItem( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem ** data);

void __si_amf_debug_NGRAN_TNLAssociationToRemoveItem( char * key, SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem * data, int lvl);

void __si_amf_memfree_NGRAN_TNLAssociationToRemoveItem( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem * data);

int __si_amf_Encode_NGRAN_TNLAssociationToRemoveItem( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NGRAN_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs ** data);

void __si_amf_debug_NGRAN_TNLAssociationToRemoveItem_ExtIEs( char * key, SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs * data, int lvl);

void __si_amf_memfree_NGRAN_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_NGRAN_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NGRANTraceID( SI_AMF_DT_NGRANTraceID ** data);

void __si_amf_init_NGRANTraceID2( SI_AMF_DT_NGRANTraceID ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_NGRANTraceID( char * key, SI_AMF_DT_NGRANTraceID * data, int lvl);

void __si_amf_memfree_NGRANTraceID( SI_AMF_DT_NGRANTraceID * data);

int __si_amf_Encode_NGRANTraceID( SI_AMF_DT_NGRANTraceID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NonDynamic5QIDescriptor( SI_AMF_DT_NonDynamic5QIDescriptor ** data);

void __si_amf_debug_NonDynamic5QIDescriptor( char * key, SI_AMF_DT_NonDynamic5QIDescriptor * data, int lvl);

void __si_amf_memfree_NonDynamic5QIDescriptor( SI_AMF_DT_NonDynamic5QIDescriptor * data);

int __si_amf_Encode_NonDynamic5QIDescriptor( SI_AMF_DT_NonDynamic5QIDescriptor * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NonDynamic5QIDescriptor_ExtIEs( SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs ** data);

void __si_amf_debug_NonDynamic5QIDescriptor_ExtIEs( char * key, SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs * data, int lvl);

void __si_amf_memfree_NonDynamic5QIDescriptor_ExtIEs( SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_NonDynamic5QIDescriptor_ExtIEs( SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NotAllowedTACs( SI_AMF_DT_NotAllowedTACs ** data);

void __si_amf_debug_NotAllowedTACs( char * key, SI_AMF_DT_NotAllowedTACs * data, int lvl);

void __si_amf_memfree_NotAllowedTACs( SI_AMF_DT_NotAllowedTACs * data);

int __si_amf_Encode_NotAllowedTACs( SI_AMF_DT_NotAllowedTACs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NotificationCause( char * key, uint8_t eNotificationCause, int lvl);

int __si_amf_Encode_NotificationCause( uint8_t eNotificationCause, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NR_CGI_ExtIEs( SI_AMF_DT_NR_CGI_ExtIEs ** data);

void __si_amf_debug_NR_CGI_ExtIEs( char * key, SI_AMF_DT_NR_CGI_ExtIEs * data, int lvl);

void __si_amf_memfree_NR_CGI_ExtIEs( SI_AMF_DT_NR_CGI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_NR_CGI_ExtIEs( SI_AMF_DT_NR_CGI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NR_CGIListForWarning( SI_AMF_DT_NR_CGIListForWarning ** data);

void __si_amf_debug_NR_CGIListForWarning( char * key, SI_AMF_DT_NR_CGIListForWarning * data, int lvl);

void __si_amf_memfree_NR_CGIListForWarning( SI_AMF_DT_NR_CGIListForWarning * data);

int __si_amf_Encode_NR_CGIListForWarning( SI_AMF_DT_NR_CGIListForWarning * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NRencryptionAlgorithms( SI_AMF_DT_NRencryptionAlgorithms ** data);

void __si_amf_init_NRencryptionAlgorithms2( SI_AMF_DT_NRencryptionAlgorithms ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_NRencryptionAlgorithms( char * key, SI_AMF_DT_NRencryptionAlgorithms * data, int lvl);

void __si_amf_memfree_NRencryptionAlgorithms( SI_AMF_DT_NRencryptionAlgorithms * data);

int __si_amf_Encode_NRencryptionAlgorithms( SI_AMF_DT_NRencryptionAlgorithms * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NRintegrityProtectionAlgorithms( SI_AMF_DT_NRintegrityProtectionAlgorithms ** data);

void __si_amf_init_NRintegrityProtectionAlgorithms2( SI_AMF_DT_NRintegrityProtectionAlgorithms ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_NRintegrityProtectionAlgorithms( char * key, SI_AMF_DT_NRintegrityProtectionAlgorithms * data, int lvl);

void __si_amf_memfree_NRintegrityProtectionAlgorithms( SI_AMF_DT_NRintegrityProtectionAlgorithms * data);

int __si_amf_Encode_NRintegrityProtectionAlgorithms( SI_AMF_DT_NRintegrityProtectionAlgorithms * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_NRPPa_PDU( SI_AMF_DT_NRPPa_PDU ** data);

void __si_amf_init_NRPPa_PDU2( SI_AMF_DT_NRPPa_PDU ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_NRPPa_PDU( char * key, SI_AMF_DT_NRPPa_PDU * data, int lvl);

void __si_amf_memfree_NRPPa_PDU( SI_AMF_DT_NRPPa_PDU * data);

int __si_amf_Encode_NRPPa_PDU( SI_AMF_DT_NRPPa_PDU * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_NumberOfBroadcastsRequested( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_NumberOfBroadcastsRequested( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_OverloadAction( char * key, uint8_t eOverloadAction, int lvl);

int __si_amf_Encode_OverloadAction( uint8_t eOverloadAction, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_OverloadResponse( SI_AMF_DT_OverloadResponse ** data);

void __si_amf_debug_OverloadResponse( char * key, SI_AMF_DT_OverloadResponse * data, int lvl);

void __si_amf_memfree_OverloadResponse( SI_AMF_DT_OverloadResponse * data);

int __si_amf_Encode_OverloadResponse( SI_AMF_DT_OverloadResponse * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_OverloadResponse_ExtIEs( SI_AMF_DT_OverloadResponse_ExtIEs ** data);

void __si_amf_debug_OverloadResponse_ExtIEs( char * key, SI_AMF_DT_OverloadResponse_ExtIEs * data, int lvl);

void __si_amf_memfree_OverloadResponse_ExtIEs( SI_AMF_DT_OverloadResponse_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_OverloadResponse_ExtIEs( SI_AMF_DT_OverloadResponse_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_OverloadStartNSSAIList( SI_AMF_DT_OverloadStartNSSAIList ** data);

void __si_amf_debug_OverloadStartNSSAIList( char * key, SI_AMF_DT_OverloadStartNSSAIList * data, int lvl);

void __si_amf_memfree_OverloadStartNSSAIList( SI_AMF_DT_OverloadStartNSSAIList * data);

int __si_amf_Encode_OverloadStartNSSAIList( SI_AMF_DT_OverloadStartNSSAIList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SliceOverloadList( SI_AMF_DT_SliceOverloadList ** data);

void __si_amf_debug_SliceOverloadList( char * key, SI_AMF_DT_SliceOverloadList * data, int lvl);

void __si_amf_memfree_SliceOverloadList( SI_AMF_DT_SliceOverloadList * data);

int __si_amf_Encode_SliceOverloadList( SI_AMF_DT_SliceOverloadList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TrafficLoadReductionIndication( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_TrafficLoadReductionIndication( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_OverloadStartNSSAIItem( SI_AMF_DT_OverloadStartNSSAIItem ** data);

void __si_amf_debug_OverloadStartNSSAIItem( char * key, SI_AMF_DT_OverloadStartNSSAIItem * data, int lvl);

void __si_amf_memfree_OverloadStartNSSAIItem( SI_AMF_DT_OverloadStartNSSAIItem * data);

int __si_amf_Encode_OverloadStartNSSAIItem( SI_AMF_DT_OverloadStartNSSAIItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_OverloadStartNSSAIItem_ExtIEs( SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs ** data);

void __si_amf_debug_OverloadStartNSSAIItem_ExtIEs( char * key, SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs * data, int lvl);

void __si_amf_memfree_OverloadStartNSSAIItem_ExtIEs( SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_OverloadStartNSSAIItem_ExtIEs( SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PacketErrorRate_ExtIEs( SI_AMF_DT_PacketErrorRate_ExtIEs ** data);

void __si_amf_debug_PacketErrorRate_ExtIEs( char * key, SI_AMF_DT_PacketErrorRate_ExtIEs * data, int lvl);

void __si_amf_memfree_PacketErrorRate_ExtIEs( SI_AMF_DT_PacketErrorRate_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PacketErrorRate_ExtIEs( SI_AMF_DT_PacketErrorRate_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PagingAttemptInformation_ExtIEs( SI_AMF_DT_PagingAttemptInformation_ExtIEs ** data);

void __si_amf_debug_PagingAttemptInformation_ExtIEs( char * key, SI_AMF_DT_PagingAttemptInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_PagingAttemptInformation_ExtIEs( SI_AMF_DT_PagingAttemptInformation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PagingAttemptInformation_ExtIEs( SI_AMF_DT_PagingAttemptInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PagingOrigin( char * key, uint8_t ePagingOrigin, int lvl);

int __si_amf_Encode_PagingOrigin( uint8_t ePagingOrigin, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PagingPriority( char * key, uint8_t ePagingPriority, int lvl);

int __si_amf_Encode_PagingPriority( uint8_t ePagingPriority, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityIndication( SI_AMF_DT_SecurityIndication ** data);

void __si_amf_debug_SecurityIndication( char * key, SI_AMF_DT_SecurityIndication * data, int lvl);

void __si_amf_memfree_SecurityIndication( SI_AMF_DT_SecurityIndication * data);

int __si_amf_Encode_SecurityIndication( SI_AMF_DT_SecurityIndication * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestAcknowledgeTransfer( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer ** data);

void __si_amf_debug_PathSwitchRequestAcknowledgeTransfer( char * key, SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer * data, int lvl);

void __si_amf_memfree_PathSwitchRequestAcknowledgeTransfer( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer * data);

int __si_amf_Encode_PathSwitchRequestAcknowledgeTransfer( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformationPairList( SI_AMF_DT_UPTransportLayerInformationPairList ** data);

void __si_amf_debug_UPTransportLayerInformationPairList( char * key, SI_AMF_DT_UPTransportLayerInformationPairList * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformationPairList( SI_AMF_DT_UPTransportLayerInformationPairList * data);

int __si_amf_Encode_UPTransportLayerInformationPairList( SI_AMF_DT_UPTransportLayerInformationPairList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs ** data);

void __si_amf_debug_PathSwitchRequestAcknowledgeTransfer_ExtIEs( char * key, SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PathSwitchRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PathSwitchRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestSetupFailedTransfer( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer ** data);

void __si_amf_debug_PathSwitchRequestSetupFailedTransfer( char * key, SI_AMF_DT_PathSwitchRequestSetupFailedTransfer * data, int lvl);

void __si_amf_memfree_PathSwitchRequestSetupFailedTransfer( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer * data);

int __si_amf_Encode_PathSwitchRequestSetupFailedTransfer( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestSetupFailedTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs ** data);

void __si_amf_debug_PathSwitchRequestSetupFailedTransfer_ExtIEs( char * key, SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PathSwitchRequestSetupFailedTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PathSwitchRequestSetupFailedTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserPlaneSecurityInformation( SI_AMF_DT_UserPlaneSecurityInformation ** data);

void __si_amf_debug_UserPlaneSecurityInformation( char * key, SI_AMF_DT_UserPlaneSecurityInformation * data, int lvl);

void __si_amf_memfree_UserPlaneSecurityInformation( SI_AMF_DT_UserPlaneSecurityInformation * data);

int __si_amf_Encode_UserPlaneSecurityInformation( SI_AMF_DT_UserPlaneSecurityInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAcceptedList( SI_AMF_DT_QosFlowAcceptedList ** data);

void __si_amf_debug_QosFlowAcceptedList( char * key, SI_AMF_DT_QosFlowAcceptedList * data, int lvl);

void __si_amf_memfree_QosFlowAcceptedList( SI_AMF_DT_QosFlowAcceptedList * data);

int __si_amf_Encode_QosFlowAcceptedList( SI_AMF_DT_QosFlowAcceptedList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestTransfer( SI_AMF_DT_PathSwitchRequestTransfer ** data);

void __si_amf_debug_PathSwitchRequestTransfer( char * key, SI_AMF_DT_PathSwitchRequestTransfer * data, int lvl);

void __si_amf_memfree_PathSwitchRequestTransfer( SI_AMF_DT_PathSwitchRequestTransfer * data);

int __si_amf_Encode_PathSwitchRequestTransfer( SI_AMF_DT_PathSwitchRequestTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs ** data);

void __si_amf_debug_PathSwitchRequestTransfer_ExtIEs( char * key, SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PathSwitchRequestTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PathSwitchRequestTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestUnsuccessfulTransfer( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer ** data);

void __si_amf_debug_PathSwitchRequestUnsuccessfulTransfer( char * key, SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer * data, int lvl);

void __si_amf_memfree_PathSwitchRequestUnsuccessfulTransfer( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer * data);

int __si_amf_Encode_PathSwitchRequestUnsuccessfulTransfer( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs ** data);

void __si_amf_debug_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( char * key, SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionAggregateMaximumBitRate( SI_AMF_DT_PDUSessionAggregateMaximumBitRate ** data);

void __si_amf_debug_PDUSessionAggregateMaximumBitRate( char * key, SI_AMF_DT_PDUSessionAggregateMaximumBitRate * data, int lvl);

void __si_amf_memfree_PDUSessionAggregateMaximumBitRate( SI_AMF_DT_PDUSessionAggregateMaximumBitRate * data);

int __si_amf_Encode_PDUSessionAggregateMaximumBitRate( SI_AMF_DT_PDUSessionAggregateMaximumBitRate * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs ** data);

void __si_amf_debug_PDUSessionAggregateMaximumBitRate_ExtIEs( char * key, SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PDUSessionID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_PDUSessionID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceAdmittedList( SI_AMF_DT_PDUSessionResourceAdmittedList ** data);

void __si_amf_debug_PDUSessionResourceAdmittedList( char * key, SI_AMF_DT_PDUSessionResourceAdmittedList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceAdmittedList( SI_AMF_DT_PDUSessionResourceAdmittedList * data);

int __si_amf_Encode_PDUSessionResourceAdmittedList( SI_AMF_DT_PDUSessionResourceAdmittedList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverRequestAcknowledgeTransferOctStr( SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr ** data);

void __si_amf_init_HandoverRequestAcknowledgeTransferOctStr2( SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_HandoverRequestAcknowledgeTransferOctStr( char * key, SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr * data, int lvl);

void __si_amf_memfree_HandoverRequestAcknowledgeTransferOctStr( SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr * data);

int __si_amf_Encode_HandoverRequestAcknowledgeTransferOctStr( SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceAdmittedItem( SI_AMF_DT_PDUSessionResourceAdmittedItem ** data);

void __si_amf_debug_PDUSessionResourceAdmittedItem( char * key, SI_AMF_DT_PDUSessionResourceAdmittedItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceAdmittedItem( SI_AMF_DT_PDUSessionResourceAdmittedItem * data);

int __si_amf_Encode_PDUSessionResourceAdmittedItem( SI_AMF_DT_PDUSessionResourceAdmittedItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceAdmittedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceAdmittedItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceAdmittedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceAdmittedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToModifyListModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm ** data);

void __si_amf_debug_PDUSessionResourceFailedToModifyListModCfm( char * key, SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToModifyListModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm * data);

int __si_amf_Encode_PDUSessionResourceFailedToModifyListModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr2( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToModifyItemModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm ** data);

void __si_amf_debug_PDUSessionResourceFailedToModifyItemModCfm( char * key, SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToModifyItemModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm * data);

int __si_amf_Encode_PDUSessionResourceFailedToModifyItemModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToModifyListModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes ** data);

void __si_amf_debug_PDUSessionResourceFailedToModifyListModRes( char * key, SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToModifyListModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes * data);

int __si_amf_Encode_PDUSessionResourceFailedToModifyListModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceModifyUnsuccessfulTransferOctStr2( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceModifyUnsuccessfulTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceModifyUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToModifyItemModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes ** data);

void __si_amf_debug_PDUSessionResourceFailedToModifyItemModRes( char * key, SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToModifyItemModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes * data);

int __si_amf_Encode_PDUSessionResourceFailedToModifyItemModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupListCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupListCxtFail( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupListCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupListCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceSetupUnsuccessfulTransferOctStr2( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceSetupUnsuccessfulTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceSetupUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemCxtFail( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupItemCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupListCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupListCxtRes( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupListCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupListCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemCxtRes( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupListHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupListHOAck( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupListHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupListHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverResourceAllocationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr ** data);

void __si_amf_init_HandoverResourceAllocationUnsuccessfulTransferOctStr2( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_HandoverResourceAllocationUnsuccessfulTransferOctStr( char * key, SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr * data, int lvl);

void __si_amf_memfree_HandoverResourceAllocationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr * data);

int __si_amf_Encode_HandoverResourceAllocationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemHOAck( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupItemHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupListPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupListPSReq( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupListPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupListPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestSetupFailedTransferOctStr( SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr ** data);

void __si_amf_init_PathSwitchRequestSetupFailedTransferOctStr2( SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PathSwitchRequestSetupFailedTransferOctStr( char * key, SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr * data, int lvl);

void __si_amf_memfree_PathSwitchRequestSetupFailedTransferOctStr( SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr * data);

int __si_amf_Encode_PathSwitchRequestSetupFailedTransferOctStr( SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemPSReq( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupItemPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupListSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupListSURes( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupListSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupListSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemSURes( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes * data);

int __si_amf_Encode_PDUSessionResourceFailedToSetupItemSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceHandoverList( SI_AMF_DT_PDUSessionResourceHandoverList ** data);

void __si_amf_debug_PDUSessionResourceHandoverList( char * key, SI_AMF_DT_PDUSessionResourceHandoverList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceHandoverList( SI_AMF_DT_PDUSessionResourceHandoverList * data);

int __si_amf_Encode_PDUSessionResourceHandoverList( SI_AMF_DT_PDUSessionResourceHandoverList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverCommandTransferOctStr( SI_AMF_DT_HandoverCommandTransferOctStr ** data);

void __si_amf_init_HandoverCommandTransferOctStr2( SI_AMF_DT_HandoverCommandTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_HandoverCommandTransferOctStr( char * key, SI_AMF_DT_HandoverCommandTransferOctStr * data, int lvl);

void __si_amf_memfree_HandoverCommandTransferOctStr( SI_AMF_DT_HandoverCommandTransferOctStr * data);

int __si_amf_Encode_HandoverCommandTransferOctStr( SI_AMF_DT_HandoverCommandTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceHandoverItem( SI_AMF_DT_PDUSessionResourceHandoverItem ** data);

void __si_amf_debug_PDUSessionResourceHandoverItem( char * key, SI_AMF_DT_PDUSessionResourceHandoverItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceHandoverItem( SI_AMF_DT_PDUSessionResourceHandoverItem * data);

int __si_amf_Encode_PDUSessionResourceHandoverItem( SI_AMF_DT_PDUSessionResourceHandoverItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceHandoverItem_ExtIEs( SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceHandoverItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceHandoverItem_ExtIEs( SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceHandoverItem_ExtIEs( SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceInformationList( SI_AMF_DT_PDUSessionResourceInformationList ** data);

void __si_amf_debug_PDUSessionResourceInformationList( char * key, SI_AMF_DT_PDUSessionResourceInformationList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceInformationList( SI_AMF_DT_PDUSessionResourceInformationList * data);

int __si_amf_Encode_PDUSessionResourceInformationList( SI_AMF_DT_PDUSessionResourceInformationList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowInformationList( SI_AMF_DT_QosFlowInformationList ** data);

void __si_amf_debug_QosFlowInformationList( char * key, SI_AMF_DT_QosFlowInformationList * data, int lvl);

void __si_amf_memfree_QosFlowInformationList( SI_AMF_DT_QosFlowInformationList * data);

int __si_amf_Encode_QosFlowInformationList( SI_AMF_DT_QosFlowInformationList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceInformationItem( SI_AMF_DT_PDUSessionResourceInformationItem ** data);

void __si_amf_debug_PDUSessionResourceInformationItem( char * key, SI_AMF_DT_PDUSessionResourceInformationItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceInformationItem( SI_AMF_DT_PDUSessionResourceInformationItem * data);

int __si_amf_Encode_PDUSessionResourceInformationItem( SI_AMF_DT_PDUSessionResourceInformationItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceInformationItem_ExtIEs( SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceInformationItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceInformationItem_ExtIEs( SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceInformationItem_ExtIEs( SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceListCxtRelCpl( SI_AMF_DT_PDUSessionResourceListCxtRelCpl ** data);

void __si_amf_debug_PDUSessionResourceListCxtRelCpl( char * key, SI_AMF_DT_PDUSessionResourceListCxtRelCpl * data, int lvl);

void __si_amf_memfree_PDUSessionResourceListCxtRelCpl( SI_AMF_DT_PDUSessionResourceListCxtRelCpl * data);

int __si_amf_Encode_PDUSessionResourceListCxtRelCpl( SI_AMF_DT_PDUSessionResourceListCxtRelCpl * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceItemCxtRelCpl( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl ** data);

void __si_amf_debug_PDUSessionResourceItemCxtRelCpl( char * key, SI_AMF_DT_PDUSessionResourceItemCxtRelCpl * data, int lvl);

void __si_amf_memfree_PDUSessionResourceItemCxtRelCpl( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl * data);

int __si_amf_Encode_PDUSessionResourceItemCxtRelCpl( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleaseResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceReleaseResponseTransferOctStr2( SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceReleaseResponseTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleaseResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceReleaseResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceItemCxtRelCpl_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceItemCxtRelCpl_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceItemCxtRelCpl_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceItemCxtRelCpl_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceListCxtRelReq( SI_AMF_DT_PDUSessionResourceListCxtRelReq ** data);

void __si_amf_debug_PDUSessionResourceListCxtRelReq( char * key, SI_AMF_DT_PDUSessionResourceListCxtRelReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceListCxtRelReq( SI_AMF_DT_PDUSessionResourceListCxtRelReq * data);

int __si_amf_Encode_PDUSessionResourceListCxtRelReq( SI_AMF_DT_PDUSessionResourceListCxtRelReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceItemCxtRelReq( SI_AMF_DT_PDUSessionResourceItemCxtRelReq ** data);

void __si_amf_debug_PDUSessionResourceItemCxtRelReq( char * key, SI_AMF_DT_PDUSessionResourceItemCxtRelReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceItemCxtRelReq( SI_AMF_DT_PDUSessionResourceItemCxtRelReq * data);

int __si_amf_Encode_PDUSessionResourceItemCxtRelReq( SI_AMF_DT_PDUSessionResourceItemCxtRelReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceItemCxtRelReq_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceItemCxtRelReq_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceItemCxtRelReq_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceItemCxtRelReq_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceListHORqd( SI_AMF_DT_PDUSessionResourceListHORqd ** data);

void __si_amf_debug_PDUSessionResourceListHORqd( char * key, SI_AMF_DT_PDUSessionResourceListHORqd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceListHORqd( SI_AMF_DT_PDUSessionResourceListHORqd * data);

int __si_amf_Encode_PDUSessionResourceListHORqd( SI_AMF_DT_PDUSessionResourceListHORqd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverRequiredTransferOctStr( SI_AMF_DT_HandoverRequiredTransferOctStr ** data);

void __si_amf_init_HandoverRequiredTransferOctStr2( SI_AMF_DT_HandoverRequiredTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_HandoverRequiredTransferOctStr( char * key, SI_AMF_DT_HandoverRequiredTransferOctStr * data, int lvl);

void __si_amf_memfree_HandoverRequiredTransferOctStr( SI_AMF_DT_HandoverRequiredTransferOctStr * data);

int __si_amf_Encode_HandoverRequiredTransferOctStr( SI_AMF_DT_HandoverRequiredTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceItemHORqd( SI_AMF_DT_PDUSessionResourceItemHORqd ** data);

void __si_amf_debug_PDUSessionResourceItemHORqd( char * key, SI_AMF_DT_PDUSessionResourceItemHORqd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceItemHORqd( SI_AMF_DT_PDUSessionResourceItemHORqd * data);

int __si_amf_Encode_PDUSessionResourceItemHORqd( SI_AMF_DT_PDUSessionResourceItemHORqd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceItemHORqd_ExtIEs( SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceItemHORqd_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceItemHORqd_ExtIEs( SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceItemHORqd_ExtIEs( SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowModifyConfirmList( SI_AMF_DT_QosFlowModifyConfirmList ** data);

void __si_amf_debug_QosFlowModifyConfirmList( char * key, SI_AMF_DT_QosFlowModifyConfirmList * data, int lvl);

void __si_amf_memfree_QosFlowModifyConfirmList( SI_AMF_DT_QosFlowModifyConfirmList * data);

int __si_amf_Encode_QosFlowModifyConfirmList( SI_AMF_DT_QosFlowModifyConfirmList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyConfirmTransfer( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer ** data);

void __si_amf_debug_PDUSessionResourceModifyConfirmTransfer( char * key, SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyConfirmTransfer( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer * data);

int __si_amf_Encode_PDUSessionResourceModifyConfirmTransfer( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyConfirmTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyConfirmTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyConfirmTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyConfirmTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer ** data);

void __si_amf_debug_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( char * key, SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer * data);

int __si_amf_Encode_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyRequestTransfer( SI_AMF_DT_PDUSessionResourceModifyRequestTransfer ** data);

void __si_amf_debug_PDUSessionResourceModifyRequestTransfer( char * key, SI_AMF_DT_PDUSessionResourceModifyRequestTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyRequestTransfer( SI_AMF_DT_PDUSessionResourceModifyRequestTransfer * data);

int __si_amf_Encode_PDUSessionResourceModifyRequestTransfer( SI_AMF_DT_PDUSessionResourceModifyRequestTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UL_NGU_UP_TNLModifyList( SI_AMF_DT_UL_NGU_UP_TNLModifyList ** data);

void __si_amf_debug_UL_NGU_UP_TNLModifyList( char * key, SI_AMF_DT_UL_NGU_UP_TNLModifyList * data, int lvl);

void __si_amf_memfree_UL_NGU_UP_TNLModifyList( SI_AMF_DT_UL_NGU_UP_TNLModifyList * data);

int __si_amf_Encode_UL_NGU_UP_TNLModifyList( SI_AMF_DT_UL_NGU_UP_TNLModifyList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAddOrModifyRequestList( SI_AMF_DT_QosFlowAddOrModifyRequestList ** data);

void __si_amf_debug_QosFlowAddOrModifyRequestList( char * key, SI_AMF_DT_QosFlowAddOrModifyRequestList * data, int lvl);

void __si_amf_memfree_QosFlowAddOrModifyRequestList( SI_AMF_DT_QosFlowAddOrModifyRequestList * data);

int __si_amf_Encode_QosFlowAddOrModifyRequestList( SI_AMF_DT_QosFlowAddOrModifyRequestList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyRequestTransferIEs( SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyRequestTransferIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyRequestTransferIEs( SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyRequestTransferIEs( SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAddOrModifyResponseList( SI_AMF_DT_QosFlowAddOrModifyResponseList ** data);

void __si_amf_debug_QosFlowAddOrModifyResponseList( char * key, SI_AMF_DT_QosFlowAddOrModifyResponseList * data, int lvl);

void __si_amf_memfree_QosFlowAddOrModifyResponseList( SI_AMF_DT_QosFlowAddOrModifyResponseList * data);

int __si_amf_Encode_QosFlowAddOrModifyResponseList( SI_AMF_DT_QosFlowAddOrModifyResponseList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyResponseTransfer( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer ** data);

void __si_amf_debug_PDUSessionResourceModifyResponseTransfer( char * key, SI_AMF_DT_PDUSessionResourceModifyResponseTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyResponseTransfer( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer * data);

int __si_amf_Encode_PDUSessionResourceModifyResponseTransfer( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyResponseTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowPerTNLInformation( SI_AMF_DT_QosFlowPerTNLInformation ** data);

void __si_amf_debug_QosFlowPerTNLInformation( char * key, SI_AMF_DT_QosFlowPerTNLInformation * data, int lvl);

void __si_amf_memfree_QosFlowPerTNLInformation( SI_AMF_DT_QosFlowPerTNLInformation * data);

int __si_amf_Encode_QosFlowPerTNLInformation( SI_AMF_DT_QosFlowPerTNLInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyIndicationTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer ** data);

void __si_amf_debug_PDUSessionResourceModifyIndicationTransfer( char * key, SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyIndicationTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer * data);

int __si_amf_Encode_PDUSessionResourceModifyIndicationTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PDUSessionUsageReportRatType( char * key, uint8_t ePDUSessionUsageReportRatType, int lvl);

int __si_amf_Encode_PDUSessionUsageReportRatType( uint8_t ePDUSessionUsageReportRatType, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_VolumeTimedReportList( SI_AMF_DT_VolumeTimedReportList ** data);

void __si_amf_debug_VolumeTimedReportList( char * key, SI_AMF_DT_VolumeTimedReportList * data, int lvl);

void __si_amf_memfree_VolumeTimedReportList( SI_AMF_DT_VolumeTimedReportList * data);

int __si_amf_Encode_VolumeTimedReportList( SI_AMF_DT_VolumeTimedReportList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionUsageReport( SI_AMF_DT_PDUSessionUsageReport ** data);

void __si_amf_debug_PDUSessionUsageReport( char * key, SI_AMF_DT_PDUSessionUsageReport * data, int lvl);

void __si_amf_memfree_PDUSessionUsageReport( SI_AMF_DT_PDUSessionUsageReport * data);

int __si_amf_Encode_PDUSessionUsageReport( SI_AMF_DT_PDUSessionUsageReport * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QoSFlowsUsageReportList( SI_AMF_DT_QoSFlowsUsageReportList ** data);

void __si_amf_debug_QoSFlowsUsageReportList( char * key, SI_AMF_DT_QoSFlowsUsageReportList * data, int lvl);

void __si_amf_memfree_QoSFlowsUsageReportList( SI_AMF_DT_QoSFlowsUsageReportList * data);

int __si_amf_Encode_QoSFlowsUsageReportList( SI_AMF_DT_QoSFlowsUsageReportList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecondaryRATUsageInformation( SI_AMF_DT_SecondaryRATUsageInformation ** data);

void __si_amf_debug_SecondaryRATUsageInformation( char * key, SI_AMF_DT_SecondaryRATUsageInformation * data, int lvl);

void __si_amf_memfree_SecondaryRATUsageInformation( SI_AMF_DT_SecondaryRATUsageInformation * data);

int __si_amf_Encode_SecondaryRATUsageInformation( SI_AMF_DT_SecondaryRATUsageInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyIndicationTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyIndicationTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyIndicationTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyIndicationTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyListModCfm( SI_AMF_DT_PDUSessionResourceModifyListModCfm ** data);

void __si_amf_debug_PDUSessionResourceModifyListModCfm( char * key, SI_AMF_DT_PDUSessionResourceModifyListModCfm * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyListModCfm( SI_AMF_DT_PDUSessionResourceModifyListModCfm * data);

int __si_amf_Encode_PDUSessionResourceModifyListModCfm( SI_AMF_DT_PDUSessionResourceModifyListModCfm * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyConfirmTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceModifyConfirmTransferOctStr2( SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceModifyConfirmTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyConfirmTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceModifyConfirmTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModCfm( SI_AMF_DT_PDUSessionResourceModifyItemModCfm ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModCfm( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModCfm * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModCfm( SI_AMF_DT_PDUSessionResourceModifyItemModCfm * data);

int __si_amf_Encode_PDUSessionResourceModifyItemModCfm( SI_AMF_DT_PDUSessionResourceModifyItemModCfm * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModCfm_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyListModInd( SI_AMF_DT_PDUSessionResourceModifyListModInd ** data);

void __si_amf_debug_PDUSessionResourceModifyListModInd( char * key, SI_AMF_DT_PDUSessionResourceModifyListModInd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyListModInd( SI_AMF_DT_PDUSessionResourceModifyListModInd * data);

int __si_amf_Encode_PDUSessionResourceModifyListModInd( SI_AMF_DT_PDUSessionResourceModifyListModInd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyIndicationTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceModifyIndicationTransferOctStr2( SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceModifyIndicationTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyIndicationTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceModifyIndicationTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModInd( SI_AMF_DT_PDUSessionResourceModifyItemModInd ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModInd( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModInd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModInd( SI_AMF_DT_PDUSessionResourceModifyItemModInd * data);

int __si_amf_Encode_PDUSessionResourceModifyItemModInd( SI_AMF_DT_PDUSessionResourceModifyItemModInd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModInd_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModInd_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModInd_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyItemModInd_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyListModReq( SI_AMF_DT_PDUSessionResourceModifyListModReq ** data);

void __si_amf_debug_PDUSessionResourceModifyListModReq( char * key, SI_AMF_DT_PDUSessionResourceModifyListModReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyListModReq( SI_AMF_DT_PDUSessionResourceModifyListModReq * data);

int __si_amf_Encode_PDUSessionResourceModifyListModReq( SI_AMF_DT_PDUSessionResourceModifyListModReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceModifyRequestTransferOctStr2( SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceModifyRequestTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceModifyRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModReq( SI_AMF_DT_PDUSessionResourceModifyItemModReq ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModReq( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModReq( SI_AMF_DT_PDUSessionResourceModifyItemModReq * data);

int __si_amf_Encode_PDUSessionResourceModifyItemModReq( SI_AMF_DT_PDUSessionResourceModifyItemModReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModReq_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModReq_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModReq_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyItemModReq_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyListModRes( SI_AMF_DT_PDUSessionResourceModifyListModRes ** data);

void __si_amf_debug_PDUSessionResourceModifyListModRes( char * key, SI_AMF_DT_PDUSessionResourceModifyListModRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyListModRes( SI_AMF_DT_PDUSessionResourceModifyListModRes * data);

int __si_amf_Encode_PDUSessionResourceModifyListModRes( SI_AMF_DT_PDUSessionResourceModifyListModRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceModifyResponseTransferOctStr2( SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceModifyResponseTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceModifyResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModRes( SI_AMF_DT_PDUSessionResourceModifyItemModRes ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModRes( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModRes( SI_AMF_DT_PDUSessionResourceModifyItemModRes * data);

int __si_amf_Encode_PDUSessionResourceModifyItemModRes( SI_AMF_DT_PDUSessionResourceModifyItemModRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyItemModRes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer ** data);

void __si_amf_debug_PDUSessionResourceModifyUnsuccessfulTransfer( char * key, SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer * data);

int __si_amf_Encode_PDUSessionResourceModifyUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyList( SI_AMF_DT_PDUSessionResourceNotifyList ** data);

void __si_amf_debug_PDUSessionResourceNotifyList( char * key, SI_AMF_DT_PDUSessionResourceNotifyList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyList( SI_AMF_DT_PDUSessionResourceNotifyList * data);

int __si_amf_Encode_PDUSessionResourceNotifyList( SI_AMF_DT_PDUSessionResourceNotifyList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceNotifyTransferOctStr2( SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceNotifyTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceNotifyTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyItem( SI_AMF_DT_PDUSessionResourceNotifyItem ** data);

void __si_amf_debug_PDUSessionResourceNotifyItem( char * key, SI_AMF_DT_PDUSessionResourceNotifyItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyItem( SI_AMF_DT_PDUSessionResourceNotifyItem * data);

int __si_amf_Encode_PDUSessionResourceNotifyItem( SI_AMF_DT_PDUSessionResourceNotifyItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyItem_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceNotifyItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyItem_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceNotifyItem_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyReleasedTransfer( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer ** data);

void __si_amf_debug_PDUSessionResourceNotifyReleasedTransfer( char * key, SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyReleasedTransfer( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer * data);

int __si_amf_Encode_PDUSessionResourceNotifyReleasedTransfer( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowNotifyList( SI_AMF_DT_QosFlowNotifyList ** data);

void __si_amf_debug_QosFlowNotifyList( char * key, SI_AMF_DT_QosFlowNotifyList * data, int lvl);

void __si_amf_memfree_QosFlowNotifyList( SI_AMF_DT_QosFlowNotifyList * data);

int __si_amf_Encode_QosFlowNotifyList( SI_AMF_DT_QosFlowNotifyList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyTransfer( SI_AMF_DT_PDUSessionResourceNotifyTransfer ** data);

void __si_amf_debug_PDUSessionResourceNotifyTransfer( char * key, SI_AMF_DT_PDUSessionResourceNotifyTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyTransfer( SI_AMF_DT_PDUSessionResourceNotifyTransfer * data);

int __si_amf_Encode_PDUSessionResourceNotifyTransfer( SI_AMF_DT_PDUSessionResourceNotifyTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceNotifyTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceNotifyTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleaseCommandTransfer( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer ** data);

void __si_amf_debug_PDUSessionResourceReleaseCommandTransfer( char * key, SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleaseCommandTransfer( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer * data);

int __si_amf_Encode_PDUSessionResourceReleaseCommandTransfer( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleaseCommandTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceReleaseCommandTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleaseCommandTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceReleaseCommandTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedListNot( SI_AMF_DT_PDUSessionResourceReleasedListNot ** data);

void __si_amf_debug_PDUSessionResourceReleasedListNot( char * key, SI_AMF_DT_PDUSessionResourceReleasedListNot * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedListNot( SI_AMF_DT_PDUSessionResourceReleasedListNot * data);

int __si_amf_Encode_PDUSessionResourceReleasedListNot( SI_AMF_DT_PDUSessionResourceReleasedListNot * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceNotifyReleasedTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceNotifyReleasedTransferOctStr2( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceNotifyReleasedTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceNotifyReleasedTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceNotifyReleasedTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemNot( SI_AMF_DT_PDUSessionResourceReleasedItemNot ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemNot( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemNot * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemNot( SI_AMF_DT_PDUSessionResourceReleasedItemNot * data);

int __si_amf_Encode_PDUSessionResourceReleasedItemNot( SI_AMF_DT_PDUSessionResourceReleasedItemNot * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemNot_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemNot_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemNot_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceReleasedItemNot_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedListPSAck( SI_AMF_DT_PDUSessionResourceReleasedListPSAck ** data);

void __si_amf_debug_PDUSessionResourceReleasedListPSAck( char * key, SI_AMF_DT_PDUSessionResourceReleasedListPSAck * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedListPSAck( SI_AMF_DT_PDUSessionResourceReleasedListPSAck * data);

int __si_amf_Encode_PDUSessionResourceReleasedListPSAck( SI_AMF_DT_PDUSessionResourceReleasedListPSAck * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestUnsuccessfulTransferOctStr( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr ** data);

void __si_amf_init_PathSwitchRequestUnsuccessfulTransferOctStr2( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PathSwitchRequestUnsuccessfulTransferOctStr( char * key, SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr * data, int lvl);

void __si_amf_memfree_PathSwitchRequestUnsuccessfulTransferOctStr( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr * data);

int __si_amf_Encode_PathSwitchRequestUnsuccessfulTransferOctStr( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemPSAck( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemPSAck( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemPSAck * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemPSAck( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck * data);

int __si_amf_Encode_PDUSessionResourceReleasedItemPSAck( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemPSAck_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemPSAck_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemPSAck_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceReleasedItemPSAck_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedListPSFail( SI_AMF_DT_PDUSessionResourceReleasedListPSFail ** data);

void __si_amf_debug_PDUSessionResourceReleasedListPSFail( char * key, SI_AMF_DT_PDUSessionResourceReleasedListPSFail * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedListPSFail( SI_AMF_DT_PDUSessionResourceReleasedListPSFail * data);

int __si_amf_Encode_PDUSessionResourceReleasedListPSFail( SI_AMF_DT_PDUSessionResourceReleasedListPSFail * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemPSFail( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemPSFail( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemPSFail * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemPSFail( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail * data);

int __si_amf_Encode_PDUSessionResourceReleasedItemPSFail( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemPSFail_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemPSFail_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemPSFail_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceReleasedItemPSFail_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedListRelRes( SI_AMF_DT_PDUSessionResourceReleasedListRelRes ** data);

void __si_amf_debug_PDUSessionResourceReleasedListRelRes( char * key, SI_AMF_DT_PDUSessionResourceReleasedListRelRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedListRelRes( SI_AMF_DT_PDUSessionResourceReleasedListRelRes * data);

int __si_amf_Encode_PDUSessionResourceReleasedListRelRes( SI_AMF_DT_PDUSessionResourceReleasedListRelRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemRelRes( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemRelRes( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemRelRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemRelRes( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes * data);

int __si_amf_Encode_PDUSessionResourceReleasedItemRelRes( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleasedItemRelRes_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceReleasedItemRelRes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleasedItemRelRes_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceReleasedItemRelRes_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleaseResponseTransfer( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer ** data);

void __si_amf_debug_PDUSessionResourceReleaseResponseTransfer( char * key, SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleaseResponseTransfer( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer * data);

int __si_amf_Encode_PDUSessionResourceReleaseResponseTransfer( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleaseResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceReleaseResponseTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleaseResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceReleaseResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSecondaryRATUsageList( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList ** data);

void __si_amf_debug_PDUSessionResourceSecondaryRATUsageList( char * key, SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSecondaryRATUsageList( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList * data);

int __si_amf_Encode_PDUSessionResourceSecondaryRATUsageList( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecondaryRATDataUsageReportTransferOctStr( SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr ** data);

void __si_amf_init_SecondaryRATDataUsageReportTransferOctStr2( SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_SecondaryRATDataUsageReportTransferOctStr( char * key, SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr * data, int lvl);

void __si_amf_memfree_SecondaryRATDataUsageReportTransferOctStr( SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr * data);

int __si_amf_Encode_SecondaryRATDataUsageReportTransferOctStr( SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSecondaryRATUsageItem( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem ** data);

void __si_amf_debug_PDUSessionResourceSecondaryRATUsageItem( char * key, SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSecondaryRATUsageItem( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem * data);

int __si_amf_Encode_PDUSessionResourceSecondaryRATUsageItem( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupListCxtReq( SI_AMF_DT_PDUSessionResourceSetupListCxtReq ** data);

void __si_amf_debug_PDUSessionResourceSetupListCxtReq( char * key, SI_AMF_DT_PDUSessionResourceSetupListCxtReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupListCxtReq( SI_AMF_DT_PDUSessionResourceSetupListCxtReq * data);

int __si_amf_Encode_PDUSessionResourceSetupListCxtReq( SI_AMF_DT_PDUSessionResourceSetupListCxtReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceSetupRequestTransferOctStr2( SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceSetupRequestTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceSetupRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemCxtReq( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq ** data);

void __si_amf_debug_PDUSessionResourceSetupItemCxtReq( char * key, SI_AMF_DT_PDUSessionResourceSetupItemCxtReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemCxtReq( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq * data);

int __si_amf_Encode_PDUSessionResourceSetupItemCxtReq( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemCxtReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupItemCxtReq_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemCxtReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupItemCxtReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupListCxtRes( SI_AMF_DT_PDUSessionResourceSetupListCxtRes ** data);

void __si_amf_debug_PDUSessionResourceSetupListCxtRes( char * key, SI_AMF_DT_PDUSessionResourceSetupListCxtRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupListCxtRes( SI_AMF_DT_PDUSessionResourceSetupListCxtRes * data);

int __si_amf_Encode_PDUSessionResourceSetupListCxtRes( SI_AMF_DT_PDUSessionResourceSetupListCxtRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceSetupResponseTransferOctStr2( SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceSetupResponseTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceSetupResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes ** data);

void __si_amf_debug_PDUSessionResourceSetupItemCxtRes( char * key, SI_AMF_DT_PDUSessionResourceSetupItemCxtRes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes * data);

int __si_amf_Encode_PDUSessionResourceSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupItemCxtRes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupListHOReq( SI_AMF_DT_PDUSessionResourceSetupListHOReq ** data);

void __si_amf_debug_PDUSessionResourceSetupListHOReq( char * key, SI_AMF_DT_PDUSessionResourceSetupListHOReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupListHOReq( SI_AMF_DT_PDUSessionResourceSetupListHOReq * data);

int __si_amf_Encode_PDUSessionResourceSetupListHOReq( SI_AMF_DT_PDUSessionResourceSetupListHOReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemHOReq( SI_AMF_DT_PDUSessionResourceSetupItemHOReq ** data);

void __si_amf_debug_PDUSessionResourceSetupItemHOReq( char * key, SI_AMF_DT_PDUSessionResourceSetupItemHOReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemHOReq( SI_AMF_DT_PDUSessionResourceSetupItemHOReq * data);

int __si_amf_Encode_PDUSessionResourceSetupItemHOReq( SI_AMF_DT_PDUSessionResourceSetupItemHOReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemHOReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupItemHOReq_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemHOReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupItemHOReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupListSUReq( SI_AMF_DT_PDUSessionResourceSetupListSUReq ** data);

void __si_amf_debug_PDUSessionResourceSetupListSUReq( char * key, SI_AMF_DT_PDUSessionResourceSetupListSUReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupListSUReq( SI_AMF_DT_PDUSessionResourceSetupListSUReq * data);

int __si_amf_Encode_PDUSessionResourceSetupListSUReq( SI_AMF_DT_PDUSessionResourceSetupListSUReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemSUReq( SI_AMF_DT_PDUSessionResourceSetupItemSUReq ** data);

void __si_amf_debug_PDUSessionResourceSetupItemSUReq( char * key, SI_AMF_DT_PDUSessionResourceSetupItemSUReq * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemSUReq( SI_AMF_DT_PDUSessionResourceSetupItemSUReq * data);

int __si_amf_Encode_PDUSessionResourceSetupItemSUReq( SI_AMF_DT_PDUSessionResourceSetupItemSUReq * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemSUReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupItemSUReq_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemSUReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupItemSUReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupListSURes( SI_AMF_DT_PDUSessionResourceSetupListSURes ** data);

void __si_amf_debug_PDUSessionResourceSetupListSURes( char * key, SI_AMF_DT_PDUSessionResourceSetupListSURes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupListSURes( SI_AMF_DT_PDUSessionResourceSetupListSURes * data);

int __si_amf_Encode_PDUSessionResourceSetupListSURes( SI_AMF_DT_PDUSessionResourceSetupListSURes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemSURes( SI_AMF_DT_PDUSessionResourceSetupItemSURes ** data);

void __si_amf_debug_PDUSessionResourceSetupItemSURes( char * key, SI_AMF_DT_PDUSessionResourceSetupItemSURes * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemSURes( SI_AMF_DT_PDUSessionResourceSetupItemSURes * data);

int __si_amf_Encode_PDUSessionResourceSetupItemSURes( SI_AMF_DT_PDUSessionResourceSetupItemSURes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupItemSURes_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupRequestTransfer( SI_AMF_DT_PDUSessionResourceSetupRequestTransfer ** data);

void __si_amf_debug_PDUSessionResourceSetupRequestTransfer( char * key, SI_AMF_DT_PDUSessionResourceSetupRequestTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupRequestTransfer( SI_AMF_DT_PDUSessionResourceSetupRequestTransfer * data);

int __si_amf_Encode_PDUSessionResourceSetupRequestTransfer( SI_AMF_DT_PDUSessionResourceSetupRequestTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupResponseTransfer( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer ** data);

void __si_amf_debug_PDUSessionResourceSetupResponseTransfer( char * key, SI_AMF_DT_PDUSessionResourceSetupResponseTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupResponseTransfer( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer * data);

int __si_amf_Encode_PDUSessionResourceSetupResponseTransfer( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupResponseTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer ** data);

void __si_amf_debug_PDUSessionResourceSetupUnsuccessfulTransfer( char * key, SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer * data);

int __si_amf_Encode_PDUSessionResourceSetupUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSwitchedList( SI_AMF_DT_PDUSessionResourceSwitchedList ** data);

void __si_amf_debug_PDUSessionResourceSwitchedList( char * key, SI_AMF_DT_PDUSessionResourceSwitchedList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSwitchedList( SI_AMF_DT_PDUSessionResourceSwitchedList * data);

int __si_amf_Encode_PDUSessionResourceSwitchedList( SI_AMF_DT_PDUSessionResourceSwitchedList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestAcknowledgeTransferOctStr( SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr ** data);

void __si_amf_init_PathSwitchRequestAcknowledgeTransferOctStr2( SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PathSwitchRequestAcknowledgeTransferOctStr( char * key, SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr * data, int lvl);

void __si_amf_memfree_PathSwitchRequestAcknowledgeTransferOctStr( SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr * data);

int __si_amf_Encode_PathSwitchRequestAcknowledgeTransferOctStr( SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSwitchedItem( SI_AMF_DT_PDUSessionResourceSwitchedItem ** data);

void __si_amf_debug_PDUSessionResourceSwitchedItem( char * key, SI_AMF_DT_PDUSessionResourceSwitchedItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSwitchedItem( SI_AMF_DT_PDUSessionResourceSwitchedItem * data);

int __si_amf_Encode_PDUSessionResourceSwitchedItem( SI_AMF_DT_PDUSessionResourceSwitchedItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceSwitchedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceSwitchedItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceSwitchedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceSwitchedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToBeSwitchedDLList( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList ** data);

void __si_amf_debug_PDUSessionResourceToBeSwitchedDLList( char * key, SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToBeSwitchedDLList( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList * data);

int __si_amf_Encode_PDUSessionResourceToBeSwitchedDLList( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PathSwitchRequestTransferOctStr( SI_AMF_DT_PathSwitchRequestTransferOctStr ** data);

void __si_amf_init_PathSwitchRequestTransferOctStr2( SI_AMF_DT_PathSwitchRequestTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PathSwitchRequestTransferOctStr( char * key, SI_AMF_DT_PathSwitchRequestTransferOctStr * data, int lvl);

void __si_amf_memfree_PathSwitchRequestTransferOctStr( SI_AMF_DT_PathSwitchRequestTransferOctStr * data);

int __si_amf_Encode_PathSwitchRequestTransferOctStr( SI_AMF_DT_PathSwitchRequestTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToBeSwitchedDLItem( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem ** data);

void __si_amf_debug_PDUSessionResourceToBeSwitchedDLItem( char * key, SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToBeSwitchedDLItem( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem * data);

int __si_amf_Encode_PDUSessionResourceToBeSwitchedDLItem( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToReleaseListHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd ** data);

void __si_amf_debug_PDUSessionResourceToReleaseListHOCmd( char * key, SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToReleaseListHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd * data);

int __si_amf_Encode_PDUSessionResourceToReleaseListHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_HandoverPreparationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr ** data);

void __si_amf_init_HandoverPreparationUnsuccessfulTransferOctStr2( SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_HandoverPreparationUnsuccessfulTransferOctStr( char * key, SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr * data, int lvl);

void __si_amf_memfree_HandoverPreparationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr * data);

int __si_amf_Encode_HandoverPreparationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToReleaseItemHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd ** data);

void __si_amf_debug_PDUSessionResourceToReleaseItemHOCmd( char * key, SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToReleaseItemHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd * data);

int __si_amf_Encode_PDUSessionResourceToReleaseItemHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToReleaseListRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd ** data);

void __si_amf_debug_PDUSessionResourceToReleaseListRelCmd( char * key, SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToReleaseListRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd * data);

int __si_amf_Encode_PDUSessionResourceToReleaseListRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceReleaseCommandTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr ** data);

void __si_amf_init_PDUSessionResourceReleaseCommandTransferOctStr2( SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_PDUSessionResourceReleaseCommandTransferOctStr( char * key, SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr * data, int lvl);

void __si_amf_memfree_PDUSessionResourceReleaseCommandTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr * data);

int __si_amf_Encode_PDUSessionResourceReleaseCommandTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToReleaseItemRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd ** data);

void __si_amf_debug_PDUSessionResourceToReleaseItemRelCmd( char * key, SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToReleaseItemRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd * data);

int __si_amf_Encode_PDUSessionResourceToReleaseItemRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs ** data);

void __si_amf_debug_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( char * key, SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_PDUSessionType( char * key, uint8_t ePDUSessionType, int lvl);

int __si_amf_Encode_PDUSessionType( uint8_t ePDUSessionType, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PDUSessionUsageReport_ExtIEs( SI_AMF_DT_PDUSessionUsageReport_ExtIEs ** data);

void __si_amf_debug_PDUSessionUsageReport_ExtIEs( char * key, SI_AMF_DT_PDUSessionUsageReport_ExtIEs * data, int lvl);

void __si_amf_memfree_PDUSessionUsageReport_ExtIEs( SI_AMF_DT_PDUSessionUsageReport_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PDUSessionUsageReport_ExtIEs( SI_AMF_DT_PDUSessionUsageReport_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PLMNSupportList( SI_AMF_DT_PLMNSupportList ** data);

void __si_amf_debug_PLMNSupportList( char * key, SI_AMF_DT_PLMNSupportList * data, int lvl);

void __si_amf_memfree_PLMNSupportList( SI_AMF_DT_PLMNSupportList * data);

int __si_amf_Encode_PLMNSupportList( SI_AMF_DT_PLMNSupportList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PLMNSupportItem( SI_AMF_DT_PLMNSupportItem ** data);

void __si_amf_debug_PLMNSupportItem( char * key, SI_AMF_DT_PLMNSupportItem * data, int lvl);

void __si_amf_memfree_PLMNSupportItem( SI_AMF_DT_PLMNSupportItem * data);

int __si_amf_Encode_PLMNSupportItem( SI_AMF_DT_PLMNSupportItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PLMNSupportItem_ExtIEs( SI_AMF_DT_PLMNSupportItem_ExtIEs ** data);

void __si_amf_debug_PLMNSupportItem_ExtIEs( char * key, SI_AMF_DT_PLMNSupportItem_ExtIEs * data, int lvl);

void __si_amf_memfree_PLMNSupportItem_ExtIEs( SI_AMF_DT_PLMNSupportItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_PLMNSupportItem_ExtIEs( SI_AMF_DT_PLMNSupportItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PWSFailedCellIDList( SI_AMF_DT_PWSFailedCellIDList ** data);

void __si_amf_debug_PWSFailedCellIDList( char * key, SI_AMF_DT_PWSFailedCellIDList * data, int lvl);

void __si_amf_memfree_PWSFailedCellIDList( SI_AMF_DT_PWSFailedCellIDList * data);

int __si_amf_Encode_PWSFailedCellIDList( SI_AMF_DT_PWSFailedCellIDList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_PWSFailedCellIDList_ExtIEs( SI_AMF_DT_PWSFailedCellIDList_ExtIEs ** data);

void __si_amf_debug_PWSFailedCellIDList_ExtIEs( char * key, SI_AMF_DT_PWSFailedCellIDList_ExtIEs * data, int lvl);

void __si_amf_memfree_PWSFailedCellIDList_ExtIEs( SI_AMF_DT_PWSFailedCellIDList_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_PWSFailedCellIDList_ExtIEs( SI_AMF_DT_PWSFailedCellIDList_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosCharacteristics( SI_AMF_DT_QosCharacteristics ** data);

void __si_amf_debug_QosCharacteristics( char * key, SI_AMF_DT_QosCharacteristics * data, int lvl);

void __si_amf_memfree_QosCharacteristics( SI_AMF_DT_QosCharacteristics * data);

int __si_amf_Encode_QosCharacteristics( SI_AMF_DT_QosCharacteristics * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosCharacteristics_ExtIEs( SI_AMF_DT_QosCharacteristics_ExtIEs ** data);

void __si_amf_debug_QosCharacteristics_ExtIEs( char * key, SI_AMF_DT_QosCharacteristics_ExtIEs * data, int lvl);

void __si_amf_memfree_QosCharacteristics_ExtIEs( SI_AMF_DT_QosCharacteristics_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_QosCharacteristics_ExtIEs( SI_AMF_DT_QosCharacteristics_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAcceptedItem( SI_AMF_DT_QosFlowAcceptedItem ** data);

void __si_amf_debug_QosFlowAcceptedItem( char * key, SI_AMF_DT_QosFlowAcceptedItem * data, int lvl);

void __si_amf_memfree_QosFlowAcceptedItem( SI_AMF_DT_QosFlowAcceptedItem * data);

int __si_amf_Encode_QosFlowAcceptedItem( SI_AMF_DT_QosFlowAcceptedItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAcceptedItem_ExtIEs( SI_AMF_DT_QosFlowAcceptedItem_ExtIEs ** data);

void __si_amf_debug_QosFlowAcceptedItem_ExtIEs( char * key, SI_AMF_DT_QosFlowAcceptedItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowAcceptedItem_ExtIEs( SI_AMF_DT_QosFlowAcceptedItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowAcceptedItem_ExtIEs( SI_AMF_DT_QosFlowAcceptedItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ReflectiveQosAttribute( char * key, uint8_t eReflectiveQosAttribute, int lvl);

int __si_amf_Encode_ReflectiveQosAttribute( uint8_t eReflectiveQosAttribute, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowLevelQosParameters( SI_AMF_DT_QosFlowLevelQosParameters ** data);

void __si_amf_debug_QosFlowLevelQosParameters( char * key, SI_AMF_DT_QosFlowLevelQosParameters * data, int lvl);

void __si_amf_memfree_QosFlowLevelQosParameters( SI_AMF_DT_QosFlowLevelQosParameters * data);

int __si_amf_Encode_QosFlowLevelQosParameters( SI_AMF_DT_QosFlowLevelQosParameters * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAddOrModifyRequestItem( SI_AMF_DT_QosFlowAddOrModifyRequestItem ** data);

void __si_amf_debug_QosFlowAddOrModifyRequestItem( char * key, SI_AMF_DT_QosFlowAddOrModifyRequestItem * data, int lvl);

void __si_amf_memfree_QosFlowAddOrModifyRequestItem( SI_AMF_DT_QosFlowAddOrModifyRequestItem * data);

int __si_amf_Encode_QosFlowAddOrModifyRequestItem( SI_AMF_DT_QosFlowAddOrModifyRequestItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAddOrModifyRequestItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs ** data);

void __si_amf_debug_QosFlowAddOrModifyRequestItem_ExtIEs( char * key, SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowAddOrModifyRequestItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowAddOrModifyRequestItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAddOrModifyResponseItem( SI_AMF_DT_QosFlowAddOrModifyResponseItem ** data);

void __si_amf_debug_QosFlowAddOrModifyResponseItem( char * key, SI_AMF_DT_QosFlowAddOrModifyResponseItem * data, int lvl);

void __si_amf_memfree_QosFlowAddOrModifyResponseItem( SI_AMF_DT_QosFlowAddOrModifyResponseItem * data);

int __si_amf_Encode_QosFlowAddOrModifyResponseItem( SI_AMF_DT_QosFlowAddOrModifyResponseItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowAddOrModifyResponseItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs ** data);

void __si_amf_debug_QosFlowAddOrModifyResponseItem_ExtIEs( char * key, SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowAddOrModifyResponseItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowAddOrModifyResponseItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowInformationItem( SI_AMF_DT_QosFlowInformationItem ** data);

void __si_amf_debug_QosFlowInformationItem( char * key, SI_AMF_DT_QosFlowInformationItem * data, int lvl);

void __si_amf_memfree_QosFlowInformationItem( SI_AMF_DT_QosFlowInformationItem * data);

int __si_amf_Encode_QosFlowInformationItem( SI_AMF_DT_QosFlowInformationItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ULForwarding( char * key, uint8_t eULForwarding, int lvl);

int __si_amf_Encode_ULForwarding( uint8_t eULForwarding, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowInformationItem_ExtIEs( SI_AMF_DT_QosFlowInformationItem_ExtIEs ** data);

void __si_amf_debug_QosFlowInformationItem_ExtIEs( char * key, SI_AMF_DT_QosFlowInformationItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowInformationItem_ExtIEs( SI_AMF_DT_QosFlowInformationItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowInformationItem_ExtIEs( SI_AMF_DT_QosFlowInformationItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowLevelQosParameters_ExtIEs( SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs ** data);

void __si_amf_debug_QosFlowLevelQosParameters_ExtIEs( char * key, SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowLevelQosParameters_ExtIEs( SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowLevelQosParameters_ExtIEs( SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowWithCauseItem( SI_AMF_DT_QosFlowWithCauseItem ** data);

void __si_amf_debug_QosFlowWithCauseItem( char * key, SI_AMF_DT_QosFlowWithCauseItem * data, int lvl);

void __si_amf_memfree_QosFlowWithCauseItem( SI_AMF_DT_QosFlowWithCauseItem * data);

int __si_amf_Encode_QosFlowWithCauseItem( SI_AMF_DT_QosFlowWithCauseItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowWithCauseItem_ExtIEs( SI_AMF_DT_QosFlowWithCauseItem_ExtIEs ** data);

void __si_amf_debug_QosFlowWithCauseItem_ExtIEs( char * key, SI_AMF_DT_QosFlowWithCauseItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowWithCauseItem_ExtIEs( SI_AMF_DT_QosFlowWithCauseItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowWithCauseItem_ExtIEs( SI_AMF_DT_QosFlowWithCauseItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowModifyConfirmItem( SI_AMF_DT_QosFlowModifyConfirmItem ** data);

void __si_amf_debug_QosFlowModifyConfirmItem( char * key, SI_AMF_DT_QosFlowModifyConfirmItem * data, int lvl);

void __si_amf_memfree_QosFlowModifyConfirmItem( SI_AMF_DT_QosFlowModifyConfirmItem * data);

int __si_amf_Encode_QosFlowModifyConfirmItem( SI_AMF_DT_QosFlowModifyConfirmItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowModifyConfirmItem_ExtIEs( SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs ** data);

void __si_amf_debug_QosFlowModifyConfirmItem_ExtIEs( char * key, SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowModifyConfirmItem_ExtIEs( SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowModifyConfirmItem_ExtIEs( SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowNotifyItem( SI_AMF_DT_QosFlowNotifyItem ** data);

void __si_amf_debug_QosFlowNotifyItem( char * key, SI_AMF_DT_QosFlowNotifyItem * data, int lvl);

void __si_amf_memfree_QosFlowNotifyItem( SI_AMF_DT_QosFlowNotifyItem * data);

int __si_amf_Encode_QosFlowNotifyItem( SI_AMF_DT_QosFlowNotifyItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowNotifyItem_ExtIEs( SI_AMF_DT_QosFlowNotifyItem_ExtIEs ** data);

void __si_amf_debug_QosFlowNotifyItem_ExtIEs( char * key, SI_AMF_DT_QosFlowNotifyItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowNotifyItem_ExtIEs( SI_AMF_DT_QosFlowNotifyItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowNotifyItem_ExtIEs( SI_AMF_DT_QosFlowNotifyItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowPerTNLInformation_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs ** data);

void __si_amf_debug_QosFlowPerTNLInformation_ExtIEs( char * key, SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowPerTNLInformation_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowPerTNLInformation_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowPerTNLInformationItem( SI_AMF_DT_QosFlowPerTNLInformationItem ** data);

void __si_amf_debug_QosFlowPerTNLInformationItem( char * key, SI_AMF_DT_QosFlowPerTNLInformationItem * data, int lvl);

void __si_amf_memfree_QosFlowPerTNLInformationItem( SI_AMF_DT_QosFlowPerTNLInformationItem * data);

int __si_amf_Encode_QosFlowPerTNLInformationItem( SI_AMF_DT_QosFlowPerTNLInformationItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowPerTNLInformationItem_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs ** data);

void __si_amf_debug_QosFlowPerTNLInformationItem_ExtIEs( char * key, SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowPerTNLInformationItem_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowPerTNLInformationItem_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowSetupRequestList( SI_AMF_DT_QosFlowSetupRequestList ** data);

void __si_amf_debug_QosFlowSetupRequestList( char * key, SI_AMF_DT_QosFlowSetupRequestList * data, int lvl);

void __si_amf_memfree_QosFlowSetupRequestList( SI_AMF_DT_QosFlowSetupRequestList * data);

int __si_amf_Encode_QosFlowSetupRequestList( SI_AMF_DT_QosFlowSetupRequestList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowSetupRequestItem( SI_AMF_DT_QosFlowSetupRequestItem ** data);

void __si_amf_debug_QosFlowSetupRequestItem( char * key, SI_AMF_DT_QosFlowSetupRequestItem * data, int lvl);

void __si_amf_memfree_QosFlowSetupRequestItem( SI_AMF_DT_QosFlowSetupRequestItem * data);

int __si_amf_Encode_QosFlowSetupRequestItem( SI_AMF_DT_QosFlowSetupRequestItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowSetupRequestItem_ExtIEs( SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs ** data);

void __si_amf_debug_QosFlowSetupRequestItem_ExtIEs( char * key, SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowSetupRequestItem_ExtIEs( SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowSetupRequestItem_ExtIEs( SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowItemWithDataForwarding( SI_AMF_DT_QosFlowItemWithDataForwarding ** data);

void __si_amf_debug_QosFlowItemWithDataForwarding( char * key, SI_AMF_DT_QosFlowItemWithDataForwarding * data, int lvl);

void __si_amf_memfree_QosFlowItemWithDataForwarding( SI_AMF_DT_QosFlowItemWithDataForwarding * data);

int __si_amf_Encode_QosFlowItemWithDataForwarding( SI_AMF_DT_QosFlowItemWithDataForwarding * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowItemWithDataForwarding_ExtIEs( SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs ** data);

void __si_amf_debug_QosFlowItemWithDataForwarding_ExtIEs( char * key, SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowItemWithDataForwarding_ExtIEs( SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowItemWithDataForwarding_ExtIEs( SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowSetupResponseListSURes( SI_AMF_DT_QosFlowSetupResponseListSURes ** data);

void __si_amf_debug_QosFlowSetupResponseListSURes( char * key, SI_AMF_DT_QosFlowSetupResponseListSURes * data, int lvl);

void __si_amf_memfree_QosFlowSetupResponseListSURes( SI_AMF_DT_QosFlowSetupResponseListSURes * data);

int __si_amf_Encode_QosFlowSetupResponseListSURes( SI_AMF_DT_QosFlowSetupResponseListSURes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowSetupResponseItemSURes( SI_AMF_DT_QosFlowSetupResponseItemSURes ** data);

void __si_amf_debug_QosFlowSetupResponseItemSURes( char * key, SI_AMF_DT_QosFlowSetupResponseItemSURes * data, int lvl);

void __si_amf_memfree_QosFlowSetupResponseItemSURes( SI_AMF_DT_QosFlowSetupResponseItemSURes * data);

int __si_amf_Encode_QosFlowSetupResponseItemSURes( SI_AMF_DT_QosFlowSetupResponseItemSURes * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowSetupResponseItemSURes_ExtIEs( SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs ** data);

void __si_amf_debug_QosFlowSetupResponseItemSURes_ExtIEs( char * key, SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowSetupResponseItemSURes_ExtIEs( SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowSetupResponseItemSURes_ExtIEs( SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowToBeForwardedItem( SI_AMF_DT_QosFlowToBeForwardedItem ** data);

void __si_amf_debug_QosFlowToBeForwardedItem( char * key, SI_AMF_DT_QosFlowToBeForwardedItem * data, int lvl);

void __si_amf_memfree_QosFlowToBeForwardedItem( SI_AMF_DT_QosFlowToBeForwardedItem * data);

int __si_amf_Encode_QosFlowToBeForwardedItem( SI_AMF_DT_QosFlowToBeForwardedItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QosFlowToBeForwardedItem_ExtIEs( SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs ** data);

void __si_amf_debug_QosFlowToBeForwardedItem_ExtIEs( char * key, SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs * data, int lvl);

void __si_amf_memfree_QosFlowToBeForwardedItem_ExtIEs( SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QosFlowToBeForwardedItem_ExtIEs( SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_QoSFlowsUsageReport_ItemRatType( char * key, uint8_t eQoSFlowsUsageReport_ItemRatType, int lvl);

int __si_amf_Encode_QoSFlowsUsageReport_ItemRatType( uint8_t eQoSFlowsUsageReport_ItemRatType, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QoSFlowsUsageReport_Item( SI_AMF_DT_QoSFlowsUsageReport_Item ** data);

void __si_amf_debug_QoSFlowsUsageReport_Item( char * key, SI_AMF_DT_QoSFlowsUsageReport_Item * data, int lvl);

void __si_amf_memfree_QoSFlowsUsageReport_Item( SI_AMF_DT_QoSFlowsUsageReport_Item * data);

int __si_amf_Encode_QoSFlowsUsageReport_Item( SI_AMF_DT_QoSFlowsUsageReport_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_QoSFlowsUsageReport_Item_ExtIEs( SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs ** data);

void __si_amf_debug_QoSFlowsUsageReport_Item_ExtIEs( char * key, SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_QoSFlowsUsageReport_Item_ExtIEs( SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_QoSFlowsUsageReport_Item_ExtIEs( SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RANNodeName( SI_AMF_DT_RANNodeName ** data);

void __si_amf_init_RANNodeName2( SI_AMF_DT_RANNodeName ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_RANNodeName( char * key, SI_AMF_DT_RANNodeName * data, int lvl);

void __si_amf_memfree_RANNodeName( SI_AMF_DT_RANNodeName * data);

int __si_amf_Encode_RANNodeName( SI_AMF_DT_RANNodeName * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RANPagingPriority( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_RANPagingPriority( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RANStatusTransfer_TransparentContainer( SI_AMF_DT_RANStatusTransfer_TransparentContainer ** data);

void __si_amf_debug_RANStatusTransfer_TransparentContainer( char * key, SI_AMF_DT_RANStatusTransfer_TransparentContainer * data, int lvl);

void __si_amf_memfree_RANStatusTransfer_TransparentContainer( SI_AMF_DT_RANStatusTransfer_TransparentContainer * data);

int __si_amf_Encode_RANStatusTransfer_TransparentContainer( SI_AMF_DT_RANStatusTransfer_TransparentContainer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RANStatusTransfer_TransparentContainer_ExtIEs( SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs ** data);

void __si_amf_debug_RANStatusTransfer_TransparentContainer_ExtIEs( char * key, SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs * data, int lvl);

void __si_amf_memfree_RANStatusTransfer_TransparentContainer_ExtIEs( SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_RANStatusTransfer_TransparentContainer_ExtIEs( SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RAN_UE_NGAP_ID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_RAN_UE_NGAP_ID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RATRestrictionInformation( SI_AMF_DT_RATRestrictionInformation ** data);

void __si_amf_init_RATRestrictionInformation2( SI_AMF_DT_RATRestrictionInformation ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_RATRestrictionInformation( char * key, SI_AMF_DT_RATRestrictionInformation * data, int lvl);

void __si_amf_memfree_RATRestrictionInformation( SI_AMF_DT_RATRestrictionInformation * data);

int __si_amf_Encode_RATRestrictionInformation( SI_AMF_DT_RATRestrictionInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RATRestrictions_Item( SI_AMF_DT_RATRestrictions_Item ** data);

void __si_amf_debug_RATRestrictions_Item( char * key, SI_AMF_DT_RATRestrictions_Item * data, int lvl);

void __si_amf_memfree_RATRestrictions_Item( SI_AMF_DT_RATRestrictions_Item * data);

int __si_amf_Encode_RATRestrictions_Item( SI_AMF_DT_RATRestrictions_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RATRestrictions_Item_ExtIEs( SI_AMF_DT_RATRestrictions_Item_ExtIEs ** data);

void __si_amf_debug_RATRestrictions_Item_ExtIEs( char * key, SI_AMF_DT_RATRestrictions_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_RATRestrictions_Item_ExtIEs( SI_AMF_DT_RATRestrictions_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_RATRestrictions_Item_ExtIEs( SI_AMF_DT_RATRestrictions_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedCellsForPaging_ExtIEs( SI_AMF_DT_RecommendedCellsForPaging_ExtIEs ** data);

void __si_amf_debug_RecommendedCellsForPaging_ExtIEs( char * key, SI_AMF_DT_RecommendedCellsForPaging_ExtIEs * data, int lvl);

void __si_amf_memfree_RecommendedCellsForPaging_ExtIEs( SI_AMF_DT_RecommendedCellsForPaging_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_RecommendedCellsForPaging_ExtIEs( SI_AMF_DT_RecommendedCellsForPaging_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RecommendedCellItemTime( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_RecommendedCellItemTime( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedCellItem( SI_AMF_DT_RecommendedCellItem ** data);

void __si_amf_debug_RecommendedCellItem( char * key, SI_AMF_DT_RecommendedCellItem * data, int lvl);

void __si_amf_memfree_RecommendedCellItem( SI_AMF_DT_RecommendedCellItem * data);

int __si_amf_Encode_RecommendedCellItem( SI_AMF_DT_RecommendedCellItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedCellItem_ExtIEs( SI_AMF_DT_RecommendedCellItem_ExtIEs ** data);

void __si_amf_debug_RecommendedCellItem_ExtIEs( char * key, SI_AMF_DT_RecommendedCellItem_ExtIEs * data, int lvl);

void __si_amf_memfree_RecommendedCellItem_ExtIEs( SI_AMF_DT_RecommendedCellItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_RecommendedCellItem_ExtIEs( SI_AMF_DT_RecommendedCellItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedRANNodesForPaging_ExtIEs( SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs ** data);

void __si_amf_debug_RecommendedRANNodesForPaging_ExtIEs( char * key, SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs * data, int lvl);

void __si_amf_memfree_RecommendedRANNodesForPaging_ExtIEs( SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_RecommendedRANNodesForPaging_ExtIEs( SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedRANNodeItem( SI_AMF_DT_RecommendedRANNodeItem ** data);

void __si_amf_debug_RecommendedRANNodeItem( char * key, SI_AMF_DT_RecommendedRANNodeItem * data, int lvl);

void __si_amf_memfree_RecommendedRANNodeItem( SI_AMF_DT_RecommendedRANNodeItem * data);

int __si_amf_Encode_RecommendedRANNodeItem( SI_AMF_DT_RecommendedRANNodeItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RecommendedRANNodeItem_ExtIEs( SI_AMF_DT_RecommendedRANNodeItem_ExtIEs ** data);

void __si_amf_debug_RecommendedRANNodeItem_ExtIEs( char * key, SI_AMF_DT_RecommendedRANNodeItem_ExtIEs * data, int lvl);

void __si_amf_memfree_RecommendedRANNodeItem_ExtIEs( SI_AMF_DT_RecommendedRANNodeItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_RecommendedRANNodeItem_ExtIEs( SI_AMF_DT_RecommendedRANNodeItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ReferenceID( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_ReferenceID( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RelativeAMFCapacity( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_RelativeAMFCapacity( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RepetitionPeriod( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_RepetitionPeriod( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_ResetAll( char * key, uint8_t eResetAll, int lvl);

int __si_amf_Encode_ResetAll( uint8_t eResetAll, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_associatedLogicalNG_connectionList( SI_AMF_DT_UE_associatedLogicalNG_connectionList ** data);

void __si_amf_debug_UE_associatedLogicalNG_connectionList( char * key, SI_AMF_DT_UE_associatedLogicalNG_connectionList * data, int lvl);

void __si_amf_memfree_UE_associatedLogicalNG_connectionList( SI_AMF_DT_UE_associatedLogicalNG_connectionList * data);

int __si_amf_Encode_UE_associatedLogicalNG_connectionList( SI_AMF_DT_UE_associatedLogicalNG_connectionList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ResetType( SI_AMF_DT_ResetType ** data);

void __si_amf_debug_ResetType( char * key, SI_AMF_DT_ResetType * data, int lvl);

void __si_amf_memfree_ResetType( SI_AMF_DT_ResetType * data);

int __si_amf_Encode_ResetType( SI_AMF_DT_ResetType * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ResetType_ExtIEs( SI_AMF_DT_ResetType_ExtIEs ** data);

void __si_amf_debug_ResetType_ExtIEs( char * key, SI_AMF_DT_ResetType_ExtIEs * data, int lvl);

void __si_amf_memfree_ResetType_ExtIEs( SI_AMF_DT_ResetType_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_ResetType_ExtIEs( SI_AMF_DT_ResetType_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RoutingID( SI_AMF_DT_RoutingID ** data);

void __si_amf_init_RoutingID2( SI_AMF_DT_RoutingID ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_RoutingID( char * key, SI_AMF_DT_RoutingID * data, int lvl);

void __si_amf_memfree_RoutingID( SI_AMF_DT_RoutingID * data);

int __si_amf_Encode_RoutingID( SI_AMF_DT_RoutingID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RRCContainer( SI_AMF_DT_RRCContainer ** data);

void __si_amf_init_RRCContainer2( SI_AMF_DT_RRCContainer ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_RRCContainer( char * key, SI_AMF_DT_RRCContainer * data, int lvl);

void __si_amf_memfree_RRCContainer( SI_AMF_DT_RRCContainer * data);

int __si_amf_Encode_RRCContainer( SI_AMF_DT_RRCContainer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RRCEstablishmentCause( char * key, uint8_t eRRCEstablishmentCause, int lvl);

int __si_amf_Encode_RRCEstablishmentCause( uint8_t eRRCEstablishmentCause, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RRCInactiveTransitionReportRequest( char * key, uint8_t eRRCInactiveTransitionReportRequest, int lvl);

int __si_amf_Encode_RRCInactiveTransitionReportRequest( uint8_t eRRCInactiveTransitionReportRequest, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_RRCState( char * key, uint8_t eRRCState, int lvl);

int __si_amf_Encode_RRCState( uint8_t eRRCState, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SCTP_TLAs( SI_AMF_DT_SCTP_TLAs ** data);

void __si_amf_debug_SCTP_TLAs( char * key, SI_AMF_DT_SCTP_TLAs * data, int lvl);

void __si_amf_memfree_SCTP_TLAs( SI_AMF_DT_SCTP_TLAs * data);

int __si_amf_Encode_SCTP_TLAs( SI_AMF_DT_SCTP_TLAs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecondaryRATUsageInformation_ExtIEs( SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs ** data);

void __si_amf_debug_SecondaryRATUsageInformation_ExtIEs( char * key, SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_SecondaryRATUsageInformation_ExtIEs( SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SecondaryRATUsageInformation_ExtIEs( SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecondaryRATDataUsageReportTransfer( SI_AMF_DT_SecondaryRATDataUsageReportTransfer ** data);

void __si_amf_debug_SecondaryRATDataUsageReportTransfer( char * key, SI_AMF_DT_SecondaryRATDataUsageReportTransfer * data, int lvl);

void __si_amf_memfree_SecondaryRATDataUsageReportTransfer( SI_AMF_DT_SecondaryRATDataUsageReportTransfer * data);

int __si_amf_Encode_SecondaryRATDataUsageReportTransfer( SI_AMF_DT_SecondaryRATDataUsageReportTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecondaryRATDataUsageReportTransfer_ExtIEs( SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs ** data);

void __si_amf_debug_SecondaryRATDataUsageReportTransfer_ExtIEs( char * key, SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_SecondaryRATDataUsageReportTransfer_ExtIEs( SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SecondaryRATDataUsageReportTransfer_ExtIEs( SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityKey( SI_AMF_DT_SecurityKey ** data);

void __si_amf_init_SecurityKey2( SI_AMF_DT_SecurityKey ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_SecurityKey( char * key, SI_AMF_DT_SecurityKey * data, int lvl);

void __si_amf_memfree_SecurityKey( SI_AMF_DT_SecurityKey * data);

int __si_amf_Encode_SecurityKey( SI_AMF_DT_SecurityKey * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityContext( SI_AMF_DT_SecurityContext ** data);

void __si_amf_debug_SecurityContext( char * key, SI_AMF_DT_SecurityContext * data, int lvl);

void __si_amf_memfree_SecurityContext( SI_AMF_DT_SecurityContext * data);

int __si_amf_Encode_SecurityContext( SI_AMF_DT_SecurityContext * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityContext_ExtIEs( SI_AMF_DT_SecurityContext_ExtIEs ** data);

void __si_amf_debug_SecurityContext_ExtIEs( char * key, SI_AMF_DT_SecurityContext_ExtIEs * data, int lvl);

void __si_amf_memfree_SecurityContext_ExtIEs( SI_AMF_DT_SecurityContext_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SecurityContext_ExtIEs( SI_AMF_DT_SecurityContext_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityIndication_ExtIEs( SI_AMF_DT_SecurityIndication_ExtIEs ** data);

void __si_amf_debug_SecurityIndication_ExtIEs( char * key, SI_AMF_DT_SecurityIndication_ExtIEs * data, int lvl);

void __si_amf_memfree_SecurityIndication_ExtIEs( SI_AMF_DT_SecurityIndication_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SecurityIndication_ExtIEs( SI_AMF_DT_SecurityIndication_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SecurityResult_ExtIEs( SI_AMF_DT_SecurityResult_ExtIEs ** data);

void __si_amf_debug_SecurityResult_ExtIEs( char * key, SI_AMF_DT_SecurityResult_ExtIEs * data, int lvl);

void __si_amf_memfree_SecurityResult_ExtIEs( SI_AMF_DT_SecurityResult_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SecurityResult_ExtIEs( SI_AMF_DT_SecurityResult_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SerialNumber( SI_AMF_DT_SerialNumber ** data);

void __si_amf_init_SerialNumber2( SI_AMF_DT_SerialNumber ** data, u_char * cstr, uint32_t len, int bitslen);

void __si_amf_debug_SerialNumber( char * key, SI_AMF_DT_SerialNumber * data, int lvl);

void __si_amf_memfree_SerialNumber( SI_AMF_DT_SerialNumber * data);

int __si_amf_Encode_SerialNumber( SI_AMF_DT_SerialNumber * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ServedGUAMIList( SI_AMF_DT_ServedGUAMIList ** data);

void __si_amf_debug_ServedGUAMIList( char * key, SI_AMF_DT_ServedGUAMIList * data, int lvl);

void __si_amf_memfree_ServedGUAMIList( SI_AMF_DT_ServedGUAMIList * data);

int __si_amf_Encode_ServedGUAMIList( SI_AMF_DT_ServedGUAMIList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ServedGUAMIItem( SI_AMF_DT_ServedGUAMIItem ** data);

void __si_amf_debug_ServedGUAMIItem( char * key, SI_AMF_DT_ServedGUAMIItem * data, int lvl);

void __si_amf_memfree_ServedGUAMIItem( SI_AMF_DT_ServedGUAMIItem * data);

int __si_amf_Encode_ServedGUAMIItem( SI_AMF_DT_ServedGUAMIItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ServedGUAMIItem_ExtIEs( SI_AMF_DT_ServedGUAMIItem_ExtIEs ** data);

void __si_amf_debug_ServedGUAMIItem_ExtIEs( char * key, SI_AMF_DT_ServedGUAMIItem_ExtIEs * data, int lvl);

void __si_amf_memfree_ServedGUAMIItem_ExtIEs( SI_AMF_DT_ServedGUAMIItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_ServedGUAMIItem_ExtIEs( SI_AMF_DT_ServedGUAMIItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ServiceAreaInformation_Item( SI_AMF_DT_ServiceAreaInformation_Item ** data);

void __si_amf_debug_ServiceAreaInformation_Item( char * key, SI_AMF_DT_ServiceAreaInformation_Item * data, int lvl);

void __si_amf_memfree_ServiceAreaInformation_Item( SI_AMF_DT_ServiceAreaInformation_Item * data);

int __si_amf_Encode_ServiceAreaInformation_Item( SI_AMF_DT_ServiceAreaInformation_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ServiceAreaInformation_Item_ExtIEs( SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs ** data);

void __si_amf_debug_ServiceAreaInformation_Item_ExtIEs( char * key, SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_ServiceAreaInformation_Item_ExtIEs( SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_ServiceAreaInformation_Item_ExtIEs( SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SliceOverloadItem( SI_AMF_DT_SliceOverloadItem ** data);

void __si_amf_debug_SliceOverloadItem( char * key, SI_AMF_DT_SliceOverloadItem * data, int lvl);

void __si_amf_memfree_SliceOverloadItem( SI_AMF_DT_SliceOverloadItem * data);

int __si_amf_Encode_SliceOverloadItem( SI_AMF_DT_SliceOverloadItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SliceOverloadItem_ExtIEs( SI_AMF_DT_SliceOverloadItem_ExtIEs ** data);

void __si_amf_debug_SliceOverloadItem_ExtIEs( char * key, SI_AMF_DT_SliceOverloadItem_ExtIEs * data, int lvl);

void __si_amf_memfree_SliceOverloadItem_ExtIEs( SI_AMF_DT_SliceOverloadItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SliceOverloadItem_ExtIEs( SI_AMF_DT_SliceOverloadItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SliceSupportItem( SI_AMF_DT_SliceSupportItem ** data);

void __si_amf_debug_SliceSupportItem( char * key, SI_AMF_DT_SliceSupportItem * data, int lvl);

void __si_amf_memfree_SliceSupportItem( SI_AMF_DT_SliceSupportItem * data);

int __si_amf_Encode_SliceSupportItem( SI_AMF_DT_SliceSupportItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SliceSupportItem_ExtIEs( SI_AMF_DT_SliceSupportItem_ExtIEs ** data);

void __si_amf_debug_SliceSupportItem_ExtIEs( char * key, SI_AMF_DT_SliceSupportItem_ExtIEs * data, int lvl);

void __si_amf_memfree_SliceSupportItem_ExtIEs( SI_AMF_DT_SliceSupportItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SliceSupportItem_ExtIEs( SI_AMF_DT_SliceSupportItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_S_NSSAI_ExtIEs( SI_AMF_DT_S_NSSAI_ExtIEs ** data);

void __si_amf_debug_S_NSSAI_ExtIEs( char * key, SI_AMF_DT_S_NSSAI_ExtIEs * data, int lvl);

void __si_amf_memfree_S_NSSAI_ExtIEs( SI_AMF_DT_S_NSSAI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_S_NSSAI_ExtIEs( SI_AMF_DT_S_NSSAI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetRANNodeID( SI_AMF_DT_TargetRANNodeID ** data);

void __si_amf_debug_TargetRANNodeID( char * key, SI_AMF_DT_TargetRANNodeID * data, int lvl);

void __si_amf_memfree_TargetRANNodeID( SI_AMF_DT_TargetRANNodeID * data);

int __si_amf_Encode_TargetRANNodeID( SI_AMF_DT_TargetRANNodeID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceRANNodeID( SI_AMF_DT_SourceRANNodeID ** data);

void __si_amf_debug_SourceRANNodeID( char * key, SI_AMF_DT_SourceRANNodeID * data, int lvl);

void __si_amf_memfree_SourceRANNodeID( SI_AMF_DT_SourceRANNodeID * data);

int __si_amf_Encode_SourceRANNodeID( SI_AMF_DT_SourceRANNodeID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_SONInformationRequest( char * key, uint8_t eSONInformationRequest, int lvl);

int __si_amf_Encode_SONInformationRequest( uint8_t eSONInformationRequest, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnTLAs( SI_AMF_DT_XnTLAs ** data);

void __si_amf_debug_XnTLAs( char * key, SI_AMF_DT_XnTLAs * data, int lvl);

void __si_amf_memfree_XnTLAs( SI_AMF_DT_XnTLAs * data);

int __si_amf_Encode_XnTLAs( SI_AMF_DT_XnTLAs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnExtTLAs( SI_AMF_DT_XnExtTLAs ** data);

void __si_amf_debug_XnExtTLAs( char * key, SI_AMF_DT_XnExtTLAs * data, int lvl);

void __si_amf_memfree_XnExtTLAs( SI_AMF_DT_XnExtTLAs * data);

int __si_amf_Encode_XnExtTLAs( SI_AMF_DT_XnExtTLAs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnTNLConfigurationInfo( SI_AMF_DT_XnTNLConfigurationInfo ** data);

void __si_amf_debug_XnTNLConfigurationInfo( char * key, SI_AMF_DT_XnTNLConfigurationInfo * data, int lvl);

void __si_amf_memfree_XnTNLConfigurationInfo( SI_AMF_DT_XnTNLConfigurationInfo * data);

int __si_amf_Encode_XnTNLConfigurationInfo( SI_AMF_DT_XnTNLConfigurationInfo * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SONInformationReply( SI_AMF_DT_SONInformationReply ** data);

void __si_amf_debug_SONInformationReply( char * key, SI_AMF_DT_SONInformationReply * data, int lvl);

void __si_amf_memfree_SONInformationReply( SI_AMF_DT_SONInformationReply * data);

int __si_amf_Encode_SONInformationReply( SI_AMF_DT_SONInformationReply * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SONInformation( SI_AMF_DT_SONInformation ** data);

void __si_amf_debug_SONInformation( char * key, SI_AMF_DT_SONInformation * data, int lvl);

void __si_amf_memfree_SONInformation( SI_AMF_DT_SONInformation * data);

int __si_amf_Encode_SONInformation( SI_AMF_DT_SONInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SONConfigurationTransfer( SI_AMF_DT_SONConfigurationTransfer ** data);

void __si_amf_debug_SONConfigurationTransfer( char * key, SI_AMF_DT_SONConfigurationTransfer * data, int lvl);

void __si_amf_memfree_SONConfigurationTransfer( SI_AMF_DT_SONConfigurationTransfer * data);

int __si_amf_Encode_SONConfigurationTransfer( SI_AMF_DT_SONConfigurationTransfer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SONConfigurationTransfer_ExtIEs( SI_AMF_DT_SONConfigurationTransfer_ExtIEs ** data);

void __si_amf_debug_SONConfigurationTransfer_ExtIEs( char * key, SI_AMF_DT_SONConfigurationTransfer_ExtIEs * data, int lvl);

void __si_amf_memfree_SONConfigurationTransfer_ExtIEs( SI_AMF_DT_SONConfigurationTransfer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SONConfigurationTransfer_ExtIEs( SI_AMF_DT_SONConfigurationTransfer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SONInformation_ExtIEs( SI_AMF_DT_SONInformation_ExtIEs ** data);

void __si_amf_debug_SONInformation_ExtIEs( char * key, SI_AMF_DT_SONInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_SONInformation_ExtIEs( SI_AMF_DT_SONInformation_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_SONInformation_ExtIEs( SI_AMF_DT_SONInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SONInformationReply_ExtIEs( SI_AMF_DT_SONInformationReply_ExtIEs ** data);

void __si_amf_debug_SONInformationReply_ExtIEs( char * key, SI_AMF_DT_SONInformationReply_ExtIEs * data, int lvl);

void __si_amf_memfree_SONInformationReply_ExtIEs( SI_AMF_DT_SONInformationReply_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SONInformationReply_ExtIEs( SI_AMF_DT_SONInformationReply_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEHistoryInformation( SI_AMF_DT_UEHistoryInformation ** data);

void __si_amf_debug_UEHistoryInformation( char * key, SI_AMF_DT_UEHistoryInformation * data, int lvl);

void __si_amf_memfree_UEHistoryInformation( SI_AMF_DT_UEHistoryInformation * data);

int __si_amf_Encode_UEHistoryInformation( SI_AMF_DT_UEHistoryInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer ** data);

void __si_amf_debug_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( char * key, SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer * data, int lvl);

void __si_amf_memfree_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer * data);

int __si_amf_Encode_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs ** data);

void __si_amf_debug_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( char * key, SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs * data, int lvl);

void __si_amf_memfree_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceRANNodeID_ExtIEs( SI_AMF_DT_SourceRANNodeID_ExtIEs ** data);

void __si_amf_debug_SourceRANNodeID_ExtIEs( char * key, SI_AMF_DT_SourceRANNodeID_ExtIEs * data, int lvl);

void __si_amf_memfree_SourceRANNodeID_ExtIEs( SI_AMF_DT_SourceRANNodeID_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SourceRANNodeID_ExtIEs( SI_AMF_DT_SourceRANNodeID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceToTarget_TransparentContainer( SI_AMF_DT_SourceToTarget_TransparentContainer ** data);

void __si_amf_init_SourceToTarget_TransparentContainer2( SI_AMF_DT_SourceToTarget_TransparentContainer ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_SourceToTarget_TransparentContainer( char * key, SI_AMF_DT_SourceToTarget_TransparentContainer * data, int lvl);

void __si_amf_memfree_SourceToTarget_TransparentContainer( SI_AMF_DT_SourceToTarget_TransparentContainer * data);

int __si_amf_Encode_SourceToTarget_TransparentContainer( SI_AMF_DT_SourceToTarget_TransparentContainer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_ConfiguredNSSAI( SI_AMF_DT_ConfiguredNSSAI ** data);

void __si_amf_init_ConfiguredNSSAI2( SI_AMF_DT_ConfiguredNSSAI ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_ConfiguredNSSAI( char * key, SI_AMF_DT_ConfiguredNSSAI * data, int lvl);

void __si_amf_memfree_ConfiguredNSSAI( SI_AMF_DT_ConfiguredNSSAI * data);

int __si_amf_Encode_ConfiguredNSSAI( SI_AMF_DT_ConfiguredNSSAI * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RejectedNSSAIinPLMN( SI_AMF_DT_RejectedNSSAIinPLMN ** data);

void __si_amf_init_RejectedNSSAIinPLMN2( SI_AMF_DT_RejectedNSSAIinPLMN ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_RejectedNSSAIinPLMN( char * key, SI_AMF_DT_RejectedNSSAIinPLMN * data, int lvl);

void __si_amf_memfree_RejectedNSSAIinPLMN( SI_AMF_DT_RejectedNSSAIinPLMN * data);

int __si_amf_Encode_RejectedNSSAIinPLMN( SI_AMF_DT_RejectedNSSAIinPLMN * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_RejectedNSSAIinTA( SI_AMF_DT_RejectedNSSAIinTA ** data);

void __si_amf_init_RejectedNSSAIinTA2( SI_AMF_DT_RejectedNSSAIinTA ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_RejectedNSSAIinTA( char * key, SI_AMF_DT_RejectedNSSAIinTA * data, int lvl);

void __si_amf_memfree_RejectedNSSAIinTA( SI_AMF_DT_RejectedNSSAIinTA * data);

int __si_amf_Encode_RejectedNSSAIinTA( SI_AMF_DT_RejectedNSSAIinTA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceToTarget_AMFInformationReroute( SI_AMF_DT_SourceToTarget_AMFInformationReroute ** data);

void __si_amf_debug_SourceToTarget_AMFInformationReroute( char * key, SI_AMF_DT_SourceToTarget_AMFInformationReroute * data, int lvl);

void __si_amf_memfree_SourceToTarget_AMFInformationReroute( SI_AMF_DT_SourceToTarget_AMFInformationReroute * data);

int __si_amf_Encode_SourceToTarget_AMFInformationReroute( SI_AMF_DT_SourceToTarget_AMFInformationReroute * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SourceToTarget_AMFInformationReroute_ExtIEs( SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs ** data);

void __si_amf_debug_SourceToTarget_AMFInformationReroute_ExtIEs( char * key, SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs * data, int lvl);

void __si_amf_memfree_SourceToTarget_AMFInformationReroute_ExtIEs( SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SourceToTarget_AMFInformationReroute_ExtIEs( SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SupportedTAList( SI_AMF_DT_SupportedTAList ** data);

void __si_amf_debug_SupportedTAList( char * key, SI_AMF_DT_SupportedTAList * data, int lvl);

void __si_amf_memfree_SupportedTAList( SI_AMF_DT_SupportedTAList * data);

int __si_amf_Encode_SupportedTAList( SI_AMF_DT_SupportedTAList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SupportedTAItem( SI_AMF_DT_SupportedTAItem ** data);

void __si_amf_debug_SupportedTAItem( char * key, SI_AMF_DT_SupportedTAItem * data, int lvl);

void __si_amf_memfree_SupportedTAItem( SI_AMF_DT_SupportedTAItem * data);

int __si_amf_Encode_SupportedTAItem( SI_AMF_DT_SupportedTAItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_SupportedTAItem_ExtIEs( SI_AMF_DT_SupportedTAItem_ExtIEs ** data);

void __si_amf_debug_SupportedTAItem_ExtIEs( char * key, SI_AMF_DT_SupportedTAItem_ExtIEs * data, int lvl);

void __si_amf_memfree_SupportedTAItem_ExtIEs( SI_AMF_DT_SupportedTAItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_SupportedTAItem_ExtIEs( SI_AMF_DT_SupportedTAItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAI_ExtIEs( SI_AMF_DT_TAI_ExtIEs ** data);

void __si_amf_debug_TAI_ExtIEs( char * key, SI_AMF_DT_TAI_ExtIEs * data, int lvl);

void __si_amf_memfree_TAI_ExtIEs( SI_AMF_DT_TAI_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAI_ExtIEs( SI_AMF_DT_TAI_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIBroadcastEUTRA_Item( SI_AMF_DT_TAIBroadcastEUTRA_Item ** data);

void __si_amf_debug_TAIBroadcastEUTRA_Item( char * key, SI_AMF_DT_TAIBroadcastEUTRA_Item * data, int lvl);

void __si_amf_memfree_TAIBroadcastEUTRA_Item( SI_AMF_DT_TAIBroadcastEUTRA_Item * data);

int __si_amf_Encode_TAIBroadcastEUTRA_Item( SI_AMF_DT_TAIBroadcastEUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs ** data);

void __si_amf_debug_TAIBroadcastEUTRA_Item_ExtIEs( char * key, SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_TAIBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAIBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIBroadcastNR_Item( SI_AMF_DT_TAIBroadcastNR_Item ** data);

void __si_amf_debug_TAIBroadcastNR_Item( char * key, SI_AMF_DT_TAIBroadcastNR_Item * data, int lvl);

void __si_amf_memfree_TAIBroadcastNR_Item( SI_AMF_DT_TAIBroadcastNR_Item * data);

int __si_amf_Encode_TAIBroadcastNR_Item( SI_AMF_DT_TAIBroadcastNR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIBroadcastNR_Item_ExtIEs( SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs ** data);

void __si_amf_debug_TAIBroadcastNR_Item_ExtIEs( char * key, SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_TAIBroadcastNR_Item_ExtIEs( SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAIBroadcastNR_Item_ExtIEs( SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAICancelledEUTRA_Item( SI_AMF_DT_TAICancelledEUTRA_Item ** data);

void __si_amf_debug_TAICancelledEUTRA_Item( char * key, SI_AMF_DT_TAICancelledEUTRA_Item * data, int lvl);

void __si_amf_memfree_TAICancelledEUTRA_Item( SI_AMF_DT_TAICancelledEUTRA_Item * data);

int __si_amf_Encode_TAICancelledEUTRA_Item( SI_AMF_DT_TAICancelledEUTRA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAICancelledEUTRA_Item_ExtIEs( SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs ** data);

void __si_amf_debug_TAICancelledEUTRA_Item_ExtIEs( char * key, SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_TAICancelledEUTRA_Item_ExtIEs( SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAICancelledEUTRA_Item_ExtIEs( SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAICancelledNR_Item( SI_AMF_DT_TAICancelledNR_Item ** data);

void __si_amf_debug_TAICancelledNR_Item( char * key, SI_AMF_DT_TAICancelledNR_Item * data, int lvl);

void __si_amf_memfree_TAICancelledNR_Item( SI_AMF_DT_TAICancelledNR_Item * data);

int __si_amf_Encode_TAICancelledNR_Item( SI_AMF_DT_TAICancelledNR_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAICancelledNR_Item_ExtIEs( SI_AMF_DT_TAICancelledNR_Item_ExtIEs ** data);

void __si_amf_debug_TAICancelledNR_Item_ExtIEs( char * key, SI_AMF_DT_TAICancelledNR_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_TAICancelledNR_Item_ExtIEs( SI_AMF_DT_TAICancelledNR_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAICancelledNR_Item_ExtIEs( SI_AMF_DT_TAICancelledNR_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForInactiveItem( SI_AMF_DT_TAIListForInactiveItem ** data);

void __si_amf_debug_TAIListForInactiveItem( char * key, SI_AMF_DT_TAIListForInactiveItem * data, int lvl);

void __si_amf_memfree_TAIListForInactiveItem( SI_AMF_DT_TAIListForInactiveItem * data);

int __si_amf_Encode_TAIListForInactiveItem( SI_AMF_DT_TAIListForInactiveItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForInactiveItem_ExtIEs( SI_AMF_DT_TAIListForInactiveItem_ExtIEs ** data);

void __si_amf_debug_TAIListForInactiveItem_ExtIEs( char * key, SI_AMF_DT_TAIListForInactiveItem_ExtIEs * data, int lvl);

void __si_amf_memfree_TAIListForInactiveItem_ExtIEs( SI_AMF_DT_TAIListForInactiveItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAIListForInactiveItem_ExtIEs( SI_AMF_DT_TAIListForInactiveItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForPaging( SI_AMF_DT_TAIListForPaging ** data);

void __si_amf_debug_TAIListForPaging( char * key, SI_AMF_DT_TAIListForPaging * data, int lvl);

void __si_amf_memfree_TAIListForPaging( SI_AMF_DT_TAIListForPaging * data);

int __si_amf_Encode_TAIListForPaging( SI_AMF_DT_TAIListForPaging * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForPagingItem( SI_AMF_DT_TAIListForPagingItem ** data);

void __si_amf_debug_TAIListForPagingItem( char * key, SI_AMF_DT_TAIListForPagingItem * data, int lvl);

void __si_amf_memfree_TAIListForPagingItem( SI_AMF_DT_TAIListForPagingItem * data);

int __si_amf_Encode_TAIListForPagingItem( SI_AMF_DT_TAIListForPagingItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForPagingItem_ExtIEs( SI_AMF_DT_TAIListForPagingItem_ExtIEs ** data);

void __si_amf_debug_TAIListForPagingItem_ExtIEs( char * key, SI_AMF_DT_TAIListForPagingItem_ExtIEs * data, int lvl);

void __si_amf_memfree_TAIListForPagingItem_ExtIEs( SI_AMF_DT_TAIListForPagingItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TAIListForPagingItem_ExtIEs( SI_AMF_DT_TAIListForPagingItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForRestart( SI_AMF_DT_TAIListForRestart ** data);

void __si_amf_debug_TAIListForRestart( char * key, SI_AMF_DT_TAIListForRestart * data, int lvl);

void __si_amf_memfree_TAIListForRestart( SI_AMF_DT_TAIListForRestart * data);

int __si_amf_Encode_TAIListForRestart( SI_AMF_DT_TAIListForRestart * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TAIListForWarning( SI_AMF_DT_TAIListForWarning ** data);

void __si_amf_debug_TAIListForWarning( char * key, SI_AMF_DT_TAIListForWarning * data, int lvl);

void __si_amf_memfree_TAIListForWarning( SI_AMF_DT_TAIListForWarning * data);

int __si_amf_Encode_TAIListForWarning( SI_AMF_DT_TAIListForWarning * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargeteNB_ID( SI_AMF_DT_TargeteNB_ID ** data);

void __si_amf_debug_TargeteNB_ID( char * key, SI_AMF_DT_TargeteNB_ID * data, int lvl);

void __si_amf_memfree_TargeteNB_ID( SI_AMF_DT_TargeteNB_ID * data);

int __si_amf_Encode_TargeteNB_ID( SI_AMF_DT_TargeteNB_ID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargeteNB_ID_ExtIEs( SI_AMF_DT_TargeteNB_ID_ExtIEs ** data);

void __si_amf_debug_TargeteNB_ID_ExtIEs( char * key, SI_AMF_DT_TargeteNB_ID_ExtIEs * data, int lvl);

void __si_amf_memfree_TargeteNB_ID_ExtIEs( SI_AMF_DT_TargeteNB_ID_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TargeteNB_ID_ExtIEs( SI_AMF_DT_TargeteNB_ID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetID( SI_AMF_DT_TargetID ** data);

void __si_amf_debug_TargetID( char * key, SI_AMF_DT_TargetID * data, int lvl);

void __si_amf_memfree_TargetID( SI_AMF_DT_TargetID * data);

int __si_amf_Encode_TargetID( SI_AMF_DT_TargetID * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetID_ExtIEs( SI_AMF_DT_TargetID_ExtIEs ** data);

void __si_amf_debug_TargetID_ExtIEs( char * key, SI_AMF_DT_TargetID_ExtIEs * data, int lvl);

void __si_amf_memfree_TargetID_ExtIEs( SI_AMF_DT_TargetID_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_TargetID_ExtIEs( SI_AMF_DT_TargetID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer ** data);

void __si_amf_debug_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( char * key, SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer * data, int lvl);

void __si_amf_memfree_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer * data);

int __si_amf_Encode_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs ** data);

void __si_amf_debug_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( char * key, SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs * data, int lvl);

void __si_amf_memfree_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetRANNodeID_ExtIEs( SI_AMF_DT_TargetRANNodeID_ExtIEs ** data);

void __si_amf_debug_TargetRANNodeID_ExtIEs( char * key, SI_AMF_DT_TargetRANNodeID_ExtIEs * data, int lvl);

void __si_amf_memfree_TargetRANNodeID_ExtIEs( SI_AMF_DT_TargetRANNodeID_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TargetRANNodeID_ExtIEs( SI_AMF_DT_TargetRANNodeID_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TargetToSource_TransparentContainer( SI_AMF_DT_TargetToSource_TransparentContainer ** data);

void __si_amf_init_TargetToSource_TransparentContainer2( SI_AMF_DT_TargetToSource_TransparentContainer ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_TargetToSource_TransparentContainer( char * key, SI_AMF_DT_TargetToSource_TransparentContainer * data, int lvl);

void __si_amf_memfree_TargetToSource_TransparentContainer( SI_AMF_DT_TargetToSource_TransparentContainer * data);

int __si_amf_Encode_TargetToSource_TransparentContainer( SI_AMF_DT_TargetToSource_TransparentContainer * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TimerApproachForGUAMIRemoval( char * key, uint8_t eTimerApproachForGUAMIRemoval, int lvl);

int __si_amf_Encode_TimerApproachForGUAMIRemoval( uint8_t eTimerApproachForGUAMIRemoval, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TimeStamp( SI_AMF_DT_TimeStamp ** data);

void __si_amf_init_TimeStamp2( SI_AMF_DT_TimeStamp ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_TimeStamp( char * key, SI_AMF_DT_TimeStamp * data, int lvl);

void __si_amf_memfree_TimeStamp( SI_AMF_DT_TimeStamp * data);

int __si_amf_Encode_TimeStamp( SI_AMF_DT_TimeStamp * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TimeToWait( char * key, uint8_t eTimeToWait, int lvl);

int __si_amf_Encode_TimeToWait( uint8_t eTimeToWait, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TNLAssociationList( SI_AMF_DT_TNLAssociationList ** data);

void __si_amf_debug_TNLAssociationList( char * key, SI_AMF_DT_TNLAssociationList * data, int lvl);

void __si_amf_memfree_TNLAssociationList( SI_AMF_DT_TNLAssociationList * data);

int __si_amf_Encode_TNLAssociationList( SI_AMF_DT_TNLAssociationList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TNLAssociationItem( SI_AMF_DT_TNLAssociationItem ** data);

void __si_amf_debug_TNLAssociationItem( char * key, SI_AMF_DT_TNLAssociationItem * data, int lvl);

void __si_amf_memfree_TNLAssociationItem( SI_AMF_DT_TNLAssociationItem * data);

int __si_amf_Encode_TNLAssociationItem( SI_AMF_DT_TNLAssociationItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TNLAssociationItem_ExtIEs( SI_AMF_DT_TNLAssociationItem_ExtIEs ** data);

void __si_amf_debug_TNLAssociationItem_ExtIEs( char * key, SI_AMF_DT_TNLAssociationItem_ExtIEs * data, int lvl);

void __si_amf_memfree_TNLAssociationItem_ExtIEs( SI_AMF_DT_TNLAssociationItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TNLAssociationItem_ExtIEs( SI_AMF_DT_TNLAssociationItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_TraceDepth( char * key, uint8_t eTraceDepth, int lvl);

int __si_amf_Encode_TraceDepth( uint8_t eTraceDepth, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TraceActivation( SI_AMF_DT_TraceActivation ** data);

void __si_amf_debug_TraceActivation( char * key, SI_AMF_DT_TraceActivation * data, int lvl);

void __si_amf_memfree_TraceActivation( SI_AMF_DT_TraceActivation * data);

int __si_amf_Encode_TraceActivation( SI_AMF_DT_TraceActivation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_TraceActivation_ExtIEs( SI_AMF_DT_TraceActivation_ExtIEs ** data);

void __si_amf_debug_TraceActivation_ExtIEs( char * key, SI_AMF_DT_TraceActivation_ExtIEs * data, int lvl);

void __si_amf_memfree_TraceActivation_ExtIEs( SI_AMF_DT_TraceActivation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_TraceActivation_ExtIEs( SI_AMF_DT_TraceActivation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEAggregateMaximumBitRate( SI_AMF_DT_UEAggregateMaximumBitRate ** data);

void __si_amf_debug_UEAggregateMaximumBitRate( char * key, SI_AMF_DT_UEAggregateMaximumBitRate * data, int lvl);

void __si_amf_memfree_UEAggregateMaximumBitRate( SI_AMF_DT_UEAggregateMaximumBitRate * data);

int __si_amf_Encode_UEAggregateMaximumBitRate( SI_AMF_DT_UEAggregateMaximumBitRate * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs ** data);

void __si_amf_debug_UEAggregateMaximumBitRate_ExtIEs( char * key, SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs * data, int lvl);

void __si_amf_memfree_UEAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UEAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_associatedLogicalNG_connectionItem( SI_AMF_DT_UE_associatedLogicalNG_connectionItem ** data);

void __si_amf_debug_UE_associatedLogicalNG_connectionItem( char * key, SI_AMF_DT_UE_associatedLogicalNG_connectionItem * data, int lvl);

void __si_amf_memfree_UE_associatedLogicalNG_connectionItem( SI_AMF_DT_UE_associatedLogicalNG_connectionItem * data);

int __si_amf_Encode_UE_associatedLogicalNG_connectionItem( SI_AMF_DT_UE_associatedLogicalNG_connectionItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_associatedLogicalNG_connectionItem_ExtIEs( SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs ** data);

void __si_amf_debug_UE_associatedLogicalNG_connectionItem_ExtIEs( char * key, SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs * data, int lvl);

void __si_amf_memfree_UE_associatedLogicalNG_connectionItem_ExtIEs( SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UE_associatedLogicalNG_connectionItem_ExtIEs( SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_UEContextRequest( char * key, uint8_t eUEContextRequest, int lvl);

int __si_amf_Encode_UEContextRequest( uint8_t eUEContextRequest, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEIdentityIndexValue_ExtIEs( SI_AMF_DT_UEIdentityIndexValue_ExtIEs ** data);

void __si_amf_debug_UEIdentityIndexValue_ExtIEs( char * key, SI_AMF_DT_UEIdentityIndexValue_ExtIEs * data, int lvl);

void __si_amf_memfree_UEIdentityIndexValue_ExtIEs( SI_AMF_DT_UEIdentityIndexValue_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_UEIdentityIndexValue_ExtIEs( SI_AMF_DT_UEIdentityIndexValue_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_NGAP_ID_pair( SI_AMF_DT_UE_NGAP_ID_pair ** data);

void __si_amf_debug_UE_NGAP_ID_pair( char * key, SI_AMF_DT_UE_NGAP_ID_pair * data, int lvl);

void __si_amf_memfree_UE_NGAP_ID_pair( SI_AMF_DT_UE_NGAP_ID_pair * data);

int __si_amf_Encode_UE_NGAP_ID_pair( SI_AMF_DT_UE_NGAP_ID_pair * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_NGAP_IDs( SI_AMF_DT_UE_NGAP_IDs ** data);

void __si_amf_debug_UE_NGAP_IDs( char * key, SI_AMF_DT_UE_NGAP_IDs * data, int lvl);

void __si_amf_memfree_UE_NGAP_IDs( SI_AMF_DT_UE_NGAP_IDs * data);

int __si_amf_Encode_UE_NGAP_IDs( SI_AMF_DT_UE_NGAP_IDs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_NGAP_IDs_ExtIEs( SI_AMF_DT_UE_NGAP_IDs_ExtIEs ** data);

void __si_amf_debug_UE_NGAP_IDs_ExtIEs( char * key, SI_AMF_DT_UE_NGAP_IDs_ExtIEs * data, int lvl);

void __si_amf_memfree_UE_NGAP_IDs_ExtIEs( SI_AMF_DT_UE_NGAP_IDs_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_UE_NGAP_IDs_ExtIEs( SI_AMF_DT_UE_NGAP_IDs_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UE_NGAP_ID_pair_ExtIEs( SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs ** data);

void __si_amf_debug_UE_NGAP_ID_pair_ExtIEs( char * key, SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs * data, int lvl);

void __si_amf_memfree_UE_NGAP_ID_pair_ExtIEs( SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UE_NGAP_ID_pair_ExtIEs( SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEPagingIdentity( SI_AMF_DT_UEPagingIdentity ** data);

void __si_amf_debug_UEPagingIdentity( char * key, SI_AMF_DT_UEPagingIdentity * data, int lvl);

void __si_amf_memfree_UEPagingIdentity( SI_AMF_DT_UEPagingIdentity * data);

int __si_amf_Encode_UEPagingIdentity( SI_AMF_DT_UEPagingIdentity * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEPagingIdentity_ExtIEs( SI_AMF_DT_UEPagingIdentity_ExtIEs ** data);

void __si_amf_debug_UEPagingIdentity_ExtIEs( char * key, SI_AMF_DT_UEPagingIdentity_ExtIEs * data, int lvl);

void __si_amf_memfree_UEPagingIdentity_ExtIEs( SI_AMF_DT_UEPagingIdentity_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_UEPagingIdentity_ExtIEs( SI_AMF_DT_UEPagingIdentity_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_UEPresence( char * key, uint8_t eUEPresence, int lvl);

int __si_amf_Encode_UEPresence( uint8_t eUEPresence, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEPresenceInAreaOfInterestList( SI_AMF_DT_UEPresenceInAreaOfInterestList ** data);

void __si_amf_debug_UEPresenceInAreaOfInterestList( char * key, SI_AMF_DT_UEPresenceInAreaOfInterestList * data, int lvl);

void __si_amf_memfree_UEPresenceInAreaOfInterestList( SI_AMF_DT_UEPresenceInAreaOfInterestList * data);

int __si_amf_Encode_UEPresenceInAreaOfInterestList( SI_AMF_DT_UEPresenceInAreaOfInterestList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEPresenceInAreaOfInterestItem( SI_AMF_DT_UEPresenceInAreaOfInterestItem ** data);

void __si_amf_debug_UEPresenceInAreaOfInterestItem( char * key, SI_AMF_DT_UEPresenceInAreaOfInterestItem * data, int lvl);

void __si_amf_memfree_UEPresenceInAreaOfInterestItem( SI_AMF_DT_UEPresenceInAreaOfInterestItem * data);

int __si_amf_Encode_UEPresenceInAreaOfInterestItem( SI_AMF_DT_UEPresenceInAreaOfInterestItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UEPresenceInAreaOfInterestItem_ExtIEs( SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs ** data);

void __si_amf_debug_UEPresenceInAreaOfInterestItem_ExtIEs( char * key, SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs * data, int lvl);

void __si_amf_memfree_UEPresenceInAreaOfInterestItem_ExtIEs( SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UEPresenceInAreaOfInterestItem_ExtIEs( SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UERadioCapability( SI_AMF_DT_UERadioCapability ** data);

void __si_amf_init_UERadioCapability2( SI_AMF_DT_UERadioCapability ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_UERadioCapability( char * key, SI_AMF_DT_UERadioCapability * data, int lvl);

void __si_amf_memfree_UERadioCapability( SI_AMF_DT_UERadioCapability * data);

int __si_amf_Encode_UERadioCapability( SI_AMF_DT_UERadioCapability * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UERadioCapabilityForPagingOfNR( SI_AMF_DT_UERadioCapabilityForPagingOfNR ** data);

void __si_amf_init_UERadioCapabilityForPagingOfNR2( SI_AMF_DT_UERadioCapabilityForPagingOfNR ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_UERadioCapabilityForPagingOfNR( char * key, SI_AMF_DT_UERadioCapabilityForPagingOfNR * data, int lvl);

void __si_amf_memfree_UERadioCapabilityForPagingOfNR( SI_AMF_DT_UERadioCapabilityForPagingOfNR * data);

int __si_amf_Encode_UERadioCapabilityForPagingOfNR( SI_AMF_DT_UERadioCapabilityForPagingOfNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UERadioCapabilityForPagingOfEUTRA( SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA ** data);

void __si_amf_init_UERadioCapabilityForPagingOfEUTRA2( SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_UERadioCapabilityForPagingOfEUTRA( char * key, SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA * data, int lvl);

void __si_amf_memfree_UERadioCapabilityForPagingOfEUTRA( SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA * data);

int __si_amf_Encode_UERadioCapabilityForPagingOfEUTRA( SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UERadioCapabilityForPaging( SI_AMF_DT_UERadioCapabilityForPaging ** data);

void __si_amf_debug_UERadioCapabilityForPaging( char * key, SI_AMF_DT_UERadioCapabilityForPaging * data, int lvl);

void __si_amf_memfree_UERadioCapabilityForPaging( SI_AMF_DT_UERadioCapabilityForPaging * data);

int __si_amf_Encode_UERadioCapabilityForPaging( SI_AMF_DT_UERadioCapabilityForPaging * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UERadioCapabilityForPaging_ExtIEs( SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs ** data);

void __si_amf_debug_UERadioCapabilityForPaging_ExtIEs( char * key, SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs * data, int lvl);

void __si_amf_memfree_UERadioCapabilityForPaging_ExtIEs( SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UERadioCapabilityForPaging_ExtIEs( SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_UERetentionInformation( char * key, uint8_t eUERetentionInformation, int lvl);

int __si_amf_Encode_UERetentionInformation( uint8_t eUERetentionInformation, int isExt, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UESecurityCapabilities( SI_AMF_DT_UESecurityCapabilities ** data);

void __si_amf_debug_UESecurityCapabilities( char * key, SI_AMF_DT_UESecurityCapabilities * data, int lvl);

void __si_amf_memfree_UESecurityCapabilities( SI_AMF_DT_UESecurityCapabilities * data);

int __si_amf_Encode_UESecurityCapabilities( SI_AMF_DT_UESecurityCapabilities * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UESecurityCapabilities_ExtIEs( SI_AMF_DT_UESecurityCapabilities_ExtIEs ** data);

void __si_amf_debug_UESecurityCapabilities_ExtIEs( char * key, SI_AMF_DT_UESecurityCapabilities_ExtIEs * data, int lvl);

void __si_amf_memfree_UESecurityCapabilities_ExtIEs( SI_AMF_DT_UESecurityCapabilities_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UESecurityCapabilities_ExtIEs( SI_AMF_DT_UESecurityCapabilities_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UL_NGU_UP_TNLModifyItem( SI_AMF_DT_UL_NGU_UP_TNLModifyItem ** data);

void __si_amf_debug_UL_NGU_UP_TNLModifyItem( char * key, SI_AMF_DT_UL_NGU_UP_TNLModifyItem * data, int lvl);

void __si_amf_memfree_UL_NGU_UP_TNLModifyItem( SI_AMF_DT_UL_NGU_UP_TNLModifyItem * data);

int __si_amf_Encode_UL_NGU_UP_TNLModifyItem( SI_AMF_DT_UL_NGU_UP_TNLModifyItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UL_NGU_UP_TNLModifyItem_ExtIEs( SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs ** data);

void __si_amf_debug_UL_NGU_UP_TNLModifyItem_ExtIEs( char * key, SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs * data, int lvl);

void __si_amf_memfree_UL_NGU_UP_TNLModifyItem_ExtIEs( SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UL_NGU_UP_TNLModifyItem_ExtIEs( SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UnavailableGUAMIList( SI_AMF_DT_UnavailableGUAMIList ** data);

void __si_amf_debug_UnavailableGUAMIList( char * key, SI_AMF_DT_UnavailableGUAMIList * data, int lvl);

void __si_amf_memfree_UnavailableGUAMIList( SI_AMF_DT_UnavailableGUAMIList * data);

int __si_amf_Encode_UnavailableGUAMIList( SI_AMF_DT_UnavailableGUAMIList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UnavailableGUAMIItem( SI_AMF_DT_UnavailableGUAMIItem ** data);

void __si_amf_debug_UnavailableGUAMIItem( char * key, SI_AMF_DT_UnavailableGUAMIItem * data, int lvl);

void __si_amf_memfree_UnavailableGUAMIItem( SI_AMF_DT_UnavailableGUAMIItem * data);

int __si_amf_Encode_UnavailableGUAMIItem( SI_AMF_DT_UnavailableGUAMIItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UnavailableGUAMIItem_ExtIEs( SI_AMF_DT_UnavailableGUAMIItem_ExtIEs ** data);

void __si_amf_debug_UnavailableGUAMIItem_ExtIEs( char * key, SI_AMF_DT_UnavailableGUAMIItem_ExtIEs * data, int lvl);

void __si_amf_memfree_UnavailableGUAMIItem_ExtIEs( SI_AMF_DT_UnavailableGUAMIItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UnavailableGUAMIItem_ExtIEs( SI_AMF_DT_UnavailableGUAMIItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformation_ExtIEs( SI_AMF_DT_UPTransportLayerInformation_ExtIEs ** data);

void __si_amf_debug_UPTransportLayerInformation_ExtIEs( char * key, SI_AMF_DT_UPTransportLayerInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformation_ExtIEs( SI_AMF_DT_UPTransportLayerInformation_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_UPTransportLayerInformation_ExtIEs( SI_AMF_DT_UPTransportLayerInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformationItem( SI_AMF_DT_UPTransportLayerInformationItem ** data);

void __si_amf_debug_UPTransportLayerInformationItem( char * key, SI_AMF_DT_UPTransportLayerInformationItem * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformationItem( SI_AMF_DT_UPTransportLayerInformationItem * data);

int __si_amf_Encode_UPTransportLayerInformationItem( SI_AMF_DT_UPTransportLayerInformationItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformationItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs ** data);

void __si_amf_debug_UPTransportLayerInformationItem_ExtIEs( char * key, SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformationItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UPTransportLayerInformationItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformationPairItem( SI_AMF_DT_UPTransportLayerInformationPairItem ** data);

void __si_amf_debug_UPTransportLayerInformationPairItem( char * key, SI_AMF_DT_UPTransportLayerInformationPairItem * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformationPairItem( SI_AMF_DT_UPTransportLayerInformationPairItem * data);

int __si_amf_Encode_UPTransportLayerInformationPairItem( SI_AMF_DT_UPTransportLayerInformationPairItem * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UPTransportLayerInformationPairItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs ** data);

void __si_amf_debug_UPTransportLayerInformationPairItem_ExtIEs( char * key, SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs * data, int lvl);

void __si_amf_memfree_UPTransportLayerInformationPairItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UPTransportLayerInformationPairItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformationEUTRA( SI_AMF_DT_UserLocationInformationEUTRA ** data);

void __si_amf_debug_UserLocationInformationEUTRA( char * key, SI_AMF_DT_UserLocationInformationEUTRA * data, int lvl);

void __si_amf_memfree_UserLocationInformationEUTRA( SI_AMF_DT_UserLocationInformationEUTRA * data);

int __si_amf_Encode_UserLocationInformationEUTRA( SI_AMF_DT_UserLocationInformationEUTRA * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformationNR( SI_AMF_DT_UserLocationInformationNR ** data);

void __si_amf_debug_UserLocationInformationNR( char * key, SI_AMF_DT_UserLocationInformationNR * data, int lvl);

void __si_amf_memfree_UserLocationInformationNR( SI_AMF_DT_UserLocationInformationNR * data);

int __si_amf_Encode_UserLocationInformationNR( SI_AMF_DT_UserLocationInformationNR * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformationN3IWF( SI_AMF_DT_UserLocationInformationN3IWF ** data);

void __si_amf_debug_UserLocationInformationN3IWF( char * key, SI_AMF_DT_UserLocationInformationN3IWF * data, int lvl);

void __si_amf_memfree_UserLocationInformationN3IWF( SI_AMF_DT_UserLocationInformationN3IWF * data);

int __si_amf_Encode_UserLocationInformationN3IWF( SI_AMF_DT_UserLocationInformationN3IWF * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformation( SI_AMF_DT_UserLocationInformation ** data);

void __si_amf_debug_UserLocationInformation( char * key, SI_AMF_DT_UserLocationInformation * data, int lvl);

void __si_amf_memfree_UserLocationInformation( SI_AMF_DT_UserLocationInformation * data);

int __si_amf_Encode_UserLocationInformation( SI_AMF_DT_UserLocationInformation * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformation_ExtIEs( SI_AMF_DT_UserLocationInformation_ExtIEs ** data);

void __si_amf_debug_UserLocationInformation_ExtIEs( char * key, SI_AMF_DT_UserLocationInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_UserLocationInformation_ExtIEs( SI_AMF_DT_UserLocationInformation_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_UserLocationInformation_ExtIEs( SI_AMF_DT_UserLocationInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformationEUTRA_ExtIEs( SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs ** data);

void __si_amf_debug_UserLocationInformationEUTRA_ExtIEs( char * key, SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs * data, int lvl);

void __si_amf_memfree_UserLocationInformationEUTRA_ExtIEs( SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UserLocationInformationEUTRA_ExtIEs( SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformationN3IWF_ExtIEs( SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs ** data);

void __si_amf_debug_UserLocationInformationN3IWF_ExtIEs( char * key, SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs * data, int lvl);

void __si_amf_memfree_UserLocationInformationN3IWF_ExtIEs( SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UserLocationInformationN3IWF_ExtIEs( SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserLocationInformationNR_ExtIEs( SI_AMF_DT_UserLocationInformationNR_ExtIEs ** data);

void __si_amf_debug_UserLocationInformationNR_ExtIEs( char * key, SI_AMF_DT_UserLocationInformationNR_ExtIEs * data, int lvl);

void __si_amf_memfree_UserLocationInformationNR_ExtIEs( SI_AMF_DT_UserLocationInformationNR_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UserLocationInformationNR_ExtIEs( SI_AMF_DT_UserLocationInformationNR_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_UserPlaneSecurityInformation_ExtIEs( SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs ** data);

void __si_amf_debug_UserPlaneSecurityInformation_ExtIEs( char * key, SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs * data, int lvl);

void __si_amf_memfree_UserPlaneSecurityInformation_ExtIEs( SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_UserPlaneSecurityInformation_ExtIEs( SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_VolumeTimedReport_ItemTimeStamp( SI_AMF_DT_VolumeTimedReport_ItemTimeStamp ** data);

void __si_amf_init_VolumeTimedReport_ItemTimeStamp2( SI_AMF_DT_VolumeTimedReport_ItemTimeStamp ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_VolumeTimedReport_ItemTimeStamp( char * key, SI_AMF_DT_VolumeTimedReport_ItemTimeStamp * data, int lvl);

void __si_amf_memfree_VolumeTimedReport_ItemTimeStamp( SI_AMF_DT_VolumeTimedReport_ItemTimeStamp * data);

int __si_amf_Encode_VolumeTimedReport_ItemTimeStamp( SI_AMF_DT_VolumeTimedReport_ItemTimeStamp * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_debug_VolumeTimedReport_ItemUsageCount( char * key, unsigned long long int data, int lvl);

int __si_amf_Encode_VolumeTimedReport_ItemUsageCount( unsigned long long int data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_VolumeTimedReport_Item( SI_AMF_DT_VolumeTimedReport_Item ** data);

void __si_amf_debug_VolumeTimedReport_Item( char * key, SI_AMF_DT_VolumeTimedReport_Item * data, int lvl);

void __si_amf_memfree_VolumeTimedReport_Item( SI_AMF_DT_VolumeTimedReport_Item * data);

int __si_amf_Encode_VolumeTimedReport_Item( SI_AMF_DT_VolumeTimedReport_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_VolumeTimedReport_Item_ExtIEs( SI_AMF_DT_VolumeTimedReport_Item_ExtIEs ** data);

void __si_amf_debug_VolumeTimedReport_Item_ExtIEs( char * key, SI_AMF_DT_VolumeTimedReport_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_VolumeTimedReport_Item_ExtIEs( SI_AMF_DT_VolumeTimedReport_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_VolumeTimedReport_Item_ExtIEs( SI_AMF_DT_VolumeTimedReport_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_WarningAreaCoordinates( SI_AMF_DT_WarningAreaCoordinates ** data);

void __si_amf_init_WarningAreaCoordinates2( SI_AMF_DT_WarningAreaCoordinates ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_WarningAreaCoordinates( char * key, SI_AMF_DT_WarningAreaCoordinates * data, int lvl);

void __si_amf_memfree_WarningAreaCoordinates( SI_AMF_DT_WarningAreaCoordinates * data);

int __si_amf_Encode_WarningAreaCoordinates( SI_AMF_DT_WarningAreaCoordinates * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_WarningAreaList( SI_AMF_DT_WarningAreaList ** data);

void __si_amf_debug_WarningAreaList( char * key, SI_AMF_DT_WarningAreaList * data, int lvl);

void __si_amf_memfree_WarningAreaList( SI_AMF_DT_WarningAreaList * data);

int __si_amf_Encode_WarningAreaList( SI_AMF_DT_WarningAreaList * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_WarningAreaList_ExtIEs( SI_AMF_DT_WarningAreaList_ExtIEs ** data);

void __si_amf_debug_WarningAreaList_ExtIEs( char * key, SI_AMF_DT_WarningAreaList_ExtIEs * data, int lvl);

void __si_amf_memfree_WarningAreaList_ExtIEs( SI_AMF_DT_WarningAreaList_ExtIEs * data);

// EHS-ADT=2  DT=3 Container
int __si_amf_Encode_WarningAreaList_ExtIEs( SI_AMF_DT_WarningAreaList_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_WarningMessageContents( SI_AMF_DT_WarningMessageContents ** data);

void __si_amf_init_WarningMessageContents2( SI_AMF_DT_WarningMessageContents ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_WarningMessageContents( char * key, SI_AMF_DT_WarningMessageContents * data, int lvl);

void __si_amf_memfree_WarningMessageContents( SI_AMF_DT_WarningMessageContents * data);

int __si_amf_Encode_WarningMessageContents( SI_AMF_DT_WarningMessageContents * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_WarningSecurityInfo( SI_AMF_DT_WarningSecurityInfo ** data);

void __si_amf_init_WarningSecurityInfo2( SI_AMF_DT_WarningSecurityInfo ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_WarningSecurityInfo( char * key, SI_AMF_DT_WarningSecurityInfo * data, int lvl);

void __si_amf_memfree_WarningSecurityInfo( SI_AMF_DT_WarningSecurityInfo * data);

int __si_amf_Encode_WarningSecurityInfo( SI_AMF_DT_WarningSecurityInfo * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_WarningType( SI_AMF_DT_WarningType ** data);

void __si_amf_init_WarningType2( SI_AMF_DT_WarningType ** data, u_char * cstr, uint32_t len);

void __si_amf_debug_WarningType( char * key, SI_AMF_DT_WarningType * data, int lvl);

void __si_amf_memfree_WarningType( SI_AMF_DT_WarningType * data);

int __si_amf_Encode_WarningType( SI_AMF_DT_WarningType * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnGTP_TLAs( SI_AMF_DT_XnGTP_TLAs ** data);

void __si_amf_debug_XnGTP_TLAs( char * key, SI_AMF_DT_XnGTP_TLAs * data, int lvl);

void __si_amf_memfree_XnGTP_TLAs( SI_AMF_DT_XnGTP_TLAs * data);

int __si_amf_Encode_XnGTP_TLAs( SI_AMF_DT_XnGTP_TLAs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnExtTLA_Item( SI_AMF_DT_XnExtTLA_Item ** data);

void __si_amf_debug_XnExtTLA_Item( char * key, SI_AMF_DT_XnExtTLA_Item * data, int lvl);

void __si_amf_memfree_XnExtTLA_Item( SI_AMF_DT_XnExtTLA_Item * data);

int __si_amf_Encode_XnExtTLA_Item( SI_AMF_DT_XnExtTLA_Item * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnExtTLA_Item_ExtIEs( SI_AMF_DT_XnExtTLA_Item_ExtIEs ** data);

void __si_amf_debug_XnExtTLA_Item_ExtIEs( char * key, SI_AMF_DT_XnExtTLA_Item_ExtIEs * data, int lvl);

void __si_amf_memfree_XnExtTLA_Item_ExtIEs( SI_AMF_DT_XnExtTLA_Item_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_XnExtTLA_Item_ExtIEs( SI_AMF_DT_XnExtTLA_Item_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

void __si_amf_init_XnTNLConfigurationInfo_ExtIEs( SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs ** data);

void __si_amf_debug_XnTNLConfigurationInfo_ExtIEs( char * key, SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs * data, int lvl);

void __si_amf_memfree_XnTNLConfigurationInfo_ExtIEs( SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs * data);

// EHS-ADT=1  DT=3 Container
int __si_amf_Encode_XnTNLConfigurationInfo_ExtIEs( SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs * data, uint8_t * buffer, int * len, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AdditionalDLUPTNLInformationForHOList( SI_AMF_DT_AdditionalDLUPTNLInformationForHOList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TransportLayerAddress( SI_AMF_DT_TransportLayerAddress ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GTP_TEID( SI_AMF_DT_GTP_TEID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GTPTunnel( SI_AMF_DT_GTPTunnel ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UPTransportLayerInformation( SI_AMF_DT_UPTransportLayerInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowListWithDataForwarding( SI_AMF_DT_QosFlowListWithDataForwarding ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AdditionalDLUPTNLInformationForHOItem( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AdditionalDLUPTNLInformationForHOItem_ExtIEs( SI_AMF_DT_AdditionalDLUPTNLInformationForHOItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

//TODO: DataType -><- Got NULL

int __si_amf_Decode_AdditionalQosFlowInformation( uint8_t * eAdditionalQosFlowInformation,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PriorityLevelARP( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_Pre_emptionCapability( uint8_t * ePre_emptionCapability,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_Pre_emptionVulnerability( uint8_t * ePre_emptionVulnerability,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AllocationAndRetentionPriority( SI_AMF_DT_AllocationAndRetentionPriority ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AllocationAndRetentionPriority_ExtIEs( SI_AMF_DT_AllocationAndRetentionPriority_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AllowedNSSAI( SI_AMF_DT_AllowedNSSAI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SST( SI_AMF_DT_SST ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SD( SI_AMF_DT_SD ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_S_NSSAI( SI_AMF_DT_S_NSSAI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AllowedNSSAI_Item( SI_AMF_DT_AllowedNSSAI_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AllowedNSSAI_Item_ExtIEs( SI_AMF_DT_AllowedNSSAI_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AllowedTACs( SI_AMF_DT_AllowedTACs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMFName( SI_AMF_DT_AMFName ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PLMNIdentity( SI_AMF_DT_PLMNIdentity ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GNB_IDBS( SI_AMF_DT_GNB_IDBS ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GNB_ID( SI_AMF_DT_GNB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GlobalGNB_ID( SI_AMF_DT_GlobalGNB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NgENB_IDmacroNgENB_ID( SI_AMF_DT_NgENB_IDmacroNgENB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NgENB_IDshortMacroNgENB_ID( SI_AMF_DT_NgENB_IDshortMacroNgENB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NgENB_IDlongMacroNgENB_ID( SI_AMF_DT_NgENB_IDlongMacroNgENB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NgENB_ID( SI_AMF_DT_NgENB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GlobalNgENB_ID( SI_AMF_DT_GlobalNgENB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_N3IWF_IDBS( SI_AMF_DT_N3IWF_IDBS ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_N3IWF_ID( SI_AMF_DT_N3IWF_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GlobalN3IWF_ID( SI_AMF_DT_GlobalN3IWF_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GlobalRANNodeID( SI_AMF_DT_GlobalRANNodeID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAC( SI_AMF_DT_TAC ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAI( SI_AMF_DT_TAI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMFPagingTarget( SI_AMF_DT_AMFPagingTarget ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_AMFPagingTarget_ExtIEs( SI_AMF_DT_AMFPagingTarget_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMFPointer( SI_AMF_DT_AMFPointer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMFRegionID( SI_AMF_DT_AMFRegionID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMFSetID( SI_AMF_DT_AMFSetID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationSetupList( SI_AMF_DT_AMF_TNLAssociationSetupList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CPTransportLayerInformation( SI_AMF_DT_CPTransportLayerInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationSetupItem( SI_AMF_DT_AMF_TNLAssociationSetupItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AMF_TNLAssociationSetupItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationSetupItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationToAddList( SI_AMF_DT_AMF_TNLAssociationToAddList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TNLAssociationUsage( uint8_t * eTNLAssociationUsage,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TNLAddressWeightFactor( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationToAddItem( SI_AMF_DT_AMF_TNLAssociationToAddItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AMF_TNLAssociationToAddItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToAddItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationToRemoveList( SI_AMF_DT_AMF_TNLAssociationToRemoveList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationToRemoveItem( SI_AMF_DT_AMF_TNLAssociationToRemoveItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AMF_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToRemoveItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationToUpdateList( SI_AMF_DT_AMF_TNLAssociationToUpdateList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_TNLAssociationToUpdateItem( SI_AMF_DT_AMF_TNLAssociationToUpdateItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AMF_TNLAssociationToUpdateItem_ExtIEs( SI_AMF_DT_AMF_TNLAssociationToUpdateItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AMF_UE_NGAP_ID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestTAIList( SI_AMF_DT_AreaOfInterestTAIList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestCellList( SI_AMF_DT_AreaOfInterestCellList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestRANNodeList( SI_AMF_DT_AreaOfInterestRANNodeList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterest( SI_AMF_DT_AreaOfInterest ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AreaOfInterest_ExtIEs( SI_AMF_DT_AreaOfInterest_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NRCellIdentity( SI_AMF_DT_NRCellIdentity ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NR_CGI( SI_AMF_DT_NR_CGI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EUTRACellIdentity( SI_AMF_DT_EUTRACellIdentity ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EUTRA_CGI( SI_AMF_DT_EUTRA_CGI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NGRAN_CGI( SI_AMF_DT_NGRAN_CGI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestCellItem( SI_AMF_DT_AreaOfInterestCellItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AreaOfInterestCellItem_ExtIEs( SI_AMF_DT_AreaOfInterestCellItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestList( SI_AMF_DT_AreaOfInterestList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LocationReportingReferenceID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestItem( SI_AMF_DT_AreaOfInterestItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AreaOfInterestItem_ExtIEs( SI_AMF_DT_AreaOfInterestItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestRANNodeItem( SI_AMF_DT_AreaOfInterestRANNodeItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AreaOfInterestRANNodeItem_ExtIEs( SI_AMF_DT_AreaOfInterestRANNodeItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AreaOfInterestTAIItem( SI_AMF_DT_AreaOfInterestTAIItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AreaOfInterestTAIItem_ExtIEs( SI_AMF_DT_AreaOfInterestTAIItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedCellList( SI_AMF_DT_RecommendedCellList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedCellsForPaging( SI_AMF_DT_RecommendedCellsForPaging ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AssistanceDataForRecommendedCells( SI_AMF_DT_AssistanceDataForRecommendedCells ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PagingAttemptCount( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_IntendedNumberOfPagingAttempts( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NextPagingAreaScope( uint8_t * eNextPagingAreaScope,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PagingAttemptInformation( SI_AMF_DT_PagingAttemptInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AssistanceDataForPaging( SI_AMF_DT_AssistanceDataForPaging ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AssistanceDataForPaging_ExtIEs( SI_AMF_DT_AssistanceDataForPaging_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AssistanceDataForRecommendedCells_ExtIEs( SI_AMF_DT_AssistanceDataForRecommendedCells_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AssociatedQosFlowList( SI_AMF_DT_AssociatedQosFlowList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AssociatedQosFlowItemQosFlowMappingIndication( uint8_t * eAssociatedQosFlowItemQosFlowMappingIndication,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowIdentifier( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AssociatedQosFlowItem( SI_AMF_DT_AssociatedQosFlowItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_AssociatedQosFlowItem_ExtIEs( SI_AMF_DT_AssociatedQosFlowItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_AveragingWindow( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_BitRate( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDCancelledEUTRA( SI_AMF_DT_CellIDCancelledEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAICancelledEUTRA( SI_AMF_DT_TAICancelledEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDCancelledEUTRA( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDCancelledNR( SI_AMF_DT_CellIDCancelledNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAICancelledNR( SI_AMF_DT_TAICancelledNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDCancelledNR( SI_AMF_DT_EmergencyAreaIDCancelledNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_BroadcastCancelledAreaList( SI_AMF_DT_BroadcastCancelledAreaList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_BroadcastCancelledAreaList_ExtIEs( SI_AMF_DT_BroadcastCancelledAreaList_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDBroadcastEUTRA( SI_AMF_DT_CellIDBroadcastEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIBroadcastEUTRA( SI_AMF_DT_TAIBroadcastEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDBroadcastEUTRA( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDBroadcastNR( SI_AMF_DT_CellIDBroadcastNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIBroadcastNR( SI_AMF_DT_TAIBroadcastNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDBroadcastNR( SI_AMF_DT_EmergencyAreaIDBroadcastNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_BroadcastCompletedAreaList( SI_AMF_DT_BroadcastCompletedAreaList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_BroadcastCompletedAreaList_ExtIEs( SI_AMF_DT_BroadcastCompletedAreaList_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_BroadcastPLMNList( SI_AMF_DT_BroadcastPLMNList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SliceSupportList( SI_AMF_DT_SliceSupportList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_BroadcastPLMNItem( SI_AMF_DT_BroadcastPLMNItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_BroadcastPLMNItem_ExtIEs( SI_AMF_DT_BroadcastPLMNItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelAllWarningMessages( uint8_t * eCancelAllWarningMessages,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInEAI_EUTRA( SI_AMF_DT_CancelledCellsInEAI_EUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NumberOfBroadcasts( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInEAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CancelledCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_EUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInEAI_NR( SI_AMF_DT_CancelledCellsInEAI_NR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInEAI_NR_Item( SI_AMF_DT_CancelledCellsInEAI_NR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CancelledCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInEAI_NR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInTAI_EUTRA( SI_AMF_DT_CancelledCellsInTAI_EUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInTAI_EUTRA_Item( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CancelledCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_EUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInTAI_NR( SI_AMF_DT_CancelledCellsInTAI_NR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CancelledCellsInTAI_NR_Item( SI_AMF_DT_CancelledCellsInTAI_NR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CancelledCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CancelledCellsInTAI_NR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CauseRadioNetwork( uint8_t * eCauseRadioNetwork,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CauseTransport( uint8_t * eCauseTransport,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CauseNas( uint8_t * eCauseNas,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CauseProtocol( uint8_t * eCauseProtocol,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CauseMisc( uint8_t * eCauseMisc,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_Cause( SI_AMF_DT_Cause ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_Cause_ExtIEs( SI_AMF_DT_Cause_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDBroadcastEUTRA_Item( SI_AMF_DT_CellIDBroadcastEUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CellIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastEUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDBroadcastNR_Item( SI_AMF_DT_CellIDBroadcastNR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CellIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_CellIDBroadcastNR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDCancelledEUTRA_Item( SI_AMF_DT_CellIDCancelledEUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CellIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_CellIDCancelledEUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDCancelledNR_Item( SI_AMF_DT_CellIDCancelledNR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CellIDCancelledNR_Item_ExtIEs( SI_AMF_DT_CellIDCancelledNR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EUTRA_CGIList( SI_AMF_DT_EUTRA_CGIList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NR_CGIList( SI_AMF_DT_NR_CGIList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellIDListForRestart( SI_AMF_DT_CellIDListForRestart ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_CellIDListForRestart_ExtIEs( SI_AMF_DT_CellIDListForRestart_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellSize( uint8_t * eCellSize,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CellType( SI_AMF_DT_CellType ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CellType_ExtIEs( SI_AMF_DT_CellType_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedActivityPeriod( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedIdlePeriod( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SourceOfUEActivityBehaviourInformation( uint8_t * eSourceOfUEActivityBehaviourInformation,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedUEActivityBehaviour( SI_AMF_DT_ExpectedUEActivityBehaviour ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedHOInterval( uint8_t * eExpectedHOInterval,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedUEMobility( uint8_t * eExpectedUEMobility,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedUEMovingTrajectory( SI_AMF_DT_ExpectedUEMovingTrajectory ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedUEBehaviour( SI_AMF_DT_ExpectedUEBehaviour ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CNAssistedRANTuning( SI_AMF_DT_CNAssistedRANTuning ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CNAssistedRANTuning_ExtIEs( SI_AMF_DT_CNAssistedRANTuning_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CNTypeRestrictionsForEquivalent( SI_AMF_DT_CNTypeRestrictionsForEquivalent ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CNTypeRestrictionsForEquivalentItemCNType( uint8_t * eCNTypeRestrictionsForEquivalentItemCNType,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CNTypeRestrictionsForEquivalentItem( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CNTypeRestrictionsForEquivalentItem_ExtIEs( SI_AMF_DT_CNTypeRestrictionsForEquivalentItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CNTypeRestrictionsForServing( uint8_t * eCNTypeRestrictionsForServing,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CommonNetworkInstance( SI_AMF_DT_CommonNetworkInstance ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInEAI_EUTRA( SI_AMF_DT_CompletedCellsInEAI_EUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInEAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CompletedCellsInEAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_EUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInEAI_NR( SI_AMF_DT_CompletedCellsInEAI_NR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInEAI_NR_Item( SI_AMF_DT_CompletedCellsInEAI_NR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CompletedCellsInEAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInEAI_NR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInTAI_EUTRA( SI_AMF_DT_CompletedCellsInTAI_EUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInTAI_EUTRA_Item( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CompletedCellsInTAI_EUTRA_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_EUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInTAI_NR( SI_AMF_DT_CompletedCellsInTAI_NR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CompletedCellsInTAI_NR_Item( SI_AMF_DT_CompletedCellsInTAI_NR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CompletedCellsInTAI_NR_Item_ExtIEs( SI_AMF_DT_CompletedCellsInTAI_NR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ConcurrentWarningMessageInd( uint8_t * eConcurrentWarningMessageInd,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ConfidentialityProtectionIndication( uint8_t * eConfidentialityProtectionIndication,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ConfidentialityProtectionResult( uint8_t * eConfidentialityProtectionResult,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEIdentityIndexValueIL( SI_AMF_DT_UEIdentityIndexValueIL ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEIdentityIndexValue( SI_AMF_DT_UEIdentityIndexValue ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PagingDRX( uint8_t * ePagingDRX,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PeriodicRegistrationUpdateTimer( SI_AMF_DT_PeriodicRegistrationUpdateTimer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_MICOModeIndication( uint8_t * eMICOModeIndication,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIListForInactive( SI_AMF_DT_TAIListForInactive ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CoreNetworkAssistanceInformationForInactive( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CoreNetworkAssistanceInformationForInactive_ExtIEs( SI_AMF_DT_CoreNetworkAssistanceInformationForInactive_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_COUNTValueForPDCP_SN12INT( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_COUNTValueForPDCP_SN12INT2( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_COUNTValueForPDCP_SN12( SI_AMF_DT_COUNTValueForPDCP_SN12 ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_COUNTValueForPDCP_SN12_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN12_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_COUNTValueForPDCP_SN18INT( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_COUNTValueForPDCP_SN18INT2( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_COUNTValueForPDCP_SN18( SI_AMF_DT_COUNTValueForPDCP_SN18 ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_COUNTValueForPDCP_SN18_ExtIEs( SI_AMF_DT_COUNTValueForPDCP_SN18_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PortNumber( SI_AMF_DT_PortNumber ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EndpointIPAddressAndPort( SI_AMF_DT_EndpointIPAddressAndPort ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_CPTransportLayerInformation_ExtIEs( SI_AMF_DT_CPTransportLayerInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnosticsCriticality( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnosticsProcedureCode( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnosticsTriggeringMessage( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnostics_IE_List( SI_AMF_DT_CriticalityDiagnostics_IE_List ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnostics( SI_AMF_DT_CriticalityDiagnostics ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CriticalityDiagnostics_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnostics_IE_Item_ProtocolIE_ID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnostics_IE_Item_Criticality( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TypeOfError( uint8_t * eTypeOfError,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_CriticalityDiagnostics_IE_Item( SI_AMF_DT_CriticalityDiagnostics_IE_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_CriticalityDiagnostics_IE_Item_ExtIEs( SI_AMF_DT_CriticalityDiagnostics_IE_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DataCodingScheme( SI_AMF_DT_DataCodingScheme ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DataForwardingAccepted( uint8_t * eDataForwardingAccepted,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DataForwardingNotPossible( uint8_t * eDataForwardingNotPossible,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DataForwardingResponseDRBList( SI_AMF_DT_DataForwardingResponseDRBList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRB_ID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DataForwardingResponseDRBItem( SI_AMF_DT_DataForwardingResponseDRBItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DataForwardingResponseDRBItem_ExtIEs( SI_AMF_DT_DataForwardingResponseDRBItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DelayCritical( uint8_t * eDelayCritical,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DLForwarding( uint8_t * eDLForwarding,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DL_NGU_TNLInformationReused( uint8_t * eDL_NGU_TNLInformationReused,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DirectForwardingPathAvailability( uint8_t * eDirectForwardingPathAvailability,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBsSubjectToStatusTransferList( SI_AMF_DT_DRBsSubjectToStatusTransferList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL12ReceiveStatusOfUL_PDCP_SDUs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusUL12( SI_AMF_DT_DRBStatusUL12 ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs( SI_AMF_DT_DRBStatusUL18ReceiveStatusOfUL_PDCP_SDUs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusUL18( SI_AMF_DT_DRBStatusUL18 ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusUL( SI_AMF_DT_DRBStatusUL ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusDL12( SI_AMF_DT_DRBStatusDL12 ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusDL18( SI_AMF_DT_DRBStatusDL18 ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBStatusDL( SI_AMF_DT_DRBStatusDL ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBsSubjectToStatusTransferItem( SI_AMF_DT_DRBsSubjectToStatusTransferItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DRBsSubjectToStatusTransferItem_ExtIEs( SI_AMF_DT_DRBsSubjectToStatusTransferItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_DRBStatusDL_ExtIEs( SI_AMF_DT_DRBStatusDL_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DRBStatusDL12_ExtIEs( SI_AMF_DT_DRBStatusDL12_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DRBStatusDL18_ExtIEs( SI_AMF_DT_DRBStatusDL18_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_DRBStatusUL_ExtIEs( SI_AMF_DT_DRBStatusUL_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DRBStatusUL12_ExtIEs( SI_AMF_DT_DRBStatusUL12_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DRBStatusUL18_ExtIEs( SI_AMF_DT_DRBStatusUL18_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBsToQosFlowsMappingList( SI_AMF_DT_DRBsToQosFlowsMappingList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_DRBsToQosFlowsMappingItem( SI_AMF_DT_DRBsToQosFlowsMappingItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_DRBsToQosFlowsMappingItem_ExtIEs( SI_AMF_DT_DRBsToQosFlowsMappingItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PriorityLevelQos( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PacketDelayBudget( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PacketErrorRateInt( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PacketErrorRate( SI_AMF_DT_PacketErrorRate ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_FiveQI( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_MaximumDataBurstVolume( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_Dynamic5QIDescriptor( SI_AMF_DT_Dynamic5QIDescriptor ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_Dynamic5QIDescriptor_ExtIEs( SI_AMF_DT_Dynamic5QIDescriptor_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaID( SI_AMF_DT_EmergencyAreaID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDBroadcastEUTRA_Item( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastEUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDBroadcastNR_Item( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EmergencyAreaIDBroadcastNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDBroadcastNR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDCancelledEUTRA_Item( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledEUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDCancelledNR_Item( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EmergencyAreaIDCancelledNR_Item_ExtIEs( SI_AMF_DT_EmergencyAreaIDCancelledNR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDList( SI_AMF_DT_EmergencyAreaIDList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyAreaIDListForRestart( SI_AMF_DT_EmergencyAreaIDListForRestart ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyFallbackRequestIndicator( uint8_t * eEmergencyFallbackRequestIndicator,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyServiceTargetCN( uint8_t * eEmergencyServiceTargetCN,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EmergencyFallbackIndicator( SI_AMF_DT_EmergencyFallbackIndicator ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EmergencyFallbackIndicator_ExtIEs( SI_AMF_DT_EmergencyFallbackIndicator_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EN_DCSONConfigurationTransfer( SI_AMF_DT_EN_DCSONConfigurationTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EndpointIPAddressAndPort_ExtIEs( SI_AMF_DT_EndpointIPAddressAndPort_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EquivalentPLMNs( SI_AMF_DT_EquivalentPLMNs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EPS_TAC( SI_AMF_DT_EPS_TAC ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EPS_TAI( SI_AMF_DT_EPS_TAI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EPS_TAI_ExtIEs( SI_AMF_DT_EPS_TAI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_E_RAB_ID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_E_RABInformationList( SI_AMF_DT_E_RABInformationList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_E_RABInformationItem( SI_AMF_DT_E_RABInformationItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_E_RABInformationItem_ExtIEs( SI_AMF_DT_E_RABInformationItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_EUTRA_CGI_ExtIEs( SI_AMF_DT_EUTRA_CGI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EUTRA_CGIListForWarning( SI_AMF_DT_EUTRA_CGIListForWarning ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EUTRAencryptionAlgorithms( SI_AMF_DT_EUTRAencryptionAlgorithms ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EUTRAintegrityProtectionAlgorithms( SI_AMF_DT_EUTRAintegrityProtectionAlgorithms ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_EventType( uint8_t * eEventType,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_ExpectedUEActivityBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEActivityBehaviour_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_ExpectedUEBehaviour_ExtIEs( SI_AMF_DT_ExpectedUEBehaviour_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedUEMovingTrajectoryItemTime( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ExpectedUEMovingTrajectoryItem( SI_AMF_DT_ExpectedUEMovingTrajectoryItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_ExpectedUEMovingTrajectoryItem_ExtIEs( SI_AMF_DT_ExpectedUEMovingTrajectoryItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_FiveG_TMSI( SI_AMF_DT_FiveG_TMSI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_FiveG_S_TMSI( SI_AMF_DT_FiveG_S_TMSI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_FiveG_S_TMSI_ExtIEs( SI_AMF_DT_FiveG_S_TMSI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ForbiddenAreaInformation( SI_AMF_DT_ForbiddenAreaInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ForbiddenTACs( SI_AMF_DT_ForbiddenTACs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ForbiddenAreaInformation_Item( SI_AMF_DT_ForbiddenAreaInformation_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_ForbiddenAreaInformation_Item_ExtIEs( SI_AMF_DT_ForbiddenAreaInformation_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NotificationControl( uint8_t * eNotificationControl,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PacketLossRate( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GBR_QosInformation( SI_AMF_DT_GBR_QosInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_GBR_QosInformation_ExtIEs( SI_AMF_DT_GBR_QosInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_GlobalGNB_ID_ExtIEs( SI_AMF_DT_GlobalGNB_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_GlobalN3IWF_ID_ExtIEs( SI_AMF_DT_GlobalN3IWF_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_GlobalNgENB_ID_ExtIEs( SI_AMF_DT_GlobalNgENB_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_GlobalRANNodeID_ExtIEs( SI_AMF_DT_GlobalRANNodeID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_GNB_ID_ExtIEs( SI_AMF_DT_GNB_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_GTPTunnel_ExtIEs( SI_AMF_DT_GTPTunnel_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_GUAMI( SI_AMF_DT_GUAMI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_GUAMI_ExtIEs( SI_AMF_DT_GUAMI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowToBeForwardedList( SI_AMF_DT_QosFlowToBeForwardedList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverCommandTransfer( SI_AMF_DT_HandoverCommandTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowPerTNLInformationList( SI_AMF_DT_QosFlowPerTNLInformationList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UPTransportLayerInformationList( SI_AMF_DT_UPTransportLayerInformationList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_HandoverCommandTransfer_ExtIEs( SI_AMF_DT_HandoverCommandTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverFlag( uint8_t * eHandoverFlag,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverPreparationUnsuccessfulTransfer( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_HandoverPreparationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverPreparationUnsuccessfulTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_IntegrityProtectionResult( uint8_t * eIntegrityProtectionResult,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecurityResult( SI_AMF_DT_SecurityResult ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowListWithCause( SI_AMF_DT_QosFlowListWithCause ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverRequestAcknowledgeTransfer( SI_AMF_DT_HandoverRequestAcknowledgeTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_HandoverRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_HandoverRequestAcknowledgeTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverRequiredTransfer( SI_AMF_DT_HandoverRequiredTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_HandoverRequiredTransfer_ExtIEs( SI_AMF_DT_HandoverRequiredTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverResourceAllocationUnsuccessfulTransfer( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverType( uint8_t * eHandoverType,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_IMSVoiceSupportIndicator( uint8_t * eIMSVoiceSupportIndicator,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_IndexToRFSP( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedRANNodeList( SI_AMF_DT_RecommendedRANNodeList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedRANNodesForPaging( SI_AMF_DT_RecommendedRANNodesForPaging ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_InfoOnRecommendedCellsAndRANNodesForPaging( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs( SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_IntegrityProtectionIndication( uint8_t * eIntegrityProtectionIndication,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_InterfacesToTrace( SI_AMF_DT_InterfacesToTrace ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TimeUEStayedInCell( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TimeUEStayedInCellEnhancedGranularity( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LastVisitedNGRANCellInformation( SI_AMF_DT_LastVisitedNGRANCellInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LastVisitedEUTRANCellInformation( SI_AMF_DT_LastVisitedEUTRANCellInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LastVisitedUTRANCellInformation( SI_AMF_DT_LastVisitedUTRANCellInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LastVisitedGERANCellInformation( SI_AMF_DT_LastVisitedGERANCellInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LastVisitedCellInformation( SI_AMF_DT_LastVisitedCellInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_LastVisitedCellInformation_ExtIEs( SI_AMF_DT_LastVisitedCellInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LastVisitedCellItem( SI_AMF_DT_LastVisitedCellItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_LastVisitedCellItem_ExtIEs( SI_AMF_DT_LastVisitedCellItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_LastVisitedNGRANCellInformation_ExtIEs( SI_AMF_DT_LastVisitedNGRANCellInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LocationReportingAdditionalInfo( uint8_t * eLocationReportingAdditionalInfo,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ReportArea( uint8_t * eReportArea,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_LocationReportingRequestType( SI_AMF_DT_LocationReportingRequestType ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_LocationReportingRequestType_ExtIEs( SI_AMF_DT_LocationReportingRequestType_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_MaskedIMEISV( SI_AMF_DT_MaskedIMEISV ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_MessageIdentifier( SI_AMF_DT_MessageIdentifier ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_MaximumIntegrityProtectedDataRate( uint8_t * eMaximumIntegrityProtectedDataRate,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RATRestrictions( SI_AMF_DT_RATRestrictions ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ServiceAreaInformation( SI_AMF_DT_ServiceAreaInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_MobilityRestrictionList( SI_AMF_DT_MobilityRestrictionList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_MobilityRestrictionList_ExtIEs( SI_AMF_DT_MobilityRestrictionList_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_N3IWF_ID_ExtIEs( SI_AMF_DT_N3IWF_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NAS_PDU( SI_AMF_DT_NAS_PDU ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NASSecurityParametersFromNGRAN( SI_AMF_DT_NASSecurityParametersFromNGRAN ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NetworkInstance( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NewSecurityContextInd( uint8_t * eNewSecurityContextInd,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NextHopChainingCount( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_NgENB_ID_ExtIEs( SI_AMF_DT_NgENB_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_NGRAN_CGI_ExtIEs( SI_AMF_DT_NGRAN_CGI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NGRAN_TNLAssociationToRemoveList( SI_AMF_DT_NGRAN_TNLAssociationToRemoveList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NGRAN_TNLAssociationToRemoveItem( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_NGRAN_TNLAssociationToRemoveItem_ExtIEs( SI_AMF_DT_NGRAN_TNLAssociationToRemoveItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NGRANTraceID( SI_AMF_DT_NGRANTraceID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NonDynamic5QIDescriptor( SI_AMF_DT_NonDynamic5QIDescriptor ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_NonDynamic5QIDescriptor_ExtIEs( SI_AMF_DT_NonDynamic5QIDescriptor_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NotAllowedTACs( SI_AMF_DT_NotAllowedTACs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NotificationCause( uint8_t * eNotificationCause,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_NR_CGI_ExtIEs( SI_AMF_DT_NR_CGI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NR_CGIListForWarning( SI_AMF_DT_NR_CGIListForWarning ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NRencryptionAlgorithms( SI_AMF_DT_NRencryptionAlgorithms ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NRintegrityProtectionAlgorithms( SI_AMF_DT_NRintegrityProtectionAlgorithms ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NRPPa_PDU( SI_AMF_DT_NRPPa_PDU ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_NumberOfBroadcastsRequested( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_OverloadAction( uint8_t * eOverloadAction,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_OverloadResponse( SI_AMF_DT_OverloadResponse ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_OverloadResponse_ExtIEs( SI_AMF_DT_OverloadResponse_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_OverloadStartNSSAIList( SI_AMF_DT_OverloadStartNSSAIList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SliceOverloadList( SI_AMF_DT_SliceOverloadList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TrafficLoadReductionIndication( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_OverloadStartNSSAIItem( SI_AMF_DT_OverloadStartNSSAIItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_OverloadStartNSSAIItem_ExtIEs( SI_AMF_DT_OverloadStartNSSAIItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PacketErrorRate_ExtIEs( SI_AMF_DT_PacketErrorRate_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PagingAttemptInformation_ExtIEs( SI_AMF_DT_PagingAttemptInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PagingOrigin( uint8_t * ePagingOrigin,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PagingPriority( uint8_t * ePagingPriority,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecurityIndication( SI_AMF_DT_SecurityIndication ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestAcknowledgeTransfer( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UPTransportLayerInformationPairList( SI_AMF_DT_UPTransportLayerInformationPairList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PathSwitchRequestAcknowledgeTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestAcknowledgeTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestSetupFailedTransfer( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PathSwitchRequestSetupFailedTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestSetupFailedTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UserPlaneSecurityInformation( SI_AMF_DT_UserPlaneSecurityInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowAcceptedList( SI_AMF_DT_QosFlowAcceptedList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestTransfer( SI_AMF_DT_PathSwitchRequestTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PathSwitchRequestTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestUnsuccessfulTransfer( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PathSwitchRequestUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionAggregateMaximumBitRate( SI_AMF_DT_PDUSessionAggregateMaximumBitRate ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_PDUSessionAggregateMaximumBitRate_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceAdmittedList( SI_AMF_DT_PDUSessionResourceAdmittedList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverRequestAcknowledgeTransferOctStr( SI_AMF_DT_HandoverRequestAcknowledgeTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceAdmittedItem( SI_AMF_DT_PDUSessionResourceAdmittedItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceAdmittedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceAdmittedItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToModifyListModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToModifyItemModCfm( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModCfm_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToModifyListModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToModifyItemModRes( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToModifyItemModRes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupListCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupUnsuccessfulTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupItemCxtFail( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtFail_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupListCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemCxtRes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupListHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverResourceAllocationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverResourceAllocationUnsuccessfulTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupItemHOAck( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemHOAck_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupListPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestSetupFailedTransferOctStr( SI_AMF_DT_PathSwitchRequestSetupFailedTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupItemPSReq( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemPSReq_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupListSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceFailedToSetupItemSURes( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceFailedToSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceFailedToSetupItemSURes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceHandoverList( SI_AMF_DT_PDUSessionResourceHandoverList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverCommandTransferOctStr( SI_AMF_DT_HandoverCommandTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceHandoverItem( SI_AMF_DT_PDUSessionResourceHandoverItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceHandoverItem_ExtIEs( SI_AMF_DT_PDUSessionResourceHandoverItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceInformationList( SI_AMF_DT_PDUSessionResourceInformationList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowInformationList( SI_AMF_DT_QosFlowInformationList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceInformationItem( SI_AMF_DT_PDUSessionResourceInformationItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceInformationItem_ExtIEs( SI_AMF_DT_PDUSessionResourceInformationItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceListCxtRelCpl( SI_AMF_DT_PDUSessionResourceListCxtRelCpl ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceItemCxtRelCpl( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleaseResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseResponseTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceItemCxtRelCpl_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelCpl_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceListCxtRelReq( SI_AMF_DT_PDUSessionResourceListCxtRelReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceItemCxtRelReq( SI_AMF_DT_PDUSessionResourceItemCxtRelReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceItemCxtRelReq_ExtIEs( SI_AMF_DT_PDUSessionResourceItemCxtRelReq_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceListHORqd( SI_AMF_DT_PDUSessionResourceListHORqd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverRequiredTransferOctStr( SI_AMF_DT_HandoverRequiredTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceItemHORqd( SI_AMF_DT_PDUSessionResourceItemHORqd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceItemHORqd_ExtIEs( SI_AMF_DT_PDUSessionResourceItemHORqd_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowModifyConfirmList( SI_AMF_DT_QosFlowModifyConfirmList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyConfirmTransfer( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyConfirmTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyConfirmTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyIndicationUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationUnsuccessfulTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyRequestTransfer( SI_AMF_DT_PDUSessionResourceModifyRequestTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UL_NGU_UP_TNLModifyList( SI_AMF_DT_UL_NGU_UP_TNLModifyList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowAddOrModifyRequestList( SI_AMF_DT_QosFlowAddOrModifyRequestList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyRequestTransferIEs( SI_AMF_DT_PDUSessionResourceModifyRequestTransferIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowAddOrModifyResponseList( SI_AMF_DT_QosFlowAddOrModifyResponseList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyResponseTransfer( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyResponseTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowPerTNLInformation( SI_AMF_DT_QosFlowPerTNLInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyIndicationTransfer( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionUsageReportRatType( uint8_t * ePDUSessionUsageReportRatType,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_VolumeTimedReportList( SI_AMF_DT_VolumeTimedReportList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionUsageReport( SI_AMF_DT_PDUSessionUsageReport ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QoSFlowsUsageReportList( SI_AMF_DT_QoSFlowsUsageReportList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecondaryRATUsageInformation( SI_AMF_DT_SecondaryRATUsageInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyIndicationTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyIndicationTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyListModCfm( SI_AMF_DT_PDUSessionResourceModifyListModCfm ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyConfirmTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyConfirmTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyItemModCfm( SI_AMF_DT_PDUSessionResourceModifyItemModCfm ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyItemModCfm_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModCfm_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyListModInd( SI_AMF_DT_PDUSessionResourceModifyListModInd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyIndicationTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyIndicationTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyItemModInd( SI_AMF_DT_PDUSessionResourceModifyItemModInd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyItemModInd_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModInd_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyListModReq( SI_AMF_DT_PDUSessionResourceModifyListModReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyRequestTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyItemModReq( SI_AMF_DT_PDUSessionResourceModifyItemModReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyItemModReq_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModReq_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyListModRes( SI_AMF_DT_PDUSessionResourceModifyListModRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceModifyResponseTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyItemModRes( SI_AMF_DT_PDUSessionResourceModifyItemModRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyItemModRes_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyItemModRes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceModifyUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceModifyUnsuccessfulTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceNotifyList( SI_AMF_DT_PDUSessionResourceNotifyList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceNotifyTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceNotifyItem( SI_AMF_DT_PDUSessionResourceNotifyItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceNotifyItem_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceNotifyReleasedTransfer( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceNotifyReleasedTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowNotifyList( SI_AMF_DT_QosFlowNotifyList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceNotifyTransfer( SI_AMF_DT_PDUSessionResourceNotifyTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceNotifyTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceNotifyTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleaseCommandTransfer( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceReleaseCommandTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseCommandTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedListNot( SI_AMF_DT_PDUSessionResourceReleasedListNot ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceNotifyReleasedTransferOctStr( SI_AMF_DT_PDUSessionResourceNotifyReleasedTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedItemNot( SI_AMF_DT_PDUSessionResourceReleasedItemNot ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceReleasedItemNot_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemNot_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedListPSAck( SI_AMF_DT_PDUSessionResourceReleasedListPSAck ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestUnsuccessfulTransferOctStr( SI_AMF_DT_PathSwitchRequestUnsuccessfulTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedItemPSAck( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceReleasedItemPSAck_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSAck_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedListPSFail( SI_AMF_DT_PDUSessionResourceReleasedListPSFail ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedItemPSFail( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceReleasedItemPSFail_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemPSFail_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedListRelRes( SI_AMF_DT_PDUSessionResourceReleasedListRelRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleasedItemRelRes( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceReleasedItemRelRes_ExtIEs( SI_AMF_DT_PDUSessionResourceReleasedItemRelRes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleaseResponseTransfer( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceReleaseResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceReleaseResponseTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSecondaryRATUsageList( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecondaryRATDataUsageReportTransferOctStr( SI_AMF_DT_SecondaryRATDataUsageReportTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSecondaryRATUsageItem( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSecondaryRATUsageItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSecondaryRATUsageItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupListCxtReq( SI_AMF_DT_PDUSessionResourceSetupListCxtReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupRequestTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupRequestTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupItemCxtReq( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupItemCxtReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtReq_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupListCxtRes( SI_AMF_DT_PDUSessionResourceSetupListCxtRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupResponseTransferOctStr( SI_AMF_DT_PDUSessionResourceSetupResponseTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupItemCxtRes( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupItemCxtRes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemCxtRes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupListHOReq( SI_AMF_DT_PDUSessionResourceSetupListHOReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupItemHOReq( SI_AMF_DT_PDUSessionResourceSetupItemHOReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupItemHOReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemHOReq_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupListSUReq( SI_AMF_DT_PDUSessionResourceSetupListSUReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupItemSUReq( SI_AMF_DT_PDUSessionResourceSetupItemSUReq ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupItemSUReq_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSUReq_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupListSURes( SI_AMF_DT_PDUSessionResourceSetupListSURes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupItemSURes( SI_AMF_DT_PDUSessionResourceSetupItemSURes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupItemSURes_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupItemSURes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupRequestTransfer( SI_AMF_DT_PDUSessionResourceSetupRequestTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupResponseTransfer( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupResponseTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupResponseTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSetupUnsuccessfulTransfer( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs( SI_AMF_DT_PDUSessionResourceSetupUnsuccessfulTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSwitchedList( SI_AMF_DT_PDUSessionResourceSwitchedList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestAcknowledgeTransferOctStr( SI_AMF_DT_PathSwitchRequestAcknowledgeTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceSwitchedItem( SI_AMF_DT_PDUSessionResourceSwitchedItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceSwitchedItem_ExtIEs( SI_AMF_DT_PDUSessionResourceSwitchedItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceToBeSwitchedDLList( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PathSwitchRequestTransferOctStr( SI_AMF_DT_PathSwitchRequestTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceToBeSwitchedDLItem( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceToBeSwitchedDLItem_ExtIEs( SI_AMF_DT_PDUSessionResourceToBeSwitchedDLItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceToReleaseListHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_HandoverPreparationUnsuccessfulTransferOctStr( SI_AMF_DT_HandoverPreparationUnsuccessfulTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceToReleaseItemHOCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceToReleaseItemHOCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemHOCmd_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceToReleaseListRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceReleaseCommandTransferOctStr( SI_AMF_DT_PDUSessionResourceReleaseCommandTransferOctStr ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionResourceToReleaseItemRelCmd( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionResourceToReleaseItemRelCmd_ExtIEs( SI_AMF_DT_PDUSessionResourceToReleaseItemRelCmd_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PDUSessionType( uint8_t * ePDUSessionType,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PDUSessionUsageReport_ExtIEs( SI_AMF_DT_PDUSessionUsageReport_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PLMNSupportList( SI_AMF_DT_PLMNSupportList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PLMNSupportItem( SI_AMF_DT_PLMNSupportItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_PLMNSupportItem_ExtIEs( SI_AMF_DT_PLMNSupportItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_PWSFailedCellIDList( SI_AMF_DT_PWSFailedCellIDList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_PWSFailedCellIDList_ExtIEs( SI_AMF_DT_PWSFailedCellIDList_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosCharacteristics( SI_AMF_DT_QosCharacteristics ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_QosCharacteristics_ExtIEs( SI_AMF_DT_QosCharacteristics_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowAcceptedItem( SI_AMF_DT_QosFlowAcceptedItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowAcceptedItem_ExtIEs( SI_AMF_DT_QosFlowAcceptedItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ReflectiveQosAttribute( uint8_t * eReflectiveQosAttribute,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowLevelQosParameters( SI_AMF_DT_QosFlowLevelQosParameters ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowAddOrModifyRequestItem( SI_AMF_DT_QosFlowAddOrModifyRequestItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowAddOrModifyRequestItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyRequestItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowAddOrModifyResponseItem( SI_AMF_DT_QosFlowAddOrModifyResponseItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowAddOrModifyResponseItem_ExtIEs( SI_AMF_DT_QosFlowAddOrModifyResponseItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowInformationItem( SI_AMF_DT_QosFlowInformationItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ULForwarding( uint8_t * eULForwarding,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowInformationItem_ExtIEs( SI_AMF_DT_QosFlowInformationItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowLevelQosParameters_ExtIEs( SI_AMF_DT_QosFlowLevelQosParameters_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowWithCauseItem( SI_AMF_DT_QosFlowWithCauseItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowWithCauseItem_ExtIEs( SI_AMF_DT_QosFlowWithCauseItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowModifyConfirmItem( SI_AMF_DT_QosFlowModifyConfirmItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowModifyConfirmItem_ExtIEs( SI_AMF_DT_QosFlowModifyConfirmItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowNotifyItem( SI_AMF_DT_QosFlowNotifyItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowNotifyItem_ExtIEs( SI_AMF_DT_QosFlowNotifyItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowPerTNLInformation_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowPerTNLInformationItem( SI_AMF_DT_QosFlowPerTNLInformationItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowPerTNLInformationItem_ExtIEs( SI_AMF_DT_QosFlowPerTNLInformationItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowSetupRequestList( SI_AMF_DT_QosFlowSetupRequestList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowSetupRequestItem( SI_AMF_DT_QosFlowSetupRequestItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowSetupRequestItem_ExtIEs( SI_AMF_DT_QosFlowSetupRequestItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowItemWithDataForwarding( SI_AMF_DT_QosFlowItemWithDataForwarding ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowItemWithDataForwarding_ExtIEs( SI_AMF_DT_QosFlowItemWithDataForwarding_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowSetupResponseListSURes( SI_AMF_DT_QosFlowSetupResponseListSURes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowSetupResponseItemSURes( SI_AMF_DT_QosFlowSetupResponseItemSURes ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowSetupResponseItemSURes_ExtIEs( SI_AMF_DT_QosFlowSetupResponseItemSURes_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QosFlowToBeForwardedItem( SI_AMF_DT_QosFlowToBeForwardedItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QosFlowToBeForwardedItem_ExtIEs( SI_AMF_DT_QosFlowToBeForwardedItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QoSFlowsUsageReport_ItemRatType( uint8_t * eQoSFlowsUsageReport_ItemRatType,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_QoSFlowsUsageReport_Item( SI_AMF_DT_QoSFlowsUsageReport_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_QoSFlowsUsageReport_Item_ExtIEs( SI_AMF_DT_QoSFlowsUsageReport_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RANNodeName( SI_AMF_DT_RANNodeName ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RANPagingPriority( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RANStatusTransfer_TransparentContainer( SI_AMF_DT_RANStatusTransfer_TransparentContainer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_RANStatusTransfer_TransparentContainer_ExtIEs( SI_AMF_DT_RANStatusTransfer_TransparentContainer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RAN_UE_NGAP_ID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RATRestrictionInformation( SI_AMF_DT_RATRestrictionInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RATRestrictions_Item( SI_AMF_DT_RATRestrictions_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_RATRestrictions_Item_ExtIEs( SI_AMF_DT_RATRestrictions_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_RecommendedCellsForPaging_ExtIEs( SI_AMF_DT_RecommendedCellsForPaging_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedCellItemTime( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedCellItem( SI_AMF_DT_RecommendedCellItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_RecommendedCellItem_ExtIEs( SI_AMF_DT_RecommendedCellItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_RecommendedRANNodesForPaging_ExtIEs( SI_AMF_DT_RecommendedRANNodesForPaging_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RecommendedRANNodeItem( SI_AMF_DT_RecommendedRANNodeItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_RecommendedRANNodeItem_ExtIEs( SI_AMF_DT_RecommendedRANNodeItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ReferenceID( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RelativeAMFCapacity( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RepetitionPeriod( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ResetAll( uint8_t * eResetAll,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UE_associatedLogicalNG_connectionList( SI_AMF_DT_UE_associatedLogicalNG_connectionList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ResetType( SI_AMF_DT_ResetType ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_ResetType_ExtIEs( SI_AMF_DT_ResetType_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RoutingID( SI_AMF_DT_RoutingID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RRCContainer( SI_AMF_DT_RRCContainer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RRCEstablishmentCause( uint8_t * eRRCEstablishmentCause,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RRCInactiveTransitionReportRequest( uint8_t * eRRCInactiveTransitionReportRequest,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RRCState( uint8_t * eRRCState,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SCTP_TLAs( SI_AMF_DT_SCTP_TLAs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SecondaryRATUsageInformation_ExtIEs( SI_AMF_DT_SecondaryRATUsageInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecondaryRATDataUsageReportTransfer( SI_AMF_DT_SecondaryRATDataUsageReportTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SecondaryRATDataUsageReportTransfer_ExtIEs( SI_AMF_DT_SecondaryRATDataUsageReportTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecurityKey( SI_AMF_DT_SecurityKey ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SecurityContext( SI_AMF_DT_SecurityContext ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SecurityContext_ExtIEs( SI_AMF_DT_SecurityContext_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SecurityIndication_ExtIEs( SI_AMF_DT_SecurityIndication_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SecurityResult_ExtIEs( SI_AMF_DT_SecurityResult_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SerialNumber( SI_AMF_DT_SerialNumber ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ServedGUAMIList( SI_AMF_DT_ServedGUAMIList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ServedGUAMIItem( SI_AMF_DT_ServedGUAMIItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_ServedGUAMIItem_ExtIEs( SI_AMF_DT_ServedGUAMIItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ServiceAreaInformation_Item( SI_AMF_DT_ServiceAreaInformation_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_ServiceAreaInformation_Item_ExtIEs( SI_AMF_DT_ServiceAreaInformation_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SliceOverloadItem( SI_AMF_DT_SliceOverloadItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SliceOverloadItem_ExtIEs( SI_AMF_DT_SliceOverloadItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SliceSupportItem( SI_AMF_DT_SliceSupportItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SliceSupportItem_ExtIEs( SI_AMF_DT_SliceSupportItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_S_NSSAI_ExtIEs( SI_AMF_DT_S_NSSAI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TargetRANNodeID( SI_AMF_DT_TargetRANNodeID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SourceRANNodeID( SI_AMF_DT_SourceRANNodeID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SONInformationRequest( uint8_t * eSONInformationRequest,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_XnTLAs( SI_AMF_DT_XnTLAs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_XnExtTLAs( SI_AMF_DT_XnExtTLAs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_XnTNLConfigurationInfo( SI_AMF_DT_XnTNLConfigurationInfo ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SONInformationReply( SI_AMF_DT_SONInformationReply ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SONInformation( SI_AMF_DT_SONInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SONConfigurationTransfer( SI_AMF_DT_SONConfigurationTransfer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SONConfigurationTransfer_ExtIEs( SI_AMF_DT_SONConfigurationTransfer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_SONInformation_ExtIEs( SI_AMF_DT_SONInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SONInformationReply_ExtIEs( SI_AMF_DT_SONInformationReply_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEHistoryInformation( SI_AMF_DT_UEHistoryInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SourceRANNodeID_ExtIEs( SI_AMF_DT_SourceRANNodeID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SourceToTarget_TransparentContainer( SI_AMF_DT_SourceToTarget_TransparentContainer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_ConfiguredNSSAI( SI_AMF_DT_ConfiguredNSSAI ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RejectedNSSAIinPLMN( SI_AMF_DT_RejectedNSSAIinPLMN ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_RejectedNSSAIinTA( SI_AMF_DT_RejectedNSSAIinTA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SourceToTarget_AMFInformationReroute( SI_AMF_DT_SourceToTarget_AMFInformationReroute ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SourceToTarget_AMFInformationReroute_ExtIEs( SI_AMF_DT_SourceToTarget_AMFInformationReroute_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SupportedTAList( SI_AMF_DT_SupportedTAList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_SupportedTAItem( SI_AMF_DT_SupportedTAItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_SupportedTAItem_ExtIEs( SI_AMF_DT_SupportedTAItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAI_ExtIEs( SI_AMF_DT_TAI_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIBroadcastEUTRA_Item( SI_AMF_DT_TAIBroadcastEUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAIBroadcastEUTRA_Item_ExtIEs( SI_AMF_DT_TAIBroadcastEUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIBroadcastNR_Item( SI_AMF_DT_TAIBroadcastNR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAIBroadcastNR_Item_ExtIEs( SI_AMF_DT_TAIBroadcastNR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAICancelledEUTRA_Item( SI_AMF_DT_TAICancelledEUTRA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAICancelledEUTRA_Item_ExtIEs( SI_AMF_DT_TAICancelledEUTRA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAICancelledNR_Item( SI_AMF_DT_TAICancelledNR_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAICancelledNR_Item_ExtIEs( SI_AMF_DT_TAICancelledNR_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIListForInactiveItem( SI_AMF_DT_TAIListForInactiveItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAIListForInactiveItem_ExtIEs( SI_AMF_DT_TAIListForInactiveItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIListForPaging( SI_AMF_DT_TAIListForPaging ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIListForPagingItem( SI_AMF_DT_TAIListForPagingItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TAIListForPagingItem_ExtIEs( SI_AMF_DT_TAIListForPagingItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIListForRestart( SI_AMF_DT_TAIListForRestart ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TAIListForWarning( SI_AMF_DT_TAIListForWarning ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TargeteNB_ID( SI_AMF_DT_TargeteNB_ID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TargeteNB_ID_ExtIEs( SI_AMF_DT_TargeteNB_ID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TargetID( SI_AMF_DT_TargetID ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_TargetID_ExtIEs( SI_AMF_DT_TargetID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs( SI_AMF_DT_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TargetRANNodeID_ExtIEs( SI_AMF_DT_TargetRANNodeID_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TargetToSource_TransparentContainer( SI_AMF_DT_TargetToSource_TransparentContainer ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TimerApproachForGUAMIRemoval( uint8_t * eTimerApproachForGUAMIRemoval,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TimeStamp( SI_AMF_DT_TimeStamp ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TimeToWait( uint8_t * eTimeToWait,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TNLAssociationList( SI_AMF_DT_TNLAssociationList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TNLAssociationItem( SI_AMF_DT_TNLAssociationItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TNLAssociationItem_ExtIEs( SI_AMF_DT_TNLAssociationItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TraceDepth( uint8_t * eTraceDepth,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_TraceActivation( SI_AMF_DT_TraceActivation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_TraceActivation_ExtIEs( SI_AMF_DT_TraceActivation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEAggregateMaximumBitRate( SI_AMF_DT_UEAggregateMaximumBitRate ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UEAggregateMaximumBitRate_ExtIEs( SI_AMF_DT_UEAggregateMaximumBitRate_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UE_associatedLogicalNG_connectionItem( SI_AMF_DT_UE_associatedLogicalNG_connectionItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UE_associatedLogicalNG_connectionItem_ExtIEs( SI_AMF_DT_UE_associatedLogicalNG_connectionItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEContextRequest( uint8_t * eUEContextRequest,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_UEIdentityIndexValue_ExtIEs( SI_AMF_DT_UEIdentityIndexValue_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UE_NGAP_ID_pair( SI_AMF_DT_UE_NGAP_ID_pair ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UE_NGAP_IDs( SI_AMF_DT_UE_NGAP_IDs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_UE_NGAP_IDs_ExtIEs( SI_AMF_DT_UE_NGAP_IDs_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UE_NGAP_ID_pair_ExtIEs( SI_AMF_DT_UE_NGAP_ID_pair_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEPagingIdentity( SI_AMF_DT_UEPagingIdentity ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_UEPagingIdentity_ExtIEs( SI_AMF_DT_UEPagingIdentity_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEPresence( uint8_t * eUEPresence,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEPresenceInAreaOfInterestList( SI_AMF_DT_UEPresenceInAreaOfInterestList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UEPresenceInAreaOfInterestItem( SI_AMF_DT_UEPresenceInAreaOfInterestItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UEPresenceInAreaOfInterestItem_ExtIEs( SI_AMF_DT_UEPresenceInAreaOfInterestItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UERadioCapability( SI_AMF_DT_UERadioCapability ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UERadioCapabilityForPagingOfNR( SI_AMF_DT_UERadioCapabilityForPagingOfNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UERadioCapabilityForPagingOfEUTRA( SI_AMF_DT_UERadioCapabilityForPagingOfEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UERadioCapabilityForPaging( SI_AMF_DT_UERadioCapabilityForPaging ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UERadioCapabilityForPaging_ExtIEs( SI_AMF_DT_UERadioCapabilityForPaging_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UERetentionInformation( uint8_t * eUERetentionInformation,  int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UESecurityCapabilities( SI_AMF_DT_UESecurityCapabilities ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UESecurityCapabilities_ExtIEs( SI_AMF_DT_UESecurityCapabilities_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UL_NGU_UP_TNLModifyItem( SI_AMF_DT_UL_NGU_UP_TNLModifyItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UL_NGU_UP_TNLModifyItem_ExtIEs( SI_AMF_DT_UL_NGU_UP_TNLModifyItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UnavailableGUAMIList( SI_AMF_DT_UnavailableGUAMIList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UnavailableGUAMIItem( SI_AMF_DT_UnavailableGUAMIItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UnavailableGUAMIItem_ExtIEs( SI_AMF_DT_UnavailableGUAMIItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_UPTransportLayerInformation_ExtIEs( SI_AMF_DT_UPTransportLayerInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UPTransportLayerInformationItem( SI_AMF_DT_UPTransportLayerInformationItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UPTransportLayerInformationItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UPTransportLayerInformationPairItem( SI_AMF_DT_UPTransportLayerInformationPairItem ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UPTransportLayerInformationPairItem_ExtIEs( SI_AMF_DT_UPTransportLayerInformationPairItem_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UserLocationInformationEUTRA( SI_AMF_DT_UserLocationInformationEUTRA ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UserLocationInformationNR( SI_AMF_DT_UserLocationInformationNR ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UserLocationInformationN3IWF( SI_AMF_DT_UserLocationInformationN3IWF ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_UserLocationInformation( SI_AMF_DT_UserLocationInformation ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_UserLocationInformation_ExtIEs( SI_AMF_DT_UserLocationInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UserLocationInformationEUTRA_ExtIEs( SI_AMF_DT_UserLocationInformationEUTRA_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UserLocationInformationN3IWF_ExtIEs( SI_AMF_DT_UserLocationInformationN3IWF_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UserLocationInformationNR_ExtIEs( SI_AMF_DT_UserLocationInformationNR_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_UserPlaneSecurityInformation_ExtIEs( SI_AMF_DT_UserPlaneSecurityInformation_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_VolumeTimedReport_ItemTimeStamp( SI_AMF_DT_VolumeTimedReport_ItemTimeStamp ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_VolumeTimedReport_ItemUsageCount( unsigned long long int * data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_VolumeTimedReport_Item( SI_AMF_DT_VolumeTimedReport_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_VolumeTimedReport_Item_ExtIEs( SI_AMF_DT_VolumeTimedReport_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_WarningAreaCoordinates( SI_AMF_DT_WarningAreaCoordinates ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_WarningAreaList( SI_AMF_DT_WarningAreaList ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=2  DT=3 Container L:2619
int __si_amf_Decode_WarningAreaList_ExtIEs( SI_AMF_DT_WarningAreaList_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_WarningMessageContents( SI_AMF_DT_WarningMessageContents ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_WarningSecurityInfo( SI_AMF_DT_WarningSecurityInfo ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_WarningType( SI_AMF_DT_WarningType ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_XnGTP_TLAs( SI_AMF_DT_XnGTP_TLAs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

int __si_amf_Decode_XnExtTLA_Item( SI_AMF_DT_XnExtTLA_Item ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_XnExtTLA_Item_ExtIEs( SI_AMF_DT_XnExtTLA_Item_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// DHS-ADT=1  DT=3 Container L:2619
int __si_amf_Decode_XnTNLConfigurationInfo_ExtIEs( SI_AMF_DT_XnTNLConfigurationInfo_ExtIEs ** data, int * isSet, int lvl, SI_ASN_CodingContext * codingContext);

// PDU-Message Dependencies List = 82
// 1 - PDUSessionResourceSetupRequest
// 2 - PDUSessionResourceSetupResponse
// 3 - PDUSessionResourceReleaseCommand
// 4 - PDUSessionResourceReleaseResponse
// 5 - PDUSessionResourceModifyRequest
// 6 - PDUSessionResourceModifyResponse
// 7 - PDUSessionResourceNotify
// 8 - PDUSessionResourceModifyIndication
// 9 - PDUSessionResourceModifyConfirm
// 10 - RedirectionVoiceFallback
// 11 - InitialContextSetupRequest
// 12 - InitialContextSetupResponse
// 13 - InitialContextSetupFailure
// 14 - UEContextReleaseRequest
// 15 - UEContextReleaseCommand
// 16 - UEContextReleaseComplete
// 17 - UEContextModificationRequest
// 18 - UEContextModificationResponse
// 19 - UEContextModificationFailure
// 20 - RRCInactiveTransitionReport
// 21 - HandoverRequired
// 22 - HandoverCommand
// 23 - HandoverPreparationFailure
// 24 - HandoverRequest
// 25 - HandoverRequestAcknowledge
// 26 - HandoverFailure
// 27 - HandoverNotify
// 28 - PathSwitchRequest
// 29 - PathSwitchRequestAcknowledge
// 30 - PathSwitchRequestFailure
// 31 - HandoverCancel
// 32 - HandoverCancelAcknowledge
// 33 - UplinkRANStatusTransfer
// 34 - DownlinkRANStatusTransfer
// 35 - Paging
// 36 - InitialUEMessage
// 37 - DownlinkNASTransport
// 38 - UplinkNASTransport
// 39 - NASNonDeliveryIndication
// 40 - OCTET-STRING
// 41 - RerouteNASRequest
// 42 - NGSetupRequest
// 43 - NGSetupResponse
// 44 - NGSetupFailure
// 45 - RANConfigurationUpdate
// 46 - RANConfigurationUpdateAcknowledge
// 47 - RANConfigurationUpdateFailure
// 48 - AMFConfigurationUpdate
// 49 - AMFConfigurationUpdateAcknowledge
// 50 - AMFConfigurationUpdateFailure
// 51 - AMFStatusIndication
// 52 - NGReset
// 53 - NGResetAcknowledge
// 54 - ErrorIndication
// 55 - OverloadStart
// 56 - 
// 57 - OverloadStop
// 58 - UplinkRANConfigurationTransfer
// 59 - DownlinkRANConfigurationTransfer
// 60 - WriteReplaceWarningRequest
// 61 - WriteReplaceWarningResponse
// 62 - PWSCancelRequest
// 63 - PWSCancelResponse
// 64 - PWSRestartIndication
// 65 - PWSFailureIndication
// 66 - DownlinkUEAssociatedNRPPaTransport
// 67 - UplinkUEAssociatedNRPPaTransport
// 68 - DownlinkNonUEAssociatedNRPPaTransport
// 69 - UplinkNonUEAssociatedNRPPaTransport
// 70 - TraceStart
// 71 - TraceFailureIndication
// 72 - DeactivateTrace
// 73 - CellTrafficTrace
// 74 - LocationReportingControl
// 75 - LocationReportingFailureIndication
// 76 - LocationReport
// 77 - UETNLABindingReleaseRequest
// 78 - UERadioCapabilityInfoIndication
// 79 - UERadioCapabilityCheckRequest
// 80 - UERadioCapabilityCheckResponse
// 81 - PrivateMessage
// 82 - SecondaryRATDataUsageReport
// ------------------------------------------------------------ 
//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceSetup  L:8448

typedef struct __si_amf_dt_PDUSessionResourceSetupRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RANPagingPriority, PRESENCE = optional L:8487
	unsigned long long int rANPagingPriority;
	int rANPagingPriority_isset;

	// ID = id-NAS-PDU, PRESENCE = optional L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-PDUSessionResourceSetupListSUReq, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceSetupListSUReq * pDUSessionResourceSetupListSUReq;
	int pDUSessionResourceSetupListSUReq_isset;

	// ID = id-UEAggregateMaximumBitRate, PRESENCE = optional L:8487
	SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate;
	int uEAggregateMaximumBitRate_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceSetupRequest;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceSetup  L:8448

typedef struct __si_amf_dt_PDUSessionResourceSetupResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceSetupListSURes, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceSetupListSURes * pDUSessionResourceSetupListSURes;
	int pDUSessionResourceSetupListSURes_isset;

	// ID = id-PDUSessionResourceFailedToSetupListSURes, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToSetupListSURes * pDUSessionResourceFailedToSetupListSURes;
	int pDUSessionResourceFailedToSetupListSURes_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceSetupResponse;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceRelease  L:8448

typedef struct __si_amf_dt_PDUSessionResourceReleaseCommand
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RANPagingPriority, PRESENCE = optional L:8487
	unsigned long long int rANPagingPriority;
	int rANPagingPriority_isset;

	// ID = id-NAS-PDU, PRESENCE = optional L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-PDUSessionResourceToReleaseListRelCmd, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceToReleaseListRelCmd * pDUSessionResourceToReleaseListRelCmd;
	int pDUSessionResourceToReleaseListRelCmd_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceRelease  L:8448

typedef struct __si_amf_dt_PDUSessionResourceReleaseResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceReleasedListRelRes, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceReleasedListRelRes * pDUSessionResourceReleasedListRelRes;
	int pDUSessionResourceReleasedListRelRes_isset;

	// ID = id-UserLocationInformation, PRESENCE = optional L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceModify  L:8448

typedef struct __si_amf_dt_PDUSessionResourceModifyRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RANPagingPriority, PRESENCE = optional L:8487
	unsigned long long int rANPagingPriority;
	int rANPagingPriority_isset;

	// ID = id-PDUSessionResourceModifyListModReq, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceModifyListModReq * pDUSessionResourceModifyListModReq;
	int pDUSessionResourceModifyListModReq_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceModifyRequest;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceModify  L:8448

typedef struct __si_amf_dt_PDUSessionResourceModifyResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceModifyListModRes, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceModifyListModRes * pDUSessionResourceModifyListModRes;
	int pDUSessionResourceModifyListModRes_isset;

	// ID = id-PDUSessionResourceFailedToModifyListModRes, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToModifyListModRes * pDUSessionResourceFailedToModifyListModRes;
	int pDUSessionResourceFailedToModifyListModRes_isset;

	// ID = id-UserLocationInformation, PRESENCE = optional L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceModifyResponse;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceNotify  L:8448

typedef struct __si_amf_dt_PDUSessionResourceNotify
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceNotifyList, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceNotifyList * pDUSessionResourceNotifyList;
	int pDUSessionResourceNotifyList_isset;

	// ID = id-PDUSessionResourceReleasedListNot, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceReleasedListNot * pDUSessionResourceReleasedListNot;
	int pDUSessionResourceReleasedListNot_isset;

	// ID = id-UserLocationInformation, PRESENCE = optional L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceNotify;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceModifyIndication  L:8448

typedef struct __si_amf_dt_PDUSessionResourceModifyIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceModifyListModInd, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceModifyListModInd * pDUSessionResourceModifyListModInd;
	int pDUSessionResourceModifyListModInd_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceModifyIndication;


//ELEMENTARY-PROCEDURE = [2] pDUSessionResourceModifyIndication  L:8448

typedef struct __si_amf_dt_PDUSessionResourceModifyConfirm
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceModifyListModCfm, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceModifyListModCfm * pDUSessionResourceModifyListModCfm;
	int pDUSessionResourceModifyListModCfm_isset;

	// ID = id-PDUSessionResourceFailedToModifyListModCfm, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToModifyListModCfm * pDUSessionResourceFailedToModifyListModCfm;
	int pDUSessionResourceFailedToModifyListModCfm_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm;


// GOT-NULL RedirectionVoiceFallback
//ELEMENTARY-PROCEDURE = [2] initialContextSetup  L:8448

typedef struct __si_amf_dt_InitialContextSetupRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-OldAMF, PRESENCE = optional L:8487
	SI_AMF_DT_AMFName * oldAMF;
	int oldAMF_isset;

	// ID = id-UEAggregateMaximumBitRate, PRESENCE = conditional L:8487
	SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate;
	int uEAggregateMaximumBitRate_isset;

	// ID = id-CoreNetworkAssistanceInformationForInactive, PRESENCE = optional L:8487
	SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * coreNetworkAssistanceInformationForInactive;
	int coreNetworkAssistanceInformationForInactive_isset;

	// ID = id-GUAMI, PRESENCE = mandatory L:8487
	SI_AMF_DT_GUAMI * gUAMI;
	int gUAMI_isset;

	// ID = id-PDUSessionResourceSetupListCxtReq, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceSetupListCxtReq * pDUSessionResourceSetupListCxtReq;
	int pDUSessionResourceSetupListCxtReq_isset;

	// ID = id-AllowedNSSAI, PRESENCE = mandatory L:8487
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI;
	int allowedNSSAI_isset;

	// ID = id-UESecurityCapabilities, PRESENCE = mandatory L:8487
	SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities;
	int uESecurityCapabilities_isset;

	// ID = id-SecurityKey, PRESENCE = mandatory L:8487
	SI_AMF_DT_SecurityKey * securityKey;
	int securityKey_isset;

	// ID = id-TraceActivation, PRESENCE = optional L:8487
	SI_AMF_DT_TraceActivation * traceActivation;
	int traceActivation_isset;

	// ID = id-MobilityRestrictionList, PRESENCE = optional L:8487
	SI_AMF_DT_MobilityRestrictionList * mobilityRestrictionList;
	int mobilityRestrictionList_isset;

	// ID = id-UERadioCapability, PRESENCE = optional L:8487
	SI_AMF_DT_UERadioCapability * uERadioCapability;
	int uERadioCapability_isset;

	// ID = id-IndexToRFSP, PRESENCE = optional L:8487
	unsigned long long int indexToRFSP;
	int indexToRFSP_isset;

	// ID = id-MaskedIMEISV, PRESENCE = optional L:8487
	SI_AMF_DT_MaskedIMEISV * maskedIMEISV;
	int maskedIMEISV_isset;

	// ID = id-NAS-PDU, PRESENCE = optional L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-EmergencyFallbackIndicator, PRESENCE = optional L:8487
	SI_AMF_DT_EmergencyFallbackIndicator * emergencyFallbackIndicator;
	int emergencyFallbackIndicator_isset;

	// ID = id-RRCInactiveTransitionReportRequest, PRESENCE = optional L:8487
	uint8_t rRCInactiveTransitionReportRequest;
	int rRCInactiveTransitionReportRequest_isset;

	// ID = id-UERadioCapabilityForPaging, PRESENCE = optional L:8487
	SI_AMF_DT_UERadioCapabilityForPaging * uERadioCapabilityForPaging;
	int uERadioCapabilityForPaging_isset;

	//id-RedirectionVoiceFallback:RedirectionVoiceFallback
	// ID = id-LocationReportingRequestType, PRESENCE = optional L:8487
	SI_AMF_DT_LocationReportingRequestType * locationReportingRequestType;
	int locationReportingRequestType_isset;

	// ID = id-CNAssistedRANTuning, PRESENCE = optional L:8487
	SI_AMF_DT_CNAssistedRANTuning * cNAssistedRANTuning;
	int cNAssistedRANTuning_isset;

	
} SI_AMF_DT_PDU_InitialContextSetupRequest;


//ELEMENTARY-PROCEDURE = [2] initialContextSetup  L:8448

typedef struct __si_amf_dt_InitialContextSetupResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceSetupListCxtRes, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceSetupListCxtRes * pDUSessionResourceSetupListCxtRes;
	int pDUSessionResourceSetupListCxtRes_isset;

	// ID = id-PDUSessionResourceFailedToSetupListCxtRes, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtRes * pDUSessionResourceFailedToSetupListCxtRes;
	int pDUSessionResourceFailedToSetupListCxtRes_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_InitialContextSetupResponse;


//ELEMENTARY-PROCEDURE = [2] initialContextSetup  L:8448

typedef struct __si_amf_dt_InitialContextSetupFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceFailedToSetupListCxtFail, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToSetupListCxtFail * pDUSessionResourceFailedToSetupListCxtFail;
	int pDUSessionResourceFailedToSetupListCxtFail_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_InitialContextSetupFailure;


//ELEMENTARY-PROCEDURE = [2] uEContextReleaseRequest  L:8448

typedef struct __si_amf_dt_UEContextReleaseRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceListCxtRelReq, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceListCxtRelReq * pDUSessionResourceListCxtRelReq;
	int pDUSessionResourceListCxtRelReq_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	
} SI_AMF_DT_PDU_UEContextReleaseRequest;


//ELEMENTARY-PROCEDURE = [2] uEContextRelease  L:8448

typedef struct __si_amf_dt_UEContextReleaseCommand
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-UE-NGAP-IDs, PRESENCE = mandatory L:8487
	SI_AMF_DT_UE_NGAP_IDs * uENGAPIDs;
	int uENGAPIDs_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	
} SI_AMF_DT_PDU_UEContextReleaseCommand;


//ELEMENTARY-PROCEDURE = [2] uEContextRelease  L:8448

typedef struct __si_amf_dt_UEContextReleaseComplete
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-UserLocationInformation, PRESENCE = optional L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-InfoOnRecommendedCellsAndRANNodesForPaging, PRESENCE = optional L:8487
	SI_AMF_DT_InfoOnRecommendedCellsAndRANNodesForPaging * infoOnRecommendedCellsAndRANNodesForPaging;
	int infoOnRecommendedCellsAndRANNodesForPaging_isset;

	// ID = id-PDUSessionResourceListCxtRelCpl, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceListCxtRelCpl * pDUSessionResourceListCxtRelCpl;
	int pDUSessionResourceListCxtRelCpl_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_UEContextReleaseComplete;


//ELEMENTARY-PROCEDURE = [2] uEContextModification  L:8448

typedef struct __si_amf_dt_UEContextModificationRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RANPagingPriority, PRESENCE = optional L:8487
	unsigned long long int rANPagingPriority;
	int rANPagingPriority_isset;

	// ID = id-SecurityKey, PRESENCE = optional L:8487
	SI_AMF_DT_SecurityKey * securityKey;
	int securityKey_isset;

	// ID = id-IndexToRFSP, PRESENCE = optional L:8487
	unsigned long long int indexToRFSP;
	int indexToRFSP_isset;

	// ID = id-UEAggregateMaximumBitRate, PRESENCE = optional L:8487
	SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate;
	int uEAggregateMaximumBitRate_isset;

	// ID = id-UESecurityCapabilities, PRESENCE = optional L:8487
	SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities;
	int uESecurityCapabilities_isset;

	// ID = id-CoreNetworkAssistanceInformationForInactive, PRESENCE = optional L:8487
	SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * coreNetworkAssistanceInformationForInactive;
	int coreNetworkAssistanceInformationForInactive_isset;

	// ID = id-EmergencyFallbackIndicator, PRESENCE = optional L:8487
	SI_AMF_DT_EmergencyFallbackIndicator * emergencyFallbackIndicator;
	int emergencyFallbackIndicator_isset;

	// ID = id-NewAMF-UE-NGAP-ID, PRESENCE = optional L:8487
	unsigned long long int newAMFUENGAPID;
	int newAMFUENGAPID_isset;

	// ID = id-RRCInactiveTransitionReportRequest, PRESENCE = optional L:8487
	uint8_t rRCInactiveTransitionReportRequest;
	int rRCInactiveTransitionReportRequest_isset;

	// ID = id-NewGUAMI, PRESENCE = optional L:8487
	SI_AMF_DT_GUAMI * newGUAMI;
	int newGUAMI_isset;

	// ID = id-CNAssistedRANTuning, PRESENCE = optional L:8487
	SI_AMF_DT_CNAssistedRANTuning * cNAssistedRANTuning;
	int cNAssistedRANTuning_isset;

	
} SI_AMF_DT_PDU_UEContextModificationRequest;


//ELEMENTARY-PROCEDURE = [2] uEContextModification  L:8448

typedef struct __si_amf_dt_UEContextModificationResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RRCState, PRESENCE = optional L:8487
	uint8_t rRCState;
	int rRCState_isset;

	// ID = id-UserLocationInformation, PRESENCE = optional L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_UEContextModificationResponse;


//ELEMENTARY-PROCEDURE = [2] uEContextModification  L:8448

typedef struct __si_amf_dt_UEContextModificationFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_UEContextModificationFailure;


//ELEMENTARY-PROCEDURE = [2] rRCInactiveTransitionReport  L:8448

typedef struct __si_amf_dt_RRCInactiveTransitionReport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RRCState, PRESENCE = mandatory L:8487
	uint8_t rRCState;
	int rRCState_isset;

	// ID = id-UserLocationInformation, PRESENCE = mandatory L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	
} SI_AMF_DT_PDU_RRCInactiveTransitionReport;


//ELEMENTARY-PROCEDURE = [2] handoverPreparation  L:8448

typedef struct __si_amf_dt_HandoverRequired
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-HandoverType, PRESENCE = mandatory L:8487
	uint8_t handoverType;
	int handoverType_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-TargetID, PRESENCE = mandatory L:8487
	SI_AMF_DT_TargetID * targetID;
	int targetID_isset;

	// ID = id-DirectForwardingPathAvailability, PRESENCE = optional L:8487
	uint8_t directForwardingPathAvailability;
	int directForwardingPathAvailability_isset;

	// ID = id-PDUSessionResourceListHORqd, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceListHORqd * pDUSessionResourceListHORqd;
	int pDUSessionResourceListHORqd_isset;

	// ID = id-SourceToTarget-TransparentContainer, PRESENCE = mandatory L:8487
	SI_AMF_DT_SourceToTarget_TransparentContainer * sourceToTargetTransparentContainer;
	int sourceToTargetTransparentContainer_isset;

	
} SI_AMF_DT_PDU_HandoverRequired;


//ELEMENTARY-PROCEDURE = [2] handoverPreparation  L:8448

typedef struct __si_amf_dt_HandoverCommand
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-HandoverType, PRESENCE = mandatory L:8487
	uint8_t handoverType;
	int handoverType_isset;

	// ID = id-NASSecurityParametersFromNGRAN, PRESENCE = conditional L:8487
	SI_AMF_DT_NASSecurityParametersFromNGRAN * nASSecurityParametersFromNGRAN;
	int nASSecurityParametersFromNGRAN_isset;

	// ID = id-PDUSessionResourceHandoverList, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceHandoverList * pDUSessionResourceHandoverList;
	int pDUSessionResourceHandoverList_isset;

	// ID = id-PDUSessionResourceToReleaseListHOCmd, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceToReleaseListHOCmd * pDUSessionResourceToReleaseListHOCmd;
	int pDUSessionResourceToReleaseListHOCmd_isset;

	// ID = id-TargetToSource-TransparentContainer, PRESENCE = mandatory L:8487
	SI_AMF_DT_TargetToSource_TransparentContainer * targetToSourceTransparentContainer;
	int targetToSourceTransparentContainer_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_HandoverCommand;


//ELEMENTARY-PROCEDURE = [2] handoverPreparation  L:8448

typedef struct __si_amf_dt_HandoverPreparationFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_HandoverPreparationFailure;


//ELEMENTARY-PROCEDURE = [2] handoverResourceAllocation  L:8448

typedef struct __si_amf_dt_HandoverRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-HandoverType, PRESENCE = mandatory L:8487
	uint8_t handoverType;
	int handoverType_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-UEAggregateMaximumBitRate, PRESENCE = mandatory L:8487
	SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate;
	int uEAggregateMaximumBitRate_isset;

	// ID = id-CoreNetworkAssistanceInformationForInactive, PRESENCE = optional L:8487
	SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * coreNetworkAssistanceInformationForInactive;
	int coreNetworkAssistanceInformationForInactive_isset;

	// ID = id-UESecurityCapabilities, PRESENCE = mandatory L:8487
	SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities;
	int uESecurityCapabilities_isset;

	// ID = id-SecurityContext, PRESENCE = mandatory L:8487
	SI_AMF_DT_SecurityContext * securityContext;
	int securityContext_isset;

	// ID = id-NewSecurityContextInd, PRESENCE = optional L:8487
	uint8_t newSecurityContextInd;
	int newSecurityContextInd_isset;

	// ID = id-NASC, PRESENCE = optional L:8487
	SI_AMF_DT_NAS_PDU * nASC;
	int nASC_isset;

	// ID = id-PDUSessionResourceSetupListHOReq, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceSetupListHOReq * pDUSessionResourceSetupListHOReq;
	int pDUSessionResourceSetupListHOReq_isset;

	// ID = id-AllowedNSSAI, PRESENCE = mandatory L:8487
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI;
	int allowedNSSAI_isset;

	// ID = id-TraceActivation, PRESENCE = optional L:8487
	SI_AMF_DT_TraceActivation * traceActivation;
	int traceActivation_isset;

	// ID = id-MaskedIMEISV, PRESENCE = optional L:8487
	SI_AMF_DT_MaskedIMEISV * maskedIMEISV;
	int maskedIMEISV_isset;

	// ID = id-SourceToTarget-TransparentContainer, PRESENCE = mandatory L:8487
	SI_AMF_DT_SourceToTarget_TransparentContainer * sourceToTargetTransparentContainer;
	int sourceToTargetTransparentContainer_isset;

	// ID = id-MobilityRestrictionList, PRESENCE = optional L:8487
	SI_AMF_DT_MobilityRestrictionList * mobilityRestrictionList;
	int mobilityRestrictionList_isset;

	// ID = id-LocationReportingRequestType, PRESENCE = optional L:8487
	SI_AMF_DT_LocationReportingRequestType * locationReportingRequestType;
	int locationReportingRequestType_isset;

	// ID = id-RRCInactiveTransitionReportRequest, PRESENCE = optional L:8487
	uint8_t rRCInactiveTransitionReportRequest;
	int rRCInactiveTransitionReportRequest_isset;

	// ID = id-GUAMI, PRESENCE = mandatory L:8487
	SI_AMF_DT_GUAMI * gUAMI;
	int gUAMI_isset;

	//id-RedirectionVoiceFallback:RedirectionVoiceFallback
	// ID = id-CNAssistedRANTuning, PRESENCE = optional L:8487
	SI_AMF_DT_CNAssistedRANTuning * cNAssistedRANTuning;
	int cNAssistedRANTuning_isset;

	
} SI_AMF_DT_PDU_HandoverRequest;


//ELEMENTARY-PROCEDURE = [2] handoverResourceAllocation  L:8448

typedef struct __si_amf_dt_HandoverRequestAcknowledge
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceAdmittedList, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceAdmittedList * pDUSessionResourceAdmittedList;
	int pDUSessionResourceAdmittedList_isset;

	// ID = id-PDUSessionResourceFailedToSetupListHOAck, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToSetupListHOAck * pDUSessionResourceFailedToSetupListHOAck;
	int pDUSessionResourceFailedToSetupListHOAck_isset;

	// ID = id-TargetToSource-TransparentContainer, PRESENCE = mandatory L:8487
	SI_AMF_DT_TargetToSource_TransparentContainer * targetToSourceTransparentContainer;
	int targetToSourceTransparentContainer_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_HandoverRequestAcknowledge;


//ELEMENTARY-PROCEDURE = [2] handoverResourceAllocation  L:8448

typedef struct __si_amf_dt_HandoverFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_HandoverFailure;


//ELEMENTARY-PROCEDURE = [2] handoverNotification  L:8448

typedef struct __si_amf_dt_HandoverNotify
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-UserLocationInformation, PRESENCE = mandatory L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	
} SI_AMF_DT_PDU_HandoverNotify;


//ELEMENTARY-PROCEDURE = [2] pathSwitchRequest  L:8448

typedef struct __si_amf_dt_PathSwitchRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-SourceAMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int sourceAMFUENGAPID;
	int sourceAMFUENGAPID_isset;

	// ID = id-UserLocationInformation, PRESENCE = mandatory L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-UESecurityCapabilities, PRESENCE = mandatory L:8487
	SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities;
	int uESecurityCapabilities_isset;

	// ID = id-PDUSessionResourceToBeSwitchedDLList, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceToBeSwitchedDLList * pDUSessionResourceToBeSwitchedDLList;
	int pDUSessionResourceToBeSwitchedDLList_isset;

	// ID = id-PDUSessionResourceFailedToSetupListPSReq, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceFailedToSetupListPSReq * pDUSessionResourceFailedToSetupListPSReq;
	int pDUSessionResourceFailedToSetupListPSReq_isset;

	
} SI_AMF_DT_PDU_PathSwitchRequest;


//ELEMENTARY-PROCEDURE = [2] pathSwitchRequest  L:8448

typedef struct __si_amf_dt_PathSwitchRequestAcknowledge
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-UESecurityCapabilities, PRESENCE = optional L:8487
	SI_AMF_DT_UESecurityCapabilities * uESecurityCapabilities;
	int uESecurityCapabilities_isset;

	// ID = id-SecurityContext, PRESENCE = mandatory L:8487
	SI_AMF_DT_SecurityContext * securityContext;
	int securityContext_isset;

	// ID = id-NewSecurityContextInd, PRESENCE = optional L:8487
	uint8_t newSecurityContextInd;
	int newSecurityContextInd_isset;

	// ID = id-PDUSessionResourceSwitchedList, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceSwitchedList * pDUSessionResourceSwitchedList;
	int pDUSessionResourceSwitchedList_isset;

	// ID = id-PDUSessionResourceReleasedListPSAck, PRESENCE = optional L:8487
	SI_AMF_DT_PDUSessionResourceReleasedListPSAck * pDUSessionResourceReleasedListPSAck;
	int pDUSessionResourceReleasedListPSAck_isset;

	// ID = id-AllowedNSSAI, PRESENCE = mandatory L:8487
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI;
	int allowedNSSAI_isset;

	// ID = id-CoreNetworkAssistanceInformationForInactive, PRESENCE = optional L:8487
	SI_AMF_DT_CoreNetworkAssistanceInformationForInactive * coreNetworkAssistanceInformationForInactive;
	int coreNetworkAssistanceInformationForInactive_isset;

	// ID = id-RRCInactiveTransitionReportRequest, PRESENCE = optional L:8487
	uint8_t rRCInactiveTransitionReportRequest;
	int rRCInactiveTransitionReportRequest_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	//id-RedirectionVoiceFallback:RedirectionVoiceFallback
	// ID = id-CNAssistedRANTuning, PRESENCE = optional L:8487
	SI_AMF_DT_CNAssistedRANTuning * cNAssistedRANTuning;
	int cNAssistedRANTuning_isset;

	
} SI_AMF_DT_PDU_PathSwitchRequestAcknowledge;


//ELEMENTARY-PROCEDURE = [2] pathSwitchRequest  L:8448

typedef struct __si_amf_dt_PathSwitchRequestFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceReleasedListPSFail, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceReleasedListPSFail * pDUSessionResourceReleasedListPSFail;
	int pDUSessionResourceReleasedListPSFail_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_PathSwitchRequestFailure;


//ELEMENTARY-PROCEDURE = [2] handoverCancel  L:8448

typedef struct __si_amf_dt_HandoverCancel
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	
} SI_AMF_DT_PDU_HandoverCancel;


//ELEMENTARY-PROCEDURE = [2] handoverCancel  L:8448

typedef struct __si_amf_dt_HandoverCancelAcknowledge
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_HandoverCancelAcknowledge;


//ELEMENTARY-PROCEDURE = [2] uplinkRANStatusTransfer  L:8448

typedef struct __si_amf_dt_UplinkRANStatusTransfer
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RANStatusTransfer-TransparentContainer, PRESENCE = mandatory L:8487
	SI_AMF_DT_RANStatusTransfer_TransparentContainer * rANStatusTransferTransparentContainer;
	int rANStatusTransferTransparentContainer_isset;

	
} SI_AMF_DT_PDU_UplinkRANStatusTransfer;


//ELEMENTARY-PROCEDURE = [2] downlinkRANStatusTransfer  L:8448

typedef struct __si_amf_dt_DownlinkRANStatusTransfer
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RANStatusTransfer-TransparentContainer, PRESENCE = mandatory L:8487
	SI_AMF_DT_RANStatusTransfer_TransparentContainer * rANStatusTransferTransparentContainer;
	int rANStatusTransferTransparentContainer_isset;

	
} SI_AMF_DT_PDU_DownlinkRANStatusTransfer;


//ELEMENTARY-PROCEDURE = [2] paging  L:8448

typedef struct __si_amf_dt_Paging
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-UEPagingIdentity, PRESENCE = mandatory L:8487
	SI_AMF_DT_UEPagingIdentity * uEPagingIdentity;
	int uEPagingIdentity_isset;

	// ID = id-PagingDRX, PRESENCE = optional L:8487
	uint8_t pagingDRX;
	int pagingDRX_isset;

	// ID = id-TAIListForPaging, PRESENCE = mandatory L:8487
	SI_AMF_DT_TAIListForPaging * tAIListForPaging;
	int tAIListForPaging_isset;

	// ID = id-PagingPriority, PRESENCE = optional L:8487
	uint8_t pagingPriority;
	int pagingPriority_isset;

	// ID = id-UERadioCapabilityForPaging, PRESENCE = optional L:8487
	SI_AMF_DT_UERadioCapabilityForPaging * uERadioCapabilityForPaging;
	int uERadioCapabilityForPaging_isset;

	// ID = id-PagingOrigin, PRESENCE = optional L:8487
	uint8_t pagingOrigin;
	int pagingOrigin_isset;

	// ID = id-AssistanceDataForPaging, PRESENCE = optional L:8487
	SI_AMF_DT_AssistanceDataForPaging * assistanceDataForPaging;
	int assistanceDataForPaging_isset;

	
} SI_AMF_DT_PDU_Paging;


//ELEMENTARY-PROCEDURE = [2] initialUEMessage  L:8448

typedef struct __si_amf_dt_InitialUEMessage
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-NAS-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-UserLocationInformation, PRESENCE = mandatory L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-RRCEstablishmentCause, PRESENCE = mandatory L:8487
	uint8_t rRCEstablishmentCause;
	int rRCEstablishmentCause_isset;

	// ID = id-FiveG-S-TMSI, PRESENCE = optional L:8487
	SI_AMF_DT_FiveG_S_TMSI * fiveGSTMSI;
	int fiveGSTMSI_isset;

	// ID = id-AMFSetID, PRESENCE = optional L:8487
	SI_AMF_DT_AMFSetID * aMFSetID;
	int aMFSetID_isset;

	// ID = id-UEContextRequest, PRESENCE = optional L:8487
	uint8_t uEContextRequest;
	int uEContextRequest_isset;

	// ID = id-AllowedNSSAI, PRESENCE = optional L:8487
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI;
	int allowedNSSAI_isset;

	// ID = id-SourceToTarget-AMFInformationReroute, PRESENCE = optional L:8487
	SI_AMF_DT_SourceToTarget_AMFInformationReroute * sourceToTargetAMFInformationReroute;
	int sourceToTargetAMFInformationReroute_isset;

	
} SI_AMF_DT_PDU_InitialUEMessage;


//ELEMENTARY-PROCEDURE = [2] downlinkNASTransport  L:8448

typedef struct __si_amf_dt_DownlinkNASTransport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-OldAMF, PRESENCE = optional L:8487
	SI_AMF_DT_AMFName * oldAMF;
	int oldAMF_isset;

	// ID = id-RANPagingPriority, PRESENCE = optional L:8487
	unsigned long long int rANPagingPriority;
	int rANPagingPriority_isset;

	// ID = id-NAS-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-MobilityRestrictionList, PRESENCE = optional L:8487
	SI_AMF_DT_MobilityRestrictionList * mobilityRestrictionList;
	int mobilityRestrictionList_isset;

	// ID = id-IndexToRFSP, PRESENCE = optional L:8487
	unsigned long long int indexToRFSP;
	int indexToRFSP_isset;

	// ID = id-UEAggregateMaximumBitRate, PRESENCE = optional L:8487
	SI_AMF_DT_UEAggregateMaximumBitRate * uEAggregateMaximumBitRate;
	int uEAggregateMaximumBitRate_isset;

	// ID = id-AllowedNSSAI, PRESENCE = optional L:8487
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI;
	int allowedNSSAI_isset;

	
} SI_AMF_DT_PDU_DownlinkNASTransport;


//ELEMENTARY-PROCEDURE = [2] uplinkNASTransport  L:8448

typedef struct __si_amf_dt_UplinkNASTransport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-NAS-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-UserLocationInformation, PRESENCE = mandatory L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	
} SI_AMF_DT_PDU_UplinkNASTransport;


//ELEMENTARY-PROCEDURE = [2] nASNonDeliveryIndication  L:8448

typedef struct __si_amf_dt_NASNonDeliveryIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-NAS-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NAS_PDU * nASPDU;
	int nASPDU_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	
} SI_AMF_DT_PDU_NASNonDeliveryIndication;


// GOT-NULL OCTET-STRING
//ELEMENTARY-PROCEDURE = [2] rerouteNASRequest  L:8448

typedef struct __si_amf_dt_RerouteNASRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = optional L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	//id-NGAP-Message:OCTET-STRING
	// ID = id-AMFSetID, PRESENCE = mandatory L:8487
	SI_AMF_DT_AMFSetID * aMFSetID;
	int aMFSetID_isset;

	// ID = id-AllowedNSSAI, PRESENCE = optional L:8487
	SI_AMF_DT_AllowedNSSAI * allowedNSSAI;
	int allowedNSSAI_isset;

	// ID = id-SourceToTarget-AMFInformationReroute, PRESENCE = optional L:8487
	SI_AMF_DT_SourceToTarget_AMFInformationReroute * sourceToTargetAMFInformationReroute;
	int sourceToTargetAMFInformationReroute_isset;

	
} SI_AMF_DT_PDU_RerouteNASRequest;


//ELEMENTARY-PROCEDURE = [2] nGSetup  L:8448

typedef struct __si_amf_dt_NGSetupRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-GlobalRANNodeID, PRESENCE = mandatory L:8487
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;
	int globalRANNodeID_isset;

	// ID = id-RANNodeName, PRESENCE = optional L:8487
	SI_AMF_DT_RANNodeName * rANNodeName;
	int rANNodeName_isset;

	// ID = id-SupportedTAList, PRESENCE = mandatory L:8487
	SI_AMF_DT_SupportedTAList * supportedTAList;
	int supportedTAList_isset;

	// ID = id-DefaultPagingDRX, PRESENCE = mandatory L:8487
	uint8_t defaultPagingDRX;
	int defaultPagingDRX_isset;

	// ID = id-UERetentionInformation, PRESENCE = optional L:8487
	uint8_t uERetentionInformation;
	int uERetentionInformation_isset;

	
} SI_AMF_DT_PDU_NGSetupRequest;


//ELEMENTARY-PROCEDURE = [2] nGSetup  L:8448

typedef struct __si_amf_dt_NGSetupResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMFName, PRESENCE = mandatory L:8487
	SI_AMF_DT_AMFName * aMFName;
	int aMFName_isset;

	// ID = id-ServedGUAMIList, PRESENCE = mandatory L:8487
	SI_AMF_DT_ServedGUAMIList * servedGUAMIList;
	int servedGUAMIList_isset;

	// ID = id-RelativeAMFCapacity, PRESENCE = mandatory L:8487
	unsigned long long int relativeAMFCapacity;
	int relativeAMFCapacity_isset;

	// ID = id-PLMNSupportList, PRESENCE = mandatory L:8487
	SI_AMF_DT_PLMNSupportList * pLMNSupportList;
	int pLMNSupportList_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	// ID = id-UERetentionInformation, PRESENCE = optional L:8487
	uint8_t uERetentionInformation;
	int uERetentionInformation_isset;

	
} SI_AMF_DT_PDU_NGSetupResponse;


//ELEMENTARY-PROCEDURE = [2] nGSetup  L:8448

typedef struct __si_amf_dt_NGSetupFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-TimeToWait, PRESENCE = optional L:8487
	uint8_t timeToWait;
	int timeToWait_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_NGSetupFailure;


//ELEMENTARY-PROCEDURE = [2] rANConfigurationUpdate  L:8448

typedef struct __si_amf_dt_RANConfigurationUpdate
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-RANNodeName, PRESENCE = optional L:8487
	SI_AMF_DT_RANNodeName * rANNodeName;
	int rANNodeName_isset;

	// ID = id-SupportedTAList, PRESENCE = optional L:8487
	SI_AMF_DT_SupportedTAList * supportedTAList;
	int supportedTAList_isset;

	// ID = id-DefaultPagingDRX, PRESENCE = optional L:8487
	uint8_t defaultPagingDRX;
	int defaultPagingDRX_isset;

	// ID = id-GlobalRANNodeID, PRESENCE = optional L:8487
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;
	int globalRANNodeID_isset;

	// ID = id-NGRAN-TNLAssociationToRemoveList, PRESENCE = optional L:8487
	SI_AMF_DT_NGRAN_TNLAssociationToRemoveList * nGRANTNLAssociationToRemoveList;
	int nGRANTNLAssociationToRemoveList_isset;

	
} SI_AMF_DT_PDU_RANConfigurationUpdate;


//ELEMENTARY-PROCEDURE = [2] rANConfigurationUpdate  L:8448

typedef struct __si_amf_dt_RANConfigurationUpdateAcknowledge
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge;


//ELEMENTARY-PROCEDURE = [2] rANConfigurationUpdate  L:8448

typedef struct __si_amf_dt_RANConfigurationUpdateFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-TimeToWait, PRESENCE = optional L:8487
	uint8_t timeToWait;
	int timeToWait_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_RANConfigurationUpdateFailure;


//ELEMENTARY-PROCEDURE = [2] aMFConfigurationUpdate  L:8448

typedef struct __si_amf_dt_AMFConfigurationUpdate
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMFName, PRESENCE = optional L:8487
	SI_AMF_DT_AMFName * aMFName;
	int aMFName_isset;

	// ID = id-ServedGUAMIList, PRESENCE = optional L:8487
	SI_AMF_DT_ServedGUAMIList * servedGUAMIList;
	int servedGUAMIList_isset;

	// ID = id-RelativeAMFCapacity, PRESENCE = optional L:8487
	unsigned long long int relativeAMFCapacity;
	int relativeAMFCapacity_isset;

	// ID = id-PLMNSupportList, PRESENCE = optional L:8487
	SI_AMF_DT_PLMNSupportList * pLMNSupportList;
	int pLMNSupportList_isset;

	// ID = id-AMF-TNLAssociationToAddList, PRESENCE = optional L:8487
	SI_AMF_DT_AMF_TNLAssociationToAddList * aMFTNLAssociationToAddList;
	int aMFTNLAssociationToAddList_isset;

	// ID = id-AMF-TNLAssociationToRemoveList, PRESENCE = optional L:8487
	SI_AMF_DT_AMF_TNLAssociationToRemoveList * aMFTNLAssociationToRemoveList;
	int aMFTNLAssociationToRemoveList_isset;

	// ID = id-AMF-TNLAssociationToUpdateList, PRESENCE = optional L:8487
	SI_AMF_DT_AMF_TNLAssociationToUpdateList * aMFTNLAssociationToUpdateList;
	int aMFTNLAssociationToUpdateList_isset;

	
} SI_AMF_DT_PDU_AMFConfigurationUpdate;


//ELEMENTARY-PROCEDURE = [2] aMFConfigurationUpdate  L:8448

typedef struct __si_amf_dt_AMFConfigurationUpdateAcknowledge
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-TNLAssociationSetupList, PRESENCE = optional L:8487
	SI_AMF_DT_AMF_TNLAssociationSetupList * aMFTNLAssociationSetupList;
	int aMFTNLAssociationSetupList_isset;

	// ID = id-AMF-TNLAssociationFailedToSetupList, PRESENCE = optional L:8487
	SI_AMF_DT_TNLAssociationList * aMFTNLAssociationFailedToSetupList;
	int aMFTNLAssociationFailedToSetupList_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge;


//ELEMENTARY-PROCEDURE = [2] aMFConfigurationUpdate  L:8448

typedef struct __si_amf_dt_AMFConfigurationUpdateFailure
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-TimeToWait, PRESENCE = optional L:8487
	uint8_t timeToWait;
	int timeToWait_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_AMFConfigurationUpdateFailure;


//ELEMENTARY-PROCEDURE = [2] aMFStatusIndication  L:8448

typedef struct __si_amf_dt_AMFStatusIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-UnavailableGUAMIList, PRESENCE = mandatory L:8487
	SI_AMF_DT_UnavailableGUAMIList * unavailableGUAMIList;
	int unavailableGUAMIList_isset;

	
} SI_AMF_DT_PDU_AMFStatusIndication;


//ELEMENTARY-PROCEDURE = [2] nGReset  L:8448

typedef struct __si_amf_dt_NGReset
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-ResetType, PRESENCE = mandatory L:8487
	SI_AMF_DT_ResetType * resetType;
	int resetType_isset;

	
} SI_AMF_DT_PDU_NGReset;


//ELEMENTARY-PROCEDURE = [2] nGReset  L:8448

typedef struct __si_amf_dt_NGResetAcknowledge
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-UE-associatedLogicalNG-connectionList, PRESENCE = optional L:8487
	SI_AMF_DT_UE_associatedLogicalNG_connectionList * uEassociatedLogicalNGconnectionList;
	int uEassociatedLogicalNGconnectionList_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_NGResetAcknowledge;


//ELEMENTARY-PROCEDURE = [2] errorIndication  L:8448

typedef struct __si_amf_dt_ErrorIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = optional L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = optional L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-Cause, PRESENCE = optional L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_ErrorIndication;


//ELEMENTARY-PROCEDURE = [2] overloadStart  L:8448

typedef struct __si_amf_dt_OverloadStart
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMFOverloadResponse, PRESENCE = optional L:8487
	SI_AMF_DT_OverloadResponse * aMFOverloadResponse;
	int aMFOverloadResponse_isset;

	// ID = id-AMFTrafficLoadReductionIndication, PRESENCE = optional L:8487
	unsigned long long int aMFTrafficLoadReductionIndication;
	int aMFTrafficLoadReductionIndication_isset;

	// ID = id-OverloadStartNSSAIList, PRESENCE = optional L:8487
	SI_AMF_DT_OverloadStartNSSAIList * overloadStartNSSAIList;
	int overloadStartNSSAIList_isset;

	
} SI_AMF_DT_PDU_OverloadStart;


// GOT-NULL 
//ELEMENTARY-PROCEDURE = [2] overloadStop  L:8448

typedef struct __si_amf_dt_OverloadStop
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	//:
	
} SI_AMF_DT_PDU_OverloadStop;


//ELEMENTARY-PROCEDURE = [2] uplinkRANConfigurationTransfer  L:8448

typedef struct __si_amf_dt_UplinkRANConfigurationTransfer
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-SONConfigurationTransferUL, PRESENCE = optional L:8487
	SI_AMF_DT_SONConfigurationTransfer * sONConfigurationTransferUL;
	int sONConfigurationTransferUL_isset;

	// ID = id-ENDC-SONConfigurationTransferUL, PRESENCE = optional L:8487
	SI_AMF_DT_EN_DCSONConfigurationTransfer * eNDCSONConfigurationTransferUL;
	int eNDCSONConfigurationTransferUL_isset;

	
} SI_AMF_DT_PDU_UplinkRANConfigurationTransfer;


//ELEMENTARY-PROCEDURE = [2] downlinkRANConfigurationTransfer  L:8448

typedef struct __si_amf_dt_DownlinkRANConfigurationTransfer
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-SONConfigurationTransferDL, PRESENCE = optional L:8487
	SI_AMF_DT_SONConfigurationTransfer * sONConfigurationTransferDL;
	int sONConfigurationTransferDL_isset;

	// ID = id-ENDC-SONConfigurationTransferDL, PRESENCE = optional L:8487
	SI_AMF_DT_EN_DCSONConfigurationTransfer * eNDCSONConfigurationTransferDL;
	int eNDCSONConfigurationTransferDL_isset;

	
} SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer;


//ELEMENTARY-PROCEDURE = [2] writeReplaceWarning  L:8448

typedef struct __si_amf_dt_WriteReplaceWarningRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-MessageIdentifier, PRESENCE = mandatory L:8487
	SI_AMF_DT_MessageIdentifier * messageIdentifier;
	int messageIdentifier_isset;

	// ID = id-SerialNumber, PRESENCE = mandatory L:8487
	SI_AMF_DT_SerialNumber * serialNumber;
	int serialNumber_isset;

	// ID = id-WarningAreaList, PRESENCE = optional L:8487
	SI_AMF_DT_WarningAreaList * warningAreaList;
	int warningAreaList_isset;

	// ID = id-RepetitionPeriod, PRESENCE = mandatory L:8487
	unsigned long long int repetitionPeriod;
	int repetitionPeriod_isset;

	// ID = id-NumberOfBroadcastsRequested, PRESENCE = mandatory L:8487
	unsigned long long int numberOfBroadcastsRequested;
	int numberOfBroadcastsRequested_isset;

	// ID = id-WarningType, PRESENCE = optional L:8487
	SI_AMF_DT_WarningType * warningType;
	int warningType_isset;

	// ID = id-WarningSecurityInfo, PRESENCE = optional L:8487
	SI_AMF_DT_WarningSecurityInfo * warningSecurityInfo;
	int warningSecurityInfo_isset;

	// ID = id-DataCodingScheme, PRESENCE = optional L:8487
	SI_AMF_DT_DataCodingScheme * dataCodingScheme;
	int dataCodingScheme_isset;

	// ID = id-WarningMessageContents, PRESENCE = optional L:8487
	SI_AMF_DT_WarningMessageContents * warningMessageContents;
	int warningMessageContents_isset;

	// ID = id-ConcurrentWarningMessageInd, PRESENCE = optional L:8487
	uint8_t concurrentWarningMessageInd;
	int concurrentWarningMessageInd_isset;

	// ID = id-WarningAreaCoordinates, PRESENCE = optional L:8487
	SI_AMF_DT_WarningAreaCoordinates * warningAreaCoordinates;
	int warningAreaCoordinates_isset;

	
} SI_AMF_DT_PDU_WriteReplaceWarningRequest;


//ELEMENTARY-PROCEDURE = [2] writeReplaceWarning  L:8448

typedef struct __si_amf_dt_WriteReplaceWarningResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-MessageIdentifier, PRESENCE = mandatory L:8487
	SI_AMF_DT_MessageIdentifier * messageIdentifier;
	int messageIdentifier_isset;

	// ID = id-SerialNumber, PRESENCE = mandatory L:8487
	SI_AMF_DT_SerialNumber * serialNumber;
	int serialNumber_isset;

	// ID = id-BroadcastCompletedAreaList, PRESENCE = optional L:8487
	SI_AMF_DT_BroadcastCompletedAreaList * broadcastCompletedAreaList;
	int broadcastCompletedAreaList_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_WriteReplaceWarningResponse;


//ELEMENTARY-PROCEDURE = [2] pWSCancel  L:8448

typedef struct __si_amf_dt_PWSCancelRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-MessageIdentifier, PRESENCE = mandatory L:8487
	SI_AMF_DT_MessageIdentifier * messageIdentifier;
	int messageIdentifier_isset;

	// ID = id-SerialNumber, PRESENCE = mandatory L:8487
	SI_AMF_DT_SerialNumber * serialNumber;
	int serialNumber_isset;

	// ID = id-WarningAreaList, PRESENCE = optional L:8487
	SI_AMF_DT_WarningAreaList * warningAreaList;
	int warningAreaList_isset;

	// ID = id-CancelAllWarningMessages, PRESENCE = optional L:8487
	uint8_t cancelAllWarningMessages;
	int cancelAllWarningMessages_isset;

	
} SI_AMF_DT_PDU_PWSCancelRequest;


//ELEMENTARY-PROCEDURE = [2] pWSCancel  L:8448

typedef struct __si_amf_dt_PWSCancelResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-MessageIdentifier, PRESENCE = mandatory L:8487
	SI_AMF_DT_MessageIdentifier * messageIdentifier;
	int messageIdentifier_isset;

	// ID = id-SerialNumber, PRESENCE = mandatory L:8487
	SI_AMF_DT_SerialNumber * serialNumber;
	int serialNumber_isset;

	// ID = id-BroadcastCancelledAreaList, PRESENCE = optional L:8487
	SI_AMF_DT_BroadcastCancelledAreaList * broadcastCancelledAreaList;
	int broadcastCancelledAreaList_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_PWSCancelResponse;


//ELEMENTARY-PROCEDURE = [2] pWSRestartIndication  L:8448

typedef struct __si_amf_dt_PWSRestartIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-CellIDListForRestart, PRESENCE = mandatory L:8487
	SI_AMF_DT_CellIDListForRestart * cellIDListForRestart;
	int cellIDListForRestart_isset;

	// ID = id-GlobalRANNodeID, PRESENCE = mandatory L:8487
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;
	int globalRANNodeID_isset;

	// ID = id-TAIListForRestart, PRESENCE = mandatory L:8487
	SI_AMF_DT_TAIListForRestart * tAIListForRestart;
	int tAIListForRestart_isset;

	// ID = id-EmergencyAreaIDListForRestart, PRESENCE = optional L:8487
	SI_AMF_DT_EmergencyAreaIDListForRestart * emergencyAreaIDListForRestart;
	int emergencyAreaIDListForRestart_isset;

	
} SI_AMF_DT_PDU_PWSRestartIndication;


//ELEMENTARY-PROCEDURE = [2] pWSFailureIndication  L:8448

typedef struct __si_amf_dt_PWSFailureIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-PWSFailedCellIDList, PRESENCE = mandatory L:8487
	SI_AMF_DT_PWSFailedCellIDList * pWSFailedCellIDList;
	int pWSFailedCellIDList_isset;

	// ID = id-GlobalRANNodeID, PRESENCE = mandatory L:8487
	SI_AMF_DT_GlobalRANNodeID * globalRANNodeID;
	int globalRANNodeID_isset;

	
} SI_AMF_DT_PDU_PWSFailureIndication;


//ELEMENTARY-PROCEDURE = [2] downlinkUEAssociatedNRPPaTransport  L:8448

typedef struct __si_amf_dt_DownlinkUEAssociatedNRPPaTransport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RoutingID, PRESENCE = mandatory L:8487
	SI_AMF_DT_RoutingID * routingID;
	int routingID_isset;

	// ID = id-NRPPa-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NRPPa_PDU * nRPPaPDU;
	int nRPPaPDU_isset;

	
} SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport;


//ELEMENTARY-PROCEDURE = [2] uplinkUEAssociatedNRPPaTransport  L:8448

typedef struct __si_amf_dt_UplinkUEAssociatedNRPPaTransport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-RoutingID, PRESENCE = mandatory L:8487
	SI_AMF_DT_RoutingID * routingID;
	int routingID_isset;

	// ID = id-NRPPa-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NRPPa_PDU * nRPPaPDU;
	int nRPPaPDU_isset;

	
} SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport;


//ELEMENTARY-PROCEDURE = [2] downlinkNonUEAssociatedNRPPaTransport  L:8448

typedef struct __si_amf_dt_DownlinkNonUEAssociatedNRPPaTransport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-RoutingID, PRESENCE = mandatory L:8487
	SI_AMF_DT_RoutingID * routingID;
	int routingID_isset;

	// ID = id-NRPPa-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NRPPa_PDU * nRPPaPDU;
	int nRPPaPDU_isset;

	
} SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport;


//ELEMENTARY-PROCEDURE = [2] uplinkNonUEAssociatedNRPPaTransport  L:8448

typedef struct __si_amf_dt_UplinkNonUEAssociatedNRPPaTransport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-RoutingID, PRESENCE = mandatory L:8487
	SI_AMF_DT_RoutingID * routingID;
	int routingID_isset;

	// ID = id-NRPPa-PDU, PRESENCE = mandatory L:8487
	SI_AMF_DT_NRPPa_PDU * nRPPaPDU;
	int nRPPaPDU_isset;

	
} SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport;


//ELEMENTARY-PROCEDURE = [2] traceStart  L:8448

typedef struct __si_amf_dt_TraceStart
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-TraceActivation, PRESENCE = mandatory L:8487
	SI_AMF_DT_TraceActivation * traceActivation;
	int traceActivation_isset;

	
} SI_AMF_DT_PDU_TraceStart;


//ELEMENTARY-PROCEDURE = [2] traceFailureIndication  L:8448

typedef struct __si_amf_dt_TraceFailureIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-NGRANTraceID, PRESENCE = mandatory L:8487
	SI_AMF_DT_NGRANTraceID * nGRANTraceID;
	int nGRANTraceID_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	
} SI_AMF_DT_PDU_TraceFailureIndication;


//ELEMENTARY-PROCEDURE = [2] deactivateTrace  L:8448

typedef struct __si_amf_dt_DeactivateTrace
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-NGRANTraceID, PRESENCE = mandatory L:8487
	SI_AMF_DT_NGRANTraceID * nGRANTraceID;
	int nGRANTraceID_isset;

	
} SI_AMF_DT_PDU_DeactivateTrace;


//ELEMENTARY-PROCEDURE = [2] cellTrafficTrace  L:8448

typedef struct __si_amf_dt_CellTrafficTrace
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-NGRANTraceID, PRESENCE = mandatory L:8487
	SI_AMF_DT_NGRANTraceID * nGRANTraceID;
	int nGRANTraceID_isset;

	// ID = id-NGRAN-CGI, PRESENCE = mandatory L:8487
	SI_AMF_DT_NGRAN_CGI * nGRANCGI;
	int nGRANCGI_isset;

	// ID = id-TraceCollectionEntityIPAddress, PRESENCE = mandatory L:8487
	SI_AMF_DT_TransportLayerAddress * traceCollectionEntityIPAddress;
	int traceCollectionEntityIPAddress_isset;

	
} SI_AMF_DT_PDU_CellTrafficTrace;


//ELEMENTARY-PROCEDURE = [2] locationReportingControl  L:8448

typedef struct __si_amf_dt_LocationReportingControl
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-LocationReportingRequestType, PRESENCE = mandatory L:8487
	SI_AMF_DT_LocationReportingRequestType * locationReportingRequestType;
	int locationReportingRequestType_isset;

	
} SI_AMF_DT_PDU_LocationReportingControl;


//ELEMENTARY-PROCEDURE = [2] locationReportingFailureIndication  L:8448

typedef struct __si_amf_dt_LocationReportingFailureIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-Cause, PRESENCE = mandatory L:8487
	SI_AMF_DT_Cause * cause;
	int cause_isset;

	
} SI_AMF_DT_PDU_LocationReportingFailureIndication;


//ELEMENTARY-PROCEDURE = [2] locationReport  L:8448

typedef struct __si_amf_dt_LocationReport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-UserLocationInformation, PRESENCE = mandatory L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	// ID = id-UEPresenceInAreaOfInterestList, PRESENCE = optional L:8487
	SI_AMF_DT_UEPresenceInAreaOfInterestList * uEPresenceInAreaOfInterestList;
	int uEPresenceInAreaOfInterestList_isset;

	// ID = id-LocationReportingRequestType, PRESENCE = mandatory L:8487
	SI_AMF_DT_LocationReportingRequestType * locationReportingRequestType;
	int locationReportingRequestType_isset;

	
} SI_AMF_DT_PDU_LocationReport;


//ELEMENTARY-PROCEDURE = [2] uETNLABindingRelease  L:8448

typedef struct __si_amf_dt_UETNLABindingReleaseRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	
} SI_AMF_DT_PDU_UETNLABindingReleaseRequest;


//ELEMENTARY-PROCEDURE = [2] uERadioCapabilityInfoIndication  L:8448

typedef struct __si_amf_dt_UERadioCapabilityInfoIndication
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-UERadioCapability, PRESENCE = mandatory L:8487
	SI_AMF_DT_UERadioCapability * uERadioCapability;
	int uERadioCapability_isset;

	// ID = id-UERadioCapabilityForPaging, PRESENCE = optional L:8487
	SI_AMF_DT_UERadioCapabilityForPaging * uERadioCapabilityForPaging;
	int uERadioCapabilityForPaging_isset;

	
} SI_AMF_DT_PDU_UERadioCapabilityInfoIndication;


//ELEMENTARY-PROCEDURE = [2] uERadioCapabilityCheck  L:8448

typedef struct __si_amf_dt_UERadioCapabilityCheckRequest
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-UERadioCapability, PRESENCE = optional L:8487
	SI_AMF_DT_UERadioCapability * uERadioCapability;
	int uERadioCapability_isset;

	
} SI_AMF_DT_PDU_UERadioCapabilityCheckRequest;


//ELEMENTARY-PROCEDURE = [2] uERadioCapabilityCheck  L:8448

typedef struct __si_amf_dt_UERadioCapabilityCheckResponse
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-IMSVoiceSupportIndicator, PRESENCE = mandatory L:8487
	uint8_t iMSVoiceSupportIndicator;
	int iMSVoiceSupportIndicator_isset;

	// ID = id-CriticalityDiagnostics, PRESENCE = optional L:8487
	SI_AMF_DT_CriticalityDiagnostics * criticalityDiagnostics;
	int criticalityDiagnostics_isset;

	
} SI_AMF_DT_PDU_UERadioCapabilityCheckResponse;


//ELEMENTARY-PROCEDURE = [2] privateMessage  L:8448

typedef struct __si_amf_dt_PrivateMessage
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	//:
	
} SI_AMF_DT_PDU_PrivateMessage;


//ELEMENTARY-PROCEDURE = [2] secondaryRATDataUsageReport  L:8448

typedef struct __si_amf_dt_SecondaryRATDataUsageReport
{
	uint8_t pduIEExtension;
	uint8_t pduMessageChoice;
	uint8_t messageId;
	uint8_t * transportObject;
	uint16_t iECount;
	uint8_t decodingError;

	// ID = id-AMF-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int aMFUENGAPID;
	int aMFUENGAPID_isset;

	// ID = id-RAN-UE-NGAP-ID, PRESENCE = mandatory L:8487
	unsigned long long int rANUENGAPID;
	int rANUENGAPID_isset;

	// ID = id-PDUSessionResourceSecondaryRATUsageList, PRESENCE = mandatory L:8487
	SI_AMF_DT_PDUSessionResourceSecondaryRATUsageList * pDUSessionResourceSecondaryRATUsageList;
	int pDUSessionResourceSecondaryRATUsageList_isset;

	// ID = id-HandoverFlag, PRESENCE = optional L:8487
	uint8_t handoverFlag;
	int handoverFlag_isset;

	// ID = id-UserLocationInformation, PRESENCE = optional L:8487
	SI_AMF_DT_UserLocationInformation * userLocationInformation;
	int userLocationInformation_isset;

	
} SI_AMF_DT_PDU_SecondaryRATDataUsageReport;


void __si_amf_debug_pdu( uint8_t * buffer, int len);


// ELEMENTARY-PROCEDURE = [0] aMFConfigurationUpdate  L:6944
// ProcedureCode = 0
// ProcedureCodeName = id-AMFConfigurationUpdate
// Criticality = reject

int __si_amf_encode_pdu_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objPDUAMFConfigurationUpdate, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objPDUAMFConfigurationUpdate, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objPDUAMFConfigurationUpdate);

int __si_amf_memfree_pdu_AMFConfigurationUpdate( SI_AMF_DT_PDU_AMFConfigurationUpdate * objPDUAMFConfigurationUpdate);



// ELEMENTARY-PROCEDURE = [0] aMFConfigurationUpdate  L:6944
// ProcedureCode = 0
// ProcedureCodeName = id-AMFConfigurationUpdate
// Criticality = reject

int __si_amf_encode_pdu_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objPDUAMFConfigurationUpdateAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objPDUAMFConfigurationUpdateAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objPDUAMFConfigurationUpdateAcknowledge);

int __si_amf_memfree_pdu_AMFConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_AMFConfigurationUpdateAcknowledge * objPDUAMFConfigurationUpdateAcknowledge);



// ELEMENTARY-PROCEDURE = [0] aMFConfigurationUpdate  L:6944
// ProcedureCode = 0
// ProcedureCodeName = id-AMFConfigurationUpdate
// Criticality = reject

int __si_amf_encode_pdu_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objPDUAMFConfigurationUpdateFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objPDUAMFConfigurationUpdateFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objPDUAMFConfigurationUpdateFailure);

int __si_amf_memfree_pdu_AMFConfigurationUpdateFailure( SI_AMF_DT_PDU_AMFConfigurationUpdateFailure * objPDUAMFConfigurationUpdateFailure);



// ELEMENTARY-PROCEDURE = [0] aMFStatusIndication  L:6944
// ProcedureCode = 1
// ProcedureCodeName = id-AMFStatusIndication
// Criticality = ignore

int __si_amf_encode_pdu_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objPDUAMFStatusIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objPDUAMFStatusIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objPDUAMFStatusIndication);

int __si_amf_memfree_pdu_AMFStatusIndication( SI_AMF_DT_PDU_AMFStatusIndication * objPDUAMFStatusIndication);



// ELEMENTARY-PROCEDURE = [0] cellTrafficTrace  L:6944
// ProcedureCode = 2
// ProcedureCodeName = id-CellTrafficTrace
// Criticality = ignore

int __si_amf_encode_pdu_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objPDUCellTrafficTrace, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objPDUCellTrafficTrace, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objPDUCellTrafficTrace);

int __si_amf_memfree_pdu_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objPDUCellTrafficTrace);



// ELEMENTARY-PROCEDURE = [0] deactivateTrace  L:6944
// ProcedureCode = 3
// ProcedureCodeName = id-DeactivateTrace
// Criticality = ignore

int __si_amf_encode_pdu_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objPDUDeactivateTrace, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objPDUDeactivateTrace, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objPDUDeactivateTrace);

int __si_amf_memfree_pdu_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objPDUDeactivateTrace);



// ELEMENTARY-PROCEDURE = [0] downlinkNASTransport  L:6944
// ProcedureCode = 4
// ProcedureCodeName = id-DownlinkNASTransport
// Criticality = ignore

int __si_amf_encode_pdu_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objPDUDownlinkNASTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objPDUDownlinkNASTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objPDUDownlinkNASTransport);

int __si_amf_memfree_pdu_DownlinkNASTransport( SI_AMF_DT_PDU_DownlinkNASTransport * objPDUDownlinkNASTransport);



// ELEMENTARY-PROCEDURE = [0] downlinkNonUEAssociatedNRPPaTransport  L:6944
// ProcedureCode = 5
// ProcedureCodeName = id-DownlinkNonUEAssociatedNRPPaTransport
// Criticality = ignore

int __si_amf_encode_pdu_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objPDUDownlinkNonUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objPDUDownlinkNonUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objPDUDownlinkNonUEAssociatedNRPPaTransport);

int __si_amf_memfree_pdu_DownlinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkNonUEAssociatedNRPPaTransport * objPDUDownlinkNonUEAssociatedNRPPaTransport);



// ELEMENTARY-PROCEDURE = [0] downlinkRANConfigurationTransfer  L:6944
// ProcedureCode = 6
// ProcedureCodeName = id-DownlinkRANConfigurationTransfer
// Criticality = ignore

int __si_amf_encode_pdu_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objPDUDownlinkRANConfigurationTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objPDUDownlinkRANConfigurationTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objPDUDownlinkRANConfigurationTransfer);

int __si_amf_memfree_pdu_DownlinkRANConfigurationTransfer( SI_AMF_DT_PDU_DownlinkRANConfigurationTransfer * objPDUDownlinkRANConfigurationTransfer);



// ELEMENTARY-PROCEDURE = [0] downlinkRANStatusTransfer  L:6944
// ProcedureCode = 7
// ProcedureCodeName = id-DownlinkRANStatusTransfer
// Criticality = ignore

int __si_amf_encode_pdu_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objPDUDownlinkRANStatusTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objPDUDownlinkRANStatusTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objPDUDownlinkRANStatusTransfer);

int __si_amf_memfree_pdu_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objPDUDownlinkRANStatusTransfer);



// ELEMENTARY-PROCEDURE = [0] downlinkUEAssociatedNRPPaTransport  L:6944
// ProcedureCode = 8
// ProcedureCodeName = id-DownlinkUEAssociatedNRPPaTransport
// Criticality = ignore

int __si_amf_encode_pdu_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objPDUDownlinkUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objPDUDownlinkUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objPDUDownlinkUEAssociatedNRPPaTransport);

int __si_amf_memfree_pdu_DownlinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_DownlinkUEAssociatedNRPPaTransport * objPDUDownlinkUEAssociatedNRPPaTransport);



// ELEMENTARY-PROCEDURE = [0] errorIndication  L:6944
// ProcedureCode = 9
// ProcedureCodeName = id-ErrorIndication
// Criticality = ignore

int __si_amf_encode_pdu_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objPDUErrorIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objPDUErrorIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objPDUErrorIndication);

int __si_amf_memfree_pdu_ErrorIndication( SI_AMF_DT_PDU_ErrorIndication * objPDUErrorIndication);



// ELEMENTARY-PROCEDURE = [0] handoverCancel  L:6944
// ProcedureCode = 10
// ProcedureCodeName = id-HandoverCancel
// Criticality = reject

int __si_amf_encode_pdu_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objPDUHandoverCancel, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objPDUHandoverCancel, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objPDUHandoverCancel);

int __si_amf_memfree_pdu_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objPDUHandoverCancel);



// ELEMENTARY-PROCEDURE = [0] handoverCancel  L:6944
// ProcedureCode = 10
// ProcedureCodeName = id-HandoverCancel
// Criticality = reject

int __si_amf_encode_pdu_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objPDUHandoverCancelAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objPDUHandoverCancelAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objPDUHandoverCancelAcknowledge);

int __si_amf_memfree_pdu_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objPDUHandoverCancelAcknowledge);



// ELEMENTARY-PROCEDURE = [0] handoverNotification  L:6944
// ProcedureCode = 11
// ProcedureCodeName = id-HandoverNotification
// Criticality = ignore

int __si_amf_encode_pdu_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objPDUHandoverNotify, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objPDUHandoverNotify, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objPDUHandoverNotify);

int __si_amf_memfree_pdu_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objPDUHandoverNotify);



// ELEMENTARY-PROCEDURE = [0] handoverPreparation  L:6944
// ProcedureCode = 12
// ProcedureCodeName = id-HandoverPreparation
// Criticality = reject

int __si_amf_encode_pdu_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objPDUHandoverRequired, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objPDUHandoverRequired, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objPDUHandoverRequired);

int __si_amf_memfree_pdu_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objPDUHandoverRequired);



// ELEMENTARY-PROCEDURE = [0] handoverPreparation  L:6944
// ProcedureCode = 12
// ProcedureCodeName = id-HandoverPreparation
// Criticality = reject

int __si_amf_encode_pdu_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objPDUHandoverCommand, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objPDUHandoverCommand, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objPDUHandoverCommand);

int __si_amf_memfree_pdu_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objPDUHandoverCommand);



// ELEMENTARY-PROCEDURE = [0] handoverPreparation  L:6944
// ProcedureCode = 12
// ProcedureCodeName = id-HandoverPreparation
// Criticality = reject

int __si_amf_encode_pdu_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objPDUHandoverPreparationFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objPDUHandoverPreparationFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objPDUHandoverPreparationFailure);

int __si_amf_memfree_pdu_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objPDUHandoverPreparationFailure);



// ELEMENTARY-PROCEDURE = [0] handoverResourceAllocation  L:6944
// ProcedureCode = 13
// ProcedureCodeName = id-HandoverResourceAllocation
// Criticality = reject

int __si_amf_encode_pdu_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objPDUHandoverRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objPDUHandoverRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objPDUHandoverRequest);

int __si_amf_memfree_pdu_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objPDUHandoverRequest);



// ELEMENTARY-PROCEDURE = [0] handoverResourceAllocation  L:6944
// ProcedureCode = 13
// ProcedureCodeName = id-HandoverResourceAllocation
// Criticality = reject

int __si_amf_encode_pdu_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objPDUHandoverRequestAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objPDUHandoverRequestAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objPDUHandoverRequestAcknowledge);

int __si_amf_memfree_pdu_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objPDUHandoverRequestAcknowledge);



// ELEMENTARY-PROCEDURE = [0] handoverResourceAllocation  L:6944
// ProcedureCode = 13
// ProcedureCodeName = id-HandoverResourceAllocation
// Criticality = reject

int __si_amf_encode_pdu_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objPDUHandoverFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objPDUHandoverFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objPDUHandoverFailure);

int __si_amf_memfree_pdu_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objPDUHandoverFailure);



// ELEMENTARY-PROCEDURE = [0] initialContextSetup  L:6944
// ProcedureCode = 14
// ProcedureCodeName = id-InitialContextSetup
// Criticality = reject

int __si_amf_encode_pdu_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objPDUInitialContextSetupRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objPDUInitialContextSetupRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objPDUInitialContextSetupRequest);

int __si_amf_memfree_pdu_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objPDUInitialContextSetupRequest);



// ELEMENTARY-PROCEDURE = [0] initialContextSetup  L:6944
// ProcedureCode = 14
// ProcedureCodeName = id-InitialContextSetup
// Criticality = reject

int __si_amf_encode_pdu_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objPDUInitialContextSetupResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objPDUInitialContextSetupResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objPDUInitialContextSetupResponse);

int __si_amf_memfree_pdu_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objPDUInitialContextSetupResponse);



// ELEMENTARY-PROCEDURE = [0] initialContextSetup  L:6944
// ProcedureCode = 14
// ProcedureCodeName = id-InitialContextSetup
// Criticality = reject

int __si_amf_encode_pdu_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objPDUInitialContextSetupFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objPDUInitialContextSetupFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objPDUInitialContextSetupFailure);

int __si_amf_memfree_pdu_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objPDUInitialContextSetupFailure);



// ELEMENTARY-PROCEDURE = [0] initialUEMessage  L:6944
// ProcedureCode = 15
// ProcedureCodeName = id-InitialUEMessage
// Criticality = ignore

int __si_amf_encode_pdu_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objPDUInitialUEMessage, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objPDUInitialUEMessage, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objPDUInitialUEMessage);

int __si_amf_memfree_pdu_InitialUEMessage( SI_AMF_DT_PDU_InitialUEMessage * objPDUInitialUEMessage);



// ELEMENTARY-PROCEDURE = [0] locationReport  L:6944
// ProcedureCode = 18
// ProcedureCodeName = id-LocationReport
// Criticality = ignore

int __si_amf_encode_pdu_LocationReport( SI_AMF_DT_PDU_LocationReport * objPDULocationReport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_LocationReport( SI_AMF_DT_PDU_LocationReport * objPDULocationReport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_LocationReport( SI_AMF_DT_PDU_LocationReport * objPDULocationReport);

int __si_amf_memfree_pdu_LocationReport( SI_AMF_DT_PDU_LocationReport * objPDULocationReport);



// ELEMENTARY-PROCEDURE = [0] locationReportingControl  L:6944
// ProcedureCode = 16
// ProcedureCodeName = id-LocationReportingControl
// Criticality = ignore

int __si_amf_encode_pdu_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objPDULocationReportingControl, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objPDULocationReportingControl, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objPDULocationReportingControl);

int __si_amf_memfree_pdu_LocationReportingControl( SI_AMF_DT_PDU_LocationReportingControl * objPDULocationReportingControl);



// ELEMENTARY-PROCEDURE = [0] locationReportingFailureIndication  L:6944
// ProcedureCode = 17
// ProcedureCodeName = id-LocationReportingFailureIndication
// Criticality = ignore

int __si_amf_encode_pdu_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objPDULocationReportingFailureIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objPDULocationReportingFailureIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objPDULocationReportingFailureIndication);

int __si_amf_memfree_pdu_LocationReportingFailureIndication( SI_AMF_DT_PDU_LocationReportingFailureIndication * objPDULocationReportingFailureIndication);



// ELEMENTARY-PROCEDURE = [0] nASNonDeliveryIndication  L:6944
// ProcedureCode = 19
// ProcedureCodeName = id-NASNonDeliveryIndication
// Criticality = ignore

int __si_amf_encode_pdu_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objPDUNASNonDeliveryIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objPDUNASNonDeliveryIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objPDUNASNonDeliveryIndication);

int __si_amf_memfree_pdu_NASNonDeliveryIndication( SI_AMF_DT_PDU_NASNonDeliveryIndication * objPDUNASNonDeliveryIndication);



// ELEMENTARY-PROCEDURE = [0] nGReset  L:6944
// ProcedureCode = 20
// ProcedureCodeName = id-NGReset
// Criticality = reject

int __si_amf_encode_pdu_NGReset( SI_AMF_DT_PDU_NGReset * objPDUNGReset, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_NGReset( SI_AMF_DT_PDU_NGReset * objPDUNGReset, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_NGReset( SI_AMF_DT_PDU_NGReset * objPDUNGReset);

int __si_amf_memfree_pdu_NGReset( SI_AMF_DT_PDU_NGReset * objPDUNGReset);



// ELEMENTARY-PROCEDURE = [0] nGReset  L:6944
// ProcedureCode = 20
// ProcedureCodeName = id-NGReset
// Criticality = reject

int __si_amf_encode_pdu_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objPDUNGResetAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objPDUNGResetAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objPDUNGResetAcknowledge);

int __si_amf_memfree_pdu_NGResetAcknowledge( SI_AMF_DT_PDU_NGResetAcknowledge * objPDUNGResetAcknowledge);



// ELEMENTARY-PROCEDURE = [0] nGSetup  L:6944
// ProcedureCode = 21
// ProcedureCodeName = id-NGSetup
// Criticality = reject

int __si_amf_encode_pdu_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objPDUNGSetupRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objPDUNGSetupRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objPDUNGSetupRequest);

int __si_amf_memfree_pdu_NGSetupRequest( SI_AMF_DT_PDU_NGSetupRequest * objPDUNGSetupRequest);



// ELEMENTARY-PROCEDURE = [0] nGSetup  L:6944
// ProcedureCode = 21
// ProcedureCodeName = id-NGSetup
// Criticality = reject

int __si_amf_encode_pdu_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objPDUNGSetupResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objPDUNGSetupResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objPDUNGSetupResponse);

int __si_amf_memfree_pdu_NGSetupResponse( SI_AMF_DT_PDU_NGSetupResponse * objPDUNGSetupResponse);



// ELEMENTARY-PROCEDURE = [0] nGSetup  L:6944
// ProcedureCode = 21
// ProcedureCodeName = id-NGSetup
// Criticality = reject

int __si_amf_encode_pdu_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objPDUNGSetupFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objPDUNGSetupFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objPDUNGSetupFailure);

int __si_amf_memfree_pdu_NGSetupFailure( SI_AMF_DT_PDU_NGSetupFailure * objPDUNGSetupFailure);



// ELEMENTARY-PROCEDURE = [0] overloadStart  L:6944
// ProcedureCode = 22
// ProcedureCodeName = id-OverloadStart
// Criticality = ignore

int __si_amf_encode_pdu_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objPDUOverloadStart, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objPDUOverloadStart, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objPDUOverloadStart);

int __si_amf_memfree_pdu_OverloadStart( SI_AMF_DT_PDU_OverloadStart * objPDUOverloadStart);



// ELEMENTARY-PROCEDURE = [0] overloadStop  L:6944
// ProcedureCode = 23
// ProcedureCodeName = id-OverloadStop
// Criticality = reject

int __si_amf_encode_pdu_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objPDUOverloadStop, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objPDUOverloadStop, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objPDUOverloadStop);

int __si_amf_memfree_pdu_OverloadStop( SI_AMF_DT_PDU_OverloadStop * objPDUOverloadStop);



// ELEMENTARY-PROCEDURE = [0] paging  L:6944
// ProcedureCode = 24
// ProcedureCodeName = id-Paging
// Criticality = ignore

int __si_amf_encode_pdu_Paging( SI_AMF_DT_PDU_Paging * objPDUPaging, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_Paging( SI_AMF_DT_PDU_Paging * objPDUPaging, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_Paging( SI_AMF_DT_PDU_Paging * objPDUPaging);

int __si_amf_memfree_pdu_Paging( SI_AMF_DT_PDU_Paging * objPDUPaging);



// ELEMENTARY-PROCEDURE = [0] pathSwitchRequest  L:6944
// ProcedureCode = 25
// ProcedureCodeName = id-PathSwitchRequest
// Criticality = reject

int __si_amf_encode_pdu_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPDUPathSwitchRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPDUPathSwitchRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPDUPathSwitchRequest);

int __si_amf_memfree_pdu_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPDUPathSwitchRequest);



// ELEMENTARY-PROCEDURE = [0] pathSwitchRequest  L:6944
// ProcedureCode = 25
// ProcedureCodeName = id-PathSwitchRequest
// Criticality = reject

int __si_amf_encode_pdu_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPDUPathSwitchRequestAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPDUPathSwitchRequestAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPDUPathSwitchRequestAcknowledge);

int __si_amf_memfree_pdu_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPDUPathSwitchRequestAcknowledge);



// ELEMENTARY-PROCEDURE = [0] pathSwitchRequest  L:6944
// ProcedureCode = 25
// ProcedureCodeName = id-PathSwitchRequest
// Criticality = reject

int __si_amf_encode_pdu_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPDUPathSwitchRequestFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPDUPathSwitchRequestFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPDUPathSwitchRequestFailure);

int __si_amf_memfree_pdu_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPDUPathSwitchRequestFailure);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceModify  L:6944
// ProcedureCode = 26
// ProcedureCodeName = id-PDUSessionResourceModify
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUPDUSessionResourceModifyRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUPDUSessionResourceModifyRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUPDUSessionResourceModifyRequest);

int __si_amf_memfree_pdu_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUPDUSessionResourceModifyRequest);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceModify  L:6944
// ProcedureCode = 26
// ProcedureCodeName = id-PDUSessionResourceModify
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUPDUSessionResourceModifyResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUPDUSessionResourceModifyResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUPDUSessionResourceModifyResponse);

int __si_amf_memfree_pdu_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUPDUSessionResourceModifyResponse);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceModifyIndication  L:6944
// ProcedureCode = 27
// ProcedureCodeName = id-PDUSessionResourceModifyIndication
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUPDUSessionResourceModifyIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUPDUSessionResourceModifyIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUPDUSessionResourceModifyIndication);

int __si_amf_memfree_pdu_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUPDUSessionResourceModifyIndication);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceModifyIndication  L:6944
// ProcedureCode = 27
// ProcedureCodeName = id-PDUSessionResourceModifyIndication
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUPDUSessionResourceModifyConfirm, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUPDUSessionResourceModifyConfirm, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUPDUSessionResourceModifyConfirm);

int __si_amf_memfree_pdu_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUPDUSessionResourceModifyConfirm);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceNotify  L:6944
// ProcedureCode = 30
// ProcedureCodeName = id-PDUSessionResourceNotify
// Criticality = ignore

int __si_amf_encode_pdu_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUPDUSessionResourceNotify, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUPDUSessionResourceNotify, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUPDUSessionResourceNotify);

int __si_amf_memfree_pdu_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUPDUSessionResourceNotify);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceRelease  L:6944
// ProcedureCode = 28
// ProcedureCodeName = id-PDUSessionResourceRelease
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUPDUSessionResourceReleaseCommand, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUPDUSessionResourceReleaseCommand, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUPDUSessionResourceReleaseCommand);

int __si_amf_memfree_pdu_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUPDUSessionResourceReleaseCommand);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceRelease  L:6944
// ProcedureCode = 28
// ProcedureCodeName = id-PDUSessionResourceRelease
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUPDUSessionResourceReleaseResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUPDUSessionResourceReleaseResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUPDUSessionResourceReleaseResponse);

int __si_amf_memfree_pdu_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUPDUSessionResourceReleaseResponse);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceSetup  L:6944
// ProcedureCode = 29
// ProcedureCodeName = id-PDUSessionResourceSetup
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUPDUSessionResourceSetupRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUPDUSessionResourceSetupRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUPDUSessionResourceSetupRequest);

int __si_amf_memfree_pdu_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUPDUSessionResourceSetupRequest);



// ELEMENTARY-PROCEDURE = [0] pDUSessionResourceSetup  L:6944
// ProcedureCode = 29
// ProcedureCodeName = id-PDUSessionResourceSetup
// Criticality = reject

int __si_amf_encode_pdu_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUPDUSessionResourceSetupResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUPDUSessionResourceSetupResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUPDUSessionResourceSetupResponse);

int __si_amf_memfree_pdu_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUPDUSessionResourceSetupResponse);



// ELEMENTARY-PROCEDURE = [0] privateMessage  L:6944
// ProcedureCode = 31
// ProcedureCodeName = id-PrivateMessage
// Criticality = ignore

int __si_amf_encode_pdu_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPDUPrivateMessage, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPDUPrivateMessage, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPDUPrivateMessage);

int __si_amf_memfree_pdu_PrivateMessage( SI_AMF_DT_PDU_PrivateMessage * objPDUPrivateMessage);



// ELEMENTARY-PROCEDURE = [0] pWSCancel  L:6944
// ProcedureCode = 32
// ProcedureCodeName = id-PWSCancel
// Criticality = reject

int __si_amf_encode_pdu_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPDUPWSCancelRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPDUPWSCancelRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPDUPWSCancelRequest);

int __si_amf_memfree_pdu_PWSCancelRequest( SI_AMF_DT_PDU_PWSCancelRequest * objPDUPWSCancelRequest);



// ELEMENTARY-PROCEDURE = [0] pWSCancel  L:6944
// ProcedureCode = 32
// ProcedureCodeName = id-PWSCancel
// Criticality = reject

int __si_amf_encode_pdu_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPDUPWSCancelResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPDUPWSCancelResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPDUPWSCancelResponse);

int __si_amf_memfree_pdu_PWSCancelResponse( SI_AMF_DT_PDU_PWSCancelResponse * objPDUPWSCancelResponse);



// ELEMENTARY-PROCEDURE = [0] pWSFailureIndication  L:6944
// ProcedureCode = 33
// ProcedureCodeName = id-PWSFailureIndication
// Criticality = ignore

int __si_amf_encode_pdu_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPDUPWSFailureIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPDUPWSFailureIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPDUPWSFailureIndication);

int __si_amf_memfree_pdu_PWSFailureIndication( SI_AMF_DT_PDU_PWSFailureIndication * objPDUPWSFailureIndication);



// ELEMENTARY-PROCEDURE = [0] pWSRestartIndication  L:6944
// ProcedureCode = 34
// ProcedureCodeName = id-PWSRestartIndication
// Criticality = ignore

int __si_amf_encode_pdu_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPDUPWSRestartIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPDUPWSRestartIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPDUPWSRestartIndication);

int __si_amf_memfree_pdu_PWSRestartIndication( SI_AMF_DT_PDU_PWSRestartIndication * objPDUPWSRestartIndication);



// ELEMENTARY-PROCEDURE = [0] rANConfigurationUpdate  L:6944
// ProcedureCode = 35
// ProcedureCodeName = id-RANConfigurationUpdate
// Criticality = reject

int __si_amf_encode_pdu_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objPDURANConfigurationUpdate, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objPDURANConfigurationUpdate, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objPDURANConfigurationUpdate);

int __si_amf_memfree_pdu_RANConfigurationUpdate( SI_AMF_DT_PDU_RANConfigurationUpdate * objPDURANConfigurationUpdate);



// ELEMENTARY-PROCEDURE = [0] rANConfigurationUpdate  L:6944
// ProcedureCode = 35
// ProcedureCodeName = id-RANConfigurationUpdate
// Criticality = reject

int __si_amf_encode_pdu_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objPDURANConfigurationUpdateAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objPDURANConfigurationUpdateAcknowledge, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objPDURANConfigurationUpdateAcknowledge);

int __si_amf_memfree_pdu_RANConfigurationUpdateAcknowledge( SI_AMF_DT_PDU_RANConfigurationUpdateAcknowledge * objPDURANConfigurationUpdateAcknowledge);



// ELEMENTARY-PROCEDURE = [0] rANConfigurationUpdate  L:6944
// ProcedureCode = 35
// ProcedureCodeName = id-RANConfigurationUpdate
// Criticality = reject

int __si_amf_encode_pdu_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objPDURANConfigurationUpdateFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objPDURANConfigurationUpdateFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objPDURANConfigurationUpdateFailure);

int __si_amf_memfree_pdu_RANConfigurationUpdateFailure( SI_AMF_DT_PDU_RANConfigurationUpdateFailure * objPDURANConfigurationUpdateFailure);



// ELEMENTARY-PROCEDURE = [0] rerouteNASRequest  L:6944
// ProcedureCode = 36
// ProcedureCodeName = id-RerouteNASRequest
// Criticality = reject

int __si_amf_encode_pdu_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objPDURerouteNASRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objPDURerouteNASRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objPDURerouteNASRequest);

int __si_amf_memfree_pdu_RerouteNASRequest( SI_AMF_DT_PDU_RerouteNASRequest * objPDURerouteNASRequest);



// ELEMENTARY-PROCEDURE = [0] rRCInactiveTransitionReport  L:6944
// ProcedureCode = 37
// ProcedureCodeName = id-RRCInactiveTransitionReport
// Criticality = ignore

int __si_amf_encode_pdu_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objPDURRCInactiveTransitionReport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objPDURRCInactiveTransitionReport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objPDURRCInactiveTransitionReport);

int __si_amf_memfree_pdu_RRCInactiveTransitionReport( SI_AMF_DT_PDU_RRCInactiveTransitionReport * objPDURRCInactiveTransitionReport);



// ELEMENTARY-PROCEDURE = [0] secondaryRATDataUsageReport  L:6944
// ProcedureCode = 52
// ProcedureCodeName = id-SecondaryRATDataUsageReport
// Criticality = ignore

int __si_amf_encode_pdu_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objPDUSecondaryRATDataUsageReport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objPDUSecondaryRATDataUsageReport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objPDUSecondaryRATDataUsageReport);

int __si_amf_memfree_pdu_SecondaryRATDataUsageReport( SI_AMF_DT_PDU_SecondaryRATDataUsageReport * objPDUSecondaryRATDataUsageReport);



// ELEMENTARY-PROCEDURE = [0] traceFailureIndication  L:6944
// ProcedureCode = 38
// ProcedureCodeName = id-TraceFailureIndication
// Criticality = ignore

int __si_amf_encode_pdu_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objPDUTraceFailureIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objPDUTraceFailureIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objPDUTraceFailureIndication);

int __si_amf_memfree_pdu_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objPDUTraceFailureIndication);



// ELEMENTARY-PROCEDURE = [0] traceStart  L:6944
// ProcedureCode = 39
// ProcedureCodeName = id-TraceStart
// Criticality = ignore

int __si_amf_encode_pdu_TraceStart( SI_AMF_DT_PDU_TraceStart * objPDUTraceStart, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_TraceStart( SI_AMF_DT_PDU_TraceStart * objPDUTraceStart, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_TraceStart( SI_AMF_DT_PDU_TraceStart * objPDUTraceStart);

int __si_amf_memfree_pdu_TraceStart( SI_AMF_DT_PDU_TraceStart * objPDUTraceStart);



// ELEMENTARY-PROCEDURE = [0] uEContextModification  L:6944
// ProcedureCode = 40
// ProcedureCodeName = id-UEContextModification
// Criticality = reject

int __si_amf_encode_pdu_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objPDUUEContextModificationRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objPDUUEContextModificationRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objPDUUEContextModificationRequest);

int __si_amf_memfree_pdu_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objPDUUEContextModificationRequest);



// ELEMENTARY-PROCEDURE = [0] uEContextModification  L:6944
// ProcedureCode = 40
// ProcedureCodeName = id-UEContextModification
// Criticality = reject

int __si_amf_encode_pdu_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objPDUUEContextModificationResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objPDUUEContextModificationResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objPDUUEContextModificationResponse);

int __si_amf_memfree_pdu_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objPDUUEContextModificationResponse);



// ELEMENTARY-PROCEDURE = [0] uEContextModification  L:6944
// ProcedureCode = 40
// ProcedureCodeName = id-UEContextModification
// Criticality = reject

int __si_amf_encode_pdu_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objPDUUEContextModificationFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objPDUUEContextModificationFailure, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objPDUUEContextModificationFailure);

int __si_amf_memfree_pdu_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objPDUUEContextModificationFailure);



// ELEMENTARY-PROCEDURE = [0] uEContextRelease  L:6944
// ProcedureCode = 41
// ProcedureCodeName = id-UEContextRelease
// Criticality = reject

int __si_amf_encode_pdu_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objPDUUEContextReleaseCommand, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objPDUUEContextReleaseCommand, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objPDUUEContextReleaseCommand);

int __si_amf_memfree_pdu_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objPDUUEContextReleaseCommand);



// ELEMENTARY-PROCEDURE = [0] uEContextRelease  L:6944
// ProcedureCode = 41
// ProcedureCodeName = id-UEContextRelease
// Criticality = reject

int __si_amf_encode_pdu_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objPDUUEContextReleaseComplete, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objPDUUEContextReleaseComplete, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objPDUUEContextReleaseComplete);

int __si_amf_memfree_pdu_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objPDUUEContextReleaseComplete);



// ELEMENTARY-PROCEDURE = [0] uEContextReleaseRequest  L:6944
// ProcedureCode = 42
// ProcedureCodeName = id-UEContextReleaseRequest
// Criticality = ignore

int __si_amf_encode_pdu_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objPDUUEContextReleaseRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objPDUUEContextReleaseRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objPDUUEContextReleaseRequest);

int __si_amf_memfree_pdu_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objPDUUEContextReleaseRequest);



// ELEMENTARY-PROCEDURE = [0] uERadioCapabilityCheck  L:6944
// ProcedureCode = 43
// ProcedureCodeName = id-UERadioCapabilityCheck
// Criticality = reject

int __si_amf_encode_pdu_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objPDUUERadioCapabilityCheckRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objPDUUERadioCapabilityCheckRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objPDUUERadioCapabilityCheckRequest);

int __si_amf_memfree_pdu_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objPDUUERadioCapabilityCheckRequest);



// ELEMENTARY-PROCEDURE = [0] uERadioCapabilityCheck  L:6944
// ProcedureCode = 43
// ProcedureCodeName = id-UERadioCapabilityCheck
// Criticality = reject

int __si_amf_encode_pdu_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objPDUUERadioCapabilityCheckResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objPDUUERadioCapabilityCheckResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objPDUUERadioCapabilityCheckResponse);

int __si_amf_memfree_pdu_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objPDUUERadioCapabilityCheckResponse);



// ELEMENTARY-PROCEDURE = [0] uERadioCapabilityInfoIndication  L:6944
// ProcedureCode = 44
// ProcedureCodeName = id-UERadioCapabilityInfoIndication
// Criticality = ignore

int __si_amf_encode_pdu_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objPDUUERadioCapabilityInfoIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objPDUUERadioCapabilityInfoIndication, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objPDUUERadioCapabilityInfoIndication);

int __si_amf_memfree_pdu_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objPDUUERadioCapabilityInfoIndication);



// ELEMENTARY-PROCEDURE = [0] uETNLABindingRelease  L:6944
// ProcedureCode = 45
// ProcedureCodeName = id-UETNLABindingRelease
// Criticality = ignore

int __si_amf_encode_pdu_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objPDUUETNLABindingReleaseRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objPDUUETNLABindingReleaseRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objPDUUETNLABindingReleaseRequest);

int __si_amf_memfree_pdu_UETNLABindingReleaseRequest( SI_AMF_DT_PDU_UETNLABindingReleaseRequest * objPDUUETNLABindingReleaseRequest);



// ELEMENTARY-PROCEDURE = [0] uplinkNASTransport  L:6944
// ProcedureCode = 46
// ProcedureCodeName = id-UplinkNASTransport
// Criticality = ignore

int __si_amf_encode_pdu_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objPDUUplinkNASTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objPDUUplinkNASTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objPDUUplinkNASTransport);

int __si_amf_memfree_pdu_UplinkNASTransport( SI_AMF_DT_PDU_UplinkNASTransport * objPDUUplinkNASTransport);



// ELEMENTARY-PROCEDURE = [0] uplinkNonUEAssociatedNRPPaTransport  L:6944
// ProcedureCode = 47
// ProcedureCodeName = id-UplinkNonUEAssociatedNRPPaTransport
// Criticality = ignore

int __si_amf_encode_pdu_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objPDUUplinkNonUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objPDUUplinkNonUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objPDUUplinkNonUEAssociatedNRPPaTransport);

int __si_amf_memfree_pdu_UplinkNonUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkNonUEAssociatedNRPPaTransport * objPDUUplinkNonUEAssociatedNRPPaTransport);



// ELEMENTARY-PROCEDURE = [0] uplinkRANConfigurationTransfer  L:6944
// ProcedureCode = 48
// ProcedureCodeName = id-UplinkRANConfigurationTransfer
// Criticality = ignore

int __si_amf_encode_pdu_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objPDUUplinkRANConfigurationTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objPDUUplinkRANConfigurationTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objPDUUplinkRANConfigurationTransfer);

int __si_amf_memfree_pdu_UplinkRANConfigurationTransfer( SI_AMF_DT_PDU_UplinkRANConfigurationTransfer * objPDUUplinkRANConfigurationTransfer);



// ELEMENTARY-PROCEDURE = [0] uplinkRANStatusTransfer  L:6944
// ProcedureCode = 49
// ProcedureCodeName = id-UplinkRANStatusTransfer
// Criticality = ignore

int __si_amf_encode_pdu_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objPDUUplinkRANStatusTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objPDUUplinkRANStatusTransfer, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objPDUUplinkRANStatusTransfer);

int __si_amf_memfree_pdu_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objPDUUplinkRANStatusTransfer);



// ELEMENTARY-PROCEDURE = [0] uplinkUEAssociatedNRPPaTransport  L:6944
// ProcedureCode = 50
// ProcedureCodeName = id-UplinkUEAssociatedNRPPaTransport
// Criticality = ignore

int __si_amf_encode_pdu_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objPDUUplinkUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objPDUUplinkUEAssociatedNRPPaTransport, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objPDUUplinkUEAssociatedNRPPaTransport);

int __si_amf_memfree_pdu_UplinkUEAssociatedNRPPaTransport( SI_AMF_DT_PDU_UplinkUEAssociatedNRPPaTransport * objPDUUplinkUEAssociatedNRPPaTransport);



// ELEMENTARY-PROCEDURE = [0] writeReplaceWarning  L:6944
// ProcedureCode = 51
// ProcedureCodeName = id-WriteReplaceWarning
// Criticality = reject

int __si_amf_encode_pdu_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objPDUWriteReplaceWarningRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objPDUWriteReplaceWarningRequest, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objPDUWriteReplaceWarningRequest);

int __si_amf_memfree_pdu_WriteReplaceWarningRequest( SI_AMF_DT_PDU_WriteReplaceWarningRequest * objPDUWriteReplaceWarningRequest);



// ELEMENTARY-PROCEDURE = [0] writeReplaceWarning  L:6944
// ProcedureCode = 51
// ProcedureCodeName = id-WriteReplaceWarning
// Criticality = reject

int __si_amf_encode_pdu_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objPDUWriteReplaceWarningResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_decode_pdu_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objPDUWriteReplaceWarningResponse, SI_ASN_CodingContext * codingContext);

int __si_amf_debug_pdu_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objPDUWriteReplaceWarningResponse);

int __si_amf_memfree_pdu_WriteReplaceWarningResponse( SI_AMF_DT_PDU_WriteReplaceWarningResponse * objPDUWriteReplaceWarningResponse);








#endif
