// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/InvalidObjectException.hpp>

extern void unimplemented_(const char16_t* name);
java::io::InvalidObjectException::InvalidObjectException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::InvalidObjectException::InvalidObjectException(::java::lang::String* arg0)
    : InvalidObjectException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::io::InvalidObjectException::serialVersionUID;

void ::java::io::InvalidObjectException::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::InvalidObjectException::ctor(::java::lang::String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::InvalidObjectException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.InvalidObjectException", 30);
    return c;
}

java::lang::Class* java::io::InvalidObjectException::getClass0()
{
    return class_();
}

