// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl_ALSocket.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket::AggressiveLivenessTransportLayerImpl_ALSocket(AggressiveLivenessTransportLayerImpl *AggressiveLivenessTransportLayerImpl_this, const ::default_init_tag&)
    : super(AggressiveLivenessTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
    , AggressiveLivenessTransportLayerImpl_this(AggressiveLivenessTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket::AggressiveLivenessTransportLayerImpl_ALSocket(AggressiveLivenessTransportLayerImpl *AggressiveLivenessTransportLayerImpl_this, LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef) 
    : AggressiveLivenessTransportLayerImpl_ALSocket(AggressiveLivenessTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(manager,socket,hardRef);
}

void org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket::ctor(LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef)
{
    super::ctor(manager, socket, hardRef);
}

void org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    super::receiveSelectResult(static_cast< ::org::mpisws::p2p::transport::P2PSocket* >(socket), canRead, canWrite);
    AggressiveLivenessTransportLayerImpl_this->cancelLivenessCheck(static_cast< LivenessTransportLayerImpl_EntityManager* >(manager), npc(socket)->getOptions());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.AggressiveLivenessTransportLayerImpl.ALSocket", 79);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl_ALSocket::getClass0()
{
    return class_();
}

