// Generated from /pastry-2.1/src/rice/selector/testing/SelectorTest.java
#include <rice/selector/testing/SelectorTest.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/selector/testing/SelectorTest_scheduleRepeated_1.hpp>
#include <rice/selector/testing/SelectorTest_scheduleStuff_2.hpp>
#include <rice/selector/testing/SelectorTest_scheduleStuff_3.hpp>

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

rice::selector::testing::SelectorTest::SelectorTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::selector::testing::SelectorTest::SelectorTest()
    : SelectorTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool& rice::selector::testing::SelectorTest::logAll()
{
    clinit();
    return logAll_;
}
bool rice::selector::testing::SelectorTest::logAll_;

bool& rice::selector::testing::SelectorTest::logIssues()
{
    clinit();
    return logIssues_;
}
bool rice::selector::testing::SelectorTest::logIssues_;

rice::environment::Environment*& rice::selector::testing::SelectorTest::environment()
{
    clinit();
    return environment_;
}
rice::environment::Environment* rice::selector::testing::SelectorTest::environment_;

void rice::selector::testing::SelectorTest::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    environment_ = new ::rice::environment::Environment();
    npc(::java::lang::System::out())->println(u"hello world <selector test>"_j);
    auto sman = npc(environment_)->getSelectorManager();
    auto timer = npc(sman)->getTimer();
    scheduleRepeated(timer, sman);
    for (auto i = int32_t(0); i < 10; i++) {
        scheduleStuff(timer, sman);
        try {
            ::java::lang::Thread::sleep(1000);
        } catch (::java::lang::InterruptedException* ie) {
        }
    }
}

void rice::selector::testing::SelectorTest::scheduleRepeated(::rice::selector::Timer* timer, ::rice::selector::SelectorManager* sman)
{
    clinit();
    auto const t1Start = npc(npc(environment_)->getTimeSource())->currentTimeMillis();
    auto const t1Delay = int32_t(3000);
    npc(timer)->schedule(new SelectorTest_scheduleRepeated_1(t1Start, t1Delay), t1Delay, t1Delay);
}

void rice::selector::testing::SelectorTest::scheduleStuff(::rice::selector::Timer* timer, ::rice::selector::SelectorManager* sman)
{
    clinit();
    auto const t1Start = npc(npc(environment_)->getTimeSource())->currentTimeMillis();
    auto const t1Delay = int32_t(5000);
    npc(timer)->schedule(new SelectorTest_scheduleStuff_2(t1Start, t1Delay), t1Delay);
    auto const i1Start = npc(npc(environment_)->getTimeSource())->currentTimeMillis();
    npc(sman)->invoke(new SelectorTest_scheduleStuff_3(i1Start));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::selector::testing::SelectorTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.selector.testing.SelectorTest", 34);
    return c;
}

void rice::selector::testing::SelectorTest::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        logAll_ = true;
        logIssues_ = true;
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::selector::testing::SelectorTest::getClass0()
{
    return class_();
}

