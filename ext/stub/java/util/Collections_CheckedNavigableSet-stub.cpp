// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedNavigableSet.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Spliterator.hpp>
#include <java/util/stream/Stream.hpp>
#include <ObjectArray.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::Collections_CheckedNavigableSet::Collections_CheckedNavigableSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedNavigableSet::Collections_CheckedNavigableSet(NavigableSet* arg0, ::java::lang::Class* arg1)
    : Collections_CheckedNavigableSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_CheckedNavigableSet::serialVersionUID;

void ::java::util::Collections_CheckedNavigableSet::ctor(NavigableSet* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedNavigableSet::ctor(NavigableSet* arg0, ::java::lang::Class* arg1)");
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::ceiling(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedNavigableSet::ceiling(::java::lang::Object* arg0)");
    return 0;
}

java::util::Iterator* java::util::Collections_CheckedNavigableSet::descendingIterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::Collections_CheckedNavigableSet::descendingIterator()");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::descendingSet()
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::descendingSet()");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::floor(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedNavigableSet::floor(::java::lang::Object* arg0)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::headSet(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::headSet(::java::lang::Object* arg0)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::headSet(::java::lang::Object* arg0, bool arg1)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::headSet(::java::lang::Object* arg0, bool arg1)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::higher(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedNavigableSet::higher(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::lower(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedNavigableSet::lower(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::pollFirst()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedNavigableSet::pollFirst()");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::pollLast()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedNavigableSet::pollLast()");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::tailSet(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::tailSet(::java::lang::Object* arg0)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::tailSet(::java::lang::Object* arg0, bool arg1)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_CheckedNavigableSet::tailSet(::java::lang::Object* arg0, bool arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedNavigableSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedNavigableSet", 41);
    return c;
}

void java::util::Collections_CheckedNavigableSet::forEach(::java::util::function::Consumer* arg0)
{
    Collections_CheckedCollection::forEach(arg0);
}

java::util::stream::Stream* java::util::Collections_CheckedNavigableSet::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::parallelStream());
}

bool java::util::Collections_CheckedNavigableSet::removeIf(::java::util::function::Predicate* arg0)
{
    return Collections_CheckedCollection::removeIf(arg0);
}

java::util::stream::Stream* java::util::Collections_CheckedNavigableSet::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::stream());
}

bool java::util::Collections_CheckedNavigableSet::add(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::add(arg0);
}

bool java::util::Collections_CheckedNavigableSet::addAll(Collection* arg0)
{
    return Collections_CheckedCollection::addAll(arg0);
}

void java::util::Collections_CheckedNavigableSet::clear()
{
    Collections_CheckedCollection::clear();
}

bool java::util::Collections_CheckedNavigableSet::contains(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::contains(arg0);
}

bool java::util::Collections_CheckedNavigableSet::containsAll(Collection* arg0)
{
    return Collections_CheckedCollection::containsAll(arg0);
}

bool java::util::Collections_CheckedNavigableSet::equals(::java::lang::Object* arg0)
{
    return Collections_CheckedSet::equals(arg0);
}

int32_t java::util::Collections_CheckedNavigableSet::hashCode()
{
    return Collections_CheckedSet::hashCode();
}

bool java::util::Collections_CheckedNavigableSet::isEmpty()
{
    return Collections_CheckedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_CheckedNavigableSet::iterator()
{
    return java_cast< Iterator* >(Collections_CheckedCollection::iterator());
}

bool java::util::Collections_CheckedNavigableSet::remove(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::remove(arg0);
}

bool java::util::Collections_CheckedNavigableSet::removeAll(Collection* arg0)
{
    return Collections_CheckedCollection::removeAll(arg0);
}

bool java::util::Collections_CheckedNavigableSet::retainAll(Collection* arg0)
{
    return Collections_CheckedCollection::retainAll(arg0);
}

int32_t java::util::Collections_CheckedNavigableSet::size()
{
    return Collections_CheckedCollection::size();
}

java::lang::ObjectArray* java::util::Collections_CheckedNavigableSet::toArray_()
{
    return Collections_CheckedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_CheckedNavigableSet::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_CheckedCollection::toArray_(arg0));
}

java::util::Comparator* java::util::Collections_CheckedNavigableSet::comparator()
{
    return java_cast< Comparator* >(Collections_CheckedSortedSet::comparator());
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::first()
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedSortedSet::first());
}

java::lang::Object* java::util::Collections_CheckedNavigableSet::last()
{
    return java_cast< ::java::lang::Object* >(Collections_CheckedSortedSet::last());
}

java::util::Spliterator* java::util::Collections_CheckedNavigableSet::spliterator()
{
    return java_cast< Spliterator* >(Collections_CheckedCollection::spliterator());
}

java::lang::Class* java::util::Collections_CheckedNavigableSet::getClass0()
{
    return class_();
}

