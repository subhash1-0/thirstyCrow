// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/WireTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/SocketOpeningTransportLayer.hpp>
#include <java/net/InetSocketAddress.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::wire::WireTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual WireTransportLayer
    , public virtual SocketOpeningTransportLayer
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::net::InetSocketAddress* bindAddress {  };
    UDPLayer* udp {  };
    TCPLayer* tcp {  };
    ::rice::environment::logging::Logger* logger {  };
    ::rice::environment::Environment* environment {  };

private:
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };

public: /* protected */
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };

public:
    bool forceBindAddress {  };
protected:
    void ctor(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler) /* throws(IOException) */;
    void ctor(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableServer) /* throws(IOException) */;
    void ctor(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableTCPServer, bool enableUDPServer) /* throws(IOException) */;

public:
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::net::InetSocketAddress* destination, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::net::InetSocketAddress* destination, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::java::net::InetSocketAddress* getLocalIdentifier() override;

public: /* package */
    bool destroyed {  };

public:
    void destroy() override;
    virtual bool isDestroyed();
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;

public: /* protected */
    virtual void messageReceived(::java::net::InetSocketAddress* address, ::java::nio::ByteBuffer* buffer, ::java::util::Map* options) /* throws(IOException) */;
    virtual void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* sm) /* throws(IOException) */;

public: /* package */
    ::java::util::Collection* listeners {  };

public:
    virtual void addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener);
    virtual void removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener);

public: /* protected */
    virtual ::java::lang::Iterable* getTLlisteners();

public: /* package */
    ::java::util::Collection* slisteners {  };

public:
    void addSocketCountListener(::org::mpisws::p2p::transport::SocketCountListener* listener) override;
    void removeSocketCountListener(::org::mpisws::p2p::transport::SocketCountListener* listener) override;

public: /* protected */
    virtual ::java::lang::Iterable* getSlisteners();

public:
    virtual void broadcastChannelOpened(::java::net::InetSocketAddress* addr, ::java::util::Map* options, bool outgoing);
    virtual void broadcastChannelClosed(::java::net::InetSocketAddress* addr, ::java::util::Map* options);

    // Generated
    WireTransportLayerImpl(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);
    WireTransportLayerImpl(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableServer);
    WireTransportLayerImpl(::java::net::InetSocketAddress* bindAddress, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, bool enableTCPServer, bool enableUDPServer);
protected:
    WireTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
};
