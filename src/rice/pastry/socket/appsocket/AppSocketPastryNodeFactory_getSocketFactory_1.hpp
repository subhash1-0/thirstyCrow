// Generated from /pastry-2.1/src/rice/pastry/socket/appsocket/AppSocketPastryNodeFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/appsocket/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/socket/appsocket/SocketFactory.hpp>

struct default_init_tag;

class rice::pastry::socket::appsocket::AppSocketPastryNodeFactory_getSocketFactory_1
    : public virtual ::java::lang::Object
    , public virtual SocketFactory
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t uid {  };

public:
    ::rice::p2p::commonapi::Cancellable* getAppSocket(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options) override;
    ::rice::p2p::commonapi::Cancellable* getSocketChannel(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options) override;

public: /* protected */
    virtual ::rice::p2p::commonapi::Cancellable* getSocket(::java::net::InetSocketAddress* addr, int32_t appid, ::rice::Continuation* c, ::java::util::Map* options);

public:
    virtual ::rice::pastry::socket::TransportLayerNodeHandle* getHandle(::java::net::InetSocketAddress* addr);
    virtual ::org::mpisws::p2p::transport::TransportLayer* getTL();

    // Generated
    AppSocketPastryNodeFactory_getSocketFactory_1(AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this, ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory, ::rice::pastry::transport::NodeHandleAdapter* nha);
    static ::java::lang::Class *class_();

private:
    void init();
    AppSocketPastryNodeFactory *AppSocketPastryNodeFactory_this;
    ::rice::pastry::socket::SocketNodeHandleFactory* handleFactory;
    ::rice::pastry::transport::NodeHandleAdapter* nha;
    virtual ::java::lang::Class* getClass0();
    friend class AppSocketPastryNodeFactory;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer;
    friend class AppSocketPastryNodeFactory_AppSocketFactoryLayer_openSocket_1;
    friend class AppSocketPastryNodeFactory_BogusTLPastryNode;
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
