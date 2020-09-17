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


void amf_ngap_procedure_TraceStart( SI_AMF_DT_PDU_TraceStart * objTraceStart, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_TraceFailureIndication( SI_AMF_DT_PDU_TraceFailureIndication * objTraceFailureIndication, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_DeactivateTrace( SI_AMF_DT_PDU_DeactivateTrace * objDeactivateTrace, SI_NGAPNode * ngNode)
{
}

void amf_ngap_procedure_CellTrafficTrace( SI_AMF_DT_PDU_CellTrafficTrace * objCellTrafficTrace, SI_NGAPNode * ngNode)
{
}












