// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ClassCastException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ClassCastException::ClassCastException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ClassCastException::ClassCastException()
    : ClassCastException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::ClassCastException::ClassCastException(String* arg0)
    : ClassCastException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::ClassCastException::serialVersionUID;

void ::java::lang::ClassCastException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassCastException::ctor()");
}

void ::java::lang::ClassCastException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ClassCastException::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ClassCastException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ClassCastException", 28);
    return c;
}

java::lang::Class* java::lang::ClassCastException::getClass0()
{
    return class_();
}

