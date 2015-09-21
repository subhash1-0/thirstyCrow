// Generated from /pastry-2.1/src/rice/selector/SelectorManager.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/random/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/Destructable.hpp>

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

    namespace nio
    {
        namespace channels
        {
typedef ::SubArray< ::java::nio::channels::SelectionKey, ::java::lang::ObjectArray > SelectionKeyArray;
        } // channels
    } // nio
} // java

struct default_init_tag;

class rice::selector::SelectorManager
    : public ::java::lang::Thread
    , public virtual Timer
    , public virtual ::rice::Destructable
{

public:
    typedef ::java::lang::Thread super;

private:
    static int32_t TIMEOUT_;

public: /* protected */
    ::java::nio::channels::Selector* selector {  };
    ::java::util::LinkedList* invocations {  };
    ::java::util::HashSet* modifyKeys {  };
    ::java::util::HashSet* cancelledKeys {  };
    ::java::util::Queue* timerQueue {  };
    int64_t wakeupTime {  };
    ::rice::environment::time::TimeSource* timeSource {  };

public: /* package */
    int64_t lastTime {  };

public: /* protected */
    ::rice::environment::logging::Logger* logger {  };
    ::java::lang::String* instance {  };
    bool running {  };
    bool select_ {  };
    ::rice::environment::random::RandomSource* random {  };
protected:
    void ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* random);
    void ctor(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log);

public: /* protected */
    ::rice::environment::Environment* environment {  };

public:
    virtual void setEnvironment(::rice::environment::Environment* env);
    virtual void cancel(::java::nio::channels::SelectionKey* key);
    virtual ::java::nio::channels::SelectionKey* getKey(::java::nio::channels::SelectableChannel* channel);
    virtual ::java::nio::channels::SelectionKey* register_(::java::nio::channels::SelectableChannel* channel, SelectionKeyHandler* handler, int32_t ops) /* throws(IOException) */;
    virtual void invoke(::java::lang::Runnable* d);
    virtual int32_t getNumInvocations();
    virtual void modifyKey(::java::nio::channels::SelectionKey* key);

public: /* protected */
    virtual void onLoop();

public:
    void run() override;
    void destroy() override;

public: /* protected */
    bool useLoopListeners_ {  };

public:
    virtual void useLoopListeners(bool val);

public: /* protected */
    virtual void notifyLoopListeners();

public: /* package */
    ::java::util::ArrayList* loopObservers {  };

public:
    virtual void addLoopObserver(LoopObserver* lo);
    virtual void removeLoopObserver(LoopObserver* lo);

public: /* protected */
    virtual void doSelections() /* throws(IOException) */;
    virtual void doInvocations();
    virtual ::java::lang::Runnable* getInvocation();
    virtual ::java::nio::channels::SelectionKey* getModifyKey();
    virtual int32_t select(int32_t time) /* throws(IOException) */;
    virtual ::java::nio::channels::SelectionKeyArray* selectedKeys() /* throws(IOException) */;

public:
    virtual bool isSelectorThread();
    TimerTask* schedule(TimerTask* task) override;
    TimerTask* schedule(TimerTask* task, int64_t delay) override;
    TimerTask* schedule(TimerTask* task, int64_t delay, int64_t period) override;
    TimerTask* scheduleAtFixedRate(TimerTask* task, int64_t delay, int64_t period) override;

public: /* protected */
    ::java::lang::Object* seqLock {  };
    int32_t seqCtr {  };
    virtual void addTask(TimerTask* task);

public:
    virtual void removeTask(TimerTask* task);
    virtual void wakeup();
    virtual int64_t getNextTaskExecutionTime();

public: /* protected */
    virtual void executeDueTasks();
    virtual bool executeTask(TimerTask* next);

public:
    virtual Timer* getTimer();
    virtual ::java::nio::channels::Selector* getSelector();
    virtual void setSelect(bool b);
    virtual ::rice::environment::Environment* getEnvironment();
    virtual void setLogLevel(int32_t level);
    static void main(::java::lang::StringArray* args);

    // Generated
    SelectorManager(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log, ::rice::environment::random::RandomSource* random);
    SelectorManager(::java::lang::String* instance, ::rice::environment::time::TimeSource* timeSource, ::rice::environment::logging::LogManager* log);
protected:
    SelectorManager(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();

private:
    void init();

public:
    static int32_t& TIMEOUT();

private:
    virtual ::java::lang::Class* getClass0();
};
