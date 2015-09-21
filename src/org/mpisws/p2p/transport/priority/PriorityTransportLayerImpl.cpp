// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.java
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/priority/PrimarySocketListener.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_sendMessage_3.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_destroy_4.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_incomingSocket_1.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_openSocket_2.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager_MessageWrapper.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/priority/PriorityTransportLayerListener.hpp>
#include <org/mpisws/p2p/transport/proximity/ProximityProvider.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/util/SortedLinkedList.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/TimerTask.hpp>
#include <Array.hpp>

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
org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PriorityTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PriorityTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proximityProvider, ::rice::environment::Environment* env, int32_t maxMsgSize, int32_t maxQueueSize, ::org::mpisws::p2p::transport::ErrorHandler* handler) 
    : PriorityTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,livenessProvider,proximityProvider,env,maxMsgSize,maxQueueSize,handler);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::init()
{
    MAX_MSG_SIZE = int32_t(10000);
    MAX_QUEUE_SIZE = int32_t(30);
    MAX_BIG_MSG_SIZE = ::java::lang::Integer::MAX_VALUE;
    primarySocketListeners = new ::java::util::ArrayList();
    destroyed = false;
    listeners = new ::java::util::ArrayList();
    plisteners = new ::java::util::ArrayList();
}

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PASSTHROUGH_SOCKET_B;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PRIMARY_SOCKET_B;

constexpr int8_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::BIG_MSG_SOCKET_B;

int8_tArray*& org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PASSTHROUGH_SOCKET()
{
    clinit();
    return PASSTHROUGH_SOCKET_;
}
int8_tArray* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PASSTHROUGH_SOCKET_;

int8_tArray*& org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PRIMARY_SOCKET()
{
    clinit();
    return PRIMARY_SOCKET_;
}
int8_tArray* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::PRIMARY_SOCKET_;

