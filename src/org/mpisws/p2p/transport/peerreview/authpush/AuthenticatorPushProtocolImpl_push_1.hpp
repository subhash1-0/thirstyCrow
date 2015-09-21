// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <rice/Continuation.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1
    : public virtual ::java::lang::Object
    , public virtual ::rice::Continuation
{

public:
    typedef ::java::lang::Object super;
    void receiveException(::java::lang::Exception* exception) override;
    virtual void receiveResult(::java::util::Map* result);

    // Generated
    AuthenticatorPushProtocolImpl_push_1(AuthenticatorPushProtocolImpl *AuthenticatorPushProtocolImpl_this);
    static ::java::lang::Class *class_();
    virtual void receiveResult(::java::lang::Object* result) override;
    AuthenticatorPushProtocolImpl *AuthenticatorPushProtocolImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AuthenticatorPushProtocolImpl;
};
