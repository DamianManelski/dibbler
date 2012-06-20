#include <iostream>
#include "DNSUpdate.h"
#include "Logger.h"

using namespace std;
<<<<<<< HEAD
int main(int argc, const char *argv[]) {
=======

bool DnsUpdate_test(DNSUpdate::DnsUpdateProtocol proto, bool dhcid, bool tsig) {
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    string dnsAddr   = "2000::1";
    string zonename  = "example.org.";
    string hostname  = "troi.example.org.";
    string hostip    = "2000::dead:beef";

<<<<<<< HEAD
    DNSUpdate *act = new DNSUpdate(dnsAddr, zonename, hostname, hostip, 
				   DNSUPDATE_AAAA, DNSUpdate::DNSUPDATE_TCP);
    int result = act->run();
    delete act;
    Log(Debug) << "RESULT: PTR=" << result << LogEnd;

    DNSUpdate *act2= new DNSUpdate(dnsAddr, zonename, hostname, hostip,
				   DNSUPDATE_AAAA, DNSUpdate::DNSUPDATE_UDP);
    int result2 = act2->run();
    delete act2;
    Log(Debug) << "RESULT: PTR=" << result2 << LogEnd;

=======
    char duid[]="this is my duid";
    int duidLen = strlen(duid);

    DNSUpdate *act = new DNSUpdate(dnsAddr, zonename, hostname, hostip, 
				   DNSUPDATE_AAAA, proto);
    if (dhcid)
        act->addDHCID(duid, duidLen);

    int result = act->run(5);
    delete act;
    Log(Debug) << "RESULT: PTR=" << result << LogEnd;

    return true;
}

int main(int argc, const char *argv[]) {

    DnsUpdate_test(DNSUpdate::DNSUPDATE_UDP, false, false);
    DnsUpdate_test(DNSUpdate::DNSUPDATE_TCP, false, false);

    DnsUpdate_test(DNSUpdate::DNSUPDATE_UDP, true, false);
    DnsUpdate_test(DNSUpdate::DNSUPDATE_UDP, false, true);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}
