// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.java
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayer.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/stub/NullHashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer_generateEnvironment_2.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSM.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.hpp>
#include <org/mpisws/p2p/transport/util/DefaultErrorHandler.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/environment/params/simple/SimpleParameters.hpp>
#include <rice/environment/processing/sim/SimProcessor.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/environment/time/TimeSource.hpp>
#include <rice/environment/time/simple/SimpleTimeSource.hpp>
#include <rice/environment/time/simulated/DirectTimeSource.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <Array.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

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

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
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

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::RecordLayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::RecordLayer(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* name, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::rice::environment::Environment* env)  /* throws(IOException) */
    : RecordLayer(*static_cast< ::default_init_tag* >(0))
{
    ctor(tl,name,serializer,env);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::init()
{
    initialized = false;
    socketCtr = ::java::lang::Integer::MIN_VALUE;
}

java::lang::String*& org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::PR_RELEVANT_LEN()
{
    clinit();
    return PR_RELEVANT_LEN_;
}
java::lang::String* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::PR_RELEVANT_LEN_;

java::lang::String*& org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::PR_RELEVANT_MSG()
{
    clinit();
    return PR_RELEVANT_MSG_;
}
java::lang::String* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::PR_RELEVANT_MSG_;

java::nio::ByteBuffer*& org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::ONE()
{
    clinit();
    return ONE_;
}
java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::ONE_;

java::nio::ByteBuffer*& org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::ZERO()
{
    clinit();
    return ZERO_;
}
java::nio::ByteBuffer* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::ZERO_;

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::ctor(::org::mpisws::p2p::transport::TransportLayer* tl, ::java::lang::String* name, ::org::mpisws::p2p::transport::util::Serializer* serializer, ::rice::environment::Environment* env) /* throws(IOException) */
{
    super::ctor();
    init();
    this->logger = npc(npc(env)->getLogManager())->getLogger(RecordLayer::class_(), nullptr);
    this->identifierSerializer = serializer;
    auto nhp = new ::org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider();
    auto shf = new ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl(nhp, env);
    auto one = new ::int8_tArray(int32_t(1));
    (*one)[int32_t(0)] = 1;
    ONE() = ::java::nio::ByteBuffer::wrap(one);
    auto zero = new ::int8_tArray(int32_t(1));
    (*zero)[int32_t(0)] = 0;
    ZERO() = ::java::nio::ByteBuffer::wrap(zero);
    this->tl = tl;
    npc(java_cast< ::org::mpisws::p2p::transport::TransportLayer* >(this->tl))->setCallback(this);
    this->history = npc(shf)->create(name, static_cast< int64_t >(int32_t(0)), npc(nhp)->EMPTY_HASH());
    this->environment = env;
    this->lastLogEntry = -int32_t(1);
    this->handler = new ::org::mpisws::p2p::transport::util::DefaultErrorHandler(logger);
    initialized = true;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::updateLogTime()
{
    auto now = npc(npc(environment)->getTimeSource())->currentTimeMillis();
    if(now > lastLogEntry) {
        if(!npc(history)->setNextSeq(now * int32_t(1000000)))
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(::java::lang::StringBuilder().append(u"PeerReview: Cannot roll back history sequence number from "_j)->append(npc(history)->getLastSeq())
                ->append(u" to "_j)
                ->append(now * int32_t(1000000))->toString())->append(u"; did you change the local time?"_j)->toString());

        lastLogEntry = now;
    }
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::logEvent(int16_t type, ::java::nio::ByteBufferArray*/*...*/ entry) /* throws(IOException) */
{
    if(history == nullptr)
        return;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST) {
        npc(logger)->logException(::java::lang::StringBuilder().append(u"logging #"_j)->append(npc(history)->getNumEntries())
            ->append(u" t:"_j)
            ->append(type)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));
    } else if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER) {
        npc(logger)->log(::java::lang::StringBuilder().append(u"logging #"_j)->append(npc(history)->getNumEntries())
            ->append(u" t:"_j)
            ->append(type)->toString());
    }
    updateLogTime();
    npc(history)->appendEntry(type, true, entry);
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    auto const socketId = socketCtr++;
    auto const socketIdBuffer = ::java::nio::ByteBuffer::wrap(::rice::p2p::util::MathUtils::intToByteArray_(socketId));
    try {
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(identifierSerializer)->serialize(i, sob);
        logEvent(EVT_SOCKET_OPEN_OUTGOING, new ::java::nio::ByteBufferArray({socketIdBuffer, npc(sob)->getByteBuffer()}));
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u")"_j)->toString(), ioe);

    }
    auto const ret = new ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl(i, options, logger);
    npc(ret)->setSubCancellable(npc(tl)->openSocket(i, new RecordLayer_openSocket_1(this, socketIdBuffer, i, deliverSocketToMe, ret, options, socketId), options));
    return ret;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::incomingSocket(::org::mpisws::p2p::transport::P2PSocket* s) /* throws(IOException) */
{
    auto const socketId = socketCtr++;
    auto const socketIdBuffer = ::java::nio::ByteBuffer::wrap(::rice::p2p::util::MathUtils::intToByteArray_(socketId));
    try {
        npc(socketIdBuffer)->clear();
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(identifierSerializer)->serialize(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()), sob);
        logEvent(EVT_SOCKET_OPEN_INCOMING, new ::java::nio::ByteBufferArray({socketIdBuffer, npc(sob)->getByteBuffer()}));
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"incomingSocket("_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier())))
                ->append(u")"_j)->toString(), ioe);

    }
    npc(callback)->incomingSocket(new RecordSocket(java_cast< ::java::lang::Object* >(npc(s)->getIdentifier()), s, logger, npc(s)->getOptions(), socketId, socketIdBuffer, this));
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::sendMessage(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
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
    if(options == nullptr || !npc(options)->containsKey(PR_RELEVANT_MSG()) || npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(PR_RELEVANT_MSG())))))->intValue() != 0) {
        auto position = npc(m)->position();
        auto relevantLen = npc(m)->remaining();
        if(options != nullptr && npc(options)->containsKey(PR_RELEVANT_LEN()) && npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(PR_RELEVANT_LEN())))))->intValue() >= 0) {
            relevantLen = npc((java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(PR_RELEVANT_LEN())))))->intValue();
        }
        try {
            auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
            npc(identifierSerializer)->serialize(i, sob);
            logEvent(EVT_SEND, new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer(), m}));
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"sendMessage("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(m))
                    ->append(u")"_j)->toString(), ioe);

        }
        npc(m)->position(position);
    }
    return npc(tl)->sendMessage(i, m, deliverAckToMe, options);
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::messageReceived(::java::lang::Object* i, ::java::nio::ByteBuffer* m, ::java::util::Map* options) /* throws(IOException) */
{
    try {
        if(identifierSerializer == nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Dropping messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
                    ->append(u","_j)
                    ->append(static_cast< ::java::lang::Object* >(m))
                    ->append(u") while booting"_j)->toString());

            return;
        }
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(identifierSerializer)->serialize(i, sob);
        logEvent(EVT_RECV, new ::java::nio::ByteBufferArray({npc(sob)->getByteBuffer(), m}));
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"messageReceived("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u","_j)
                ->append(static_cast< ::java::lang::Object* >(m))
                ->append(u")"_j)->toString(), ioe);

    }
    npc(callback)->messageReceived(i, m, options);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::messageReceived(::java::lang::Object* i, ::java::lang::Object* m, ::java::util::Map* options)
{ 
    messageReceived(dynamic_cast< ::java::lang::Object* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), options);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::acceptMessages(bool b)
{
    npc(tl)->acceptMessages(b);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::acceptSockets(bool b)
{
    npc(tl)->acceptSockets(b);
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::getLocalIdentifier()
{
    return java_cast< ::java::lang::Object* >(npc(tl)->getLocalIdentifier());
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->callback = callback;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    this->handler = handler;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::destroy()
{
    try {
        if(history != nullptr)
            npc(history)->close();

        history = nullptr;
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Error destroying."_j, ioe);

    }
    npc(tl)->destroy();
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::generateEnvironment()
{
    clinit();
    return generateEnvironment(static_cast< ::rice::environment::random::RandomSource* >(nullptr));
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::generateEnvironment(int32_t randomSeed)
{
    clinit();
    auto srs = new ::rice::environment::random::simple::SimpleRandomSource(static_cast< int64_t >(randomSeed), static_cast< ::rice::environment::logging::LogManager* >(nullptr));
    auto env = generateEnvironment(static_cast< ::rice::environment::random::RandomSource* >(srs));
    npc(srs)->setLogManager(npc(env)->getLogManager());
    return env;
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::generateEnvironment(::rice::environment::random::RandomSource* rs)
{
    clinit();
    ::rice::environment::params::Parameters* params = new ::rice::environment::params::simple::SimpleParameters(::rice::environment::Environment::defaultParamFileArray_(), nullptr);
    auto dts = new ::rice::environment::time::simulated::DirectTimeSource(::java::lang::System::currentTimeMillis());
    auto lm = ::rice::environment::Environment::generateDefaultLogManager(dts, params);
    npc(dts)->setLogManager(lm);
    ::rice::selector::SelectorManager* selector = new RecordSM(u"Default"_j, new ::rice::environment::time::simple::SimpleTimeSource(), dts, lm, rs);
    npc(dts)->setSelectorManager(selector);
    ::rice::environment::processing::Processor* proc = new ::rice::environment::processing::sim::SimProcessor(selector);
    ::rice::environment::Environment* ret = new RecordLayer_generateEnvironment_2(selector, proc, rs, dts, lm, params, ::rice::environment::Environment::generateDefaultExceptionStrategy(lm));
    return ret;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::logSocketException(::java::nio::ByteBuffer* socketId, ::java::lang::Exception* ioe) /* throws(IOException) */
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::CONFIG)
        npc(logger)->logException(::java::lang::StringBuilder().append(u"logSocketException("_j)->append(static_cast< ::java::lang::Object* >(ioe))
            ->append(u")"_j)->toString(), ioe);

    auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
    auto className = npc(npc(ioe)->getClass())->getName();
    if(npc(className)->endsWith(u"ClosedChannelException"_j)) {
        npc(sob)->writeShort(EX_TYPE_ClosedChannel);
        npc(sob)->writeUTF(npc(ioe)->getMessage());
    } else if(npc(className)->equals(static_cast< ::java::lang::Object* >(u"java.io.IOException"_j))) {
        npc(sob)->writeShort(EX_TYPE_IO);
        npc(sob)->writeUTF(npc(ioe)->getMessage());
    } else {
        npc(sob)->writeShort(EX_TYPE_Unknown);
        npc(sob)->writeUTF(className);
        npc(sob)->writeUTF(npc(ioe)->getMessage());
    }
    auto ioeBuffer = ::java::nio::ByteBuffer::wrap(npc(sob)->getBytes());
    npc(ioeBuffer)->limit(npc(sob)->getWritten());
    logEvent(EVT_SOCKET_EXCEPTION, new ::java::nio::ByteBufferArray({socketId, ioeBuffer}));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.record.RecordLayer", 61);
    return c;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::clinit()
{
struct string_init_ {
    string_init_() {
    PR_RELEVANT_LEN_ = u"pr_relevant_len"_j;
    PR_RELEVANT_MSG_ = u"pr_relevant_msg"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer::getClass0()
{
    return class_();
}

