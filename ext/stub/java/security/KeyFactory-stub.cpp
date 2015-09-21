// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/KeyFactory.hpp>

extern void unimplemented_(const char16_t* name);
java::security::KeyFactory::KeyFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::KeyFactory::KeyFactory(KeyFactorySpi* arg0, Provider* arg1, ::java::lang::String* arg2)
    : KeyFactory(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}

sun::security::util::Debug*& java::security::KeyFactory::debug()
{
    clinit();
    return debug_;
}
sun::security::util::Debug* java::security::KeyFactory::debug_;

/* private: void ::java::security::KeyFactory::ctor(::java::lang::String* arg0) */
void ::java::security::KeyFactory::ctor(KeyFactorySpi* arg0, Provider* arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::KeyFactory::ctor(KeyFactorySpi* arg0, Provider* arg1, ::java::lang::String* arg2)");
}

java::security::PrivateKey* java::security::KeyFactory::generatePrivate(::java::security::spec::KeySpec* arg0)
{ /* stub */
    unimplemented_(u"java::security::PrivateKey* java::security::KeyFactory::generatePrivate(::java::security::spec::KeySpec* arg0)");
    return 0;
}

java::security::PublicKey* java::security::KeyFactory::generatePublic(::java::security::spec::KeySpec* arg0)
{ /* stub */
    unimplemented_(u"java::security::PublicKey* java::security::KeyFactory::generatePublic(::java::security::spec::KeySpec* arg0)");
    return 0;
}

java::lang::String* java::security::KeyFactory::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

java::security::KeyFactory* java::security::KeyFactory::getInstance(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyFactory* java::security::KeyFactory::getInstance(::java::lang::String* arg0)");
    return 0;
}

java::security::KeyFactory* java::security::KeyFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyFactory* java::security::KeyFactory::getInstance(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::security::KeyFactory* java::security::KeyFactory::getInstance(::java::lang::String* arg0, Provider* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::KeyFactory* java::security::KeyFactory::getInstance(::java::lang::String* arg0, Provider* arg1)");
    return 0;
}

java::security::spec::KeySpec* java::security::KeyFactory::getKeySpec(Key* arg0, ::java::lang::Class* arg1)
{ /* stub */
    unimplemented_(u"java::security::spec::KeySpec* java::security::KeyFactory::getKeySpec(Key* arg0, ::java::lang::Class* arg1)");
    return 0;
}

java::security::Provider* java::security::KeyFactory::getProvider()
{ /* stub */
return provider ; /* getter */
}

/* private: java::security::KeyFactorySpi* java::security::KeyFactory::nextSpi(KeyFactorySpi* arg0) */
java::security::Key* java::security::KeyFactory::translateKey(Key* arg0)
{ /* stub */
    unimplemented_(u"java::security::Key* java::security::KeyFactory::translateKey(Key* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::KeyFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.KeyFactory", 24);
    return c;
}

java::lang::Class* java::security::KeyFactory::getClass0()
{
    return class_();
}

