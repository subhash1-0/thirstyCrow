// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.java
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer_incomingSocket_2.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/Serializer.hpp>
#include <org/mpisws/p2p/transport/simpleidentity/SimpleIdentityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
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

org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_incomingSocket_2::SimpleIdentityTransportLayer_incomingSocket_2(SimpleIdentityTransportLayer *SimpleIdentityTransportLayer_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib)
    : super(*static_cast< ::default_init_tag* >(0))
    , SimpleIdentityTransportLayer_this(SimpleIdentityTransportLayer_this)
    , sib(sib)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_incomingSocket_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    try {
        auto remoteIdentifier = java_cast< ::java::lang::Object* >(npc(SimpleIdentityTransportLayer_this->serializer)->deserialize(sib, java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), npc(socket)->getOptions()));
        npc(SimpleIdentityTransportLayer_this->callback)->incomingSocket(new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(remoteIdentifier, socket, SimpleIdentityTransportLayer_this->logger, SimpleIdentityTransportLayer_this->errorHandler, npc(socket)->getOptions()));
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
    }
}

void org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_incomingSocket_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(SimpleIdentityTransportLayer_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_incomingSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::simpleidentity::SimpleIdentityTransportLayer_incomingSocket_2::getClass0()
{
    return class_();
}

