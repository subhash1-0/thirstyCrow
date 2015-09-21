// Generated from /pastry-2.1/src/rice/pastry/socket/internet/InternetPastryNodeFactory.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/internet/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::socket::internet::InternetPastryNodeFactory_findExternalAddressHelper_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::net::InetAddress* result);
    virtual void receiveException(::java::io::IOException* exception);

    // Generated
    InternetPastryNodeFactory_findExternalAddressHelper_2(InternetPastryNodeFactory *InternetPastryNodeFactory_this, ::rice::Continuation* deliverResultToMe, ::rice::pastry::Id* nodeId, ::java::net::InetSocketAddress* bindAddress);
    static ::java::lang::Class *class_();
    virtual void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::java::lang::Object* result) override;
    InternetPastryNodeFactory *InternetPastryNodeFactory_this;
    ::rice::Continuation* deliverResultToMe;
    ::rice::pastry::Id* nodeId;
    ::java::net::InetSocketAddress* bindAddress;

private:
    virtual ::java::lang::Class* getClass0();
    friend class InternetPastryNodeFactory;
    friend class InternetPastryNodeFactory_findExternalNodes_1;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_3_run_3_1;
    friend class InternetPastryNodeFactory_verifyConnectivityThenMakeNewNode_4;
};
