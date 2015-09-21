// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/reflect/Method.hpp>

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

extern void unimplemented_(const char16_t* name);
java::lang::reflect::Method::Method(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::reflect::Method::Method(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10)
    : Method(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
}


void ::java::lang::reflect::Method::ctor(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::reflect::Method::ctor(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10)");
}

/* private: sun::reflect::MethodAccessor* java::lang::reflect::Method::acquireMethodAccessor() */
java::lang::reflect::Method* java::lang::reflect::Method::copy()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* java::lang::reflect::Method::copy()");
    return 0;
}

bool java::lang::reflect::Method::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Method::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::reflect::AnnotatedType* java::lang::reflect::Method::getAnnotatedReturnType()
{ /* stub */
    unimplemented_(u"java::lang::reflect::AnnotatedType* java::lang::reflect::Method::getAnnotatedReturnType()");
    return 0;
}

java::lang::annotation::Annotation* java::lang::reflect::Method::getAnnotation(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::Annotation* java::lang::reflect::Method::getAnnotation(::java::lang::Class* arg0)");
    return 0;
}

int8_tArray* java::lang::reflect::Method::getAnnotationBytes()
{ /* stub */
    unimplemented_(u"int8_tArray* java::lang::reflect::Method::getAnnotationBytes()");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::reflect::Method::getDeclaredAnnotations()
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::reflect::Method::getDeclaredAnnotations()");
    return 0;
}

java::lang::Class* java::lang::reflect::Method::getDeclaringClass()
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::reflect::Method::getDeclaringClass()");
    return 0;
}

java::lang::Object* java::lang::reflect::Method::getDefaultValue()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::reflect::Method::getDefaultValue()");
    return 0;
}

java::lang::ClassArray* java::lang::reflect::Method::getExceptionTypes()
{ /* stub */
return exceptionTypes ; /* getter */
}

/* private: sun::reflect::generics::factory::GenericsFactory* java::lang::reflect::Method::getFactory() */
java::lang::reflect::TypeArray* java::lang::reflect::Method::getGenericExceptionTypes()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeArray* java::lang::reflect::Method::getGenericExceptionTypes()");
    return 0;
}

sun::reflect::generics::repository::MethodRepository* java::lang::reflect::Method::getGenericInfo()
{ /* stub */
return genericInfo ; /* getter */
}

java::lang::reflect::TypeArray* java::lang::reflect::Method::getGenericParameterTypes()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeArray* java::lang::reflect::Method::getGenericParameterTypes()");
    return 0;
}

java::lang::reflect::Type* java::lang::reflect::Method::getGenericReturnType()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Type* java::lang::reflect::Method::getGenericReturnType()");
    return 0;
}

/* private: java::lang::String* java::lang::reflect::Method::getGenericSignature() */
sun::reflect::MethodAccessor* java::lang::reflect::Method::getMethodAccessor()
{ /* stub */
return methodAccessor ; /* getter */
}

int32_t java::lang::reflect::Method::getModifiers()
{ /* stub */
return modifiers ; /* getter */
}

java::lang::String* java::lang::reflect::Method::getName()
{ /* stub */
return name ; /* getter */
}

java::lang::annotation::AnnotationArrayArray* java::lang::reflect::Method::getParameterAnnotations()
{ /* stub */
}

int32_t java::lang::reflect::Method::getParameterCount()
{ /* stub */
    unimplemented_(u"int32_t java::lang::reflect::Method::getParameterCount()");
    return 0;
}

java::lang::ClassArray* java::lang::reflect::Method::getParameterTypes()
{ /* stub */
return parameterTypes ; /* getter */
}

java::lang::Class* java::lang::reflect::Method::getReturnType()
{ /* stub */
return returnType ; /* getter */
}

java::lang::reflect::Executable* java::lang::reflect::Method::getRoot()
{ /* stub */
}

java::lang::reflect::TypeVariableArray* java::lang::reflect::Method::getTypeParameters()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeVariableArray* java::lang::reflect::Method::getTypeParameters()");
    return 0;
}

void java::lang::reflect::Method::handleParameterNumberMismatch(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::Method::handleParameterNumberMismatch(int32_t arg0, int32_t arg1)");
}

bool java::lang::reflect::Method::hasGenericInformation()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Method::hasGenericInformation()");
    return 0;
}

int32_t java::lang::reflect::Method::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::lang::reflect::Method::hashCode()");
    return 0;
}

java::lang::Object* java::lang::reflect::Method::invoke(::java::lang::Object* arg0, ::java::lang::ObjectArray* arg1)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::reflect::Method::invoke(::java::lang::Object* arg0, ::java::lang::ObjectArray* arg1)");
    return 0;
}

bool java::lang::reflect::Method::isBridge()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Method::isBridge()");
    return 0;
}

bool java::lang::reflect::Method::isDefault()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Method::isDefault()");
    return 0;
}

bool java::lang::reflect::Method::isSynthetic()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Method::isSynthetic()");
    return 0;
}

bool java::lang::reflect::Method::isVarArgs()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Method::isVarArgs()");
    return 0;
}

void java::lang::reflect::Method::setMethodAccessor(::sun::reflect::MethodAccessor* arg0)
{ /* stub */
    this->methodAccessor = arg0; /* setter */
}

void java::lang::reflect::Method::specificToGenericStringHeader(::java::lang::StringBuilder* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::Method::specificToGenericStringHeader(::java::lang::StringBuilder* arg0)");
}

void java::lang::reflect::Method::specificToStringHeader(::java::lang::StringBuilder* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::Method::specificToStringHeader(::java::lang::StringBuilder* arg0)");
}

java::lang::String* java::lang::reflect::Method::toGenericString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::reflect::Method::toGenericString()");
    return 0;
}

java::lang::String* java::lang::reflect::Method::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::reflect::Method::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::reflect::Method::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.reflect.Method", 24);
    return c;
}

java::lang::Class* java::lang::reflect::Method::getClass0()
{
    return class_();
}

