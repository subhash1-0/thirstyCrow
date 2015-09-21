// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/reflect/AccessibleObject.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::Annotation, ::java::lang::ObjectArray > AnnotationArray;
        } // annotation

        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::AccessibleObject, ::java::lang::ObjectArray, AnnotatedElementArray > AccessibleObjectArray;
        } // reflect
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
java::lang::reflect::AccessibleObject::AccessibleObject(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::reflect::AccessibleObject::AccessibleObject()
    : AccessibleObject(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::security::Permission*& java::lang::reflect::AccessibleObject::ACCESS_PERMISSION()
{
    clinit();
    return ACCESS_PERMISSION_;
}
java::security::Permission* java::lang::reflect::AccessibleObject::ACCESS_PERMISSION_;
sun::reflect::ReflectionFactory*& java::lang::reflect::AccessibleObject::reflectionFactory()
{
    clinit();
    return reflectionFactory_;
}
sun::reflect::ReflectionFactory* java::lang::reflect::AccessibleObject::reflectionFactory_;

void ::java::lang::reflect::AccessibleObject::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::reflect::AccessibleObject::ctor()");
}

void java::lang::reflect::AccessibleObject::checkAccess(::java::lang::Class* arg0, ::java::lang::Class* arg1, ::java::lang::Object* arg2, int32_t arg3)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::AccessibleObject::checkAccess(::java::lang::Class* arg0, ::java::lang::Class* arg1, ::java::lang::Object* arg2, int32_t arg3)");
}

java::lang::annotation::Annotation* java::lang::reflect::AccessibleObject::getAnnotation(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::Annotation* java::lang::reflect::AccessibleObject::getAnnotation(::java::lang::Class* arg0)");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getAnnotations()
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getAnnotations()");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getAnnotationsByType(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getAnnotationsByType(::java::lang::Class* arg0)");
    return 0;
}

java::lang::annotation::Annotation* java::lang::reflect::AccessibleObject::getDeclaredAnnotation(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::Annotation* java::lang::reflect::AccessibleObject::getDeclaredAnnotation(::java::lang::Class* arg0)");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getDeclaredAnnotations()
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getDeclaredAnnotations()");
    return 0;
}

java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getDeclaredAnnotationsByType(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"java::lang::annotation::AnnotationArray* java::lang::reflect::AccessibleObject::getDeclaredAnnotationsByType(::java::lang::Class* arg0)");
    return 0;
}

bool java::lang::reflect::AccessibleObject::isAccessible()
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::AccessibleObject::isAccessible()");
    return 0;
}

bool java::lang::reflect::AccessibleObject::isAnnotationPresent(::java::lang::Class* arg0)
{ /* stub */
    unimplemented_(u"bool java::lang::reflect::AccessibleObject::isAnnotationPresent(::java::lang::Class* arg0)");
    return 0;
}

void java::lang::reflect::AccessibleObject::setAccessible(bool arg0)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::AccessibleObject::setAccessible(bool arg0)");
}

void java::lang::reflect::AccessibleObject::setAccessible(AccessibleObjectArray* arg0, bool arg1)
{ /* stub */
    clinit();
    unimplemented_(u"void java::lang::reflect::AccessibleObject::setAccessible(AccessibleObjectArray* arg0, bool arg1)");
}

/* private: void java::lang::reflect::AccessibleObject::setAccessible0(AccessibleObject* arg0, bool arg1) */
void java::lang::reflect::AccessibleObject::slowCheckMemberAccess(::java::lang::Class* arg0, ::java::lang::Class* arg1, ::java::lang::Object* arg2, int32_t arg3, ::java::lang::Class* arg4)
{ /* stub */
    unimplemented_(u"void java::lang::reflect::AccessibleObject::slowCheckMemberAccess(::java::lang::Class* arg0, ::java::lang::Class* arg1, ::java::lang::Object* arg2, int32_t arg3, ::java::lang::Class* arg4)");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::reflect::AccessibleObject::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.reflect.AccessibleObject", 34);
    return c;
}

java::lang::Class* java::lang::reflect::AccessibleObject::getClass0()
{
    return class_();
}

