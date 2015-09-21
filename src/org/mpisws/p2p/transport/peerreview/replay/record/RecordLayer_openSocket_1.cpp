// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.java
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer_openSocket_1.hpp>

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
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.hpp>
#include <org/mpisws/p2p/transport/util/SocketRequestHandleImpl.hpp>
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

org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_openSocket_1::RecordLayer_openSocket_1(RecordLayer *RecordLayer_this, ::java::nio::ByteBuffer* socketIdBuffer, ::java::lang::Object* i, ::org::mpisws::p2p::transport::SocketCallback* deliverSocketToMe, ::org::mpisws::p2p::transport::util::SocketRequestHandleImpl* ret, ::java::util::Map* options, int32_t socketId)
    : super(*static_cast< ::default_init_tag* >(0))
    , RecordLayer_this(RecordLayer_this)
    , socketIdBuffer(socketIdBuffer)
    , i(i)
    , deliverSocketToMe(deliverSocketToMe)
    , ret(ret)
    , options(options)
    , socketId(socketId)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_openSocket_1::receiveResult(::org::mpisws::p2p::transport::SocketRequestHandle* cancellable, ::org::mpisws::p2p::transport::P2PSocket* sock)
{
    npc(socketIdBuffer)->clear();
    try {
        RecordLayer_this->logEvent(::org::mpisws::p2p::transport::peerreview::PeerReviewConstants::EVT_SOCKET_OPENED_OUTGOING, new ::java::nio::ByteBufferArray({socketIdBuffer}));
    } catch (::java::io::IOException* ioe) {
        if(npc(RecordLayer_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(RecordLayer_this->logger)->logException(::java::lang::StringBuilder().append(u"error logging in openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u")"_j)->toString(), ioe);

    }
    npc(socketIdBuffer)->clear();
    npc(deliverSocketToMe)->receiveResult(ret, new RecordSocket(i, sock, RecordLayer_this->logger, options, socketId, socketIdBuffer, RecordLayer_this));
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_openSocket_1::receiveException(::org::mpisws::p2p::transport::SocketRequestHandle* s, ::java::lang::Exception* ex)
{
    npc(socketIdBuffer)->clear();
    try {
        RecordLayer_this->logSocketException(socketIdBuffer, ex);
    } catch (::java::io::IOException* ioe) {
        if(npc(RecordLayer_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(RecordLayer_this->logger)->logException(::java::lang::StringBuilder().append(u"openSocket("_j)->append(static_cast< ::java::lang::Object* >(i))
                ->append(u")@"_j)
                ->append(socketId)->toString(), ioe);

    }
    npc(deliverSocketToMe)->receiveException(ret, ex);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_openSocket_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordLayer_openSocket_1::getClass0()
{
    return class_();
}

