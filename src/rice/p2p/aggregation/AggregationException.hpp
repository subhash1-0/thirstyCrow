// Generated from /pastry-2.1/src/rice/p2p/aggregation/AggregationException.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/aggregation/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class rice::p2p::aggregation::AggregationException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;
protected:
    void ctor(::java::lang::String* msg);

    // Generated

public:
    AggregationException(::java::lang::String* msg);
protected:
    AggregationException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
