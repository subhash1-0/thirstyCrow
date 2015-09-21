// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_PastRegrTest_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor();
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::Runnable* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::String* arg0)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::Runnable* arg0, ::java::security::AccessControlContext* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::Runnable* arg0, ::java::lang::String* arg1)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1, arg2);
}

rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::PastRegrTest_PastRegrTest_1(PastRegrTest *PastRegrTest_this, ::java::lang::ThreadGroup* arg0, ::java::lang::Runnable* arg1, ::java::lang::String* arg2, int64_t arg3)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
    ctor(arg0, arg1, arg2, arg3);
}

void rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::run()
{
    while (PastRegrTest_this->running) {
        try {
            sleep(50);
            PastRegrTest_this->simulate();
        } catch (::java::lang::Exception* e) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(e))->append(u" blah"_j)->toString());
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_PastRegrTest_1::getClass0()
{
    return class_();
}

