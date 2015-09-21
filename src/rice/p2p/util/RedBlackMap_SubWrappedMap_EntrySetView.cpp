// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java
#include <rice/p2p/util/RedBlackMap_SubWrappedMap_EntrySetView.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_Entry.hpp>
#include <rice/p2p/util/RedBlackMap_SubMapEntryIterator.hpp>
#include <rice/p2p/util/RedBlackMap_SubWrappedMap.hpp>
#include <rice/p2p/util/RedBlackMap_SubWrappedMapEntryIterator.hpp>
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

rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::RedBlackMap_SubWrappedMap_EntrySetView(RedBlackMap_SubWrappedMap *RedBlackMap_SubWrappedMap_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , RedBlackMap_SubWrappedMap_this(RedBlackMap_SubWrappedMap_this)
{
    clinit();
}

rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::RedBlackMap_SubWrappedMap_EntrySetView(RedBlackMap_SubWrappedMap *RedBlackMap_SubWrappedMap_this)
    : RedBlackMap_SubWrappedMap_EntrySetView(RedBlackMap_SubWrappedMap_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::init()
{
    size_ = -int32_t(1);
}

int32_t rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::size()
{
    if(size_ == -int32_t(1) || sizeModCount != RedBlackMap_SubWrappedMap_this->RedBlackMap_this->modCount) {
        size_ = 0;
        sizeModCount = RedBlackMap_SubWrappedMap_this->RedBlackMap_this->modCount;
        auto i = iterator();
        while (npc(i)->hasNext()) {
            size_++;
            npc(i)->next();
        }
    }
    return size_;
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::isEmpty()
{
    return !npc(iterator())->hasNext();
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::contains(::java::lang::Object* o)
{
    if(!(dynamic_cast< ::java::util::Map_Entry* >(o) != nullptr))
        return false;

    auto entry = java_cast< ::java::util::Map_Entry* >(o);
    auto key = java_cast< ::java::lang::Object* >(npc(entry)->getKey());
    if(!RedBlackMap_SubWrappedMap_this->inRange(key))
        return false;

    auto node = RedBlackMap_SubWrappedMap_this->RedBlackMap_this->getEntry(key);
    return node != nullptr && RedBlackMap::valEquals(npc(node)->getValue(), java_cast< ::java::lang::Object* >(npc(entry)->getValue()));
}

bool rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::remove(::java::lang::Object* o)
{
    if(!(dynamic_cast< ::java::util::Map_Entry* >(o) != nullptr))
        return false;

    auto entry = java_cast< ::java::util::Map_Entry* >(o);
    auto key = java_cast< ::java::lang::Object* >(npc(entry)->getKey());
    if(!RedBlackMap_SubWrappedMap_this->inRange(key))
        return false;

    auto node = RedBlackMap_SubWrappedMap_this->RedBlackMap_this->getEntry(key);
    if(node != nullptr && RedBlackMap::valEquals(npc(node)->getValue(), java_cast< ::java::lang::Object* >(npc(entry)->getValue()))) {
        RedBlackMap_SubWrappedMap_this->RedBlackMap_this->deleteEntry(node);
        return true;
    }
    return false;
}

java::util::Iterator* rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::iterator()
{
    auto from = RedBlackMap_SubWrappedMap_this->RedBlackMap_this->getCeilEntry(RedBlackMap_SubWrappedMap_this->fromKey);
    auto to = RedBlackMap_SubWrappedMap_this->RedBlackMap_this->getPrecedingEntry(RedBlackMap_SubWrappedMap_this->toKey);
    if(from == nullptr) {
        return new RedBlackMap_SubMapEntryIterator(RedBlackMap_SubWrappedMap_this->RedBlackMap_this, RedBlackMap_SubWrappedMap_this->RedBlackMap_this->firstEntry(), RedBlackMap_SubWrappedMap_this->RedBlackMap_this->getCeilEntry(RedBlackMap_SubWrappedMap_this->toKey));
    } else if(to == nullptr) {
        return new RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap_SubWrappedMap_this->RedBlackMap_this, from, RedBlackMap_SubWrappedMap_this->RedBlackMap_this->firstEntry());
    } else {
        return new RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap_SubWrappedMap_this->RedBlackMap_this, from, RedBlackMap_SubWrappedMap_this->RedBlackMap_this->getCeilEntry(RedBlackMap_SubWrappedMap_this->toKey));
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RedBlackMap.SubWrappedMap.EntrySetView", 52);
    return c;
}

java::lang::Class* rice::p2p::util::RedBlackMap_SubWrappedMap_EntrySetView::getClass0()
{
    return class_();
}

