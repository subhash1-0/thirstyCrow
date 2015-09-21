// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_SynchronizedSet.hpp>

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
java::util::Collections_SynchronizedSet::Collections_SynchronizedSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_SynchronizedSet::Collections_SynchronizedSet(Set* arg0)
    : Collections_SynchronizedSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::Collections_SynchronizedSet::Collections_SynchronizedSet(Set* arg0, ::java::lang::Object* arg1)
    : Collections_SynchronizedSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_SynchronizedSet::serialVersionUID;

void ::java::util::Collections_SynchronizedSet::ctor(Set* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedSet::ctor(Set* arg0)");
}

void ::java::util::Collections_SynchronizedSet::ctor(Set* arg0, ::java::lang::Object* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedSet::ctor(Set* arg0, ::java::lang::Object* arg1)");
}

bool java::util::Collections_SynchronizedSet::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_SynchronizedSet::equals(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Collections_SynchronizedSet::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_SynchronizedSet::hashCode()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_SynchronizedSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.SynchronizedSet", 37);
    return c;
}

void java::util::Collections_SynchronizedSet::forEach(::java::util::function::Consumer* action)
{
    Collections_SynchronizedCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_SynchronizedSet::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_SynchronizedCollection::parallelStream());
}

bool java::util::Collections_SynchronizedSet::removeIf(::java::util::function::Predicate* filter)
{
    return Collections_SynchronizedCollection::removeIf(filter);
}

java::util::stream::Stream* java::util::Collections_SynchronizedSet::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_SynchronizedCollection::stream());
}

bool java::util::Collections_SynchronizedSet::add(::java::lang::Object* arg0)
{
    return Collections_SynchronizedCollection::add(arg0);
}

bool java::util::Collections_SynchronizedSet::addAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::addAll(arg0);
}

void java::util::Collections_SynchronizedSet::clear()
{
    Collections_SynchronizedCollection::clear();
}

bool java::util::Collections_SynchronizedSet::contains(::java::lang::Object* arg0)
{
    return Collections_SynchronizedCollection::contains(arg0);
}

bool java::util::Collections_SynchronizedSet::containsAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::containsAll(arg0);
}

bool java::util::Collections_SynchronizedSet::isEmpty()
{
    return Collections_SynchronizedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_SynchronizedSet::iterator()
{
    return java_cast< Iterator* >(Collections_SynchronizedCollection::iterator());
}

bool java::util::Collections_SynchronizedSet::remove(::java::lang::Object* arg0)
{
    return Collections_SynchronizedCollection::remove(arg0);
}

bool java::util::Collections_SynchronizedSet::removeAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::removeAll(arg0);
}

bool java::util::Collections_SynchronizedSet::retainAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::retainAll(arg0);
}

int32_t java::util::Collections_SynchronizedSet::size()
{
    return Collections_SynchronizedCollection::size();
}

java::util::Spliterator* java::util::Collections_SynchronizedSet::spliterator()
{
    return java_cast< Spliterator* >(Collections_SynchronizedCollection::spliterator());
}

java::lang::ObjectArray* java::util::Collections_SynchronizedSet::toArray_()
{
    return Collections_SynchronizedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_SynchronizedSet::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_SynchronizedCollection::toArray_(arg0));
}

java::lang::Class* java::util::Collections_SynchronizedSet::getClass0()
{
    return class_();
}

