// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_DirectoryFilter.hpp>

#include <rice/persistence/PersistentStorage.hpp>

rice::persistence::PersistentStorage_DirectoryFilter::PersistentStorage_DirectoryFilter(PersistentStorage *PersistentStorage_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
{
    clinit();
}

rice::persistence::PersistentStorage_DirectoryFilter::PersistentStorage_DirectoryFilter(PersistentStorage *PersistentStorage_this)
    : PersistentStorage_DirectoryFilter(PersistentStorage_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool rice::persistence::PersistentStorage_DirectoryFilter::accept(::java::io::File* dir, ::java::lang::String* name)
{
    return PersistentStorage_this->isDirectory(dir, name);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_DirectoryFilter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.PersistentStorage.DirectoryFilter", 50);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_DirectoryFilter::getClass0()
{
    return class_();
}

