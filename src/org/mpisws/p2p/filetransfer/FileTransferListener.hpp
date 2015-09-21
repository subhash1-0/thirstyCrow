// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferListener.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::filetransfer::FileTransferListener
    : public virtual ::java::lang::Object
{
    virtual void fileTransferred(FileReceipt* receipt, int64_t bytesTransferred, int64_t total, bool incoming) = 0;
    virtual void msgTransferred(BBReceipt* receipt, int32_t bytesTransferred, int32_t total, bool incoming) = 0;
    virtual void transferCancelled(Receipt* receipt, bool incoming) = 0;
    virtual void transferFailed(Receipt* receipt, bool incoming) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
