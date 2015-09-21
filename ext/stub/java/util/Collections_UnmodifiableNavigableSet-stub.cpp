// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_UnmodifiableNavigableSet.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Comparator.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/SortedSet.hpp>
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
java::util::Collections_UnmodifiableNavigableSet::Collections_UnmodifiableNavigableSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_UnmodifiableNavigableSet::Collections_UnmodifiableNavigableSet(NavigableSet* arg0)
    : Collections_UnmodifiableNavigableSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::NavigableSet*& java::util::Collections_UnmodifiableNavigableSet::EMPTY_NAVIGABLE_SET()
{
    clinit();
    return EMPTY_NAVIGABLE_SET_;
}
java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::EMPTY_NAVIGABLE_SET_;
constexpr int64_t java::util::Collections_UnmodifiableNavigableSet::serialVersionUID;

void ::java::util::Collections_UnmodifiableNavigableSet::ctor(NavigableSet* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_UnmodifiableNavigableSet::ctor(NavigableSet* arg0)");
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::ceiling(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::ceiling(::java::lang::Object* arg0)");
    return 0;
}

java::util::Iterator* java::util::Collections_UnmodifiableNavigableSet::descendingIterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::Collections_UnmodifiableNavigableSet::descendingIterator()");
    return 0;
}

java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::descendingSet()
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::descendingSet()");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::floor(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::floor(::java::lang::Object* arg0)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::headSet(::java::lang::Object* arg0, bool arg1)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::headSet(::java::lang::Object* arg0, bool arg1)");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::higher(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::higher(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::lower(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::lower(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::pollFirst()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::pollFirst()");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::pollLast()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::pollLast()");
    return 0;
}

java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::subSet(::java::lang::Object* arg0, bool arg1, ::java::lang::Object* arg2, bool arg3)");
    return 0;
}

java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::tailSet(::java::lang::Object* arg0, bool arg1)
{ /* stub */
    unimplemented_(u"java::util::NavigableSet* java::util::Collections_UnmodifiableNavigableSet::tailSet(::java::lang::Object* arg0, bool arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_UnmodifiableNavigableSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.UnmodifiableNavigableSet", 46);
    return c;
}

void java::util::Collections_UnmodifiableNavigableSet::forEach(::java::util::function::Consumer* action)
{
    Collections_UnmodifiableCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_UnmodifiableNavigableSet::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_UnmodifiableCollection::parallelStream());
}

bool java::util::Collections_UnmodifiableNavigableSet::removeIf(::java::util::function::Predicate* arg0)
{
    return Collections_UnmodifiableCollection::removeIf(arg0);
}

java::util::stream::Stream* java::util::Collections_UnmodifiableNavigableSet::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_UnmodifiableCollection::stream());
}

bool java::util::Collections_UnmodifiableNavigableSet::add(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableCollection::add(arg0);
}

bool java::util::Collections_UnmodifiableNavigableSet::addAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::addAll(arg0);
}

void java::util::Collections_UnmodifiableNavigableSet::clear()
{
    Collections_UnmodifiableCollection::clear();
}

bool java::util::Collections_UnmodifiableNavigableSet::contains(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableCollection::contains(arg0);
}

bool java::util::Collections_UnmodifiableNavigableSet::containsAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::containsAll(arg0);
}

bool java::util::Collections_UnmodifiableNavigableSet::equals(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableSet::equals(arg0);
}

int32_t java::util::Collections_UnmodifiableNavigableSet::hashCode()
{
    return Collections_UnmodifiableSet::hashCode();
}

bool java::util::Collections_UnmodifiableNavigableSet::isEmpty()
{
    return Collections_UnmodifiableCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_UnmodifiableNavigableSet::iterator()
{
    return java_cast< Iterator* >(Collections_UnmodifiableCollection::iterator());
}

bool java::util::Collections_UnmodifiableNavigableSet::remove(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableCollection::remove(arg0);
}

bool java::util::Collections_UnmodifiableNavigableSet::removeAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::removeAll(arg0);
}

bool java::util::Collections_UnmodifiableNavigableSet::retainAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::retainAll(arg0);
}

int32_t java::util::Collections_UnmodifiableNavigableSet::size()
{
    return Collections_UnmodifiableCollection::size();
}

java::lang::ObjectArray* java::util::Collections_UnmodifiableNavigableSet::toArray_()
{
    return Collections_UnmodifiableCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_UnmodifiableNavigableSet::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_UnmodifiableCollection::toArray_(arg0));
}

java::util::Comparator* java::util::Collections_UnmodifiableNavigableSet::comparator()
{
    return java_cast< Comparator* >(Collections_UnmodifiableSortedSet::comparator());
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::first()
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableSortedSet::first());
}

java::util::SortedSet* java::util::Collections_UnmodifiableNavigableSet::headSet(::java::lang::Object* arg0)
{
    return java_cast< SortedSet* >(Collections_UnmodifiableSortedSet::headSet(arg0));
}

java::lang::Object* java::util::Collections_UnmodifiableNavigableSet::last()
{
    return java_cast< ::java::lang::Object* >(Collections_UnmodifiableSortedSet::last());
}

java::util::Spliterator* java::util::Collections_UnmodifiableNavigableSet::spliterator()
{
    return java_cast< Spliterator* >(Collections_UnmodifiableCollection::spliterator());
}

java::util::SortedSet* java::util::Collections_UnmodifiableNavigableSet::subSet(::java::lang::Object* arg0, ::java::lang::Object* arg1)
{
    return java_cast< SortedSet* >(Collections_UnmodifiableSortedSet::subSet(arg0, arg1));
}

java::util::SortedSet* java::util::Collections_UnmodifiableNavigableSet::tailSet(::java::lang::Object* arg0)
{
    return java_cast< SortedSet* >(Collections_UnmodifiableSortedSet::tailSet(arg0));
}

java::lang::Class* java::util::Collections_UnmodifiableNavigableSet::getClass0()
{
    return class_();
}

