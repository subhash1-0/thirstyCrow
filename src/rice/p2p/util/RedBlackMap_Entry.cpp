// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_Entry.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map_Entry.hpp>
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

rice::p2p::util::RedBlackMap_Entry::RedBlackMap_Entry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::RedBlackMap_Entry::RedBlackMap_Entry(::java::lang::Object* key, ::java::lang::Object* value, RedBlackMap_Entry* parent) 
    : RedBlackMap_Entry(*static_cast< ::default_init_tag* >(0))
{
    ctor(key,value,parent);
}

void rice::p2p::util::RedBlackMap_Entry::init()
{
    left = nullptr;
    right = nullptr;
    color = RedBlackMap::BLACK;
    deleted = false;
}

void rice::p2p::util::RedBlackMap_Entry::ctor(::java::lang::Object* key, ::java::lang::Object* value, RedBlackMap_Entry* parent)
{
    super::ctor();
    init();
    this->key = key;
    this->value = value;
    this->parent = parent;
}

java::lang::Object* rice::p2p::util::RedBlackMap_Entry::getKey()
{
    return key;
}

java::lang::Object* rice::p2p::util::RedBlackMap_Entry::getValue()
{
    return value;
}

java::lang::Object* rice::p2p::util::RedBlackMap_Entry::setValue(::java::lang::Object* value)
{
    auto oldValue = this->value;
    this->value = value;
    return oldValue;
}

bool rice::p2p::util::RedBlackMap_Entry::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< ::java::util::Map_Entry* >(o) != nullptr))
        return false;

    auto e = java_cast< ::java::util::Map_Entry* >(o);
    return RedBlackMap::valEquals(key, java_cast< ::java::lang::Object* >(npc(e)->getKey())) && RedBlackMap::valEquals(value, java_cast< ::java::lang::Object* >(npc(e)->getValue()));
}

int32_t rice::p2p::util::RedBlackMap_Entry::hashCode()
{
    auto keyHash = (key == nullptr ? int32_t(0) : npc(key)->hashCode());
    auto valueHash = (value == nullptr ? int32_t(0) : npc(value)->hashCode());
    return keyHash ^ valueHash;
}

java::lang::String* rice::p2p::util::RedBlackMap_Entry::toString()
{
    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(key))->append(u"="_j)
        ->append(static_cast< ::java::lang::Object* >(value))->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_Entry::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.Entry", 31);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_Entry::getClass0()
{
    return class_();
}

