// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_sendMessage_3
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex) override;

    // Generated
    MultiInetAddressTransportLayerImpl_sendMessage_3(MultiInetAddressTransportLayerImpl *MultiInetAddressTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, MultiInetSocketAddress* i);
    static ::java::lang::Class *class_();
    MultiInetAddressTransportLayerImpl *MultiInetAddressTransportLayerImpl_this;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* handle;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    MultiInetSocketAddress* i;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiInetAddressTransportLayerImpl;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2;
    friend class MultiInetAddressTransportLayerImpl_incomingSocket_2;
};
