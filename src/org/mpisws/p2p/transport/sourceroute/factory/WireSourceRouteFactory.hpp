// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/factory/WireSourceRouteFactory.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::factory::WireSourceRouteFactory
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory
{

public:
    typedef ::java::lang::Object super;
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::net::InetSocketAddress* localAddr, ::java::net::InetSocketAddress* lastHop) /* throws(IOException) */;
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getSourceRoute(::java::util::List* route) override;
    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* reverse(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route) override;
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getSourceRoute(::java::net::InetSocketAddress* local, ::java::net::InetSocketAddress* dest);
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getSourceRoute(::java::net::InetSocketAddress* local);

    // Generated
    WireSourceRouteFactory();
protected:
    WireSourceRouteFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::java::lang::Object* local, ::java::lang::Object* lastHop) override;
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getSourceRoute(::java::lang::Object* local, ::java::lang::Object* dest) override;
    virtual ::org::mpisws::p2p::transport::sourceroute::SourceRoute* getSourceRoute(::java::lang::Object* local) override;

private:
    virtual ::java::lang::Class* getClass0();
};
