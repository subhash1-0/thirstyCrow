// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Observable.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyEntryDeserializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/MyScribeClient.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_Recorder_2.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_PublishInvokation.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Recorder_SubscribeInvokation.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/Replayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/BasicEntryDeserializer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/params/simple/SimpleParameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/socket/SocketNodeHandle.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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

    namespace util
    {
typedef ::SubArray< ::java::util::Observable, ::java::lang::ObjectArray > ObservableArray;
    } // util
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::NodeHandle, ::java::util::ObservableArray, ::java::io::SerializableArray > NodeHandleArray;
        } // commonapi
    } // p2p
} // rice

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::testing::transportlayer::replay::Recorder::Recorder(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::replay::Recorder::Recorder(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env)  /* throws(Exception) */
    : Recorder(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env);
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder::init()
{
    apps = new ::java::util::ArrayList();
    storedRandSeed = new ::java::util::HashMap();
    recorders = new ::java::util::HashMap();
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    init();
    auto const params = npc(env)->getParameters();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::socket::SocketPastryNodeFactory* const factory = new Recorder_Recorder_1(this, nidFactory, bindport, env);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto const nodeContainer = new ::java::util::ArrayList(int32_t(1));
        npc(npc(env)->getSelectorManager())->invoke(new Recorder_Recorder_2(this, factory, nodeContainer, bootaddress));
        {
            synchronized synchronized_0(nodeContainer);
            {
                while (npc(nodeContainer)->isEmpty()) {
                    npc(nodeContainer)->wait(500);
                }
            }
        }
        auto node = java_cast< ::rice::pastry::PastryNode* >(npc(nodeContainer)->get(int32_t(0)));
        {
            synchronized synchronized_1(node);
            {
                while (!npc(node)->isReady() && !npc(node)->joinFailed()) {
                    npc(node)->wait(500);
                    if(npc(node)->joinFailed()) {
                        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not join the FreePastry ring.  Reason:"_j)->append(static_cast< ::java::lang::Object* >(npc(node)->joinFailedReason()))->toString());
                    }
                }
            }
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node: "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());
    }
    auto i = npc(apps)->iterator();
    auto app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(i)->next()));
    npc(npc(env)->getSelectorManager())->invoke(new Recorder_SubscribeInvokation(this, app));
    npc(npc(env)->getSelectorManager())->invoke(new Recorder_PublishInvokation(this, app));
    while (npc(i)->hasNext()) {
        app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(i)->next()));
        npc(npc(env)->getSelectorManager())->invoke(new Recorder_SubscribeInvokation(this, app));
    }
    npc(npc(env)->getTimeSource())->sleep(5000);
    printTree(apps);
    npc(npc(env)->getTimeSource())->sleep(15000);
    npc(env)->destroy();
    npc(::java::lang::System::out())->println(u"done recording"_j);
    ::java::lang::Thread::sleep(1000);
    auto playbackCtr = int32_t(0);
    auto mscI = npc(apps)->iterator();
    while (playbackCtr < npc(params)->getInt(u"org.mpisws.p2p.testing.transportlayer.replay.num_playbacks"_j) && npc(mscI)->hasNext()) {
        app = java_cast< MyScribeClient* >(npc(mscI)->next());
        auto endpoint = npc(app)->endpoint;
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"playing back "_j)->append(static_cast< ::java::lang::Object* >(npc(app)->node))->toString());
        if(npc(params)->getBoolean(u"org.mpisws.p2p.testing.transportlayer.replay.Recorder_printlog"_j))
            printLog(::java::lang::StringBuilder().append(u"0x"_j)->append(npc(npc(npc(endpoint)->getId())->toStringFull())->substring(0, 6))->toString(), new ::rice::environment::Environment());

        auto snh = java_cast< ::rice::pastry::socket::SocketNodeHandle* >(npc(endpoint)->getLocalNodeHandle());
        try {
            Replayer::replayNode(java_cast< ::rice::pastry::Id* >(npc(snh)->getId()), npc(snh)->getInetSocketAddress(), bootaddress, npc(snh)->getEpoch(), (npc(java_cast< ::java::lang::Long* >(npc(storedRandSeed)->get(npc(snh)->getId()))))->longValue());
        } catch (::java::lang::InterruptedException* ie) {
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"finished playing "_j)->append(static_cast< ::java::lang::Object* >(npc(app)->node))->toString());
        playbackCtr++;
    }
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder::printLog(::java::lang::String* arg, ::rice::environment::Environment* env) /* throws(IOException) */
{
    ::org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::printLog(arg, new MyEntryDeserializer(new ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer()), env);
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder::printTree(::java::util::ArrayList* apps)
{
    clinit();
    auto appTable = new ::java::util::Hashtable();
    auto i = npc(apps)->iterator();
    while (npc(i)->hasNext()) {
        auto app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(i)->next()));
        npc(appTable)->put(static_cast< ::java::lang::Object* >(npc(npc(app)->endpoint)->getLocalNodeHandle()), static_cast< ::java::lang::Object* >(app));
    }
    auto seed = npc(npc((java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(apps)->get(int32_t(0))))))->endpoint)->getLocalNodeHandle();
    auto root = getRoot(seed, appTable);
    recursivelyPrintChildren(root, 0, appTable);
}

