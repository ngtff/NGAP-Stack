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

void amf_ngap_procedure_InitialContextSetupRequest( SI_AMF_DT_PDU_InitialContextSetupRequest * objInitialContextSetupRequest, SI_NGAPNode * ngNode)
{
	__si_amf_debug_pdu_InitialContextSetupRequest( objInitialContextSetupRequest);
}

void amf_ngap_procedure_InitialContextSetupResponse( SI_AMF_DT_PDU_InitialContextSetupResponse * objInitialContextSetupResponse, SI_NGAPNode * ngNode)
{
	
}


void amf_ngap_procedure_InitialContextSetupFailure( SI_AMF_DT_PDU_InitialContextSetupFailure * objInitialContextSetupFailure, SI_NGAPNode * ngNode)
{
	
}



void amf_ngap_procedure_UEContextReleaseCommand( SI_AMF_DT_PDU_UEContextReleaseCommand * objUEContextReleaseCommand, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_UEContextReleaseComplete( SI_AMF_DT_PDU_UEContextReleaseComplete * objUEContextReleaseComplete, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_UEContextReleaseRequest( SI_AMF_DT_PDU_UEContextReleaseRequest * objUEContextReleaseRequest, SI_NGAPNode * ngNode)
{
	
}



void amf_ngap_procedure_UEContextModificationRequest( SI_AMF_DT_PDU_UEContextModificationRequest * objUEContextModificationRequest, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_UEContextModificationResponse( SI_AMF_DT_PDU_UEContextModificationResponse * objUEContextModificationResponse, SI_NGAPNode * ngNode)
{
	
}

void amf_ngap_procedure_UEContextModificationFailure( SI_AMF_DT_PDU_UEContextModificationFailure * objUEContextModificationFailure, SI_NGAPNode * ngNode)
{
	
}









