// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <sun/reflect/generics/repository/ConstructorRepository.hpp>

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

extern void unimplemented_(const char16_t* name);
sun::reflect::generics::repository::ConstructorRepository::ConstructorRepository(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

sun::reflect::generics::repository::ConstructorRepository::ConstructorRepository(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
    : ConstructorRepository(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::sun::reflect::generics::repository::ConstructorRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::sun::reflect::generics::repository::ConstructorRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)");
}

java::lang::reflect::TypeArray* sun::reflect::generics::repository::ConstructorRepository::getExceptionTypes()
{ /* stub */
return exceptionTypes ; /* getter */
}

java::lang::reflect::TypeArray* sun::reflect::generics::repository::ConstructorRepository::getParameterTypes()
{ /* stub */
    unimplemented_(u"java::lang::reflect::TypeArray* sun::reflect::generics::repository::ConstructorRepository::getParameterTypes()");
    return 0;
}

sun::reflect::generics::repository::ConstructorRepository* sun::reflect::generics::repository::ConstructorRepository::make(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"sun::reflect::generics::repository::ConstructorRepository* sun::reflect::generics::repository::ConstructorRepository::make(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)");
    return 0;
}

sun::reflect::generics::tree::MethodTypeSignature* sun::reflect::generics::repository::ConstructorRepository::parse(::java::lang::String* arg0)
{ /* stub */
    unimplemented_(u"sun::reflect::generics::tree::MethodTypeSignature* sun::reflect::generics::repository::ConstructorRepository::parse(::java::lang::String* arg0)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* sun::reflect::generics::repository::ConstructorRepository::class_()
{
    static ::java::lang::Class* c = ::class_(u"sun.reflect.generics.repository.ConstructorRepository", 53);
    return c;
}

java::lang::Class* sun::reflect::generics::repository::ConstructorRepository::getClass0()
{
    return class_();
}

