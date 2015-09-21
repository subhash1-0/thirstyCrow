// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Replayer.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collections.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEntryDeserializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer_Replayer_2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer_Replayer_1.hpp>
#include <org/mpisws/p2p/transport/direct/EventSimulator.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/BasicEntryDeserializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

org::mpisws::p2p::testing::transportlayer::replay::Replayer::Replayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::Replayer::Replayer(::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* bootaddress, int64_t startTime, int64_t randSeed)  /* throws(Exception) */
    : Replayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,addr,bootaddress,startTime,randSeed);
}

void org::mpisws::p2p::testing::transportlayer::replay::Replayer::ctor(::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* bootaddress, int64_t startTime, int64_t randSeed) /* throws(Exception) */
{
    super::ctor();
    this->bootaddress = bootaddress;
    auto env = ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::generateEnvironment(npc(id)->toString(), startTime, randSeed, nullptr);
    auto const params = npc(env)->getParameters();
    npc(params)->setInt(u"pastry_socket_scm_max_open_sockets"_j, npc(params)->getInt(u"org.mpisws.p2p.testing.transportlayer.replay_pastry_socket_scm_max_open_sockets"_j));
    npc(params)->setBoolean(u"pastry_socket_use_own_random"_j, false);
    logger = npc(npc(env)->getLogManager())->getLogger(Replayer::class_(), nullptr);
    auto const simLogger = npc(npc(env)->getLogManager())->getLogger(::org::mpisws::p2p::transport::direct::EventSimulator::class_(), nullptr);
    ::java::util::List* const replayers = new ::java::util::ArrayList();
    ::rice::pastry::socket::SocketPastryNodeFactory* factory = new Replayer_Replayer_2(this, id, addr, replayers, new Replayer_Replayer_1(this, id), npc(addr)->getPort(), env);
    node = java_cast< ::rice::pastry::PastryNode* >(npc(factory)->newNode());
    app = new MyScribeClient(node);
    auto sim = java_cast< ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM* >(npc(env)->getSelectorManager());
    auto replay = java_cast< ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer* >(npc(replayers)->get(0));
    npc(replay)->makeProgress();
    npc(sim)->setVerifier(replay);
    npc(sim)->start();
    try {
        npc(npc(env)->getTimeSource())->sleep(55000);
    } catch (::java::lang::InterruptedException* ie) {
        return;
    }
    npc(env)->destroy();
}

void org::mpisws::p2p::testing::transportlayer::replay::Replayer::replayNode(::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::net::InetSocketAddress* bootaddress, int64_t startTime, int64_t randSeed) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    if(npc(npc(env)->getParameters())->getBoolean(u"org.mpisws.p2p.testing.transportlayer.replay.Replayer_printlog"_j))
        printLog(::java::lang::StringBuilder().append(u"0x"_j)->append(npc(npc(id)->toStringFull())->substring(0, 6))->toString(), env);

    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(id)->toStringFull())->append(u" "_j)
        ->append(npc(npc(addr)->getAddress())->getHostAddress())
        ->append(u" "_j)
        ->append(npc(addr)->getPort())
        ->append(u" "_j)
        ->append(npc(bootaddress)->getPort())
        ->append(u" "_j)
        ->append(startTime)
        ->append(u" "_j)
        ->append(randSeed)->toString());
    npc(env)->destroy();
    new Replayer(id, addr, bootaddress, startTime, randSeed);
}

void org::mpisws::p2p::testing::transportlayer::replay::Replayer::printLog(::java::lang::String* arg, ::rice::environment::Environment* env) /* throws(IOException) */
{
    clinit();
    ::org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::printLog(arg, new MyEntryDeserializer(new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer()), env);
}

void org::mpisws::p2p::testing::transportlayer::replay::Replayer::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto hex = (*args)[int32_t(0)];
    auto a = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
    auto startPort = npc(::java::lang::Integer::decode((*args)[int32_t(2)]))->intValue();
    auto bootPort = npc(::java::lang::Integer::decode((*args)[int32_t(3)]))->intValue();
    auto addr = new ::java::net::InetSocketAddress(a, startPort);
    auto bootaddress = new ::java::net::InetSocketAddress(a, bootPort);
    auto startTime = npc(::java::lang::Long::decode((*args)[int32_t(4)]))->longValue();
    auto randSeed = npc(::java::lang::Long::decode((*args)[int32_t(5)]))->longValue();
    replayNode(::rice::pastry::Id::build(hex), addr, bootaddress, startTime, randSeed);
}

void org::mpisws::p2p::testing::transportlayer::replay::Replayer::replayEvent(int16_t type, ::rice::p2p::commonapi::rawserialization::InputBuffer* entry)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"replayEvent("_j)->append(type)
            ->append(u")"_j)->toString());

    switch (type) {
    case EVT_BOOT:
        npc(npc(node)->getBootstrapper())->boot(::java::util::Collections::singletonList(bootaddress));
        break;
    case EVT_SUBSCRIBE:
        npc(app)->subscribe();
        break;
    case EVT_PUBLISH:
        npc(app)->startPublishTask();
        break;
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Replayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.Replayer", 53);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Replayer::getClass0()
{
    return class_();
}

