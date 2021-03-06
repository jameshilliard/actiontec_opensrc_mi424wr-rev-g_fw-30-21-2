# Makefile.in for kaffe - a Java(tm) compatible virtual machine wrapper.
#
# Copyright (c) 1996, 1997, 1998, 1999
#	Transvirtual Technologies, Inc.  All rights reserved.
#
# See the file "license.terms" for information on usage and redistribution 
# of this file. 

jrebin_PROGRAMS = kaffe-bin

if NEED_LIBXPROF
libxprof = ../xprof/libkaffexprof.la
endif

if ENABLE_JVMPI
libjvmpi = ../jvmpi/libkaffejvmpi.la
endif

if COND_KAFFE_X_AWT
INCLUDE_KAFFE_X_AWT = -DKAFFE_X_AWT_INCLUDED
endif

if COND_KAFFE_QT_AWT
INCLUDE_KAFFE_QT_AWT = -DKAFFE_QT_AWT_INCLUDED
endif

if COND_KAFFE_NANOX_AWT
INCLUDE_KAFFE_NANOX_AWT = -DKAFFE_NANOX_AWT_INCLUDED
endif

AM_CPPFLAGS = \
	-I../kaffevm \
	-I$(srcdir)/../kaffevm \
	-I$(top_srcdir)/libltdl \
	-I$(top_srcdir)/kaffe/jvmpi \
	-I$(top_srcdir)/kaffe/xprof \
	-I$(top_srcdir)/kaffe/kaffevm/jni \
	-I$(top_builddir)/include \
	$(INCLUDE_KAFFE_X_AWT) \
	$(INCLUDE_KAFFE_QT_AWT) \
	$(INCLUDE_KAFFE_NANOX_AWT)

kaffe_bin_SOURCES = \
	main.c \
	version.c \
	version.h

LIBKAFFEVM = \
	$(libxprof) \
	$(libjvmpi) \
	$(top_builddir)/kaffe/kaffevm/libkaffevm.la

kaffe_bin_LDFLAGS = \
	$(KVMBINFLAGS) \
	-export-dynamic

kaffe_bin_LDADD = \
	$(DLOPEN_JAVA_LIBS) \
	$(OPT_DLOPEN_JAVA_LIBS) \
	$(LIBKAFFEVM) \
	$(KAFFE_LIBS) \
	$(top_builddir)/replace/libreplace.la \
	$(LTLIBINTL) 

kaffe_bin_DEPENDENCIES = \
	$(LIBKAFFEVM) \
	$(JAVA_LIBS)

### Rules to generate the version-info header file
version.o: version-info.h
version-info.h: $(top_srcdir)/ChangeLog $(top_builddir)/config.status
	-rm -f $@ $@T
	echo "/* version-info.h is automagically generated by Kaffe's Makefile */" > $@T
	sed < $(top_srcdir)/ChangeLog            \
	  -e 's/^/#define VER_CHANGELOG_HEAD "/' \
	  -e 's/$$/"/'				 \
	  -e '1q' >> $@T
	echo '#define VER_COMPILE_DATE  "'`date`'" '            >> $@T
	echo '#define VER_COMPILE_HOST  "'`hostname`'"'         >> $@T
	echo '#define VER_CC            "$(CC)"'                >> $@T
	echo '#define VER_KAFFELIBS     "$(Kaffe_LDADD)""$(LIBS)"'      >> $@T
	echo '#define VER_CFLAGS        "$(AM_CFLAGS)""$(CFLAGS)"'      >> $@T
	echo '#define VER_CPPFLAGS      "$(AM_CPPFLAGS)""$(CPPFLAGS)"'  >> $@T
	echo '#define VER_LDFLAGS       "$(Kaffe_LDFLAGS)"'            >> $@T
	echo '#define VER_DEFS          "$(DEFS)"'              >> $@T
	echo '#define VER_PREFIX        "$(prefix)"'            >> $@T
	echo '#define VER_THREAD_SYSTEM "$(THREAD_SYSTEM)"'     >> $@T
	echo '#define VER_GARBAGE_COLLECTOR "$(GC_NAME)"'     >> $@T
	-mv $@T $@

DISTCLEANFILES = version-info.h

dist-hook:
	@for file in $(DISTCLEANFILES); do \
	  rm -f $(distdir)/$$file; \
	done
