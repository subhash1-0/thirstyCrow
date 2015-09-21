// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestResolve.hpp>

#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestResolve2.hpp>

rice::p2p::util::testing::XMLObjectStreamUnit_TestResolve::XMLObjectStreamUnit_TestResolve(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestResolve::XMLObjectStreamUnit_TestResolve()
    : XMLObjectStreamUnit_TestResolve(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Object* rice::p2p::util::testing::XMLObjectStreamUnit_TestResolve::readResolve()
{
    return new XMLObjectStreamUnit_TestResolve2();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestResolve::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestResolve", 53);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestResolve::getClass0()
{
    return class_();
}

