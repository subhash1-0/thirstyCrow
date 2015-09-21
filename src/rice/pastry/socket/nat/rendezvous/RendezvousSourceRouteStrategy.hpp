// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousSourceRouteStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousSourceRouteStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteStrategy
{

public:
    typedef ::java::lang::Object super;
    ::java::util::Collection* getSourceRoutes(::java::lang::Object* destination) override;

    // Generated
    RendezvousSourceRouteStrategy();
protected:
    RendezvousSourceRouteStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
