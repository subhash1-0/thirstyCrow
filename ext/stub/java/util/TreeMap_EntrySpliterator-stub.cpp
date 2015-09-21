// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_EntrySpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_EntrySpliterator::TreeMap_EntrySpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::TreeMap_EntrySpliterator::TreeMap_EntrySpliterator(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
    : TreeMap_EntrySpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5);
}


void ::java::util::TreeMap_EntrySpliterator::ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::TreeMap_EntrySpliterator::ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)");
}

int32_t java::util::TreeMap_EntrySpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::TreeMap_EntrySpliterator::characteristics()");
    return 0;
}

void java::util::TreeMap_EntrySpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::TreeMap_EntrySpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

java::util::Comparator* java::util::TreeMap_EntrySpliterator::getComparator()
{ /* stub */
    unimplemented_(u"java::util::Comparator* java::util::TreeMap_EntrySpliterator::getComparator()");
    return 0;
}

bool java::util::TreeMap_EntrySpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::TreeMap_EntrySpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::TreeMap_EntrySpliterator* java::util::TreeMap_EntrySpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::TreeMap_EntrySpliterator* java::util::TreeMap_EntrySpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_EntrySpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.EntrySpliterator", 34);
    return c;
}

int64_t java::util::TreeMap_EntrySpliterator::estimateSize()
{
    return TreeMap_TreeMapSpliterator::estimateSize();
}

java::lang::Class* java::util::TreeMap_EntrySpliterator::getClass0()
{
    return class_();
}

