// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/MessageInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/priority/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::priority::MessageInfo
    : public virtual ::java::lang::Object
{
    virtual ::java::nio::ByteBuffer* getMessage() = 0;
    virtual ::java::util::Map* getOptions() = 0;
    virtual int32_t getPriroity() = 0;
    virtual int32_t getSize() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
