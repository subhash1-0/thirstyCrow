// Generated from /pastry-2.1/src/rice/pastry/PastryNode.java
#include <rice/pastry/PastryNode.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Iterable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Collections.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/HashSet.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <java/util/Vector.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayer.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/Continuation.hpp>
#include <rice/Destructable.hpp>
#include <rice/Executable.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/processing/Processor.hpp>
#include <rice/p2p/commonapi/exception/AppNotRegisteredException.hpp>
#include <rice/p2p/commonapi/exception/NoReceiverAvailableException.hpp>
#include <rice/p2p/commonapi/rawserialization/MessageDeserializer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawMessage.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/JoinFailedException.hpp>
#include <rice/pastry/NetworkListener.hpp>
#include <rice/pastry/NodeHandle.hpp>
#include <rice/pastry/NodeHandleFactory.hpp>
#include <rice/pastry/NodeHandleFactoryListener.hpp>
#include <rice/pastry/NodeHandleFetcher.hpp>
#include <rice/pastry/PastryNode_destroy_2.hpp>
#include <rice/pastry/PastryNode_connect_3.hpp>
#include <rice/pastry/PastryNode_incomingSocket_4.hpp>
#include <rice/pastry/PastryNode_send_5.hpp>
#include <rice/pastry/PastryNode_send_6.hpp>
#include <rice/pastry/PastryNode_send_7.hpp>
#include <rice/pastry/PastryNode_getDefaultReadyStrategy_1.hpp>
#include <rice/pastry/ReadyStrategy.hpp>
#include <rice/pastry/ScheduledMessage.hpp>
#include <rice/pastry/boot/Bootstrapper.hpp>
#include <rice/pastry/client/PastryAppl.hpp>
#include <rice/pastry/commonapi/PastryEndpoint.hpp>
#include <rice/pastry/commonapi/PastryIdFactory.hpp>
#include <rice/pastry/join/JoinProtocol.hpp>
#include <rice/pastry/leafset/InitiateLeafSetMaintenance.hpp>
#include <rice/pastry/leafset/LeafSet.hpp>
#include <rice/pastry/messaging/Message.hpp>
#include <rice/pastry/messaging/MessageDispatch.hpp>
#include <rice/pastry/messaging/PJavaSerializedMessage.hpp>
#include <rice/pastry/messaging/PRawMessage.hpp>
#include <rice/pastry/routing/InitiateRouteSetMaintenance.hpp>
#include <rice/pastry/routing/Router.hpp>
#include <rice/pastry/routing/RoutingTable.hpp>
#include <rice/pastry/transport/PMessageNotification.hpp>
#include <rice/pastry/transport/PMessageReceipt.hpp>
#include <rice/pastry/transport/PMessageReceiptImpl.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>

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
rice::pastry::PastryNode::PastryNode(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::pastry::PastryNode::PastryNode(Id* id, ::rice::environment::Environment* e) 
    : PastryNode(*static_cast< ::default_init_tag* >(0))
{
    ctor(id,e);
}

void rice::pastry::PastryNode::init()
{
    joinFailed_ = false;
    isDestroyed = false;
    defaultReadyStrategy = nullptr;
    neverBeenReady = true;
    destructables = new ::java::util::HashSet();
    leafSetRoutineMaintenance = nullptr;
    routeSetRoutineMaintenance = nullptr;
    vars = new ::java::util::HashMap();
    livenessListeners = new ::java::util::ArrayList();
    networkListeners = new ::java::util::ArrayList();
}

constexpr int8_t rice::pastry::PastryNode::CONNECTION_UNKNOWN_ERROR;

constexpr int8_t rice::pastry::PastryNode::CONNECTION_UNKNOWN;

constexpr int8_t rice::pastry::PastryNode::CONNECTION_OK;

constexpr int8_t rice::pastry::PastryNode::CONNECTION_NO_APP;

constexpr int8_t rice::pastry::PastryNode::CONNECTION_NO_ACCEPTOR;

void rice::pastry::PastryNode::ctor(Id* id, ::rice::environment::Environment* e)
{
    super::ctor();
    init();
    myEnvironment = e;
    myNodeId = id;
    readyStrategy = getDefaultReadyStrategy();
    apps = new ::java::util::Vector();
    logger = npc(npc(e)->getLogManager())->getLogger(getClass(), nullptr);
    npc(e)->addDestructable(this);
}

void rice::pastry::PastryNode::boot(::java::lang::Object* o)
{
    if(o == nullptr) {
        npc(getBootstrapper())->boot(::java::util::Collections::EMPTY_LIST());
    } else {
        if(dynamic_cast< ::java::util::Collection* >(o) != nullptr) {
            boot(java_cast< ::java::util::Collection* >(o));
        } else {
            npc(getBootstrapper())->boot(::java::util::Collections::singleton(o));
        }
    }
}

void rice::pastry::PastryNode::boot(::java::util::Collection* o2)
{
    auto o = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(o2));
    while (npc(o)->remove(static_cast< ::java::lang::Object* >(nullptr))) 
                ;

    npc(getBootstrapper())->boot(o);
}

