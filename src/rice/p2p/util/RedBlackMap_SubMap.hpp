// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/SortedMap.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_SubMap
    : public ::java::util::AbstractMap
    , public virtual ::java::util::SortedMap
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::util::AbstractMap super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-6520786458950516097LL) };
    bool fromStart {  }, toEnd {  };
    ::java::lang::Object* fromKey {  };
    ::java::lang::Object* toKey {  };
protected:
    void ctor(::java::lang::Object* fromKey, ::java::lang::Object* toKey);
    void ctor(::java::lang::Object* key, bool headMap);
    void ctor(bool fromStart, ::java::lang::Object* fromKey, bool toEnd, ::java::lang::Object* toKey);

public:
    bool isEmpty() override;
    bool containsKey(::java::lang::Object* key) override;
    ::java::lang::Object* get(::java::lang::Object* key) override;
    ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* value) override;
    ::java::util::Comparator* comparator() override;
    ::java::lang::Object* firstKey() override;
    ::java::lang::Object* lastKey() override;

private:
    ::java::util::Set* entrySet_ {  };

public:
    ::java::util::Set* entrySet() override;

public: /* protected */
    virtual ::java::lang::Object* putInRange(::java::lang::Object* key);

public:
    ::java::util::SortedMap* subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey) override;
    ::java::util::SortedMap* headMap(::java::lang::Object* toKey) override;
    ::java::util::SortedMap* tailMap(::java::lang::Object* fromKey) override;

private:
    bool inRange(::java::lang::Object* key);
    bool inRange2(::java::lang::Object* key);

    // Generated

public: /* package */
    RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, ::java::lang::Object* fromKey, ::java::lang::Object* toKey);
    RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, ::java::lang::Object* key, bool headMap);
    RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, bool fromStart, ::java::lang::Object* fromKey, bool toEnd, ::java::lang::Object* toKey);
protected:
    RedBlackMap_SubMap(RedBlackMap *RedBlackMap_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void clear();
    virtual bool containsValue(::java::lang::Object* value);
    virtual bool equals(::java::lang::Object* o);
    virtual int32_t hashCode();
    virtual void putAll(::java::util::Map* m);
    virtual ::java::lang::Object* remove(::java::lang::Object* key);
    virtual int32_t size();
    ::java::util::Set* keySet();
    ::java::util::Collection* values();
    virtual bool remove(::java::lang::Object* key, ::java::lang::Object* value);
    RedBlackMap *RedBlackMap_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class RedBlackMap;
    friend class RedBlackMap_keySet_1;
    friend class RedBlackMap_values_2;
    friend class RedBlackMap_entrySet_3;
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
