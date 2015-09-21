// Generated from /pastry-2.1/src/rice/p2p/glacier/FragmentKeySet.java
#include <rice/p2p/glacier/FragmentKeySet.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/glacier/FragmentKey.hpp>
#include <rice/p2p/glacier/FragmentKeyRange.hpp>
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

rice::p2p::glacier::FragmentKeySet::FragmentKeySet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::glacier::FragmentKeySet::FragmentKeySet() 
    : FragmentKeySet(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::glacier::FragmentKeySet::FragmentKeySet(FragmentKeySet* o) 
    : FragmentKeySet(*static_cast< ::default_init_tag* >(0))
{
    ctor(o);
}

rice::p2p::glacier::FragmentKeySet::FragmentKeySet(::java::util::SortedMap* s) 
    : FragmentKeySet(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

void rice::p2p::glacier::FragmentKeySet::ctor()
{
    super::ctor();
    idSet = new ::rice::p2p::util::RedBlackMap();
    validHash = false;
}

void rice::p2p::glacier::FragmentKeySet::ctor(FragmentKeySet* o)
{
    super::ctor();
    idSet = new ::rice::p2p::util::RedBlackMap(npc(o)->idSet);
    cachedHash = npc(o)->cachedHash;
    validHash = npc(o)->validHash;
}

void rice::p2p::glacier::FragmentKeySet::ctor(::java::util::SortedMap* s)
{
    super::ctor();
    idSet = s;
    validHash = false;
}

bool rice::p2p::glacier::FragmentKeySet::isMember(::rice::p2p::commonapi::Id* id)
{
    return npc(idSet)->containsKey(id);
}

java::util::Iterator* rice::p2p::glacier::FragmentKeySet::getIterator()
{
    return npc(npc(idSet)->keySet())->iterator();
}

int8_tArray* rice::p2p::glacier::FragmentKeySet::getHash()
{
    throw new ::java::lang::RuntimeException(u"FragmentKeySet.getHash() is not supported!"_j);
}

bool rice::p2p::glacier::FragmentKeySet::isMemberId(::rice::p2p::commonapi::Id* id)
{
    return isMember(id);
}

int32_t rice::p2p::glacier::FragmentKeySet::numElements()
{
    return npc(idSet)->size();
}

void rice::p2p::glacier::FragmentKeySet::addMember(::rice::p2p::commonapi::Id* id)
{
    npc(idSet)->put(id, nullptr);
    validHash = false;
}

void rice::p2p::glacier::FragmentKeySet::removeMember(::rice::p2p::commonapi::Id* id)
{
    npc(idSet)->remove(id);
    validHash = false;
}

rice::p2p::glacier::FragmentKey* rice::p2p::glacier::FragmentKeySet::minMember()
{
    return java_cast< FragmentKey* >(java_cast< ::java::lang::Object* >(npc(idSet)->firstKey()));
}

rice::p2p::glacier::FragmentKey* rice::p2p::glacier::FragmentKeySet::maxMember()
{
    return java_cast< FragmentKey* >(java_cast< ::java::lang::Object* >(npc(idSet)->lastKey()));
}

rice::p2p::glacier::FragmentKeySet* rice::p2p::glacier::FragmentKeySet::subSet(::rice::p2p::commonapi::Id* from, ::rice::p2p::commonapi::Id* to)
{
    return new FragmentKeySet(npc(idSet)->subMap(from, to));
}

rice::p2p::glacier::FragmentKeySet* rice::p2p::glacier::FragmentKeySet::subSet(FragmentKeyRange* range)
{
    if(npc(range)->isEmpty())
        return new FragmentKeySet();

    if(npc(npc(range)->getCCWId())->equals(npc(range)->getCWId()))
        return this;
    else
        return subSet(npc(range)->getCCWId(), npc(range)->getCWId());
}

java::lang::String* rice::p2p::glacier::FragmentKeySet::toString()
{
    auto it = getIterator();
    ::rice::p2p::commonapi::Id* key;
    auto s = u"[ IdSet: "_j;
    while (npc(it)->hasNext()) {
        key = java_cast< ::rice::p2p::commonapi::Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
        s = ::java::lang::StringBuilder().append(s)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u","_j)->toString();
    }
    s = ::java::lang::StringBuilder().append(s)->append(u" ]"_j)->toString();
    return s;
}

void rice::p2p::glacier::FragmentKeySet::addId(::rice::p2p::commonapi::Id* id)
{
    addMember(id);
}

void rice::p2p::glacier::FragmentKeySet::removeId(::rice::p2p::commonapi::Id* id)
{
    removeMember(java_cast< FragmentKey* >(id));
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::FragmentKeySet::subSet(::rice::p2p::commonapi::IdRange* range)
{
    return subSet(java_cast< FragmentKeyRange* >(range));
}

int8_tArray* rice::p2p::glacier::FragmentKeySet::hash()
{
    return getHash();
}

java::lang::Object* rice::p2p::glacier::FragmentKeySet::clone()
{
    return new FragmentKeySet(this);
}

rice::p2p::commonapi::IdSet* rice::p2p::glacier::FragmentKeySet::build()
{
    return new FragmentKeySet();
}

rice::p2p::commonapi::IdArray* rice::p2p::glacier::FragmentKeySet::asArray_()
{
    return java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(idSet)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray(int32_t(0))))));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::glacier::FragmentKeySet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.glacier.FragmentKeySet", 31);
    return c;
}

java::lang::Class* rice::p2p::glacier::FragmentKeySet::getClass0()
{
    return class_();
}

