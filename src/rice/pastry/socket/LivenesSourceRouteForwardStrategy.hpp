// Generated from /pastry-2.1/src/rice/pastry/socket/LivenesSourceRouteForwardStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteForwardStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::LivenesSourceRouteForwardStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::sourceroute::SourceRouteForwardStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness {  };

private:
    ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* factory {  };
protected:
    void ctor(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* factory, ::rice::environment::Environment* env);

public:
    virtual void setLivenessProvider(::org::mpisws::p2p::transport::liveness::LivenessProvider* liveness);
    bool forward(::java::lang::Object* nextHop, ::org::mpisws::p2p::transport::sourceroute::SourceRoute* sr, bool socket, ::java::util::Map* options) override;

    // Generated
    LivenesSourceRouteForwardStrategy(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* factory, ::rice::environment::Environment* env);
protected:
    LivenesSourceRouteForwardStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
