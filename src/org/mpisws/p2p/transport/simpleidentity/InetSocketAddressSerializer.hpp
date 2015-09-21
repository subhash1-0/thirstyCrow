// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/InetSocketAddressSerializer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/Serializer.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <java/net/InetSocketAddress.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::InetSocketAddressSerializer
    : public virtual ::java::lang::Object
    , public virtual Serializer
    , public virtual ::org::mpisws::p2p::transport::util::Serializer
{

public:
    typedef ::java::lang::Object super;
    static constexpr int8_t IPV4 { int8_t(4) };
    static constexpr int8_t IPV6 { int8_t(6) };
    static constexpr int32_t IPV4_BYTES { int32_t(4) };
    static constexpr int32_t IPV6_BYTES { int32_t(16) };
    virtual ::java::net::InetSocketAddress* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::net::InetSocketAddress* i, ::java::util::Map* options) /* throws(IOException) */;
    virtual void serialize(::java::net::InetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */;
    static ::java::net::InetSocketAddress* deserializeAddress(::rice::p2p::commonapi::rawserialization::InputBuffer* b) /* throws(IOException) */;
    static void serializeAddress(::java::net::InetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */;
    virtual int32_t getSerializedLength(::java::net::InetSocketAddress* i);
    ::java::net::InetSocketAddress* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */ override;

    // Generated
    InetSocketAddressSerializer();
protected:
    InetSocketAddressSerializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) override;

private:
    virtual ::java::lang::Class* getClass0();
};
