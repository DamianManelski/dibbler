/*
 * Dibbler - a portable DHCPv6
 *
 * authors: Tomasz Mrugalski <thomson@klub.com.pl>
 *          Marek Senderski <msend@o2.pl>
 *
 * released under GNU GPL v2 only licence
 *
 * $Id: SocketIPv6.cpp,v 1.20 2008-08-29 00:07:30 thomson Exp $
 *
 */


#include <string.h>
#include <string>
#include "SocketIPv6.h"
#include "Portable.h"
#include "DHCPConst.h"
#include "Logger.h"

/**
 * static elements of TIfaceSocket class
 */ 
int TIfaceSocket::Count=0;
int TIfaceSocket::MaxFD=0;

/**
 * creates socket bound to specific address on this interface
 * @param iface   interface name
 * @param ifindex interface index
 * @param port    UDP port, to which socket will be bound
 * @param addr    IPv6 address 
 * @param ifaceonly force interface-only flag in setsockopt()?
 * @param reuse   should socket be bound with reuse flag in setsockopt()?
 */
TIfaceSocket::TIfaceSocket(char * iface, int ifindex, int port,
<<<<<<< HEAD
                   SPtr<TIPv6Addr> addr, bool ifaceonly, bool reuse) {
    if (this->Count==0) {
        FD_ZERO(getFDS());
=======
				   SPtr<TIPv6Addr> addr, bool ifaceonly, bool reuse) { 
    if (this->Count==0) {
	FD_ZERO(getFDS());
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }
    this->Count++;
    this->createSocket(iface, ifindex, addr, port, ifaceonly, reuse);
}

<<<<<<< HEAD

=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
enum EState TIfaceSocket::getStatus() {
    return this->Status;
}


/**
 * creates socket bound to this interface
 * @param iface      interface name
 * @param ifaceid    interface index
 * @param port       UDP port, to which socket will be bound
 * @param ifaceonly  force interface-only flag in setsockopt()?
 * @param reuse      should socket be bound with reuse flag in setsockopt()?
 */
TIfaceSocket::TIfaceSocket(char * iface,int ifaceid, int port,bool ifaceonly, bool reuse) {
    if (this->Count==0) {
<<<<<<< HEAD
        FD_ZERO(getFDS());
=======
	FD_ZERO(getFDS());
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

    // bind it to any address (::)
    char anyaddr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    SPtr<TIPv6Addr> smartAny (new TIPv6Addr(anyaddr));   
    this->createSocket(iface, ifaceid, smartAny, port, ifaceonly, reuse);
    this->Count++;
}

<<<<<<< HEAD

/**
 * creates TCP socket bound to specific address on this interface
 * @param iface   interface name
 * @param ifaceid interface index
 * @param port    TCP port, to which socket will be bound
 * @param addr    IPv6 address
 * @param ifaceonly force interface-only flag in setsockopt()?
 * @param socketType is TCP protocol socket
 */
TIfaceSocket::TIfaceSocket(char *iface, int ifaceid, int port, SPtr<TIPv6Addr> addr, bool ifaceonly, bool reuse, int socketType, int isMulticast)
{
    if (this->Count==0) {
        FD_ZERO(getFDS());
    }
    this->Count++;
    this->createTcpSocket(iface, ifaceid, addr, port, ifaceonly, reuse,socketType,isMulticast);
}


=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
/**
 * creates socket on this interface.
 * @param iface - interface name
 * @param ifaceid - interface ID
 * @param port - port, to which socket will be bound
 * @param addr - address 
 * @param ifaceonly - force interface-only flag in setsockopt()
 * @param reuse should socket be bound with reuse flag in setsockopt()?
 *
 * @return negative error code (or 0 if everything is ok)
 */
<<<<<<< HEAD
int TIfaceSocket::createSocket(char * iface, int ifaceid, SPtr<TIPv6Addr> addr,  int port, bool ifaceonly, bool reuse) {

=======
int TIfaceSocket::createSocket(char * iface, int ifaceid, SPtr<TIPv6Addr> addr, 
				   int port, bool ifaceonly, bool reuse) {
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    int sock;

    // store info about this socket 
    strncpy(this->Iface,iface,MAX_IFNAME_LENGTH);
    this->IfaceID = ifaceid;
    this->Port = port;
    this->IfaceOnly = ifaceonly;
    this->Status = STATE_NOTCONFIGURED;
    this->Addr   = addr;
    
    // is this address multicast? So the socket is.
    if ((addr->getAddr())[0]==(char)0xff) 
        this->Multicast = true;
    else
        this->Multicast = false;

    // create socket
    sock = sock_add(this->Iface, this->IfaceID, addr->getPlain(), 
		    this->Port, ifaceonly?1:0, reuse?1:0);

    if (sock<0) {
<<<<<<< HEAD
        printError(sock, iface, ifaceid, addr, port);
        this->Status = STATE_FAILED;
        return -3;
=======
	printError(sock, iface, ifaceid, addr, port);
	this->Status = STATE_FAILED;
	return -3;
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
    }

    this->FD = sock;
    this->Status = STATE_CONFIGURED;

    // add FileDescriptior fd_set using FD_SET macro
    FD_SET(this->FD,this->getFDS());
    if (FD>MaxFD)
        MaxFD = FD;

    return 0;
}

<<<<<<< HEAD
int TIfaceSocket::createTcpSocket(char *iface, int ifaceid, SPtr<TIPv6Addr> addr, int port, bool ifaceonly, bool reuse, bool sockType, int isMulticast)
{
    int sock;

    // store info about this socket
    strncpy(this->Iface,iface,MAX_IFNAME_LENGTH);
    this->IfaceID = ifaceid;
    this->Port = port;
    this->IfaceOnly = ifaceonly;
    this->Status = STATE_NOTCONFIGURED;
    this->Addr   = addr;
    this->SocketType = sockType;

    // is this address multicast? So the socket is.
    if (isMulticast) {
        if ((addr->getAddr())[0]==(char)0xff)
            this->Multicast = true;
        else
            this->Multicast = false;
    }

    if(this->SocketType){
        // create socket
        sock = sock_add_tcp(this->Iface, this->IfaceID, addr->getPlain(),
                this->Port, ifaceonly?1:0, reuse?1:0,this->SocketType);

        if (sock<0) {
            printError(sock, iface, ifaceid, addr, port);
            this->Status = STATE_FAILED;
            return -3;
        }
    } else {
        //printError(len, this->Iface, this->IfaceID, addr, this->Port);
        Log(Error) << "Unable to create TCP socket. Is IPv6 protocol supported in your system?"
    }

    this->FD = sock;
    this->Status = STATE_CONFIGURED;

    // add FileDescriptior fd_set using FD_SET macro
    FD_SET(this->FD,this->getFDS());
    if (FD>MaxFD)
        MaxFD = FD;
    return 0;
}

=======
>>>>>>> c851e389da43c1649eff5a1b7971999200e5d44d
/**
 * sends data through socket
 * @param buf - buffer to send
 * @param len - number of bytes to send
 * @param addr - where send this data
 * @param port - to which port
 * returns number of bytes sent or -1 if something went wrong
 */
int TIfaceSocket::send(char * buf,int len, SPtr<TIPv6Addr> addr,int port) {

    int result;
    
    //extern "C" int sock_send(int fd, char * addr, char * buf, int buflen, int port, int ifaceID);

    result = sock_send(this->FD, addr->getPlain(), buf, len, port, this->IfaceID);

    if (result<0) {
	printError(result, this->Iface, this->IfaceID, addr, port);
	return -1;
    }

    /* send success full */
    return result;
}

/**
 * receives data from socket
 * @param buf - received data are stored here
 * @param addr - will contain info about sender
 */
int TIfaceSocket::recv(char * buf, SPtr<TIPv6Addr> addr) {
    char myPlainAddr[48];
    char peerPlainAddr[48];

    // maximum DHCPv6 packet size
    int len=1500;

    len = sock_recv(this->FD, myPlainAddr, peerPlainAddr, buf, len);

    if ( len  < 0 ) {
	printError(len, this->Iface, this->IfaceID, addr, this->Port);
        return -1;
    }

    // convert to packed form (plain->16-byte)
    char packedAddr[16];
    inet_pton6(peerPlainAddr,packedAddr);
    addr->setAddr(packedAddr);
    return len;
}

/**
 * returns FDS - FileDescriptorSet 
 * it's some really weird POSIX macro. It uses FD_SET, FD_ZERO and FD_CLR macros
 * defined somewhere in system headers
 */
fd_set * TIfaceSocket::getFDS() {
    static fd_set FDS;
    return &FDS;
}

/**
 * returns FileDescritor
 */
int TIfaceSocket::getFD() {
    return this->FD;
}

/**
 * returns interface ID
 */
int TIfaceSocket::getIfaceID() {
    return this->IfaceID;
}

/**
 * returns port
 */
int TIfaceSocket::getPort() {
    return this->Port;
}

/**
 * returns address
 */
SPtr<TIPv6Addr> TIfaceSocket::getAddr() {
    return this->Addr;
}

/**
 * closes socket, and removes its number from FDS
 */
TIfaceSocket::~TIfaceSocket() {
    if (Status!=STATE_CONFIGURED) 
	return;

    //execute low-level function
    sock_del(this->FD);

    FD_CLR(this->FD,getFDS());

    this->Count--;
}

void TIfaceSocket::printError(int error, char * iface, int ifaceid, SPtr<TIPv6Addr> addr, int port)
{
    // detect errors
    switch (error) {
    case LOWLEVEL_ERROR_UNSPEC:
        Log(Error) << "Unable to create socket. Is IPv6 protocol supported in your system?" 
		   << LogEnd;
        break;
    case LOWLEVEL_ERROR_BIND_IFACE:
        Log(Error) << "Unable to bind socket to interface " << this->Iface << "/" 
		   << this->IfaceID << "." << LogEnd;
        break;
    case LOWLEVEL_ERROR_BIND_FAILED:
        Log(Error) << "Unable to bind socket (iface=" << iface << "/" << ifaceid 
		   << ", addr=" << addr->getPlain() << ", port=" 
		   << this->Port << ")." << LogEnd;
        break;
    case LOWLEVEL_ERROR_MCAST_HOPS:
        Log(Error) << "Unable to set multicast hops. (iface= " << iface << "/" << ifaceid  
		   << ", addr=" << *this->Addr << ", port=" << this->Port << ")" << LogEnd;
        break;
    case LOWLEVEL_ERROR_MCAST_MEMBERSHIP:
        Log(Error) << "Unable to perform multicast group operation." << LogEnd;
        break;
    case LOWLEVEL_ERROR_GETADDRINFO:
        Log(Error) << "getaddrinfo() failed. Is IPv6 protocol supported by your system?" << LogEnd;
        break;
    case LOWLEVEL_ERROR_SOCK_OPTS:
        Log(Error) << "Unable to set up socket options." << LogEnd;
        break;
    case LOWLEVEL_ERROR_REUSE_FAILED:
        Log(Error) << "Unable to set up socket option SO_REUSEADDR" << LogEnd;
        break;
    default:
        break;
    }
    if (error_message()) {
	Log(Error) << "Low-level layer error message: " << error_message() << LogEnd;
    }
}

// --------------------------------------------------------------------
// --- operators ------------------------------------------------------
// --------------------------------------------------------------------
/*
 * flush this data in XML format
 */
ostream & operator <<(ostream & strum, TIfaceSocket &x)
{
    strum << dec 
	  << "<IfaceSocket"
	  << " fd=\"" << x.getFD() << "\""
	  << " port=\"" << x.getPort() << "\""
	  << " iface=\"" << x.Iface << "\""
	  << " addr=\"" << *x.Addr << "\"";
    if (x.Multicast) 
	strum << " multicast=\"true\"";
    if (x.IfaceOnly)
	strum << " ifaceonly=\"true\"";
    strum << " status=\"" << StateToString(x.Status)
	  << "\"" << " />" << endl;
    return strum;
}
