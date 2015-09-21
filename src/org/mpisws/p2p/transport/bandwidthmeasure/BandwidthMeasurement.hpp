// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasurement.java

#pragma once

#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasurement
    : public virtual ::java::lang::Object
{
    virtual ::java::util::Map* getBandwidthUsed() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
