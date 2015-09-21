// Generated from /pastry-2.1/src/rice/pastry/standard/RapidRerouter.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::standard::RapidRerouter_RouterNotification
    : public virtual ::java::lang::Object
    , public virtual ::rice::p2p::commonapi::Cancellable
    , public virtual ::rice::pastry::transport::PMessageNotification
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::pastry::routing::RouteMessage* rm {  };
    ::rice::pastry::NodeHandle* dest {  };
    ::rice::pastry::transport::PMessageReceipt* cancellable {  };
protected:
    void ctor(::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle);

public:
    virtual void setCancellable(::rice::pastry::transport::PMessageReceipt* receipt);
    void sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason) override;

public: /* package */
    bool failed {  };
    bool sent_ {  };
    bool cancelled {  };

public:
    void sent(::rice::pastry::transport::PMessageReceipt* msg) override;
    bool cancel() override;
    ::java::lang::String* toString() override;

    // Generated
    RapidRerouter_RouterNotification(RapidRerouter *RapidRerouter_this, ::rice::pastry::routing::RouteMessage* rm, ::rice::pastry::NodeHandle* handle);
protected:
    RapidRerouter_RouterNotification(RapidRerouter *RapidRerouter_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    RapidRerouter *RapidRerouter_this;
    virtual ::java::lang::Class* getClass0();
    friend class RapidRerouter;
    friend class RapidRerouter_rerouteMe_1;
};
