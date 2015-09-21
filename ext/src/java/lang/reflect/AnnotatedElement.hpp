// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/annotation/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace annotation
        {
typedef ::SubArray< ::java::lang::annotation::Annotation, ::java::lang::ObjectArray > AnnotationArray;
        } // annotation
    } // lang
} // java

struct java::lang::reflect::AnnotatedElement
    : public virtual ::java::lang::Object
{

    virtual ::java::lang::annotation::Annotation* getAnnotation(::java::lang::Class* arg0) = 0;
    virtual ::java::lang::annotation::AnnotationArray* getAnnotations() = 0;
    virtual ::java::lang::annotation::AnnotationArray* getAnnotationsByType(::java::lang::Class* arg0);
    virtual ::java::lang::annotation::Annotation* getDeclaredAnnotation(::java::lang::Class* arg0);
    virtual ::java::lang::annotation::AnnotationArray* getDeclaredAnnotations() = 0;
    virtual ::java::lang::annotation::AnnotationArray* getDeclaredAnnotationsByType(::java::lang::Class* arg0);
    virtual bool isAnnotationPresent(::java::lang::Class* arg0);

    // Generated
    static ::java::lang::Class *class_();
};
