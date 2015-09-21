// Generated from /pastry-2.1/src/rice/p2p/commonapi/rawserialization/SizeCheckOutputBuffer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>

struct rice::p2p::commonapi::rawserialization::SizeCheckOutputBuffer
    : public virtual OutputBuffer
{
    virtual void writeSpecial(::java::lang::Object* o) /* throws(IOException) */ = 0;
    virtual int32_t bytesWritten() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
