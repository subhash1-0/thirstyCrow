// Generated from /pastry-2.1/src/rice/p2p/util/BloomFilter.java
#include <rice/p2p/util/BloomFilter_main_2.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/DataInputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::BloomFilter_main_2::BloomFilter_main_2(::java::io::ByteArrayInputStream* bais)
    : super(*static_cast< ::default_init_tag* >(0))
    , bais(bais)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::util::BloomFilter_main_2::init()
{
    dis = new ::java::io::DataInputStream(bais);
}

int32_t rice::p2p::util::BloomFilter_main_2::readInt() /* throws(IOException) */
{
    return npc(dis)->readInt();
}

int8_t rice::p2p::util::BloomFilter_main_2::readByte() /* throws(IOException) */
{
    return npc(dis)->readByte();
}

int32_t rice::p2p::util::BloomFilter_main_2::bytesRemaining()
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

java::lang::String* rice::p2p::util::BloomFilter_main_2::readUTF() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

int16_t rice::p2p::util::BloomFilter_main_2::readShort() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

int16_t rice::p2p::util::BloomFilter_main_2::peakShort() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

int64_t rice::p2p::util::BloomFilter_main_2::readLong() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

float rice::p2p::util::BloomFilter_main_2::readFloat() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

double rice::p2p::util::BloomFilter_main_2::readDouble() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

char16_t rice::p2p::util::BloomFilter_main_2::readChar() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

bool rice::p2p::util::BloomFilter_main_2::readBoolean() /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

int32_t rice::p2p::util::BloomFilter_main_2::read(::int8_tArray* b) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

int32_t rice::p2p::util::BloomFilter_main_2::read(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::BloomFilter_main_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::BloomFilter_main_2::getClass0()
{
    return class_();
}

