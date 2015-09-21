// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/replay/Recorder.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/replay/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/pastry/fwd-pastry-2.1.hpp>
#include <rice/pastry/boot/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <rice/pastry/transport/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/SocketPastryNodeFactory.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::replay::Recorder_Recorder_1
    : public ::rice::pastry::socket::SocketPastryNodeFactory
{

public:
    typedef ::rice::pastry::socket::SocketPastryNodeFactory super;
    ::rice::pastry::NodeHandle* getLocalHandle(::rice::pastry::PastryNode* pn, ::rice::pastry::NodeHandleFactory* nhf) override;

public: /* protected */
    ::rice::environment::random::RandomSource* cloneRandomSource(::rice::environment::Environment* rootEnvironment, ::rice::pastry::Id* nodeId, ::rice::environment::logging::LogManager* lman) override;
    ::org::mpisws::p2p::transport::TransportLayer* getWireTransportLayer(::java::net::InetSocketAddress* innermostAddress, ::rice::pastry::PastryNode* pn) /* throws(IOException) */ override;
    ::rice::pastry::boot::Bootstrapper* getBootstrapper(::rice::pastry::PastryNode* pn, ::rice::pastry::transport::NodeHandleAdapter* tl, ::rice::pastry::NodeHandleFactory* handleFactory, ::rice::pastry::standard::ProximityNeighborSelector* pns) override;

    // Generated

public:
    Recorder_Recorder_1(Recorder *Recorder_this, ::rice::pastry::NodeIdFactory* nf, int32_t startPort, ::rice::environment::Environment* env);
    Recorder_Recorder_1(Recorder *Recorder_this, ::rice::pastry::NodeIdFactory* nf, ::java::net::InetAddress* bindAddress, int32_t startPort, ::rice::environment::Environment* env);
    static ::java::lang::Class *class_();
    Recorder *Recorder_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class Recorder;
    friend class Recorder_Recorder_1_getBootstrapper_1_1;
    friend class Recorder_Recorder_2;
    friend class Recorder_AppInvokation;
    friend class Recorder_SubscribeInvokation;
    friend class Recorder_PublishInvokation;
};
