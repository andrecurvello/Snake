################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/kernel/devices/led.obj: ../src/kernel/devices/led.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="F:/workspace/projects/Snake" --include_path="F:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/kernel/devices/led.pp" --obj_directory="src/kernel/devices" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/kernel/devices/uart.obj: ../src/kernel/devices/uart.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="F:/workspace/projects/Snake" --include_path="F:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/kernel/devices/uart.pp" --obj_directory="src/kernel/devices" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/kernel/devices/watchdog.obj: ../src/kernel/devices/watchdog.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="F:/workspace/projects/Snake" --include_path="F:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/kernel/devices/watchdog.pp" --obj_directory="src/kernel/devices" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


