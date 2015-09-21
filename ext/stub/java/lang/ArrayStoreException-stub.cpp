// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/ArrayStoreException.hpp>

extern void unimplemented_(const char16_t* name);
java::lang::ArrayStoreException::ArrayStoreException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::ArrayStoreException::ArrayStoreException()
    : ArrayStoreException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::ArrayStoreException::ArrayStoreException(String* arg0)
    : ArrayStoreException(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::lang::ArrayStoreException::serialVersionUID;

void ::java::lang::ArrayStoreException::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ArrayStoreException::ctor()");
}

void ::java::lang::ArrayStoreException::ctor(String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::ArrayStoreException::ctor(String* arg0)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::ArrayStoreException::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.ArrayStoreException", 29);
    return c;
}

java::lang::Class* java::lang::ArrayStoreException::getClass0()
{
    return class_();
}

