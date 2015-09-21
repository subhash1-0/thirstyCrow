// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/CloneNotSupportedException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::CloneNotSupportedException::CloneNotSupportedException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::CloneNotSupportedException::CloneNotSupportedException()
    : CloneNotSupportedException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::CloneNotSupportedException::CloneNotSupportedException(String* arg0)
    : CloneNotSupportedException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::CloneNotSupportedException::serialVersionUID;

void ::java::lang::CloneNotSupportedException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::CloneNotSupportedException::ctor()");
}

void ::java::lang::CloneNotSupportedException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::CloneNotSupportedException::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::CloneNotSupportedException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.CloneNotSupportedException", 36);
    return c;
}

java::lang::Class* java::lang::CloneNotSupportedException::getClass0()
{
    return class_();
}

