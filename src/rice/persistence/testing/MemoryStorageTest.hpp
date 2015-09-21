// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java

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
typedef ::SubArray< ::java::lang::Number, ObjectArray, ::java::io::SerializableArray > NumberArray;
typedef ::SubArray< ::java::lang::Integer, NumberArray, ComparableArray > IntegerArray;
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

class rice::persistence::testing::MemoryStorageTest
    : public Test
{

public:
    typedef Test super;

private:
    ::rice::p2p::commonapi::IdFactory* FACTORY {  };

public: /* protected */
    ::rice::persistence::Storage* storage {  };
    bool store {  };

private:
    ::rice::p2p::commonapi::IdArray* data {  };
    ::java::lang::IntegerArray* metadata {  };
protected:
    void ctor(bool store, ::rice::environment::Environment* env);

public:
    virtual void setUp(::rice::Continuation* c);
    virtual void testRetreival(::rice::Continuation* c);
    virtual void testExists(::rice::Continuation* c);

private:
    void testRemoval(::rice::Continuation* c);
    void testScan(::rice::Continuation* c);
    void testRandomInserts(::rice::Continuation* c);
    void testErrors(::rice::Continuation* c);

public:
    virtual void testVariableLength();
    void start() override;
    static void main(::java::lang::StringArray* args) /* throws(IOException) */;

    // Generated
    MemoryStorageTest(bool store, ::rice::environment::Environment* env);
protected:
    MemoryStorageTest(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MemoryStorageTest_setUp_1;
    friend class MemoryStorageTest_setUp_2;
    friend class MemoryStorageTest_setUp_3;
    friend class MemoryStorageTest_setUp_4;
    friend class MemoryStorageTest_testRetreival_5;
    friend class MemoryStorageTest_testRetreival_6;
    friend class MemoryStorageTest_testRetreival_7;
    friend class MemoryStorageTest_testRetreival_8;
    friend class MemoryStorageTest_testRetreival_9;
    friend class MemoryStorageTest_testRetreival_10;
    friend class MemoryStorageTest_testExists_11;
    friend class MemoryStorageTest_testExists_11_receiveResult_11_1;
    friend class MemoryStorageTest_testRemoval_12;
    friend class MemoryStorageTest_testRemoval_13;
    friend class MemoryStorageTest_testRemoval_14;
    friend class MemoryStorageTest_testRemoval_15;
    friend class MemoryStorageTest_testScan_16;
    friend class MemoryStorageTest_testScan_17;
    friend class MemoryStorageTest_testScan_18;
    friend class MemoryStorageTest_testRandomInserts_19;
    friend class MemoryStorageTest_testRandomInserts_20;
    friend class MemoryStorageTest_testRandomInserts_21;
    friend class MemoryStorageTest_testRandomInserts_22;
    friend class MemoryStorageTest_testRandomInserts_23;
    friend class MemoryStorageTest_testErrors_24;
    friend class MemoryStorageTest_testErrors_25;
    friend class MemoryStorageTest_testErrors_26;
    friend class MemoryStorageTest_testVariableLength_27;
    friend class MemoryStorageTest_testVariableLength_27_receiveResult_27_1;
    friend class MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1;
    friend class MemoryStorageTest_testVariableLength_27_receiveResult_27_1_receiveResult_27_1_1_receiveResult_27_1_1_1;
    friend class MemoryStorageTest_VariableId;
};
