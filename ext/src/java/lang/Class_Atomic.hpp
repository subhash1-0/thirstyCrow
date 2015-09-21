// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/ref/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <sun/misc/fwd-pastry-2.1.hpp>
#include <sun/reflect/annotation/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

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

struct default_init_tag;

class java::lang::Class_Atomic
    : public virtual Object
{

public:
    typedef Object super;

private:
    static int64_t annotationDataOffset_;
    static int64_t annotationTypeOffset_;
    static int64_t reflectionDataOffset_;
    static ::sun::misc::Unsafe* unsafe_;

    /*void ctor(); (private) */

public: /* package */
    static bool casAnnotationData(Class* arg0, Class_AnnotationData* arg1, Class_AnnotationData* arg2);
    static bool casAnnotationType(Class* arg0, ::sun::reflect::annotation::AnnotationType* arg1, ::sun::reflect::annotation::AnnotationType* arg2);
    static bool casReflectionData(Class* arg0, ::java::lang::ref::SoftReference* arg1, ::java::lang::ref::SoftReference* arg2);
    /*static int64_t objectFieldOffset(::java::lang::reflect::FieldArray* arg0, String* arg1); (private) */

    // Generated

public:
    Class_Atomic();
protected:
    Class_Atomic(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static int64_t& annotationDataOffset();
    static int64_t& annotationTypeOffset();
    static int64_t& reflectionDataOffset();
    static ::sun::misc::Unsafe*& unsafe();
    virtual ::java::lang::Class* getClass0();
};
