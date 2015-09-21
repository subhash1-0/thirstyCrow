// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/AggressiveLivenessTransportLayerImpl_ALSocket.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>

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

extern void lock(::java::lang::Object *);
extern void unlock(::java::lang::Object *);

namespace
{
    struct synchronized
    {
        synchronized(::java::lang::Object *o) : o(o) { ::lock(o); }
        ~synchronized() { ::unlock(o); }
    private:
        synchronized(const synchronized&); synchronized& operator=(const synchronized&);
        ::java::lang::Object *o;
    };
}
org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::AggressiveLivenessTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::AggressiveLivenessTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle) 
    : AggressiveLivenessTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,env,errorHandler,checkDeadThrottle);
}

void org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle)
{
    super::ctor(tl, env, errorHandler, checkDeadThrottle);
}

org::mpisws::p2p::transport::P2PSocket* org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::getLSocket(::org::mpisws::p2p::transport::P2PSocket* s, LivenessTransportLayerImpl_EntityManager* manager)
{
    auto sock = new AggressiveLivenessTransportLayerImpl_ALSocket(this, manager, s, java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get()));
    {
        synchronized synchronized_0(npc(manager)->sockets);
        {
            npc(npc(manager)->sockets)->add(static_cast< ::java::lang::Object* >(sock));
        }
    }
    return sock;
}

void org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    super::messageReceived(static_cast< ::java::lang::Object* >(i), m, options);
    cancelLivenessCheck(static_cast< ::java::lang::Object* >(i), options);
}

void org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.AggressiveLivenessTransportLayerImpl", 70);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::AggressiveLivenessTransportLayerImpl::getClass0()
{
    return class_();
}

