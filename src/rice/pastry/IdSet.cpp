// Generated from /pastry-2.1/src/rice/pastry/IdSet.java
#include <rice/pastry/IdSet.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/MessageDigest.hpp>
#include <java/security/NoSuchAlgorithmException.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/commonapi/Id.hpp>
#include <rice/p2p/commonapi/IdRange.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/IdRange.hpp>
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

rice::pastry::IdSet::IdSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::IdSet::IdSet() 
    : IdSet(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::pastry::IdSet::IdSet(::java::util::SortedMap* s) 
    : IdSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(s);
}

constexpr int64_t rice::pastry::IdSet::serialVersionUID;

void rice::pastry::IdSet::ctor()
{
    super::ctor();
    idSet = new ::rice::p2p::util::RedBlackMap();
    validHash = false;
}

void rice::pastry::IdSet::ctor(::java::util::SortedMap* s)
{
    super::ctor();
    idSet = s;
    validHash = false;
}

int32_t rice::pastry::IdSet::numElements()
{
    return npc(idSet)->size();
}

void rice::pastry::IdSet::addMember(Id* id)
{
    npc(idSet)->put(id, nullptr);
    validHash = false;
}

void rice::pastry::IdSet::removeMember(Id* id)
{
    npc(idSet)->remove(id);
    validHash = false;
}

bool rice::pastry::IdSet::isMember(Id* id)
{
    return npc(idSet)->containsKey(id);
}

rice::pastry::Id* rice::pastry::IdSet::minMember()
{
    return java_cast< Id* >(java_cast< ::java::lang::Object* >(npc(idSet)->firstKey()));
}

rice::pastry::Id* rice::pastry::IdSet::maxMember()
{
    return java_cast< Id* >(java_cast< ::java::lang::Object* >(npc(idSet)->lastKey()));
}

rice::pastry::IdSet* rice::pastry::IdSet::subSet(Id* from, Id* to)
{
    return new ::rice::pastry::IdSet(npc(idSet)->subMap(from, to));
}

rice::pastry::IdSet* rice::pastry::IdSet::subSet(IdRange* range)
{
    if(npc(range)->isEmpty()) {
        return new ::rice::pastry::IdSet();
    } else if(npc(npc(range)->getCCW())->equals(npc(range)->getCW())) {
        return this;
    } else {
        return subSet(npc(range)->getCCW(), npc(range)->getCW());
    }
}

java::util::Iterator* rice::pastry::IdSet::getIterator()
{
    return npc(npc(idSet)->keySet())->iterator();
}

int8_tArray* rice::pastry::IdSet::getHash()
{
    if(validHash)
        return cachedHash;

    ::java::security::MessageDigest* md = nullptr;
    try {
        md = ::java::security::MessageDigest::getInstance(u"SHA"_j);
    } catch (::java::security::NoSuchAlgorithmException* e) {
        throw new ::java::lang::RuntimeException(u"No SHA support!"_j, e);
    }
    auto it = getIterator();
    auto raw = new ::int8_tArray(Id::IdBitLength / int32_t(8));
    Id* id;
    while (npc(it)->hasNext()) {
        id = java_cast< Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
        npc(id)->blit(raw);
        npc(md)->update(raw);
    }
    cachedHash = npc(md)->digest();
    validHash = true;
    return cachedHash;
}

java::lang::String* rice::pastry::IdSet::toString()
{
    auto it = getIterator();
    Id* key;
    auto s = u"[ IdSet: "_j;
    while (npc(it)->hasNext()) {
        key = java_cast< Id* >(java_cast< ::java::lang::Object* >(npc(it)->next()));
        s = ::java::lang::StringBuilder().append(s)->append(static_cast< ::java::lang::Object* >(key))
            ->append(u","_j)->toString();
    }
    s = ::java::lang::StringBuilder().append(s)->append(u" ]"_j)->toString();
    return s;
}

void rice::pastry::IdSet::addId(::rice::p2p::commonapi::Id* id)
{
    addMember(java_cast< Id* >(id));
}

void rice::pastry::IdSet::removeId(::rice::p2p::commonapi::Id* id)
{
    removeMember(java_cast< Id* >(id));
}

bool rice::pastry::IdSet::isMemberId(::rice::p2p::commonapi::Id* id)
{
    return isMember(java_cast< Id* >(id));
}

rice::p2p::commonapi::IdSet* rice::pastry::IdSet::build()
{
    return new ::rice::pastry::IdSet();
}

rice::p2p::commonapi::IdSet* rice::pastry::IdSet::subSet(::rice::p2p::commonapi::IdRange* range)
{
    return subSet(java_cast< IdRange* >(range));
}

int8_tArray* rice::pastry::IdSet::hash()
{
    return getHash();
}

rice::p2p::commonapi::IdArray* rice::pastry::IdSet::asArray_()
{
    return java_cast< ::rice::p2p::commonapi::IdArray* >(java_cast< ::java::lang::ObjectArray* >(npc(npc(idSet)->keySet())->toArray_(static_cast< ::java::lang::ObjectArray* >(new ::rice::p2p::commonapi::IdArray(int32_t(0))))));
}

java::lang::Object* rice::pastry::IdSet::clone()
{
    return new ::rice::pastry::IdSet(idSet);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::IdSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.IdSet", 17);
    return c;
}

java::lang::Class* rice::pastry::IdSet::getClass0()
{
    return class_();
}

