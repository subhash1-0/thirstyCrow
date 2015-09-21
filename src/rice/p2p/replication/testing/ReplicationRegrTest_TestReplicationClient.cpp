// Generated from /pastry-2.1/src/rice/p2p/replication/testing/ReplicationRegrTest.java
#include <rice/p2p/replication/testing/ReplicationRegrTest_TestReplicationClient.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <rice/Continuation_ListenerContinuation.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/replication/testing/ReplicationRegrTest.hpp>
#include <rice/persistence/MemoryStorage.hpp>

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

rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::ReplicationRegrTest_TestReplicationClient(ReplicationRegrTest *ReplicationRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationRegrTest_this(ReplicationRegrTest_this)
{
    clinit();
}

rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::ReplicationRegrTest_TestReplicationClient(ReplicationRegrTest *ReplicationRegrTest_this, ::rice::p2p::commonapi::Node* node) 
    : ReplicationRegrTest_TestReplicationClient(ReplicationRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->storage = new ::rice::persistence::MemoryStorage(ReplicationRegrTest_this->FACTORY);
    this->node = node;
}

void rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::fetch(::rice::p2p::commonapi::IdSet* keySet, ::rice::p2p::commonapi::NodeHandle* hint)
{
    auto i = npc(keySet)->getIterator();
    while (npc(i)->hasNext()) {
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        npc(storage)->store(next, static_cast< ::java::io::Serializable* >(nullptr), static_cast< ::java::io::Serializable* >(next), static_cast< ::rice::Continuation* >(new ::rice::Continuation_ListenerContinuation(::java::lang::StringBuilder().append(u"Insertion of "_j)->append(static_cast< ::java::lang::Object* >(next))->toString(), ReplicationRegrTest_this->environment)));
    }
}

void rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::setRange(::rice::p2p::commonapi::IdRange* range)
{
    auto notRange = npc(range)->getComplementRange();
    auto set = npc(storage)->scan(notRange);
    auto i = npc(set)->getIterator();
    while (npc(i)->hasNext()) {
        auto next = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(i)->next()));
        npc(storage)->unstore(next, static_cast< ::rice::Continuation* >(new ::rice::Continuation_ListenerContinuation(::java::lang::StringBuilder().append(u"Removal of "_j)->append(static_cast< ::java::lang::Object* >(next))->toString(), ReplicationRegrTest_this->environment)));
    }
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(storage)->scan(range);
}

void rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::insert(::rice::p2p::commonapi::Id* id)
{
    npc(storage)->store(id, static_cast< ::java::io::Serializable* >(nullptr), static_cast< ::java::io::Serializable* >(id), static_cast< ::rice::Continuation* >(new ::rice::Continuation_ListenerContinuation(::java::lang::StringBuilder().append(u"Insertion of id "_j)->append(static_cast< ::java::lang::Object* >(id))->toString(), ReplicationRegrTest_this->environment)));
}

java::lang::String* rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::toString()
{
    return ::java::lang::StringBuilder().append(u"TestRepClient "_j)->append(npc(node)->toString())->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.testing.ReplicationRegrTest.TestReplicationClient", 70);
    return c;
}

java::lang::Class* rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient::getClass0()
{
    return class_();
}

