// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/RedBlackMap_EntryIterator.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_KeyIterator
    : public RedBlackMap_EntryIterator
{

public:
    typedef RedBlackMap_EntryIterator super;
    ::java::lang::Object* next() override;

    // Generated
    RedBlackMap_KeyIterator(RedBlackMap *RedBlackMap_this);
protected:
    RedBlackMap_KeyIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class RedBlackMap;
    friend class RedBlackMap_keySet_1;
    friend class RedBlackMap_values_2;
    friend class RedBlackMap_entrySet_3;
    friend class RedBlackMap_SubMap;
    friend class RedBlackMap_SubMap_EntrySetView;
    friend class RedBlackMap_SubWrappedMap;
    friend class RedBlackMap_SubWrappedMap_EntrySetView;
    friend class RedBlackMap_EntryIterator;
    friend class RedBlackMap_ValueIterator;
    friend class RedBlackMap_SubMapEntryIterator;
    friend class RedBlackMap_SubWrappedMapEntryIterator;
    friend class RedBlackMap_Entry;
};
