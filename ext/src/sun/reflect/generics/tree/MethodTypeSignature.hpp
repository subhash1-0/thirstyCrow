// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/tree/fwd-pastry-2.1.hpp>
#include <sun/reflect/generics/visitor/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <sun/reflect/generics/tree/Signature.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace sun
{
    namespace reflect
    {
        namespace generics
        {
            namespace tree
            {
typedef ::SubArray< ::sun::reflect::generics::tree::Tree, ::java::lang::ObjectArray > TreeArray;
typedef ::SubArray< ::sun::reflect::generics::tree::TypeTree, ::java::lang::ObjectArray, TreeArray > TypeTreeArray;
typedef ::SubArray< ::sun::reflect::generics::tree::ReturnType, ::java::lang::ObjectArray, TypeTreeArray > ReturnTypeArray;
typedef ::SubArray< ::sun::reflect::generics::tree::TypeSignature, ::java::lang::ObjectArray, ReturnTypeArray > TypeSignatureArray;
typedef ::SubArray< ::sun::reflect::generics::tree::BaseType, ::java::lang::ObjectArray, TypeSignatureArray > BaseTypeArray;
typedef ::SubArray< ::sun::reflect::generics::tree::TypeArgument, ::java::lang::ObjectArray, TypeTreeArray > TypeArgumentArray;
typedef ::SubArray< ::sun::reflect::generics::tree::FieldTypeSignature, ::java::lang::ObjectArray, BaseTypeArray, TypeSignatureArray, TypeArgumentArray > FieldTypeSignatureArray;
typedef ::SubArray< ::sun::reflect::generics::tree::FormalTypeParameter, ::java::lang::ObjectArray, TypeTreeArray > FormalTypeParameterArray;
            } // tree
        } // generics
    } // reflect
} // sun

struct default_init_tag;

class sun::reflect::generics::tree::MethodTypeSignature
    : public virtual ::java::lang::Object
    , public virtual Signature
{

public:
    typedef ::java::lang::Object super;

private:
    FieldTypeSignatureArray* exceptionTypes {  };
    FormalTypeParameterArray* formalTypeParams {  };
    TypeSignatureArray* parameterTypes {  };
    ReturnType* returnType {  };

    /*void ctor(FormalTypeParameterArray* arg0, TypeSignatureArray* arg1, ReturnType* arg2, FieldTypeSignatureArray* arg3); (private) */

public:
    virtual void accept(::sun::reflect::generics::visitor::Visitor* arg0);
    virtual FieldTypeSignatureArray* getExceptionTypes();
    FormalTypeParameterArray* getFormalTypeParameters() override;
    virtual TypeSignatureArray* getParameterTypes();
    virtual ReturnType* getReturnType();
    static MethodTypeSignature* make(FormalTypeParameterArray* arg0, TypeSignatureArray* arg1, ReturnType* arg2, FieldTypeSignatureArray* arg3);

    // Generated
    MethodTypeSignature();
protected:
    MethodTypeSignature(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
