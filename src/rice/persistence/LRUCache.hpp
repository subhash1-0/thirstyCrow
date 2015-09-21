// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/environment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/persistence/Cache.hpp>

struct default_init_tag;

class rice::persistence::LRUCache
    : public virtual ::java::lang::Object
    , public virtual Cache
{

public:
    typedef ::java::lang::Object super;

private:
    int32_t maximumSize {  };
    Storage* storage {  };
    ::java::util::LinkedList* order {  };

public: /* protected */
    ::rice::environment::Environment* environment {  };
protected:
    void ctor(Storage* storage, int32_t maximumSize, ::rice::environment::Environment* env);

public:
    virtual Storage* getStorage();
    void rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c) override;
    void cache(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) override;
    void uncache(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    bool exists(::rice::p2p::commonapi::Id* id) override;
    void getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) override;
    ::java::io::Serializable* getMetadata(::rice::p2p::commonapi::Id* id) override;
    void setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command) override;
    ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) override;
    ::rice::p2p::commonapi::IdSet* scan() override;
    ::java::util::SortedMap* scanMetadata(::rice::p2p::commonapi::IdRange* range) override;
    ::java::util::SortedMap* scanMetadata() override;
    ::java::util::SortedMap* scanMetadataValuesHead(::java::lang::Object* value) override;
    ::java::util::SortedMap* scanMetadataValuesNull() override;
    int64_t getMaximumSize() override;
    int32_t getSize() override;
    int64_t getTotalSize() override;
    void setMaximumSize(int32_t size, ::rice::Continuation* c) override;

private:
    void resize(int32_t size, ::rice::Continuation* c);
    int32_t getSize(::java::lang::Object* obj);

public:
    void flush(::rice::Continuation* c) override;

    // Generated
    LRUCache(Storage* storage, int32_t maximumSize, ::rice::environment::Environment* env);
protected:
    LRUCache(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class LRUCache_rename_1;
    friend class LRUCache_cache_2;
    friend class LRUCache_setMaximumSize_3;
    friend class LRUCache_resize_4;
    friend class LRUCache_flush_5;
};
