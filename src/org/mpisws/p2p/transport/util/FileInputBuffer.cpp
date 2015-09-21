// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/util/FileInputBuffer.java
#include <org/mpisws/p2p/transport/util/FileInputBuffer.hpp>

#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <rice/environment/logging/Logger.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::util::FileInputBuffer::FileInputBuffer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::util::FileInputBuffer::FileInputBuffer(::java::io::File* f, ::rice::environment::logging::Logger* logger)  /* throws(FileNotFoundException) */
    : FileInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(f,logger);
}

org::mpisws::p2p::transport::util::FileInputBuffer::FileInputBuffer(::java::lang::String* fileName, ::rice::environment::logging::Logger* logger)  /* throws(FileNotFoundException) */
    : FileInputBuffer(*static_cast< ::default_init_tag* >(0))
{
    ctor(fileName,logger);
}

void org::mpisws::p2p::transport::util::FileInputBuffer::ctor(::java::io::File* f, ::rice::environment::logging::Logger* logger) /* throws(FileNotFoundException) */
{
    super::ctor(new ::java::io::FileInputStream(f));
    this->file = f;
}

void org::mpisws::p2p::transport::util::FileInputBuffer::ctor(::java::lang::String* fileName, ::rice::environment::logging::Logger* logger) /* throws(FileNotFoundException) */
{
    ctor(new ::java::io::File(fileName), logger);
}

int32_t org::mpisws::p2p::transport::util::FileInputBuffer::bytesRemaining()
{
    try {
        return this->available();
    } catch (::java::io::IOException* ioe) {
        if(npc(logger)->level <= ::rice::environment::logging::Logger::WARNING)
            npc(logger)->logException(::java::lang::StringBuilder().append(u"error getting available bytes for "_j)->append(static_cast< ::java::lang::Object* >(this))
                ->append(u"."_j)->toString(), ioe);

        return -int32_t(1);
    }
}

java::lang::String* org::mpisws::p2p::transport::util::FileInputBuffer::toString()
{
    return ::java::lang::StringBuilder().append(u"FIB{"_j)->append(static_cast< ::java::lang::Object* >(file))
        ->append(u"}"_j)->toString();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::util::FileInputBuffer::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.util.FileInputBuffer", 45);
    return c;
}

int32_t org::mpisws::p2p::transport::util::FileInputBuffer::read(::int8_tArray* b)
{
    return DataInputStream::read(b);
}

int32_t org::mpisws::p2p::transport::util::FileInputBuffer::read(::int8_tArray* b, int32_t off, int32_t len)
{
    return DataInputStream::read(b, off, len);
}

bool org::mpisws::p2p::transport::util::FileInputBuffer::readBoolean()
{
    return DataInputStream::readBoolean();
}

int8_t org::mpisws::p2p::transport::util::FileInputBuffer::readByte()
{
    return DataInputStream::readByte();
}

char16_t org::mpisws::p2p::transport::util::FileInputBuffer::readChar()
{
    return DataInputStream::readChar();
}

double org::mpisws::p2p::transport::util::FileInputBuffer::readDouble()
{
    return DataInputStream::readDouble();
}

float org::mpisws::p2p::transport::util::FileInputBuffer::readFloat()
{
    return DataInputStream::readFloat();
}

int32_t org::mpisws::p2p::transport::util::FileInputBuffer::readInt()
{
    return DataInputStream::readInt();
}

int64_t org::mpisws::p2p::transport::util::FileInputBuffer::readLong()
{
    return DataInputStream::readLong();
}

int16_t org::mpisws::p2p::transport::util::FileInputBuffer::readShort()
{
    return DataInputStream::readShort();
}

java::lang::String* org::mpisws::p2p::transport::util::FileInputBuffer::readUTF()
{
    return DataInputStream::readUTF();
}

java::lang::String* org::mpisws::p2p::transport::util::FileInputBuffer::readUTF(::java::io::DataInput* arg0)
{
    return super::readUTF(arg0);
}

int32_t org::mpisws::p2p::transport::util::FileInputBuffer::read()
{
    return super::read();
}

java::lang::Class* org::mpisws::p2p::transport::util::FileInputBuffer::getClass0()
{
    return class_();
}

