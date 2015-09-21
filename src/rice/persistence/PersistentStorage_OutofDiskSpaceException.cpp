// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_OutofDiskSpaceException.hpp>

rice::persistence::PersistentStorage_OutofDiskSpaceException::PersistentStorage_OutofDiskSpaceException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::persistence::PersistentStorage_OutofDiskSpaceException::PersistentStorage_OutofDiskSpaceException()
    : PersistentStorage_OutofDiskSpaceException(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_OutofDiskSpaceException::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.PersistentStorage.OutofDiskSpaceException", 58);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_OutofDiskSpaceException::getClass0()
{
    return class_();
}

