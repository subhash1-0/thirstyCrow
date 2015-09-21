// Generated from /pastry-2.1/src/rice/pastry/leafset/LeafSetProtocolAddress.java
#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>

rice::pastry::leafset::LeafSetProtocolAddress::LeafSetProtocolAddress(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::LeafSetProtocolAddress::LeafSetProtocolAddress()
    : LeafSetProtocolAddress(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

constexpr int32_t rice::pastry::leafset::LeafSetProtocolAddress::myCode;

int32_t rice::pastry::leafset::LeafSetProtocolAddress::getCode()
{
    clinit();
    return myCode;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::LeafSetProtocolAddress::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.LeafSetProtocolAddress", 42);
    return c;
}

java::lang::Class* rice::pastry::leafset::LeafSetProtocolAddress::getClass0()
{
    return class_();
}

