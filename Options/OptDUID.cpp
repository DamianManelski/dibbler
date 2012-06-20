/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
 */

#include <stdlib.h>
<<<<<<< HEAD

#ifdef WIN32
#include <winsock2.h>
#endif
#ifdef LINUX
#include <netinet/in.h>
#endif 

=======
#include "Portable.h"
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include "DHCPConst.h"
#include "OptDUID.h"

TOptDUID::TOptDUID(int type, SPtr<TDUID> duid, TMsg* parent)
    :TOpt(type, parent)
{
    DUID=duid;
}

 int TOptDUID::getSize()
{
    if (this->DUID)
	return this->DUID->getLen()+4;
    return 4;
}

 char * TOptDUID::storeSelf( char* buf)
{
<<<<<<< HEAD
    *(uint16_t*)buf = htons(OptType);
    buf+=2;
    *(uint16_t*)buf = htons(DUID->getLen());
    buf+=2;
=======
    buf = writeUint16(buf, OptType);
    buf = writeUint16(buf, DUID->getLen());
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    return this->DUID->storeSelf(buf);
}

TOptDUID::TOptDUID(int type, const char* buf, int bufsize, TMsg* parent)
    :TOpt(type, parent)
{
    this->DUID = new TDUID(buf,bufsize);
    // buf+=DUID->getLen(); 
    // bufsize-=DUID->getLen();
}

SPtr<TDUID> TOptDUID::getDUID()
{
	return DUID;
}

bool TOptDUID::isValid()
{
    if (this->getDUID()->getLen()>2) 
        return true;
    return false;
}
