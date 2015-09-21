// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/FileOutputBuffer.java
#include <org/mpisws/p2p/transport/util/FileOutputBuffer.hpp>

#include <java/io/FileOutputStream.hpp>
#include <java/lang/Integer.hpp>

org::mpisws::p2p::transport::util::FileOutputBuffer::FileOutputBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::FileOutputBuffer::FileOutputBuffer(::java::io::File* f, bool append)  /* throws(FileNotFoundException) */
    : FileOutputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(f,append);
}

org::mpisws::p2p::transport::util::FileOutputBuffer::FileOutputBuffer(::java::io::File* f)  /* throws(FileNotFoundException) */
    : FileOutputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(f);
}

org::mpisws::p2p::transport::util::FileOutputBuffer::FileOutputBuffer(::java::lang::String* fileName)  /* throws(FileNotFoundException) */
    : FileOutputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(fileName);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::ctor(::java::io::File* f, bool append) /* throws(FileNotFoundException) */
{
    super::ctor(new ::java::io::FileOutputStream(f, append));
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::ctor(::java::io::File* f) /* throws(FileNotFoundException) */
{
    super::ctor(new ::java::io::FileOutputStream(f));
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::ctor(::java::lang::String* fileName) /* throws(FileNotFoundException) */
{
    super::ctor(new ::java::io::FileOutputStream(fileName));
}

int32_t org::mpisws::p2p::transport::util::FileOutputBuffer::bytesRemaining()
{
    return ::java::lang::Integer::MAX_VALUE;
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeByte(int8_t v) /* throws(IOException) */
{
    this->write(static_cast< int32_t >(v));
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeChar(char16_t v) /* throws(IOException) */
{
    writeChar(static_cast< int32_t >(v));
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeShort(int16_t v) /* throws(IOException) */
{
    writeShort(static_cast< int32_t >(v));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::FileOutputBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.FileOutputBuffer", 46);
    return c;
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::write(::int8_tArray* b, int32_t off, int32_t len)
{
    DataOutputStream::write(b, off, len);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeBoolean(bool v)
{
    DataOutputStream::writeBoolean(v);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeDouble(double v)
{
    DataOutputStream::writeDouble(v);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeFloat(float v)
{
    DataOutputStream::writeFloat(v);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeInt(int32_t v)
{
    DataOutputStream::writeInt(v);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeLong(int64_t v)
{
    DataOutputStream::writeLong(v);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeUTF(::java::lang::String* str)
{
    DataOutputStream::writeUTF(str);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::write(int32_t arg0)
{
    super::write(arg0);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeByte(int32_t arg0)
{
    super::writeByte(arg0);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeChar(int32_t arg0)
{
    super::writeChar(arg0);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::writeShort(int32_t arg0)
{
    super::writeShort(arg0);
}

int32_t org::mpisws::p2p::transport::util::FileOutputBuffer::writeUTF(::java::lang::String* arg0, ::java::io::DataOutput* arg1)
{
    return super::writeUTF(arg0, arg1);
}

void org::mpisws::p2p::transport::util::FileOutputBuffer::write(::int8_tArray* arg0)
{
    super::write(arg0);
}

java::lang::Class* org::mpisws::p2p::transport::util::FileOutputBuffer::getClass0()
{
    return class_();
}

