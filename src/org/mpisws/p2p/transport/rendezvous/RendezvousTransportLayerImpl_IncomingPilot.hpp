// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_AbstractPilot.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_IncomingPilot
    : public RendezvousTransportLayerImpl_AbstractPilot
{

public:
    typedef RendezvousTransportLayerImpl_AbstractPilot super;
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket) /* throws(IOException) */;

public: /* protected */
    virtual void requestSocket(RendezvousContact* requestor, int32_t uid) /* throws(IOException) */;
    void read() /* throws(IOException) */ override;

public:
    bool cancel() override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;
    void run() override;

    // Generated
    RendezvousTransportLayerImpl_IncomingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, ::org::mpisws::p2p::transport::P2PSocket* socket);
protected:
    RendezvousTransportLayerImpl_IncomingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

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
    friend class RendezvousTransportLayerImpl_readAcceptHeader_6_receiveSelectResult_6_5;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7;
    friend class RendezvousTransportLayerImpl_openAcceptSocket_7_receiveResult_7_1;
    friend class RendezvousTransportLayerImpl_sendMessage_8;
    friend class RendezvousTransportLayerImpl_openPilot_9;
    friend class RendezvousTransportLayerImpl_AbstractPilot;
    friend class RendezvousTransportLayerImpl_OutgoingPilot;
    friend class RendezvousTransportLayerImpl_ByteWriter;
};
