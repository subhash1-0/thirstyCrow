// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <rice/environment/logging/Logger.hpp>

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

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2 *IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this, ::java::nio::ByteBuffer* writeMe, ::java::util::Map* newOptions)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this)
    , writeMe(writeMe)
    , newOptions(newOptions)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);

}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canRead)
        throw new ::java::io::IOException(u"Not expecting to read."_j);

    if(!canWrite)
        throw new ::java::io::IOException(u"Expecting to write."_j);

    if(npc(socket)->write(writeMe) == -int32_t(1)) {
        if(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), new ::org::mpisws::p2p::transport::ClosedChannelException(u"Error on incoming socket."_j));

        return;
    }
    if(npc(writeMe)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    ::org::mpisws::p2p::transport::P2PSocket* const returnMe = new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), socket, IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger, IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->errorHandler, newOptions);
    npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->callback)->incomingSocket(returnMe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1::getClass0()
{
    return class_();
}

