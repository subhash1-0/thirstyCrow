// Generated from /pastry-2.1/src/rice/p2p/util/RandomAccessFileIOBuffer.java
#include <rice/p2p/util/RandomAccessFileIOBuffer.hpp>

#include <java/lang/Integer.hpp>

rice::p2p::util::RandomAccessFileIOBuffer::RandomAccessFileIOBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::RandomAccessFileIOBuffer::RandomAccessFileIOBuffer(::java::io::File* file, ::java::lang::String* mode)  /* throws(FileNotFoundException) */
    : RandomAccessFileIOBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(file,mode);
}

rice::p2p::util::RandomAccessFileIOBuffer::RandomAccessFileIOBuffer(::java::lang::String* name, ::java::lang::String* mode)  /* throws(FileNotFoundException) */
    : RandomAccessFileIOBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(name,mode);
}

void rice::p2p::util::RandomAccessFileIOBuffer::ctor(::java::io::File* file, ::java::lang::String* mode) /* throws(FileNotFoundException) */
{
    super::ctor(file, mode);
}

void rice::p2p::util::RandomAccessFileIOBuffer::ctor(::java::lang::String* name, ::java::lang::String* mode) /* throws(FileNotFoundException) */
{
    super::ctor(name, mode);
}

int32_t rice::p2p::util::RandomAccessFileIOBuffer::bytesRemaining()
{
    return ::java::lang::Integer::MAX_VALUE;
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeByte(int8_t v) /* throws(IOException) */
{
    this->write(static_cast< int32_t >(v));
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeChar(char16_t v) /* throws(IOException) */
{
    writeChar(static_cast< int32_t >(v));
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeShort(int16_t v) /* throws(IOException) */
{
    writeShort(static_cast< int32_t >(v));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::RandomAccessFileIOBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.RandomAccessFileIOBuffer", 38);
    return c;
}

int32_t rice::p2p::util::RandomAccessFileIOBuffer::read(::int8_tArray* b)
{
    return RandomAccessFile::read(b);
}

int32_t rice::p2p::util::RandomAccessFileIOBuffer::read(::int8_tArray* b, int32_t off, int32_t len)
{
    return RandomAccessFile::read(b, off, len);
}

bool rice::p2p::util::RandomAccessFileIOBuffer::readBoolean()
{
    return RandomAccessFile::readBoolean();
}

int8_t rice::p2p::util::RandomAccessFileIOBuffer::readByte()
{
    return RandomAccessFile::readByte();
}

char16_t rice::p2p::util::RandomAccessFileIOBuffer::readChar()
{
    return RandomAccessFile::readChar();
}

double rice::p2p::util::RandomAccessFileIOBuffer::readDouble()
{
    return RandomAccessFile::readDouble();
}

float rice::p2p::util::RandomAccessFileIOBuffer::readFloat()
{
    return RandomAccessFile::readFloat();
}

int32_t rice::p2p::util::RandomAccessFileIOBuffer::readInt()
{
    return RandomAccessFile::readInt();
}

int64_t rice::p2p::util::RandomAccessFileIOBuffer::readLong()
{
    return RandomAccessFile::readLong();
}

int16_t rice::p2p::util::RandomAccessFileIOBuffer::readShort()
{
    return RandomAccessFile::readShort();
}

java::lang::String* rice::p2p::util::RandomAccessFileIOBuffer::readUTF()
{
    return RandomAccessFile::readUTF();
}

void rice::p2p::util::RandomAccessFileIOBuffer::write(::int8_tArray* b, int32_t off, int32_t len)
{
    RandomAccessFile::write(b, off, len);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeBoolean(bool v)
{
    RandomAccessFile::writeBoolean(v);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeDouble(double v)
{
    RandomAccessFile::writeDouble(v);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeFloat(float v)
{
    RandomAccessFile::writeFloat(v);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeInt(int32_t v)
{
    RandomAccessFile::writeInt(v);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeLong(int64_t v)
{
    RandomAccessFile::writeLong(v);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeUTF(::java::lang::String* str)
{
    RandomAccessFile::writeUTF(str);
}

int32_t rice::p2p::util::RandomAccessFileIOBuffer::read()
{
    return super::read();
}

void rice::p2p::util::RandomAccessFileIOBuffer::write(int32_t arg0)
{
    super::write(arg0);
}

void rice::p2p::util::RandomAccessFileIOBuffer::write(::int8_tArray* arg0)
{
    super::write(arg0);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeByte(int32_t arg0)
{
    super::writeByte(arg0);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeChar(int32_t arg0)
{
    super::writeChar(arg0);
}

void rice::p2p::util::RandomAccessFileIOBuffer::writeShort(int32_t arg0)
{
    super::writeShort(arg0);
}

java::lang::Class* rice::p2p::util::RandomAccessFileIOBuffer::getClass0()
{
    return class_();
}

