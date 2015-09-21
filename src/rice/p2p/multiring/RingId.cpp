// Generated from /pastry-2.1/src/rice/p2p/multiring/RingId.java
#include <rice/p2p/multiring/RingId.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/util/WeakHashMap.hpp>
#include <rice/p2p/commonapi/Endpoint.hpp>
#include <rice/p2p/commonapi/Id_Distance.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <rice/pastry/Id.hpp>
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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::p2p::multiring::RingId::RingId(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::RingId::RingId(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id) 
    : RingId(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,id);
}

rice::p2p::multiring::RingId::RingId(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint)  /* throws(IOException) */
    : RingId(*static_cast< ::default_init_tag* >(0))
{
    ctor(buf,endpoint);
}

int16_t& rice::p2p::multiring::RingId::TYPE()
{
    clinit();
    return TYPE_;
}
int16_t rice::p2p::multiring::RingId::TYPE_;

constexpr int64_t rice::p2p::multiring::RingId::serialVersionUID;

java::util::WeakHashMap*& rice::p2p::multiring::RingId::RINGID_MAP()
{
    clinit();
    return RINGID_MAP_;
}
java::util::WeakHashMap* rice::p2p::multiring::RingId::RINGID_MAP_;

void rice::p2p::multiring::RingId::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id)
{
    super::ctor();
    this->id = id;
    this->ringId = ringId;
    if((id == nullptr) || (ringId == nullptr))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"RingId created with args "_j)->append(static_cast< ::java::lang::Object* >(ringId))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

    if(dynamic_cast< RingId* >(id) != nullptr)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"RingId created with id as a RingId!"_j)->append(static_cast< ::java::lang::Object* >(ringId))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

    if(dynamic_cast< RingId* >(ringId) != nullptr)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"RingId created with ringId as a RingId!"_j)->append(static_cast< ::java::lang::Object* >(ringId))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(id))->toString());

}

rice::p2p::multiring::RingId* rice::p2p::multiring::RingId::build(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::Id* id)
{
    clinit();
    return resolve(new RingId(ringId, id));
}

rice::p2p::multiring::RingId* rice::p2p::multiring::RingId::resolve(RingId* id)
{
    clinit();
    {
        synchronized synchronized_0(RINGID_MAP_);
        {
            auto ref = java_cast< ::java::lang::ref::WeakReference* >(java_cast< ::java::lang::Object* >(npc(RINGID_MAP_)->get(static_cast< ::java::lang::Object* >(id))));
            RingId* result = nullptr;
            if((ref != nullptr) && ((result = java_cast< RingId* >(java_cast< ::java::lang::Object* >(npc(ref)->get()))) != nullptr)) {
                return result;
            } else {
                npc(RINGID_MAP_)->put(static_cast< ::java::lang::Object* >(id), static_cast< ::java::lang::Object* >(new ::java::lang::ref::WeakReference(id)));
                return id;
            }
        }
    }
}

java::lang::Object* rice::p2p::multiring::RingId::readResolve() /* throws(ObjectStreamException) */
{
    return this;
}

rice::p2p::multiring::RingId* rice::p2p::multiring::RingId::build(::java::lang::String* s)
{
    clinit();
    auto sArray_ = npc(s)->split(u"\\(|\\)| |,"_j);
    return build(::rice::pastry::Id::build((*sArray_)[int32_t(1)]), ::rice::pastry::Id::build((*sArray_)[int32_t(3)]));
}

rice::p2p::commonapi::Id* rice::p2p::multiring::RingId::getId()
{
    return id;
}

rice::p2p::commonapi::Id* rice::p2p::multiring::RingId::getRingId()
{
    return ringId;
}

bool rice::p2p::multiring::RingId::isBetween(::rice::p2p::commonapi::Id* ccw, ::rice::p2p::commonapi::Id* cw)
{
    if(!(dynamic_cast< RingId* >(ccw) != nullptr) || (!npc(npc((java_cast< RingId* >(ccw)))->getRingId())->equals(ringId)) || !(dynamic_cast< RingId* >(cw) != nullptr)|| (!npc(npc((java_cast< RingId* >(cw)))->getRingId())->equals(ringId)))
        throw new ::java::lang::IllegalArgumentException(u"Defined only for RingIds from the same ring!"_j);

    return npc(id)->isBetween(npc((java_cast< RingId* >(ccw)))->getId(), npc((java_cast< RingId* >(cw)))->getId());
}

