#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/adc/src/adc1.c mcc_generated_files/input_capture/src/sccp4.c mcc_generated_files/input_capture/src/sccp2.c mcc_generated_files/input_capture/src/sccp3.c mcc_generated_files/input_capture/src/sccp1.c mcc_generated_files/pwm_hs/src/pwm.c mcc_generated_files/system/src/dmt_asm.s mcc_generated_files/system/src/dmt.c mcc_generated_files/system/src/reset.c mcc_generated_files/system/src/system.c mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/interrupt.c mcc_generated_files/system/src/where_was_i.s mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/traps.c mcc_generated_files/timer/src/delay.c mcc_generated_files/timer/src/tmr1.c mcc_generated_files/uart/src/uart1.c main.c VCOMP.c VCOMP_asm.s

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o ${OBJECTDIR}/mcc_generated_files/system/src/system.o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o ${OBJECTDIR}/main.o ${OBJECTDIR}/VCOMP.o ${OBJECTDIR}/VCOMP_asm.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o.d ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o.d ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o.d ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o.d ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d ${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o.d ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d ${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o.d ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/VCOMP.o.d ${OBJECTDIR}/VCOMP_asm.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o ${OBJECTDIR}/mcc_generated_files/system/src/system.o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o ${OBJECTDIR}/main.o ${OBJECTDIR}/VCOMP.o ${OBJECTDIR}/VCOMP_asm.o

# Source Files
SOURCEFILES=mcc_generated_files/adc/src/adc1.c mcc_generated_files/input_capture/src/sccp4.c mcc_generated_files/input_capture/src/sccp2.c mcc_generated_files/input_capture/src/sccp3.c mcc_generated_files/input_capture/src/sccp1.c mcc_generated_files/pwm_hs/src/pwm.c mcc_generated_files/system/src/dmt_asm.s mcc_generated_files/system/src/dmt.c mcc_generated_files/system/src/reset.c mcc_generated_files/system/src/system.c mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/interrupt.c mcc_generated_files/system/src/where_was_i.s mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/traps.c mcc_generated_files/timer/src/delay.c mcc_generated_files/timer/src/tmr1.c mcc_generated_files/uart/src/uart1.c main.c VCOMP.c VCOMP_asm.s



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CH512MP506
MP_LINKER_FILE_OPTION=,--script=p33CH512MP506.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o: mcc_generated_files/adc/src/adc1.c  .generated_files/flags/default/89fa33e01a8ff281180fffc890938c7b17c43ea2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/adc/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc/src/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o: mcc_generated_files/input_capture/src/sccp4.c  .generated_files/flags/default/7ba2b1ab4fd49f8c2de2ebb5ab9b8ade2602110e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp4.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o: mcc_generated_files/input_capture/src/sccp2.c  .generated_files/flags/default/90c0c334b966a3d96c8eeec89269658fe1ee5227 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp2.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o: mcc_generated_files/input_capture/src/sccp3.c  .generated_files/flags/default/e5a5f1d4c42dc7bb5943791123e20b92c23c8ae8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp3.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o: mcc_generated_files/input_capture/src/sccp1.c  .generated_files/flags/default/ed25e26dda19f9be6acd668bf61f48728034e90a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp1.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o: mcc_generated_files/pwm_hs/src/pwm.c  .generated_files/flags/default/608dd3e4346b002f310219a7b5f6609063d4e9b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/pwm_hs/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pwm_hs/src/pwm.c  -o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/dmt.o: mcc_generated_files/system/src/dmt.c  .generated_files/flags/default/dd8e1747100f2ef5643f1db32570723f51bbc358 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/dmt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/reset.o: mcc_generated_files/system/src/reset.c  .generated_files/flags/default/e40b197f7a26f0907acb7626e96a61d3ceee0bb9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/reset.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/system.o: mcc_generated_files/system/src/system.c  .generated_files/flags/default/1c83734ab44f4c0f2027c0f3caa1a2276027e84c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/system.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.o: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/7c5d3ffe587b45cdd6842e19b9fa524691912249 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/clock.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.o: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/25e610e539b055ab95bbddbe6d4445caf752ef58 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/pins.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/f93e1abeb3aee3028bfa514a2c57fa15fb629d2e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/interrupt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/13a8c34b6fbb3c77b15afbff3d7c07260eecb78c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/config_bits.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/traps.o: mcc_generated_files/system/src/traps.c  .generated_files/flags/default/5027157d5e3b1c78bae25f17798e18084a6d558 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/traps.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/delay.o: mcc_generated_files/timer/src/delay.c  .generated_files/flags/default/19500e413d2a3d02a0be2d1e6aa27f01693a99a3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/delay.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/delay.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o: mcc_generated_files/timer/src/tmr1.c  .generated_files/flags/default/8b588654585e66be82ddf7b1d9b39b1939342c31 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o: mcc_generated_files/uart/src/uart1.c  .generated_files/flags/default/27279fceb2d7e1c25ad17dfb0ed385a9f5fd6bdf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/uart/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart/src/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/32f7ab0c629bd3dc0e5aa84702d90ef4f15144fb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/VCOMP.o: VCOMP.c  .generated_files/flags/default/2187efe2ce43271bcda212f8dabbfa97a6f1ce3b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/VCOMP.o.d 
	@${RM} ${OBJECTDIR}/VCOMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  VCOMP.c  -o ${OBJECTDIR}/VCOMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/VCOMP.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o: mcc_generated_files/adc/src/adc1.c  .generated_files/flags/default/a4ce95bd786778984a5c335f3f66bf74fdf63694 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/adc/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc/src/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o: mcc_generated_files/input_capture/src/sccp4.c  .generated_files/flags/default/9827b8693f1ab8312325876328ee31347b36997e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp4.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp4.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o: mcc_generated_files/input_capture/src/sccp2.c  .generated_files/flags/default/3688bbb4e340ac3f212024fedc8d6ecb58d2dab4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp2.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o: mcc_generated_files/input_capture/src/sccp3.c  .generated_files/flags/default/73565468fcf83db1878789fc53a3fac981725966 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp3.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp3.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o: mcc_generated_files/input_capture/src/sccp1.c  .generated_files/flags/default/2ab13a95ddd791312b336e329acae804e51d2c06 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/input_capture/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/input_capture/src/sccp1.c  -o ${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/input_capture/src/sccp1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o: mcc_generated_files/pwm_hs/src/pwm.c  .generated_files/flags/default/d8408da9ad2a78f1e994d48c8d251418f6a93265 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/pwm_hs/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pwm_hs/src/pwm.c  -o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/dmt.o: mcc_generated_files/system/src/dmt.c  .generated_files/flags/default/63a965402374ad3ae01b6bcebeffb1dac721ff12 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/dmt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/reset.o: mcc_generated_files/system/src/reset.c  .generated_files/flags/default/4bfbe1cbceeb12258e7ae3a9c952f9ce9be05957 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/reset.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/system.o: mcc_generated_files/system/src/system.c  .generated_files/flags/default/96baf7fe1baab6345cbda9f40519ea007b762418 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/system.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.o: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/48208ca1b67683f04b26d5c287d6b2cd2bcd90c2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/clock.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.o: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/bc26c8f2adcca94616edc71d56d1a31673816cc6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/pins.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/9b05df4ae2ed756127021eeba77536539b6848be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/interrupt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/799d1fbedf719aedfec7ed3486f06358f6200b28 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/config_bits.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/traps.o: mcc_generated_files/system/src/traps.c  .generated_files/flags/default/153ea590f6a0c4ec58cbbb3ad725cd6e84b97052 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/traps.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/delay.o: mcc_generated_files/timer/src/delay.c  .generated_files/flags/default/de3e687ca2b2ceba162e3c3b01516bfdffe8142d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/delay.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/delay.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o: mcc_generated_files/timer/src/tmr1.c  .generated_files/flags/default/c566745b19a791ded67b91e95c884300fc5fa427 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o: mcc_generated_files/uart/src/uart1.c  .generated_files/flags/default/899b0804e3c13a071aec4aa9855859eed39bf2fd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/uart/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart/src/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/7a881a36909f5dcb5b9afb0b104e94ba802d8c45 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/VCOMP.o: VCOMP.c  .generated_files/flags/default/db357d41dbbd00a616e7f0096405477e69fdfbca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/VCOMP.o.d 
	@${RM} ${OBJECTDIR}/VCOMP.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  VCOMP.c  -o ${OBJECTDIR}/VCOMP.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/VCOMP.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o: mcc_generated_files/system/src/dmt_asm.s  .generated_files/flags/default/8fd6b7dfdf79a638d81a4667573abb1b46569cb2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/system/src/dmt_asm.s  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o: mcc_generated_files/system/src/where_was_i.s  .generated_files/flags/default/c2eb0e23261b4bd3d62f0189df72bc6e558b1dc9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/system/src/where_was_i.s  -o ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/VCOMP_asm.o: VCOMP_asm.s  .generated_files/flags/default/fc074766bd7819a570c0ac1d3a12dd7c577c1a91 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/VCOMP_asm.o.d 
	@${RM} ${OBJECTDIR}/VCOMP_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  VCOMP_asm.s  -o ${OBJECTDIR}/VCOMP_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/VCOMP_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o: mcc_generated_files/system/src/dmt_asm.s  .generated_files/flags/default/d1e819b342dd4b25af454f64da1143fbfb911686 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/system/src/dmt_asm.s  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o: mcc_generated_files/system/src/where_was_i.s  .generated_files/flags/default/dadb4116b928592a4443f0793dcb789e104c9f60 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/system/src/where_was_i.s  -o ${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/system/src/where_was_i.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/VCOMP_asm.o: VCOMP_asm.s  .generated_files/flags/default/372f209772b3b8e0b4efa8c22d558bb68b2119ca .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/VCOMP_asm.o.d 
	@${RM} ${OBJECTDIR}/VCOMP_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  VCOMP_asm.s  -o ${OBJECTDIR}/VCOMP_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -Wa,-MD,"${OBJECTDIR}/VCOMP_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/CH512MP506_Controller.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
