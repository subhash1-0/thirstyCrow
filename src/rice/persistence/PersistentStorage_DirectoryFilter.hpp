// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/FilenameFilter.hpp>

struct default_init_tag;

class rice::persistence::PersistentStorage_DirectoryFilter
    : public virtual ::java::lang::Object
    , public virtual ::java::io::FilenameFilter
{

public:
    typedef ::java::lang::Object super;
    bool accept(::java::io::File* dir, ::java::lang::String* name) override;

    // Generated
    PersistentStorage_DirectoryFilter(PersistentStorage *PersistentStorage_this);
protected:
    PersistentStorage_DirectoryFilter(PersistentStorage *PersistentStorage_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    PersistentStorage *PersistentStorage_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PersistentStorage;
    friend class PersistentStorage_setTimer_1;
    friend class PersistentStorage_setTimer_1_run_1_1;
    friend class PersistentStorage_rename_2;
    friend class PersistentStorage_store_3;
    friend class PersistentStorage_unstore_4;
    friend class PersistentStorage_setMetadata_5;
    friend class PersistentStorage_getObject_6;
    friend class PersistentStorage_flush_7;
    friend class PersistentStorage_FileFilter;
    friend class PersistentStorage_CharacterHashSet;
    friend class PersistentStorage_PersistenceException;
    friend class PersistentStorage_OutofDiskSpaceException;
};
