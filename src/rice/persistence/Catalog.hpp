// Generated from /pastry-2.1/src/rice/persistence/Catalog.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct rice::persistence::Catalog
    : public virtual ::java::lang::Object
{
    virtual bool exists(::rice::p2p::commonapi::Id* id) = 0;
    virtual void getObject(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) = 0;
    virtual ::java::io::Serializable* getMetadata(::rice::p2p::commonapi::Id* id) = 0;
    virtual void setMetadata(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::rice::Continuation* command) = 0;
    virtual void rename(::rice::p2p::commonapi::Id* oldId, ::rice::p2p::commonapi::Id* newId, ::rice::Continuation* c) = 0;
    virtual ::rice::p2p::commonapi::IdSet* scan(::rice::p2p::commonapi::IdRange* range) = 0;
    virtual ::rice::p2p::commonapi::IdSet* scan() = 0;
    virtual ::java::util::SortedMap* scanMetadata(::rice::p2p::commonapi::IdRange* range) = 0;
    virtual ::java::util::SortedMap* scanMetadata() = 0;
    virtual ::java::util::SortedMap* scanMetadataValuesHead(::java::lang::Object* value) = 0;
    virtual ::java::util::SortedMap* scanMetadataValuesNull() = 0;
    virtual int32_t getSize() = 0;
    virtual int64_t getTotalSize() = 0;
    virtual void flush(::rice::Continuation* c) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
