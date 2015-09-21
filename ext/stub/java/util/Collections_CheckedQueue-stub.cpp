// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Collections_CheckedQueue.hpp>

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
java::util::Collections_CheckedQueue::Collections_CheckedQueue(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Collections_CheckedQueue::Collections_CheckedQueue(Queue* arg0, ::java::lang::Class* arg1)
    : Collections_CheckedQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::util::Collections_CheckedQueue::serialVersionUID;

void ::java::util::Collections_CheckedQueue::ctor(Queue* arg0, ::java::lang::Class* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Collections_CheckedQueue::ctor(Queue* arg0, ::java::lang::Class* arg1)");
}

java::lang::Object* java::util::Collections_CheckedQueue::element()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedQueue::element()");
    return 0;
}

bool java::util::Collections_CheckedQueue::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_CheckedQueue::equals(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::util::Collections_CheckedQueue::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::util::Collections_CheckedQueue::hashCode()");
    return 0;
}

bool java::util::Collections_CheckedQueue::offer(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Collections_CheckedQueue::offer(::java::lang::Object* arg0)");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedQueue::peek()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedQueue::peek()");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedQueue::poll()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedQueue::poll()");
    return 0;
}

java::lang::Object* java::util::Collections_CheckedQueue::remove()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::Collections_CheckedQueue::remove()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Collections_CheckedQueue::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Collections.CheckedQueue", 34);
    return c;
}

void java::util::Collections_CheckedQueue::forEach(::java::util::function::Consumer* arg0)
{
    Collections_CheckedCollection::forEach(arg0);
}

bool java::util::Collections_CheckedQueue::addAll(Collection* arg0)
{
    return Collections_CheckedCollection::addAll(arg0);
}

void java::util::Collections_CheckedQueue::clear()
{
    Collections_CheckedCollection::clear();
}

bool java::util::Collections_CheckedQueue::contains(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::contains(arg0);
}

bool java::util::Collections_CheckedQueue::containsAll(Collection* arg0)
{
    return Collections_CheckedCollection::containsAll(arg0);
}

bool java::util::Collections_CheckedQueue::isEmpty()
{
    return Collections_CheckedCollection::isEmpty();
}

java::util::Iterator* java::util::Collections_CheckedQueue::iterator()
{
    return java_cast< Iterator* >(Collections_CheckedCollection::iterator());
}

java::util::stream::Stream* java::util::Collections_CheckedQueue::parallelStream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::parallelStream());
}

bool java::util::Collections_CheckedQueue::remove(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::remove(arg0);
}

bool java::util::Collections_CheckedQueue::removeAll(Collection* arg0)
{
    return Collections_CheckedCollection::removeAll(arg0);
}

bool java::util::Collections_CheckedQueue::removeIf(::java::util::function::Predicate* arg0)
{
    return Collections_CheckedCollection::removeIf(arg0);
}

bool java::util::Collections_CheckedQueue::retainAll(Collection* arg0)
{
    return Collections_CheckedCollection::retainAll(arg0);
}

int32_t java::util::Collections_CheckedQueue::size()
{
    return Collections_CheckedCollection::size();
}

java::util::Spliterator* java::util::Collections_CheckedQueue::spliterator()
{
    return java_cast< Spliterator* >(Collections_CheckedCollection::spliterator());
}

java::util::stream::Stream* java::util::Collections_CheckedQueue::stream()
{
    return java_cast< ::java::util::stream::Stream* >(Collections_CheckedCollection::stream());
}

java::lang::ObjectArray* java::util::Collections_CheckedQueue::toArray_()
{
    return Collections_CheckedCollection::toArray_();
}

java::lang::ObjectArray* java::util::Collections_CheckedQueue::toArray_(::java::lang::ObjectArray* arg0)
{
    return java_cast< ::java::lang::ObjectArray* >(Collections_CheckedCollection::toArray_(arg0));
}

bool java::util::Collections_CheckedQueue::add(::java::lang::Object* arg0)
{
    return Collections_CheckedCollection::add(arg0);
}

java::lang::Class* java::util::Collections_CheckedQueue::getClass0()
{
    return class_();
}

