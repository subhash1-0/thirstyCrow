// Generated from /pastry-2.1/src/rice/pastry/testing/DistHelloWorld.java
#include <rice/pastry/testing/DistHelloWorld.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/net/UnknownHostException.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/dist/DistPastryNodeFactory.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>
#include <rice/pastry/standard/IPNodeIdFactory.hpp>
#include <rice/pastry/testing/HelloWorldApp.hpp>
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
rice::pastry::testing::DistHelloWorld::DistHelloWorld(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::DistHelloWorld::DistHelloWorld(::rice::environment::Environment* env)  /* throws(IOException) */
    : DistHelloWorld(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

int32_t& rice::pastry::testing::DistHelloWorld::port()
{
    clinit();
    return port_;
}
int32_t rice::pastry::testing::DistHelloWorld::port_;

java::lang::String*& rice::pastry::testing::DistHelloWorld::bshost()
{
    clinit();
    return bshost_;
}
java::lang::String* rice::pastry::testing::DistHelloWorld::bshost_;

int32_t& rice::pastry::testing::DistHelloWorld::bsport()
{
    clinit();
    return bsport_;
}
int32_t rice::pastry::testing::DistHelloWorld::bsport_;

int32_t& rice::pastry::testing::DistHelloWorld::numnodes()
{
    clinit();
    return numnodes_;
}
int32_t rice::pastry::testing::DistHelloWorld::numnodes_;

int32_t& rice::pastry::testing::DistHelloWorld::nummsgs()
{
    clinit();
    return nummsgs_;
}
int32_t rice::pastry::testing::DistHelloWorld::nummsgs_;

int32_t& rice::pastry::testing::DistHelloWorld::protocol()
{
    clinit();
    return protocol_;
}
int32_t rice::pastry::testing::DistHelloWorld::protocol_;

void rice::pastry::testing::DistHelloWorld::ctor(::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    environment = env;
    factory = ::rice::pastry::dist::DistPastryNodeFactory::getFactory(new ::rice::pastry::standard::IPNodeIdFactory(::java::net::InetAddress::getLocalHost(), port_, env), protocol_, port_, env);
    pastryNodes = new ::java::util::Vector();
    helloClients = new ::java::util::Vector();
}

rice::pastry::NodeHandle* rice::pastry::testing::DistHelloWorld::getBootstrap(bool firstNode)
{
    ::java::net::InetSocketAddress* addr = nullptr;
    if(firstNode && bshost_ != nullptr)
        addr = new ::java::net::InetSocketAddress(bshost_, bsport_);
    else {
        try {
            addr = new ::java::net::InetSocketAddress(npc(::java::net::InetAddress::getLocalHost())->getHostName(), bsport_);
        } catch (::java::net::UnknownHostException* e) {
            npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(e));
        }
    }
    auto bshandle = npc((java_cast< ::rice::pastry::socket::SocketPastryNodeFactory* >(factory)))->getNodeHandle(addr);
    return bshandle;
}

void rice::pastry::testing::DistHelloWorld::doIinitstuff(::java::lang::StringArray* args, ::rice::environment::Environment* env)
{
    clinit();
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-help"_j))) {
            npc(::java::lang::System::out())->println(u"Usage: DistHelloWorld [-msgs m] [-nodes n] [-port p] [-bootstrap bshost[:bsport]]"_j);
            npc(::java::lang::System::out())->println(u"                     [-protocol (rmi|wire)] [-verbose|-silent|-verbosity v] [-help]"_j);
            npc(::java::lang::System::out())->println(u""_j);
            npc(::java::lang::System::out())->println(u"  Ports p and bsport refer to RMI registry  or Socket port numbers (default = 5009)."_j);
            npc(::java::lang::System::out())->println(u"  Without -bootstrap bshost[:bsport], only localhost:p is used for bootstrap."_j);
            npc(::java::lang::System::out())->println(u"  Default verbosity is 8, -verbose is 1, and -silent is 10 (error msgs only)."_j);
            ::java::lang::System::exit(1);
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-msgs"_j)) && i + int32_t(1) < npc(args)->length)
            nummsgs_ = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);

    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-verbosity"_j)) && i + int32_t(1) < npc(args)->length) {
            auto num = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            npc(npc(env)->getParameters())->setInt(u"loglevel"_j, num * int32_t(100));
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-silent"_j)) && i + int32_t(1) < npc(args)->length) {
            npc(npc(env)->getParameters())->setInt(u"loglevel"_j, ::rice::environment::logging::Logger::SEVERE);
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-verbose"_j)) && i + int32_t(1) < npc(args)->length) {
            npc(npc(env)->getParameters())->setInt(u"loglevel"_j, ::rice::environment::logging::Logger::ALL);
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-port"_j)) && i + int32_t(1) < npc(args)->length) {
            auto p = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(p > 0) {
                port_ = p;
                bsport_ = p;
            }
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-bootstrap"_j)) && i + int32_t(1) < npc(args)->length) {
            auto str = (*args)[i + int32_t(1)];
            auto index = npc(str)->indexOf(static_cast< int32_t >(u':'));
            if(index == -int32_t(1)) {
                bshost_ = str;
                bsport_ = port_;
            } else {
                bshost_ = npc(str)->substring(0, index);
                bsport_ = ::java::lang::Integer::parseInt(npc(str)->substring(index + int32_t(1)));
                if(bsport_ <= 0)
                    bsport_ = port_;

            }
            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-nodes"_j)) && i + int32_t(1) < npc(args)->length) {
            auto n = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);
            if(n > 0)
                numnodes_ = n;

            break;
        }
    }
    for (auto i = int32_t(0); i < npc(args)->length; i++) {
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-protocol"_j)) && i + int32_t(1) < npc(args)->length) {
            auto s = (*args)[i + int32_t(1)];
            if(npc(s)->equalsIgnoreCase(u"socket"_j))
                protocol_ = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_SOCKET();
            else
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ERROR: Unsupported protocol: "_j)->append(s)->toString());
            break;
        }
    }
}

