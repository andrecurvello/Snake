################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/main.obj: ../src/main.cpp $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/bin/cl470" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5/include" --include_path="F:/workspace/projects/Snake" --include_path="F:/StellarisWare" --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


