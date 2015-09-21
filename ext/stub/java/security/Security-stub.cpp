// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/security/Security.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace util
    {
typedef ::SubArray< ::java::util::Dictionary, ::java::lang::ObjectArray > DictionaryArray;
typedef ::SubArray< ::java::util::Map, ::java::lang::ObjectArray > MapArray;
typedef ::SubArray< ::java::util::Hashtable, DictionaryArray, MapArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > HashtableArray;
typedef ::SubArray< ::java::util::Properties, HashtableArray > PropertiesArray;
    } // util

    namespace security
    {
typedef ::SubArray< ::java::security::Provider, ::java::util::PropertiesArray > ProviderArray;
    } // security
} // java

extern void unimplemented_(const char16_t* name);
java::security::Security::Security(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::util::Properties*& java::security::Security::props()
{
    clinit();
    return props_;
}
java::util::Properties* java::security::Security::props_;
sun::security::util::Debug*& java::security::Security::sdebug()
{
    clinit();
    return sdebug_;
}
sun::security::util::Debug* java::security::Security::sdebug_;
java::util::Map*& java::security::Security::spiMap()
{
    clinit();
    return spiMap_;
}
java::util::Map* java::security::Security::spiMap_;

/* private: void ::java::security::Security::ctor() */
int32_t java::security::Security::addProvider(Provider* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::security::Security::addProvider(Provider* arg0)");
    return 0;
}

/* private: void java::security::Security::check(::java::lang::String* arg0) */
/* private: void java::security::Security::checkInsertProvider(::java::lang::String* arg0) */
java::lang::String* java::security::Security::getAlgorithmProperty(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::security::Security::getAlgorithmProperty(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::util::Set* java::security::Security::getAlgorithms(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::util::Set* java::security::Security::getAlgorithms(::java::lang::String* arg0)");
    return 0;
}

/* private: java::util::LinkedHashSet* java::security::Security::getAllQualifyingCandidates(::java::lang::String* arg0, ::java::lang::String* arg1, ProviderArray* arg2) */
java::lang::StringArray* java::security::Security::getFilterComponents(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::StringArray* java::security::Security::getFilterComponents(::java::lang::String* arg0, ::java::lang::String* arg1)");
    return 0;
}

java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2)");
    return 0;
}

java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, Provider* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, Provider* arg2)");
    return 0;
}

java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::Object* arg3)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::Object* arg3)");
    return 0;
}

java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, Provider* arg2, ::java::lang::Object* arg3)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::ObjectArray* java::security::Security::getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, Provider* arg2, ::java::lang::Object* arg3)");
    return 0;
}

java::lang::String* java::security::Security::getProperty(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::String* java::security::Security::getProperty(::java::lang::String* arg0)");
    return 0;
}

java::security::Provider* java::security::Security::getProvider(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::Provider* java::security::Security::getProvider(::java::lang::String* arg0)");
    return 0;
}

/* private: java::security::Security_ProviderProperty* java::security::Security::getProviderProperty(::java::lang::String* arg0) */
/* private: java::lang::String* java::security::Security::getProviderProperty(::java::lang::String* arg0, Provider* arg1) */
java::security::ProviderArray* java::security::Security::getProviders()
{ /* stub */
    clinit();
    unimplemented_(u"java::security::ProviderArray* java::security::Security::getProviders()");
    return 0;
}

java::security::ProviderArray* java::security::Security::getProviders(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::ProviderArray* java::security::Security::getProviders(::java::lang::String* arg0)");
    return 0;
}

java::security::ProviderArray* java::security::Security::getProviders(::java::util::Map* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::security::ProviderArray* java::security::Security::getProviders(::java::util::Map* arg0)");
    return 0;
}

/* private: java::util::LinkedHashSet* java::security::Security::getProvidersNotUsingCache(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ProviderArray* arg4) */
/* private: java::lang::Class* java::security::Security::getSpiClass(::java::lang::String* arg0) */
/* private: void java::security::Security::initialize() */
/* private: void java::security::Security::initializeStatic() */
int32_t java::security::Security::insertProviderAt(Provider* arg0, int32_t arg1)
{ /* stub */
    clinit();
    unimplemented_(u"int32_t java::security::Security::insertProviderAt(Provider* arg0, int32_t arg1)");
    return 0;
}

/* private: void java::security::Security::invalidateSMCache(::java::lang::String* arg0) */
/* private: bool java::security::Security::isConstraintSatisfied(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2) */
/* private: bool java::security::Security::isCriterionSatisfied(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::lang::String* arg4) */
/* private: bool java::security::Security::isStandardAttr(::java::lang::String* arg0) */
void java::security::Security::removeProvider(::java::lang::String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"void java::security::Security::removeProvider(::java::lang::String* arg0)");
}

/* private: java::io::File* java::security::Security::securityPropFile(::java::lang::String* arg0) */
void java::security::Security::setProperty(::java::lang::String* arg0, ::java::lang::String* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::security::Security::setProperty(::java::lang::String* arg0, ::java::lang::String* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::security::Security::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.security.Security", 22);
    return c;
}

java::lang::Class* java::security::Security::getClass0()
{
    return class_();
}