rice::pastry::ReadyStrategy* rice::pastry::PastryNode::getDefaultReadyStrategy()
{
    if(defaultReadyStrategy != nullptr)
        return defaultReadyStrategy;

    defaultReadyStrategy = new PastryNode_getDefaultReadyStrategy_1(this);
    return defaultReadyStrategy;
}

void rice::pastry::PastryNode::setReadyStrategy(ReadyStrategy* rs)
{
    readyStrategy = rs;
}

void rice::pastry::PastryNode::setElements(NodeHandle* lh, ::rice::pastry::messaging::MessageDispatch* md, ::rice::pastry::leafset::LeafSet* ls, ::rice::pastry::routing::RoutingTable* rt, ::rice::pastry::routing::Router* router)
{
    localhandle = lh;
    setMessageDispatch(md);
    leafSet = ls;
    routeSet = rt;
    this->router = router;
}

void rice::pastry::PastryNode::setJoinProtocols(::rice::pastry::boot::Bootstrapper* boot, ::rice::pastry::join::JoinProtocol* joinP, ::rice::pastry::leafset::LeafSetProtocol* leafsetP, ::rice::pastry::routing::RouteSetProtocol* routeP)
{
    this->bootstrapper = boot;
    this->joiner = joinP;
}

rice::p2p::commonapi::NodeHandle* rice::pastry::PastryNode::getLocalNodeHandle()
{
    return localhandle;
}

rice::environment::Environment* rice::pastry::PastryNode::getEnvironment()
{
    return myEnvironment;
}

rice::pastry::NodeHandle* rice::pastry::PastryNode::getLocalHandle()
{
    return localhandle;
}

rice::pastry::Id* rice::pastry::PastryNode::getNodeId()
{
    return myNodeId;
}

bool rice::pastry::PastryNode::isReady()
{
    return npc(readyStrategy)->isReady();
}

rice::pastry::messaging::MessageDispatch* rice::pastry::PastryNode::getMessageDispatch()
{
    return myMessageDispatch;
}

void rice::pastry::PastryNode::setMessageDispatch(::rice::pastry::messaging::MessageDispatch* md)
{
    myMessageDispatch = md;
    addDestructable(myMessageDispatch);
}

rice::Destructable* rice::pastry::PastryNode::addDestructable(::rice::Destructable* d)
{
    npc(destructables)->add(static_cast< ::java::lang::Object* >(d));
    return d;
}

bool rice::pastry::PastryNode::removeDestructable(::rice::Destructable* d)
{
    return npc(destructables)->remove(static_cast< ::java::lang::Object* >(d));
}

void rice::pastry::PastryNode::nodeIsReady(bool state)
{
}

