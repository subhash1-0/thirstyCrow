// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousApp.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousApp
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::org::mpisws::p2p::transport::rendezvous::RendezvousStrategy
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* protected */
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    ::rice::selector::SelectorManager* selectorManager {  };
    ::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayer* tl {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    virtual void isNatted(::rice::p2p::commonapi::NodeHandle* bootstrap, ::rice::Continuation* receiveResult);
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;
    bool deliverWhenNotReady() override;
    virtual ::rice::p2p::commonapi::Cancellable* openChannel(RendezvousSocketNodeHandle* target, RendezvousSocketNodeHandle* rendezvous, RendezvousSocketNodeHandle* source, int32_t uid, ::rice::Continuation* deliverAckToMe, ::java::util::Map* options);
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(RendezvousSocketNodeHandle* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* ops);
    ::java::lang::String* toString() override;
    void setTransportLayer(::org::mpisws::p2p::transport::rendezvous::RendezvousTransportLayer* tl) override;

    // Generated
    RendezvousApp(::rice::pastry::PastryNode* pn);
protected:
    RendezvousApp(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::rice::p2p::commonapi::Cancellable* openChannel(::java::lang::Object* target, ::java::lang::Object* rendezvous, ::java::lang::Object* source, int32_t uid, ::rice::Continuation* deliverResultToMe, ::java::util::Map* options) override;
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RendezvousApp_RendezvousApp_1;
    friend class RendezvousApp_openChannel_2;
    friend class RendezvousApp_openChannel_3;
    friend class RendezvousApp_openChannel_4;
    friend class RendezvousApp_sendMessage_5;
    friend class RendezvousApp_sendMessage_6;
    friend class RendezvousApp_sendMessage_7;
};
