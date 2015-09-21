// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual MultiInetAddressTransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t MAX_NUM_ADDRESSES {  };
    ::org::mpisws::p2p::transport::TransportLayer* wire {  };
    MultiInetSocketAddress* localAddress {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::rice::environment::logging::Logger* logger {  };
    AddressStrategy* strategy {  };

private:
    bool sendIdentifier {  };
protected:
    void ctor(MultiInetSocketAddress* localAddress, ::org::mpisws::p2p::transport::TransportLayer* wire, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler, AddressStrategy* strategy);

public:
    AddressStrategy* getAddressStrategy() override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(MultiInetSocketAddress* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(MultiInetSocketAddress* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::java::lang::String* toString() override;
    virtual void messageReceived(::java::net::InetSocketAddress* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    MultiInetSocketAddress* getLocalIdentifier() override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    void destroy() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    virtual void setSendIdentifier(bool sendIdentifier);
    virtual bool isSendIdentifier();

    // Generated
    MultiInetAddressTransportLayerImpl(MultiInetSocketAddress* localAddress, ::org::mpisws::p2p::transport::TransportLayer* wire, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* handler, AddressStrategy* strategy);
protected:
    MultiInetAddressTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiInetAddressTransportLayerImpl_openSocket_1;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2;
    friend class MultiInetAddressTransportLayerImpl_incomingSocket_2;
    friend class MultiInetAddressTransportLayerImpl_sendMessage_3;
};
