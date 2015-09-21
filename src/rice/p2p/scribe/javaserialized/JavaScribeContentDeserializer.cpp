// Generated from /pastry-2.1/src/rice/p2p/scribe/javaserialized/JavaScribeContentDeserializer.java
#include <rice/p2p/scribe/javaserialized/JavaScribeContentDeserializer.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/scribe/ScribeContent.hpp>
#include <rice/p2p/util/rawserialization/JavaDeserializer.hpp>
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

rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer::JavaScribeContentDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer::JavaScribeContentDeserializer() 
    : JavaScribeContentDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer::ctor()
{
    super::ctor();
}

rice::p2p::scribe::ScribeContent* rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer::deserializeScribeContent(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    auto array = new ::int8_tArray(npc(buf)->readInt());
    npc(buf)->read(array);
    ::java::io::ObjectInputStream* ois = new ::rice::p2p::util::rawserialization::JavaDeserializer(new ::java::io::ByteArrayInputStream(array), endpoint);
    try {
        auto o = npc(ois)->readObject();
        auto ret = java_cast< ::rice::p2p::scribe::ScribeContent* >(o);
        return ret;
    } catch (::java::lang::ClassNotFoundException* e) {
        throw new ::java::lang::RuntimeException(u"Unknown class type in message - cant deserialize."_j, e);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.scribe.javaserialized.JavaScribeContentDeserializer", 60);
    return c;
}

java::lang::Class* rice::p2p::scribe::javaserialized::JavaScribeContentDeserializer::getClass0()
{
    return class_();
}