rice::pastry::PastryNode* rice::pastry::testing::DistHelloWorld::makePastryNode(bool firstNode)
{
    auto bootstrap = getBootstrap(firstNode);
    auto pn = npc(factory)->newNode(bootstrap);
    npc(pastryNodes)->addElement(pn);
    auto app = new HelloWorldApp(pn);
    npc(helloClients)->addElement(app);
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"created "_j)->append(static_cast< ::java::lang::Object* >(pn))->toString());
    return pn;
}

void rice::pastry::testing::DistHelloWorld::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    npc(npc(env)->getParameters())->setInt(u"loglevel"_j, 800);
    doIinitstuff(args, env);
    auto driver = new DistHelloWorld(env);
    auto pn = npc(driver)->makePastryNode(true);
    {
        synchronized synchronized_0(pn);
        {
            while (!npc(pn)->isReady()) {
                try {
                    npc(pn)->wait();
                } catch (::java::lang::InterruptedException* e) {
                    npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(e));
                }
            }
        }
    }
    for (auto i = int32_t(1); i < numnodes_; i++) {
        pn = npc(driver)->makePastryNode(false);
        {
            synchronized synchronized_1(pn);
            {
                while (!npc(pn)->isReady()) {
                    try {
                        npc(pn)->wait();
                    } catch (::java::lang::InterruptedException* e) {
                        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(e));
                    }
                }
            }
        }
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(numnodes_)->append(u" nodes constructed"_j)->toString());
    for (auto i = int32_t(0); i < nummsgs_; i++) {
        for (auto client = int32_t(0); client < npc(npc(driver)->helloClients)->size(); client++) {
            auto app = java_cast< HelloWorldApp* >(java_cast< ::java::lang::Object* >(npc(npc(driver)->helloClients)->get(client)));
            npc(app)->sendRndMsg(npc(npc(driver)->environment)->getRandomSource());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::DistHelloWorld::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.DistHelloWorld", 34);
    return c;
}

void rice::pastry::testing::DistHelloWorld::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        port_ = int32_t(5009);
        bshost_ = nullptr;
        bsport_ = int32_t(5009);
        numnodes_ = int32_t(1);
        nummsgs_ = int32_t(2);
        protocol_ = ::rice::pastry::dist::DistPastryNodeFactory::PROTOCOL_DEFAULT();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::DistHelloWorld::getClass0()
{
    return class_();
}