rice::p2p::commonapi::NodeHandle* org::mpisws::p2p::testing::transportlayer::replay::Recorder::getRoot(::rice::p2p::commonapi::NodeHandle* seed, ::java::util::Hashtable* appTable)
{
    clinit();
    auto app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(appTable)->get(static_cast< ::java::lang::Object* >(seed))));
    if(npc(app)->isRoot())
        return seed;

    auto nextSeed = npc(app)->getParent();
    return getRoot(nextSeed, appTable);
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder::recursivelyPrintChildren(::rice::p2p::commonapi::NodeHandle* curNode, int32_t recursionDepth, ::java::util::Hashtable* appTable)
{
    clinit();
    auto s = u""_j;
    for (auto numTabs = int32_t(0); numTabs < recursionDepth; numTabs++) {
        s = ::java::lang::StringBuilder(s).append(u"  "_j)->toString();
    }
    s = ::java::lang::StringBuilder(s).append(npc(npc(curNode)->getId())->toString())->toString();
    npc(::java::lang::System::out())->println(s);
    auto app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(appTable)->get(static_cast< ::java::lang::Object* >(curNode))));
    auto children = npc(app)->getChildren();
    for (auto curChild = int32_t(0); curChild < npc(children)->length; curChild++) {
        recursivelyPrintChildren((*children)[curChild], recursionDepth + int32_t(1), appTable);
    }
}

void org::mpisws::p2p::testing::transportlayer::replay::Recorder::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    ::rice::environment::params::Parameters* params = new ::rice::environment::params::simple::SimpleParameters(::rice::environment::Environment::defaultParamFileArray_(), nullptr);
    if(npc(params)->getBoolean(u"org.mpisws.p2p.testing.transportlayer.replay.Recorder_logtofile"_j)) {
        ::java::lang::System::setOut(new ::java::io::PrintStream(u"replay.txt"_j));
        ::java::lang::System::setErr(::java::lang::System::out());
    }
    auto env = ::org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::generateEnvironment();
    params = npc(env)->getParameters();
    npc(params)->setInt(u"pastry_socket_scm_max_open_sockets"_j, npc(params)->getInt(u"org.mpisws.p2p.testing.transportlayer.replay_pastry_socket_scm_max_open_sockets"_j));
    npc(params)->setBoolean(u"pastry_socket_use_own_random"_j, false);
    npc(params)->setString(u"nat_search_policy"_j, u"never"_j);
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
        auto dt = new Recorder(bindport, bootaddress, numNodes, env);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.scribe.ScribeTutorial localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.scribe.ScribeTutorial 9001 pokey.cs.almamater.edu 9001 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.replay.Recorder", 53);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::replay::Recorder::getClass0()
{
    return class_();
}

