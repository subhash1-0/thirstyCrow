// Generated from /pastry-2.1/src/rice/p2p/commonapi/Id.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Comparable.hpp>
#include <java/io/Serializable.hpp>

struct rice::p2p::commonapi::Id_Distance
    : public virtual ::java::lang::Comparable
    , public virtual ::java::io::Serializable
{
    virtual Id_Distance* shiftDistance(int32_t cnt, int32_t fill) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
