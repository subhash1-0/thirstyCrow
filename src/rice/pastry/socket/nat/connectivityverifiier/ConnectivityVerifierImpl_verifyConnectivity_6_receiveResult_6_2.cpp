// Generated from /pastry-2.1/src/rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.java
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3.hpp>
#include <rice/pastry/socket/nat/connectivityverifiier/ConnectivityVerifierImpl.hpp>
#include <rice/selector/SelectorManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2(ConnectivityVerifierImpl_verifyConnectivity_6 *ConnectivityVerifierImpl_verifyConnectivity_6_this, ::rice::p2p::util::AttachableCancellable* ret, ::org::mpisws::p2p::transport::networkinfo::InetSocketAddressLookup* lookup, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::util::Collection* probeAddresses, ::org::mpisws::p2p::transport::networkinfo::ConnectivityResult* deliverResultToMe, ::java::util::ArrayList* probeList)
    : super(*static_cast< ::default_init_tag* >(0))
    , ConnectivityVerifierImpl_verifyConnectivity_6_this(ConnectivityVerifierImpl_verifyConnectivity_6_this)
    , ret(ret)
    , lookup(lookup)
    , local(local)
    , probeAddresses(probeAddresses)
    , deliverResultToMe(deliverResultToMe)
    , probeList(probeList)
{
    clinit();
    init();
    ctor();
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::init()
{
    udpSuccess_ = false;
    tcpSuccess_ = false;
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::udpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options)
{
    udpSuccess_ = true;
    if(tcpSuccess_) {
        npc(ret)->cancel();
        npc(lookup)->destroy();
    }
    if(npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u"). udpSuccess("_j)
            ->append(static_cast< ::java::lang::Object* >(from))
            ->append(u")"_j)->toString());

    npc(npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->environment)->getSelectorManager())->invoke(new ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_udpSuccess_6_2_1(this, deliverResultToMe, from, options));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::tcpSuccess(::java::net::InetSocketAddress* from, ::java::util::Map* options)
{
    tcpSuccess_ = true;
    if(udpSuccess_) {
        npc(ret)->cancel();
        npc(lookup)->destroy();
    }
    if(npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(probeAddresses))
            ->append(u"). tcpSuccess("_j)
            ->append(static_cast< ::java::lang::Object* >(from))
            ->append(u")"_j)->toString());

    npc(npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->environment)->getSelectorManager())->invoke(new ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_tcpSuccess_6_2_2(this, deliverResultToMe, from, options));
}

void rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::receiveException(::java::lang::Exception* exception)
{
    if(npc(probeList)->isEmpty()) {
        npc(lookup)->destroy();
        if(npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"verifyConnectivity("_j)->append(static_cast< ::java::lang::Object* >(local))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(probeAddresses))
                ->append(u"). failure no more addresses "_j)
                ->append(static_cast< ::java::lang::Object* >(exception))->toString());

        npc(npc(ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->environment)->getSelectorManager())->invoke(new ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2_receiveException_6_2_3(this, deliverResultToMe, exception));
        return;
    }
    ConnectivityVerifierImpl_verifyConnectivity_6_this->ConnectivityVerifierImpl_this->verifyConnectivityHelper(lookup, ret, local, probeList, deliverResultToMe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::connectivityverifiier::ConnectivityVerifierImpl_verifyConnectivity_6_receiveResult_6_2::getClass0()
{
    return class_();
}

