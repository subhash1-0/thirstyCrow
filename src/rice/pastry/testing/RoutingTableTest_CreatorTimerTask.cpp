// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_CreatorTimerTask.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/pastry/testing/RoutingTableTest.hpp>

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
rice::pastry::testing::RoutingTableTest_CreatorTimerTask::RoutingTableTest_CreatorTimerTask(RoutingTableTest *RoutingTableTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RoutingTableTest_this(RoutingTableTest_this)
{
    clinit();
}

rice::pastry::testing::RoutingTableTest_CreatorTimerTask::RoutingTableTest_CreatorTimerTask(RoutingTableTest *RoutingTableTest_this) 
    : RoutingTableTest_CreatorTimerTask(RoutingTableTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::testing::RoutingTableTest_CreatorTimerTask::init()
{
    ctr = int32_t(0);
}

void rice::pastry::testing::RoutingTableTest_CreatorTimerTask::ctor()
{
    super::ctor();
    init();
}

void rice::pastry::testing::RoutingTableTest_CreatorTimerTask::run()
{
    try {
        RoutingTableTest_this->createNode();
    } catch (::java::lang::Exception* ie) {
        npc(ie)->printStackTrace();
    }
    {
        synchronized synchronized_0(this);
        {
            ctr++;
            if(ctr % int32_t(100) == 0) {
                npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Created "_j)->append(ctr)
                    ->append(u" nodes."_j)->toString());
            }
            if(ctr >= RoutingTableTest_this->numNodes) {
                RoutingTableTest_this->startLoggerTask();
                cancel();
            }
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_CreatorTimerTask::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.testing.RoutingTableTest.CreatorTimerTask", 53);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_CreatorTimerTask::getClass0()
{
    return class_();
}

