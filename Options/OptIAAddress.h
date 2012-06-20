/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
<<<<<<< HEAD
 * $Id: OptIAAddress.h,v 1.5 2008-08-29 00:07:30 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.4  2004-10-27 22:07:56  thomson
 * Signed/unsigned issues fixed, Lifetime option implemented, INFORMATION-REQUEST
 * message is now sent properly. Valid lifetime granted by server fixed.
 *
 * Revision 1.3  2004/09/07 22:02:33  thomson
 * pref/valid/IAID is not unsigned, RAPID-COMMIT now works ok.
 *
=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
 */

#ifndef OPTIAADDRESS_H
#define OPTIAADDRESS_H

#include "SmartPtr.h"
#include "Container.h"
#include "Opt.h"
#include "IPv6Addr.h"

class TOptIAAddress : public TOpt
{
  public:
<<<<<<< HEAD
    TOptIAAddress( char * &addr, int &n, TMsg* parent);
=======
    TOptIAAddress(char* &addr, int& n, TMsg* parent);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    TOptIAAddress( SPtr<TIPv6Addr> addr, unsigned long pref, unsigned long valid, TMsg* parent);
    int getSize();
    
    char * storeSelf( char* buf);
    SPtr<TIPv6Addr> getAddr();
    unsigned long getPref();
    unsigned long getValid();
    void setPref(unsigned long pref);
    void setValid(unsigned long valid);
<<<<<<< HEAD
    bool isValid();    

=======
    bool isValid();

    virtual bool doDuties() { return true; } // does nothing on its own
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
 private:
    SPtr<TIPv6Addr> Addr;
    unsigned long Valid;
    unsigned long Pref;
    bool ValidOpt;
};

#endif
