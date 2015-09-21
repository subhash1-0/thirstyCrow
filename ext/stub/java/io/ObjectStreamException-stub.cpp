// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/io/ObjectStreamException.hpp>

extern void unimplemented_(const char16_t* name);
java::io::ObjectStreamException::ObjectStreamException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::io::ObjectStreamException::ObjectStreamException()
    : ObjectStreamException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::io::ObjectStreamException::ObjectStreamException(::java::lang::String* arg0)
    : ObjectStreamException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::io::ObjectStreamException::serialVersionUID;

void ::java::io::ObjectStreamException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectStreamException::ctor()");
}

void ::java::io::ObjectStreamException::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::io::ObjectStreamException::ctor(::java::lang::String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::io::ObjectStreamException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.io.ObjectStreamException", 29);
    return c;
}

java::lang::Class* java::io::ObjectStreamException::getClass0()
{
    return class_();
}

