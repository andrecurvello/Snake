/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.platforms.stellaris package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"F:\workspace\projects\Snake\Debug\configPkg\package\cfg\app_pem3.oem3"
-l"F:\Program Files\Texas Instruments\ccsv5.2.1\xdctools_3_23_03_53\packages\ti\catalog\arm\cortexm3\lm3init\lib\Boot.aem3"
-l"F:\Program Files\Texas Instruments\ccsv5.2.1\bios_6_33_05_46\packages\ti\sysbios\lib\instrumented_em3\sysbios\sysbios.lib"
-l"F:\Program Files\Texas Instruments\ccsv5.2.1\xdctools_3_23_03_53\packages\ti\targets\arm\rtsarm\lib\ti.targets.arm.rtsarm.aem3"
-l"F:\Program Files\Texas Instruments\ccsv5.2.1\xdctools_3_23_03_53\packages\ti\targets\arm\rtsarm\lib\boot.aem3"
-l"F:\Program Files\Texas Instruments\ccsv5.2.1\xdctools_3_23_03_53\packages\ti\targets\arm\rtsarm\lib\auto_init.aem3"

--retain="*(xdc.meta)"

/* C6x Elf symbols */
--symbol_map __TI_STACK_SIZE=__STACK_SIZE
--symbol_map __TI_STACK_BASE=__stack
--symbol_map _stack=__stack


--args 0x0
-heap  0x0
-stack 0x2000

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.arm (null): */

/* Content from ti.targets.arm.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.targets.arm.rtsarm (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.family.arm (ti/sysbios/family/arm/linkcmd.xdt): */
--retain "*(.vecs)"

/* Content from ti.sysbios.hal (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.arm.m3 (ti/sysbios/family/arm/m3/linkcmd.xdt): */
--retain "*(.resetVecs)"

/* Content from ti.sysbios.family.arm.lm3 (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.catalog.arm.cortexm3 (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.arm.peripherals.timers (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.catalog.arm.cortexm4 (null): */

/* Content from ti.catalog.arm.cortexm3.lm3init (null): */

/* Content from ti.platforms.stellaris (null): */

/* Content from configPkg (null): */



/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;


SECTIONS
{
    .text: load >> FLASH
    .stack: load > SRAM
    .bss: load > SRAM
    .cinit: load > FLASH
    .init_array: load >> SRAM
    .const: load >> FLASH
    .data: load >> SRAM
    .rodata: load >> SRAM
    .neardata: load >> SRAM
    .fardata: load >> SRAM
    .switch: load >> SRAM
    .sysmem: load > SRAM
    .far: load >> SRAM
    .args: load > SRAM align = 0x4, fill = 0 {_argsize = 0x0; }
    .cio: load >> SRAM
    .bootVecs:  type = DSECT
    .vecs: load > 0x20000000
    .resetVecs: load > 0x0
    .pinit: load > FLASH



    xdc.meta: type = COPY
}
