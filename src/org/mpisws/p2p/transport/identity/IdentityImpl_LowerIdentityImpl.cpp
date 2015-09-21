// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/identity/IdentityImpl.java
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_incomingSocket_2.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl_LowerIdentityImpl_sendMessage_3.hpp>
#include <org/mpisws/p2p/transport/identity/IdentityImpl.hpp>
#include <org/mpisws/p2p/transport/identity/IdentitySerializer.hpp>
#include <org/mpisws/p2p/transport/identity/MemoryExpiredException.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/OptionsFactory.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
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

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::IdentityImpl_LowerIdentityImpl(IdentityImpl *IdentityImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , IdentityImpl_this(IdentityImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::IdentityImpl_LowerIdentityImpl(IdentityImpl *IdentityImpl_this, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler) 
    : IdentityImpl_LowerIdentityImpl(IdentityImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(tl,handler);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    super::ctor();
    this->tl = tl;
    logger = npc(npc(IdentityImpl_this->environment)->getLogManager())->getLogger(IdentityImpl::class_(), u"lower"_j);
    if(handler != nullptr) {
        this->errorHandler = handler;
    } else {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
    npc(tl)->setCallback(this);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(50))
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    try {
        if((options == nullptr) || npc(options)->containsKey(IdentityImpl::DONT_VERIFY()) && npc((java_cast< ::java::lang::Boolean* >(java_cast< ::java::lang::Object* >(npc(options)->get(IdentityImpl::DONT_VERIFY())))))->booleanValue()) {
            npc(sob)->writeByte(int32_t(0));
        } else {
            npc(sob)->writeByte(int32_t(1));
            auto const dest = java_cast< ::java::lang::Object* >(IdentityImpl_this->getIntendedDest(options));
            if(dest == nullptr) {
                npc(deliverSocketToMe)->receiveException(ret, new MemoryExpiredException(::java::lang::StringBuilder().append(u"No record of the upper identifier for "_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u" index="_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(options)->get(IdentityImpl::NODE_HANDLE_FROM_INDEX()))))->toString()));
                return ret;
            }
            if(IdentityImpl_this->addBinding(dest, i, options)) {
            } else {
                npc(deliverSocketToMe)->receiveException(ret, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i));
                return ret;
            }
            npc(IdentityImpl_this->serializer)->serialize(sob, dest);
        }
        npc(sob)->write(IdentityImpl_this->localIdentifier);
    } catch (::java::io::IOException* ioe) {
        npc(deliverSocketToMe)->receiveException(ret, ioe);
        return ret;
    }
    ::java::nio::ByteBuffer* buf;
    buf = npc(sob)->getByteBuffer();
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new IdentityImpl_LowerIdentityImpl_openSocket_1(this, ret, buf, deliverSocketToMe, i, options), options));
    return ret;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(s))
            ->append(u")"_j)->toString());

    (new IdentityImpl_LowerIdentityImpl_incomingSocket_2(this))->receiveSelectResult(s, true, false);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        auto b = new ::int8_tArray(npc(m)->remaining());
        ::java::lang::System::arraycopy(npc(m)->array(), npc(m)->position(), b, 0, npc(b)->length);
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)
            ->append(::java::util::Arrays::toString(b))->toString());
    } else {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
            npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(m))
                ->append(u")"_j)->toString());
        }
    }
    auto const ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    ::int8_tArray* msgWithHeader;
    if(npc(options)->containsKey(IdentityImpl::NODE_HANDLE_FROM_INDEX())) {
        msgWithHeader = new ::int8_tArray(int32_t(1) + npc(IdentityImpl_this->localIdentifier)->length + npc(m)->remaining());
        (*msgWithHeader)[int32_t(0)] = IdentityImpl::NO_ID;
        ::java::lang::System::arraycopy(IdentityImpl_this->localIdentifier, 0, msgWithHeader, 1, npc(IdentityImpl_this->localIdentifier)->length);
        npc(m)->get(msgWithHeader, int32_t(1) + npc(IdentityImpl_this->localIdentifier)->length, npc(m)->remaining());
    } else {
        auto dest = java_cast< ::java::lang::Object* >(IdentityImpl_this->getIntendedDest(options));
        if(dest == nullptr) {
            if(deliverAckToMe != nullptr)
                npc(deliverAckToMe)->sendFailed(ret, new MemoryExpiredException(::java::lang::StringBuilder().append(u"No record of the upper identifier for "_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u" index="_j)
                    ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(options)->get(IdentityImpl::NODE_HANDLE_FROM_INDEX()))))->toString()));

            return ret;
        }
        if(IdentityImpl_this->addBinding(dest, i, options)) {
        } else {
            npc(deliverAckToMe)->sendFailed(ret, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i, m));
            return ret;
        }
        ::int8_tArray* destBytes;
        try {
            auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(static_cast< int32_t >((npc(IdentityImpl_this->localIdentifier)->length * 2.5)));
            npc(IdentityImpl_this->serializer)->serialize(sob, dest);
            destBytes = npc(sob)->getBytes();
        } catch (::java::io::IOException* ioe) {
            npc(deliverAckToMe)->sendFailed(ret, ioe);
            return ret;
        }
        msgWithHeader = new ::int8_tArray(int32_t(1) + npc(destBytes)->length + npc(IdentityImpl_this->localIdentifier)->length+ npc(m)->remaining());
        (*msgWithHeader)[int32_t(0)] = IdentityImpl::NORMAL;
        ::java::lang::System::arraycopy(destBytes, 0, msgWithHeader, 1, npc(destBytes)->length);
        ::java::lang::System::arraycopy(IdentityImpl_this->localIdentifier, 0, msgWithHeader, int32_t(1) + npc(destBytes)->length, npc(IdentityImpl_this->localIdentifier)->length);
        npc(m)->get(msgWithHeader, int32_t(1) + npc(destBytes)->length + npc(IdentityImpl_this->localIdentifier)->length, npc(m)->remaining());
    }
    auto const buf = ::java::nio::ByteBuffer::wrap(msgWithHeader);
    npc(ret)->setSubCancellable(npc(tl)->sendMessage(i, buf, new IdentityImpl_LowerIdentityImpl_sendMessage_3(this, ret, deliverAckToMe, i), options));
    return ret;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    auto newOptions = ::org::mpisws::p2p::transport::util::OptionsFactory::copyOptions(options);
    auto msgType = npc(m)->get();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u"):"_j)
            ->append(msgType)->toString());

    {
        ::int8_tArray* dest;
        ::rice::p2p::util::rawserialization::SimpleInputBuffer* sib;
        ::java::lang::Object* from;
        ::java::lang::Object* oldDest;
        ::java::lang::Object* newDest;
        switch (msgType) {
        case IdentityImpl::NORMAL:
            dest = new ::int8_tArray(npc(IdentityImpl_this->localIdentifier)->length);
            npc(m)->get(dest);
            if(!::java::util::Arrays::equals(dest, IdentityImpl_this->localIdentifier)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"received message for wrong node from:"_j)->append(static_cast< ::java::lang::Object* >(i))
                        ->append(u" intended:"_j)
                        ->append(::java::util::Arrays::toString(dest))
                        ->append(u" me:"_j)
                        ->append(::java::util::Arrays::toString(IdentityImpl_this->localIdentifier))->toString());

                auto errorMessage = new ::int8_tArray(int32_t(1) + npc(IdentityImpl_this->localIdentifier)->length);
                (*errorMessage)[int32_t(0)] = IdentityImpl::INCORRECT_IDENTITY;
                ::java::lang::System::arraycopy(IdentityImpl_this->localIdentifier, 0, errorMessage, 1, npc(IdentityImpl_this->localIdentifier)->length);
                auto buf = ::java::nio::ByteBuffer::wrap(errorMessage);
                npc(tl)->sendMessage(i, buf, nullptr, options);
                return;
            }
        case IdentityImpl::NO_ID:
            sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(m)->array(), npc(m)->position());
            from = java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->deserialize(sib, i));
            npc(m)->position(npc(npc(m)->array())->length - npc(sib)->bytesRemaining());
            if(IdentityImpl_this->addBinding(from, i, options)) {
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Warning.  Received message from stale identifier:"_j)->append(static_cast< ::java::lang::Object* >(from))
                        ->append(u". Current identifier is "_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->bindings)->get(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateUp(i))))))
                        ->append(u" lower:"_j)
                        ->append(static_cast< ::java::lang::Object* >(i))
                        ->append(u" Probably a delayed message, dropping."_j)->toString());

                npc(errorHandler)->receivedUnexpectedData(i, npc(m)->array(), npc(m)->position(), newOptions);
                return;
            }
            npc(newOptions)->put(IdentityImpl::NODE_HANDLE_FROM_INDEX(), from);
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
                auto b = new ::int8_tArray(npc(m)->remaining());
                ::java::lang::System::arraycopy(npc(m)->array(), npc(m)->position(), b, 0, npc(b)->length);
                npc(logger)->log(::java::lang::StringBuilder().append(u"received message for me from:"_j)->append(static_cast< ::java::lang::Object* >(from))
                    ->append(u"("_j)
                    ->append(static_cast< ::java::lang::Object* >(from))
                    ->append(u"("_j)
                    ->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u")) "_j)
                    ->append(::java::util::Arrays::toString(b))->toString());
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"received message for me from:"_j)->append(static_cast< ::java::lang::Object* >(from))
                        ->append(u"("_j)
                        ->append(static_cast< ::java::lang::Object* >(i))
                        ->append(u") "_j)
                        ->append(static_cast< ::java::lang::Object* >(m))->toString());

            }
            npc(callback)->messageReceived(i, m, newOptions);
            break;
        case IdentityImpl::INCORRECT_IDENTITY:
            oldDest = java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->bindings)->get(java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->translateUp(i))));
            newDest = java_cast< ::java::lang::Object* >(npc(IdentityImpl_this->serializer)->deserialize(new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(m)->array(), npc(m)->position()), i));
            if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(logger)->log(::java::lang::StringBuilder().append(u"received INCORRECT_IDENTITY:"_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u" old:"_j)
                    ->append(static_cast< ::java::lang::Object* >(oldDest))
                    ->append(u" new:"_j)
                    ->append(static_cast< ::java::lang::Object* >(newDest))->toString());

            if(IdentityImpl_this->addBinding(newDest, i, options)) {
            }
        }
    }

}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::acceptSockets(bool b)
{
    npc(tl)->acceptMessages(b);
}

java::lang::Object* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"destroy()"_j);

    npc(tl)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.identity.IdentityImpl.LowerIdentityImpl", 64);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::identity::IdentityImpl_LowerIdentityImpl::getClass0()
{
    return class_();
}

