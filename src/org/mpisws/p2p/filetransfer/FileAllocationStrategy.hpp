// Generated from /pastry-2.1/src/org/mpisws/p2p/filetransfer/FileAllocationStrategy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/filetransfer/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::filetransfer::FileAllocationStrategy
    : public virtual ::java::lang::Object
{
    virtual ::java::io::File* getFile(::java::nio::ByteBuffer* metadata, int64_t offset, int64_t length) /* throws(IOException) */ = 0;
    virtual void fileCancelled(::java::nio::ByteBuffer* metadata, ::java::io::File* f, int64_t offset, int64_t downloadedLength, int64_t requestedLength, ::java::lang::Exception* reason) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
