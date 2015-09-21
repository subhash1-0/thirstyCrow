// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeApp.java
#include <rice/pastry/socket/nat/probe/ProbeApp.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <org/mpisws/p2p/transport/multiaddress/AddressStrategy.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/networkinfo/Prober.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/socket/nat/probe/ProbeApp_ProbeApp_1.hpp>
#include <rice/pastry/socket/nat/probe/ProbeApp_requestProbe_2.hpp>
#include <rice/pastry/socket/nat/probe/ProbeRequestMessage.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketNodeHandle.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>

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

rice::pastry::socket::nat::probe::ProbeApp::ProbeApp(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::socket::nat::probe::ProbeApp::ProbeApp(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::networkinfo::Prober* prober, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy) 
    : ProbeApp(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,prober,addressStrategy);
}

void rice::pastry::socket::nat::probe::ProbeApp::ctor(::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::networkinfo::Prober* prober, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy)
{
    super::ctor(pn, nullptr, int32_t(0), nullptr);
    this->prober = prober;
    this->addressStrategy = addressStrategy;
    setDeserializer(new ProbeApp_ProbeApp_1(this));
}

void rice::pastry::socket::nat::probe::ProbeApp::messageForAppl(::rice::pastry::messaging::Message* msg)
{
    auto prm = java_cast< ProbeRequestMessage* >(msg);
    handleProbeRequestMessage(prm);
}

void rice::pastry::socket::nat::probe::ProbeApp::handleProbeRequestMessage(ProbeRequestMessage* prm)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"handleProbeRequestMessage("_j)->append(static_cast< ::java::lang::Object* >(prm))
            ->append(u")"_j)->toString());

    npc(prober)->probe(npc(addressStrategy)->getAddress(npc((java_cast< ::rice::pastry::socket::SocketNodeHandle* >(npc(thePastryNode)->getLocalHandle())))->getAddress(), npc(prm)->getProbeRequester()), npc(prm)->getUID(), nullptr, nullptr);
}

rice::p2p::commonapi::Cancellable* rice::pastry::socket::nat::probe::ProbeApp::requestProbe(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* addr, int64_t uid, ::rice::Continuation* deliverResultToMe)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"requestProbe("_j)->append(static_cast< ::java::lang::Object* >(addr))
            ->append(u","_j)
            ->append(uid)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverResultToMe))
            ->append(u")"_j)->toString());

    auto valid = new ::java::util::ArrayList();
    auto candidates = npc(npc(thePastryNode)->getLeafSet())->iterator();
    while (npc(candidates)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::socket::SocketNodeHandle* >(java_cast< ::rice::pastry::NodeHandle* >(npc(candidates)->next()));
        if(!npc(nh)->equals(static_cast< ::java::lang::Object* >(npc(thePastryNode)->getLocalHandle()))) {
            if(npc(npc(addressStrategy)->getAddress(npc(nh)->getAddress(), addr))->equals(static_cast< ::java::lang::Object* >(npc(addr)->getOutermostAddress()))) {
                npc(valid)->add(static_cast< ::java::lang::Object* >(nh));
            }
        }
    }
    if(npc(valid)->isEmpty()) {
        npc(deliverResultToMe)->receiveResult(::java::lang::Boolean::valueOf(false));
        return nullptr;
    }
    auto handle = java_cast< ::rice::pastry::NodeHandle* >(npc(valid)->get(npc(npc(npc(thePastryNode)->getEnvironment())->getRandomSource())->nextInt(npc(valid)->size())));
    auto prm = new ProbeRequestMessage(addr, uid, getAddress());
    return npc(thePastryNode)->send(handle, prm, new ProbeApp_requestProbe_2(this, deliverResultToMe), nullptr);
}

java::util::Collection* rice::pastry::socket::nat::probe::ProbeApp::getExternalAddresses()
{
    auto ret = new ::java::util::ArrayList();
    auto i = npc(npc(thePastryNode)->getLeafSet())->iterator();
    while (npc(i)->hasNext()) {
        auto nh = java_cast< ::rice::pastry::NodeHandle* >(npc(i)->next());
        auto rsnh = java_cast< ::rice::pastry::socket::nat::rendezvous::RendezvousSocketNodeHandle* >(nh);
        if(npc(rsnh)->canContactDirect()) {
            npc(ret)->add(static_cast< ::java::lang::Object* >(npc(rsnh)->getInetSocketAddress()));
        }
    }
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::socket::nat::probe::ProbeApp::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.socket.nat.probe.ProbeApp", 37);
    return c;
}

java::lang::Class* rice::pastry::socket::nat::probe::ProbeApp::getClass0()
{
    return class_();
}

