// Generated from /pastry-2.1/src/rice/p2p/scribe/messaging/AnycastMessage.java
#include <rice/p2p/scribe/messaging/AnycastMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/NodeHandle.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/scribe/Topic.hpp>
#include <rice/p2p/scribe/rawserialization/JavaSerializedScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/RawScribeContent.hpp>
#include <rice/p2p/scribe/rawserialization/ScribeContentDeserializer.hpp>

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

rice::p2p::scribe::messaging::AnycastMessage::AnycastMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::messaging::AnycastMessage::AnycastMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content) 
    : AnycastMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic,content);
}

rice::p2p::scribe::messaging::AnycastMessage::AnycastMessage(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content) 
    : AnycastMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,topic,content);
}

rice::p2p::scribe::messaging::AnycastMessage::AnycastMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd)  /* throws(IOException) */
    : AnycastMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,cd);
}

constexpr int16_t rice::p2p::scribe::messaging::AnycastMessage::TYPE;

void rice::p2p::scribe::messaging::AnycastMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::ScribeContent* content)
{
    ctor(source, topic, dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr ? java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) : static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content)));
}

void rice::p2p::scribe::messaging::AnycastMessage::ctor(::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::scribe::Topic* topic, ::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    super::ctor(source, topic);
    this->initialRequestor = source;
    this->content = content;
    this->visited = new ::java::util::ArrayList();
    this->toVisit = new ::java::util::LinkedList();
    addVisited(source);
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::messaging::AnycastMessage::getContent()
{
    if(content == nullptr)
        return nullptr;

    if(npc(content)->getType() == 0)
        return npc((java_cast< ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent* >(content)))->getContent();

    return content;
}

rice::p2p::scribe::rawserialization::RawScribeContent* rice::p2p::scribe::messaging::AnycastMessage::getRawContent()
{
    return content;
}

void rice::p2p::scribe::messaging::AnycastMessage::setContent(::rice::p2p::scribe::rawserialization::RawScribeContent* content)
{
    this->content = content;
}

void rice::p2p::scribe::messaging::AnycastMessage::setContent(::rice::p2p::scribe::ScribeContent* content)
{
    if(dynamic_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(content) != nullptr) {
        setContent(content);
    } else {
        setContent(static_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(content)));
    }
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::AnycastMessage::peekNext()
{
    if(npc(toVisit)->size() == 0) {
        return nullptr;
    }
    return java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(toVisit)->getFirst()));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::AnycastMessage::getNext()
{
    if(npc(toVisit)->size() == 0) {
        return nullptr;
    }
    return java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(toVisit)->removeFirst()));
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::AnycastMessage::peekLastToVisit()
{
    return java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(toVisit)->getLast());
}

void rice::p2p::scribe::messaging::AnycastMessage::addVisited(::rice::p2p::commonapi::NodeHandle* handle)
{
    if(handle == nullptr) {
        return;
    }
    if(!npc(visited)->contains(static_cast< ::java::lang::Object* >(handle))) {
        npc(visited)->add(static_cast< ::java::lang::Object* >(handle));
    }
    while (npc(toVisit)->remove(static_cast< ::java::lang::Object* >(handle))) {
        npc(toVisit)->remove(static_cast< ::java::lang::Object* >(handle));
    }
}

void rice::p2p::scribe::messaging::AnycastMessage::addFirst(::rice::p2p::commonapi::NodeHandle* handle)
{
    if(handle == nullptr) {
        return;
    }
    if((!npc(toVisit)->contains(static_cast< ::java::lang::Object* >(handle))) && (!npc(visited)->contains(static_cast< ::java::lang::Object* >(handle)))) {
        npc(toVisit)->addFirst(static_cast< ::java::lang::Object* >(handle));
    }
}

void rice::p2p::scribe::messaging::AnycastMessage::addLast(::rice::p2p::commonapi::NodeHandle* handle)
{
    if(handle == nullptr) {
        return;
    }
    if((!npc(toVisit)->contains(static_cast< ::java::lang::Object* >(handle))) && (!npc(visited)->contains(static_cast< ::java::lang::Object* >(handle)))) {
        npc(toVisit)->addLast(static_cast< ::java::lang::Object* >(handle));
    }
}

