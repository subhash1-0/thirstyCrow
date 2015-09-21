// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_incomingSocket_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;

    // Generated
    SimpleIdentityTransportLayer_incomingSocket_2(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib);
    static ::java::lang::Class *class_();
    SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this;
    ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib;

private:
    virtual ::java::lang::Class* getClass0();
    friend class SimpleIdentityTransportLayer;
    friend class SimpleIdentityTransportLayer_DefaultLocalIdentifierStrategy;
    friend class SimpleIdentityTransportLayer_openSocket_1;
    friend class SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1;
};
