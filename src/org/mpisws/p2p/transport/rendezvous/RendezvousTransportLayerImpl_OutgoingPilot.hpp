// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousTransportLayerImpl_AbstractPilot.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousContact.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayerImpl_OutgoingPilot
    : public RendezvousTransportLayerImpl_AbstractPilot
    , public virtual ::org::mpisws::p2p::transport::SocketRequestHandle
{

public:
    typedef RendezvousTransportLayerImpl_AbstractPilot super;

public: /* protected */
    ::org::mpisws::p2p::transport::SocketRequestHandle* cancellable {  };
    ::java::util::Map* options {  };
protected:
    void ctor(RendezvousContact* i, ::java::util::Map* options);

public:
    virtual void init_();
    virtual void receiveException(::java::lang::Exception* ex);
    virtual void setCancellable(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable);
    virtual void setSocket(::org::mpisws::p2p::transport::P2PSocket* socket);
    ::java::lang::String* toString() override;
    virtual bool ping();
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

public: /* protected */
    void read() /* throws(IOException) */ override;

public:
    RendezvousContact* getIdentifier() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;
    void run() override;

    // Generated
    RendezvousTransportLayerImpl_OutgoingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, RendezvousContact* i, ::java::util::Map* options);
protected:
    RendezvousTransportLayerImpl_OutgoingPilot(RendezvousTransportLayerImpl *RendezvousTransportLayerImpl_this, const ::default_init_tag&);


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
    friend class RendezvousTransportLayerImpl_IncomingPilot;
    friend class RendezvousTransportLayerImpl_ByteWriter;
};