void rice::pastry::PastryNode::setReady()
{
    setReady(true);
}

void rice::pastry::PastryNode::setReady(bool ready)
{
    npc(readyStrategy)->setReady(ready);
}

rice::pastry::NodeHandle* rice::pastry::PastryNode::coalesce(NodeHandle* newHandle)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"coalesce("_j)->append(static_cast< ::java::lang::Object* >(newHandle))
            ->append(u")"_j)->toString());

    return java_cast< NodeHandle* >(npc(handleFactory)->coalesce(newHandle));
}

void rice::pastry::PastryNode::notifyReadyObservers()
{
    auto ready = npc(readyStrategy)->isReady();
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"PastryNode.notifyReadyObservers("_j)->append(ready)
            ->append(u")"_j)->toString());

    if(ready) {
        nodeIsReady();
        nodeIsReady(true);
        setChanged();
        notifyObservers(::java::lang::Boolean::valueOf(true));
        if(neverBeenReady) {
            auto tmpApps = new ::java::util::Vector(static_cast< ::java::util::Collection* >(apps));
            auto it = npc(tmpApps)->iterator();
            while (npc(it)->hasNext()) 
                                npc((java_cast< ::rice::pastry::client::PastryAppl* >((java_cast< ::rice::pastry::client::PastryAppl* >(npc(it)->next())))))->notifyReady();

            neverBeenReady = false;
        }
        {
            synchronized synchronized_0(this);
            {
                notifyAll();
            }
        }
    } else {
        nodeIsReady(false);
        setChanged();
        notifyObservers(new ::java::lang::Boolean(false));
    }
}

bool rice::pastry::PastryNode::isClosest(Id* key)
{
    if(npc(leafSet)->mostSimilar(key) == 0)
        return true;
    else
        return false;
}

rice::pastry::leafset::LeafSet* rice::pastry::PastryNode::getLeafSet()
{
    return leafSet;
}

rice::pastry::routing::RoutingTable* rice::pastry::PastryNode::getRoutingTable()
{
    return routeSet;
}

void rice::pastry::PastryNode::addLeafSetObserver(::java::util::Observer* o)
{
    npc(leafSet)->addObserver(o);
}

void rice::pastry::PastryNode::deleteLeafSetObserver(::java::util::Observer* o)
{
    npc(leafSet)->deleteObserver(o);
}

void rice::pastry::PastryNode::addLeafSetListener(NodeSetListener* listener)
{
    npc(leafSet)->addNodeSetListener(listener);
}

void rice::pastry::PastryNode::deleteLeafSetListener(NodeSetListener* listener)
{
    npc(leafSet)->deleteNodeSetListener(listener);
}

void rice::pastry::PastryNode::addRouteSetObserver(::java::util::Observer* o)
{
    npc(routeSet)->addObserver(o);
}

void rice::pastry::PastryNode::deleteRouteSetObserver(::java::util::Observer* o)
{
    npc(routeSet)->deleteObserver(o);
}

void rice::pastry::PastryNode::addRouteSetListener(NodeSetListener* listener)
{
    npc(routeSet)->addNodeSetListener(listener);
}

void rice::pastry::PastryNode::removeRouteSetListener(NodeSetListener* listener)
{
    npc(routeSet)->removeNodeSetListener(listener);
}

void rice::pastry::PastryNode::receiveMessage(::rice::pastry::messaging::Message* msg)
{
    if(isDestroyed)
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"receiveMessage("_j)->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

    npc(myMessageDispatch)->dispatchMessage(msg);
}

void rice::pastry::PastryNode::registerReceiver(int32_t address, ::rice::pastry::client::PastryAppl* receiver)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"registerReceiver("_j)->append(address)
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(receiver))
            ->append(u"):"_j)
            ->append(static_cast< ::java::lang::Object* >(npc(receiver)->getDeserializer()))->toString());

    npc(myMessageDispatch)->registerReceiver(address, receiver);
}

