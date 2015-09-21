// Generated from /pastry-2.1/src/rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.java
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest_runMaintenance_1.hpp>

#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Application.hpp>
#include <rice/p2p/replication/Replication.hpp>
#include <rice/p2p/replication/ReplicationClient.hpp>
#include <rice/p2p/replication/manager/ReplicationManager.hpp>
#include <rice/p2p/replication/manager/ReplicationManagerImpl.hpp>
#include <rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.hpp>
#include <ObjectArray.hpp>
#include <SubArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
        } // commonapi

        namespace replication
        {
typedef ::SubArray< ::rice::p2p::replication::ReplicationClient, ::java::lang::ObjectArray > ReplicationClientArray;

            namespace manager
            {
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManager, ::java::lang::ObjectArray > ReplicationManagerArray;
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerImpl, ::java::lang::ObjectArray, ReplicationManagerArray, ::rice::p2p::replication::ReplicationClientArray, ::rice::p2p::commonapi::ApplicationArray > ReplicationManagerImplArray;
            } // manager
        } // replication
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_runMaintenance_1::ReplicationManagerRegrTest_runMaintenance_1(ReplicationManagerRegrTest *ReplicationManagerRegrTest_this, int32_t j)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationManagerRegrTest_this(ReplicationManagerRegrTest_this)
    , j(j)
{
    clinit();
    ctor();
}

void rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_runMaintenance_1::run()
{
    npc(npc((*ReplicationManagerRegrTest_this->replications)[j])->getReplication())->replicate();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_runMaintenance_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_runMaintenance_1::getClass0()
{
    return class_();
}

