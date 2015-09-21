// Generated from /pastry-2.1/src/rice/pastry/standard/StandardRouter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/routing/Router.hpp>

struct default_init_tag;

class rice::pastry::standard::StandardRouter
    : public ::rice::pastry::client::PastryAppl
    , public virtual ::rice::pastry::routing::Router
{

public:
    typedef ::rice::pastry::client::PastryAppl super;

public: /* package */
    ::rice::pastry::messaging::MessageDispatch* dispatch {  };

public: /* protected */
    ::rice::pastry::routing::RouterStrategy* routerStrategy {  };
protected:
    void ctor(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch);
    void ctor(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy);

public:
    virtual void setRouterStrategy(::rice::pastry::routing::RouterStrategy* strategy);
    void receiveMessage(::rice::pastry::messaging::Message* msg) override;
    void route(::rice::pastry::routing::RouteMessage* rm) override;
    virtual bool routeMessage(::rice::pastry::routing::RouteMessage* rm);

public: /* protected */
    virtual void sendTheMessage(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle);

private:
    void receiveRouteMessage(::rice::pastry::routing::RouteMessage* msg);

public:
    ::java::util::Iterator* getBestRoutingCandidates(::rice::pastry::Id* target) override;

public: /* protected */
    virtual ::java::util::Iterator* getBestRoutingCandidates(::rice::pastry::Id* target, int32_t lsPos, bool leafSetOnly);
    virtual ::java::util::ArrayList* getLSCollection(int32_t lsPos);

public:
    virtual void deliverToApplication(::rice::pastry::routing::RouteMessage* msg);

private:
    void checkForRouteTableHole(::rice::pastry::routing::RouteMessage* msg, ::rice::pastry::NodeHandle* handle);

public: /* protected */
    int32_t ROUTE_TABLE_PATCH_THROTTLE {  };
    ::java::util::Map* lastTimeSentRouteTablePatch {  };

public:
    bool deliverWhenNotReady() override;
    void messageForAppl(::rice::pastry::messaging::Message* msg) override;

    // Generated
    StandardRouter(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch);
    StandardRouter(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy);
protected:
    StandardRouter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class StandardRouter_AliveRouterStrategy;
    friend class StandardRouter_StandardRouter_1;
    friend class StandardRouter_route_2;
    friend class StandardRouter_sendTheMessage_3;
    friend class StandardRouter_getBestRoutingCandidates_4;
};
