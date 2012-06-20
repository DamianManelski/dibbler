/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
<<<<<<< HEAD
 * $Id: IfaceMgr.h,v 1.9 2008-08-29 00:07:30 thomson Exp $
 *
=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
 */

class TIfaceMgr;
#ifndef IFACEMGR_H
#define IFACEMGR_H

#include "SmartPtr.h"
#include "Container.h"
<<<<<<< HEAD

#include "Iface.h"

=======
#include "ScriptParams.h"

#include "Iface.h"

class TMsg;
class TOpt;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

class TIfaceMgr {
  public:
    friend ostream & operator <<(ostream & strum, TIfaceMgr &x);

    TIfaceMgr(string xmlFile, bool getIfaces);

    // ---Iface related---
    void firstIface();
    SPtr<TIfaceIface> getIface();
    SPtr<TIfaceIface> getIfaceByName(string name);
    SPtr<TIfaceIface> getIfaceByID(int id);
    SPtr<TIfaceIface> getIfaceBySocket(int fd);
    int countIface();

    // ---other---
    int select(unsigned long time, char *buf, int &bufsize, SPtr<TIPv6Addr> peer);
    string printMac(char * mac, int macLen);
    void dump();
    bool isDone();

<<<<<<< HEAD
    ~TIfaceMgr();

 protected:
    string XmlFile;

    List(TIfaceIface) IfaceLst; //Interface list

=======
    void notifyScripts(std::string scriptName, SPtr<TMsg> question, SPtr<TMsg> answer);
    void notifyScripts(std::string scriptName, SPtr<TMsg> question, SPtr<TMsg> answer,
                       TNotifyScriptParams& params);
    void notifyScript(std::string scriptName, std::string action, TNotifyScriptParams& params);

    virtual ~TIfaceMgr();

 protected:
    virtual void optionToEnv(TNotifyScriptParams& params, SPtr<TOpt> opt, std::string txtPrefix );

    string XmlFile;
    List(TIfaceIface) IfaceLst; //Interface list
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    bool IsDone; 
};

#endif
