// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/LeafSetRendezvousStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/RendezvousGenerationStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::LeafSetRendezvousStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::rendezvous::RendezvousGenerationStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::rice::pastry::PastryNode* pn {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor(::rice::pastry::PastryNode* pn, ::rice::environment::random::RandomSource* r);

public:
    virtual RendezvousSocketNodeHandle* getRendezvousPoint(RendezvousSocketNodeHandle* dest, ::java::util::Map* options);

    // Generated
    LeafSetRendezvousStrategy(::rice::pastry::PastryNode* pn, ::rice::environment::random::RandomSource* r);
protected:
    LeafSetRendezvousStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* getRendezvousPoint(::java::lang::Object* dest, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
};
