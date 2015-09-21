// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_sendMessage_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason) override;

    // Generated
    BandwidthLimitingTransportLayer_sendMessage_2(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* returnMe);
    static ::java::lang::Class *class_();
    BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* returnMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthLimitingTransportLayer;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1;
    friend class BandwidthLimitingTransportLayer_openSocket_3;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingSocket;
    friend class BandwidthLimitingTransportLayer_exampleA_4;
    friend class BandwidthLimitingTransportLayer_exampleB_5;
    friend class BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1;
};
