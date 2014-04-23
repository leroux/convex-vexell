##############################################################################
# Build global options
# NOTE: Can be overridden externally.
#
include setup.mk

# Compiler options here.
ifeq ($(USE_OPT),)
  USE_OPT = -O2 -ggdb -fomit-frame-pointer -falign-functions=16 -fgnu89-inline
endif

# C specific options here (added to USE_OPT).
ifeq ($(USE_COPT),)
  USE_COPT =
endif

# C++ specific options here (added to USE_OPT).
ifeq ($(USE_CPPOPT),)
  USE_CPPOPT = -fno-rtti
endif

# Enable this if you want the linker to remove unused code and data
ifeq ($(USE_LINK_GC),)
  USE_LINK_GC = yes
endif

# If enabled, this option allows to compile the application in THUMB mode.
ifeq ($(USE_THUMB),)
  USE_THUMB = yes
endif

# Enable this if you want to see the full log while compiling.
ifeq ($(USE_VERBOSE_COMPILE),)
  USE_VERBOSE_COMPILE = no
endif

#
# Build global options
##############################################################################

##############################################################################
# Architecture or project specific options
#

# Enable this if you really want to use the STM FWLib.
ifeq ($(USE_FWLIB),)
  USE_FWLIB = no
endif

#
# Architecture or project specific options
##############################################################################

##############################################################################
# Project, sources and paths
#

# PROS compatible build directory
ifeq ($(BUILDDIR),)
BUILDDIR = bin
endif

# Define project name here
ifeq ($(PROJECT),)
PROJECT  = output
endif

# Path to Vexell - default assumes making examples
ifeq ($(CHIBIOS),)
VEXELL = ../../vexell
endif

# Path to ChibiOS/RT - default assumes making examples
ifeq ($(CHIBIOS),)
CHIBIOS = $(VEXELL)/../ChibiOS-RT
endif

# Path to ConVEX root - default assumes making examples
ifeq ($(CONVEX),)
CONVEX  = $(VEXELL)/../convex/convex/cortex
endif

# Imported source files and paths
include boards/VEX_STM32_CORTEX/board.mk
include $(CHIBIOS)/os/hal/platforms/STM32F1xx/platform.mk
include $(CHIBIOS)/os/hal/hal.mk
include $(CHIBIOS)/os/ports/GCC/ARMCMx/STM32F1xx/port.mk
include $(CHIBIOS)/os/kernel/kernel.mk
include $(CONVEX)/fw/vexfw.mk
include $(CHIBIOS)/test/test.mk

# include the optional code
ifeq    ($(CONVEX_OPT),yes)
include $(CONVEX)/opt/vexopt.mk
endif

# Define linker script file here
LDSCRIPT= $(CONVEX)/ld/STM32F103xD.ld

# C sources that can be compiled in ARM or THUMB mode depending on the global
# setting.
# replaced standard shell with custom variant
# $(CHIBIOS)/os/various/shell.c \

CSRC = $(PORTSRC) \
       $(KERNSRC) \
       $(TESTSRC) \
       $(HALSRC) \
       $(PLATFORMSRC) \
       $(BOARDSRC) \
       $(CHIBIOS)/os/various/evtimer.c \
       $(CHIBIOS)/os/various/syscalls.c \
       $(CHIBIOS)/os/various/chprintf.c \
       $(VEXFWSRC) \
       $(VEXOPTSRC) \
       $(VEXUSERSRC) \
       main.c \
       dummy4jhc.c

# C++ sources that can be compiled in ARM or THUMB mode depending on the global
# setting.
CPPSRC =

# C sources to be compiled in ARM mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
ACSRC =

# C++ sources to be compiled in ARM mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
ACPPSRC =

# C sources to be compiled in THUMB mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
TCSRC =

# C sources to be compiled in THUMB mode regardless of the global setting.
# NOTE: Mixing ARM and THUMB mode enables the -mthumb-interwork compiler
#       option that results in lower performance and larger code size.
TCPPSRC =

# List ASM source files here
ASMSRC = $(PORTASM)

