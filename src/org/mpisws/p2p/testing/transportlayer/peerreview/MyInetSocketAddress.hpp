// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress
    : public ::java::net::InetSocketAddress
    , public virtual ::rice::p2p::commonapi::rawserialization::RawSerializable
{

public:
    typedef ::java::net::InetSocketAddress super;

private:
    static ::org::mpisws::p2p::transport::util::Serializer* serializer_;
protected:
    void ctor(::java::net::InetAddress* addr, int32_t port);

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    MyInetSocketAddress(::java::net::InetAddress* addr, int32_t port);
protected:
    MyInetSocketAddress(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::org::mpisws::p2p::transport::util::Serializer*& serializer();

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyInetSocketAddress_1;
};
