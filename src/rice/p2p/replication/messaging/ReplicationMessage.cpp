// Generated from /pastry-2.1/src/rice/p2p/replication/messaging/ReplicationMessage.java
#include <rice/p2p/replication/messaging/ReplicationMessage.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::replication::messaging::ReplicationMessage::ReplicationMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::messaging::ReplicationMessage::ReplicationMessage(::rice::p2p::commonapi::NodeHandle* source) 
    : ReplicationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source);
}

rice::p2p::replication::messaging::ReplicationMessage::ReplicationMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : ReplicationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int64_t rice::p2p::replication::messaging::ReplicationMessage::serialVersionUID;

void rice::p2p::replication::messaging::ReplicationMessage::ctor(::rice::p2p::commonapi::NodeHandle* source)
{
    super::ctor();
    this->source = source;
}

int32_t rice::p2p::replication::messaging::ReplicationMessage::getPriority()
{
    return MEDIUM_PRIORITY;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::replication::messaging::ReplicationMessage::getSource()
{
    return source;
}

void rice::p2p::replication::messaging::ReplicationMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    source = npc(endpoint)->readNodeHandle(buf);
}

void rice::p2p::replication::messaging::ReplicationMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(source)->serialize(buf);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::messaging::ReplicationMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.messaging.ReplicationMessage", 49);
    return c;
}

java::lang::Class* rice::p2p::replication::messaging::ReplicationMessage::getClass0()
{
    return class_();
}

