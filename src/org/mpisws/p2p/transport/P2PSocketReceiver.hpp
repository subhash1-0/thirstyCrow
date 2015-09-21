// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/P2PSocketReceiver.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct org::mpisws::p2p::transport::P2PSocketReceiver
    : public virtual ::java::lang::Object
{
    virtual void receiveSelectResult(P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ = 0;
    virtual void receiveException(P2PSocket* socket, ::java::lang::Exception* ioe) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
