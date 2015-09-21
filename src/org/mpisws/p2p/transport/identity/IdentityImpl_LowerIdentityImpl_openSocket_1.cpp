// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1::IdentityImpl_LowerIdentityImpl_openSocket_1(IdentityImpl_LowerIdentityImpl *IdentityImpl_LowerIdentityImpl_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::nio::ByteBuffer* buf, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_this(IdentityImpl_LowerIdentityImpl_this)
    , ret(ret)
    , buf(buf)
    , deliverSocketToMe(deliverSocketToMe)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(ret)->setSubCancellable(new IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_1(this, sock));
    try {
        (new IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2(this, buf, deliverSocketToMe, ret, i, options))->receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(ret, ioe);
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(ret, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1::getClass0()
{
    return class_();
}

