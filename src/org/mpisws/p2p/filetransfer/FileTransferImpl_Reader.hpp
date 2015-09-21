// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/appsocket/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::filetransfer::FileTransferImpl_Reader
    : public virtual ::java::lang::Object
{
    virtual bool read(::rice::p2p::commonapi::appsocket::AppSocket* socket) /* throws(IOException) */ = 0;

    // Generated
    static ::java::lang::Class *class_();
};
