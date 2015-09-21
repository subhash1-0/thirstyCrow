// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java
#include <rice/environment/processing/simple/SimpleProcessor.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/util/concurrent/PriorityBlockingQueue.hpp>
#include <rice/Continuation.hpp>
#include <rice/Executable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/environment/processing/WorkRequest.hpp>
#include <rice/environment/processing/simple/BlockingIOThread.hpp>
#include <rice/environment/processing/simple/ProcessingRequest.hpp>
#include <rice/environment/processing/simple/ProcessingThread.hpp>
#include <rice/environment/processing/simple/SimpleProcessor_main_1.hpp>
#include <rice/environment/processing/simple/SimpleProcessor_main_2.hpp>
#include <rice/environment/processing/simple/SimpleProcessor_main_3.hpp>
#include <rice/environment/processing/simple/SimpleProcessor_main_4.hpp>
#include <rice/environment/processing/simple/WorkQueue.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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
rice::environment::processing::simple::SimpleProcessor::SimpleProcessor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::environment::processing::simple::SimpleProcessor::SimpleProcessor(::java::lang::String* name) 
    : SimpleProcessor(*static_cast< ::default_init_tag* >(0))
{
    ctor(name);
}

void rice::environment::processing::simple::SimpleProcessor::init()
{
    seq = ::java::lang::Long::MIN_VALUE;
}

void rice::environment::processing::simple::SimpleProcessor::ctor(::java::lang::String* name)
{
    super::ctor();
    init();
    QUEUE = new ::java::util::concurrent::PriorityBlockingQueue();
    THREAD = new ProcessingThread(::java::lang::StringBuilder().append(name)->append(u".ProcessingThread"_j)->toString(), QUEUE);
    npc(THREAD)->start();
    npc(THREAD)->setPriority(::java::lang::Thread::MIN_PRIORITY);
    workQueue = new WorkQueue();
    bioThread = new BlockingIOThread(workQueue);
    npc(bioThread)->start();
}

/* <R, E extends Exception> */rice::p2p::commonapi::Cancellable* rice::environment::processing::simple::SimpleProcessor::process(::rice::Executable* task, ::rice::Continuation* command, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log)
{
    return process(static_cast< ::rice::Executable* >(task), static_cast< ::rice::Continuation* >(command), int32_t(0), selector, ts, log);
}

/* <R, E extends Exception> */rice::p2p::commonapi::Cancellable* rice::environment::processing::simple::SimpleProcessor::process(::rice::Executable* task, ::rice::Continuation* command, int32_t priority, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log)
{
    int64_t nextSeq;
    {
        synchronized synchronized_0(this);
        {
            nextSeq = seq++;
        }
    }
    auto ret = new ProcessingRequest(task, command, priority, nextSeq, log, ts, selector);
    npc(QUEUE)->offer(static_cast< ::java::lang::Object* >(ret));
    return ret;
}

rice::p2p::commonapi::Cancellable* rice::environment::processing::simple::SimpleProcessor::processBlockingIO(::rice::environment::processing::WorkRequest* workRequest)
{
    npc(workQueue)->enqueue(workRequest);
    return workRequest;
}

java::util::Queue* rice::environment::processing::simple::SimpleProcessor::getQueue()
{
    return QUEUE;
}

void rice::environment::processing::simple::SimpleProcessor::destroy()
{
    npc(THREAD)->destroy();
    npc(QUEUE)->clear();
    npc(bioThread)->destroy();
    npc(workQueue)->destroy();
}

rice::environment::processing::simple::WorkQueue* rice::environment::processing::simple::SimpleProcessor::getIOQueue()
{
    return workQueue;
}

void rice::environment::processing::simple::SimpleProcessor::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto env = new ::rice::environment::Environment();
    auto p = npc(env)->getProcessor();
    npc(p)->process(new SimpleProcessor_main_1(), new SimpleProcessor_main_2(), npc(env)->getSelectorManager(), npc(env)->getTimeSource(), npc(env)->getLogManager());
    for (auto seq = int32_t(0); seq < 10; seq++) {
        auto const mySeq = seq;
        npc(p)->process(new SimpleProcessor_main_3(mySeq), new SimpleProcessor_main_4(mySeq), npc(env)->getSelectorManager(), npc(env)->getTimeSource(), npc(env)->getLogManager());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Done scheduling "_j)->append(mySeq)->toString());
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::environment::processing::simple::SimpleProcessor::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.environment.processing.simple.SimpleProcessor", 50);
    return c;
}

java::lang::Class* rice::environment::processing::simple::SimpleProcessor::getClass0()
{
    return class_();
}

