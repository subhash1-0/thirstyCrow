// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedSet.hpp>

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
java::util::Collections_CheckedSet::Collections_CheckedSet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedSet::Collections_CheckedSet(Set* arg0, ::java::lang::Class* arg1)
    : Collections_CheckedSet(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_CheckedSet::serialVersionUID;

void ::java::util::Collections_CheckedSet::ctor(Set* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedSet::ctor(Set* arg0, ::java::lang::Class* arg1)");
}

bool java::util::Collections_CheckedSet::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_CheckedSet::equals(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Collections_CheckedSet::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_CheckedSet::hashCode()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedSet::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedSet", 32);
    return c;
}

void java::util::Collections_CheckedSet::forEach(::java::util::function::Consumer* action)
{
    Collections_CheckedCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_CheckedSet::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::parallelStream());
}

bool java::util::Collections_CheckedSet::removeIf(::java::util::function::Predicate* filter)
{
    return Collections_CheckedCollection::removeIf(filter);
}

java::util::stream::Stream* java::util::Collections_CheckedSet::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::stream());
}

bool java::util::Collections_CheckedSet::add(::java::lang::Object* e)
{
    return Collections_CheckedCollection::add(e);
}

bool java::util::Collections_CheckedSet::addAll(Collection* c)
{
    return Collections_CheckedCollection::addAll(c);
}

void java::util::Collections_CheckedSet::clear()
{
    Collections_CheckedCollection::clear();
}

bool java::util::Collections_CheckedSet::contains(::java::lang::Object* o)
{
    return Collections_CheckedCollection::contains(o);
}

bool java::util::Collections_CheckedSet::containsAll(Collection* c)
{
    return Collections_CheckedCollection::containsAll(c);
}

bool java::util::Collections_CheckedSet::isEmpty()
{
    return Collections_CheckedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_CheckedSet::iterator()
{
    return java_cast< Iterator* >(Collections_CheckedCollection::iterator());
}

bool java::util::Collections_CheckedSet::remove(::java::lang::Object* o)
{
    return Collections_CheckedCollection::remove(o);
}

bool java::util::Collections_CheckedSet::removeAll(Collection* c)
{
    return Collections_CheckedCollection::removeAll(c);
}

bool java::util::Collections_CheckedSet::retainAll(Collection* c)
{
    return Collections_CheckedCollection::retainAll(c);
}

int32_t java::util::Collections_CheckedSet::size()
{
    return Collections_CheckedCollection::size();
}

java::util::Spliterator* java::util::Collections_CheckedSet::spliterator()
{
    return java_cast< Spliterator* >(Collections_CheckedCollection::spliterator());
}

java::lang::ObjectArray* java::util::Collections_CheckedSet::toArray_()
{
    return Collections_CheckedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_CheckedSet::toArray_(::java::lang::ObjectArray* a)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_CheckedCollection::toArray_(a));
}

java::lang::Class* java::util::Collections_CheckedSet::getClass0()
{
    return class_();
}

