// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::org::mpisws::p2p::transport::P2PSocket* result);
    void receiveException(::java::lang::Exception* exception) override;

    // Generated
    RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5(RendezvousTransportLayerImpl_readAcceptHeader_6 *RendezvousTransportLayerImpl_readAcceptHeader_6_this, ::org::mpisws::p2p::transport::P2PSocket* acceptorSocket, RendezvousContact* target, RendezvousContact* opener, int32_t uid, ::rice::p2p::util::tuples::MutableTuple* forwardSockets, ::org::mpisws::p2p::transport::P2PSocket* connectorSocket);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    RendezvousTransportLayerImpl_readAcceptHeader_6 *RendezvousTransportLayerImpl_readAcceptHeader_6_this;
    ::org::mpisws::p2p::transport::P2PSocket* acceptorSocket;
    RendezvousContact* target;
    RendezvousContact* opener;
    int32_t uid;
    ::rice::p2p::util::tuples::MutableTuple* forwardSockets;
    ::org::mpisws::p2p::transport::P2PSocket* connectorSocket;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousTransportLayerImpl;
    friend class RendezvousTransportLayerImpl_openSocket_1;
    friend class RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class RendezvousTransportLayerImpl_openSocketUsingRouting_2;
    friend class RendezvousTransportLayerImpl_openSocketViaPilot_3;
    friend class RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1;
    friend class RendezvousTransportLayerImpl_incomingSocket_4;
    friend class RendezvousTransportLayerImpl_readConnectHeader_5;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_3;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1;
    friend class RendezvousTransportLayerImpl_sendMessage_8;
    friend class RendezvousTransportLayerImpl_openPilot_9;
    friend class RendezvousTransportLayerImpl_AbstractPilot;
    friend class RendezvousTransportLayerImpl_OutgoingPilot;
    friend class RendezvousTransportLayerImpl_IncomingPilot;
    friend class RendezvousTransportLayerImpl_ByteWriter;
};
