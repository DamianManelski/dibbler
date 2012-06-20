#ifndef CLNTOPTLQ_H
#define CLNTOPTLQ_H

#include "Opt.h"
#include "DHCPConst.h"
#include "SmartPtr.h"
#include "DUID.h"
#include "IPv6Addr.h"
#include "OptInteger.h"
#include "OptGeneric.h"

class TClntOptLQ: public TOpt{

public:
  TClntOptLQ(char * buf, int bufsize, TMsg* parent);
  bool doDuties();
  ELeaseQueryType getQueryType();
  int getSize();
  char * storeSelf(char* buf);
  // SPtr<TIPv6Addr> getLinkAddr(); // not uses by bulk leasequery (?)
private:
  ELeaseQueryType QueryType;
  SPtr<TDUID> Duid;
  SPtr<TIPv6Addr> Addr;

  bool IsValid;

}



#endif // CLNTOPTLQ_H
