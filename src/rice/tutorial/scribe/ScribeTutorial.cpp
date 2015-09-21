// Generated from /pastry-2.1/src/rice/tutorial/scribe/ScribeTutorial.java
#include <rice/tutorial/scribe/ScribeTutorial.hpp>

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
#include <java/util/Hashtable.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Observable.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/tutorial/scribe/MyScribeClient.hpp>
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
rice::tutorial::scribe::ScribeTutorial::ScribeTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::scribe::ScribeTutorial::ScribeTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env)  /* throws(Exception) */
    : ScribeTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env);
}

void rice::tutorial::scribe::ScribeTutorial::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::scribe::ScribeTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::socket::SocketPastryNodeFactory(nidFactory, bindport, env);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto node = npc(factory)->newNode();
        auto app = new MyScribeClient(node);
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
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node: "_j)->append(static_cast< ::java::lang::Object* >(node))->toString());
    }
    auto i = npc(apps)->iterator();
    auto app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(i)->next()));
    npc(app)->subscribe();
    npc(app)->startPublishTask();
    while (npc(i)->hasNext()) {
        app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(i)->next()));
        npc(app)->subscribe();
    }
    npc(npc(env)->getTimeSource())->sleep(5000);
    printTree(apps);
}

void rice::tutorial::scribe::ScribeTutorial::printTree(::java::util::Vector* apps)
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

rice::p2p::commonapi::NodeHandle* rice::tutorial::scribe::ScribeTutorial::getRoot(::rice::p2p::commonapi::NodeHandle* seed, ::java::util::Hashtable* appTable)
{
    clinit();
    auto app = java_cast< MyScribeClient* >(java_cast< MyScribeClient* >(npc(appTable)->get(static_cast< ::java::lang::Object* >(seed))));
    if(npc(app)->isRoot())
        return seed;

    auto nextSeed = npc(app)->getParent();
    return getRoot(nextSeed, appTable);
}

void rice::tutorial::scribe::ScribeTutorial::recursivelyPrintChildren(::rice::p2p::commonapi::NodeHandle* curNode, int32_t recursionDepth, ::java::util::Hashtable* appTable)
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

void rice::tutorial::scribe::ScribeTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
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
        auto dt = new ScribeTutorial(bindport, bootaddress, numNodes, env);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.scribe.ScribeTutorial localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.scribe.ScribeTutorial 9001 pokey.cs.almamater.edu 9001 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::scribe::ScribeTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.scribe.ScribeTutorial", 35);
    return c;
}

java::lang::Class* rice::tutorial::scribe::ScribeTutorial::getClass0()
{
    return class_();
}

