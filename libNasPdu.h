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

//#include "sirik_core.h"
//#include "libAsn.h"

#ifndef SIRIK_NASPDU_H
#define SIRIK_NASPDU_H

#define	SI_EMM_NAS_Attach_request									65
#define	SI_EMM_NAS_Attach_accept									66
#define	SI_EMM_NAS_Attach_complete									67
#define	SI_EMM_NAS_Attach_reject									68
#define	SI_EMM_NAS_Detach_request									69
#define	SI_EMM_NAS_Detach_accept									70

#define	SI_EMM_NAS_Tracking_area_update_request						72
#define	SI_EMM_NAS_Tracking_area_update_accept						73
#define	SI_EMM_NAS_Tracking_area_update_complete					74
#define	SI_EMM_NAS_Tracking_area_update_reject						75

#define	SI_EMM_NAS_Extended_service_request							76
#define	SI_EMM_NAS_Control_plane_service_request					77
#define	SI_EMM_NAS_Service_reject									78
#define	SI_EMM_NAS_Service_accept									79

#define	SI_EMM_NAS_GUTI_reallocation_command						80
#define	SI_EMM_NAS_GUTI_reallocation_complete						81
#define	SI_EMM_NAS_Authentication_request							82
#define	SI_EMM_NAS_Authentication_response							83
#define	SI_EMM_NAS_Authentication_reject							84
#define	SI_EMM_NAS_Authentication_failure							92
#define	SI_EMM_NAS_Identity_request									85
#define	SI_EMM_NAS_Identity_response								86
#define	SI_EMM_NAS_Security_mode_command							93
#define	SI_EMM_NAS_Security_mode_complete							94
#define	SI_EMM_NAS_Security_mode_reject								95

#define	SI_EMM_NAS_EMM_status										96
#define	SI_EMM_NAS_EMM_information									97
#define	SI_EMM_NAS_Downlink_NAS_transport							98
#define	SI_EMM_NAS_Uplink_NAS_transport								99
#define	SI_EMM_NAS_CS_Service_notification							100
#define	SI_EMM_NAS_Downlink_generic_NAS_transport					104
#define	SI_EMM_NAS_Uplink_generic_NAS_transport						105


#define	SI_ESM_NAS_Activate_default_EPS_bearer_context_request		193
#define	SI_ESM_NAS_Activate_default_EPS_bearer_context_accept		194
#define	SI_ESM_NAS_Activate_default_EPS_bearer_context_reject		195
#define	SI_ESM_NAS_Activate_dedicated_EPS_bearer_context_request	197
#define	SI_ESM_NAS_Activate_dedicated_EPS_bearer_context_accept		198
#define	SI_ESM_NAS_Activate_dedicated_EPS_bearer_context_reject		199
#define	SI_ESM_NAS_Modify_EPS_bearer_context_request				201
#define	SI_ESM_NAS_Modify_EPS_bearer_context_accept					202
#define	SI_ESM_NAS_Modify_EPS_bearer_context_reject					203
#define	SI_ESM_NAS_Deactivate_EPS_bearer_context_request			205
#define	SI_ESM_NAS_Deactivate_EPS_bearer_context_accept				206
#define	SI_ESM_NAS_PDN_connectivity_request							208
#define	SI_ESM_NAS_PDN_connectivity_reject							209
#define	SI_ESM_NAS_PDN_disconnect_request							210
#define	SI_ESM_NAS_PDN_disconnect_reject							211
#define	SI_ESM_NAS_Bearer_resource_allocation_request				212
#define	SI_ESM_NAS_Bearer_resource_allocation_reject				213
#define	SI_ESM_NAS_Bearer_resource_modification_request				214
#define	SI_ESM_NAS_Bearer_resource_modification_reject				215
#define	SI_ESM_NAS_ESM_information_request							217
#define	SI_ESM_NAS_ESM_information_response							218
#define	SI_ESM_NAS_Notification										219
#define	SI_ESM_NAS_ESM_dummy_message								220
#define	SI_ESM_NAS_ESM_status										232
#define	SI_ESM_NAS_Remote_UE_report									233
#define	SI_ESM_NAS_Remote_UE_report_response						234	
#define	SI_ESM_NAS_ESM_data_transport								235

#define SI_NAS_SHT_Plain_NAS_message_not_security_protected					0

// Integrity protected										
#define SI_NAS_SHT_IP														1

// Integrity protected and ciphered
#define SI_NAS_SHT_IPC														2

// Integrity protected with new EPS security context
#define SI_NAS_SHT_IP_EPS_security_context									3

//Integrity protected and ciphered with new EPS security context
#define SI_NAS_SHT_IPC_EPS_security_context									4

// Integrity protected and partially ciphered NAS message
#define SI_NAS_SHT_IPPC														5

//Non-standard L3 message
#define SI_NAS_SHT_Security_header_for_the_SERVICE_REQUEST_message			12


#define SI_5GS_MM_REGISTRATION_REQUEST										65
#define SI_5GS_MM_REGISTRATION_ACCEPT										66
#define SI_5GS_MM_REGISTRATION_COMPLETE										67
#define SI_5GS_MM_REGISTRATION_REJECT										68
#define SI_5GS_MM_UE_ORGIN_DE_REGISTRATION_REQUEST							69
#define SI_5GS_MM_UE_ORGIN_DE_REGISTRATION_ACCEPT							70
#define SI_5GS_MM_UE_TERMI_DE_REGISTRATION_REQUEST							71
#define SI_5GS_MM_UE_TERMI_DE_REGISTRATION_ACCEPT							72

#define SI_5GS_MM_SERVICE_REQUEST											76
#define SI_5GS_MM_SERVICE_REJECT											77
#define SI_5GS_MM_SERVICE_ACCEPT											78

#define SI_5GS_MM_CONFIGURATION_UPDATE_COMMAND								84
#define SI_5GS_MM_CONFIGURATION_UPDATE_COMPLETE								85
#define SI_5GS_MM_AUTHENTICATION_REQUEST									86
#define SI_5GS_MM_AUTHENTICATION_RESPONSE									87
#define SI_5GS_MM_AUTHENTICATION_REJECT										88
#define SI_5GS_MM_AUTHENTICATION_FAILURE									89
#define SI_5GS_MM_AUTHENTICATION_RESULT										90
#define SI_5GS_MM_IDENTITY_REQUEST											91
#define SI_5GS_MM_IDENTITY_RESPONSE											92
#define SI_5GS_MM_SECURITY_MODE_COMMAND										93
#define SI_5GS_MM_SECURITY_MODE_COMPLETE									94
#define SI_5GS_MM_SECURITY_MODE_REJECT										95

#define SI_5GS_MM_STATUS													100
#define SI_5GS_MM_NOTIFICATION												101
#define SI_5GS_MM_NOTIFICATION_RESPONSE										102
#define SI_5GS_MM_UL_NAS_TRANSPORT											103
#define SI_5GS_MM_DL_NAS_TRANSPORT											104

#define SI_5GS_SM_PDU_SESSION_ESTABLISHMENT_REQUEST							193
#define SI_5GS_SM_PDU_SESSION_ESTABLISHMENT_ACCEPT							194
#define SI_5GS_SM_PDU_SESSION_ESTABLISHMENT_REJECT							195

#define SI_5GS_SM_PDU_SESSION_AUTHENTICATION_COMMAND						197
#define SI_5GS_SM_PDU_SESSION_AUTHENTICATION_COMPLETE						198
#define SI_5GS_SM_PDU_SESSION_AUTHENTICATION_RESULT							199

#define SI_5GS_SM_PDU_SESSION_MODIFICATION_REQUEST							201
#define SI_5GS_SM_PDU_SESSION_MODIFICATION_REJECT							202
#define SI_5GS_SM_PDU_SESSION_MODIFICATION_COMMAND							203
#define SI_5GS_SM_PDU_SESSION_MODIFICATION_COMPLETE							204
#define SI_5GS_SM_PDU_SESSION_MODIFICATION_COMMAND_REJECT					205

#define SI_5GS_SM_PDU_SESSION_RELEASE_REQUEST								209
#define SI_5GS_SM_PDU_SESSION_RELEASE_REJECT								210
#define SI_5GS_SM_PDU_SESSION_RELEASE_COMMAND								211
#define SI_5GS_SM_PDU_SESSION_RELEASE_COMPLETE								212

#define SI_5GS_SM_STATUS													214

#define SI_5GS_SM_EPD														46
#define SI_5GS_MM_EPD														126



// 5G MM CONSTANTS
// REGISTRATION_TYPE
#define SI_5GS_MM_REGISTRATION_TYPE__INITIAL_REGISTRATION							1
#define SI_5GS_MM_REGISTRATION_TYPE__MOBILE_REGISTRATION_UPDATING					2
#define SI_5GS_MM_REGISTRATION_TYPE__PERIODIC_REGISTRATION_UPDATING					3
#define SI_5GS_MM_REGISTRATION_TYPE__EMERGENCY_REGISTRATION							4

// SMS over NAS transport requested (SMS requested) (octet 3, bit 4)
#define SI_5GS_MM_SMS_OVER_NAS_NOT_SUPPORTED										0
#define SI_5GS_MM_SMS_OVER_NAS_SUPPORTED											1

// Follow-on request bit (FOR) (octet 3, bit 5)
#define SI_5GS_MM_NO_FOLLOW_ON_REQUEST_PENDING										0
#define SI_5GS_MM_FOLLOW_ON_REQUEST_PENDING											1




typedef struct __si_nibbleHelper
{
	uint8_t b1 : 4;
	uint8_t b2 : 4;
} SI_NibbleHelper;


typedef struct __naspduSecurityHeader
{
	uint8_t ProtocolDiscriminator : 4;		//LSB
	uint8_t EPSBIOrSHT : 4;					//MSB
	u_char  MAC[4];
	uint8_t SequenceNumber;
	
} NASPduSecurityHeader;


typedef struct __naspduHeader
{
	uint8_t ProtocolDiscriminator : 4;		//LSB
	uint8_t EPSBIOrSHT : 4;					//MSB
	
	uint8_t ProcedureTransactionIdentity;
	uint8_t ProcedureTransactionIdentity_isset;
	
	uint8_t MessageType;
	
} NASPduHeader;

typedef struct __naspduFGSecurityHeader
{
	uint8_t ProtocolDiscriminator : 4;		//LSB
	uint8_t EPSBIOrSHT : 4;					//MSB
	u_char  MAC[4];
	uint8_t SequenceNumber;
	
} NASPduFGSecurityHeader;


typedef struct __naspduFGHeader
{
	uint8_t ProtocolDiscriminator;		//LSB
	uint8_t PSIOrSHT;					//MSB
	
	uint8_t IsSMMsg;
	uint8_t PDUSessionId;
	uint8_t ProcedureTransactionIdentity;
	uint8_t ProcedureTransactionIdentity_isset;
	
	uint8_t MessageType;
	
} NASPduFGHeader;



typedef struct __naspdu_AdditionalInformation
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t data[255];
	
	uint8_t isset;
} NASPdu_AdditionalInformation;


typedef struct __naspdu_DeviceProperties
{
	struct
	{
		uint8_t LowPriority : 1; //LSB
		uint8_t Spare : 3;			
		uint8_t IEI: 4; //MSB  				// 8, 7 , 6, 5
	} b1;
	
	uint8_t isset;
} NASPdu_DeviceProperties;


typedef struct __naspdu_EPSBearerContextStatus
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t EBI0:1;
		uint8_t EBI1:1;
		uint8_t EBI2:1;
		uint8_t EBI3:1;
		uint8_t EBI4:1;
		uint8_t EBI5:1;
		uint8_t EBI6:1;
		uint8_t EBI7:1;
	} b1;
	
	struct
	{
		uint8_t EBI8:1;
		uint8_t EBI9:1;
		uint8_t EBI10:1;
		uint8_t EBI11:1;
		uint8_t EBI12:1;
		uint8_t EBI13:1;
		uint8_t EBI14:1;
		uint8_t EBI15:1;
	} b2;
	
	uint8_t isset;
} NASPdu_EPSBearerContextStatus;


//decode done
typedef struct __naspdu_LocationAreaIdentification
{
	uint8_t IEI;
	u_char MCCMNC[3];
	u_char LAC[2];
	
	uint8_t isset;
} NASPdu_LocationAreaIdentification;


// decode done 
typedef struct __naspdu_MobileIdentity
{
	uint8_t IEI;
	uint8_t Length;

	/*
	struct 
	{
		uint8_t MobileIdentityType : 3;
		uint8_t OddEvenIndication : 1;
		uint8_t IdentityDigits : 4;
	} Type;
	*/
	
	/*
	struct 
	{
		char data[20];
		int len;
	} IMEISV;
	*/
	
	u_char data[20];
	
	uint8_t isset;
} NASPdu_MobileIdentity;


typedef struct __naspdu_MobileStationClassmark2
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t RFPowerCapablity : 3;
		uint8_t A51 : 1;
		uint8_t ESIND : 1;
		uint8_t RevisionLevel : 2;
		uint8_t Spare : 1;
	} b1;
	
	struct
	{
		uint8_t FC : 1;
		uint8_t VGCS : 1;
		uint8_t VBS : 1;
		uint8_t SMCaPabi : 1;
		uint8_t SSScreenInd : 2;
		uint8_t PSCapa : 1;
		uint8_t Spare : 1;
	} b2;
	
	struct
	{
		uint8_t A52 : 1;
		uint8_t A53 : 1;
		uint8_t CMSP : 1;
		uint8_t SoLSA : 1;
		uint8_t UCS2 : 1;
		uint8_t LCSVACAP : 1;
		uint8_t Spare : 1;
		uint8_t CM3 : 1;
	} b3;
	
	uint8_t isset;
} NASPdu_MobileStationClassmark2;


typedef struct __naspdu_MobileStationClassmark3
{
	uint8_t IEI;
	uint8_t Length;
	
	u_char data[34];
	
	uint8_t isset;
} NASPdu_MobileStationClassmark3;


