// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousRouterStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/routing/RouterStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousRouterStrategy
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::routing::RouterStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::priority::PriorityTransportLayer* priority {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::priority::PriorityTransportLayer* priority, ::rice::environment::Environment* env);

public:
    ::rice::pastry::NodeHandle* pickNextHop(::rice::pastry::routing::RouteMessage* msg, ::java::util::Iterator* i) override;

public: /* protected */
    virtual int32_t routingQuality(::rice::pastry::NodeHandle* nh);
    virtual ::java::util::Map* getOptions(::rice::pastry::NodeHandle* nh);

    // Generated

public:
    RendezvousRouterStrategy(::org::mpisws::p2p::transport::priority::PriorityTransportLayer* priority, ::rice::environment::Environment* env);
protected:
    RendezvousRouterStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
