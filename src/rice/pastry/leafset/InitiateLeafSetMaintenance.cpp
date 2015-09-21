// Generated from /pastry-2.1/src/rice/pastry/leafset/InitiateLeafSetMaintenance.java
#include <rice/pastry/leafset/InitiateLeafSetMaintenance.hpp>

#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>

rice::pastry::leafset::InitiateLeafSetMaintenance::InitiateLeafSetMaintenance(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::leafset::InitiateLeafSetMaintenance::InitiateLeafSetMaintenance() 
    : InitiateLeafSetMaintenance(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::leafset::InitiateLeafSetMaintenance::ctor()
{
    super::ctor(LeafSetProtocolAddress::getCode());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::leafset::InitiateLeafSetMaintenance::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.leafset.InitiateLeafSetMaintenance", 46);
    return c;
}

java::lang::Class* rice::pastry::leafset::InitiateLeafSetMaintenance::getClass0()
{
    return class_();
}

