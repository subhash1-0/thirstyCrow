// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleBootTask_1.hpp>

#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Vector.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleBootTask_1_run_1_1.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial.hpp>
#include <rice/tutorial/deterministicsimulator/MyApp.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1::DirectTutorial_scheduleBootTask_1(DirectTutorial *DirectTutorial_this, ::rice::pastry::PastryNodeFactory* factory, ::rice::environment::Environment* env, int32_t numNodes, ::rice::pastry::NodeIdFactory* nidFactory)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectTutorial_this(DirectTutorial_this)
    , factory(factory)
    , env(env)
    , numNodes(numNodes)
    , nidFactory(nidFactory)
{
    clinit();
    init();
    ctor();
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1::init()
{
    bootHandle = nullptr;
    curNode = int32_t(0);
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1::run()
{
    try {
        auto const node = npc(factory)->newNode();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Creating new node "_j)->append(static_cast< ::java::lang::Object* >(node))
            ->append(u" at "_j)
            ->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
        auto app = new MyApp(node);
        npc(DirectTutorial_this->apps)->add(static_cast< ::java::lang::Object* >(app));
        curNode++;
        auto const myCurNode = curNode;
        npc(node)->addObserver(new DirectTutorial_scheduleBootTask_1_run_1_1(this, node, env, myCurNode, numNodes, nidFactory));
        npc(node)->boot(static_cast< ::java::lang::Object* >(bootHandle));
        bootHandle = npc(node)->getLocalHandle();
        if(curNode >= numNodes)
            cancel();

    } catch (::java::io::IOException* ioe) {
        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1::getClass0()
{
    return class_();
}

