// Generated from /pastry-2.1/src/rice/pastry/testing/HelloWorld.java
#include <rice/pastry/testing/HelloWorld.hpp>

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
#include <java/lang/Thread.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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
rice::pastry::testing::HelloWorld::HelloWorld(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::HelloWorld::HelloWorld(::rice::environment::Environment* env) 
    : HelloWorld(*static_cast< ::default_init_tag* >(0))
{
    ctor(env);
}

int32_t& rice::pastry::testing::HelloWorld::numnodes()
{
    clinit();
    return numnodes_;
}
int32_t rice::pastry::testing::HelloWorld::numnodes_;

int32_t& rice::pastry::testing::HelloWorld::nummsgs()
{
    clinit();
    return nummsgs_;
}
int32_t rice::pastry::testing::HelloWorld::nummsgs_;

bool& rice::pastry::testing::HelloWorld::simultaneous_joins()
{
    clinit();
    return simultaneous_joins_;
}
bool rice::pastry::testing::HelloWorld::simultaneous_joins_;

bool& rice::pastry::testing::HelloWorld::simultaneous_msgs()
{
    clinit();
    return simultaneous_msgs_;
}
bool rice::pastry::testing::HelloWorld::simultaneous_msgs_;

void rice::pastry::testing::HelloWorld::ctor(::rice::environment::Environment* env)
{
    super::ctor();
    environment = env;
    simulator = new ::rice::pastry::direct::EuclideanNetwork(env);
    factory = new ::rice::pastry::direct::DirectPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(environment), simulator, environment);
    pastryNodes = new ::java::util::Vector();
    helloClients = new ::java::util::Vector();
}

rice::pastry::NodeHandle* rice::pastry::testing::HelloWorld::getBootstrap()
{
    ::rice::pastry::NodeHandle* bootstrap = nullptr;
    try {
        auto lastnode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->lastElement()));
        bootstrap = npc(lastnode)->getLocalHandle();
    } catch (::java::util::NoSuchElementException* e) {
    }
    return bootstrap;
}

void rice::pastry::testing::HelloWorld::makePastryNode(int32_t num)
{
    auto pn = npc(factory)->newNode(getBootstrap());
    npc(pastryNodes)->addElement(pn);
    auto app = new HelloWorldApp(pn);
    npc(helloClients)->addElement(app);
    {
        synchronized synchronized_0(pn);
        {
            while (!npc(pn)->isReady()) {
                try {
                    npc(pn)->wait(300);
                } catch (::java::lang::InterruptedException* ie) {
                }
            }
        }
    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"created "_j)->append(num)
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(pn))->toString());
}

void rice::pastry::testing::HelloWorld::printLeafSets()
{
    for (auto i = int32_t(0); i < npc(pastryNodes)->size(); i++) {
        auto pn = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->get(i)));
        npc(::java::lang::System::out())->println(npc(npc(pn)->getLeafSet())->toString());
    }
}

void rice::pastry::testing::HelloWorld::sendRandomMessage()
{
    auto n = npc(helloClients)->size();
    auto client = npc(npc(environment)->getRandomSource())->nextInt(n);
    auto app = java_cast< HelloWorldApp* >(java_cast< ::java::lang::Object* >(npc(helloClients)->get(client)));
    npc(app)->sendRndMsg(npc(environment)->getRandomSource());
}

bool rice::pastry::testing::HelloWorld::simulate()
{
    return false;
}

void rice::pastry::testing::HelloWorld::doIinitstuff(::java::lang::StringArray* args, ::rice::environment::Environment* env)
{
    clinit();
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
        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-nodes"_j)) && i + int32_t(1) < npc(args)->length)
            numnodes_ = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);

        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-msgs"_j)) && i + int32_t(1) < npc(args)->length)
            nummsgs_ = ::java::lang::Integer::parseInt((*args)[i + int32_t(1)]);

        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-simultaneous_joins"_j)))
            simultaneous_joins_ = true;

        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-simultaneous_msgs"_j)))
            simultaneous_msgs_ = true;

        if(npc((*args)[i])->equals(static_cast< ::java::lang::Object* >(u"-help"_j))) {
            npc(::java::lang::System::out())->println(u"Usage: HelloWorld [-msgs m] [-nodes n] [-verbose|-silent|-verbosity v]"_j);
            npc(::java::lang::System::out())->println(u"                  [-simultaneous_joins] [-simultaneous_msgs] [-help]"_j);
            npc(::java::lang::System::out())->println(u"  Default verbosity is 8, -verbose is 1, and -silent is 10 (error msgs only)."_j);
            ::java::lang::System::exit(1);
        }
    }
}

void rice::pastry::testing::HelloWorld::main(::java::lang::StringArray* args)
{
    clinit();
    auto env = ::rice::environment::Environment::directEnvironment();
    doIinitstuff(args, env);
    auto driver = new HelloWorld(env);
    for (auto i = int32_t(0); i < numnodes_; i++) {
        npc(driver)->makePastryNode(i);
        if(simultaneous_joins_ == false)
            while (npc(driver)->simulate()) 
                                ;


    }
    if(simultaneous_joins_) {
        npc(::java::lang::System::out())->println(u"let the joins begin!"_j);
        while (npc(driver)->simulate()) 
                        ;

    }
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(numnodes_)->append(u" nodes constructed"_j)->toString());
    npc(driver)->printLeafSets();
    for (auto i = int32_t(0); i < nummsgs_; i++) {
        npc(driver)->sendRandomMessage();
        if(simultaneous_msgs_ == false)
            while (npc(driver)->simulate()) 
                                ;


    }
    if(simultaneous_msgs_) {
        npc(::java::lang::System::out())->println(u"let the msgs begin!"_j);
        while (npc(driver)->simulate()) 
                        ;

    }
    try {
        ::java::lang::Thread::sleep(5000);
    } catch (::java::lang::InterruptedException* ie) {
    }
    npc(env)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::HelloWorld::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.HelloWorld", 30);
    return c;
}

void rice::pastry::testing::HelloWorld::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        numnodes_ = int32_t(3);
        nummsgs_ = int32_t(30);
        simultaneous_joins_ = false;
        simultaneous_msgs_ = false;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::pastry::testing::HelloWorld::getClass0()
{
    return class_();
}

