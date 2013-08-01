################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../app.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"F:/Program Files/Texas Instruments/ccsv5.2.1/xdctools_3_23_03_53/xs" --xdcpath="F:/Program Files/Texas Instruments/ccsv5.2.1/bios_6_33_05_46/packages;F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.stellaris:LM3S6965 -r release -c "F:/Program Files/Texas Instruments/ccsv5.2.1/ccsv5/tools/compiler/tms470_4.9.5" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


