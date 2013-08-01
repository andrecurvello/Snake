#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = F:/PROGRA~1/TEXASI~1/ccsv5.2.1/bios_6_33_05_46/packages;F:/PROGRA~1/TEXASI~1/ccsv5.2.1/ccsv5/ccs_base
override XDCROOT = F:/PROGRA~1/TEXASI~1/ccsv5.2.1/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = F:/PROGRA~1/TEXASI~1/ccsv5.2.1/bios_6_33_05_46/packages;F:/PROGRA~1/TEXASI~1/ccsv5.2.1/ccsv5/ccs_base;F:/PROGRA~1/TEXASI~1/ccsv5.2.1/xdctools_3_23_03_53/packages;..
HOSTOS = Windows
endif
