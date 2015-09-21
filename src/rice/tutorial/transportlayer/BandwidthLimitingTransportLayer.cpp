// Generated from /pastry-2.1/src/rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.java
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer.hpp>

#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/pastry/PastryNodeFactory.hpp>
#include <rice/selector/SelectorManager.hpp>
#include <rice/selector/Timer.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleA_4.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_exampleB_5.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_sendMessage_2.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_openSocket_3.hpp>
#include <rice/tutorial/transportlayer/BandwidthLimitingTransportLayer_BandwidthLimitingSocket.hpp>
#include <rice/tutorial/transportlayer/NotEnoughBandwidthException.hpp>

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
rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::BandwidthLimitingTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::BandwidthLimitingTransportLayer(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t bucketSize, int32_t bucketTimelimit, ::rice::environment::Environment* env) 
    : BandwidthLimitingTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,bucketSize,bucketTimelimit,env);
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::init()
{
    sockets = new ::java::util::ArrayList();
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, int32_t bucketSize, int32_t bucketTimelimit, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->environment = env;
    this->tl = tl;
    BUCKET_SIZE = bucketSize;
    BUCKET_TIME_LIMIT = bucketTimelimit;
    logger = npc(npc(env)->getLogManager())->getLogger(BandwidthLimitingTransportLayer::class_(), nullptr);
    this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    npc(tl)->setCallback(this);
    npc(npc(npc(environment)->getSelectorManager())->getTimer())->schedule(new BandwidthLimitingTransportLayer_BandwidthLimitingTransportLayer_1(this), 0, BUCKET_TIME_LIMIT);
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    auto const returnMe = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    auto success = true;
    {
        synchronized synchronized_0(this);
        {
            if(npc(m)->remaining() > bucket) {
                success = false;
            } else {
                bucket -= npc(m)->remaining();
            }
        }
    }
    if(!success) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping message "_j)->append(static_cast< ::java::lang::Object* >(m))
                ->append(u" because not enough bandwidth:"_j)
                ->append(bucket)->toString());

        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->sendFailed(returnMe, new NotEnoughBandwidthException(bucket, npc(m)->remaining()));

        return returnMe;
    }
    npc(returnMe)->setSubCancellable(npc(tl)->sendMessage(i, m, new BandwidthLimitingTransportLayer_sendMessage_2(this, deliverAckToMe, returnMe), options));
    return returnMe;
}

org::mpisws::p2p::transport::MessageRequestHandle* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

org::mpisws::p2p::transport::SocketRequestHandle* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const returnMe = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(returnMe)->setSubCancellable(npc(tl)->openSocket(i, new BandwidthLimitingTransportLayer_openSocket_3(this, deliverSocketToMe, returnMe), options));
    return returnMe;
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(callback)->incomingSocket(new BandwidthLimitingTransportLayer_BandwidthLimitingSocket(this, s));
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
    npc(tl)->setErrorHandler(handler);
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::destroy()
{
    npc(tl)->destroy();
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    npc(callback)->messageReceived(i, m, options);
}

void rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

rice::pastry::PastryNodeFactory* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::exampleA(int32_t bindport, ::rice::environment::Environment* env, ::rice::pastry::NodeIdFactory* nidFactory, int32_t amt, int32_t time) /* throws(IOException) */
{
    clinit();
    ::rice::pastry::PastryNodeFactory* factory = new BandwidthLimitingTransportLayer_exampleA_4(amt, time, nidFactory, bindport, env);
    return factory;
}

rice::pastry::PastryNodeFactory* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::exampleB(int32_t bindport, ::rice::environment::Environment* env, ::rice::pastry::NodeIdFactory* nidFactory, int32_t amt, int32_t time) /* throws(IOException) */
{
    clinit();
    ::rice::pastry::PastryNodeFactory* factory = new BandwidthLimitingTransportLayer_exampleB_5(amt, time, nidFactory, bindport, env);
    return factory;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.tutorial.transportlayer.BandwidthLimitingTransportLayer", 60);
    return c;
}

java::lang::Class* rice::tutorial::transportlayer::BandwidthLimitingTransportLayer::getClass0()
{
    return class_();
}

