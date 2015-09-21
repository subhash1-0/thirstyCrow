// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/factory/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/tree/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/GenericDeclRepository.hpp>
#include <sun/reflect/generics/tree/MethodTypeSignature.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
    } // lang
} // java

struct default_init_tag;

class sun::reflect::generics::repository::ConstructorRepository
    : public GenericDeclRepository
{

public:
    typedef GenericDeclRepository super;

private:
    ::java::lang::reflect::TypeArray* exceptionTypes {  };
    ::java::lang::reflect::TypeArray* paramTypes {  };

protected:
    void ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1);

public:
    virtual ::java::lang::reflect::TypeArray* getExceptionTypes();
    virtual ::java::lang::reflect::TypeArray* getParameterTypes();
    static ConstructorRepository* make(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1);

public: /* protected */
    ::sun::reflect::generics::tree::MethodTypeSignature* parse(::java::lang::String* arg0) override;

    // Generated
    ConstructorRepository(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1);
protected:
    ConstructorRepository(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
