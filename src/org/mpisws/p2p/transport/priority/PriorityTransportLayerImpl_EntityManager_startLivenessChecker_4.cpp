// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4.hpp>

#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>
#include <rice/environment/logging/Logger.hpp>

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
org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4::PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4(PriorityTransportLayerImpl_EntityManager *PriorityTransportLayerImpl_EntityManager_this, ::java::lang::Object* temp, ::java::util::Map* options)
    : super(*static_cast< ::default_init_tag* >(0))
    , PriorityTransportLayerImpl_EntityManager_this(PriorityTransportLayerImpl_EntityManager_this)
    , temp(temp)
    , options(options)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4::run()
{
    {
        synchronized synchronized_0(PriorityTransportLayerImpl_EntityManager_this);
        {
            if(cancelled)
                return;

            PriorityTransportLayerImpl_EntityManager_this->stopLivenessChecker();
            if(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->destroyed)
                return;

            npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->livenessProvider)->checkLiveness(temp, options);
            if(npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->level <= npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->INFO)
                npc(PriorityTransportLayerImpl_EntityManager_this->PriorityTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_this))->append(u".liveness checker setting pendingSocket to null "_j)
                    ->append(static_cast< ::java::lang::Object* >(PriorityTransportLayerImpl_EntityManager_this->pendingSocket))->toString());

            npc(PriorityTransportLayerImpl_EntityManager_this->pendingSocket)->cancel();
            PriorityTransportLayerImpl_EntityManager_this->pendingSocket = nullptr;
        }
    }
    PriorityTransportLayerImpl_EntityManager_this->scheduleToWriteIfNeeded();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager_startLivenessChecker_4::getClass0()
{
    return class_();
}

