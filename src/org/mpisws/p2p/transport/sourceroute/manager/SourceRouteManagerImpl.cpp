// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.java
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRoute.hpp>
#include <org/mpisws/p2p/transport/sourceroute/SourceRouteFactory.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerImpl_AddressManager.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteManagerP2PSocket.hpp>
#include <org/mpisws/p2p/transport/sourceroute/manager/SourceRouteStrategy.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>

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
org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::SourceRouteManagerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::SourceRouteManagerImpl(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider, ::rice::environment::Environment* env, SourceRouteStrategy* strategy) 
    : SourceRouteManagerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(srFactory,tl,livenessProvider,proxProvider,env,strategy);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::init()
{
    CHECK_LIVENESS_THROTTLE = int32_t(5000);
    listeners = new ::java::util::ArrayList();
}

constexpr int32_t org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::DEFAULT_PROXIMITY;

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::ctor(::org::mpisws::p2p::transport::sourceroute::SourceRouteFactory* srFactory, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider, ::rice::environment::Environment* env, SourceRouteStrategy* strategy)
{
    super::ctor();
    init();
    if(tl == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"tl == null"_j);

    if(proxProvider == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"proxProvider == null"_j);

    if(strategy == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"strategy == null"_j);

    this->tl = tl;
    this->livenessProvider = livenessProvider;
    this->proxProvider = proxProvider;
    npc(java_cast< ::org::mpisws::p2p::transport::proximity::ProximityProvider* >(this->proxProvider))->addProximityListener(this);
    this->strategy = strategy;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(SourceRouteManagerImpl::class_(), nullptr);
    this->srFactory = srFactory;
    this->localAddress = java_cast< ::java::lang::Object* >(npc(java_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(npc(tl)->getLocalIdentifier()))->getFirstHop());
    npc(tl)->setCallback(this);
    npc(livenessProvider)->addLivenessListener(this);
    addressManagers = new ::java::util::HashMap();
    auto p = npc(environment)->getParameters();
    PING_THROTTLE = npc(p)->getLong(u"pastry_socket_srm_ping_throttle"_j);
    NUM_SOURCE_ROUTE_ATTEMPTS = npc(p)->getInt(u"pastry_socket_srm_num_source_route_attempts"_j);
    hardLinks = new ::java::util::HashSet();
    livenessListeners = new ::java::util::ArrayList();
    pingListeners = new ::java::util::ArrayList();
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    return npc(getAddressManager(i))->sendMessage(m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl_AddressManager* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::getAddressManager(::java::lang::Object* address)
{
    {
        synchronized synchronized_0(addressManagers);
        {
            auto manager = java_cast< SourceRouteManagerImpl_AddressManager* >(npc(addressManagers)->get(address));
            if(manager == nullptr) {
                manager = new SourceRouteManagerImpl_AddressManager(this, address);
                npc(addressManagers)->put(address, manager);
            } else {
            }
            return manager;
        }
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::clearState(::java::lang::Object* i)
{
    npc(getAddressManager(i))->clearLivenessState();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::addHardLink(SourceRouteManagerImpl_AddressManager* am)
{
    {
        synchronized synchronized_1(hardLinks);
        {
            npc(hardLinks)->add(static_cast< ::java::lang::Object* >(am));
        }
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::removeHardLink(SourceRouteManagerImpl_AddressManager* am)
{
    {
        synchronized synchronized_2(hardLinks);
        {
            npc(hardLinks)->remove(static_cast< ::java::lang::Object* >(am));
        }
    }
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(50))
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    return npc(getAddressManager(i))->openSocket(deliverSocketToMe, options);
}

bool org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::checkLiveness(::java::lang::Object* address, ::java::util::Map* options)
{
    return npc(getAddressManager(address))->checkLiveness(options);
}

int32_t org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::getLiveness(::java::lang::Object* address, ::java::util::Map* options)
{
    return npc(getAddressManager(address))->getLiveness(options);
}

int32_t org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::proximity(::java::lang::Object* address, ::java::util::Map* options)
{
    return npc(getAddressManager(address))->proximity(options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(localAddress);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::destroy()
{
    npc(tl)->destroy();
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_3(livenessListeners);
        {
            npc(livenessListeners)->add(static_cast< ::java::lang::Object* >(name));
        }
    }
}

bool org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_4(livenessListeners);
        {
            return npc(livenessListeners)->remove(static_cast< ::java::lang::Object* >(name));
        }
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyLivenessListeners("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(liveness)
            ->append(u")"_j)->toString());

    ::java::util::List* temp;
    {
        synchronized synchronized_5(livenessListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(livenessListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::liveness::LivenessListener* listener = java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(_i->next());
        {
            npc(listener)->livenessChanged(i, liveness, options);
        }
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(callback)->incomingSocket(new SourceRouteManagerP2PSocket(s, logger, errorHandler, environment));
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::messageReceived(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(java_cast< ::java::lang::Object* >(npc(i)->getLastHop()), m, options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::livenessChanged(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t val, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"livenessChanged("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(val)
            ->append(u")"_j)->toString());

    npc(getAddressManager(java_cast< ::java::lang::Object* >(npc(i)->getLastHop())))->livenessChanged(i, val, options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{ 
    livenessChanged(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), val, options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    {
        synchronized synchronized_6(listeners);
        {
            npc(listeners)->add(listener);
        }
    }
}

bool org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    {
        synchronized synchronized_7(listeners);
        {
            return npc(listeners)->remove(listener);
        }
    }
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::proximityChanged(::org::mpisws::p2p::transport::sourceroute::SourceRoute* i, int32_t newProximity, ::java::util::Map* options)
{
    npc(getAddressManager(java_cast< ::java::lang::Object* >(npc(i)->getLastHop())))->markProximity(i, newProximity, options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options)
{ 
    proximityChanged(dynamic_cast< ::org::mpisws::p2p::transport::sourceroute::SourceRoute* >(i), newProximity, options);
}

void org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::notifyProximityListeners(::java::lang::Object* i, int32_t prox, ::java::util::Map* options)
{
    ::java::util::Collection* temp;
    {
        synchronized synchronized_8(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::proximity::ProximityListener* p = java_cast< ::org::mpisws::p2p::transport::proximity::ProximityListener* >(_i->next());
        {
            npc(p)->proximityChanged(i, prox, options);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.sourceroute.manager.SourceRouteManagerImpl", 67);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::sourceroute::manager::SourceRouteManagerImpl::getClass0()
{
    return class_();
}

