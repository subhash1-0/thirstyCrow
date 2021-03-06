// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/concurrent/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::concurrent::PriorityBlockingQueue_PBQSpliterator final
    : public virtual ::java::lang::Object
    , public ::java::util::Spliterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::ObjectArray* array {  };
    int32_t fence {  };
    int32_t index {  };
    PriorityBlockingQueue* queue {  };

protected:
    void ctor(PriorityBlockingQueue* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;

public: /* package */
    int32_t getFence();

public:
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    ::java::util::Spliterator* trySplit() override;

    // Generated

public: /* package */
    PriorityBlockingQueue_PBQSpliterator(PriorityBlockingQueue* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3);
protected:
    PriorityBlockingQueue_PBQSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
