// Generated from /pastry-2.1/src/rice/environment/processing/simple/WorkQueue.java
#include <rice/environment/processing/simple/WorkQueue.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/List.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/environment/processing/simple/WorkQueueOverflowException.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
rice::environment::processing::simple::WorkQueue::WorkQueue(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::WorkQueue::WorkQueue() 
    : WorkQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

rice::environment::processing::simple::WorkQueue::WorkQueue(int32_t capacity) 
    : WorkQueue(*static_cast< ::default_init_tag* >(0))
{
    ctor(capacity);
}

void rice::environment::processing::simple::WorkQueue::init()
{
    q = new ::java::util::LinkedList();
    capacity = -int32_t(1);
    running = true;
}

void rice::environment::processing::simple::WorkQueue::ctor()
{
    super::ctor();
    init();
}

int32_t rice::environment::processing::simple::WorkQueue::getLength()
{
    return npc(q)->size();
}

void rice::environment::processing::simple::WorkQueue::ctor(int32_t capacity)
{
    super::ctor();
    init();
    this->capacity = capacity;
}

void rice::environment::processing::simple::WorkQueue::enqueue(::rice::environment::processing::WorkRequest* request)
{
    if(capacity < 0 || npc(q)->size() < capacity) {
        npc(q)->add(static_cast< ::java::lang::Object* >(request));
        notifyAll();
    } else {
        npc(request)->returnError(new WorkQueueOverflowException());
    }
}

rice::environment::processing::WorkRequest* rice::environment::processing::simple::WorkQueue::dequeue()
{
    while (npc(q)->isEmpty() && running.load()) {
        try {
            wait();
        } catch (::java::lang::InterruptedException* e) {
            npc(e)->printStackTrace();
        }
    }
    if(!running.load())
        return nullptr;

    return java_cast< ::rice::environment::processing::WorkRequest* >(java_cast< ::rice::environment::processing::WorkRequest* >(npc(q)->remove(int32_t(0))));
}

void rice::environment::processing::simple::WorkQueue::destroy()
{
    running = false;
    {
        synchronized synchronized_0(this);
        {
            notifyAll();
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::WorkQueue::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.WorkQueue", 44);
    return c;
}

java::lang::Class* rice::environment::processing::simple::WorkQueue::getClass0()
{
    return class_();
}

