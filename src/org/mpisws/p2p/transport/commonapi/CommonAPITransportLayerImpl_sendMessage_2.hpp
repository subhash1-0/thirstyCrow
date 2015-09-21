// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/commonapi/CommonAPITransportLayerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/commonapi/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::commonapi::CommonAPITransportLayerImpl_sendMessage_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex) override;

    // Generated
    CommonAPITransportLayerImpl_sendMessage_2(CommonAPITransportLayerImpl *CommonAPITransportLayerImpl_this, ::rice::p2p::commonapi::NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe);
    static ::java::lang::Class *class_();
    CommonAPITransportLayerImpl *CommonAPITransportLayerImpl_this;
    ::rice::p2p::commonapi::NodeHandle* i;
    ::rice::p2p::commonapi::rawserialization::RawMessage* m;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class CommonAPITransportLayerImpl;
    friend class CommonAPITransportLayerImpl_CommonAPITransportLayerImpl_1;
};
