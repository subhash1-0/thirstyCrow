// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1(ConnectivityVerifierImpl_verifyConnectivity_6 *ConnectivityVerifierImpl_verifyConnectivity_6_this, ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_verifyConnectivity_6_this(ConnectivityVerifierImpl_verifyConnectivity_6_this)
    , lookup(lookup)
{
    clinit();
    ctor();
}

bool rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1::cancel()
{
    npc(lookup)->destroy();
    return true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1::getClass0()
{
    return class_();
}

