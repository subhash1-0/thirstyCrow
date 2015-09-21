// Generated from /pastry-2.1/src/rice/selector/testing/SelectorTest.java
#include <rice/selector/testing/SelectorTest_scheduleStuff_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/testing/SelectorTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::selector::testing::SelectorTest_scheduleStuff_2::SelectorTest_scheduleStuff_2(int64_t t1Start, int32_t t1Delay)
    : super(*static_cast< ::default_init_tag* >(0))
    , t1Start(t1Start)
    , t1Delay(t1Delay)
{
    clinit();
    ctor();
}

void rice::selector::testing::SelectorTest_scheduleStuff_2::run()
{
    auto curTime = npc(npc(SelectorTest::environment())->getTimeSource())->currentTimeMillis();
    curTime -= t1Start;
    if((SelectorTest::logAll()) || (SelectorTest::logIssues() && (curTime - t1Delay) > 100))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Scheduled once for delay "_j)->append(t1Delay)
            ->append(u" actual delay "_j)
            ->append(curTime)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::testing::SelectorTest_scheduleStuff_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::selector::testing::SelectorTest_scheduleStuff_2::getClass0()
{
    return class_();
}

