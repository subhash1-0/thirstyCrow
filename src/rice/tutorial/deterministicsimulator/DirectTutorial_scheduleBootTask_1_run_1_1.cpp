// Generated from /pastry-2.1/src/rice/tutorial/deterministicsimulator/DirectTutorial.java
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleBootTask_1_run_1_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Throwable.hpp>
#include <java/util/Observable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial_scheduleBootTask_1.hpp>
#include <rice/tutorial/deterministicsimulator/DirectTutorial.hpp>

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
rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1_run_1_1::DirectTutorial_scheduleBootTask_1_run_1_1(DirectTutorial_scheduleBootTask_1 *DirectTutorial_scheduleBootTask_1_this, ::rice::pastry::PastryNode* node, ::rice::environment::Environment* env, int32_t myCurNode, int32_t numNodes, ::rice::pastry::NodeIdFactory* nidFactory)
    : super(*static_cast< ::default_init_tag* >(0))
    , DirectTutorial_scheduleBootTask_1_this(DirectTutorial_scheduleBootTask_1_this)
    , node(node)
    , env(env)
    , myCurNode(myCurNode)
    , numNodes(numNodes)
    , nidFactory(nidFactory)
{
    clinit();
    ctor();
}

void rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1_run_1_1::update(::java::util::Observable* o, ::java::lang::Object* arg)
{
    {
        auto finally0 = finally([&] {
            npc(o)->deleteObserver(this);
        });
        {
            if(dynamic_cast< ::java::lang::Boolean* >(arg) != nullptr) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Finished creating new node "_j)->append(static_cast< ::java::lang::Object* >(node))
                    ->append(u" at "_j)
                    ->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
                if(myCurNode == numNodes) {
                    DirectTutorial_scheduleBootTask_1_this->DirectTutorial_this->scheduleDeliveryTask(nidFactory, env);
                }
            } else if(dynamic_cast< ::rice::pastry::JoinFailedException* >(arg) != nullptr) {
                auto jfe = java_cast< ::rice::pastry::JoinFailedException* >(arg);
                npc(jfe)->printStackTrace();
                throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(jfe));
            }
        }
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1_run_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::tutorial::deterministicsimulator::DirectTutorial_scheduleBootTask_1_run_1_1::getClass0()
{
    return class_();
}

