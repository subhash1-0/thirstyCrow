// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedSortedSet.hpp>

#include <java/lang/ClassCastException.hpp>
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
java::util::Collections_CheckedSortedSet::Collections_CheckedSortedSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedSortedSet::Collections_CheckedSortedSet(SortedSet* arg0, ::java::lang::Class* arg1)
    : Collections_CheckedSortedSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_CheckedSortedSet::serialVersionUID;

void ::java::util::Collections_CheckedSortedSet::ctor(SortedSet* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedSortedSet::ctor(SortedSet* arg0, ::java::lang::Class* arg1)");
}

java::util::Comparator* java::util::Collections_CheckedSortedSet::comparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::Collections_CheckedSortedSet::comparator()");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedSortedSet::first()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedSortedSet::first()");
    return 0;
}

java::util::SortedSet* java::util::Collections_CheckedSortedSet::headSet(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedSet* java::util::Collections_CheckedSortedSet::headSet(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedSortedSet::last()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedSortedSet::last()");
    return 0;
}

java::util::SortedSet* java::util::Collections_CheckedSortedSet::subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::util::SortedSet* java::util::Collections_CheckedSortedSet::subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1)");
    return 0;
}

java::util::SortedSet* java::util::Collections_CheckedSortedSet::tailSet(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::util::SortedSet* java::util::Collections_CheckedSortedSet::tailSet(::java::lang::Object* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedSortedSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedSortedSet", 38);
    return c;
}

void java::util::Collections_CheckedSortedSet::forEach(::java::util::function::Consumer* action)
{
    Collections_CheckedCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_CheckedSortedSet::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::parallelStream());
}

bool java::util::Collections_CheckedSortedSet::removeIf(::java::util::function::Predicate* filter)
{
    return Collections_CheckedCollection::removeIf(filter);
}

java::util::stream::Stream* java::util::Collections_CheckedSortedSet::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::stream());
}

bool java::util::Collections_CheckedSortedSet::add(::java::lang::Object* e)
{
    return Collections_CheckedCollection::add(e);
}

bool java::util::Collections_CheckedSortedSet::addAll(Collection* c)
{
    return Collections_CheckedCollection::addAll(c);
}

void java::util::Collections_CheckedSortedSet::clear()
{
    Collections_CheckedCollection::clear();
}

bool java::util::Collections_CheckedSortedSet::contains(::java::lang::Object* o)
{
    return Collections_CheckedCollection::contains(o);
}

bool java::util::Collections_CheckedSortedSet::containsAll(Collection* c)
{
    return Collections_CheckedCollection::containsAll(c);
}

bool java::util::Collections_CheckedSortedSet::equals(::java::lang::Object* o)
{
    return Collections_CheckedSet::equals(o);
}

int32_t java::util::Collections_CheckedSortedSet::hashCode()
{
    return Collections_CheckedSet::hashCode();
}

bool java::util::Collections_CheckedSortedSet::isEmpty()
{
    return Collections_CheckedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_CheckedSortedSet::iterator()
{
    return java_cast< Iterator* >(Collections_CheckedCollection::iterator());
}

bool java::util::Collections_CheckedSortedSet::remove(::java::lang::Object* o)
{
    return Collections_CheckedCollection::remove(o);
}

bool java::util::Collections_CheckedSortedSet::removeAll(Collection* c)
{
    return Collections_CheckedCollection::removeAll(c);
}

bool java::util::Collections_CheckedSortedSet::retainAll(Collection* c)
{
    return Collections_CheckedCollection::retainAll(c);
}

int32_t java::util::Collections_CheckedSortedSet::size()
{
    return Collections_CheckedCollection::size();
}

java::lang::ObjectArray* java::util::Collections_CheckedSortedSet::toArray_()
{
    return Collections_CheckedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_CheckedSortedSet::toArray_(::java::lang::ObjectArray* a)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_CheckedCollection::toArray_(a));
}

java::util::Spliterator* java::util::Collections_CheckedSortedSet::spliterator()
{
    return java_cast< Spliterator* >(Collections_CheckedCollection::spliterator());
}

java::lang::Class* java::util::Collections_CheckedSortedSet::getClass0()
{
    return class_();
}

