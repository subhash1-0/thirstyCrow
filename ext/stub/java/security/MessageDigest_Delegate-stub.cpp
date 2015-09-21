// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/MessageDigest_Delegate.hpp>

extern void unimplemented_(const char16_t* name);
java::security::MessageDigest_Delegate::MessageDigest_Delegate(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::MessageDigest_Delegate::MessageDigest_Delegate(MessageDigestSpi* arg0, ::java::lang::String* arg1)
    : MessageDigest_Delegate(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::java::security::MessageDigest_Delegate::ctor(MessageDigestSpi* arg0, ::java::lang::String* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::MessageDigest_Delegate::ctor(MessageDigestSpi* arg0, ::java::lang::String* arg1)");
}

java::lang::Object* java::security::MessageDigest_Delegate::clone()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::MessageDigest_Delegate::clone()");
    return 0;
}

int8_tArray* java::security::MessageDigest_Delegate::engineDigest()
{ /* stub */
    unimplemented_(u"int8_tArray* java::security::MessageDigest_Delegate::engineDigest()");
    return 0;
}

int32_t java::security::MessageDigest_Delegate::engineDigest(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"int32_t java::security::MessageDigest_Delegate::engineDigest(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
    return 0;
}

int32_t java::security::MessageDigest_Delegate::engineGetDigestLength()
{ /* stub */
    unimplemented_(u"int32_t java::security::MessageDigest_Delegate::engineGetDigestLength()");
    return 0;
}

void java::security::MessageDigest_Delegate::engineReset()
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest_Delegate::engineReset()");
}

void java::security::MessageDigest_Delegate::engineUpdate(int8_t arg0)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest_Delegate::engineUpdate(int8_t arg0)");
}

void java::security::MessageDigest_Delegate::engineUpdate(::java::nio::ByteBuffer* arg0)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest_Delegate::engineUpdate(::java::nio::ByteBuffer* arg0)");
}

void java::security::MessageDigest_Delegate::engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2)
{ /* stub */
    unimplemented_(u"void java::security::MessageDigest_Delegate::engineUpdate(::int8_tArray* arg0, int32_t arg1, int32_t arg2)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::MessageDigest_Delegate::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.MessageDigest.Delegate", 36);
    return c;
}

java::lang::Class* java::security::MessageDigest_Delegate::getClass0()
{
    return class_();
}

