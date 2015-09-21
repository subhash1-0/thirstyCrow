// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/PortSerializer.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/Serializer.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::PortSerializer
    : public virtual ::java::lang::Object
    , public virtual Serializer
{

public:
    typedef ::java::lang::Object super;
    virtual ::java::net::InetSocketAddress* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::net::InetSocketAddress* i, ::java::util::Map* options) /* throws(IOException) */;
    virtual void serialize(::java::net::InetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */;

    // Generated
    PortSerializer();
protected:
    PortSerializer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::Object* deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::lang::Object* i, ::java::util::Map* options) override;
    virtual void serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) override;

private:
    virtual ::java::lang::Class* getClass0();
};
