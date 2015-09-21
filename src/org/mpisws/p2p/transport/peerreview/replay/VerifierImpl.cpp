// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.java
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/reflect/AnnotatedElement.hpp>
#include <java/lang/reflect/Constructor.hpp>
#include <java/lang/reflect/GenericDeclaration.hpp>
#include <java/lang/reflect/Type.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/util/Arrays.hpp>
#include <java/util/HashMap.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/MessageCallback.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/SocketRequestHandle.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/IdentifierExtractor.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/identity/IdentityTransport.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/EventCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/ReplaySocket.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierImpl_openSocket_1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierMRH.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplaySM.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/environment/logging/LogManager.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/selector/SelectorManager.hpp>
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
        namespace reflect
        {
typedef ::SubArray< ::java::lang::reflect::AnnotatedElement, ::java::lang::ObjectArray > AnnotatedElementArray;
typedef ::SubArray< ::java::lang::reflect::GenericDeclaration, ::java::lang::ObjectArray, AnnotatedElementArray > GenericDeclarationArray;
typedef ::SubArray< ::java::lang::reflect::Type, ::java::lang::ObjectArray > TypeArray;
        } // reflect
typedef ::SubArray< ::java::lang::Class, ObjectArray, ::java::io::SerializableArray, ::java::lang::reflect::GenericDeclarationArray, ::java::lang::reflect::TypeArray, ::java::lang::reflect::AnnotatedElementArray > ClassArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
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

org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::VerifierImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::VerifierImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, ::java::lang::Object* extInfo)  /* throws(IOException) */
    : VerifierImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,env,history,localHandle,firstEntryToReplay,extInfo);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::init()
{
    eventCallback = new ::java::util::HashMap();
    callbacks = new ::java::util::HashMap();
    eventToCallback = new ::int32_tArray(int32_t(256));
    sockets = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, ::rice::environment::Environment* env, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, ::java::lang::Object* extInfo) /* throws(IOException) */
{
    super::ctor();
    init();
    if(!(dynamic_cast< ::org::mpisws::p2p::transport::peerreview::replay::playback::ReplaySM* >(npc(env)->getSelectorManager()) != nullptr)) {
        throw new ::java::lang::IllegalArgumentException(::java::lang::StringBuilder().append(u"Environment.getSelectorManager() must be a ReplaySM, was a "_j)->append(static_cast< ::java::lang::Object* >(npc(npc(env)->getSelectorManager())->getClass()))->toString());
    }
    this->environment = env;
    this->logger = npc(npc(environment)->getLogManager())->getLogger(VerifierImpl::class_(), npc(localHandle)->toString());
    this->history = history;
    this->app = nullptr;
    this->transport = peerreview;
    this->peerreview = peerreview;
    this->localHandle = localHandle;
    this->foundFault = false;
    this->nextEventIndex = firstEntryToReplay - int32_t(1);
    this->initialized = false;
    this->extInfo = extInfo;
    for (auto i = int32_t(0); i < 256; i++) 
                (*eventToCallback)[i] = -int32_t(1);

    fetchNextEvent();
    if(next == nullptr) {
        foundFault = true;
    }
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::getExtInfo()
{
    return extInfo;
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::fetchNextEvent()
{
    next = nullptr;
    nextEventIndex++;
    try {
        next = npc(history)->statEntry(nextEventIndex);
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Error fetching log entry #"_j)->append(nextEventIndex)->toString(), ioe);

        foundFault = true;
        return;
    }
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"fetchNextEvent():"_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

    if(next == nullptr) {
        return;
    }
    if(npc(next)->isHashed()) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Fetched log entry #"_j)->append(nextEventIndex)
                ->append(u" (type "_j)
                ->append(npc(next)->getType())
                ->append(u", hashed, seq="_j)
                ->append(npc(next)->getSeq())
                ->append(u")"_j)->toString());

    } else {
        try {
            nextEvent = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(history)->getEntry(nextEventIndex, npc(next)->getSizeInFile()));
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(u"Error fetching log entry #"_j)->append(nextEventIndex)
                    ->append(u" (type "_j)
                    ->append(npc(next)->getType())
                    ->append(u", size "_j)
                    ->append(npc(next)->getSizeInFile())
                    ->append(u" bytes, seq="_j)
                    ->append(npc(next)->getSeq())
                    ->append(u")"_j)->toString(), ioe);

            foundFault = true;
            return;
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Fetched log entry #"_j)->append(nextEventIndex)
                ->append(u" (type "_j)
                ->append(npc(next)->getType())
                ->append(u", size "_j)
                ->append(npc(next)->getSizeInFile())
                ->append(u" bytes, seq="_j)
                ->append(npc(next)->getSeq())
                ->append(u")"_j)->toString());

    }
}

