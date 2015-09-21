// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/util/List.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_12.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_12_receiveResult_12_1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1(PNSApplication_getNearest_12_receiveResult_12_1 *PNSApplication_getNearest_12_receiveResult_12_1_this, ::rice::Continuation* retToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_getNearest_12_receiveResult_12_1_this(PNSApplication_getNearest_12_receiveResult_12_1_this)
    , retToMe(retToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1::receiveResult(::rice::pastry::NodeHandle* result)
{
    auto nearNode = result;
    npc(retToMe)->receiveResult(PNSApplication_getNearest_12_receiveResult_12_1_this->PNSApplication_getNearest_12_this->PNSApplication_this->sortedProximityCache());
}

void rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::NodeHandle* >(result));
}

void rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(retToMe)->receiveResult(PNSApplication_getNearest_12_receiveResult_12_1_this->PNSApplication_getNearest_12_this->PNSApplication_this->sortedProximityCache());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1::getClass0()
{
    return class_();
}

