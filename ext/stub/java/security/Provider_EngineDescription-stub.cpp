// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Provider_EngineDescription.hpp>

extern void unimplemented_(const char16_t* name);
java::security::Provider_EngineDescription::Provider_EngineDescription(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::Provider_EngineDescription::Provider_EngineDescription(::java::lang::String* arg0, bool arg1, ::java::lang::String* arg2)
    : Provider_EngineDescription(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2);
}


void ::java::security::Provider_EngineDescription::ctor(::java::lang::String* arg0, bool arg1, ::java::lang::String* arg2)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Provider_EngineDescription::ctor(::java::lang::String* arg0, bool arg1, ::java::lang::String* arg2)");
}

java::lang::Class* java::security::Provider_EngineDescription::getConstructorParameterClass()
{ /* stub */
return constructorParameterClass ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Provider_EngineDescription::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Provider.EngineDescription", 40);
    return c;
}

java::lang::Class* java::security::Provider_EngineDescription::getClass0()
{
    return class_();
}

