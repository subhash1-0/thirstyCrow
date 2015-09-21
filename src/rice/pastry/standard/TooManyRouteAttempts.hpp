// Generated from /pastry-2.1/src/rice/pastry/standard/TooManyRouteAttempts.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/pastry/routing/fwd-pastry-2.1.hpp>
#include <rice/pastry/standard/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class rice::pastry::standard::TooManyRouteAttempts
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;
protected:
    void ctor(::rice::pastry::routing::RouteMessage* rm, int32_t max_retries);

    // Generated

public:
    TooManyRouteAttempts(::rice::pastry::routing::RouteMessage* rm, int32_t max_retries);
protected:
    TooManyRouteAttempts(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
