// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/annotation/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <sun/reflect/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/factory/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/Executable.hpp>
#include <sun/reflect/generics/repository/MethodRepository.hpp>

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
typedef ::SubArray< ::java::lang::reflect::TypeVariable, ::java::lang::ObjectArray, TypeArray, AnnotatedElementArray > TypeVariableArray;
        } // reflect

        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::AnnotationArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > AnnotationArrayArray;
        } // annotation
    } // lang
} // java

struct default_init_tag;

class java::lang::reflect::Method final
    : public Executable
{

public:
    typedef Executable super;

private:
    ::int8_tArray* annotationDefault {  };
    ::int8_tArray* annotations {  };
    ::java::lang::Class* clazz {  };
    ::java::lang::ClassArray* exceptionTypes {  };
    ::sun::reflect::generics::repository::MethodRepository* genericInfo {  };
    std::atomic< ::sun::reflect::MethodAccessor* > methodAccessor {  };
    int32_t modifiers {  };
    ::java::lang::String* name {  };
    ::int8_tArray* parameterAnnotations {  };
    ::java::lang::ClassArray* parameterTypes {  };
    ::java::lang::Class* returnType {  };
    Method* root {  };
    ::java::lang::String* signature {  };
    int32_t slot {  };

protected:
    void ctor(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10);
    /*::sun::reflect::MethodAccessor* acquireMethodAccessor(); (private) */

public: /* package */
    Method* copy();

public:
    bool equals(::java::lang::Object* arg0) override;
    AnnotatedType* getAnnotatedReturnType() override;
    ::java::lang::annotation::Annotation* getAnnotation(::java::lang::Class* arg0) override;

public: /* package */
    ::int8_tArray* getAnnotationBytes() override;

public:
    ::java::lang::annotation::AnnotationArray* getDeclaredAnnotations() override;
    ::java::lang::Class* getDeclaringClass() override;
    ::java::lang::Object* getDefaultValue();
    ::java::lang::ClassArray* getExceptionTypes() override;
    /*::sun::reflect::generics::factory::GenericsFactory* getFactory(); (private) */
    TypeArray* getGenericExceptionTypes() override;

public: /* package */
    ::sun::reflect::generics::repository::MethodRepository* getGenericInfo() override;

public:
    TypeArray* getGenericParameterTypes() override;
    Type* getGenericReturnType();
    /*::java::lang::String* getGenericSignature(); (private) */

public: /* package */
    ::sun::reflect::MethodAccessor* getMethodAccessor();

public:
    int32_t getModifiers() override;
    ::java::lang::String* getName() override;
    ::java::lang::annotation::AnnotationArrayArray* getParameterAnnotations() override;
    int32_t getParameterCount() override;
    ::java::lang::ClassArray* getParameterTypes() override;
    ::java::lang::Class* getReturnType();

public: /* package */
    Executable* getRoot() override;

public:
    TypeVariableArray* getTypeParameters() override;

public: /* package */
    void handleParameterNumberMismatch(int32_t arg0, int32_t arg1) override;
    bool hasGenericInformation() override;

public:
    int32_t hashCode() override;
    ::java::lang::Object* invoke(::java::lang::Object* arg0, ::java::lang::ObjectArray* arg1);
    bool isBridge();
    bool isDefault();
    bool isSynthetic() override;
    bool isVarArgs() override;

public: /* package */
    void setMethodAccessor(::sun::reflect::MethodAccessor* arg0);
    void specificToGenericStringHeader(::java::lang::StringBuilder* arg0) override;
    void specificToStringHeader(::java::lang::StringBuilder* arg0) override;

public:
    ::java::lang::String* toGenericString() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    Method(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10);
protected:
    Method(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
