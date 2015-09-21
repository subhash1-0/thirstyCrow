// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::MyInetSocketAddress_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::util::Serializer
{

public:
    typedef ::java::lang::Object super;
    static constexpr int8_t IPV4 { int8_t(4) };
    static constexpr int8_t IPV6 { int8_t(6) };
    static constexpr int32_t IPV4_BYTES { int32_t(4) };
    static constexpr int32_t IPV6_BYTES { int32_t(16) };
    MyInetSocketAddress* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b) /* throws(IOException) */ override;
    virtual void serialize(MyInetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */;

    // Generated
    MyInetSocketAddress_1();
    static ::java::lang::Class *class_();
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MyInetSocketAddress;
};
