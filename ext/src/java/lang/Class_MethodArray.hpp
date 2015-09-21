// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
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
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Executable, AccessibleObjectArray, MemberArray, GenericDeclarationArray > ExecutableArray;
typedef ::SubArray< ::java::lang::reflect::Method, ExecutableArray > MethodArray;
        } // reflect
    } // lang
} // java

struct default_init_tag;

class java::lang::Class_MethodArray
    : public virtual Object
{

public:
    typedef Object super;

private:
    int32_t defaults {  };
    int32_t length_ {  };
    ::java::lang::reflect::MethodArray* methods {  };

protected:
    void ctor();
    void ctor(int32_t arg0);

public: /* package */
    virtual void add(::java::lang::reflect::Method* arg0);
    virtual void addAll(::java::lang::reflect::MethodArray* arg0);
    virtual void addAll(Class_MethodArray* arg0);
    virtual void addAllIfNotPresent(Class_MethodArray* arg0);
    virtual void addIfNotPresent(::java::lang::reflect::Method* arg0);
    virtual void addInterfaceMethods(::java::lang::reflect::MethodArray* arg0);
    virtual void compactAndTrim();
    virtual ::java::lang::reflect::Method* get(int32_t arg0);
    virtual ::java::lang::reflect::MethodArray* getArray_();
    virtual ::java::lang::reflect::Method* getFirst();
    virtual bool hasDefaults();
    static bool hasMoreSpecificClass(::java::lang::reflect::Method* arg0, ::java::lang::reflect::Method* arg1);
    virtual int32_t length();
    /*bool matchesNameAndDescriptor(::java::lang::reflect::Method* arg0, ::java::lang::reflect::Method* arg1); (private) */
    /*void remove(int32_t arg0); (private) */
    virtual void removeByNameAndDescriptor(::java::lang::reflect::Method* arg0);
    virtual void removeLessSpecifics();

    // Generated
    Class_MethodArray();
    Class_MethodArray(int32_t arg0);
protected:
    Class_MethodArray(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
