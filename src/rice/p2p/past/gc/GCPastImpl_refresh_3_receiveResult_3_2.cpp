// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Continuation.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl_ReplicaMap.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2::GCPastImpl_refresh_3_receiveResult_3_2(GCPastImpl_refresh_3 *GCPastImpl_refresh_3_this, ::rice::environment::logging::Logger* logger, GCPastImpl_ReplicaMap* map, GCIdSet* ids, ::rice::Continuation* continuation)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_refresh_3_this(GCPastImpl_refresh_3_this)
    , logger(logger)
    , map(map)
    , ids(ids)
{
    clinit();
    ctor(continuation);
}

void rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2::receiveResult(::java::lang::Object* o)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"REFRESH: BACK ON NORMAL THREAD!"_j);

    auto const iterator = npc(map)->getReplicas();
    ::rice::Continuation* send = new GCPastImpl_refresh_3_receiveResult_3_2_receiveResult_3_2_1(this, iterator, map, logger, ids, parent);
    npc(send)->receiveResult(nullptr);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3_receiveResult_3_2::getClass0()
{
    return class_();
}

