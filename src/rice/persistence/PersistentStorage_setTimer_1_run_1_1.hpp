// Generated from /pastry-2.1/src/rice/persistence/PersistentStorage.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/selector/fwd-pastry-2.1.hpp>
#include <rice/environment/processing/WorkRequest.hpp>

struct default_init_tag;

class rice::persistence::PersistentStorage_setTimer_1_run_1_1
    : public ::rice::environment::processing::WorkRequest
{

public:
    typedef ::rice::environment::processing::WorkRequest super;
    ::java::lang::String* toString() override;
    ::java::lang::Object* doWork() /* throws(Exception) */ override;

    // Generated
    PersistentStorage_setTimer_1_run_1_1(PersistentStorage_setTimer_1 *PersistentStorage_setTimer_1_this, ::rice::Continuation* c, ::rice::selector::SelectorManager* sm);
    PersistentStorage_setTimer_1_run_1_1(PersistentStorage_setTimer_1 *PersistentStorage_setTimer_1_this);
    static ::java::lang::Class *class_();
    PersistentStorage_setTimer_1 *PersistentStorage_setTimer_1_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class PersistentStorage;
    friend class PersistentStorage_setTimer_1;
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
    friend class PersistentStorage_OutofDiskSpaceException;
};
