// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java
#include <rice/p2p/past/testing/RawPastRegrTest_TestExceptionCommand.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/testing/CommonAPITest.hpp>
#include <rice/p2p/past/testing/RawPastRegrTest.hpp>

rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::RawPastRegrTest_TestExceptionCommand(RawPastRegrTest *RawPastRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RawPastRegrTest_this(RawPastRegrTest_this)
{
    clinit();
}

rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::RawPastRegrTest_TestExceptionCommand(RawPastRegrTest *RawPastRegrTest_this)
    : RawPastRegrTest_TestExceptionCommand(RawPastRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::receiveResult(::java::lang::Object* result)
{
    RawPastRegrTest_this->stepDone(::rice::p2p::commonapi::testing::CommonAPITest::FAILURE(), ::java::lang::StringBuilder().append(u"Command should throw an exception - got "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

void rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::receive(::java::lang::Object* result) /* throws(Exception) */
{
}

void rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::receiveException(::java::lang::Exception* e)
{
    try {
        receive(e);
    } catch (::java::lang::Exception* ex) {
        receiveException(ex);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.RawPastRegrTest.TestExceptionCommand", 58);
    return c;
}

java::lang::Class* rice::p2p::past::testing::RawPastRegrTest_TestExceptionCommand::getClass0()
{
    return class_();
}