void rice::pastry::PastryNode::registerApp(::rice::pastry::client::PastryAppl* app)
{
    if(isReady())
        npc(app)->notifyReady();

    npc(apps)->add(static_cast< ::java::lang::Object* >(app));
}

java::lang::String* rice::pastry::PastryNode::toString()
{
    return ::java::lang::StringBuilder().append(u"PastryNode"_j)->append(static_cast< ::java::lang::Object* >(localhandle))->toString();
}

rice::p2p::commonapi::Endpoint* rice::pastry::PastryNode::registerApplication(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance)
{
    return new ::rice::pastry::commonapi::PastryEndpoint(this, application, instance, true);
}

rice::p2p::commonapi::Endpoint* rice::pastry::PastryNode::buildEndpoint(::rice::p2p::commonapi::Application* application, ::java::lang::String* instance)
{
    return new ::rice::pastry::commonapi::PastryEndpoint(this, application, instance, false);
}

rice::p2p::commonapi::Id* rice::pastry::PastryNode::getId()
{
    return getNodeId();
}

rice::p2p::commonapi::IdFactory* rice::pastry::PastryNode::getIdFactory()
{
    return new ::rice::pastry::commonapi::PastryIdFactory(getEnvironment());
}

void rice::pastry::PastryNode::process(::rice::Executable* task, ::rice::Continuation* command)
{
    try {
        npc(npc(myEnvironment)->getProcessor())->process(task, command, npc(myEnvironment)->getSelectorManager(), npc(myEnvironment)->getTimeSource(), npc(myEnvironment)->getLogManager());
    } catch (::java::lang::Exception* e) {
        npc(command)->receiveException(e);
    }
}

void rice::pastry::PastryNode::destroy()
{
    if(isDestroyed)
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Destroying "_j)->append(static_cast< ::java::lang::Object* >(this))->toString());

    isDestroyed = true;
    auto i = npc(destructables)->iterator();
    while (npc(i)->hasNext()) {
        auto d = java_cast< ::rice::Destructable* >(npc(i)->next());
        if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(5))
            npc(logger)->log(::java::lang::StringBuilder().append(u"Destroying "_j)->append(static_cast< ::java::lang::Object* >(d))->toString());

        npc(d)->destroy();
    }
    npc(getEnvironment())->removeDestructable(this);
    if(npc(npc(getEnvironment())->getSelectorManager())->isSelectorThread()) {
        if(tl != nullptr)
            npc(tl)->destroy();

    } else {
        npc(npc(getEnvironment())->getSelectorManager())->invoke(new PastryNode_destroy_2(this));
    }
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::pastry::PastryNode::connect(NodeHandle* i, ::rice::p2p::commonapi::appsocket::AppSocketReceiver* deliverSocketToMe, ::rice::pastry::client::PastryAppl* appl, int32_t timeout)
{
    auto const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, nullptr, logger);
    ::java::lang::Runnable* r = new PastryNode_connect_3(this, appl, handle, i, deliverSocketToMe);
    if(npc(npc(myEnvironment)->getSelectorManager())->isSelectorThread()) {
        npc(r)->run();
    } else {
        npc(npc(myEnvironment)->getSelectorManager())->invoke(r);
    }
    return handle;
}

void rice::pastry::PastryNode::joinFailed(JoinFailedException* cje)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(logger)->log(::java::lang::StringBuilder().append(u"joinFailed("_j)->append(static_cast< ::java::lang::Object* >(cje))
            ->append(u")"_j)->toString());

    joinFailedReason_ = cje;
    {
        synchronized synchronized_1(this);
        {
            joinFailed_ = true;
            this->notifyAll();
        }
    }
    setChanged();
    this->notifyObservers(cje);
}

bool rice::pastry::PastryNode::joinFailed()
{
    return joinFailed_;
}

