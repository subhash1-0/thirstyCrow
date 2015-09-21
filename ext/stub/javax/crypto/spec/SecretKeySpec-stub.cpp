// Generated from C:/Program Files/Java/jre1.8.0_51/lib/jce.jar
#include <javax/crypto/spec/SecretKeySpec.hpp>

extern void unimplemented_(const char16_t* name);
javax::crypto::spec::SecretKeySpec::SecretKeySpec(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

javax::crypto::spec::SecretKeySpec::SecretKeySpec(::int8_tArray* arg0, ::java::lang::String* arg1)
    : SecretKeySpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

javax::crypto::spec::SecretKeySpec::SecretKeySpec(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3)
    : SecretKeySpec(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3);
}

constexpr int64_t javax::crypto::spec::SecretKeySpec::serialVersionUID;

void ::javax::crypto::spec::SecretKeySpec::ctor(::int8_tArray* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::spec::SecretKeySpec::ctor(::int8_tArray* arg0, ::java::lang::String* arg1)");
}

void ::javax::crypto::spec::SecretKeySpec::ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::javax::crypto::spec::SecretKeySpec::ctor(::int8_tArray* arg0, int32_t arg1, int32_t arg2, ::java::lang::String* arg3)");
}

bool javax::crypto::spec::SecretKeySpec::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool javax::crypto::spec::SecretKeySpec::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::String* javax::crypto::spec::SecretKeySpec::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

int8_tArray* javax::crypto::spec::SecretKeySpec::getEncoded()
{ /* stub */
    unimplemented_(u"int8_tArray* javax::crypto::spec::SecretKeySpec::getEncoded()");
    return 0;
}

java::lang::String* javax::crypto::spec::SecretKeySpec::getFormat()
{ /* stub */
    unimplemented_(u"java::lang::String* javax::crypto::spec::SecretKeySpec::getFormat()");
    return 0;
}

int32_t javax::crypto::spec::SecretKeySpec::hashCode()
{ /* stub */
    unimplemented_(u"int32_t javax::crypto::spec::SecretKeySpec::hashCode()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* javax::crypto::spec::SecretKeySpec::class_()
{
    static ::java::lang::Class* c = ::class_(u"javax.crypto.spec.SecretKeySpec", 31);
    return c;
}

java::lang::Class* javax::crypto::spec::SecretKeySpec::getClass0()
{
    return class_();
}

