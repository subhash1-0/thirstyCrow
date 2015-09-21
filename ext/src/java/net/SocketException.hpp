// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/net/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class java::net::SocketException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-5935874303556886934LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    SocketException();
    SocketException(::java::lang::String* arg0);
protected:
    SocketException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
