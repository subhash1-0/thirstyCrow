// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/ssl/SSLTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/ssl/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>

struct org::mpisws::p2p::transport::ssl::SSLTransportLayer
    : public virtual ::org::mpisws::p2p::transport::TransportLayer
    , public virtual ::org::mpisws::p2p::transport::TransportLayerCallback
{

private:
    static ::java::lang::String* OPTION_ENCRYPTION_;
    static ::java::lang::String* OPTION_AUTHENTICATION_;
    static ::java::lang::String* OPTION_CERT_SUBJECT_;

public:
    static constexpr int32_t CLIENT_AUTH_NONE { int32_t(0) };
    static constexpr int32_t CLIENT_AUTH_REQUIRED { int32_t(1) };
    static constexpr int32_t CLIENT_AUTH_OPTIONAL { int32_t(2) };
    static constexpr int32_t NO { int32_t(0) };
    static constexpr int32_t YES { int32_t(1) };

    // Generated
    static ::java::lang::Class *class_();
    static ::java::lang::String*& OPTION_ENCRYPTION();
    static ::java::lang::String*& OPTION_AUTHENTICATION();
    static ::java::lang::String*& OPTION_CERT_SUBJECT();
};
