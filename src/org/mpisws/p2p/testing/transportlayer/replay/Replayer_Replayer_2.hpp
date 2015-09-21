// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Replayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Replayer_Replayer_2
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;
    ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf) override;

public: /* protected */
    ::rice::environment::random::RandomSource* cloneRandomSource(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman) override;
    ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;

    // Generated

public:
    Replayer_Replayer_2(Replayer *Replayer_this, ::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::util::List* replayers, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    Replayer_Replayer_2(Replayer *Replayer_this, ::rice::pastry::Id* id, ::java::net::InetSocketAddress* addr, ::java::util::List* replayers, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    Replayer *Replayer_this;
    ::rice::pastry::Id* id;
    ::java::net::InetSocketAddress* addr;
    ::java::util::List* replayers;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Replayer;
    friend class Replayer_Replayer_1;
};
