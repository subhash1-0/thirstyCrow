// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1(SimpleIdentityTransportLayer_openSocket_1 *SimpleIdentityTransportLayer_openSocket_1_this, ::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimpleIdentityTransportLayer_openSocket_1_this(SimpleIdentityTransportLayer_openSocket_1_this)
    , writeMe(writeMe)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(socket)->write(writeMe) < 0) {
        npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::ClosedChannelException(u"Socket closed."_j));
        return;
    }
    if(npc(writeMe)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    npc(deliverSocketToMe)->receiveResult(ret, new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), socket, SimpleIdentityTransportLayer_openSocket_1_this->SimpleIdentityTransportLayer_this->logger, SimpleIdentityTransportLayer_openSocket_1_this->SimpleIdentityTransportLayer_this->errorHandler, npc(socket)->getOptions()));
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(deliverSocketToMe)->receiveException(ret, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1::getClass0()
{
    return class_();
}

