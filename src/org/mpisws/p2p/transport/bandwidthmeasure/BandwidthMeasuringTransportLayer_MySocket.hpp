// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_MySocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;
    void close() override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;
    virtual bool wantsToWrite();
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
protected:
    void ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options);

public:
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;
    int64_t read(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;

    // Generated
    BandwidthMeasuringTransportLayer_MySocket(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this, ::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::java::util::Map* options);
protected:
    BandwidthMeasuringTransportLayer_MySocket(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTransportLayer;
    friend class BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1;
    friend class BandwidthMeasuringTransportLayer_openSocket_2;
};
