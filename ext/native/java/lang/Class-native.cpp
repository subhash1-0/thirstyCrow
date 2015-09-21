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

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AccessibleObject, ::java::lang::ObjectArray, AnnotatedElementArray > AccessibleObjectArray;
typedef ::SubArray< ::java::lang::reflect::Member, ::java::lang::ObjectArray > MemberArray;
typedef ::SubArray< ::java::lang::reflect::Executable, AccessibleObjectArray, MemberArray, GenericDeclarationArray > ExecutableArray;
typedef ::SubArray< ::java::lang::reflect::Constructor, ExecutableArray > ConstructorArray;
typedef ::SubArray< ::java::lang::reflect::Field, AccessibleObjectArray, MemberArray > FieldArray;
typedef ::SubArray< ::java::lang::reflect::Method, ExecutableArray > MethodArray;
        } // reflect
    } // lang
} // java

extern void unimplemented_(const char16_t* name);

/* private: bool java::lang::Class::desiredAssertionStatus0(Class* arg0) */
/* private: java::lang::Class* java::lang::Class::forName0(String* arg0, bool arg1, ClassLoader* arg2, Class* arg3) */
java::lang::Class* java::lang::Class::getComponentType()
{ /* native */
    unimplemented_(u"java::lang::Class* java::lang::Class::getComponentType()");
    return 0;
}

sun::reflect::ConstantPool* java::lang::Class::getConstantPool()
{ /* native */
    unimplemented_(u"sun::reflect::ConstantPool* java::lang::Class::getConstantPool()");
    return 0;
}

/* private: java::lang::ClassArray* java::lang::Class::getDeclaredClasses0() */
/* private: java::lang::reflect::ConstructorArray* java::lang::Class::getDeclaredConstructors0(bool arg0) */
/* private: java::lang::reflect::FieldArray* java::lang::Class::getDeclaredFields0(bool arg0) */
/* private: java::lang::reflect::MethodArray* java::lang::Class::getDeclaredMethods0(bool arg0) */
/* private: java::lang::Class* java::lang::Class::getDeclaringClass0() */
/* private: java::lang::ObjectArray* java::lang::Class::getEnclosingMethod0() */
/* private: java::lang::String* java::lang::Class::getGenericSignature0() */
/* private: java::lang::ClassArray* java::lang::Class::getInterfaces0() */
int32_t java::lang::Class::getModifiers()
{ /* native */
    unimplemented_(u"int32_t java::lang::Class::getModifiers()");
    return 0;
}

/* private: java::lang::String* java::lang::Class::getName0() */
java::lang::Class* java::lang::Class::getPrimitiveClass(String* arg0)
{ /* native */
    clinit();
    unimplemented_(u"java::lang::Class* java::lang::Class::getPrimitiveClass(String* arg0)");
    return 0;
}

/* private: java::security::ProtectionDomain* java::lang::Class::getProtectionDomain0() */
int8_tArray* java::lang::Class::getRawAnnotations()
{ /* native */
    unimplemented_(u"int8_tArray* java::lang::Class::getRawAnnotations()");
    return 0;
}

int8_tArray* java::lang::Class::getRawTypeAnnotations()
{ /* native */
    unimplemented_(u"int8_tArray* java::lang::Class::getRawTypeAnnotations()");
    return 0;
}

java::lang::ObjectArray* java::lang::Class::getSigners()
{ /* native */
    unimplemented_(u"java::lang::ObjectArray* java::lang::Class::getSigners()");
    return 0;
}

java::lang::Class* java::lang::Class::getSuperclass()
{ /* native */
    unimplemented_(u"java::lang::Class* java::lang::Class::getSuperclass()");
    return 0;
}

bool java::lang::Class::isArray_()
{ /* native */
    unimplemented_(u"bool java::lang::Class::isArray_()");
    return 0;
}

bool java::lang::Class::isAssignableFrom(Class* arg0)
{ /* native */
    unimplemented_(u"bool java::lang::Class::isAssignableFrom(Class* arg0)");
    return 0;
}

bool java::lang::Class::isInstance(Object* arg0)
{ /* native */
    unimplemented_(u"bool java::lang::Class::isInstance(Object* arg0)");
    return 0;
}

bool java::lang::Class::isInterface()
{ /* native */
    unimplemented_(u"bool java::lang::Class::isInterface()");
    return 0;
}

bool java::lang::Class::isPrimitive()
{ /* native */
    unimplemented_(u"bool java::lang::Class::isPrimitive()");
    return 0;
}

/* private: void java::lang::Class::registerNatives() */
void java::lang::Class::setSigners(ObjectArray* arg0)
{ /* native */
    unimplemented_(u"void java::lang::Class::setSigners(ObjectArray* arg0)");
}

