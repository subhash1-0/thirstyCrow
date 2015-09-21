// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <sun/reflect/generics/repository/GenericDeclRepository.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
typedef ::SubArray< ::java::lang::reflect::TypeVariable, ::java::lang::ObjectArray, TypeArray, AnnotatedElementArray > TypeVariableArray;
        } // reflect
    } // lang
} // java

extern void unimplemented_(const char16_t* name);
sun::reflect::generics::repository::GenericDeclRepository::GenericDeclRepository(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

sun::reflect::generics::repository::GenericDeclRepository::GenericDeclRepository(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
    : GenericDeclRepository(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::sun::reflect::generics::repository::GenericDeclRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::sun::reflect::generics::repository::GenericDeclRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)");
}

java::lang::reflect::TypeVariableArray* sun::reflect::generics::repository::GenericDeclRepository::getTypeParameters()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeVariableArray* sun::reflect::generics::repository::GenericDeclRepository::getTypeParameters()");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* sun::reflect::generics::repository::GenericDeclRepository::class_()
{
    static ::java::lang::Class* c = ::class_(u"sun.reflect.generics.repository.GenericDeclRepository", 53);
    return c;
}

java::lang::Class* sun::reflect::generics::repository::GenericDeclRepository::getClass0()
{
    return class_();
}

