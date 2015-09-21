// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
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

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1 *IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this, ::org::mpisws::p2p::transport::util::SocketInputBuffer* sib)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this)
    , sib(sib)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->errorHandler)->receivedException(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), ioe);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(canWrite)
        throw new ::java::io::IOException(u"Never asked to write!"_j);

    if(!canRead)
        throw new ::java::io::IOException(u"Can't read!"_j);

    auto const newOptions = ::org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(npc(socket)->getOptions());
    ::java::lang::Object* from;
    try {
        from = java_cast< ::java::lang::Object* >(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->serializer)->deserialize(sib, java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())));
        npc(newOptions)->put(IdentityImpl::NODE_HANDLE_FROM_INDEX(), from);
    } catch (::org::mpisws::p2p::transport::util::InsufficientBytesException* ibe) {
        npc(socket)->register_(true, false, this);
        return;
    }
    if(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->addBinding(from, java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), npc(socket)->getOptions())) {
    } else {
        if(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Serious error.  There was an attempt to open a socket from a supposedly stale identifier:"_j)->append(static_cast< ::java::lang::Object* >(from))
                ->append(u". Current identifier is "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->bindings)->get(java_cast< ::java::lang::Object* >(npc(IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_this->IdentityImpl_LowerIdentityImpl_incomingSocket_2_this->IdentityImpl_LowerIdentityImpl_this->IdentityImpl_this->serializer)->translateUp(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))))))
                ->append(u" lower:"_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->toString());

        npc(socket)->close();
        return;
    }
    auto result = (new ::int8_tArray({IdentityImpl::SUCCESS}));
    auto const writeMe = ::java::nio::ByteBuffer::wrap(result);
    (new IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2_receiveSelectResult_2_1_2_1(this, writeMe, newOptions))->receiveSelectResult(socket, false, true);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl_incomingSocket_2_receiveSelectResult_2_1_receiveSelectResult_2_1_2::getClass0()
{
    return class_();
}

