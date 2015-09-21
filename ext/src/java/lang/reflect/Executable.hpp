// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/annotation/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/AccessibleObject.hpp>
#include <java/lang/reflect/Member.hpp>
#include <java/lang/reflect/GenericDeclaration.hpp>

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
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;

        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::Annotation, ::java::lang::ObjectArray > AnnotationArray;
        } // annotation

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedType, ::java::lang::ObjectArray, AnnotatedElementArray > AnnotatedTypeArray;
typedef ::SubArray< ::java::lang::reflect::Parameter, ::java::lang::ObjectArray, AnnotatedElementArray > ParameterArray;
typedef ::SubArray< ::java::lang::reflect::TypeVariable, ::java::lang::ObjectArray, TypeArray, AnnotatedElementArray > TypeVariableArray;
        } // reflect

        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::AnnotationArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > AnnotationArrayArray;
        } // annotation
    } // lang
} // java

struct default_init_tag;

class java::lang::reflect::Executable
    : public AccessibleObject
    , public virtual Member
    , public virtual GenericDeclaration
{

public:
    typedef AccessibleObject super;

private:
    ::java::util::Map* declaredAnnotations_ {  };
    std::atomic< bool > hasRealParameterData_ {  };
    std::atomic< ParameterArray* > parameters {  };

protected:
    void ctor();
    /*::java::util::Map* declaredAnnotations(); (private) */

public: /* package */
    virtual bool equalParamTypes(::java::lang::ClassArray* arg0, ::java::lang::ClassArray* arg1);
    virtual TypeArray* getAllGenericParameterTypes();

public:
    virtual AnnotatedTypeArray* getAnnotatedExceptionTypes();
    virtual AnnotatedTypeArray* getAnnotatedParameterTypes();
    virtual AnnotatedType* getAnnotatedReceiverType();
    virtual AnnotatedType* getAnnotatedReturnType() = 0;

public: /* package */
    virtual AnnotatedType* getAnnotatedReturnType0(Type* arg0);

public:
    ::java::lang::annotation::Annotation* getAnnotation(::java::lang::Class* arg0) override;

public: /* package */
    virtual ::int8_tArray* getAnnotationBytes() = 0;

public:
    ::java::lang::annotation::AnnotationArray* getAnnotationsByType(::java::lang::Class* arg0) override;
    ::java::lang::annotation::AnnotationArray* getDeclaredAnnotations() override;
    /*::java::lang::Class* getDeclaringClass(); (already declared) */
    virtual ::java::lang::ClassArray* getExceptionTypes() = 0;
    virtual TypeArray* getGenericExceptionTypes();

public: /* package */
    virtual ::sun::reflect::generics::repository::ConstructorRepository* getGenericInfo() = 0;

public:
    virtual TypeArray* getGenericParameterTypes();
    /*int32_t getModifiers(); (already declared) */
    /*::java::lang::String* getName(); (already declared) */
    virtual ::java::lang::annotation::AnnotationArrayArray* getParameterAnnotations() = 0;
    virtual int32_t getParameterCount();
    virtual ::java::lang::ClassArray* getParameterTypes() = 0;
    virtual ParameterArray* getParameters();
    /*ParameterArray* getParameters0(); (private) */

public: /* package */
    virtual Executable* getRoot() = 0;
    virtual ::int8_tArray* getTypeAnnotationBytes();
    virtual ::int8_tArray* getTypeAnnotationBytes0();
    /*TypeVariableArray* getTypeParameters(); (already declared) */
    virtual void handleParameterNumberMismatch(int32_t arg0, int32_t arg1) = 0;
    virtual bool hasGenericInformation() = 0;
    virtual bool hasRealParameterData();

public:
    bool isSynthetic() override;
    virtual bool isVarArgs();

public: /* package */
    virtual ::java::lang::annotation::AnnotationArrayArray* parseParameterAnnotations(::int8_tArray* arg0);
    virtual void printModifiersIfNonzero(::java::lang::StringBuilder* arg0, int32_t arg1, bool arg2);
    /*ParameterArray* privateGetParameters(); (private) */
    virtual void separateWithCommas(::java::lang::ClassArray* arg0, ::java::lang::StringBuilder* arg1);
    virtual ::java::lang::annotation::AnnotationArrayArray* sharedGetParameterAnnotations(::java::lang::ClassArray* arg0, ::int8_tArray* arg1);
    virtual ::java::lang::String* sharedToGenericString(int32_t arg0, bool arg1);
    virtual ::java::lang::String* sharedToString(int32_t arg0, bool arg1, ::java::lang::ClassArray* arg2, ::java::lang::ClassArray* arg3);
    virtual void specificToGenericStringHeader(::java::lang::StringBuilder* arg0) = 0;
    virtual void specificToStringHeader(::java::lang::StringBuilder* arg0) = 0;
    /*ParameterArray* synthesizeAllParams(); (private) */

public:
    virtual ::java::lang::String* toGenericString() = 0;
    /*void verifyParameters(ParameterArray* arg0); (private) */

    // Generated

public: /* package */
    Executable();
protected:
    Executable(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::lang::annotation::AnnotationArray* getAnnotations();
    virtual ::java::lang::annotation::Annotation* getDeclaredAnnotation(::java::lang::Class* arg0);
    virtual ::java::lang::annotation::AnnotationArray* getDeclaredAnnotationsByType(::java::lang::Class* arg0);
    virtual bool isAnnotationPresent(::java::lang::Class* arg0);

private:
    virtual ::java::lang::Class* getClass0();
};
