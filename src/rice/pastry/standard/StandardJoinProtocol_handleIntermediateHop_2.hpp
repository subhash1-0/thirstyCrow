// Generated from /pastry-2.1/src/rice/pastry/standard/StandardJoinProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/routing/RouteMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardJoinProtocol_handleIntermediateHop_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::routing::RouteMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sendSuccess(::rice::pastry::routing::RouteMessage* message, ::rice::pastry::NodeHandle* nextHop) override;
    void sendFailed(::rice::pastry::routing::RouteMessage* message, ::java::lang::Exception* e) override;

    // Generated
    StandardJoinProtocol_handleIntermediateHop_2(StandardJoinProtocol *StandardJoinProtocol_this);
    static ::java::lang::Class *class_();
    StandardJoinProtocol *StandardJoinProtocol_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StandardJoinProtocol;
    friend class StandardJoinProtocol_SJPDeserializer;
    friend class StandardJoinProtocol_handleInitiateJoin_1;
    friend class StandardJoinProtocol_respondToJoiner_3;
};
