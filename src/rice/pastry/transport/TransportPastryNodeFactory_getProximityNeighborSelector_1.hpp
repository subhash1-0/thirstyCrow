// Generated from /pastry-2.1/src/rice/pastry/transport/TransportPastryNodeFactory.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/pastry/standard/ProximityNeighborSelector.hpp>

struct default_init_tag;

class rice::pastry::transport::TransportPastryNodeFactory_getProximityNeighborSelector_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::pastry::standard::ProximityNeighborSelector
{

public:
    typedef ::java::lang::Object super;
    ::rice::p2p::commonapi::Cancellable* getNearHandles(::java::util::Collection* bootHandles, ::rice::Continuation* deliverResultToMe) override;

    // Generated
    TransportPastryNodeFactory_getProximityNeighborSelector_1(TransportPastryNodeFactory *TransportPastryNodeFactory_this);
    static ::java::lang::Class *class_();
    TransportPastryNodeFactory *TransportPastryNodeFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class TransportPastryNodeFactory;
};
