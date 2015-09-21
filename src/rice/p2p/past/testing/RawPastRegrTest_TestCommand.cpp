// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_TestCommand.hpp>

#include <java/lang/Exception.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

rice::p2p::past::testing::RawPastRegrTest_TestCommand::RawPastRegrTest_TestCommand(RawPastRegrTest *RawPastRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
}

rice::p2p::past::testing::RawPastRegrTest_TestCommand::RawPastRegrTest_TestCommand(RawPastRegrTest *RawPastRegrTest_this)
    : RawPastRegrTest_TestCommand(RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_TestCommand::receiveResult(::java::lang::Object* result)
{
    try {
        receive(result);
    } catch (::java::lang::Exception* e) {
        receiveException(e);
    }
}

void rice::p2p::past::testing::RawPastRegrTest_TestCommand::receive(::java::lang::Object* result) /* throws(Exception) */
{
}

void rice::p2p::past::testing::RawPastRegrTest_TestCommand::receiveException(::java::lang::Exception* e)
{
    RawPastRegrTest_this->stepException(e);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestCommand::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.RawPastRegrTest.TestCommand", 49);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestCommand::getClass0()
{
    return class_();
}

