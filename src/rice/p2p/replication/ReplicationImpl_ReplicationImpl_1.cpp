// Generated from /pastry-2.1/src/rice/p2p/replication/ReplicationImpl.java
#include <rice/p2p/replication/ReplicationImpl_ReplicationImpl_1.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/replication/ReplicationImpl.hpp>
#include <rice/p2p/replication/messaging/RequestMessage.hpp>
#include <rice/p2p/replication/messaging/ResponseMessage.hpp>

rice::p2p::replication::ReplicationImpl_ReplicationImpl_1::ReplicationImpl_ReplicationImpl_1(ReplicationImpl *ReplicationImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , ReplicationImpl_this(ReplicationImpl_this)
{
    clinit();
    ctor();
}

rice::p2p::commonapi::Message* rice::p2p::replication::ReplicationImpl_ReplicationImpl_1::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    switch (type) {
    case ::rice::p2p::replication::messaging::RequestMessage::TYPE:
        return ::rice::p2p::replication::messaging::RequestMessage::build(buf, ReplicationImpl_this->endpoint);
    case ::rice::p2p::replication::messaging::ResponseMessage::TYPE:
        return ::rice::p2p::replication::messaging::ResponseMessage::build(buf, ReplicationImpl_this->endpoint);
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unknown type:"_j)->append(type)->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::ReplicationImpl_ReplicationImpl_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::replication::ReplicationImpl_ReplicationImpl_1::getClass0()
{
    return class_();
}

