<<<<<<< HEAD
SUBDIRS = poslib 

libposlib_configdir = $(includedir)/$(PACKAGE)-$(VERSION)
libposlib_config_DATA = config.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = poslib-@GENVERSION@.pc 

poslib-@GENVERSION@.pc: poslib.pc
	cp $< $@
	
CLEANFILES = poslib-@GENVERSION@.pc 
=======
noinst_LIBRARIES = libposlib.a
INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/Misc

libposlib_a_SOURCES = \
  dnsmessage.cpp \
  domainfn.cpp \
  exception.cpp \
  lexfn.cpp \
  masterfile.cpp \
  postime.cpp \
  random.cpp \
  resolver.cpp \
  rr.cpp \
  socket.cpp \
  vsnprintf.cpp \
  bits.h \
  dnsmessage.h \
  dnsdefs.h \
  domainfn.h \
  exception.h \
  lexfn.h \
  masterfile.h \
  poslib.h \
  postime.h \
  random.h \
  resolver.h \
  rr.h \
  socket.h \
  syssocket.h \
  sysstl.h \
  sysstring.h \
  syssocket.h \
  types.h \
  vsnprintf.h


dist_noinst_DATA = w32poll.cpp w32poll.h ChangeLog-poslib
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
