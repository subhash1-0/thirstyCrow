// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/cert/Certificate.hpp>

extern void unimplemented_(const char16_t* name);
java::security::cert::Certificate::Certificate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::cert::Certificate::Certificate(::java::lang::String* arg0)
    : Certificate(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}

constexpr int64_t java::security::cert::Certificate::serialVersionUID;

void ::java::security::cert::Certificate::ctor(::java::lang::String* arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::cert::Certificate::ctor(::java::lang::String* arg0)");
}

bool java::security::cert::Certificate::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::cert::Certificate::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::String* java::security::cert::Certificate::getType()
{ /* stub */
return type ; /* getter */
}

int32_t java::security::cert::Certificate::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::security::cert::Certificate::hashCode()");
    return 0;
}

void java::security::cert::Certificate::verify(::java::security::PublicKey* arg0, ::java::security::Provider* arg1)
{ /* stub */
    unimplemented_(u"void java::security::cert::Certificate::verify(::java::security::PublicKey* arg0, ::java::security::Provider* arg1)");
}

java::lang::Object* java::security::cert::Certificate::writeReplace()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::cert::Certificate::writeReplace()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::cert::Certificate::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.cert.Certificate", 30);
    return c;
}

java::lang::Class* java::security::cert::Certificate::getClass0()
{
    return class_();
}

