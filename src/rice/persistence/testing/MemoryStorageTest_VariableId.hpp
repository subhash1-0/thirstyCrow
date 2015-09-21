// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Id.hpp>

struct default_init_tag;

class rice::persistence::testing::MemoryStorageTest_VariableId
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Id
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(4893) };

public: /* protected */
    int32_t num {  };

private:
    static ::java::lang::String* STRING_;
protected:
    void ctor(int32_t num);

public:
    bool isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw) override;
    bool clockwise(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id* addToId(::rice::p2p::commonapi::Id_Distance* offset) override;
    ::rice::p2p::commonapi::Id_Distance* distanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::rice::p2p::commonapi::Id_Distance* longDistanceFromId(::rice::p2p::commonapi::Id* nid) override;
    ::int8_tArray* toByteArray_() override;
    void toByteArray_(::int8_tArray* array, int32_t offset) override;
    int32_t getByteArrayLength() override;
    ::java::lang::String* toStringFull() override;
    virtual int32_t compareTo(::rice::p2p::commonapi::Id* o);
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;

    // Generated
    MemoryStorageTest_VariableId(MemoryStorageTest *MemoryStorageTest_this, int32_t num);
protected:
    MemoryStorageTest_VariableId(MemoryStorageTest *MemoryStorageTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    virtual int32_t compareTo(::java::lang::Object* arg0) override;
    MemoryStorageTest *MemoryStorageTest_this;
    static ::java::lang::String*& STRING();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MemoryStorageTest;
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
};
