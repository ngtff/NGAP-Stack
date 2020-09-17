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

void amf_ngap_procedure_PDUSessionResourceSetupRequest( SI_AMF_DT_PDU_PDUSessionResourceSetupRequest * objPDUSessionResourceSetupRequest, SI_NGAPNode * ngNode)
{
	__si_amf_debug_pdu_PDUSessionResourceSetupRequest( objPDUSessionResourceSetupRequest);
}

void amf_ngap_procedure_PDUSessionResourceSetupResponse( SI_AMF_DT_PDU_PDUSessionResourceSetupResponse * objPDUSessionResourceSetupResponse, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_PDUSessionResourceReleaseCommand( SI_AMF_DT_PDU_PDUSessionResourceReleaseCommand * objPDUSessionResourceReleaseCommand, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_PDUSessionResourceReleaseResponse( SI_AMF_DT_PDU_PDUSessionResourceReleaseResponse * objPDUSessionResourceReleaseResponse, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_PDUSessionResourceModifyRequest( SI_AMF_DT_PDU_PDUSessionResourceModifyRequest * objPDUSessionResourceModifyRequest, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_PDUSessionResourceModifyResponse( SI_AMF_DT_PDU_PDUSessionResourceModifyResponse * objPDUSessionResourceModifyResponse, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_PDUSessionResourceNotify( SI_AMF_DT_PDU_PDUSessionResourceNotify * objPDUSessionResourceNotify, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_PDUSessionResourceModifyIndication( SI_AMF_DT_PDU_PDUSessionResourceModifyIndication * objPDUSessionResourceModifyIndication, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_PDUSessionResourceModifyConfirm( SI_AMF_DT_PDU_PDUSessionResourceModifyConfirm * objPDUSessionResourceModifyConfirm, SI_NGAPNode * ngNode)
{
	
}







