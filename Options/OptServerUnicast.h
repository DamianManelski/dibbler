/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
 * $Id: OptServerUnicast.h,v 1.2 2004-09-05 15:27:49 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 *
 */

#ifndef OPTSERVERUNICAST_H
#define OPTSERVERUNICAST_H

#include "Opt.h"
#include "DHCPConst.h"
#include "SmartPtr.h"
#include "IPv6Addr.h"

class TOptServerUnicast : public TOpt
{
public:
    TOptServerUnicast( char * &buf,  int &n, TMsg* parent);
    TOptServerUnicast(SmartPtr<TIPv6Addr> addr, TMsg * parent);
    int getSize();
    char * storeSelf( char* buf);
    SmartPtr<TIPv6Addr> getAddr();
private:
    SmartPtr<TIPv6Addr> Addr;
};

#endif
