// Generated from /pastry-2.1/src/rice/environment/processing/simple/WorkQueueOverflowException.java

#pragma once

#include <rice/environment/processing/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Exception.hpp>

struct default_init_tag;

class rice::environment::processing::simple::WorkQueueOverflowException
    : public ::java::lang::Exception
{

public:
    typedef ::java::lang::Exception super;

    // Generated
    WorkQueueOverflowException();
protected:
    WorkQueueOverflowException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