typedef struct __naspdu_NASSecurityParametersFromEUTRA
{
	uint8_t IEI;
	
	struct
	{
		uint8_t DLNasCount : 4;
		uint8_t Spare : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_NASSecurityParametersFromEUTRA;


typedef struct __naspdu_NASSecurityParametersToEUTRA
{
	uint8_t IEI;
	
	u_char NonceMME[4];
	
	struct
	{
		uint8_t TypeOfIntegrityProtectionAlgorithm : 3;
		uint8_t Spare1:1; //bit 4
		uint8_t TypeOfCipheringAlgorithm : 3; // 7 6 5
		uint8_t Spare:1; //bit 8
	} b1;
	
	struct
	{
		uint8_t NASKeySetId : 3;
		uint8_t TSC : 1;
		uint8_t Spare : 4;
	} b2;
	
	uint8_t isset;	
} NASPdu_NASSecurityParametersToEUTRA;


// decode done
typedef struct __naspdu_PLMNList
{
	uint8_t IEI;
	uint8_t Length;
	
	u_char data[47];
	
	uint8_t isset;
} NASPdu_PLMNList;


typedef struct __naspdu_SpareHalfOctet
{
	uint8_t isset;	
} NASPdu_SpareHalfOctet;


typedef struct __naspdu_SupportedCodecList
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[49];
	uint8_t isset;	
} NASPdu_SupportedCodecList;





// EMM

// decode done
typedef struct __naspdu_AdditionalUpdateResult
{
	struct
	{
		//2, 1
		uint8_t AdditionalUpdateResultValue : 2;

		//4, 3
		uint8_t Spare : 2;

		// 8, 7 , 6, 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;	
} NASPdu_AdditionalUpdateResult;



typedef struct __naspdu_AdditionalUpdateType
{
	struct
	{
		// 1
		uint8_t AUTV : 1;
		
		// 2
		uint8_t SAF : 1;
		
		// 4, 3
		uint8_t PNBCIoT : 2;
		
		// 8, 7 , 6, 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_AdditionalUpdateType;



typedef struct __naspdu_AuthenticationFailureParameter
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t data[14];	
	
	uint8_t isset;
} NASPdu_AuthenticationFailureParameter;



typedef struct __naspdu_AuthenticationParameterAUTN
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t data[40];
	uint8_t isset;
} NASPdu_AuthenticationParameterAUTN;



typedef struct __naspdu_AuthenticationParameterRAND
{
	uint8_t IEI;
	uint8_t data[40];
	uint8_t isset;
} NASPdu_AuthenticationParameterRAND;



typedef struct __naspdu_AuthenticationResponseParameter
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t data[16];
	uint8_t isset;
} NASPdu_AuthenticationResponseParameter;



typedef struct __naspdu_CipheringKeySequenceNumber
{
	struct
	{
		// 3, 2, 1
		uint8_t KeySequence : 3;
		// 4
		uint8_t Spare : 1;
		// 8, 7 , 6, 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_CipheringKeySequenceNumber;


//decode done
typedef struct __naspdu_SMSServicesStatus
{
	struct
	{
		// 3, 2, 1
		uint8_t ServicesStatus : 3;
	
		// 4
		uint8_t Spare : 1;
		
		// 8, 7 , 6, 5
		uint8_t IEI : 4;
	} b1;	
	uint8_t isset;
} NASPdu_SMSServicesStatus;



typedef struct __naspdu_CSFBResponse
{
	struct
	{
		// 3, 2, 1
		uint8_t CSFBResponseValue : 3;
		
		// 4
		uint8_t Spare : 1;
		
		// 8, 7 , 6, 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_CSFBResponse;



typedef struct __naspdu_DaylightSavingTime
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		//2, 1
		uint8_t DST   : 2;
		
		// 8 to 3
		uint8_t Spare : 6;
	} b1;
	
	uint8_t isset;
} NASPdu_DaylightSavingTime;



typedef struct __naspdu_DetachType
{
	struct
	{
		// 3, 2, 1
		uint8_t TypeOfDetach : 3;
		
		// 4
		uint8_t SwitchOff : 1;
		
		// 8, 7 , 6, 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_DetachType;



typedef struct __naspdu_DRXParameter
{
	uint8_t IEI;
	
	uint8_t SplitPGCycleCode;
	
	struct
	{
		//3,2,1
		uint8_t NonDRXTimer : 3;
		
		//4
		uint8_t SplitOnCCH : 1;
		
		//8,7,6,5
		uint8_t CNSpecifiedDRXCycleLengthCoefficent : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_DRXParameter;

/*
	2	IMSI unknown in HSS
	3	Illegal UE
	5	IMEI not accepted
	6	Illegal ME
	7	EPS services not allowed
	8	EPS services and non-EPS services not allowed
	9	UE identity cannot be derived by the network
	10	Implicitly detached
	11	PLMN not allowed
	12	Tracking Area not allowed
	13	Roaming not allowed in this tracking area
	14	EPS services not allowed in this PLMN
	15	No Suitable Cells In tracking area
	16	MSC temporarily not reachable
	17	Network failure
	18	CS domain not available
	19	ESM failure
	20	MAC failure
	21	Synch failure
	22	Congestion
	23	UE security capabilities mismatch
	24	Security mode rejected, unspecified
	25	Not authorized for this CSG
	26	Non-EPS authentication unacceptable
	35	Requested service option not authorized in this PLMN
	39	CS service temporarily not available
	40	No EPS bearer context activated
	42	Severe network failure
	95	Semantically incorrect message
	96	Invalid mandatory information
	97	Message type non-existent or not implemented
	98	Message type not compatible with the protocol state
	99	Information element non-existent or not implemented
	100	Conditional IE error
	101	Message not compatible with the protocol state
	111	Protocol error, unspecified
		
*/
// decode done
typedef struct __naspdu_EMMCause
{
	uint8_t IEI;
	uint8_t Cause;
	uint8_t isset;
} NASPdu_EMMCause;



// decode done
typedef struct __naspdu_EPSAttachResult
{
	struct
	{
		//3,2,1
		uint8_t AttachResultValue : 3;
		//4
		uint8_t Spare : 1;
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_EPSAttachResult;



typedef struct __naspdu_EPSAttachType
{
	struct
	{
		//3,2,1
		uint8_t AttachTypeValue : 3;
		
		//4
		uint8_t Spare : 1;
		
		//8,7,6,5
		uint8_t IEI : 4;	
	} b1;	
	uint8_t isset;
} NASPdu_EPSAttachType;


// decode done
typedef struct __naspdu_EPSMobileIdentity
{
	uint8_t IEI;
	uint8_t Length;
	
	struct 
	{
		uint8_t TypeOfIdentity : 3;
		uint8_t OddEvenIndication : 1;
		uint8_t Spare : 4;
	} Type;
	
	// if TypeOfIdentity=1 IMSI
	struct 
	{
		unsigned char data[20];
		int len;
	} IMSI;
	
	// if TypeOfIdentity=6 GUTI
	uint8_t MCCMNC[3];
	uint16_t MMEGroupId;
	uint8_t MMECode;
	uint8_t M_TMSI[4];
	
	uint8_t isset;
} NASPdu_EPSMobileIdentity;


//decode done
typedef struct __naspdu_EPSNetworkFeatureSupport
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		// 1
		uint8_t IMSVoPS : 1;
		
		// 2
		uint8_t EMCBS : 1;
		
		// 3
		uint8_t EPCLCS : 1;
		
		// 5, 4
		uint8_t CSLCS : 2;
		
		// 6
		uint8_t ESRPS : 1;
		
		// 7
		uint8_t ERWoPDN : 1;
		
		// 8
		uint8_t CPCIoT : 1;
	} b1;
	
	struct
	{
		// 1
		uint8_t UPCIoT : 1;
		
		// 2
		uint8_t S1UData : 1;
		
		// 3
		uint8_t HCCPCIoT : 1;
		
		// 4
		uint8_t ePCO : 1;
		
		// 5
		uint8_t RestrictEC : 1;
		
		// 6
		uint8_t RestrictDCNR : 1;	
		
		// 7
		uint8_t IWKN26 : 1;	
		
		// 8 15 bearers
		uint8_t FTBearers : 1;	
	} b2;
	
	uint8_t isset;
} NASPdu_EPSNetworkFeatureSupport;



typedef struct __naspdu_EPSUpdateResult
{
	struct
	{
		//3,2,1
		uint8_t Result : 3;
		
		//4
		uint8_t Spare : 1;
		
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;	
	uint8_t isset;
} NASPdu_EPSUpdateResult;



typedef struct __naspdu_EPSUpdateType
{
	struct
	{
		//3,2,1
		uint8_t Type : 3;
		
		//4
		uint8_t Spare : 1;
		
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;	
	uint8_t isset;
} NASPdu_EPSUpdateType;


//decode done
typedef struct __naspdu_ESMMessageContainer
{
	uint8_t IEI;
	uint16_t Length;
	
	u_char data[2048];
	uint8_t isset;
} NASPdu_ESMMessageContainer;



// decode done
typedef struct __naspdu_GPRSTimer
{
	uint8_t IEI;
	
	struct
	{
		//5 4 3 2 1
		uint8_t TimerValue : 5;
		
		//8,7,6
		uint8_t Unit : 3;
	} b1;
	
	uint8_t isset;
} NASPdu_GPRSTimer;


//decode done
typedef struct __naspdu_GPRSTimer2
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t TimerValue;
	uint8_t isset;
} NASPdu_GPRSTimer2;


//decode done
typedef struct __naspdu_GPRSTimer3
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		//5 4 3 2 1
		uint8_t TimerValue : 5;
		
		//8,7,6
		uint8_t Unit : 3;
	} b1;
	
	uint8_t isset;
} NASPdu_GPRSTimer3;



typedef struct __naspdu_IdentityType2
{
	struct
	{
		// 3, 2, 1
		uint8_t Type : 3;
		// 4
		uint8_t Spare : 1;
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_IdentityType2;



typedef struct __naspdu_IMEISVRequest
{
	struct
	{
		// 3, 2, 1
		uint8_t IMEISV : 3;
		
		// 4
		uint8_t Spare : 1;
		
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_IMEISVRequest;



typedef struct __naspdu_KSIAndSequenceNumber
{
	uint8_t IEI;
	
	struct
	{
		//5, 4, 3, 2, 1
		uint8_t SequenceNumber : 5;
		
		//8,7,6
		uint8_t KSI : 3;
	} b1;
	
	uint8_t isset;
} NASPdu_KSIAndSequenceNumber;



typedef struct __naspdu_MSNetworkCapability
{
	uint8_t IEI;
	uint8_t Length;
	//u_char data[8];
	
	struct 
	{
		uint8_t RevisionLevelIndicator : 1;
		uint8_t SoLSACapability : 1;
		uint8_t SSScreeningIndicator : 2;
		uint8_t UCS2Support : 1;
		uint8_t SMCapabilitiesViaGPRSChannels : 1;
		uint8_t SMCapabilitiesViaDedicatedChannels : 1;
		uint8_t GEA1 : 1;
	} b1;
	
	struct 
	{
		uint8_t LCSVACapability : 1;
		uint8_t ExtGEA7 : 1;
		uint8_t ExtGEA6 : 1;
		uint8_t ExtGEA5 : 1;
		uint8_t ExtGEA4 : 1;
		uint8_t ExtGEA3 : 1;
		uint8_t ExtGEA2 : 1;
		uint8_t PFCFeatureMode : 1;
	} b2;
	
	struct 
	{
		uint8_t GeranNetworkSharingCapability : 1;
		uint8_t NFCapability : 1;
		uint8_t EPCCapability : 1;
		uint8_t SRVCCToGERANUTRANCapability : 1;
		uint8_t ISRSupport : 1;
		uint8_t EMMCombinedProcCapability : 1;
		uint8_t PSIntraRatHOFromGeranToEUTRANS1ModeCapability : 1;
		uint8_t PSIntraRatHOFromGeranToUTRANIuModeCapability : 1;
	} b3;
	
	uint8_t isset;
} NASPdu_MSNetworkCapability;



typedef struct __naspdu_MSNetworkFeatureSupport
{
	struct
	{
		// 1
		uint8_t ExtendedPeriodicTimers : 1;
		// 2
		uint8_t Spare : 3;
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_MSNetworkFeatureSupport;



typedef struct __naspdu_NASKeySetIdentifier
{
	struct
	{
		// 3 2 1
		uint8_t Identifier : 3;
		// 4
		uint8_t TSC : 1;
		//8,7,6,5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_NASKeySetIdentifier;


typedef struct __naspdu_NASMessageContainer
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[255];
	uint8_t isset;
} NASPdu_NASMessageContainer;



typedef struct __naspdu_NASSecurityAlgorithms
{
	uint8_t IEI;

	struct
	{
		// 7 6 5
		uint8_t TypeOfIntegrityProtectionAlgorithm : 3;
		
		// 4
		uint8_t Spare1 : 1;
		
		// 7 6 5
		uint8_t TypeOfCipheringAlgorithm : 3;
		
		// 8
		uint8_t Spare : 1;
	} b1;
	
	uint8_t isset;
} NASPdu_NASSecurityAlgorithms;



typedef struct __naspdu_NetworkName
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		// 3 2 1
		uint8_t NoOfSpaceBits : 3;
		
		// 4
		uint8_t AddCI : 1;
		
		// 7 6 5
		uint8_t CodingScheme : 3;
		
		// 8
		uint8_t Ext : 1;
	} b1;
	
	u_char data[255];
	uint8_t isset;
} NASPdu_NetworkName;



typedef struct __naspdu_NetworkResourceIdentifierContainer
{
	uint8_t IEI;
	uint8_t Length;
	
	u_char b1[2];

	uint8_t isset;
} NASPdu_NetworkResourceIdentifierContainer;



typedef struct __naspdu_Nonce
{
	uint8_t IEI;
	u_char data[4];
	uint8_t isset;
} NASPdu_Nonce;



typedef struct __naspdu_PagingIdentity
{
	uint8_t IEI;
	struct
	{
		uint8_t PagingIdentityValue : 1;
		uint8_t Spare : 7;
	} b1;
	uint8_t isset;
} NASPdu_PagingIdentity;



typedef struct __naspdu_PTMSISignature
{
	uint8_t IEI;
	u_char data[3];
	uint8_t isset;
} NASPdu_PTMSISignature;



typedef struct __naspdu_ExtendedEMMCause
{
	struct
	{
		// 1 
		uint8_t EUtranAllowed : 1;
		
		// 2 
		uint8_t EPSOptimizationInfo : 1;
		
		// 3 
		uint8_t NBIoTAllowed : 1;
		
		// 4 
		uint8_t Spare : 1;
		
		// 8, 7, 6, 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_ExtendedEMMCause;



typedef struct __naspdu_ServiceType
{
	struct
	{
		// 4 3 2 1
		uint8_t ServiceTypeValue : 4;	
		// 8, 7, 6, 5
		uint8_t IEI : 4;
	} b1;	
	uint8_t isset;	
} NASPdu_ServiceType;



typedef struct __naspdu_ShortMAC
{
	uint8_t IEI;
	uint16_t MACValue;
	uint8_t isset;
} NASPdu_ShortMAC;



typedef struct __naspdu_TimeZone
{
	uint8_t IEI;
	uint8_t TimeZone;
	uint8_t isset;
} NASPdu_TimeZone;



typedef struct __naspdu_TimeZoneAndTime
{
	uint8_t IEI;
	uint8_t Year;
	uint8_t Month;
	uint8_t Day;
	uint8_t Hour;
	uint8_t Minute;
	uint8_t Second;
	uint8_t TimeZone;
	uint8_t isset;
} NASPdu_TimeZoneAndTime;



typedef struct __naspdu_TMSIStatus
{
	struct
	{
		// 1
		uint8_t TMSIFlag : 3;	
		// 4 3 2
		uint8_t Spare : 3;	
		// 8, 7, 6, 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_TMSIStatus;



typedef struct __naspdu_TrackingAreaIdentity
{
	uint8_t IEI;
	u_char MCCMNC[3];
	u_char TAC[2];
	uint8_t isset;
} NASPdu_TrackingAreaIdentity;

typedef struct __naspdu_TrackingAreaIdentityItem
{
	// 5 4 3 2 1
	uint8_t NumberOfElements : 6;
	
	// 7 6
	uint8_t TypeOfList : 2;	
	
	// 8
	uint8_t Spare : 1;	
	
	u_char MCCMNC[3];
	u_char TAC[10][2];
} NASPdu_TrackingAreaIdentityItem;


// decode done
typedef struct __naspdu_TrackingAreaIdentityList
{
	/*
	NASPdu_TrackingAreaIdentityItem * Head;
	NASPdu_TrackingAreaIdentityItem * Current;
	int Count;
	*/
	
	uint8_t IEI;
	uint8_t Length;
	u_char data[98];
	uint8_t isset;
} NASPdu_TrackingAreaIdentityList;



typedef struct __naspdu_UENetworkCapability
{
	uint8_t IEI;
	uint8_t Length;
	
	// ------------- byte 1
	struct
	{
		uint8_t EEA7 : 1;		//1 bit
		uint8_t EEA6 : 1;
		uint8_t EEA5 : 1;
		uint8_t EEA4 : 1;
		uint8_t EEA3 : 1;
		uint8_t EEA2 : 1;
		uint8_t EEA1 : 1;
		uint8_t EEA0 : 1;		//8 bit
	} EEA;
	uint8_t EEA_isSet;
	// ------------- byte 1
	
	// ------------- byte 2
	struct
	{
		uint8_t EIA7 : 1;		//1 bit
		uint8_t EIA6 : 1;
		uint8_t EIA5 : 1;
		uint8_t EIA4 : 1;
		uint8_t EIA3 : 1;
		uint8_t EIA2 : 1;
		uint8_t EIA1 : 1;
		uint8_t EIA0 : 1;		//8 bit
	} EIA;	
	uint8_t EIA_isSet;
	// ------------- byte 2
	
	// ------------- byte 3
	struct
	{
		uint8_t UEA7 : 1;		//1 bit
		uint8_t UEA6 : 1;
		uint8_t UEA5 : 1;
		uint8_t UEA4 : 1;
		uint8_t UEA3 : 1;
		uint8_t UEA2 : 1;
		uint8_t UEA1 : 1;
		uint8_t UEA0 : 1;		//8 bit
	} UEA;	
	uint8_t UEA_isSet;
	// ------------- byte 3
	
	// ------------- byte 4
	struct
	{
		uint8_t UIA7 : 1;		//1 bit
		uint8_t UIA6 : 1;
		uint8_t UIA5 : 1;
		uint8_t UIA4 : 1;
		uint8_t UIA3 : 1;
		uint8_t UIA2 : 1;
		uint8_t UIA1 : 1;
		uint8_t UCS2 : 1;		//8 bit
	} UIA;	
	uint8_t UIA_isSet;
	// ------------- byte 4	

	// ------------- byte 5
	struct
	{
		uint8_t NF : 1;		//1 bit
		uint8_t SRVCC : 1;
		uint8_t LCS : 1;
		uint8_t LPP : 1;
		uint8_t ACCCSFB : 1;
		uint8_t H245ASH : 1;
		uint8_t ProSe : 1;
		uint8_t ProSedd : 1;		//8 bit
	} B5;	
	uint8_t B5_isSet;
	// ------------- byte 5	
	
	// ------------- byte 6
	struct
	{
		uint8_t ProSedc : 1;				//1 bit
		uint8_t ProseRelay : 1;
		uint8_t CPCIoT : 1;
		uint8_t UPCIoT : 1;
		uint8_t S1UData : 1;
		uint8_t ERWoPDN : 1;
		uint8_t HCCPCIoT : 1;
		uint8_t ePCO : 1;		//8 bit
	} B6;	
	uint8_t B6_isSet;
	// ------------- byte 6	
	
	// ------------- byte 7
	struct
	{
		uint8_t multipleDRB : 1;				//1 bit
		uint8_t V2XPC5 : 1;
		uint8_t RestrictEC : 1;
		uint8_t CPBackoff : 1;
		uint8_t DCNR : 1;
		uint8_t N1Mod : 1;
		uint8_t SGC : 1;
		uint8_t FTBearer : 1;		//8 bit
	} B7;
	uint8_t B7_isSet;
	// ------------- byte 7	
	uint8_t isset;
} NASPdu_UENetworkCapability;



typedef struct __naspdu_UERadioCapabilityInformationUpdateNeeded
{
	struct 
	{
		// 1
		uint8_t URCUpd : 1;
		// 4 3 2
		uint8_t Spare : 3;	
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_UERadioCapabilityInformationUpdateNeeded;



typedef struct __naspdu_UESecurityCapability
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		// ------------- byte 1
		uint8_t EEA7 : 1;		//1 bit
		uint8_t EEA6 : 1;
		uint8_t EEA5 : 1;
		uint8_t EEA4 : 1;
		uint8_t EEA3 : 1;
		uint8_t EEA2 : 1;
		uint8_t EEA1 : 1;
		uint8_t EEA0 : 1;		//8 bit
		// ------------- byte 1
	} EEA;
	
	struct
	{
		// ------------- byte 2
		uint8_t EIA7 : 1;		//1 bit
		uint8_t EIA6 : 1;
		uint8_t EIA5 : 1;
		uint8_t EIA4 : 1;
		uint8_t EIA3 : 1;
		uint8_t EIA2 : 1;
		uint8_t EIA1 : 1;
		uint8_t EIA0 : 1;		//8 bit
		// ------------- byte 2
	} EIA;
	
	struct
	{
		// ------------- byte 3
		uint8_t UEA7 : 1;		//1 bit
		uint8_t UEA6 : 1;
		uint8_t UEA5 : 1;
		uint8_t UEA4 : 1;
		uint8_t UEA3 : 1;
		uint8_t UEA2 : 1;
		uint8_t UEA1 : 1;
		uint8_t UEA0 : 1;		//8 bit
		// ------------- byte 3
	} UEA;
	
	struct
	{
		// ------------- byte 4
		uint8_t UIA7 : 1;		//1 bit
		uint8_t UIA6 : 1;
		uint8_t UIA5 : 1;
		uint8_t UIA4 : 1;
		uint8_t UIA3 : 1;
		uint8_t UIA2 : 1;
		uint8_t UIA1 : 1;
		uint8_t Spar2 : 1;		//8 bit
		// ------------- byte 4	
	} UIA;
	
	struct
	{
		// ------------- byte 4
		uint8_t GEA7 : 1;		//1 bit
		uint8_t GEA6 : 1;
		uint8_t GEA5 : 1;
		uint8_t GEA4 : 1;
		uint8_t GEA3 : 1;
		uint8_t GEA2 : 1;
		uint8_t GEA1 : 1;
		uint8_t Spar1 : 1;		//8 bit
		// ------------- byte 4
	} GEA;
	
	uint8_t isset;
} NASPdu_UESecurityCapability;


typedef struct __naspdu_EmergencyNumberItem
{
	uint8_t Length;
	u_char data[10];
} NASPdu_EmergencyNumberItem;


//decode done
typedef struct __naspdu_EmergencyNumberList
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[1024];
	//NASPdu_EmergencyNumberItem List[10];
	//int Count;
	uint8_t isset;
} NASPdu_EmergencyNumberList;


//decode done
typedef struct __naspdu_ExtendedEmergencyNumberList
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[1024];
	//NASPdu_EmergencyNumberItem List[10];
	//int Count;
	uint8_t isset;
} NASPdu_ExtendedEmergencyNumberList;



typedef struct __naspdu_CLI
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t NPI : 4;
		uint8_t TypeOfNumber : 3;
		uint8_t Extension : 1;
	} b1;

	struct
	{
		uint8_t ScreenIndicator : 2;
		uint8_t Spare : 3;
		uint8_t PresentationIndicator : 2;
		uint8_t Extension : 1;
	} b2;
	
	u_char data[12];
	uint8_t isset;
} NASPdu_CLI;



typedef struct __naspdu_SSCode
{
	uint8_t IEI;
	uint8_t Code;
	uint8_t isset;
} NASPdu_SSCode;



typedef struct __naspdu_LCSIndicator
{
	uint8_t IEI;
	uint8_t Value;
	uint8_t isset;
} NASPdu_LCSIndicator;



typedef struct __naspdu_LCSClientIdentity
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[255];
	uint8_t isset;
} NASPdu_LCSClientIdentity;



typedef struct __naspdu_GenericMessageContainerType
{
	//uint8_t IEI;
	//uint8_t Length;
	//u_char data[8];
	uint8_t Type;
	uint8_t isset;
} NASPdu_GenericMessageContainerType;



typedef struct __naspdu_GenericMessageContainer
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[255];
	uint8_t isset;
} NASPdu_GenericMessageContainer;



typedef struct __naspdu_VoiceDomainPreferenceAndUEsUsageSetting
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		// 2 1 
		uint8_t VoiceDomainPreferenceForEUTRAN : 2;	
		
		// 3
		uint8_t UEUsageSetting : 1;
		
		// 8 7 6 5 4
		uint8_t Spare : 5;
	} b1;
	
	uint8_t isset;
} NASPdu_VoiceDomainPreferenceAndUEsUsageSetting;



typedef struct __naspdu_GUTIType
{
	struct
	{
		// 1
		uint8_t Type : 1;
		// 4 3 2
		uint8_t Spare : 3;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;	
	uint8_t isset;
} NASPdu_GUTIType;


//decode done
typedef struct __naspdu_ExtendedDRXParameters
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		// 8 7 6 5
		uint8_t eDRXValue : 4;
		
		// 8 7 6 5
		uint8_t PagingTimeWindow : 4;
	} b1;	
	uint8_t isset;
} NASPdu_ExtendedDRXParameters;



typedef struct __naspdu_ControlPlaneServiceType
{
	struct
	{
		// 3 2 1
		uint8_t ServiceTypeValue : 3;
		
		// 4 
		uint8_t ActiveFlag : 1;
		
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_ControlPlaneServiceType;


//deocde done
typedef struct __naspdu_DCNID
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[2];
	uint8_t isset;
} NASPdu_DCNID;


//decode done
typedef struct __naspdu_Non3GPPNWProvidedPolicies
{
	struct
	{
		uint8_t N3ENIndicator : 1;
		uint8_t Spare : 3;
		uint8_t IEI : 4;	
	} b1;
	uint8_t isset;
} NASPdu_Non3GPPNWProvidedPolicies;



typedef struct __naspdu_HashMME
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[10];
	uint8_t isset;
} NASPdu_HashMME;



typedef struct __naspdu_ReplayedNASMessageContainer
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[1024];
	uint8_t isset;
} NASPdu_ReplayedNASMessageContainer;


//decode done
typedef struct __naspdu_NetworkPolicy
{
	struct
	{
		// 1
		uint8_t RedirPolicy : 1;
		
		// 4 3 2
		uint8_t Spare : 3;
		
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_NetworkPolicy;



typedef struct __naspdu_UEAdditionalSecurityCapability
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		// ------------- byte 1
		uint8_t FGEA7 : 1;		//1 bit
		uint8_t FGEA6 : 1;
		uint8_t FGEA5 : 1;
		uint8_t FGEA4 : 1;
		uint8_t FGEA3 : 1;
		uint8_t FGEA2 : 1;
		uint8_t FGEA1 : 1;
		uint8_t FGEA0 : 1;		//8 bit
		// ------------- byte 1
	} b1;
	
	struct
	{
		// ------------- byte 2
		uint8_t FGEA15 : 1;		//8 bit
		uint8_t FGEA14 : 1;
		uint8_t FGEA13 : 1;
		uint8_t FGEA12 : 1;
		uint8_t FGEA11 : 1;
		uint8_t FGEA10 : 1;
		uint8_t FGEA9 : 1;
		uint8_t FGEA8 : 1;		//1 bit
		// ------------- byte 2
	} b2;
	
	struct
	{
		// ------------- byte 3
		uint8_t FGIA7 : 1;		//1 bit
		uint8_t FGIA6 : 1;
		uint8_t FGIA5 : 1;
		uint8_t FGIA4 : 1;
		uint8_t FGIA3 : 1;
		uint8_t FGIA2 : 1;
		uint8_t FGIA1 : 1;
		uint8_t FGIA0 : 1;		//8 bit
		// ------------- byte 3
	} b3;
	
	struct
	{
		// ------------- byte 3
		uint8_t FGIA15 : 1;		//8 bit
		uint8_t FGIA14 : 1;
		uint8_t FGIA13 : 1;
		uint8_t FGIA12 : 1;
		uint8_t FGIA11 : 1;
		uint8_t FGIA10 : 1;
		uint8_t FGIA9 : 1;
		uint8_t FGIA8 : 1;		//1 bit
		// ------------- byte 3
	} b4;
	
	uint8_t isset;
} NASPdu_UEAdditionalSecurityCapability;



typedef struct __naspdu_UEStatus
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t S1Mode : 1;
		uint8_t N1Mode : 1;
		uint8_t Spare : 6;
	} b1;	
	uint8_t isset;
} NASPdu_UEStatus;



typedef struct __naspdu_AdditionalInformationRequested
{
	uint8_t IEI;
	struct
	{
		uint8_t CipherKey : 1;
		uint8_t Spare : 7;	
	} b1;
	uint8_t isset;
} NASPdu_AdditionalInformationRequested;


typedef struct __naspdu_CipheringKeyDataSet
{
	uint16_t CipheringSetID;
	u_char CipheringKey[15];
	
	// not built fully
} NASPdu_CipheringKeyDataSet;

//decode done
typedef struct __naspdu_CipheringKeyData
{
	uint8_t IEI;
	uint16_t Length;
	
	u_char data[1024];
	uint8_t isset;
} NASPdu_CipheringKeyData;


/*
-------------------
*/

typedef struct __naspdu_AccessPointName
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[102];
	uint8_t isset;
} NASPdu_AccessPointName;



typedef struct __naspdu_APNAggregateMaximumBitRate
{
	uint8_t IEI;
	uint8_t Length;
	
	uint8_t APNAMBRForDownlink;
	uint8_t APNAMBRForUplink;
	
	uint8_t APNAMBRForDownlinkExt1;
	uint8_t APNAMBRForUplinkExt1;	
	uint8_t APNAMBRForDownlinkExt1_isset;
	uint8_t APNAMBRForUplinkExt1_isset;
	
	uint8_t APNAMBRForDownlinkExt2;
	uint8_t APNAMBRForUplinkExt2;		
	uint8_t APNAMBRForDownlinkExt2_isset;
	uint8_t APNAMBRForUplinkExt2_isset;	
	
	uint8_t isset;
} NASPdu_APNAggregateMaximumBitRate;



typedef struct __naspdu_ConnectivityType
{
	struct
	{
		// 4 3 2 1
		uint8_t TypeValue : 4;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_ConnectivityType;



typedef struct __naspdu_EPSQualityOfService
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t QCI;
	
	// --Optional Elements
	uint8_t MaximumBitRateForUplink;
	uint8_t MaximumBitRateForUplink_isset;
	
	uint8_t MaximumBitRateForDownlink;
	uint8_t MaximumBitRateForDownlink_isset;
	
	uint8_t GuaranteedBitRateForUplink;
	uint8_t GuaranteedBitRateForUplink_isset;
	
	uint8_t GuaranteedBitRateForDownlink;
	uint8_t GuaranteedBitRateForDownlink_isset;
	
	uint8_t MaximumBitRateForUplinkEx1;
	uint8_t MaximumBitRateForUplinkEx1_isset;
	
	uint8_t MaximumBitRateForDownlinkEx1;
	uint8_t MaximumBitRateForDownlinkEx1_isset;
	
	uint8_t GuaranteedBitRateForUplinkEx1;
	uint8_t GuaranteedBitRateForUplinkEx1_isset;
	
	uint8_t GuaranteedBitRateForDownlinkEx1;
	uint8_t GuaranteedBitRateForDownlinkEx1_isset;
	
	uint8_t MaximumBitRateForUplinkEx2;
	uint8_t MaximumBitRateForUplinkEx2_isset;
	
	uint8_t MaximumBitRateForDownlinkEx2;
	uint8_t MaximumBitRateForDownlinkEx2_isset;
	
	uint8_t GuaranteedBitRateForUplinkEx2;
	uint8_t GuaranteedBitRateForUplinkEx2_isset;
	
	uint8_t GuaranteedBitRateForDownlinkEx2;
	uint8_t GuaranteedBitRateForDownlinkEx2_isset;

	uint8_t isset;
} NASPdu_EPSQualityOfService;



typedef struct __naspdu_ESMCause
{
	uint8_t IEI;
	uint8_t CauseValue;
	uint8_t isset;
} NASPdu_ESMCause;



typedef struct __naspdu_ESMInformationTransferFlag
{
	struct
	{
		// 1
		uint8_t EITValue : 1;
		// 4 3 2
		uint8_t Spare : 3;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_ESMInformationTransferFlag;



typedef struct __naspdu_LinkedEPSBearerIdentity
{
	struct
	{
		// 4 3 2 1
		uint8_t LinkedEPSBearerIdentityValue : 4;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_LinkedEPSBearerIdentity;



typedef struct __naspdu_LLCServiceAccessPointIdentifier
{
	uint8_t IEI;
	
	struct
	{
		// 4 3 2 1
		uint8_t LLCSAPI : 4;
		
		// 8 7 6 5
		uint8_t Spare : 4;
	} b1;
	
	uint8_t isset;	
} NASPdu_LLCServiceAccessPointIdentifier;



typedef struct __naspdu_NotificationIndicator
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t Value;
	uint8_t isset;
} NASPdu_NotificationIndicator;



typedef struct __naspdu_PacketFlowIdentifier
{
	uint8_t IEI;
	uint8_t Length;
	struct
	{
		uint8_t FlowIdentifierValue : 7;
		uint8_t Spare : 1;
	} b1;
	uint8_t isset;
} NASPdu_PacketFlowIdentifier;



typedef struct __naspdu_PDNAddress
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t PDNTypeValue : 3;
		uint8_t Spare : 5;
	} b1;
	
	u_char data[16];
	
	uint8_t isset;
} NASPdu_PDNAddress;


typedef struct __naspdu_PDNType
{
	struct
	{
		//  3 21
		uint8_t PDNTypeValue : 3;
		// 4
		uint8_t Spare : 1;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_PDNType;



typedef struct __naspdu_ProtocolConfigurationOptions
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t ConfigurationProtocol:3;
		uint8_t Spare : 4;
		uint8_t ext : 1;
	} b1;
	u_char data[253];
	uint8_t isset;
} NASPdu_ProtocolConfigurationOptions;



typedef struct __naspdu_RadioPriority
{
	struct
	{
		//  3 2 1
		uint8_t RadioPriorityLevelValue : 3;
		// 4
		uint8_t Spare : 1;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_RadioPriority;


typedef struct __naspdu_QualityOfService
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t ReliabilityClass : 3;
		uint8_t DelayClass : 3;
		uint8_t Spare : 2;
	} b1;
	
	struct
	{
		uint8_t PrecedenceClass : 3;
		uint8_t Spare : 1;
		uint8_t PeakThroughput : 4;
	} b2;
	
	struct 
	{
		uint8_t MeanThroughput : 5;
		uint8_t Spare : 3;
	} b3;
	
	struct 
	{
		uint8_t DeliveryOfErroneousSDU : 3;
		uint8_t DeliveryOrder : 2;
		uint8_t TrafficClass : 3;
	} b4;
	
	uint8_t MaximumSDUSize;
	uint8_t MaximumBitRateForUplink;
	uint8_t MaximumBitRateForDownlink;
	
	struct 
	{
		uint8_t SDUErrorRatio : 4;
		uint8_t ResidualBER : 4;
	} b5;
	
	struct 
	{
		uint8_t TrafficHandlingPriority : 2;
		uint8_t TransferDelay : 6;
	} b6;
	
	uint8_t GuaranteedBitRateForUplink;
	uint8_t GuaranteedBitRateForDownlink;
	
	struct 
	{
		uint8_t SourceStatisticsDescriptor : 4;
		uint8_t SignallingIndication : 1;
		uint8_t Spare : 3;
	} b7;
	
	uint8_t MaximumBitRateForDownlinkEx1;
	uint8_t MaximumBitRateForDownlinkEx1_isset;
	
	uint8_t GuaranteedBitRateForDownlinkEx1;
	uint8_t GuaranteedBitRateForDownlinkEx1_isset;
	
	uint8_t MaximumBitRateForUplinkEx1;
	uint8_t MaximumBitRateForUplinkEx1_isset;
	
	uint8_t GuaranteedBitRateForUplinkEx1;
	uint8_t GuaranteedBitRateForUplinkEx1_isset;
	
	uint8_t MaximumBitRateForDownlinkEx2;
	uint8_t MaximumBitRateForDownlinkEx2_isset;
	
	uint8_t GuaranteedBitRateForDownlinkEx2;
	uint8_t GuaranteedBitRateForDownlinkEx2_isset;
	
	uint8_t MaximumBitRateForUplinkEx2;
	uint8_t MaximumBitRateForUplinkEx2_isset;
	
	uint8_t GuaranteedBitRateForUplinkEx2;
	uint8_t GuaranteedBitRateForUplinkEx2_isset;
	
	u_char data[8];
	uint8_t isset;
} NASPdu_QualityOfService;


typedef struct __naspdu_ReAttemptIndicator
{
	uint8_t IEI;
	uint8_t Length;	
	struct
	{
		// 1
		uint8_t RATC : 1;
		// 2
		uint8_t EPLM : 1;
		// 8 7 6 5 4 3
		uint8_t Spare : 6;
	} b1;
	uint8_t isset;
} NASPdu_ReAttemptIndicator;



typedef struct __naspdu_RequestType
{
	struct
	{
		//  3 2 1
		uint8_t RequestTypeValue : 3;
		// 4
		uint8_t Spare : 1;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_RequestType;



typedef struct __naspdu_TrafficFlowAggregateDescription
{
	uint8_t IEI;
	uint8_t Length;	
	
	struct 
	{
		uint8_t NoOfPacketFilters : 4;
		uint8_t EBit : 1;
		uint8_t TFTOperationCode : 3;
	} b1;
	
	
	u_char data[255];
	uint8_t isset;
} NASPdu_TrafficFlowAggregateDescription;

void __si_naspdu_addEmptyTFADPacketFilterId( NASPdu_TrafficFlowAggregateDescription * pTrafficFlowTemplate, uint8_t pId);
void __si_naspdu_addTFADPacketFilter( NASPdu_TrafficFlowAggregateDescription * pTrafficFlowTemplate, uint8_t pId, uint8_t pDir, uint8_t pPEFP, uint8_t len, u_char * content);


typedef struct __naspdu_TrafficFlowTemplate
{
	uint8_t IEI;
	uint8_t Length;	
	
	struct 
	{
		uint8_t NoOfPacketFilters : 4;
		uint8_t EBit : 1;
		uint8_t TFTOperationCode : 3;
	} b1;
	
	u_char data[255];
	uint8_t isset;
} NASPdu_TrafficFlowTemplate;

void __si_naspdu_addEmptyTFTPacketFilterId( NASPdu_TrafficFlowTemplate * pTrafficFlowTemplate, uint8_t pId);
void __si_naspdu_addTFTPacketFilter( NASPdu_TrafficFlowTemplate * pTrafficFlowTemplate, uint8_t pId, uint8_t pDir, uint8_t pPEFP, uint8_t len, u_char * content);



typedef struct __naspdu_TransactionIdentifier
{
	uint8_t IEI;
	uint8_t Length;	
	
	struct
	{
		uint8_t Spare : 4;
		uint8_t T1Value : 3;
		uint8_t T1Flag : 1;
	} b1;

	struct
	{
		uint8_t T1Value : 7;
		uint8_t Ext : 1;
	} b2;
	
	uint8_t isset;
} NASPdu_TransactionIdentifier;



typedef struct __naspdu_WLANOffloadAcceptability
{
	struct
	{
		uint8_t E_UTRANOffloadAcceptabilityValue:1;
		uint8_t UTRANOffloadAcceptabilityValue:1;
		uint8_t Spare:2;
		uint8_t IEI:4;
	} b1;	
	uint8_t isset;
} NASPdu_WLANOffloadAcceptability;



typedef struct __naspdu_NBIFOMContainer
{
	uint8_t IEI;
	uint8_t Length;	
	u_char data[257];
	uint8_t isset;
} NASPdu_NBIFOMContainer;



typedef struct __naspdu_RemoteUEContextList
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[2048];
	uint8_t isset;
} NASPdu_RemoteUEContextList;



typedef struct __naspdu_PKMFAddress
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t AddressType : 4;
		uint8_t Spare : 4;
	} b1;
	
	u_char data[20];
	uint8_t isset;
} NASPdu_PKMFAddress;



typedef struct __naspdu_HeaderCompressionConfiguration
{
	uint8_t IEI;
	uint8_t Length;	
	
	struct
	{
		uint8_t P0x0002:1;
		uint8_t P0x0003:1;
		uint8_t P0x0004:1;
		uint8_t P0x0006:1;
		uint8_t P0x0102:1;
		uint8_t P0x0103:1;
		uint8_t P0x0104:1;
		uint8_t Spare : 1;
	} b1;
	
	uint16_t MAX_CID;
	
	u_char data[257];
	uint8_t isset;
} NASPdu_HeaderCompressionConfiguration;



typedef struct __naspdu_ControlPlaneOnlyIndication
{
	struct
	{
		// 1
		uint8_t CPOI : 1;
		// 4 3 2
		uint8_t Spare : 3;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;	
	uint8_t isset;
} NASPdu_ControlPlaneOnlyIndication;



typedef struct __naspdu_UserDataContainer
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[2048];
	uint8_t isset;
} NASPdu_UserDataContainer;



typedef struct __naspdu_ReleaseAssistanceIndication
{
	struct
	{
		// 2 1
		uint8_t DDX : 2;
		// 4 3
		uint8_t Spare : 2;
		// 8 7 6 5
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_ReleaseAssistanceIndication;



typedef struct __naspdu_ExtendedProtocolConfigurationOptions
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[2048];
	uint8_t isset;
} NASPdu_ExtendedProtocolConfigurationOptions;



typedef struct __naspdu_HeaderCompressionConfigurationStatus
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t EBI0:1;
		uint8_t EBI1:1;
		uint8_t EBI2:1;
		uint8_t EBI3:1;
		uint8_t EBI4:1;
		uint8_t EBI5:1;
		uint8_t EBI6:1;
		uint8_t EBI7:1;
	} b1;
	
	struct
	{
		uint8_t EBI8:1;
		uint8_t EBI9:1;
		uint8_t EBI10:1;
		uint8_t EBI11:1;
		uint8_t EBI12:1;
		uint8_t EBI13:1;
		uint8_t EBI14:1;
		uint8_t EBI15:1;
	} b2;
	
	uint8_t isset;	
} NASPdu_HeaderCompressionConfigurationStatus;



typedef struct __naspdu_ServingPLMNRateControl
{
	uint8_t isset;
	uint8_t IEI;
	uint8_t Length;
	uint16_t RateControlValue;
} NASPdu_ServingPLMNRateControl;



typedef struct __naspdu_ExtendedAPNAggregateMaximumBitRate
{
	uint8_t IEI;
	uint8_t Length;	
	
	uint8_t UnitForExtendedAPNAMBRForDownlink;
	uint16_t ExtendedAPNAMBRForDownlink;
	
	uint8_t UnitForExtendedAPNAMBRForUplink;
	uint16_t ExtendedAPNAMBRForUplink;
	
	uint8_t isset;
} NASPdu_ExtendedAPNAggregateMaximumBitRate;



typedef struct __naspdu_ExtendedQualityOfService
{
	uint8_t IEI;
	uint8_t Length;	
	
	uint8_t UnitForMaximumBitRate;
	uint16_t MaximumBitRateForUplink;
	uint16_t MaximumBitRateForDownlink;
	uint8_t UnitForGuaranteedBitRate;
	uint16_t GuaranteedBitRateForUplink;
	uint16_t GuaranteedBitRateForDownlink;
	
	uint8_t isset;
} NASPdu_ExtendedQualityOfService;
// ----------------------------------------------------------------------------------------------
// 5G IE
typedef struct __naspdu_eap_message
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[1503];
	uint8_t isset;
} NASPdu_EAPMessage; 

typedef struct __naspdu_snssai
{
	uint8_t IEI;
	uint8_t Length;
	
	uint8_t SST;
	u_char SliceDifferentiator[3];
	uint8_t MappedConfiguredSST;
	u_char MappedConfiguredSD[3];
	
	uint8_t isset;
} NASPdu_SNSSAI; 

typedef struct __naspdu_s1n1nas_transparent_container
{
	uint8_t IEI;
	uint8_t Length;
	
	u_char MessageAuthenticationCode[3];
	
	struct
	{
		uint8_t TypeOfIntegrityProtectionAlgorithm : 4;
		uint8_t TypeOfCipheringAlgorithm : 4;
	} b1;
	
	struct
	{
		uint8_t KeySetIdentifierIn5G : 3;
		uint8_t TSC : 1;
		uint8_t NASCount : 4;
	} b2;
	
	u_char FGUESecurityCapability[2];
	u_char EPSUESecurityCapability[2];
	
	uint8_t isset;
} NASPdu_S1N1NasTransparentContainer; 

typedef struct __naspdu_fgmm_abba
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t isset;
	u_char data[255];
} NASPdu_FGMMABBA;

