// Generated from /pastry-2.1/src/rice/pastry/standard/RapidRerouter.java

#pragma once

#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class rice::pastry::standard::RapidRerouter_rerouteMe_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    RapidRerouter_rerouteMe_1(RapidRerouter *RapidRerouter_this, ::rice::pastry::routing::RouteMessage* rm);
    static ::java::lang::Class *class_();
    RapidRerouter *RapidRerouter_this;
    ::rice::pastry::routing::RouteMessage* rm;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RapidRerouter;
    friend class RapidRerouter_RouterNotification;
};
