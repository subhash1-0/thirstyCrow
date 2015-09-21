// Generated from /pastry-2.1/src/rice/p2p/glacier/v2/messaging/GlacierDataMessage.java
#include <rice/p2p/glacier/v2/messaging/GlacierDataMessage.hpp>

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
#include <rice/p2p/glacier/Fragment.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/v2/Manifest.hpp>
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
typedef ::SubArray< ::rice::p2p::glacier::Fragment, ::java::lang::ObjectArray, ::java::io::SerializableArray > FragmentArray;
typedef ::SubArray< ::rice::p2p::glacier::FragmentKey, ::java::lang::ObjectArray, ::rice::p2p::commonapi::IdArray > FragmentKeyArray;

            namespace v2
            {
typedef ::SubArray< ::rice::p2p::glacier::v2::Manifest, ::java::lang::ObjectArray, ::java::io::SerializableArray > ManifestArray;
            } // v2
        } // glacier
    } // p2p
} // rice

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::glacier::v2::messaging::GlacierDataMessage::GlacierDataMessage(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::v2::messaging::GlacierDataMessage::GlacierDataMessage(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, ::rice::p2p::glacier::Fragment* fragment, ::rice::p2p::glacier::v2::Manifest* manifest, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag) 
    : GlacierDataMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,key,fragment,manifest,source,dest,isResponse,tag);
}

rice::p2p::glacier::v2::messaging::GlacierDataMessage::GlacierDataMessage(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, ::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::glacier::v2::ManifestArray* manifests, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag) 
    : GlacierDataMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(uid,keys,fragments,manifests,source,dest,isResponse,tag);
}

rice::p2p::glacier::v2::messaging::GlacierDataMessage::GlacierDataMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GlacierDataMessage(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::v2::messaging::GlacierDataMessage::TYPE;

void rice::p2p::glacier::v2::messaging::GlacierDataMessage::ctor(int32_t uid, ::rice::p2p::glacier::FragmentKey* key, ::rice::p2p::glacier::Fragment* fragment, ::rice::p2p::glacier::v2::Manifest* manifest, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag)
{
    ctor(uid, new ::rice::p2p::glacier::FragmentKeyArray({key}), new ::rice::p2p::glacier::FragmentArray({fragment}), new ::rice::p2p::glacier::v2::ManifestArray({manifest}), source, dest, isResponse, tag);
}

void rice::p2p::glacier::v2::messaging::GlacierDataMessage::ctor(int32_t uid, ::rice::p2p::glacier::FragmentKeyArray* keys, ::rice::p2p::glacier::FragmentArray* fragments, ::rice::p2p::glacier::v2::ManifestArray* manifests, ::rice::p2p::commonapi::NodeHandle* source, ::rice::p2p::commonapi::Id* dest, bool isResponse, char16_t tag)
{
    super::ctor(uid, source, dest, isResponse, tag);
    this->keys = keys;
    this->fragments = fragments;
    this->manifests = manifests;
}

int32_t rice::p2p::glacier::v2::messaging::GlacierDataMessage::numKeys()
{
    return npc(keys)->length;
}

rice::p2p::glacier::FragmentKey* rice::p2p::glacier::v2::messaging::GlacierDataMessage::getKey(int32_t index)
{
    return (*keys)[index];
}

rice::p2p::glacier::Fragment* rice::p2p::glacier::v2::messaging::GlacierDataMessage::getFragment(int32_t index)
{
    return (*fragments)[index];
}

rice::p2p::glacier::v2::Manifest* rice::p2p::glacier::v2::messaging::GlacierDataMessage::getManifest(int32_t index)
{
    return (*manifests)[index];
}

java::lang::String* rice::p2p::glacier::v2::messaging::GlacierDataMessage::toString()
{
    return ::java::lang::StringBuilder().append(u"[GlacierData for "_j)->append(static_cast< ::java::lang::Object* >((*keys)[int32_t(0)]))
        ->append(u" ("_j)
        ->append((numKeys() - int32_t(1)))
        ->append(u" more keys)]"_j)->toString();
}

int16_t rice::p2p::glacier::v2::messaging::GlacierDataMessage::getType()
{
    return TYPE;
}

void rice::p2p::glacier::v2::messaging::GlacierDataMessage::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeByte(static_cast< int8_t >(int32_t(0)));
    super::serialize(buf);
    auto l = npc(fragments)->length;
    npc(buf)->writeInt(l);
    for (auto i = int32_t(0); i < l; i++) {
        if((*fragments)[i] == nullptr) {
            npc(buf)->writeBoolean(false);
        } else {
            npc(buf)->writeBoolean(true);
            npc((*fragments)[i])->serialize(buf);
        }
    }
    l = npc(keys)->length;
    npc(buf)->writeInt(l);
    for (auto i = int32_t(0); i < l; i++) {
        npc((*keys)[i])->serialize(buf);
    }
    l = npc(manifests)->length;
    npc(buf)->writeInt(l);
    for (auto i = int32_t(0); i < l; i++) {
        if((*manifests)[i] == nullptr) {
            npc(buf)->writeBoolean(false);
        } else {
            npc(buf)->writeBoolean(true);
            npc((*manifests)[i])->serialize(buf);
        }
    }
}

rice::p2p::glacier::v2::messaging::GlacierDataMessage* rice::p2p::glacier::v2::messaging::GlacierDataMessage::build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    clinit();
    auto version = npc(buf)->readByte();
    switch (version) {
    case int32_t(0):
        return new GlacierDataMessage(buf, endpoint);
    default:
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown Version: "_j)->append(version)->toString());
    }

}

void rice::p2p::glacier::v2::messaging::GlacierDataMessage::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor(buf, endpoint);
    fragments = new ::rice::p2p::glacier::FragmentArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(fragments)->length; i++) {
        if(npc(buf)->readBoolean())
            fragments->set(i, new ::rice::p2p::glacier::Fragment(buf));

    }
    keys = new ::rice::p2p::glacier::FragmentKeyArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(keys)->length; i++) {
        keys->set(i, new ::rice::p2p::glacier::FragmentKey(buf, endpoint));
    }
    manifests = new ::rice::p2p::glacier::v2::ManifestArray(npc(buf)->readInt());
    for (auto i = int32_t(0); i < npc(manifests)->length; i++) {
        if(npc(buf)->readBoolean())
            manifests->set(i, new ::rice::p2p::glacier::v2::Manifest(buf));

    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierDataMessage::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.v2.messaging.GlacierDataMessage", 48);
    return c;
}

java::lang::Class* rice::p2p::glacier::v2::messaging::GlacierDataMessage::getClass0()
{
    return class_();
}

