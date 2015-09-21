// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferWriter.java
#include <org/mpisws/p2p/transport/util/BufferWriter.hpp>

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

org::mpisws::p2p::transport::util::BufferWriter::BufferWriter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::BufferWriter::BufferWriter(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation, bool includeSizeHeader) 
    : BufferWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(writeMe,socket,continuation,includeSizeHeader);
}

org::mpisws::p2p::transport::util::BufferWriter::BufferWriter(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation) 
    : BufferWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(writeMe,socket,continuation);
}

void org::mpisws::p2p::transport::util::BufferWriter::init()
{
    sizeBuf = nullptr;
}

void org::mpisws::p2p::transport::util::BufferWriter::ctor(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation, bool includeSizeHeader)
{
    super::ctor();
    init();
    this->writeMe = writeMe;
    this->continuation = continuation;
    if(includeSizeHeader) {
        sizeBuf = ::java::nio::ByteBuffer::allocate(4);
        npc(npc(sizeBuf)->asIntBuffer())->put(npc(writeMe)->remaining());
        npc(sizeBuf)->clear();
    }
    try {
        receiveSelectResult(socket, false, true);
    } catch (::java::io::IOException* ioe) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(ioe));
    }
}

void org::mpisws::p2p::transport::util::BufferWriter::ctor(::java::nio::ByteBuffer* writeMe, ::org::mpisws::p2p::transport::P2PSocket* socket, ::rice::Continuation* continuation)
{
    ctor(writeMe, socket, continuation, true);
}

void org::mpisws::p2p::transport::util::BufferWriter::receiveException(::org::mpisws::p2p::transport::P2PSocket* socket, ::java::lang::Exception* ioe)
{
    if(continuation == nullptr) {
        npc(socket)->close();
    } else {
        npc(continuation)->receiveException(ioe);
    }
}

void org::mpisws::p2p::transport::util::BufferWriter::receiveSelectResult(::org::mpisws::p2p::transport::P2PSocket* socket, bool canRead, bool canWrite) /* throws(IOException) */
{
    if(sizeBuf != nullptr && npc(sizeBuf)->hasRemaining()) {
        if(npc(socket)->write(sizeBuf) < 0) {
            receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Unexpected closure of channel to "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->toString())));
            return;
        }
    }
    if(npc(socket)->write(writeMe) < 0) {
        receiveException(socket, static_cast< ::java::lang::Exception* >(new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Unexpected closure of channel to "_j)->append(static_cast< ::java::lang::Object* >(java_cast< ::java::lang::Object* >(npc(socket)->getIdentifier())))->toString())));
        return;
    }
    if(npc(writeMe)->hasRemaining()) {
        npc(socket)->register_(false, true, this);
        return;
    }
    if(continuation == nullptr) {
        npc(socket)->close();
    } else {
        npc(continuation)->receiveResult(socket);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::BufferWriter::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.BufferWriter", 42);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::BufferWriter::getClass0()
{
    return class_();
}

