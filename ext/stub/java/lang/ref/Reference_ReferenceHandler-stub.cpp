// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ref/Reference_ReferenceHandler.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ref::Reference_ReferenceHandler::Reference_ReferenceHandler(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ref::Reference_ReferenceHandler::Reference_ReferenceHandler(::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1)
    : Reference_ReferenceHandler(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::lang::ref::Reference_ReferenceHandler::ctor(::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ref::Reference_ReferenceHandler::ctor(::java::lang::ThreadGroup* arg0, ::java::lang::String* arg1)");
}

void java::lang::ref::Reference_ReferenceHandler::run()
{ /* stub */
    unimplemented_(u"void java::lang::ref::Reference_ReferenceHandler::run()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ref::Reference_ReferenceHandler::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ref.Reference.ReferenceHandler", 40);
    return c;
}

java::lang::Class* java::lang::ref::Reference_ReferenceHandler::getClass0()
{
    return class_();
}

