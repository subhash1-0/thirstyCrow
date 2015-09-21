// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java
#include <rice/tutorial/deterministicsimulator/DirectTutorial.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/pastry/direct/DirectPastryNodeFactory.hpp>
#include <rice/pastry/direct/EuclideanNetwork.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleBootTask_1.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleDeliveryTask_2.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleDeliveryTask_3.hpp>
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

rice::tutorial::deterministicsimulator::DirectTutorial::DirectTutorial(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::deterministicsimulator::DirectTutorial::DirectTutorial(int32_t numNodes, ::rice::environment::Environment* env)  /* throws(Exception) */
    : DirectTutorial(*static_cast< ::default_init_tag* >(0))
{
    ctor(numNodes,env);
}

void rice::tutorial::deterministicsimulator::DirectTutorial::init()
{
    apps = new ::java::util::Vector();
}

void rice::tutorial::deterministicsimulator::DirectTutorial::ctor(int32_t numNodes, ::rice::environment::Environment* env) /* throws(Exception) */
{
    super::ctor();
    init();
    ::rice::pastry::NodeIdFactory* const nidFactory = new ::rice::pastry::standard::RandomNodeIdFactory(env);
    ::rice::pastry::direct::NetworkSimulator* simulator = new ::rice::pastry::direct::EuclideanNetwork(env);
    npc(simulator)->stop();
    ::rice::pastry::PastryNodeFactory* factory = new ::rice::pastry::direct::DirectPastryNodeFactory(nidFactory, simulator, env);
    scheduleBootTask(numNodes, nidFactory, factory, env);
    npc(simulator)->start();
}

void rice::tutorial::deterministicsimulator::DirectTutorial::scheduleBootTask(int32_t numNodes, ::rice::pastry::NodeIdFactory* nidFactory, ::rice::pastry::PastryNodeFactory* factory, ::rice::environment::Environment* env)
{
    npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new DirectTutorial_scheduleBootTask_1(this, factory, env, numNodes, nidFactory), 0, 1000);
}

void rice::tutorial::deterministicsimulator::DirectTutorial::scheduleDeliveryTask(::rice::pastry::NodeIdFactory* nidFactory, ::rice::environment::Environment* env)
{
    npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new DirectTutorial_scheduleDeliveryTask_2(this, nidFactory), 10000, 1000);
    npc(npc(npc(env)->getSelectorManager())->getTimer())->schedule(new DirectTutorial_scheduleDeliveryTask_3(this), 20000, 1000);
}

void rice::tutorial::deterministicsimulator::DirectTutorial::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    ::rice::environment::Environment* env;
    if(npc(args)->length > 1) {
        auto randSeed = ::java::lang::Integer::parseInt((*args)[int32_t(1)]);
        env = ::rice::environment::Environment::directEnvironment(randSeed);
    } else {
        env = ::rice::environment::Environment::directEnvironment();
    }
    try {
        auto numNodes = ::java::lang::Integer::parseInt((*args)[int32_t(0)]);
        auto dt = new DirectTutorial(numNodes, env);
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Usage:"_j);
        npc(::java::lang::System::out())->println(u"java [-cp FreePastry-<version>.jar] rice.tutorial.direct.DirectTutorial numNodes"_j);
        npc(::java::lang::System::out())->println(u"example java rice.tutorial.direct.DirectTutorial 100"_j);
        throw e;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.deterministicsimulator.DirectTutorial", 51);
    return c;
}

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial::getClass0()
{
    return class_();
}

