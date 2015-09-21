// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.java
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer_openSocket_1.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/limitsockets/LimitSocketsTransportLayer.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_1::LimitSocketsTransportLayer_openSocket_1(LimitSocketsTransportLayer *LimitSocketsTransportLayer_this, ::java::lang::Object* i_, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options_, ::java::lang::Object* i, ::java::util::Map* options, ::rice::environment::logging::Logger* logger)
    : super(*static_cast< ::default_init_tag* >(0))
    , LimitSocketsTransportLayer_this(LimitSocketsTransportLayer_this)
    , i(i_)
    , deliverSocketToMe(deliverSocketToMe)
    , options(options_)
{
    clinit();
    ctor(i, options, logger);
}

bool org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_1::cancel()
{
    if(npc(LimitSocketsTransportLayer_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(LimitSocketsTransportLayer_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".openSocket("_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(this))
            ->append(u".cancel()"_j)->toString());

    return super::cancel();
}

java::lang::String* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_1::toString()
{
    return ::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(LimitSocketsTransportLayer_this))->append(u"RequestHandle.openSocket("_j)
        ->append(static_cast< ::java::lang::Object* >(i))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
        ->append(u","_j)
        ->append(static_cast< ::java::lang::Object* >(options))
        ->append(u")"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::limitsockets::LimitSocketsTransportLayer_openSocket_1::getClass0()
{
    return class_();
}

