// Generated from /pastry-2.1/src/rice/p2p/util/StringCache.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::StringCache_Entry
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::lang::String* value {  };
    int32_t hash {  };
    StringCache_Entry* next {  };
protected:
    void ctor(int32_t h, ::java::lang::String* v, StringCache_Entry* n);

public:
    virtual ::java::lang::String* getValue();
    bool equals(::java::lang::Object* o) override;
    int32_t hashCode() override;
    ::java::lang::String* toString() override;

    // Generated

public: /* package */
    StringCache_Entry(int32_t h, ::java::lang::String* v, StringCache_Entry* n);
protected:
    StringCache_Entry(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
    friend class StringCache;
};
