// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager_checkLiveness_1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_DeadChecker.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/selector/SelectorManager.hpp>

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
org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::LivenessTransportLayerImpl_EntityManager(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , LivenessTransportLayerImpl_this(LivenessTransportLayerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::LivenessTransportLayerImpl_EntityManager(LivenessTransportLayerImpl *LivenessTransportLayerImpl_this, ::java::lang::Object* identifier) 
    : LivenessTransportLayerImpl_EntityManager(LivenessTransportLayerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(identifier);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::init()
{
    RTO = LivenessTransportLayerImpl_this->DEFAULT_RTO;
    RTT = int32_t(0);
    standardD = RTO / 4.0;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::ctor(::java::lang::Object* identifier)
{
    super::ctor();
    init();
    if(identifier == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"identifier is null"_j);

    this->identifier = new ::java::lang::ref::WeakReference(identifier);
    this->liveness = LivenessTypes::LIVENESS_SUSPECTED;
    this->pendingDeadchecker = nullptr;
    this->updated = 0LL;
    sockets = new ::java::util::HashSet();
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_DeadChecker* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::getPending()
{
    return pendingDeadchecker;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::setPending(LivenessTransportLayerImpl_DeadChecker* d)
{
    pendingDeadchecker = d;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::removeSocket(LivenessTransportLayerImpl_LSocket* socket)
{
    {
        synchronized synchronized_0(sockets);
        {
            npc(sockets)->remove(static_cast< ::java::lang::Object* >(socket));
        }
    }
}

int32_t org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::rto()
{
    return static_cast< int32_t >(RTO);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::markAlive(::java::util::Map* options)
{
    auto notify = false;
    if(liveness != LivenessTypes::LIVENESS_ALIVE)
        notify = true;

    this->liveness = LivenessTypes::LIVENESS_ALIVE;
    if(notify) {
        auto temp = java_cast< ::java::lang::Object* >(npc(identifier)->get());
        if(temp != nullptr) {
            LivenessTransportLayerImpl_this->notifyLivenessListeners(temp, liveness, options);
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::markSuspected(::java::util::Map* options)
{
    if(liveness > LivenessTypes::LIVENESS_SUSPECTED)
        return;

    auto notify = false;
    if(liveness != LivenessTypes::LIVENESS_SUSPECTED)
        notify = true;

    this->liveness = LivenessTypes::LIVENESS_SUSPECTED;
    if(notify) {
        if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".markSuspected() notify = true"_j)->toString());

        auto temp = java_cast< ::java::lang::Object* >(npc(identifier)->get());
        if(temp != nullptr) {
            LivenessTransportLayerImpl_this->notifyLivenessListeners(temp, liveness, options);
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::markDead(::java::util::Map* options)
{
    auto notify = false;
    if(liveness < LivenessTypes::LIVENESS_DEAD)
        notify = true;

    if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".markDead() notify:"_j)
            ->append(notify)->toString());

    markDeadHelper(LivenessTypes::LIVENESS_DEAD, options, notify);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::markDeadForever(::java::util::Map* options)
{
    auto notify = false;
    if(liveness < LivenessTypes::LIVENESS_DEAD_FOREVER)
        notify = true;

    if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".markDeadForever() notify:"_j)
            ->append(notify)->toString());

    markDeadHelper(LivenessTypes::LIVENESS_DEAD_FOREVER, options, notify);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::markDeadHelper(int32_t liveness, ::java::util::Map* options, bool notify)
{
    this->liveness = liveness;
    if(getPending() != nullptr) {
        npc(getPending())->cancel();
    }
    if(notify) {
        auto temp = java_cast< ::java::lang::Object* >(npc(identifier)->get());
        if(temp != nullptr) {
            LivenessTransportLayerImpl_this->notifyLivenessListeners(temp, liveness, options);
        } else {
            if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"markDeadHelper("_j)->append(liveness)
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(options))
                    ->append(u","_j)
                    ->append(notify)
                    ->append(u") temp == null!  Can't notify listeners!"_j)->toString());

        }
    }
    ::java::util::ArrayList* temp;
    {
        synchronized synchronized_1(sockets);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(sockets));
            npc(sockets)->clear();
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        LivenessTransportLayerImpl_LSocket* sock = java_cast< LivenessTransportLayerImpl_LSocket* >(_i->next());
        {
            if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::INFO)
                npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"closing "_j)->append(static_cast< ::java::lang::Object* >(sock))->toString());

            npc(sock)->close();
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::updateRTO(int64_t m)
{
    if(m < 0)
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"rtt must be >= 0, was:"_j)->append(m)->toString());

    auto err = m - RTT;
    auto absErr = err;
    if(absErr < 0) {
        absErr *= -int32_t(1);
    }
    RTT = RTT + LivenessTransportLayerImpl_this->gainG * err;
    standardD = standardD + LivenessTransportLayerImpl_this->gainH * (absErr - standardD);
    RTO = static_cast< int32_t >((RTT + (4.0 * standardD)));
    if(RTO > LivenessTransportLayerImpl_this->RTO_UBOUND) {
        RTO = LivenessTransportLayerImpl_this->RTO_UBOUND;
    }
    if(RTO < LivenessTransportLayerImpl_this->RTO_LBOUND) {
        RTO = LivenessTransportLayerImpl_this->RTO_LBOUND;
    }
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::checkLiveness(::java::util::Map* options)
{
    if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".checkLiveness()"_j)->toString());

    auto ret = false;
    auto rto = LivenessTransportLayerImpl_this->DEFAULT_RTO;
    {
        synchronized synchronized_2(this);
        {
            if(this->getPending() != nullptr) {
                if(this->liveness < LivenessTypes::LIVENESS_DEAD) {
                    return true;
                } else {
                    return false;
                }
            }
            auto now = npc(LivenessTransportLayerImpl_this->time)->currentTimeMillis();
            if((this->liveness < LivenessTypes::LIVENESS_DEAD) || (this->updated < now - LivenessTransportLayerImpl_this->CHECK_DEAD_THROTTLE)) {
                this->updated = now;
                rto = static_cast< LivenessTransportLayerImpl_EntityManager* >(this)->rto();
                this->setPending(new LivenessTransportLayerImpl_DeadChecker(LivenessTransportLayerImpl_this, this, LivenessTransportLayerImpl_this->NUM_PING_TRIES, rto, options));
                ret = true;
            } else {
                if(npc(LivenessTransportLayerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER) {
                    npc(LivenessTransportLayerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".checkLiveness() not checking "_j)
                        ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(identifier)->get())))
                        ->append(u" checked to recently, can't check for "_j)
                        ->append(((updated + LivenessTransportLayerImpl_this->CHECK_DEAD_THROTTLE) - now))
                        ->append(u" millis."_j)->toString());
                }
            }
        }
    }
    if(ret) {
        auto const theRTO = rto;
        ::java::lang::Runnable* r = new LivenessTransportLayerImpl_EntityManager_checkLiveness_1(this, theRTO, options);
        if(npc(npc(LivenessTransportLayerImpl_this->environment)->getSelectorManager())->isSelectorThread()) {
            npc(r)->run();
        } else {
            npc(npc(LivenessTransportLayerImpl_this->environment)->getSelectorManager())->invoke(r);
        }
    }
    if(this->liveness >= LivenessTypes::LIVENESS_DEAD)
        return false;

    return ret;
}

java::lang::String* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::toString()
{
    auto temp = java_cast< ::java::lang::Object* >(npc(identifier)->get());
    if(temp == nullptr)
        return u"null"_j;

    return npc(temp)->toString();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::destroy()
{
    if(getPending() != nullptr)
        npc(getPending())->cancel();

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.LivenessTransportLayerImpl.EntityManager", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager::getClass0()
{
    return class_();
}

