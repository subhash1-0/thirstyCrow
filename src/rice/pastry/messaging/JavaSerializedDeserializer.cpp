// Generated from /pastry-2.1/src/rice/pastry/messaging/JavaSerializedDeserializer.java
#include <rice/pastry/messaging/JavaSerializedDeserializer.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/StreamCorruptedException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Message.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/pastry/PastryNode.hpp>
#include <rice/pastry/messaging/PastryObjectInputStream.hpp>
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

rice::pastry::messaging::JavaSerializedDeserializer::JavaSerializedDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::messaging::JavaSerializedDeserializer::JavaSerializedDeserializer(::rice::pastry::PastryNode* pn) 
    : JavaSerializedDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor(pn);
}

void rice::pastry::messaging::JavaSerializedDeserializer::init()
{
    deserializeOnlyTypeZero = true;
}

void rice::pastry::messaging::JavaSerializedDeserializer::ctor(::rice::pastry::PastryNode* pn)
{
    super::ctor();
    init();
    this->pn = pn;
}

void rice::pastry::messaging::JavaSerializedDeserializer::setAlwaysUseJavaSerialization(bool val)
{
    deserializeOnlyTypeZero = !val;
}

rice::p2p::commonapi::Message* rice::pastry::messaging::JavaSerializedDeserializer::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, int16_t type, int32_t priority, ::rice::p2p::commonapi::NodeHandle* sender) /* throws(IOException) */
{
    if(deserializeOnlyTypeZero && (type != 0))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Type must be zero, was "_j)->append(type)
            ->append(u".  See http://freepastry.org/FreePastry/extendingRawMessages.html for more information."_j)->toString());

    ::java::lang::Object* o = nullptr;
    try {
        auto array = new ::int8_tArray(npc(buf)->bytesRemaining());
        npc(buf)->read(array);
        ::java::io::ObjectInputStream* ois = new PastryObjectInputStream(new ::java::io::ByteArrayInputStream(array), pn);
        o = npc(ois)->readObject();
        auto ret = java_cast< ::rice::p2p::commonapi::Message* >(o);
        return ret;
    } catch (::java::io::StreamCorruptedException* sce) {
        if(!deserializeOnlyTypeZero)
            throw new ::java::lang::RuntimeException(u"Not a java serialized message!  See http://freepastry.org/FreePastry/extendingRawMessages.html for more information."_j, sce);
        else
            throw sce;
    } catch (::java::lang::ClassNotFoundException* e) {
        throw new ::java::lang::RuntimeException(u"Unknown class type in message - closing channel."_j, e);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::messaging::JavaSerializedDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.messaging.JavaSerializedDeserializer", 48);
    return c;
}

java::lang::Class* rice::pastry::messaging::JavaSerializedDeserializer::getClass0()
{
    return class_();
}

