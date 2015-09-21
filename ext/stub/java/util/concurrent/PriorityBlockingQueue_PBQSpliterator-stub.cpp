// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/concurrent/PriorityBlockingQueue_PBQSpliterator.hpp>

extern void unimplemented_(const char16_t* name);
java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::PriorityBlockingQueue_PBQSpliterator(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::PriorityBlockingQueue_PBQSpliterator(PriorityBlockingQueue* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3)
    : PriorityBlockingQueue_PBQSpliterator(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}


void ::java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::ctor(PriorityBlockingQueue* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::ctor(PriorityBlockingQueue* arg0, ::java::lang::ObjectArray* arg1, int32_t arg2, int32_t arg3)");
}

int32_t java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::characteristics()
{ /* stub */
    unimplemented_(u"int32_t java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::characteristics()");
    return 0;
}

int64_t java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::estimateSize()
{ /* stub */
    unimplemented_(u"int64_t java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::estimateSize()");
    return 0;
}

void java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"void java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::forEachRemaining(::java::util::function::Consumer* arg0)");
}

int32_t java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::getFence()
{ /* stub */
return fence ; /* getter */
}

bool java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::tryAdvance(::java::util::function::Consumer* arg0)
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::tryAdvance(::java::util::function::Consumer* arg0)");
    return 0;
}

java::util::Spliterator* java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::trySplit()
{ /* stub */
    unimplemented_(u"java::util::Spliterator* java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::trySplit()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.concurrent.PriorityBlockingQueue.PBQSpliterator", 57);
    return c;
}

java::lang::Class* java::util::concurrent::PriorityBlockingQueue_PBQSpliterator::getClass0()
{
    return class_();
}

