// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <sun/reflect/ReflectionFactory.hpp>

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

extern void unimplemented_(const char16_t* name);
sun::reflect::ReflectionFactory::ReflectionFactory(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

int32_t& sun::reflect::ReflectionFactory::inflationThreshold_()
{
    clinit();
    return inflationThreshold__;
}
int32_t sun::reflect::ReflectionFactory::inflationThreshold__;
bool& sun::reflect::ReflectionFactory::initted()
{
    clinit();
    return initted_;
}
bool sun::reflect::ReflectionFactory::initted_;
std::atomic< sun::reflect::LangReflectAccess* >& sun::reflect::ReflectionFactory::langReflectAccess_()
{
    clinit();
    return langReflectAccess__;
}
std::atomic< sun::reflect::LangReflectAccess* > sun::reflect::ReflectionFactory::langReflectAccess__;
bool& sun::reflect::ReflectionFactory::noInflation()
{
    clinit();
    return noInflation_;
}
bool sun::reflect::ReflectionFactory::noInflation_;
java::security::Permission*& sun::reflect::ReflectionFactory::reflectionFactoryAccessPerm()
{
    clinit();
    return reflectionFactoryAccessPerm_;
}
java::security::Permission* sun::reflect::ReflectionFactory::reflectionFactoryAccessPerm_;
sun::reflect::ReflectionFactory*& sun::reflect::ReflectionFactory::soleInstance()
{
    clinit();
    return soleInstance_;
}
sun::reflect::ReflectionFactory* sun::reflect::ReflectionFactory::soleInstance_;

/* private: void ::sun::reflect::ReflectionFactory::ctor() */
/* private: void sun::reflect::ReflectionFactory::checkInitted() */
java::lang::reflect::Constructor* sun::reflect::ReflectionFactory::copyConstructor(::java::lang::reflect::Constructor* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* sun::reflect::ReflectionFactory::copyConstructor(::java::lang::reflect::Constructor* arg0)");
    return 0;
}

java::lang::reflect::Field* sun::reflect::ReflectionFactory::copyField(::java::lang::reflect::Field* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Field* sun::reflect::ReflectionFactory::copyField(::java::lang::reflect::Field* arg0)");
    return 0;
}

java::lang::reflect::Method* sun::reflect::ReflectionFactory::copyMethod(::java::lang::reflect::Method* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* sun::reflect::ReflectionFactory::copyMethod(::java::lang::reflect::Method* arg0)");
    return 0;
}

sun::reflect::ConstructorAccessor* sun::reflect::ReflectionFactory::getConstructorAccessor(::java::lang::reflect::Constructor* arg0)
{ /* stub */
    unimplemented_(u"sun::reflect::ConstructorAccessor* sun::reflect::ReflectionFactory::getConstructorAccessor(::java::lang::reflect::Constructor* arg0)");
    return 0;
}

int8_tArray* sun::reflect::ReflectionFactory::getExecutableTypeAnnotationBytes(::java::lang::reflect::Executable* arg0)
{ /* stub */
    unimplemented_(u"int8_tArray* sun::reflect::ReflectionFactory::getExecutableTypeAnnotationBytes(::java::lang::reflect::Executable* arg0)");
    return 0;
}

sun::reflect::MethodAccessor* sun::reflect::ReflectionFactory::getMethodAccessor(::java::lang::reflect::Method* arg0)
{ /* stub */
    unimplemented_(u"sun::reflect::MethodAccessor* sun::reflect::ReflectionFactory::getMethodAccessor(::java::lang::reflect::Method* arg0)");
    return 0;
}

sun::reflect::ReflectionFactory* sun::reflect::ReflectionFactory::getReflectionFactory()
{ /* stub */
    clinit();
    unimplemented_(u"sun::reflect::ReflectionFactory* sun::reflect::ReflectionFactory::getReflectionFactory()");
    return 0;
}

int32_t sun::reflect::ReflectionFactory::inflationThreshold()
{ /* stub */
    clinit();
    unimplemented_(u"int32_t sun::reflect::ReflectionFactory::inflationThreshold()");
    return 0;
}

/* private: sun::reflect::LangReflectAccess* sun::reflect::ReflectionFactory::langReflectAccess() */
java::lang::reflect::Constructor* sun::reflect::ReflectionFactory::newConstructor(::java::lang::Class* arg0, ::java::lang::ClassArray* arg1, ::java::lang::ClassArray* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6, ::int8_tArray* arg7)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* sun::reflect::ReflectionFactory::newConstructor(::java::lang::Class* arg0, ::java::lang::ClassArray* arg1, ::java::lang::ClassArray* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6, ::int8_tArray* arg7)");
    return 0;
}