bool org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::verifiedOK()
{
    return !foundFault;
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::getNextEvent()
{
    return next;
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::setApplication(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app)
{
    this->app = java_cast< ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* >(app);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::registerEvent(EventCallback* callback, ::int16_tArray*/*...*/ eventType)
{
    for(auto s : *npc(eventType)) {
        registerEvent(callback, s);
    }
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::registerEvent(EventCallback* callback, int16_t eventType)
{
    if(npc(eventCallback)->containsKey(::java::lang::Short::valueOf(eventType))) {
        if(callback != java_cast< EventCallback* >(npc(eventCallback)->get(::java::lang::Short::valueOf(eventType))))
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Event #"_j)->append(eventType)
                ->append(u" registered twice"_j)->toString());

    }
    npc(eventCallback)->put(::java::lang::Short::valueOf(eventType), callback);
}

bool org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::makeProgress()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"makeProgress()"_j);

    if(foundFault || next == nullptr)
        return false;

    if(!initialized && (npc(next)->getType() != EVT_CHECKPOINT) && (npc(next)->getType() != EVT_INIT)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: No INIT or CHECKPOINT found at the beginning of the log; marking as invalid "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        foundFault = true;
        return false;
    }
    if(next == nullptr)
        return false;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Replaying event #"_j)->append(nextEventIndex)
            ->append(u" (type "_j)
            ->append(npc(next)->getType())
            ->append(u", seq="_j)
            ->append(npc(next)->getSeq())
            ->append(u")"_j)->toString());

    if(npc(next)->isHashed() && (npc(next)->getType() != EVT_CHECKPOINT) && (npc(next)->getType() != EVT_INIT)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Trying to replay hashed event "_j)->append(npc(next)->getType())->toString());

        foundFault = true;
        return false;
    }
    try {
        {
            ::rice::p2p::commonapi::rawserialization::RawSerializable* sender;
            int64_t senderSeq;
            bool hashed;
            int32_t msgLen;
            int32_t relevantLen;
            ::int8_tArray* msgBytes;
            ::java::nio::ByteBuffer* msgBuf;
            ::rice::p2p::commonapi::rawserialization::RawSerializable* id;
            int64_t ackedSeq;
            VerifierMRH* foo;
            ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* temp;
            ::rice::p2p::commonapi::rawserialization::InputBuffer* tempEvent;
            switch (npc(next)->getType()) {
            case EVT_VRF: {
                    fetchNextEvent();
                    break;
                }
            case EVT_SEND:
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->logException(::java::lang::StringBuilder().append(u"Replay: Encountered EVT_SEND evt #"_j)->append(nextEventIndex)
                        ->append(u"; marking as invalid"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

                foundFault = true;
                return false;
            case EVT_SOCKET_READ: {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->logException(::java::lang::StringBuilder().append(u"Replay: Encountered EVT_SOCKET_READ evt #"_j)->append(nextEventIndex)
                            ->append(u"; marking as invalid"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

                    foundFault = true;
                    return false;
                }
            case EVT_SOCKET_CLOSE: {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->logException(::java::lang::StringBuilder().append(u"Replay: Encountered EVT_SOCKET_CLOSE evt #"_j)->append(nextEventIndex)
                            ->append(u"; marking as invalid"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

                    foundFault = true;
                    return false;
                }
            case EVT_SOCKET_SHUTDOWN_OUTPUT: {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->logException(::java::lang::StringBuilder().append(u"Replay: Encountered EVT_SOCKET_SHUTDOWN_OUTPUT evt #"_j)->append(nextEventIndex)
                            ->append(u"; marking as invalid"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

                    foundFault = true;
                    return false;
                }
            case EVT_RECV:
                sender = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getHandleSerializer())->deserialize(nextEvent));
                senderSeq = npc(nextEvent)->readLong();
                hashed = npc(nextEvent)->readBoolean();
                msgLen = npc(nextEvent)->bytesRemaining();
                relevantLen = hashed ? (msgLen - npc(transport)->getHashSizeBytes()) : msgLen;
                msgBytes = new ::int8_tArray(msgLen);
                npc(nextEvent)->read(msgBytes);
                msgBuf = ::java::nio::ByteBuffer::wrap(msgBytes);
                fetchNextEvent();
                if(next == nullptr || (npc(next)->getType() != EVT_SIGN) || (npc(next)->getSizeInFile() != static_cast< int32_t >((npc(transport)->getHashSizeBytes() + npc(transport)->getSignatureSizeBytes())))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(u"Replay: RECV event not followed by SIGN; marking as invalid"_j);

                    foundFault = true;
                    return false;
                }
                fetchNextEvent();
                npc(app)->messageReceived(sender, msgBuf, nullptr);
                break;
            case EVT_SIGN:
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Spurious SIGN event; marking as invalid"_j);

                foundFault = true;
                return false;
            case EVT_ACK:
                id = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdSerializer())->deserialize(nextEvent));
                ackedSeq = npc(nextEvent)->readLong();
                foo = java_cast< VerifierMRH* >(npc(callbacks)->remove(::java::lang::Long::valueOf(ackedSeq)));
                if(foo == nullptr) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: no message to be acked for seq:"_j)->append(ackedSeq)
                            ->append(u" fail."_j)->toString());

                    foundFault = true;
                    return false;
                }
                npc(foo)->ack();
                fetchNextEvent();
                break;
            case EVT_SENDSIGN:
                fetchNextEvent();
                break;
            case EVT_CHECKPOINT:
                if(!initialized) {
                    if(!npc(next)->isHashed()) {
                        initialized = true;
                        if(!npc(app)->loadCheckpoint(nextEvent)) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(u"Cannot load checkpoint"_j);

                            foundFault = true;
                        }
                    } else {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(u"Replay: Initial checkpoint is hashed; marking as invalid"_j);

                        foundFault = true;
                    }
                } else {
                    auto buf = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
                    npc(app)->storeCheckpoint(buf);
                    auto actualCheckpointSize = npc(buf)->getWritten();
                    if(!npc(next)->isHashed()) {
                        if(actualCheckpointSize != npc(next)->getSizeInFile()) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Checkpoint has different size (expected "_j)->append(npc(next)->getSizeInFile())
                                    ->append(u" bytes, but got "_j)
                                    ->append(actualCheckpointSize)
                                    ->append(u"); marking as invalid"_j)->toString());

                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Expected:"_j)->append(static_cast< ::java::lang::Object* >(nextEvent))->toString());

                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Found:"_j)->append(actualCheckpointSize)->toString());

                            foundFault = true;
                            return false;
                        }
                        auto bar = new ::int8_tArray(actualCheckpointSize);
                        npc(nextEvent)->read(bar);
                        if(!::java::util::Arrays::equals(bar, npc(buf)->getBytes())) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(u"Replay: Checkpoint does not match"_j);

                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Expected:"_j)->append(npc(next)->getSizeInFile())->toString());

                            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Found:"_j)->append(npc(buf)->getWritten())->toString());

                            foundFault = true;
                            return false;
                        }
                    } else {
                        auto checkpointHash = npc(transport)->hash(new ::java::nio::ByteBufferArray({npc(buf)->getByteBuffer()}));
                        if(!::java::util::Arrays::equals(checkpointHash, npc(next)->getContentHash())) {
                            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Checkpoint is hashed, but does not match hash value in the log\n"_j)->append(::java::util::Arrays::toString(checkpointHash))
                                    ->append(u"\n"_j)
                                    ->append(::java::util::Arrays::toString(npc(next)->getContentHash()))->toString());

                            foundFault = true;
                            return false;
                        }
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINEST)
                            npc(logger)->log(u"Hashed checkpoint is OK"_j);

                        npc(history)->upgradeHashedEntry(static_cast< int32_t >(nextEventIndex), npc(buf)->getByteBuffer());
                    }
                }
                fetchNextEvent();
                break;
            case EVT_INIT:
                initialized = true;
                npc(app)->init_();
                fetchNextEvent();
                break;
            case EVT_SOCKET_OPEN_INCOMING: {
                    auto socketId = npc(nextEvent)->readInt();
                    auto opener = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getHandleSerializer())->deserialize(nextEvent));
                    fetchNextEvent();
                    incomingSocket(opener, socketId);
                    break;
                }
            case EVT_SOCKET_OPENED_OUTGOING: {
                    auto socketId = npc(nextEvent)->readInt();
                    fetchNextEvent();
                    socketOpened(socketId);
                    break;
                }
            case EVT_SOCKET_CAN_READ: {
                    auto socketId = npc(nextEvent)->readInt();
                    fetchNextEvent();
                    socketIO(socketId, true, false);
                    break;
                }
            case EVT_SOCKET_CAN_WRITE: {
                    auto socketId = npc(nextEvent)->readInt();
                    fetchNextEvent();
                    socketIO(socketId, false, true);
                    break;
                }
            case EVT_SOCKET_CAN_RW: {
                    auto socketId = npc(nextEvent)->readInt();
                    fetchNextEvent();
                    socketIO(socketId, true, true);
                    break;
                }
            case EVT_SOCKET_EXCEPTION: {
                    auto socketId = npc(nextEvent)->readInt();
                    auto ex = deserializeException(nextEvent);
                    npc(logger)->log(::java::lang::StringBuilder().append(u"deserializeException("_j)->append(static_cast< ::java::lang::Object* >(ex))
                        ->append(u")"_j)->toString());
                    fetchNextEvent();
                    socketException(socketId, ex);
                    break;
                }
            default:
                if(!npc(eventCallback)->containsKey(::java::lang::Short::valueOf(npc(next)->getType()))) {
                    if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                        npc(logger)->log(::java::lang::StringBuilder().append(u"Replay("_j)->append(nextEventIndex)
                            ->append(u"): Unregistered event #"_j)
                            ->append(npc(next)->getType())
                            ->append(u"; marking as invalid"_j)->toString());

                    foundFault = true;
                    return false;
                }
                temp = next;
                tempEvent = nextEvent;
                fetchNextEvent();
                npc(java_cast< EventCallback* >(npc(eventCallback)->get(::java::lang::Short::valueOf(npc(temp)->getType()))))->replayEvent(npc(temp)->getType(), tempEvent);
                break;
            }
        }

    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Exception handling event #"_j)->append(nextEventIndex)
                ->append(u" "_j)
                ->append(static_cast< ::java::lang::Object* >(next))->toString(), ioe);

        foundFault = true;
        return false;
    }
    return true;
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::sendMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{
    try {
        auto msgLen = npc(message)->remaining();
        auto pos = npc(message)->position();
        auto lim = npc(message)->limit();
        auto relevantLen = npc(message)->remaining();
        if(options != nullptr && npc(options)->containsKey(::org::mpisws::p2p::transport::peerreview::PeerReview::RELEVANT_LENGTH())) {
            relevantLen = (npc(java_cast< ::java::lang::Integer* >(java_cast< ::java::lang::Object* >(npc(options)->get(::org::mpisws::p2p::transport::peerreview::PeerReview::RELEVANT_LENGTH())))))->intValue();
        }
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Verifier::send("_j)->append(static_cast< ::java::lang::Object* >(target))
                ->append(u", "_j)
                ->append(relevantLen)
                ->append(u"/"_j)
                ->append(npc(message)->remaining())
                ->append(u" bytes)"_j)->toString());

        if(next == nullptr) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Replay: Send event after end of segment; marking as invalid"_j);

            foundFault = true;
            return nullptr;
        }
        if(npc(next)->getType() == EVT_INIT) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
                npc(logger)->log(u"Skipped; next event is an INIT"_j);

            return nullptr;
        }
        if(npc(next)->getType() != EVT_SEND) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay("_j)->append(nextEventIndex)
                    ->append(u"): SEND event during replay, but next event in log is #"_j)
                    ->append(npc(next)->getType())
                    ->append(u"; marking as invalid"_j)->toString());

            foundFault = true;
            return nullptr;
        }
        auto sendSeq = npc(next)->getSeq();
        auto ret = new VerifierMRH(target, message, deliverAckToMe, options);
        npc(callbacks)->put(::java::lang::Long::valueOf(sendSeq), ret);
        if(npc(next)->isHashed()) {
            auto buf = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
            auto targetId = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getIdentifierExtractor())->extractIdentifier(target));
            npc(targetId)->serialize(buf);
            npc(buf)->writeBoolean(relevantLen < msgLen);
            npc(buf)->write(npc(message)->array(), npc(message)->position(), relevantLen);
            if(relevantLen < msgLen) {
                npc(message)->position(pos);
                npc(message)->limit(lim);
                auto hash = npc(transport)->hash(new ::java::nio::ByteBufferArray({message}));
            }
            auto cHash = npc(transport)->hash(new ::java::nio::ByteBufferArray({npc(buf)->getByteBuffer()}));
            if(!::java::util::Arrays::equals(cHash, npc(next)->getContentHash())) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: SEND is hashed, but hash of predicted SEND entry does not match hash in the log"_j);

                foundFault = true;
                return nullptr;
            }
            fetchNextEvent();
            /* assert((npc(next)->getType() == EVT_SENDSIGN)) */ ;
            fetchNextEvent();
            return ret;
        }
        ::rice::p2p::commonapi::rawserialization::RawSerializable* logReceiver;
        logReceiver = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getHandleSerializer())->deserialize(nextEvent));
        if(!npc(logReceiver)->equals(target)) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay("_j)->append(nextEventIndex)
                    ->append(u"): SEND to "_j)
                    ->append(static_cast< ::java::lang::Object* >(target))
                    ->append(u" during replay, but log shows SEND to "_j)
                    ->append(static_cast< ::java::lang::Object* >(logReceiver))
                    ->append(u"; marking as invalid"_j)->toString());

            nextEvent = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(history)->getEntry(next, npc(next)->getSizeInFile()));
            foundFault = true;
            return ret;
        }
        auto logIsHashed = npc(nextEvent)->readBoolean();
        if(logIsHashed) {
            if(relevantLen >= msgLen) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Message sent during replay is entirely relevant, but log entry is partly hashed; marking as invalid"_j);

                foundFault = true;
                return nullptr;
            }
            auto logRelevantLen = npc(nextEvent)->bytesRemaining() - npc(transport)->getHashSizeBytes();
            /* assert((logRelevantLen >= 0)) */ ;
            if(relevantLen != logRelevantLen) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Message sent during replay has "_j)->append(relevantLen)
                        ->append(u" relevant bytes, but log entry has "_j)
                        ->append(logRelevantLen)
                        ->append(u"; marking as invalid"_j)->toString());

                foundFault = true;
                return nullptr;
            }
            auto loggedMsg = new ::int8_tArray(logRelevantLen);
            npc(nextEvent)->read(loggedMsg);
            auto loggedMsgBB = ::java::nio::ByteBuffer::wrap(loggedMsg);
            if((relevantLen > 0) && npc(message)->equals(static_cast< ::java::lang::Object* >(loggedMsgBB))) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Relevant part of partly hashed message differs"_j);

                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Expected: ["_j)->append(static_cast< ::java::lang::Object* >(loggedMsgBB))
                        ->append(u"]"_j)->toString());

                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Actual:   ["_j)->append(static_cast< ::java::lang::Object* >(message))
                        ->append(u"]"_j)->toString());

                foundFault = true;
                return nullptr;
            }
            auto logHash = new ::int8_tArray(npc(transport)->getHashSizeBytes());
            npc(nextEvent)->read(logHash);
            auto msgHashBytes = npc(message)->array();
            auto msgHash = new ::int8_tArray(npc(transport)->getHashSizeBytes());
            ::java::lang::System::arraycopy(msgHashBytes, npc(msgHashBytes)->length - npc(transport)->getHashSizeBytes(), msgHash, 0, npc(transport)->getHashSizeBytes());
            /* assert((msgLen == (relevantLen + npc(transport)->getHashSizeBytes()))) */ ;
            if(!npc(msgHash)->equals(logHash)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Hashed part of partly hashed message differs"_j);

                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Expected: ["_j)->append(static_cast< ::java::lang::Object* >(logHash))
                        ->append(u"]"_j)->toString());

                if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Actual:   ["_j)->append(static_cast< ::java::lang::Object* >(msgHash))
                        ->append(u"]"_j)->toString());

                foundFault = true;
                return nullptr;
            }
        } else {
            if(relevantLen < msgLen) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Message sent during replay is only partly relevant, but log entry is not hashed; marking as invalid"_j);

                foundFault = true;
                return nullptr;
            }
            auto logMsglen = npc(nextEvent)->bytesRemaining();
            if(msgLen != logMsglen) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Message sent during replay has "_j)->append(msgLen)
                        ->append(u" bytes, but log entry has "_j)
                        ->append(logMsglen)
                        ->append(u"; marking as invalid"_j)->toString());

                foundFault = true;
                return nullptr;
            }
            auto loggedMsg = new ::int8_tArray(npc(nextEvent)->bytesRemaining());
            npc(nextEvent)->read(loggedMsg);
            auto sentMsg = new ::int8_tArray(npc(message)->remaining());
            npc(message)->get(sentMsg);
            if(npc(loggedMsg)->length != npc(sentMsg)->length) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Message sent during replay differs from message in the log by length log:"_j)->append(npc(loggedMsg)->length)
                        ->append(u" sent:"_j)
                        ->append(npc(sentMsg)->length)->toString());

                foundFault = true;
                return nullptr;
            }
            if((msgLen > 0) && !::java::util::Arrays::equals(loggedMsg, sentMsg)) {
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Message sent during replay differs from message in the log"_j);

                foundFault = true;
                return nullptr;
            }
        }
        fetchNextEvent();
        /* assert((npc(next)->getType() == EVT_SENDSIGN)) */ ;
        fetchNextEvent();
        if(next == nullptr) {
            npc(logger)->log(u"next event is null"_j);
        }
        return ret;
    } catch (::java::io::IOException* ioe) {
        npc(logger)->logException(u"Error calculating hash"_j, ioe);
        foundFault = true;
        return nullptr;
    }
}

