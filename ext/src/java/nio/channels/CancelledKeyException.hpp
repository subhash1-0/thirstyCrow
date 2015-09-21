// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/lang/IllegalStateException.hpp>

struct default_init_tag;

class java::nio::channels::CancelledKeyException
    : public ::java::lang::IllegalStateException
{

public:
    typedef ::java::lang::IllegalStateException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-8438032138028814268LL) };

protected:
    void ctor();

    // Generated

public:
    CancelledKeyException();
protected:
    CancelledKeyException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
