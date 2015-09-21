// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/playback/ReplayVerifier.java
#include <org/mpisws/p2p/transport/peerreview/replay/playback/ReplayVerifier.hpp>

#include <java/io/IOException.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/ClassNotFoundException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/IllegalStateException.hpp>
#include <java/lang/Integer.hpp>
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
#include <org/mpisws/p2p/transport/peerreview/PeerReviewCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashProvider.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/EventCallback.hpp>
#include <org/mpisws/p2p/transport/util/Serializer.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
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

org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::ReplayVerifier(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::ReplayVerifier(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, int16_t signatureSizeBytes, int16_t hashSizeBytes, int32_t firstEntryToReplay, ::rice::environment::logging::Logger* logger)  /* throws(IOException) */
    : ReplayVerifier(*static_cast< ::default_init_tag* >(0))
{
    ctor(serializer,hashProv,history,localHandle,signatureSizeBytes,hashSizeBytes,firstEntryToReplay,logger);
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::init()
{
    eventToCallback = new ::int32_tArray(int32_t(256));
    useSendSign = false;
    useSenderSeq = false;
    useLogHashFlag = false;
    eventCallback = new ::java::util::HashMap();
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::ctor(::org::mpisws::p2p::transport::util::Serializer* serializer, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::java::lang::Object* localHandle, int16_t signatureSizeBytes, int16_t hashSizeBytes, int32_t firstEntryToReplay, ::rice::environment::logging::Logger* logger) /* throws(IOException) */
{
    super::ctor();
    init();
    this->logger = logger;
    this->history = history;
    this->numEventCallbacks = 0;
    this->serializer = serializer;
    this->hashProv = hashProv;
    this->localHandle = localHandle;
    this->foundFault = false;
    this->haveNextEvent = false;
    this->nextEventIndex = firstEntryToReplay - int32_t(1);
    this->initialized = false;
    this->signatureSizeBytes = signatureSizeBytes;
    this->hashSizeBytes = hashSizeBytes;
    this->numTimers = 0;
    for (auto i = int32_t(0); i < 256; i++) 
                (*eventToCallback)[i] = -int32_t(1);

    fetchNextEvent();
    if(!haveNextEvent)
        foundFault = true;

}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::verifiedOK()
{
    return !foundFault;
}

org::mpisws::p2p::transport::peerreview::history::IndexEntry* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::getNextEvent()
{
    return next;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::setApplication(::org::mpisws::p2p::transport::peerreview::PeerReviewCallback* app)
{
    this->app = app;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::fetchNextEvent()
{
    haveNextEvent = false;
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

    if(next == nullptr)
        return;

    if(npc(next)->getSizeInFile() < 0) {
        nextEventIsHashed = true;
        nextEvent = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(next)->getContentHash());
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Fetched log entry #"_j)->append(nextEventIndex)
                ->append(u" (type "_j)
                ->append(npc(next)->getType())
                ->append(u", hashed, seq="_j)
                ->append(npc(next)->getSeq())
                ->append(u")"_j)->toString());

    } else {
        nextEventIsHashed = false;
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
    haveNextEvent = true;
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::send(::java::lang::Object* target, ::java::nio::ByteBuffer* message, int32_t relevantLen) /* throws(IOException) */
{
    auto msgLen = npc(message)->remaining();
    auto pos = npc(message)->position();
    auto lim = npc(message)->limit();
    if(relevantLen < 0)
        relevantLen = npc(message)->remaining();

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Verifier::send("_j)->append(static_cast< ::java::lang::Object* >(target))
            ->append(u", "_j)
            ->append(relevantLen)
            ->append(u"/"_j)
            ->append(npc(message)->remaining())
            ->append(u" bytes)"_j)->toString());

    if(!haveNextEvent) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: Send event after end of segment; marking as invalid"_j);

        foundFault = true;
        return;
    }
    if(npc(next)->getType() == EVT_INIT) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::FINER)
            npc(logger)->log(u"Skipped; next event is an INIT"_j);

        return;
    }
    if(npc(next)->getType() != EVT_SEND) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay("_j)->append(nextEventIndex)
                ->append(u"): SEND event during replay, but next event in log is #"_j)
                ->append(npc(next)->getType())
                ->append(u"; marking as invalid"_j)->toString());

        foundFault = true;
        return;
    }
    if(nextEventIsHashed) {
        auto buf = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(serializer)->serialize(target, buf);
        if(useLogHashFlag)
            npc(buf)->writeBoolean(relevantLen < msgLen);

        npc(buf)->write(npc(message)->array(), npc(message)->position(), relevantLen);
        if(relevantLen < msgLen) {
            npc(message)->position(pos);
            npc(message)->limit(lim);
            auto hash = npc(hashProv)->hash(new ::java::nio::ByteBufferArray({message}));
        }
        auto cHash = npc(hashProv)->hash(new ::java::nio::ByteBufferArray({::java::nio::ByteBuffer::wrap(npc(buf)->getBytes())}));
        if(!npc(cHash)->equals(npc(next)->getContentHash())) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Replay: SEND is hashed, but hash of predicted SEND entry does not match hash in the log"_j);

            foundFault = true;
            return;
        }
        if(useSendSign) {
            fetchNextEvent();
            /* assert((npc(next)->getType() == EVT_SENDSIGN)) */ ;
        }
        fetchNextEvent();
        return;
    }
    ::java::lang::Object* logReceiver;
    logReceiver = java_cast< ::java::lang::Object* >(npc(serializer)->deserialize(nextEvent));
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
        return;
    }
    auto logIsHashed = false;
    if(useLogHashFlag)
        logIsHashed = npc(nextEvent)->readBoolean();

    if(logIsHashed) {
        if(relevantLen >= msgLen) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Replay: Message sent during replay is entirely relevant, but log entry is partly hashed; marking as invalid"_j);

            foundFault = true;
            return;
        }
        auto logRelevantLen = npc(nextEvent)->bytesRemaining() - hashSizeBytes;
        /* assert((logRelevantLen >= 0)) */ ;
        if(relevantLen != logRelevantLen) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Message sent during replay has "_j)->append(relevantLen)
                    ->append(u" relevant bytes, but log entry has "_j)
                    ->append(logRelevantLen)
                    ->append(u"; marking as invalid"_j)->toString());

            foundFault = true;
            return;
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
            return;
        }
        auto logHash = new ::int8_tArray(hashSizeBytes);
        npc(nextEvent)->read(logHash);
        auto msgHashBytes = npc(message)->array();
        auto msgHash = new ::int8_tArray(hashSizeBytes);
        ::java::lang::System::arraycopy(msgHashBytes, npc(msgHashBytes)->length - hashSizeBytes, msgHash, 0, hashSizeBytes);
        /* assert((msgLen == (relevantLen + hashSizeBytes))) */ ;
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
            return;
        }
    } else {
        if(relevantLen < msgLen) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Replay: Message sent during replay is only partly relevant, but log entry is not hashed; marking as invalid"_j);

            foundFault = true;
            return;
        }
        auto logMsglen = npc(nextEvent)->bytesRemaining();
        if(msgLen != logMsglen) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: Message sent during replay has "_j)->append(msgLen)
                    ->append(u" bytes, but log entry has "_j)
                    ->append(logMsglen)
                    ->append(u"; marking as invalid"_j)->toString());

            foundFault = true;
            return;
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
            return;
        }
        if((msgLen > 0) && !::java::util::Arrays::equals(loggedMsg, sentMsg)) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->log(u"Replay: Message sent during replay differs from message in the log"_j);

            foundFault = true;
            return;
        }
    }
    if(useSendSign) {
        fetchNextEvent();
        /* assert((npc(next)->getType() == EVT_SENDSIGN)) */ ;
    }
    fetchNextEvent();
}

