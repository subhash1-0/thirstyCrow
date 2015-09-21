// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/LeafSetPilotStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/rendezvous/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/NodeSetListener.hpp>
#include <org/mpisws/p2p/transport/rendezvous/OutgoingPilotListener.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::LeafSetPilotStrategy
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::NodeSetListener
    , public virtual ::org::mpisws::p2p::transport::rendezvous::OutgoingPilotListener
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::leafset::LeafSet* leafSet, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::rice::environment::Environment* env);

public:
    void nodeSetUpdate(::rice::pastry::NodeSetEventSource* nodeSetEventSource, ::rice::pastry::NodeHandle* handle, bool added) override;
    virtual void pilotOpening(::org::mpisws::p2p::transport::rendezvous::RendezvousContact* i);
    virtual void pilotClosed(::org::mpisws::p2p::transport::rendezvous::RendezvousContact* i);

    // Generated
    LeafSetPilotStrategy(::rice::pastry::leafset::LeafSet* leafSet, ::org::mpisws::p2p::transport::rendezvous::PilotManager* manager, ::rice::environment::Environment* env);
protected:
    LeafSetPilotStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void pilotClosed(::java::lang::Object* i) override;
    virtual void pilotOpening(::java::lang::Object* i) override;

private:
    virtual ::java::lang::Class* getClass0();
};
