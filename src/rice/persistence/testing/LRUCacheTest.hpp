// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/Test.hpp>

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
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi
    } // p2p
} // rice

struct default_init_tag;

class rice::persistence::testing::LRUCacheTest
    : public Test
{

public:
    typedef Test super;

public: /* protected */
    static constexpr int32_t CACHE_SIZE { int32_t(100) };

private:
    ::rice::p2p::commonapi::IdFactory* FACTORY {  };
    ::rice::persistence::Cache* cache {  };
    ::rice::p2p::commonapi::IdArray* data {  };
protected:
    void ctor(::rice::environment::Environment* env);

public:
    virtual void setUp(::rice::Continuation* c);

private:
    void testExists(::rice::Continuation* c);
    void testScan(::rice::Continuation* c);
    void testRandomInserts(::rice::Continuation* c);
    void testErrors();

public:
    void start() override;
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    LRUCacheTest(::rice::environment::Environment* env);
protected:
    LRUCacheTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LRUCacheTest_setUp_1;
    friend class LRUCacheTest_setUp_2;
    friend class LRUCacheTest_setUp_3;
    friend class LRUCacheTest_setUp_4;
    friend class LRUCacheTest_testExists_5;
    friend class LRUCacheTest_testScan_6;
    friend class LRUCacheTest_testScan_7;
    friend class LRUCacheTest_testScan_8;
    friend class LRUCacheTest_testRandomInserts_9;
    friend class LRUCacheTest_testRandomInserts_10;
    friend class LRUCacheTest_testRandomInserts_11;
    friend class LRUCacheTest_testRandomInserts_12;
    friend class LRUCacheTest_testRandomInserts_13;
    friend class LRUCacheTest_testErrors_14;
    friend class LRUCacheTest_testErrors_15;
    friend class LRUCacheTest_testErrors_16;
};
