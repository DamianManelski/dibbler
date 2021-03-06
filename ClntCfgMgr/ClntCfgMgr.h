/*                                                                           
 * Dibbler - a portable DHCPv6                                               
 *                                                                           
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>                           
 *          Marek Senderski <msend@o2.pl>                                    
 * changes: Krzysztof WNuk <keczi@poczta.onet.pl>                                                                         
 *          Michal Kowalczuk <michal@kowalczuk.eu>
 *
 * released under GNU GPL v2 only licence                                
 *                                                                           
 * $Id: ClntCfgMgr.h,v 1.30 2008-08-30 21:41:10 thomson Exp $
 */

class TClntCfgMgr;
class TClntCfgIface;
class ClntParser;
#ifndef CLNTCFGMGR_H
#define CLNTCFGMGR_H

#include <string>
#include "SmartPtr.h"
#include "Container.h"
#include "ClntCfgIface.h"
#include "ClntIfaceMgr.h"
#include "ClntCfgIA.h"
#include "ClntCfgPD.h"
#include "CfgMgr.h"

#ifndef MOD_DISABLE_AUTH
#include "KeyList.h"
#endif

#define ClntCfgMgr() (TClntCfgMgr::instance())

class TClntCfgMgr : public TCfgMgr
{
    friend ostream & operator<<(ostream &strum, TClntCfgMgr &x);
 private:
    TClntCfgMgr(const std::string cfgFile);

 public:
    static TClntCfgMgr & instance();
    static void instanceCreate(const std::string cfgFile);
    ~TClntCfgMgr();
    
    // --- Iface related ---
    SPtr<TClntCfgIA> getIA(long IAID);
    SPtr<TClntCfgPD> getPD(long IAID);
    SPtr<TClntCfgIface> getIface();
    SPtr<TClntCfgIface> getIface(int id);
    void firstIface();
    void addIface(SPtr<TClntCfgIface> x);
    void makeInactiveIface(int ifindex, bool inactive);
    int countIfaces();
    void dump();
    
    void setReconfigure(bool enable);
    bool getReconfigure();
    
    //IA related
    bool setIAState(int iface, int iaid, enum EState state);
    int countAddrForIA(long IAID);
    
    SPtr<TClntCfgIface> getIfaceByIAID(int iaid);
    bool isDone();

    DigestTypes getDigest();
    void setDigest(DigestTypes value);

<<<<<<< HEAD
    string getScriptsDir();
    bool getNotifyScripts();
=======
    void setScript(std::string script) { ScriptName = script; }
    string getScript() { return ScriptName; }
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    bool anonInfRequest();
    bool insistMode();
    bool inactiveMode();
    bool addInfRefreshTime();

    int inactiveIfacesCnt();
    SPtr<TClntCfgIface> checkInactiveIfaces();
    bool openSocket(SPtr<TClntCfgIface> iface);

#ifndef MOD_DISABLE_AUTH
    // Authorization
    uint32_t getAAASPI();
    List(DigestTypes) getAuthAcceptMethods();
    bool getAuthEnabled();
    SPtr<KeyList> AuthKeys;
#endif

#ifdef MOD_REMOTE_AUTOCONF
    void setRemoteAutoconf(bool enable);
    bool getRemoteAutoconf();
#endif

    bool getFQDNFlagS();
<<<<<<< HEAD
    bool getMappingPrefix();
=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    bool useConfirm();
private:
    bool setGlobalOptions(ClntParser * parser);
    bool validateConfig();
    bool validateIface(SPtr<TClntCfgIface> iface);
    bool validateIA(SPtr<TClntCfgIface> ptrIface, SPtr<TClntCfgIA> ptrIA);
    bool validateAddr(SPtr<TClntCfgIface> ptrIface, 
		      SPtr<TClntCfgIA> ptrIA,
		      SPtr<TClntCfgAddr> ptrAddr);
    bool parseConfigFile(string cfgFile);
    bool matchParsedSystemInterfaces(ClntParser *parser);

    List(TClntCfgIface) ClntCfgIfaceLst;
    List(TClntCfgIface) InactiveLst;
<<<<<<< HEAD
    string ScriptsDir;
    bool NotifyScripts;
=======
    string ScriptName;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    bool AnonInfRequest;
    bool InsistMode;
    bool InactiveMode;
    bool UseConfirm;
    bool Reconfigure;

    DigestTypes Digest;
#ifndef MOD_DISABLE_AUTH
    bool AuthEnabled;
    List(DigestTypes) AuthAcceptMethods;
    uint32_t AAASPI;
#endif

<<<<<<< HEAD
    bool RemoteAutoconf;

    bool FQDNFlagS; // S bit in the FQDN option
    bool MappingPrefix;
=======
#ifdef MOD_REMOTE_AUTOCONF
    bool RemoteAutoconf;
#endif

    bool FQDNFlagS; // S bit in the FQDN option
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d

    static TClntCfgMgr * Instance;
};

typedef bool HardcodedCfgFunc(TClntCfgMgr *cfgMgr, string params);

#endif
