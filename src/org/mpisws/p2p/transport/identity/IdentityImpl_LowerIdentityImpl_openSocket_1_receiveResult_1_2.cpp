// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2(IdentityImpl_LowerIdentityImpl_openSocket_1 *IdentityImpl_LowerIdentityImpl_openSocket_1_this, ::java::nio::ByteBuffer* buf, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_openSocket_1_this(IdentityImpl_LowerIdentityImpl_openSocket_1_this)
    , buf(buf)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead)
        throw new ::java::io::IOException(u"Never asked to read!"_j);

    if(!canWrite)
        throw new ::java::io::IOException(u"Can't write!"_j);

    if(npc(socket)->write(buf) < 0) {
        npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Remote node closed socket while opening.  Try again."_j));
        return;
    }
    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
    } else {
        npc(socket)->register_(true, false, new IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2_receiveSelectResult_1_2_1(this, deliverSocketToMe, ret, i, options));
    }
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(ret, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_openSocket_1_receiveResult_1_2::getClass0()
{
    return class_();
}

