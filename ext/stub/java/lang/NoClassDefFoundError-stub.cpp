// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/NoClassDefFoundError.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::NoClassDefFoundError::NoClassDefFoundError(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::NoClassDefFoundError::NoClassDefFoundError()
    : NoClassDefFoundError(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::NoClassDefFoundError::NoClassDefFoundError(String* arg0)
    : NoClassDefFoundError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::NoClassDefFoundError::serialVersionUID;

void ::java::lang::NoClassDefFoundError::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::NoClassDefFoundError::ctor()");
}

void ::java::lang::NoClassDefFoundError::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::NoClassDefFoundError::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::NoClassDefFoundError::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.NoClassDefFoundError", 30);
    return c;
}

java::lang::Class* java::lang::NoClassDefFoundError::getClass0()
{
    return class_();
}

