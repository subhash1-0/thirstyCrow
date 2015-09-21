// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayer.java

#pragma once

#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>

struct org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
{
    virtual AddressStrategy* getAddressStrategy() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
