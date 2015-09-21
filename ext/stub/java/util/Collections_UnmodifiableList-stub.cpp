// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_UnmodifiableList.hpp>

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
java::util::Collections_UnmodifiableList::Collections_UnmodifiableList(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_UnmodifiableList::Collections_UnmodifiableList(List* arg0)
    : Collections_UnmodifiableList(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::util::Collections_UnmodifiableList::serialVersionUID;

void ::java::util::Collections_UnmodifiableList::ctor(List* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_UnmodifiableList::ctor(List* arg0)");
}

void java::util::Collections_UnmodifiableList::add(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"void java::util::Collections_UnmodifiableList::add(int32_t arg0, ::java::lang::Object* arg1)");
}

bool java::util::Collections_UnmodifiableList::addAll(int32_t arg0, Collection* arg1)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_UnmodifiableList::addAll(int32_t arg0, Collection* arg1)");
    return 0;
}

bool java::util::Collections_UnmodifiableList::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_UnmodifiableList::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_UnmodifiableList::get(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableList::get(int32_t arg0)");
    return 0;
}

int32_t java::util::Collections_UnmodifiableList::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_UnmodifiableList::hashCode()");
    return 0;
}

int32_t java::util::Collections_UnmodifiableList::indexOf(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_UnmodifiableList::indexOf(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Collections_UnmodifiableList::lastIndexOf(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_UnmodifiableList::lastIndexOf(::java::lang::Object* arg0)");
    return 0;
}

java::util::ListIterator* java::util::Collections_UnmodifiableList::listIterator()
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::Collections_UnmodifiableList::listIterator()");
    return 0;
}

java::util::ListIterator* java::util::Collections_UnmodifiableList::listIterator(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::util::ListIterator* java::util::Collections_UnmodifiableList::listIterator(int32_t arg0)");
    return 0;
}

/* private: java::lang::Object* java::util::Collections_UnmodifiableList::readResolve() */
java::lang::Object* java::util::Collections_UnmodifiableList::remove(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableList::remove(int32_t arg0)");
    return 0;
}

void java::util::Collections_UnmodifiableList::replaceAll(::java::util::function::UnaryOperator* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_UnmodifiableList::replaceAll(::java::util::function::UnaryOperator* arg0)");
}

java::lang::Object* java::util::Collections_UnmodifiableList::set(int32_t arg0, ::java::lang::Object* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_UnmodifiableList::set(int32_t arg0, ::java::lang::Object* arg1)");
    return 0;
}

void java::util::Collections_UnmodifiableList::sort(Comparator* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Collections_UnmodifiableList::sort(Comparator* arg0)");
}

java::util::List* java::util::Collections_UnmodifiableList::subList(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"java::util::List* java::util::Collections_UnmodifiableList::subList(int32_t arg0, int32_t arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_UnmodifiableList::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.UnmodifiableList", 38);
    return c;
}

void java::util::Collections_UnmodifiableList::forEach(::java::util::function::Consumer* action)
{
    Collections_UnmodifiableCollection::forEach(action);
}

java::util::stream::Stream* java::util::Collections_UnmodifiableList::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_UnmodifiableCollection::parallelStream());
}

bool java::util::Collections_UnmodifiableList::removeIf(::java::util::function::Predicate* filter)
{
    return Collections_UnmodifiableCollection::removeIf(filter);
}

java::util::stream::Stream* java::util::Collections_UnmodifiableList::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_UnmodifiableCollection::stream());
}

bool java::util::Collections_UnmodifiableList::add(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableCollection::add(arg0);
}

bool java::util::Collections_UnmodifiableList::addAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::addAll(arg0);
}

void java::util::Collections_UnmodifiableList::clear()
{
    Collections_UnmodifiableCollection::clear();
}

bool java::util::Collections_UnmodifiableList::contains(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableCollection::contains(arg0);
}

bool java::util::Collections_UnmodifiableList::containsAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::containsAll(arg0);
}

bool java::util::Collections_UnmodifiableList::isEmpty()
{
    return Collections_UnmodifiableCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_UnmodifiableList::iterator()
{
    return java_cast< Iterator* >(Collections_UnmodifiableCollection::iterator());
}

bool java::util::Collections_UnmodifiableList::remove(::java::lang::Object* arg0)
{
    return Collections_UnmodifiableCollection::remove(arg0);
}

bool java::util::Collections_UnmodifiableList::removeAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::removeAll(arg0);
}

bool java::util::Collections_UnmodifiableList::retainAll(Collection* arg0)
{
    return Collections_UnmodifiableCollection::retainAll(arg0);
}

int32_t java::util::Collections_UnmodifiableList::size()
{
    return Collections_UnmodifiableCollection::size();
}

java::util::Spliterator* java::util::Collections_UnmodifiableList::spliterator()
{
    return java_cast< Spliterator* >(Collections_UnmodifiableCollection::spliterator());
}

java::lang::ObjectArray* java::util::Collections_UnmodifiableList::toArray_()
{
    return Collections_UnmodifiableCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_UnmodifiableList::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_UnmodifiableCollection::toArray_(arg0));
}

java::lang::Class* java::util::Collections_UnmodifiableList::getClass0()
{
    return class_();
}

