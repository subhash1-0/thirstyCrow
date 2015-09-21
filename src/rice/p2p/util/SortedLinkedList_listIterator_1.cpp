// Generated from /pastry-2.1/src/rice/p2p/util/SortedLinkedList.java
#include <rice/p2p/util/SortedLinkedList_listIterator_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/ListIterator.hpp>
#include <rice/p2p/util/SortedLinkedList.hpp>

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

rice::p2p::util::SortedLinkedList_listIterator_1::SortedLinkedList_listIterator_1(SortedLinkedList *SortedLinkedList_this, ::java::util::ListIterator* it)
    : super(*static_cast< ::default_init_tag* >(0))
    , SortedLinkedList_this(SortedLinkedList_this)
    , it(it)
{
    clinit();
    ctor();
}

void rice::p2p::util::SortedLinkedList_listIterator_1::add(::java::lang::Comparable* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"Does not guarantee sortedness."_j);
}

void rice::p2p::util::SortedLinkedList_listIterator_1::add(::java::lang::Object* arg0)
{ 
    add(dynamic_cast< ::java::lang::Comparable* >(arg0));
}

bool rice::p2p::util::SortedLinkedList_listIterator_1::hasNext()
{
    return npc(it)->hasNext();
}

bool rice::p2p::util::SortedLinkedList_listIterator_1::hasPrevious()
{
    return npc(it)->hasPrevious();
}

java::lang::Comparable* rice::p2p::util::SortedLinkedList_listIterator_1::next()
{
    return java_cast< ::java::lang::Comparable* >(npc(it)->next());
}

int32_t rice::p2p::util::SortedLinkedList_listIterator_1::nextIndex()
{
    return npc(it)->nextIndex();
}

java::lang::Comparable* rice::p2p::util::SortedLinkedList_listIterator_1::previous()
{
    return java_cast< ::java::lang::Comparable* >(npc(it)->previous());
}

int32_t rice::p2p::util::SortedLinkedList_listIterator_1::previousIndex()
{
    return npc(it)->previousIndex();
}

void rice::p2p::util::SortedLinkedList_listIterator_1::remove()
{
    npc(it)->remove();
}

void rice::p2p::util::SortedLinkedList_listIterator_1::set(::java::lang::Comparable* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"Does not guarantee sortedness."_j);
}

void rice::p2p::util::SortedLinkedList_listIterator_1::set(::java::lang::Object* arg0)
{ 
    set(dynamic_cast< ::java::lang::Comparable* >(arg0));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::SortedLinkedList_listIterator_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::SortedLinkedList_listIterator_1::getClass0()
{
    return class_();
}

