// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/FileTransferImpl_Reader.hpp>
#include <org/mpisws/p2p/filetransfer/Receipt.hpp>

struct org::mpisws::p2p::filetransfer::FileTransferImpl_DataReader
    : public virtual FileTransferImpl_Reader
    , public virtual Receipt
{
    virtual bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket, int32_t size) /* throws(IOException) */ = 0;
    virtual void cancelled(FileTransferImpl_DataReader* reader) = 0;

    // Generated
    static ::java::lang::Class *class_();
    virtual bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket) = 0;
};
