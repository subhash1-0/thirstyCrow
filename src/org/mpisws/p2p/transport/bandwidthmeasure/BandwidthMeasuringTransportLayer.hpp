// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::TransportLayer* tl {  };
    ::org::mpisws::p2p::transport::TransportLayerCallback* callback {  };
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::ErrorHandler* errorHandler {  };
    int32_t measurementPeriod {  };

public:
    static constexpr int32_t CUR_DOWN { int32_t(0) };
    static constexpr int32_t CUR_UP { int32_t(1) };
    static constexpr int32_t CUR_SATURATED { int32_t(2) };
    static constexpr int32_t LAST_DOWN { int32_t(3) };
    static constexpr int32_t LAST_UP { int32_t(4) };
    static constexpr int32_t LAST_SATURATED { int32_t(5) };
    static constexpr int32_t NUM_VALS { int32_t(6) };
    static constexpr int32_t SATURATED { int32_t(1) };
    static constexpr int32_t NOT_SATURATED { int32_t(0) };

public: /* package */
    ::java::util::Map* measured {  };

public: /* protected */
    ::rice::environment::time::TimeSource* time {  };
protected:
    void ctor(int32_t measurementPeriod, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);

public: /* package */
    int64_t lastMeasure {  };

public: /* protected */
    virtual void measure();

public:
    virtual ::rice::p2p::util::tuples::Tuple* getVals(::java::lang::Object* i);
    virtual ::java::util::Map* getBandwidthUsed();
    void incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */ override;
    virtual void messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options);
    ::org::mpisws::p2p::transport::SocketRequestHandle* openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options) override;
    void acceptMessages(bool b) override;
    void acceptSockets(bool b) override;
    ::java::lang::Object* getLocalIdentifier() override;
    void setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback) override;
    void setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler) override;
    void destroy() override;

    // Generated
    BandwidthMeasuringTransportLayer(int32_t measurementPeriod, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env);
protected:
    BandwidthMeasuringTransportLayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1;
    friend class BandwidthMeasuringTransportLayer_MySocket;
    friend class BandwidthMeasuringTransportLayer_openSocket_2;
};
