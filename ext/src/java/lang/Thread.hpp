// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <sun/nio/ch/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

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

struct default_init_tag;

class java::lang::Thread
    : public virtual Object
    , public virtual Runnable
{

public:
    typedef Object super;

private:
    static StackTraceElementArray* EMPTY_STACK_TRACE_;

public:
    static constexpr int32_t MAX_PRIORITY { int32_t(10) };
    static constexpr int32_t MIN_PRIORITY { int32_t(1) };
    static constexpr int32_t NORM_PRIORITY { int32_t(5) };

private:
    static RuntimePermission* SUBCLASS_IMPLEMENTATION_PERMISSION_;
    std::atomic< ::sun::nio::ch::Interruptible* > blocker {  };
    Object* blockerLock {  };
    ClassLoader* contextClassLoader {  };
    bool daemon {  };
    static std::atomic< Thread_UncaughtExceptionHandler* > defaultUncaughtExceptionHandler_;
    int64_t eetop {  };
    ThreadGroup* group {  };

public: /* package */
    ThreadLocal_ThreadLocalMap* inheritableThreadLocals {  };

private:
    ::java::security::AccessControlContext* inheritedAccessControlContext {  };
    std::atomic< ::char16_tArray* > name {  };
    int64_t nativeParkEventPointer {  };

public: /* package */
    std::atomic< Object* > parkBlocker {  };

private:
    int32_t priority {  };
    bool single_step {  };
    int64_t stackSize {  };
    bool stillborn {  };
    Runnable* target {  };
    static int32_t threadInitNumber_;

public: /* package */
    int32_t threadLocalRandomProbe {  };
    int32_t threadLocalRandomSecondarySeed {  };
    int64_t threadLocalRandomSeed {  };
    ThreadLocal_ThreadLocalMap* threadLocals {  };

private:
    Thread* threadQ {  };
    static int64_t threadSeqNumber_;
    std::atomic< int32_t > threadStatus {  };
    int64_t tid {  };
    std::atomic< Thread_UncaughtExceptionHandler* > uncaughtExceptionHandler {  };

protected:
    void ctor();
    void ctor(Runnable* arg0);
    void ctor(String* arg0);
    void ctor(Runnable* arg0, ::java::security::AccessControlContext* arg1);
    void ctor(ThreadGroup* arg0, Runnable* arg1);
    void ctor(ThreadGroup* arg0, String* arg1);
    void ctor(Runnable* arg0, String* arg1);
    void ctor(ThreadGroup* arg0, Runnable* arg1, String* arg2);
    void ctor(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3);

public:
    static int32_t activeCount();
    /*static bool auditSubclass(Class* arg0); (private) */

public: /* package */
    virtual void blockedOn(::sun::nio::ch::Interruptible* arg0);

public:
    void checkAccess();

public: /* protected */
    Object* clone() override;

public:
    virtual int32_t countStackFrames();
    static Thread* currentThread();
    virtual void destroy();
    /*void dispatchUncaughtException(Throwable* arg0); (private) */
    static void dumpStack();
    /*static StackTraceElementArrayArray* dumpThreads(ThreadArray* arg0); (private) */
    static int32_t enumerate(ThreadArray* arg0);
    /*void exit(); (private) */
    static ::java::util::Map* getAllStackTraces();
    virtual ClassLoader* getContextClassLoader();
    static Thread_UncaughtExceptionHandler* getDefaultUncaughtExceptionHandler();
    virtual int64_t getId();
    String* getName();
    int32_t getPriority();
    virtual StackTraceElementArray* getStackTrace();
    virtual Thread_State* getState();
    ThreadGroup* getThreadGroup();
    /*static ThreadArray* getThreads(); (private) */
    virtual Thread_UncaughtExceptionHandler* getUncaughtExceptionHandler();
    static bool holdsLock(Object* arg0);
    /*void init_(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3); (private) */
    /*void init_(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3, ::java::security::AccessControlContext* arg4); (private) */
    virtual void interrupt();
    /*void interrupt0(); (private) */
    static bool interrupted();
    bool isAlive();
    /*static bool isCCLOverridden(Class* arg0); (private) */
    bool isDaemon();
    virtual bool isInterrupted();
    /*bool isInterrupted(bool arg0); (private) */
    void join();
    void join(int64_t arg0);
    void join(int64_t arg0, int32_t arg1);
    /*static int64_t nextThreadID(); (private) */
    /*static int32_t nextThreadNum(); (private) */

public: /* package */
    static void processQueue(::java::lang::ref::ReferenceQueue* arg0, ::java::util::concurrent::ConcurrentMap* arg1);
    /*static void registerNatives(); (private) */

public:
    void resume();
    /*void resume0(); (private) */
    void run() override;
    virtual void setContextClassLoader(ClassLoader* arg0);
    void setDaemon(bool arg0);
    static void setDefaultUncaughtExceptionHandler(Thread_UncaughtExceptionHandler* arg0);
    void setName(String* arg0);
    /*void setNativeName(String* arg0); (private) */
    void setPriority(int32_t arg0);
    /*void setPriority0(int32_t arg0); (private) */
    virtual void setUncaughtExceptionHandler(Thread_UncaughtExceptionHandler* arg0);
    static void sleep(int64_t arg0);
    static void sleep(int64_t arg0, int32_t arg1);
    virtual void start();
    /*void start0(); (private) */
    void stop();
    void stop(Throwable* arg0);
    /*void stop0(Object* arg0); (private) */
    void suspend();
    /*void suspend0(); (private) */
    String* toString() override;
    static void yield();

    // Generated
    Thread();
    Thread(Runnable* arg0);
    Thread(String* arg0);

public: /* package */
    Thread(Runnable* arg0, ::java::security::AccessControlContext* arg1);

public:
    Thread(ThreadGroup* arg0, Runnable* arg1);
    Thread(ThreadGroup* arg0, String* arg1);
    Thread(Runnable* arg0, String* arg1);
    Thread(ThreadGroup* arg0, Runnable* arg1, String* arg2);
    Thread(ThreadGroup* arg0, Runnable* arg1, String* arg2, int64_t arg3);
protected:
    Thread(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static StackTraceElementArray*& EMPTY_STACK_TRACE();
    static RuntimePermission*& SUBCLASS_IMPLEMENTATION_PERMISSION();
    static std::atomic< Thread_UncaughtExceptionHandler* >& defaultUncaughtExceptionHandler();
    static int32_t& threadInitNumber();
    static int64_t& threadSeqNumber();
    virtual ::java::lang::Class* getClass0();
};
