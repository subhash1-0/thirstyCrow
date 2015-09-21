// Generated from /pastry-2.1/src/rice/p2p/util/ReverseTreeMap.java
#include <rice/p2p/util/ReverseTreeMap.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Set.hpp>
#include <java/util/SortedMap.hpp>
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

rice::p2p::util::ReverseTreeMap::ReverseTreeMap(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::ReverseTreeMap::ReverseTreeMap() 
    : ReverseTreeMap(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::util::ReverseTreeMap::ReverseTreeMap(::java::util::SortedMap* normal, ::java::util::SortedMap* reverse, ::java::util::SortedMap* nulls) 
    : ReverseTreeMap(*static_cast< ::default_init_tag* >(0))
{
    ctor(normal,reverse,nulls);
}

void rice::p2p::util::ReverseTreeMap::init()
{
    normal = new RedBlackMap();
    reverse = new RedBlackMap();
    nulls = new RedBlackMap();
}

void rice::p2p::util::ReverseTreeMap::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::ReverseTreeMap::ctor(::java::util::SortedMap* normal, ::java::util::SortedMap* reverse, ::java::util::SortedMap* nulls)
{
    super::ctor();
    init();
    this->normal = normal;
    this->reverse = reverse;
    this->nulls = nulls;
}

int32_t rice::p2p::util::ReverseTreeMap::size()
{
    return npc(normal)->size();
}

bool rice::p2p::util::ReverseTreeMap::containsKey(::java::lang::Object* key)
{
    return npc(normal)->containsKey(key);
}

java::lang::Object* rice::p2p::util::ReverseTreeMap::get(::java::lang::Object* key)
{
    return java_cast< ::java::lang::Object* >(npc(normal)->get(key));
}

java::util::Set* rice::p2p::util::ReverseTreeMap::keySet()
{
    return npc(normal)->keySet();
}

void rice::p2p::util::ReverseTreeMap::remove(::java::lang::Object* key)
{
    auto value = java_cast< ::java::lang::Object* >(npc(normal)->remove(key));
    if(value != nullptr) {
        auto o = java_cast< RedBlackMap* >(java_cast< ::java::lang::Object* >(npc(reverse)->get(value)));
        npc(o)->remove(key);
        if(npc(o)->size() == 0) {
            npc(reverse)->remove(value);
        }
    } else {
        npc(nulls)->remove(key);
    }
}

void rice::p2p::util::ReverseTreeMap::put(::java::lang::Object* key, ::java::lang::Object* value)
{
    auto old = java_cast< ::java::lang::Object* >(npc(normal)->put(key, value));
    if(old != nullptr) {
        auto o = java_cast< RedBlackMap* >(java_cast< ::java::lang::Object* >(npc(reverse)->get(old)));
        npc(o)->remove(key);
        if(npc(o)->size() == 0) {
            npc(reverse)->remove(old);
        }
    } else {
        npc(nulls)->remove(key);
    }
    if(value != nullptr) {
        auto v = java_cast< RedBlackMap* >(java_cast< ::java::lang::Object* >(npc(reverse)->get(value)));
        if(v == nullptr) {
            v = new RedBlackMap();
            npc(reverse)->put(value, v);
        }
        npc(v)->put(key, value);
    } else {
        npc(nulls)->put(key, nullptr);
    }
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::keyMap()
{
    return normal;
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::keyHeadMap(::java::lang::Object* value)
{
    return npc(normal)->headMap(value);
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::keyTailMap(::java::lang::Object* value)
{
    return npc(normal)->tailMap(value);
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::keySubMap(::java::lang::Object* start, ::java::lang::Object* end)
{
    return npc(normal)->subMap(start, end);
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::valueHeadMap(::java::lang::Object* value)
{
    return convert(npc(reverse)->headMap(value));
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::valueTailMap(::java::lang::Object* value)
{
    return convert(npc(reverse)->tailMap(value));
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::valueSubMap(::java::lang::Object* start, ::java::lang::Object* end)
{
    return convert(npc(reverse)->subMap(start, end));
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::valueNullMap()
{
    return nulls;
}

java::util::SortedMap* rice::p2p::util::ReverseTreeMap::convert(::java::util::SortedMap* map)
{
    ::java::util::SortedMap* result = new RedBlackMap();
    auto i = npc(npc(map)->keySet())->iterator();
    while (npc(i)->hasNext()) 
                npc(result)->putAll(java_cast< ::java::util::SortedMap* >(java_cast< ::java::lang::Object* >(npc(map)->get(java_cast< ::java::lang::Object* >(npc(i)->next())))));

    return result;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::ReverseTreeMap::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.ReverseTreeMap", 28);
    return c;
}

java::lang::Class* rice::p2p::util::ReverseTreeMap::getClass0()
{
    return class_();
}