int32_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::openSocket(::java::lang::Object* target) /* throws(IOException) */
{
    if(!haveNextEvent) {
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
    ::java::lang::Object* logReceiver;
    logReceiver = java_cast< ::java::lang::Object* >(npc(serializer)->deserialize(nextEvent));
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

int32_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::readSocket(int32_t socketId, ::java::nio::ByteBuffer* dst) /* throws(IOException) */
{
    if(!haveNextEvent) {
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

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::generatedSocketException(int32_t socketId, ::java::io::IOException* ioe)
{
    if(!haveNextEvent) {
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

int32_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::writeSocket(int32_t socketId, ::java::nio::ByteBuffer* src) /* throws(IOException) */
{
    if(!haveNextEvent) {
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

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::close(int32_t socketId)
{
    if(!haveNextEvent) {
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

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::shutdownOutput(int32_t socketId)
{
    if(!haveNextEvent) {
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

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::registerEvent(::org::mpisws::p2p::transport::peerreview::replay::EventCallback* callback, ::int16_tArray*/*...*/ eventType)
{
    for(auto s : *npc(eventType)) {
        registerEvent(callback, s);
    }
}

void org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::registerEvent(::org::mpisws::p2p::transport::peerreview::replay::EventCallback* callback, int16_t eventType)
{
    if(npc(eventCallback)->containsKey(::java::lang::Short::valueOf(eventType))) {
        if(callback != java_cast< ::org::mpisws::p2p::transport::peerreview::replay::EventCallback* >(npc(eventCallback)->get(::java::lang::Short::valueOf(eventType))))
            throw new ::java::lang::IllegalStateException(::java::lang::StringBuilder().append(u"Event #"_j)->append(eventType)
                ->append(u" registered twice"_j)->toString());

    }
    npc(eventCallback)->put(::java::lang::Short::valueOf(eventType), callback);
}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::makeProgress()
{
    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(u"makeProgress()"_j);

    if(foundFault || !haveNextEvent)
        return false;

    if(!initialized && (npc(next)->getType() != EVT_CHECKPOINT) && (npc(next)->getType() != EVT_INIT)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(::java::lang::StringBuilder().append(u"Replay: No INIT or CHECKPOINT found at the beginning of the log; marking as invalid "_j)->append(static_cast< ::java::lang::Object* >(next))->toString());

        foundFault = true;
        return false;
    }
    if(!haveNextEvent)
        return false;

    if(npc(logger)->level <= ::rice::environment::logging::Logger::FINE)
        npc(logger)->log(::java::lang::StringBuilder().append(u"Replaying event #"_j)->append(nextEventIndex)
            ->append(u" (type "_j)
            ->append(npc(next)->getType())
            ->append(u", seq="_j)
            ->append(npc(next)->getSeq())
            ->append(u")"_j)->toString());

    if(nextEventIsHashed && (npc(next)->getType() != EVT_CHECKPOINT) && (npc(next)->getType() != EVT_INIT)) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->log(u"Replay: Trying to replay hashed event"_j);

        foundFault = true;
        return false;
    }
    try {
        {
            ::java::lang::Object* sender;
            int64_t senderSeq;
            bool hashed;
            int32_t msgLen;
            int32_t relevantLen;
            ::int8_tArray* msgBytes;
            ::java::nio::ByteBuffer* msgBuf;
            ::org::mpisws::p2p::transport::peerreview::history::IndexEntry* temp;
            ::rice::p2p::commonapi::rawserialization::InputBuffer* tempEvent;
            switch (npc(next)->getType()) {
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
                sender = java_cast< ::java::lang::Object* >(npc(serializer)->deserialize(nextEvent));
                senderSeq = int32_t(0);
                if(useSenderSeq)
                    senderSeq = npc(nextEvent)->readLong();

                hashed = false;
                if(useLogHashFlag)
                    hashed = npc(nextEvent)->readBoolean();

                msgLen = npc(nextEvent)->bytesRemaining();
                relevantLen = hashed ? (msgLen - hashSizeBytes) : msgLen;
                msgBytes = new ::int8_tArray(msgLen);
                npc(nextEvent)->read(msgBytes);
                msgBuf = ::java::nio::ByteBuffer::wrap(msgBytes);
                if(useSendSign) {
                    fetchNextEvent();
                    if(!haveNextEvent || (npc(next)->getType() != EVT_SIGN) || (npc(next)->getSizeInFile() != static_cast< int32_t >((hashSizeBytes + signatureSizeBytes)))) {
                        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                            npc(logger)->log(u"Replay: RECV event not followed by SIGN; marking as invalid"_j);

                        foundFault = true;
                        return false;
                    }
                }
                fetchNextEvent();
                receive(sender, msgBuf);
                break;
            case EVT_SIGN:
                if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                    npc(logger)->log(u"Replay: Spurious SIGN event; marking as invalid"_j);

                foundFault = true;
                return false;
            case EVT_ACK:
                fetchNextEvent();
                break;
            case EVT_SENDSIGN:
                fetchNextEvent();
                break;
            case EVT_CHECKPOINT:
            case EVT_INIT:
                initialized = true;
                fetchNextEvent();
                break;
            case EVT_SOCKET_OPEN_INCOMING: {
                    auto socketId = npc(nextEvent)->readInt();
                    auto opener = java_cast< ::java::lang::Object* >(npc(serializer)->deserialize(nextEvent));
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
                npc(java_cast< ::org::mpisws::p2p::transport::peerreview::replay::EventCallback* >(npc(eventCallback)->get(::java::lang::Short::valueOf(npc(temp)->getType()))))->replayEvent(npc(temp)->getType(), tempEvent);
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

int64_t org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::getNextEventTime()
{
    return npc(next)->getSeq() / int32_t(1000000);
}

bool org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::isSuccess()
{
    if(initialized && verifiedOK()) {
        if(next == nullptr)
            return true;

    }
    return false;
}

java::io::IOException* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::deserializeException(::rice::p2p::commonapi::rawserialization::InputBuffer* nextEvent) /* throws(IOException) */
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

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.playback.ReplayVerifier", 66);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::playback::ReplayVerifier::getClass0()
{
    return class_();
}

