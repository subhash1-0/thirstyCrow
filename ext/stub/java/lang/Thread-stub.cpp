// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Thread.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Runnable, ObjectArray > RunnableArray;
typedef ::SubArray< ::java::lang::StackTraceElement, ObjectArray, ::java::io::SerializableArray > StackTraceElementArray;
typedef ::SubArray< ::java::lang::Thread, ObjectArray, RunnableArray > ThreadArray;
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
java::lang::Thread::Thread(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Thread::Thread()
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Thread::Thread(Runnable* arg0)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Thread::Thread(String* arg0)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::Thread::Thread(Runnable* arg0, ::java::security::AccessControlContext* arg1)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Thread::Thread(ThreadGroup* arg0, Runnable* arg1)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Thread::Thread(ThreadGroup* arg0, String* arg1)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Thread::Thread(Runnable* arg0, String* arg1)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::Thread::Thread(ThreadGroup* arg0, Runnable* arg1, String* arg2)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

java::lang::Thread::Thread(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3)
    : Thread(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

java::lang::StackTraceElementArray*& java::lang::Thread::EMPTY_STACK_TRACE()
{
    clinit();
    return EMPTY_STACK_TRACE_;
}
java::lang::StackTraceElementArray* java::lang::Thread::EMPTY_STACK_TRACE_;
constexpr int32_t java::lang::Thread::MAX_PRIORITY;
constexpr int32_t java::lang::Thread::MIN_PRIORITY;
constexpr int32_t java::lang::Thread::NORM_PRIORITY;
java::lang::RuntimePermission*& java::lang::Thread::SUBCLASS_IMPLEMENTATION_PERMISSION()
{
    clinit();
    return SUBCLASS_IMPLEMENTATION_PERMISSION_;
}
java::lang::RuntimePermission* java::lang::Thread::SUBCLASS_IMPLEMENTATION_PERMISSION_;
std::atomic< java::lang::Thread_UncaughtExceptionHandler* >& java::lang::Thread::defaultUncaughtExceptionHandler()
{
    clinit();
    return defaultUncaughtExceptionHandler_;
}
std::atomic< java::lang::Thread_UncaughtExceptionHandler* > java::lang::Thread::defaultUncaughtExceptionHandler_;
int32_t& java::lang::Thread::threadInitNumber()
{
    clinit();
    return threadInitNumber_;
}
int32_t java::lang::Thread::threadInitNumber_;
int64_t& java::lang::Thread::threadSeqNumber()
{
    clinit();
    return threadSeqNumber_;
}
int64_t java::lang::Thread::threadSeqNumber_;

void ::java::lang::Thread::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor()");
}

void ::java::lang::Thread::ctor(Runnable* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(Runnable* arg0)");
}

void ::java::lang::Thread::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(String* arg0)");
}

void ::java::lang::Thread::ctor(Runnable* arg0, ::java::security::AccessControlContext* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(Runnable* arg0, ::java::security::AccessControlContext* arg1)");
}

void ::java::lang::Thread::ctor(ThreadGroup* arg0, Runnable* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(ThreadGroup* arg0, Runnable* arg1)");
}

void ::java::lang::Thread::ctor(ThreadGroup* arg0, String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(ThreadGroup* arg0, String* arg1)");
}

void ::java::lang::Thread::ctor(Runnable* arg0, String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(Runnable* arg0, String* arg1)");
}

void ::java::lang::Thread::ctor(ThreadGroup* arg0, Runnable* arg1, String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(ThreadGroup* arg0, Runnable* arg1, String* arg2)");
}

void ::java::lang::Thread::ctor(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread::ctor(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3)");
}

int32_t java::lang::Thread::activeCount()
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Thread::activeCount()");
    return 0;
}

/* private: bool java::lang::Thread::auditSubclass(Class* arg0) */
void java::lang::Thread::blockedOn(::sun::nio::ch::Interruptible* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Thread::blockedOn(::sun::nio::ch::Interruptible* arg0)");
}

void java::lang::Thread::checkAccess()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::checkAccess()");
}

java::lang::Object* java::lang::Thread::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::Thread::clone()");
    return 0;
}

void java::lang::Thread::destroy()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::destroy()");
}

/* private: void java::lang::Thread::dispatchUncaughtException(Throwable* arg0) */
void java::lang::Thread::dumpStack()
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::Thread::dumpStack()");
}

int32_t java::lang::Thread::enumerate(ThreadArray* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::lang::Thread::enumerate(ThreadArray* arg0)");
    return 0;
}

/* private: void java::lang::Thread::exit() */
java::util::Map* java::lang::Thread::getAllStackTraces()
{ /* stub */
    clinit();
    unimplemented_(u"java::util::Map* java::lang::Thread::getAllStackTraces()");
    return 0;
}

