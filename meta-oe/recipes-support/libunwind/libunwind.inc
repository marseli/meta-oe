DESCRIPTION = "a portable and efficient C programming interface (API) to determine the call-chain of a program"
HOMEPAGE = "http://www.nongnu.org/libunwind"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=3fced11d6df719b47505837a51c16ae5"

SRC_URI = "http://download.savannah.nongnu.org/releases/${BPN}/${BPN}-${PV}.tar.gz"

MIRRORS += "http://download.savannah.nongnu.org/releases/ http://download-mirror.savannah.gnu.org/releases/ \n"

inherit autotools

PACKAGECONFIG ??= ""
PACKAGECONFIG[lzma] = "--enable-minidebuginfo,--disable-minidebuginfo,lzma"

EXTRA_OECONF_arm = "--enable-debug-frame"

CFLAGS += "${ATOMICOPS}"
ATOMICOPS_armv5 = "-DAO_USE_PTHREAD_DEFS=1"
ATOMICOPS_armv4 = "-DAO_USE_PTHREAD_DEFS=1"
ATOMICOPS ?= ""

LDFLAGS += "${LIBATOMICS}"
LIBATOMICS_armv5 = "-latomic_ops"
LIBATOMICS_armv4 = "-latomic_ops"
LIBATOMICS ?= ""

DEPENDS += "${DEPLIBATOMICS}"
DEPLIBATOMICS_armv5 = "libatomics-ops"
DEPLIBATOMICS_armv4 = "libatomics-ops"
DEPLIBATOMICS ?= ""

BBCLASSEXTEND = "native"
