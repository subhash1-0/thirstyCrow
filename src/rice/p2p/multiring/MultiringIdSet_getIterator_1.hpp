// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdSet.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>
#include <rice/p2p/commonapi/Id.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringIdSet_getIterator_1
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Iterator
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::Iterator* i {  };

public:
    bool hasNext() override;
    ::rice::p2p::commonapi::Id* next() override;
    void remove() override;

    // Generated
    MultiringIdSet_getIterator_1(MultiringIdSet *MultiringIdSet_this);
    static ::java::lang::Class *class_();

private:
    void init();
    MultiringIdSet *MultiringIdSet_this;
    virtual ::java::lang::Class* getClass0();
    friend class MultiringIdSet;
};
