// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/SocketInputBuffer.java
#include <org/mpisws/p2p/transport/util/SocketInputBuffer.hpp>

#include <java/io/DataInputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <org/mpisws/p2p/transport/ClosedChannelException.hpp>
#include <org/mpisws/p2p/transport/P2PSocket.hpp>
#include <org/mpisws/p2p/transport/util/InsufficientBytesException.hpp>
#include <org/mpisws/p2p/transport/util/SocketInputBuffer_resetDis_1.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::util::SocketInputBuffer::SocketInputBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::SocketInputBuffer::SocketInputBuffer(::org::mpisws::p2p::transport::P2PSocket* socket) 
    : SocketInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket);
}

org::mpisws::p2p::transport::util::SocketInputBuffer::SocketInputBuffer(::org::mpisws::p2p::transport::P2PSocket* socket, int32_t size) 
    : SocketInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(socket,size);
}

void org::mpisws::p2p::transport::util::SocketInputBuffer::ctor(::org::mpisws::p2p::transport::P2PSocket* socket)
{
    ctor(socket, int32_t(1024));
}

void org::mpisws::p2p::transport::util::SocketInputBuffer::ctor(::org::mpisws::p2p::transport::P2PSocket* socket, int32_t size)
{
    super::ctor();
    this->socket = socket;
    initialSize = size;
    cache = new ::int8_tArray(size);
    readPtr = ::java::nio::ByteBuffer::wrap(cache);
    writePtr = ::java::nio::ByteBuffer::wrap(cache);
    resetDis();
}

void org::mpisws::p2p::transport::util::SocketInputBuffer::resetDis()
{
    if(dis != nullptr && npc(dis)->markSupported()) {
        try {
            npc(dis)->reset();
        } catch (::java::io::IOException* ioe) {
            dis = nullptr;
            resetDis();
        }
        return;
    }
    dis = new ::java::io::DataInputStream(new SocketInputBuffer_resetDis_1(this));
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::bytesRemaining()
{
    return UNKNOWN;
}

void org::mpisws::p2p::transport::util::SocketInputBuffer::reset()
{
    npc(readPtr)->clear();
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::size()
{
    return npc(writePtr)->position();
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::readInternal(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    auto bytesToRead = needBytes(len, false);
    npc(readPtr)->get(b, off, bytesToRead);
    return bytesToRead;
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::readInternal(::int8_tArray* b) /* throws(IOException) */
{
    auto bytesToRead = needBytes(npc(b)->length, false);
    npc(readPtr)->get(b, 0, bytesToRead);
    return bytesToRead;
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::readInternal() /* throws(IOException) */
{
    needBytes(1, true);
    return (npc(readPtr)->get() & int32_t(255));
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    return npc(dis)->read(b, off, len);
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::read(::int8_tArray* b) /* throws(IOException) */
{
    return npc(dis)->read(b);
}

int8_t org::mpisws::p2p::transport::util::SocketInputBuffer::readByte() /* throws(IOException) */
{
    return npc(dis)->readByte();
}

bool org::mpisws::p2p::transport::util::SocketInputBuffer::readBoolean() /* throws(IOException) */
{
    return npc(dis)->readBoolean();
}

char16_t org::mpisws::p2p::transport::util::SocketInputBuffer::readChar() /* throws(IOException) */
{
    return npc(dis)->readChar();
}

double org::mpisws::p2p::transport::util::SocketInputBuffer::readDouble() /* throws(IOException) */
{
    return npc(dis)->readDouble();
}

float org::mpisws::p2p::transport::util::SocketInputBuffer::readFloat() /* throws(IOException) */
{
    return npc(dis)->readFloat();
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::readInt() /* throws(IOException) */
{
    return npc(dis)->readInt();
}

int64_t org::mpisws::p2p::transport::util::SocketInputBuffer::readLong() /* throws(IOException) */
{
    return npc(dis)->readLong();
}

int16_t org::mpisws::p2p::transport::util::SocketInputBuffer::readShort() /* throws(IOException) */
{
    return npc(dis)->readShort();
}

java::lang::String* org::mpisws::p2p::transport::util::SocketInputBuffer::readUTF() /* throws(IOException) */
{
    return npc(dis)->readUTF();
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::needBytes(int32_t num, bool fail) /* throws(IOException) */
{
    auto bytesToReadIntoCache = num - (npc(writePtr)->position() - npc(readPtr)->position());
    if(bytesToReadIntoCache > 0) {
        readBytesIntoCache(bytesToReadIntoCache);
    }
    auto ret = npc(writePtr)->position() - npc(readPtr)->position();
    if(ret > num)
        ret = num;

    if(fail && ret < num) {
        reset();
        throw new InsufficientBytesException(num, ret);
    }
    return ret;
}

int32_t org::mpisws::p2p::transport::util::SocketInputBuffer::readBytesIntoCache(int32_t num) /* throws(IOException) */
{
    ::java::nio::ByteBuffer* in;
    switch (num) {
    case int32_t(0):
        return 0;
    case int32_t(1):
        if(one == nullptr)
            one = ::java::nio::ByteBuffer::allocate(num);

        npc(one)->clear();
        in = one;
        break;
    case int32_t(2):
        if(two == nullptr)
            two = ::java::nio::ByteBuffer::allocate(num);

        npc(two)->clear();
        in = two;
        break;
    case int32_t(4):
        if(four == nullptr)
            four = ::java::nio::ByteBuffer::allocate(num);

        npc(four)->clear();
        in = four;
        break;
    case int32_t(8):
        if(eight == nullptr)
            eight = ::java::nio::ByteBuffer::allocate(num);

        npc(eight)->clear();
        in = eight;
        break;
    default:
        in = ::java::nio::ByteBuffer::allocate(num);
    }

    auto ret = static_cast< int32_t >(npc(socket)->read(in));
    if(ret == -int32_t(1))
        throw new ::org::mpisws::p2p::transport::ClosedChannelException(::java::lang::StringBuilder().append(u"Socket "_j)->append(static_cast< ::java::lang::Object* >(socket))
            ->append(u" is already closed. (during read)"_j)->toString());

    npc(in)->flip();
    while (npc(writePtr)->remaining() < ret) {
        grow();
    }
    npc(writePtr)->put(in);
    return ret;
}

void org::mpisws::p2p::transport::util::SocketInputBuffer::clear() /* throws(IOException) */
{
    if(npc(cache)->length > initialSize)
        cache = new ::int8_tArray(initialSize);

    readPtr = ::java::nio::ByteBuffer::wrap(cache);
    writePtr = ::java::nio::ByteBuffer::wrap(cache);
    resetDis();
}

void org::mpisws::p2p::transport::util::SocketInputBuffer::grow()
{
    auto newCache = new ::int8_tArray(npc(cache)->length);
    ::java::lang::System::arraycopy(cache, 0, newCache, 0, npc(cache)->length);
    auto newReadPtr = ::java::nio::ByteBuffer::wrap(newCache);
    auto newWritePtr = ::java::nio::ByteBuffer::wrap(newCache);
    npc(newReadPtr)->position(npc(readPtr)->position());
    npc(newWritePtr)->position(npc(writePtr)->position());
    cache = newCache;
    readPtr = newReadPtr;
    writePtr = newWritePtr;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::SocketInputBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.SocketInputBuffer", 47);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::util::SocketInputBuffer::getClass0()
{
    return class_();
}

