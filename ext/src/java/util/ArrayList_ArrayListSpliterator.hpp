// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::ArrayList_ArrayListSpliterator final
    : public virtual ::java::lang::Object
    , public Spliterator
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t expectedModCount {  };
    int32_t fence {  };
    int32_t index {  };
    ArrayList* list {  };

protected:
    void ctor(ArrayList* arg0, int32_t arg1, int32_t arg2, int32_t arg3);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    /*int32_t getFence(); (private) */
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    ArrayList_ArrayListSpliterator* trySplit() override;

    // Generated

public: /* package */
    ArrayList_ArrayListSpliterator(ArrayList* arg0, int32_t arg1, int32_t arg2, int32_t arg3);
protected:
    ArrayList_ArrayListSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
