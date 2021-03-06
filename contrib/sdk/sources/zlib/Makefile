# Makefile for zlib, derived from Makefile.dj2.
# Modified for mingw32 by C. Spieler, 6/16/98.
# Updated for zlib 1.2.x by Christian Spieler and Cosmin Truta, Mar-2003.
# Last updated: Mar 2012.
# Tested under Cygwin and MinGW.

# Copyright (C) 1995-2003 Jean-loup Gailly.
# For conditions of distribution and use, see copyright notice in zlib.h

STATICLIB = libz.a
SHAREDLIB = libz.dll
IMPLIB    = libz.dll.a

CC = kos32-gcc
LD = kos32-ld
AR = kos32-ar
STRIP = kos32-strip

INSTALLDIR:= /home/autobuild/tools/win32/lib

CFLAGS = $(LOC) -DHAVE_UNISTD_H -U_Win32 -U_WIN32 -U__MINGW32__ -O2 -Wall -fno-ident -fomit-frame-pointer 

AS = $(CC)
ASFLAGS = $(LOC) -Wall

LDFLAGS = $(LOC)

ARFLAGS = rcs

LDFLAGS:=  -shared -s -T dll.lds --entry _DllStartup --image-base=0 --out-implib $(IMPLIB)

INCLUDES= -I../newlib/libc/include

LIBS:=  -ldll -lc.dll

ifeq ($(findstring ebox,$(MAKECMDGOALS)),ebox)
CFLAGS+=-march=pentium-mmx
endif

OBJS = adler32.o compress.o crc32.o deflate.o gzclose.o gzlib.o gzread.o \
       gzwrite.o infback.o inffast.o inflate.o inftrees.o trees.o uncompr.o zutil.o
OBJA =

all: $(STATICLIB) $(SHAREDLIB) $(IMPLIB) Makefile

ebox: $(STATICLIB) $(SHAREDLIB) $(IMPLIB) Makefile

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

.S.o:
	$(AS) $(ASFLAGS) -c -o $@ $<

$(STATICLIB): $(OBJS) $(OBJA) Makefile
	$(AR) $(ARFLAGS) $@ $(OBJS) $(OBJA)
	mv -f libz.a $(INSTALLDIR)

$(IMPLIB): $(SHAREDLIB)

$(SHAREDLIB): zlib.def $(OBJS) $(OBJA) Makefile
	$(LD) $(LDFLAGS) -o $@ zlib.def $(OBJS) $(OBJA) $(LIBS) 
	$(STRIP) $@
	#sed -f ../newlib/cmd1.sed zlib.def > mem
	#sed -f ../newlib/cmd2.sed mem >zlib.inc 
	mv -f libz.dll ../../bin
	mv -f libz.dll.a $(INSTALLDIR)


adler32.o: zlib.h zconf.h
compress.o: zlib.h zconf.h
crc32.o: crc32.h zlib.h zconf.h
deflate.o: deflate.h zutil.h zlib.h zconf.h
gzclose.o: zlib.h zconf.h gzguts.h
gzlib.o: zlib.h zconf.h gzguts.h
gzread.o: zlib.h zconf.h gzguts.h
gzwrite.o: zlib.h zconf.h gzguts.h
inffast.o: zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h
inflate.o: zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h
infback.o: zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h
inftrees.o: zutil.h zlib.h zconf.h inftrees.h
trees.o: deflate.h zutil.h zlib.h zconf.h trees.h
uncompr.o: zlib.h zconf.h
zutil.o: zutil.h zlib.h zconf.h
