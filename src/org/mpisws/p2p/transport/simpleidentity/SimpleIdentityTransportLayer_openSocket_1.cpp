// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_openSocket_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/LocalIdentifierStrategy.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1::SimpleIdentityTransportLayer_openSocket_1(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimpleIdentityTransportLayer_this(SimpleIdentityTransportLayer_this)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    try {
        auto const writeMe = ::java::nio::ByteBuffer::wrap(npc(SimpleIdentityTransportLayer_this->localIdStrategy)->getLocalIdentifierBytes());
        (new SimpleIdentityTransportLayer_openSocket_1_receiveResult_1_1(this, writeMe, deliverSocketToMe, ret))->receiveSelectResult(sock, false, true);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(ret, ioe);
    }
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(deliverSocketToMe)->receiveException(ret, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_openSocket_1::getClass0()
{
    return class_();
}

