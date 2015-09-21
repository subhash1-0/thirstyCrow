// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/HashMap_ValueSpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::HashMap_ValueSpliterator::HashMap_ValueSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::HashMap_ValueSpliterator::HashMap_ValueSpliterator(HashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)
    : HashMap_ValueSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::util::HashMap_ValueSpliterator::ctor(HashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::HashMap_ValueSpliterator::ctor(HashMap* arg0, int32_t arg1, int32_t arg2, int32_t arg3, int32_t arg4)");
}

int32_t java::util::HashMap_ValueSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::HashMap_ValueSpliterator::characteristics()");
    return 0;
}

void java::util::HashMap_ValueSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::HashMap_ValueSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

bool java::util::HashMap_ValueSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::HashMap_ValueSpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::HashMap_ValueSpliterator* java::util::HashMap_ValueSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::HashMap_ValueSpliterator* java::util::HashMap_ValueSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::HashMap_ValueSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.HashMap.ValueSpliterator", 34);
    return c;
}

int64_t java::util::HashMap_ValueSpliterator::estimateSize()
{
    return HashMap_HashMapSpliterator::estimateSize();
}

java::lang::Class* java::util::HashMap_ValueSpliterator::getClass0()
{
    return class_();
}

