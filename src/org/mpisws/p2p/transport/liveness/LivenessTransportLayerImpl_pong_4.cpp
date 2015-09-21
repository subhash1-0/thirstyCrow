// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_pong_4.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_pong_4::LivenessTransportLayerImpl_pong_4(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, ::java::lang::Object* i, int64_t senderTime, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_this(LivenessTransportLayerImpl_this)
    , i(i)
    , senderTime(senderTime)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_pong_4::ack(::org::mpisws::p2p::transport::MessageRequestHandle* msg)
{
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_pong_4::sendFailed(::org::mpisws::p2p::transport::MessageRequestHandle* msg, ::java::lang::Exception* reason)
{
    if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER) {
        npc(LivenessTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"pong("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(senderTime)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u") failed"_j)->toString(), reason);
    } else {
        if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"pong("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(senderTime)
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(options))
                ->append(u") failed "_j)
                ->append(static_cast< ::java::lang::Object* >(reason))->toString());

    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_pong_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_pong_4::getClass0()
{
    return class_();
}

