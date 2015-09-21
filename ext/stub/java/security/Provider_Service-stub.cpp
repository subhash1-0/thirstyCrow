// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Provider_Service.hpp>

extern void unimplemented_(const char16_t* name);
java::security::Provider_Service::Provider_Service(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::security::Provider_Service::Provider_Service(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::util::List* arg4, ::java::util::Map* arg5)
    : Provider_Service(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5);
}

java::lang::ClassArray*& java::security::Provider_Service::CLASS0()
{
    clinit();
    return CLASS0_;
}
java::lang::ClassArray* java::security::Provider_Service::CLASS0_;

/* private: void ::java::security::Provider_Service::ctor(Provider* arg0) */
void ::java::security::Provider_Service::ctor(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::util::List* arg4, ::java::util::Map* arg5)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::security::Provider_Service::ctor(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::util::List* arg4, ::java::util::Map* arg5)");
}

/* private: void java::security::Provider_Service::addAlias(::java::lang::String* arg0) */
void java::security::Provider_Service::addAttribute(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    unimplemented_(u"void java::security::Provider_Service::addAttribute(::java::lang::String* arg0, ::java::lang::String* arg1)");
}

java::lang::String* java::security::Provider_Service::getAlgorithm()
{ /* stub */
return algorithm ; /* getter */
}

/* private: java::util::List* java::security::Provider_Service::getAliases() */
java::lang::String* java::security::Provider_Service::getAttribute(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::Provider_Service::getAttribute(::java::lang::String* arg0)");
    return 0;
}

java::lang::String* java::security::Provider_Service::getClassName()
{ /* stub */
return className ; /* getter */
}

/* private: java::lang::Class* java::security::Provider_Service::getImplClass() */
/* private: java::lang::Class* java::security::Provider_Service::getKeyClass(::java::lang::String* arg0) */
java::security::Provider* java::security::Provider_Service::getProvider()
{ /* stub */
return provider ; /* getter */
}

java::lang::String* java::security::Provider_Service::getType()
{ /* stub */
return type ; /* getter */
}

/* private: bool java::security::Provider_Service::hasKeyAttributes() */
/* private: bool java::security::Provider_Service::isValid() */
java::lang::Object* java::security::Provider_Service::newInstance(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::security::Provider_Service::newInstance(::java::lang::Object* arg0)");
    return 0;
}

/* private: java::lang::Object* java::security::Provider_Service::newInstanceGeneric(::java::lang::Object* arg0) */
/* private: bool java::security::Provider_Service::supportsKeyClass(Key* arg0) */
/* private: bool java::security::Provider_Service::supportsKeyFormat(Key* arg0) */
bool java::security::Provider_Service::supportsParameter(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::security::Provider_Service::supportsParameter(::java::lang::Object* arg0)");
    return 0;
}

java::lang::String* java::security::Provider_Service::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::security::Provider_Service::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Provider_Service::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Provider.Service", 30);
    return c;
}

java::lang::Class* java::security::Provider_Service::getClass0()
{
    return class_();
}

