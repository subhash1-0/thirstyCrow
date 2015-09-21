// Generated from /pastry-2.1/src/rice/persistence/StorageManagerImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/persistence/StorageManager.hpp>

struct default_init_tag;

class rice::persistence::StorageManagerImpl
    : public virtual ::java::lang::Object
    , public virtual StorageManager
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::p2p::commonapi::IdFactory* factory {  };
    Storage* storage {  };
    Cache* cache_ {  };
protected:
    void ctor(::rice::p2p::commonapi::IdFactory* factory, Storage* storage, Cache* cache);

public:
    Storage* getStorage() override;
    Cache* getCache() override;
    bool exists(::rice::p2p::commonapi::Id* id) override;
    void rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c) override;
    void getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    ::java::io::Serializable* getMetadata(::rice::p2p::commonapi::Id* id) override;
    void setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan() override;
    ::java::util::SortedMap* scanMetadata(::rice::p2p::commonapi::IdRange* range) override;
    ::java::util::SortedMap* scanMetadata() override;
    ::java::util::SortedMap* scanMetadataValuesHead(::java::lang::Object* value) override;
    ::java::util::SortedMap* scanMetadataValuesNull() override;
    int64_t getTotalSize() override;
    int32_t getSize() override;
    void store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) override;
    void unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    void cache(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) override;
    void uncache(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    int64_t getMaximumSize() override;
    void setMaximumSize(int32_t size, ::rice::Continuation* c) override;
    void flush(::rice::Continuation* c) override;

    // Generated
    StorageManagerImpl(::rice::p2p::commonapi::IdFactory* factory, Storage* storage, Cache* cache);
protected:
    StorageManagerImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class StorageManagerImpl_rename_1;
    friend class StorageManagerImpl_getObject_2;
    friend class StorageManagerImpl_setMetadata_3;
    friend class StorageManagerImpl_flush_4;
};
