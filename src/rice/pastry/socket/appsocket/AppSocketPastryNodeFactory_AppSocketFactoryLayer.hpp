// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <java/net/InetSocketAddress.hpp>

struct default_init_tag;

class rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_AppSocketFactoryLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl {  };

private:
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
protected:
    void ctor(::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl);

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::net::InetSocketAddress* getLocalIdentifier() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::net::InetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    void destroy() override;

    // Generated
    AppSocketPastryNodeFactory_AppSocketFactoryLayer(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl* wtl);
protected:
    AppSocketPastryNodeFactory_AppSocketFactoryLayer(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;
    AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AppSocketPastryNodeFactory;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1;
    friend class AppSocketPastryNodeFactory_BogusTLPastryNode;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getAppSocket_1_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocketChannel_1_2;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_1;
    friend class AppSocketPastryNodeFactory_getSocketFactory_1_getSocket_1_3_receiveResult_1_3_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getLivenessProvider_2_1;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getOverrideLiveness_2_2;
    friend class AppSocketPastryNodeFactory_getLivenessTransportLayer_2_getPinger_2_3;
};
