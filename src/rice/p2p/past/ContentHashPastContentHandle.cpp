// Generated from /pastry-2.1/src/rice/p2p/past/ContentHashPastContentHandle.java
#include <rice/p2p/past/ContentHashPastContentHandle.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::past::ContentHashPastContentHandle::ContentHashPastContentHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::ContentHashPastContentHandle::ContentHashPastContentHandle(::rice::p2p::commonapi::NodeHandle* nh, ::rice::p2p::commonapi::Id* id) 
    : ContentHashPastContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(nh,id);
}

rice::p2p::past::ContentHashPastContentHandle::ContentHashPastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : ContentHashPastContentHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::past::ContentHashPastContentHandle::TYPE;

void rice::p2p::past::ContentHashPastContentHandle::ctor(::rice::p2p::commonapi::NodeHandle* nh, ::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    storageNode = nh;
    myId = id;
}

rice::p2p::commonapi::Id* rice::p2p::past::ContentHashPastContentHandle::getId()
{
    return myId;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::past::ContentHashPastContentHandle::getNodeHandle()
{
    return storageNode;
}

void rice::p2p::past::ContentHashPastContentHandle::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    myId = npc(endpoint)->readId(buf, npc(buf)->readShort());
    storageNode = npc(endpoint)->readNodeHandle(buf);
}

void rice::p2p::past::ContentHashPastContentHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(myId)->getType());
    npc(myId)->serialize(buf);
    npc(storageNode)->serialize(buf);
}

int16_t rice::p2p::past::ContentHashPastContentHandle::getType()
{
    return TYPE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::ContentHashPastContentHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.ContentHashPastContentHandle", 42);
    return c;
}

java::lang::Class* rice::p2p::past::ContentHashPastContentHandle::getClass0()
{
    return class_();
}

