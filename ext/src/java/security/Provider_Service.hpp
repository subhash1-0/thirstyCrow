// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
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

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

struct default_init_tag;

class java::security::Provider_Service
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::lang::ClassArray* CLASS0_;
    ::java::lang::String* algorithm {  };
    ::java::util::List* aliases {  };
    ::java::util::Map* attributes {  };
    ::java::lang::String* className {  };
    std::atomic< ::java::lang::ref::Reference* > classRef {  };
    std::atomic< ::java::lang::Boolean* > hasKeyAttributes_ {  };
    Provider* provider {  };
    bool registered {  };
    ::java::lang::ClassArray* supportedClasses {  };
    ::java::lang::StringArray* supportedFormats {  };
    ::java::lang::String* type {  };

    /*void ctor(Provider* arg0); (private) */
protected:
    void ctor(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::util::List* arg4, ::java::util::Map* arg5);
    /*void addAlias(::java::lang::String* arg0); (private) */

public: /* package */
    virtual void addAttribute(::java::lang::String* arg0, ::java::lang::String* arg1);

public:
    ::java::lang::String* getAlgorithm();
    /*::java::util::List* getAliases(); (private) */
    ::java::lang::String* getAttribute(::java::lang::String* arg0);
    ::java::lang::String* getClassName();
    /*::java::lang::Class* getImplClass(); (private) */
    /*::java::lang::Class* getKeyClass(::java::lang::String* arg0); (private) */
    Provider* getProvider();
    ::java::lang::String* getType();
    /*bool hasKeyAttributes(); (private) */
    /*bool isValid(); (private) */
    virtual ::java::lang::Object* newInstance(::java::lang::Object* arg0);
    /*::java::lang::Object* newInstanceGeneric(::java::lang::Object* arg0); (private) */
    /*bool supportsKeyClass(Key* arg0); (private) */
    /*bool supportsKeyFormat(Key* arg0); (private) */
    virtual bool supportsParameter(::java::lang::Object* arg0);
    ::java::lang::String* toString() override;

    // Generated
    Provider_Service(Provider* arg0, ::java::lang::String* arg1, ::java::lang::String* arg2, ::java::lang::String* arg3, ::java::util::List* arg4, ::java::util::Map* arg5);
protected:
    Provider_Service(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::lang::ClassArray*& CLASS0();
    virtual ::java::lang::Class* getClass0();
};
