// Generated from /pastry-2.1/src/rice/pastry/testing/LeafSetTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeSetListener.hpp>

struct default_init_tag;

class rice::pastry::testing::LeafSetTest_MyObserver
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeSetListener
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::leafset::LeafSet* ls {  };
protected:
    void ctor(::rice::pastry::leafset::LeafSet* ls);

public:
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* set, ::rice::pastry::NodeHandle* handle, bool added) override;

    // Generated
    LeafSetTest_MyObserver(LeafSetTest *LeafSetTest_this, ::rice::pastry::leafset::LeafSet* ls);
protected:
    LeafSetTest_MyObserver(LeafSetTest *LeafSetTest_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    LeafSetTest *LeafSetTest_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LeafSetTest;
    friend class LeafSetTest_TestNodeHandle;
};
