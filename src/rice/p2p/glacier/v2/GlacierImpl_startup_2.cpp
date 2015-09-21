// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierImpl.java
#include <rice/p2p/glacier/v2/GlacierImpl_startup_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl_startup_2_timeoutExpired_2_1.hpp>
#include <rice/p2p/glacier/v2/GlacierImpl.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborRequestMessage.hpp>
#include <rice/p2p/glacier/v2/messaging/GlacierNeighborResponseMessage.hpp>
#include <rice/persistence/StorageManager.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::GlacierImpl_startup_2::GlacierImpl_startup_2(GlacierImpl *GlacierImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , GlacierImpl_this(GlacierImpl_this)
{
    clinit();
    ctor();
}

java::lang::String* rice::p2p::glacier::v2::GlacierImpl_startup_2::toString()
{
    return u"Neighbor continuation"_j;
}

void rice::p2p::glacier::v2::GlacierImpl_startup_2::init_()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->expireNeighborsDelayAfterJoin;
    auto leafSet = npc(GlacierImpl_this->endpoint)->neighborSet(999);
    auto localHandle = GlacierImpl_this->getLocalNodeHandle();
    auto cwExtreme = localHandle;
    auto ccwExtreme = localHandle;
    for (auto i = int32_t(0); i < npc(leafSet)->size(); i++) {
        auto thisHandle = npc(leafSet)->getHandle(i);
        if(npc(npc(localHandle)->getId())->clockwise(npc(thisHandle)->getId())) {
            if(npc(npc(cwExtreme)->getId())->clockwise(npc(thisHandle)->getId()))
                cwExtreme = thisHandle;

        } else {
            if(npc(npc(ccwExtreme)->getId())->clockwise(npc(thisHandle)->getId()))
                ccwExtreme = thisHandle;

        }
    }
    auto leafRange = npc(GlacierImpl_this->factory)->buildIdRange(npc(ccwExtreme)->getId(), npc(cwExtreme)->getId());
    for (auto k = int32_t(0); k < npc(leafSet)->size(); k++) {
        if(!npc(npc(npc(leafSet)->getHandle(k))->getId())->equals(npc(GlacierImpl_this->getLocalNodeHandle())->getId())) {
            GlacierImpl_this->neighborSeen(npc(npc(leafSet)->getHandle(k))->getId(), npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis());
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Asking "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(leafSet)->getHandle(k))->getId()))
                    ->append(u" about neighbors in "_j)
                    ->append(static_cast< ::java::lang::Object* >(leafRange))->toString());

            GlacierImpl_this->sendMessage(nullptr, new ::rice::p2p::glacier::v2::messaging::GlacierNeighborRequestMessage(getMyUID(), leafRange, GlacierImpl_this->getLocalNodeHandle(), npc(npc(leafSet)->getHandle(k))->getId(), GlacierImpl_this->tagNeighbor), npc(leafSet)->getHandle(k));
        }
    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_2::receiveResult(::java::lang::Object* o)
{
    if(dynamic_cast< ::rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage* >(o) != nullptr) {
        auto const gnrm = java_cast< ::rice::p2p::glacier::v2::messaging::GlacierNeighborResponseMessage* >(o);
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"NeighborResponse from "_j)->append(static_cast< ::java::lang::Object* >(npc(gnrm)->getSource()))
                ->append(u" with "_j)
                ->append(npc(gnrm)->numNeighbors())
                ->append(u" neighbors"_j)->toString());

        for (auto i = int32_t(0); i < npc(gnrm)->numNeighbors(); i++) 
                        GlacierImpl_this->neighborSeen(npc(gnrm)->getNeighbor(i), npc(gnrm)->getLastSeen(i));

    } else {
        if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Unknown response in neighbor continuation: "_j)->append(static_cast< ::java::lang::Object* >(o))
                ->append(u" -- discarded"_j)->toString());

    }
}

void rice::p2p::glacier::v2::GlacierImpl_startup_2::receiveException(::java::lang::Exception* e)
{
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(GlacierImpl_this->logger)->logException(u"Exception in neighbor continuation: "_j, e);

    terminate();
}

void rice::p2p::glacier::v2::GlacierImpl_startup_2::timeoutExpired()
{
    nextTimeout = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() + GlacierImpl_this->expireNeighborsInterval;
    auto const earliestAcceptableDate = npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis() - GlacierImpl_this->neighborTimeout;
    auto allNeighbors = npc(GlacierImpl_this->neighborStorage)->scan();
    auto iter = npc(allNeighbors)->getIterator();
    auto leafSet = npc(GlacierImpl_this->endpoint)->neighborSet(999);
    if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(GlacierImpl_this->logger)->log(u"Checking neighborhood for expired certificates..."_j);

    while (npc(iter)->hasNext()) {
        auto const thisNeighbor = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(iter)->next()));
        if(npc(leafSet)->memberHandle(thisNeighbor)) {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"CNE: Refreshing current neighbor: "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))->toString());

            GlacierImpl_this->neighborSeen(thisNeighbor, npc(npc(GlacierImpl_this->environment)->getTimeSource())->currentTimeMillis());
        } else {
            if(npc(GlacierImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(GlacierImpl_this->logger)->log(::java::lang::StringBuilder().append(u"CNE: Retrieving "_j)->append(static_cast< ::java::lang::Object* >(thisNeighbor))->toString());

            npc(GlacierImpl_this->neighborStorage)->getObject(thisNeighbor, new GlacierImpl_startup_2_timeoutExpired_2_1(this, thisNeighbor, earliestAcceptableDate));
        }
    }
    GlacierImpl_this->determineResponsibleRange();
}

int64_t rice::p2p::glacier::v2::GlacierImpl_startup_2::getTimeout()
{
    return nextTimeout;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::GlacierImpl_startup_2::getClass0()
{
    return class_();
}

