// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ref/WeakReference.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ref::WeakReference::WeakReference(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ref::WeakReference::WeakReference(::java::lang::Object* arg0)
    : WeakReference(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::ref::WeakReference::WeakReference(::java::lang::Object* arg0, ReferenceQueue* arg1)
    : WeakReference(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::lang::ref::WeakReference::ctor(::java::lang::Object* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::WeakReference::ctor(::java::lang::Object* arg0)");
}

void ::java::lang::ref::WeakReference::ctor(::java::lang::Object* arg0, ReferenceQueue* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::WeakReference::ctor(::java::lang::Object* arg0, ReferenceQueue* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ref::WeakReference::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ref.WeakReference", 27);
    return c;
}

java::lang::Class* java::lang::ref::WeakReference::getClass0()
{
    return class_();
}

