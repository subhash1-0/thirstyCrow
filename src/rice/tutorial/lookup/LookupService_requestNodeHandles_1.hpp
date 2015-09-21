// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService_requestNodeHandles_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    LookupService_requestNodeHandles_1(LookupService *LookupService_this, ::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont);
    static ::java::lang::Class *class_();
    LookupService *LookupService_this;
    ::rice::p2p::commonapi::Id* id;
    int32_t num;
    ::rice::Continuation* cont;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupService;
    friend class LookupService_sendMessageWithRetries_2;
    friend class LookupService_requestNodeHandle_3;
    friend class LookupService_requestNodeHandle_3_run_3_1;
    friend class LookupService_NodeLookupTimeout;
    friend class LookupService_NodeLookupQuery;
    friend class LookupService_NodeLookupResponse;
    friend class LookupService_NodeLookupTimeoutException;
};
