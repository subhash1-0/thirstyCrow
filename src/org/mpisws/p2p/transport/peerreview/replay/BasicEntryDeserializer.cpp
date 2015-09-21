// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/BasicEntryDeserializer.java
#include <org/mpisws/p2p/transport/peerreview/replay/BasicEntryDeserializer.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/IndexEntry.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistory.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/SecureHistoryFactoryImpl.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/reader/LogReader.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/stub/NullHashProvider.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
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
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::BasicEntryDeserializer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::BasicEntryDeserializer()
    : BasicEntryDeserializer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

java::lang::String* org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::entryId(int16_t id)
{
    switch (id) {
    case EVT_SEND:
        return u"Send"_j;
    case EVT_RECV:
        return u"Receive"_j;
    case EVT_SIGN:
        return u"Sign"_j;
    case EVT_ACK:
        return u"Ack"_j;
    case EVT_CHECKPOINT:
        return u"Checkpoint"_j;
    case EVT_INIT:
        return u"Init"_j;
    case EVT_SENDSIGN:
        return u"Send_sign"_j;
    case EVT_SOCKET_OPEN_INCOMING:
        return u"Socket_open_incoming"_j;
    case EVT_SOCKET_OPEN_OUTGOING:
        return u"Socket_open_outgoing"_j;
    case EVT_SOCKET_OPENED_OUTGOING:
        return u"Socket_opened_outgoing"_j;
    case EVT_SOCKET_EXCEPTION:
        return u"Socket_exception"_j;
    case EVT_SOCKET_CLOSE:
        return u"Socket_close"_j;
    case EVT_SOCKET_CLOSED:
        return u"Socket_closed"_j;
    case EVT_SOCKET_CAN_READ:
        return u"Socket_can_R"_j;
    case EVT_SOCKET_CAN_WRITE:
        return u"Socket_can_W"_j;
    case EVT_SOCKET_CAN_RW:
        return u"Socket_can_RW"_j;
    case EVT_SOCKET_READ:
        return u"Socket_R"_j;
    case EVT_SOCKET_WRITE:
        return u"Socket_W"_j;
    case EVT_SOCKET_SHUTDOWN_OUTPUT:
        return u"Socket_shutdown_output"_j;
    default:
        return nullptr;
    }

}

java::lang::String* org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::read(::org::mpisws::p2p::transport::peerreview::history::IndexEntry* ie, ::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history) /* throws(IOException) */
{
    if(npc(ie)->getType() >= EVT_MIN_SOCKET_EVT && npc(ie)->getType() <= EVT_MAX_SOCKET_EVT) {
        return ::java::lang::StringBuilder().append(entryId(npc(ie)->getType()))->append(u" n:"_j)
            ->append(npc(ie)->getSeq())
            ->append(u" i:"_j)
            ->append(npc(ie)->getFileIndex())
            ->append(u" sock:"_j)
            ->append((new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(history)->getEntry(ie, int32_t(4))))->readInt())->toString();
    }
    return ::java::lang::StringBuilder().append(entryId(npc(ie)->getType()))->append(u" n:"_j)
        ->append(npc(ie)->getSeq())
        ->append(u" s:"_j)
        ->append(npc(ie)->getSizeInFile())
        ->append(u" i:"_j)
        ->append(npc(ie)->getFileIndex())->toString();
}

void org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::printLog(::java::lang::String* name, ::org::mpisws::p2p::transport::peerreview::history::reader::EntryDeserializer* deserializer, ::rice::environment::Environment* env) /* throws(IOException) */
{
    clinit();
    npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"printLog("_j)->append(name)
        ->append(u")"_j)->toString());
    ::java::lang::String* line;
    ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hashProv = new ::org::mpisws::p2p::transport::peerreview::history::stub::NullHashProvider();
    auto ctr = int32_t(0);
    auto reader = new ::org::mpisws::p2p::transport::peerreview::history::reader::LogReader(name, new ::org::mpisws::p2p::transport::peerreview::history::SecureHistoryFactoryImpl(hashProv, env), deserializer);
    while ((line = npc(reader)->readEntry()) != nullptr) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"#"_j)->append(ctr)
            ->append(u" "_j)
            ->append(line)->toString());
        ctr++;
    }
}

void org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::main(::java::lang::StringArray* args) /* throws(IOException) */
{
    clinit();
    printLog((*args)[int32_t(0)], new BasicEntryDeserializer(), new ::rice::environment::Environment());
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.BasicEntryDeserializer", 65);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::BasicEntryDeserializer::getClass0()
{
    return class_();
}

