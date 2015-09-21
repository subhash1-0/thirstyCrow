// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/HashMap_HashMapSpliterator.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::HashMap_EntrySpliterator final
    : public HashMap_HashMapSpliterator
    , public Spliterator
{

public:
    typedef HashMap_HashMapSpliterator super;

protected:
    void ctor(HashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);

public:
    int32_t characteristics() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    HashMap_EntrySpliterator* trySplit() override;

    // Generated

public: /* package */
    HashMap_EntrySpliterator(HashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);
protected:
    HashMap_EntrySpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int64_t estimateSize();

private:
    virtual ::java::lang::Class* getClass0();
};
