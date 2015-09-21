// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/util/WeakHashMap_WeakHashMapSpliterator.hpp>
#include <java/util/Spliterator.hpp>

struct default_init_tag;

class java::util::WeakHashMap_ValueSpliterator final
    : public WeakHashMap_WeakHashMapSpliterator
    , public Spliterator
{

public:
    typedef WeakHashMap_WeakHashMapSpliterator super;

protected:
    void ctor(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);

public:
    int32_t characteristics() override;
    void forEachRemaining(::java::util::function::Consumer* arg0) override;
    bool tryAdvance(::java::util::function::Consumer* arg0) override;
    WeakHashMap_ValueSpliterator* trySplit() override;

    // Generated

public: /* package */
    WeakHashMap_ValueSpliterator(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4);
protected:
    WeakHashMap_ValueSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual int64_t estimateSize();

private:
    virtual ::java::lang::Class* getClass0();
};
