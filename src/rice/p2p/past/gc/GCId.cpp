// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCId.java
#include <rice/p2p/past/gc/GCId.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
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

rice::p2p::past::gc::GCId::GCId(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCId::GCId(::rice::p2p::commonapi::Id* id, int64_t expiration) 
    : GCId(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,expiration);
}

rice::p2p::past::gc::GCId::GCId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : GCId(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

constexpr int16_t rice::p2p::past::gc::GCId::TYPE;

void rice::p2p::past::gc::GCId::ctor(::rice::p2p::commonapi::Id* id, int64_t expiration)
{
    super::ctor();
    this->id = id;
    this->expiration = expiration;
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCId::getId()
{
    return id;
}

int64_t rice::p2p::past::gc::GCId::getExpiration()
{
    return expiration;
}

bool rice::p2p::past::gc::GCId::isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw)
{
    return npc(id)->isBetween(npc((java_cast< GCId* >(ccw)))->getId(), npc((java_cast< GCId* >(cw)))->getId());
}

bool rice::p2p::past::gc::GCId::clockwise(::rice::p2p::commonapi::Id* nid)
{
    return npc(id)->clockwise(npc((java_cast< GCId* >(nid)))->getId());
}

rice::p2p::commonapi::Id* rice::p2p::past::gc::GCId::addToId(::rice::p2p::commonapi::Id_Distance* offset)
{
    return new GCId(npc(id)->addToId(offset), expiration);
}

rice::p2p::commonapi::Id_Distance* rice::p2p::past::gc::GCId::distanceFromId(::rice::p2p::commonapi::Id* nid)
{
    return npc(id)->distanceFromId(npc((java_cast< GCId* >(nid)))->getId());
}

rice::p2p::commonapi::Id_Distance* rice::p2p::past::gc::GCId::longDistanceFromId(::rice::p2p::commonapi::Id* nid)
{
    return npc(id)->longDistanceFromId(npc((java_cast< GCId* >(nid)))->getId());
}

int8_tArray* rice::p2p::past::gc::GCId::toByteArray_()
{
    auto result = new ::int8_tArray(getByteArrayLength());
    toByteArray_(result, int32_t(0));
    return result;
}

void rice::p2p::past::gc::GCId::toByteArray_(::int8_tArray* array, int32_t offset)
{
    npc(id)->toByteArray_(array, offset);
    ::rice::p2p::util::MathUtils::longToByteArray_(expiration, array, offset + npc(id)->getByteArrayLength());
}

int32_t rice::p2p::past::gc::GCId::getByteArrayLength()
{
    return npc(id)->getByteArrayLength() + int32_t(8);
}

bool rice::p2p::past::gc::GCId::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< GCId* >(o) != nullptr))
        return false;

    return (npc(npc((java_cast< GCId* >(o)))->id)->equals(id) && (npc((java_cast< GCId* >(o)))->expiration == expiration));
}

int32_t rice::p2p::past::gc::GCId::hashCode()
{
    return npc(id)->hashCode();
}

java::lang::String* rice::p2p::past::gc::GCId::toString()
{
    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(id))->append(u"-"_j)
        ->append(expiration)->toString();
}

java::lang::String* rice::p2p::past::gc::GCId::toStringFull()
{
    return ::java::lang::StringBuilder().append(npc(id)->toStringFull())->append(u"-"_j)
        ->append(expiration)->toString();
}

int32_t rice::p2p::past::gc::GCId::compareTo(::rice::p2p::commonapi::Id* o)
{
    return npc(id)->compareTo(npc((java_cast< GCId* >(o)))->id);
}

int32_t rice::p2p::past::gc::GCId::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id* >(o));
}

int16_t rice::p2p::past::gc::GCId::getType()
{
    return TYPE;
}

void rice::p2p::past::gc::GCId::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(getType());
    npc(buf)->writeLong(expiration);
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

void rice::p2p::past::gc::GCId::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    npc(buf)->readShort();
    expiration = npc(buf)->readLong();
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCId::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCId", 21);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCId::getClass0()
{
    return class_();
}

