// Generated from /pastry-2.1/src/rice/p2p/past/messaging/ContinuationMessage.java
#include <rice/p2p/past/messaging/ContinuationMessage.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/Continuation.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/util/rawserialization/JavaDeserializer.hpp>
#include <rice/p2p/util/rawserialization/JavaSerializationException.hpp>
#include <Array.hpp>

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

rice::p2p::past::messaging::ContinuationMessage::ContinuationMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::messaging::ContinuationMessage::ContinuationMessage(int32_t uid, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : ContinuationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,source,dest);
}

rice::p2p::past::messaging::ContinuationMessage::ContinuationMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : ContinuationMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int64_t rice::p2p::past::messaging::ContinuationMessage::serialVersionUID;

void rice::p2p::past::messaging::ContinuationMessage::ctor(int32_t uid, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
}

void rice::p2p::past::messaging::ContinuationMessage::receiveResult(::java::lang::Object* o)
{
    setResponse();
    response = o;
}

void rice::p2p::past::messaging::ContinuationMessage::receiveException(::java::lang::Exception* e)
{
    setResponse();
    exception = e;
}

void rice::p2p::past::messaging::ContinuationMessage::returnResponse(::rice::Continuation* c, ::rice::environment::Environment* env, ::java::lang::String* instance)
{
    if(exception == nullptr)
        npc(c)->receiveResult(response);
    else
        npc(c)->receiveException(exception);
}

java::lang::Object* rice::p2p::past::messaging::ContinuationMessage::getResponse()
{
    return response;
}

int8_t& rice::p2p::past::messaging::ContinuationMessage::S_EMPTY()
{
    clinit();
    return S_EMPTY_;
}
int8_t rice::p2p::past::messaging::ContinuationMessage::S_EMPTY_;

int8_t& rice::p2p::past::messaging::ContinuationMessage::S_SUB()
{
    clinit();
    return S_SUB_;
}
int8_t rice::p2p::past::messaging::ContinuationMessage::S_SUB_;

int8_t& rice::p2p::past::messaging::ContinuationMessage::S_JAVA_RESPONSE()
{
    clinit();
    return S_JAVA_RESPONSE_;
}
int8_t rice::p2p::past::messaging::ContinuationMessage::S_JAVA_RESPONSE_;

int8_t& rice::p2p::past::messaging::ContinuationMessage::S_JAVA_EXCEPTION()
{
    clinit();
    return S_JAVA_EXCEPTION_;
}
int8_t rice::p2p::past::messaging::ContinuationMessage::S_JAVA_EXCEPTION_;

void rice::p2p::past::messaging::ContinuationMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    serType = npc(buf)->readByte();
    if(serType > S_SUB_)
        deserialize(buf, endpoint);

}

void rice::p2p::past::messaging::ContinuationMessage::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    auto array = new ::int8_tArray(npc(buf)->readInt());
    npc(buf)->read(array);
    ::java::io::ObjectInputStream* ois = new ::rice::p2p::util::rawserialization::JavaDeserializer(new ::java::io::ByteArrayInputStream(array), endpoint);
    ::java::lang::Object* content;
    try {
        content = npc(ois)->readObject();
        if(serType == S_JAVA_RESPONSE_) {
            response = content;
        } else {
            exception = java_cast< ::java::lang::Exception* >(content);
        }
    } catch (::java::lang::ClassNotFoundException* e) {
        throw new ::java::lang::RuntimeException(u"Unknown class type in message - closing channel."_j, e);
    }
}

void rice::p2p::past::messaging::ContinuationMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize) /* throws(IOException) */
{
    super::serialize(buf);
    serType = S_EMPTY_;
    if(javaSerialize) {
        auto content = response;
        if(response != nullptr) {
            serType = S_JAVA_RESPONSE_;
        } else {
            serType = S_JAVA_EXCEPTION_;
            content = exception;
        }
        if(content == nullptr) {
            serType = S_EMPTY_;
            npc(buf)->writeByte(serType);
        } else {
            try {
                npc(buf)->writeByte(serType);
                auto baos = new ::java::io::ByteArrayOutputStream();
                auto oos = new ::java::io::ObjectOutputStream(baos);
                npc(oos)->writeObject(content);
                npc(oos)->close();
                auto temp = npc(baos)->toByteArray_();
                npc(buf)->writeInt(npc(temp)->length);
                npc(buf)->write(temp, 0, npc(temp)->length);
            } catch (::java::io::IOException* ioe) {
                throw new ::rice::p2p::util::rawserialization::JavaSerializationException(content, ioe);
            }
        }
    } else {
        npc(buf)->writeByte(S_SUB_);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::messaging::ContinuationMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.messaging.ContinuationMessage", 43);
    return c;
}

void rice::p2p::past::messaging::ContinuationMessage::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        S_EMPTY_ = int32_t(0);
        S_SUB_ = int32_t(1);
        S_JAVA_RESPONSE_ = int32_t(3);
        S_JAVA_EXCEPTION_ = int32_t(2);
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::past::messaging::ContinuationMessage::getClass0()
{
    return class_();
}