rice::pastry::JoinFailedException* rice::pastry::PastryNode::joinFailedReason()
{
    return joinFailedReason_;
}

rice::pastry::routing::Router* rice::pastry::PastryNode::getRouter()
{
    return router;
}

java::lang::String* rice::pastry::PastryNode::printRouteState()
{
    auto ret = ::java::lang::StringBuilder().append(npc(leafSet)->toString())->append(u"\n"_j)->toString();
    ret = ::java::lang::StringBuilder(ret).append(npc(routeSet)->toString())->toString();
    return ret;
}

void rice::pastry::PastryNode::setSocketElements(int32_t lsmf, int32_t rsmf, ::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proxProvider, NodeHandleFactory* handleFactory)
{
    this->localhandle = localhandle;
    this->leafSetMaintFreq = lsmf;
    this->routeSetMaintFreq = rsmf;
    this->handleFactory = handleFactory;
    this->proxProvider = proxProvider;
    npc(proxProvider)->addProximityListener(this);
    this->tl = tl;
    this->livenessProvider = livenessProvider;
    npc(tl)->setCallback(this);
    npc(livenessProvider)->addLivenessListener(this);
}

java::util::Map* rice::pastry::PastryNode::getVars()
{
    return vars;
}

void rice::pastry::PastryNode::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    auto const appIdBuffer = ::java::nio::ByteBuffer::allocate(4);
    npc(s)->register_(true, false, new PastryNode_incomingSocket_4(this, appIdBuffer));
}

void rice::pastry::PastryNode::acceptAppSocket(int32_t appId) /* throws(AppSocketException) */
{
    auto acceptorAppl = npc(getMessageDispatch())->getDestinationByAddress(appId);
    if(acceptorAppl == nullptr)
        throw new ::rice::p2p::commonapi::exception::AppNotRegisteredException(appId);

    if(!npc(acceptorAppl)->canReceiveSocket())
        throw new ::rice::p2p::commonapi::exception::NoReceiverAvailableException();

}

int32_t rice::pastry::PastryNode::proximity(NodeHandle* nh)
{
    return proximity(nh, static_cast< ::java::util::Map* >(nullptr));
}

int32_t rice::pastry::PastryNode::proximity(NodeHandle* nh, ::java::util::Map* options)
{
    return npc(proxProvider)->proximity(nh, options);
}

int32_t rice::pastry::PastryNode::proximity(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return proximity(dynamic_cast< NodeHandle* >(i), options);
}

rice::pastry::ScheduledMessage* rice::pastry::PastryNode::scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay)
{
    auto sm = new ScheduledMessage(this, msg);
    npc(npc(npc(getEnvironment())->getSelectorManager())->getTimer())->schedule(sm, delay);
    return sm;
}

rice::pastry::ScheduledMessage* rice::pastry::PastryNode::scheduleMsg(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period)
{
    auto sm = new ScheduledMessage(this, msg);
    npc(npc(npc(getEnvironment())->getSelectorManager())->getTimer())->schedule(sm, delay, period);
    return sm;
}

rice::pastry::ScheduledMessage* rice::pastry::PastryNode::scheduleMsgAtFixedRate(::rice::pastry::messaging::Message* msg, int64_t delay, int64_t period)
{
    auto sm = new ScheduledMessage(this, msg);
    npc(npc(npc(getEnvironment())->getSelectorManager())->getTimer())->scheduleAtFixedRate(sm, delay, period);
    return sm;
}

