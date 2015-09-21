// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregateHandle.java
#include <rice/p2p/aggregation/AggregateHandle.hpp>

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

rice::p2p::aggregation::AggregateHandle::AggregateHandle(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::aggregation::AggregateHandle::AggregateHandle(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration) 
    : AggregateHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle,id,version,expiration);
}

rice::p2p::aggregation::AggregateHandle::AggregateHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : AggregateHandle(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::aggregation::AggregateHandle::TYPE;

void rice::p2p::aggregation::AggregateHandle::ctor(::rice::p2p::commonapi::NodeHandle* handle, ::rice::p2p::commonapi::Id* id, int64_t version, int64_t expiration)
{
    super::ctor();
    this->id = id;
    this->handle = handle;
    this->version = version;
    this->expiration = expiration;
}

rice::p2p::commonapi::Id* rice::p2p::aggregation::AggregateHandle::getId()
{
    return id;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::aggregation::AggregateHandle::getNodeHandle()
{
    return handle;
}

int64_t rice::p2p::aggregation::AggregateHandle::getVersion()
{
    return version;
}

int64_t rice::p2p::aggregation::AggregateHandle::getExpiration()
{
    return expiration;
}

int16_t rice::p2p::aggregation::AggregateHandle::getType()
{
    return TYPE;
}

void rice::p2p::aggregation::AggregateHandle::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    version = npc(buf)->readLong();
    expiration = npc(buf)->readLong();
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
    handle = npc(endpoint)->readNodeHandle(buf);
}

void rice::p2p::aggregation::AggregateHandle::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(version);
    npc(buf)->writeLong(expiration);
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
    npc(handle)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::aggregation::AggregateHandle::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.aggregation.AggregateHandle", 36);
    return c;
}

java::lang::Class* rice::p2p::aggregation::AggregateHandle::getClass0()
{
    return class_();
}

