// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationPolicy.java
#include <rice/p2p/replication/ReplicationPolicy_DefaultReplicationPolicy.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>

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

rice::p2p::replication::ReplicationPolicy_DefaultReplicationPolicy::ReplicationPolicy_DefaultReplicationPolicy(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::ReplicationPolicy_DefaultReplicationPolicy::ReplicationPolicy_DefaultReplicationPolicy()
    : ReplicationPolicy_DefaultReplicationPolicy(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::ReplicationPolicy_DefaultReplicationPolicy::difference(::rice::p2p::commonapi::IdSet* local, ::rice::p2p::commonapi::IdSet* remote, ::rice::p2p::commonapi::IdFactory* factory)
{
    auto result = npc(factory)->buildIdSet();
    auto i = npc(remote)->getIterator();
    while (npc(i)->hasNext()) {
        auto id = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next()));
        if(!npc(local)->isMemberId(id))
            npc(result)->addId(id);

    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationPolicy_DefaultReplicationPolicy::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.ReplicationPolicy.DefaultReplicationPolicy", 63);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationPolicy_DefaultReplicationPolicy::getClass0()
{
    return class_();
}

