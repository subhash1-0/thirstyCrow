// Generated from /pastry-2.1/src/rice/p2p/util/tuples/MutableTuple.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>

struct default_init_tag;

class rice::p2p::util::tuples::MutableTuple
    : public Tuple
{

public:
    typedef Tuple super;
protected:
    void ctor(::java::lang::Object* a, ::java::lang::Object* b);
    void ctor();

public:
    virtual void set(::java::lang::Object* a, ::java::lang::Object* b);
    virtual void setA(::java::lang::Object* a);
    virtual void setB(::java::lang::Object* b);

    // Generated
    MutableTuple(::java::lang::Object* a, ::java::lang::Object* b);
    MutableTuple();
protected:
    MutableTuple(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
