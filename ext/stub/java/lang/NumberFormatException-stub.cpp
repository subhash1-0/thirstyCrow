// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/NumberFormatException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::NumberFormatException::NumberFormatException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::NumberFormatException::NumberFormatException()
    : NumberFormatException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::NumberFormatException::NumberFormatException(String* arg0)
    : NumberFormatException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::NumberFormatException::serialVersionUID;

void ::java::lang::NumberFormatException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::NumberFormatException::ctor()");
}

void ::java::lang::NumberFormatException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::NumberFormatException::ctor(String* arg0)");
}

java::lang::NumberFormatException* java::lang::NumberFormatException::forInputString(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::NumberFormatException* java::lang::NumberFormatException::forInputString(String* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::NumberFormatException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.NumberFormatException", 31);
    return c;
}

java::lang::Class* java::lang::NumberFormatException::getClass0()
{
    return class_();
}

