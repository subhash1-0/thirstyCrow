// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/InterruptedException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::InterruptedException::InterruptedException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::InterruptedException::InterruptedException()
    : InterruptedException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::InterruptedException::InterruptedException(String* arg0)
    : InterruptedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::InterruptedException::serialVersionUID;

void ::java::lang::InterruptedException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::InterruptedException::ctor()");
}

void ::java::lang::InterruptedException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::InterruptedException::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::InterruptedException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.InterruptedException", 30);
    return c;
}

java::lang::Class* java::lang::InterruptedException::getClass0()
{
    return class_();
}