typedef struct __naspdu_FGMMNASSecurityAlgorithms
{
	uint8_t IEI;

	struct
	{
		uint8_t TypeOfIntegrityProtectionAlgorithm : 4;
		uint8_t TypeOfCipheringAlgorithm : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_FGMMNASSecurityAlgorithms;

typedef struct __naspdu_FGMM_UESecurityCapability
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t FGEA7 : 1;
		uint8_t FGEA6 : 1;
		uint8_t FGEA5 : 1;
		uint8_t FGEA4 : 1;
		uint8_t FGEA3 : 1;
		uint8_t FGEA2 : 1;
		uint8_t FGEA1 : 1;
		uint8_t FGEA0 : 1;
	} b1;
	
	struct
	{
		uint8_t FGIA7 : 1;
		uint8_t FGIA6 : 1;
		uint8_t FGIA5 : 1;
		uint8_t FGIA4 : 1;
		uint8_t FGIA3 : 1;
		uint8_t FGIA2 : 1;
		uint8_t FGIA1 : 1;
		uint8_t FGIA0 : 1;
	} b2;
	
	struct
	{
		uint8_t EGEA7 : 1;
		uint8_t EGEA6 : 1;
		uint8_t EGEA5 : 1;
		uint8_t EGEA4 : 1;
		uint8_t EGEA3 : 1;
		uint8_t EGEA2 : 1;
		uint8_t EGEA1 : 1;
		uint8_t EGEA0 : 1;
	} b3;
	
	struct
	{
		uint8_t EGEI7 : 1;
		uint8_t EGEI6 : 1;
		uint8_t EGEI5 : 1;
		uint8_t EGEI4 : 1;
		uint8_t EGEI3 : 1;
		uint8_t EGEI2 : 1;
		uint8_t EGEI1 : 1;
		uint8_t EGEI0 : 1;
	} b4;
	
	uint8_t isset;
} NASPdu_FGMM_UESecurityCapability;

