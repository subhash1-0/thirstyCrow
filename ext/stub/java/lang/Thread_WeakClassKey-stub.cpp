// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Thread_WeakClassKey.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::Thread_WeakClassKey::Thread_WeakClassKey(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Thread_WeakClassKey::Thread_WeakClassKey(Class* arg0, ::java::lang::ref::ReferenceQueue* arg1)
    : Thread_WeakClassKey(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::lang::Thread_WeakClassKey::ctor(Class* arg0, ::java::lang::ref::ReferenceQueue* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Thread_WeakClassKey::ctor(Class* arg0, ::java::lang::ref::ReferenceQueue* arg1)");
}

bool java::lang::Thread_WeakClassKey::equals(Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::Thread_WeakClassKey::equals(Object* arg0)");
    return 0;
}

int32_t java::lang::Thread_WeakClassKey::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Thread_WeakClassKey::hashCode()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Thread_WeakClassKey::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Thread.WeakClassKey", 29);
    return c;
}

java::lang::Class* java::lang::Thread_WeakClassKey::getClass0()
{
    return class_();
}

