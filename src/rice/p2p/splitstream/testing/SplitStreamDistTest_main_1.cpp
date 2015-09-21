// Generated from /pastry-2.1/src/rice/p2p/splitstream/testing/SplitStreamDistTest.java
#include <rice/p2p/splitstream/testing/SplitStreamDistTest_main_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/splitstream/testing/SplitStreamDistTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::splitstream::testing::SplitStreamDistTest_main_1::SplitStreamDistTest_main_1(::rice::environment::Environment* env)
    : super(*static_cast< ::default_init_tag* >(0))
    , env(env)
{
    clinit();
    ctor();
}

void rice::p2p::splitstream::testing::SplitStreamDistTest_main_1::run()
{
    while (true) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"ImALIVE:"_j)->append(npc(npc(env)->getTimeSource())->currentTimeMillis())->toString());
        try {
            ::java::lang::Thread::sleep(SplitStreamDistTest::IM_ALIVE_PERIOD);
        } catch (::java::lang::Exception* e) {
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamDistTest_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::splitstream::testing::SplitStreamDistTest_main_1::getClass0()
{
    return class_();
}

