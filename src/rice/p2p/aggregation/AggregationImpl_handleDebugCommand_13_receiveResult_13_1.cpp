// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationImpl.java
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_13_receiveResult_13_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Vector.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/p2p/aggregation/AggregationImpl_handleDebugCommand_13.hpp>
#include <rice/p2p/aggregation/AggregationImpl.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/glacier/v2/DebugContent.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13_receiveResult_13_1::AggregationImpl_handleDebugCommand_13_receiveResult_13_1(AggregationImpl_handleDebugCommand_13 *AggregationImpl_handleDebugCommand_13_this, int32_t burstSize, double sizeSkew, int32_t smallSize, int32_t largeSize, int64_t expiration, ::rice::Continuation* outerContinuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , AggregationImpl_handleDebugCommand_13_this(AggregationImpl_handleDebugCommand_13_this)
    , burstSize(burstSize)
    , sizeSkew(sizeSkew)
    , smallSize(smallSize)
    , largeSize(largeSize)
    , expiration(expiration)
    , outerContinuation(outerContinuation)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13_receiveResult_13_1::init()
{
    remainingHere = burstSize;
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13_receiveResult_13_1::receiveResult(::java::lang::Object* o)
{
    if(remainingHere > 0) {
        if(npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Continuing burst insert, "_j)->append(remainingHere)
                ->append(u" remaining"_j)->toString());

        auto thisAvgSize = ((0.001 * npc(npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->environment)->getRandomSource())->nextInt(1000)) < sizeSkew) ? smallSize : largeSize;
        auto thisSize = static_cast< int32_t >((0.3 * thisAvgSize + npc(npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->environment)->getRandomSource())->nextInt(static_cast< int32_t >((1.4 * thisAvgSize)))));
        auto randomID = npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->factory)->buildRandomId(npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->environment)->getRandomSource());
        remainingHere--;
        npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->monitorIDs)->add(static_cast< ::java::lang::Object* >(randomID));
        AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->insert(static_cast< ::rice::p2p::past::PastContent* >(new ::rice::p2p::glacier::v2::DebugContent(randomID, false, int32_t(0), new ::int8_tArray(thisSize))), expiration, static_cast< ::rice::Continuation* >(this));
    } else {
        if(npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->logger)->log(u"Burst insertion complete, flushing..."_j);

        AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->flush(outerContinuation);
    }
}

void rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13_receiveResult_13_1::receiveException(::java::lang::Exception* e)
{
    if(npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(AggregationImpl_handleDebugCommand_13_this->AggregationImpl_this->logger)->logException(u"Monitor.add component insertion failed: "_j, e);

    receiveResult(static_cast< ::java::lang::Object* >(e));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13_receiveResult_13_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregationImpl_handleDebugCommand_13_receiveResult_13_1::getClass0()
{
    return class_();
}

