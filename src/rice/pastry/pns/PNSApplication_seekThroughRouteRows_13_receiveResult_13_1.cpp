// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_seekThroughRouteRows_13_receiveResult_13_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication_seekThroughRouteRows_13.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1(PNSApplication_seekThroughRouteRows_13 *PNSApplication_seekThroughRouteRows_13_this, int16_t i, int16_t depth, ::rice::pastry::NodeHandle* currentClosest, ::rice::Continuation* returnToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_seekThroughRouteRows_13_this(PNSApplication_seekThroughRouteRows_13_this)
    , i(i)
    , depth(depth)
    , currentClosest(currentClosest)
    , returnToMe(returnToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1::receiveResult(::rice::pastry::NodeHandle* nearNode)
{
    if((i >= depth - int32_t(1)) && (npc(currentClosest)->equals(static_cast< ::java::lang::Object* >(nearNode)))) {
        npc(returnToMe)->receiveResult(nearNode);
    } else {
        auto newIndex = static_cast< int16_t >((i + int32_t(1)));
        if(newIndex > depth - int32_t(1))
            newIndex = static_cast< int16_t >((depth - int32_t(1)));

        PNSApplication_seekThroughRouteRows_13_this->PNSApplication_this->seekThroughRouteRows(newIndex, depth, nearNode, returnToMe);
    }
}

void rice::pastry::pns::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::NodeHandle* >(result));
}

void rice::pastry::pns::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1::receiveException(::java::lang::Exception* exception)
{
    npc(returnToMe)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_seekThroughRouteRows_13_receiveResult_13_1::getClass0()
{
    return class_();
}

