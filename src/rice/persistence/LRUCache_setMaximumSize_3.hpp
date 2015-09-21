// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class rice::persistence::LRUCache_setMaximumSize_3
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveResult(::java::lang::Object* o) override;
    void receiveException(::java::lang::Exception* e) override;

    // Generated
    LRUCache_setMaximumSize_3(LRUCache *LRUCache_this, int32_t size, ::rice::Continuation* c);
    static ::java::lang::Class *class_();
    LRUCache *LRUCache_this;
    int32_t size;
    ::rice::Continuation* c;

private:
    virtual ::java::lang::Class* getClass0();
    friend class LRUCache;
    friend class LRUCache_rename_1;
    friend class LRUCache_cache_2;
    friend class LRUCache_resize_4;
    friend class LRUCache_flush_5;
};
