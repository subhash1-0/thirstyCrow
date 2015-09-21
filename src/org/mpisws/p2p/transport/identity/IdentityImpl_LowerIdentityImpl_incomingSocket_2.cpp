// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
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

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2::IdentityImpl_LowerIdentityImpl_incomingSocket_2(IdentityImpl_LowerIdentityImpl *IdentityImpl_LowerIdentityImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_this(IdentityImpl_LowerIdentityImpl_this)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2::init()
{
    buf = ::java::nio::ByteBuffer::allocate(1);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(socket)->read(buf) < 0) {
        if(npc(IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), new ::java::io::IOException(u"Socket closed while incoming."_j));

        return;
    }
    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
        return;
    }
    npc(buf)->clear();
    auto wantsToVerifyB = npc(buf)->get();
    auto const wantsToVerify = (wantsToVerifyB == static_cast< int8_t >(int32_t(1)));
    (new IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1(this, wantsToVerify))->receiveSelectResult(socket, true, false);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2::getClass0()
{
    return class_();
}

