<<<<<<< HEAD
 /*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *
 * released under GNU GPL v2 only licence
 *
=======
/*                                                                           
 * Dibbler - a portable DHCPv6                                               
 *                                                                           
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>                           
 *
 * released under GNU GPL v2 only licence                                
 *                                                                           
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
 */

class TSrvMsgLeaseQuery;
#ifndef SRVMSGLEASEQUERY_H
#define SRVMSGLEASEQUERY_H

#include "SmartPtr.h"
#include "SrvMsg.h"
#include "IPv6Addr.h"

class TSrvMsgLeaseQuery : public TSrvMsg
{
  public:
<<<<<<< HEAD
    TSrvMsgLeaseQuery(int iface, SPtr<TIPv6Addr> addr, char* buf,
                      int bufSize, bool tcp = false);

=======
    TSrvMsgLeaseQuery(int iface, SPtr<TIPv6Addr> addr, char* buf, int bufSize);
    
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    void doDuties();
    bool check();
    ~TSrvMsgLeaseQuery();
    string getName();
<<<<<<< HEAD
    bool isTCP() { return tcp; };
  private:
    bool tcp;
=======

  private:
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
};


#endif /* SRVMSGREQUEST_H */
