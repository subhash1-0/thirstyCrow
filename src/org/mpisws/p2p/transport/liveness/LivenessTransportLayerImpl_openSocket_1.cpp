// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_openSocket_1.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/channels/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_openSocket_1::LivenessTransportLayerImpl_openSocket_1(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::lang::Object* i, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_this(LivenessTransportLayerImpl_this)
    , deliverSocketToMe(deliverSocketToMe)
    , i(i)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(deliverSocketToMe)->receiveResult(cancellable, LivenessTransportLayerImpl_this->getLSocket(sock, LivenessTransportLayerImpl_this->getManager(i)));
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    if(LivenessTransportLayerImpl_this->connectionExceptionMeansFaulty_) {
        if(dynamic_cast< ::java::nio::channels::ClosedChannelException* >(ex) != nullptr) {
        } else {
            if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(LivenessTransportLayerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"Marking "_j)->append(static_cast< ::java::lang::Object* >(s))
                    ->append(u" dead due to exception opening socket."_j)->toString(), ex);

            npc(LivenessTransportLayerImpl_this->getManager(i))->markDead(options);
        }
    }
    npc(deliverSocketToMe)->receiveException(s, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_openSocket_1::getClass0()
{
    return class_();
}

