// Generated from /pastry-2.1/src/rice/tutorial/remotesocket/Tutorial2.java
#include <rice/tutorial/remotesocket/Tutorial2.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Class.hpp>
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
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.hpp>
#include <rice/pastry/socket/appsocket/SocketFactory.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/standard/StandardAddress.hpp>
#include <rice/tutorial/remotesocket/MyApp.hpp>
#include <rice/tutorial/remotesocket/Tutorial2_Tutorial2_1.hpp>
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
rice::tutorial::remotesocket::Tutorial2::Tutorial2(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::remotesocket::Tutorial2::Tutorial2(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env, bool useDirect)  /* throws(Exception) */
    : Tutorial2(*static_cast< ::default_init_tag* >(0))
{
    ctor(bindport,bootaddress,numNodes,env,useDirect);
}

void rice::tutorial::remotesocket::Tutorial2::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::remotesocket::Tutorial2::ctor(int32_t bindport, ::java::net::InetSocketAddress* bootaddress, int32_t numNodes, ::rice::environment::Environment* env, bool useDirect) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    auto factory = new ::rice::pastry::socket::appsocket::AppSocketPastryNodeFactory(nidFactory, bindport, env);
    ::rice::p2p::commonapi::IdFactory* idFactory = new ::rice::pastry::commonapi::PastryIdFactory(env);
    for (auto curNode = int32_t(0); curNode < numNodes; curNode++) {
        auto node = npc(factory)->newNode();
        auto app = new MyApp(node, idFactory);
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
    npc(npc(env)->getTimeSource())->sleep(1000);
    auto sFactory = npc(factory)->getSocketFactory();
    npc(sFactory)->getSocketChannel(bootaddress, ::rice::pastry::standard::StandardAddress::getAddress(MyApp::class_(), u"myinstance"_j, env), new Tutorial2_Tutorial2_1(this), nullptr);
}

void rice::tutorial::remotesocket::Tutorial2::main(::java::lang::StringArray* args) /* throws(Exception) */
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
        auto numNodes = ::java::lang::Integer::parseInt((*args)[npc(args)->length - int32_t(1)]);
        if(!useDirect) {
            bindport = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
            auto bootaddr = ::java::net::InetAddress::getByName((*args)[int32_t(1)]);
            auto bootport = ::java::lang::Integer::parseInt((*args)[int32_t(2)]);
            bootaddress = new ::java::net::InetSocketAddress(bootaddr, bootport);
        }
        auto dt = new Tutorial2(bindport, bootaddress, numNodes, env, useDirect);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.appsocket.Tutorial localbindport bootIP bootPort numNodes"_j);
        npc(::java::lang::System::out())->println(u"  or"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.appsocket.Tutorial -direct numNodes"_j);
        npc(::java::lang::System::out())->println();
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial 9001 pokey.cs.almamater.edu 9001 10"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.DistTutorial -direct 10"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::remotesocket::Tutorial2::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.remotesocket.Tutorial2", 36);
    return c;
}

java::lang::Class* rice::tutorial::remotesocket::Tutorial2::getClass0()
{
    return class_();
}

