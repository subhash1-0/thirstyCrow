// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class java::io::FileNotFoundException
    : public IOException
{

public:
    typedef IOException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(-897856973823710492LL) };

protected:
    void ctor();
    void ctor(::java::lang::String* arg0);
    /*void ctor(::java::lang::String* arg0, ::java::lang::String* arg1); (private) */

    // Generated

public:
    FileNotFoundException();
    FileNotFoundException(::java::lang::String* arg0);
protected:
    FileNotFoundException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
