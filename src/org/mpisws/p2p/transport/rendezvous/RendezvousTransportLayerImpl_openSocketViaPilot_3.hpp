// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_openSocketViaPilot_3
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::SocketCallback
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock) override;
    void receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex) override;

    // Generated
    RendezvousTransportLayerImpl_openSocketViaPilot_3(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::java::nio::ByteBuffer* writeBuffer, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::SocketRequestHandle* handle, int32_t uid, RendezvousContact* dest, RendezvousContact* middleMan, ::java::nio::ByteBuffer* readBuffer, ::java::util::Map* options);
    static ::java::lang::Class *class_();
    RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this;
    ::java::nio::ByteBuffer* writeBuffer;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::SocketRequestHandle* handle;
    int32_t uid;
    RendezvousContact* dest;
    RendezvousContact* middleMan;
    ::java::nio::ByteBuffer* readBuffer;
    ::java::util::Map* options;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousTransportLayerImpl;
    friend class RendezvousTransportLayerImpl_openSocket_1;
    friend class RendezvousTransportLayerImpl_openSocket_1_receiveResult_1_1;
    friend class RendezvousTransportLayerImpl_openSocketUsingRouting_2;
    friend class RendezvousTransportLayerImpl_openSocketViaPilot_3_receiveResult_3_1;
    friend class RendezvousTransportLayerImpl_incomingSocket_4;
    friend class RendezvousTransportLayerImpl_readConnectHeader_5;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_1;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_2;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_3;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_4;
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1;
    friend class RendezvousTransportLayerImpl_sendMessage_8;
    friend class RendezvousTransportLayerImpl_openPilot_9;
    friend class RendezvousTransportLayerImpl_AbstractPilot;
    friend class RendezvousTransportLayerImpl_OutgoingPilot;
    friend class RendezvousTransportLayerImpl_IncomingPilot;
    friend class RendezvousTransportLayerImpl_ByteWriter;
};
