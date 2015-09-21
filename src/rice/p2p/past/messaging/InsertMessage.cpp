// Generated from /pastry-2.1/src/rice/p2p/past/messaging/InsertMessage.java
#include <rice/p2p/past/messaging/InsertMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/PastContent.hpp>
#include <rice/p2p/past/rawserialization/JavaSerializedPastContent.hpp>
#include <rice/p2p/past/rawserialization/PastContentDeserializer.hpp>
#include <rice/p2p/past/rawserialization/RawPastContent.hpp>

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

rice::p2p::past::messaging::InsertMessage::InsertMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::InsertMessage::InsertMessage(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : InsertMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,content,source,dest);
}

rice::p2p::past::messaging::InsertMessage::InsertMessage(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : InsertMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,content,source,dest);
}

rice::p2p::past::messaging::InsertMessage::InsertMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd)  /* throws(IOException) */
    : InsertMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint,pcd);
}

constexpr int16_t rice::p2p::past::messaging::InsertMessage::TYPE;

constexpr int64_t rice::p2p::past::messaging::InsertMessage::serialVersionUID;

void rice::p2p::past::messaging::InsertMessage::ctor(int32_t uid, ::rice::p2p::past::PastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    ctor(uid, dynamic_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(content) != nullptr ? java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(content) : static_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(content)), source, dest);
}

void rice::p2p::past::messaging::InsertMessage::ctor(int32_t uid, ::rice::p2p::past::rawserialization::RawPastContent* content, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    this->content = content;
}

rice::p2p::past::PastContent* rice::p2p::past::messaging::InsertMessage::getContent()
{
    if(npc(content)->getType() == 0)
        return npc((java_cast< ::rice::p2p::past::rawserialization::JavaSerializedPastContent* >(content)))->getContent();

    return content;
}

void rice::p2p::past::messaging::InsertMessage::receiveResult(::java::lang::Object* o)
{
    super::receiveResult(o);
    content = nullptr;
}

void rice::p2p::past::messaging::InsertMessage::receiveException(::java::lang::Exception* e)
{
    super::receiveException(e);
    content = nullptr;
}

java::lang::String* rice::p2p::past::messaging::InsertMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[InsertMessage for "_j)->append(static_cast< ::java::lang::Object* >(content))
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::messaging::InsertMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::messaging::InsertMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    serializeHelper(buf);
}

void rice::p2p::past::messaging::InsertMessage::serializeHelper(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    if(response != nullptr && dynamic_cast< ::java::lang::Boolean* >(response) != nullptr) {
        super::serialize(buf, false);
        npc(buf)->writeBoolean(npc((java_cast< ::java::lang::Boolean* >(response)))->booleanValue());
    } else {
        super::serialize(buf, true);
    }
    npc(buf)->writeBoolean(content != nullptr);
    if(content != nullptr) {
        npc(buf)->writeShort(npc(content)->getType());
        npc(content)->serialize(buf);
    }
}

rice::p2p::past::messaging::InsertMessage* rice::p2p::past::messaging::InsertMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new InsertMessage(buf, endpoint, pcd);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::messaging::InsertMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, ::rice::p2p::past::rawserialization::PastContentDeserializer* pcd) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    if(serType == S_SUB()) {
        response = new ::java::lang::Boolean(npc(buf)->readBoolean());
    }
    if(npc(buf)->readBoolean()) {
        auto contentType = npc(buf)->readShort();
        if(contentType == 0) {
            content = new ::rice::p2p::past::rawserialization::JavaSerializedPastContent(npc(pcd)->deserializePastContent(buf, endpoint, contentType));
        } else {
            content = java_cast< ::rice::p2p::past::rawserialization::RawPastContent* >(npc(pcd)->deserializePastContent(buf, endpoint, contentType));
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::InsertMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.InsertMessage", 37);
    return c;
}

void rice::p2p::past::messaging::InsertMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::messaging::InsertMessage::getClass0()
{
    return class_();
}

