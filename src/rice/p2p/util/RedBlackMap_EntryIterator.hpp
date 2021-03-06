// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_EntryIterator
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

private:
    RedBlackMap_Entry* lastReturned {  };

public: /* protected */
    RedBlackMap_Entry* next_ {  };
protected:
    void ctor();
    void ctor(RedBlackMap_Entry* first);

public:
    bool hasNext() override;

public: /* package */
    RedBlackMap_Entry* nextEntry();

public:
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated

public: /* package */
    RedBlackMap_EntryIterator(RedBlackMap *RedBlackMap_this);
    RedBlackMap_EntryIterator(RedBlackMap *RedBlackMap_this, RedBlackMap_Entry* first);
protected:
    RedBlackMap_EntryIterator(RedBlackMap *RedBlackMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    RedBlackMap *RedBlackMap_this;
    virtual ::java::lang::Class* getClass0();
    friend class RedBlackMap;
    friend class RedBlackMap_keySet_1;
    friend class RedBlackMap_values_2;
    friend class RedBlackMap_entrySet_3;
    friend class RedBlackMap_SubMap;
    friend class RedBlackMap_SubMap_EntrySetView;
    friend class RedBlackMap_SubWrappedMap;
    friend class RedBlackMap_SubWrappedMap_EntrySetView;
    friend class RedBlackMap_KeyIterator;
    friend class RedBlackMap_ValueIterator;
    friend class RedBlackMap_SubMapEntryIterator;
    friend class RedBlackMap_SubWrappedMapEntryIterator;
    friend class RedBlackMap_Entry;
};
