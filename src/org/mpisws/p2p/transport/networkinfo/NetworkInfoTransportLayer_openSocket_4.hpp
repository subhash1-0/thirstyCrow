// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer_openSocket_4
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::java::lang::Exception* exception) override;

    // Generated
    NetworkInfoTransportLayer_openSocket_4(NetworkInfoTransportLayer *NetworkInfoTransportLayer_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable, ::int8_tArray* header, ::java::net::InetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe);
    static ::java::lang::Class *class_();
    NetworkInfoTransportLayer *NetworkInfoTransportLayer_this;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* cancellable;
    ::int8_tArray* header;
    ::java::net::InetSocketAddress* i;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class NetworkInfoTransportLayer;
    friend class NetworkInfoTransportLayer_getMyInetAddress_1;
    friend class NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1;
    friend class NetworkInfoTransportLayer_getId_2;
    friend class NetworkInfoTransportLayer_getId_2_receiveResult_2_1;
    friend class NetworkInfoTransportLayer_getExternalNodes_3;
    friend class NetworkInfoTransportLayer_getExternalNodes_3_receiveResult_3_1;
    friend class NetworkInfoTransportLayer_openSocket_4_receiveResult_4_1;
    friend class NetworkInfoTransportLayer_openSocket_4_receiveResult_4_2;
    friend class NetworkInfoTransportLayer_incomingSocket_5;
    friend class NetworkInfoTransportLayer_handleIpRequest_6;
    friend class NetworkInfoTransportLayer_handleNodesRequest_7;
    friend class NetworkInfoTransportLayer_handleIdRequest_8;
    friend class NetworkInfoTransportLayer_handleProbeRequest_9;
    friend class NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1;
    friend class NetworkInfoTransportLayer_handleProbeRequest_9_receiveSelectResult_9_1_returnResult_9_1_1;
    friend class NetworkInfoTransportLayer_handleProbeResponse_10;
    friend class NetworkInfoTransportLayer_sendMessage_11;
    friend class NetworkInfoTransportLayer_verifyConnectivity_12;
    friend class NetworkInfoTransportLayer_verifyConnectivity_13;
    friend class NetworkInfoTransportLayer_verifyConnectivity_13_receiveResult_13_1;
    friend class NetworkInfoTransportLayer_probe_14;
    friend class NetworkInfoTransportLayer_probe_15;
};
