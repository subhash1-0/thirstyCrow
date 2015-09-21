// Generated from /pastry-2.1/src/rice/pastry/messaging/PRawMessage.java
#include <rice/pastry/messaging/PRawMessage.hpp>

rice::pastry::messaging::PRawMessage::PRawMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::PRawMessage::PRawMessage(int32_t address) 
    : PRawMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

rice::pastry::messaging::PRawMessage::PRawMessage(int32_t address, ::java::util::Date* timestamp) 
    : PRawMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(address,timestamp);
}

void rice::pastry::messaging::PRawMessage::ctor(int32_t address)
{
    ctor(address, nullptr);
}

void rice::pastry::messaging::PRawMessage::ctor(int32_t address, ::java::util::Date* timestamp)
{
    super::ctor(address, timestamp);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::PRawMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.PRawMessage", 33);
    return c;
}

int32_t rice::pastry::messaging::PRawMessage::getPriority()
{
    return Message::getPriority();
}

java::lang::Class* rice::pastry::messaging::PRawMessage::getClass0()
{
    return class_();
}

