// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Class.hpp>

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

        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::Annotation, ::java::lang::ObjectArray > AnnotationArray;
        } // annotation

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AccessibleObject, ::java::lang::ObjectArray, AnnotatedElementArray > AccessibleObjectArray;
typedef ::SubArray< ::java::lang::reflect::AnnotatedType, ::java::lang::ObjectArray, AnnotatedElementArray > AnnotatedTypeArray;
typedef ::SubArray< ::java::lang::reflect::Member, ::java::lang::ObjectArray > MemberArray;
typedef ::SubArray< ::java::lang::reflect::Executable, AccessibleObjectArray, MemberArray, GenericDeclarationArray > ExecutableArray;
typedef ::SubArray< ::java::lang::reflect::Constructor, ExecutableArray > ConstructorArray;
typedef ::SubArray< ::java::lang::reflect::Field, AccessibleObjectArray, MemberArray > FieldArray;
typedef ::SubArray< ::java::lang::reflect::Method, ExecutableArray > MethodArray;
typedef ::SubArray< ::java::lang::reflect::TypeVariable, ::java::lang::ObjectArray, TypeArray, AnnotatedElementArray > TypeVariableArray;
        } // reflect
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
java::lang::Class::Class(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

constexpr int32_t java::lang::Class::ANNOTATION;
constexpr int32_t java::lang::Class::ENUM;
constexpr int32_t java::lang::Class::SYNTHETIC;
java::security::ProtectionDomain*& java::lang::Class::allPermDomain()
{
    clinit();
    return allPermDomain_;
}
java::security::ProtectionDomain* java::lang::Class::allPermDomain_;
bool& java::lang::Class::initted()
{
    clinit();
    return initted_;
}
bool java::lang::Class::initted_;
sun::reflect::ReflectionFactory*& java::lang::Class::reflectionFactory()
{
    clinit();
    return reflectionFactory_;
}
sun::reflect::ReflectionFactory* java::lang::Class::reflectionFactory_;
java::io::ObjectStreamFieldArray*& java::lang::Class::serialPersistentFields()
{
    clinit();
    return serialPersistentFields_;
}
java::io::ObjectStreamFieldArray* java::lang::Class::serialPersistentFields_;
constexpr int64_t java::lang::Class::serialVersionUID;
bool& java::lang::Class::useCaches()
{
    clinit();
    return useCaches_;
}
bool java::lang::Class::useCaches_;

/* private: void ::java::lang::Class::ctor(ClassLoader* arg0) */
/* private: void java::lang::Class::addAll(::java::util::Collection* arg0, ::java::lang::reflect::FieldArray* arg1) */
/* private: java::lang::Class_AnnotationData* java::lang::Class::annotationData() */
/* private: java::lang::String* java::lang::Class::argumentTypesToString(ClassArray* arg0) */
/* private: bool java::lang::Class::arrayContentsEq(ObjectArray* arg0, ObjectArray* arg1) */
java::lang::Class* java::lang::Class::asSubclass(Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::Class::asSubclass(Class* arg0)");
    return 0;
}

/* private: java::lang::String* java::lang::Class::cannotCastMsg(Object* arg0) */
bool java::lang::Class::casAnnotationType(::sun::reflect::annotation::AnnotationType* arg0, ::sun::reflect::annotation::AnnotationType* arg1)
{ /* stub */
    unimplemented_(u"bool java::lang::Class::casAnnotationType(::sun::reflect::annotation::AnnotationType* arg0, ::sun::reflect::annotation::AnnotationType* arg1)");
    return 0;
}

java::lang::Object* java::lang::Class::cast(Object* arg0)
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::Class::cast(Object* arg0)");
    return 0;
}

/* private: void java::lang::Class::checkInitted() */
/* private: void java::lang::Class::checkMemberAccess(int32_t arg0, Class* arg1, bool arg2) */
/* private: void java::lang::Class::checkPackageAccess(ClassLoader* arg0, bool arg1) */
/* private: java::lang::reflect::ConstructorArray* java::lang::Class::copyConstructors(::java::lang::reflect::ConstructorArray* arg0) */
/* private: java::lang::reflect::FieldArray* java::lang::Class::copyFields(::java::lang::reflect::FieldArray* arg0) */
/* private: java::lang::reflect::MethodArray* java::lang::Class::copyMethods(::java::lang::reflect::MethodArray* arg0) */
/* private: java::lang::Class_AnnotationData* java::lang::Class::createAnnotationData(int32_t arg0) */
bool java::lang::Class::desiredAssertionStatus()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::desiredAssertionStatus()");
    return 0;
}

