class TClntIfaceMgr;

#ifndef CLNTMSGLEASEQUERY_H
#define CLNTMSGLEASEQUERY_H


#include "SmartPtr.h"
#include "ClntMsg.h"
#include "ClntCfgMgr.h"
#include "ClntOptLQ.h"

class TClntMsgLeaseQuery : public TClntMsg
{
  public:


    ClntMsgLeasequery(int iface, SPtr<TIPv6Addr> addr, int msgSize, int msgType, int TransID, char* buf, int bufSize);
    ClntMsgLeasequery(int iface, SPtr<TIPv6Addr> addr, int msgSize, int msgType, int TransID);

    bool queryByAddress();
    bool queryByClientID();
    bool queryByLinkAddress();
    bool queryByRemoteID();
    bool queryByRelayID();

    // set attributes according to RFC
    void setAttributes(int iface, SPtr<TIPv6Addr> addr, int msgSize, int msgType, long transID);
    void sendTcp();
    void retryConnection(); //if server doesn't answer retry attemption
    void validateLQ();//defined in rfc 5007 (why validate ?)
    void isComletion(); //check completion of server replay (rfc 5460 p.11)
    void multipleQuery();//requestor can send multiple query to receive more data
    void terminate();//terminate tcp connection after BULK_LQ_DATA_TIMEOUT

   // void answer(SPtr<TClntMsg> msg);
   // todo: discarding messages if doesn't contain client's data
    void doDuties();
    bool check(); //check if sending message is correct
    string getName();
    ~ClntMsgLeasequery();
};



#endif // CLNTMSGLEASEQUERY_H
