// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_UpperIdentityImpl_openSocket_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_UpperIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl_openSocket_1::IdentityImpl_UpperIdentityImpl_openSocket_1(IdentityImpl_UpperIdentityImpl *IdentityImpl_UpperIdentityImpl_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_UpperIdentityImpl_this(IdentityImpl_UpperIdentityImpl_this)
    , deliverSocketToMe(deliverSocketToMe)
    , handle(handle)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(handle, ex);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(deliverSocketToMe)->receiveResult(handle, new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(i, sock, IdentityImpl_UpperIdentityImpl_this->logger, IdentityImpl_UpperIdentityImpl_this->errorHandler, options));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_UpperIdentityImpl_openSocket_1::getClass0()
{
    return class_();
}

