// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/MaintenanceMessage.java
#include <rice/p2p/scribe/messaging/MaintenanceMessage.hpp>

#include <java/lang/String.hpp>

rice::p2p::scribe::messaging::MaintenanceMessage::MaintenanceMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::MaintenanceMessage::MaintenanceMessage() 
    : MaintenanceMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::scribe::messaging::MaintenanceMessage::ctor()
{
    super::ctor();
}

int32_t rice::p2p::scribe::messaging::MaintenanceMessage::getPriority()
{
    return DEFAULT_PRIORITY;
}

java::lang::String* rice::p2p::scribe::messaging::MaintenanceMessage::toString()
{
    return u"MaintenanceMessage"_j;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::MaintenanceMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.MaintenanceMessage", 44);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::MaintenanceMessage::getClass0()
{
    return class_();
}

