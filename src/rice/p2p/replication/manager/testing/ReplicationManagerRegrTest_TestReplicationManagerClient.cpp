// Generated from /pastry-2.1/src/rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.java
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest_TestReplicationManagerClient.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/commonapi/Node.hpp>
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::ReplicationManagerRegrTest_TestReplicationManagerClient(ReplicationManagerRegrTest *ReplicationManagerRegrTest_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationManagerRegrTest_this(ReplicationManagerRegrTest_this)
{
    clinit();
}

rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::ReplicationManagerRegrTest_TestReplicationManagerClient(ReplicationManagerRegrTest *ReplicationManagerRegrTest_this, ::rice::p2p::commonapi::Node* node) 
    : ReplicationManagerRegrTest_TestReplicationManagerClient(ReplicationManagerRegrTest_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(node);
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::ctor(::rice::p2p::commonapi::Node* node)
{
    super::ctor();
    this->set = npc(npc(node)->getIdFactory())->buildIdSet();
    this->node = node;
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::fetch(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::NodeHandle* hint, ::rice::Continuation* command)
{
    npc(set)->addId(id);
    npc(command)->receiveResult(new ::java::lang::Boolean(true));
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::remove(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    npc(set)->removeId(id);
    npc(command)->receiveResult(new ::java::lang::Boolean(true));
}

rice::p2p::commonapi::IdSet* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::scan(::rice::p2p::commonapi::IdRange* range)
{
    return npc(set)->subSet(range);
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::insert(::rice::p2p::commonapi::Id* id)
{
    npc(set)->addId(id);
}

bool rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::exists(::rice::p2p::commonapi::Id* id)
{
    return npc(set)->isMemberId(id);
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::existsInOverlay(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    npc(command)->receiveResult(::java::lang::Boolean::TRUE());
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::reInsert(::rice::p2p::commonapi::Id* id, ::rice::Continuation* command)
{
    npc(command)->receiveResult(::java::lang::Boolean::TRUE());
}

java::lang::String* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::toString()
{
    auto s = ::java::lang::StringBuilder().append(u"TRMC:"_j)->append(static_cast< ::java::lang::Object* >(node))->toString();
    return s;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.testing.ReplicationManagerRegrTest.TestReplicationManagerClient", 92);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient::getClass0()
{
    return class_();
}

