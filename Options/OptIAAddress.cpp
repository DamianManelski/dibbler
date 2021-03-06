/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
<<<<<<< HEAD
 * $Id: OptIAAddress.cpp,v 1.7 2007-08-26 10:26:19 thomson Exp $
 *
 */

=======
 */

//#include <netinet/in.h>
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include <string.h>
#include "Portable.h"
#include "DHCPConst.h"
#include "Opt.h"
#include "OptIAAddress.h"

<<<<<<< HEAD
TOptIAAddress::TOptIAAddress( char * &buf, int &n, TMsg* parent)
	:TOpt(OPTION_IAADDR, parent)
{
    this->ValidOpt=false;
    if (n>=24)
    {
        Addr=new TIPv6Addr(buf);
        buf+= 16; n-=16;
        this->Pref  = ntohl(*((long*)buf));
        buf+= 4;  n-=4;
        this->Valid = ntohl(*((long*)buf));
        buf+= 4;  n-=4;    
        this->ValidOpt=true;
=======
TOptIAAddress::TOptIAAddress(char * &buf, int& n, TMsg* parent)
	:TOpt(OPTION_IAADDR, parent)
{
    ValidOpt=false;
    if (n>=24)
    {
        Addr = new TIPv6Addr(buf);
        buf += 16; n -= 16;
        Pref = readUint32(buf);
        buf += sizeof(uint32_t); n -= sizeof(uint32_t);
        Valid = readUint32(buf);
        buf += sizeof(uint32_t); n -= sizeof(uint32_t);

        ValidOpt=true;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
}

TOptIAAddress::TOptIAAddress(SPtr<TIPv6Addr> addr, unsigned long pref, 
			     unsigned long valid, TMsg* parent)
    :TOpt(OPTION_IAADDR, parent) {
    if(addr)
        Addr=addr;
    else
        Addr=new TIPv6Addr();
    this->Pref = pref;
    this->Valid = valid;
}

int TOptIAAddress::getSize() {
    int mySize = 28;
    return mySize+getSubOptSize();
}

void TOptIAAddress::setPref(unsigned long pref) {
    this->Pref = pref;
}

void TOptIAAddress::setValid(unsigned long valid) {
    this->Valid = valid;
}

 char * TOptIAAddress::storeSelf( char* buf)
{
<<<<<<< HEAD
    *(uint16_t*)buf = htons(OptType);
    buf+=2;
    *(uint16_t*)buf = htons( getSize()-4 );
    buf+=2;
    memcpy(buf,Addr->getAddr(),16);
    buf+=16;
    *(uint32_t*)buf = htonl(Pref);
    buf+=4;
    *(uint32_t*)buf = htonl(Valid);
    buf+=4;
	buf=storeSubOpt(buf);
=======
    buf = writeUint16(buf, OptType);

    buf = writeUint16(buf, getSize() - 4 );

    memcpy(buf,Addr->getAddr(),16);
    buf+=16;

    buf = writeUint32(buf, Pref);

    buf = writeUint32(buf, Valid);

    buf=storeSubOpt(buf);

>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    return buf;
}

 SPtr<TIPv6Addr> TOptIAAddress::getAddr()
{
	return this->Addr;
}

unsigned long TOptIAAddress::getPref()
{
	return this->Pref;
}

unsigned long TOptIAAddress::getValid()
{
	return this->Valid;
}

bool TOptIAAddress::isValid()
{
    return this->ValidOpt;
}
