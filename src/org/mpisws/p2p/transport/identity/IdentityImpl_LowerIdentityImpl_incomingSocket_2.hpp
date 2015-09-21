// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::P2PSocketReceiver
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::java::nio::ByteBuffer* buf {  };

public:
    void receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe) override;
    void receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */ override;

    // Generated
    IdentityImpl_LowerIdentityImpl_incomingSocket_2(IdentityImpl_LowerIdentityImpl *IdentityImpl_LowerIdentityImpl_this);
    static ::java::lang::Class *class_();

private:
    void init();
    IdentityImpl_LowerIdentityImpl *IdentityImpl_LowerIdentityImpl_this;
    virtual ::java::lang::Class* getClass0();
    friend class IdentityImpl;
    friend class IdentityImpl_IdentityImpl_1;
    friend class IdentityImpl_IdentityImpl_1_nodeHandleFound_1_1;
    friend class IdentityImpl_LowerIdentityImpl;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1;
    friend class IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1_receiveSelectResult_1_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1;
    friend class IdentityImpl_LowerIdentityImpl_sendMessage_3;
    friend class IdentityImpl_UpperIdentityImpl;
    friend class IdentityImpl_UpperIdentityImpl_openSocket_1;
    friend class IdentityImpl_IdentityMessageHandle;
};
