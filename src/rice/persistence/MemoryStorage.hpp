// Generated from /pastry-2.1/src/rice/persistence/MemoryStorage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/persistence/Storage.hpp>

struct default_init_tag;

class rice::persistence::MemoryStorage
    : public virtual ::java::lang::Object
    , public virtual Storage
{

public:
    typedef ::java::lang::Object super;

private:
    ::java::util::HashMap* storage {  };
    ::rice::p2p::util::ReverseTreeMap* metadata {  };
    ::rice::p2p::commonapi::IdSet* idSet {  };
    int32_t currentSize {  };
    ::rice::p2p::commonapi::IdFactory* factory {  };
protected:
    void ctor(::rice::p2p::commonapi::IdFactory* factory);

public:
    void flush(::rice::Continuation* c) override;
    void rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c) override;
    void store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) override;
    void unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    bool exists(::rice::p2p::commonapi::Id* id) override;
    ::java::io::Serializable* getMetadata(::rice::p2p::commonapi::Id* id) override;
    void setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command) override;
    void getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan() override;
    ::java::util::SortedMap* scanMetadata(::rice::p2p::commonapi::IdRange* range) override;
    ::java::util::SortedMap* scanMetadata() override;
    ::java::util::SortedMap* scanMetadataValuesHead(::java::lang::Object* value) override;
    ::java::util::SortedMap* scanMetadataValuesNull() override;
    int64_t getTotalSize() override;
    int32_t getSize() override;

private:
    int32_t getSize(::java::lang::Object* obj);

    // Generated

public:
    MemoryStorage(::rice::p2p::commonapi::IdFactory* factory);
protected:
    MemoryStorage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