typedef struct __naspdu_fgmm_capability
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t S1Mode : 1;
		uint8_t HOAttach : 1;
		uint8_t LTEPP : 1;
		uint8_t Spare : 5;
	} b1;
	
	uint8_t Spare;
	u_char data[15];
	
	uint8_t isset;
} NASPdu_FGMMCapability; 

typedef struct __naspdu_fgmm_cause
{
	uint8_t IEI;
	uint8_t CauseValue;
	uint8_t isset;
} NASPdu_FGMMCause;

typedef struct __naspdu_fgs_identity_type
{
	struct
	{
		uint8_t TypeOfIdentity:3;
		uint8_t Spare:1;
		uint8_t IEI:4;
	} b1;
	uint8_t isset;
} NASPdu_FGSIdentityType;

typedef struct __naspdu_fgs_update_type
{
	uint8_t IEI;
	uint8_t Length;
	struct
	{
		uint8_t SMSRequested:1;
		uint8_t NGRAN_RCU:1;
		uint8_t Spare:6;
	} b1;
	uint8_t isset;
} NASPdu_FGSUpdateType;


#define FGS_MOBILE_IDENTITY_NONE			0
#define FGS_MOBILE_IDENTITY_SUCI			1
#define FGS_MOBILE_IDENTITY_5G_GUTI			2
#define FGS_MOBILE_IDENTITY_IMEI			3
#define FGS_MOBILE_IDENTITY_5G_S_TMSI		4
#define FGS_MOBILE_IDENTITY_IMEISV			5

typedef struct __naspdu_fgs_mobile_identity
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[255];
	uint8_t isset;
	
	/*
	uint8_t typeOfId;
	u_char mccmnc[3];
	uint8_t AMFReginId;
	uint16_t AMFSetId;
	uint8_t AMFPointer;
	*/
		
} NASPdu_FGSMobileIdentity;

typedef struct __naspdu_fgs_network_feature_support
{
	uint8_t IEI;
	uint8_t Length;
	struct
	{
		uint8_t IMSVoPS : 2;
		uint8_t EMC : 2;
		uint8_t EMF : 2;
		uint8_t IWKN26 : 1;
		uint8_t MPSI : 1;
	} b1;
	uint8_t isset;	
} NASPdu_FGSNetworkFeatureSupport;

typedef struct __naspdu_fgs_registration_result
{
	uint8_t IEI;
	uint8_t Length;
	struct
	{
		uint8_t FGSRegistrationResultValue : 3;
		uint8_t SMSAllowed : 1;
		uint8_t Spare : 4;
	} b1;
	uint8_t isset;	
} NASPdu_FGSRegistrationResult;

typedef struct __naspdu_fgs_registration_type
{
	struct
	{
		uint8_t FGSRegistrationTypeValue : 3;
		uint8_t FOR : 1;
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;	
} NASPdu_FGSRegistrationType;

typedef struct __naspdu_access_type
{
	struct
	{
		uint8_t AccessType : 2;
		uint8_t Spare : 2;
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;	
} NASPdu_AccessType;

typedef struct __naspdu_allowed_pdu_session_status
{
	uint8_t IEI;
	uint8_t Length;

	struct
	{
		uint8_t PSI0:1;
		uint8_t PSI1:1;
		uint8_t PSI2:1;
		uint8_t PSI3:1;
		uint8_t PSI4:1;
		uint8_t PSI5:1;
		uint8_t PSI6:1;
		uint8_t PSI7:1;
	} b1;

	struct
	{
		uint8_t PSI08:1;
		uint8_t PSI09:1;
		uint8_t PSI10:1;
		uint8_t PSI11:1;
		uint8_t PSI12:1;
		uint8_t PSI13:1;
		uint8_t PSI14:1;
		uint8_t PSI15:1;
	} b2;
	
	u_char data[34];
	uint8_t isset;
} NASPdu_AllowedPDUSessionStatus;

typedef struct __naspdu_configuration_update_indication
{
	struct
	{
		uint8_t ACK : 2;
		uint8_t RED : 2;
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;	
} NASPdu_ConfiguratinUpdateIndication;

typedef struct __naspdu_deregistration_type
{
	struct
	{
		uint8_t AccessType : 2;
		uint8_t RegistrationRequired : 1;
		uint8_t SwitchOff : 1;
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;	
} NASPdu_DeRegistrationType;

typedef struct __naspdu_dnn
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[102];
	uint8_t isset;
} NASPdu_DNN;

typedef struct __naspdu_epsnas_message_container
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[1024];
	uint8_t isset;
} NASPdu_EPSNASMessageContainer;

typedef struct __naspdu_eps_nas_security_algorithms
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t isset;
} NASPdu_EPSNASSecurityAlgorithms;

/*
typedef struct __naspdu_extended_emergency_number_list
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t isset;
} NASPdu_ExtendedEmergencyNumberList;
*/

typedef struct __naspdu_hashamf
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[12];
	uint8_t isset;
} NASPdu_HashAMF;

typedef struct __naspdu_ladn
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[1024];
	uint8_t isset;
} NASPdu_LADN;

typedef struct __naspdu_mico
{
	struct
	{
		uint8_t RAAI : 1;
		uint8_t Spare : 3;
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;	
} NASPdu_MICO;

typedef struct __naspdu_security_algorithms
{
	uint8_t IEI;
	struct
	{
		uint8_t TypeOfIntegrityProtectionAlgorithm : 4;
		uint8_t TypeOfCipheringAlgorithm : 4;
	} b1;
	uint8_t isset;
} NASPdu_SecurityAlgorithms;

typedef struct __naspdu_nssai
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[146];
	uint8_t isset;
} NASPdu_NSSAI;

typedef struct __naspdu_payload_container
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[2048];
	uint8_t isset;
} NASPdu_PayloadContainer;

typedef struct __naspdu_pdu_session_reactivation_result
{
	uint8_t IEI;
	uint8_t Length;

	struct
	{
		uint8_t PSI0:1;
		uint8_t PSI1:1;
		uint8_t PSI2:1;
		uint8_t PSI3:1;
		uint8_t PSI4:1;
		uint8_t PSI5:1;
		uint8_t PSI6:1;
		uint8_t PSI7:1;
	} b1;

	struct
	{
		uint8_t PSI08:1;
		uint8_t PSI09:1;
		uint8_t PSI10:1;
		uint8_t PSI11:1;
		uint8_t PSI12:1;
		uint8_t PSI13:1;
		uint8_t PSI14:1;
		uint8_t PSI15:1;
	} b2;
	
	u_char data[34];
	uint8_t isset;
} NASPdu_PDUSessionReactivationResult;


typedef struct __naspdu_pdu_session_reactivation_error_cause
{
	uint8_t IEI;
	uint16_t Length;
	uint8_t PDUSessionID;
	uint8_t CauseValue;
	
	u_char data[515];
	uint8_t isset;
} NASPdu_PDUSessionReactivationErrorCause;

typedef struct __naspdu_pdu_session_status
{
	uint8_t IEI;
	uint8_t Length;

	struct
	{
		uint8_t PSI0:1;
		uint8_t PSI1:1;
		uint8_t PSI2:1;
		uint8_t PSI3:1;
		uint8_t PSI4:1;
		uint8_t PSI5:1;
		uint8_t PSI6:1;
		uint8_t PSI7:1;
	} b1;

	struct
	{
		uint8_t PSI08:1;
		uint8_t PSI09:1;
		uint8_t PSI10:1;
		uint8_t PSI11:1;
		uint8_t PSI12:1;
		uint8_t PSI13:1;
		uint8_t PSI14:1;
		uint8_t PSI15:1;
	} b2;
	
	u_char data[34];
	uint8_t isset;
} NASPdu_PDUSessionStatus;

typedef struct __naspdu_rejected_nssai
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[42];
	uint8_t isset;
} NASPdu_RejectedNSSAI;

typedef struct __naspdu_service_area_list
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[114];
	uint8_t isset;
} NASPdu_ServiceAreaList;

typedef struct __naspdu_fg_ue_security_capability
{
	uint8_t IEI;
	struct
	{
		uint8_t FGEA7 : 1;
		uint8_t FGEA6 : 1;
		uint8_t FGEA5 : 1;
		uint8_t FGEA4 : 1;
		uint8_t FG1285GEA3 : 1;
		uint8_t FG1285GEA2 : 1;
		uint8_t FG1285GEA1 : 1;
		uint8_t FGEA0 : 1;
	} b1;
	
	struct
	{
		uint8_t FG5GIA7 : 1;
		uint8_t FG5GIA6 : 1;
		uint8_t FG5GIA5 : 1;
		uint8_t FG5GIA4 : 1;
		uint8_t FG1285GIA3 : 1;
		uint8_t FG1285GIA2 : 1;
		uint8_t FG1285GIA1 : 1;
		uint8_t FGIA0 : 1;
	} b2;
	
	struct
	{
		uint8_t FGEEA7 : 1;
		uint8_t FGEEA6 : 1;
		uint8_t FGEEA5 : 1;
		uint8_t FGEEA4 : 1;
		uint8_t FG128EEA3 : 1;
		uint8_t FG128EEA2 : 1;
		uint8_t FG128EEA1 : 1;
		uint8_t FGEEA0 : 1;
	} b3;
	
	struct
	{
		uint8_t FGEIA7 : 1;
		uint8_t FGEIA6 : 1;
		uint8_t FGEIA5 : 1;
		uint8_t FGEIA4 : 1;
		uint8_t FG128EIA3 : 1;
		uint8_t FG128EIA2 : 1;
		uint8_t FG128EIA1 : 1;
		uint8_t FGEIA0 : 1;
	} b4;
	
	uint8_t isset;
} NASPdu_FGUESecurityCapability;

typedef struct __naspdu_ue_usage_setting
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t Spare : 7;
		uint8_t UEUsageSetting : 1;
	} b1;
	
	uint8_t isset;
} NASPdu_UEUsageSetting;

typedef struct __naspdu_uplink_data_status
{
	uint8_t IEI;
	uint8_t Length;

	struct
	{
		uint8_t PSI0:1;
		uint8_t PSI1:1;
		uint8_t PSI2:1;
		uint8_t PSI3:1;
		uint8_t PSI4:1;
		uint8_t PSI5:1;
		uint8_t PSI6:1;
		uint8_t PSI7:1;
	} b1;

	struct
	{
		uint8_t PSI08:1;
		uint8_t PSI09:1;
		uint8_t PSI10:1;
		uint8_t PSI11:1;
		uint8_t PSI12:1;
		uint8_t PSI13:1;
		uint8_t PSI14:1;
		uint8_t PSI15:1;
	} b2;
	
	u_char data[34];
	uint8_t isset;
} NASPdu_UplinkDataStatus;

