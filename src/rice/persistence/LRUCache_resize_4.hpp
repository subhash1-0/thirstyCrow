// Generated from /pastry-2.1/src/rice/persistence/LRUCache.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <rice/persistence/fwd-pastry-2.1.hpp>
#include <rice/Continuation_StandardContinuation.hpp>

struct default_init_tag;

class rice::persistence::LRUCache_resize_4
    : public ::rice::Continuation_StandardContinuation
{

public:
    typedef ::rice::Continuation_StandardContinuation super;

private:
    bool waitingForSize {  };

public:
    void receiveResult(::java::lang::Object* o) override;

    // Generated
    LRUCache_resize_4(LRUCache *LRUCache_this, int32_t size, ::rice::Continuation* continuation);
    static ::java::lang::Class *class_();

private:
    void init();
    LRUCache *LRUCache_this;
    int32_t size;
    virtual ::java::lang::Class* getClass0();
    friend class LRUCache;
    friend class LRUCache_rename_1;
    friend class LRUCache_cache_2;
    friend class LRUCache_setMaximumSize_3;
    friend class LRUCache_flush_5;
};
