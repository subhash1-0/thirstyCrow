// Generated from /pastry-2.1/src/rice/persistence/testing/LRUCacheTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/persistence/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::persistence::testing::LRUCacheTest_setUp_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    LRUCacheTest_setUp_2(LRUCacheTest *LRUCacheTest_this, ::rice::Continuation* put4);
    static ::java::lang::Class *class_();
    LRUCacheTest *LRUCacheTest_this;
    ::rice::Continuation* put4;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LRUCacheTest;
    friend class LRUCacheTest_setUp_1;
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
