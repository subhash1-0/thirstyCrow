// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalNodes_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::ConnectivityVerifierImpl_findExternalNodes_2(ConnectivityVerifierImpl *ConnectivityVerifierImpl_this, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* local, ::java::util::ArrayList* probeList, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* probeAddresses)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_this(ConnectivityVerifierImpl_this)
    , ret(ret)
    , local(local)
    , probeList(probeList)
    , deliverResultToMe(deliverResultToMe)
    , probeAddresses(probeAddresses)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::receiveResult(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup)
{
    ConnectivityVerifierImpl_this->findExternalNodesHelper(lookup, ret, local, probeList, deliverResultToMe);
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* >(result));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::receiveException(::java::io::IOException* exception)
{
    if(npc(ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"findExternalAddress("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResultToMe))
            ->append(u").receiveException("_j)
            ->append(static_cast< ::java::lang::Object* >(exception))
            ->append(u")"_j)->toString());

    npc(deliverResultToMe)->receiveException(exception);
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalNodes_2::getClass0()
{
    return class_();
}

