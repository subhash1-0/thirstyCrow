// Generated from /pastry-2.1/src/rice/persistence/testing/MemoryStorageTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::persistence::testing::MemoryStorageTest_testRandomInserts_21
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t count {  };

public:
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    MemoryStorageTest_testRandomInserts_21(MemoryStorageTest *MemoryStorageTest_this, int32_t START_NUM, int32_t END_NUM, int32_t SKIP, int32_t NUM_ELEMENTS, ::rice::Continuation* removeRandom);
    static ::java::lang::Class *class_();

private:
    void init();
    MemoryStorageTest *MemoryStorageTest_this;
    int32_t START_NUM;
    int32_t END_NUM;
    int32_t SKIP;
    int32_t NUM_ELEMENTS;
    ::rice::Continuation* removeRandom;
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
