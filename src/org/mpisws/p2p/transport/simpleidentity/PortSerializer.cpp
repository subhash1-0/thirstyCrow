// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/PortSerializer.java
#include <org/mpisws/p2p/transport/simpleidentity/PortSerializer.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::simpleidentity::PortSerializer::PortSerializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::simpleidentity::PortSerializer::PortSerializer()
    : PortSerializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::net::InetSocketAddress* org::mpisws::p2p::transport::simpleidentity::PortSerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::net::InetSocketAddress* i, ::java::util::Map* options) /* throws(IOException) */
{
    return new ::java::net::InetSocketAddress(npc(i)->getAddress(), static_cast< int32_t >(npc(b)->readShort()));
}

java::lang::Object* org::mpisws::p2p::transport::simpleidentity::PortSerializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* b, ::java::lang::Object* i, ::java::util::Map* options)
{ 
    return deserialize(b, dynamic_cast< ::java::net::InetSocketAddress* >(i), options);
}

void org::mpisws::p2p::transport::simpleidentity::PortSerializer::serialize(::java::net::InetSocketAddress* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b) /* throws(IOException) */
{
    npc(b)->writeShort(static_cast< int16_t >(npc(i)->getPort()));
}

void org::mpisws::p2p::transport::simpleidentity::PortSerializer::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* b)
{ 
    serialize(dynamic_cast< ::java::net::InetSocketAddress* >(i), b);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::PortSerializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.simpleidentity.PortSerializer", 54);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::PortSerializer::getClass0()
{
    return class_();
}

