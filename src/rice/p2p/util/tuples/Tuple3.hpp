// Generated from /pastry-2.1/src/rice/p2p/util/tuples/Tuple3.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class rice::p2p::util::tuples::Tuple3
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

public: /* protected */
    ::java::lang::Object* a_ {  };
    ::java::lang::Object* b_ {  };
    ::java::lang::Object* c_ {  };
protected:
    void ctor(::java::lang::Object* a, ::java::lang::Object* b, ::java::lang::Object* c);

public:
    virtual ::java::lang::Object* a();
    virtual ::java::lang::Object* b();
    virtual ::java::lang::Object* c();
    bool equals(::java::lang::Object* obj) override;
    int32_t hashCode() override;

    // Generated
    Tuple3(::java::lang::Object* a, ::java::lang::Object* b, ::java::lang::Object* c);
protected:
    Tuple3(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
