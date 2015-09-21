// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractSet.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_SubMap_EntrySetView
    : public ::java::util::AbstractSet
{

public:
    typedef ::java::util::AbstractSet super;

private:
    int32_t size_ {  }, sizeModCount {  };

public:
    int32_t size() override;
    bool isEmpty() override;
    bool contains(::java::lang::Object* o) override;
    bool remove(::java::lang::Object* o) override;
    ::java::util::Iterator* iterator() override;

    // Generated
    RedBlackMap_SubMap_EntrySetView(RedBlackMap_SubMap *RedBlackMap_SubMap_this);
protected:
    void ctor();
    RedBlackMap_SubMap_EntrySetView(RedBlackMap_SubMap *RedBlackMap_SubMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    RedBlackMap_SubMap *RedBlackMap_SubMap_this;
    virtual ::java::lang::Class* getClass0();
    friend class RedBlackMap;
    friend class RedBlackMap_keySet_1;
    friend class RedBlackMap_values_2;
    friend class RedBlackMap_entrySet_3;
    friend class RedBlackMap_SubMap;
    friend class RedBlackMap_SubWrappedMap;
    friend class RedBlackMap_SubWrappedMap_EntrySetView;
    friend class RedBlackMap_EntryIterator;
    friend class RedBlackMap_KeyIterator;
    friend class RedBlackMap_ValueIterator;
    friend class RedBlackMap_SubMapEntryIterator;
    friend class RedBlackMap_SubWrappedMapEntryIterator;
    friend class RedBlackMap_Entry;
};
