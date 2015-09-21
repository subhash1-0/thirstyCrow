// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <atomic>
#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/util/AbstractMap.hpp>
#include <java/util/SortedMap.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap
    : public ::java::util::AbstractMap
    , public virtual ::java::util::SortedMap
    , public virtual ::java::lang::Cloneable
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::util::AbstractMap super;

private:
    ::java::util::Comparator* comparator_ {  };
    RedBlackMap_Entry* root {  };
    int32_t size_ {  };
    int32_t modCount {  };
    void incrementSize();
    void decrementSize();
protected:
    void ctor();
    void ctor(::java::util::Comparator* c);
    void ctor(::java::util::Map* m);
    void ctor(::java::util::SortedMap* m);

public:
    int32_t size() override;
    bool containsKey(::java::lang::Object* key) override;
    bool containsValue(::java::lang::Object* value) override;

private:
    bool valueSearchNull(RedBlackMap_Entry* n);
    bool valueSearchNonNull(RedBlackMap_Entry* n, ::java::lang::Object* value);

public:
    ::java::lang::Object* get(::java::lang::Object* key) override;
    ::java::util::Comparator* comparator() override;
    ::java::lang::Object* firstKey() override;
    ::java::lang::Object* lastKey() override;
    void putAll(::java::util::Map* map) override;

private:
    RedBlackMap_Entry* getEntry(::java::lang::Object* key);
    RedBlackMap_Entry* getCeilEntry(::java::lang::Object* key);
    RedBlackMap_Entry* getPrecedingEntry(::java::lang::Object* key);
    static ::java::lang::Object* key(RedBlackMap_Entry* e);

public:
    ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* value) override;
    ::java::lang::Object* remove(::java::lang::Object* key) override;
    virtual ::java::lang::Object* getKey(::java::lang::Object* key);
    void clear() override;
    ::java::lang::Object* clone() override;

private:
    std::atomic< ::java::util::Set* > entrySet_ {  };
    std::atomic< ::java::util::Set* > keySet_ {  };
    std::atomic< ::java::util::Collection* > values_ {  };

public:
    ::java::util::Set* keySet() override;
    ::java::util::Collection* values() override;
    ::java::util::Set* entrySet() override;
    ::java::util::SortedMap* subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey) override;
    ::java::util::SortedMap* headMap(::java::lang::Object* toKey) override;
    ::java::util::SortedMap* tailMap(::java::lang::Object* fromKey) override;

private:
    int32_t compare(::java::lang::Object* k1, ::java::lang::Object* k2);
    static bool valEquals(::java::lang::Object* o1, ::java::lang::Object* o2);
    static constexpr bool RED { false };
    static constexpr bool BLACK { true };
    RedBlackMap_Entry* firstEntry();
    RedBlackMap_Entry* lastEntry();
    RedBlackMap_Entry* successor(RedBlackMap_Entry* t);
    static bool colorOf(RedBlackMap_Entry* p);
    static RedBlackMap_Entry* parentOf(RedBlackMap_Entry* p);
    static void setColor(RedBlackMap_Entry* p, bool c);
    static RedBlackMap_Entry* leftOf(RedBlackMap_Entry* p);
    static RedBlackMap_Entry* rightOf(RedBlackMap_Entry* p);
    void rotateLeft(RedBlackMap_Entry* p);
    void rotateRight(RedBlackMap_Entry* p);
    void fixAfterInsertion(RedBlackMap_Entry* x);
    void deleteEntry(RedBlackMap_Entry* p);
    void fixAfterDeletion(RedBlackMap_Entry* x);
    static constexpr int64_t serialVersionUID { int64_t(919286545866124006LL) };
    void writeObject(::java::io::ObjectOutputStream* s) /* throws(java.io.IOException) */;
    void readObject(::java::io::ObjectInputStream* s) /* throws(java.io.IOException, ClassNotFoundException) */;

public: /* package */
    virtual void readTreeSet(int32_t size, ::java::io::ObjectInputStream* s, ::java::lang::Object* defaultVal) /* throws(java.io.IOException, ClassNotFoundException) */;
    virtual void addAllForTreeSet(::java::util::SortedSet* set, ::java::lang::Object* defaultVal);

private:
    void buildFromSorted(int32_t size, ::java::util::Iterator* it, ::java::io::ObjectInputStream* str, ::java::lang::Object* defaultVal) /* throws(java.io.IOException, ClassNotFoundException) */;
    static RedBlackMap_Entry* buildFromSorted(int32_t level, int32_t lo, int32_t hi, int32_t redLevel, ::java::util::Iterator* it, ::java::io::ObjectInputStream* str, ::java::lang::Object* defaultVal) /* throws(java.io.IOException, ClassNotFoundException) */;
    static int32_t computeRedLevel(int32_t sz);

    // Generated

public:
    RedBlackMap();
    RedBlackMap(::java::util::Comparator* c);
    RedBlackMap(::java::util::Map* m);
    RedBlackMap(::java::util::SortedMap* m);
protected:
    RedBlackMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual bool equals(::java::lang::Object* o);
    virtual int32_t hashCode();
    virtual bool isEmpty();
    virtual bool remove(::java::lang::Object* key, ::java::lang::Object* value);

private:
    virtual ::java::lang::Class* getClass0();
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
    friend class RedBlackMap_SubWrappedMapEntryIterator;
    friend class RedBlackMap_Entry;
};
