// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileReceipt.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

struct org::mpisws::p2p::filetransfer::FileReceipt
    : public virtual Receipt
{
    virtual ::java::io::File* getFile() = 0;
    virtual ::java::nio::ByteBuffer* getMetadata() = 0;
    virtual int64_t getOffset() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