java::util::Map* java::lang::Class::enumConstantDirectory()
{ /* stub */
    unimplemented_(u"java::util::Map* java::lang::Class::enumConstantDirectory()");
    return 0;
}

java::lang::Class* java::lang::Class::forName(String* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Class* java::lang::Class::forName(String* arg0)");
    return 0;
}

java::lang::Class* java::lang::Class::forName(String* arg0, bool arg1, ClassLoader* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"java::lang::Class* java::lang::Class::forName(String* arg0, bool arg1, ClassLoader* arg2)");
    return 0;
}

java::lang::reflect::AnnotatedTypeArray* java::lang::Class::getAnnotatedInterfaces()
{ /* stub */
    unimplemented_(u"java::lang::reflect::AnnotatedTypeArray* java::lang::Class::getAnnotatedInterfaces()");
    return 0;
}

java::lang::reflect::AnnotatedType* java::lang::Class::getAnnotatedSuperclass()
{ /* stub */
    unimplemented_(u"java::lang::reflect::AnnotatedType* java::lang::Class::getAnnotatedSuperclass()");
    return 0;
}

java::lang::annotation::Annotation* java::lang::Class::getAnnotation(Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::Annotation* java::lang::Class::getAnnotation(Class* arg0)");
    return 0;
}

sun::reflect::annotation::AnnotationType* java::lang::Class::getAnnotationType()
{ /* stub */
return annotationType ; /* getter */
}

java::lang::annotation::AnnotationArray* java::lang::Class::getAnnotations()
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::Class::getAnnotations()");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::Class::getAnnotationsByType(Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::Class::getAnnotationsByType(Class* arg0)");
    return 0;
}

java::lang::String* java::lang::Class::getCanonicalName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Class::getCanonicalName()");
    return 0;
}

java::lang::ClassLoader* java::lang::Class::getClassLoader()
{ /* stub */
return classLoader ; /* getter */
}

java::lang::ClassLoader* java::lang::Class::getClassLoader0()
{ /* stub */
    unimplemented_(u"java::lang::ClassLoader* java::lang::Class::getClassLoader0()");
    return 0;
}

java::lang::ClassArray* java::lang::Class::getClasses()
{ /* stub */
    unimplemented_(u"java::lang::ClassArray* java::lang::Class::getClasses()");
    return 0;
}

java::lang::reflect::Constructor* java::lang::Class::getConstructor(ClassArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* java::lang::Class::getConstructor(ClassArray* arg0)");
    return 0;
}

/* private: java::lang::reflect::Constructor* java::lang::Class::getConstructor0(ClassArray* arg0, int32_t arg1) */
java::lang::reflect::ConstructorArray* java::lang::Class::getConstructors()
{ /* stub */
    unimplemented_(u"java::lang::reflect::ConstructorArray* java::lang::Class::getConstructors()");
    return 0;
}

java::lang::annotation::Annotation* java::lang::Class::getDeclaredAnnotation(Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::Annotation* java::lang::Class::getDeclaredAnnotation(Class* arg0)");
    return 0;
}

java::util::Map* java::lang::Class::getDeclaredAnnotationMap()
{ /* stub */
    unimplemented_(u"java::util::Map* java::lang::Class::getDeclaredAnnotationMap()");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::Class::getDeclaredAnnotations()
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::Class::getDeclaredAnnotations()");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::Class::getDeclaredAnnotationsByType(Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::Class::getDeclaredAnnotationsByType(Class* arg0)");
    return 0;
}

java::lang::ClassArray* java::lang::Class::getDeclaredClasses()
{ /* stub */
    unimplemented_(u"java::lang::ClassArray* java::lang::Class::getDeclaredClasses()");
    return 0;
}

java::lang::reflect::Constructor* java::lang::Class::getDeclaredConstructor(ClassArray* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* java::lang::Class::getDeclaredConstructor(ClassArray* arg0)");
    return 0;
}

java::lang::reflect::ConstructorArray* java::lang::Class::getDeclaredConstructors()
{ /* stub */
    unimplemented_(u"java::lang::reflect::ConstructorArray* java::lang::Class::getDeclaredConstructors()");
    return 0;
}

