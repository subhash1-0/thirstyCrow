// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.java
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/ref/WeakReference.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/List.hpp>
#include <java/util/Map.hpp>
#include <java/util/Random.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_sendMessage_2.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_ping_3.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_pong_4.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_DeadChecker.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_EntityManager.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessTransportLayerImpl_LSocket.hpp>
#include <org/mpisws/p2p/transport/liveness/PingListener.hpp>
#include <org/mpisws/p2p/transport/liveness/PingMessage.hpp>
#include <org/mpisws/p2p/transport/liveness/PongMessage.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/Parameters.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/util/TimerWeakHashMap.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
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
org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::LivenessTransportLayerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::LivenessTransportLayerImpl(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle) 
    : LivenessTransportLayerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,env,errorHandler,checkDeadThrottle);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::init()
{
    connectionExceptionMeansFaulty_ = true;
    destroyed = false;
}

constexpr int8_t org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::HDR_NORMAL;

constexpr int8_t org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::HDR_PING;

constexpr int8_t org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::HDR_PONG;

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::ErrorHandler* errorHandler, int32_t checkDeadThrottle)
{
    super::ctor();
    init();
    this->tl = tl;
    this->environment = env;
    this->logger = npc(npc(env)->getLogManager())->getLogger(LivenessTransportLayerImpl::class_(), nullptr);
    this->time = npc(env)->getTimeSource();
    this->timer = npc(npc(env)->getSelectorManager())->getTimer();
    random = new ::java::util::Random();
    this->livenessListeners = new ::java::util::ArrayList();
    this->pingListeners = new ::java::util::ArrayList();
    this->managers = new ::rice::p2p::util::TimerWeakHashMap(npc(env)->getSelectorManager(), int32_t(300000));
    auto p = npc(env)->getParameters();
    PING_DELAY = npc(p)->getInt(u"pastry_socket_scm_ping_delay"_j);
    PING_JITTER = npc(p)->getFloat(u"pastry_socket_scm_ping_jitter"_j);
    NUM_PING_TRIES = npc(p)->getInt(u"pastry_socket_scm_num_ping_tries"_j);
    BACKOFF_INITIAL = npc(p)->getInt(u"pastry_socket_scm_backoff_initial"_j);
    BACKOFF_LIMIT = npc(p)->getInt(u"pastry_socket_scm_backoff_limit"_j);
    CHECK_DEAD_THROTTLE = checkDeadThrottle;
    DEFAULT_RTO = npc(p)->getInt(u"pastry_socket_srm_default_rto"_j);
    RTO_UBOUND = npc(p)->getInt(u"pastry_socket_srm_rto_ubound"_j);
    RTO_LBOUND = npc(p)->getInt(u"pastry_socket_srm_rto_lbound"_j);
    gainH = npc(p)->getDouble(u"pastry_socket_srm_gain_h"_j);
    gainG = npc(p)->getDouble(u"pastry_socket_srm_gain_g"_j);
    npc(tl)->setCallback(this);
    this->errorHandler = errorHandler;
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::clearState(::java::lang::Object* i)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"clearState("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    deleteManager(i);
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::checkLiveness(::java::lang::Object* i, ::java::util::Map* options)
{
    return npc(getManager(i))->checkLiveness(options);
}

org::mpisws::p2p::transport::P2PSocket* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::getLSocket(::org::mpisws::p2p::transport::P2PSocket* s, LivenessTransportLayerImpl_EntityManager* manager)
{
    auto sock = new LivenessTransportLayerImpl_LSocket(this, manager, s, java_cast< ::java::lang::Object* >(npc(npc(manager)->identifier)->get()));
    {
        synchronized synchronized_0(npc(manager)->sockets);
        {
            npc(npc(manager)->sockets)->add(static_cast< ::java::lang::Object* >(sock));
        }
    }
    return sock;
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::getManager(::java::lang::Object* i)
{
    {
        synchronized synchronized_1(managers);
        {
            auto manager = java_cast< LivenessTransportLayerImpl_EntityManager* >(npc(managers)->get(i));
            if(manager == nullptr) {
                manager = new LivenessTransportLayerImpl_EntityManager(this, i);
                npc(managers)->put(i, manager);
            }
            return manager;
        }
    }
}

org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl_EntityManager* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::deleteManager(::java::lang::Object* i)
{
    {
        synchronized synchronized_2(managers);
        {
            auto manager = java_cast< LivenessTransportLayerImpl_EntityManager* >(npc(managers)->remove(i));
            if(manager != nullptr) {
                if(npc(manager)->getPending() != nullptr)
                    npc(npc(manager)->getPending())->cancel();

            }
            return manager;
        }
    }
}

int32_t org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::getLiveness(::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"getLiveness("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    {
        synchronized synchronized_3(managers);
        {
            if(npc(managers)->containsKey(i))
                return npc(java_cast< LivenessTransportLayerImpl_EntityManager* >(npc(managers)->get(i)))->liveness;

        }
    }
    return LIVENESS_SUSPECTED;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::connectionExceptionMeansFaulty(bool b)
{
    connectionExceptionMeansFaulty_ = b;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO - int32_t(50))
        npc(logger)->log(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(deliverSocketToMe))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(options))
            ->append(u")"_j)->toString());

    return npc(tl)->openSocket(i, new LivenessTransportLayerImpl_openSocket_1(this, deliverSocketToMe, i, options), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto const handle = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    auto mgr = getManager(i);
    if((mgr != nullptr) && (npc(mgr)->liveness >= LIVENESS_DEAD)) {
        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sendFailed(handle, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i, m));

        return handle;
    }
    auto msgBytes = new ::int8_tArray(npc(m)->remaining() + int32_t(1));
    (*msgBytes)[int32_t(0)] = HDR_NORMAL;
    npc(m)->get(msgBytes, 1, npc(m)->remaining());
    auto const myMsg = ::java::nio::ByteBuffer::wrap(msgBytes);
    npc(handle)->setSubCancellable(npc(tl)->sendMessage(i, myMsg, new LivenessTransportLayerImpl_sendMessage_2(this, handle, deliverAckToMe, i), options));
    return handle;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    auto hdr = npc(m)->get();
    {
        LivenessTransportLayerImpl_EntityManager* manager;
        int64_t sendTime;
        int32_t rtt;
        switch (hdr) {
        case HDR_NORMAL:
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(m))
                    ->append(u")"_j)->toString());

            npc(callback)->messageReceived(i, m, options);
            return;
        case HDR_PING:
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u", PING)"_j)->toString());

            pong(i, npc(m)->getLong(), options);
            notifyPingListenersPing(i);
            return;
        case HDR_PONG:
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                npc(logger)->log(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u", PONG)"_j)->toString());

            manager = getManager(i);
            sendTime = npc(m)->getLong();
            rtt = static_cast< int32_t >((npc(time)->currentTimeMillis() - sendTime));
            if(rtt >= 0) {
                npc(manager)->updateRTO(rtt);
                auto markAlive = false;
                {
                    synchronized synchronized_4(manager);
                    {
                        if(npc(manager)->getPending() != nullptr) {
                            npc(npc(manager)->getPending())->pingResponse(sendTime, options);
                            markAlive = true;
                        }
                    }
                }
                npc(manager)->markAlive(options);
                notifyPingListenersPong(i, rtt, options);
            } else {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"I think the clock is fishy, rtt must be >= 0, was:"_j)->append(rtt)->toString());

                npc(errorHandler)->receivedUnexpectedData(i, npc(m)->array(), 0, nullptr);
            }
            return;
        default:
            npc(errorHandler)->receivedUnexpectedData(i, npc(m)->array(), 0, nullptr);
        }
    }

}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::cancelLivenessCheck(::java::lang::Object* i, ::java::util::Map* options)
{
    auto manager = getManager(i);
    if(manager == nullptr) {
        return false;
    }
    return cancelLivenessCheck(manager, options);
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::cancelLivenessCheck(LivenessTransportLayerImpl_EntityManager* manager, ::java::util::Map* options)
{
    {
        synchronized synchronized_5(manager);
        {
            if(npc(manager)->getPending() != nullptr) {
                npc(npc(manager)->getPending())->cancel();
                return true;
            }
        }
    }
    npc(manager)->markAlive(options);
    return false;
}

java::lang::String* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::toString()
{
    return ::java::lang::StringBuilder().append(u"LivenessTL{"_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(getLocalIdentifier())))
        ->append(u"}"_j)->toString();
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::ping(::java::lang::Object* i, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"ping("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u")"_j)->toString());

    if(npc(i)->equals(java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier())))
        return false;

    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(int32_t(1024));
        npc(sob)->writeByte(HDR_PING);
        auto const now = npc(time)->currentTimeMillis();
        (new PingMessage(now))->serialize(sob);
        npc(tl)->sendMessage(i, ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes()), new LivenessTransportLayerImpl_ping_3(this, i, now, options), options);
        return true;
    } catch (::java::io::IOException* ioe) {
        npc(errorHandler)->receivedException(i, ioe);
    }
    return false;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::pong(::java::lang::Object* i, int64_t senderTime, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
        npc(logger)->log(::java::lang::StringBuilder().append(u"pong("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(senderTime)
            ->append(u")"_j)->toString());

    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer(int32_t(1024));
        npc(sob)->writeByte(HDR_PONG);
        (new PongMessage(senderTime))->serialize(sob);
        npc(tl)->sendMessage(i, ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes()), new LivenessTransportLayerImpl_pong_4(this, i, senderTime, options), options);
    } catch (::java::io::IOException* ioe) {
        npc(errorHandler)->receivedException(i, ioe);
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    errorHandler = handler;
    this->errorHandler = errorHandler;
    if(java_cast< ::org::mpisws::p2p::transport::ErrorHandler* >(this->errorHandler) == nullptr) {
        this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::destroy()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::INFO)
        npc(logger)->log(u"destroy()"_j);

    destroyed = true;
    npc(tl)->destroy();
    npc(livenessListeners)->clear();
    livenessListeners = nullptr;
    npc(pingListeners)->clear();
    pingListeners = nullptr;
    for (auto _i = npc(npc(managers)->values())->iterator(); _i->hasNext(); ) {
        LivenessTransportLayerImpl_EntityManager* em = java_cast< LivenessTransportLayerImpl_EntityManager* >(_i->next());
        {
            npc(em)->destroy();
        }
    }
    npc(managers)->clear();
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    auto m = getManager(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()));
    if(npc(m)->liveness > LIVENESS_SUSPECTED) {
        npc(m)->updated = 0LL;
        npc(m)->checkLiveness(npc(s)->getOptions());
    }
    npc(callback)->incomingSocket(getLSocket(s, getManager(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()))));
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::addLivenessListener(LivenessListener* name)
{
    if(destroyed)
        return;

    {
        synchronized synchronized_6(livenessListeners);
        {
            npc(livenessListeners)->add(static_cast< ::java::lang::Object* >(name));
        }
    }
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::removeLivenessListener(LivenessListener* name)
{
    if(destroyed)
        return true;

    {
        synchronized synchronized_7(livenessListeners);
        {
            return npc(livenessListeners)->remove(static_cast< ::java::lang::Object* >(name));
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::notifyLivenessListeners(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options)
{
    if(destroyed)
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"notifyLivenessListeners("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(liveness)
            ->append(u")"_j)->toString());

    ::java::util::List* temp;
    {
        synchronized synchronized_8(livenessListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(livenessListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        LivenessListener* listener = java_cast< LivenessListener* >(_i->next());
        {
            npc(listener)->livenessChanged(i, liveness, options);
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::addPingListener(PingListener* name)
{
    {
        synchronized synchronized_9(pingListeners);
        {
            npc(pingListeners)->add(static_cast< ::java::lang::Object* >(name));
        }
    }
}

bool org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::removePingListener(PingListener* name)
{
    {
        synchronized synchronized_10(pingListeners);
        {
            return npc(pingListeners)->remove(static_cast< ::java::lang::Object* >(name));
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::notifyPingListenersPing(::java::lang::Object* i)
{
    ::java::util::List* temp;
    {
        synchronized synchronized_11(pingListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(pingListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        PingListener* listener = java_cast< PingListener* >(_i->next());
        {
            npc(listener)->pingReceived(i, nullptr);
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::notifyPingListenersPong(::java::lang::Object* i, int32_t rtt, ::java::util::Map* options)
{
    ::java::util::List* temp;
    {
        synchronized synchronized_12(pingListeners);
        {
            temp = new ::java::util::ArrayList(static_cast< ::java::util::Collection* >(pingListeners));
        }
    }
    for (auto _i = npc(temp)->iterator(); _i->hasNext(); ) {
        PingListener* listener = java_cast< PingListener* >(_i->next());
        {
            npc(listener)->pingResponse(i, rtt, options);
        }
    }
}

void org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::setLiveness(::java::lang::Object* i, int32_t liveness, ::java::util::Map* options)
{
    auto man = getManager(i);
    switch (liveness) {
    case LIVENESS_ALIVE:
        npc(man)->markAlive(options);
        return;
    case LIVENESS_SUSPECTED:
        npc(man)->markSuspected(options);
        return;
    case LIVENESS_DEAD:
        npc(man)->markDead(options);
        return;
    case LIVENESS_DEAD_FOREVER:
        npc(man)->markDeadForever(options);
        return;
    }

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.liveness.LivenessTransportLayerImpl", 60);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::liveness::LivenessTransportLayerImpl::getClass0()
{
    return class_();
}

