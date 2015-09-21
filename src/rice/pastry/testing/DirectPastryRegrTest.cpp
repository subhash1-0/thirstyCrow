// Generated from /pastry-2.1/src/rice/pastry/testing/DirectPastryRegrTest.java
#include <rice/pastry/testing/DirectPastryRegrTest.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Thread.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/direct/DirectNodeHandle.hpp>
#include <rice/pastry/direct/DirectPastryNode.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/direct/SphereNetwork.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/pastry/testing/RegrTestApp.hpp>

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

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}
rice::pastry::testing::DirectPastryRegrTest::DirectPastryRegrTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::testing::DirectPastryRegrTest::DirectPastryRegrTest()  /* throws(IOException) */
    : DirectPastryRegrTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::DirectPastryRegrTest::ctor() /* throws(IOException) */
{
    super::ctor(::rice::environment::Environment::directEnvironment());
    simulator = new ::rice::pastry::direct::SphereNetwork(environment);
    factory = new ::rice::pastry::direct::DirectPastryNodeFactory(new ::rice::pastry::standard::RandomNodeIdFactory(environment), simulator, environment);
}

rice::pastry::NodeHandle* rice::pastry::testing::DirectPastryRegrTest::getBootstrap(bool firstNode)
{
    ::rice::pastry::NodeHandle* bootstrap = nullptr;
    try {
        auto lastnode = java_cast< ::rice::pastry::PastryNode* >(java_cast< ::java::lang::Object* >(npc(pastryNodes)->lastElement()));
        bootstrap = npc(lastnode)->getLocalHandle();
    } catch (::java::util::NoSuchElementException* e) {
    }
    return bootstrap;
}

void rice::pastry::testing::DirectPastryRegrTest::registerapp(::rice::pastry::PastryNode* pn, RegrTestApp* app)
{
}

bool rice::pastry::testing::DirectPastryRegrTest::simulate()
{
    try {
        ::java::lang::Thread::sleep(300);
    } catch (::java::lang::InterruptedException* ie) {
    }
    return false;
}

void rice::pastry::testing::DirectPastryRegrTest::pause(int32_t ms)
{
}

bool rice::pastry::testing::DirectPastryRegrTest::isReallyAlive(::rice::pastry::NodeHandle* nh)
{
    return npc(simulator)->isAlive(java_cast< ::rice::pastry::direct::DirectNodeHandle* >(nh));
}

void rice::pastry::testing::DirectPastryRegrTest::killNode(::rice::pastry::PastryNode* pn)
{
    npc(pn)->destroy();
}

void rice::pastry::testing::DirectPastryRegrTest::checkRoutingTable(RegrTestApp* rta)
{
    auto temp = ::rice::pastry::direct::DirectPastryNode::setCurrentNode(npc(rta)->getPastryNode());
    {
        auto finally0 = finally([&] {
            ::rice::pastry::direct::DirectPastryNode::setCurrentNode(temp);
        });
        {
            super::checkRoutingTable(rta);
        }
    }

}

void rice::pastry::testing::DirectPastryRegrTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    auto pt = new DirectPastryRegrTest();
    mainfunc(pt, args, 500, 100, 10, 100, 1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::DirectPastryRegrTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.DirectPastryRegrTest", 40);
    return c;
}

java::lang::Class* rice::pastry::testing::DirectPastryRegrTest::getClass0()
{
    return class_();
}

