// Generated from /pastry-2.1/src/rice/p2p/past/testing/RawPastRegrTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/testing/fwd-pastry-2.1.hpp>
#include <rice/p2p/replication/manager/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
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

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::Past, ::java::lang::ObjectArray > PastArray;
        } // past

        namespace replication
        {
            namespace manager
            {
typedef ::SubArray< ::rice::p2p::replication::manager::ReplicationManagerClient, ::java::lang::ObjectArray > ReplicationManagerClientArray;
            } // manager
        } // replication

        namespace past
        {
typedef ::SubArray< ::rice::p2p::past::PastImpl, ::java::lang::ObjectArray, PastArray, ::rice::p2p::commonapi::ApplicationArray, ::rice::p2p::replication::manager::ReplicationManagerClientArray > PastImplArray;
        } // past
    } // p2p

    namespace persistence
    {
typedef ::SubArray< ::rice::persistence::Catalog, ::java::lang::ObjectArray > CatalogArray;
typedef ::SubArray< ::rice::persistence::Cache, ::java::lang::ObjectArray, CatalogArray > CacheArray;
typedef ::SubArray< ::rice::persistence::Storage, ::java::lang::ObjectArray, CatalogArray > StorageArray;
typedef ::SubArray< ::rice::persistence::StorageManager, ::java::lang::ObjectArray, CacheArray, StorageArray > StorageManagerArray;
    } // persistence
} // rice

struct default_init_tag;

class rice::p2p::past::testing::RawPastRegrTest
    : public ::rice::p2p::commonapi::testing::CommonAPITest
{

public:
    typedef ::rice::p2p::commonapi::testing::CommonAPITest super;

private:
    static ::java::lang::String* INSTANCE_;

public:
    static constexpr int32_t REPLICATION_FACTOR { int32_t(3) };

public: /* protected */
    ::rice::persistence::StorageManagerArray* storages {  };
    ::rice::p2p::past::PastImplArray* pasts {  };
    bool running {  };
protected:
    void ctor(::rice::environment::Environment* env) /* throws(IOException) */;

public: /* protected */
    void processNode(int32_t num, ::rice::p2p::commonapi::Node* node) override;
    void runTest() override;
    virtual void testRouteRequest();
    virtual void testVersionControl();
    virtual void testFetch();
    virtual void testLookupHandles();
    virtual void testCaching();

private:
    void runReplicaMaintence();
    ::rice::p2p::commonapi::Id* generateId();

public:
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

public: /* protected */
    virtual void cleanUp();

    // Generated

public:
    RawPastRegrTest(::rice::environment::Environment* env);
protected:
    RawPastRegrTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static ::java::lang::String*& INSTANCE();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RawPastRegrTest_RawPastRegrTest_1;
    friend class RawPastRegrTest_processNode_2;
    friend class RawPastRegrTest_processNode_3;
    friend class RawPastRegrTest_testRouteRequest_4;
    friend class RawPastRegrTest_testRouteRequest_4_receive_4_1;
    friend class RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1;
    friend class RawPastRegrTest_testRouteRequest_4_receive_4_1_receive_4_1_1_receive_4_1_1_1;
    friend class RawPastRegrTest_testVersionControl_5;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1_receive_5_1_1_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1_receive_5_1_1_1_receive_5_1_1_1_1;
    friend class RawPastRegrTest_testVersionControl_5_receive_5_1_receive_5_1_1_receive_5_1_1_1_receive_5_1_1_1_1_receive_5_1_1_1_1_1;
    friend class RawPastRegrTest_testFetch_6;
    friend class RawPastRegrTest_testFetch_6_receive_6_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1;
    friend class RawPastRegrTest_testFetch_6_receive_6_1_receive_6_1_1_receive_6_1_1_1_receive_6_1_1_1_1_receive_6_1_1_1_1_1;
    friend class RawPastRegrTest_testLookupHandles_7;
    friend class RawPastRegrTest_testLookupHandles_7_receive_7_1;
    friend class RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1;
    friend class RawPastRegrTest_testLookupHandles_7_receive_7_1_receive_7_1_1_receive_7_1_1_1;
    friend class RawPastRegrTest_testCaching_8;
    friend class RawPastRegrTest_testCaching_8_receive_8_1;
    friend class RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1;
    friend class RawPastRegrTest_testCaching_8_receive_8_1_receive_8_1_1_receive_8_1_1_1;
    friend class RawPastRegrTest_TestCommand;
    friend class RawPastRegrTest_TestExceptionCommand;
    friend class RawPastRegrTest_TestPastContent;
    friend class RawPastRegrTest_VersionedTestPastContent;
    friend class RawPastRegrTest_NonOverwritingTestPastContent;
    friend class RawPastRegrTest_NonMutableTestPastContent;
    friend class RawPastRegrTest_TestPastContentHandle;
    friend class RawPastRegrTest_TestRouteMessage;
};
