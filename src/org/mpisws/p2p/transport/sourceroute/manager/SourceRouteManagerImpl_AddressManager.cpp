// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/LinkedList.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTypes.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_sendMessage_1.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_openSocket_2.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_PendingMessage.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager_PendingSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>

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

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::SourceRouteManagerImpl_AddressManager(SourceRouteManagerImpl *SourceRouteManagerImpl_this, const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
    , SourceRouteManagerImpl_this(SourceRouteManagerImpl_this)
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::SourceRouteManagerImpl_AddressManager(SourceRouteManagerImpl *SourceRouteManagerImpl_this, ::java::lang::Object* address) 
    : SourceRouteManagerImpl_AddressManager(SourceRouteManagerImpl_this, *static_cast< ::default_init_tag* >(0))
{
    ctor(address);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::init()
{
    routes = new ::java::util::HashSet();
}

constexpr int32_t org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::LIVENESS_UNKNOWN;

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::ctor(::java::lang::Object* address)
{
    super::ctor();
    init();
    this->address = address;
    this->pendingMessages = new ::java::util::LinkedList();
    this->pendingSockets = new ::java::util::LinkedList();
    if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"new AddressManager("_j)->append(static_cast< ::java::lang::Object* >(address))
            ->append(u")"_j)->toString());

    clearLivenessState();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::clearLivenessState()
{
    auto temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(routes));
    npc(routes)->clear();
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::sourceroute::SourceRoute* sr = java_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(_i->next());
        {
            npc(SourceRouteManagerImpl_this->livenessProvider)->clearState(sr);
            npc(SourceRouteManagerImpl_this->proxProvider)->clearState(sr);
        }
    }
    if(!npc(pendingMessages)->isEmpty() || !npc(pendingSockets)->isEmpty()) {
        ::java::lang::Exception* reason = new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(java_cast< ::java::lang::Object* >(this->address), ::java::lang::StringBuilder().append(u"State cleared. for "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());
        auto temp3 = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(pendingSockets));
        npc(pendingSockets)->clear();
        for (auto _i = npc(temp3)->iterator(); _i->hasNext(); ) {
            SourceRouteManagerImpl_AddressManager_PendingSocket* foo = java_cast< SourceRouteManagerImpl_AddressManager_PendingSocket* >(_i->next());
            {
                if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".clearLivenessState()1 "_j)
                        ->append(static_cast< ::java::lang::Object* >(foo))->toString());

                npc(foo)->fail(reason);
            }
        }
        auto temp2 = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(pendingMessages));
        npc(pendingMessages)->clear();
        for (auto _i = npc(temp2)->iterator(); _i->hasNext(); ) {
            SourceRouteManagerImpl_AddressManager_PendingMessage* foo = java_cast< SourceRouteManagerImpl_AddressManager_PendingMessage* >(_i->next());
            {
                if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".clearLivenessState()2 "_j)
                        ->append(static_cast< ::java::lang::Object* >(foo))->toString());

                npc(foo)->fail(reason);
            }
        }
    }
    this->liveness = LIVENESS_UNKNOWN;
    this->updated = 0LL;
    best = npc(SourceRouteManagerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->localAddress), java_cast< ::java::lang::Object* >(address));
    npc(routes)->add(static_cast< ::java::lang::Object* >(best));
}

int32_t org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::proximity(::java::util::Map* options)
{
    if(best == nullptr)
        return SourceRouteManagerImpl::DEFAULT_PROXIMITY;
    else
        return npc(SourceRouteManagerImpl_this->proxProvider)->proximity(best, options);
}

