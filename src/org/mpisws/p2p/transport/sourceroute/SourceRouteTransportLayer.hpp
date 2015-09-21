// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/SourceRouteTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>

struct org::mpisws::p2p::transport::sourceroute::SourceRouteTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
{

private:
    static ::java::lang::String* OPTION_SOURCE_ROUTE_;

public:
    static constexpr int32_t DONT_SOURCE_ROUTE { int32_t(0) };
    static constexpr int32_t ALLOW_SOURCE_ROUTE { int32_t(1) };
    virtual void addSourceRouteTap(SourceRouteTap* tap) = 0;
    virtual bool removeSourceRouteTap(SourceRouteTap* tap) = 0;

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& OPTION_SOURCE_ROUTE();
};
