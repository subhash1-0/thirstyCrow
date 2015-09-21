// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/factory/MultiAddressSourceRoute.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/factory/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::sourceroute::factory::MultiAddressSourceRoute
    : public ::org::mpisws::p2p::transport::sourceroute::SourceRoute
{

public:
    typedef ::org::mpisws::p2p::transport::sourceroute::SourceRoute super;
protected:
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* remote);
    void ctor(::java::util::List* path);
    void ctor(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* address);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int32_t getSerializedLength() override;

public: /* package */
    virtual ::java::util::List* getPath();

    // Generated
    MultiAddressSourceRoute(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* local, ::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* remote);
    MultiAddressSourceRoute(::java::util::List* path);
    MultiAddressSourceRoute(::org::mpisws::p2p::transport::multiaddress::MultiInetSocketAddress* address);
protected:
    MultiAddressSourceRoute(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
