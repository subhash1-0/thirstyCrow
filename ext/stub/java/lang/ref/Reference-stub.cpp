// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ref/Reference.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ref::Reference::Reference(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ref::Reference::Reference(::java::lang::Object* arg0)
    : Reference(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

java::lang::ref::Reference::Reference(::java::lang::Object* arg0, ReferenceQueue* arg1)
    : Reference(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

java::lang::ref::Reference_Lock*& java::lang::ref::Reference::lock()
{
    clinit();
    return lock_;
}
java::lang::ref::Reference_Lock* java::lang::ref::Reference::lock_;
java::lang::ref::Reference*& java::lang::ref::Reference::pending()
{
    clinit();
    return pending_;
}
java::lang::ref::Reference* java::lang::ref::Reference::pending_;

void ::java::lang::ref::Reference::ctor(::java::lang::Object* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::Reference::ctor(::java::lang::Object* arg0)");
}

void ::java::lang::ref::Reference::ctor(::java::lang::Object* arg0, ReferenceQueue* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::Reference::ctor(::java::lang::Object* arg0, ReferenceQueue* arg1)");
}

void java::lang::ref::Reference::clear()
{ /* stub */
    unimplemented_(u"void java::lang::ref::Reference::clear()");
}

bool java::lang::ref::Reference::enqueue()
{ /* stub */
    unimplemented_(u"bool java::lang::ref::Reference::enqueue()");
    return 0;
}

java::lang::Object* java::lang::ref::Reference::get()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::ref::Reference::get()");
    return 0;
}

bool java::lang::ref::Reference::isEnqueued()
{ /* stub */
    unimplemented_(u"bool java::lang::ref::Reference::isEnqueued()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ref::Reference::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ref.Reference", 23);
    return c;
}

java::lang::Class* java::lang::ref::Reference::getClass0()
{
    return class_();
}

