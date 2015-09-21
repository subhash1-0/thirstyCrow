// Generated from /pastry-2.1/src/rice/p2p/multiring/MultiringIdFactory.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/multiring/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class rice::p2p::multiring::MultiringIdFactory_MultiringMapEntry
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
    MultiringIdFactory_MultiringMapEntry(MultiringIdFactory *MultiringIdFactory_this, ::java::util::Map_Entry* entry);
protected:
    MultiringIdFactory_MultiringMapEntry(MultiringIdFactory *MultiringIdFactory_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    MultiringIdFactory *MultiringIdFactory_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class MultiringIdFactory;
    friend class MultiringIdFactory_MultiringSortedMap;
    friend class MultiringIdFactory_MultiringEntrySet;
    friend class MultiringIdFactory_MultiringEntrySet_iterator_1;
    friend class MultiringIdFactory_MultiringKeySet;
    friend class MultiringIdFactory_MultiringKeySet_iterator_1;
};
