// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_entrySet_3.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_EntryIterator.hpp>
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

rice::p2p::util::RedBlackMap_entrySet_3::RedBlackMap_entrySet_3(RedBlackMap *RedBlackMap_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
    ctor();
}

java::util::Iterator* rice::p2p::util::RedBlackMap_entrySet_3::iterator()
{
    return new RedBlackMap_EntryIterator(RedBlackMap_this);
}

bool rice::p2p::util::RedBlackMap_entrySet_3::contains(::java::lang::Object* o)
{
    if(!(dynamic_cast< ::java::util::Map_Entry* >(o) != nullptr))
        return false;

    auto entry = java_cast< ::java::util::Map_Entry* >(o);
    auto value = java_cast< ::java::lang::Object* >(npc(entry)->getValue());
    auto p = RedBlackMap_this->getEntry(java_cast< ::java::lang::Object* >(npc(entry)->getKey()));
    return p != nullptr && RedBlackMap::valEquals(npc(p)->getValue(), value);
}

bool rice::p2p::util::RedBlackMap_entrySet_3::remove(::java::lang::Object* o)
{
    if(!(dynamic_cast< ::java::util::Map_Entry* >(o) != nullptr))
        return false;

    auto entry = java_cast< ::java::util::Map_Entry* >(o);
    auto value = java_cast< ::java::lang::Object* >(npc(entry)->getValue());
    auto p = RedBlackMap_this->getEntry(java_cast< ::java::lang::Object* >(npc(entry)->getKey()));
    if(p != nullptr && RedBlackMap::valEquals(npc(p)->getValue(), value)) {
        RedBlackMap_this->deleteEntry(p);
        return true;
    }
    return false;
}

int32_t rice::p2p::util::RedBlackMap_entrySet_3::size()
{
    return RedBlackMap_this->size();
}

void rice::p2p::util::RedBlackMap_entrySet_3::clear()
{
    RedBlackMap_this->clear();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_entrySet_3::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_entrySet_3::getClass0()
{
    return class_();
}

