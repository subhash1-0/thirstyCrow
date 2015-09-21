// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1(IdentityImpl_LowerIdentityImpl_incomingSocket_2 *IdentityImpl_LowerIdentityImpl_incomingSocket_2_this, bool wantsToVerify)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_incomingSocket_2_this(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this)
    , wantsToVerify(wantsToVerify)
{
    clinit();
    init();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1::init()
{
    buf = ::java::nio::ByteBuffer::allocate(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier)->length);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canWrite)
        throw new ::java::io::IOException(u"Never asked to write!"_j);

    if(!canRead)
        throw new ::java::io::IOException(u"Can't read!"_j);

    if(wantsToVerify) {
        if(npc(socket)->read(buf) < 0) {
            if(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), new ::java::io::IOException(u"Socket closed while incoming."_j));

            return;
        }
        if(npc(buf)->hasRemaining()) {
            npc(socket)->register_(true, false, this);
            return;
        }
        if(!::java::util::Arrays::equals(npc(buf)->array(), IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier)) {
            if(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->log(::java::lang::StringBuilder().append(u"incomingSocket() FAILURE expected "_j)->append(::java::util::Arrays::toString(npc(buf)->array()))
                    ->append(u" me:"_j)
                    ->append(::java::util::Arrays::toString(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier))->toString());

            auto result = new ::int8_tArray(int32_t(1) + npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier)->length);
            (*result)[int32_t(0)] = IdentityImpl::FAILURE;
            ::java::lang::System::arraycopy(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier, 0, result, 1, npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->localIdentifier)->length);
            auto const writeMe = ::java::nio::ByteBuffer::wrap(result);
            (new IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_1(this, writeMe))->receiveSelectResult(socket, false, true);
            return;
        }
    } else {
        if(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
            npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Connection from "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))
                ->append(u" didn't want to verify our identity."_j)->toString());

    }
    auto const sib = new ::org::mpisws::p2p::transport::util::SocketInputBuffer(socket, int32_t(1024));
    (new IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2(this, sib))->receiveSelectResult(socket, true, false);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1::getClass0()
{
    return class_();
}

