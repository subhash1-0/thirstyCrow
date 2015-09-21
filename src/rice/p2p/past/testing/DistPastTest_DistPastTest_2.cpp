// Generated from /pastry-2.1/src/rice/p2p/past/testing/DistPastTest.java
#include <rice/p2p/past/testing/DistPastTest_DistPastTest_2.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/past/testing/DistPastTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::testing::DistPastTest_DistPastTest_2::DistPastTest_DistPastTest_2(DistPastTest *DistPastTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistPastTest_this(DistPastTest_this)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::DistPastTest_DistPastTest_2::receiveResult(::java::lang::Object* result)
{
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Got a "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

void rice::p2p::past::testing::DistPastTest_DistPastTest_2::receiveException(::java::lang::Exception* result)
{
    npc(result)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::DistPastTest_DistPastTest_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::DistPastTest_DistPastTest_2::getClass0()
{
    return class_();
}

