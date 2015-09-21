// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/BBReceipt.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

struct org::mpisws::p2p::filetransfer::BBReceipt
    : public virtual Receipt
{
    virtual ::int8_tArray* getBytes() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
