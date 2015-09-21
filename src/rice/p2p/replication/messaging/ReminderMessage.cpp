// Generated from /pastry-2.1/src/rice/p2p/replication/messaging/ReminderMessage.java
#include <rice/p2p/replication/messaging/ReminderMessage.hpp>

#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>

rice::p2p::replication::messaging::ReminderMessage::ReminderMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::replication::messaging::ReminderMessage::ReminderMessage(::rice::p2p::commonapi::NodeHandle* source) 
    : ReminderMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source);
}

constexpr int16_t rice::p2p::replication::messaging::ReminderMessage::TYPE;

void rice::p2p::replication::messaging::ReminderMessage::ctor(::rice::p2p::commonapi::NodeHandle* source)
{
    super::ctor(source);
}

int16_t rice::p2p::replication::messaging::ReminderMessage::getType()
{
    return TYPE;
}

void rice::p2p::replication::messaging::ReminderMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"serialize() not supported in MaintenanceMessage"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::replication::messaging::ReminderMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.replication.messaging.ReminderMessage", 46);
    return c;
}

java::lang::Class* rice::p2p::replication::messaging::ReminderMessage::getClass0()
{
    return class_();
}

