// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.java
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/Throwable.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySocket.hpp>
#include <org/mpisws/p2p/transport/util/MessageRequestHandleImpl.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/CloneableLogManager.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/simple/SimpleParameters.hpp>
#include <rice/environment/processing/sim/SimProcessor.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/p2p/util/MathUtils.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::ReplayLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::ReplayLayer(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, ::rice::environment::Environment* environment)  /* throws(IOException) */
    : ReplayLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(serializer,hashProv,history,localHandle,environment);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::init()
{
    sockets = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::ctor(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, ::rice::environment::Environment* environment) /* throws(IOException) */
{
    super::ctor(serializer, hashProv, history, localHandle, static_cast< int16_t >(int32_t(0)), static_cast< int16_t >(int32_t(0)), int32_t(0), npc(npc(environment)->getLogManager())->getLogger(ReplayLayer::class_(), npc(localHandle)->toString()));
    init();
    this->environment = environment;
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    try {
        auto socketId = openSocket(i);
        auto socket = new ReplaySocket(i, socketId, this, options);
        npc(socket)->setDeliverSocketToMe(deliverSocketToMe);
        npc(sockets)->put(::java::lang::Integer::valueOf(socketId), socket);
        return socket;
    } catch (::java::io::IOException* ioe) {
        ::org::mpisws::p2p::transport::SocketRequestHandle* ret = new ReplayLayer_openSocket_1(this, i, options);
        npc(deliverSocketToMe)->receiveException(ret, ioe);
        return ret;
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        npc(logger)->logException(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u"):"_j)
            ->append(::rice::p2p::util::MathUtils::toHex(npc(m)->array()))->toString(), new ::java::lang::Exception(u"Stack Trace"_j));
    } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u"):"_j)
            ->append(::rice::p2p::util::MathUtils::toHex(npc(m)->array()))->toString());
    } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE) {
        npc(logger)->log(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(m))
            ->append(u")"_j)->toString());
    }
    auto ret = new ::org::mpisws::p2p::transport::util::MessageRequestHandleImpl(i, m, options);
    try {
        send(i, m, -int32_t(1));
        if(deliverAckToMe != nullptr)
            npc(deliverAckToMe)->ack(ret);

    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u""_j, ioe);

        throw new ::java::lang::RuntimeException(static_cast< ::java::lang::Throwable* >(ioe));
    }
    return ret;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(localHandle);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::destroy()
{
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::acceptMessages(bool b)
{
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::acceptSockets(bool b)
{
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::receive(::java::lang::Object* from, ::java::nio::ByteBuffer* msg) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"receive("_j)->append(static_cast< ::java::lang::Object* >(from))
            ->append(u","_j)
            ->append(static_cast< ::java::lang::Object* >(msg))
            ->append(u")"_j)->toString());

    npc(callback)->messageReceived(from, msg, nullptr);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::socketIO(int32_t socketId, bool canRead, bool canWrite) /* throws(IOException) */
{
    npc(java_cast< ReplaySocket* >(npc(sockets)->get(::java::lang::Integer::valueOf(socketId))))->notifyIO(canRead, canWrite);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::incomingSocket(::java::lang::Object* from, int32_t socketId) /* throws(IOException) */
{
    auto socket = new ReplaySocket(from, socketId, this, nullptr);
    npc(sockets)->put(::java::lang::Integer::valueOf(socketId), socket);
    npc(callback)->incomingSocket(socket);
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::generateEnvironment(::java::lang::String* name, int64_t startTime, int64_t randSeed, ::rice::environment::logging::LogManager* lm2)
{
    clinit();
    ::rice::environment::params::Parameters* params = new ::rice::environment::params::simple::SimpleParameters(::rice::environment::Environment::defaultParamFileArray_(), nullptr);
    auto dts = new ::rice::environment::time::simulated::DirectTimeSource(startTime);
    ::rice::environment::logging::LogManager* lm;
    if((lm2 != nullptr) && (dynamic_cast< ::rice::environment::logging::CloneableLogManager* >(lm2) != nullptr)) {
        auto clm = java_cast< ::rice::environment::logging::CloneableLogManager* >(lm2);
        lm = npc(clm)->clone(::java::lang::StringBuilder().append(npc(clm)->getPrefix())->append(u"-"_j)
            ->append(name)->toString(), dts);
    } else {
        lm = ::rice::environment::Environment::generateDefaultLogManager(dts, params);
    }
    ::rice::environment::random::RandomSource* rs = new ::rice::environment::random::simple::SimpleRandomSource(randSeed, lm);
    npc(dts)->setLogManager(lm);
    ::rice::selector::SelectorManager* selector = new ReplaySM(::java::lang::StringBuilder().append(u"Replay "_j)->append(name)->toString(), dts, lm);
    npc(dts)->setSelectorManager(selector);
    ::rice::environment::processing::Processor* proc = new ::rice::environment::processing::sim::SimProcessor(selector);
    auto env = new ::rice::environment::Environment(selector, proc, rs, dts, lm, params, ::rice::environment::Environment::generateDefaultExceptionStrategy(lm));
    return env;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::socketOpened(int32_t socketId) /* throws(IOException) */
{
    npc(java_cast< ReplaySocket* >(npc(sockets)->get(::java::lang::Integer::valueOf(socketId))))->socketOpened();
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::socketException(int32_t socketId, ::java::io::IOException* ioe) /* throws(IOException) */
{
    npc(java_cast< ReplaySocket* >(npc(sockets)->get(::java::lang::Integer::valueOf(socketId))))->receiveException(ioe);
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::getEnvironment()
{
    return environment;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.playback.ReplayLayer", 63);
    return c;
}

int32_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::openSocket(::java::lang::Object* target)
{
    return super::openSocket(target);
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayLayer::getClass0()
{
    return class_();
}

