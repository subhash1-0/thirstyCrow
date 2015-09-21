// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/IllegalAccessException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::IllegalAccessException::IllegalAccessException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::IllegalAccessException::IllegalAccessException()
    : IllegalAccessException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::IllegalAccessException::IllegalAccessException(String* arg0)
    : IllegalAccessException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::IllegalAccessException::serialVersionUID;

void ::java::lang::IllegalAccessException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::IllegalAccessException::ctor()");
}

void ::java::lang::IllegalAccessException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::IllegalAccessException::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::IllegalAccessException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.IllegalAccessException", 32);
    return c;
}

java::lang::Class* java::lang::IllegalAccessException::getClass0()
{
    return class_();
}

