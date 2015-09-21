// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator_OfLong.hpp>

struct default_init_tag;

class java::util::Random_RandomLongsSpliterator final
    : public virtual ::java::lang::Object
    , public Spliterator_OfLong
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int64_t bound {  };
    int64_t fence {  };
    int64_t index {  };
    int64_t origin {  };
    Random* rng {  };

protected:
    void ctor(Random* arg0, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::LongConsumer* arg0) override;
    bool tryAdvance(::java::util::function::LongConsumer* arg0) override;
    Random_RandomLongsSpliterator* trySplit() override;

    // Generated

public: /* package */
    Random_RandomLongsSpliterator(Random* arg0, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4);
protected:
    Random_RandomLongsSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEachRemaining(::java::lang::Object* arg0) override;
    virtual bool tryAdvance(::java::lang::Object* arg0) override;
    void forEachRemaining(::java::util::function::Consumer* arg0);
    bool tryAdvance(::java::util::function::Consumer* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
