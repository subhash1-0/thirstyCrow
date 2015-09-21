// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/DistTutorial.java
#include <rice/tutorial/transportlayer/DistTutorial.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/tutorial/transportdirect/MyApp.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>
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
rice::tutorial::transportlayer::DistTutorial::DistTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::transportlayer::DistTutorial::DistTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env, int32_t bandwidth)  /* throws(Exception) */
    : DistTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env,bandwidth);
}

void rice::tutorial::transportlayer::DistTutorial::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::transportlayer::DistTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env, int32_t bandwidth) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    npc(npc(env)->getParameters())->setBoolean(u"transport_use_pns"_j, false);
    npc(npc(env)->getParameters())->setInt(u"rice.tutorial.transportlayer.BandwidthLimitingTransportLayer_loglevel"_j, ::rice::environment::logging::Logger::FINE);
    auto factory = BandwidthLimitingTransportLayer::exampleB(bindport, env, nidFactory, bandwidth, 1000);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto bootHandle = npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(bootaddress);
        auto node = npc(factory)->newNode();
        auto app = new ::rice::tutorial::transportdirect::MyApp(node);
        npc(apps)->add(static_cast< ::java::lang::Object* >(app));
        npc(node)->boot(static_cast< ::java::lang::Object* >(bootaddress));
        {
            synchronized synchronized_0(node);
            {
                while (!npc(node)->isReady() && !npc(node)->joinFailed()) {
                    npc(node)->wait(500);
                    if(npc(node)->joinFailed()) {
                        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Could not join the FreePastry ring.  Reason:"_j)->append(static_cast< ::java::lang::Object* >(npc(node)->joinFailedReason()))->toString());
                    }
                }
            }
        }
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());
    }
    npc(npc(env)->getTimeSource())->sleep(10000);
    for (auto i = int32_t(0); i < 10; i++) {
        auto appIterator = npc(apps)->iterator();
        while (npc(appIterator)->hasNext()) {
            auto app = java_cast< ::rice::tutorial::transportdirect::MyApp* >(java_cast< ::rice::tutorial::transportdirect::MyApp* >(npc(appIterator)->next()));
            ::rice::p2p::commonapi::Id* randId = npc(nidFactory)->generateNodeId();
            npc(app)->routeMyMsg(randId);
            npc(npc(env)->getTimeSource())->sleep(100);
        }
    }
    npc(npc(env)->getTimeSource())->sleep(1000);
    auto appIterator = npc(apps)->iterator();
    while (npc(appIterator)->hasNext()) {
        auto app = java_cast< ::rice::tutorial::transportdirect::MyApp* >(java_cast< ::rice::tutorial::transportdirect::MyApp* >(npc(appIterator)->next()));
        auto node = java_cast< ::rice::pastry::PastryNode* >(npc(app)->getNode());
        auto leafSet = npc(node)->getLeafSet();
        for (auto i = -npc(leafSet)->ccwSize(); i <= npc(leafSet)->cwSize(); i++) {
            if(i != 0) {
                auto nh = npc(leafSet)->get(i);
                npc(app)->routeMyMsgDirect(nh);
                npc(npc(env)->getTimeSource())->sleep(100);
            }
        }
    }
}

void rice::tutorial::transportlayer::DistTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setString(u"nat_search_policy"_j, u"never"_j);
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
        auto bandwidth = ::java::lang::Integer::parseInt((*args)[int32_t(4)]);
        auto dt = new DistTutorial(bindport, bootaddress, numNodes, env, bandwidth);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.transportlayer.DistTutorial localbindport bootIP bootPort numNodes bandwidth"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.transportlayer.DistTutorial 9001 pokey.cs.almamater.edu 9001 10 1000"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::DistTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.transportlayer.DistTutorial", 41);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::DistTutorial::getClass0()
{
    return class_();
}

