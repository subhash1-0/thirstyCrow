// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/LeafSetPilotFinder.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/leafset/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/PilotFinder.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::LeafSetPilotFinder
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::rendezvous::PilotFinder
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::leafset::LeafSet* leafSet {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn);

public:
    virtual RendezvousSocketNodeHandle* findPilot(RendezvousSocketNodeHandle* dest);

    // Generated
    LeafSetPilotFinder(::rice::pastry::PastryNode* pn);
protected:
    LeafSetPilotFinder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* findPilot(::java::lang::Object* i) override;

private:
    virtual ::java::lang::Class* getClass0();
};
