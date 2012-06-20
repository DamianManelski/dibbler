/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
 * $Id: OptInteger.cpp,v 1.3 2007-05-01 12:03:13 thomson Exp $
 *
 */

#include <stdlib.h>
<<<<<<< HEAD
#include <iostream>
#ifdef LINUX
#include <netinet/in.h>
#endif
#ifdef WIN32
#include <winsock2.h>
#endif
=======
#include <sstream>
#include <iostream>
#include "Portable.h"
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include "OptInteger.h"
#include "DHCPConst.h"

using namespace std;

TOptInteger::TOptInteger(int type, unsigned int len, unsigned int value, TMsg* parent)
    :TOpt(type, parent) {
    this->Value = value;
    this->Valid = true;
    this->Len   = len;
}

TOptInteger::TOptInteger(int type, unsigned int len, char *&buf, int &bufsize, TMsg* parent)
    :TOpt(type, parent)
{
    if ((unsigned int)bufsize<len) {
	this->Valid = false;
	return;
    }
    this->Len   = len;
    this->Valid = true;
    switch (len) {
    case 0:
	this->Value = 0;
	break;
    case 1:
	this->Value = (unsigned char)(*buf);
	break;
    case 2:
<<<<<<< HEAD
	this->Value = ntohs(*(short int*)buf);
=======
	this->Value = readUint16(buf);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
	break;
    case 3:
	this->Value = ((long)buf[0])<<16 | ((long)buf[1])<<8 | (long)buf[2]; /* no ntoh3, eh? */
	break;
    case 4:
<<<<<<< HEAD
	this->Value = ntohl(*(int*)buf);
=======
	this->Value = readUint32(buf);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
	break;
    default:
	this->Valid = false;
	return;
    }
    buf += this->Len;
    bufsize -= this->Len;
}

char * TOptInteger::storeSelf(char* buf)
{
<<<<<<< HEAD
    *(short*)buf = htons(OptType);
    buf+=2;
    *(short*)buf = htons(this->Len);
    buf+=2;
=======
    buf = writeUint16(buf, OptType);
    buf = writeUint16(buf, this->Len);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    switch (this->Len) {
    case 0:
	break;
    case 1:
	*buf = (char)this->Value;
	break;
    case 2:
<<<<<<< HEAD
	*(short int*)buf = htons(this->Value);
=======
	buf = writeUint16(buf, this->Value);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
	break;
    case 3:
    {
	int tmp = this->Value;
	buf[0] = tmp%256; tmp = tmp/256;
	buf[1] = tmp%256; tmp = tmp/256;
	buf[2] = tmp%256; tmp = tmp/256;
	break;
    }
    case 4:
<<<<<<< HEAD
	*(int*)buf = htonl(this->Value);
=======
        buf = writeUint32(buf, this->Value);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
	break;
    default:
	/* this should never happen */
	break;
    }
    return buf+this->Len;    
}
int TOptInteger::getSize() {
    return 4 /*option header length*/ + this->Len; 
}

unsigned int TOptInteger::getValue() {
    return this->Value;
}

<<<<<<< HEAD
=======
std::string TOptInteger::getPlain() {
    stringstream tmp;
    tmp << Value;
    return tmp.str();
}

>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
bool TOptInteger::isValid() {
    return this->Valid;
}
