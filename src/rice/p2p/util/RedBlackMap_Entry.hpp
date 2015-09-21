// Generated from /pastry-2.1/src/rice/p2p/util/RedBlackMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/util/Map_Entry.hpp>

struct default_init_tag;

class rice::p2p::util::RedBlackMap_Entry
    : public virtual ::java::lang::Object
    , public virtual ::java::util::Map_Entry
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::Object* key {  };
    ::java::lang::Object* value {  };
    RedBlackMap_Entry* left {  };
    RedBlackMap_Entry* right {  };
    RedBlackMap_Entry* parent {  };
    bool color {  };
    bool deleted {  };
protected:
    void ctor(::java::lang::Object* key, ::java::lang::Object* value, RedBlackMap_Entry* parent);

public:
    ::java::lang::Object* getKey() override;
    ::java::lang::Object* getValue() override;
    ::java::lang::Object* setValue(::java::lang::Object* value) override;
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    RedBlackMap_Entry(::java::lang::Object* key, ::java::lang::Object* value, RedBlackMap_Entry* parent);
protected:
    RedBlackMap_Entry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
    friend class RedBlackMap;
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
};
