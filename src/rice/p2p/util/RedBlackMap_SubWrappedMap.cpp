// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_SubWrappedMap.hpp>

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
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_SubMap.hpp>
#include <rice/p2p/util/RedBlackMap_SubWrappedMap_EntrySetView.hpp>
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

rice::p2p::util::RedBlackMap_SubWrappedMap::RedBlackMap_SubWrappedMap(RedBlackMap *RedBlackMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
}

rice::p2p::util::RedBlackMap_SubWrappedMap::RedBlackMap_SubWrappedMap(RedBlackMap *RedBlackMap_this, ::java::lang::Object* fromKey, ::java::lang::Object* toKey) 
    : RedBlackMap_SubWrappedMap(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(fromKey,toKey);
}

void rice::p2p::util::RedBlackMap_SubWrappedMap::init()
{
    entrySet_ = new RedBlackMap_SubWrappedMap_EntrySetView(this);
}

constexpr int64_t rice::p2p::util::RedBlackMap_SubWrappedMap::serialVersionUID;

void rice::p2p::util::RedBlackMap_SubWrappedMap::ctor(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    super::ctor();
    init();
    if(RedBlackMap_this->compare(fromKey, toKey) < 0)
        throw new ::java::lang::IllegalArgumentException(u"fromKey < toKey"_j);

    this->fromKey = fromKey;
    this->toKey = toKey;
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::isEmpty()
{
    return npc(entrySet_)->isEmpty();
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::containsKey(::java::lang::Object* key)
{
    return inRange(key) && RedBlackMap_this->containsKey(key);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubWrappedMap::get(::java::lang::Object* key)
{
    if(!inRange(key))
        return nullptr;

    return RedBlackMap_this->get(key);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubWrappedMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    if(!inRange(key))
        throw new ::java::lang::IllegalArgumentException(u"key out of range"_j);

    return RedBlackMap_this->put(key, value);
}

java::util::Comparator* rice::p2p::util::RedBlackMap_SubWrappedMap::comparator()
{
    return RedBlackMap_this->comparator_;
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubWrappedMap::firstKey()
{
    if(RedBlackMap_this->compare(RedBlackMap::key(RedBlackMap_this->firstEntry()), toKey) < 0)
        return RedBlackMap::key(RedBlackMap_this->firstEntry());

    if(RedBlackMap_this->getCeilEntry(fromKey) == nullptr)
        throw new ::java::util::NoSuchElementException();

    return RedBlackMap::key(RedBlackMap_this->getCeilEntry(fromKey));
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubWrappedMap::lastKey()
{
    if(RedBlackMap_this->compare(RedBlackMap::key(RedBlackMap_this->lastEntry()), fromKey) > 0)
        return RedBlackMap::key(RedBlackMap_this->lastEntry());

    if(RedBlackMap_this->getPrecedingEntry(toKey) == nullptr)
        throw new ::java::util::NoSuchElementException();

    return RedBlackMap::key(RedBlackMap_this->getPrecedingEntry(toKey));
}

java::util::Set* rice::p2p::util::RedBlackMap_SubWrappedMap::entrySet()
{
    return entrySet_;
}

java::util::SortedMap* rice::p2p::util::RedBlackMap_SubWrappedMap::subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey)
{
    if(RedBlackMap_this->compare(fromKey, toKey) > 0) {
        if((RedBlackMap_this->compare(fromKey, this->toKey) < 0) && (RedBlackMap_this->compare(toKey, this->fromKey) > 0)) {
            fromKey = ((RedBlackMap_this->compare(fromKey, this->fromKey) < 0) ? this->fromKey : fromKey);
            toKey = ((RedBlackMap_this->compare(toKey, this->toKey) > 0) ? this->toKey : toKey);
            return new RedBlackMap_SubWrappedMap(RedBlackMap_this, fromKey, toKey);
        } else {
            return (new RedBlackMap(static_cast< ::java::util::SortedMap* >(this)))->subMap(fromKey, toKey);
        }
    } else {
        if((RedBlackMap_this->compare(fromKey, this->toKey) < 0) && (RedBlackMap_this->compare(toKey, this->fromKey) > 0)) {
            return (new RedBlackMap(static_cast< ::java::util::SortedMap* >(this)))->subMap(fromKey, toKey);
        } else {
            fromKey = (((RedBlackMap_this->compare(fromKey, this->toKey) > 0) && (RedBlackMap_this->compare(fromKey, this->fromKey) < 0)) ? this->fromKey : fromKey);
            toKey = (((RedBlackMap_this->compare(toKey, this->toKey) > 0) && (RedBlackMap_this->compare(toKey, this->fromKey) < 0)) ? this->toKey : toKey);
            if(RedBlackMap_this->compare(fromKey, toKey) > 0)
                return new RedBlackMap_SubMap(RedBlackMap_this, fromKey, fromKey);
            else
                return new RedBlackMap_SubMap(RedBlackMap_this, fromKey, toKey);
        }
    }
}

java::util::SortedMap* rice::p2p::util::RedBlackMap_SubWrappedMap::headMap(::java::lang::Object* toKey)
{
    if(RedBlackMap_this->compare(toKey, this->fromKey) > 0)
        return (new RedBlackMap(static_cast< ::java::util::SortedMap* >(this)))->headMap(toKey);
    else if(RedBlackMap_this->compare(toKey, this->toKey) > 0)
        return RedBlackMap_this->headMap(this->toKey);
    else
        return RedBlackMap_this->headMap(toKey);
}

java::util::SortedMap* rice::p2p::util::RedBlackMap_SubWrappedMap::tailMap(::java::lang::Object* fromKey)
{
    if(RedBlackMap_this->compare(fromKey, this->toKey) < 0)
        return (new RedBlackMap(static_cast< ::java::util::SortedMap* >(this)))->tailMap(fromKey);
    else if(RedBlackMap_this->compare(fromKey, this->fromKey) < 0)
        return RedBlackMap_this->tailMap(this->fromKey);
    else
        return RedBlackMap_this->tailMap(fromKey);
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::inRange(::java::lang::Object* key)
{
    return (RedBlackMap_this->compare(key, fromKey) >= 0) || (RedBlackMap_this->compare(key, toKey) < 0);
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::inRange2(::java::lang::Object* key)
{
    return (RedBlackMap_this->compare(key, fromKey) >= 0) || (RedBlackMap_this->compare(key, toKey) <= 0);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_SubWrappedMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.SubWrappedMap", 39);
    return c;
}

void rice::p2p::util::RedBlackMap_SubWrappedMap::clear()
{
    AbstractMap::clear();
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::containsValue(::java::lang::Object* value)
{
    return AbstractMap::containsValue(value);
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::equals(::java::lang::Object* o)
{
    return AbstractMap::equals(o);
}

int32_t rice::p2p::util::RedBlackMap_SubWrappedMap::hashCode()
{
    return AbstractMap::hashCode();
}

void rice::p2p::util::RedBlackMap_SubWrappedMap::putAll(::java::util::Map* m)
{
    AbstractMap::putAll(m);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubWrappedMap::remove(::java::lang::Object* key)
{
    return AbstractMap::remove(key);
}

int32_t rice::p2p::util::RedBlackMap_SubWrappedMap::size()
{
    return AbstractMap::size();
}

java::util::Set* rice::p2p::util::RedBlackMap_SubWrappedMap::keySet()
{
    return java_cast< ::java::util::Set* >(AbstractMap::keySet());
}

java::util::Collection* rice::p2p::util::RedBlackMap_SubWrappedMap::values()
{
    return java_cast< ::java::util::Collection* >(AbstractMap::values());
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap::remove(::java::lang::Object* key, ::java::lang::Object* value)
{
    return super::remove(key, value);
}

java::lang::Class* rice::p2p::util::RedBlackMap_SubWrappedMap::getClass0()
{
    return class_();
}

