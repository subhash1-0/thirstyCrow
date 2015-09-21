// Generated from /pastry-2.1/src/rice/pastry/socket/nat/probe/ProbeApp.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/probe/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::probe::ProbeApp_requestProbe_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::transport::PMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sent(::rice::pastry::transport::PMessageReceipt* msg) override;
    void sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason) override;

    // Generated
    ProbeApp_requestProbe_2(ProbeApp *ProbeApp_this, ::rice::Continuation* deliverResultToMe);
    static ::java::lang::Class *class_();
    ProbeApp *ProbeApp_this;
    ::rice::Continuation* deliverResultToMe;

private:
    virtual ::java::lang::Class* getClass0();
    friend class ProbeApp;
    friend class ProbeApp_ProbeApp_1;
};
