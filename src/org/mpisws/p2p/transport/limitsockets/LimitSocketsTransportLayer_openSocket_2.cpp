// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_openSocket_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_LSSocket.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2::LimitSocketsTransportLayer_openSocket_2(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, ::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , LimitSocketsTransportLayer_this(LimitSocketsTransportLayer_this)
    , i(i)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    if(npc(LimitSocketsTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(LimitSocketsTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".openSocket("_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(ret))
            ->append(u".receiveResult()"_j)->toString());

    npc(deliverSocketToMe)->receiveResult(ret, LimitSocketsTransportLayer_this->getLSSock(sock));
}

void org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    if(npc(LimitSocketsTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(LimitSocketsTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".openSocket("_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(ret))
            ->append(u".receiveException("_j)
            ->append(static_cast< ::java::lang::Object* >(ex))
            ->append(u")"_j)->toString());

    npc(deliverSocketToMe)->receiveException(ret, ex);
}

java::lang::String* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2::toString()
{
    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(LimitSocketsTransportLayer_this))->append(u"SocketCallback.openSocket("_j)
        ->append(static_cast< ::java::lang::Object* >(i))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(options))
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_2::getClass0()
{
    return class_();
}

