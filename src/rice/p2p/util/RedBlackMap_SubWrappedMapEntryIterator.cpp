// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_SubWrappedMapEntryIterator.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <rice/p2p/util/RedBlackMap_SubMapEntryIterator.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
}

rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap *RedBlackMap_this, RedBlackMap_Entry* first, RedBlackMap_Entry* firstExcluded) 
    : RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(first,firstExcluded);
}

void rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::ctor(RedBlackMap_Entry* first, RedBlackMap_Entry* firstExcluded)
{
    super::ctor();
    iterator1 = new RedBlackMap_SubMapEntryIterator(RedBlackMap_this, RedBlackMap_this->firstEntry(), firstExcluded);
    iterator2 = new RedBlackMap_SubMapEntryIterator(RedBlackMap_this, first, nullptr);
}

bool rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::hasNext()
{
    return (npc(iterator1)->hasNext() || npc(iterator2)->hasNext());
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::next()
{
    return (npc(iterator1)->hasNext() ? npc(iterator1)->next() : npc(iterator2)->next());
}

void rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::remove()
{
    throw new ::java::lang::UnsupportedOperationException(u"remove not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.SubWrappedMapEntryIterator", 52);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator::getClass0()
{
    return class_();
}

