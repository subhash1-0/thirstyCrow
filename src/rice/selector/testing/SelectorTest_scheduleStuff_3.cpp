// Generated from /pastry-2.1/src/rice/selector/testing/SelectorTest.java
#include <rice/selector/testing/SelectorTest_scheduleStuff_3.hpp>

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

rice::selector::testing::SelectorTest_scheduleStuff_3::SelectorTest_scheduleStuff_3(int64_t i1Start)
    : super(*static_cast< ::default_init_tag* >(0))
    , i1Start(i1Start)
{
    clinit();
    ctor();
}

void rice::selector::testing::SelectorTest_scheduleStuff_3::run()
{
    auto curTime = npc(npc(SelectorTest::environment())->getTimeSource())->currentTimeMillis();
    curTime -= i1Start;
    if((SelectorTest::logAll()) || (SelectorTest::logIssues() && (curTime > 100)))
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"invoked after "_j)->append(curTime)
            ->append(u" millis."_j)->toString());

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::testing::SelectorTest_scheduleStuff_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::selector::testing::SelectorTest_scheduleStuff_3::getClass0()
{
    return class_();
}

