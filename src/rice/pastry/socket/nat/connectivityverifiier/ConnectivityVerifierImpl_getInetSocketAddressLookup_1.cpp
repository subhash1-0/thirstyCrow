// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_getInetSocketAddressLookup_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_getInetSocketAddressLookup_1::ConnectivityVerifierImpl_getInetSocketAddressLookup_1(ConnectivityVerifierImpl *ConnectivityVerifierImpl_this, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_this(ConnectivityVerifierImpl_this)
    , ret(ret)
    , bindAddress(bindAddress)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_getInetSocketAddressLookup_1::run()
{
    if(npc(ret)->isCancelled())
        return;

    auto pn = new ::rice::pastry::PastryNode(::rice::pastry::Id::build(), npc(ConnectivityVerifierImpl_this->spnf)->getEnvironment());
    try {
        auto lookup = java_cast< ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* >(npc(ConnectivityVerifierImpl_this->spnf)->getBottomLayers(pn, new ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress(bindAddress)));
        npc(deliverResultToMe)->receiveResult(lookup);
    } catch (::java::io::IOException* ioe) {
        npc(deliverResultToMe)->receiveException(ioe);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_getInetSocketAddressLookup_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_getInetSocketAddressLookup_1::getClass0()
{
    return class_();
}

