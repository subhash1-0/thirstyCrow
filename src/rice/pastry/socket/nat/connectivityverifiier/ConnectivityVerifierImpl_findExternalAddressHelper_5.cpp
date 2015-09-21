// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddressHelper_5.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveResult_5_1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::ConnectivityVerifierImpl_findExternalAddressHelper_5(ConnectivityVerifierImpl *ConnectivityVerifierImpl_this, ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::java::net::InetSocketAddress* local, ::java::util::List* probeList, ::rice::p2p::util::AttachableCancellable* ret, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_this(ConnectivityVerifierImpl_this)
    , lookup(lookup)
    , local(local)
    , probeList(probeList)
    , ret(ret)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::receiveResult(::java::net::InetSocketAddress* result)
{
    if(npc(ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"findExternalAddressHelper("_j)->append(static_cast< ::java::lang::Object* >(lookup))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeList))
            ->append(u").success:"_j)
            ->append(static_cast< ::java::lang::Object* >(result))->toString());

    npc(ret)->cancel();
    npc(lookup)->destroy();
    npc(npc(ConnectivityVerifierImpl_this->environment)->getSelectorManager())->invoke(new ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveResult_5_1(this, deliverResultToMe, result));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::net::InetSocketAddress* >(result));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::receiveException(::java::io::IOException* exception)
{
    if(npc(ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"findExternalAddressHelper("_j)->append(static_cast< ::java::lang::Object* >(lookup))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeList))
            ->append(u").receiveException("_j)
            ->append(static_cast< ::java::lang::Object* >(exception))
            ->append(u")"_j)->toString());

    if(npc(probeList)->isEmpty()) {
        npc(lookup)->destroy();
        npc(npc(ConnectivityVerifierImpl_this->environment)->getSelectorManager())->invoke(new ConnectivityVerifierImpl_findExternalAddressHelper_5_receiveException_5_2(this, deliverResultToMe, exception));
        return;
    }
    ConnectivityVerifierImpl_this->findExternalAddressHelper(lookup, ret, local, probeList, deliverResultToMe);
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::receiveException(::java::lang::Exception* exception)
{ 
    receiveException(dynamic_cast< ::java::io::IOException* >(exception));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_findExternalAddressHelper_5::getClass0()
{
    return class_();
}

