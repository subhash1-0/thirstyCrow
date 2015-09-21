// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouteSetProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/routing/RouteSetProtocol.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouteSetProtocol
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::pastry::routing::RouteSetProtocol
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

private:
    int32_t maxTrials {  };
    ::rice::pastry::routing::RoutingTable* routeTable {  };
    ::rice::environment::Environment* environmet {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt);
    void ctor(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);

public:
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;

private:
    void maintainRouteSet();

public:
    bool deliverWhenNotReady() override;

    // Generated
    StandardRouteSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt);
    StandardRouteSetProtocol(::rice::pastry::PastryNode* ln, ::rice::pastry::routing::RoutingTable* rt, ::rice::p2p::commonapi::rawserialization::MessageDeserializer* md);
protected:
    StandardRouteSetProtocol(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouteSetProtocol_SRSPDeserializer;
};
