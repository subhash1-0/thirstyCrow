// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/security/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class java::security::Security final
    : public ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::util::Properties* props_;
    static ::sun::security::util::Debug* sdebug_;
    static ::java::util::Map* spiMap_;

    /*void ctor(); (private) */

public:
    static int32_t addProvider(Provider* arg0);
    /*static void check(::java::lang::String* arg0); (private) */
    /*static void checkInsertProvider(::java::lang::String* arg0); (private) */
    static ::java::lang::String* getAlgorithmProperty(::java::lang::String* arg0, ::java::lang::String* arg1);
    static ::java::util::Set* getAlgorithms(::java::lang::String* arg0);
    /*static ::java::util::LinkedHashSet* getAllQualifyingCandidates(::java::lang::String* arg0, ::java::lang::String* arg1, ProviderArray* arg2); (private) */

public: /* package */
    static ::java::lang::StringArray* getFilterComponents(::java::lang::String* arg0, ::java::lang::String* arg1);
    static ::java::lang::ObjectArray* getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2);
    static ::java::lang::ObjectArray* getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, Provider* arg2);
    static ::java::lang::ObjectArray* getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::Object* arg3);
    static ::java::lang::ObjectArray* getImpl(::java::lang::String* arg0, ::java::lang::String* arg1, Provider* arg2, ::java::lang::Object* arg3);

public:
    static ::java::lang::String* getProperty(::java::lang::String* arg0);
    static Provider* getProvider(::java::lang::String* arg0);
    /*static Security_ProviderProperty* getProviderProperty(::java::lang::String* arg0); (private) */
    /*static ::java::lang::String* getProviderProperty(::java::lang::String* arg0, Provider* arg1); (private) */
    static ProviderArray* getProviders();
    static ProviderArray* getProviders(::java::lang::String* arg0);
    static ProviderArray* getProviders(::java::util::Map* arg0);
    /*static ::java::util::LinkedHashSet* getProvidersNotUsingCache(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ProviderArray* arg4); (private) */
    /*static ::java::lang::Class* getSpiClass(::java::lang::String* arg0); (private) */
    /*static void initialize(); (private) */
    /*static void initializeStatic(); (private) */
    static int32_t insertProviderAt(Provider* arg0, int32_t arg1);
    /*static void invalidateSMCache(::java::lang::String* arg0); (private) */
    /*static bool isConstraintSatisfied(::java::lang::String* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2); (private) */
    /*static bool isCriterionSatisfied(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::lang::String* arg4); (private) */
    /*static bool isStandardAttr(::java::lang::String* arg0); (private) */
    static void removeProvider(::java::lang::String* arg0);
    /*static ::java::io::File* securityPropFile(::java::lang::String* arg0); (private) */
    static void setProperty(::java::lang::String* arg0, ::java::lang::String* arg1);

    // Generated
    Security();
protected:
    Security(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::util::Properties*& props();
    static ::sun::security::util::Debug*& sdebug();
    static ::java::util::Map*& spiMap();
    virtual ::java::lang::Class* getClass0();
};
