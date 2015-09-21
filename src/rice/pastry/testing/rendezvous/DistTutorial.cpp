// Generated from /pastry-2.1/src/rice/pastry/testing/rendezvous/DistTutorial.java
#include <rice/pastry/testing/rendezvous/DistTutorial.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
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
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeIdFactory.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/nat/rendezvous/RendezvousSocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/rendezvous/MyApp.hpp>
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
rice::pastry::testing::rendezvous::DistTutorial::DistTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::rendezvous::DistTutorial::DistTutorial(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env, bool firewalled)  /* throws(Exception) */
    : DistTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,env,firewalled);
}

void rice::pastry::testing::rendezvous::DistTutorial::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, ::rice::environment::Environment* env, bool firewalled) /* throws(Exception) */
{
    super::ctor();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    auto factory = new ::rice::pastry::socket::nat::rendezvous::RendezvousSocketPastryNodeFactory(nidFactory, bindport, env, firewalled);
    auto bootHandle = npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(bootaddress);
    auto node = npc(factory)->newNode(bootHandle);
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
    auto app = new MyApp(node);
    npc(npc(env)->getTimeSource())->sleep(10000);
    if(bootHandle != nullptr) {
        for (auto i = int32_t(0); i < 10; i++) {
            ::rice::p2p::commonapi::Id* randId = npc(nidFactory)->generateNodeId();
            npc(app)->routeMyMsg(randId);
            npc(npc(env)->getTimeSource())->sleep(1000);
        }
        npc(npc(env)->getTimeSource())->sleep(10000);
        auto leafSet = npc(node)->getLeafSet();
        for (auto i = -npc(leafSet)->ccwSize(); i <= npc(leafSet)->cwSize(); i++) {
            if(i != 0) {
                auto nh = npc(leafSet)->get(i);
                npc(app)->routeMyMsgDirect(nh);
                npc(npc(env)->getTimeSource())->sleep(1000);
            }
        }
    }
}

void rice::pastry::testing::rendezvous::DistTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setString(u"nat_search_policy"_j, u"never"_j);
    try {
        auto bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
        auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
        auto bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        auto firewalled = ::java::lang::Boolean::parseBoolean((*args)[int32_t(3)]);
        auto dt = new DistTutorial(bindport, bootaddress, env, firewalled);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.lesson3.DistTutorial localbindport bootIP bootPort natted"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial 9001 pokey.cs.almamater.edu 9001 true"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::rendezvous::DistTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.rendezvous.DistTutorial", 43);
    return c;
}

java::lang::Class* rice::pastry::testing::rendezvous::DistTutorial::getClass0()
{
    return class_();
}
