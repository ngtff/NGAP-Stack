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

void amf_ngap_procedure_UERadioCapabilityInfoIndication( SI_AMF_DT_PDU_UERadioCapabilityInfoIndication * objUERadioCapabilityInfoIndication, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_UERadioCapabilityCheckRequest( SI_AMF_DT_PDU_UERadioCapabilityCheckRequest * objUERadioCapabilityCheckRequest, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_UERadioCapabilityCheckResponse( SI_AMF_DT_PDU_UERadioCapabilityCheckResponse * objUERadioCapabilityCheckResponse, SI_NGAPNode * ngNode)
{
}



