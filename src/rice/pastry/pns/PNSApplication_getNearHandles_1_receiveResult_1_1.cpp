// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_getNearHandles_1_receiveResult_1_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Collection.hpp>
#include <java/util/List.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/AttachableCancellable.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/pns/PNSApplication_getNearHandles_1.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::PNSApplication_getNearHandles_1_receiveResult_1_1(PNSApplication_getNearHandles_1 *PNSApplication_getNearHandles_1_this, ::rice::p2p::util::AttachableCancellable* ret, ::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_getNearHandles_1_this(PNSApplication_getNearHandles_1_this)
    , ret(ret)
    , bootHandles(bootHandles)
    , deliverResultToMe(deliverResultToMe)
{
    clinit();
    ctor();
}

void rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::receiveResult(::java::util::Collection* result)
{
    if(npc(PNSApplication_getNearHandles_1_this->PNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(PNSApplication_getNearHandles_1_this->PNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"receiveResult("_j)->append(static_cast< ::java::lang::Object* >(result))
            ->append(u") in getNearHandles()"_j)->toString());

    npc(ret)->cancel();
    finish();
}

void rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Collection* >(result));
}

void rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::receiveException(::java::lang::Exception* exception)
{
    npc(PNSApplication_getNearHandles_1_this->PNSApplication_this->logger)->logException(u"PNS got an exception in getNearHandles() returning what we got."_j, exception);
    finish();
}

void rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::finish()
{
    npc(PNSApplication_getNearHandles_1_this->PNSApplication_this->thePastryNode)->removeProximityListener(static_cast< ::org::mpisws::p2p::transport::proximity::ProximityListener* >(PNSApplication_getNearHandles_1_this->PNSApplication_this));
    auto ret = PNSApplication_getNearHandles_1_this->PNSApplication_this->sortedProximityCache();
    PNSApplication_getNearHandles_1_this->PNSApplication_this->purgeProximityCache();
    if(npc(PNSApplication_getNearHandles_1_this->PNSApplication_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(PNSApplication_getNearHandles_1_this->PNSApplication_this->logger)->log(::java::lang::StringBuilder().append(u"getNearHandles("_j)->append(static_cast< ::java::lang::Object* >(bootHandles))
            ->append(u"):"_j)
            ->append(npc(ret)->size())
            ->append(static_cast< ::java::lang::Object* >(ret))->toString());

    npc(deliverResultToMe)->receiveResult(PNSApplication_getNearHandles_1_this->PNSApplication_this->getNearHandlesHelper(ret));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::pastry::pns::PNSApplication_getNearHandles_1_receiveResult_1_1::getClass0()
{
    return class_();
}

