// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierResponseMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierResponseMessage.hpp>

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
#include <Array.hpp>
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

rice::p2p::glacier::v2::messaging::GlacierResponseMessage::GlacierResponseMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierResponseMessage::GlacierResponseMessage(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, bool haveIt, int64_t lifetime, bool authoritative, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag) 
    : GlacierResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,key,haveIt,lifetime,authoritative,source,dest,isResponse,tag);
}

rice::p2p::glacier::v2::messaging::GlacierResponseMessage::GlacierResponseMessage(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, ::boolArray* haveIt, ::int64_tArray* lifetimes, ::boolArray* authoritative, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag) 
    : GlacierResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,keys,haveIt,lifetimes,authoritative,source,dest,isResponse,tag);
}

rice::p2p::glacier::v2::messaging::GlacierResponseMessage::GlacierResponseMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierResponseMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierResponseMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierResponseMessage::ctor(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, bool haveIt, int64_t lifetime, bool authoritative, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag)
{
    ctor(uid, new ::rice::p2p::glacier::FragmentKeyArray({key}), new ::boolArray({haveIt}), new ::int64_tArray({lifetime}), new ::boolArray({authoritative}), source, dest, isResponse, tag);
}

void rice::p2p::glacier::v2::messaging::GlacierResponseMessage::ctor(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, ::boolArray* haveIt, ::int64_tArray* lifetimes, ::boolArray* authoritative, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag)
{
    super::ctor(uid, source, dest, isResponse, tag);
    this->keys = keys;
    this->haveIt = haveIt;
    this->authoritative = authoritative;
    this->lifetimes = lifetimes;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierResponseMessage::numKeys()
{
    return npc(keys)->length;
}

rice::p2p::glacier::FragmentKey* rice::p2p::glacier::v2::messaging::GlacierResponseMessage::getKey(int32_t index)
{
    return (*keys)[index];
}

bool rice::p2p::glacier::v2::messaging::GlacierResponseMessage::getHaveIt(int32_t index)
{
    return (*haveIt)[index];
}

bool rice::p2p::glacier::v2::messaging::GlacierResponseMessage::getAuthoritative(int32_t index)
{
    return (*authoritative)[index];
}

int64_t rice::p2p::glacier::v2::messaging::GlacierResponseMessage::getExpiration(int32_t index)
{
    return (*lifetimes)[index];
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierResponseMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierResponse for "_j)->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))
        ->append(u" ("_j)
        ->append((numKeys() - int32_t(1)))
        ->append(u" more keys)]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierResponseMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierResponseMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(npc(keys)->length);
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        npc((*keys)[i])->serialize(buf);
    }
    npc(buf)->writeInt(npc(lifetimes)->length);
    for (auto i = int32_t(0); i < npc(lifetimes)->length; i++) {
        npc(buf)->writeLong((*lifetimes)[i]);
    }
    npc(buf)->writeInt(npc(authoritative)->length);
    for (auto i = int32_t(0); i < npc(authoritative)->length; i++) {
        npc(buf)->writeBoolean((*authoritative)[i]);
    }
    npc(buf)->writeInt(npc(haveIt)->length);
    for (auto i = int32_t(0); i < npc(haveIt)->length; i++) {
        npc(buf)->writeBoolean((*haveIt)[i]);
    }
}

rice::p2p::glacier::v2::messaging::GlacierResponseMessage* rice::p2p::glacier::v2::messaging::GlacierResponseMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierResponseMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierResponseMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    keys = new ::rice::p2p::glacier::FragmentKeyArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        keys->set(i, new ::rice::p2p::glacier::FragmentKey(buf, endpoint));
    }
    lifetimes = new ::int64_tArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(lifetimes)->length; i++) {
        (*lifetimes)[i] = npc(buf)->readLong();
    }
    authoritative = new ::boolArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(authoritative)->length; i++) {
        (*authoritative)[i] = npc(buf)->readBoolean();
    }
    haveIt = new ::boolArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(haveIt)->length; i++) {
        (*haveIt)[i] = npc(buf)->readBoolean();
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierResponseMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierResponseMessage", 52);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierResponseMessage::getClass0()
{
    return class_();
}

