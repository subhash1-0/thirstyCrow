// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.java
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_openSocket_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_1.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetAddressTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/multiaddress/MultiInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketWrapperSocket.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/Cancellable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1::MultiInetAddressTransportLayerImpl_openSocket_1(MultiInetAddressTransportLayerImpl *MultiInetAddressTransportLayerImpl_this, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* handle, MultiInetSocketAddress* i, ::java::nio::ByteBuffer* b, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe)
    : super(*static_cast< ::default_init_tag* >(0))
    , MultiInetAddressTransportLayerImpl_this(MultiInetAddressTransportLayerImpl_this)
    , handle(handle)
    , i(i)
    , b(b)
    , deliverSocketToMe(deliverSocketToMe)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::org::mpisws::p2p::transport::P2PSocket* result)
{
    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(c) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"c != cancellable.getSubCancellable() (indicates a bug in the code) c:"_j)->append(static_cast< ::java::lang::Object* >(c))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    npc(handle)->setSubCancellable(new MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_1(this, result));
    if(npc(MultiInetAddressTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(MultiInetAddressTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u"):receiveResult("_j)
            ->append(static_cast< ::java::lang::Object* >(result))
            ->append(u")"_j)->toString());

    if(MultiInetAddressTransportLayerImpl_this->sendIdentifier) {
        npc(result)->register_(false, true, new MultiInetAddressTransportLayerImpl_openSocket_1_receiveResult_1_2(this, b, deliverSocketToMe, handle, i));
    } else {
        npc(deliverSocketToMe)->receiveResult(handle, new ::org::mpisws::p2p::transport::util::SocketWrapperSocket(i, result, MultiInetAddressTransportLayerImpl_this->logger, MultiInetAddressTransportLayerImpl_this->errorHandler, npc(result)->getOptions()));
    }
}

void org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* c, ::java::lang::Exception* exception)
{
    if(npc(handle)->getSubCancellable() != nullptr && static_cast< ::rice::p2p::commonapi::Cancellable* >(c) != npc(handle)->getSubCancellable())
        throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"c != cancellable.getSubCancellable() (indicates a bug in the code) c:"_j)->append(static_cast< ::java::lang::Object* >(c))
            ->append(u" sub:"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(handle)->getSubCancellable()))->toString());

    npc(deliverSocketToMe)->receiveException(handle, exception);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::multiaddress::MultiInetAddressTransportLayerImpl_openSocket_1::getClass0()
{
    return class_();
}

