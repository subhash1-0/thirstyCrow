// Generated from /pastry-2.1/src/rice/p2p/replication/manager/testing/ReplicationManagerRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/testing/CommonAPITest.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerClient, ::java::lang::ObjectArray > ReplicationManagerClientArray;
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerImpl, ::java::lang::ObjectArray, ReplicationManagerArray, ::rice::p2p::replication::ReplicationClientArray, ::rice::p2p::commonapi::ApplicationArray > ReplicationManagerImplArray;

                namespace testing
                {
typedef ::SubArray< ::rice::p2p::replication::manager::testing::ReplicationManagerRegrTest_TestReplicationManagerClient, ::java::lang::ObjectArray, ::rice::p2p::replication::manager::ReplicationManagerClientArray > ReplicationManagerRegrTest_TestReplicationManagerClientArray;
                } // testing
            } // manager
        } // replication
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::replication::manager::testing::ReplicationManagerRegrTest
    : public ::rice::p2p::commonapi::testing::CommonAPITest
{

public:
    typedef ::rice::p2p::commonapi::testing::CommonAPITest super;
    static constexpr int32_t REPLICATION_FACTOR { int32_t(3) };

private:
    static ::java::lang::String* INSTANCE_;

public: /* protected */
    ::rice::p2p::replication::manager::ReplicationManagerImplArray* replications {  };
    ReplicationManagerRegrTest_TestReplicationManagerClientArray* clients {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public:
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

public: /* protected */
    void processNode(int32_t num, ::rice::p2p::commonapi::Node* node) override;
    void runTest() override;

public:
    virtual void testBasic();
    virtual void testMaintenance();
    virtual void testOverload();
    virtual void testStress();
    virtual void printValsForRange(::rice::p2p::commonapi::IdRange* range);
    virtual void runMaintenance();

private:
    ::rice::p2p::commonapi::Id* generateId();
    ::rice::p2p::commonapi::Id* addToId(::rice::p2p::commonapi::Id* id, int32_t num);

    // Generated

public:
    ReplicationManagerRegrTest(::rice::environment::Environment* env);
protected:
    ReplicationManagerRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& INSTANCE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationManagerRegrTest_runMaintenance_1;
    friend class ReplicationManagerRegrTest_TestReplicationManagerClient;
};
