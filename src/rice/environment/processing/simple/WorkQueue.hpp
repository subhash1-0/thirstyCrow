// Generated from /pastry-2.1/src/rice/environment/processing/simple/WorkQueue.java

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::environment::processing::simple::WorkQueue
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::List* q {  };
    int32_t capacity {  };
    std::atomic< bool > running {  };
protected:
    void ctor();

public:
    virtual int32_t getLength();
protected:
    void ctor(int32_t capacity);

public:
    virtual void enqueue(::rice::environment::processing::WorkRequest* request);
    virtual ::rice::environment::processing::WorkRequest* dequeue();
    virtual void destroy();

    // Generated
    WorkQueue();
    WorkQueue(int32_t capacity);
protected:
    WorkQueue(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
