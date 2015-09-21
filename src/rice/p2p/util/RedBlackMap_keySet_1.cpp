// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_keySet_1.hpp>

#include <rice/p2p/util/RedBlackMap_KeyIterator.hpp>
#include <rice/p2p/util/RedBlackMap.hpp>

rice::p2p::util::RedBlackMap_keySet_1::RedBlackMap_keySet_1(RedBlackMap *RedBlackMap_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_this(RedBlackMap_this)
{
    clinit();
    ctor();
}

java::util::Iterator* rice::p2p::util::RedBlackMap_keySet_1::iterator()
{
    return new RedBlackMap_KeyIterator(RedBlackMap_this);
}

int32_t rice::p2p::util::RedBlackMap_keySet_1::size()
{
    return RedBlackMap_this->size();
}

bool rice::p2p::util::RedBlackMap_keySet_1::contains(::java::lang::Object* o)
{
    return RedBlackMap_this->containsKey(o);
}

bool rice::p2p::util::RedBlackMap_keySet_1::remove(::java::lang::Object* o)
{
    auto oldSize = RedBlackMap_this->size_;
    RedBlackMap_this->remove(o);
    return RedBlackMap_this->size_ != oldSize;
}

void rice::p2p::util::RedBlackMap_keySet_1::clear()
{
    RedBlackMap_this->clear();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_keySet_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_keySet_1::getClass0()
{
    return class_();
}

