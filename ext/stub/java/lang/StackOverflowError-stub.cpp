// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/StackOverflowError.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::StackOverflowError::StackOverflowError(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::StackOverflowError::StackOverflowError()
    : StackOverflowError(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::StackOverflowError::StackOverflowError(String* arg0)
    : StackOverflowError(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::StackOverflowError::serialVersionUID;

void ::java::lang::StackOverflowError::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::StackOverflowError::ctor()");
}

void ::java::lang::StackOverflowError::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::StackOverflowError::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::StackOverflowError::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.StackOverflowError", 28);
    return c;
}

java::lang::Class* java::lang::StackOverflowError::getClass0()
{
    return class_();
}

