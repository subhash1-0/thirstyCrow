// Generated from /pastry-2.1/src/rice/pastry/testing/LeafSetTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <java/lang/Comparable.hpp>

struct default_init_tag;

class rice::pastry::testing::LeafSetTest_TestNodeHandle
    : public ::rice::pastry::NodeHandle
    , public virtual ::java::lang::Comparable
{

public:
    typedef ::rice::pastry::NodeHandle super;

private:
    ::rice::pastry::Id* id {  };
protected:
    void ctor(::rice::pastry::Id* id);

public:
    ::rice::pastry::Id* getNodeId() override;
    int32_t getLiveness() override;
    int32_t proximity() override;
    bool ping() override;
    bool equals(::java::lang::Object* obj) override;
    int32_t hashCode() override;
    void receiveMessage(::rice::pastry::messaging::Message* m) override;
    virtual int32_t compareTo(LeafSetTest_TestNodeHandle* o);
    ::java::lang::String* toString() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    LeafSetTest_TestNodeHandle(::rice::pastry::Id* id);
protected:
    LeafSetTest_TestNodeHandle(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int32_t compareTo(::java::lang::Object* o) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LeafSetTest;
    friend class LeafSetTest_MyObserver;
};
