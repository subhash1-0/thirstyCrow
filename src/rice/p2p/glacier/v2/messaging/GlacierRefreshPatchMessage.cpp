// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRefreshPatchMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshPatchMessage.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
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
typedef ::SubArray< ::rice::p2p::glacier::VersionKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray, ::java::io::SerializableArray > VersionKeyArray;
        } // glacier
    } // p2p
} // rice

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::GlacierRefreshPatchMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::GlacierRefreshPatchMessage(int32_t uid, ::rice::p2p::glacier::VersionKeyArray* keys, ::int64_tArray* lifetimes, ::int8_tArrayArray* signatures, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierRefreshPatchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,keys,lifetimes,signatures,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::GlacierRefreshPatchMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierRefreshPatchMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::ctor(int32_t uid, ::rice::p2p::glacier::VersionKeyArray* keys, ::int64_tArray* lifetimes, ::int8_tArrayArray* signatures, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, false, tag);
    this->keys = keys;
    this->lifetimes = lifetimes;
    this->signatures = signatures;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::numKeys()
{
    return npc(keys)->length;
}

rice::p2p::glacier::VersionKey* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::getKey(int32_t index)
{
    return (*keys)[index];
}

rice::p2p::glacier::VersionKeyArray* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::getAllKeys()
{
    return keys;
}

int64_t rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::getLifetime(int32_t index)
{
    return (*lifetimes)[index];
}

int8_tArray* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::getSignature(int32_t index)
{
    return (*signatures)[index];
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierRefreshPatch for "_j)->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))
        ->append(u" ("_j)
        ->append((numKeys() - int32_t(1)))
        ->append(u" more keys)]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(npc(lifetimes)->length);
    for (auto i = int32_t(0); i < npc(lifetimes)->length; i++) {
        npc(buf)->writeLong((*lifetimes)[i]);
    }
    npc(buf)->writeInt(npc(keys)->length);
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        npc((*keys)[i])->serialize(buf);
    }
    npc(buf)->writeInt(npc(signatures)->length);
    for (auto i = int32_t(0); i < npc(signatures)->length; i++) {
        npc(buf)->writeInt(npc((*signatures)[i])->length);
        npc(buf)->write((*signatures)[i], 0, npc((*signatures)[i])->length);
    }
}

rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierRefreshPatchMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    lifetimes = new ::int64_tArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(lifetimes)->length; i++) {
        (*lifetimes)[i] = npc(buf)->readLong();
    }
    keys = new ::rice::p2p::glacier::VersionKeyArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        keys->set(i, new ::rice::p2p::glacier::VersionKey(buf, endpoint));
    }
    signatures = new ::int8_tArrayArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(signatures)->length; i++) {
        signatures->set(i, new ::int8_tArray(npc(buf)->readInt()));
        npc(buf)->read((*signatures)[i]);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierRefreshPatchMessage", 56);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshPatchMessage::getClass0()
{
    return class_();
}

