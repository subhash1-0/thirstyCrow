// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Thread_Caches.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Thread_Caches::Thread_Caches(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::concurrent::ConcurrentMap*& java::lang::Thread_Caches::subclassAudits()
{
    clinit();
    return subclassAudits_;
}
java::util::concurrent::ConcurrentMap* java::lang::Thread_Caches::subclassAudits_;
java::lang::ref::ReferenceQueue*& java::lang::Thread_Caches::subclassAuditsQueue()
{
    clinit();
    return subclassAuditsQueue_;
}
java::lang::ref::ReferenceQueue* java::lang::Thread_Caches::subclassAuditsQueue_;

/* private: void ::java::lang::Thread_Caches::ctor() */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Thread_Caches::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Thread.Caches", 23);
    return c;
}

java::lang::Class* java::lang::Thread_Caches::getClass0()
{
    return class_();
}