int8_tArray*& org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::BIG_MSG_SOCKET()
{
    clinit();
    return BIG_MSG_SOCKET_;
}
int8_tArray* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::BIG_MSG_SOCKET_;

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::org::mpisws::p2p::transport::liveness::LivenessProvider* livenessProvider, ::org::mpisws::p2p::transport::proximity::ProximityProvider* proximityProvider, ::rice::environment::Environment* env, int32_t maxMsgSize, int32_t maxQueueSize, ::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    super::ctor();
    init();
    entityManagers = new ::java::util::HashMap();
    this->logger = npc(npc(env)->getLogManager())->getLogger(PriorityTransportLayerImpl::class_(), nullptr);
    this->selectorManager = npc(env)->getSelectorManager();
    this->environment = env;
    this->MAX_MSG_SIZE = maxMsgSize;
    this->MAX_QUEUE_SIZE = maxQueueSize;
    this->tl = tl;
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(::java::lang::StringBuilder().append(u"MAX_QUEUE_SIZE:"_j)->append(MAX_QUEUE_SIZE)
            ->append(u" MAX_MSG_SIZE:"_j)
            ->append(MAX_MSG_SIZE)->toString());

    this->livenessProvider = livenessProvider;
    this->proximityProvider = proximityProvider;
    npc(tl)->setCallback(this);
    npc(livenessProvider)->addLivenessListener(this);
    this->errorHandler = handler;
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(s)->register_(true, false, new PriorityTransportLayerImpl_incomingSocket_1(this, s));
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(deliverSocketToMe == nullptr)
        throw new ::java::lang::IllegalArgumentException(u"No handle to return socket to! (deliverSocketToMe must be non-null!)"_j);

    auto const handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(handle)->setSubCancellable(npc(tl)->openSocket(i, new PriorityTransportLayerImpl_openSocket_2(this, handle, deliverSocketToMe), options));
    return handle;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
    notifyListenersRead(npc(m)->remaining(), i, options);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverAckToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    if(options != nullptr && npc(options)->containsKey(::org::mpisws::p2p::transport::wire::WireTransportLayer::OPTION_TRANSPORT_TYPE())) {
        auto val = java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::wire::WireTransportLayer::OPTION_TRANSPORT_TYPE())));
        if(val != nullptr && npc(val)->intValue() == ::org::mpisws::p2p::transport::wire::WireTransportLayer::TRANSPORT_TYPE_DATAGRAM) {
            auto const originalSize = npc(m)->remaining();
            return npc(tl)->sendMessage(i, m, new PriorityTransportLayerImpl_sendMessage_3(this, originalSize, i, options), options);
        }
    }
    return npc(getEntityManager(i))->send(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::destroy()
{
    if(destroyed)
        return;

    if(npc(npc(environment)->getSelectorManager())->isSelectorThread()) {
        destroyed = true;
        npc(tl)->destroy();
    } else {
        npc(npc(environment)->getSelectorManager())->invoke(new PriorityTransportLayerImpl_destroy_4(this));
    }
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::getEntityManager(::java::lang::Object* i)
{
    {
        synchronized synchronized_0(entityManagers);
        {
            auto ret = java_cast< PriorityTransportLayerImpl_EntityManager* >(npc(entityManagers)->get(i));
            if(ret == nullptr) {
                ret = new PriorityTransportLayerImpl_EntityManager(this, i);
                npc(entityManagers)->put(i, ret);
            }
            return ret;
        }
    }
}

org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl_EntityManager* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::deleteEntityManager(::java::lang::Object* i)
{
    {
        synchronized synchronized_1(entityManagers);
        {
            auto ret = java_cast< PriorityTransportLayerImpl_EntityManager* >(npc(entityManagers)->get(i));
            if(ret != nullptr) {
                npc(ret)->clearState();
            }
            return ret;
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::livenessChanged(::java::lang::Object* i, int32_t val, ::java::util::Map* options)
{
    if(val >= ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_DEAD) {
        npc(getEntityManager(i))->markDead();
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::cancelLivenessChecker(::java::lang::Object* i)
{
    npc(getEntityManager(i))->stopLivenessChecker();
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::printMemStats(int32_t logLevel)
{
    if(logLevel <= ::rice::environment::logging::Logger::FINE) {
        {
            synchronized synchronized_2(entityManagers);
            {
                auto queueSum = int32_t(0);
                for (auto _i = npc(npc(entityManagers)->values())->iterator(); _i->hasNext(); ) {
                    PriorityTransportLayerImpl_EntityManager* em = java_cast< PriorityTransportLayerImpl_EntityManager* >(_i->next());
                    {
                        auto queueSize = npc(npc(em)->queue)->size();
                        queueSum += queueSize;
                        if(logLevel <= ::rice::environment::logging::Logger::FINEST || (queueSize > 0 && logLevel <= ::rice::environment::logging::Logger::FINER)) {
                            auto temp = java_cast< ::java::lang::Object* >(npc(npc(em)->identifier)->get());
                            auto s = u""_j;
                            ::java::util::Map* options = nullptr;
                            if(temp != nullptr) {
                                auto peek = npc(em)->peek();
                                if(peek != nullptr) {
                                    options = npc(peek)->options;
                                }
                                s = ::java::lang::StringBuilder().append(u""_j)->append(npc(livenessProvider)->getLiveness(temp, options))->toString();
                            }
                            npc(logger)->log(::java::lang::StringBuilder().append(u"EM{"_j)->append(static_cast< ::java::lang::Object* >(temp))
                                ->append(u","_j)
                                ->append(s)
                                ->append(u","_j)
                                ->append(static_cast< ::java::lang::Object* >(npc(em)->writingSocket))
                                ->append(u","_j)
                                ->append(static_cast< ::java::lang::Object* >(npc(em)->pendingSocket))
                                ->append(u"} queue:"_j)
                                ->append(queueSize)
                                ->append(u" reg:"_j)
                                ->append(npc(em)->registered)
                                ->append(u" lChecker:"_j)
                                ->append(static_cast< ::java::lang::Object* >(npc(em)->livenessChecker))->toString());
                        }
                    }
                }
                npc(logger)->log(::java::lang::StringBuilder().append(u"NumEMs:"_j)->append(npc(entityManagers)->size())
                    ->append(u" numPendingMsgs:"_j)
                    ->append(queueSum)->toString());
            }
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::addTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener)
{
    {
        synchronized synchronized_3(listeners);
        {
            npc(listeners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::removeTransportLayerListener(::org::mpisws::p2p::transport::TransportLayerListener* listener)
{
    {
        synchronized synchronized_4(listeners);
        {
            npc(listeners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::addPriorityTransportLayerListener(PriorityTransportLayerListener* listener)
{
    {
        synchronized synchronized_5(plisteners);
        {
            npc(plisteners)->add(static_cast< ::java::lang::Object* >(listener));
        }
    }
    addTransportLayerListener(static_cast< ::org::mpisws::p2p::transport::TransportLayerListener* >(listener));
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::removePriorityTransportLayerListener(PriorityTransportLayerListener* listener)
{
    {
        synchronized synchronized_6(plisteners);
        {
            npc(plisteners)->remove(static_cast< ::java::lang::Object* >(listener));
        }
    }
    removeTransportLayerListener(static_cast< ::org::mpisws::p2p::transport::TransportLayerListener* >(listener));
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::notifyListenersRead(int32_t size, ::java::lang::Object* source, ::java::util::Map* options)
{
    if(npc(listeners)->isEmpty())
        return;

    ::java::util::ArrayList* temp;
    {
        synchronized synchronized_7(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::TransportLayerListener* l = java_cast< ::org::mpisws::p2p::transport::TransportLayerListener* >(_i->next());
        {
            npc(l)->read(size, source, options, true, true);
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::notifyListenersWrote(int32_t size, ::java::lang::Object* dest, ::java::util::Map* options)
{
    if(npc(listeners)->isEmpty())
        return;

    ::java::util::ArrayList* temp;
    {
        synchronized synchronized_8(listeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(listeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        ::org::mpisws::p2p::transport::TransportLayerListener* l = java_cast< ::org::mpisws::p2p::transport::TransportLayerListener* >(_i->next());
        {
            npc(l)->wrote(size, dest, options, true, true);
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::notifyListenersEnqueued(int32_t size, ::java::lang::Object* dest, ::java::util::Map* options)
{
    if(npc(plisteners)->isEmpty())
        return;

    ::java::util::ArrayList* temp;
    {
        synchronized synchronized_9(plisteners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(plisteners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        PriorityTransportLayerListener* l = java_cast< PriorityTransportLayerListener* >(_i->next());
        {
            npc(l)->enqueued(size, dest, options, true, true);
        }
    }
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::notifyListenersDropped(int32_t size, ::java::lang::Object* dest, ::java::util::Map* options)
{
    if(npc(plisteners)->isEmpty())
        return;

    ::java::util::ArrayList* temp;
    {
        synchronized synchronized_10(plisteners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(plisteners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        PriorityTransportLayerListener* l = java_cast< PriorityTransportLayerListener* >(_i->next());
        {
            npc(l)->dropped(size, dest, options, true, true);
        }
    }
}

int64_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::bytesPending(::java::lang::Object* i)
{
    return npc(getEntityManager(i))->bytesPending();
}

int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::queueLength(::java::lang::Object* i)
{
    return npc(getEntityManager(i))->queueLength();
}

java::util::List* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::getPendingMessages(::java::lang::Object* i)
{
    return npc(getEntityManager(i))->getPendingMessages();
}

java::util::Collection* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::nodesWithPendingMessages()
{
    auto ret = new ::java::util::ArrayList();
    {
        synchronized synchronized_11(entityManagers);
        {
            for (auto _i = npc(npc(entityManagers)->values())->iterator(); _i->hasNext(); ) {
                PriorityTransportLayerImpl_EntityManager* m = java_cast< PriorityTransportLayerImpl_EntityManager* >(_i->next());
                {
                    if(npc(m)->peek() != nullptr) {
                        npc(ret)->add(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(npc(m)->identifier)->get())));
                    }
                }
            }
        }
    }
    return ret;
}

java::util::Map* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::connectionOptions(::java::lang::Object* i)
{
    auto manager = getEntityManager(i);
    auto temp = npc(manager)->writingSocket;
    if(temp != nullptr) {
        return npc(temp)->getOptions();
    }
    auto temp2 = npc(manager)->pendingSocket;
    if(temp2 != nullptr)
        return npc(temp2)->getOptions();

    return nullptr;
}

int32_t org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::connectionStatus(::java::lang::Object* i)
{
    auto manager = getEntityManager(i);
    if(npc(manager)->writingSocket != nullptr)
        return STATUS_CONNECTED;

    if(npc(manager)->pendingSocket != nullptr)
        return STATUS_CONNECTING;

    return STATUS_NOT_CONNECTED;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::openPrimaryConnection(::java::lang::Object* i, ::java::util::Map* options)
{
    npc(getEntityManager(i))->openPrimarySocketHelper(i, options);
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::addPrimarySocketListener(PrimarySocketListener* listener)
{
    npc(primarySocketListeners)->add(static_cast< ::java::lang::Object* >(listener));
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::removePrimarySocketListener(PrimarySocketListener* listener)
{
    npc(primarySocketListeners)->remove(static_cast< ::java::lang::Object* >(listener));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.priority.PriorityTransportLayerImpl", 60);
    return c;
}

void org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        PASSTHROUGH_SOCKET_ = (new ::int8_tArray({PASSTHROUGH_SOCKET_B}));
        PRIMARY_SOCKET_ = (new ::int8_tArray({PRIMARY_SOCKET_B}));
        BIG_MSG_SOCKET_ = (new ::int8_tArray({BIG_MSG_SOCKET_B}));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::transport::priority::PriorityTransportLayerImpl::getClass0()
{
    return class_();
}

