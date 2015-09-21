// Generated from /pastry-2.1/src/rice/p2p/past/testing/PastRegrTest.java
#include <rice/p2p/past/testing/PastRegrTest_TestExceptionCommand.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/testing/CommonAPITest.hpp>
#include <rice/p2p/past/testing/PastRegrTest.hpp>

rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::PastRegrTest_TestExceptionCommand(PastRegrTest *PastRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PastRegrTest_this(PastRegrTest_this)
{
    clinit();
}

rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::PastRegrTest_TestExceptionCommand(PastRegrTest *PastRegrTest_this)
    : PastRegrTest_TestExceptionCommand(PastRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::receiveResult(::java::lang::Object* result)
{
    PastRegrTest_this->stepDone(::rice::p2p::commonapi::testing::CommonAPITest::FAILURE(), ::java::lang::StringBuilder().append(u"Command should throw an exception - got "_j)->append(static_cast< ::java::lang::Object* >(result))->toString());
}

void rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::receive(::java::lang::Object* result) /* throws(Exception) */
{
}

void rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::receiveException(::java::lang::Exception* e)
{
    try {
        receive(e);
    } catch (::java::lang::Exception* ex) {
        receiveException(ex);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.testing.PastRegrTest.TestExceptionCommand", 55);
    return c;
}

java::lang::Class* rice::p2p::past::testing::PastRegrTest_TestExceptionCommand::getClass0()
{
    return class_();
}

