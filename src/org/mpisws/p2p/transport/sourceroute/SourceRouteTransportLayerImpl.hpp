// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl
    : public virtual ::java::lang::Object
    , public virtual SourceRouteTransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t MAX_NUM_HOPS {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    ::org::mpisws::p2p::transport::TransportLayer* etl {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
    SourceRoute* localIdentifier {  };
    ::java::util::Collection* taps {  };
    SourceRouteFactory* srFactory {  };
    SourceRouteForwardStrategy* forwardSourceRouteStrategy {  };
protected:
    void ctor(SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* etl, SourceRouteForwardStrategy* fSRs, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);

public:
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(SourceRoute* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options);

public: /* protected */
    virtual void openSocketHelper(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, ::org::mpisws::p2p::transport::P2PSocket* socket, SourceRoute* i);
    virtual void incomingSocketHelper(::org::mpisws::p2p::transport::P2PSocket* socket, SourceRoute* sr) /* throws(IOException) */;

public:
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* socka) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(SourceRoute* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* errorHandler) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    SourceRoute* getLocalIdentifier() override;
    void destroy() override;
    void addSourceRouteTap(SourceRouteTap* tap) override;
    bool removeSourceRouteTap(SourceRouteTap* tap) override;

    // Generated
    SourceRouteTransportLayerImpl(SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* etl, SourceRouteForwardStrategy* fSRs, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler);
protected:
    SourceRouteTransportLayerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteTransportLayerImpl_openSocket_1;
    friend class SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_2;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1;
    friend class SourceRouteTransportLayerImpl_sendMessage_3;
};
