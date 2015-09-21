// Generated from /pastry-2.1/src/rice/environment/time/simple/SimpleTimeSource.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <rice/environment/time/simple/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/environment/time/TimeSource.hpp>

struct default_init_tag;

class rice::environment::time::simple::SimpleTimeSource
    : public virtual ::java::lang::Object
    , public virtual ::rice::environment::time::TimeSource
{

public:
    typedef ::java::lang::Object super;
protected:
    void ctor();

public:
    int64_t currentTimeMillis() override;
    void sleep(int64_t delay) /* throws(InterruptedException) */ override;
    void destroy() override;

    // Generated
    SimpleTimeSource();
protected:
    SimpleTimeSource(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
