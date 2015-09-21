// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/identity/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::identity::IdentityImpl_IdentityMessageHandle
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
    , public virtual ::org::mpisws::p2p::transport::MessageCallback
{

public:
    typedef ::java::lang::Object super;

private:
    ::rice::p2p::commonapi::Cancellable* subCancellable {  };
    ::java::lang::Object* identifier {  };
    ::java::lang::Object* message {  };
    ::java::util::Map* options {  };
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe {  };
protected:
    void ctor(::java::lang::Object* identifier, ::java::lang::Object* message, ::java::util::Map* options, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe);

public:
    ::java::lang::Object* getIdentifier() override;
    ::java::lang::Object* getMessage() override;
    ::java::util::Map* getOptions() override;

public: /* package */
    virtual void deadForever();

public:
    bool cancel() override;
    virtual void setSubCancellable(::rice::p2p::commonapi::Cancellable* cancellable);
    virtual ::rice::p2p::commonapi::Cancellable* getSubCancellable();
    void ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg) override;
    void sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason) override;
    ::java::lang::String* toString() override;

    // Generated
    IdentityImpl_IdentityMessageHandle(IdentityImpl *IdentityImpl_this, ::java::lang::Object* identifier, ::java::lang::Object* message, ::java::util::Map* options, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe);
protected:
    IdentityImpl_IdentityMessageHandle(IdentityImpl *IdentityImpl_this, const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    IdentityImpl *IdentityImpl_this;

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
    friend class IdentityImpl_LowerIdentityImpl_sendMessage_3;
    friend class IdentityImpl_UpperIdentityImpl;
    friend class IdentityImpl_UpperIdentityImpl_openSocket_1;
};
