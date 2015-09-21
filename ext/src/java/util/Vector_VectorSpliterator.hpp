// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::Vector_VectorSpliterator final
    : public virtual ::java::lang::Object
    , public Spliterator
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::lang::ObjectArray* array {  };
    int32_t expectedModCount {  };
    int32_t fence {  };
    int32_t index {  };
    Vector* list {  };

protected:
    void ctor(Vector* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    /*int32_t getFence(); (private) */
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    Spliterator* trySplit() override;

    // Generated

public: /* package */
    Vector_VectorSpliterator(Vector* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3, int32_t arg4);
protected:
    Vector_VectorSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
