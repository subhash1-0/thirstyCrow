// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/simple/SimpleSourceRouteStrategy.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/liveness/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::manager::simple::SimpleSourceRouteStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::sourceroute::manager::SourceRouteStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::util::TimerWeakHashMap* routes {  };
    NextHopStrategy* strategy {  };
    ::rice::environment::Environment* environment {  };
    ::rice::environment::logging::Logger* logger {  };
    ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessManager {  };
    ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory {  };
    ::java::lang::Object* localAddress {  };
protected:
    void ctor(::java::lang::Object* localAddress, ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, NextHopStrategy* strategy, ::rice::environment::Environment* env);

public:
    ::java::util::Collection* getSourceRoutes(::java::lang::Object* destination) override;

private:
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getRoute(::java::lang::Object* intermediate, ::java::lang::Object* dest);

    // Generated

public:
    SimpleSourceRouteStrategy(::java::lang::Object* localAddress, ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, NextHopStrategy* strategy, ::rice::environment::Environment* env);
protected:
    SimpleSourceRouteStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
