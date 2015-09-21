// Generated from /pastry-2.1/src/rice/pastry/messaging/Message.java
#include <rice/pastry/messaging/Message.hpp>

#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Date.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/NodeHandle.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::pastry::messaging::Message::Message(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::Message::Message(int32_t dest) 
    : Message(*static_cast< ::default_init_tag* >(0))
{
    ctor(dest);
}

rice::pastry::messaging::Message::Message(int32_t dest, ::java::util::Date* timestamp) 
    : Message(*static_cast< ::default_init_tag* >(0))
{
    ctor(dest,timestamp);
}

void rice::pastry::messaging::Message::init()
{
    priorityLevel = ::rice::pastry::messaging::Message::DEFAULT_PRIORITY_LEVEL;
}

constexpr int64_t rice::pastry::messaging::Message::serialVersionUID;

constexpr int32_t rice::pastry::messaging::Message::DEFAULT_PRIORITY_LEVEL;

void rice::pastry::messaging::Message::ctor(int32_t dest)
{
    ctor(dest, nullptr);
}

void rice::pastry::messaging::Message::ctor(int32_t dest, ::java::util::Date* timestamp)
{
    super::ctor();
    init();
    if(dest == 0)
        throw new ::java::lang::IllegalArgumentException(u"dest must != 0"_j);

    destination = dest;
    this->theStamp = timestamp;
    sender = nullptr;
    priority = false;
}

int32_t rice::pastry::messaging::Message::getDestination()
{
    return destination;
}

java::util::Date* rice::pastry::messaging::Message::getDate()
{
    return theStamp;
}

rice::pastry::Id* rice::pastry::messaging::Message::getSenderId()
{
    if(sender == nullptr)
        return nullptr;

    return npc(sender)->getNodeId();
}

rice::pastry::NodeHandle* rice::pastry::messaging::Message::getSender()
{
    return sender;
}

void rice::pastry::messaging::Message::setSender(::rice::pastry::NodeHandle* nh)
{
    sender = nh;
}

int32_t rice::pastry::messaging::Message::getPriority()
{
    return priorityLevel;
}

void rice::pastry::messaging::Message::setPriority(int32_t prio)
{
    priorityLevel = prio;
}

bool rice::pastry::messaging::Message::stamp(::java::util::Date* time)
{
    if(theStamp == nullptr) {
        theStamp = time;
        return true;
    } else
        return false;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::Message::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.Message", 29);
    return c;
}

java::lang::Class* rice::pastry::messaging::Message::getClass0()
{
    return class_();
}

