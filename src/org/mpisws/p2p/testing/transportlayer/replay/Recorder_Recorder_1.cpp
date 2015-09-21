// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_1_getBootstrapper_1_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>

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

org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::Recorder_Recorder_1(Recorder *Recorder_this, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , Recorder_this(Recorder_this)
{
    clinit();
    ctor(nf, startPort, env);
}

org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::Recorder_Recorder_1(Recorder *Recorder_this, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , Recorder_this(Recorder_this)
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

rice::pastry::NodeHandle* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf)
{
    auto ret = java_cast< ::rice::pastry::socket::SocketNodeHandle* >(super::getLocalHandle(pn, nhf));
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getLocalHandle():"_j)->append(npc(ret)->toStringFull())->toString());

    return ret;
}

rice::environment::random::RandomSource* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::cloneRandomSource(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman)
{
    auto randSeed = npc(npc(rootEnvironment)->getRandomSource())->nextLong();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"RandSeed for "_j)->append(static_cast< ::java::lang::Object* >(nodeId))
            ->append(u" "_j)
            ->append(randSeed)->toString());

    npc(Recorder_this->storedRandSeed)->put(nodeId, ::java::lang::Long::valueOf(randSeed));
    return new ::rice::environment::random::simple::SimpleRandomSource(randSeed, lman);
}

org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    auto ret = new ::org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer(java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(super::getWireTransportLayer(innermostAddress, pn)), ::java::lang::StringBuilder().append(u"0x"_j)->append(npc(npc(pn)->getNodeId())->toStringBare())->toString(), new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer(), npc(pn)->getEnvironment());
    npc(Recorder_this->recorders)->put(pn, ret);
    return ret;
}

rice::pastry::boot::Bootstrapper* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns)
{
    auto const internal = java_cast< ::rice::pastry::boot::Bootstrapper* >(super::getBootstrapper(pn, tl, handleFactory, pns));
    ::rice::pastry::boot::Bootstrapper* ret = new Recorder_Recorder_1_getBootstrapper_1_1(this, pn, internal);
    return ret;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1::getClass0()
{
    return class_();
}

