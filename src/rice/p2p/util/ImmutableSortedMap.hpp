// Generated from /pastry-2.1/src/rice/p2p/util/ImmutableSortedMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/SortedMap.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::ImmutableSortedMap
    : public virtual ::java::lang::Object
    , public virtual ::java::util::SortedMap
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::SortedMap* map {  };
protected:
    void ctor(::java::util::SortedMap* map);

public:
    ::java::util::Comparator* comparator() override;
    ::java::util::SortedMap* subMap(::java::lang::Object* fromKey, ::java::lang::Object* toKey) override;
    ::java::util::SortedMap* headMap(::java::lang::Object* toKey) override;
    ::java::util::SortedMap* tailMap(::java::lang::Object* fromKey) override;
    ::java::lang::Object* firstKey() override;
    ::java::lang::Object* lastKey() override;
    int32_t size() override;
    bool isEmpty() override;
    bool containsKey(::java::lang::Object* key) override;
    bool containsValue(::java::lang::Object* value) override;
    ::java::lang::Object* get(::java::lang::Object* key) override;
    ::java::lang::Object* put(::java::lang::Object* key, ::java::lang::Object* value) override;
    ::java::lang::Object* remove(::java::lang::Object* key) override;
    void putAll(::java::util::Map* t) override;
    void clear() override;
    ::java::util::Set* keySet() override;
    ::java::util::Collection* values() override;
    ::java::util::Set* entrySet() override;

    // Generated
    ImmutableSortedMap(::java::util::SortedMap* map);
protected:
    ImmutableSortedMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual bool equals(::java::lang::Object* arg0);
    virtual int32_t hashCode();
    virtual bool remove(::java::lang::Object* arg0, ::java::lang::Object* arg1);

private:
    virtual ::java::lang::Class* getClass0();
};
