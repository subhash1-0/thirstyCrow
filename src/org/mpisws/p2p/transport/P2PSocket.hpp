// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/P2PSocket.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::P2PSocket
    : public virtual ::java::lang::Object
{
    virtual ::java::util::Map* getOptions() = 0;
    virtual ::java::lang::Object* getIdentifier() = 0;
    virtual int64_t read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */ = 0;
    virtual int64_t write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */ = 0;
    virtual void register_(bool wantToRead, bool wantToWrite, P2PSocketReceiver* receiver) = 0;
    virtual void shutdownOutput() = 0;
    virtual void close() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
