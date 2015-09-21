// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <java/lang/Class_Atomic.hpp>

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
typedef ::SubArray< ::java::lang::reflect::Field, AccessibleObjectArray, MemberArray > FieldArray;
        } // reflect
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
java::lang::Class_Atomic::Class_Atomic(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

int64_t& java::lang::Class_Atomic::annotationDataOffset()
{
    clinit();
    return annotationDataOffset_;
}
int64_t java::lang::Class_Atomic::annotationDataOffset_;
int64_t& java::lang::Class_Atomic::annotationTypeOffset()
{
    clinit();
    return annotationTypeOffset_;
}
int64_t java::lang::Class_Atomic::annotationTypeOffset_;
int64_t& java::lang::Class_Atomic::reflectionDataOffset()
{
    clinit();
    return reflectionDataOffset_;
}
int64_t java::lang::Class_Atomic::reflectionDataOffset_;
sun::misc::Unsafe*& java::lang::Class_Atomic::unsafe()
{
    clinit();
    return unsafe_;
}
sun::misc::Unsafe* java::lang::Class_Atomic::unsafe_;

/* private: void ::java::lang::Class_Atomic::ctor() */
bool java::lang::Class_Atomic::casAnnotationData(Class* arg0, Class_AnnotationData* arg1, Class_AnnotationData* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Class_Atomic::casAnnotationData(Class* arg0, Class_AnnotationData* arg1, Class_AnnotationData* arg2)");
    return 0;
}

bool java::lang::Class_Atomic::casAnnotationType(Class* arg0, ::sun::reflect::annotation::AnnotationType* arg1, ::sun::reflect::annotation::AnnotationType* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Class_Atomic::casAnnotationType(Class* arg0, ::sun::reflect::annotation::AnnotationType* arg1, ::sun::reflect::annotation::AnnotationType* arg2)");
    return 0;
}

bool java::lang::Class_Atomic::casReflectionData(Class* arg0, ::java::lang::ref::SoftReference* arg1, ::java::lang::ref::SoftReference* arg2)
{ /* stub */
    clinit();
    unimplemented_(u"bool java::lang::Class_Atomic::casReflectionData(Class* arg0, ::java::lang::ref::SoftReference* arg1, ::java::lang::ref::SoftReference* arg2)");
    return 0;
}

/* private: int64_t java::lang::Class_Atomic::objectFieldOffset(::java::lang::reflect::FieldArray* arg0, String* arg1) */
extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* java::lang::Class_Atomic::class_()
{
    static ::java::lang::Class* c = ::class_(u"java.lang.Class.Atomic", 22);
    return c;
}

java::lang::Class* java::lang::Class_Atomic::getClass0()
{
    return class_();
}