java::lang::reflect::Field* java::lang::Class::getDeclaredField(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Field* java::lang::Class::getDeclaredField(String* arg0)");
    return 0;
}

java::lang::reflect::FieldArray* java::lang::Class::getDeclaredFields()
{ /* stub */
    unimplemented_(u"java::lang::reflect::FieldArray* java::lang::Class::getDeclaredFields()");
    return 0;
}

java::lang::reflect::Method* java::lang::Class::getDeclaredMethod(String* arg0, ClassArray* arg1)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* java::lang::Class::getDeclaredMethod(String* arg0, ClassArray* arg1)");
    return 0;
}

java::lang::reflect::MethodArray* java::lang::Class::getDeclaredMethods()
{ /* stub */
    unimplemented_(u"java::lang::reflect::MethodArray* java::lang::Class::getDeclaredMethods()");
    return 0;
}

java::lang::Class* java::lang::Class::getDeclaringClass()
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::Class::getDeclaringClass()");
    return 0;
}

java::lang::Class* java::lang::Class::getEnclosingClass()
{ /* stub */
    unimplemented_(u"java::lang::Class* java::lang::Class::getEnclosingClass()");
    return 0;
}

java::lang::reflect::Constructor* java::lang::Class::getEnclosingConstructor()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Constructor* java::lang::Class::getEnclosingConstructor()");
    return 0;
}

java::lang::reflect::Method* java::lang::Class::getEnclosingMethod()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* java::lang::Class::getEnclosingMethod()");
    return 0;
}

/* private: java::lang::Class_EnclosingMethodInfo* java::lang::Class::getEnclosingMethodInfo() */
java::lang::ObjectArray* java::lang::Class::getEnumConstants()
{ /* stub */
return enumConstants ; /* getter */
}

java::lang::ObjectArray* java::lang::Class::getEnumConstantsShared()
{ /* stub */
    unimplemented_(u"java::lang::ObjectArray* java::lang::Class::getEnumConstantsShared()");
    return 0;
}

int8_tArray* java::lang::Class::getExecutableTypeAnnotationBytes(::java::lang::reflect::Executable* arg0)
{ /* stub */
    clinit();
    unimplemented_(u"int8_tArray* java::lang::Class::getExecutableTypeAnnotationBytes(::java::lang::reflect::Executable* arg0)");
    return 0;
}

/* private: sun::reflect::generics::factory::GenericsFactory* java::lang::Class::getFactory() */
java::lang::reflect::Field* java::lang::Class::getField(String* arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Field* java::lang::Class::getField(String* arg0)");
    return 0;
}

/* private: java::lang::reflect::Field* java::lang::Class::getField0(String* arg0) */
java::lang::reflect::FieldArray* java::lang::Class::getFields()
{ /* stub */
    unimplemented_(u"java::lang::reflect::FieldArray* java::lang::Class::getFields()");
    return 0;
}

/* private: sun::reflect::generics::repository::ClassRepository* java::lang::Class::getGenericInfo() */
java::lang::reflect::TypeArray* java::lang::Class::getGenericInterfaces()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeArray* java::lang::Class::getGenericInterfaces()");
    return 0;
}

java::lang::reflect::Type* java::lang::Class::getGenericSuperclass()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Type* java::lang::Class::getGenericSuperclass()");
    return 0;
}

java::lang::ClassArray* java::lang::Class::getInterfaces()
{ /* stub */
    unimplemented_(u"java::lang::ClassArray* java::lang::Class::getInterfaces()");
    return 0;
}

java::lang::reflect::Method* java::lang::Class::getMethod(String* arg0, ClassArray* arg1)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* java::lang::Class::getMethod(String* arg0, ClassArray* arg1)");
    return 0;
}

/* private: java::lang::reflect::Method* java::lang::Class::getMethod0(String* arg0, ClassArray* arg1, bool arg2) */
java::lang::reflect::MethodArray* java::lang::Class::getMethods()
{ /* stub */
    unimplemented_(u"java::lang::reflect::MethodArray* java::lang::Class::getMethods()");
    return 0;
}

java::lang::String* java::lang::Class::getName()
{ /* stub */
return name ; /* getter */
}