INCDIR = $(PORTINC) $(KERNINC) $(TESTINC) \
         $(HALINC) $(PLATFORMINC) $(BOARDINC) \
         $(CHIBIOS)/os/various \
         $(VEXFWINC) $(VEXOPTINC) $(VEXUSERINC)

#
# Project, sources and paths
##############################################################################

##############################################################################
# Haskell defines
#

HSDIR   = build_haskell
HSCSRC  += $(HSDIR)/rts/gc_jgc.c $(HSDIR)/rts/jhc_rts.c $(HSDIR)/rts/stableptr.c
HSCSRC  += $(HSDIR)/rts/rts_support.c $(HSDIR)/rts/conc.c $(HSDIR)/rts/conc_custom.c
HSCSRC  += $(HSDIR)/hs_main.c
CSRC    += $(HSCSRC)
INCDIR  += $(HSDIR)
USE_OPT += -std=gnu99 -ffreestanding -nostdlib
USE_OPT += -Wno-unused-parameter -fno-strict-aliasing -D_GNU_SOURCE
USE_OPT += -DNDEBUG -D_JHC_GC=_JHC_GC_JGC -D_JHC_STANDALONE=0 -D_JHC_USE_OWN_STDIO
USE_OPT += -D_LITTLE_ENDIAN
USE_OPT += -D_JHC_ARM_STAY_IN_THUMB_MODE
USE_OPT += -D_JHC_JGC_STACKGROW=16 -D_JHC_JGC_LIMITED_NUM_MEGABLOCK=3
USE_OPT += -D_JHC_JGC_BLOCK_SHIFT=8 -D_JHC_JGC_MEGABLOCK_SHIFT=13
USE_OPT += -D_JHC_JGC_GC_STACK_SHIFT=8 -D_JHC_JGC_LIMITED_NUM_GC_STACK=2
USE_OPT += -D_JHC_JGC_NAIVEGC -D_JHC_JGC_SAVING_MALLOC_HEAP
USE_OPT += -D_JHC_CONC=_JHC_CONC_CUSTOM

#
# Haskell defines
##############################################################################

##############################################################################
# Compiler settings
#

MCU  = cortex-m3

#TRGT = arm-elf-
TRGT = arm-none-eabi-
CC   = $(TRGT)gcc
CPPC = $(TRGT)g++
# Enable loading with g++ only if you need C++ runtime support.
# NOTE: You can use C++ even without C++ support if you are careful. C++
#       runtime support makes code size explode.
LD   = $(TRGT)gcc
#LD   = $(TRGT)g++
CP   = $(TRGT)objcopy
AS   = $(TRGT)gcc -x assembler-with-cpp
OD   = $(TRGT)objdump
HEX  = $(CP) -O ihex
BIN  = $(CP) -O binary

# ARM-specific options here
AOPT =

# THUMB-specific options here
TOPT = -mthumb -DTHUMB

# Define C warning options here
CWARN = -Wall -Wextra -Wstrict-prototypes

# Define C++ warning options here
CPPWARN = -Wall -Wextra

#
# Compiler settings
##############################################################################

##############################################################################
# Start of default section
#

# List all default C defines here, like -D_DEBUG=1
DDEFS =

# List all default ASM defines here, like -D_DEBUG=1
DADEFS =

# List all default directories to look for include files here
DINCDIR =

# List the default directory to look for the libraries here
DLIBDIR =

# List all default libraries here
DLIBS =

#
# End of default section
##############################################################################

##############################################################################
# Start of user section
#

# List all user C define here, like -D_DEBUG=1
UDEFS =

# Define ASM defines here
UADEFS =

# List all user directories here
UINCDIR =

# List the user directory to look for the libraries here
ULIBDIR =

# List all user libraries here
ULIBS = -lm

#
# End of user defines
##############################################################################

ifeq ($(USE_FWLIB),yes)
  include $(CHIBIOS)/ext/stm32lib/stm32lib.mk
  CSRC += $(STM32SRC)
  INCDIR += $(STM32INC)
  USE_OPT += -DUSE_STDPERIPH_DRIVER
endif

include $(CHIBIOS)/os/ports/GCC/ARMCMx/rules.mk
