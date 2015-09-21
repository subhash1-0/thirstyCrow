// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <sun/reflect/fwd-pastry-2.1.hpp>
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
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
    } // lang
} // java

struct default_init_tag;

class sun::reflect::ReflectionFactory
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static int32_t inflationThreshold__;
    static bool initted_;
    static std::atomic< LangReflectAccess* > langReflectAccess__;
    static bool noInflation_;
    static ::java::security::Permission* reflectionFactoryAccessPerm_;
    static ReflectionFactory* soleInstance_;

    /*void ctor(); (private) */
    /*static void checkInitted(); (private) */

public:
    virtual ::java::lang::reflect::Constructor* copyConstructor(::java::lang::reflect::Constructor* arg0);
    virtual ::java::lang::reflect::Field* copyField(::java::lang::reflect::Field* arg0);
    virtual ::java::lang::reflect::Method* copyMethod(::java::lang::reflect::Method* arg0);
    virtual ConstructorAccessor* getConstructorAccessor(::java::lang::reflect::Constructor* arg0);
    virtual ::int8_tArray* getExecutableTypeAnnotationBytes(::java::lang::reflect::Executable* arg0);
    virtual MethodAccessor* getMethodAccessor(::java::lang::reflect::Method* arg0);
    static ReflectionFactory* getReflectionFactory();

public: /* package */
    static int32_t inflationThreshold();
    /*static LangReflectAccess* langReflectAccess(); (private) */

public:
    virtual ::java::lang::reflect::Constructor* newConstructor(::java::lang::Class* arg0, ::java::lang::ClassArray* arg1, ::java::lang::ClassArray* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6, ::int8_tArray* arg7);
    virtual ConstructorAccessor* newConstructorAccessor(::java::lang::reflect::Constructor* arg0);
    virtual ::java::lang::reflect::Constructor* newConstructorForSerialization(::java::lang::Class* arg0, ::java::lang::reflect::Constructor* arg1);
    virtual ::java::lang::reflect::Field* newField(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::Class* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6);
    virtual FieldAccessor* newFieldAccessor(::java::lang::reflect::Field* arg0, bool arg1);
    virtual ::java::lang::reflect::Method* newMethod(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10);
    virtual MethodAccessor* newMethodAccessor(::java::lang::reflect::Method* arg0);
    virtual void setConstructorAccessor(::java::lang::reflect::Constructor* arg0, ConstructorAccessor* arg1);
    virtual void setLangReflectAccess(LangReflectAccess* arg0);
    virtual void setMethodAccessor(::java::lang::reflect::Method* arg0, MethodAccessor* arg1);

    // Generated
    ReflectionFactory();
protected:
    ReflectionFactory(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static int32_t& inflationThreshold_();
    static bool& initted();
    static std::atomic< LangReflectAccess* >& langReflectAccess_();
    static bool& noInflation();
    static ::java::security::Permission*& reflectionFactoryAccessPerm();
    static ReflectionFactory*& soleInstance();
    virtual ::java::lang::Class* getClass0();
};
