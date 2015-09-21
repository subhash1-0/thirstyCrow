// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_BandwidthLimitingSocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket);

public:
    int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ override;

public: /* package */
    ::org::mpisws::p2p::transport::P2PSocketReceiver* storedWriter {  };

public:
    void register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver) override;
    virtual void notifyBandwidthRefilled();
    void close() override;
    void shutdownOutput() override;

    // Generated
    BandwidthLimitingTransportLayer_BandwidthLimitingSocket(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, ::org::mpisws::p2p::transport::P2PSocket* socket);
protected:
    BandwidthLimitingTransportLayer_BandwidthLimitingSocket(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthLimitingTransportLayer;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1;
    friend class BandwidthLimitingTransportLayer_sendMessage_2;
    friend class BandwidthLimitingTransportLayer_openSocket_3;
    friend class BandwidthLimitingTransportLayer_exampleA_4;
    friend class BandwidthLimitingTransportLayer_exampleB_5;
    friend class BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1;
};
