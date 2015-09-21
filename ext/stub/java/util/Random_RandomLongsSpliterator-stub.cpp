// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Random_RandomLongsSpliterator.hpp>

#include <java/util/function/LongConsumer.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Random_RandomLongsSpliterator::Random_RandomLongsSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Random_RandomLongsSpliterator::Random_RandomLongsSpliterator(Random* arg0, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
    : Random_RandomLongsSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::util::Random_RandomLongsSpliterator::ctor(Random* arg0, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Random_RandomLongsSpliterator::ctor(Random* arg0, int64_t arg1, int64_t arg2, int64_t arg3, int64_t arg4)");
}

int32_t java::util::Random_RandomLongsSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::Random_RandomLongsSpliterator::characteristics()");
    return 0;
}

int64_t java::util::Random_RandomLongsSpliterator::estimateSize()
{ /* stub */
    unimplemented_(u"int64_t java::util::Random_RandomLongsSpliterator::estimateSize()");
    return 0;
}

void java::util::Random_RandomLongsSpliterator::forEachRemaining(::java::util::function::LongConsumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Random_RandomLongsSpliterator::forEachRemaining(::java::util::function::LongConsumer* arg0)");
}

void java::util::Random_RandomLongsSpliterator::forEachRemaining(::java::lang::Object* arg0)
{ 
    forEachRemaining(dynamic_cast< ::java::util::function::LongConsumer* >(arg0));
}

bool java::util::Random_RandomLongsSpliterator::tryAdvance(::java::util::function::LongConsumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Random_RandomLongsSpliterator::tryAdvance(::java::util::function::LongConsumer* arg0)");
    return 0;
}

bool java::util::Random_RandomLongsSpliterator::tryAdvance(::java::lang::Object* arg0)
{ 
    return tryAdvance(dynamic_cast< ::java::util::function::LongConsumer* >(arg0));
}

java::util::Random_RandomLongsSpliterator* java::util::Random_RandomLongsSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::Random_RandomLongsSpliterator* java::util::Random_RandomLongsSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Random_RandomLongsSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Random.RandomLongsSpliterator", 39);
    return c;
}

void java::util::Random_RandomLongsSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{
    super::forEachRemaining(arg0);
}

bool java::util::Random_RandomLongsSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{
    return super::tryAdvance(arg0);
}

java::lang::Class* java::util::Random_RandomLongsSpliterator::getClass0()
{
    return class_();
}

