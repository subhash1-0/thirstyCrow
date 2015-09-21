// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
{

public:
    typedef ::java::lang::Object super;
    bool cancel() override;

    // Generated
    SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1(SourceRouteTransportLayerImpl_openSocket_1 *SourceRouteTransportLayerImpl_openSocket_1_this, ::org::mpisws::p2p::transport::P2PSocket* result);
    static ::java::lang::Class *class_();
    SourceRouteTransportLayerImpl_openSocket_1 *SourceRouteTransportLayerImpl_openSocket_1_this;
    ::org::mpisws::p2p::transport::P2PSocket* result;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteTransportLayerImpl;
    friend class SourceRouteTransportLayerImpl_openSocket_1;
    friend class SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_2;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1;
    friend class SourceRouteTransportLayerImpl_sendMessage_3;
};