rice::pastry::transport::PMessageReceipt* rice::pastry::PastryNode::send(NodeHandle* handle, ::rice::pastry::messaging::Message* msg, ::rice::pastry::transport::PMessageNotification* deliverAckToMe, ::java::util::Map* tempOptions)
{
    if(tempOptions != nullptr && npc(tempOptions)->containsKey(::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY())) {
    } else {
        if(tempOptions == nullptr) {
            tempOptions = new ::java::util::HashMap();
        } else {
            tempOptions = new ::java::util::HashMap(static_cast< ::java::util::Map* >(tempOptions));
        }
        npc(tempOptions)->put(::org::mpisws::p2p::transport::priority::PriorityTransportLayer::OPTION_PRIORITY(), ::java::lang::Integer::valueOf(npc(msg)->getPriority()));
    }
    auto const options = tempOptions;
    if(npc(handle)->equals(static_cast< ::java::lang::Object* >(localhandle))) {
        receiveMessage(msg);
        ::rice::pastry::transport::PMessageReceipt* ret = new PastryNode_send_5(this, options, msg);
        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sent(ret);

        return ret;
    }
    ::rice::pastry::messaging::PRawMessage* rm;
    if(dynamic_cast< ::rice::pastry::messaging::PRawMessage* >(msg) != nullptr) {
        rm = java_cast< ::rice::pastry::messaging::PRawMessage* >(msg);
    } else {
        rm = new ::rice::pastry::messaging::PJavaSerializedMessage(msg);
    }
    auto const ret = new ::rice::pastry::transport::PMessageReceiptImpl(msg, options);
    ::org::mpisws::p2p::transport::MessageCallback* callback;
    if(deliverAckToMe == nullptr) {
        callback = nullptr;
    } else {
        callback = new PastryNode_send_6(this, ret, deliverAckToMe);
    }
    if(npc(npc(getEnvironment())->getSelectorManager())->isSelectorThread()) {
        npc(ret)->setInternal(npc(tl)->sendMessage(handle, rm, callback, options));
    } else {
        npc(npc(getEnvironment())->getSelectorManager())->invoke(new PastryNode_send_7(this, ret, handle, rm, callback, options));
    }
    return ret;
}

void rice::pastry::PastryNode::messageReceived(NodeHandle* i, ::rice::p2p::commonapi::rawserialization::RawMessage* m, ::java::util::Map* options) /* throws(IOException) */
{
    if(npc(m)->getType() == 0 && (dynamic_cast< ::rice::pastry::messaging::PJavaSerializedMessage* >(m) != nullptr)) {
        receiveMessage(npc((java_cast< ::rice::pastry::messaging::PJavaSerializedMessage* >(m)))->getMessage());
    } else {
        receiveMessage(java_cast< ::rice::pastry::messaging::Message* >(m));
    }
}

void rice::pastry::PastryNode::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< NodeHandle* >(i), dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawMessage* >(m), options);
}

rice::pastry::NodeHandle* rice::pastry::PastryNode::readNodeHandle(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return java_cast< NodeHandle* >(npc(handleFactory)->readNodeHandle(buf));
}

rice::pastry::boot::Bootstrapper* rice::pastry::PastryNode::getBootstrapper()
{
    return bootstrapper;
}

void rice::pastry::PastryNode::doneNode(::java::util::Collection* bootstrap)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"doneNode:"_j)->append(static_cast< ::java::lang::Object* >(bootstrap))->toString());

    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"doneNode:"_j)->append(static_cast< ::java::lang::Object* >(bootstrap))->toString());

    if(routeSetMaintFreq > 0) {
        routeSetRoutineMaintenance = scheduleMsgAtFixedRate(new ::rice::pastry::routing::InitiateRouteSetMaintenance(), routeSetMaintFreq * int32_t(1000), routeSetMaintFreq * int32_t(1000));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
            npc(logger)->log(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(u"Scheduling routeSetMaint for "_j)->append(routeSetMaintFreq * int32_t(1000))->toString())->append(u","_j)->toString())->append(routeSetMaintFreq * int32_t(1000))->toString());

    }
    if(leafSetMaintFreq > 0) {
        leafSetRoutineMaintenance = scheduleMsgAtFixedRate(new ::rice::pastry::leafset::InitiateLeafSetMaintenance(), leafSetMaintFreq * int32_t(1000), leafSetMaintFreq * int32_t(1000));
        if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
            npc(logger)->log(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(u"Scheduling leafSetMaint for "_j)->append(leafSetMaintFreq * int32_t(1000))->toString())->append(u","_j)->toString())->append(leafSetMaintFreq * int32_t(1000))->toString());

    }
    npc(joiner)->initiateJoin(bootstrap);
}

