// Generated from /pastry-2.1/src/rice/p2p/replication/testing/ReplicationRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/testing/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::rice::Destructable, ::java::lang::ObjectArray > DestructableArray;

    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Application, ::java::lang::ObjectArray > ApplicationArray;
        } // commonapi

        namespace replication
        {
typedef ::SubArray< ::rice::p2p::replication::Replication, ::java::lang::ObjectArray > ReplicationArray;
typedef ::SubArray< ::rice::p2p::replication::ReplicationClient, ::java::lang::ObjectArray > ReplicationClientArray;
typedef ::SubArray< ::rice::p2p::replication::ReplicationImpl, ::java::lang::ObjectArray, ReplicationArray, ::rice::p2p::commonapi::ApplicationArray, ::rice::DestructableArray > ReplicationImplArray;

            namespace testing
            {
typedef ::SubArray< ::rice::p2p::replication::testing::ReplicationRegrTest_TestReplicationClient, ::java::lang::ObjectArray, ::rice::p2p::replication::ReplicationClientArray > ReplicationRegrTest_TestReplicationClientArray;
            } // testing
        } // replication
    } // p2p
} // rice

struct default_init_tag;

class rice::p2p::replication::testing::ReplicationRegrTest
    : public ::rice::p2p::commonapi::testing::CommonAPITest
{

public:
    typedef ::rice::p2p::commonapi::testing::CommonAPITest super;
    static constexpr int32_t REPLICATION_FACTOR { int32_t(3) };

private:
    static ::java::lang::String* INSTANCE_;

public: /* protected */
    ::rice::p2p::replication::ReplicationImplArray* replications {  };
    ReplicationRegrTest_TestReplicationClientArray* clients {  };
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
    virtual void runMaintenance();

private:
    ::rice::p2p::commonapi::Id* generateId();

    // Generated

public:
    ReplicationRegrTest(::rice::environment::Environment* env);
protected:
    ReplicationRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::lang::String*& INSTANCE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class ReplicationRegrTest_TestReplicationClient;
};