java::lang::Package* java::lang::Class::getPackage()
{ /* stub */
    unimplemented_(u"java::lang::Package* java::lang::Class::getPackage()");
    return 0;
}

java::security::ProtectionDomain* java::lang::Class::getProtectionDomain()
{ /* stub */
    unimplemented_(u"java::security::ProtectionDomain* java::lang::Class::getProtectionDomain()");
    return 0;
}

/* private: sun::reflect::ReflectionFactory* java::lang::Class::getReflectionFactory() */
java::net::URL* java::lang::Class::getResource(String* arg0)
{ /* stub */
    unimplemented_(u"java::net::URL* java::lang::Class::getResource(String* arg0)");
    return 0;
}

java::io::InputStream* java::lang::Class::getResourceAsStream(String* arg0)
{ /* stub */
    unimplemented_(u"java::io::InputStream* java::lang::Class::getResourceAsStream(String* arg0)");
    return 0;
}

/* private: java::lang::String* java::lang::Class::getSimpleBinaryName() */
java::lang::String* java::lang::Class::getSimpleName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Class::getSimpleName()");
    return 0;
}

java::lang::String* java::lang::Class::getTypeName()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Class::getTypeName()");
    return 0;
}

java::lang::reflect::TypeVariableArray* java::lang::Class::getTypeParameters()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeVariableArray* java::lang::Class::getTypeParameters()");
    return 0;
}

bool java::lang::Class::isAnnotation()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isAnnotation()");
    return 0;
}

bool java::lang::Class::isAnnotationPresent(Class* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isAnnotationPresent(Class* arg0)");
    return 0;
}

bool java::lang::Class::isAnonymousClass()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isAnonymousClass()");
    return 0;
}

/* private: bool java::lang::Class::isAsciiDigit(char16_t arg0) */
bool java::lang::Class::isEnum()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isEnum()");
    return 0;
}

bool java::lang::Class::isLocalClass()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isLocalClass()");
    return 0;
}

/* private: bool java::lang::Class::isLocalOrAnonymousClass() */
bool java::lang::Class::isMemberClass()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isMemberClass()");
    return 0;
}

bool java::lang::Class::isSynthetic()
{ /* stub */
    unimplemented_(u"bool java::lang::Class::isSynthetic()");
    return 0;
}

java::lang::Object* java::lang::Class::newInstance()
{ /* stub */
    unimplemented_(u"java::lang::Object* java::lang::Class::newInstance()");
    return 0;
}

/* private: java::lang::Class_ReflectionData* java::lang::Class::newReflectionData(::java::lang::ref::SoftReference* arg0, int32_t arg1) */
/* private: java::lang::reflect::ConstructorArray* java::lang::Class::privateGetDeclaredConstructors(bool arg0) */
/* private: java::lang::reflect::FieldArray* java::lang::Class::privateGetDeclaredFields(bool arg0) */
/* private: java::lang::reflect::MethodArray* java::lang::Class::privateGetDeclaredMethods(bool arg0) */
/* private: java::lang::reflect::Method* java::lang::Class::privateGetMethodRecursive(String* arg0, ClassArray* arg1, bool arg2, Class_MethodArray* arg3) */
/* private: java::lang::reflect::FieldArray* java::lang::Class::privateGetPublicFields(::java::util::Set* arg0) */
/* private: java::lang::reflect::MethodArray* java::lang::Class::privateGetPublicMethods() */
/* private: java::lang::Class_ReflectionData* java::lang::Class::reflectionData() */
/* private: java::lang::String* java::lang::Class::resolveName(String* arg0) */
/* private: java::lang::reflect::Field* java::lang::Class::searchFields(::java::lang::reflect::FieldArray* arg0, String* arg1) */
/* private: java::lang::reflect::Method* java::lang::Class::searchMethods(::java::lang::reflect::MethodArray* arg0, String* arg1, ClassArray* arg2) */
/* private: java::lang::Class* java::lang::Class::toClass(::java::lang::reflect::Type* arg0) */
java::lang::String* java::lang::Class::toGenericString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Class::toGenericString()");
    return 0;
}

java::lang::String* java::lang::Class::toString()
{ /* stub */
    unimplemented_(u"java::lang::String* java::lang::Class::toString()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Class::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Class", 15);
    return c;
}

java::lang::Class* java::lang::Class::getClass0()
{
    return class_();
}

