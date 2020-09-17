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


void amf_ngap_procedure_HandoverRequired( SI_AMF_DT_PDU_HandoverRequired * objHandoverRequired, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_HandoverCommand( SI_AMF_DT_PDU_HandoverCommand * objHandoverCommand, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_HandoverPreparationFailure( SI_AMF_DT_PDU_HandoverPreparationFailure * objHandoverPreparationFailure, SI_NGAPNode * ngNode)
{
}



void amf_ngap_procedure_HandoverRequest( SI_AMF_DT_PDU_HandoverRequest * objHandoverRequest, SI_NGAPNode * ngNode)
{
}


void amf_ngap_procedure_HandoverRequestAcknowledge( SI_AMF_DT_PDU_HandoverRequestAcknowledge * objHandoverRequestAcknowledge, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_HandoverFailure( SI_AMF_DT_PDU_HandoverFailure * objHandoverFailure, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_HandoverNotify( SI_AMF_DT_PDU_HandoverNotify * objHandoverNotify, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_PathSwitchRequest( SI_AMF_DT_PDU_PathSwitchRequest * objPathSwitchRequest, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_PathSwitchRequestAcknowledge( SI_AMF_DT_PDU_PathSwitchRequestAcknowledge * objPathSwitchRequestAcknowledge, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_PathSwitchRequestFailure( SI_AMF_DT_PDU_PathSwitchRequestFailure * objPathSwitchRequestFailure, SI_NGAPNode * ngNode)
{
}



void amf_ngap_procedure_HandoverCancel( SI_AMF_DT_PDU_HandoverCancel * objHandoverCancel, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_HandoverCancelAcknowledge( SI_AMF_DT_PDU_HandoverCancelAcknowledge * objHandoverCancelAcknowledge, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_UplinkRANStatusTransfer( SI_AMF_DT_PDU_UplinkRANStatusTransfer * objUplinkRANStatusTransfer, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_DownlinkRANStatusTransfer( SI_AMF_DT_PDU_DownlinkRANStatusTransfer * objDownlinkRANStatusTransfer, SI_NGAPNode * ngNode)
{
}










