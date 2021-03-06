<<<<<<< HEAD
/*                                                                           
 * Dibbler - a portable DHCPv6                                               
 *                                                                           
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>                           
 *          Marek Senderski <msend@o2.pl>                                    
 *                                                                           
 * released under GNU GPL v2 only licence                                
 *                                                                           
 * $Id: SrvOptIAAddress.cpp,v 1.5 2008-08-29 00:07:36 thomson Exp $
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.4  2004-10-27 22:07:56  thomson
 * Signed/unsigned issues fixed, Lifetime option implemented, INFORMATION-REQUEST
 * message is now sent properly. Valid lifetime granted by server fixed.
 *
 * Revision 1.3  2004/10/25 20:45:54  thomson
 * Option support, parsers rewritten. ClntIfaceMgr now handles options.
 *
 * Revision 1.2  2004/06/17 23:53:55  thomson
 * Server Address Assignment rewritten.
 *
 *                                                                           
 */

#ifdef WIN32
#include <winsock2.h>
#endif
#ifdef LINUX
#include <netinet/in.h>
#endif 

=======
/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 */

#include "Portable.h"
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
#include "DHCPConst.h"
#include "Opt.h"
#include "OptIAAddress.h"
#include "SrvOptIAAddress.h"
#include "SrvOptStatusCode.h"
#include "Msg.h"
#include "Logger.h"

TSrvOptIAAddress::TSrvOptIAAddress( char * buf, int bufsize, TMsg* parent)
    :TOptIAAddress(buf,bufsize, parent)
{
    int pos=0;
<<<<<<< HEAD
    while(pos<bufsize) 
    {
        int code=buf[pos]*256+buf[pos+1]; /// @todo: use htons!
        pos+=2;
        int length=buf[pos]*256+buf[pos+1]; /// @todo: use htons!
        pos+=2;
        if ((code>0)&&(code<=24))
        {                
            if(allowOptInOpt(parent->getType(),OPTION_IAADDR,code))
            {
                SPtr<TOpt> opt;
		opt = SPtr<TOpt>();
=======
    while(pos<bufsize)
    {
        uint16_t code = readUint16(buf+pos);
        pos += sizeof(uint16_t);
        uint16_t length = readUint16(buf+pos);
        pos += sizeof(uint16_t);
        if ((code>0)&&(code<=24))
        {
            if(allowOptInOpt(parent->getType(),OPTION_IAADDR,code))
            {
                SPtr<TOpt> opt;
                opt = SPtr<TOpt>();
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
                switch (code)
                {
                case OPTION_STATUS_CODE:
                    opt =(Ptr*)SPtr<TSrvOptStatusCode> (
<<<<<<< HEAD
			new TSrvOptStatusCode(buf+pos,length,this->Parent));
                    break;
                default:
		    Log(Warning) << "Option " << code<< " not supported "
=======
                        new TSrvOptStatusCode(buf+pos,length,this->Parent));
                    break;
                default:
                    Log(Warning) << "Option " << code<< " not supported "
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
                        <<" in message (type="<< parent->getType() <<")." << LogEnd;
                    break;
                }
                if((opt)&&(opt->isValid()))
                    SubOptions.append(opt);
            } else {
<<<<<<< HEAD
		Log(Warning) << "Illegal option received, opttype=" << code 
			     << " in field options of IA_NA option" << LogEnd;
	    }
        } else {
	    Log(Warning) <<"Unknown option in option IA_NA( optType=" 
		 << code << "). Option ignored." << LogEnd;
        };
        pos+=length;
    }
}

TSrvOptIAAddress::TSrvOptIAAddress(SPtr<TIPv6Addr> addr, unsigned long pref, 
				   unsigned long valid, TMsg* parent)
=======
                Log(Warning) << "Illegal option received, opttype=" << code
                             << " in field options of IA_NA option" << LogEnd;
            }
        } else {
            Log(Warning) <<"Unknown option in option IAADDR( optType="
                 << code << "). Option ignored." << LogEnd;
        };
        pos += length;
    }
}

TSrvOptIAAddress::TSrvOptIAAddress(SPtr<TIPv6Addr> addr, unsigned long pref,
                                   unsigned long valid, TMsg* parent)
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    :TOptIAAddress(addr,pref,valid, parent) {

}

bool TSrvOptIAAddress::doDuties() {
    return true;
}
