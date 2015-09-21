// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Set.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCIdFactory_GCEntrySet
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Set
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Set* set {  };
protected:
    void ctor(::java::util::Set* set);

public:
    bool add(::java::lang::Object* o) override;
    bool addAll(::java::util::Collection* c) override;
    void clear() override;
    bool contains(::java::lang::Object* o) override;
    bool containsAll(::java::util::Collection* c) override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    bool isEmpty() override;
    ::java::util::Iterator* iterator() override;
    bool remove(::java::lang::Object* o) override;
    bool removeAll(::java::util::Collection* c) override;
    bool retainAll(::java::util::Collection* c) override;
    int32_t size() override;
    ::java::lang::ObjectArray* toArray_() override;
    ::java::lang::ObjectArray* toArray_(::java::lang::ObjectArray* a) override;

    // Generated
    GCIdFactory_GCEntrySet(GCIdFactory *GCIdFactory_this, ::java::util::Set* set);
protected:
    GCIdFactory_GCEntrySet(GCIdFactory *GCIdFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    GCIdFactory *GCIdFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCIdFactory;
    friend class GCIdFactory_GCSortedMap;
    friend class GCIdFactory_GCEntrySet_iterator_1;
    friend class GCIdFactory_GCMapEntry;
};
