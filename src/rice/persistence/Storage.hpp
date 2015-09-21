// Generated from /pastry-2.1/src/rice/persistence/Storage.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/persistence/Catalog.hpp>

struct rice::persistence::Storage
    : public virtual Catalog
{
    virtual void store(::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c) = 0;
    virtual void unstore(::rice::p2p::commonapi::Id* id, ::rice::Continuation* c) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
