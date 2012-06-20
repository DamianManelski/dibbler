<<<<<<< HEAD

=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 * changes: Petr Pisar <petr.pisar(at)atlas(dot)cz>
 *          Nguyen Vinh Nghiem
 *
 * released under GNU GPL v2 only licence
 *
<<<<<<< HEAD
 * $Id: SrvTransMgr.cpp,v 1.38 2008-10-12 20:10:25 thomson Exp $
 *
 */

=======
 */

#include <sstream>
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include <limits.h>
#include "SrvTransMgr.h"
#include "SmartPtr.h"
#include "SrvCfgIface.h"
#include "Iface.h"
#include "DHCPConst.h"
#include "Logger.h"
#include "AddrClient.h"
<<<<<<< HEAD
=======
#include "AddrIA.h"
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include "SrvMsgAdvertise.h"
#include "SrvMsgReply.h"
#include "SrvMsgConfirm.h"
#include "SrvMsgDecline.h"
#include "SrvMsgRequest.h"
#include "SrvMsgReply.h"
#include "SrvMsgRebind.h"
#include "SrvMsgRenew.h"
#include "SrvMsgRelease.h"
#include "SrvMsgLeaseQuery.h"
#include "SrvMsgLeaseQueryReply.h"
<<<<<<< HEAD
#include "SrvMsgLeaseQueryData.h"
#include "SrvMsgLeaseQueryDone.h"
=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include "SrvOptIA_NA.h"
#include "SrvOptStatusCode.h"
#include "NodeClientSpecific.h"

TSrvTransMgr * TSrvTransMgr::Instance = 0;

