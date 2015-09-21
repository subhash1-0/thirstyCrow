// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/Forwarder.java

#pragma once

#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::Forwarder
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    SourceRoute* sr {  };
    ::org::mpisws::p2p::transport::P2PSocket* socka {  };
    ::org::mpisws::p2p::transport::P2PSocket* sockb {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(SourceRoute* sr, ::org::mpisws::p2p::transport::P2PSocket* socka, ::org::mpisws::p2p::transport::P2PSocket* sockb, ::rice::environment::logging::Logger* logger);

    // Generated

public:
    Forwarder(SourceRoute* sr, ::org::mpisws::p2p::transport::P2PSocket* socka, ::org::mpisws::p2p::transport::P2PSocket* sockb, ::rice::environment::logging::Logger* logger);
protected:
    Forwarder(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class Forwarder_HalfPipe;
};
