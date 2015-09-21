// Generated from /pastry-2.1/src/rice/pastry/leafset/testing/MergeTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/testing/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeSetListener.hpp>

struct default_init_tag;

class rice::pastry::leafset::testing::MergeTest_main_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeSetListener
{

public:
    typedef ::java::lang::Object super;
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added) override;

    // Generated
    MergeTest_main_2();
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MergeTest;
    friend class MergeTest_main_1;
    friend class MergeTest_TestNodeHandle;
};
