// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/reflect/Constructor.hpp>

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
java::lang::reflect::Constructor::Constructor(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::reflect::Constructor::Constructor(::java::lang::Class* arg0, ::java::lang::ClassArray* arg1, ::java::lang::ClassArray* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6, ::int8_tArray* arg7)
    : Constructor(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}


void ::java::lang::reflect::Constructor::ctor(::java::lang::Class* arg0, ::java::lang::ClassArray* arg1, ::java::lang::ClassArray* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6, ::int8_tArray* arg7)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::reflect::Constructor::ctor(::java::lang::Class* arg0, ::java::lang::ClassArray* arg1, ::java::lang::ClassArray* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6, ::int8_tArray* arg7)");
}

/* private: sun::reflect::ConstructorAccessor* java::lang::reflect::Constructor::acquireConstructorAccessor() */
java::lang::reflect::Constructor* java::lang::reflect::Constructor::copy()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* java::lang::reflect::Constructor::copy()");
    return 0;
}

bool java::lang::reflect::Constructor::equals(::java::lang::Object* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Constructor::equals(::java::lang::Object* arg0)");
    return 0;
}

java::lang::reflect::AnnotatedType* java::lang::reflect::Constructor::getAnnotatedReceiverType()
{ /* stub */
    unimplemented_(u"java::lang::reflect::AnnotatedType* java::lang::reflect::Constructor::getAnnotatedReceiverType()");
    return 0;
}

java::lang::reflect::AnnotatedType* java::lang::reflect::Constructor::getAnnotatedReturnType()
{ /* stub */
    unimplemented_(u"java::lang::reflect::AnnotatedType* java::lang::reflect::Constructor::getAnnotatedReturnType()");
    return 0;
}

java::lang::annotation::Annotation* java::lang::reflect::Constructor::getAnnotation(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::Annotation* java::lang::reflect::Constructor::getAnnotation(::java::lang::Class* arg0)");
    return 0;
}

int8_tArray* java::lang::reflect::Constructor::getAnnotationBytes()
{ /* stub */
    unimplemented_(u"int8_tArray* java::lang::reflect::Constructor::getAnnotationBytes()");
    return 0;
}

sun::reflect::ConstructorAccessor* java::lang::reflect::Constructor::getConstructorAccessor()
{ /* stub */
return constructorAccessor ; /* getter */
}

java::lang::annotation::AnnotationArray* java::lang::reflect::Constructor::getDeclaredAnnotations()
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::reflect::Constructor::getDeclaredAnnotations()");
    return 0;
}

java::lang::Class* java::lang::reflect::Constructor::getDeclaringClass()
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::reflect::Constructor::getDeclaringClass()");
    return 0;
}

java::lang::ClassArray* java::lang::reflect::Constructor::getExceptionTypes()
{ /* stub */
return exceptionTypes ; /* getter */
}

/* private: sun::reflect::generics::factory::GenericsFactory* java::lang::reflect::Constructor::getFactory() */
java::lang::reflect::TypeArray* java::lang::reflect::Constructor::getGenericExceptionTypes()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeArray* java::lang::reflect::Constructor::getGenericExceptionTypes()");
    return 0;
}

sun::reflect::generics::repository::ConstructorRepository* java::lang::reflect::Constructor::getGenericInfo()
{ /* stub */
return genericInfo ; /* getter */
}

java::lang::reflect::TypeArray* java::lang::reflect::Constructor::getGenericParameterTypes()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeArray* java::lang::reflect::Constructor::getGenericParameterTypes()");
    return 0;
}

int32_t java::lang::reflect::Constructor::getModifiers()
{ /* stub */
return modifiers ; /* getter */
}

java::lang::String* java::lang::reflect::Constructor::getName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::reflect::Constructor::getName()");
    return 0;
}

java::lang::annotation::AnnotationArrayArray* java::lang::reflect::Constructor::getParameterAnnotations()
{ /* stub */
}

int32_t java::lang::reflect::Constructor::getParameterCount()
{ /* stub */
    unimplemented_(u"int32_t java::lang::reflect::Constructor::getParameterCount()");
    return 0;
}

java::lang::ClassArray* java::lang::reflect::Constructor::getParameterTypes()
{ /* stub */
return parameterTypes ; /* getter */
}

int8_tArray* java::lang::reflect::Constructor::getRawAnnotations()
{ /* stub */
    unimplemented_(u"int8_tArray* java::lang::reflect::Constructor::getRawAnnotations()");
    return 0;
}

int8_tArray* java::lang::reflect::Constructor::getRawParameterAnnotations()
{ /* stub */
    unimplemented_(u"int8_tArray* java::lang::reflect::Constructor::getRawParameterAnnotations()");
    return 0;
}

java::lang::reflect::Executable* java::lang::reflect::Constructor::getRoot()
{ /* stub */
}

java::lang::String* java::lang::reflect::Constructor::getSignature()
{ /* stub */
return signature ; /* getter */
}

int32_t java::lang::reflect::Constructor::getSlot()
{ /* stub */
return slot ; /* getter */
}

java::lang::reflect::TypeVariableArray* java::lang::reflect::Constructor::getTypeParameters()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeVariableArray* java::lang::reflect::Constructor::getTypeParameters()");
    return 0;
}

void java::lang::reflect::Constructor::handleParameterNumberMismatch(int32_t arg0, int32_t arg1)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::Constructor::handleParameterNumberMismatch(int32_t arg0, int32_t arg1)");
}

bool java::lang::reflect::Constructor::hasGenericInformation()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Constructor::hasGenericInformation()");
    return 0;
}

int32_t java::lang::reflect::Constructor::hashCode()
{ /* stub */
    unimplemented_(u"int32_t java::lang::reflect::Constructor::hashCode()");
    return 0;
}

bool java::lang::reflect::Constructor::isSynthetic()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Constructor::isSynthetic()");
    return 0;
}

bool java::lang::reflect::Constructor::isVarArgs()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::Constructor::isVarArgs()");
    return 0;
}

java::lang::Object* java::lang::reflect::Constructor::newInstance(::java::lang::ObjectArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::reflect::Constructor::newInstance(::java::lang::ObjectArray* arg0)");
    return 0;
}

void java::lang::reflect::Constructor::setConstructorAccessor(::sun::reflect::ConstructorAccessor* arg0)
{ /* stub */
    this->constructorAccessor = arg0; /* setter */
}

void java::lang::reflect::Constructor::specificToGenericStringHeader(::java::lang::StringBuilder* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::Constructor::specificToGenericStringHeader(::java::lang::StringBuilder* arg0)");
}

void java::lang::reflect::Constructor::specificToStringHeader(::java::lang::StringBuilder* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::Constructor::specificToStringHeader(::java::lang::StringBuilder* arg0)");
}

java::lang::String* java::lang::reflect::Constructor::toGenericString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::reflect::Constructor::toGenericString()");
    return 0;
}

java::lang::String* java::lang::reflect::Constructor::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::reflect::Constructor::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::reflect::Constructor::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.reflect.Constructor", 29);
    return c;
}

java::lang::Class* java::lang::reflect::Constructor::getClass0()
{
    return class_();
}

