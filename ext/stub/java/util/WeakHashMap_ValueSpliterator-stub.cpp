// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/WeakHashMap_ValueSpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::WeakHashMap_ValueSpliterator::WeakHashMap_ValueSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::WeakHashMap_ValueSpliterator::WeakHashMap_ValueSpliterator(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)
    : WeakHashMap_ValueSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::util::WeakHashMap_ValueSpliterator::ctor(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::WeakHashMap_ValueSpliterator::ctor(WeakHashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)");
}

int32_t java::util::WeakHashMap_ValueSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::WeakHashMap_ValueSpliterator::characteristics()");
    return 0;
}

void java::util::WeakHashMap_ValueSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::WeakHashMap_ValueSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

bool java::util::WeakHashMap_ValueSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::WeakHashMap_ValueSpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::WeakHashMap_ValueSpliterator* java::util::WeakHashMap_ValueSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::WeakHashMap_ValueSpliterator* java::util::WeakHashMap_ValueSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::WeakHashMap_ValueSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.WeakHashMap.ValueSpliterator", 38);
    return c;
}

int64_t java::util::WeakHashMap_ValueSpliterator::estimateSize()
{
    return WeakHashMap_WeakHashMapSpliterator::estimateSize();
}

java::lang::Class* java::util::WeakHashMap_ValueSpliterator::getClass0()
{
    return class_();
}

