// Generated from /pastry-2.1/src/rice/tutorial/transportdirect/DistTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/direct/fwd-pastry-2.1.hpp>
#include <rice/tutorial/transportdirect/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class rice::tutorial::transportdirect::DistTutorial_DistTutorial_1
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;

    // Generated

public:
    DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    DistTutorial *DistTutorial_this;
    ::rice::pastry::direct::NetworkSimulator* simulator;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DistTutorial;
};
