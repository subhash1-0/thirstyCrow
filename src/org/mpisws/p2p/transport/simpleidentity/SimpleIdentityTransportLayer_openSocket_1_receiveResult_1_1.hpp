// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1(SimpleIdentityTransportLayer_openSocket_1 *SimpleIdentityTransportLayer_openSocket_1_this, ::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret);
    static ::java::lang::Class *class_();
    SimpleIdentityTransportLayer_openSocket_1 *SimpleIdentityTransportLayer_openSocket_1_this;
    ::java::nio::ByteBuffer* writeMe;
    ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe;
    ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleIdentityTransportLayer;
    friend class SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy;
    friend class SimpleIdentityTransportLayer_openSocket_1;
    friend class SimpleIdentityTransportLayer_incomingSocket_2;
};
