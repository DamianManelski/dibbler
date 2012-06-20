/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 licence
 *
 */

#ifndef OPTSTRING_H
#define OPTSTRING_H
#include <iostream>
#include <string>

#include "Opt.h"

class TOptString : public TOpt
{
 public:
    TOptString(int type, std::string str, TMsg* parent);
    TOptString(int type, const char *buf, unsigned short len, TMsg* parent);
    char * storeSelf( char* buf);
    int getSize();
    string getString();
    virtual bool doDuties() { return true; } // do nothing, actual code in ClntOpt* classes
<<<<<<< HEAD
 protected:
    string Str;
=======
    std::string getPlain() { return Str; }
 protected:
    std::string Str;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
};

#endif
