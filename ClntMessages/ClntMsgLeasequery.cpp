#include "ClntMsgLeasequery.h"
#include "SmartPtr.h"
#include "DHCPConst.h"
#include "Container.h"
#include "ClntIfaceMgr.h"
#include "ClntMsgAdvertise.h"
#include "OptDUID.h"
#include "ClntOptIA_NA.h"
#include "ClntOptElapsed.h"
#include "Logger.h"
#include "ClntOptOptionRequest.h"
#include "ClntCfgIface.h"
#include "ClntOptDNSServers.h"
#include "ClntOptNTPServers.h"
#include "ClntOptDomainName.h"
#include "ClntOptTimeZone.h"
#include <cmath>


TClntMsgLeaseQuery::ClntMsgLeasequery(int iface, SPtr<TIPv6Addr> addr, int msgSize, int msgType, int TransID, ELeaseQueryType  QueryType)
{
    setAttributes();

    switch (QueryType->getQueryType()) {
    case QUERY_BY_ADDRESS:
       // send = queryByAddress();
       //break;
    case QUERY_BY_CLIENT_ID:
       // send = queryByClientID();
       // break;
    case QUERY_BY_LINK_ADDRESS:
       // send = queryByLinkAddress();
       // break;
    case QUERY_BY_RELAY_ID:
      //  send = queryByRelayID();
      //  break;
    case QUERY_BY_REMOTE_ID:
      //  send = queryByRemoteID();
      //  break;
    default:
        Options.push_back( new TSrvOptStatusCode(STATUSCODE_UNKNOWNQUERYTYPE, "Invalid Query type.", this) );
        Log(Warning) << "LQ: Invalid query type (" << q->getQueryType() << " received." << LogEnd;
        return true;
    }

    //appendClientID();
    sendTcp();
}

void TClntMsgLeaseQuery::doDuties()
{

}




void TClntMsgLeaseQuery::validateLQ()
{
}

void TClntMsgLeaseQuery::multipleQuery()
{
}

void TClntMsgLeaseQuery::isComletion()
{
}

void TClntMsgLeaseQuery::retryConnection()
{
}

void TClntMsgLeaseQuery::setAttributes(int iface, SPtr<TIPv6Addr> addr, int msgSize, int msgType, long transID)
{


    PeerAddr=addr;

    messageSize=msgSize;
    this->Iface=iface;
    TransID=transID;
    IsDone=false;
    MsgType=msgType;
    this->pkt=NULL;
    DigestType = DIGEST_NONE; /* by default digest is none */
    AuthInfoPtr = NULL;
    AuthInfoKey = NULL;
    KeyGenNonce = NULL;
    KeyGenNonceLen = 0;
    AAASPI = 0;
    SPI = 0;
    ReplayDetection = 0;
}

void TClntMsgLeaseQuery::sendTcp()
{


}

void TClntMsgLeaseQuery::terminate()
{


}




