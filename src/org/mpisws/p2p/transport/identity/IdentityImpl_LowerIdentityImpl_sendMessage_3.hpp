// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_sendMessage_3
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* ex) override;

    // Generated
    IdentityImpl_LowerIdentityImpl_sendMessage_3(IdentityImpl_LowerIdentityImpl *IdentityImpl_LowerIdentityImpl_this, ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::lang::Object* i);
    static ::java::lang::Class *class_();
    IdentityImpl_LowerIdentityImpl *IdentityImpl_LowerIdentityImpl_this;
    ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl* ret;
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe;
    ::java::lang::Object* i;

private:
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
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_1;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2;
    friend class IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1;
    friend class IdentityImpl_UpperIdentityImpl;
    friend class IdentityImpl_UpperIdentityImpl_openSocket_1;
    friend class IdentityImpl_IdentityMessageHandle;
};
