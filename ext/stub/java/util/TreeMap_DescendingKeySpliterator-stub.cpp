// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/TreeMap_DescendingKeySpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::TreeMap_DescendingKeySpliterator::TreeMap_DescendingKeySpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::TreeMap_DescendingKeySpliterator::TreeMap_DescendingKeySpliterator(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
    : TreeMap_DescendingKeySpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5);
}


void ::java::util::TreeMap_DescendingKeySpliterator::ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::TreeMap_DescendingKeySpliterator::ctor(TreeMap* arg0, TreeMap_Entry* arg1, TreeMap_Entry* arg2, int32_t arg3, int32_t arg4, int32_t arg5)");
}

int32_t java::util::TreeMap_DescendingKeySpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::TreeMap_DescendingKeySpliterator::characteristics()");
    return 0;
}

void java::util::TreeMap_DescendingKeySpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::TreeMap_DescendingKeySpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

bool java::util::TreeMap_DescendingKeySpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::TreeMap_DescendingKeySpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::TreeMap_DescendingKeySpliterator* java::util::TreeMap_DescendingKeySpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::TreeMap_DescendingKeySpliterator* java::util::TreeMap_DescendingKeySpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::TreeMap_DescendingKeySpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.TreeMap.DescendingKeySpliterator", 42);
    return c;
}

int64_t java::util::TreeMap_DescendingKeySpliterator::estimateSize()
{
    return TreeMap_TreeMapSpliterator::estimateSize();
}

java::lang::Class* java::util::TreeMap_DescendingKeySpliterator::getClass0()
{
    return class_();
}

