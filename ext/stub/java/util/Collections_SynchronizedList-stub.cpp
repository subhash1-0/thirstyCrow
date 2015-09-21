// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_SynchronizedList.hpp>

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
java::util::Collections_SynchronizedList::Collections_SynchronizedList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_SynchronizedList::Collections_SynchronizedList(List* arg0)
    : Collections_SynchronizedList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::Collections_SynchronizedList::Collections_SynchronizedList(List* arg0, ::java::lang::Object* arg1)
    : Collections_SynchronizedList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_SynchronizedList::serialVersionUID;

void ::java::util::Collections_SynchronizedList::ctor(List* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedList::ctor(List* arg0)");
}

void ::java::util::Collections_SynchronizedList::ctor(List* arg0, ::java::lang::Object* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_SynchronizedList::ctor(List* arg0, ::java::lang::Object* arg1)");
}

void java::util::Collections_SynchronizedList::add(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Collections_SynchronizedList::add(int32_t arg0, ::java::lang::Object* arg1)");
}

bool java::util::Collections_SynchronizedList::addAll(int32_t arg0, Collection* arg1)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_SynchronizedList::addAll(int32_t arg0, Collection* arg1)");
    return 0;
}

bool java::util::Collections_SynchronizedList::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_SynchronizedList::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_SynchronizedList::get(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_SynchronizedList::get(int32_t arg0)");
    return 0;
}

int32_t java::util::Collections_SynchronizedList::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_SynchronizedList::hashCode()");
    return 0;
}

int32_t java::util::Collections_SynchronizedList::indexOf(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_SynchronizedList::indexOf(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Collections_SynchronizedList::lastIndexOf(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_SynchronizedList::lastIndexOf(::java::lang::Object* arg0)");
    return 0;
}

java::util::ListIterator* java::util::Collections_SynchronizedList::listIterator()
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::Collections_SynchronizedList::listIterator()");
    return 0;
}

java::util::ListIterator* java::util::Collections_SynchronizedList::listIterator(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::Collections_SynchronizedList::listIterator(int32_t arg0)");
    return 0;
}

/* private: java::lang::Object* java::util::Collections_SynchronizedList::readResolve() */
java::lang::Object* java::util::Collections_SynchronizedList::remove(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_SynchronizedList::remove(int32_t arg0)");
    return 0;
}

void java::util::Collections_SynchronizedList::replaceAll(::java::util::function::UnaryOperator* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_SynchronizedList::replaceAll(::java::util::function::UnaryOperator* arg0)");
}

java::lang::Object* java::util::Collections_SynchronizedList::set(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_SynchronizedList::set(int32_t arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::Collections_SynchronizedList::sort(Comparator* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_SynchronizedList::sort(Comparator* arg0)");
}

java::util::List* java::util::Collections_SynchronizedList::subList(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::util::List* java::util::Collections_SynchronizedList::subList(int32_t arg0, int32_t arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_SynchronizedList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.SynchronizedList", 38);
    return c;
}

void java::util::Collections_SynchronizedList::forEach(::java::util::function::Consumer* action)
{
    Collections_SynchronizedCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_SynchronizedList::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_SynchronizedCollection::parallelStream());
}

bool java::util::Collections_SynchronizedList::removeIf(::java::util::function::Predicate* filter)
{
    return Collections_SynchronizedCollection::removeIf(filter);
}

java::util::stream::Stream* java::util::Collections_SynchronizedList::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_SynchronizedCollection::stream());
}

bool java::util::Collections_SynchronizedList::add(::java::lang::Object* arg0)
{
    return Collections_SynchronizedCollection::add(arg0);
}

bool java::util::Collections_SynchronizedList::addAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::addAll(arg0);
}

void java::util::Collections_SynchronizedList::clear()
{
    Collections_SynchronizedCollection::clear();
}

bool java::util::Collections_SynchronizedList::contains(::java::lang::Object* arg0)
{
    return Collections_SynchronizedCollection::contains(arg0);
}

bool java::util::Collections_SynchronizedList::containsAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::containsAll(arg0);
}

bool java::util::Collections_SynchronizedList::isEmpty()
{
    return Collections_SynchronizedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_SynchronizedList::iterator()
{
    return java_cast< Iterator* >(Collections_SynchronizedCollection::iterator());
}

bool java::util::Collections_SynchronizedList::remove(::java::lang::Object* arg0)
{
    return Collections_SynchronizedCollection::remove(arg0);
}

bool java::util::Collections_SynchronizedList::removeAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::removeAll(arg0);
}

bool java::util::Collections_SynchronizedList::retainAll(Collection* arg0)
{
    return Collections_SynchronizedCollection::retainAll(arg0);
}

int32_t java::util::Collections_SynchronizedList::size()
{
    return Collections_SynchronizedCollection::size();
}

java::util::Spliterator* java::util::Collections_SynchronizedList::spliterator()
{
    return java_cast< Spliterator* >(Collections_SynchronizedCollection::spliterator());
}

java::lang::ObjectArray* java::util::Collections_SynchronizedList::toArray_()
{
    return Collections_SynchronizedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_SynchronizedList::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_SynchronizedCollection::toArray_(arg0));
}

java::lang::Class* java::util::Collections_SynchronizedList::getClass0()
{
    return class_();
}