typedef struct __naspdu_fgsm_capability
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t RqoS : 1;
		uint8_t MH6PDU : 1;
		uint8_t Spare : 6;
	} b1;
	
	uint8_t isset;
} NASPdu_FGSMCapability;

typedef struct __naspdu_fgsm_cause
{
	uint8_t IEI;
	uint8_t CauseValue;
	uint8_t isset;
} NASPdu_FGSMCause;

typedef struct __naspdu_allowed_ssc_mode
{
	struct
	{
		uint8_t SSC1: 1;
		uint8_t SSC2: 1;
		uint8_t SSC3: 1;
		uint8_t Spare: 1;
		uint8_t IEI : 4;
	} b1;
	uint8_t isset;
} NASPdu_AllowedSSCMode;

typedef struct __naspdu_mapped_eps_bearer_contexts
{
	uint8_t IEI;
	uint8_t Length;
	
	u_char data[2048];
	uint8_t isset;	
} NASPdu_MappedEPSBearerContexts;

typedef struct __naspdu_maximum_number_of_supported_packet_filters
{
	uint8_t IEI;
	uint16_t FilterCount;
	uint8_t isset;	
} NASPdu_MaximumNumberOfSupportedPacketFilters;

typedef struct __naspdu_pdu_address
{
	uint8_t IEI;
	uint8_t Length;
	
	struct
	{
		uint8_t PDUSessionTypeValue : 3;
		uint8_t Spare : 5;
	} b1;
	
	u_char data[40];
	uint8_t isset;	
} NASPdu_PDUAddress;

typedef struct __naspdu_integrity_protection_maximum_data_rate
{
	uint8_t IEI;
	uint8_t MaximumDataRatePerUEForUserPlaneIntegrityProtection_Uplink;
	uint8_t MaximumDataRatePerUEForUserPlaneIntegrityProtection_Downlink;
	uint8_t isset;
} NASPdu_IntegrityProtectionMaximumDataRate;

typedef struct __naspdu_pdu_session_type
{
	struct
	{
		uint8_t PDUSessionTypeValue : 3;
		uint8_t Spare : 1;
		uint8_t IEI : 4;
	} b1;
	
	uint8_t isset;
} NASPdu_PDUSessionType;

typedef struct __naspdu_qos_rules
{
	uint8_t IEI;
	uint16_t Length;
	u_char data[2048];
	uint8_t isset;
} NASPdu_QosRules;

typedef struct __naspdu_session_ambr
{
	uint8_t IEI;
	uint8_t Length;
	uint8_t isset;
	uint8_t UnitForSessionAMBRForDownlink;
	uint16_t SessionAMBRForDownlink;
	uint8_t UnitForSessionAMBRForUplink;
	uint16_t SessionAMBRForUplink;
} NASPdu_SessionAMBR;

typedef struct __naspdu_sm_pdu_dn_request_container
{
	uint8_t IEI;
	uint8_t Length;
	u_char data[2048];
	uint8_t isset;
} NASPdu_SMPDUDNRequestContainer;

typedef struct __naspdu_ssc_mode
{
	struct
	{
		uint8_t SSCModeValue:3;
		uint8_t Spare:1;
		uint8_t IEI:4;
	} b1;
	uint8_t isset;
} NASPdu_SSCMode;



// ----------------------------------------------------------------------------------------------

typedef struct __naspduBase
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;	
} NASPduBase;

typedef struct __naspduAttachAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EPSAttachResult mEPSAttachResult;
	NASPdu_GPRSTimer mGPRSTimer;
	NASPdu_TrackingAreaIdentityList mTAIList;
	NASPdu_ESMMessageContainer mESMMessageContainer;

	NASPdu_EPSMobileIdentity mGUTI;
	NASPdu_LocationAreaIdentification mLocationAreaIdentification;
	NASPdu_MobileIdentity mMSIdentity;
	NASPdu_EMMCause mEMMCause;
	NASPdu_GPRSTimer mT3402value;
	NASPdu_GPRSTimer mT3423value;
	NASPdu_PLMNList mEquivalentPLMNs;
	NASPdu_EmergencyNumberList mEmergencyNumberList;
	NASPdu_EPSNetworkFeatureSupport mEPSNetworkFeatureSupport;
	NASPdu_AdditionalUpdateResult mAdditionalUpdateResult;
	NASPdu_GPRSTimer3 mT3412ExtendedValue;
	NASPdu_GPRSTimer2 mT3324value;
	NASPdu_ExtendedDRXParameters mExtendedDRXParameters;
	NASPdu_DCNID mDCNID;
	NASPdu_SMSServicesStatus mSMSServicesStatus;
	NASPdu_Non3GPPNWProvidedPolicies mNon3GPPNWProvidedPolicies;
	NASPdu_GPRSTimer2 mT3448Value;
	NASPdu_NetworkPolicy mNetworkPolicy;
	NASPdu_GPRSTimer3 mT3447Value;
	NASPdu_ExtendedEmergencyNumberList mExtendedEmergencyNumberList;
	NASPdu_CipheringKeyData mCipheringKeyData;
	
} NASPduAttachAccept;

typedef struct __naspduAttachComplete
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	NASPdu_ESMMessageContainer mESMMessageContainer;
} NASPduAttachComplete;

typedef struct __naspduAttachReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EMMCause mEMMCause;
	
	NASPdu_ESMMessageContainer mESMMessageContainer;	
	NASPdu_GPRSTimer2 mT3346Value;
	NASPdu_GPRSTimer2 mT3402Value;
	NASPdu_ExtendedEMMCause mExtendedEMMCause;
	
} NASPduAttachReject;

typedef struct __naspduAttachRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;

	struct
	{
		uint8_t EPSAttachType : 3;
		uint8_t SpareBits : 1;
		uint8_t NASKeySetId : 3;
		uint8_t TSC : 1;
	} b1;

	
	NASPdu_EPSMobileIdentity mEPSMobileIdentity;
	NASPdu_UENetworkCapability mUENetworkCapability;
	NASPdu_ESMMessageContainer mESMMessageContainer;
	
	// ---------Optional---------------
	NASPdu_PTMSISignature mOldPTMSISignature;
	NASPdu_EPSMobileIdentity mAdditionalGUTI;
	NASPdu_TrackingAreaIdentity mLastVisitedRegisteredTAI;
	NASPdu_DRXParameter mDRXParameter;
	NASPdu_MSNetworkCapability mSNetworkCapability;
	NASPdu_LocationAreaIdentification mOldLocationAreaIdentification;
	NASPdu_TMSIStatus mTMSIStatus;
	NASPdu_MobileStationClassmark2 mMobileStationClassmark2;
	NASPdu_MobileStationClassmark3 mMobileStationClassmark3;
	NASPdu_SupportedCodecList mSupportedCodecList;
	NASPdu_AdditionalUpdateType mAdditionalUpdateType;
	NASPdu_VoiceDomainPreferenceAndUEsUsageSetting mVoiceDomainPreferenceAndUEsUsageSetting;
	NASPdu_DeviceProperties mDeviceProperties;
	NASPdu_GUTIType mOldGUTIType;
	NASPdu_MSNetworkFeatureSupport mMSNetworkFeatureSupport;
	NASPdu_NetworkResourceIdentifierContainer mNetworkResourceIdentifierContainer;
	NASPdu_GPRSTimer2 mT3324Value;
	NASPdu_GPRSTimer3 mT3412ExtendedValue;
	NASPdu_ExtendedDRXParameters mExtendedDRXParameters; 
	NASPdu_UEAdditionalSecurityCapability mUEAdditionalSecurityCapability;
	NASPdu_UEStatus mUEStatus;
	NASPdu_AdditionalInformationRequested mAdditionalInformationRequested;
		
} NASPduAttachRequest;


typedef struct __naspduAuthenticationFailure
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;

	NASPdu_EMMCause mEMMCause;
	NASPdu_AuthenticationFailureParameter mAuthenticationFailureParameter;
} NASPduAuthenticationFailure;

typedef struct __naspduAuthenticationReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
} NASPduAuthenticationReject;

typedef struct __naspduAuthenticationRequest
{
	NASPduSecurityHeader sHeader;
	
	//plain header
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t NASKeySetId : 3;
		uint8_t TSC : 1;
		uint8_t SpareBits : 4;
	} b1;
	
	NASPdu_AuthenticationParameterRAND authenticationParameterRAND;
	NASPdu_AuthenticationParameterAUTN authenticationParameterAUTN;
	
} NASPduAuthenticationRequest;

typedef struct __naspduAuthenticationResponse
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_AuthenticationResponseParameter authenticationResponseParameter;
	
} NASPduAuthenticationResponse;


typedef struct __naspduCSServiceNotification
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_PagingIdentity mPagingIdentity;
	NASPdu_CLI mCLI;
	NASPdu_SSCode mSSCode;
	NASPdu_LCSIndicator mLCSIndicator;
	NASPdu_LCSClientIdentity mLCSClientIdentity;
} NASPduCSServiceNotification;


typedef struct __naspduDetachAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
} NASPduDetachAccept;

typedef struct __naspduDetachRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t DetachType : 3;
		uint8_t SwitchOff : 1;
		uint8_t NASKeySetId : 3;
		uint8_t TSC : 1;
	} b1;
	
	NASPdu_EPSMobileIdentity mEPSMobileIdentity;
	
} NASPduDetachRequest;

typedef struct __naspduDownlinkNASTransport
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_NASMessageContainer mNASMessageContainer;
} NASPduDownlinkNASTransport;

typedef struct __naspduEMMInformation
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;

	NASPdu_NetworkName mFullNameForNetwork;
	NASPdu_NetworkName mShortNameForNetwork;
	NASPdu_TimeZone mLocalTimeZone;
	NASPdu_TimeZoneAndTime mUniversalTimeAndLocalTimeZone;
	NASPdu_DaylightSavingTime mNetworkDaylightSavingTime; 
	
} NASPduEMMInformation;

typedef struct __naspduEMMStatus
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EMMCause mEMMCause;
} NASPduEMMStatus;

typedef struct __naspduExtendedServiceRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t NASKeySetId : 4;
		uint8_t ServiceType : 4;
	} b1;
	
	NASPdu_MobileIdentity mMTMSI;
	
	
	NASPdu_CSFBResponse mCSFBResponse;
	NASPdu_EPSBearerContextStatus mEPSBearerContextStatus;
	NASPdu_DeviceProperties mDeviceProperties;
	
} NASPduExtendedServiceRequest;

typedef struct __naspduGUTIReallocationCommand
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EPSMobileIdentity mGUTI;
	NASPdu_TrackingAreaIdentityList mTAIList;
	NASPdu_DCNID mDCNID;
} NASPduGUTIReallocationCommand;

typedef struct __naspduGUTIReallocationComplete
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
} NASPduGUTIReallocationComplete;

typedef struct __naspduIdentityRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t IdentityType : 4;
		uint8_t Spare:4;
	} b1;
} NASPduIdentityRequest;

typedef struct __naspduIdentityResponse
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_MobileIdentity mMobileIdentity;
} NASPduIdentityResponse;

typedef struct __naspduSecurityModeCommand
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_NASSecurityAlgorithms nASSecurityAlgorithms;
	
	struct
	{
		uint8_t NASKeySetId : 3;
		uint8_t TSC : 1;
		uint8_t SpareBits : 4;
	} b2;
	
	NASPdu_UESecurityCapability uESecurityCapability;
	
	// O
	NASPdu_IMEISVRequest mIMEISVRequest;
	NASPdu_Nonce mReplayedNonceUE;
	NASPdu_Nonce mNonceMME;
	NASPdu_HashMME mHashMME;
	NASPdu_UEAdditionalSecurityCapability mReplayedUEAdditionalSecurityCapability;
	
} NASPduSecurityModeCommand;

typedef struct __naspduSecurityModeComplete
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_MobileIdentity mIMEISV;
	NASPdu_ReplayedNASMessageContainer mReplayedNASMessageContainer;
} NASPduSecurityModeComplete;

typedef struct __naspduSecurityModeReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EMMCause mEMMCause;
} NASPduSecurityModeReject;

typedef struct __naspduSecurityProtectedNASMessage
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_NASMessageContainer mNASMessage;
} NASPduSecurityProtectedNASMessage;

typedef struct __naspduServiceReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EMMCause mEMMCause; 	
	
	NASPdu_GPRSTimer mT3442Value;
	NASPdu_GPRSTimer2 mT3346Value;
	NASPdu_GPRSTimer2 mT3448Value;	
} NASPduServiceReject;


typedef struct __naspduServiceRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_KSIAndSequenceNumber mKSIAndSequenceNumber;
	NASPdu_ShortMAC mMAC;
} NASPduServiceRequest;


typedef struct __naspduTrackingAreaUpdateAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t EPSUpdateResult : 4;
		uint8_t Spare : 4;
	} b1;
	
	
	NASPdu_GPRSTimer mT3412Value;
	NASPdu_EPSMobileIdentity mGUTI;
	NASPdu_TrackingAreaIdentityList mTAIList;
	NASPdu_EPSBearerContextStatus mEPSBearerContextStatus;
	NASPdu_LocationAreaIdentification mLocationAreaIdentification;
	NASPdu_MobileIdentity mMobileIdentity;
	NASPdu_EMMCause mEMMCause;
	NASPdu_GPRSTimer mT3402Value;
	NASPdu_GPRSTimer mT3423Value;
	NASPdu_PLMNList mEquivalentPLMNs;
	NASPdu_EmergencyNumberList mEmergencyNumberList;
	NASPdu_EPSNetworkFeatureSupport mEPSNetworkFeatureSupport;
	NASPdu_AdditionalUpdateResult mAdditionalUpdateResult;
	NASPdu_GPRSTimer3 mT3412ExtendedValue;
	NASPdu_GPRSTimer2 mT3324Value;
	NASPdu_ExtendedDRXParameters mExtendedDRXParameters;
	NASPdu_HeaderCompressionConfigurationStatus mHeaderCompressionConfigurationStatus;
	NASPdu_DCNID mDCNID;
	NASPdu_SMSServicesStatus mSMSServicesStatus;
	NASPdu_Non3GPPNWProvidedPolicies mNon3GPPNWProvidedPolicies;
	NASPdu_GPRSTimer2 mT3448Value;
	NASPdu_NetworkPolicy mNetworkPolicy;
	NASPdu_GPRSTimer3 mT3447Value;
	NASPdu_ExtendedEmergencyNumberList mExtendedEmergencyNumberList;
	NASPdu_CipheringKeyData mCipheringKeyData;
	
} NASPduTrackingAreaUpdateAccept;


typedef struct __naspduTrackingAreaUpdateComplete
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	
} NASPduTrackingAreaUpdateComplete;


typedef struct __naspduTrackingAreaUpdateReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EMMCause mEMMCause;
	NASPdu_GPRSTimer2 mT3346Value;
	NASPdu_ExtendedEMMCause mExtendedEMMCause;	
} NASPduTrackingAreaUpdateReject;


typedef struct __naspduTrackingAreaUpdateRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct 
	{
		uint8_t EPSUpdateType : 3;
		uint8_t ActiveFlag : 1;
		uint8_t NASKeySetId : 3;
		uint8_t TSC:1;
	} b1;
	
	NASPdu_EPSMobileIdentity mOldGUTI;
	
	
	NASPdu_NASKeySetIdentifier mNonCurrentNativeNASKeySetIdentifier;
	NASPdu_CipheringKeySequenceNumber mGPRSCipheringKeySequenceNumber;
	NASPdu_PTMSISignature mOldPTMSISignature;
	NASPdu_EPSMobileIdentity mAdditionalGUTI;
	NASPdu_Nonce mNonceUE;
	NASPdu_UENetworkCapability mUENetworkCapability;
	NASPdu_TrackingAreaIdentity mLastVisitedRegisteredTAI;
	NASPdu_DRXParameter mDRXParameter;
	NASPdu_UERadioCapabilityInformationUpdateNeeded mUERadioCapabilityInformationUpdateNeeded;
	NASPdu_EPSBearerContextStatus mEPSBearerContextStatus;
	NASPdu_MSNetworkCapability mMSNetworkCapability;
	NASPdu_LocationAreaIdentification mLocationAreaIdentification;
	NASPdu_TMSIStatus mTMSIStatus; 
	NASPdu_MobileStationClassmark2 mMobileStationClassmark2;
	NASPdu_MobileStationClassmark3 mMobileStationClassmark3;
	NASPdu_SupportedCodecList mSupportedCodecs;
	NASPdu_AdditionalUpdateType mAdditionalUpdateType;
	NASPdu_VoiceDomainPreferenceAndUEsUsageSetting mVoiceDomainPreferenceAndUEsUsageSetting; 
	NASPdu_GUTIType mOldGUTIType;
	NASPdu_DeviceProperties mDeviceProperties; 
	NASPdu_MSNetworkFeatureSupport mMSNetworkFeatureSupport; 
	NASPdu_NetworkResourceIdentifierContainer mTMSIBasedNRIContainer;
	NASPdu_GPRSTimer2 mT3324Value;
	NASPdu_GPRSTimer3 mT3412ExtendedValue;
	NASPdu_ExtendedDRXParameters mExtendedDRXParameters;
	NASPdu_UEAdditionalSecurityCapability mUEAdditionalSecurityCapability;
	NASPdu_UEStatus mUEStatus;
	NASPdu_AdditionalInformationRequested mAdditionalInformationRequested;
	
} NASPduTrackingAreaUpdateRequest;


typedef struct __naspduUplinkNASTransport
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_NASMessageContainer mNASMessageContainer;
} NASPduUplinkNASTransport;


typedef struct __naspduDownlinkGenericNASTransport
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_GenericMessageContainerType mGenericMessageContainerType;
	NASPdu_GenericMessageContainer mGenericMessageContainer; 
	NASPdu_AdditionalInformation mAdditionalInformation;
	
} NASPduDownlinkGenericNASTransport;


