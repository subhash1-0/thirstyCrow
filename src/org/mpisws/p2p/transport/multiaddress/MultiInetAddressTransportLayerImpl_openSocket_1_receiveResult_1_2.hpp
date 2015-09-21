// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;

    // Generated
    MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2(MultiInetAddressTransportLayerImpl_openSocket_1 *MultiInetAddressTransportLayerImpl_openSocket_1_this, ::java::nio::ByteBuffer* b, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, MultiInetSocketAddress* i);
    static ::java::lang::Class *class_();
    MultiInetAddressTransportLayerImpl_openSocket_1 *MultiInetAddressTransportLayerImpl_openSocket_1_this;
    ::java::nio::ByteBuffer* b;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle;
    MultiInetSocketAddress* i;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiInetAddressTransportLayerImpl;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class MultiInetAddressTransportLayerImpl_incomingSocket_2;
    friend class MultiInetAddressTransportLayerImpl_sendMessage_3;
};
