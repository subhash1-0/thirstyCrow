// Generated from /pastry-2.1/src/rice/persistence/StorageManagerImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/Continuation_StandardContinuation.hpp>

struct default_init_tag;

class rice::persistence::StorageManagerImpl_getObject_2
    : public ::rice::Continuation_StandardContinuation
{

public:
    typedef ::rice::Continuation_StandardContinuation super;
    void receiveResult(::java::lang::Object* o) override;
    ::java::lang::String* toString() override;

    // Generated
    StorageManagerImpl_getObject_2(StorageManagerImpl *StorageManagerImpl_this, ::rice::p2p::commonapi::Id* id, ::rice::Continuation* continuation);
    static ::java::lang::Class *class_();
    StorageManagerImpl *StorageManagerImpl_this;
    ::rice::p2p::commonapi::Id* id;

private:
    virtual ::java::lang::Class* getClass0();
    friend class StorageManagerImpl;
    friend class StorageManagerImpl_rename_1;
    friend class StorageManagerImpl_setMetadata_3;
    friend class StorageManagerImpl_flush_4;
};
