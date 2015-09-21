// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestReplace.hpp>

#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestReplace2.hpp>

rice::p2p::util::testing::XMLObjectStreamUnit_TestReplace::XMLObjectStreamUnit_TestReplace(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestReplace::XMLObjectStreamUnit_TestReplace()
    : XMLObjectStreamUnit_TestReplace(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Object* rice::p2p::util::testing::XMLObjectStreamUnit_TestReplace::writeReplace()
{
    return new XMLObjectStreamUnit_TestReplace2();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestReplace::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestReplace", 53);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestReplace::getClass0()
{
    return class_();
}

