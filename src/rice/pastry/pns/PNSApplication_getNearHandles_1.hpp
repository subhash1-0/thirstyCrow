// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/pns/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::pastry::pns::PNSApplication_getNearHandles_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    virtual void receiveResult(::java::lang::Integer* result);
    virtual void receiveException(::java::io::IOException* exception);

    // Generated
    PNSApplication_getNearHandles_1(PNSApplication *PNSApplication_this, ::rice::pastry::NodeHandle* handle, ::rice::p2p::util::tuples::MutableTuple* best, ::rice::p2p::util::AttachableCancellable* ret, ::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe, ::java::util::Collection* remaining);
    static ::java::lang::Class *class_();
    virtual void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::java::lang::Object* result) override;
    PNSApplication *PNSApplication_this;
    ::rice::pastry::NodeHandle* handle;
    ::rice::p2p::util::tuples::MutableTuple* best;
    ::rice::p2p::util::AttachableCancellable* ret;
    ::java::util::Collection* bootHandles;
    ::rice::Continuation* deliverResultToMe;
    ::java::util::Collection* remaining;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PNSApplication;
    friend class PNSApplication_getNearHandles_1_receiveResult_1_1;
    friend class PNSApplication_getLeafSet_2;
    friend class PNSApplication_getLeafSet_3;
    friend class PNSApplication_getLeafSet_4;
    friend class PNSApplication_getRouteRow_5;
    friend class PNSApplication_getRouteRow_6;
    friend class PNSApplication_getRouteRow_7;
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
