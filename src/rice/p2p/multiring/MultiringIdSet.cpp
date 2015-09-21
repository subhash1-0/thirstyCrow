// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdSet.java
#include <rice/p2p/multiring/MultiringIdSet.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/multiring/MultiringIdRange.hpp>
#include <rice/p2p/multiring/MultiringIdSet_getIterator_1.hpp>
#include <rice/p2p/multiring/RingId.hpp>
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

rice::p2p::multiring::MultiringIdSet::MultiringIdSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::multiring::MultiringIdSet::MultiringIdSet(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdSet* set) 
    : MultiringIdSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(ringId,set);
}

constexpr int64_t rice::p2p::multiring::MultiringIdSet::serialVersionUID;

void rice::p2p::multiring::MultiringIdSet::ctor(::rice::p2p::commonapi::Id* ringId, ::rice::p2p::commonapi::IdSet* set)
{
    super::ctor();
    this->ringId = ringId;
    this->set = set;
    if((dynamic_cast< RingId* >(ringId) != nullptr) || (dynamic_cast< MultiringIdSet* >(set) != nullptr))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Illegal creation of MRIdSet: "_j)->append(static_cast< ::java::lang::Object* >(npc(ringId)->getClass()))
            ->append(u", "_j)
            ->append(static_cast< ::java::lang::Object* >(npc(set)->getClass()))->toString());

}

rice::p2p::commonapi::IdSet* rice::p2p::multiring::MultiringIdSet::getSet()
{
    return set;
}

int32_t rice::p2p::multiring::MultiringIdSet::numElements()
{
    return npc(set)->numElements();
}

void rice::p2p::multiring::MultiringIdSet::addId(::rice::p2p::commonapi::Id* id)
{
    npc(set)->addId(npc((java_cast< RingId* >(id)))->getId());
}

void rice::p2p::multiring::MultiringIdSet::removeId(::rice::p2p::commonapi::Id* id)
{
    npc(set)->removeId(npc((java_cast< RingId* >(id)))->getId());
}

bool rice::p2p::multiring::MultiringIdSet::isMemberId(::rice::p2p::commonapi::Id* id)
{
    return npc(set)->isMemberId(npc((java_cast< RingId* >(id)))->getId());
}

rice::p2p::commonapi::IdSet* rice::p2p::multiring::MultiringIdSet::subSet(::rice::p2p::commonapi::IdRange* range)
{
    if(range == nullptr)
        return java_cast< ::rice::p2p::commonapi::IdSet* >(this->clone());
    else
        return new MultiringIdSet(ringId, npc(set)->subSet(npc((java_cast< MultiringIdRange* >(range)))->getRange()));
}

java::util::Iterator* rice::p2p::multiring::MultiringIdSet::getIterator()
{
    return new MultiringIdSet_getIterator_1(this);
}

rice::p2p::commonapi::IdArray* rice::p2p::multiring::MultiringIdSet::asArray_()
{
    auto result = npc(set)->asArray_();
    for (auto i = int32_t(0); i < npc(result)->length; i++) 
                result->set(i, RingId::build(ringId, (*result)[i]));

    return result;
}

int8_tArray* rice::p2p::multiring::MultiringIdSet::hash()
{
    return npc(set)->hash();
}

bool rice::p2p::multiring::MultiringIdSet::equals(::java::lang::Object* o)
{
    auto other = java_cast< MultiringIdSet* >(o);
    return (npc(npc(other)->getSet())->equals(set) && npc(npc(other)->ringId)->equals(ringId));
}

int32_t rice::p2p::multiring::MultiringIdSet::hashCode()
{
    return (npc(set)->hashCode() + npc(ringId)->hashCode());
}

java::lang::String* rice::p2p::multiring::MultiringIdSet::toString()
{
    return ::java::lang::StringBuilder().append(u"{RingId "_j)->append(static_cast< ::java::lang::Object* >(ringId))
        ->append(u" "_j)
        ->append(npc(set)->toString())
        ->append(u"}"_j)->toString();
}

java::lang::Object* rice::p2p::multiring::MultiringIdSet::clone()
{
    return new MultiringIdSet(ringId, java_cast< ::rice::p2p::commonapi::IdSet* >(npc(set)->clone()));
}

rice::p2p::commonapi::IdSet* rice::p2p::multiring::MultiringIdSet::build()
{
    return new MultiringIdSet(ringId, npc(set)->build());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::multiring::MultiringIdSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.multiring.MultiringIdSet", 33);
    return c;
}

java::lang::Class* rice::p2p::multiring::MultiringIdSet::getClass0()
{
    return class_();
}

