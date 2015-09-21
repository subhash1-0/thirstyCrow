// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Message.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService_NodeLookupResponse
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Message
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-3200682143184682743LL) };

public: /* protected */
    ::rice::p2p::commonapi::NodeHandleSet* nodes {  };
    int32_t seqno {  };
protected:
    void ctor(::rice::p2p::commonapi::NodeHandleSet* nodes, int32_t seqno);

public:
    int32_t getPriority() override;

    // Generated
    LookupService_NodeLookupResponse(::rice::p2p::commonapi::NodeHandleSet* nodes, int32_t seqno);
protected:
    LookupService_NodeLookupResponse(const ::default_init_tag&);


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
    friend class LookupService_NodeLookupQuery;
    friend class LookupService_NodeLookupTimeoutException;
};