org::mpisws::p2p::transport::MessageRequestHandle* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::sendMessage(::java::lang::Object* i, ::java::lang::Object* m, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options)
{ 
    return sendMessage(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(i), dynamic_cast< ::java::nio::ByteBuffer* >(m), dynamic_cast< ::org::mpisws::p2p::transport::MessageCallback* >(deliverAckToMe), options);
}

int64_t org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::getNextEventTime()
{
    if(next == nullptr)
        return -int32_t(1);

    return npc(next)->getSeq() / int32_t(1000000);
}

bool org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::isSuccess()
{
    if(initialized && verifiedOK()) {
        if(next == nullptr)
            return true;

    }
    return false;
}

java::io::IOException* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::deserializeException(::rice::p2p::commonapi::rawserialization::InputBuffer* nextEvent) /* throws(IOException) */
{
    auto exType = npc(nextEvent)->readShort();
    {
        ::java::lang::String* className;
        ::java::lang::String* message;
        ::java::lang::Class* c;
        ::java::lang::ClassArray* parameterTypes;
        switch (exType) {
        case EX_TYPE_IO:
            return new ::java::io::IOException(npc(nextEvent)->readUTF());
        case EX_TYPE_ClosedChannel:
            return new ::org::mpisws::p2p::transport::ClosedChannelException(npc(nextEvent)->readUTF());
        case EX_TYPE_Unknown:
            className = npc(nextEvent)->readUTF();
            message = npc(nextEvent)->readUTF();
            try {
                c = ::java::lang::Class::forName(className);
            } catch (::java::lang::ClassNotFoundException* cnfe) {
                throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Couldn't find class"_j)->append(className)
                    ->append(u" "_j)
                    ->append(message)->toString());
            }
            parameterTypes = new ::java::lang::ClassArray(int32_t(1));
            parameterTypes->set(int32_t(0), ::java::lang::String::class_());
            try {
                auto ctor_ = npc(c)->getConstructor(parameterTypes);
                auto ioe = java_cast< ::java::io::IOException* >(java_cast< ::java::lang::Object* >(npc(ctor_)->newInstance(new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(message)}))));
                return ioe;
            } catch (::java::lang::Exception* e) {
                try {
                    auto ctor_ = npc(c)->getConstructor(new ::java::lang::ClassArray(int32_t(0)));
                    auto ioe = java_cast< ::java::io::IOException* >(java_cast< ::java::lang::Object* >(npc(ctor_)->newInstance(new ::java::lang::ObjectArray({static_cast< ::java::lang::Object* >(message)}))));
                    return ioe;
                } catch (::java::lang::Exception* e2) {
                    throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Couldn't find constructor for"_j)->append(className)
                        ->append(u" "_j)
                        ->append(message)->toString());
                }
            }
        default:
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Unknown EX_TYPE:"_j)->append(exType)->toString());
        }
    }

}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::openSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{
    try {
        auto socketId = openSocket(i);
        auto socket = new ReplaySocket(i, socketId, this, options);
        npc(socket)->setDeliverSocketToMe(deliverSocketToMe);
        npc(sockets)->put(::java::lang::Integer::valueOf(socketId), socket);
        return socket;
    } catch (::java::io::IOException* ioe) {
        ::org::mpisws::p2p::transport::SocketRequestHandle* ret = new VerifierImpl_openSocket_1(this, i, options);
        npc(deliverSocketToMe)->receiveException(ret, ioe);
        return ret;
    }
}

