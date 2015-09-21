// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_values_2.hpp>

#include <java/lang/NullPointerException.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_ValueIterator.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::RedBlackMap_values_2::RedBlackMap_values_2(RedBlackMap *RedBlackMap_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
    ctor();
}

java::util::Iterator* rice::p2p::util::RedBlackMap_values_2::iterator()
{
    return new RedBlackMap_ValueIterator(RedBlackMap_this);
}

int32_t rice::p2p::util::RedBlackMap_values_2::size()
{
    return RedBlackMap_this->size();
}

bool rice::p2p::util::RedBlackMap_values_2::contains(::java::lang::Object* o)
{
    for (auto *e = RedBlackMap_this->firstEntry(); e != nullptr; e = RedBlackMap_this->successor(e)) 
                if(RedBlackMap::valEquals(npc(e)->getValue(), o))
            return true;


    return false;
}

bool rice::p2p::util::RedBlackMap_values_2::remove(::java::lang::Object* o)
{
    for (auto *e = RedBlackMap_this->firstEntry(); e != nullptr; e = RedBlackMap_this->successor(e)) {
        if(RedBlackMap::valEquals(npc(e)->getValue(), o)) {
            RedBlackMap_this->deleteEntry(e);
            return true;
        }
    }
    return false;
}

void rice::p2p::util::RedBlackMap_values_2::clear()
{
    RedBlackMap_this->clear();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_values_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_values_2::getClass0()
{
    return class_();
}

