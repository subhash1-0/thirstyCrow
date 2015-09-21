// Generated from /pastry-2.1/src/rice/tutorial/lookup/LookupService.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/tutorial/lookup/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Application.hpp>

struct default_init_tag;

class rice::tutorial::lookup::LookupService
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Application
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::p2p::commonapi::Endpoint* endpoint {  };
    int32_t seqno {  };
    ::java::util::HashMap* pending {  };
    int64_t timeout {  };
    ::rice::environment::logging::Logger* logger {  };
    int64_t firstTimeout {  };
protected:
    void ctor(::rice::p2p::commonapi::Node* node, int64_t timeout);
    void ctor(::rice::p2p::commonapi::Node* node);

public:
    bool forward(::rice::p2p::commonapi::RouteMessage* message) override;
    void deliver(::rice::p2p::commonapi::Id* id, ::rice::p2p::commonapi::Message* message) override;
    void update(::rice::p2p::commonapi::NodeHandle* handle, bool joined) override;
    virtual void requestNodeHandles(::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont);

public: /* protected */
    virtual void sendMessageWithRetries(::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont);
    virtual void sendMessage(int32_t seq, ::rice::p2p::commonapi::Id* id, int32_t num, ::rice::Continuation* cont, int64_t timeout);

public:
    virtual void requestNodeHandle(::rice::p2p::commonapi::Id* id, ::rice::Continuation* cont);

    // Generated
    LookupService(::rice::p2p::commonapi::Node* node, int64_t timeout);
    LookupService(::rice::p2p::commonapi::Node* node);
protected:
    LookupService(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LookupService_requestNodeHandles_1;
    friend class LookupService_sendMessageWithRetries_2;
    friend class LookupService_requestNodeHandle_3;
    friend class LookupService_requestNodeHandle_3_run_3_1;
    friend class LookupService_NodeLookupTimeout;
    friend class LookupService_NodeLookupQuery;
    friend class LookupService_NodeLookupResponse;
    friend class LookupService_NodeLookupTimeoutException;
};
