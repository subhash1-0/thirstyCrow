// Generated from /pastry-2.1/src/rice/p2p/past/gc/GCPastException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/gc/fwd-pastry-2.1.hpp>
#include <rice/p2p/past/PastException.hpp>

struct default_init_tag;

class rice::p2p::past::gc::GCPastException_ObjectNotFoundException
    : public ::rice::p2p::past::PastException
{

public:
    typedef ::rice::p2p::past::PastException super;
protected:
    void ctor(::java::lang::String* msg);

    // Generated

public:
    GCPastException_ObjectNotFoundException(GCPastException *GCPastException_this, ::java::lang::String* msg);
protected:
    GCPastException_ObjectNotFoundException(GCPastException *GCPastException_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    GCPastException *GCPastException_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class GCPastException;
};
