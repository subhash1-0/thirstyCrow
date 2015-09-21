// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_SubMapEntryIterator.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/NoSuchElementException.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::RedBlackMap_SubMapEntryIterator::RedBlackMap_SubMapEntryIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&)
    : super(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::RedBlackMap_SubMapEntryIterator::RedBlackMap_SubMapEntryIterator(RedBlackMap *RedBlackMap_this, RedBlackMap_Entry* first, RedBlackMap_Entry* firstExcluded) 
    : RedBlackMap_SubMapEntryIterator(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(first,firstExcluded);
}

void rice::p2p::util::RedBlackMap_SubMapEntryIterator::ctor(RedBlackMap_Entry* first, RedBlackMap_Entry* firstExcluded)
{
    super::ctor(first);
    firstExcludedKey = (firstExcluded == nullptr ? static_cast< ::java::lang::Object* >(firstExcluded) : npc(firstExcluded)->key);
}

bool rice::p2p::util::RedBlackMap_SubMapEntryIterator::hasNext()
{
    return next_ != nullptr && ((firstExcludedKey == nullptr) || RedBlackMap_this->compare(npc(next_)->key, firstExcludedKey) < 0);
}

java::lang::Object* rice::p2p::util::RedBlackMap_SubMapEntryIterator::next()
{
    if(next_ == nullptr || ((firstExcludedKey != nullptr) && RedBlackMap_this->compare(npc(next_)->key, firstExcludedKey) >= 0))
        throw new ::java::util::NoSuchElementException();

    return nextEntry();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_SubMapEntryIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.SubMapEntryIterator", 45);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_SubMapEntryIterator::getClass0()
{
    return class_();
}

