// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/concurrent/PriorityBlockingQueue_Itr.hpp>

#include <java/util/concurrent/PriorityBlockingQueue.hpp>

extern void unimplemented_(const char16_t* name);
java::util::concurrent::PriorityBlockingQueue_Itr::PriorityBlockingQueue_Itr(PriorityBlockingQueue *PriorityBlockingQueue_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityBlockingQueue_this(PriorityBlockingQueue_this)
{
    clinit();
}

java::util::concurrent::PriorityBlockingQueue_Itr::PriorityBlockingQueue_Itr(PriorityBlockingQueue *PriorityBlockingQueue_this, ::java::lang::ObjectArray* arg0)
    : PriorityBlockingQueue_Itr(PriorityBlockingQueue_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::util::concurrent::PriorityBlockingQueue_Itr::ctor(::java::lang::ObjectArray* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::util::concurrent::PriorityBlockingQueue_Itr::ctor(::java::lang::ObjectArray* arg0)");
}

bool java::util::concurrent::PriorityBlockingQueue_Itr::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::concurrent::PriorityBlockingQueue_Itr::hasNext()");
    return 0;
}

java::lang::Object* java::util::concurrent::PriorityBlockingQueue_Itr::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::concurrent::PriorityBlockingQueue_Itr::next()");
    return 0;
}

void java::util::concurrent::PriorityBlockingQueue_Itr::remove()
{ /* stub */
    unimplemented_(u"void java::util::concurrent::PriorityBlockingQueue_Itr::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::concurrent::PriorityBlockingQueue_Itr::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.concurrent.PriorityBlockingQueue.Itr", 46);
    return c;
}

java::lang::Class* java::util::concurrent::PriorityBlockingQueue_Itr::getClass0()
{
    return class_();
}

