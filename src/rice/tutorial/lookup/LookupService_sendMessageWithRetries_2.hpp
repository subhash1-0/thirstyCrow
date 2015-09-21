// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService_sendMessageWithRetries_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int64_t t {  };
    int64_t cum {  };

public:
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::rice::p2p::commonapi::NodeHandleSet* result);

    // Generated
    LookupService_sendMessageWithRetries_2(LookupService *LookupService_this, int32_t seq, ::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont);
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void receiveResult(::java::lang::Object* result) override;
    LookupService *LookupService_this;
    int32_t seq;
    ::rice::p2p::commonapi::Id* id;
    int32_t num;
    ::rice::Continuation* cont;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupService;
    friend class LookupService_requestNodeHandles_1;
    friend class LookupService_requestNodeHandle_3;
    friend class LookupService_requestNodeHandle_3_run_3_1;
    friend class LookupService_NodeLookupTimeout;
    friend class LookupService_NodeLookupQuery;
    friend class LookupService_NodeLookupResponse;
    friend class LookupService_NodeLookupTimeoutException;
};