org::mpisws::p2p::transport::SocketRequestHandle* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::openSocket(::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::java::util::Map* options)
{ 
    return openSocket(dynamic_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(i), dynamic_cast< ::org::mpisws::p2p::transport::SocketCallback* >(deliverSocketToMe), options);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::socketIO(int32_t socketId, bool canRead, bool canWrite) /* throws(IOException) */
{
    npc(java_cast< ReplaySocket* >(npc(sockets)->get(::java::lang::Integer::valueOf(socketId))))->notifyIO(canRead, canWrite);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::incomingSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* from, int32_t socketId) /* throws(IOException) */
{
    auto socket = new ReplaySocket(from, socketId, this, nullptr);
    npc(sockets)->put(::java::lang::Integer::valueOf(socketId), socket);
    npc(app)->incomingSocket(socket);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::socketOpened(int32_t socketId) /* throws(IOException) */
{
    npc(java_cast< ReplaySocket* >(npc(sockets)->get(::java::lang::Integer::valueOf(socketId))))->socketOpened();
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::socketException(int32_t socketId, ::java::io::IOException* ioe) /* throws(IOException) */
{
    npc(java_cast< ReplaySocket* >(npc(sockets)->get(::java::lang::Integer::valueOf(socketId))))->receiveException(ioe);
}

int32_t org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::openSocket(::rice::p2p::commonapi::rawserialization::RawSerializable* target) /* throws(IOException) */
{
    if(next == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: OpenSocket event after end of segment; marking as invalid"_j);

        foundFault = true;
        return ::java::lang::Integer::MIN_VALUE;
    }
    if(npc(next)->getType() != EVT_SOCKET_OPEN_OUTGOING) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_OPEN_OUTGOING event during replay, but next event in log is #"_j)->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return ::java::lang::Integer::MIN_VALUE;
    }
    auto ret = npc(nextEvent)->readInt();
    ::rice::p2p::commonapi::rawserialization::RawSerializable* logReceiver;
    logReceiver = java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(npc(npc(peerreview)->getHandleSerializer())->deserialize(nextEvent));
    if(!npc(logReceiver)->equals(target)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_OPEN_OUTGOING to "_j)->append(static_cast< ::java::lang::Object* >(target))
                ->append(u" during replay, but log shows SOCKET_OPEN_OUTGOING to "_j)
                ->append(static_cast< ::java::lang::Object* >(logReceiver))
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return ::java::lang::Integer::MIN_VALUE;
    }
    fetchNextEvent();
    return ret;
}

int32_t org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::readSocket(int32_t socketId, ::java::nio::ByteBuffer* dst) /* throws(IOException) */
{
    if(next == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: ReadSocket event after end of segment; marking as invalid"_j);

        foundFault = true;
        return 0;
    }
    if(npc(next)->getType() == EVT_SOCKET_CLOSED) {
        fetchNextEvent();
        return -int32_t(1);
    }
    if(npc(next)->getType() != EVT_SOCKET_READ) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"Replay ("_j)->append(nextEventIndex)
                ->append(u"): SOCKET_READ event during replay, but next event in log is #"_j)
                ->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString(), new ::java::lang::Exception(u"Stack Trace"_j));

        foundFault = true;
        return ::java::lang::Integer::MIN_VALUE;
    }
    auto loggedSocket = npc(nextEvent)->readInt();
    if(loggedSocket != socketId) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_READ on socket "_j)->append(socketId)
                ->append(u" during replay, but log shows SOCKET_READ to "_j)
                ->append(loggedSocket)
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return 0;
    }
    auto ret = npc(nextEvent)->bytesRemaining();
    if(npc(dst)->remaining() < ret) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_READ reading a maximum of "_j)->append(npc(dst)->remaining())
                ->append(u" on socket "_j)
                ->append(socketId)
                ->append(u" during replay, but log shows SOCKET_READ reading "_j)
                ->append(ret)
                ->append(u" bytes; marking as invalid"_j)->toString());

        foundFault = true;
        return 0;
    }
    npc(nextEvent)->read(npc(dst)->array(), npc(dst)->position(), ret);
    npc(dst)->position(npc(dst)->position() + ret);
    fetchNextEvent();
    return ret;
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::generatedSocketException(int32_t socketId, ::java::io::IOException* ioe)
{
    if(next == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: WriteSocket event after end of segment; marking as invalid"_j);

        foundFault = true;
        return;
    }
    if(npc(next)->getType() != EVT_SOCKET_EXCEPTION) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: EVT_SOCKET_EXCEPTION event during replay, but next event in log is #"_j)->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    try {
        auto loggedSocket = npc(nextEvent)->readInt();
        if(loggedSocket != socketId) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: EVT_SOCKET_EXCEPTION on socket "_j)->append(socketId)
                    ->append(u" during replay, but log shows EVT_SOCKET_EXCEPTION to "_j)
                    ->append(loggedSocket)
                    ->append(u"; marking as invalid"_j)->toString());

            foundFault = true;
            return;
        }
    } catch (::java::io::IOException* ioe2) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(u"Replay: Error reading log"_j, ioe2);

    }
    fetchNextEvent();
    return;
}

