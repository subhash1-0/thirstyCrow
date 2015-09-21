// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/util/PriorityQueue_Itr.hpp>

#include <java/util/PriorityQueue.hpp>

extern void unimplemented_(const char16_t* name);
java::util::PriorityQueue_Itr::PriorityQueue_Itr(PriorityQueue *PriorityQueue_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityQueue_this(PriorityQueue_this)
{
    clinit();
}


/* private: void ::java::util::PriorityQueue_Itr::ctor() */
bool java::util::PriorityQueue_Itr::hasNext()
{ /* stub */
    unimplemented_(u"bool java::util::PriorityQueue_Itr::hasNext()");
    return 0;
}

java::lang::Object* java::util::PriorityQueue_Itr::next()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::util::PriorityQueue_Itr::next()");
    return 0;
}

void java::util::PriorityQueue_Itr::remove()
{ /* stub */
    unimplemented_(u"void java::util::PriorityQueue_Itr::remove()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::util::PriorityQueue_Itr::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.util.PriorityQueue.Itr", 27);
    return c;
}

java::lang::Class* java::util::PriorityQueue_Itr::getClass0()
{
    return class_();
}

