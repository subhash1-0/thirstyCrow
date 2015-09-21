// Generated from /pastry-2.1/src/rice/p2p/util/tuples/Tuple.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::tuples::Tuple
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* a_ {  };
    ::java::lang::Object* b_ {  };
protected:
    void ctor(::java::lang::Object* a, ::java::lang::Object* b);

public:
    virtual ::java::lang::Object* a();
    virtual ::java::lang::Object* b();
    bool equals(::java::lang::Object* obj) override;
    int32_t hashCode() override;

    // Generated
    Tuple(::java::lang::Object* a, ::java::lang::Object* b);
protected:
    Tuple(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
