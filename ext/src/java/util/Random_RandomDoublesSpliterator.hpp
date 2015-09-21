// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <java/util/function/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Spliterator_OfDouble.hpp>

struct default_init_tag;

class java::util::Random_RandomDoublesSpliterator final
    : public virtual ::java::lang::Object
    , public Spliterator_OfDouble
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    double bound {  };
    int64_t fence {  };
    int64_t index {  };
    double origin {  };
    Random* rng {  };

protected:
    void ctor(Random* arg0, int64_t arg1, int64_t arg2, double arg3, double arg4);

public:
    int32_t characteristics() override;
    int64_t estimateSize() override;
    void forEachRemaining(::java::util::function::DoubleConsumer* arg0) override;
    bool tryAdvance(::java::util::function::DoubleConsumer* arg0) override;
    Random_RandomDoublesSpliterator* trySplit() override;

    // Generated

public: /* package */
    Random_RandomDoublesSpliterator(Random* arg0, int64_t arg1, int64_t arg2, double arg3, double arg4);
protected:
    Random_RandomDoublesSpliterator(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual void forEachRemaining(::java::lang::Object* arg0) override;
    virtual bool tryAdvance(::java::lang::Object* arg0) override;
    void forEachRemaining(::java::util::function::Consumer* arg0);
    bool tryAdvance(::java::util::function::Consumer* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
