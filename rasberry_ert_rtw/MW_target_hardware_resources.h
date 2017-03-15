#ifndef PORTABLE_WORDSIZES
#ifdef __MW_TARGET_USE_HARDWARE_RESOURCES_H__
#ifndef __MW_TARGET_HARDWARE_RESOURCES_H__
#define __MW_TARGET_HARDWARE_RESOURCES_H__


#define MW_USECODERTARGET 1
#define MW_TARGETHARDWARE Raspberry Pi
#define MW_CONNECTIONINFO_TCPIP_IPADDRESS codertarget.raspi.getDeviceAddress
#define MW_CONNECTIONINFO_TCPIP_PORT 17725
#define MW_CONNECTIONINFO_TCPIP_VERBOSE 0
#define MW_CONNECTIONINFO_TCPIP_RUNINBACKGROUND 0
#define MW_EXTMODE_CONFIGURATION TCP/IP
#define MW_EXTMODE_RUNNING on
#define MW_RTOS Linux
#define MW_RTOSBASERATETASKPRIORITY 40
#define MW_DETECTTASKOVERRUNS 0.000000
#define MW_SCHEDULER_INTERRUPT_SOURCE 0
#define MW_BOARDPARAMETERS_DEVICEADDRESS 169.254.0.2
#define MW_BOARDPARAMETERS_USERNAME pi
#define MW_BOARDPARAMETERS_PASSWORD raspberry
#define MW_BOARDPARAMETERS_BUILDDIR /home/pi
#define MW_RUNTIME_BUILDACTION 1
#define MW_DATAVERSION 2016.02
#define MW_MULTI_TASKING_MODE 0

#endif /* __MW_TARGET_HARDWARE_RESOURCES_H__ */

#endif

#endif
