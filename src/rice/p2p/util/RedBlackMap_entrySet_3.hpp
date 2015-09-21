// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_entrySet_3
    : public ::java::util::AbstractSet
{

public:
    typedef ::java::util::AbstractSet super;
    ::java::util::Iterator* iterator() override;
    bool contains(::java::lang::Object* o) override;
    bool remove(::java::lang::Object* o) override;
    int32_t size() override;
    void clear() override;

    // Generated

public: /* protected */
    RedBlackMap_entrySet_3(RedBlackMap *RedBlackMap_this);

public:
    static ::java::lang::Class *class_();
    RedBlackMap *RedBlackMap_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RedBlackMap;
    friend class RedBlackMap_keySet_1;
    friend class RedBlackMap_values_2;
    friend class RedBlackMap_SubMap;
    friend class RedBlackMap_SubMap_EntrySetView;
    friend class RedBlackMap_SubWrappedMap;
    friend class RedBlackMap_SubWrappedMap_EntrySetView;
    friend class RedBlackMap_EntryIterator;
    friend class RedBlackMap_KeyIterator;
    friend class RedBlackMap_ValueIterator;
    friend class RedBlackMap_SubMapEntryIterator;
    friend class RedBlackMap_SubWrappedMapEntryIterator;
    friend class RedBlackMap_Entry;
};
