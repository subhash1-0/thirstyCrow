// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousLivenessProvider.java

#pragma once

#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousLivenessProvider
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessProvider
{

public:
    typedef ::java::lang::Object super;

    // Generated
    RendezvousLivenessProvider();
protected:
    RendezvousLivenessProvider(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