bool rice::p2p::multiring::RingId::clockwise(::rice::p2p::commonapi::Id* nid)
{
    if(!(dynamic_cast< RingId* >(nid) != nullptr) || (!npc(npc((java_cast< RingId* >(nid)))->getRingId())->equals(ringId)))
        throw new ::java::lang::IllegalArgumentException(u"Defined only for RingIds from the same ring!"_j);

    return npc(id)->clockwise(npc((java_cast< RingId* >(nid)))->getId());
}

rice::p2p::commonapi::Id* rice::p2p::multiring::RingId::addToId(::rice::p2p::commonapi::Id_Distance* offset)
{
    return build(ringId, npc(id)->addToId(offset));
}

rice::p2p::commonapi::Id_Distance* rice::p2p::multiring::RingId::distanceFromId(::rice::p2p::commonapi::Id* nid)
{
    if(!(dynamic_cast< RingId* >(nid) != nullptr) || (!npc(npc((java_cast< RingId* >(nid)))->getRingId())->equals(ringId)))
        throw new ::java::lang::IllegalArgumentException(u"Defined only for RingIds from the same ring!"_j);

    return npc(id)->distanceFromId(npc((java_cast< RingId* >(nid)))->getId());
}

rice::p2p::commonapi::Id_Distance* rice::p2p::multiring::RingId::longDistanceFromId(::rice::p2p::commonapi::Id* nid)
{
    if(!(dynamic_cast< RingId* >(nid) != nullptr) || (!npc(npc((java_cast< RingId* >(nid)))->getRingId())->equals(ringId)))
        throw new ::java::lang::IllegalArgumentException(u"Defined only for RingIds from the same ring!"_j);

    return npc(id)->longDistanceFromId(npc((java_cast< RingId* >(nid)))->getId());
}

int8_tArray* rice::p2p::multiring::RingId::toByteArray_()
{
    return npc(id)->toByteArray_();
}

void rice::p2p::multiring::RingId::toByteArray_(::int8_tArray* array, int32_t offset)
{
    npc(id)->toByteArray_(array, offset);
}

int32_t rice::p2p::multiring::RingId::getByteArrayLength()
{
    return npc(id)->getByteArrayLength();
}

bool rice::p2p::multiring::RingId::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< RingId* >(o) != nullptr))
        return false;

    return (npc(npc((java_cast< RingId* >(o)))->id)->equals(id) && npc(npc((java_cast< RingId* >(o)))->ringId)->equals(ringId));
}

int32_t rice::p2p::multiring::RingId::hashCode()
{
    return (npc(id)->hashCode() * npc(ringId)->hashCode());
}

java::lang::String* rice::p2p::multiring::RingId::toString()
{
    return ::java::lang::StringBuilder().append(u"("_j)->append(static_cast< ::java::lang::Object* >(ringId))
        ->append(u", "_j)
        ->append(static_cast< ::java::lang::Object* >(id))
        ->append(u")"_j)->toString();
}

java::lang::String* rice::p2p::multiring::RingId::toStringFull()
{
    return ::java::lang::StringBuilder().append(u"("_j)->append(npc(ringId)->toStringFull())
        ->append(u", "_j)
        ->append(npc(id)->toStringFull())
        ->append(u")"_j)->toString();
}

int32_t rice::p2p::multiring::RingId::compareTo(::rice::p2p::commonapi::Id* o)
{
    return npc(id)->compareTo(npc((java_cast< RingId* >(o)))->id);
}

int32_t rice::p2p::multiring::RingId::compareTo(::java::lang::Object* o)
{ 
    return compareTo(dynamic_cast< ::rice::p2p::commonapi::Id* >(o));
}

int16_t rice::p2p::multiring::RingId::getType()
{
    return TYPE_;
}

void rice::p2p::multiring::RingId::serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    npc(buf)->writeShort(npc(ringId)->getType());
    npc(ringId)->serialize(buf);
    npc(buf)->writeShort(npc(id)->getType());
    npc(id)->serialize(buf);
}

void rice::p2p::multiring::RingId::ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::rice::p2p::commonapi::Endpoint* endpoint) /* throws(IOException) */
{
    super::ctor();
    ringId = npc(endpoint)->readId(buf, npc(buf)->readShort());
    id = npc(endpoint)->readId(buf, npc(buf)->readShort());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::RingId::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.RingId", 25);
    return c;
}

void rice::p2p::multiring::RingId::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        TYPE_ = int32_t(2);
        RINGID_MAP_ = new ::java::util::WeakHashMap();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::multiring::RingId::getClass0()
{
    return class_();
}

