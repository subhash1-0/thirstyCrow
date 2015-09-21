// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/lang/reflect/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/factory/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/repository/ConstructorRepository.hpp>

struct default_init_tag;

class sun::reflect::generics::repository::MethodRepository
    : public ConstructorRepository
{

public:
    typedef ConstructorRepository super;

private:
    ::java::lang::reflect::Type* returnType {  };

    /*void ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1); (private) */

public:
    virtual ::java::lang::reflect::Type* getReturnType();
    static MethodRepository* make(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1);

    // Generated
    MethodRepository();
protected:
    MethodRepository(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
