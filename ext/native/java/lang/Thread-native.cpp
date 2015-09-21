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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Runnable, ObjectArray > RunnableArray;
typedef ::SubArray< ::java::lang::StackTraceElement, ObjectArray, ::java::io::SerializableArray > StackTraceElementArray;
typedef ::SubArray< ::java::lang::Thread, ObjectArray, RunnableArray > ThreadArray;
typedef ::SubArray< ::java::lang::StackTraceElementArray, CloneableArray, ::java::io::SerializableArray > StackTraceElementArrayArray;
    } // lang
} // java

extern void unimplemented_(const char16_t* name);

int32_t java::lang::Thread::countStackFrames()
{ /* native */
    unimplemented_(u"int32_t java::lang::Thread::countStackFrames()");
    return 0;
}

java::lang::Thread* java::lang::Thread::currentThread()
{ /* native */
    clinit();
    unimplemented_(u"java::lang::Thread* java::lang::Thread::currentThread()");
    return 0;
}

/* private: java::lang::StackTraceElementArrayArray* java::lang::Thread::dumpThreads(ThreadArray* arg0) */
/* private: java::lang::ThreadArray* java::lang::Thread::getThreads() */
bool java::lang::Thread::holdsLock(Object* arg0)
{ /* native */
    clinit();
    unimplemented_(u"bool java::lang::Thread::holdsLock(Object* arg0)");
    return 0;
}

/* private: void java::lang::Thread::interrupt0() */
bool java::lang::Thread::isAlive()
{ /* native */
    unimplemented_(u"bool java::lang::Thread::isAlive()");
    return 0;
}

/* private: bool java::lang::Thread::isInterrupted(bool arg0) */
/* private: void java::lang::Thread::registerNatives() */
/* private: void java::lang::Thread::resume0() */
/* private: void java::lang::Thread::setNativeName(String* arg0) */
/* private: void java::lang::Thread::setPriority0(int32_t arg0) */
void java::lang::Thread::sleep(int64_t arg0)
{ /* native */
    clinit();
    unimplemented_(u"void java::lang::Thread::sleep(int64_t arg0)");
}

/* private: void java::lang::Thread::start0() */
/* private: void java::lang::Thread::stop0(Object* arg0) */
/* private: void java::lang::Thread::suspend0() */
void java::lang::Thread::yield()
{ /* native */
    clinit();
    unimplemented_(u"void java::lang::Thread::yield()");
}