int32_t org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::getLiveness(::java::util::Map* options)
{
    if(liveness == LIVENESS_UNKNOWN) {
        if(npc(npc(SourceRouteManagerImpl_this->environment)->getTimeSource())->currentTimeMillis() >= this->updated + SourceRouteManagerImpl_this->CHECK_LIVENESS_THROTTLE) {
            checkLiveness(options);
        }
        return ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED;
    }
    return liveness;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::sendMessage(::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(liveness == ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD) {
        npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(npc(SourceRouteManagerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->getLocalIdentifier()), java_cast< ::java::lang::Object* >(address)), options);
        this->updated = npc(npc(SourceRouteManagerImpl_this->environment)->getTimeSource())->currentTimeMillis();
    }
    if(best == nullptr) {
        auto pending = new SourceRouteManagerImpl_AddressManager_PendingMessage(this, message, deliverAckToMe, options);
        npc(pendingMessages)->addLast(static_cast< ::java::lang::Object* >(pending));
        SourceRouteManagerImpl_this->addHardLink(this);
        return pending;
    }
    auto const handle = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(java_cast< ::java::lang::Object* >(address), message, options);
    npc(handle)->setSubCancellable(npc(SourceRouteManagerImpl_this->tl)->sendMessage(best, message, new SourceRouteManagerImpl_AddressManager_sendMessage_1(this, handle, deliverAckToMe), options));
    return handle;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::openSocket(::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"deliverSocketToMe must be non-null!"_j);

    if(liveness == ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD) {
        npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(npc(SourceRouteManagerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->getLocalIdentifier()), java_cast< ::java::lang::Object* >(address)), options);
        this->updated = npc(npc(SourceRouteManagerImpl_this->environment)->getTimeSource())->currentTimeMillis();
    }
    if(best == nullptr) {
        auto pending = new SourceRouteManagerImpl_AddressManager_PendingSocket(this, deliverSocketToMe, options);
        npc(pendingSockets)->addLast(static_cast< ::java::lang::Object* >(pending));
        SourceRouteManagerImpl_this->addHardLink(this);
        return pending;
    } else {
        auto const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(java_cast< ::java::lang::Object* >(address), options, SourceRouteManagerImpl_this->logger);
        npc(handle)->setSubCancellable(npc(SourceRouteManagerImpl_this->tl)->openSocket(best, new SourceRouteManagerImpl_AddressManager_openSocket_2(this, deliverSocketToMe, handle), options));
        return handle;
    }
}

bool org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::checkLiveness(::java::util::Map* options)
{
    auto now = npc(npc(SourceRouteManagerImpl_this->environment)->getTimeSource())->currentTimeMillis();
    this->updated = now;
    {
        ::org::mpisws::p2p::transport::sourceroute::SourceRoute* temp;
        switch (liveness) {
        case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER:
        case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD: {
                if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(SourceRouteManagerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"(SSRM) CHECKLIVENESS: CHECKING DEAD ON DEAD ADDRESS "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                        ->append(u" - JUST IN CASE, NO HARM ANYWAY"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

                auto ret = false;
                if(npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(npc(SourceRouteManagerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->getLocalIdentifier()), java_cast< ::java::lang::Object* >(address)), options))
                    ret = true;

                auto newroutes = npc(SourceRouteManagerImpl_this->strategy)->getSourceRoutes(java_cast< ::java::lang::Object* >(address));
                for (auto _i = npc(newroutes)->iterator(); _i->hasNext(); ) {
                    ::org::mpisws::p2p::transport::sourceroute::SourceRoute* route = java_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(_i->next());
                    {
                        if(npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(route, options))
                            ret = true;

                    }
                }
                return ret;
            }
        default:
            temp = best;
            if(temp != nullptr) {
                auto ret = npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(best, options);
                if(!npc(temp)->isDirect())
                    npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(npc(SourceRouteManagerImpl_this->srFactory)->getSourceRoute(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->getLocalIdentifier()), java_cast< ::java::lang::Object* >(address)), options);

                return ret;
            }
            return false;
        }
    }

}

