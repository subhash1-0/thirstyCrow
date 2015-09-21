// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/SimpleInputBuffer.java
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/io/InputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <Array.hpp>

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

rice::p2p::util::rawserialization::SimpleInputBuffer::SimpleInputBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::SimpleInputBuffer::SimpleInputBuffer(::java::nio::ByteBuffer* bb) 
    : SimpleInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(bb);
}

rice::p2p::util::rawserialization::SimpleInputBuffer::SimpleInputBuffer(::int8_tArray* bytes) 
    : SimpleInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(bytes);
}

rice::p2p::util::rawserialization::SimpleInputBuffer::SimpleInputBuffer(::int8_tArray* bytes, int32_t offset) 
    : SimpleInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(bytes,offset);
}

rice::p2p::util::rawserialization::SimpleInputBuffer::SimpleInputBuffer(::int8_tArray* bytes, int32_t offset, int32_t length) 
    : SimpleInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(bytes,offset,length);
}

void rice::p2p::util::rawserialization::SimpleInputBuffer::ctor(::java::nio::ByteBuffer* bb)
{
    ctor(npc(bb)->array(), npc(bb)->position(), npc(bb)->remaining());
}

void rice::p2p::util::rawserialization::SimpleInputBuffer::ctor(::int8_tArray* bytes)
{
    ctor(bytes, int32_t(0), npc(bytes)->length);
}

void rice::p2p::util::rawserialization::SimpleInputBuffer::ctor(::int8_tArray* bytes, int32_t offset)
{
    ctor(bytes, offset, npc(bytes)->length - offset);
}

void rice::p2p::util::rawserialization::SimpleInputBuffer::ctor(::int8_tArray* bytes, int32_t offset, int32_t length)
{
    super::ctor(new ::java::io::ByteArrayInputStream(bytes, offset, length));
    bais = java_cast< ::java::io::ByteArrayInputStream* >(this->in.load());
}

int32_t rice::p2p::util::rawserialization::SimpleInputBuffer::bytesRemaining()
{
    try {
        return this->available();
    } catch (::java::io::IOException* ioe) {
        npc(ioe)->printStackTrace();
    }
    return -int32_t(1);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::SimpleInputBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.SimpleInputBuffer", 48);
    return c;
}

int32_t rice::p2p::util::rawserialization::SimpleInputBuffer::read(::int8_tArray* b)
{
    return DataInputStream::read(b);
}

int32_t rice::p2p::util::rawserialization::SimpleInputBuffer::read(::int8_tArray* b, int32_t off, int32_t len)
{
    return DataInputStream::read(b, off, len);
}

bool rice::p2p::util::rawserialization::SimpleInputBuffer::readBoolean()
{
    return DataInputStream::readBoolean();
}

int8_t rice::p2p::util::rawserialization::SimpleInputBuffer::readByte()
{
    return DataInputStream::readByte();
}

char16_t rice::p2p::util::rawserialization::SimpleInputBuffer::readChar()
{
    return DataInputStream::readChar();
}

double rice::p2p::util::rawserialization::SimpleInputBuffer::readDouble()
{
    return DataInputStream::readDouble();
}

float rice::p2p::util::rawserialization::SimpleInputBuffer::readFloat()
{
    return DataInputStream::readFloat();
}

int32_t rice::p2p::util::rawserialization::SimpleInputBuffer::readInt()
{
    return DataInputStream::readInt();
}

int64_t rice::p2p::util::rawserialization::SimpleInputBuffer::readLong()
{
    return DataInputStream::readLong();
}

int16_t rice::p2p::util::rawserialization::SimpleInputBuffer::readShort()
{
    return DataInputStream::readShort();
}

java::lang::String* rice::p2p::util::rawserialization::SimpleInputBuffer::readUTF()
{
    return DataInputStream::readUTF();
}

java::lang::String* rice::p2p::util::rawserialization::SimpleInputBuffer::readUTF(::java::io::DataInput* arg0)
{
    return super::readUTF(arg0);
}

int32_t rice::p2p::util::rawserialization::SimpleInputBuffer::read()
{
    return super::read();
}

java::lang::Class* rice::p2p::util::rawserialization::SimpleInputBuffer::getClass0()
{
    return class_();
}

