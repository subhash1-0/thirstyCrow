// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_PersistenceException.hpp>

rice::persistence::PersistentStorage_PersistenceException::PersistentStorage_PersistenceException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::PersistentStorage_PersistenceException::PersistentStorage_PersistenceException()
    : PersistentStorage_PersistenceException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_PersistenceException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.PersistentStorage.PersistenceException", 55);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_PersistenceException::getClass0()
{
    return class_();
}

