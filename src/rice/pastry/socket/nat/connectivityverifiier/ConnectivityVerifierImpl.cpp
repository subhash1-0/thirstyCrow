// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/ConnectivityResult.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddressHelper_5.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_getInetSocketAddressLookup_1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalNodes_2.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalNodesHelper_3.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_findExternalAddress_4.hpp>
#include <rice/selector/SelectorManager.hpp>

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

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::ConnectivityVerifierImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::ConnectivityVerifierImpl(::rice::pastry::socket::SocketPastryNodeFactory* spnf) 
    : ConnectivityVerifierImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(spnf);
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::ctor(::rice::pastry::socket::SocketPastryNodeFactory* spnf)
{
    super::ctor();
    this->spnf = spnf;
    this->environment = npc(spnf)->getEnvironment();
    this->logger = npc(npc(environment)->getLogManager())->getLogger(ConnectivityVerifierImpl::class_(), nullptr);
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::getInetSocketAddressLookup(::java::net::InetSocketAddress* bindAddress, ::rice::Continuation* deliverResultToMe)
{
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    ::java::lang::Runnable* r = new ConnectivityVerifierImpl_getInetSocketAddressLookup_1(this, ret, bindAddress, deliverResultToMe);
    if(npc(npc(npc(spnf)->getEnvironment())->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(npc(spnf)->getEnvironment())->getSelectorManager())->invoke(r);
    }
    return ret;
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::findExternalNodes(::java::net::InetSocketAddress* local, ::java::util::Collection* probeAddresses, ::rice::Continuation* deliverResultToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"findExternalAddress("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResultToMe))
            ->append(u")"_j)->toString());

    auto const probeList = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(probeAddresses));
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(getInetSocketAddressLookup(local, new ConnectivityVerifierImpl_findExternalNodes_2(this, ret, local, probeList, deliverResultToMe, probeAddresses)));
    return ret;
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::findExternalNodesHelper(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* local, ::java::util::List* probeList, ::rice::Continuation* deliverResultToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"findExternalNodesHelper("_j)->append(static_cast< ::java::lang::Object* >(lookup))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeList))
            ->append(u")"_j)->toString());

    auto target = java_cast< ::java::net::InetSocketAddress* >(npc(probeList)->remove(npc(npc(npc(spnf)->getEnvironment())->getRandomSource())->nextInt(npc(probeList)->size())));
    npc(ret)->attach(npc(lookup)->getExternalNodes(target, new ConnectivityVerifierImpl_findExternalNodesHelper_3(this, lookup, local, probeList, ret, deliverResultToMe), nullptr));
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::findExternalAddress(::java::net::InetSocketAddress* local, ::java::util::Collection* probeAddresses, ::rice::Continuation* deliverResultToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"findExternalAddress("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResultToMe))
            ->append(u")"_j)->toString());

    auto const probeList = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(probeAddresses));
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(getInetSocketAddressLookup(local, new ConnectivityVerifierImpl_findExternalAddress_4(this, ret, local, probeList, deliverResultToMe, probeAddresses)));
    return ret;
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::findExternalAddressHelper(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::rice::p2p::util::AttachableCancellable* ret, ::java::net::InetSocketAddress* local, ::java::util::List* probeList, ::rice::Continuation* deliverResultToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"findExternalAddressHelper("_j)->append(static_cast< ::java::lang::Object* >(lookup))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeList))
            ->append(u")"_j)->toString());

    auto target = java_cast< ::java::net::InetSocketAddress* >(npc(probeList)->remove(npc(npc(npc(spnf)->getEnvironment())->getRandomSource())->nextInt(npc(probeList)->size())));
    npc(ret)->attach(npc(lookup)->getMyInetAddress(target, new ConnectivityVerifierImpl_findExternalAddressHelper_5(this, lookup, local, probeList, ret, deliverResultToMe), nullptr));
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::verifyConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::Collection* probeAddresses, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe)
{
    auto const probeList = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(probeAddresses));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u")"_j)->toString());

    for (auto ctr = int32_t(0); ctr < npc(local)->getNumAddresses(); ctr++) {
        npc(probeList)->remove(static_cast< ::java::lang::Object* >(npc(local)->getAddress(ctr)));
    }
    if(npc(probeList)->isEmpty()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(probeAddresses))
                ->append(u"). no valid addresses"_j)->toString());

        npc(deliverResultToMe)->receiveException(new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"No valid probe addresses. "_j)->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u" local:"_j)
            ->append(static_cast< ::java::lang::Object* >(local))->toString()));
        return nullptr;
    }
    auto const ret = new ::rice::p2p::util::AttachableCancellable();
    npc(ret)->attach(getInetSocketAddressLookup(npc(local)->getInnermostAddress(), new ConnectivityVerifierImpl_verifyConnectivity_6(this, ret, local, probeList, probeAddresses, deliverResultToMe)));
    return ret;
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::verifyConnectivityHelper(::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::rice::p2p::util::AttachableCancellable* ret, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::List* probeList, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivityHelper("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeList))
            ->append(u")"_j)->toString());

    auto target = java_cast< ::java::net::InetSocketAddress* >(npc(probeList)->remove(npc(npc(npc(spnf)->getEnvironment())->getRandomSource())->nextInt(npc(probeList)->size())));
    npc(ret)->attach(npc(lookup)->verifyConnectivity(local, target, deliverResultToMe, nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.connectivityverifiier.ConnectivityVerifierImpl", 69);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl::getClass0()
{
    return class_();
}

