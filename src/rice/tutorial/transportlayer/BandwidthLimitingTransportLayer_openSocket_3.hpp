// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportlayer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class rice::tutorial::transportlayer::BandwidthLimitingTransportLayer_openSocket_3
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;

    // Generated
    BandwidthLimitingTransportLayer_openSocket_3(BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* returnMe);
    static ::java::lang::Class *class_();
    BandwidthLimitingTransportLayer *BandwidthLimitingTransportLayer_this;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* returnMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthLimitingTransportLayer;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1;
    friend class BandwidthLimitingTransportLayer_sendMessage_2;
    friend class BandwidthLimitingTransportLayer_BandwidthLimitingSocket;
    friend class BandwidthLimitingTransportLayer_exampleA_4;
    friend class BandwidthLimitingTransportLayer_exampleB_5;
    friend class BandwidthLimitingTransportLayer_exampleB_5_getSourceRouteManagerLayer_5_1;
};
