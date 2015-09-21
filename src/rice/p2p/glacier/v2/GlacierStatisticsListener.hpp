// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/GlacierStatisticsListener.java

#pragma once

#include <rice/p2p/glacier/v2/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::p2p::glacier::v2::GlacierStatisticsListener
    : public virtual ::java::lang::Object
{
    virtual void receiveStatistics(GlacierStatistics* stat) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
