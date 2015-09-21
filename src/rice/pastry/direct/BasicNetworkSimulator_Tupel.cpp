// Generated from /pastry-2.1/src/rice/pastry/direct/BasicNetworkSimulator.java
#include <rice/pastry/direct/BasicNetworkSimulator_Tupel.hpp>

#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>
#include <rice/pastry/direct/BasicNetworkSimulator.hpp>
#include <rice/pastry/direct/NodeRecord.hpp>

rice::pastry::direct::BasicNetworkSimulator_Tupel::BasicNetworkSimulator_Tupel(BasicNetworkSimulator *BasicNetworkSimulator_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , BasicNetworkSimulator_this(BasicNetworkSimulator_this)
{
    clinit();
}

rice::pastry::direct::BasicNetworkSimulator_Tupel::BasicNetworkSimulator_Tupel(BasicNetworkSimulator *BasicNetworkSimulator_this, ::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* tl, NodeRecord* record) 
    : BasicNetworkSimulator_Tupel(BasicNetworkSimulator_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(i,tl,record);
}

void rice::pastry::direct::BasicNetworkSimulator_Tupel::ctor(::java::lang::Object* i, ::org::mpisws::p2p::transport::direct::DirectTransportLayer* tl, NodeRecord* record)
{
    super::ctor();
    this->i = i;
    this->tl = tl;
    this->record = record;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::direct::BasicNetworkSimulator_Tupel::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.direct.BasicNetworkSimulator.Tupel", 46);
    return c;
}

java::lang::Class* rice::pastry::direct::BasicNetworkSimulator_Tupel::getClass0()
{
    return class_();
}

