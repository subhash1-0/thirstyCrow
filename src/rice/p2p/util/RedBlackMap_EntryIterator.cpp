// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_EntryIterator.hpp>

#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

rice::p2p::util::RedBlackMap_EntryIterator::RedBlackMap_EntryIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
}

rice::p2p::util::RedBlackMap_EntryIterator::RedBlackMap_EntryIterator(RedBlackMap *RedBlackMap_this) 
    : RedBlackMap_EntryIterator(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::p2p::util::RedBlackMap_EntryIterator::RedBlackMap_EntryIterator(RedBlackMap *RedBlackMap_this, RedBlackMap_Entry* first) 
    : RedBlackMap_EntryIterator(RedBlackMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(first);
}

void rice::p2p::util::RedBlackMap_EntryIterator::init()
{
    lastReturned = nullptr;
    next_ = nullptr;
}

void rice::p2p::util::RedBlackMap_EntryIterator::ctor()
{
    super::ctor();
    init();
    next_ = RedBlackMap_this->firstEntry();
}

void rice::p2p::util::RedBlackMap_EntryIterator::ctor(RedBlackMap_Entry* first)
{
    super::ctor();
    init();
    next_ = first;
}

bool rice::p2p::util::RedBlackMap_EntryIterator::hasNext()
{
    return next_ != nullptr;
}

rice::p2p::util::RedBlackMap_Entry* rice::p2p::util::RedBlackMap_EntryIterator::nextEntry()
{
    lastReturned = next_;
    next_ = RedBlackMap_this->successor(next_);
    return lastReturned;
}

java::lang::Object* rice::p2p::util::RedBlackMap_EntryIterator::next()
{
    return nextEntry();
}

void rice::p2p::util::RedBlackMap_EntryIterator::remove()
{
    throw new ::java::lang::UnsupportedOperationException(u"Remove not supported!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_EntryIterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.EntryIterator", 39);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_EntryIterator::getClass0()
{
    return class_();
}

