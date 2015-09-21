// Generated from /pastry-2.1/src/rice/pastry/pns/messages/RouteRowRequest.java
#include <rice/pastry/pns/messages/RouteRowRequest.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::pns::messages::RouteRowRequest::RouteRowRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::pns::messages::RouteRowRequest::RouteRowRequest(::rice::pastry::NodeHandle* nodeHandle, int16_t index, int32_t dest) 
    : RouteRowRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodeHandle,index,dest);
}

constexpr int16_t rice::pastry::pns::messages::RouteRowRequest::TYPE;

void rice::pastry::pns::messages::RouteRowRequest::ctor(::rice::pastry::NodeHandle* nodeHandle, int16_t index, int32_t dest)
{
    super::ctor(dest);
    if(nodeHandle == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"nodeHandle == null!"_j);

    setSender(nodeHandle);
    this->index = index;
    setPriority(HIGH_PRIORITY);
}

rice::p2p::commonapi::Message* rice::pastry::pns::messages::RouteRowRequest::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandle* sender, int32_t dest) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    if(version == 0)
        return new RouteRowRequest(sender, npc(buf)->readShort(), dest);

    throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Unknown version:"_j)->append(version)->toString());
}

java::lang::String* rice::pastry::pns::messages::RouteRowRequest::toString()
{
    return ::java::lang::StringBuilder().append(u"RRReq["_j)->append(index)
        ->append(u"]"_j)->toString();
}

int16_t rice::pastry::pns::messages::RouteRowRequest::getType()
{
    return TYPE;
}

void rice::pastry::pns::messages::RouteRowRequest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    npc(buf)->writeShort(index);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::messages::RouteRowRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.pns.messages.RouteRowRequest", 40);
    return c;
}

java::lang::Class* rice::pastry::pns::messages::RouteRowRequest::getClass0()
{
    return class_();
}

