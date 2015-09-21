// Generated from /pastry-2.1/src/rice/pastry/pns/PNSApplication.java
#include <rice/pastry/pns/PNSApplication_sortedProximityCache_10.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/pns/PNSApplication.hpp>

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

rice::pastry::pns::PNSApplication_sortedProximityCache_10::PNSApplication_sortedProximityCache_10(PNSApplication *PNSApplication_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , PNSApplication_this(PNSApplication_this)
{
    clinit();
    ctor();
}

int32_t rice::pastry::pns::PNSApplication_sortedProximityCache_10::compare(::rice::pastry::NodeHandle* a, ::rice::pastry::NodeHandle* b)
{
    return npc(java_cast< ::java::lang::Integer* >(npc(PNSApplication_this->pingCache)->get(a)))->intValue() - npc(java_cast< ::java::lang::Integer* >(npc(PNSApplication_this->pingCache)->get(b)))->intValue();
}

int32_t rice::pastry::pns::PNSApplication_sortedProximityCache_10::compare(::java::lang::Object* o1, ::java::lang::Object* o2)
{ 
    return compare(dynamic_cast< ::rice::pastry::NodeHandle* >(o1), dynamic_cast< ::rice::pastry::NodeHandle* >(o2));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::pns::PNSApplication_sortedProximityCache_10::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

bool rice::pastry::pns::PNSApplication_sortedProximityCache_10::equals(::java::lang::Object* obj)
{
    return Object::equals(obj);
}

java::lang::Class* rice::pastry::pns::PNSApplication_sortedProximityCache_10::getClass0()
{
    return class_();
}

