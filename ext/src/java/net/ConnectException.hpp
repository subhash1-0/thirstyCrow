// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/net/SocketException.hpp>

struct default_init_tag;

class java::net::ConnectException
    : public SocketException
{

public:
    typedef SocketException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(3831404271622369215LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    ConnectException();
    ConnectException(::java::lang::String* arg0);
protected:
    ConnectException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
