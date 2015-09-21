// Generated from /pastry-2.1/src/rice/p2p/replication/manager/messaging/ReminderMessage.java
#include <rice/p2p/replication/manager/messaging/ReminderMessage.hpp>

rice::p2p::replication::manager::messaging::ReminderMessage::ReminderMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::manager::messaging::ReminderMessage::ReminderMessage() 
    : ReminderMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::replication::manager::messaging::ReminderMessage::ctor()
{
    super::ctor();
}

int32_t rice::p2p::replication::manager::messaging::ReminderMessage::getPriority()
{
    return MEDIUM_PRIORITY;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::manager::messaging::ReminderMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.manager.messaging.ReminderMessage", 54);
    return c;
}

java::lang::Class* rice::p2p::replication::manager::messaging::ReminderMessage::getClass0()
{
    return class_();
}

