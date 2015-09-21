// Generated from /pastry-2.1/src/rice/p2p/util/StringCache.java
#include <rice/p2p/util/StringCache_Entry.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>

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

rice::p2p::util::StringCache_Entry::StringCache_Entry(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::StringCache_Entry::StringCache_Entry(int32_t h, ::java::lang::String* v, StringCache_Entry* n) 
    : StringCache_Entry(*static_cast< ::default_init_tag* >(0))
{
    ctor(h,v,n);
}

void rice::p2p::util::StringCache_Entry::ctor(int32_t h, ::java::lang::String* v, StringCache_Entry* n)
{
    super::ctor();
    value = v;
    next = n;
    hash = h;
}

java::lang::String* rice::p2p::util::StringCache_Entry::getValue()
{
    return value;
}

bool rice::p2p::util::StringCache_Entry::equals(::java::lang::Object* o)
{
    if(!(dynamic_cast< StringCache_Entry* >(o) != nullptr))
        return false;

    auto e = java_cast< StringCache_Entry* >(o);
    auto v1 = getValue();
    auto v2 = npc(e)->getValue();
    return (v1 == v2 || (v1 != nullptr && npc(v1)->equals(static_cast< ::java::lang::Object* >(v2))));
}

int32_t rice::p2p::util::StringCache_Entry::hashCode()
{
    return int32_t(27) ^ npc(value)->hashCode();
}

java::lang::String* rice::p2p::util::StringCache_Entry::toString()
{
    return getValue();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::StringCache_Entry::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.StringCache.Entry", 31);
    return c;
}

java::lang::Class* rice::p2p::util::StringCache_Entry::getClass0()
{
    return class_();
}

