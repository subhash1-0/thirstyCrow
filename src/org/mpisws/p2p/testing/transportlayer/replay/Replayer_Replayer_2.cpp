// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Replayer.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer_Replayer_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEvents.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/stub/NullHashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/EventCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::Replayer_Replayer_2(Replayer *Replayer_this, ::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::util::List* replayers, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , Replayer_this(Replayer_this)
    , id(id)
    , addr(addr)
    , replayers(replayers)
{
    clinit();
    ctor(nf, startPort, env);
}

org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::Replayer_Replayer_2(Replayer *Replayer_this, ::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::util::List* replayers, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , Replayer_this(Replayer_this)
    , id(id)
    , addr(addr)
    , replayers(replayers)
{
    clinit();
    ctor(nf, bindAddress, startPort, env);
}

rice::pastry::NodeHandle* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf)
{
    auto ret = java_cast< ::rice::pastry::socket::SocketNodeHandle* >(super::getLocalHandle(pn, nhf));
    npc(logger)->log(npc(ret)->toStringFull());
    return ret;
}

rice::environment::random::RandomSource* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::cloneRandomSource(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman)
{
    return npc(rootEnvironment)->getRandomSource();
}

org::mpisws::p2p::transport::TransportLayer* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */
{
    ::org::mpisws::p2p::transport::util::Serializer* serializer = new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer();
    ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv = new ::org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider();
    ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactory* shFactory = new ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl(hashProv, npc(pn)->getEnvironment());
    auto logName = ::java::lang::StringBuilder().append(u"0x"_j)->append(npc(npc(id)->toStringFull())->substring(0, 6))->toString();
    auto hist = npc(shFactory)->open(logName, u"r"_j);
    auto replay = new ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer(serializer, hashProv, hist, addr, npc(pn)->getEnvironment());
    npc(replay)->registerEvent(static_cast< ::org::mpisws::p2p::transport::peerreview::replay::EventCallback* >(Replayer_this), new ::int16_tArray({MyEvents::EVT_BOOT, MyEvents::EVT_SUBSCRIBE, MyEvents::EVT_PUBLISH}));
    npc(replayers)->add(static_cast< ::java::lang::Object* >(replay));
    return replay;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2::getClass0()
{
    return class_();
}

