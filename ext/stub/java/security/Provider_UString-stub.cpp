// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Provider_UString.hpp>

extern void unimplemented_(const char16_t* name);
java::security::Provider_UString::Provider_UString(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::Provider_UString::Provider_UString(::java::lang::String* arg0)
    : Provider_UString(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::security::Provider_UString::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Provider_UString::ctor(::java::lang::String* arg0)");
}

bool java::security::Provider_UString::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::Provider_UString::equals(::java::lang::Object* arg0)");
    return 0;
}

int32_t java::security::Provider_UString::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::security::Provider_UString::hashCode()");
    return 0;
}

java::lang::String* java::security::Provider_UString::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::Provider_UString::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Provider_UString::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Provider.UString", 30);
    return c;
}

java::lang::Class* java::security::Provider_UString::getClass0()
{
    return class_();
}

