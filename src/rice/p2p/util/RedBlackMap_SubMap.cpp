// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_SubMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
#include <rice/p2p/util/RedBlackMap_SubMap_EntrySetView.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

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

rice::p2p::util::RedBlackMap_SubMap::RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
}

rice::p2p::util::RedBlackMap_SubMap::RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, ::java::lang::Object* fromKey, ::java::lang::Object* toKey) 
    : RedBlackMap_SubMap(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(fromKey,toKey);
}

rice::p2p::util::RedBlackMap_SubMap::RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, ::java::lang::Object* key, bool headMap) 
    : RedBlackMap_SubMap(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(key,headMap);
}

rice::p2p::util::RedBlackMap_SubMap::RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, bool fromStart, ::java::lang::Object* fromKey, bool toEnd, ::java::lang::Object* toKey) 
    : RedBlackMap_SubMap(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(fromStart,fromKey,toEnd,toKey);
}

void rice::p2p::util::RedBlackMap_SubMap::init()
{
    fromStart = false;
    toEnd = false;
    entrySet_ = new RedBlackMap_SubMap_EntrySetView(this);
}

constexpr int64_t rice::p2p::util::RedBlackMap_SubMap::serialVersionUID;

void rice::p2p::util::RedBlackMap_SubMap::ctor(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    super::ctor();
    init();
    if(RedBlackMap_this->compare(fromKey, toKey) > 0)
        throw new ::java::lang::IllegalArgumentException(u"fromKey > toKey"_j);

    this->fromKey = fromKey;
    this->toKey = toKey;
}

void rice::p2p::util::RedBlackMap_SubMap::ctor(::java::lang::Object* key, bool headMap)
{
    super::ctor();
    init();
    RedBlackMap_this->compare(key, key);
    if(headMap) {
        fromStart = true;
        toKey = key;
    } else {
        toEnd = true;
        fromKey = key;
    }
}

void rice::p2p::util::RedBlackMap_SubMap::ctor(bool fromStart, ::java::lang::Object* fromKey, bool toEnd, ::java::lang::Object* toKey)
{
    super::ctor();
    init();
    this->fromStart = fromStart;
    this->fromKey = fromKey;
    this->toEnd = toEnd;
    this->toKey = toKey;
}

bool rice::p2p::util::RedBlackMap_SubMap::isEmpty()
{
    return npc(entrySet_)->isEmpty();
}

bool rice::p2p::util::RedBlackMap_SubMap::containsKey(::java::lang::Object* key)
{
    return inRange(key) && RedBlackMap_this->containsKey(key);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMap::get(::java::lang::Object* key)
{
    if(!inRange(key))
        return nullptr;

    return RedBlackMap_this->get(key);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    if(!inRange(key))
        throw new ::java::lang::IllegalArgumentException(u"key out of range"_j);

    return RedBlackMap_this->put(key, value);
}

java::util::Comparator* rice::p2p::util::RedBlackMap_SubMap::comparator()
{
    return RedBlackMap_this->comparator_;
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMap::firstKey()
{
    auto first = RedBlackMap::key(fromStart ? RedBlackMap_this->firstEntry() : RedBlackMap_this->getCeilEntry(fromKey));
    if(!toEnd && RedBlackMap_this->compare(first, toKey) >= 0)
        throw (new ::java::util::NoSuchElementException());

    return first;
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMap::lastKey()
{
    auto last = RedBlackMap::key(toEnd ? RedBlackMap_this->lastEntry() : RedBlackMap_this->getPrecedingEntry(toKey));
    if(!fromStart && RedBlackMap_this->compare(last, fromKey) < 0)
        throw (new ::java::util::NoSuchElementException());

    return last;
}

java::util::Set* rice::p2p::util::RedBlackMap_SubMap::entrySet()
{
    return entrySet_;
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMap::putInRange(::java::lang::Object* key)
{
    if((!fromStart) && (RedBlackMap_this->compare(key, fromKey) < 0))
        return fromKey;
    else if((!toEnd) && (RedBlackMap_this->compare(key, toKey) > 0))
        return toKey;
    else
        return key;
}

java::util::SortedMap* rice::p2p::util::RedBlackMap_SubMap::subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    if(RedBlackMap_this->compare(fromKey, toKey) > 0)
        return (new RedBlackMap(static_cast< ::java::util::SortedMap* >(this)))->subMap(fromKey, toKey);
    else
        return new RedBlackMap_SubMap(RedBlackMap_this, putInRange(fromKey), putInRange(toKey));
}

java::util::SortedMap* rice::p2p::util::RedBlackMap_SubMap::headMap(::java::lang::Object* toKey)
{
    return new RedBlackMap_SubMap(RedBlackMap_this, fromStart, fromKey, false, putInRange(toKey));
}

java::util::SortedMap* rice::p2p::util::RedBlackMap_SubMap::tailMap(::java::lang::Object* fromKey)
{
    return new RedBlackMap_SubMap(RedBlackMap_this, false, putInRange(fromKey), toEnd, toKey);
}

bool rice::p2p::util::RedBlackMap_SubMap::inRange(::java::lang::Object* key)
{
    return (fromStart || RedBlackMap_this->compare(key, fromKey) >= 0) && (toEnd || RedBlackMap_this->compare(key, toKey) < 0);
}

bool rice::p2p::util::RedBlackMap_SubMap::inRange2(::java::lang::Object* key)
{
    return (fromStart || RedBlackMap_this->compare(key, fromKey) >= 0) && (toEnd || RedBlackMap_this->compare(key, toKey) <= 0);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_SubMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.SubMap", 32);
    return c;
}

void rice::p2p::util::RedBlackMap_SubMap::clear()
{
    AbstractMap::clear();
}

bool rice::p2p::util::RedBlackMap_SubMap::containsValue(::java::lang::Object* value)
{
    return AbstractMap::containsValue(value);
}

bool rice::p2p::util::RedBlackMap_SubMap::equals(::java::lang::Object* o)
{
    return AbstractMap::equals(o);
}

int32_t rice::p2p::util::RedBlackMap_SubMap::hashCode()
{
    return AbstractMap::hashCode();
}

void rice::p2p::util::RedBlackMap_SubMap::putAll(::java::util::Map* m)
{
    AbstractMap::putAll(m);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMap::remove(::java::lang::Object* key)
{
    return AbstractMap::remove(key);
}

int32_t rice::p2p::util::RedBlackMap_SubMap::size()
{
    return AbstractMap::size();
}

java::util::Set* rice::p2p::util::RedBlackMap_SubMap::keySet()
{
    return java_cast< ::java::util::Set* >(AbstractMap::keySet());
}

java::util::Collection* rice::p2p::util::RedBlackMap_SubMap::values()
{
    return java_cast< ::java::util::Collection* >(AbstractMap::values());
}

bool rice::p2p::util::RedBlackMap_SubMap::remove(::java::lang::Object* key, ::java::lang::Object* value)
{
    return super::remove(key, value);
}

java::lang::Class* rice::p2p::util::RedBlackMap_SubMap::getClass0()
{
    return class_();
}

