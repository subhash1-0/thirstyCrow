// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/MutableInetSocketAddressStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/LocalIdentifierStrategy.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::MutableInetSocketAddressStrategy
    : public virtual ::java::lang::Object
    , public virtual LocalIdentifierStrategy
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int32_t port {  };
    Serializer* serializer {  };
    ::java::net::InetAddress* lastLocalAddress {  };
    ::int8_tArray* lastBytes {  };
protected:
    void ctor(int32_t port, Serializer* serializer);

public:
    ::int8_tArray* getLocalIdentifierBytes() /* throws(IOException) */ override;

public: /* protected */
    virtual ::int8_tArray* serializeAddress(::java::net::InetSocketAddress* addr) /* throws(IOException) */;
    virtual ::java::net::InetAddress* getLocalAddress() /* throws(IOException) */;

    // Generated

public:
    MutableInetSocketAddressStrategy(int32_t port, Serializer* serializer);
protected:
    MutableInetSocketAddressStrategy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
