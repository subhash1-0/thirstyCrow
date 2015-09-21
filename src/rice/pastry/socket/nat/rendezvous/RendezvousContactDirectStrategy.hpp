// Generated from /pastry-2.1/src/rice/pastry/socket/nat/rendezvous/RendezvousContactDirectStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/pastry/socket/nat/rendezvous/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/rendezvous/ContactDirectStrategy.hpp>

struct default_init_tag;

class rice::pastry::socket::nat::rendezvous::RendezvousContactDirectStrategy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::rendezvous::ContactDirectStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* localAddr {  };
    ::rice::environment::Environment* environment {  };
    ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(RendezvousSocketNodeHandle* localNodeHandle, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy, ::rice::environment::Environment* environment);

public:
    virtual bool canContactDirect(RendezvousSocketNodeHandle* remoteNode);

    // Generated
    RendezvousContactDirectStrategy(RendezvousSocketNodeHandle* localNodeHandle, ::org::mpisws::p2p::transport::multiaddress::AddressStrategy* addressStrategy, ::rice::environment::Environment* environment);
protected:
    RendezvousContactDirectStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool canContactDirect(::java::lang::Object* remoteNode) override;

private:
    virtual ::java::lang::Class* getClass0();
};
