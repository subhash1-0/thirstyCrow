// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <sun/reflect/generics/tree/MethodTypeSignature.hpp>

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

extern void unimplemented_(const char16_t* name);
sun::reflect::generics::tree::MethodTypeSignature::MethodTypeSignature(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}


/* private: void ::sun::reflect::generics::tree::MethodTypeSignature::ctor(FormalTypeParameterArray* arg0, TypeSignatureArray* arg1, ReturnType* arg2, FieldTypeSignatureArray* arg3) */
void sun::reflect::generics::tree::MethodTypeSignature::accept(::sun::reflect::generics::visitor::Visitor* arg0)
{ /* stub */
    unimplemented_(u"void sun::reflect::generics::tree::MethodTypeSignature::accept(::sun::reflect::generics::visitor::Visitor* arg0)");
}

sun::reflect::generics::tree::FieldTypeSignatureArray* sun::reflect::generics::tree::MethodTypeSignature::getExceptionTypes()
{ /* stub */
return exceptionTypes ; /* getter */
}

sun::reflect::generics::tree::FormalTypeParameterArray* sun::reflect::generics::tree::MethodTypeSignature::getFormalTypeParameters()
{ /* stub */
    unimplemented_(u"sun::reflect::generics::tree::FormalTypeParameterArray* sun::reflect::generics::tree::MethodTypeSignature::getFormalTypeParameters()");
    return 0;
}

sun::reflect::generics::tree::TypeSignatureArray* sun::reflect::generics::tree::MethodTypeSignature::getParameterTypes()
{ /* stub */
return parameterTypes ; /* getter */
}

sun::reflect::generics::tree::ReturnType* sun::reflect::generics::tree::MethodTypeSignature::getReturnType()
{ /* stub */
return returnType ; /* getter */
}

sun::reflect::generics::tree::MethodTypeSignature* sun::reflect::generics::tree::MethodTypeSignature::make(FormalTypeParameterArray* arg0, TypeSignatureArray* arg1, ReturnType* arg2, FieldTypeSignatureArray* arg3)
{ /* stub */
    clinit();
    unimplemented_(u"sun::reflect::generics::tree::MethodTypeSignature* sun::reflect::generics::tree::MethodTypeSignature::make(FormalTypeParameterArray* arg0, TypeSignatureArray* arg1, ReturnType* arg2, FieldTypeSignatureArray* arg3)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* sun::reflect::generics::tree::MethodTypeSignature::class_()
{
    static ::java::lang::Class* c = ::class_(u"sun.reflect.generics.tree.MethodTypeSignature", 45);
    return c;
}

java::lang::Class* sun::reflect::generics::tree::MethodTypeSignature::getClass0()
{
    return class_();
}

