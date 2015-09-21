// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/LinkedList_LLSpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::LinkedList_LLSpliterator::LinkedList_LLSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::LinkedList_LLSpliterator::LinkedList_LLSpliterator(LinkedList* arg0, int32_t arg1, int32_t arg2)
    : LinkedList_LLSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

constexpr int32_t java::util::LinkedList_LLSpliterator::BATCH_UNIT;
constexpr int32_t java::util::LinkedList_LLSpliterator::MAX_BATCH;

void ::java::util::LinkedList_LLSpliterator::ctor(LinkedList* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::LinkedList_LLSpliterator::ctor(LinkedList* arg0, int32_t arg1, int32_t arg2)");
}

int32_t java::util::LinkedList_LLSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::LinkedList_LLSpliterator::characteristics()");
    return 0;
}

int64_t java::util::LinkedList_LLSpliterator::estimateSize()
{ /* stub */
    unimplemented_(u"int64_t java::util::LinkedList_LLSpliterator::estimateSize()");
    return 0;
}

void java::util::LinkedList_LLSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::LinkedList_LLSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

int32_t java::util::LinkedList_LLSpliterator::getEst()
{ /* stub */
return est ; /* getter */
}

bool java::util::LinkedList_LLSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::LinkedList_LLSpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::Spliterator* java::util::LinkedList_LLSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::Spliterator* java::util::LinkedList_LLSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::LinkedList_LLSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.LinkedList.LLSpliterator", 34);
    return c;
}

java::lang::Class* java::util::LinkedList_LLSpliterator::getClass0()
{
    return class_();
}

