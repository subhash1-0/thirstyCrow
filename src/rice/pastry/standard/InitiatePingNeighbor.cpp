// Generated from /pastry-2.1/src/rice/pastry/standard/InitiatePingNeighbor.java
#include <rice/pastry/standard/InitiatePingNeighbor.hpp>

#include <rice/pastry/leafset/LeafSetProtocolAddress.hpp>

rice::pastry::standard::InitiatePingNeighbor::InitiatePingNeighbor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::standard::InitiatePingNeighbor::InitiatePingNeighbor() 
    : InitiatePingNeighbor(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::pastry::standard::InitiatePingNeighbor::ctor()
{
    super::ctor(::rice::pastry::leafset::LeafSetProtocolAddress::getCode());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::standard::InitiatePingNeighbor::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.standard.InitiatePingNeighbor", 41);
    return c;
}

java::lang::Class* rice::pastry::standard::InitiatePingNeighbor::getClass0()
{
    return class_();
}

