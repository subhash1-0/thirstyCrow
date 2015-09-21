// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::persistence::LRUCache_cache_2
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    LRUCache_cache_2(LRUCache *LRUCache_this, ::rice::p2p::commonapi::Id* id, ::java::io::Serializable* metadata, ::java::io::Serializable* obj, ::rice::Continuation* c);
    static ::java::lang::Class *class_();
    LRUCache *LRUCache_this;
    ::rice::p2p::commonapi::Id* id;
    ::java::io::Serializable* metadata;
    ::java::io::Serializable* obj;
    ::rice::Continuation* c;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LRUCache;
    friend class LRUCache_rename_1;
    friend class LRUCache_setMaximumSize_3;
    friend class LRUCache_resize_4;
    friend class LRUCache_flush_5;
};
