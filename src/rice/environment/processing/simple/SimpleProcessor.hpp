// Generated from /pastry-2.1/src/rice/environment/processing/simple/SimpleProcessor.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <rice/environment/time/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/processing/Processor.hpp>

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

struct default_init_tag;

class rice::environment::processing::simple::SimpleProcessor
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::processing::Processor
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::concurrent::PriorityBlockingQueue* QUEUE {  };
    ProcessingThread* THREAD {  };
    WorkQueue* workQueue {  };
    BlockingIOThread* bioThread {  };

public: /* package */
    int64_t seq {  };
protected:
    void ctor(::java::lang::String* name);

public:
    /* <R, E extends Exception> */::rice::p2p::commonapi::Cancellable* process(::rice::Executable* task, ::rice::Continuation* command, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) override;
    /* <R, E extends Exception> */::rice::p2p::commonapi::Cancellable* process(::rice::Executable* task, ::rice::Continuation* command, int32_t priority, ::rice::selector::SelectorManager* selector, ::rice::environment::time::TimeSource* ts, ::rice::environment::logging::LogManager* log) override;
    ::rice::p2p::commonapi::Cancellable* processBlockingIO(::rice::environment::processing::WorkRequest* workRequest) override;
    virtual ::java::util::Queue* getQueue();
    void destroy() override;
    virtual WorkQueue* getIOQueue();
    static void main(::java::lang::StringArray* args) /* throws(Exception) */;

    // Generated
    SimpleProcessor(::java::lang::String* name);
protected:
    SimpleProcessor(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class SimpleProcessor_main_1;
    friend class SimpleProcessor_main_2;
    friend class SimpleProcessor_main_3;
    friend class SimpleProcessor_main_4;
};
