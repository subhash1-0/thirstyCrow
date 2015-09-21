// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupServiceTest.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupServiceTest_LookupServiceTest_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::rice::p2p::commonapi::NodeHandleSet* result);

    // Generated
    LookupServiceTest_LookupServiceTest_1(LookupServiceTest *LookupServiceTest_this, ::rice::pastry::Id* id);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    LookupServiceTest *LookupServiceTest_this;
    ::rice::pastry::Id* id;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupServiceTest;
};
