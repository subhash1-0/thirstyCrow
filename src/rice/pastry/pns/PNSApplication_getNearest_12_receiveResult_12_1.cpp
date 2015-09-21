// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getNearest_12_receiveResult_12_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/List.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_12.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1::PNSApplication_getNearest_12_receiveResult_12_1(PNSApplication_getNearest_12 *PNSApplication_getNearest_12_this, ::rice::p2p::util::AttachableCancellable* ret, ::rice::Continuation* retToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_getNearest_12_this(PNSApplication_getNearest_12_this)
    , ret(ret)
    , retToMe(retToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1::receiveResult(::rice::pastry::NodeHandle* result)
{
    auto nearNode = result;
    int16_t i = int32_t(0);
    if(!npc(npc(npc(PNSApplication_getNearest_12_this->PNSApplication_this->environment)->getParameters())->getString(u"pns_num_rows_to_use"_j))->equalsIgnoreCase(u"all"_j)) {
        i = static_cast< int16_t >((PNSApplication_getNearest_12_this->PNSApplication_this->depth - static_cast< int16_t >((npc(npc(PNSApplication_getNearest_12_this->PNSApplication_this->environment)->getParameters())->getInt(u"pns_num_rows_to_use"_j)))));
    }
    if(i < 0)
        i = 0;

    npc(ret)->attach(PNSApplication_getNearest_12_this->PNSApplication_this->seekThroughRouteRows(i, PNSApplication_getNearest_12_this->PNSApplication_this->depth, nearNode, new PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1(this, retToMe)));
}

void rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::NodeHandle* >(result));
}

void rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1::receiveException(::java::lang::Exception* exception)
{
    npc(retToMe)->receiveResult(PNSApplication_getNearest_12_this->PNSApplication_this->sortedProximityCache());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1::getClass0()
{
    return class_();
}

