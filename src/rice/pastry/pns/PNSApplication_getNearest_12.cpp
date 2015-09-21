// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getNearest_12.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/pns/PNSApplication_getNearest_12_receiveResult_12_1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getNearest_12::PNSApplication_getNearest_12(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* seed, ::rice::p2p::util::AttachableCancellable* ret, ::rice::Continuation* retToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
    , seed(seed)
    , ret(ret)
    , retToMe(retToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getNearest_12::receiveResult(::rice::pastry::leafset::LeafSet* result)
{
    if(npc(PNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"getNearest("_j)->append(static_cast< ::java::lang::Object* >(seed))
            ->append(u") got "_j)
            ->append(static_cast< ::java::lang::Object* >(result))->toString());

    auto nearNode = seed;
    auto currentClosest = seed;
    npc(ret)->attach(PNSApplication_this->closestToMe(nearNode, result, static_cast< ::rice::Continuation* >(new PNSApplication_getNearest_12_receiveResult_12_1(this, ret, retToMe))));
}

void rice::pastry::pns::PNSApplication_getNearest_12::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::rice::pastry::leafset::LeafSet* >(result));
}

void rice::pastry::pns::PNSApplication_getNearest_12::receiveException(::java::lang::Exception* exception)
{
    npc(retToMe)->receiveException(exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_12::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getNearest_12::getClass0()
{
    return class_();
}

