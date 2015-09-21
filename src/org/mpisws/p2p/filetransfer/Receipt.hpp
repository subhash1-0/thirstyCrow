// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/Receipt.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

struct org::mpisws::p2p::filetransfer::Receipt
    : public virtual ::rice::p2p::commonapi::Cancellable
{
    virtual int32_t getUID() = 0;
    virtual int64_t getSize() = 0;
    virtual int8_t getPriority() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
