// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/SortedMap.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCIdFactory_GCSortedMap
    : public virtual ::java::lang::Object
    , public virtual ::java::util::SortedMap
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::SortedMap* map {  };
protected:
    void ctor(::java::util::SortedMap* map);

public:
    ::java::util::Comparator* comparator() override;
    ::java::lang::Object* firstKey() override;
    ::java::util::SortedMap* headMap(::java::lang::Object* toKey) override;
    ::java::lang::Object* lastKey() override;
    ::java::util::SortedMap* subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey) override;
    ::java::util::SortedMap* tailMap(::java::lang::Object* fromKey) override;
    void clear() override;
    bool containsKey(::java::lang::Object* key) override;
    bool containsValue(::java::lang::Object* value) override;
    ::java::util::Set* entrySet() override;
    bool equals(::java::lang::Object* o) override;
    ::java::lang::Object* get(::java::lang::Object* key) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    ::java::util::Set* keySet() override;
    ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* value) override;
    void putAll(::java::util::Map* t) override;
    ::java::lang::Object* remove(::java::lang::Object* key) override;
    int32_t size() override;
    ::java::util::Collection* values() override;

    // Generated
    GCIdFactory_GCSortedMap(GCIdFactory *GCIdFactory_this, ::java::util::SortedMap* map);
protected:
    GCIdFactory_GCSortedMap(GCIdFactory *GCIdFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool remove(::java::lang::Object* key, ::java::lang::Object* value);
    GCIdFactory *GCIdFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCIdFactory;
    friend class GCIdFactory_GCEntrySet;
    friend class GCIdFactory_GCEntrySet_iterator_1;
    friend class GCIdFactory_GCMapEntry;
};
