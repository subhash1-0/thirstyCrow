// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCIdSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCIdSet_getIterator_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::util::Iterator* i {  };

public:
    bool hasNext() override;
    ::rice::p2p::commonapi::Id* next() override;
    void remove() override;

    // Generated
    GCIdSet_getIterator_1(GCIdSet *GCIdSet_this);
    static ::java::lang::Class *class_();

private:
    void init();
    GCIdSet *GCIdSet_this;
    virtual ::java::lang::Class* getClass0();
    friend class GCIdSet;
};
