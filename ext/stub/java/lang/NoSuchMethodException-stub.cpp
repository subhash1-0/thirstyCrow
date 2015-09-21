// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/NoSuchMethodException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::NoSuchMethodException::NoSuchMethodException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::NoSuchMethodException::NoSuchMethodException()
    : NoSuchMethodException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::NoSuchMethodException::NoSuchMethodException(String* arg0)
    : NoSuchMethodException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::NoSuchMethodException::serialVersionUID;

void ::java::lang::NoSuchMethodException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::NoSuchMethodException::ctor()");
}

void ::java::lang::NoSuchMethodException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::NoSuchMethodException::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::NoSuchMethodException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.NoSuchMethodException", 31);
    return c;
}

java::lang::Class* java::lang::NoSuchMethodException::getClass0()
{
    return class_();
}

