// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastImpl.java
#include <rice/p2p/past/gc/GCPastImpl_ReplicaMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>
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

rice::p2p::past::gc::GCPastImpl_ReplicaMap::GCPastImpl_ReplicaMap(GCPastImpl *GCPastImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , GCPastImpl_this(GCPastImpl_this)
{
    clinit();
}

rice::p2p::past::gc::GCPastImpl_ReplicaMap::GCPastImpl_ReplicaMap(GCPastImpl *GCPastImpl_this)
    : GCPastImpl_ReplicaMap(GCPastImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::past::gc::GCPastImpl_ReplicaMap::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::past::gc::GCPastImpl_ReplicaMap::init()
{
    map = new ::java::util::HashMap();
}

void rice::p2p::past::gc::GCPastImpl_ReplicaMap::addReplica(::rice::p2p::commonapi::NodeHandle* handle, GCId* id)
{
    auto set = java_cast< ::rice::p2p::commonapi::IdSet* >(java_cast< ::java::lang::Object* >(npc(map)->get(static_cast< ::java::lang::Object* >(handle))));
    if(set == nullptr) {
        set = new GCIdSet(GCPastImpl_this->realFactory);
        npc(map)->put(static_cast< ::java::lang::Object* >(handle), static_cast< ::java::lang::Object* >(set));
    }
    npc(set)->addId(id);
}

java::util::Iterator* rice::p2p::past::gc::GCPastImpl_ReplicaMap::getReplicas()
{
    return npc(npc(map)->keySet())->iterator();
}

rice::p2p::past::gc::GCIdSet* rice::p2p::past::gc::GCPastImpl_ReplicaMap::getIds(::rice::p2p::commonapi::NodeHandle* replica)
{
    return java_cast< GCIdSet* >(java_cast< ::java::lang::Object* >(npc(map)->get(static_cast< ::java::lang::Object* >(replica))));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCPastImpl_ReplicaMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCPastImpl.ReplicaMap", 38);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCPastImpl_ReplicaMap::getClass0()
{
    return class_();
}

