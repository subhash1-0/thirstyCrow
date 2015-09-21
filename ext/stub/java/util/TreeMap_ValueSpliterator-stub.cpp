// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_ValueSpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_ValueSpliterator::TreeMap_ValueSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::TreeMap_ValueSpliterator::TreeMap_ValueSpliterator(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
    : TreeMap_ValueSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5);
}


void ::java::util::TreeMap_ValueSpliterator::ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::TreeMap_ValueSpliterator::ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)");
}

int32_t java::util::TreeMap_ValueSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::TreeMap_ValueSpliterator::characteristics()");
    return 0;
}

void java::util::TreeMap_ValueSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::TreeMap_ValueSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

bool java::util::TreeMap_ValueSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::TreeMap_ValueSpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::TreeMap_ValueSpliterator* java::util::TreeMap_ValueSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::TreeMap_ValueSpliterator* java::util::TreeMap_ValueSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_ValueSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.ValueSpliterator", 34);
    return c;
}

int64_t java::util::TreeMap_ValueSpliterator::estimateSize()
{
    return TreeMap_TreeMapSpliterator::estimateSize();
}

java::lang::Class* java::util::TreeMap_ValueSpliterator::getClass0()
{
    return class_();
}