java::lang::ClassLoader* java::lang::Thread::getContextClassLoader()
{ /* stub */
return contextClassLoader ; /* getter */
}

java::lang::Thread_UncaughtExceptionHandler* java::lang::Thread::getDefaultUncaughtExceptionHandler()
{ /* stub */
    clinit();
return defaultUncaughtExceptionHandler() ; /* getter */
}

int64_t java::lang::Thread::getId()
{ /* stub */
    unimplemented_(u"int64_t java::lang::Thread::getId()");
    return 0;
}

java::lang::String* java::lang::Thread::getName()
{ /* stub */
}

int32_t java::lang::Thread::getPriority()
{ /* stub */
return priority ; /* getter */
}

java::lang::StackTraceElementArray* java::lang::Thread::getStackTrace()
{ /* stub */
    unimplemented_(u"java::lang::StackTraceElementArray* java::lang::Thread::getStackTrace()");
    return 0;
}

java::lang::Thread_State* java::lang::Thread::getState()
{ /* stub */
    unimplemented_(u"java::lang::Thread_State* java::lang::Thread::getState()");
    return 0;
}

java::lang::ThreadGroup* java::lang::Thread::getThreadGroup()
{ /* stub */
    unimplemented_(u"java::lang::ThreadGroup* java::lang::Thread::getThreadGroup()");
    return 0;
}

java::lang::Thread_UncaughtExceptionHandler* java::lang::Thread::getUncaughtExceptionHandler()
{ /* stub */
return uncaughtExceptionHandler ; /* getter */
}

/* private: void java::lang::Thread::init_(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3) */
/* private: void java::lang::Thread::init_(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3, ::java::security::AccessControlContext* arg4) */
void java::lang::Thread::interrupt()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::interrupt()");
}

bool java::lang::Thread::interrupted()
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Thread::interrupted()");
    return 0;
}

/* private: bool java::lang::Thread::isCCLOverridden(Class* arg0) */
bool java::lang::Thread::isDaemon()
{ /* stub */
    unimplemented_(u"bool java::lang::Thread::isDaemon()");
    return 0;
}

bool java::lang::Thread::isInterrupted()
{ /* stub */
    unimplemented_(u"bool java::lang::Thread::isInterrupted()");
    return 0;
}

void java::lang::Thread::join()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::join()");
}

void java::lang::Thread::join(int64_t arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Thread::join(int64_t arg0)");
}

void java::lang::Thread::join(int64_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"void java::lang::Thread::join(int64_t arg0, int32_t arg1)");
}

/* private: int64_t java::lang::Thread::nextThreadID() */
/* private: int32_t java::lang::Thread::nextThreadNum() */
void java::lang::Thread::processQueue(::java::lang::ref::ReferenceQueue* arg0, ::java::util::concurrent::ConcurrentMap* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::Thread::processQueue(::java::lang::ref::ReferenceQueue* arg0, ::java::util::concurrent::ConcurrentMap* arg1)");
}

void java::lang::Thread::resume()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::resume()");
}

void java::lang::Thread::run()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::run()");
}

void java::lang::Thread::setContextClassLoader(ClassLoader* arg0)
{ /* stub */
    this->contextClassLoader = arg0; /* setter */
}

void java::lang::Thread::setDaemon(bool arg0)
{ /* stub */
    this->daemon = arg0; /* setter */
}

void java::lang::Thread::setDefaultUncaughtExceptionHandler(Thread_UncaughtExceptionHandler* arg0)
{ /* stub */
    clinit();
    Thread::defaultUncaughtExceptionHandler() = arg0; /* setter */
}

void java::lang::Thread::setName(String* arg0)
{ /* stub */
}

void java::lang::Thread::setPriority(int32_t arg0)
{ /* stub */
    this->priority = arg0; /* setter */
}

void java::lang::Thread::setUncaughtExceptionHandler(Thread_UncaughtExceptionHandler* arg0)
{ /* stub */
    this->uncaughtExceptionHandler = arg0; /* setter */
}

void java::lang::Thread::sleep(int64_t arg0, int32_t arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::Thread::sleep(int64_t arg0, int32_t arg1)");
}

void java::lang::Thread::start()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::start()");
}

void java::lang::Thread::stop()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::stop()");
}

void java::lang::Thread::stop(Throwable* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Thread::stop(Throwable* arg0)");
}

void java::lang::Thread::suspend()
{ /* stub */
    unimplemented_(u"void java::lang::Thread::suspend()");
}

java::lang::String* java::lang::Thread::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Thread::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Thread::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Thread", 16);
    return c;
}

java::lang::Class* java::lang::Thread::getClass0()
{
    return class_();
}

