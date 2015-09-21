// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/SimpleAddressStrategy.java

#pragma once

#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/multiaddress/AddressStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::multiaddress::SimpleAddressStrategy
    : public virtual ::java::lang::Object
    , public virtual AddressStrategy
{

public:
    typedef ::java::lang::Object super;
    ::java::net::InetSocketAddress* getAddress(MultiInetSocketAddress* local, MultiInetSocketAddress* remote) override;

    // Generated
    SimpleAddressStrategy();
protected:
    SimpleAddressStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
