// Generated from /pastry-2.1/src/rice/pastry/routing/RequestRouteRow.java
#include <rice/pastry/routing/RequestRouteRow.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/routing/RouteProtocolAddress.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::routing::RequestRouteRow::RequestRouteRow(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::routing::RequestRouteRow::RequestRouteRow(::rice::pastry::NodeHandle* nh, int16_t r) 
    : RequestRouteRow(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,r);
}

rice::pastry::routing::RequestRouteRow::RequestRouteRow(::java::util::Date* stamp, ::rice::pastry::NodeHandle* nh, int16_t r) 
    : RequestRouteRow(*static_cast< ::default_init_tag* >(0))
{
    ctor(stamp,nh,r);
}

rice::pastry::routing::RequestRouteRow::RequestRouteRow(::rice::pastry::NodeHandle* sender, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf)  /* throws(IOException) */
    : RequestRouteRow(*static_cast< ::default_init_tag* >(0))
{
    ctor(sender,buf);
}

constexpr int16_t rice::pastry::routing::RequestRouteRow::TYPE;

void rice::pastry::routing::RequestRouteRow::ctor(::rice::pastry::NodeHandle* nh, int16_t r)
{
    ctor(nullptr, nh, r);
}

void rice::pastry::routing::RequestRouteRow::ctor(::java::util::Date* stamp, ::rice::pastry::NodeHandle* nh, int16_t r)
{
    super::ctor(RouteProtocolAddress::getCode(), stamp);
    setSender(nh);
    row = r;
    setPriority(MAX_PRIORITY);
}

rice::pastry::NodeHandle* rice::pastry::routing::RequestRouteRow::returnHandle()
{
    return getSender();
}

int16_t rice::pastry::routing::RequestRouteRow::getRow()
{
    return row;
}

java::lang::String* rice::pastry::routing::RequestRouteRow::toString()
{
    auto s = u""_j;
    s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u"RequestRouteRow(row "_j)->append(row)
        ->append(u" by "_j)
        ->append(static_cast< ::java::lang::Object* >(npc(getSender())->getNodeId()))
        ->append(u")"_j)->toString())->toString();
    return s;
}

int16_t rice::pastry::routing::RequestRouteRow::getType()
{
    return TYPE;
}

void rice::pastry::routing::RequestRouteRow::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeShort(row);
}

void rice::pastry::routing::RequestRouteRow::ctor(::rice::pastry::NodeHandle* sender, ::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    super::ctor(RouteProtocolAddress::getCode(), nullptr);
    setSender(sender);
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        row = npc(buf)->readShort();
        setPriority(MAX_PRIORITY);
        break;
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::routing::RequestRouteRow::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.routing.RequestRouteRow", 35);
    return c;
}

java::lang::Class* rice::pastry::routing::RequestRouteRow::getClass0()
{
    return class_();
}

