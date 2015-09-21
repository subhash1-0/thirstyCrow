// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_testCustomSerializer_1.hpp>

#include <rice/p2p/util/testing/XMLObjectStreamUnit.hpp>

rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::XMLObjectStreamUnit_testCustomSerializer_1(XMLObjectStreamUnit *XMLObjectStreamUnit_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , XMLObjectStreamUnit_this(XMLObjectStreamUnit_this)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::init()
{
    hashCode_ = int32_t(83);
}

int32_t rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::hashCode()
{
    return hashCode_;
}

void rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::readObject(::java::io::ObjectInputStream* oos) /* throws(IOException, ClassNotFoundException) */
{
    hashCode_ = 100;
}

void rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_testCustomSerializer_1::getClass0()
{
    return class_();
}

