// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/wire/WireTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/wire/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>

struct org::mpisws::p2p::transport::wire::WireTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
{

private:
    static ::java::lang::String* OPTION_TRANSPORT_TYPE_;

public:
    static constexpr int32_t TRANSPORT_TYPE_DATAGRAM { int32_t(0) };
    static constexpr int32_t TRANSPORT_TYPE_GUARANTEED { int32_t(1) };

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& OPTION_TRANSPORT_TYPE();
};
