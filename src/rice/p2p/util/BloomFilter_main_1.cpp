// Generated from /pastry-2.1/src/rice/p2p/util/BloomFilter.java
#include <rice/p2p/util/BloomFilter_main_1.hpp>

#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/DataOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::BloomFilter_main_1::BloomFilter_main_1(::java::io::ByteArrayOutputStream* baos)
    : super(*static_cast< ::default_init_tag* >(0))
    , baos(baos)
{
    clinit();
    init();
    ctor();
}

void rice::p2p::util::BloomFilter_main_1::init()
{
    dos = new ::java::io::DataOutputStream(baos);
}

void rice::p2p::util::BloomFilter_main_1::writeInt(int32_t v) /* throws(IOException) */
{
    npc(dos)->writeInt(v);
}

void rice::p2p::util::BloomFilter_main_1::writeByte(int8_t v) /* throws(IOException) */
{
    npc(dos)->writeByte(static_cast< int32_t >(v));
}

java::io::ByteArrayOutputStream* rice::p2p::util::BloomFilter_main_1::getBaos()
{
    return baos;
}

int32_t rice::p2p::util::BloomFilter_main_1::bytesRemaining()
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeUTF(::java::lang::String* str) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeShort(int16_t v) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeLong(int64_t v) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeFloat(float v) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeDouble(double v) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeChar(char16_t v) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::writeBoolean(bool v) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

void rice::p2p::util::BloomFilter_main_1::write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    throw new ::java::lang::RuntimeException(u"Not Implemented."_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::BloomFilter_main_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::util::BloomFilter_main_1::getClass0()
{
    return class_();
}

