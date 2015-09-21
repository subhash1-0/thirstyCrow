// Generated from /pastry-2.1/src/rice/p2p/glacier/VersionKey.java
#include <rice/p2p/glacier/VersionKey.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/p2p/multiring/RingId.hpp>
#include <rice/p2p/util/MathUtils.hpp>
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
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

rice::p2p::glacier::VersionKey::VersionKey(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::VersionKey::VersionKey(::rice::p2p::commonapi::Id* id, int64_t version) 
    : VersionKey(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,version);
}

rice::p2p::glacier::VersionKey::VersionKey(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : VersionKey(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::glacier::VersionKey::TYPE;

constexpr int64_t rice::p2p::glacier::VersionKey::serialVersionUID;

void rice::p2p::glacier::VersionKey::ctor(::rice::p2p::commonapi::Id* id, int64_t version)
{
    super::ctor();
    this->id = id;
    this->version = version;
}

int64_t rice::p2p::glacier::VersionKey::getVersion()
{
    return version;
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKey::getId()
{
    return id;
}

bool rice::p2p::glacier::VersionKey::equals(::java::lang::Object* peer)
{
    if(!(dynamic_cast< VersionKey* >(peer) != nullptr)) {
        return false;
    }
    auto fk = java_cast< VersionKey* >(peer);
    return ((npc(fk)->version == this->version) && npc(npc(fk)->id)->equals(this->id));
}

java::lang::String* rice::p2p::glacier::VersionKey::toString()
{
    return ::java::lang::StringBuilder().append(npc(id)->toString())->append(u"v"_j)
        ->append(version)->toString();
}

java::lang::String* rice::p2p::glacier::VersionKey::toStringFull()
{
    return ::java::lang::StringBuilder().append(npc(id)->toStringFull())->append(u"v"_j)
        ->append(version)->toString();
}

int32_t rice::p2p::glacier::VersionKey::compareTo(::rice::p2p::commonapi::Id* o)
{
    auto idResult = npc(id)->compareTo(npc((java_cast< VersionKey* >(o)))->id);
    if(idResult != 0) {
        return idResult;
    }
    if((version - npc((java_cast< VersionKey* >(o)))->version) < 0)
        return -int32_t(1);

    if((version - npc((java_cast< VersionKey* >(o)))->version) > 0)
        return 1;

    return 0;
}

int32_t rice::p2p::glacier::VersionKey::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id* >(o));
}

int32_t rice::p2p::glacier::VersionKey::hashCode()
{
    return (npc(id)->hashCode() + ((new ::java::lang::Long(version))->hashCode()));
}

int8_tArray* rice::p2p::glacier::VersionKey::toByteArray_()
{
    auto result = new ::int8_tArray(getByteArrayLength());
    toByteArray_(result, int32_t(0));
    return result;
}

void rice::p2p::glacier::VersionKey::toByteArray_(::int8_tArray* result, int32_t offset)
{
    npc(id)->toByteArray_(result, offset);
    ::rice::p2p::util::MathUtils::longToByteArray_(version, result, offset + npc(id)->getByteArrayLength());
}

int32_t rice::p2p::glacier::VersionKey::getByteArrayLength()
{
    return npc(id)->getByteArrayLength() + int32_t(8);
}

bool rice::p2p::glacier::VersionKey::isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw)
{
    throw new ::java::lang::RuntimeException(u"VersionKey.isBetween() is not supported!"_j);
}

rice::p2p::commonapi::Id_Distance* rice::p2p::glacier::VersionKey::longDistanceFromId(::rice::p2p::commonapi::Id* nid)
{
    throw new ::java::lang::RuntimeException(u"VersionKey.longDistanceFromId() is not supported!"_j);
}

rice::p2p::commonapi::Id_Distance* rice::p2p::glacier::VersionKey::distanceFromId(::rice::p2p::commonapi::Id* nid)
{
    throw new ::java::lang::RuntimeException(u"VersionKey.distanceFromId() is not supported!"_j);
}

rice::p2p::commonapi::Id* rice::p2p::glacier::VersionKey::addToId(::rice::p2p::commonapi::Id_Distance* offset)
{
    throw new ::java::lang::RuntimeException(u"VersionKey.addToId() is not supported!"_j);
}

bool rice::p2p::glacier::VersionKey::clockwise(::rice::p2p::commonapi::Id* nid)
{
    throw new ::java::lang::RuntimeException(u"VersionKey.clockwise() is not supported!"_j);
}

rice::p2p::glacier::VersionKey* rice::p2p::glacier::VersionKey::build(::java::lang::String* s)
{
    clinit();
    auto sArray_ = npc(s)->split(u"v"_j);
    return new VersionKey(static_cast< ::rice::p2p::commonapi::Id* >(::rice::p2p::multiring::RingId::build((*sArray_)[int32_t(0)])), ::java::lang::Long::parseLong((*sArray_)[int32_t(1)]));
}

void rice::p2p::glacier::VersionKey::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    version = npc(buf)->readLong();
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

void rice::p2p::glacier::VersionKey::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeLong(version);
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

int16_t rice::p2p::glacier::VersionKey::getType()
{
    return TYPE;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::VersionKey::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.VersionKey", 27);
    return c;
}

java::lang::Class* rice::p2p::glacier::VersionKey::getClass0()
{
    return class_();
}

