// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::persistence::PersistentStorage_CharacterHashSet
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::boolArray* bitMap {  };

public:
    virtual void put(char16_t a);
    virtual bool contains(char16_t a);
    virtual void remove(char16_t a);
    virtual ::char16_tArray* get();

private:
    ::int32_tArray* getOffsets();
    int32_t getOffset(int32_t index);
    int32_t count();

    // Generated

public:
    PersistentStorage_CharacterHashSet(PersistentStorage *PersistentStorage_this);
protected:
    void ctor();
    PersistentStorage_CharacterHashSet(PersistentStorage *PersistentStorage_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    PersistentStorage *PersistentStorage_this;
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
    friend class PersistentStorage_PersistenceException;
    friend class PersistentStorage_OutofDiskSpaceException;
};
