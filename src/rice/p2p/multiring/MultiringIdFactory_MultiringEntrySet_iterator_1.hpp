// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Iterator.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringIdFactory_MultiringEntrySet_iterator_1
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
    MultiringIdFactory_MultiringEntrySet_iterator_1(MultiringIdFactory_MultiringEntrySet *MultiringIdFactory_MultiringEntrySet_this);
    static ::java::lang::Class *class_();

private:
    void init();
    MultiringIdFactory_MultiringEntrySet *MultiringIdFactory_MultiringEntrySet_this;
    virtual ::java::lang::Class* getClass0();
    friend class MultiringIdFactory;
    friend class MultiringIdFactory_MultiringSortedMap;
    friend class MultiringIdFactory_MultiringEntrySet;
    friend class MultiringIdFactory_MultiringKeySet;
    friend class MultiringIdFactory_MultiringKeySet_iterator_1;
    friend class MultiringIdFactory_MultiringMapEntry;
};
