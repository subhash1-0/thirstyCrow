// Generated from /pastry-2.1/src/rice/environment/processing/simple/ProcessingThread.java
#include <rice/environment/processing/simple/ProcessingThread.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/util/concurrent/PriorityBlockingQueue.hpp>
#include <rice/environment/processing/simple/ProcessingRequest.hpp>

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

rice::environment::processing::simple::ProcessingThread::ProcessingThread(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::ProcessingThread::ProcessingThread(::java::lang::String* name, ::java::util::concurrent::PriorityBlockingQueue* queue) 
    : ProcessingThread(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,queue);
}

void rice::environment::processing::simple::ProcessingThread::init()
{
    running = false;
}

void rice::environment::processing::simple::ProcessingThread::ctor(::java::lang::String* name, ::java::util::concurrent::PriorityBlockingQueue* queue)
{
    super::ctor(name);
    init();
    this->queue = queue;
}

void rice::environment::processing::simple::ProcessingThread::run()
{
    running = true;
    while (running.load()) {
        try {
            auto e = java_cast< ProcessingRequest* >(npc(queue)->take());
            if(e != nullptr)
                npc(e)->run();

        } catch (::java::lang::InterruptedException* ie) {
        }
    }
}

void rice::environment::processing::simple::ProcessingThread::destroy()
{
    running = false;
    interrupt();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::ProcessingThread::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.ProcessingThread", 51);
    return c;
}

java::lang::Class* rice::environment::processing::simple::ProcessingThread::getClass0()
{
    return class_();
}

