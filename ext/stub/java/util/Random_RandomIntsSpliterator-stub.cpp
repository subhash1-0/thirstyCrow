// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/Random_RandomIntsSpliterator.hpp>

#include <java/util/function/IntConsumer.hpp>

extern void unimplemented_(const char16_t* name);
java::util::Random_RandomIntsSpliterator::Random_RandomIntsSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Random_RandomIntsSpliterator::Random_RandomIntsSpliterator(Random* arg0, int64_t arg1, int64_t arg2, int32_t arg3, int32_t arg4)
    : Random_RandomIntsSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::util::Random_RandomIntsSpliterator::ctor(Random* arg0, int64_t arg1, int64_t arg2, int32_t arg3, int32_t arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::Random_RandomIntsSpliterator::ctor(Random* arg0, int64_t arg1, int64_t arg2, int32_t arg3, int32_t arg4)");
}

int32_t java::util::Random_RandomIntsSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::Random_RandomIntsSpliterator::characteristics()");
    return 0;
}

int64_t java::util::Random_RandomIntsSpliterator::estimateSize()
{ /* stub */
    unimplemented_(u"int64_t java::util::Random_RandomIntsSpliterator::estimateSize()");
    return 0;
}

void java::util::Random_RandomIntsSpliterator::forEachRemaining(::java::util::function::IntConsumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::Random_RandomIntsSpliterator::forEachRemaining(::java::util::function::IntConsumer* arg0)");
}

void java::util::Random_RandomIntsSpliterator::forEachRemaining(::java::lang::Object* arg0)
{ 
    forEachRemaining(dynamic_cast< ::java::util::function::IntConsumer* >(arg0));
}

bool java::util::Random_RandomIntsSpliterator::tryAdvance(::java::util::function::IntConsumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::Random_RandomIntsSpliterator::tryAdvance(::java::util::function::IntConsumer* arg0)");
    return 0;
}

bool java::util::Random_RandomIntsSpliterator::tryAdvance(::java::lang::Object* arg0)
{ 
    return tryAdvance(dynamic_cast< ::java::util::function::IntConsumer* >(arg0));
}

java::util::Random_RandomIntsSpliterator* java::util::Random_RandomIntsSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::Random_RandomIntsSpliterator* java::util::Random_RandomIntsSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::Random_RandomIntsSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.Random.RandomIntsSpliterator", 38);
    return c;
}

void java::util::Random_RandomIntsSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{
    super::forEachRemaining(arg0);
}

bool java::util::Random_RandomIntsSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{
    return super::tryAdvance(arg0);
}

java::lang::Class* java::util::Random_RandomIntsSpliterator::getClass0()
{
    return class_();
}

