// Generated from /pastry-2.1/src/rice/pastry/ScheduledMessage.java
#include <rice/pastry/ScheduledMessage.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/Message.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::ScheduledMessage::ScheduledMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::ScheduledMessage::ScheduledMessage(PastryNode* pn, ::rice::pastry::messaging::Message* msg) 
    : ScheduledMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn,msg);
}

void rice::pastry::ScheduledMessage::ctor(PastryNode* pn, ::rice::pastry::messaging::Message* msg)
{
    super::ctor();
    localNode = pn;
    this->msg = msg;
}

rice::pastry::messaging::Message* rice::pastry::ScheduledMessage::getMessage()
{
    return msg;
}

rice::pastry::PastryNode* rice::pastry::ScheduledMessage::getLocalNode()
{
    return localNode;
}

void rice::pastry::ScheduledMessage::run()
{
    try {
        auto m = msg;
        if(m != nullptr)
            npc(localNode)->receiveMessage(msg);

    } catch (::java::lang::Exception* e) {
        auto logger = npc(npc(npc(localNode)->getEnvironment())->getLogManager())->getLogger(getClass(), nullptr);
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Delivering "_j)->append(static_cast< ::java::lang::Object* >(this))
                ->append(u" caused exception "_j)->toString(), e);

    }
}

java::lang::String* rice::pastry::ScheduledMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"SchedMsg for "_j)->append(static_cast< ::java::lang::Object* >(msg))->toString();
}

bool rice::pastry::ScheduledMessage::cancel()
{
    msg = nullptr;
    localNode = nullptr;
    return super::cancel();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::ScheduledMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.ScheduledMessage", 28);
    return c;
}

java::lang::Class* rice::pastry::ScheduledMessage::getClass0()
{
    return class_();
}

