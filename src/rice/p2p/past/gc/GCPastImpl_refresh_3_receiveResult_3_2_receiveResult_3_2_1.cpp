// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Continuation_NamedContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_2.hpp>
#include <rice/p2p/past/gc/GCPastImpl_ReplicaMap.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/messaging/GCRefreshMessage.hpp>
#include <rice/p2p/past/messaging/PastMessage.hpp>

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

rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1::GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1(GCPastImpl_refresh_3_receiveResult_3_2 *GCPastImpl_refresh_3_receiveResult_3_2_this, ::java::util::Iterator* iterator, GCPastImpl_ReplicaMap* map, ::rice::environment::logging::Logger* logger, GCIdSet* ids, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_refresh_3_receiveResult_3_2_this(GCPastImpl_refresh_3_receiveResult_3_2_this)
    , iterator(iterator)
    , map(map)
    , logger(logger)
    , ids(ids)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1::receiveResult(::java::lang::Object* o)
{
    if(npc(iterator)->hasNext()) {
        auto next = java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::java::lang::Object* >(npc(iterator)->next()));
        auto ids = npc(map)->getIds(next);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"REFRESH: SENDING REQUEST TO "_j)->append(static_cast< ::java::lang::Object* >(next))
                ->append(u" FOR IDSET "_j)
                ->append(static_cast< ::java::lang::Object* >(ids))->toString());

        GCPastImpl_refresh_3_receiveResult_3_2_this->GCPastImpl_refresh_3_this->GCPastImpl_this->sendRequest(next, static_cast< ::rice::p2p::past::messaging::PastMessage* >(new ::rice::p2p::past::gc::messaging::GCRefreshMessage(GCPastImpl_refresh_3_receiveResult_3_2_this->GCPastImpl_refresh_3_this->GCPastImpl_this->getUID(), ids, GCPastImpl_refresh_3_receiveResult_3_2_this->GCPastImpl_refresh_3_this->GCPastImpl_this->getLocalNodeHandle(), npc(next)->getId())), static_cast< ::rice::Continuation* >(new ::rice::Continuation_NamedContinuation(::java::lang::StringBuilder().append(u"GCRefresh to "_j)->append(static_cast< ::java::lang::Object* >(next))->toString(), this)));
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(u"REFRESH: DONE SENDING REQUESTS, RECURSING"_j);

        GCPastImpl_refresh_3_receiveResult_3_2_this->GCPastImpl_refresh_3_this->GCPastImpl_this->refresh(ids, parent);
    }
}

void rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1::receiveException(::java::lang::Exception* e)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"GOT EXCEPTION "_j)->append(static_cast< ::java::lang::Object* >(e))
            ->append(u" REFRESHING ITEMS - CONTINUING"_j)->toString());

    receiveResult(static_cast< ::java::lang::Object* >(nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1::getClass0()
{
    return class_();
}

