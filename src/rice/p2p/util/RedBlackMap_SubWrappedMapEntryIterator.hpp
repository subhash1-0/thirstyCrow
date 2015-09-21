// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_SubWrappedMapEntryIterator
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    RedBlackMap_SubMapEntryIterator* iterator1 {  };
    RedBlackMap_SubMapEntryIterator* iterator2 {  };
protected:
    void ctor(RedBlackMap_Entry* first, RedBlackMap_Entry* firstExcluded);

public:
    bool hasNext() override;
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated

public: /* package */
    RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap *RedBlackMap_this, RedBlackMap_Entry* first, RedBlackMap_Entry* firstExcluded);
protected:
    RedBlackMap_SubWrappedMapEntryIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    RedBlackMap *RedBlackMap_this;

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
    friend class RedBlackMap_KeyIterator;
    friend class RedBlackMap_ValueIterator;
    friend class RedBlackMap_SubMapEntryIterator;
    friend class RedBlackMap_Entry;
};
