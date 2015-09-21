// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCIdFactory_GCMapEntry
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Map_Entry
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Map_Entry* entry {  };
protected:
    void ctor(::java::util::Map_Entry* entry);

public:
    bool equals(::java::lang::Object* o) override;
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    int32_t hashCode() override;
    ::java::lang::Object* setValue(::java::lang::Object* value) override;

    // Generated
    GCIdFactory_GCMapEntry(GCIdFactory *GCIdFactory_this, ::java::util::Map_Entry* entry);
protected:
    GCIdFactory_GCMapEntry(GCIdFactory *GCIdFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    GCIdFactory *GCIdFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCIdFactory;
    friend class GCIdFactory_GCSortedMap;
    friend class GCIdFactory_GCEntrySet;
    friend class GCIdFactory_GCEntrySet_iterator_1;
};
