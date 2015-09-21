// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdSet.java
#include <rice/p2p/past/gc/GCIdSet.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdFactory.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/commonapi/IdSet.hpp>
#include <rice/p2p/past/gc/GCId.hpp>
#include <rice/p2p/past/gc/GCIdRange.hpp>
#include <rice/p2p/past/gc/GCIdSet_getIterator_1.hpp>
#include <rice/p2p/past/gc/GCPastImpl.hpp>
#include <rice/p2p/past/gc/GCPastMetadata.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>
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

rice::p2p::past::gc::GCIdSet::GCIdSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::past::gc::GCIdSet::GCIdSet(::rice::p2p::commonapi::IdFactory* factory) 
    : GCIdSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(factory);
}

rice::p2p::past::gc::GCIdSet::GCIdSet(::rice::p2p::commonapi::IdSet* set, ::java::util::SortedMap* timeouts) 
    : GCIdSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(set,timeouts);
}

void rice::p2p::past::gc::GCIdSet::ctor(::rice::p2p::commonapi::IdFactory* factory)
{
    super::ctor();
    this->ids = npc(factory)->buildIdSet();
    this->timeouts = new ::rice::p2p::util::RedBlackMap();
}

void rice::p2p::past::gc::GCIdSet::ctor(::rice::p2p::commonapi::IdSet* set, ::java::util::SortedMap* timeouts)
{
    super::ctor();
    this->ids = set;
    this->timeouts = timeouts;
}

int32_t rice::p2p::past::gc::GCIdSet::numElements()
{
    return npc(ids)->numElements();
}

void rice::p2p::past::gc::GCIdSet::addId(::rice::p2p::commonapi::Id* id)
{
    auto gcid = java_cast< GCId* >(id);
    npc(ids)->addId(npc(gcid)->getId());
    npc(timeouts)->put(npc(gcid)->getId(), new GCPastMetadata(npc(gcid)->getExpiration()));
}

void rice::p2p::past::gc::GCIdSet::removeId(::rice::p2p::commonapi::Id* id)
{
    auto gcid = java_cast< GCId* >(id);
    npc(ids)->removeId(npc(gcid)->getId());
    npc(timeouts)->remove(npc(gcid)->getId());
}

bool rice::p2p::past::gc::GCIdSet::isMemberId(::rice::p2p::commonapi::Id* id)
{
    auto gcid = java_cast< GCId* >(id);
    return npc(ids)->isMemberId(npc(gcid)->getId());
}

rice::p2p::commonapi::IdSet* rice::p2p::past::gc::GCIdSet::subSet(::rice::p2p::commonapi::IdRange* range)
{
    return new GCIdSet(npc(ids)->subSet(npc((java_cast< GCIdRange* >(range)))->getRange()), timeouts);
}

java::util::Iterator* rice::p2p::past::gc::GCIdSet::getIterator()
{
    return new GCIdSet_getIterator_1(this);
}

rice::p2p::past::gc::GCId* rice::p2p::past::gc::GCIdSet::getGCId(::rice::p2p::commonapi::Id* id)
{
    auto metadata = java_cast< GCPastMetadata* >(java_cast< ::java::lang::Object* >(npc(timeouts)->get(id)));
    if(metadata != nullptr)
        return new GCId(id, npc(metadata)->getExpiration());
    else
        return new GCId(id, GCPastImpl::DEFAULT_EXPIRATION);
}

rice::p2p::commonapi::IdArray* rice::p2p::past::gc::GCIdSet::asArray_()
{
    auto array = npc(ids)->asArray_();
    for (auto i = int32_t(0); i < npc(array)->length; i++) 
                array->set(i, getGCId((*array)[i]));

    return array;
}

int8_tArray* rice::p2p::past::gc::GCIdSet::hash()
{
    throw new ::java::lang::UnsupportedOperationException(u"hash on GCIdSet()!"_j);
}

bool rice::p2p::past::gc::GCIdSet::equals(::java::lang::Object* o)
{
    auto other = java_cast< GCIdSet* >(o);
    if(numElements() != npc(other)->numElements())
        return false;

    auto i = npc(ids)->getIterator();
    while (npc(i)->hasNext()) 
                if(!npc(other)->isMemberId(java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::rice::p2p::commonapi::Id* >(npc(i)->next()))))
            return false;


    return true;
}

int32_t rice::p2p::past::gc::GCIdSet::hashCode()
{
    return npc(ids)->hashCode();
}

java::lang::String* rice::p2p::past::gc::GCIdSet::toString()
{
    return ::java::lang::StringBuilder().append(u"{GCIdSet of size "_j)->append(numElements())
        ->append(u"}"_j)->toString();
}

java::lang::Object* rice::p2p::past::gc::GCIdSet::clone()
{
    return new GCIdSet(ids, timeouts);
}

rice::p2p::commonapi::IdSet* rice::p2p::past::gc::GCIdSet::build()
{
    return new GCIdSet(npc(ids)->build(), new ::rice::p2p::util::RedBlackMap());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::gc::GCIdSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.past.gc.GCIdSet", 24);
    return c;
}

java::lang::Class* rice::p2p::past::gc::GCIdSet::getClass0()
{
    return class_();
}

