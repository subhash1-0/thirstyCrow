// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar
#include <sun/reflect/generics/repository/AbstractRepository.hpp>

extern void unimplemented_(const char16_t* name);
sun::reflect::generics::repository::AbstractRepository::AbstractRepository(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

sun::reflect::generics::repository::AbstractRepository::AbstractRepository(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
    : AbstractRepository(*static_cast< ::default_init_tag* >(0))
{
    ctor(arg0, arg1);
}


void ::sun::reflect::generics::repository::AbstractRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)
{ /* stub */
    /* super::ctor(); */
    unimplemented_(u"void ::sun::reflect::generics::repository::AbstractRepository::ctor(::java::lang::String* arg0, ::sun::reflect::generics::factory::GenericsFactory* arg1)");
}

/* private: sun::reflect::generics::factory::GenericsFactory* sun::reflect::generics::repository::AbstractRepository::getFactory() */
sun::reflect::generics::visitor::Reifier* sun::reflect::generics::repository::AbstractRepository::getReifier()
{ /* stub */
    unimplemented_(u"sun::reflect::generics::visitor::Reifier* sun::reflect::generics::repository::AbstractRepository::getReifier()");
    return 0;
}

sun::reflect::generics::tree::Tree* sun::reflect::generics::repository::AbstractRepository::getTree()
{ /* stub */
return tree ; /* getter */
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* sun::reflect::generics::repository::AbstractRepository::class_()
{
    static ::java::lang::Class* c = ::class_(u"sun.reflect.generics.repository.AbstractRepository", 50);
    return c;
}

java::lang::Class* sun::reflect::generics::repository::AbstractRepository::getClass0()
{
    return class_();
}

