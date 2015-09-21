// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerP2PSocket.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerP2PSocket
    : public ::org::mpisws::p2p::transport::util::SocketWrapperSocket
{

public:
    typedef ::org::mpisws::p2p::transport::util::SocketWrapperSocket super;
protected:
    void ctor(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env);

    // Generated

public:
    SourceRouteManagerP2PSocket(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, ::rice::environment::Environment* env);
protected:
    SourceRouteManagerP2PSocket(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
