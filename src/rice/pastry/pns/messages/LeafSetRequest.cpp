// Generated from /pastry-2.1/src/rice/pastry/pns/messages/LeafSetRequest.java
#include <rice/pastry/pns/messages/LeafSetRequest.hpp>

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

rice::pastry::pns::messages::LeafSetRequest::LeafSetRequest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::pns::messages::LeafSetRequest::LeafSetRequest(::rice::pastry::NodeHandle* nodeHandle, int32_t dest) 
    : LeafSetRequest(*static_cast< ::default_init_tag* >(0))
{
    ctor(nodeHandle,dest);
}

constexpr int16_t rice::pastry::pns::messages::LeafSetRequest::TYPE;

void rice::pastry::pns::messages::LeafSetRequest::ctor(::rice::pastry::NodeHandle* nodeHandle, int32_t dest)
{
    super::ctor(dest);
    if(nodeHandle == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"nodeHandle == null!"_j);

    setSender(nodeHandle);
    setPriority(HIGH_PRIORITY);
}

rice::pastry::pns::messages::LeafSetRequest* rice::pastry::pns::messages::LeafSetRequest::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::pastry::NodeHandle* sender, int32_t dest) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    if(version == 0)
        return new LeafSetRequest(sender, dest);

    throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Unknown version:"_j)->append(version)->toString());
}

int16_t rice::pastry::pns::messages::LeafSetRequest::getType()
{
    return TYPE;
}

void rice::pastry::pns::messages::LeafSetRequest::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::messages::LeafSetRequest::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.pns.messages.LeafSetRequest", 39);
    return c;
}

java::lang::Class* rice::pastry::pns::messages::LeafSetRequest::getClass0()
{
    return class_();
}

