// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.java
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer.hpp>

#include <java/lang/Boolean.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Collection.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Map.hpp>
#include <java/util/Set.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_openSocket_2.hpp>
#include <org/mpisws/p2p/transport/bandwidthmeasure/BandwidthMeasuringTransportLayer_MySocket.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/p2p/util/tuples/Tuple3.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
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
org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::BandwidthMeasuringTransportLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::BandwidthMeasuringTransportLayer(int32_t measurementPeriod, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env) 
    : BandwidthMeasuringTransportLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(measurementPeriod,tl,env);
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::init()
{
    measurementPeriod = int32_t(5000);
    measured = new ::java::util::HashMap();
}

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::CUR_DOWN;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::CUR_UP;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::CUR_SATURATED;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::LAST_DOWN;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::LAST_UP;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::LAST_SATURATED;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::NUM_VALS;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::SATURATED;

constexpr int32_t org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::NOT_SATURATED;

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::ctor(int32_t measurementPeriod, ::org::mpisws::p2p::transport::TransportLayer* tl, ::rice::environment::Environment* env)
{
    super::ctor();
    init();
    this->tl = tl;
    npc(tl)->setCallback(this);
    this->measurementPeriod = measurementPeriod;
    this->logger = npc(npc(env)->getLogManager())->getLogger(BandwidthMeasuringTransportLayer::class_(), nullptr);
    this->errorHandler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    this->time = npc(env)->getTimeSource();
    this->lastMeasure = npc(time)->currentTimeMillis();
    npc(npc(env)->getSelectorManager())->schedule(static_cast< ::rice::selector::TimerTask* >(new BandwidthMeasuringTransportLayer_BandwidthMeasuringTransportLayer_1(this)), static_cast< int64_t >(measurementPeriod), static_cast< int64_t >(measurementPeriod));
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::measure()
{
    {
        synchronized synchronized_0(measured);
        {
            auto now = npc(time)->currentTimeMillis();
            auto diff = static_cast< int32_t >((now - lastMeasure));
            lastMeasure = now;
            for (auto _i = npc(npc(measured)->keySet())->iterator(); _i->hasNext(); ) {
                ::java::lang::Object* i = java_cast< ::java::lang::Object* >(_i->next());
                {
                    auto t = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(measured)->get(i));
                    auto vals = java_cast< ::int32_tArray* >(npc(t)->a());
                    (*vals)[LAST_DOWN] = (*vals)[CUR_DOWN] * int32_t(1000) / diff;
                    (*vals)[LAST_UP] = (*vals)[CUR_UP] * int32_t(1000) / diff;
                    (*vals)[LAST_SATURATED] = (*vals)[CUR_SATURATED];
                    (*vals)[CUR_DOWN] = 0;
                    (*vals)[CUR_UP] = 0;
                    (*vals)[CUR_SATURATED] = NOT_SATURATED;
                    if((*vals)[LAST_SATURATED] == NOT_SATURATED) {
                        for (auto _i = npc(java_cast< ::java::util::Collection* >(npc(t)->b()))->iterator(); _i->hasNext(); ) {
                            BandwidthMeasuringTransportLayer_MySocket* s = java_cast< BandwidthMeasuringTransportLayer_MySocket* >(_i->next());
                            {
                                if(npc(s)->wantsToWrite()) {
                                    (*vals)[LAST_SATURATED] = SATURATED;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

rice::p2p::util::tuples::Tuple* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::getVals(::java::lang::Object* i)
{
    auto ret = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(measured)->get(i));
    if(ret == nullptr) {
        ret = new ::rice::p2p::util::tuples::Tuple(new ::int32_tArray(NUM_VALS), new ::java::util::ArrayList());
        npc(measured)->put(i, ret);
    }
    return ret;
}

java::util::Map* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::getBandwidthUsed()
{
    {
        synchronized synchronized_1(measured);
        {
            auto ret = new ::java::util::HashMap();
            for (auto _i = npc(npc(measured)->keySet())->iterator(); _i->hasNext(); ) {
                ::java::lang::Object* i = java_cast< ::java::lang::Object* >(_i->next());
                {
                    auto t = java_cast< ::rice::p2p::util::tuples::Tuple* >(npc(measured)->get(i));
                    auto vals = java_cast< ::int32_tArray* >(npc(t)->a());
                    npc(ret)->put(static_cast< ::java::lang::Object* >(i), static_cast< ::java::lang::Object* >(new ::rice::p2p::util::tuples::Tuple3(::java::lang::Integer::valueOf((*vals)[LAST_DOWN]), ::java::lang::Integer::valueOf((*vals)[LAST_UP]), ::java::lang::Boolean::valueOf(((*vals)[LAST_SATURATED] == SATURATED) ? true : false))));
                }
            }
            return ret;
        }
    }
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    npc(callback)->incomingSocket(new BandwidthMeasuringTransportLayer_MySocket(this, java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()), s, logger, errorHandler, npc(s)->getOptions()));
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    {
        synchronized synchronized_2(measured);
        {
            (*java_cast< ::int32_tArray* >(npc(getVals(i))->a()))[CUR_DOWN] += npc(m)->remaining();
        }
    }
    npc(callback)->messageReceived(i, m, options);
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    {
        synchronized synchronized_3(measured);
        {
            (*java_cast< ::int32_tArray* >(npc(getVals(i))->a()))[CUR_UP] += npc(m)->remaining();
        }
    }
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new BandwidthMeasuringTransportLayer_openSocket_2(this, deliverSocketToMe, ret, i, options), options));
    return ret;
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->errorHandler = handler;
}

void org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::destroy()
{
    npc(tl)->destroy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.bandwidthmeasure.BandwidthMeasuringTransportLayer", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::bandwidthmeasure::BandwidthMeasuringTransportLayer::getClass0()
{
    return class_();
}

