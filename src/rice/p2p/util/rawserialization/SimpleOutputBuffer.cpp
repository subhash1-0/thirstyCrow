// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/SimpleOutputBuffer.java
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/OutputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
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

rice::p2p::util::rawserialization::SimpleOutputBuffer::SimpleOutputBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::SimpleOutputBuffer::SimpleOutputBuffer(int32_t size) 
    : SimpleOutputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(size);
}

rice::p2p::util::rawserialization::SimpleOutputBuffer::SimpleOutputBuffer() 
    : SimpleOutputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::ctor(int32_t size)
{
    super::ctor(new ::java::io::ByteArrayOutputStream(size));
    baos = java_cast< ::java::io::ByteArrayOutputStream* >(out);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::ctor()
{
    super::ctor(new ::java::io::ByteArrayOutputStream());
    baos = java_cast< ::java::io::ByteArrayOutputStream* >(out);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeByte(int8_t v) /* throws(IOException) */
{
    this->write(static_cast< int32_t >(v));
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeChar(char16_t v) /* throws(IOException) */
{
    writeChar(static_cast< int32_t >(v));
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeShort(int16_t v) /* throws(IOException) */
{
    writeShort(static_cast< int32_t >(v));
}

int32_t rice::p2p::util::rawserialization::SimpleOutputBuffer::bytesRemaining()
{
    return ::java::lang::Integer::MAX_VALUE;
}

int8_tArray* rice::p2p::util::rawserialization::SimpleOutputBuffer::getBytes()
{
    return npc(baos)->toByteArray_();
}

java::nio::ByteBuffer* rice::p2p::util::rawserialization::SimpleOutputBuffer::getByteBuffer()
{
    return ::java::nio::ByteBuffer::wrap(getBytes());
}

int32_t rice::p2p::util::rawserialization::SimpleOutputBuffer::getWritten()
{
    return written;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::SimpleOutputBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.SimpleOutputBuffer", 49);
    return c;
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::write(::int8_tArray* b, int32_t off, int32_t len)
{
    DataOutputStream::write(b, off, len);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeBoolean(bool v)
{
    DataOutputStream::writeBoolean(v);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeDouble(double v)
{
    DataOutputStream::writeDouble(v);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeFloat(float v)
{
    DataOutputStream::writeFloat(v);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeInt(int32_t v)
{
    DataOutputStream::writeInt(v);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeLong(int64_t v)
{
    DataOutputStream::writeLong(v);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeUTF(::java::lang::String* str)
{
    DataOutputStream::writeUTF(str);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::write(int32_t arg0)
{
    super::write(arg0);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeByte(int32_t arg0)
{
    super::writeByte(arg0);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeChar(int32_t arg0)
{
    super::writeChar(arg0);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::writeShort(int32_t arg0)
{
    super::writeShort(arg0);
}

int32_t rice::p2p::util::rawserialization::SimpleOutputBuffer::writeUTF(::java::lang::String* arg0, ::java::io::DataOutput* arg1)
{
    return super::writeUTF(arg0, arg1);
}

void rice::p2p::util::rawserialization::SimpleOutputBuffer::write(::int8_tArray* b)
{
    super::write(b);
}

java::lang::Class* rice::p2p::util::rawserialization::SimpleOutputBuffer::getClass0()
{
    return class_();
}

