// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayerImpl_incomingSocket_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* e) override;

    // Generated
    SourceRouteTransportLayerImpl_incomingSocket_2(SourceRouteTransportLayerImpl *SourceRouteTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib, ::org::mpisws::p2p::transport::P2PSocket* socka);
    static ::java::lang::Class *class_();
    SourceRouteTransportLayerImpl *SourceRouteTransportLayerImpl_this;
    ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib;
    ::org::mpisws::p2p::transport::P2PSocket* socka;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SourceRouteTransportLayerImpl;
    friend class SourceRouteTransportLayerImpl_openSocket_1;
    friend class SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class SourceRouteTransportLayerImpl_openSocket_1_receiveResult_1_2;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class SourceRouteTransportLayerImpl_incomingSocket_2_receiveSelectResult_2_1_receiveResult_2_1_1;
    friend class SourceRouteTransportLayerImpl_sendMessage_3;
};
