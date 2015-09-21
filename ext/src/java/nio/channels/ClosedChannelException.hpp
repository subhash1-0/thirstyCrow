// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/io/IOException.hpp>

struct default_init_tag;

class java::nio::channels::ClosedChannelException
    : public ::java::io::IOException
{

public:
    typedef ::java::io::IOException super;

private:
    static constexpr int64_t serialVersionUID { int64_t(882777185433553857LL) };

protected:
    void ctor();

    // Generated

public:
    ClosedChannelException();
protected:
    ClosedChannelException(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
