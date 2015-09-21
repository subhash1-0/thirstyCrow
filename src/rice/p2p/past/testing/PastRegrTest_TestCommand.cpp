// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_TestCommand.hpp>

#include <java/lang/Exception.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

rice::p2p::past::testing::PastRegrTest_TestCommand::PastRegrTest_TestCommand(PastRegrTest *PastRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest_TestCommand::PastRegrTest_TestCommand(PastRegrTest *PastRegrTest_this)
    : PastRegrTest_TestCommand(PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_TestCommand::receiveResult(::java::lang::Object* result)
{
    try {
        receive(result);
    } catch (::java::lang::Exception* e) {
        receiveException(e);
    }
}

void rice::p2p::past::testing::PastRegrTest_TestCommand::receive(::java::lang::Object* result) /* throws(Exception) */
{
}

void rice::p2p::past::testing::PastRegrTest_TestCommand::receiveException(::java::lang::Exception* e)
{
    PastRegrTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestCommand::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest.TestCommand", 46);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestCommand::getClass0()
{
    return class_();
}

