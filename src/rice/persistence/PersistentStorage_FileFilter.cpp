// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java
#include <rice/persistence/PersistentStorage_FileFilter.hpp>

#include <rice/persistence/PersistentStorage.hpp>

rice::persistence::PersistentStorage_FileFilter::PersistentStorage_FileFilter(PersistentStorage *PersistentStorage_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , PersistentStorage_this(PersistentStorage_this)
{
    clinit();
}

rice::persistence::PersistentStorage_FileFilter::PersistentStorage_FileFilter(PersistentStorage *PersistentStorage_this)
    : PersistentStorage_FileFilter(PersistentStorage_this, *static_cast< ::default_init_tag* >(0))
{
    ctor();
}

bool rice::persistence::PersistentStorage_FileFilter::accept(::java::io::File* dir, ::java::lang::String* name)
{
    return PersistentStorage_this->isFile(dir, name);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::persistence::PersistentStorage_FileFilter::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.persistence.PersistentStorage.FileFilter", 45);
    return c;
}

java::lang::Class* rice::persistence::PersistentStorage_FileFilter::getClass0()
{
    return class_();
}