typedef struct __naspduUplinkGenericNASTransport
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_GenericMessageContainerType mGenericMessageContainerType;
	NASPdu_GenericMessageContainer mGenericMessageContainer; 
	NASPdu_AdditionalInformation mAdditionalInformation;
	
} NASPduUplinkGenericNASTransport;


typedef struct __naspduControlPlaneServiceRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t ControlPlaneServiceType: 3;
		uint8_t ActiveFlag: 1;
		uint8_t NASKeySetId: 3;
		uint8_t TSC:1;
	} b1;
	
	NASPdu_ESMMessageContainer mESMMessageContainer;
	NASPdu_NASMessageContainer mNASMessageContainer;
	NASPdu_EPSBearerContextStatus mEPSBearerContextStatus;
	NASPdu_DeviceProperties mDeviceProperties;
	
} NASPduControlPlaneServiceRequest;


typedef struct __naspduServiceAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EPSBearerContextStatus mEPSBearerContextStatus;
	NASPdu_GPRSTimer2 mGPRSTimer2;
} NASPduServiceAccept;


// ESM

typedef struct __naspduActivateDedicatedEPSBearerContextAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduActivateDedicatedEPSBearerContextAccept;


typedef struct __naspduActivateDedicatedEPSBearerContextReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduActivateDedicatedEPSBearerContextReject;


typedef struct __naspduActivateDedicatedEPSBearerContextRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t Spare : 4;
		uint8_t LinkedEPSBearerIdentity : 4;
	} b1;
	
	NASPdu_EPSQualityOfService mEPSQoS;
	NASPdu_TrafficFlowTemplate mTFT;
	
	NASPdu_TransactionIdentifier mTransactionIdentifier;
	NASPdu_QualityOfService mNegotiatedQoS;
	NASPdu_LLCServiceAccessPointIdentifier mNegotiatedLLCSAPI;
	NASPdu_RadioPriority mRadioPriority; 
	NASPdu_PacketFlowIdentifier mPacketFlowIdentifier; 
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_WLANOffloadAcceptability mWLANOffloadAcceptability;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	NASPdu_ExtendedQualityOfService mExtendedEPSQoS;

} NASPduActivateDedicatedEPSBearerContextRequest;


typedef struct __naspduActivateDefaultEPSBearerContextAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;

	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduActivateDefaultEPSBearerContextAccept;


typedef struct __naspduActivateDefaultEPSBearerContextReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;

	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduActivateDefaultEPSBearerContextReject;


typedef struct __naspduActivateDefaultEPSBearerContextRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EPSQualityOfService mEPSQoS;
	NASPdu_AccessPointName mAccessPointName;
	NASPdu_PDNAddress mPDNAddress;
	
	NASPdu_TransactionIdentifier mTransactionIdentifier;
	NASPdu_QualityOfService mNegotiatedQoS;
	NASPdu_LLCServiceAccessPointIdentifier mNegotiatedLLCSAPI;
	NASPdu_RadioPriority mRadioPriority;
	NASPdu_PacketFlowIdentifier mPacketFlowIdentifier;
	NASPdu_APNAggregateMaximumBitRate mAPNAMBR;
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ConnectivityType mConnectivityType;
	NASPdu_WLANOffloadAcceptability mWLANOffloadAcceptability;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_HeaderCompressionConfiguration mHeaderCompressionConfiguration;
	NASPdu_ControlPlaneOnlyIndication mControlPlaneOnlyIndication;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	NASPdu_ServingPLMNRateControl mServingPLMNRateControl;
	NASPdu_ExtendedAPNAggregateMaximumBitRate mExtendedAPNAMBR;
	
} NASPduActivateDefaultEPSBearerContextRequest;


typedef struct __naspduBearerResourceAllocationReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_GPRSTimer3 mBackOffTimerValue;
	NASPdu_ReAttemptIndicator mReAttemptIndicator;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduBearerResourceAllocationReject;


typedef struct __naspduBearerResourceAllocationRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t LinkedEPSBearerIdentity : 4;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_TrafficFlowAggregateDescription mTrafficFlowAggregate;
	NASPdu_EPSQualityOfService mRequiredTrafficFlowQoS;
	
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_DeviceProperties mDeviceProperties;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	NASPdu_ExtendedQualityOfService mExtendedEPSQoS;
	
} NASPduBearerResourceAllocationRequest;


typedef struct __naspduBearerResourceModificationReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_GPRSTimer3 mBackOffTimerValue;
	NASPdu_ReAttemptIndicator mReAttemptIndicator;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduBearerResourceModificationReject;


typedef struct __naspduBearerResourceModificationRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t Spare : 4;
		uint8_t EPSBearerIdentityForPacketFilter : 4;
	} b1;
	
	NASPdu_TrafficFlowAggregateDescription mTrafficFlowAggregate;
	
	NASPdu_EPSQualityOfService mRequiredTrafficFlowQoS;
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_DeviceProperties mDeviceProperties;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_HeaderCompressionConfiguration mHeaderCompressionConfiguration;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	NASPdu_ExtendedQualityOfService mExtendedQualityOfService;
	
} NASPduBearerResourceModificationRequest;


typedef struct __naspduDeactivateEPSBearerContextAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduDeactivateEPSBearerContextAccept;

typedef struct __naspduDeactivateEPSBearerContextRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_GPRSTimer3 mT3396Value;
	NASPdu_WLANOffloadAcceptability mWLANOffloadAcceptability;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduDeactivateEPSBearerContextRequest;

typedef struct __naspduESMDummyMessage
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
} NASPduESMDummyMessage;


typedef struct __naspduESMInformationRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
} NASPduESMInformationRequest;


typedef struct __naspduESMInformationResponse
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_AccessPointName mAccessPointName;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduESMInformationResponse;


typedef struct __naspduESMStatus
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	
} NASPduESMStatus;


typedef struct __naspduModifyEPSBearerContextAccept
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduModifyEPSBearerContextAccept;


typedef struct __naspduModifyEPSBearerContextReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduModifyEPSBearerContextReject;


typedef struct __naspduModifyEPSBearerContextRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_EPSQualityOfService mNewEPSQoS;
	NASPdu_TrafficFlowTemplate mTFT;
	NASPdu_QualityOfService mQualityOfService;
	NASPdu_LLCServiceAccessPointIdentifier mLLCServiceAccessPointIdentifier;
	NASPdu_RadioPriority mRadioPriority;
	NASPdu_PacketFlowIdentifier mPacketFlowIdentifier;
	NASPdu_APNAggregateMaximumBitRate mAPNAggregateMaximumBitRate;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_WLANOffloadAcceptability mWLANOffloadAcceptability;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_HeaderCompressionConfiguration mHeaderCompressionConfiguration;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	NASPdu_ExtendedAPNAggregateMaximumBitRate mExtendedAPNAMBR;
	NASPdu_ExtendedQualityOfService mExtendedEPSQoS;
	
} NASPduModifyEPSBearerContextRequest;


typedef struct __naspduNotification
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_NotificationIndicator mNotificationIndicator;

} NASPduNotification;


typedef struct __naspduPDNConnectivityReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_GPRSTimer3 mBackOffTimerValue;
	NASPdu_ReAttemptIndicator mReAttemptIndicator;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;

} NASPduPDNConnectivityReject;


typedef struct __naspduPDNConnectivityRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t RequestType : 4;
		uint8_t PDNType : 4;
	} b1;
	
	NASPdu_ESMInformationTransferFlag mESMInformationTransferFlag; 
	NASPdu_AccessPointName mAccessPointName;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_DeviceProperties mDeviceProperties;
	NASPdu_NBIFOMContainer mNBIFOMContainer;
	NASPdu_HeaderCompressionConfiguration mHeaderCompressionConfiguration;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduPDNConnectivityRequest;

typedef struct __naspduPDNDisconnectReject
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_ESMCause mESMCause;
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduPDNDisconnectReject;


typedef struct __naspduPDNDisconnectRequest
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	struct
	{
		uint8_t LinkedEPSBearerIdentity : 4;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_ProtocolConfigurationOptions mProtocolConfigurationOptions;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduPDNDisconnectRequest;


typedef struct __naspduRemoteUEReport
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_RemoteUEContextList mRemoteUEContextConnected;
	NASPdu_RemoteUEContextList mRemoteUEContextDisconnected;
	NASPdu_PKMFAddress mProSeKeyManagementFunctionAddress;
	
} NASPduRemoteUEReport;


typedef struct __naspduRemoteUEReportResponse
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
} NASPduRemoteUEReportResponse;


typedef struct __naspduESMDataTransport
{
	NASPduSecurityHeader sHeader;
	NASPduHeader pHeader;
	
	NASPdu_UserDataContainer mUserDataContainer;
	NASPdu_ReleaseAssistanceIndication mReleaseAssistanceIndication;
} NASPduESMDataTransport;

//------------------------------------------------------------------------------------------------------------
// 5GS

typedef struct __naspduFGMM_RegistrationRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	//NASPdu_FGSRegistrationType mFGSRegistrationType;
	
	struct
	{
		uint8_t FGSRegistrationType : 3;
		uint8_t FOR : 1;
		uint8_t ngKSI : 3;
		uint8_t TSC : 1;
	} b1;
	
	NASPdu_FGSMobileIdentity mFGSMobileIdentity;						//M -- 9.10.3.4
	NASPdu_NASKeySetIdentifier mNASKeySetIdentifier;					// 9.10.3.29
	NASPdu_FGMMCapability mFGMMCapability;
	NASPdu_FGUESecurityCapability mFGUESecurityCapability;
	NASPdu_NSSAI mRequestedNSSAI;
	NASPdu_TrackingAreaIdentity mLastVisitedRegisteredTAI;				//5GS tracking area identity   	9.10.3.8
	NASPdu_UENetworkCapability mS1UENetworkCapability;					//S1 UE network capability  	9.10.3.44
	NASPdu_UplinkDataStatus mUplinkDataStatus;
	NASPdu_PDUSessionStatus mPDUSessionStatus;
	NASPdu_MICO mMICOIndication;										// MICO indication  9.10.3.28
	NASPdu_UEStatus mUEStatus;
	NASPdu_FGSMobileIdentity mAdditionalGUTI;
	NASPdu_AllowedPDUSessionStatus mAllowedPDUSessionStatus;
	NASPdu_UEUsageSetting mUEUsageSetting;
	NASPdu_DRXParameter mRequestedDRXparameters;
	NASPdu_EPSNASMessageContainer mEPSNASMessageContainer;
	NASPdu_PayloadContainer mPayloadContainer;
	NASPdu_FGSUpdateType mFGSUpdateType;
	
} NASPduFGMM_RegistrationRequest;

typedef struct __naspduFGMM_RegistrationAccept
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSRegistrationResult mFGSRegistrationResult;
	NASPdu_FGSMobileIdentity m5GGUTI;
	NASPdu_PLMNList mEquivalentPLMNs;
	NASPdu_TrackingAreaIdentityList mTAIlist;											//5GS tracking area identity list 9.10.3.9
	NASPdu_NSSAI mAllowedNSSAI;
	NASPdu_RejectedNSSAI mRejectedNSSAI;
	NASPdu_NSSAI mConfiguredNSSAI;
	NASPdu_FGSNetworkFeatureSupport mFGSNetworkFeatureSupport;
	NASPdu_PDUSessionStatus mPDUSessionStatus;
	NASPdu_PDUSessionReactivationResult mPDUSessionReactivationResult;
	NASPdu_PDUSessionReactivationErrorCause mPDUSessionReactivationErrorCause; 
	NASPdu_LADN mLADNInformation; 														// LADN information 9.10.3.27;
	NASPdu_MICO mMICOIndication;														// 9.10.3.28
	NASPdu_ServiceAreaList mServiceAreaList; 
	NASPdu_GPRSTimer3 mT3512Value;
	NASPdu_GPRSTimer2 mNon3GPPDeRegistrationTimerValue;
	NASPdu_GPRSTimer2 mT3502Value;
	NASPdu_EmergencyNumberList mEmergencyNumberList;
	NASPdu_ExtendedEmergencyNumberList mExtendedEmergencyNumberList;
	//NASPdu_Tra																		// TBD 9.10.3.49
	NASPdu_EAPMessage mEAPMessage; 		
	
	
} NASPduFGMM_RegistrationAccept;

typedef struct __naspduFGMM_RegistrationComplete
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
} NASPduFGMM_RegistrationComplete;

typedef struct __naspduFGMM_RegistrationReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGMMCause mFGMMCause;
	NASPdu_GPRSTimer2 mT3346Value;
	NASPdu_GPRSTimer2 mT3502Value;
	NASPdu_EAPMessage mEAPMessage;
	
} NASPduFGMM_RegistrationReject;

typedef struct __naspduFGMM_DeregistrationRequestUEI
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t DeRegistrationType : 4;
		uint8_t ngKSI : 3;
		uint8_t TSC : 1;
	} b1;
	
	NASPdu_FGSMobileIdentity mFGSMobileIdentity;
	
} NASPduFGMM_DeregistrationRequestUEI;

typedef struct __naspduFGMM_DeregistrationAcceptUEI
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
} NASPduFGMM_DeregistrationAcceptUEI;

typedef struct __naspduFGMM_DeregistrationRequestUET
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;

	struct
	{
		uint8_t DeRegistrationType_AccessType : 2;
		uint8_t DeRegistrationType_ReRegistrationRequired : 1;
		uint8_t DeRegistrationType_SwitchOff : 1;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_FGMMCause mFGMMCause;
	NASPdu_GPRSTimer2 mT3346Value;
	
} NASPduFGMM_DeregistrationRequestUET;

typedef struct __naspduFGMM_DeregistrationAcceptUET
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
} NASPduFGMM_DeregistrationAcceptUET;


typedef struct __naspduFGMM_ServiceRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t ngKSI : 3;
		uint8_t TSC : 1;
		uint8_t ServiceType : 4;
	} b1;
	
	NASPdu_FGSMobileIdentity m5GSTMSI;
	NASPdu_UplinkDataStatus mUplinkDataStatus;
	NASPdu_PDUSessionStatus mPDUSessionStatus;
	NASPdu_AllowedPDUSessionStatus mAllowedPDUSessionStatus;
	
} NASPduFGMM_ServiceRequest;

typedef struct __naspduFGMM_ServiceReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGMMCause mFGMMCause;
	NASPdu_PDUSessionStatus mPDUSessionStatus;
	NASPdu_GPRSTimer2 mT3346Value;
	NASPdu_EAPMessage mEAPMessage;
} NASPduFGMM_ServiceReject;

typedef struct __naspduFGMM_ServiceAccept
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_PDUSessionStatus mPDUSessionStatus;
	NASPdu_PDUSessionReactivationResult mPDUSessionReactivationResult;
	NASPdu_PDUSessionReactivationErrorCause mPDUSessionReactivationErrorCause;
	NASPdu_EAPMessage mEAPMessage;
	
} NASPduFGMM_ServiceAccept;

typedef struct __naspduFGMM_ConfigurationUpdateCommand
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_ConfiguratinUpdateIndication mConfiguratinUpdateIndication;
	NASPdu_FGSMobileIdentity mFGSMobileIdentity;
	NASPdu_TrackingAreaIdentityList mTAIList;
	NASPdu_NSSAI mAllowedNSSAI;
	NASPdu_ServiceAreaList mServiceAreaList;
	NASPdu_NetworkName mFullNameForNetwork;
	NASPdu_NetworkName mShortNameForNetwork;
	NASPdu_TimeZone mLocalTimeZone;
	NASPdu_TimeZoneAndTime mUniversalTimeAndLocalTimeZone;
	NASPdu_DaylightSavingTime mNetworkDaylightSavingTime;
	NASPdu_LADN mLADNInformation;
	NASPdu_MICO mMICOIndication;
	NASPdu_NSSAI mConfiguredNSSAI;
	NASPdu_RejectedNSSAI mRejectedNSSAI;
} NASPduFGMM_ConfigurationUpdateCommand;

typedef struct __naspduFGMM_ConfigurationUpdateComplete
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
} NASPduFGMM_ConfigurationUpdateComplete;

typedef struct __naspduFGMM_AuthenticationRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t ngKSI : 4;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_FGMMABBA mABBA;
	NASPdu_AuthenticationParameterRAND mAuthenticationParameterRAND;
	NASPdu_AuthenticationParameterAUTN mAuthenticationParameterAUTN;
	NASPdu_EAPMessage mEAPMessage;	
} NASPduFGMM_AuthenticationRequest;

typedef struct __naspduFGMM_AuthenticationResponse
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_AuthenticationResponseParameter mAuthenticationResponseParameter;
	NASPdu_EAPMessage mEAPMessage;
} NASPduFGMM_AuthenticationResponse;

typedef struct __naspduFGMM_AuthenticationReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_EAPMessage mEAPMessage;
} NASPduFGMM_AuthenticationReject;

typedef struct __naspduFGMM_AuthenticationFailure
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGMMCause mFGMMCause; 
	NASPdu_AuthenticationFailureParameter mAuthenticationFailureParameter;
} NASPduFGMM_AuthenticationFailure;

typedef struct __naspduFGMM_AuthenticationResult
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t ngKSI : 3;
		uint8_t TSC : 1;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_FGMMABBA mABBA;
} NASPduFGMM_AuthenticationResult;

typedef struct __naspduFGMM_IdentityRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t FGSIdentityType : 3;
		uint8_t Spare : 5;
	} b1;
	
} NASPduFGMM_IdentityRequest;

typedef struct __naspduFGMM_IdentityResponse
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMobileIdentity mMobileIdentity;
} NASPduFGMM_IdentityResponse;

typedef struct __naspduFGMM_SecurityModeCommand
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGMMNASSecurityAlgorithms mNASSecurityAlgorithms;
	
	struct
	{
		uint8_t ngKSI : 3;
		uint8_t TSC : 1;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_FGMM_UESecurityCapability mUESecurityCapability;
	NASPdu_IMEISVRequest mIMEISVRequest;
	NASPdu_HashAMF mHashAMF;
	NASPdu_EPSNASSecurityAlgorithms mSelectedEPSNASSecurityAlgorithms;
	NASPdu_EAPMessage mEAPMessage;
} NASPduFGMM_SecurityModeCommand;

