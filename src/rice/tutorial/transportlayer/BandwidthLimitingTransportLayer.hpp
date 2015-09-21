// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::BandwidthLimitingTransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
    int32_t BUCKET_SIZE {  };
    int32_t BUCKET_TIME_LIMIT {  };
    int32_t bucket {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
protected:
    void ctor(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t bucketSize, int32_t bucketTimelimit, ::rice::environment::Environment* env);

public:
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };

public:
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;

public: /* package */
    ::java::util::Collection* sockets {  };

public:
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    static ::rice::pastry::PastryNodeFactory* exampleA(int32_t bindport, ::rice::environment::Environment* env, ::rice::pastry::NodeIdFactory* nidFactory, int32_t amt, int32_t time) /* throws(IOException) */;
    static ::rice::pastry::PastryNodeFactory* exampleB(int32_t bindport, ::rice::environment::Environment* env, ::rice::pastry::NodeIdFactory* nidFactory, int32_t amt, int32_t time) /* throws(IOException) */;

    // Generated
    BandwidthLimitingTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t bucketSize, int32_t bucketTimelimit, ::rice::environment::Environment* env);
protected:
    BandwidthLimitingTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1;
    friend class BandwidthLimitingTransportLayer_sendMessage_2;
    friend class BandwidthLimitingTransportLayer_openSocket_3;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingSocket;
    friend class BandwidthLimitingTransportLayer_exampleA_4;
    friend class BandwidthLimitingTransportLayer_exampleB_5;
    friend class BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1;
};
