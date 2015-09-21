// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::ConnectivityVerifierImpl_verifyConnectivity_6(ConnectivityVerifierImpl *ConnectivityVerifierImpl_this, ::rice::p2p::util::AttachableCancellable* ret, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::ArrayList* probeList, ::java::util::Collection* probeAddresses, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_this(ConnectivityVerifierImpl_this)
    , ret(ret)
    , local(local)
    , probeList(probeList)
    , probeAddresses(probeAddresses)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::receiveResult(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup)
{
    npc(ret)->attach(new ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_1(this, lookup));
    ConnectivityVerifierImpl_this->verifyConnectivityHelper(lookup, ret, local, probeList, new ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2(this, ret, lookup, local, probeAddresses, deliverResultToMe, probeList));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* >(result));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::receiveException(::java::io::IOException* exception)
{
    if(npc(ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u"). couldn't get tl "_j)
            ->append(static_cast< ::java::lang::Object* >(exception))->toString());

    npc(deliverResultToMe)->receiveException(exception);
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6::getClass0()
{
    return class_();
}

