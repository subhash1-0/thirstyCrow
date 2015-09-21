// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransfer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::filetransfer::FileTransfer
    : public virtual ::java::lang::Object
{
    virtual FileReceipt* sendFile(::java::io::File* f, ::java::nio::ByteBuffer* metadata, int8_t priority, int64_t offset, int64_t length, ::rice::Continuation* c) /* throws(IOException) */ = 0;
    virtual FileReceipt* sendFile(::java::io::File* f, ::java::nio::ByteBuffer* metadata, int8_t priority, ::rice::Continuation* c) /* throws(IOException) */ = 0;
    virtual BBReceipt* sendMsg(::java::nio::ByteBuffer* bb, int8_t priority, ::rice::Continuation* c) = 0;
    virtual void addListener(FileTransferListener* listener) = 0;
    virtual void removeListener(FileTransferListener* listener) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