void rice::pastry::PastryNode::livenessChanged(NodeHandle* i, int32_t val, ::java::util::Map* options)
{
    if(val == LIVENESS_ALIVE) {
        npc(i)->update(NodeHandle::DECLARED_LIVE());
    } else {
        if(val >= LIVENESS_DEAD) {
            npc(i)->update(NodeHandle::DECLARED_DEAD());
        }
    }
    notifyLivenessListeners(java_cast< NodeHandle* >(i), val, options);
}

void rice::pastry::PastryNode::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{ 
    livenessChanged(dynamic_cast< NodeHandle* >(i), val, options);
}

void rice::pastry::PastryNode::addLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_2(livenessListeners);
        {
            npc(livenessListeners)->add(name);
        }
    }
}

bool rice::pastry::PastryNode::removeLivenessListener(::org::mpisws::p2p::transport::liveness::LivenessListener* name)
{
    {
        synchronized synchronized_3(livenessListeners);
        {
            return npc(livenessListeners)->remove(name);
        }
    }
}

void rice::pastry::PastryNode::notifyLivenessListeners(NodeHandle* i, int32_t val, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyLivenessListeners("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(val)
            ->append(u")"_j)->toString());

    ::java::util::ArrayList* temp;
    {
        synchronized synchronized_4(livenessListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(livenessListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::liveness::LivenessListener* ll = java_cast< ::org::mpisws::p2p::transport::liveness::LivenessListener* >(_i->next());
        {
            npc(ll)->livenessChanged(i, val, options);
        }
    }
}

bool rice::pastry::PastryNode::checkLiveness(NodeHandle* i, ::java::util::Map* options)
{
    return npc(livenessProvider)->checkLiveness(i, options);
}

bool rice::pastry::PastryNode::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return checkLiveness(dynamic_cast< NodeHandle* >(i), options);
}

int32_t rice::pastry::PastryNode::getLiveness(NodeHandle* i, ::java::util::Map* options)
{
    return npc(livenessProvider)->getLiveness(i, options);
}

int32_t rice::pastry::PastryNode::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{ 
    return getLiveness(dynamic_cast< NodeHandle* >(i), options);
}

int32_t rice::pastry::PastryNode::getLiveness(NodeHandle* i)
{
    return npc(livenessProvider)->getLiveness(i, nullptr);
}

bool rice::pastry::PastryNode::isAlive(NodeHandle* i)
{
    return (npc(livenessProvider)->getLiveness(i, nullptr) < LIVENESS_DEAD);
}

void rice::pastry::PastryNode::proximityChanged(NodeHandle* handle, int32_t val, ::java::util::Map* options)
{
    npc(handle)->update(NodeHandle::PROXIMITY_CHANGED());
}

void rice::pastry::PastryNode::proximityChanged(::java::lang::Object* i, int32_t newProximity, ::java::util::Map* options)
{ 
    proximityChanged(dynamic_cast< NodeHandle* >(i), newProximity, options);
}

org::mpisws::p2p::transport::liveness::LivenessProvider* rice::pastry::PastryNode::getLivenessProvider()
{
    return livenessProvider;
}

org::mpisws::p2p::transport::proximity::ProximityProvider* rice::pastry::PastryNode::getProxProvider()
{
    return proxProvider;
}

org::mpisws::p2p::transport::TransportLayer* rice::pastry::PastryNode::getTL()
{
    return tl;
}

void rice::pastry::PastryNode::clearState(NodeHandle* i)
{
    npc(livenessProvider)->clearState(i);
}

void rice::pastry::PastryNode::clearState(::java::lang::Object* i)
{ 
    clearState(dynamic_cast< NodeHandle* >(i));
}

void rice::pastry::PastryNode::addProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    npc(proxProvider)->addProximityListener(listener);
}