typedef struct __naspduFGMM_SecurityModeComplete
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMobileIdentity mIMEISV;
	NASPdu_NASMessageContainer mNASMessageContainer;
	
} NASPduFGMM_SecurityModeComplete;

typedef struct __naspduFGMM_SecurityModeReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGMMCause mFGMMCause;
	
} NASPduFGMM_SecurityModeReject;

typedef struct __naspduFGMM_5GMMStatus
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGMMCause mFGMMCause;
} NASPduFGMM_5GMMStatus;

typedef struct __naspduFGMM_Notification
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t AccessType : 2;
		uint8_t Spare : 6;
	} b1;
	
} NASPduFGMM_Notification;

typedef struct __naspduFGMM_NotificationResponse
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_PDUSessionStatus mPDUSessionStatus;
} NASPduFGMM_NotificationResponse;

typedef struct __naspduFGMM_ULNASTransport
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t PayloadContainerType : 4;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_PayloadContainer mPayloadContainer;
	
} NASPduFGMM_ULNASTransport;

typedef struct __naspduFGMM_DLNASTransport
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t PayloadContainerType : 4;
		uint8_t Spare : 4;
	} b1;
	
	NASPdu_PayloadContainer mPayloadContainer;	
	
} NASPduFGMM_DLNASTransport;

// SM
typedef struct __naspduFGSM_PDUSessionEstablishmentRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_IntegrityProtectionMaximumDataRate mIntegrityProtectionMaximumDataRate;
	NASPdu_PDUSessionType mPDUSessionType;
	NASPdu_SSCMode mSSCMode;
	NASPdu_FGSMCapability mFGSMCapability;
	NASPdu_MaximumNumberOfSupportedPacketFilters mMaximumNumberOfSupportedPacketFilters;
	//NASPdu_
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduFGSM_PDUSessionEstablishmentRequest;

typedef struct __naspduFGSM_PDUSessionEstablishmentAccept
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	struct
	{
		uint8_t PDUSessionType : 4;
		uint8_t SSCMode : 4;
	} b1;
	
	
	NASPdu_QosRules mAuthorizedQoSRules;
	NASPdu_SessionAMBR mSessionAMBR; 
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_PDUAddress mPDUAddress;
	NASPdu_GPRSTimer mRQTimerValue;
	NASPdu_SNSSAI mSNSSAI;
	NASPdu_MappedEPSBearerContexts mMappedEPSBearerContexts;
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	NASPdu_DNN mDNN;
	
} NASPduFGSM_PDUSessionEstablishmentAccept;

typedef struct __naspduFGSM_PDUSessionEstablishmentReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_GPRSTimer3 mBackOffTimerValue;
	NASPdu_AllowedSSCMode mAllowedSSCMode;
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionEstablishmentReject;

typedef struct __naspduFGSM_PDUSessionAuthenticationCommand
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionAuthenticationCommand;


typedef struct __naspduFGSM_PDUSessionAuthenticationComplete
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionAuthenticationComplete;

typedef struct __naspduFGSM_PDUSessionAuthenticationResult
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionAuthenticationResult;

typedef struct __naspduFGSM_PDUSessionModificationRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCapability mFGSMCapability;
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_MaximumNumberOfSupportedPacketFilters mMaximumNumberOfSupportedPacketFilters;
	NASPdu_QosRules mRequestedQoSRules;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionModificationRequest;

typedef struct __naspduFGSM_PDUSessionModificationReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_GPRSTimer3 mBackOffTimerValue;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionModificationReject;

typedef struct __naspduFGSM_PDUSessionModificationCommand
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_SessionAMBR mSessionAMBR;
	NASPdu_GPRSTimer mRQTimerValue;
	NASPdu_QosRules mAuthorizedQoSRules;
	NASPdu_MappedEPSBearerContexts mMappedEPSBearerContexts;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
	
} NASPduFGSM_PDUSessionModificationCommand;

typedef struct __naspduFGSM_PDUSessionModificationComplete
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionModificationComplete;

typedef struct __naspduFGSM_PDUSessionModificationCommandReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;

	NASPdu_FGSMCause mFGSMCause;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;	
} NASPduFGSM_PDUSessionModificationCommandReject;

typedef struct __naspduFGSM_PDUSessionReleaseRequest
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;	
} NASPduFGSM_PDUSessionReleaseRequest;

typedef struct __naspduFGSM_PDUSessionReleaseReject
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionReleaseReject;

typedef struct __naspduFGSM_PDUSessionReleaseCommand
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_GPRSTimer mBackOffTimerValue;
	NASPdu_EAPMessage mEAPMessage;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionReleaseCommand;

typedef struct __naspduFGSM_PDUSessionReleaseComplete
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
	NASPdu_ExtendedProtocolConfigurationOptions mExtendedProtocolConfigurationOptions;
} NASPduFGSM_PDUSessionReleaseComplete;

typedef struct __naspduFGSM_Status
{
	NASPduFGSecurityHeader sHeader;
	NASPduFGHeader pHeader;
	
	NASPdu_FGSMCause mFGSMCause;
} NASPduFGSM_Status;


//------------------------------------------------------------------------------------------------------------

typedef struct __si_csn_plainHeader
{
	uint8_t ProtocolDiscriminator : 4;		//LSB
	uint8_t EPSBIOrSHT : 4;					//MSB
	uint8_t MessageType;
} SI_CSN_PlainHeader;

typedef struct __naspduDecode
{
	int MessageType;
	uint8_t * messageObj;
	unsigned char * buffer;
	int length;
	int pos;
	int iStatus;
	uint8_t iMandatoryDecoded;
	uint8_t iLastElementId;
	uint8_t iUnSuccessfulElementId;
	uint8_t MMType;
	uint8_t ProtocolDiscriminator;
	uint32_t errorLineNo;
} SI_NASPduDecode;

int __si_naspdu_DecodeMessage( SI_NASPduDecode * decodePdu);
int __si_naspdu_DecodeFGMessage( SI_NASPduDecode * decodePdu, unsigned char * data, unsigned int length);
int __si_naspdu_encodePlainHeader( NASPduHeader * oHeader, SI_ASN_CodingContext * context);


