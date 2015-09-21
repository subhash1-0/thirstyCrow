// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.java
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket_register_1.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace nio
    {
typedef ::SubArray< ::java::nio::Buffer, ::java::lang::ObjectArray > BufferArray;
typedef ::SubArray< ::java::nio::ByteBuffer, BufferArray, ::java::lang::ComparableArray > ByteBufferArray;
    } // nio
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket_register_1::RecordSocket_register_1(RecordSocket *RecordSocket_this, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
    : super(*static_cast< ::default_init_tag* >(0))
    , RecordSocket_this(RecordSocket_this)
    , receiver(receiver)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket_register_1::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    int16_t evt;
    if(canRead && canWrite) {
        evt = ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants::EVT_SOCKET_CAN_RW;
    } else if(canRead) {
        evt = ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants::EVT_SOCKET_CAN_READ;
    } else if(canWrite) {
        evt = ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants::EVT_SOCKET_CAN_WRITE;
    } else {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"I can't read or write. canRead:"_j)->append(canRead)
            ->append(u" canWrite:"_j)
            ->append(canWrite)->toString());
    }
    try {
        npc(RecordSocket_this->socketIdBuffer)->clear();
        npc(RecordSocket_this->recordLayer)->logEvent(evt, new ::java::nio::ByteBufferArray({RecordSocket_this->socketIdBuffer}));
    } catch (::java::io::IOException* ioe2) {
        if(npc(RecordSocket_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(RecordSocket_this->logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveException()"_j)->toString(), ioe2);

    }
    npc(receiver)->receiveSelectResult(RecordSocket_this, canRead, canWrite);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket_register_1::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    try {
        npc(RecordSocket_this->socketIdBuffer)->clear();
        npc(RecordSocket_this->recordLayer)->logSocketException(RecordSocket_this->socketIdBuffer, ioe);
    } catch (::java::io::IOException* ioe2) {
        if(npc(RecordSocket_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(RecordSocket_this->logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u"@"_j)
                ->append(RecordSocket_this->socketId)
                ->append(u".receiveException()"_j)->toString(), ioe2);

    }
    npc(receiver)->receiveException(socket, ioe);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket_register_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket_register_1::getClass0()
{
    return class_();
}