bool rice::pastry::PastryNode::removeProximityListener(::org::mpisws::p2p::transport::proximity::ProximityListener* listener)
{
    return npc(proxProvider)->removeProximityListener(listener);
}

void rice::pastry::PastryNode::nodeIsReady()
{
}

rice::pastry::NodeHandleFactory* rice::pastry::PastryNode::getHandleFactroy()
{
    return handleFactory;
}

void rice::pastry::PastryNode::addNetworkListener(NetworkListener* listener)
{
    {
        synchronized synchronized_5(networkListeners);
        {
            npc(networkListeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void rice::pastry::PastryNode::removeNetworkListener(NetworkListener* listener)
{
    {
        synchronized synchronized_6(networkListeners);
        {
            npc(networkListeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

java::lang::Iterable* rice::pastry::PastryNode::getNetworkListeners()
{
    {
        synchronized synchronized_7(networkListeners);
        {
            return new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(networkListeners));
        }
    }
}

void rice::pastry::PastryNode::broadcastChannelClosed(::java::net::InetSocketAddress* addr)
{
    for (auto _i = npc(getNetworkListeners())->iterator(); _i->hasNext(); ) {
        NetworkListener* listener = java_cast< NetworkListener* >(_i->next());
        
                        npc(listener)->channelClosed(addr);

    }
}

void rice::pastry::PastryNode::broadcastChannelOpened(::java::net::InetSocketAddress* addr, int32_t reason)
{
    for (auto _i = npc(getNetworkListeners())->iterator(); _i->hasNext(); ) {
        NetworkListener* listener = java_cast< NetworkListener* >(_i->next());
        
                        npc(listener)->channelOpened(addr, reason);

    }
}

void rice::pastry::PastryNode::broadcastSentListeners(int32_t address, int16_t msgType, ::java::net::InetSocketAddress* dest, int32_t size, int32_t wireType)
{
    for (auto _i = npc(getNetworkListeners())->iterator(); _i->hasNext(); ) {
        NetworkListener* listener = java_cast< NetworkListener* >(_i->next());
        
                        npc(listener)->dataSent(address, msgType, dest, size, wireType);

    }
}

void rice::pastry::PastryNode::broadcastReceivedListeners(int32_t address, int16_t msgType, ::java::net::InetSocketAddress* from, int32_t size, int32_t wireType)
{
    for (auto _i = npc(getNetworkListeners())->iterator(); _i->hasNext(); ) {
        NetworkListener* listener = java_cast< NetworkListener* >(_i->next());
        
                        npc(listener)->dataReceived(address, msgType, from, size, wireType);

    }
}

void rice::pastry::PastryNode::addNodeHandleFactoryListener(NodeHandleFactoryListener* listener)
{
    npc(handleFactory)->addNodeHandleFactoryListener(listener);
}

void rice::pastry::PastryNode::removeNodeHandleFactoryListener(NodeHandleFactoryListener* listener)
{
    npc(handleFactory)->removeNodeHandleFactoryListener(listener);
}

void rice::pastry::PastryNode::setNodeHandleFetcher(NodeHandleFetcher* nodeHandleFetcher)
{
    this->nodeHandleFetcher = nodeHandleFetcher;
}

void rice::pastry::PastryNode::getNodeHandle(::java::lang::Object* o, ::rice::Continuation* c)
{
    npc(nodeHandleFetcher)->getNodeHandle(o, c);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::pastry::PastryNode::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.pastry.PastryNode", 22);
    return c;
}

java::lang::Class* rice::pastry::PastryNode::getClass0()
{
    return class_();
}

