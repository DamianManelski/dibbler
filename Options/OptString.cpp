/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
<<<<<<< HEAD
 * $Id: OptString.cpp,v 1.3 2007-08-26 10:26:19 thomson Exp $
=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
 */

#include <string.h>
#include <iostream>
#include "Portable.h"
#include "OptString.h"
#include "DHCPConst.h"

using namespace std;

TOptString::TOptString(int type, std::string str, TMsg* parent)
    :TOpt(type, parent), Str(str) {
}

TOptString::TOptString(int type, const char *buf, unsigned short bufsize, TMsg* parent)
    :TOpt(type, parent)
{
    char* str=new char[bufsize+1];
    memcpy(str,buf,bufsize);
    str[bufsize]=0;
    Str = string(str);
    delete [] str;
}

char * TOptString::storeSelf(char* buf)
{
<<<<<<< HEAD
    *(short*)buf = htons(OptType);
    buf+=2;
    *(short*)buf = htons(getSize()-4);
    buf+=2;
=======
    buf = writeUint16(buf, OptType);
    buf = writeUint16(buf, getSize()-4);
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    memcpy(buf,Str.c_str(),Str.length());
    buf[Str.length()]=0;  // null-terminated
    return buf+this->Str.length()+1;

    *buf = (char)Str.length(); // length of a string (with first byte)
    buf++;
    memcpy(buf,this->Str.c_str(),this->Str.length());
    buf += this->Str.length();
    *buf=0; // add final 0.
    return buf+1;
}

int TOptString::getSize() {
    return (int)(Str.length()+6); // 4-normal header + 1 (strlen) + 1 (final 0)
}

string TOptString::getString() {
    return Str;
}
