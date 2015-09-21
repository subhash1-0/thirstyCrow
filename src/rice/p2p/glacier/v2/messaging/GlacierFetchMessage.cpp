// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierFetchMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierFetchMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
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

        namespace glacier
        {
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;
        } // glacier
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierFetchMessage::GlacierFetchMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierFetchMessage::GlacierFetchMessage(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, int32_t request, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierFetchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,key,request,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierFetchMessage::GlacierFetchMessage(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, int32_t request, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierFetchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,keys,request,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierFetchMessage::GlacierFetchMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierFetchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::TYPE;

constexpr int32_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_FRAGMENT;

constexpr int32_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_MANIFEST;

constexpr int32_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::FETCH_FRAGMENT_AND_MANIFEST;

void rice::p2p::glacier::v2::messaging::GlacierFetchMessage::ctor(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, int32_t request, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    ctor(uid, new ::rice::p2p::glacier::FragmentKeyArray({key}), request, source, dest, tag);
}

void rice::p2p::glacier::v2::messaging::GlacierFetchMessage::ctor(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, int32_t request, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, false, tag);
    this->keys = keys;
    this->request = request;
}

rice::p2p::glacier::FragmentKeyArray* rice::p2p::glacier::v2::messaging::GlacierFetchMessage::getAllKeys()
{
    return keys;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::getRequest()
{
    return request;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::getNumKeys()
{
    return npc(keys)->length;
}

rice::p2p::glacier::FragmentKey* rice::p2p::glacier::v2::messaging::GlacierFetchMessage::getKey(int32_t index)
{
    return (*keys)[index];
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierFetchMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierFetch for "_j)->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))
        ->append(u" and "_j)
        ->append((npc(keys)->length - int32_t(1)))
        ->append(u" other keys, req="_j)
        ->append(request)
        ->append(u"]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierFetchMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierFetchMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(request);
    auto l = npc(keys)->length;
    npc(buf)->writeInt(l);
    for (auto i = int32_t(0); i < l; i++) {
        npc((*keys)[i])->serialize(buf);
    }
}

rice::p2p::glacier::v2::messaging::GlacierFetchMessage* rice::p2p::glacier::v2::messaging::GlacierFetchMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierFetchMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierFetchMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    request = npc(buf)->readInt();
    auto l = npc(buf)->readInt();
    keys = new ::rice::p2p::glacier::FragmentKeyArray(l);
    for (auto i = int32_t(0); i < l; i++) {
        keys->set(i, new ::rice::p2p::glacier::FragmentKey(buf, endpoint));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierFetchMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierFetchMessage", 49);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierFetchMessage::getClass0()
{
    return class_();
}

