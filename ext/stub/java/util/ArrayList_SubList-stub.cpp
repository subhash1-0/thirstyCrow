// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/ArrayList_SubList.hpp>

#include <java/util/ArrayList.hpp>
#include <java/util/ListIterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::ArrayList_SubList::ArrayList_SubList(ArrayList *ArrayList_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , ArrayList_this(ArrayList_this)
{
    clinit();
}

java::util::ArrayList_SubList::ArrayList_SubList(ArrayList *ArrayList_this, AbstractList* arg0, int32_t arg1, int32_t arg2, int32_t arg3)
    : ArrayList_SubList(ArrayList_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}


void ::java::util::ArrayList_SubList::ctor(AbstractList* arg0, int32_t arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::ArrayList_SubList::ctor(AbstractList* arg0, int32_t arg1, int32_t arg2, int32_t arg3)");
}

void java::util::ArrayList_SubList::add(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::util::ArrayList_SubList::add(int32_t arg0, ::java::lang::Object* arg1)");
}

bool java::util::ArrayList_SubList::addAll(Collection* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::ArrayList_SubList::addAll(Collection* arg0)");
    return 0;
}

bool java::util::ArrayList_SubList::addAll(int32_t arg0, Collection* arg1)
{ /* stub */
    unimplemented_(u"bool java::util::ArrayList_SubList::addAll(int32_t arg0, Collection* arg1)");
    return 0;
}

/* private: void java::util::ArrayList_SubList::checkForComodification() */
java::lang::Object* java::util::ArrayList_SubList::get(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::ArrayList_SubList::get(int32_t arg0)");
    return 0;
}

java::util::Iterator* java::util::ArrayList_SubList::iterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::ArrayList_SubList::iterator()");
    return 0;
}

java::util::ListIterator* java::util::ArrayList_SubList::listIterator(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::ArrayList_SubList::listIterator(int32_t arg0)");
    return 0;
}

/* private: java::lang::String* java::util::ArrayList_SubList::outOfBoundsMsg(int32_t arg0) */
/* private: void java::util::ArrayList_SubList::rangeCheck(int32_t arg0) */
/* private: void java::util::ArrayList_SubList::rangeCheckForAdd(int32_t arg0) */
java::lang::Object* java::util::ArrayList_SubList::remove(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::ArrayList_SubList::remove(int32_t arg0)");
    return 0;
}

void java::util::ArrayList_SubList::removeRange(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"void java::util::ArrayList_SubList::removeRange(int32_t arg0, int32_t arg1)");
}

java::lang::Object* java::util::ArrayList_SubList::set(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::ArrayList_SubList::set(int32_t arg0, ::java::lang::Object* arg1)");
    return 0;
}

int32_t java::util::ArrayList_SubList::size()
{ /* stub */
    unimplemented_(u"int32_t java::util::ArrayList_SubList::size()");
    return 0;
}

java::util::Spliterator* java::util::ArrayList_SubList::spliterator()
{ /* stub */
    unimplemented_(u"java::util::Spliterator* java::util::ArrayList_SubList::spliterator()");
    return 0;
}

java::util::List* java::util::ArrayList_SubList::subList(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::util::List* java::util::ArrayList_SubList::subList(int32_t arg0, int32_t arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::ArrayList_SubList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.ArrayList.SubList", 27);
    return c;
}

bool java::util::ArrayList_SubList::add(::java::lang::Object* arg0)
{
    return super::add(arg0);
}

java::util::ListIterator* java::util::ArrayList_SubList::listIterator()
{
    return super::listIterator();
}

bool java::util::ArrayList_SubList::remove(::java::lang::Object* arg0)
{
    return super::remove(arg0);
}

java::lang::Class* java::util::ArrayList_SubList::getClass0()
{
    return class_();
}

