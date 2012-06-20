/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *
 * Released under GNU GPL v2 licence
 *
 * $Id: ReqMsg.cpp,v 1.2 2007-12-03 16:59:17 thomson Exp $
 */

#include <string>
#include "ReqMsg.h"
#include "DHCPConst.h"
<<<<<<< HEAD
#include "ReqTransMgr.h"

using namespace std;

TReqMsg::TReqMsg(int iface, SPtr<TIPv6Addr> addr, int msgType, int msgSize)
    :TMsg(iface, addr, msgType)
{
    this->setAttributes(iface,addr,msgSize,msgType,transID);
=======

using namespace std;

TReqMsg::TReqMsg(int iface, SPtr<TIPv6Addr> addr, int msgType)
    :TMsg(iface, addr, msgType)
{

>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}
    // used to create TMsg object based on received char[] data
TReqMsg::TReqMsg(int iface, SPtr<TIPv6Addr> addr, char* &buf, int &bufSize)
    :TMsg(iface, addr, buf, bufSize)
{
<<<<<<< HEAD
     this->setAttributes(iface,addr,msgSize,msgType,transID);
=======

>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}


string TReqMsg::getName() 
{
    switch (MsgType) {
    case LEASEQUERY_MSG:
        return "LEASEQUERY";    
    case LEASEQUERY_REPLY_MSG:
        return "LEASEQUERY_RSP";
    default:
        return "unknown";
    }
}

void TReqMsg::addOption(SPtr<TOpt> opt)
{
    Options.push_back(opt);
}

<<<<<<< HEAD
void TReqMsg::setAttributes(int iface, SPtr<TIPv6Addr> addr, int msgSize, int msgType, long transID)
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


void TReqMsg::validateLQ()
{

}

void TReqMsg::isComletion()
{

}

void TReqMsg::multipleQuery()
{
}



=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