java::lang::String* rice::p2p::scribe::messaging::AnycastMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"Anycast["_j)->append(static_cast< ::java::lang::Object* >(getTopic()))
        ->append(u" "_j)
        ->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"]"_j)->toString();
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::AnycastMessage::getInitialRequestor()
{
    return initialRequestor;
}

rice::p2p::commonapi::NodeHandle* rice::p2p::scribe::messaging::AnycastMessage::getLastVisited()
{
    if(npc(visited)->size() == 0) {
        return nullptr;
    } else {
        return java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(visited)->get(npc(visited)->size() - int32_t(1)));
    }
}

void rice::p2p::scribe::messaging::AnycastMessage::remove(::rice::p2p::commonapi::NodeHandle* handle)
{
    if(handle == nullptr) {
        return;
    }
    npc(toVisit)->remove(static_cast< ::java::lang::Object* >(handle));
    npc(visited)->remove(static_cast< ::java::lang::Object* >(handle));
}

int32_t rice::p2p::scribe::messaging::AnycastMessage::getVisitedSize()
{
    return npc(visited)->size();
}

int32_t rice::p2p::scribe::messaging::AnycastMessage::getToVisitSize()
{
    return npc(toVisit)->size();
}

bool rice::p2p::scribe::messaging::AnycastMessage::hasVisited(::rice::p2p::commonapi::NodeHandle* handle)
{
    return npc(visited)->contains(static_cast< ::java::lang::Object* >(handle));
}

int16_t rice::p2p::scribe::messaging::AnycastMessage::getType()
{
    return TYPE;
}

void rice::p2p::scribe::messaging::AnycastMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(1)));
    serializeHelper(buf);
}

void rice::p2p::scribe::messaging::AnycastMessage::serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    super::serialize(buf);
    npc(initialRequestor)->serialize(buf);
    npc(buf)->writeInt(npc(toVisit)->size());
    auto i = npc(toVisit)->iterator();
    while (npc(i)->hasNext()) {
        npc((java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(i)->next()))))->serialize(buf);
    }
    npc(buf)->writeInt(npc(visited)->size());
    i = npc(visited)->iterator();
    while (npc(i)->hasNext()) {
        npc((java_cast< ::rice::p2p::commonapi::NodeHandle* >(java_cast< ::rice::p2p::commonapi::NodeHandle* >(npc(i)->next()))))->serialize(buf);
    }
    if(content == nullptr) {
        npc(buf)->writeBoolean(false);
    } else {
        npc(buf)->writeBoolean(true);
        npc(buf)->writeShort(npc(content)->getType());
        npc(content)->serialize(buf);
    }
}

rice::p2p::scribe::messaging::AnycastMessage* rice::p2p::scribe::messaging::AnycastMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* scd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(1):
        return new AnycastMessage(buf, endpoint, scd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::scribe::messaging::AnycastMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::scribe::rawserialization::ScribeContentDeserializer* cd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    initialRequestor = npc(endpoint)->readNodeHandle(buf);
    toVisit = new ::java::util::LinkedList();
    auto toVisitLength = npc(buf)->readInt();
    for (auto i = int32_t(0); i < toVisitLength; i++) {
        npc(toVisit)->addLast(static_cast< ::java::lang::Object* >(npc(endpoint)->readNodeHandle(buf)));
    }
    auto visitedLength = npc(buf)->readInt();
    visited = new ::java::util::ArrayList(visitedLength);
    for (auto i = int32_t(0); i < visitedLength; i++) {
        npc(visited)->add(static_cast< ::java::lang::Object* >(npc(endpoint)->readNodeHandle(buf)));
    }
    if(npc(buf)->readBoolean()) {
        auto contentType = npc(buf)->readShort();
        if(contentType == 0) {
            content = new ::rice::p2p::scribe::rawserialization::JavaSerializedScribeContent(npc(cd)->deserializeScribeContent(buf, endpoint, contentType));
        } else {
            content = java_cast< ::rice::p2p::scribe::rawserialization::RawScribeContent* >(npc(cd)->deserializeScribeContent(buf, endpoint, contentType));
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::messaging::AnycastMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.messaging.AnycastMessage", 40);
    return c;
}

java::lang::Class* rice::p2p::scribe::messaging::AnycastMessage::getClass0()
{
    return class_();
}

