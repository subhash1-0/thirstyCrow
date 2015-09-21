// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/proximity/ProximityProvider.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/proximity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::proximity::ProximityProvider
    : public virtual ::java::lang::Object
{
    static constexpr int32_t DEFAULT_PROXIMITY { int32_t(3600000) };
    virtual int32_t proximity(::java::lang::Object* i, ::java::util::Map* options) = 0;
    virtual void addProximityListener(ProximityListener* listener) = 0;
    virtual bool removeProximityListener(ProximityListener* listener) = 0;
    virtual void clearState(::java::lang::Object* i) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
