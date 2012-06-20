TOPDIR=../..

OBJECTS = DnsUpdate01.o DnsUpdate02.o

TESTS = DnsUpdate01 DnsUpdate02

tests: $(TESTS)

objs: $(OBJECTS)

libs: testDnsUpdate.a

include $(TOPDIR)/Makefile.inc

DnsUpdate01: DnsUpdate01.cpp
<<<<<<< HEAD
	$(CXX) $(CXXFLAGS) -o DnsUpdate01 $< -L$(TOPDIR)/Misc -lMisc \
		              -L$(TOPDIR)/LowLevel \
=======
	$(CXX) $(CPPFLAGS) -o DnsUpdate01 $< 
	$(LD) $< -L$(TOPDIR)/Misc -lMisc \
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
			      -L$(TOPDIR)/IfaceMgr -lIfaceMgr

DnsUpdate02: DnsUpdate02.cpp
	cd $(TOPDIR); make libposlib
	cd $(MISC); make libs
	cd $(SRVIFACEMGR); make libs
	$(CXX) $(CXXFLAGS) -o DnsUpdate02 $< -L$(TOPDIR)/Misc -lMisc \
<<<<<<< HEAD
		              -L$(TOPDIR)/LowLevel \
=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
			      -L$(TOPDIR)/IfaceMgr -lIfaceMgr \
			      -L$(TOPDIR)/SrvIfaceMgr -lSrvIfaceMgr \
			      -L$(POSLIB) -lposlib \
			      -L$(MISC) -lMisc

