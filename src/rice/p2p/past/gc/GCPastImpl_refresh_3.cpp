// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_refresh_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandleSet.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl_refresh_3_receiveResult_3_2.hpp>
#include <rice/p2p/past/gc/GCPastImpl_ReplicaMap.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>

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

rice::p2p::past::gc::GCPastImpl_refresh_3::GCPastImpl_refresh_3(GCPastImpl *GCPastImpl_this, ::rice::environment::logging::Logger* logger, ::rice::p2p::commonapi::IdArray* array, GCIdSet* ids, ::java::lang::String* name, ::rice::Continuation* command)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
    , logger(logger)
    , array(array)
    , ids(ids)
{
    clinit();
    ctor(name, command);
}

void rice::p2p::past::gc::GCPastImpl_refresh_3::receiveResult(::java::lang::Object* o)
{
    auto const set = java_cast< ::rice::p2p::commonapi::NodeHandleSet* >(o);
    auto const map = new GCPastImpl_ReplicaMap(GCPastImpl_this);
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"REFRESH: GOT "_j)->append(static_cast< ::java::lang::Object* >(set))
            ->append(u" SET OF HANDLES!"_j)->toString());

    npc(GCPastImpl_this->endpoint)->process(new GCPastImpl_refresh_3_receiveResult_3_1(this, logger, array, set, map, ids), new GCPastImpl_refresh_3_receiveResult_3_2(this, logger, map, ids, parent));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_refresh_3::getClass0()
{
    return class_();
}

