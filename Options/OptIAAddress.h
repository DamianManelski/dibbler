/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 or later licence
 *
 * $Id: OptIAAddress.h,v 1.4 2004-10-27 22:07:56 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.3  2004/09/07 22:02:33  thomson
 * pref/valid/IAID is not unsigned, RAPID-COMMIT now works ok.
 *
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
    TOptIAAddress( char * &addr, int &n, TMsg* parent);
    TOptIAAddress( SmartPtr<TIPv6Addr> addr, unsigned long pref, unsigned long valid, TMsg* parent);
    int getSize();
    
    char * storeSelf( char* buf);
    SmartPtr<TIPv6Addr> getAddr();
    unsigned long getPref();
    unsigned long getValid();
    void setPref(unsigned long pref);
    void setValid(unsigned long valid);
    bool isValid();    

 private:
    SmartPtr<TIPv6Addr> Addr;
    unsigned long Valid;
    unsigned long Pref;
    bool ValidOpt;
};

#endif
