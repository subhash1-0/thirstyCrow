// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/direct/DirectTransportLayer.java
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/net/SocketTimeoutException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/direct/ConnectorExceptionDelivery.hpp>
#include <org/mpisws/p2p/transport/direct/DirectAppSocket.hpp>
#include <org/mpisws/p2p/transport/direct/DirectTransportLayer_CancelAndClose.hpp>
#include <org/mpisws/p2p/transport/direct/GenericNetworkSimulator.hpp>
#include <org/mpisws/p2p/transport/exception/NodeIsFaultyException.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessListener.hpp>
#include <org/mpisws/p2p/transport/liveness/LivenessProvider.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/CancellableTask.hpp>
#include <rice/pastry/direct/NetworkSimulator.hpp>

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

org::mpisws::p2p::transport::direct::DirectTransportLayer::DirectTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::direct::DirectTransportLayer::DirectTransportLayer(::java::lang::Object* local, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::direct::NodeRecord* nr, ::rice::environment::Environment* env) 
    : DirectTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(local,simulator,nr,env);
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::init()
{
    acceptMessages_ = true;
    acceptSockets_ = true;
    seq = ::java::lang::Integer::MIN_VALUE;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::ctor(::java::lang::Object* local, ::rice::pastry::direct::NetworkSimulator* simulator, ::rice::pastry::direct::NodeRecord* nr, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->localIdentifier = local;
    this->simulator = npc(simulator)->getGenericSimulator();
    this->livenessProvider = npc(simulator)->getLivenessProvider();
    this->environment = env;
    this->logger = npc(npc(environment)->getLogManager())->getLogger(DirectTransportLayer::class_(), nullptr);
    npc(simulator)->registerNode(local, this, nr);
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::acceptMessages(bool b)
{
    acceptMessages_ = b;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::acceptSockets(bool b)
{
    acceptSockets_ = b;
}

java::lang::Object* org::mpisws::p2p::transport::direct::DirectTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(localIdentifier);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::direct::DirectTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto handle = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    if(npc(simulator)->isAlive(i)) {
        auto delay = static_cast< int32_t >(::java::lang::Math::round(npc(simulator)->networkDelay(java_cast< ::java::lang::Object* >(localIdentifier), i)));
        auto socket = new DirectAppSocket(i, java_cast< ::java::lang::Object* >(localIdentifier), deliverSocketToMe, simulator, handle, options);
        auto cancelAndClose = new DirectTransportLayer_CancelAndClose(socket, npc(simulator)->enqueueDelivery(npc(socket)->getAcceptorDelivery(), delay));
        npc(handle)->setSubCancellable(cancelAndClose);
    } else {
        auto delay = int32_t(5000);
        npc(handle)->setSubCancellable(npc(simulator)->enqueueDelivery(new ConnectorExceptionDelivery(deliverSocketToMe, handle, new ::java::net::SocketTimeoutException()), delay));
    }
    return handle;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::direct::DirectTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(!npc(simulator)->isAlive(java_cast< ::java::lang::Object* >(localIdentifier)))
        return nullptr;

    auto handle = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    if(npc(livenessProvider)->getLiveness(i, nullptr) >= ::org::mpisws::p2p::transport::liveness::LivenessListener::LIVENESS_DEAD) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Attempt to send message "_j)->append(static_cast< ::java::lang::Object* >(m))
                ->append(u" to a dead node "_j)
                ->append(static_cast< ::java::lang::Object* >(i))
                ->append(u"!"_j)->toString());

        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sendFailed(handle, new ::org::mpisws::p2p::transport::exception::NodeIsFaultyException(i));

    } else {
        if(npc(simulator)->isAlive(i)) {
            auto delay = static_cast< int32_t >(::java::lang::Math::round(npc(simulator)->networkDelay(java_cast< ::java::lang::Object* >(localIdentifier), i)));
            npc(handle)->setSubCancellable(npc(simulator)->deliverMessage(m, i, java_cast< ::java::lang::Object* >(localIdentifier), delay));
            if(deliverAckToMe != nullptr)
                npc(deliverAckToMe)->ack(handle);

        } else {
        }
    }
    return handle;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::destroy()
{
    npc(simulator)->remove(java_cast< ::java::lang::Object* >(getLocalIdentifier()));
}

bool org::mpisws::p2p::transport::direct::DirectTransportLayer::canReceiveSocket()
{
    return acceptSockets_;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::finishReceiveSocket(::org::mpisws::p2p::transport::P2PSocket* acceptorEndpoint)
{
    try {
        npc(callback)->incomingSocket(acceptorEndpoint);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Exception in "_j)->append(static_cast< ::java::lang::Object* >(callback))->toString(), ioe);

    }
}

rice::environment::logging::Logger* org::mpisws::p2p::transport::direct::DirectTransportLayer::getLogger()
{
    return logger;
}

int32_t org::mpisws::p2p::transport::direct::DirectTransportLayer::getNextSeq()
{
    return seq++;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::incomingMessage(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

rice::environment::Environment* org::mpisws::p2p::transport::direct::DirectTransportLayer::getEnvironment()
{
    return environment;
}

void org::mpisws::p2p::transport::direct::DirectTransportLayer::clearState(::java::lang::Object* i)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::direct::DirectTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.direct.DirectTransportLayer", 52);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::direct::DirectTransportLayer::getClass0()
{
    return class_();
}

