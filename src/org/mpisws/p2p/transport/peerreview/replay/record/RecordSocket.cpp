// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.java
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/Buffer.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/ErrorHandler.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/P2PSocketReceiver.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordLayer.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/record/RecordSocket_register_1.hpp>
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

org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::RecordSocket(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::RecordSocket(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::java::util::Map* options, int32_t socketId, ::java::nio::ByteBuffer* sib, RecordLayer* recordLayer) 
    : RecordSocket(*static_cast< ::default_init_tag* >(0))
{
    ctor(identifier,socket,logger,options,socketId,sib,recordLayer);
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::init()
{
    closed = false;
    outputShutdown = false;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::ctor(::java::lang::Object* identifier, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::environment::logging::Logger* logger, ::java::util::Map* options, int32_t socketId, ::java::nio::ByteBuffer* sib, RecordLayer* recordLayer)
{
    super::ctor(identifier, socket, logger, npc(recordLayer)->handler, options);
    init();
    this->socketId = socketId;
    this->socketIdBuffer = sib;
    this->recordLayer = recordLayer;
}

int64_t org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::read(::java::nio::ByteBuffer* dsts) /* throws(IOException) */
{
    auto pos = npc(dsts)->position();
    auto ret = static_cast< int32_t >(super::read(dsts));
    if(ret < 0) {
        try {
            npc(socketIdBuffer)->clear();
            npc(recordLayer)->logEvent(EVT_SOCKET_CLOSED, new ::java::nio::ByteBufferArray({socketIdBuffer}));
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".read()"_j)->toString(), ioe);

        }
    } else {
        auto bits = ::java::nio::ByteBuffer::wrap(npc(dsts)->array());
        npc(bits)->position(pos);
        npc(bits)->limit(pos + ret);
        try {
            npc(socketIdBuffer)->clear();
            npc(recordLayer)->logEvent(EVT_SOCKET_READ, new ::java::nio::ByteBufferArray({socketIdBuffer, bits}));
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".read()"_j)->toString(), ioe);

        }
    }
    return ret;
}

int64_t org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::write(::java::nio::ByteBuffer* srcs) /* throws(IOException) */
{
    auto pos = npc(srcs)->position();
    auto ret = static_cast< int32_t >(super::write(srcs));
    if(ret < 0) {
        try {
            npc(socketIdBuffer)->clear();
            npc(recordLayer)->logEvent(EVT_SOCKET_CLOSED, new ::java::nio::ByteBufferArray({socketIdBuffer}));
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".write()"_j)->toString(), ioe);

        }
    } else {
        auto bits = ::java::nio::ByteBuffer::wrap(npc(srcs)->array());
        npc(bits)->position(pos);
        npc(bits)->limit(pos + ret);
        try {
            npc(socketIdBuffer)->clear();
            npc(recordLayer)->logEvent(EVT_SOCKET_WRITE, new ::java::nio::ByteBufferArray({socketIdBuffer, bits}));
        } catch (::java::io::IOException* ioe) {
            if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
                npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".write()"_j)->toString(), ioe);

        }
    }
    return ret;
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::close()
{
    try {
        closed = true;
        npc(socketIdBuffer)->clear();
        npc(recordLayer)->logEvent(EVT_SOCKET_CLOSE, new ::java::nio::ByteBufferArray({socketIdBuffer}));
    } catch (::java::io::IOException* ioe2) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveException()"_j)->toString(), ioe2);

    }
    super::close();
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::shutdownOutput()
{
    try {
        outputShutdown = true;
        npc(socketIdBuffer)->clear();
        npc(recordLayer)->logEvent(EVT_SOCKET_SHUTDOWN_OUTPUT, new ::java::nio::ByteBufferArray({socketIdBuffer}));
    } catch (::java::io::IOException* ioe2) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(static_cast< ::java::lang::Object* >(this))->append(u".receiveException()"_j)->toString(), ioe2);

    }
    super::shutdownOutput();
}

void org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::register_(bool wantToRead, bool wantToWrite, ::org::mpisws::p2p::transport::P2PSocketReceiver* receiver)
{
    if(closed) {
        npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" already closed."_j)->toString()));
        return;
    }
    if(wantToWrite && outputShutdown) {
        npc(receiver)->receiveException(this, new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(this))
            ->append(u" already shutdown output."_j)->toString()));
        return;
    }
    super::register_(wantToRead, wantToWrite, static_cast< ::org::mpisws::p2p::transport::P2PSocketReceiver* >(new RecordSocket_register_1(this, receiver)));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.replay.record.RecordSocket", 62);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::replay::record::RecordSocket::getClass0()
{
    return class_();
}

