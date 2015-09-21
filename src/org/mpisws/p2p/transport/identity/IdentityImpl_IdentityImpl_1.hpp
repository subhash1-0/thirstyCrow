// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/identity/SerializerListener.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::IdentityImpl_IdentityImpl_1
    : public virtual ::java::lang::Object
    , public virtual SerializerListener
{

public:
    typedef ::java::lang::Object super;
    void nodeHandleFound(::java::lang::Object* handle) override;

    // Generated
    IdentityImpl_IdentityImpl_1(IdentityImpl *IdentityImpl_this);
    static ::java::lang::Class *class_();
    IdentityImpl *IdentityImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class IdentityImpl;
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
    friend class IdentityImpl_LowerIdentityImpl_sendMessage_3;
    friend class IdentityImpl_UpperIdentityImpl;
    friend class IdentityImpl_UpperIdentityImpl_openSocket_1;
    friend class IdentityImpl_IdentityMessageHandle;
};
