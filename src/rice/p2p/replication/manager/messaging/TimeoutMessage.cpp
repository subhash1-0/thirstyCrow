// Generated from /pastry-2.1/src/rice/p2p/replication/manager/messaging/TimeoutMessage.java
#include <rice/p2p/replication/manager/messaging/TimeoutMessage.hpp>

#include <rice/p2p/commonapi/Id.hpp>

rice::p2p::replication::manager::messaging::TimeoutMessage::TimeoutMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::manager::messaging::TimeoutMessage::TimeoutMessage(::rice::p2p::commonapi::Id* id) 
    : TimeoutMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(id);
}

void rice::p2p::replication::manager::messaging::TimeoutMessage::ctor(::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
}

int32_t rice::p2p::replication::manager::messaging::TimeoutMessage::getPriority()
{
    return MEDIUM_PRIORITY;
}

rice::p2p::commonapi::Id* rice::p2p::replication::manager::messaging::TimeoutMessage::getId()
{
    return id;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::messaging::TimeoutMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.messaging.TimeoutMessage", 53);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::messaging::TimeoutMessage::getClass0()
{
    return class_();
}

