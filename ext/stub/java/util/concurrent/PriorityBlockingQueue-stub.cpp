// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/concurrent/PriorityBlockingQueue.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Object.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

extern void unimplemented_(const char16_t* name);
java::util::concurrent::PriorityBlockingQueue::PriorityBlockingQueue(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::concurrent::PriorityBlockingQueue::PriorityBlockingQueue()
    : PriorityBlockingQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::util::concurrent::PriorityBlockingQueue::PriorityBlockingQueue(int32_t arg0)
    : PriorityBlockingQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::concurrent::PriorityBlockingQueue::PriorityBlockingQueue(::java::util::Collection* arg0)
    : PriorityBlockingQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::util::concurrent::PriorityBlockingQueue::PriorityBlockingQueue(int32_t arg0, ::java::util::Comparator* arg1)
    : PriorityBlockingQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int32_t java::util::concurrent::PriorityBlockingQueue::DEFAULT_INITIAL_CAPACITY;
constexpr int32_t java::util::concurrent::PriorityBlockingQueue::MAX_ARRAY_SIZE;
sun::misc::Unsafe*& java::util::concurrent::PriorityBlockingQueue::UNSAFE()
{
    clinit();
    return UNSAFE_;
}
sun::misc::Unsafe* java::util::concurrent::PriorityBlockingQueue::UNSAFE_;
int64_t& java::util::concurrent::PriorityBlockingQueue::allocationSpinLockOffset()
{
    clinit();
    return allocationSpinLockOffset_;
}
int64_t java::util::concurrent::PriorityBlockingQueue::allocationSpinLockOffset_;
constexpr int64_t java::util::concurrent::PriorityBlockingQueue::serialVersionUID;

void ::java::util::concurrent::PriorityBlockingQueue::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::concurrent::PriorityBlockingQueue::ctor()");
}

void ::java::util::concurrent::PriorityBlockingQueue::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::concurrent::PriorityBlockingQueue::ctor(int32_t arg0)");
}

void ::java::util::concurrent::PriorityBlockingQueue::ctor(::java::util::Collection* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::concurrent::PriorityBlockingQueue::ctor(::java::util::Collection* arg0)");
}

void ::java::util::concurrent::PriorityBlockingQueue::ctor(int32_t arg0, ::java::util::Comparator* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::concurrent::PriorityBlockingQueue::ctor(int32_t arg0, ::java::util::Comparator* arg1)");
}

bool java::util::concurrent::PriorityBlockingQueue::add(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue::add(::java::lang::Object* arg0)");
    return 0;
}

void java::util::concurrent::PriorityBlockingQueue::clear()
{ /* stub */
    unimplemented_(u"void java::util::concurrent::PriorityBlockingQueue::clear()");
}

java::util::Comparator* java::util::concurrent::PriorityBlockingQueue::comparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::concurrent::PriorityBlockingQueue::comparator()");
    return 0;
}

bool java::util::concurrent::PriorityBlockingQueue::contains(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue::contains(::java::lang::Object* arg0)");
    return 0;
}

/* private: java::lang::Object* java::util::concurrent::PriorityBlockingQueue::dequeue() */
int32_t java::util::concurrent::PriorityBlockingQueue::drainTo(::java::util::Collection* arg0)
{ /* stub */
    unimplemented_(u"int32_t java::util::concurrent::PriorityBlockingQueue::drainTo(::java::util::Collection* arg0)");
    return 0;
}

int32_t java::util::concurrent::PriorityBlockingQueue::drainTo(::java::util::Collection* arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"int32_t java::util::concurrent::PriorityBlockingQueue::drainTo(::java::util::Collection* arg0, int32_t arg1)");
    return 0;
}

/* private: void java::util::concurrent::PriorityBlockingQueue::heapify() */
/* private: int32_t java::util::concurrent::PriorityBlockingQueue::indexOf(::java::lang::Object* arg0) */
java::util::Iterator* java::util::concurrent::PriorityBlockingQueue::iterator()
{ /* stub */
    unimplemented_(u"java::util::Iterator* java::util::concurrent::PriorityBlockingQueue::iterator()");
    return 0;
}

bool java::util::concurrent::PriorityBlockingQueue::offer(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue::offer(::java::lang::Object* arg0)");
    return 0;
}

bool java::util::concurrent::PriorityBlockingQueue::offer(::java::lang::Object* arg0, int64_t arg1, TimeUnit* arg2)
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue::offer(::java::lang::Object* arg0, int64_t arg1, TimeUnit* arg2)");
    return 0;
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue::peek()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::concurrent::PriorityBlockingQueue::peek()");
    return 0;
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue::poll()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::concurrent::PriorityBlockingQueue::poll()");
    return 0;
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue::poll(int64_t arg0, TimeUnit* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::concurrent::PriorityBlockingQueue::poll(int64_t arg0, TimeUnit* arg1)");
    return 0;
}

