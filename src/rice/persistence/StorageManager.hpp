// Generated from /pastry-2.1/src/rice/persistence/StorageManager.java

#pragma once

#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/persistence/Cache.hpp>
#include <rice/persistence/Storage.hpp>

struct rice::persistence::StorageManager
    : public virtual Cache
    , public virtual Storage
{
    virtual Storage* getStorage() = 0;
    virtual Cache* getCache() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
