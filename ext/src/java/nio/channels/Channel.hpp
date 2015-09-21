// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/io/Closeable.hpp>

struct java::nio::channels::Channel
    : public virtual ::java::io::Closeable
{

    /*void close(); (already declared) */
    virtual bool isOpen() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
