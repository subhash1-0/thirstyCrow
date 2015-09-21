// Generated from /pastry-2.1/src/rice/p2p/glacier/VersionKeySet.java
#include <rice/p2p/glacier/VersionKeySet.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/glacier/VersionKey.hpp>
#include <rice/p2p/glacier/VersionKeyRange.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>
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

rice::p2p::glacier::VersionKeySet::VersionKeySet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::VersionKeySet::VersionKeySet() 
    : VersionKeySet(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::glacier::VersionKeySet::VersionKeySet(VersionKeySet* o) 
    : VersionKeySet(*static_cast< ::default_init_tag* >(0))
{
    ctor(o);
}

rice::p2p::glacier::VersionKeySet::VersionKeySet(::java::util::SortedMap* s) 
    : VersionKeySet(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

void rice::p2p::glacier::VersionKeySet::ctor()
{
    super::ctor();
    idSet = new ::rice::p2p::util::RedBlackMap();
    validHash = false;
}

void rice::p2p::glacier::VersionKeySet::ctor(VersionKeySet* o)
{
    super::ctor();
    idSet = new ::rice::p2p::util::RedBlackMap(npc(o)->idSet);
    cachedHash = npc(o)->cachedHash;
    validHash = npc(o)->validHash;
}

void rice::p2p::glacier::VersionKeySet::ctor(::java::util::SortedMap* s)
{
    super::ctor();
    idSet = s;
    validHash = false;
}

bool rice::p2p::glacier::VersionKeySet::isMember(::rice::p2p::commonapi::Id* id)
{
    return npc(idSet)->containsKey(id);
}

java::util::Iterator* rice::p2p::glacier::VersionKeySet::getIterator()
{
    return npc(npc(idSet)->keySet())->iterator();
}

int8_tArray* rice::p2p::glacier::VersionKeySet::getHash()
{
    throw new ::java::lang::RuntimeException(u"VersionKeySet.getHash() is not supported!"_j);
}

bool rice::p2p::glacier::VersionKeySet::isMemberId(::rice::p2p::commonapi::Id* id)
{
    return isMember(id);
}

int32_t rice::p2p::glacier::VersionKeySet::numElements()
{
    return npc(idSet)->size();
}

void rice::p2p::glacier::VersionKeySet::addMember(::rice::p2p::commonapi::Id* id)
{
    npc(idSet)->put(id, nullptr);
    validHash = false;
}

void rice::p2p::glacier::VersionKeySet::removeMember(::rice::p2p::commonapi::Id* id)
{
    npc(idSet)->remove(id);
    validHash = false;
}

rice::p2p::glacier::VersionKey* rice::p2p::glacier::VersionKeySet::minMember()
{
    return java_cast< VersionKey* >(java_cast< ::java::lang::Object* >(npc(idSet)->firstKey()));
}

rice::p2p::glacier::VersionKey* rice::p2p::glacier::VersionKeySet::maxMember()
{
    return java_cast< VersionKey* >(java_cast< ::java::lang::Object* >(npc(idSet)->lastKey()));
}

rice::p2p::glacier::VersionKeySet* rice::p2p::glacier::VersionKeySet::subSet(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to)
{
    return new VersionKeySet(npc(idSet)->subMap(from, to));
}

rice::p2p::glacier::VersionKeySet* rice::p2p::glacier::VersionKeySet::subSet(VersionKeyRange* range)
{
    if(npc(range)->isEmpty())
        return new VersionKeySet();

    if(npc(npc(range)->getCCWId())->equals(npc(range)->getCWId()))
        return this;
    else
        return subSet(npc(range)->getCCWId(), npc(range)->getCWId());
}

java::lang::String* rice::p2p::glacier::VersionKeySet::toString()
{
    auto it = getIterator();
    ::rice::p2p::commonapi::Id* key;
    auto s = u"[ IdSet:  ]"_j;
    return s;
}

void rice::p2p::glacier::VersionKeySet::addId(::rice::p2p::commonapi::Id* id)
{
    addMember(id);
}

void rice::p2p::glacier::VersionKeySet::removeId(::rice::p2p::commonapi::Id* id)
{
    removeMember(java_cast< VersionKey* >(id));
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::VersionKeySet::subSet(::rice::p2p::commonapi::IdRange* range)
{
    return subSet(java_cast< VersionKeyRange* >(range));
}

int8_tArray* rice::p2p::glacier::VersionKeySet::hash()
{
    return getHash();
}

java::lang::Object* rice::p2p::glacier::VersionKeySet::clone()
{
    return new VersionKeySet(this);
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::VersionKeySet::build()
{
    return new VersionKeySet();
}

rice::p2p::commonapi::IdArray* rice::p2p::glacier::VersionKeySet::asArray_()
{
    return java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(idSet)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray(int32_t(0))))));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::VersionKeySet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.VersionKeySet", 30);
    return c;
}

java::lang::Class* rice::p2p::glacier::VersionKeySet::getClass0()
{
    return class_();
}

