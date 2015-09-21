// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierRefreshCompleteMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierRefreshCompleteMessage.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::GlacierRefreshCompleteMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::GlacierRefreshCompleteMessage(int32_t uid, ::rice::p2p::glacier::VersionKeyArray* keys, ::int32_tArray* updates, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag) 
    : GlacierRefreshCompleteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,keys,updates,source,dest,tag);
}

rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::GlacierRefreshCompleteMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierRefreshCompleteMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::ctor(int32_t uid, ::rice::p2p::glacier::VersionKeyArray* keys, ::int32_tArray* updates, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, char16_t tag)
{
    super::ctor(uid, source, dest, true, tag);
    this->keys = keys;
    this->updates = updates;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::numKeys()
{
    return npc(keys)->length;
}

rice::p2p::glacier::VersionKey* rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::getKey(int32_t index)
{
    return (*keys)[index];
}

int64_t rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::getUpdates(int32_t index)
{
    return (*updates)[index];
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierRefreshComplete for "_j)->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))
        ->append(u" ("_j)
        ->append((numKeys() - int32_t(1)))
        ->append(u" more keys)]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    npc(buf)->writeInt(npc(updates)->length);
    for (auto i = int32_t(0); i < npc(updates)->length; i++) {
        npc(buf)->writeInt((*updates)[i]);
    }
    npc(buf)->writeInt(npc(keys)->length);
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        npc((*keys)[i])->serialize(buf);
    }
}

rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage* rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierRefreshCompleteMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    updates = new ::int32_tArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(updates)->length; i++) {
        (*updates)[i] = npc(buf)->readInt();
    }
    keys = new ::rice::p2p::glacier::VersionKeyArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        keys->set(i, new ::rice::p2p::glacier::VersionKey(buf, endpoint));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierRefreshCompleteMessage", 59);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierRefreshCompleteMessage::getClass0()
{
    return class_();
}

