// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_13.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_13_receiveResult_13_1.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13::AggregationImpl_handleDebugCommand_13(AggregationImpl *AggregationImpl_this, int32_t numFiles, int32_t avgBurstSize, double sizeSkew, int32_t smallSize, int32_t largeSize, int64_t expiration)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_this(AggregationImpl_this)
    , numFiles(numFiles)
    , avgBurstSize(avgBurstSize)
    , sizeSkew(sizeSkew)
    , smallSize(smallSize)
    , largeSize(largeSize)
    , expiration(expiration)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13::init()
{
    remainingTotal = numFiles;
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13::receiveResult(::java::lang::Object* o)
{
    if(remainingTotal > 0) {
        auto const burstSize = ::java::lang::Math::min(static_cast< int32_t >(((avgBurstSize * 0.3) + npc(npc(AggregationImpl_this->environment)->getRandomSource())->nextInt(static_cast< int32_t >((1.4 * avgBurstSize))))), remainingTotal);
        ::rice::Continuation* const outerContinuation = this;
        remainingTotal -= burstSize;
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Inserting burst of size "_j)->append(burstSize)
                ->append(u", remaining objects: "_j)
                ->append(remainingTotal)->toString());

        ::rice::Continuation* c2 = new AggregationImpl_handleDebugCommand_13_receiveResult_13_1(this, burstSize, sizeSkew, smallSize, largeSize, expiration, outerContinuation);
        npc(c2)->receiveResult(new ::java::lang::Boolean(true));
    } else {
        if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Monitor add completed, "_j)->append(numFiles)
                ->append(u" objects created successfully"_j)->toString());

    }
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_this->logger)->logException(u"Monitor.add aggregate insertion failed: "_j, e);

    receiveResult(static_cast< ::java::lang::Object* >(e));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13::getClass0()
{
    return class_();
}

