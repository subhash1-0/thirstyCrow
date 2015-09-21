// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/annotation/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <java/security/fwd-pastry-2.1.hpp>
#include <sun/reflect/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/reflect/AnnotatedElement.hpp>

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

struct default_init_tag;

class java::lang::reflect::AccessibleObject
    : public virtual ::java::lang::Object
    , public virtual AnnotatedElement
{

public:
    typedef ::java::lang::Object super;

private:
    static ::java::security::Permission* ACCESS_PERMISSION_;

public: /* package */
    bool override {  };

private:
    static ::sun::reflect::ReflectionFactory* reflectionFactory_;

public: /* package */
    std::atomic< ::java::lang::Object* > securityCheckCache {  };

protected:
    void ctor();

public: /* package */
    virtual void checkAccess(::java::lang::Class* arg0, ::java::lang::Class* arg1, ::java::lang::Object* arg2, int32_t arg3);

public:
    ::java::lang::annotation::Annotation* getAnnotation(::java::lang::Class* arg0) override;
    ::java::lang::annotation::AnnotationArray* getAnnotations() override;
    ::java::lang::annotation::AnnotationArray* getAnnotationsByType(::java::lang::Class* arg0) override;
    ::java::lang::annotation::Annotation* getDeclaredAnnotation(::java::lang::Class* arg0) override;
    ::java::lang::annotation::AnnotationArray* getDeclaredAnnotations() override;
    ::java::lang::annotation::AnnotationArray* getDeclaredAnnotationsByType(::java::lang::Class* arg0) override;
    virtual bool isAccessible();
    bool isAnnotationPresent(::java::lang::Class* arg0) override;
    virtual void setAccessible(bool arg0);
    static void setAccessible(AccessibleObjectArray* arg0, bool arg1);
    /*static void setAccessible0(AccessibleObject* arg0, bool arg1); (private) */

public: /* package */
    virtual void slowCheckMemberAccess(::java::lang::Class* arg0, ::java::lang::Class* arg1, ::java::lang::Object* arg2, int32_t arg3, ::java::lang::Class* arg4);

    // Generated

public: /* protected */
    AccessibleObject();
protected:
    AccessibleObject(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    static ::java::security::Permission*& ACCESS_PERMISSION();

public: /* package */
    static ::sun::reflect::ReflectionFactory*& reflectionFactory();

private:
    virtual ::java::lang::Class* getClass0();
};
