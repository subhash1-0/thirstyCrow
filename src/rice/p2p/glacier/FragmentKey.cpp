// Generated from /pastry-2.1/src/rice/p2p/glacier/FragmentKey.java
#include <rice/p2p/glacier/FragmentKey.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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

rice::p2p::glacier::FragmentKey::FragmentKey(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::FragmentKey::FragmentKey(VersionKey* key, int32_t id) 
    : FragmentKey(*static_cast< ::default_init_tag* >(0))
{
    ctor(key,id);
}

rice::p2p::glacier::FragmentKey::FragmentKey(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : FragmentKey(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::FragmentKey::TYPE;

constexpr int64_t rice::p2p::glacier::FragmentKey::serialVersionUID;

void rice::p2p::glacier::FragmentKey::ctor(VersionKey* key, int32_t id)
{
    super::ctor();
    this->id = id;
    this->key = key;
}

bool rice::p2p::glacier::FragmentKey::isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw)
{
    throw new ::java::lang::RuntimeException(u"FragmentKey.isBetween() is not supported!"_j);
}

rice::p2p::glacier::VersionKey* rice::p2p::glacier::FragmentKey::getVersionKey()
{
    return key;
}

int32_t rice::p2p::glacier::FragmentKey::getFragmentID()
{
    return id;
}

rice::p2p::glacier::FragmentKey* rice::p2p::glacier::FragmentKey::getPeerKey(int32_t otherId)
{
    return new FragmentKey(key, otherId);
}

bool rice::p2p::glacier::FragmentKey::equals(::java::lang::Object* peer)
{
    if(!(dynamic_cast< FragmentKey* >(peer) != nullptr)) {
        return false;
    }
    auto sk = java_cast< FragmentKey* >(peer);
    return (npc(npc(sk)->key)->equals(static_cast< ::java::lang::Object* >(this->key)) && (npc(sk)->id == this->id));
}

int8_tArray* rice::p2p::glacier::FragmentKey::toByteArray_()
{
    auto result = new ::int8_tArray(getByteArrayLength());
    toByteArray_(result, int32_t(0));
    return result;
}

void rice::p2p::glacier::FragmentKey::toByteArray_(::int8_tArray* result, int32_t offset)
{
    npc(key)->toByteArray_(result, offset);
    ::rice::p2p::util::MathUtils::intToByteArray_(id, result, offset + npc(key)->getByteArrayLength());
}

int32_t rice::p2p::glacier::FragmentKey::getByteArrayLength()
{
    return npc(key)->getByteArrayLength() + int32_t(4);
}

java::lang::String* rice::p2p::glacier::FragmentKey::toStringFull()
{
    return ::java::lang::StringBuilder().append(npc(key)->toStringFull())->append(u"#"_j)
        ->append(id)->toString();
}

java::lang::String* rice::p2p::glacier::FragmentKey::toString()
{
    return ::java::lang::StringBuilder().append(npc(key)->toString())->append(u"#"_j)
        ->append(id)->toString();
}

rice::p2p::commonapi::Id_Distance* rice::p2p::glacier::FragmentKey::longDistanceFromId(::rice::p2p::commonapi::Id* nid)
{
    throw new ::java::lang::RuntimeException(u"FragmentKey.longDistanceFromId() is not supported!"_j);
}

rice::p2p::commonapi::Id_Distance* rice::p2p::glacier::FragmentKey::distanceFromId(::rice::p2p::commonapi::Id* nid)
{
    throw new ::java::lang::RuntimeException(u"FragmentKey.distanceFromId() is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::FragmentKey::addToId(::rice::p2p::commonapi::Id_Distance* offset)
{
    throw new ::java::lang::RuntimeException(u"FragmentKey.addToId() is not supported!"_j);
}

bool rice::p2p::glacier::FragmentKey::clockwise(::rice::p2p::commonapi::Id* nid)
{
    throw new ::java::lang::RuntimeException(u"FragmentKey.clockwise() is not supported!"_j);
}

int32_t rice::p2p::glacier::FragmentKey::compareTo(::rice::p2p::commonapi::Id* o)
{
    auto keyResult = npc(key)->compareTo(static_cast< ::rice::p2p::commonapi::Id* >(npc((java_cast< FragmentKey* >(o)))->key));
    if(keyResult != 0) {
        return keyResult;
    }
    if(this->id < npc((java_cast< FragmentKey* >(o)))->id) {
        return -int32_t(1);
    }
    if(this->id > npc((java_cast< FragmentKey* >(o)))->id) {
        return 1;
    }
    return 0;
}

int32_t rice::p2p::glacier::FragmentKey::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id* >(o));
}

int32_t rice::p2p::glacier::FragmentKey::hashCode()
{
    return (npc(key)->hashCode() + id);
}

void rice::p2p::glacier::FragmentKey::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    id = npc(buf)->readInt();
    key = new VersionKey(buf, endpoint);
}

void rice::p2p::glacier::FragmentKey::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeInt(id);
    npc(key)->serialize(buf);
}

int16_t rice::p2p::glacier::FragmentKey::getType()
{
    return TYPE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::FragmentKey::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.FragmentKey", 28);
    return c;
}

java::lang::Class* rice::p2p::glacier::FragmentKey::getClass0()
{
    return class_();
}