java::lang::String* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::toString()
{
    return ::java::lang::StringBuilder().append(u"AM "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(this->address)))->toString();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::livenessChanged(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t val, ::java::util::Map* options)
{
    npc(routes)->add(static_cast< ::java::lang::Object* >(i));
    if(!npc(java_cast< ::java::lang::Object* >(npc(i)->getLastHop()))->equals(java_cast< ::java::lang::Object* >(address)))
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(i))->append(u"!="_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
            ->append(u" val:"_j)
            ->append(val)->toString());

    switch (val) {
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE:
        markAlive(i, options);
        return;
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED:
        markSuspected(i, options);
        return;
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD:
        markDead(i, options);
        return;
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER:
        markDeadForever(options);
        return;
    default:
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Unexpected val:"_j)->append(val)
            ->append(u" i:"_j)
            ->append(static_cast< ::java::lang::Object* >(i))
            ->append(u" address:"_j)
            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))->toString());
    }

}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::markAlive(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route, ::java::util::Map* options)
{
    if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" markAlive("_j)
            ->append(static_cast< ::java::lang::Object* >(route))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(best))->toString());

    if(best == nullptr) {
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"(SSRM) No previous best route existed to "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" route "_j)
                ->append(static_cast< ::java::lang::Object* >(route))
                ->append(u" is now the best"_j)->toString());

        best = route;
    }
    if((npc(best)->getNumHops() > npc(route)->getNumHops()) || ((npc(best)->getNumHops() == npc(route)->getNumHops()) && (npc(SourceRouteManagerImpl_this->proxProvider)->proximity(best, options) > npc(SourceRouteManagerImpl_this->proxProvider)->proximity(route, options)))) {
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"(SSRM) Route "_j)->append(static_cast< ::java::lang::Object* >(route))
                ->append(u" is better than previous best route "_j)
                ->append(static_cast< ::java::lang::Object* >(best))
                ->append(u" - replacing"_j)->toString());

        best = route;
    }
    setAlive(options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::markSuspected(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route, ::java::util::Map* options)
{
    if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" markSuspected("_j)
            ->append(static_cast< ::java::lang::Object* >(route))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(best))->toString());

    if(((best == nullptr) || (npc(best)->equals(static_cast< ::java::lang::Object* >(route)))) && (liveness < ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD))
        setSuspected(options);

}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::markDead(::org::mpisws::p2p::transport::sourceroute::SourceRoute* deadRoute, ::java::util::Map* options)
{
    if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" markDead("_j)
            ->append(static_cast< ::java::lang::Object* >(deadRoute))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(best))->toString());

    if(liveness >= ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD)
        return;

    if((best == nullptr) || (npc(deadRoute)->equals(static_cast< ::java::lang::Object* >(best)))) {
        best = nullptr;
        auto newroutes = npc(SourceRouteManagerImpl_this->strategy)->getSourceRoutes(java_cast< ::java::lang::Object* >(address));
        npc(java_cast< ::java::util::HashSet* >(this->routes))->addAll(static_cast< ::java::util::Collection* >(newroutes));
        auto found = false;
        ::org::mpisws::p2p::transport::sourceroute::SourceRoute* newBest = nullptr;
        for (auto _i = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(java_cast< ::java::util::HashSet* >(this->routes)))->iterator(); _i->hasNext(); ) {
            ::org::mpisws::p2p::transport::sourceroute::SourceRoute* route = java_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(_i->next());
            {
                if(!npc(java_cast< ::java::lang::Object* >(npc(route)->getLastHop()))->equals(java_cast< ::java::lang::Object* >(address))) {
                    if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::SEVERE)
                        npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"SRStrategy "_j)->append(static_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->strategy))
                            ->append(u" is broken.  It returned "_j)
                            ->append(static_cast< ::java::lang::Object* >(route))
                            ->append(u" as a route to "_j)
                            ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))->toString());

                } else {
                    if(npc(SourceRouteManagerImpl_this->livenessProvider)->checkLiveness(route, options)) {
                        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" Checking "_j)
                                ->append(static_cast< ::java::lang::Object* >(route))->toString());

                        found = true;
                    }
                    if(npc(SourceRouteManagerImpl_this->livenessProvider)->getLiveness(route, options) < ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD) {
                        if(newBest == nullptr || (npc(newBest)->getNumHops() > npc(route)->getNumHops()) || ((npc(newBest)->getNumHops() == npc(route)->getNumHops()) && (npc(SourceRouteManagerImpl_this->proxProvider)->proximity(newBest, options) > npc(SourceRouteManagerImpl_this->proxProvider)->proximity(route, options)))) {
                            newBest = route;
                        }
                        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u" Found "_j)
                                ->append(static_cast< ::java::lang::Object* >(route))->toString());

                        found = true;
                    }
                }
            }
        }
        if(newBest != nullptr) {
            if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
                npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Found existing known route "_j)->append(static_cast< ::java::lang::Object* >(newBest))
                    ->append(u" to replace old dead route "_j)
                    ->append(static_cast< ::java::lang::Object* >(deadRoute))
                    ->append(u" - replacing"_j)->toString());

            best = newBest;
            auto tempLiveness = npc(SourceRouteManagerImpl_this->livenessProvider)->getLiveness(newBest, options);
            if(tempLiveness == ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE) {
                setAlive(options);
            } else if(tempLiveness == ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED) {
                setSuspected(options);
            }
            return;
        }
        if(found) {
            setSuspected(options);
        } else {
            setDead(options);
        }
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::markDeadForever(::java::util::Map* options)
{
    this->best = nullptr;
    setDeadForever(options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::markProximity(::org::mpisws::p2p::transport::sourceroute::SourceRoute* route, int32_t proximity, ::java::util::Map* options)
{
    if(best == nullptr) {
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"(SSRM) No previous best route existed to "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" route "_j)
                ->append(static_cast< ::java::lang::Object* >(route))
                ->append(u" is now the best"_j)->toString());

        best = route;
    }
    if(npc(route)->equals(static_cast< ::java::lang::Object* >(best))) {
        SourceRouteManagerImpl_this->notifyProximityListeners(java_cast< ::java::lang::Object* >(address), proximity, options);
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::setAlive(::java::util::Map* options)
{
    if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"setAlive():"_j)
            ->append(static_cast< ::java::lang::Object* >(best))->toString());

    if(best == nullptr)
        throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"best is null in "_j)->append(toString())->toString());

    while (!npc(pendingMessages)->isEmpty()) {
        auto pm = java_cast< SourceRouteManagerImpl_AddressManager_PendingMessage* >(npc(pendingMessages)->removeFirst());
        npc(pm)->cancellable = npc(SourceRouteManagerImpl_this->tl)->sendMessage(best, npc(pm)->message, pm, npc(pm)->options);
    }
    while (!npc(pendingSockets)->isEmpty()) {
        auto pas = java_cast< SourceRouteManagerImpl_AddressManager_PendingSocket* >(npc(pendingSockets)->removeFirst());
        npc(pas)->cancellable = npc(SourceRouteManagerImpl_this->tl)->openSocket(best, pas, npc(pas)->options);
    }
    if(npc(pendingMessages)->isEmpty() && npc(pendingSockets)->isEmpty())
        npc(SourceRouteManagerImpl_this->hardLinks)->remove(static_cast< ::java::lang::Object* >(this));

    switch (liveness) {
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER:
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD:
        liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE;
        SourceRouteManagerImpl_this->notifyLivenessListeners(java_cast< ::java::lang::Object* >(address), ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE, options);
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->localAddress)))
                ->append(u" Found address "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be alive again."_j)->toString());

        break;
    case LIVENESS_UNKNOWN:
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED:
        liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE;
        SourceRouteManagerImpl_this->notifyLivenessListeners(java_cast< ::java::lang::Object* >(address), ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE, options);
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->localAddress)))
                ->append(u" Found address "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be unsuspected."_j)->toString());

        break;
    }

}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::setSuspected(::java::util::Map* options)
{
    switch (liveness) {
    case LIVENESS_UNKNOWN:
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_ALIVE:
        liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED;
        SourceRouteManagerImpl_this->notifyLivenessListeners(java_cast< ::java::lang::Object* >(address), ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED, options);
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: "_j)->append(npc(npc(SourceRouteManagerImpl_this->environment)->getTimeSource())->currentTimeMillis())
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->localAddress)))
                ->append(u" Found address "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be suspected."_j)->toString());

        break;
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER:
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD:
        liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED;
        SourceRouteManagerImpl_this->notifyLivenessListeners(java_cast< ::java::lang::Object* >(address), ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_SUSPECTED, options);
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(SourceRouteManagerImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"ERROR: Found node handle "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be suspected from dead - should not happen!"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        break;
    }

}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::setDead(::java::util::Map* options)
{
    switch (liveness) {
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER:
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD:
        return;
    default:
        this->best = nullptr;
        this->liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD;
        SourceRouteManagerImpl_this->notifyLivenessListeners(java_cast< ::java::lang::Object* >(address), ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD, options);
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"COUNT: "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(SourceRouteManagerImpl_this->localAddress)))
                ->append(u" Found address "_j)
                ->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be dead."_j)->toString());

        break;
    }

    purgeQueue();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::setDeadForever(::java::util::Map* options)
{
    switch (liveness) {
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER:
        return;
    case ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD:
        this->liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER;
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Found address "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be dead forever."_j)->toString());

        break;
    default:
        this->best = nullptr;
        this->liveness = ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER;
        SourceRouteManagerImpl_this->notifyLivenessListeners(java_cast< ::java::lang::Object* >(address), ::org::mpisws::p2p::transport::liveness::LivenessTypes::LIVENESS_DEAD_FOREVER, options);
        if(npc(SourceRouteManagerImpl_this->logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(SourceRouteManagerImpl_this->logger)->log(::java::lang::StringBuilder().append(u"Found address "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(address)))
                ->append(u" to be dead forever."_j)->toString());

        break;
    }

    purgeQueue();
    clearLivenessState();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::purgeQueue()
{
    while (!npc(pendingMessages)->isEmpty()) {
        auto pm = java_cast< SourceRouteManagerImpl_AddressManager_PendingMessage* >(npc(pendingMessages)->removeFirst());
        if(npc(pm)->deliverAckToMe != nullptr)
            npc(npc(pm)->deliverAckToMe)->sendFailed(pm, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(java_cast< ::java::lang::Object* >(address)));

    }
    while (!npc(pendingSockets)->isEmpty()) {
        auto ps = java_cast< SourceRouteManagerImpl_AddressManager_PendingSocket* >(npc(pendingSockets)->removeFirst());
        npc(npc(ps)->deliverSocketToMe)->receiveException(ps, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(java_cast< ::java::lang::Object* >(address)));
    }
    SourceRouteManagerImpl_this->removeHardLink(this);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.manager.SourceRouteManagerImpl.AddressManager", 82);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager::getClass0()
{
    return class_();
}

