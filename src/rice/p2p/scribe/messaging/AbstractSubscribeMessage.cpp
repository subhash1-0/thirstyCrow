// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/AbstractSubscribeMessage.java
#include <rice/p2p/scribe/messaging/AbstractSubscribeMessage.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/Topic.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::scribe::messaging::AbstractSubscribeMessage::AbstractSubscribeMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::AbstractSubscribeMessage::AbstractSubscribeMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id) 
    : AbstractSubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topics,id);
}

rice::p2p::scribe::messaging::AbstractSubscribeMessage::AbstractSubscribeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : AbstractSubscribeMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

void rice::p2p::scribe::messaging::AbstractSubscribeMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, int32_t id)
{
    super::ctor();
    this->source = source;
    this->id = id;
    this->topics = topics;
}

int32_t rice::p2p::scribe::messaging::AbstractSubscribeMessage::getId()
{
    return id;
}

int32_t rice::p2p::scribe::messaging::AbstractSubscribeMessage::getPriority()
{
    return MEDIUM_HIGH_PRIORITY;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::AbstractSubscribeMessage::getSource()
{
    return source;
}

java::util::List* rice::p2p::scribe::messaging::AbstractSubscribeMessage::getTopics()
{
    return topics;
}

java::lang::String* rice::p2p::scribe::messaging::AbstractSubscribeMessage::toString()
{
    auto s = ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(source))->append(u","_j)
        ->append(id)->toString();
    if(npc(topics)->size() <= 3) {
        for (auto _i = npc(topics)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::scribe::Topic* topic = java_cast< ::rice::p2p::scribe::Topic* >(_i->next());
            {
                s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" "_j)->append(static_cast< ::java::lang::Object* >(topic))->toString())->toString();
            }
        }
    } else {
        s = ::java::lang::StringBuilder(s).append(::java::lang::StringBuilder().append(u" numTopics:"_j)->append(npc(topics)->size())->toString())->toString();
    }
    return s;
}

void rice::p2p::scribe::messaging::AbstractSubscribeMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    source = npc(endpoint)->readNodeHandle(buf);
    id = npc(buf)->readInt();
}

void rice::p2p::scribe::messaging::AbstractSubscribeMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(source)->serialize(buf);
    npc(buf)->writeInt(id);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::AbstractSubscribeMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.AbstractSubscribeMessage", 50);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::AbstractSubscribeMessage::getClass0()
{
    return class_();
}

