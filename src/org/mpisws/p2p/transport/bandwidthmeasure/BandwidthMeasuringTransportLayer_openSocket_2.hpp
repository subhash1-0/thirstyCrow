// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer_openSocket_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;

    // Generated
    BandwidthMeasuringTransportLayer_openSocket_2(BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    BandwidthMeasuringTransportLayer *BandwidthMeasuringTransportLayer_this;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret;
    ::java::lang::Object* i;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BandwidthMeasuringTransportLayer;
    friend class BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1;
    friend class BandwidthMeasuringTransportLayer_MySocket;
};
