// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/pastry/pns/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>

struct default_init_tag;

class rice::pastry::pns::PNSApplication_getRouteRow_7
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::transport::PMessageNotification
{

public:
    typedef ::java::lang::Object super;
    void sent(::rice::pastry::transport::PMessageReceipt* msg) override;
    void sendFailed(::rice::pastry::transport::PMessageReceipt* msg, ::java::lang::Exception* reason) override;

    // Generated
    PNSApplication_getRouteRow_7(PNSApplication *PNSApplication_this, ::rice::p2p::util::AttachableCancellable* cancellable, ::rice::Continuation* c);
    static ::java::lang::Class *class_();
    PNSApplication *PNSApplication_this;
    ::rice::p2p::util::AttachableCancellable* cancellable;
    ::rice::Continuation* c;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PNSApplication;
    friend class PNSApplication_getNearHandles_1;
    friend class PNSApplication_getNearHandles_1_receiveResult_1_1;
    friend class PNSApplication_getLeafSet_2;
    friend class PNSApplication_getLeafSet_3;
    friend class PNSApplication_getLeafSet_4;
    friend class PNSApplication_getRouteRow_5;
    friend class PNSApplication_getRouteRow_6;
    friend class PNSApplication_getProximity_8;
    friend class PNSApplication_getProximity_9;
    friend class PNSApplication_sortedProximityCache_10;
    friend class PNSApplication_getNearest_11;
    friend class PNSApplication_getNearest_12;
    friend class PNSApplication_getNearest_12_receiveResult_12_1;
    friend class PNSApplication_getNearest_12_receiveResult_12_1_receiveResult_12_1_1;
    friend class PNSApplication_seekThroughRouteRows_13;
    friend class PNSApplication_seekThroughRouteRows_13_receiveResult_13_1;
    friend class PNSApplication_closestToMe_14;
    friend class PNSApplication_PNSDeserializer;
};
