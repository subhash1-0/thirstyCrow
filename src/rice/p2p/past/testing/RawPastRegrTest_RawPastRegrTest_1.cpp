// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_RawPastRegrTest_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor();
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::Runnable* target)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(target);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::String* name)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(name);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::ThreadGroup* group, ::java::lang::Runnable* target)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(group, target);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::ThreadGroup* group, ::java::lang::String* name)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(group, name);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::Runnable* target, ::java::lang::String* name)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(target, name);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::ThreadGroup* group, ::java::lang::Runnable* target, ::java::lang::String* name)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(group, target, name);
}

rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::RawPastRegrTest_RawPastRegrTest_1(RawPastRegrTest *RawPastRegrTest_this, ::java::lang::ThreadGroup* group, ::java::lang::Runnable* target, ::java::lang::String* name, int64_t stackSize)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
    ctor(group, target, name, stackSize);
}

void rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::run()
{
    while (RawPastRegrTest_this->running) {
        try {
            sleep(50);
            RawPastRegrTest_this->simulate();
        } catch (::java::lang::Exception* e) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(e))->append(u" blah"_j)->toString());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_RawPastRegrTest_1::getClass0()
{
    return class_();
}

