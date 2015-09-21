// Generated from /pastry-2.1/src/rice/environment/processing/simple/ProcessingThread.java

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class rice::environment::processing::simple::ProcessingThread
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;

public: /* package */
    ::java::util::concurrent::PriorityBlockingQueue* queue {  };
    std::atomic< bool > running {  };
protected:
    void ctor(::java::lang::String* name, ::java::util::concurrent::PriorityBlockingQueue* queue);

public:
    void run() override;
    void destroy() override;

    // Generated
    ProcessingThread(::java::lang::String* name, ::java::util::concurrent::PriorityBlockingQueue* queue);
protected:
    ProcessingThread(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