TSrvTransMgr::TSrvTransMgr(const std::string xmlFile)
: XmlFile(xmlFile), IsDone(false)
{
    // TransMgr is certainly not done yet. We're just getting started

    // for each interface in CfgMgr, create socket (in IfaceMgr)
    SPtr<TSrvCfgIface> confIface;
    SrvCfgMgr().firstIface();
    while (confIface = SrvCfgMgr().getIface()) {
<<<<<<< HEAD
  	    if (!this->openSocket(confIface)) {
	          this->IsDone = true;
	          break;
	      }
=======
            if (!this->openSocket(confIface)) {
                  this->IsDone = true;
                  break;
              }
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

    SrvAddrMgr().setCacheSize(SrvCfgMgr().getCacheSize());
}

/*
 * opens proper (multicast or unicast) socket on interface
 */
bool TSrvTransMgr::openSocket(SPtr<TSrvCfgIface> confIface) {

    SPtr<TSrvIfaceIface> iface = (Ptr*)SrvIfaceMgr().getIfaceByID(confIface->getID());
    SPtr<TIPv6Addr> unicast = confIface->getUnicast();

    if (confIface->isRelay()) {
<<<<<<< HEAD
	while (iface->getUnderlaying()) {
	    iface = iface->getUnderlaying();
	}
	if (!iface->countSocket())
	    Log(Notice) << "Relay init: Creating socket on the underlaying interface: " << iface->getName()
			<< "/" << iface->getID() << "." << LogEnd;
    }

    if (unicast) {
	/* unicast */
	Log(Notice) << "Creating unicast (" << *unicast << ") socket on " << confIface->getName()
		    << "/" << confIface->getID() << " interface." << LogEnd;
	if (!iface->addSocket( unicast, DHCPSERVER_PORT, true, false)) {
	    Log(Crit) << "Proper socket creation failed." << LogEnd;
	    return false;
	}
=======
        while (iface->getUnderlaying()) {
            iface = iface->getUnderlaying();
        }
        if (!iface->countSocket())
            Log(Notice) << "Relay init: Creating socket on the underlaying interface: " << iface->getName()
                        << "/" << iface->getID() << "." << LogEnd;
    }

    if (unicast) {
        /* unicast */
        Log(Notice) << "Creating unicast (" << *unicast << ") socket on " << confIface->getName()
                    << "/" << confIface->getID() << " interface." << LogEnd;
        if (!iface->addSocket( unicast, DHCPSERVER_PORT, true, false)) {
            Log(Crit) << "Proper socket creation failed." << LogEnd;
            return false;
        }
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

    char srvAddr[16];
    if (!confIface->isRelay()) {
<<<<<<< HEAD
	inet_pton6(ALL_DHCP_RELAY_AGENTS_AND_SERVERS,srvAddr);
    } else {
	inet_pton6(ALL_DHCP_SERVERS,srvAddr);
=======
        inet_pton6(ALL_DHCP_RELAY_AGENTS_AND_SERVERS,srvAddr);
    } else {
        inet_pton6(ALL_DHCP_SERVERS,srvAddr);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

    SPtr<TIPv6Addr> ipAddr(new TIPv6Addr(srvAddr));
    Log(Notice) << "Creating multicast (" << ipAddr->getPlain() << ") socket on " << confIface->getName()
<<<<<<< HEAD
		<< "/" << confIface->getID() << " (" << iface->getName() << "/"
		<< iface->getID() << ") interface." << LogEnd;
    if (iface->getSocketByAddr(ipAddr)) {
	Log(Notice) << "Address " << ipAddr->getPlain() << " is already bound on the "
		    << iface->getName() << "." << LogEnd;
	return true;
    }

    if (!iface->addSocket(ipAddr, DHCPSERVER_PORT, true, false)) {
	Log(Crit) << "Proper socket creation failed." << LogEnd;
	return false;
=======
                << "/" << confIface->getID() << " (" << iface->getName() << "/"
                << iface->getID() << ") interface." << LogEnd;
    if (iface->getSocketByAddr(ipAddr)) {
        Log(Notice) << "Address " << ipAddr->getPlain() << " is already bound on the "
                    << iface->getName() << "." << LogEnd;
        return true;
    }

    if (!iface->addSocket(ipAddr, DHCPSERVER_PORT, true, false)) {
        Log(Crit) << "Proper socket creation failed." << LogEnd;
        return false;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

#if 1
    if (!iface->countLLAddress()) {
        Log(Crit) << "There is no link-local address on " << iface->getFullName() << " defined." << LogEnd;
        return false;
    }
    memcpy(srvAddr, iface->firstLLAddress(), 16);
    SPtr<TIPv6Addr> llAddr = new TIPv6Addr(iface->firstLLAddress());
    if (iface->getSocketByAddr(llAddr)) {
<<<<<<< HEAD
	Log(Notice) << "Address " << llAddr->getPlain() << " is already bound on the "
	    << iface->getName() << "." << LogEnd;
	return true;
    } else {
        Log(Notice) << "Creating link-local (" << llAddr->getPlain() << ") socket on " << iface->getFullName()
	            << " interface." << LogEnd;
	if (!iface->addSocket(llAddr, DHCPSERVER_PORT, true, false)) {
    	    Log(Crit) << "Failed to create link-local socket on " << iface->getFullName() << " interface." << LogEnd;
    	    return false;
    	}
=======
        Log(Notice) << "Address " << llAddr->getPlain() << " is already bound on the "
            << iface->getName() << "." << LogEnd;
        return true;
    } else {
        Log(Notice) << "Creating link-local (" << llAddr->getPlain() << ") socket on " << iface->getFullName()
                    << " interface." << LogEnd;
        if (!iface->addSocket(llAddr, DHCPSERVER_PORT, true, false)) {
            Log(Crit) << "Failed to create link-local socket on " << iface->getFullName() << " interface." << LogEnd;
            return false;
        }
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
#endif

    return true;
}

/**
 * Computes number of seconds when next event is expected or a job is
 * supposted to be proceeded.
 *
 * @returns Number of seconds when something should happend
 */
long TSrvTransMgr::getTimeout()
{
    unsigned long min = 0xffffffff;
    unsigned long ifaceRecheckPeriod = 10;
    unsigned long addrTimeout = 0xffffffff;
    SPtr<TSrvMsg> ptrMsg;
    MsgLst.first();
    while (ptrMsg = MsgLst.get() )
    {
        if (ptrMsg->getTimeout() < min)
            min = ptrMsg->getTimeout();
    }
    if (SrvCfgMgr().inactiveIfacesCnt() && ifaceRecheckPeriod<min)
<<<<<<< HEAD
	min = ifaceRecheckPeriod;
=======
        min = ifaceRecheckPeriod;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    addrTimeout = SrvAddrMgr().getValidTimeout();
    return min<addrTimeout?min:addrTimeout;
}

void TSrvTransMgr::relayMsg(SPtr<TSrvMsg> msg)
{
    requestMsg = msg;
<<<<<<< HEAD
    
=======

>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    if (!msg->check()) {
        // proper warnings will be printed in the check() method, if necessary.
        // Log(Warning) << "Invalid message received." << LogEnd;
        return;
    }

    // Ask NodeClietSpecific to analyse the message
    NodeClientSpecific::analyseMessage(msg);
    //SrvCfgMgr().InClientClass(msg);

    /// @todo (or at least disable by default) answer buffering mechanism
    SPtr<TSrvMsg> answ;
    Log(Debug) << MsgLst.count() << " answers buffered.";

    MsgLst.first();
    while(answ=(Ptr*)MsgLst.get())
    {
        if (answ->getTransID()==msg->getTransID()) {
            Log(Cont) << " Old reply with transID=" << hex << msg->getTransID()
<<<<<<< HEAD
		      << dec << " found. Sending old reply." << LogEnd;
	    answ->send();
=======
                      << dec << " found. Sending old reply." << LogEnd;
            answ->send();
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
            return;
        }
    }
    Log(Cont) << " Old reply for transID=" << hex << msg->getTransID()
<<<<<<< HEAD
	      << " not found. Generating new answer." << dec << LogEnd;


    switch(msg->getType()) {
    case SOLICIT_MSG: {
	SPtr<TSrvCfgIface> ptrCfgIface = SrvCfgMgr().getIfaceByID(msg->getIface());
	if (msg->getOption(OPTION_RAPID_COMMIT) && !ptrCfgIface->getRapidCommit()) {
	    Log(Info) << "SOLICIT with RAPID-COMMIT received, but RAPID-COMMIT is disabled on "
		      << ptrCfgIface->getName() << " interface." << LogEnd;
	}
	if (msg->getOption(OPTION_RAPID_COMMIT) && ptrCfgIface->getRapidCommit() )
	{
	    SPtr<TSrvMsgSolicit> nmsg = (Ptr*)msg;
	    SPtr<TSrvMsgReply> answRep = new TSrvMsgReply(nmsg);
	    //if at least one IA has in reply message status success
	    if (!answRep->isDone()) {
		SPtr<TOpt> ptrOpt;
		answRep->firstOption();
		bool found=false;
		while( (ptrOpt=answRep->getOption()) && (!found) ) {
		    if (ptrOpt->getOptType()==OPTION_IA_NA) {
			SPtr<TSrvOptIA_NA> ptrIA=(Ptr*) ptrOpt;
			SPtr<TSrvOptStatusCode> ptrStat= (Ptr*)
			    ptrIA->getOption(OPTION_STATUS_CODE);
			if(ptrStat&&(ptrStat->getCode()==STATUSCODE_SUCCESS))
			    found=true;
		    }
		}
		if(found) {
		    this->MsgLst.append((Ptr*)answRep);
		    break;
		}
		// else we didn't assign any address - this message sucks
		// it's better if advertise will be sent - maybe with better options
	    }
	}
	//if there was no Rapid Commit option in solicit message or
	//construction of reply with rapid commit wasn't successful
	//Maybe it's possible to construct appropriate advertise message
	//and assign some "not rapid" addresses to this client
	SPtr<TSrvMsgAdvertise> x = new TSrvMsgAdvertise((Ptr*)msg);
	this->MsgLst.append((Ptr*)x);
	break;
=======
              << " not found. Generating new answer." << dec << LogEnd;

    SPtr<TMsg> q, a; // question and answer

    q = (Ptr*) msg;

    switch(msg->getType()) {
    case SOLICIT_MSG: {
        SPtr<TSrvCfgIface> ptrCfgIface = SrvCfgMgr().getIfaceByID(msg->getIface());
        if (msg->getOption(OPTION_RAPID_COMMIT) && !ptrCfgIface->getRapidCommit()) {
            Log(Info) << "SOLICIT with RAPID-COMMIT received, but RAPID-COMMIT is disabled on "
                      << ptrCfgIface->getName() << " interface." << LogEnd;
        }
        if (msg->getOption(OPTION_RAPID_COMMIT) && ptrCfgIface->getRapidCommit() )
        {
            SPtr<TSrvMsgSolicit> nmsg = (Ptr*)msg;
            SPtr<TSrvMsgReply> answRep = new TSrvMsgReply(nmsg);
            //if at least one IA has in reply message status success
            if (!answRep->isDone()) {
                SPtr<TOpt> ptrOpt;
                answRep->firstOption();
                bool found=false;
                while( (ptrOpt=answRep->getOption()) && (!found) ) {
                    if (ptrOpt->getOptType()==OPTION_IA_NA) {
                        SPtr<TSrvOptIA_NA> ptrIA=(Ptr*) ptrOpt;
                        SPtr<TSrvOptStatusCode> ptrStat= (Ptr*)
                            ptrIA->getOption(OPTION_STATUS_CODE);
                        if(ptrStat&&(ptrStat->getCode()==STATUSCODE_SUCCESS))
                            found=true;
                    }
                }
                if(found) {
                    this->MsgLst.append((Ptr*)answRep);
                    a = (Ptr*)answRep;
                    break;
                }
                // else we didn't assign any address - this message sucks
                // it's better if advertise will be sent - maybe with better options
            }
        }
        //if there was no Rapid Commit option in solicit message or
        //construction of reply with rapid commit wasn't successful
        //Maybe it's possible to construct appropriate advertise message
        //and assign some "not rapid" addresses to this client
        SPtr<TSrvMsgAdvertise> x = new TSrvMsgAdvertise((Ptr*)msg);
        this->MsgLst.append((Ptr*)x);
        a = (Ptr*)x;
        break;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
    case REQUEST_MSG:
    {
        SPtr<TSrvMsgRequest> nmsg = (Ptr*)msg;
        answ = new TSrvMsgReply(nmsg);
        this->MsgLst.append((Ptr*)answ);
<<<<<<< HEAD
=======
        a = (Ptr*)answ;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
        break;
    }
    case CONFIRM_MSG:
    {
<<<<<<< HEAD
	SPtr<TSrvMsgConfirm> nmsg=(Ptr*)msg;
	answ=new TSrvMsgReply(nmsg);
	this->MsgLst.append((Ptr*)answ);
	break;
    }
    case RENEW_MSG:
    {
	SPtr<TSrvMsgRenew> nmsg=(Ptr*)msg;
	answ=new TSrvMsgReply(nmsg);
	this->MsgLst.append((Ptr*)answ);
	break;
    }
    case REBIND_MSG:
    {
	SPtr<TSrvMsgRebind> nmsg=(Ptr*)msg;
	answ=new TSrvMsgReply(nmsg);
	MsgLst.append((Ptr*)answ);
	break;
    }
    case DECLINE_MSG:
    {
	SPtr<TSrvMsgDecline> nmsg=(Ptr*)msg;
	answ=new TSrvMsgReply( nmsg);
	MsgLst.append((Ptr*)answ);
	break;
    }
    case RELEASE_MSG:
    {
	SPtr<TSrvMsgRelease> nmsg=(Ptr*)msg;
	answ=new TSrvMsgReply( nmsg);
	MsgLst.append((Ptr*)answ);
	break;
    }
    case INFORMATION_REQUEST_MSG :
    {
	SPtr<TSrvMsgInfRequest> nmsg=(Ptr*)msg;
	answ = new TSrvMsgReply( nmsg);
	MsgLst.append((Ptr*)answ);
	break;
    }
    case LEASEQUERY_MSG:
    {
        SPtr<TSrvMsgLeaseQuery> lq = (Ptr*)msg;
        processLeaseQuery(lq);
	break;
=======
        SPtr<TSrvMsgConfirm> nmsg=(Ptr*)msg;
        answ=new TSrvMsgReply(nmsg);
        this->MsgLst.append((Ptr*)answ);
        a = (Ptr*)answ;
        break;
    }
    case RENEW_MSG:
    {
        SPtr<TSrvMsgRenew> nmsg=(Ptr*)msg;
        answ=new TSrvMsgReply(nmsg);
        this->MsgLst.append((Ptr*)answ);
        a = (Ptr*)answ;
        break;
    }
    case REBIND_MSG:
    {
        SPtr<TSrvMsgRebind> nmsg=(Ptr*)msg;
        answ=new TSrvMsgReply(nmsg);
        MsgLst.append((Ptr*)answ);
        a = (Ptr*)answ;
        break;
    }
    case DECLINE_MSG:
    {
        SPtr<TSrvMsgDecline> nmsg=(Ptr*)msg;
        answ=new TSrvMsgReply( nmsg);
        MsgLst.append((Ptr*)answ);
        a = (Ptr*)answ;
        break;
    }
    case RELEASE_MSG:
    {
        SPtr<TSrvMsgRelease> nmsg=(Ptr*)msg;
        answ=new TSrvMsgReply( nmsg);
        MsgLst.append((Ptr*)answ);
        a = (Ptr*)answ;
        break;
    }
    case INFORMATION_REQUEST_MSG :
    {
        SPtr<TSrvMsgInfRequest> nmsg=(Ptr*)msg;
        answ=new TSrvMsgReply( nmsg);
        MsgLst.append((Ptr*)answ);
        a = (Ptr*)answ;
        break;
    }
    case LEASEQUERY_MSG:
    {
        int iface = msg->getIface();
        if (!SrvCfgMgr().getIfaceByID(iface) || !SrvCfgMgr().getIfaceByID(iface)->leaseQuerySupport()) {
            Log(Error) << "LQ: LeaseQuery message received on " << iface
                       << " interface, but it is not supported there." << LogEnd;
            return;
        }
        Log(Debug) << "LQ: LeaseQuery received, preparing RQ_REPLY" << LogEnd;
        SPtr<TSrvMsgLeaseQuery> lq = (Ptr*)msg;
        answ = new TSrvMsgLeaseQueryReply(lq);
        MsgLst.append( (Ptr*) answ);
        break;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
    case RECONFIGURE_MSG:
    case ADVERTISE_MSG:
    case REPLY_MSG:
    {
<<<<<<< HEAD
	Log(Warning) << "Invalid message type received: " << msg->getType()
		     << LogEnd;
	break;
=======
        Log(Warning) << "Invalid message type received: " << msg->getType()
                     << LogEnd;
        break;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
    case RELAY_FORW_MSG: // They should be decapsulated earlier
    case RELAY_REPL_MSG:
    default:
    {
<<<<<<< HEAD
	Log(Warning)<< "Message type " << msg->getType()
		    << " not supported." << LogEnd;
	break;
    }
    }

=======
        Log(Warning)<< "Message type " << msg->getType()
                    << " not supported." << LogEnd;
        break;
    }
    }

    if (a) {
        SrvIfaceMgr().notifyScripts(SrvCfgMgr().getScriptName(), q, a);
    }

>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    // save DB state regardless of action taken
    SrvAddrMgr().dump();
    SrvCfgMgr().dump();
}

void TSrvTransMgr::doDuties()
{
    int deletedCnt = 0;
    // are there any outdated addresses?
<<<<<<< HEAD
    if (!SrvAddrMgr().getValidTimeout())
        SrvAddrMgr().doDuties();
=======
    std::vector<TSrvAddrMgr::TExpiredInfo> addrLst;
    std::vector<TSrvAddrMgr::TExpiredInfo> tempAddrLst;
    std::vector<TSrvAddrMgr::TExpiredInfo> prefixLst;

    if (!SrvAddrMgr().getValidTimeout()) {
        SrvAddrMgr().doDuties(addrLst, tempAddrLst, prefixLst);
        removeExpired(addrLst, tempAddrLst, prefixLst);
    }
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    // for each message on list, let it do its duties, if timeout is reached
    SPtr<TSrvMsg> msg;
    MsgLst.first();
    while (msg=MsgLst.get())
        if ( (!msg->getTimeout()) && (!msg->isDone()) )
            msg->doDuties();

    // now delete messages marked as done
    MsgLst.first();
    while (msg = MsgLst.get() )
    {
        if (msg->isDone())
        {
            MsgLst.del();
<<<<<<< HEAD
	    deletedCnt++;
        }
    }
    if (deletedCnt) {
	Log(Debug) << deletedCnt << " message(s) were removed from cache." << LogEnd;
=======
            deletedCnt++;
        }
    }
    if (deletedCnt) {
        Log(Debug) << deletedCnt << " message(s) were removed from cache." << LogEnd;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

    // Open socket on interface which becames ready during server run
    if (SrvCfgMgr().inactiveMode())
    {
<<<<<<< HEAD
	SPtr<TSrvCfgIface> x;
	x = SrvCfgMgr().checkInactiveIfaces();
	if (x)
	    openSocket(x);
    }

}

=======
        SPtr<TSrvCfgIface> x;
        x = SrvCfgMgr().checkInactiveIfaces();
        if (x)
            openSocket(x);
    }

}


/// @brief Generates parameters for notify script based on expired lease information
///
/// @param params Notify parameters (all available info will be set here)
/// @param exp expired lease details
/// @param type type of lease (IA, TA or PD)
void TSrvTransMgr::notifyExpireInfo(TNotifyScriptParams& params, const TSrvAddrMgr::TExpiredInfo& exp,
                                    TAddrIA::TIAType type) {
    stringstream tmp;
    tmp << exp.ia->getIface();
    params.addParam("IFINDEX", tmp.str());

    SPtr<TIfaceIface> iface = SrvIfaceMgr().getIfaceByID(exp.ia->getIface());
    if (iface)
        params.addParam("IFACE", iface->getName());

    if (exp.ia->getSrvAddr())
        params.addParam("REMOTE_ADDR", exp.ia->getSrvAddr()->getPlain());
    switch (type) {
    case TAddrIA::TYPE_IA:
    case TAddrIA::TYPE_TA:
    {
        params.addAddr(exp.addr, 0, 0, "");
        break;
    }
    case TAddrIA::TYPE_PD:
    {
        params.addPrefix(exp.addr, exp.prefixLen, 0, 0);
    }
    break;
    }

    tmp.str("");
    tmp << exp.ia->getIAID();
    params.addParam("IAID", tmp.str());
    params.addParam("SRV_OPTION1", exp.client->getDUID()->getPlain()); // set client-id
}

/// @brief Removes expired leases and calls notify script
///
/// @param addrLst
/// @param tempAddrLst
/// @param prefixLst
void TSrvTransMgr::removeExpired(std::vector<TSrvAddrMgr::TExpiredInfo>& addrLst,
                                 std::vector<TSrvAddrMgr::TExpiredInfo>& tempAddrLst,
                                 std::vector<TSrvAddrMgr::TExpiredInfo>& prefixLst) {
    for (vector<TSrvAddrMgr::TExpiredInfo>::iterator addr = addrLst.begin();
         addr != addrLst.end(); ++addr) {
        // delete this address
        Log(Notice) << "Address " << *(addr->addr) << " in IA (IAID="
                    << addr->ia->getIAID() << ") in client (DUID=\""
                    << addr->client->getDUID()->getPlain()
                    << "\") has expired." << LogEnd;

        SrvAddrMgr().delClntAddr(addr->client->getDUID(),
                                 addr->ia->getIAID(),
                                 addr->addr, false);

        TNotifyScriptParams params;
        notifyExpireInfo(params, *addr, TAddrIA::TYPE_IA);
        SrvIfaceMgr().notifyScript(SrvCfgMgr().getScriptName(), "expire", params);
    }

    for (vector<TSrvAddrMgr::TExpiredInfo>::iterator addr = tempAddrLst.begin();
         addr != tempAddrLst.end(); ++addr) {
        // delete this address
        Log(Notice) << "Temp. address " << *(addr->addr) << " in IA (IAID="
                    << addr->ia->getIAID() << ") in client (DUID=\""
                    << addr->client->getDUID()->getPlain()
                    << "\") has expired." << LogEnd;

        SrvAddrMgr().delTAAddr(addr->client->getDUID(),
                               addr->ia->getIAID(),
                               addr->addr, false);

        TNotifyScriptParams params;
        notifyExpireInfo(params, *addr, TAddrIA::TYPE_TA);
        SrvIfaceMgr().notifyScript(SrvCfgMgr().getScriptName(), "expire", params);
    }

    for (vector<TSrvAddrMgr::TExpiredInfo>::iterator prefix = prefixLst.begin();
         prefix != prefixLst.end(); ++prefix) {
                // delete this prefix
        Log(Notice) << "Prefix " << prefix->addr->getPlain() << " in IAID="
                    << prefix->ia->getIAID() << " for client (DUID="
                    << prefix->client->getDUID()->getPlain()
                    << ") has expired." << LogEnd;

        SrvAddrMgr().delPrefix(prefix->client->getDUID(),
                               prefix->ia->getIAID(),
                               prefix->addr, false);

        TNotifyScriptParams params;
        notifyExpireInfo(params, *prefix, TAddrIA::TYPE_PD);
        SrvIfaceMgr().notifyScript(SrvCfgMgr().getScriptName(), "expire", params);
    }

    SrvAddrMgr().dump();
}


>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
void TSrvTransMgr::shutdown()
{
    SrvAddrMgr().dump();
    IsDone = true;
}

bool TSrvTransMgr::isDone()
{
    return IsDone;
}

char* TSrvTransMgr::getCtrlAddr() {
<<<<<<< HEAD
	return this->ctrlAddr;
}

int  TSrvTransMgr::getCtrlIface() {
	return this->ctrlIface;
=======
        return this->ctrlAddr;
}

int  TSrvTransMgr::getCtrlIface() {
        return this->ctrlIface;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}

void TSrvTransMgr::dump() {
    std::ofstream xmlDump;
    xmlDump.open(this->XmlFile.c_str());
    xmlDump << *this;
    xmlDump.close();
}

TSrvTransMgr::~TSrvTransMgr() {
    Log(Debug) << "SrvTransMgr cleanup." << LogEnd;
}

void TSrvTransMgr::instanceCreate( const std::string config )
{
  if (!Instance)
    Instance = new TSrvTransMgr(config);
  else
    Log(Crit) << "Attempt to create another Transmission Manager. One instance already present!" << LogEnd;
}

TSrvTransMgr & TSrvTransMgr::instance()
{
  if (!Instance)
    Log(Crit) << "TransMgr not created yet. Application error. Crashing in 3... 2... 1..." << LogEnd;
  return *Instance;
}

<<<<<<< HEAD
=======
/// TODO Remove this horrible workaround!
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
SPtr<TSrvMsg> TSrvTransMgr::getCurrentRequest()
{
    return requestMsg;
}

<<<<<<< HEAD

void TSrvTransMgr::processLeaseQuery(SPtr<TSrvMsgLeaseQuery> lq) {
    SPtr<TSrvMsg> asnw;
    int iface = lq->getIface();
    if (!SrvCfgMgr().getIfaceByID(iface) || !SrvCfgMgr().getIfaceByID(iface)->leaseQuerySupport()) {
        Log(Error) << "LQ: LeaseQuery message received on " << iface << " interface, but it is not supported there." << LogEnd;
        return;
    }

    if (lq->isTCP()) {
        Log(Debug) << "BLQ: LeaseQuery received over TCP, preparing answer." << LogEnd;
    } else {
        Log(Debug) << "LQ: LeaseQuery received over UDP, preparing answer." << LogEnd;
    }
    
    SPtr<TSrvOptLQ> query;
    query = (Ptr*) lq->getOption(OPTION_LQ_QUERY);
    if (!query) {
        Log(Warning) << "LQ: Unable to find LQ_QUERY option in LQ message. Not sending reply." << LogEnd;
        return;
    }

    SPtr<TSrvMsg> answ = new TSrvMsgLeaseQueryReply(lq);
    // don't add to MsgLst (no need to store cached reply)
    // LQ-REPLY was sent from TSrvMsgLeaseQueryReply constructor
}

=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
ostream & operator<<(ostream &s, TSrvTransMgr &x)
{
    s << "<TSrvTransMgr>" << endl;
    s << "<!-- SrvTransMgr dumps are not implemented yet -->" << endl;
    s << "</TSrvTransMgr>" << endl;
    return s;
}
