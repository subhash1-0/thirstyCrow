// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/networkinfo/NetworkInfoTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/networkinfo/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/networkinfo/InetSocketAddressLookup.hpp>
#include <org/mpisws/p2p/transport/networkinfo/Prober.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <java/net/InetSocketAddress.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::networkinfo::NetworkInfoTransportLayer
    : public virtual ::java::lang::Object
    , public virtual InetSocketAddressLookup
    , public virtual Prober
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    static constexpr int8_t HEADER_PASSTHROUGH_BYTE { int8_t(0) };
    static constexpr int8_t HEADER_IP_ADDRESS_REQUEST_BYTE { int8_t(1) };
    static constexpr int8_t HEADER_PROBE_REQUEST_BYTE { int8_t(2) };
    static constexpr int8_t HEADER_PROBE_RESPONSE_BYTE { int8_t(3) };
    static constexpr int8_t HEADER_NODES_REQUEST_BYTE { int8_t(4) };
    static constexpr int8_t HEADER_ID_REQUEST_BYTE { int8_t(5) };

private:
    static ::int8_tArray* HEADER_PASSTHROUGH_;
    static ::int8_tArray* HEADER_IP_ADDRESS_REQUEST_;
    static ::int8_tArray* HEADER_NODES_REQUEST_;

public: /* package */
    ::java::util::Map* serializedIds {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);

public: /* package */
    ::org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer* addrSerializer {  };

public:
    ::rice::p2p::commonapi::Cancellable* getMyInetAddress(::java::net::InetSocketAddress* bootstrap, ::rice::Continuation* c, ::java::util::Map* options) override;
    virtual void setId(int8_t index, ::int8_tArray* value);
    virtual ::rice::p2p::commonapi::Cancellable* getId(::java::net::InetSocketAddress* bootstrap, int8_t index, ::rice::Continuation* c, ::java::util::Map* options);
    ::rice::p2p::commonapi::Cancellable* getExternalNodes(::java::net::InetSocketAddress* bootstrap, ::rice::Continuation* c, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::net::InetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::net::InetSocketAddress* i, ::int8_tArray* header, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void handleIpRequest(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;
    virtual void handleNodesRequest(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;
    virtual void handleIdRequest(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;
    virtual void handleProbeRequest(::org::mpisws::p2p::transport::P2PSocket* socket);
    virtual void handleProbeResponse(::org::mpisws::p2p::transport::P2PSocket* socket);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::net::InetSocketAddress* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual void messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    void destroy() override;

public: /* protected */
    ProbeStrategy* probeStrategy {  };

public:
    virtual void setProbeStrategy(ProbeStrategy* probeStrategy);

public: /* package */
    ::java::util::Map* verifyConnectionRequests {  };

public:
    ::rice::p2p::commonapi::Cancellable* verifyConnectivity(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::java::net::InetSocketAddress* probeAddress, ConnectivityResult* deliverResultToMe, ::java::util::Map* options) override;
    ::rice::p2p::commonapi::Cancellable* probe(::java::net::InetSocketAddress* addr, int64_t uid, ::rice::Continuation* deliverResponseToMe, ::java::util::Map* options) override;

    // Generated
    NetworkInfoTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);
protected:
    NetworkInfoTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

public: /* protected */
    static ::int8_tArray*& HEADER_PASSTHROUGH();
    static ::int8_tArray*& HEADER_IP_ADDRESS_REQUEST();
    static ::int8_tArray*& HEADER_NODES_REQUEST();

private:
    virtual ::java::lang::Class* getClass0();
    friend class NetworkInfoTransportLayer_getMyInetAddress_1;
    friend class NetworkInfoTransportLayer_getMyInetAddress_1_receiveResult_1_1;
    friend class NetworkInfoTransportLayer_getId_2;
    friend class NetworkInfoTransportLayer_getId_2_receiveResult_2_1;
    friend class NetworkInfoTransportLayer_getExternalNodes_3;
    friend class NetworkInfoTransportLayer_getExternalNodes_3_receiveResult_3_1;
    friend class NetworkInfoTransportLayer_openSocket_4;
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