sun::reflect::ConstructorAccessor* sun::reflect::ReflectionFactory::newConstructorAccessor(::java::lang::reflect::Constructor* arg0)
{ /* stub */
    unimplemented_(u"sun::reflect::ConstructorAccessor* sun::reflect::ReflectionFactory::newConstructorAccessor(::java::lang::reflect::Constructor* arg0)");
    return 0;
}

java::lang::reflect::Constructor* sun::reflect::ReflectionFactory::newConstructorForSerialization(::java::lang::Class* arg0, ::java::lang::reflect::Constructor* arg1)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* sun::reflect::ReflectionFactory::newConstructorForSerialization(::java::lang::Class* arg0, ::java::lang::reflect::Constructor* arg1)");
    return 0;
}

java::lang::reflect::Field* sun::reflect::ReflectionFactory::newField(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::Class* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Field* sun::reflect::ReflectionFactory::newField(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::Class* arg2, int32_t arg3, int32_t arg4, ::java::lang::String* arg5, ::int8_tArray* arg6)");
    return 0;
}

sun::reflect::FieldAccessor* sun::reflect::ReflectionFactory::newFieldAccessor(::java::lang::reflect::Field* arg0, bool arg1)
{ /* stub */
    unimplemented_(u"sun::reflect::FieldAccessor* sun::reflect::ReflectionFactory::newFieldAccessor(::java::lang::reflect::Field* arg0, bool arg1)");
    return 0;
}

java::lang::reflect::Method* sun::reflect::ReflectionFactory::newMethod(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* sun::reflect::ReflectionFactory::newMethod(::java::lang::Class* arg0, ::java::lang::String* arg1, ::java::lang::ClassArray* arg2, ::java::lang::Class* arg3, ::java::lang::ClassArray* arg4, int32_t arg5, int32_t arg6, ::java::lang::String* arg7, ::int8_tArray* arg8, ::int8_tArray* arg9, ::int8_tArray* arg10)");
    return 0;
}

sun::reflect::MethodAccessor* sun::reflect::ReflectionFactory::newMethodAccessor(::java::lang::reflect::Method* arg0)
{ /* stub */
    unimplemented_(u"sun::reflect::MethodAccessor* sun::reflect::ReflectionFactory::newMethodAccessor(::java::lang::reflect::Method* arg0)");
    return 0;
}

void sun::reflect::ReflectionFactory::setConstructorAccessor(::java::lang::reflect::Constructor* arg0, ConstructorAccessor* arg1)
{ /* stub */
    unimplemented_(u"void sun::reflect::ReflectionFactory::setConstructorAccessor(::java::lang::reflect::Constructor* arg0, ConstructorAccessor* arg1)");
}

void sun::reflect::ReflectionFactory::setLangReflectAccess(LangReflectAccess* arg0)
{ /* stub */
    unimplemented_(u"void sun::reflect::ReflectionFactory::setLangReflectAccess(LangReflectAccess* arg0)");
}

void sun::reflect::ReflectionFactory::setMethodAccessor(::java::lang::reflect::Method* arg0, MethodAccessor* arg1)
{ /* stub */
    unimplemented_(u"void sun::reflect::ReflectionFactory::setMethodAccessor(::java::lang::reflect::Method* arg0, MethodAccessor* arg1)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* sun::reflect::ReflectionFactory::class_()
{
    static ::java::lang::Class* c = ::class_(u"sun.reflect.ReflectionFactory", 29);
    return c;
}

java::lang::Class* sun::reflect::ReflectionFactory::getClass0()
{
    return class_();
}

