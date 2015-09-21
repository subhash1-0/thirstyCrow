// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Random_RandomDoublesSpliterator.hpp>

#include <java/util/function/DoubleConsumer.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Random_RandomDoublesSpliterator::Random_RandomDoublesSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Random_RandomDoublesSpliterator::Random_RandomDoublesSpliterator(Random* arg0, int64_t arg1, int64_t arg2, double arg3, double arg4)
    : Random_RandomDoublesSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::util::Random_RandomDoublesSpliterator::ctor(Random* arg0, int64_t arg1, int64_t arg2, double arg3, double arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Random_RandomDoublesSpliterator::ctor(Random* arg0, int64_t arg1, int64_t arg2, double arg3, double arg4)");
}

int32_t java::util::Random_RandomDoublesSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::Random_RandomDoublesSpliterator::characteristics()");
    return 0;
}

int64_t java::util::Random_RandomDoublesSpliterator::estimateSize()
{ /* stub */
    unimplemented_(u"int64_t java::util::Random_RandomDoublesSpliterator::estimateSize()");
    return 0;
}

void java::util::Random_RandomDoublesSpliterator::forEachRemaining(::java::util::function::DoubleConsumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Random_RandomDoublesSpliterator::forEachRemaining(::java::util::function::DoubleConsumer* arg0)");
}

void java::util::Random_RandomDoublesSpliterator::forEachRemaining(::java::lang::Object* arg0)
{ 
    forEachRemaining(dynamic_cast< ::java::util::function::DoubleConsumer* >(arg0));
}

bool java::util::Random_RandomDoublesSpliterator::tryAdvance(::java::util::function::DoubleConsumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Random_RandomDoublesSpliterator::tryAdvance(::java::util::function::DoubleConsumer* arg0)");
    return 0;
}

bool java::util::Random_RandomDoublesSpliterator::tryAdvance(::java::lang::Object* arg0)
{ 
    return tryAdvance(dynamic_cast< ::java::util::function::DoubleConsumer* >(arg0));
}

java::util::Random_RandomDoublesSpliterator* java::util::Random_RandomDoublesSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::Random_RandomDoublesSpliterator* java::util::Random_RandomDoublesSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Random_RandomDoublesSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Random.RandomDoublesSpliterator", 41);
    return c;
}

void java::util::Random_RandomDoublesSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{
    super::forEachRemaining(arg0);
}

bool java::util::Random_RandomDoublesSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{
    return super::tryAdvance(arg0);
}

java::lang::Class* java::util::Random_RandomDoublesSpliterator::getClass0()
{
    return class_();
}

