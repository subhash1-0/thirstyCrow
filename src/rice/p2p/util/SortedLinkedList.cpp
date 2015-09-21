// Generated from /pastry-2.1/src/rice/p2p/util/SortedLinkedList.java
#include <rice/p2p/util/SortedLinkedList.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/UnsupportedOperationException.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/ListIterator.hpp>
#include <rice/p2p/util/SortedLinkedList_listIterator_1.hpp>

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

rice::p2p::util::SortedLinkedList::SortedLinkedList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::SortedLinkedList::SortedLinkedList()
    : SortedLinkedList(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool rice::p2p::util::SortedLinkedList::addAll(::java::util::Collection* c)
{
    for (auto _i = npc(c)->iterator(); _i->hasNext(); ) {
        ::java::lang::Comparable* elt = java_cast< ::java::lang::Comparable* >(_i->next());
        {
            add(elt);
        }
    }
    return true;
}

bool rice::p2p::util::SortedLinkedList::addAll(int32_t index, ::java::util::Collection* c)
{
    throw new ::java::lang::UnsupportedOperationException(u"Does not guarantee sortedness."_j);
}

void rice::p2p::util::SortedLinkedList::addFirst(::java::lang::Comparable* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"Does not guarantee sortedness."_j);
}

void rice::p2p::util::SortedLinkedList::addFirst(::java::lang::Object* arg0)
{ 
    addFirst(dynamic_cast< ::java::lang::Comparable* >(arg0));
}

void rice::p2p::util::SortedLinkedList::addLast(::java::lang::Comparable* o)
{
    throw new ::java::lang::UnsupportedOperationException(u"Does not guarantee sortedness."_j);
}

void rice::p2p::util::SortedLinkedList::addLast(::java::lang::Object* arg0)
{ 
    addLast(dynamic_cast< ::java::lang::Comparable* >(arg0));
}

java::util::ListIterator* rice::p2p::util::SortedLinkedList::listIterator(int32_t index)
{
    auto const it = java_cast< ::java::util::ListIterator* >(super::listIterator(index));
    return new SortedLinkedList_listIterator_1(this, it);
}

java::lang::Comparable* rice::p2p::util::SortedLinkedList::set(int32_t index, ::java::lang::Comparable* element)
{
    throw new ::java::lang::UnsupportedOperationException(u"Does not guarantee sortedness."_j);
}

java::lang::Object* rice::p2p::util::SortedLinkedList::set(int32_t arg0, ::java::lang::Object* arg1)
{ 
    return set(arg0, dynamic_cast< ::java::lang::Comparable* >(arg1));
}

bool rice::p2p::util::SortedLinkedList::add(::java::lang::Comparable* o)
{
    if(isEmpty()) {
        super::add(static_cast< ::java::lang::Object* >(o));
        return true;
    }
    if(npc(java_cast< ::java::lang::Comparable* >(getFirst()))->compareTo(o) >= 0) {
        super::addFirst(static_cast< ::java::lang::Object* >(o));
        return true;
    }
    if(npc(java_cast< ::java::lang::Comparable* >(getLast()))->compareTo(o) <= 0) {
        super::addLast(static_cast< ::java::lang::Object* >(o));
        return true;
    }
    auto i = java_cast< ::java::util::ListIterator* >(super::listIterator(int32_t(0)));
    ::java::lang::Comparable* elt;
    while (npc(i)->hasNext()) {
        elt = java_cast< ::java::lang::Comparable* >(npc(i)->next());
        auto diff = npc(elt)->compareTo(o);
        if(diff >= 0)
            break;

    }
    npc(i)->previous();
    npc(i)->add(o);
    return true;
}

bool rice::p2p::util::SortedLinkedList::add(::java::lang::Object* arg0)
{ 
    return add(dynamic_cast< ::java::lang::Comparable* >(arg0));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::SortedLinkedList::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.SortedLinkedList", 30);
    return c;
}

void rice::p2p::util::SortedLinkedList::add(int32_t arg0, ::java::lang::Object* arg1)
{
    super::add(arg0, arg1);
}

java::util::ListIterator* rice::p2p::util::SortedLinkedList::listIterator()
{
    return super::listIterator();
}

java::lang::Class* rice::p2p::util::SortedLinkedList::getClass0()
{
    return class_();
}

