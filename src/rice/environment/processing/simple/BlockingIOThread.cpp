// Generated from /pastry-2.1/src/rice/environment/processing/simple/BlockingIOThread.java
#include <rice/environment/processing/simple/BlockingIOThread.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/environment/processing/simple/WorkQueue.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::environment::processing::simple::BlockingIOThread::BlockingIOThread(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::BlockingIOThread::BlockingIOThread(WorkQueue* workQ) 
    : BlockingIOThread(*static_cast< ::default_init_tag* >(0))
{
    ctor(workQ);
}

void rice::environment::processing::simple::BlockingIOThread::init()
{
    running = true;
}

void rice::environment::processing::simple::BlockingIOThread::ctor(WorkQueue* workQ)
{
    super::ctor(u"Persistence Worker Thread"_j);
    init();
    this->workQ = workQ;
}

void rice::environment::processing::simple::BlockingIOThread::run()
{
    running = true;
    while (running.load()) {
        auto wr = npc(workQ)->dequeue();
        if(wr != nullptr)
            npc(wr)->run();

    }
}

void rice::environment::processing::simple::BlockingIOThread::destroy()
{
    running = false;
    npc(workQ)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::BlockingIOThread::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.BlockingIOThread", 51);
    return c;
}

java::lang::Class* rice::environment::processing::simple::BlockingIOThread::getClass0()
{
    return class_();
}

