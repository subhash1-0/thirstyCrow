// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class java::io::UnsupportedEncodingException
    : public IOException
{

public:
    typedef IOException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-4274276298326136670LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);

    // Generated

public:
    UnsupportedEncodingException();
    UnsupportedEncodingException(::java::lang::String* arg0);
protected:
    UnsupportedEncodingException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
