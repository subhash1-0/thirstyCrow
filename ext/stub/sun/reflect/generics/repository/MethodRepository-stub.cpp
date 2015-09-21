// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <sun/reflect/generics/repository/MethodRepository.hpp>

extern void unimplemented_(const char16_t* name);
sun::reflect::generics::repository::MethodRepository::MethodRepository(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}


/* private: void ::sun::reflect::generics::repository::MethodRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1) */
java::lang::reflect::Type* sun::reflect::generics::repository::MethodRepository::getReturnType()
{ /* stub */
return returnType ; /* getter */
}

sun::reflect::generics::repository::MethodRepository* sun::reflect::generics::repository::MethodRepository::make(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
{ /* stub */
    clinit();
    unimplemented_(u"sun::reflect::generics::repository::MethodRepository* sun::reflect::generics::repository::MethodRepository::make(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)");
    return 0;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* sun::reflect::generics::repository::MethodRepository::class_()
{
    static ::java::lang::Class* c = ::class_(u"sun.reflect.generics.repository.MethodRepository", 48);
    return c;
}

java::lang::Class* sun::reflect::generics::repository::MethodRepository::getClass0()
{
    return class_();
}

