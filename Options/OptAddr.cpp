/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
<<<<<<< HEAD
 * $Id: OptAddr.cpp,v 1.1 2004-10-26 22:36:57 thomson Exp $
 *
 */

#ifdef WIN32
#include <winsock2.h>
#endif
#ifdef LINUX
#include <netinet/in.h>
#endif
#include "OptAddr.h"
#include "Logger.h"

TOptAddr::TOptAddr(int type, const char * buf, unsigned short len, TMsg* parent)
    :TOpt(type, parent) {
    if (len!=16) {
=======
 */

#include "Portable.h"
#include "OptAddr.h"
#include "Logger.h"
#include "OptRtPrefix.h"
#include "OptGeneric.h"

TOptAddr::TOptAddr(int type, const char * buf, unsigned short len, TMsg* parent)
    :TOpt(type, parent) {
    if (len<16) {
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
	Valid = false;
	Log(Warning) << "Malformed option (code=" << type << ", length=" << len
		     << "), expected length is 16." << LogEnd;
	return;
    }
    Addr = new TIPv6Addr(buf, false); // plain = false
<<<<<<< HEAD
=======
    buf += 16;
    len -= 16;

    Valid = parseOptions(SubOptions, buf, len, parent);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}

TOptAddr::TOptAddr(int type, SPtr<TIPv6Addr> addr, TMsg* parent)
    :TOpt(type, parent) {
    this->Addr = addr;
}

int TOptAddr::getSize() {
<<<<<<< HEAD
    return 20;
=======
    // 20 - size of this option
    return 20 + getSubOptSize();
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}

SPtr<TIPv6Addr> TOptAddr::getAddr() {
    return Addr;
}

<<<<<<< HEAD
char * TOptAddr::storeSelf(char* buf) {
    *(uint16_t*)buf = htons(OptType);
    buf+=2;
    *(uint16_t*)buf = htons( getSize()-4 );
    buf+=2;
    this->Addr->storeSelf(buf);
    return buf;
=======
std::string TOptAddr::getPlain() {
    return Addr->getPlain();
}

char * TOptAddr::storeSelf(char* buf) {
    // store generic header
    buf = writeUint16( buf, OptType );
    buf = writeUint16( buf, getSize() - 4 );

    // store address
    buf = Addr->storeSelf(buf);

    // store sub-options (if three are any)
    return storeSubOpt(buf);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
}
