// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/io/InterruptedIOException.hpp>

struct default_init_tag;

class java::net::SocketTimeoutException
    : public ::java::io::InterruptedIOException
{

public:
    typedef ::java::io::InterruptedIOException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-8846654841826352300LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    SocketTimeoutException();
    SocketTimeoutException(::java::lang::String* arg0);
protected:
    SocketTimeoutException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
