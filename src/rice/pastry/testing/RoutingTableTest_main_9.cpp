// Generated from /pastry-2.1/src/rice/pastry/testing/RoutingTableTest.java
#include <rice/pastry/testing/RoutingTableTest_main_9.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>

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
rice::pastry::testing::RoutingTableTest_main_9::RoutingTableTest_main_9(::java::lang::Object* lock)
    : super(*static_cast< ::default_init_tag* >(0))
    , lock(lock)
{
    clinit();
    ctor();
}

void rice::pastry::testing::RoutingTableTest_main_9::destroy()
{
    {
        synchronized synchronized_0(lock);
        {
            npc(lock)->notify();
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::testing::RoutingTableTest_main_9::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::testing::RoutingTableTest_main_9::getClass0()
{
    return class_();
}

