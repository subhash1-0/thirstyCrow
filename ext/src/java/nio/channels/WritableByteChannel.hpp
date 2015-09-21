// Generated from C:/Program Files/Java/jre1.8.0_51/lib/rt.jar

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/nio/channels/fwd-pastry-2.1.hpp>
#include <java/nio/channels/Channel.hpp>

struct java::nio::channels::WritableByteChannel
    : public virtual Channel
{

    virtual int32_t write(::java::nio::ByteBuffer* arg0) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
