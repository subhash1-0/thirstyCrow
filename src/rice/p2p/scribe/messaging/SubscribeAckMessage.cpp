// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/SubscribeAckMessage.java
#include <rice/p2p/scribe/messaging/SubscribeAckMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
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

rice::p2p::scribe::messaging::SubscribeAckMessage::SubscribeAckMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::SubscribeAckMessage::SubscribeAckMessage(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::java::util::List* pathsToRoot, int32_t id) 
    : SubscribeAckMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topics,pathsToRoot,id);
}

rice::p2p::scribe::messaging::SubscribeAckMessage::SubscribeAckMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : SubscribeAckMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::scribe::messaging::SubscribeAckMessage::TYPE;

void rice::p2p::scribe::messaging::SubscribeAckMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::java::util::List* topics, ::java::util::List* pathsToRoot, int32_t id)
{
    super::ctor(source, topics, id);
    if(npc(topics)->size() != npc(pathsToRoot)->size())
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Must be a path for each topic.  Topics: "_j)->append(npc(topics)->size())
            ->append(u" Paths:"_j)
            ->append(npc(pathsToRoot)->size())->toString());

    this->topics = topics;
    this->pathsToRoot = pathsToRoot;
}

java::util::List* rice::p2p::scribe::messaging::SubscribeAckMessage::getPathsToRoot()
{
    return pathsToRoot;
}

java::lang::String* rice::p2p::scribe::messaging::SubscribeAckMessage::toString()
{
    if(npc(topics)->size() == 1)
        return ::java::lang::StringBuilder().append(u"SubscribeAckMessage{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::rice::p2p::scribe::Topic* >(npc(topics)->get(0))))
            ->append(u" ID:"_j)
            ->append(id)
            ->append(u"}"_j)->toString();

    return ::java::lang::StringBuilder().append(u"SubscribeAckMessage{"_j)->append(npc(topics)->size())
        ->append(u" ID:"_j)
        ->append(id)
        ->append(u"}"_j)->toString();
}

int16_t rice::p2p::scribe::messaging::SubscribeAckMessage::getType()
{
    return TYPE;
}

void rice::p2p::scribe::messaging::SubscribeAckMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(1)));
    super::serialize(buf);
    auto numTopics = npc(topics)->size();
    npc(buf)->writeInt(numTopics);
    auto j = npc(topics)->iterator();
    auto i = npc(pathsToRoot)->iterator();
    while (npc(j)->hasNext()) {
        npc(java_cast< ::rice::p2p::scribe::Topic* >(npc(j)->next()))->serialize(buf);
        auto pathToRoot = java_cast< ::java::util::List* >(npc(i)->next());
        npc(buf)->writeInt(npc(pathToRoot)->size());
        for (auto _i = npc(pathToRoot)->iterator(); _i->hasNext(); ) {
            ::rice::p2p::commonapi::Id* id = java_cast< ::rice::p2p::commonapi::Id* >(_i->next());
            {
                npc(buf)->writeShort(npc(id)->getType());
                npc(id)->serialize(buf);
            }
        }
    }
}

rice::p2p::scribe::messaging::SubscribeAckMessage* rice::p2p::scribe::messaging::SubscribeAckMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return nullptr;
    case int32_t(1):
        return new SubscribeAckMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::scribe::messaging::SubscribeAckMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    auto numTopics = npc(buf)->readInt();
    topics = new ::java::util::ArrayList(numTopics);
    pathsToRoot = new ::java::util::ArrayList(numTopics);
    for (auto i = int32_t(0); i < numTopics; i++) {
        npc(topics)->add(static_cast< ::java::lang::Object* >(new ::rice::p2p::scribe::Topic(buf, endpoint)));
        auto length = npc(buf)->readInt();
        ::java::util::List* pathToRoot = new ::java::util::ArrayList(length);
        for (auto j = int32_t(0); j < length; j++) {
            npc(pathToRoot)->add(static_cast< ::java::lang::Object* >(npc(endpoint)->readId(buf, npc(buf)->readShort())));
        }
        npc(pathsToRoot)->add(static_cast< ::java::lang::Object* >(pathToRoot));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::SubscribeAckMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.SubscribeAckMessage", 45);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::SubscribeAckMessage::getClass0()
{
    return class_();
}

