// Generated from /pastry-2.1/src/rice/p2p/util/ReverseTreeMap.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <java/io/Serializable.hpp>

struct default_init_tag;

class rice::p2p::util::ReverseTreeMap
    : public virtual ::java::lang::Object
    , public virtual ::java::io::Serializable
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::util::SortedMap* normal {  };
    ::java::util::SortedMap* reverse {  };
    ::java::util::SortedMap* nulls {  };
protected:
    void ctor();
    void ctor(::java::util::SortedMap* normal, ::java::util::SortedMap* reverse, ::java::util::SortedMap* nulls);

public:
    virtual int32_t size();
    virtual bool containsKey(::java::lang::Object* key);
    virtual ::java::lang::Object* get(::java::lang::Object* key);
    virtual ::java::util::Set* keySet();
    virtual void remove(::java::lang::Object* key);
    virtual void put(::java::lang::Object* key, ::java::lang::Object* value);
    virtual ::java::util::SortedMap* keyMap();
    virtual ::java::util::SortedMap* keyHeadMap(::java::lang::Object* value);
    virtual ::java::util::SortedMap* keyTailMap(::java::lang::Object* value);
    virtual ::java::util::SortedMap* keySubMap(::java::lang::Object* start, ::java::lang::Object* end);
    virtual ::java::util::SortedMap* valueHeadMap(::java::lang::Object* value);
    virtual ::java::util::SortedMap* valueTailMap(::java::lang::Object* value);
    virtual ::java::util::SortedMap* valueSubMap(::java::lang::Object* start, ::java::lang::Object* end);
    virtual ::java::util::SortedMap* valueNullMap();

public: /* protected */
    virtual ::java::util::SortedMap* convert(::java::util::SortedMap* map);

    // Generated

public:
    ReverseTreeMap();

public: /* protected */
    ReverseTreeMap(::java::util::SortedMap* normal, ::java::util::SortedMap* reverse, ::java::util::SortedMap* nulls);
protected:
    ReverseTreeMap(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
