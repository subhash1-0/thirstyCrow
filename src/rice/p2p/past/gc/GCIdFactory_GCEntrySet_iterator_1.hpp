// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCIdFactory_GCEntrySet_iterator_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Iterator* i {  };

public:
    bool hasNext() override;
    ::java::lang::Object* next() override;
    void remove() override;

    // Generated
    GCIdFactory_GCEntrySet_iterator_1(GCIdFactory_GCEntrySet *GCIdFactory_GCEntrySet_this);
    static ::java::lang::Class *class_();

private:
    void init();
    GCIdFactory_GCEntrySet *GCIdFactory_GCEntrySet_this;
    virtual ::java::lang::Class* getClass0();
    friend class GCIdFactory;
    friend class GCIdFactory_GCSortedMap;
    friend class GCIdFactory_GCEntrySet;
    friend class GCIdFactory_GCMapEntry;
};
