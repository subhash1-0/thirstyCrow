// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl_push_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/peerreview/authpush/AuthenticatorPushProtocolImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStore.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1::AuthenticatorPushProtocolImpl_push_1(AuthenticatorPushProtocolImpl *AuthenticatorPushProtocolImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AuthenticatorPushProtocolImpl_this(AuthenticatorPushProtocolImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1::receiveException(::java::lang::Exception* exception)
{
    npc(AuthenticatorPushProtocolImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Error requesting witnesses "_j)->append(static_cast< ::java::lang::Object* >(npc(AuthenticatorPushProtocolImpl_this->authOutStore)->getSubjects()))->toString(), exception);
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1::receiveResult(::java::util::Map* result)
{
    AuthenticatorPushProtocolImpl_this->continuePush(result);
}

void org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::util::Map* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::authpush::AuthenticatorPushProtocolImpl_push_1::getClass0()
{
    return class_();
}

