// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java

#pragma once

#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/persistence/PersistentStorage_PersistenceException.hpp>

struct default_init_tag;

class rice::persistence::PersistentStorage_OutofDiskSpaceException
    : public PersistentStorage_PersistenceException
{

public:
    typedef PersistentStorage_PersistenceException super;

    // Generated
    PersistentStorage_OutofDiskSpaceException();
protected:
    PersistentStorage_OutofDiskSpaceException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

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
    friend class PersistentStorage_DirectoryFilter;
    friend class PersistentStorage_FileFilter;
    friend class PersistentStorage_CharacterHashSet;
    friend class PersistentStorage_PersistenceException;
};
