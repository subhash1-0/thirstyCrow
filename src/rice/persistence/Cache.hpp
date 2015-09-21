// Generated from /pastry-2.1/src/rice/persistence/Cache.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/persistence/Catalog.hpp>

struct rice::persistence::Cache
    : public virtual Catalog
{
    virtual void cache(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) = 0;
    virtual void uncache(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) = 0;
    virtual int64_t getMaximumSize() = 0;
    virtual void setMaximumSize(int32_t size, ::rice::Continuation* c) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
