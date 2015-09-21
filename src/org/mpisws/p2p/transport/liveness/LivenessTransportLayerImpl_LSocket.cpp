// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/selector/TimerTask.hpp>

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
org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::LivenessTransportLayerImpl_LSocket(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_this(LivenessTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::LivenessTransportLayerImpl_LSocket(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef) 
    : LivenessTransportLayerImpl_LSocket(LivenessTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(manager,socket,hardRef);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::init()
{
    closed = false;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::ctor(LivenessTransportLayerImpl_EntityManager* manager, ::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Object* hardRef)
{
    super::ctor(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()), socket, LivenessTransportLayerImpl_this->logger, java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(LivenessTransportLayerImpl_this->errorHandler), npc(socket)->getOptions());
    init();
    if(hardRef == nullptr)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"hardRef == null "_j)->append(static_cast< ::java::lang::Object* >(manager))
            ->append(u" "_j)
            ->append(static_cast< ::java::lang::Object* >(socket))->toString());

    this->manager = manager;
    this->hardRef = hardRef;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(closed) {
        npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" is already closed."_j)->toString()));
        return;
    }
    if(wantToWrite)
        startLivenessCheckerTimer();

    super::register_(wantToRead, wantToWrite, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(receiver));
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    auto m = LivenessTransportLayerImpl_this->getManager(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier()));
    if(npc(m)->liveness > LivenessTypes::LIVENESS_SUSPECTED) {
        npc(m)->updated = 0LL;
        npc(m)->checkLiveness(npc(socket)->getOptions());
    }
    if(canWrite) {
        stopLivenessCheckerTimer();
    }
    super::receiveSelectResult(static_cast< ::org::mpisws::p2p::transport::P2PSocket* >(socket), canRead, canWrite);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::startLivenessCheckerTimer()
{
    {
        synchronized synchronized_0(this);
        {
            if(livenessCheckerTimer != nullptr)
                return;

            livenessCheckerTimer = new LivenessTransportLayerImpl_LSocket_startLivenessCheckerTimer_1(this);
        }
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Checking liveness on "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get())))
            ->append(u" in "_j)
            ->append(npc(manager)->rto())
            ->append(u" millis if we don't write."_j)->toString());

    npc(LivenessTransportLayerImpl_this->timer)->schedule(livenessCheckerTimer, npc(manager)->rto() * int32_t(4), 30000);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::stopLivenessCheckerTimer()
{
    {
        synchronized synchronized_1(this);
        {
            if(livenessCheckerTimer != nullptr)
                npc(livenessCheckerTimer)->cancel();

            livenessCheckerTimer = nullptr;
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::close()
{
    closed = true;
    npc(manager)->removeSocket(this);
    super::close();
}

java::lang::String* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::toString()
{
    return ::java::lang::StringBuilder().append(u"LSocket{"_j)->append(static_cast< ::java::lang::Object* >(socket))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.LivenessTransportLayerImpl.LSocket", 68);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_LSocket::getClass0()
{
    return class_();
}

