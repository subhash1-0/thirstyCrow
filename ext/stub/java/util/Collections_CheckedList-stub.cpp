// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedList.hpp>

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
java::util::Collections_CheckedList::Collections_CheckedList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedList::Collections_CheckedList(List* arg0, ::java::lang::Class* arg1)
    : Collections_CheckedList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_CheckedList::serialVersionUID;

void ::java::util::Collections_CheckedList::ctor(List* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedList::ctor(List* arg0, ::java::lang::Class* arg1)");
}

void java::util::Collections_CheckedList::add(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Collections_CheckedList::add(int32_t arg0, ::java::lang::Object* arg1)");
}

bool java::util::Collections_CheckedList::addAll(int32_t arg0, Collection* arg1)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_CheckedList::addAll(int32_t arg0, Collection* arg1)");
    return 0;
}

bool java::util::Collections_CheckedList::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_CheckedList::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedList::get(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedList::get(int32_t arg0)");
    return 0;
}

int32_t java::util::Collections_CheckedList::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_CheckedList::hashCode()");
    return 0;
}

int32_t java::util::Collections_CheckedList::indexOf(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_CheckedList::indexOf(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Collections_CheckedList::lastIndexOf(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_CheckedList::lastIndexOf(::java::lang::Object* arg0)");
    return 0;
}

java::util::ListIterator* java::util::Collections_CheckedList::listIterator()
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::Collections_CheckedList::listIterator()");
    return 0;
}

java::util::ListIterator* java::util::Collections_CheckedList::listIterator(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::Collections_CheckedList::listIterator(int32_t arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedList::remove(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedList::remove(int32_t arg0)");
    return 0;
}

void java::util::Collections_CheckedList::replaceAll(::java::util::function::UnaryOperator* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_CheckedList::replaceAll(::java::util::function::UnaryOperator* arg0)");
}

java::lang::Object* java::util::Collections_CheckedList::set(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedList::set(int32_t arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::Collections_CheckedList::sort(Comparator* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_CheckedList::sort(Comparator* arg0)");
}

java::util::List* java::util::Collections_CheckedList::subList(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::util::List* java::util::Collections_CheckedList::subList(int32_t arg0, int32_t arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedList", 33);
    return c;
}

void java::util::Collections_CheckedList::forEach(::java::util::function::Consumer* action)
{
    Collections_CheckedCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_CheckedList::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::parallelStream());
}

bool java::util::Collections_CheckedList::removeIf(::java::util::function::Predicate* arg0)
{
    return Collections_CheckedCollection::removeIf(arg0);
}

java::util::stream::Stream* java::util::Collections_CheckedList::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::stream());
}

bool java::util::Collections_CheckedList::add(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::add(arg0);
}

bool java::util::Collections_CheckedList::addAll(Collection* arg0)
{
    return Collections_CheckedCollection::addAll(arg0);
}

void java::util::Collections_CheckedList::clear()
{
    Collections_CheckedCollection::clear();
}

bool java::util::Collections_CheckedList::contains(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::contains(arg0);
}

bool java::util::Collections_CheckedList::containsAll(Collection* arg0)
{
    return Collections_CheckedCollection::containsAll(arg0);
}

bool java::util::Collections_CheckedList::isEmpty()
{
    return Collections_CheckedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_CheckedList::iterator()
{
    return java_cast< Iterator* >(Collections_CheckedCollection::iterator());
}

bool java::util::Collections_CheckedList::remove(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::remove(arg0);
}

bool java::util::Collections_CheckedList::removeAll(Collection* arg0)
{
    return Collections_CheckedCollection::removeAll(arg0);
}

bool java::util::Collections_CheckedList::retainAll(Collection* arg0)
{
    return Collections_CheckedCollection::retainAll(arg0);
}

int32_t java::util::Collections_CheckedList::size()
{
    return Collections_CheckedCollection::size();
}

java::util::Spliterator* java::util::Collections_CheckedList::spliterator()
{
    return java_cast< Spliterator* >(Collections_CheckedCollection::spliterator());
}

java::lang::ObjectArray* java::util::Collections_CheckedList::toArray_()
{
    return Collections_CheckedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_CheckedList::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_CheckedCollection::toArray_(arg0));
}

java::lang::Class* java::util::Collections_CheckedList::getClass0()
{
    return class_();
}

