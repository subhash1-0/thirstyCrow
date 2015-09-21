// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferReader.java
#include <org/mpisws/p2p/transport/util/BufferReader.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <java/nio/IntBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <rice/Continuation.hpp>

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

org::mpisws::p2p::transport::util::BufferReader::BufferReader(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::BufferReader::BufferReader(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation) 
    : BufferReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,continuation);
}

org::mpisws::p2p::transport::util::BufferReader::BufferReader(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation, int32_t size) 
    : BufferReader(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,continuation,size);
}

void org::mpisws::p2p::transport::util::BufferReader::init()
{
    readSize = false;
    size = -int32_t(1);
}

void org::mpisws::p2p::transport::util::BufferReader::ctor(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation)
{
    ctor(socket, continuation, -int32_t(1));
}

void org::mpisws::p2p::transport::util::BufferReader::ctor(::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation, int32_t size)
{
    super::ctor();
    init();
    this->continuation = continuation;
    this->size = size;
    if(size < 0) {
        buf = ::java::nio::ByteBuffer::allocate(4);
    } else {
        buf = ::java::nio::ByteBuffer::allocate(size);
    }
    try {
        receiveSelectResult(socket, true, false);
    } catch (::java::io::IOException* ioe) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(ioe));
    }
}

void org::mpisws::p2p::transport::util::BufferReader::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    npc(continuation)->receiveException(ioe);
}

void org::mpisws::p2p::transport::util::BufferReader::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(npc(socket)->read(buf) < 0) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Unexpected closure of channel to "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->toString())));
        return;
    }
    if(npc(buf)->hasRemaining()) {
        npc(socket)->register_(true, false, this);
        return;
    }
    npc(buf)->flip();
    if(size < 0) {
        size = npc(npc(buf)->asIntBuffer())->get();
        buf = ::java::nio::ByteBuffer::allocate(size);
        receiveSelectResult(socket, true, false);
    } else {
        npc(continuation)->receiveResult(buf);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::BufferReader::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.BufferReader", 42);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::BufferReader::getClass0()
{
    return class_();
}

