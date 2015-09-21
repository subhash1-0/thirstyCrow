// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService_NodeLookupQuery
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-4882776401593706141LL) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandle* source {  };
    int32_t numNodes {  };
    int32_t seqno {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandle* localHandle, int32_t num, int32_t seqno);

public:
    int32_t getPriority() override;

    // Generated
    LookupService_NodeLookupQuery(::rice::p2p::commonapi::NodeHandle* localHandle, int32_t num, int32_t seqno);
protected:
    LookupService_NodeLookupQuery(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupService;
    friend class LookupService_requestNodeHandles_1;
    friend class LookupService_sendMessageWithRetries_2;
    friend class LookupService_requestNodeHandle_3;
    friend class LookupService_requestNodeHandle_3_run_3_1;
    friend class LookupService_NodeLookupTimeout;
    friend class LookupService_NodeLookupResponse;
    friend class LookupService_NodeLookupTimeoutException;
};
