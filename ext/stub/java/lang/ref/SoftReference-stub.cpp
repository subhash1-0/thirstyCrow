// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ref/SoftReference.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ref::SoftReference::SoftReference(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ref::SoftReference::SoftReference(::java::lang::Object* arg0)
    : SoftReference(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::ref::SoftReference::SoftReference(::java::lang::Object* arg0, ReferenceQueue* arg1)
    : SoftReference(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

int64_t& java::lang::ref::SoftReference::clock()
{
    clinit();
    return clock_;
}
int64_t java::lang::ref::SoftReference::clock_;

void ::java::lang::ref::SoftReference::ctor(::java::lang::Object* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::SoftReference::ctor(::java::lang::Object* arg0)");
}

void ::java::lang::ref::SoftReference::ctor(::java::lang::Object* arg0, ReferenceQueue* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::SoftReference::ctor(::java::lang::Object* arg0, ReferenceQueue* arg1)");
}

java::lang::Object* java::lang::ref::SoftReference::get()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::ref::SoftReference::get()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ref::SoftReference::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ref.SoftReference", 27);
    return c;
}

java::lang::Class* java::lang::ref::SoftReference::getClass0()
{
    return class_();
}