int __si_naspdu_encodeAdditionalInformation( uint8_t iei, NASPdu_AdditionalInformation * oAdditionalInformation, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDeviceProperties( uint8_t iei, NASPdu_DeviceProperties * oDeviceProperties, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSBearerContextStatus( uint8_t iei, NASPdu_EPSBearerContextStatus * oEPSBearerContextStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeLocationAreaIdentification( uint8_t iei, NASPdu_LocationAreaIdentification * oLocationAreaIdentification, SI_ASN_CodingContext * context);
int __si_naspdu_encodeMobileIdentity( uint8_t iei, NASPdu_MobileIdentity * oMobileIdentity, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeMobileStationClassmark2( uint8_t iei, NASPdu_MobileStationClassmark2 * oMobileStationClassmark2, SI_ASN_CodingContext * context);
int __si_naspdu_encodeMobileStationClassmark3( uint8_t iei, NASPdu_MobileStationClassmark3 * oMobileStationClassmark3, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNASSecurityParametersFromEUTRA( uint8_t iei, NASPdu_NASSecurityParametersFromEUTRA * oNASSecurityParametersFromEUTRA, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNASSecurityParametersToEUTRA( uint8_t iei, NASPdu_NASSecurityParametersToEUTRA * oNASSecurityParametersToEUTRA, SI_ASN_CodingContext * context);
int __si_naspdu_encodePLMNList( uint8_t iei, NASPdu_PLMNList * oPLMNList, SI_ASN_CodingContext * context);
int __si_naspdu_encodeSpareHalfOctet( uint8_t iei, NASPdu_SpareHalfOctet * oSpareHalfOctet, SI_ASN_CodingContext * context);
int __si_naspdu_encodeSupportedCodecList( uint8_t iei, NASPdu_SupportedCodecList * oSupportedCodecList, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAdditionalUpdateResult( uint8_t iei, NASPdu_AdditionalUpdateResult * oAdditionalUpdateResult, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAdditionalUpdateType( uint8_t iei, NASPdu_AdditionalUpdateType * oAdditionalUpdateType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAuthenticationFailureParameter( uint8_t iei, NASPdu_AuthenticationFailureParameter * oAuthenticationFailureParameter, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAuthenticationParameterAUTN( uint8_t iei, NASPdu_AuthenticationParameterAUTN * oAuthenticationParameterAUTN, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeAuthenticationParameterRAND( uint8_t iei, NASPdu_AuthenticationParameterRAND * oAuthenticationParameterRAND, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeAuthenticationResponseParameter( uint8_t iei, NASPdu_AuthenticationResponseParameter * oAuthenticationResponseParameter, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeCipheringKeySequenceNumber( uint8_t iei, NASPdu_CipheringKeySequenceNumber * oCipheringKeySequenceNumber, SI_ASN_CodingContext * context);
int __si_naspdu_encodeSMSServicesStatus( uint8_t iei, NASPdu_SMSServicesStatus * oSMSServicesStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeCSFBResponse( uint8_t iei, NASPdu_CSFBResponse * oCSFBResponse, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDaylightSavingTime( uint8_t iei, NASPdu_DaylightSavingTime * oDaylightSavingTime, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDetachType( uint8_t iei, NASPdu_DetachType * oDetachType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDRXParameter( uint8_t iei, NASPdu_DRXParameter * oDRXParameter, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeEMMCause( uint8_t iei, NASPdu_EMMCause * oEMMCause, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSAttachResult( uint8_t iei, NASPdu_EPSAttachResult * oEPSAttachResult, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSAttachType( uint8_t iei, NASPdu_EPSAttachType * oEPSAttachType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSMobileIdentity( uint8_t iei, NASPdu_EPSMobileIdentity * oEPSMobileIdentity, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeMobileIdentity( uint8_t iei, NASPdu_MobileIdentity * oMobileIdentity, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSNetworkFeatureSupport( uint8_t iei, NASPdu_EPSNetworkFeatureSupport * oEPSNetworkFeatureSupport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSUpdateResult( uint8_t iei, NASPdu_EPSUpdateResult * oEPSUpdateResult, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSUpdateType( uint8_t iei, NASPdu_EPSUpdateType * oEPSUpdateType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeESMMessageContainer( uint8_t iei, NASPdu_ESMMessageContainer * oESMMessageContainer, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeGPRSTimer( uint8_t iei, NASPdu_GPRSTimer * oGPRSTimer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGPRSTimer2( uint8_t iei, NASPdu_GPRSTimer2 * oGPRSTimer2, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGPRSTimer3( uint8_t iei, NASPdu_GPRSTimer3 * oGPRSTimer3, SI_ASN_CodingContext * context);
int __si_naspdu_encodeIdentityType2( uint8_t iei, NASPdu_IdentityType2 * oIdentityType2, SI_ASN_CodingContext * context);
int __si_naspdu_encodeIMEISVRequest( uint8_t iei, NASPdu_IMEISVRequest * oIMEISVRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeKSIAndSequenceNumber( uint8_t iei, NASPdu_KSIAndSequenceNumber * oKSIAndSequenceNumber, SI_ASN_CodingContext * context);
int __si_naspdu_encodeMSNetworkCapability( uint8_t iei, NASPdu_MSNetworkCapability * oMSNetworkCapability, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeMSNetworkFeatureSupport( uint8_t iei, NASPdu_MSNetworkFeatureSupport * oMSNetworkFeatureSupport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNASKeySetIdentifier( uint8_t iei, NASPdu_NASKeySetIdentifier * oNASKeySetIdentifier, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNASMessageContainer( uint8_t iei, NASPdu_NASMessageContainer * oNASMessageContainer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNASSecurityAlgorithms( uint8_t iei, NASPdu_NASSecurityAlgorithms * oNASSecurityAlgorithms, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeNetworkName( uint8_t iei, NASPdu_NetworkName * oNetworkName, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNetworkResourceIdentifierContainer( uint8_t iei, NASPdu_NetworkResourceIdentifierContainer * oNetworkResourceIdentifierContainer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNonce( uint8_t iei, NASPdu_Nonce * oNonce, SI_ASN_CodingContext * context);
int __si_naspdu_encodePagingIdentity( uint8_t iei, NASPdu_PagingIdentity * oPagingIdentity, SI_ASN_CodingContext * context);
int __si_naspdu_encodePTMSISignature( uint8_t iei, NASPdu_PTMSISignature * oPTMSISignature, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedEMMCause( uint8_t iei, NASPdu_ExtendedEMMCause * oExtendedEMMCause, SI_ASN_CodingContext * context);
int __si_naspdu_encodeServiceType( uint8_t iei, NASPdu_ServiceType * oServiceType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeShortMAC( uint8_t iei, NASPdu_ShortMAC * oShortMAC, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTimeZone( uint8_t iei, NASPdu_TimeZone * oTimeZone, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTimeZoneAndTime( uint8_t iei, NASPdu_TimeZoneAndTime * oTimeZoneAndTime, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTMSIStatus( uint8_t iei, NASPdu_TMSIStatus * oTMSIStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaIdentity( uint8_t iei, NASPdu_TrackingAreaIdentity * oTrackingAreaIdentity, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaIdentityItem( uint8_t iei, NASPdu_TrackingAreaIdentityItem * oTrackingAreaIdentityItem, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaIdentityList( uint8_t iei, NASPdu_TrackingAreaIdentityList * oTrackingAreaIdentityList, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUENetworkCapability( uint8_t iei, NASPdu_UENetworkCapability * oUENetworkCapability, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeUERadioCapabilityInformationUpdateNeeded( uint8_t iei, NASPdu_UERadioCapabilityInformationUpdateNeeded * oUERadioCapabilityInformationUpdateNeeded, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUESecurityCapability( uint8_t iei, NASPdu_UESecurityCapability * oUESecurityCapability, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeEmergencyNumberItem( uint8_t iei, NASPdu_EmergencyNumberItem * oEmergencyNumberItem, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEmergencyNumberList( uint8_t iei, NASPdu_EmergencyNumberList * oEmergencyNumberList, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedEmergencyNumberList( uint8_t iei, NASPdu_ExtendedEmergencyNumberList * oExtendedEmergencyNumberList, SI_ASN_CodingContext * context);
int __si_naspdu_encodeCLI( uint8_t iei, NASPdu_CLI * oCLI, SI_ASN_CodingContext * context);
int __si_naspdu_encodeSSCode( uint8_t iei, NASPdu_SSCode * oSSCode, SI_ASN_CodingContext * context);
int __si_naspdu_encodeLCSIndicator( uint8_t iei, NASPdu_LCSIndicator * oLCSIndicator, SI_ASN_CodingContext * context);
int __si_naspdu_encodeLCSClientIdentity( uint8_t iei, NASPdu_LCSClientIdentity * oLCSClientIdentity, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGenericMessageContainerType( uint8_t iei, NASPdu_GenericMessageContainerType * oGenericMessageContainerType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGenericMessageContainer( uint8_t iei, NASPdu_GenericMessageContainer * oGenericMessageContainer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeVoiceDomainPreferenceAndUEsUsageSetting( uint8_t iei, NASPdu_VoiceDomainPreferenceAndUEsUsageSetting * oVoiceDomainPreferenceAndUEsUsageSetting, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGUTIType( uint8_t iei, NASPdu_GUTIType * oGUTIType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedDRXParameters( uint8_t iei, NASPdu_ExtendedDRXParameters * oExtendedDRXParameters, SI_ASN_CodingContext * context);
int __si_naspdu_encodeControlPlaneServiceType( uint8_t iei, NASPdu_ControlPlaneServiceType * oControlPlaneServiceType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDCNID( uint8_t iei, NASPdu_DCNID * oDCNID, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNon3GPPNWProvidedPolicies( uint8_t iei, NASPdu_Non3GPPNWProvidedPolicies * oNon3GPPNWProvidedPolicies, SI_ASN_CodingContext * context);
int __si_naspdu_encodeHashMME( uint8_t iei, NASPdu_HashMME * oHashMME, SI_ASN_CodingContext * context);
int __si_naspdu_encodeReplayedNASMessageContainer( uint8_t iei, NASPdu_ReplayedNASMessageContainer * oReplayedNASMessageContainer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNetworkPolicy( uint8_t iei, NASPdu_NetworkPolicy * oNetworkPolicy, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUEAdditionalSecurityCapability( uint8_t iei, NASPdu_UEAdditionalSecurityCapability * oUEAdditionalSecurityCapability, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUEStatus( uint8_t iei, NASPdu_UEStatus * oUEStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAdditionalInformationRequested( uint8_t iei, NASPdu_AdditionalInformationRequested * oAdditionalInformationRequested, SI_ASN_CodingContext * context);
int __si_naspdu_encodeCipheringKeyDataSet( uint8_t iei, NASPdu_CipheringKeyDataSet * oCipheringKeyDataSet, SI_ASN_CodingContext * context);
int __si_naspdu_encodeCipheringKeyData( uint8_t iei, NASPdu_CipheringKeyData * oCipheringKeyData, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAccessPointName( uint8_t iei, NASPdu_AccessPointName * oAccessPointName, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAPNAggregateMaximumBitRate( uint8_t iei, NASPdu_APNAggregateMaximumBitRate * oAPNAggregateMaximumBitRate, SI_ASN_CodingContext * context);
int __si_naspdu_encodeConnectivityType( uint8_t iei, NASPdu_ConnectivityType * oConnectivityType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEPSQualityOfService( uint8_t iei, NASPdu_EPSQualityOfService * oEPSQualityOfService, SI_ASN_CodingContext * context);
int __si_naspdu_encodeESMCause( uint8_t iei, NASPdu_ESMCause * oESMCause, SI_ASN_CodingContext * context);//
int __si_naspdu_encodeESMInformationTransferFlag( uint8_t iei, NASPdu_ESMInformationTransferFlag * oESMInformationTransferFlag, SI_ASN_CodingContext * context);
int __si_naspdu_encodeLinkedEPSBearerIdentity( uint8_t iei, NASPdu_LinkedEPSBearerIdentity * oLinkedEPSBearerIdentity, SI_ASN_CodingContext * context);
int __si_naspdu_encodeLLCServiceAccessPointIdentifier( uint8_t iei, NASPdu_LLCServiceAccessPointIdentifier * oLLCServiceAccessPointIdentifier, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNotificationIndicator( uint8_t iei, NASPdu_NotificationIndicator * oNotificationIndicator, SI_ASN_CodingContext * context);
int __si_naspdu_encodePacketFlowIdentifier( uint8_t iei, NASPdu_PacketFlowIdentifier * oPacketFlowIdentifier, SI_ASN_CodingContext * context);
int __si_naspdu_encodePDNAddress( uint8_t iei, NASPdu_PDNAddress * oPDNAddress, SI_ASN_CodingContext * context);
int __si_naspdu_encodePDNType( uint8_t iei, NASPdu_PDNType * oPDNType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeProtocolConfigurationOptions( uint8_t iei, NASPdu_ProtocolConfigurationOptions * oProtocolConfigurationOptions, SI_ASN_CodingContext * context);
int __si_naspdu_encodeRadioPriority( uint8_t iei, NASPdu_RadioPriority * oRadioPriority, SI_ASN_CodingContext * context);
int __si_naspdu_encodeQualityOfService( uint8_t iei, NASPdu_QualityOfService * oQualityOfService, SI_ASN_CodingContext * context);
int __si_naspdu_encodeReAttemptIndicator( uint8_t iei, NASPdu_ReAttemptIndicator * oReAttemptIndicator, SI_ASN_CodingContext * context);
int __si_naspdu_encodeRequestType( uint8_t iei, NASPdu_RequestType * oRequestType, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrafficFlowAggregateDescription( uint8_t iei, NASPdu_TrafficFlowAggregateDescription * oTrafficFlowAggregateDescription, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrafficFlowTemplate( uint8_t iei, NASPdu_TrafficFlowTemplate * oTrafficFlowTemplate, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTransactionIdentifier( uint8_t iei, NASPdu_TransactionIdentifier * oTransactionIdentifier, SI_ASN_CodingContext * context);
int __si_naspdu_encodeWLANOffloadAcceptability( uint8_t iei, NASPdu_WLANOffloadAcceptability * oWLANOffloadAcceptability, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNBIFOMContainer( uint8_t iei, NASPdu_NBIFOMContainer * oNBIFOMContainer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeRemoteUEContextList( uint8_t iei, NASPdu_RemoteUEContextList * oRemoteUEContextList, SI_ASN_CodingContext * context);
int __si_naspdu_encodePKMFAddress( uint8_t iei, NASPdu_PKMFAddress * oPKMFAddress, SI_ASN_CodingContext * context);
int __si_naspdu_encodeHeaderCompressionConfiguration( uint8_t iei, NASPdu_HeaderCompressionConfiguration * oHeaderCompressionConfiguration, SI_ASN_CodingContext * context);
int __si_naspdu_encodeControlPlaneOnlyIndication( uint8_t iei, NASPdu_ControlPlaneOnlyIndication * oControlPlaneOnlyIndication, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUserDataContainer( uint8_t iei, NASPdu_UserDataContainer * oUserDataContainer, SI_ASN_CodingContext * context);
int __si_naspdu_encodeReleaseAssistanceIndication( uint8_t iei, NASPdu_ReleaseAssistanceIndication * oReleaseAssistanceIndication, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedProtocolConfigurationOptions( uint8_t iei, NASPdu_ExtendedProtocolConfigurationOptions * oExtendedProtocolConfigurationOptions, SI_ASN_CodingContext * context);
int __si_naspdu_encodeHeaderCompressionConfigurationStatus( uint8_t iei, NASPdu_HeaderCompressionConfigurationStatus * oHeaderCompressionConfigurationStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeServingPLMNRateControl( uint8_t iei, NASPdu_ServingPLMNRateControl * oServingPLMNRateControl, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedAPNAggregateMaximumBitRate( uint8_t iei, NASPdu_ExtendedAPNAggregateMaximumBitRate * oExtendedAPNAggregateMaximumBitRate, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedQualityOfService( uint8_t iei, NASPdu_ExtendedQualityOfService * oExtendedQualityOfService, SI_ASN_CodingContext * context);





int __si_naspdu_encodeAttachAccept( NASPduAttachAccept * oAttachAccept, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAttachComplete( NASPduAttachComplete * oAttachComplete, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAttachReject( NASPduAttachReject * oAttachReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAttachRequest( NASPduAttachRequest * oAttachRequest, SI_ASN_CodingContext * context);	//
int __si_naspdu_encodeAuthenticationFailure( NASPduAuthenticationFailure * oAuthenticationFailure, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAuthenticationReject( NASPduAuthenticationReject * oAuthenticationReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeAuthenticationRequest( NASPduAuthenticationRequest * oAuthenticationRequest, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeAuthenticationResponse( NASPduAuthenticationResponse * oAuthenticationResponse, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeCSServiceNotification( NASPduCSServiceNotification * oCSServiceNotification, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDetachAccept( NASPduDetachAccept * oDetachAccept, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeDetachRequest( NASPduDetachRequest * oDetachRequest, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeDownlinkNASTransport( NASPduDownlinkNASTransport * oDownlinkNASTransport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEMMInformation( NASPduEMMInformation * oEMMInformation, SI_ASN_CodingContext * context);
int __si_naspdu_encodeEMMStatus( NASPduEMMStatus * oEMMStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeExtendedServiceRequest( NASPduExtendedServiceRequest * oExtendedServiceRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGUTIReallocationCommand( NASPduGUTIReallocationCommand * oGUTIReallocationCommand, SI_ASN_CodingContext * context);
int __si_naspdu_encodeGUTIReallocationComplete( NASPduGUTIReallocationComplete * oGUTIReallocationComplete, SI_ASN_CodingContext * context);
int __si_naspdu_encodeIdentityRequest( NASPduIdentityRequest * oIdentityRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeIdentityResponse( NASPduIdentityResponse * oIdentityResponse, SI_ASN_CodingContext * context);
int __si_naspdu_encodeSecurityModeCommand( NASPduSecurityModeCommand * oSecurityModeCommand, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeSecurityModeComplete( NASPduSecurityModeComplete * oSecurityModeComplete, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeSecurityModeReject( NASPduSecurityModeReject * oSecurityModeReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeSecurityProtectedNASMessage( NASPduSecurityProtectedNASMessage * oSecurityProtectedNASMessage, SI_ASN_CodingContext * context);
int __si_naspdu_encodeServiceReject( NASPduServiceReject * oServiceReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeServiceRequest( NASPduServiceRequest * oServiceRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaUpdateAccept( NASPduTrackingAreaUpdateAccept * oTrackingAreaUpdateAccept, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaUpdateComplete( NASPduTrackingAreaUpdateComplete * oTrackingAreaUpdateComplete, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaUpdateReject( NASPduTrackingAreaUpdateReject * oTrackingAreaUpdateReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeTrackingAreaUpdateRequest( NASPduTrackingAreaUpdateRequest * oTrackingAreaUpdateRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUplinkNASTransport( NASPduUplinkNASTransport * oUplinkNASTransport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDownlinkGenericNASTransport( NASPduDownlinkGenericNASTransport * oDownlinkGenericNASTransport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeUplinkGenericNASTransport( NASPduUplinkGenericNASTransport * oUplinkGenericNASTransport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeControlPlaneServiceRequest( NASPduControlPlaneServiceRequest * oControlPlaneServiceRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeServiceAccept( NASPduServiceAccept * oServiceAccept, SI_ASN_CodingContext * context);

int __si_naspdu_encodeActivateDedicatedEPSBearerContextAccept( NASPduActivateDedicatedEPSBearerContextAccept * oActivateDedicatedEPSBearerContextAccept, SI_ASN_CodingContext * context);
int __si_naspdu_encodeActivateDedicatedEPSBearerContextReject( NASPduActivateDedicatedEPSBearerContextReject * oActivateDedicatedEPSBearerContextReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeActivateDedicatedEPSBearerContextRequest( NASPduActivateDedicatedEPSBearerContextRequest * oActivateDedicatedEPSBearerContextRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeActivateDefaultEPSBearerContextAccept( NASPduActivateDefaultEPSBearerContextAccept * oActivateDefaultEPSBearerContextAccept, SI_ASN_CodingContext * context);
int __si_naspdu_encodeActivateDefaultEPSBearerContextReject( NASPduActivateDefaultEPSBearerContextReject * oActivateDefaultEPSBearerContextReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeActivateDefaultEPSBearerContextRequest( NASPduActivateDefaultEPSBearerContextRequest * oActivateDefaultEPSBearerContextRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeBearerResourceAllocationReject( NASPduBearerResourceAllocationReject * oBearerResourceAllocationReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeBearerResourceAllocationRequest( NASPduBearerResourceAllocationRequest * oBearerResourceAllocationRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeBearerResourceModificationReject( NASPduBearerResourceModificationReject * oBearerResourceModificationReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeBearerResourceModificationRequest( NASPduBearerResourceModificationRequest * oBearerResourceModificationRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeDeactivateEPSBearerContextAccept( NASPduDeactivateEPSBearerContextAccept * oDeactivateEPSBearerContextAccept, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeDeactivateEPSBearerContextRequest( NASPduDeactivateEPSBearerContextRequest * oDeactivateEPSBearerContextRequest, SI_ASN_CodingContext * context); //
int __si_naspdu_encodeESMDummyMessage( NASPduESMDummyMessage * oESMDummyMessage, SI_ASN_CodingContext * context);
int __si_naspdu_encodeESMInformationRequest( NASPduESMInformationRequest * oESMInformationRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeESMInformationResponse( NASPduESMInformationResponse * oESMInformationResponse, SI_ASN_CodingContext * context);
int __si_naspdu_encodeESMStatus( NASPduESMStatus * oESMStatus, SI_ASN_CodingContext * context);
int __si_naspdu_encodeModifyEPSBearerContextAccept( NASPduModifyEPSBearerContextAccept * oModifyEPSBearerContextAccept, SI_ASN_CodingContext * context);
int __si_naspdu_encodeModifyEPSBearerContextReject( NASPduModifyEPSBearerContextReject * oModifyEPSBearerContextReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodeModifyEPSBearerContextRequest( NASPduModifyEPSBearerContextRequest * oModifyEPSBearerContextRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeNotification( NASPduNotification * oNotification, SI_ASN_CodingContext * context);
int __si_naspdu_encodePDNConnectivityReject( NASPduPDNConnectivityReject * oPDNConnectivityReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodePDNConnectivityRequest( NASPduPDNConnectivityRequest * oPDNConnectivityRequest, SI_ASN_CodingContext * context); //
int __si_naspdu_encodePDNDisconnectReject( NASPduPDNDisconnectReject * oPDNDisconnectReject, SI_ASN_CodingContext * context);
int __si_naspdu_encodePDNDisconnectRequest( NASPduPDNDisconnectRequest * oPDNDisconnectRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodePDNDisconnectRequest( NASPduPDNDisconnectRequest * oPDNDisconnectRequest, SI_ASN_CodingContext * context);
int __si_naspdu_encodeRemoteUEReport( NASPduRemoteUEReport * oRemoteUEReport, SI_ASN_CodingContext * context);
int __si_naspdu_encodeESMDataTransport( NASPduESMDataTransport * oESMDataTransport, SI_ASN_CodingContext * context);

// 5GS
int __si_naspdu_fgmm_encodeRegistrationRequest( NASPduFGMM_RegistrationRequest * ptrRegistrationRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeRegistrationAccept( NASPduFGMM_RegistrationAccept * ptrRegistrationAccept, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeRegistrationComplete( NASPduFGMM_RegistrationComplete * ptrRegistrationComplete, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeRegistrationReject( NASPduFGMM_RegistrationReject * ptrRegistrationReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeDeregistrationRequestUEI( NASPduFGMM_DeregistrationRequestUEI * ptrDeregistrationRequestUEI, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeDeregistrationAcceptUEI( NASPduFGMM_DeregistrationAcceptUEI * ptrDeregistrationAcceptUEI, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeDeregistrationRequestUET( NASPduFGMM_DeregistrationRequestUET * ptrDeregistrationRequestUET, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeDeregistrationAcceptUET( NASPduFGMM_DeregistrationAcceptUET * ptrDeregistrationAcceptUET, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeServiceRequest( NASPduFGMM_ServiceRequest * ptrServiceRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeServiceReject( NASPduFGMM_ServiceReject * ptrServiceReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeServiceAccept( NASPduFGMM_ServiceAccept * ptrServiceAccept, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeConfigurationUpdateCommand( NASPduFGMM_ConfigurationUpdateCommand * ptrConfigurationUpdateCommand, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeConfigurationUpdateComplete( NASPduFGMM_ConfigurationUpdateComplete * ptrConfigurationUpdateComplete, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeAuthenticationRequest( NASPduFGMM_AuthenticationRequest * ptrAuthenticationRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeAuthenticationResponse( NASPduFGMM_AuthenticationResponse * ptrAuthenticationResponse, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeAuthenticationReject( NASPduFGMM_AuthenticationReject * ptrAuthenticationReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeAuthenticationFailure( NASPduFGMM_AuthenticationFailure * ptrAuthenticationFailure, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeAuthenticationResult( NASPduFGMM_AuthenticationResult * ptrAuthenticationResult, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeIdentityRequest( NASPduFGMM_IdentityRequest * ptrIdentityRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeIdentityResponse( NASPduFGMM_IdentityResponse * ptrIdentityResponse, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeSecurityModeCommand( NASPduFGMM_SecurityModeCommand * ptrSecurityModeCommand, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeSecurityModeComplete( NASPduFGMM_SecurityModeComplete * ptrSecurityModeComplete, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeSecurityModeReject( NASPduFGMM_SecurityModeReject * ptrSecurityModeReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encode5GMMStatus( NASPduFGMM_5GMMStatus * ptr5GMMStatus, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeNotification( NASPduFGMM_Notification * ptrNotification, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeNotificationResponse( NASPduFGMM_NotificationResponse * ptrNotificationResponse, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeULNASTransport( NASPduFGMM_ULNASTransport * ptrULNASTransport, SI_ASN_CodingContext * context);
int __si_naspdu_fgmm_encodeDLNASTransport( NASPduFGMM_DLNASTransport * ptrDLNASTransport, SI_ASN_CodingContext * context);
// SM
int __si_naspdu_fgsm_encodePDUSessionEstablishmentRequest( NASPduFGSM_PDUSessionEstablishmentRequest * ptrPDUSessionEstablishmentRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionEstablishmentAccept( NASPduFGSM_PDUSessionEstablishmentAccept * ptrPDUSessionEstablishmentAccept, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionEstablishmentReject( NASPduFGSM_PDUSessionEstablishmentReject * ptrPDUSessionEstablishmentReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionAuthenticationCommand( NASPduFGSM_PDUSessionAuthenticationCommand * ptrPDUSessionAuthenticationCommand, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionAuthenticationComplete( NASPduFGSM_PDUSessionAuthenticationComplete * ptrPDUSessionAuthenticationComplete, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionAuthenticationResult( NASPduFGSM_PDUSessionAuthenticationResult * ptrPDUSessionAuthenticationResult, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionModificationRequest( NASPduFGSM_PDUSessionModificationRequest * ptrPDUSessionModificationRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionModificationReject( NASPduFGSM_PDUSessionModificationReject * ptrPDUSessionModificationReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionModificationCommand( NASPduFGSM_PDUSessionModificationCommand * ptrPDUSessionModificationCommand, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionModificationComplete( NASPduFGSM_PDUSessionModificationComplete * ptrPDUSessionModificationComplete, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionModificationCommandReject( NASPduFGSM_PDUSessionModificationCommandReject * ptrPDUSessionModificationCommandReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionReleaseRequest( NASPduFGSM_PDUSessionReleaseRequest * ptrPDUSessionReleaseRequest, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionReleaseReject( NASPduFGSM_PDUSessionReleaseReject * ptrPDUSessionReleaseReject, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionReleaseCommand( NASPduFGSM_PDUSessionReleaseCommand * ptrPDUSessionReleaseCommand, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodePDUSessionReleaseComplete( NASPduFGSM_PDUSessionReleaseComplete * ptrPDUSessionReleaseComplete, SI_ASN_CodingContext * context);
int __si_naspdu_fgsm_encodeStatus( NASPduFGSM_Status * ptrStatus, SI_ASN_CodingContext * context);
// 5GS END



void __si_naspdu_TrackingAreaIdentityList_addItem( NASPdu_TrackingAreaIdentityList * oTrackingAreaIdentityList, uint8_t type, uint8_t NoOfTAC, char * mccmnc, char * tac);
void __si_naspdu_EmergencyNumberList_addItem( NASPdu_EmergencyNumberList * oEmergencyNumberList, uint8_t servCategory, uint64_t emergencyNumber);
void __si_naspdu_ExtendedEmergencyNumberList_addItem( NASPdu_ExtendedEmergencyNumberList * oEENL, uint64_t emergencyNumber, char * subServiceField, uint8_t subServiceFieldLen);
void __si_naspdu_addMobileIdentity( NASPdu_MobileIdentity * oMobileIdentity, uint8_t type, uint8_t OddEven, char * data, uint8_t dataLen);
void __si_naspdu_getMobileIdentity( NASPdu_MobileIdentity * oMobileIdentity, uint8_t * type, uint8_t * OddEven, u_char * data, uint8_t * dataLen);

void __si_naspdu_addProtocolConfigurationOptions( NASPdu_ProtocolConfigurationOptions * pPCO, uint16_t pProtocolId, uint8_t pLength, u_char * pContents);

void __si_naspdu_freeNASPduDecode( SI_NASPduDecode * decodePdu);

#endif


