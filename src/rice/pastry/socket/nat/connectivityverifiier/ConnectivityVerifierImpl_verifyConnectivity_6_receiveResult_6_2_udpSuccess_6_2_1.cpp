// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1(ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2 *ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_this, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe, ::java::net::InetSocketAddress* from, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_this(ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_this)
    , deliverResultToMe(deliverResultToMe)
    , from(from)
    , options(options)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1::run()
{
    npc(deliverResultToMe)->udpSuccess(from, options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1::getClass0()
{
    return class_();
}

