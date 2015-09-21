// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class java::util::concurrent::PriorityBlockingQueue_Itr final
    : public virtual ::java::lang::Object
    , public ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::ObjectArray* array {  };
    int32_t cursor {  };
    int32_t lastRet {  };
    PriorityBlockingQueue* this$0 {  };

protected:
    void ctor(::java::lang::ObjectArray* arg0);

public:
    bool hasNext() override;
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated

public: /* package */
    PriorityBlockingQueue_Itr(PriorityBlockingQueue *PriorityBlockingQueue_this, ::java::lang::ObjectArray* arg0);
protected:
    PriorityBlockingQueue_Itr(PriorityBlockingQueue *PriorityBlockingQueue_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PriorityBlockingQueue *PriorityBlockingQueue_this;

private:
    virtual ::java::lang::Class* getClass0();
};
