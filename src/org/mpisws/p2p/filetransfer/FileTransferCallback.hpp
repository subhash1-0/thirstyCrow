// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileTransferCallback.java

#pragma once

#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::filetransfer::FileTransferCallback
    : public virtual ::java::lang::Object
{
    virtual void messageReceived(::java::nio::ByteBuffer* bb) = 0;
    virtual void fileReceived(::java::io::File* f, ::java::nio::ByteBuffer* metadata) = 0;
    virtual void receiveException(::java::lang::Exception* ioe) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
