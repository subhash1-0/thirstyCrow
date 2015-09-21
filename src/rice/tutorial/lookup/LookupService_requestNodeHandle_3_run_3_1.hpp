// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService_requestNodeHandle_3_run_3_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::rice::p2p::commonapi::NodeHandleSet* result);

    // Generated
    LookupService_requestNodeHandle_3_run_3_1(LookupService_requestNodeHandle_3 *LookupService_requestNodeHandle_3_this, ::rice::Continuation* cont);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    LookupService_requestNodeHandle_3 *LookupService_requestNodeHandle_3_this;
    ::rice::Continuation* cont;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupService;
    friend class LookupService_requestNodeHandles_1;
    friend class LookupService_sendMessageWithRetries_2;
    friend class LookupService_requestNodeHandle_3;
    friend class LookupService_NodeLookupTimeout;
    friend class LookupService_NodeLookupQuery;
    friend class LookupService_NodeLookupResponse;
    friend class LookupService_NodeLookupTimeoutException;
};
