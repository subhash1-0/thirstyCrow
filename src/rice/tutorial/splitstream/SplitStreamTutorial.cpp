// Generated from /pastry-2.1/src/rice/tutorial/splitstream/SplitStreamTutorial.java
#include <rice/tutorial/splitstream/SplitStreamTutorial.hpp>

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
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/tutorial/splitstream/MySplitStreamClient.hpp>
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
rice::tutorial::splitstream::SplitStreamTutorial::SplitStreamTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::splitstream::SplitStreamTutorial::SplitStreamTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env, bool useDirect)  /* throws(Exception) */
    : SplitStreamTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env,useDirect);
}

void rice::tutorial::splitstream::SplitStreamTutorial::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::splitstream::SplitStreamTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env, bool useDirect) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory;
    if(useDirect) {
        ::rice::pastry::direct::NetworkSimulator* sim = new ::rice::pastry::direct::EuclideanNetwork(env);
        factory = new ::rice::pastry::direct::DirectPastryNodeFactory(nidFactory, sim, env);
    } else {
        factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    }
    ::rice::p2p::commonapi::IdFactory* idFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    ::java::lang::Object* bootHandle = nullptr;
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto node = npc(factory)->newNode();
        auto app = new MySplitStreamClient(node);
        npc(apps)->add(static_cast< ::java::lang::Object* >(app));
        npc(node)->boot(bootHandle);
        if(bootHandle == nullptr) {
            if(useDirect) {
                bootHandle = npc(node)->getLocalHandle();
            } else {
                bootHandle = bootaddress;
            }
        }
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
    auto i = npc(apps)->iterator();
    auto app = java_cast< MySplitStreamClient* >(java_cast< MySplitStreamClient* >(npc(i)->next()));
    npc(app)->subscribe();
    npc(app)->startPublishTask();
    while (npc(i)->hasNext()) {
        app = java_cast< MySplitStreamClient* >(java_cast< MySplitStreamClient* >(npc(i)->next()));
        npc(app)->subscribe();
    }
    npc(npc(env)->getTimeSource())->sleep(5000);
}

void rice::tutorial::splitstream::SplitStreamTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    try {
        bool useDirect;
        if(npc((*args)[int32_t(0)])->equalsIgnoreCase(u"-direct"_j)) {
            useDirect = true;
        } else {
            useDirect = false;
        }
        ::rice::environment::Environment* env;
        if(useDirect) {
            env = ::rice::environment::Environment::directEnvironment();
        } else {
            env = new ::rice::environment::Environment();
            npc(npc(env)->getParameters())->setString(u"nat_search_policy"_j, u"never"_j);
        }
        auto bindport = int32_t(0);
        ::java::net::InetSocketAddress* bootaddress = nullptr;
        int32_t numNodes;
        if(!useDirect) {
            bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
            auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
            auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
            numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(3)]);
            bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        } else {
            numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(1)]);
        }
        auto dt = new SplitStreamTutorial(bindport, bootaddress, numNodes, env, useDirect);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.lesson6.ScribeTutorial localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial 9001 pokey.cs.almamater.edu 9001 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::splitstream::SplitStreamTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.splitstream.SplitStreamTutorial", 45);
    return c;
}

java::lang::Class* rice::tutorial::splitstream::SplitStreamTutorial::getClass0()
{
    return class_();
}

