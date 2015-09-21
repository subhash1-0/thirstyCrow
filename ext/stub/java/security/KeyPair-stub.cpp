// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyPair.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyPair::KeyPair(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyPair::KeyPair(PublicKey* arg0, PrivateKey* arg1)
    : KeyPair(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}

constexpr int64_t java::security::KeyPair::serialVersionUID;

void ::java::security::KeyPair::ctor(PublicKey* arg0, PrivateKey* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyPair::ctor(PublicKey* arg0, PrivateKey* arg1)");
}

java::security::PrivateKey* java::security::KeyPair::getPrivate()
{ /* stub */
    unimplemented_(u"java::security::PrivateKey* java::security::KeyPair::getPrivate()");
    return 0;
}

java::security::PublicKey* java::security::KeyPair::getPublic()
{ /* stub */
    unimplemented_(u"java::security::PublicKey* java::security::KeyPair::getPublic()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyPair::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyPair", 21);
    return c;
}

java::lang::Class* java::security::KeyPair::getClass0()
{
    return class_();
}

