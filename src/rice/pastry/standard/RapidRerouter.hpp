// Generated from /pastry-2.1/src/rice/pastry/standard/RapidRerouter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/messaging/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/StandardRouter.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>

struct default_init_tag;

class rice::pastry::standard::RapidRerouter
    : public StandardRouter
    , public virtual ::org::mpisws::p2p::transport::liveness::LivenessListener
{

public:
    typedef StandardRouter super;
    static constexpr int32_t MAX_RETRIES { int32_t(10) };

public: /* package */
    ::java::util::Map* pending {  };
protected:
    void ctor(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy);

public: /* protected */
    void sendTheMessage(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle) override;
    virtual void rerouteMe(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* oldDest, ::java::lang::Exception* ioe);

private:
    void addToPending(RapidRerouter_RouterNotification* notifyMe, ::rice::pastry::NodeHandle* handle);
    bool removeFromPending(RapidRerouter_RouterNotification* notifyMe, ::rice::pastry::NodeHandle* handle);

public:
    virtual void livenessChanged(::rice::pastry::NodeHandle* i, int32_t val, ::java::util::Map* options);
    void destroy() override;

    // Generated
    RapidRerouter(::rice::pastry::PastryNode* thePastryNode, ::rice::pastry::messaging::MessageDispatch* dispatch, ::rice::pastry::routing::RouterStrategy* strategy);
protected:
    RapidRerouter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RapidRerouter_rerouteMe_1;
    friend class RapidRerouter_RouterNotification;
};