void java::util::concurrent::PriorityBlockingQueue::put(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"void java::util::concurrent::PriorityBlockingQueue::put(::java::lang::Object* arg0)");
}

/* private: void java::util::concurrent::PriorityBlockingQueue::readObject(::java::io::ObjectInputStream* arg0) */
int32_t java::util::concurrent::PriorityBlockingQueue::remainingCapacity()
{ /* stub */
    unimplemented_(u"int32_t java::util::concurrent::PriorityBlockingQueue::remainingCapacity()");
    return 0;
}

bool java::util::concurrent::PriorityBlockingQueue::remove(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue::remove(::java::lang::Object* arg0)");
    return 0;
}

/* private: void java::util::concurrent::PriorityBlockingQueue::removeAt(int32_t arg0) */
void java::util::concurrent::PriorityBlockingQueue::removeEQ(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"void java::util::concurrent::PriorityBlockingQueue::removeEQ(::java::lang::Object* arg0)");
}

/* private: void java::util::concurrent::PriorityBlockingQueue::siftDownComparable(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2, int32_t arg3) */
/* private: void java::util::concurrent::PriorityBlockingQueue::siftDownUsingComparator(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2, int32_t arg3, ::java::util::Comparator* arg4) */
/* private: void java::util::concurrent::PriorityBlockingQueue::siftUpComparable(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2) */
/* private: void java::util::concurrent::PriorityBlockingQueue::siftUpUsingComparator(int32_t arg0, ::java::lang::Object* arg1, ::java::lang::ObjectArray* arg2, ::java::util::Comparator* arg3) */
int32_t java::util::concurrent::PriorityBlockingQueue::size()
{ /* stub */
    unimplemented_(u"int32_t java::util::concurrent::PriorityBlockingQueue::size()");
    return 0;
}

java::util::Spliterator* java::util::concurrent::PriorityBlockingQueue::spliterator()
{ /* stub */
    unimplemented_(u"java::util::Spliterator* java::util::concurrent::PriorityBlockingQueue::spliterator()");
    return 0;
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue::take()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::concurrent::PriorityBlockingQueue::take()");
    return 0;
}

java::lang::ObjectArray* java::util::concurrent::PriorityBlockingQueue::toArray_()
{ /* stub */
    unimplemented_(u"java::lang::ObjectArray* java::util::concurrent::PriorityBlockingQueue::toArray_()");
    return 0;
}

java::lang::ObjectArray* java::util::concurrent::PriorityBlockingQueue::toArray_(::java::lang::ObjectArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::ObjectArray* java::util::concurrent::PriorityBlockingQueue::toArray_(::java::lang::ObjectArray* arg0)");
    return 0;
}

java::lang::String* java::util::concurrent::PriorityBlockingQueue::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::util::concurrent::PriorityBlockingQueue::toString()");
    return 0;
}

/* private: void java::util::concurrent::PriorityBlockingQueue::tryGrow(::java::lang::ObjectArray* arg0, int32_t arg1) */
/* private: void java::util::concurrent::PriorityBlockingQueue::writeObject(::java::io::ObjectOutputStream* arg0) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::concurrent::PriorityBlockingQueue::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.concurrent.PriorityBlockingQueue", 42);
    return c;
}

bool java::util::concurrent::PriorityBlockingQueue::addAll(::java::util::Collection* arg0)
{
    return AbstractQueue::addAll(arg0);
}

bool java::util::concurrent::PriorityBlockingQueue::containsAll(::java::util::Collection* arg0)
{
    return AbstractCollection::containsAll(arg0);
}

bool java::util::concurrent::PriorityBlockingQueue::equals(::java::lang::Object* arg0)
{
    return Object::equals(arg0);
}

int32_t java::util::concurrent::PriorityBlockingQueue::hashCode()
{
    return Object::hashCode();
}

bool java::util::concurrent::PriorityBlockingQueue::isEmpty()
{
    return AbstractCollection::isEmpty();
}

bool java::util::concurrent::PriorityBlockingQueue::removeAll(::java::util::Collection* arg0)
{
    return AbstractCollection::removeAll(arg0);
}

bool java::util::concurrent::PriorityBlockingQueue::retainAll(::java::util::Collection* arg0)
{
    return AbstractCollection::retainAll(arg0);
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue::element()
{
    return java_cast< ::java::lang::Object* >(AbstractQueue::element());
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue::remove()
{
    return java_cast< ::java::lang::Object* >(AbstractQueue::remove());
}

java::lang::Class* java::util::concurrent::PriorityBlockingQueue::getClass0()
{
    return class_();
}

