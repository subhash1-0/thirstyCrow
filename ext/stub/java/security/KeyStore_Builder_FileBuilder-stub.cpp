// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyStore_Builder_FileBuilder.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyStore_Builder_FileBuilder::KeyStore_Builder_FileBuilder(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyStore_Builder_FileBuilder::KeyStore_Builder_FileBuilder(::java::lang::String* arg0, Provider* arg1, ::java::io::File* arg2, KeyStore_ProtectionParameter* arg3, AccessControlContext* arg4)
    : KeyStore_Builder_FileBuilder(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4);
}


void ::java::security::KeyStore_Builder_FileBuilder::ctor(::java::lang::String* arg0, Provider* arg1, ::java::io::File* arg2, KeyStore_ProtectionParameter* arg3, AccessControlContext* arg4)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyStore_Builder_FileBuilder::ctor(::java::lang::String* arg0, Provider* arg1, ::java::io::File* arg2, KeyStore_ProtectionParameter* arg3, AccessControlContext* arg4)");
}

java::security::KeyStore* java::security::KeyStore_Builder_FileBuilder::getKeyStore()
{ /* stub */
return keyStore ; /* getter */
}

java::security::KeyStore_ProtectionParameter* java::security::KeyStore_Builder_FileBuilder::getProtectionParameter(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::security::KeyStore_ProtectionParameter* java::security::KeyStore_Builder_FileBuilder::getProtectionParameter(::java::lang::String* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyStore_Builder_FileBuilder::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyStore.Builder.FileBuilder", 42);
    return c;
}

java::lang::Class* java::security::KeyStore_Builder_FileBuilder::getClass0()
{
    return class_();
}

