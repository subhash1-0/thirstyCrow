// Generated from /pastry-2.1/src/rice/p2p/past/gc/messaging/GCRefreshMessage.java
#include <rice/p2p/past/gc/messaging/GCRefreshMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdSet.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
    } // lang
} // java

namespace rice
{
    namespace p2p
    {
        namespace commonapi
        {
typedef ::SubArray< ::rice::p2p::commonapi::Id, ::java::lang::ObjectArray, ::java::lang::ComparableArray, ::java::io::SerializableArray > IdArray;
        } // commonapi

        namespace past
        {
            namespace gc
            {
typedef ::SubArray< ::rice::p2p::past::gc::GCId, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > GCIdArray;
            } // gc
        } // past
    } // p2p
} // rice

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

rice::p2p::past::gc::messaging::GCRefreshMessage::GCRefreshMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::messaging::GCRefreshMessage::GCRefreshMessage(int32_t uid, ::rice::p2p::past::gc::GCIdSet* keys, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest) 
    : GCRefreshMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,keys,source,dest);
}

rice::p2p::past::gc::messaging::GCRefreshMessage::GCRefreshMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GCRefreshMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::past::gc::messaging::GCRefreshMessage::TYPE;

void rice::p2p::past::gc::messaging::GCRefreshMessage::ctor(int32_t uid, ::rice::p2p::past::gc::GCIdSet* keys, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest)
{
    super::ctor(uid, source, dest);
    this->keys = new ::rice::p2p::past::gc::GCIdArray(npc(keys)->numElements());
    ::java::lang::System::arraycopy(npc(keys)->asArray_(), 0, this->keys, 0, npc(this->keys)->length);
}

rice::p2p::past::gc::GCIdArray* rice::p2p::past::gc::messaging::GCRefreshMessage::getKeys()
{
    return keys;
}

java::lang::String* rice::p2p::past::gc::messaging::GCRefreshMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GCRefreshMessage of "_j)->append(npc(keys)->length)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::past::gc::messaging::GCRefreshMessage::getType()
{
    return TYPE;
}

void rice::p2p::past::gc::messaging::GCRefreshMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    if(response != nullptr && dynamic_cast< ::java::lang::BooleanArray* >(response) != nullptr) {
        super::serialize(buf, false);
        auto array = java_cast< ::java::lang::BooleanArray* >(response);
        npc(buf)->writeInt(npc(array)->length);
        for (auto i = int32_t(0); i < npc(array)->length; i++) {
            npc(buf)->writeBoolean(npc((*array)[i])->booleanValue());
        }
    } else {
        super::serialize(buf, true);
    }
    npc(buf)->writeInt(npc(keys)->length);
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        npc(buf)->writeShort(npc((*keys)[i])->getType());
        npc((*keys)[i])->serialize(buf);
    }
}

rice::p2p::past::gc::messaging::GCRefreshMessage* rice::p2p::past::gc::messaging::GCRefreshMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GCRefreshMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::past::gc::messaging::GCRefreshMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    if(serType == S_SUB()) {
        auto arrayLength = npc(buf)->readInt();
        auto array = new ::java::lang::BooleanArray(arrayLength);
        for (auto i = int32_t(0); i < arrayLength; i++) {
            array->set(i, new ::java::lang::Boolean(npc(buf)->readBoolean()));
        }
    }
    keys = new ::rice::p2p::past::gc::GCIdArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        keys->set(i, java_cast< ::rice::p2p::past::gc::GCId* >(npc(endpoint)->readId(buf, npc(buf)->readShort())));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::messaging::GCRefreshMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.messaging.GCRefreshMessage", 43);
    return c;
}

void rice::p2p::past::gc::messaging::GCRefreshMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf, bool javaSerialize)
{
    super::serialize(buf, javaSerialize);
}

java::lang::Class* rice::p2p::past::gc::messaging::GCRefreshMessage::getClass0()
{
    return class_();
}

