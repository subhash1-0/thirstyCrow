// Generated from /pastry-2.1/src/rice/p2p/util/SoftHashMap.java
#include <rice/p2p/util/SoftHashMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/ref/SoftReference.hpp>

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

rice::p2p::util::SoftHashMap::SoftHashMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::SoftHashMap::SoftHashMap()
    : SoftHashMap(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool rice::p2p::util::SoftHashMap::containsKey(::java::lang::Object* key)
{
    if(!super::containsKey(key))
        return false;

    if(super::get(key) == nullptr) {
        return true;
    } else {
        return (java_cast< ::java::lang::Object* >(npc((java_cast< ::java::lang::ref::SoftReference* >(super::get(key))))->get()) != nullptr);
    }
}

bool rice::p2p::util::SoftHashMap::containsValue(::java::lang::Object* value)
{
    if(value == nullptr) {
        return super::containsValue(static_cast< ::java::lang::Object* >(nullptr));
    } else {
        return super::containsValue(static_cast< ::java::lang::Object* >(new ::java::lang::ref::SoftReference(value)));
    }
}

java::lang::Object* rice::p2p::util::SoftHashMap::get(::java::lang::Object* key)
{
    auto value = java_cast< ::java::lang::ref::SoftReference* >(super::get(key));
    if(value == nullptr) {
        return nullptr;
    } else {
        auto result = java_cast< ::java::lang::Object* >(npc(value)->get());
        if(result != nullptr) {
            return result;
        } else {
            remove(key);
            return nullptr;
        }
    }
}

java::lang::Object* rice::p2p::util::SoftHashMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    auto result = get(key);
    if(value != nullptr) {
        super::put(static_cast< ::java::lang::Object* >(key), static_cast< ::java::lang::Object* >(new ::java::lang::ref::SoftReference(value)));
    } else {
        super::put(static_cast< ::java::lang::Object* >(key), static_cast< ::java::lang::Object* >(nullptr));
    }
    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::SoftHashMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.SoftHashMap", 25);
    return c;
}

java::lang::Class* rice::p2p::util::SoftHashMap::getClass0()
{
    return class_();
}

