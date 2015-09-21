// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Class_MethodArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::AccessibleObject, ::java::lang::ObjectArray, AnnotatedElementArray > AccessibleObjectArray;
typedef ::SubArray< ::java::lang::reflect::Member, ::java::lang::ObjectArray > MemberArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Executable, AccessibleObjectArray, MemberArray, GenericDeclarationArray > ExecutableArray;
typedef ::SubArray< ::java::lang::reflect::Method, ExecutableArray > MethodArray;
        } // reflect
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
java::lang::Class_MethodArray::Class_MethodArray(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

java::lang::Class_MethodArray::Class_MethodArray()
    : Class_MethodArray(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::Class_MethodArray::Class_MethodArray(int32_t arg0)
    : Class_MethodArray(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0);
}


void ::java::lang::Class_MethodArray::ctor()
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Class_MethodArray::ctor()");
}

void ::java::lang::Class_MethodArray::ctor(int32_t arg0)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::java::lang::Class_MethodArray::ctor(int32_t arg0)");
}

void java::lang::Class_MethodArray::add(::java::lang::reflect::Method* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::add(::java::lang::reflect::Method* arg0)");
}

void java::lang::Class_MethodArray::addAll(::java::lang::reflect::MethodArray* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::addAll(::java::lang::reflect::MethodArray* arg0)");
}

void java::lang::Class_MethodArray::addAll(Class_MethodArray* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::addAll(Class_MethodArray* arg0)");
}

void java::lang::Class_MethodArray::addAllIfNotPresent(Class_MethodArray* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::addAllIfNotPresent(Class_MethodArray* arg0)");
}

void java::lang::Class_MethodArray::addIfNotPresent(::java::lang::reflect::Method* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::addIfNotPresent(::java::lang::reflect::Method* arg0)");
}

void java::lang::Class_MethodArray::addInterfaceMethods(::java::lang::reflect::MethodArray* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::addInterfaceMethods(::java::lang::reflect::MethodArray* arg0)");
}

void java::lang::Class_MethodArray::compactAndTrim()
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::compactAndTrim()");
}

java::lang::reflect::Method* java::lang::Class_MethodArray::get(int32_t arg0)
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* java::lang::Class_MethodArray::get(int32_t arg0)");
    return 0;
}

java::lang::reflect::MethodArray* java::lang::Class_MethodArray::getArray_()
{ /* stub */
    unimplemented_(u"java::lang::reflect::MethodArray* java::lang::Class_MethodArray::getArray_()");
    return 0;
}

java::lang::reflect::Method* java::lang::Class_MethodArray::getFirst()
{ /* stub */
    unimplemented_(u"java::lang::reflect::Method* java::lang::Class_MethodArray::getFirst()");
    return 0;
}

bool java::lang::Class_MethodArray::hasDefaults()
{ /* stub */
    unimplemented_(u"bool java::lang::Class_MethodArray::hasDefaults()");
    return 0;
}

bool java::lang::Class_MethodArray::hasMoreSpecificClass(::java::lang::reflect::Method* arg0, ::java::lang::reflect::Method* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Class_MethodArray::hasMoreSpecificClass(::java::lang::reflect::Method* arg0, ::java::lang::reflect::Method* arg1)");
    return 0;
}

int32_t java::lang::Class_MethodArray::length()
{ /* stub */
    unimplemented_(u"int32_t java::lang::Class_MethodArray::length()");
    return 0;
}

/* private: bool java::lang::Class_MethodArray::matchesNameAndDescriptor(::java::lang::reflect::Method* arg0, ::java::lang::reflect::Method* arg1) */
/* private: void java::lang::Class_MethodArray::remove(int32_t arg0) */
void java::lang::Class_MethodArray::removeByNameAndDescriptor(::java::lang::reflect::Method* arg0)
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::removeByNameAndDescriptor(::java::lang::reflect::Method* arg0)");
}

void java::lang::Class_MethodArray::removeLessSpecifics()
{ /* stub */
    unimplemented_(u"void java::lang::Class_MethodArray::removeLessSpecifics()");
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Class_MethodArray::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Class.MethodArray", 27);
    return c;
}

java::lang::Class* java::lang::Class_MethodArray::getClass0()
{
    return class_();
}

