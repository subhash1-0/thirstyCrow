// Generated from /pastry-2.1/src/rice/tutorial/ssl/DistTutorial.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/tutorial/ssl/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class rice::tutorial::ssl::DistTutorial_DistTutorial_1
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;

public: /* protected */
    ::org::mpisws::p2p::transport::TransportLayer* getSourceRouteTransportLayer(::org::mpisws::p2p::transport::TransportLayer* etl, ::rice::pastry::PastryNode* pn, ::org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRouteFactory* esrFactory) override;
    ::org::mpisws::p2p::transport::identity::BindStrategy* getBindStrategy() override;

    // Generated

public:
    DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::java::security::KeyStore* store, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    DistTutorial_DistTutorial_1(DistTutorial *DistTutorial_this, ::java::security::KeyStore* store, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    DistTutorial *DistTutorial_this;
    ::java::security::KeyStore* store;

private:
    virtual ::java::lang::Class* getClass0();
    friend class DistTutorial;
    friend class DistTutorial_DistTutorial_1_getBindStrategy_1_1;
};
