// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_KeyIterator.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::RedBlackMap_KeyIterator::RedBlackMap_KeyIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&)
    : super(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::RedBlackMap_KeyIterator::RedBlackMap_KeyIterator(RedBlackMap *RedBlackMap_this)
    : RedBlackMap_KeyIterator(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Object* rice::p2p::util::RedBlackMap_KeyIterator::next()
{
    return npc(nextEntry())->key;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_KeyIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.KeyIterator", 37);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_KeyIterator::getClass0()
{
    return class_();
}

