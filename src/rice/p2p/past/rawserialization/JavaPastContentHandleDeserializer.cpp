// Generated from /pastry-2.1/src/rice/p2p/past/rawserialization/JavaPastContentHandleDeserializer.java
#include <rice/p2p/past/rawserialization/JavaPastContentHandleDeserializer.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/past/ContentHashPastContentHandle.hpp>
#include <rice/p2p/past/PastContentHandle.hpp>
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

rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer::JavaPastContentHandleDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer::JavaPastContentHandleDeserializer()
    : JavaPastContentHandleDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::past::PastContentHandle* rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer::deserializePastContentHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint, int16_t contentType) /* throws(IOException) */
{
    {
        ::int8_tArray* array;
        ::java::io::ObjectInputStream* ois;
        switch (contentType) {
        case int32_t(0):
            array = new ::int8_tArray(npc(buf)->readInt());
            npc(buf)->read(array);
            ois = new ::rice::p2p::util::rawserialization::JavaDeserializer(new ::java::io::ByteArrayInputStream(array), endpoint);
            try {
                auto o = npc(ois)->readObject();
                auto ret = java_cast< ::rice::p2p::past::PastContentHandle* >(o);
                return ret;
            } catch (::java::lang::ClassNotFoundException* e) {
                throw new ::java::lang::RuntimeException(u"Unknown class type in message - cant deserialize."_j, e);
            }
        case ::rice::p2p::past::ContentHashPastContentHandle::TYPE:
            return new ::rice::p2p::past::ContentHashPastContentHandle(buf, endpoint);
        }
    }

    throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"contentType must be 0 was:"_j)->append(contentType)
        ->append(u" endpoint:"_j)
        ->append(static_cast< ::java::lang::Object* >(endpoint))->toString());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.rawserialization.JavaPastContentHandleDeserializer", 64);
    return c;
}

java::lang::Class* rice::p2p::past::rawserialization::JavaPastContentHandleDeserializer::getClass0()
{
    return class_();
}