int32_t org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::writeSocket(int32_t socketId, ::java::nio::ByteBuffer* src) /* throws(IOException) */
{
    if(next == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: WriteSocket event after end of segment; marking as invalid"_j);

        foundFault = true;
        return 0;
    }
    if(npc(next)->getType() == EVT_SOCKET_CLOSED) {
        fetchNextEvent();
        return -int32_t(1);
    }
    if(npc(next)->getType() != EVT_SOCKET_WRITE) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_WRITE event during replay, but next event in log is #"_j)->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return ::java::lang::Integer::MIN_VALUE;
    }
    auto loggedSocket = npc(nextEvent)->readInt();
    if(loggedSocket != socketId) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_WRITE on socket "_j)->append(socketId)
                ->append(u" during replay, but log shows SOCKET_WRITE to "_j)
                ->append(loggedSocket)
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return 0;
    }
    auto ret = npc(nextEvent)->bytesRemaining();
    if(npc(src)->remaining() < ret) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_WRITE writing a maximum of "_j)->append(npc(src)->remaining())
                ->append(u" on socket "_j)
                ->append(socketId)
                ->append(u" during replay, but log shows SOCKET_WRITE writing "_j)
                ->append(ret)
                ->append(u" bytes; marking as invalid"_j)->toString());

        foundFault = true;
        return 0;
    }
    auto loggedMsg = new ::int8_tArray(ret);
    auto sentMsg = new ::int8_tArray(ret);
    npc(nextEvent)->read(loggedMsg);
    npc(src)->get(sentMsg);
    if(!::java::util::Arrays::equals(loggedMsg, sentMsg)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: Message wrote during replay differs from message in the log"_j);

        foundFault = true;
        return 0;
    }
    fetchNextEvent();
    return ret;
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::close(int32_t socketId)
{
    if(next == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay("_j)->append(nextEventIndex)
                ->append(u"): SOCKET_CLOSE event after end of segment; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    if(npc(next)->getType() != EVT_SOCKET_CLOSE) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay("_j)->append(nextEventIndex)
                ->append(u"): SOCKET_CLOSE event during replay, but next event in log is #"_j)
                ->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    int32_t loggedSocket;
    try {
        loggedSocket = npc(nextEvent)->readInt();
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Error deserializing event "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        foundFault = true;
        return;
    }
    if(loggedSocket != socketId) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: SOCKET_CLOSE on socket "_j)->append(socketId)
                ->append(u" during replay, but log shows SOCKET_CLOSE to "_j)
                ->append(loggedSocket)
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    fetchNextEvent();
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::shutdownOutput(int32_t socketId)
{
    if(next == nullptr) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: EVT_SOCKET_SHUTDOWN_OUTPUT event after end of segment; marking as invalid"_j);

        foundFault = true;
        return;
    }
    if(npc(next)->getType() != EVT_SOCKET_SHUTDOWN_OUTPUT) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: EVT_SOCKET_SHUTDOWN_OUTPUT event during replay, but next event in log is #"_j)->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    int32_t loggedSocket;
    try {
        loggedSocket = npc(nextEvent)->readInt();
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Error deserializing event "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        foundFault = true;
        return;
    }
    if(loggedSocket != socketId) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: EVT_SOCKET_SHUTDOWN_OUTPUT on socket "_j)->append(socketId)
                ->append(u" during replay, but log shows EVT_SOCKET_SHUTDOWN_OUTPUT to "_j)
                ->append(loggedSocket)
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    fetchNextEvent();
}

rice::environment::Environment* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::getEnvironment()
{
    return environment;
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::acceptMessages(bool b)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::acceptSockets(bool b)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::getLocalIdentifier()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(localHandle);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::setCallback(::org::mpisws::p2p::transport::TransportLayerCallback* callback)
{
    this->app = java_cast< ::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* >(callback);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::setErrorHandler(::org::mpisws::p2p::transport::ErrorHandler* handler)
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

void org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::destroy()
{
    throw new ::java::lang::RuntimeException(u"implement"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.VerifierImpl", 55);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::VerifierImpl::getClass0()
{
    return class_();
}

