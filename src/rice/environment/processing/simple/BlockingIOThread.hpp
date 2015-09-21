// Generated from /pastry-2.1/src/rice/environment/processing/simple/BlockingIOThread.java

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Thread.hpp>

struct default_init_tag;

class rice::environment::processing::simple::BlockingIOThread
    : public ::java::lang::Thread
{

public:
    typedef ::java::lang::Thread super;

public: /* package */
    WorkQueue* workQ {  };
    std::atomic< bool > running {  };
protected:
    void ctor(WorkQueue* workQ);

public:
    void run() override;
    void destroy() override;

    // Generated
    BlockingIOThread(WorkQueue* workQ);
protected:
    BlockingIOThread(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
