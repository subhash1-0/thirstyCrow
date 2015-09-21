// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/BufferReaderWriter.java
#include <org/mpisws/p2p/transport/util/BufferReaderWriter.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/util/BufferReader.hpp>
#include <org/mpisws/p2p/transport/util/BufferReaderWriter_BufferReaderWriter_1.hpp>
#include <org/mpisws/p2p/transport/util/BufferReaderWriter_BufferReaderWriter_2.hpp>
#include <org/mpisws/p2p/transport/util/BufferWriter.hpp>
#include <rice/Continuation.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::util::BufferReaderWriter::BufferReaderWriter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::BufferReaderWriter::BufferReaderWriter(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c) 
    : BufferReaderWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(sock,writeMe,writeSize,c);
}

org::mpisws::p2p::transport::util::BufferReaderWriter::BufferReaderWriter(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c, int32_t readSize) 
    : BufferReaderWriter(*static_cast< ::default_init_tag* >(0))
{
    ctor(sock,writeMe,writeSize,c,readSize);
}

void org::mpisws::p2p::transport::util::BufferReaderWriter::init()
{
    doneReading = false;
    doneWriting = false;
    failed = false;
    sentException = false;
    read = nullptr;
}

void org::mpisws::p2p::transport::util::BufferReaderWriter::ctor(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c)
{
    ctor(sock, writeMe, writeSize, c, -int32_t(1));
}

void org::mpisws::p2p::transport::util::BufferReaderWriter::ctor(::org::mpisws::p2p::transport::P2PSocket* sock, ::java::nio::ByteBuffer* writeMe, bool writeSize, ::rice::Continuation* c, int32_t readSize)
{
    super::ctor();
    init();
    this->socket = sock;
    this->c = c;
    new BufferReader(sock, new BufferReaderWriter_BufferReaderWriter_1(this), readSize);
    new BufferWriter(writeMe, sock, new BufferReaderWriter_BufferReaderWriter_2(this), writeSize);
}

void org::mpisws::p2p::transport::util::BufferReaderWriter::done(::java::lang::Exception* e)
{
    if(failed) {
        if(!sentException) {
            sentException = true;
            npc(c)->receiveException(e);
            npc(socket)->close();
        }
        return;
    }
    if(doneReading && doneWriting) {
        npc(c)->receiveResult(read);
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::BufferReaderWriter::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.BufferReaderWriter", 48);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::BufferReaderWriter::getClass0()
{
    return class_();
}

