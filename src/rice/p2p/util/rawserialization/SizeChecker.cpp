// Generated from /pastry-2.1/src/rice/p2p/util/rawserialization/SizeChecker.java
#include <rice/p2p/util/rawserialization/SizeChecker.hpp>

#include <java/lang/Byte.hpp>
#include <java/lang/Character.hpp>
#include <java/lang/Double.hpp>
#include <java/lang/Float.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Short.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::rawserialization::SizeChecker::SizeChecker(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::rawserialization::SizeChecker::SizeChecker()
    : SizeChecker(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::rawserialization::SizeChecker::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::rawserialization::SizeChecker::init()
{
    count = int32_t(0);
}

int32_t rice::p2p::util::rawserialization::SizeChecker::bytesWritten()
{
    return count;
}

int32_t rice::p2p::util::rawserialization::SizeChecker::bytesRemaining()
{
    return -int32_t(1);
}

void rice::p2p::util::rawserialization::SizeChecker::write(::int8_tArray* b, int32_t off, int32_t len) /* throws(IOException) */
{
    count += len;
}

void rice::p2p::util::rawserialization::SizeChecker::writeBoolean(bool v) /* throws(IOException) */
{
    count++;
}

void rice::p2p::util::rawserialization::SizeChecker::writeByte(int8_t v) /* throws(IOException) */
{
    count += ::java::lang::Byte::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeChar(char16_t v) /* throws(IOException) */
{
    count += ::java::lang::Character::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeDouble(double v) /* throws(IOException) */
{
    count += ::java::lang::Double::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeFloat(float v) /* throws(IOException) */
{
    count += ::java::lang::Float::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeInt(int32_t v) /* throws(IOException) */
{
    count += ::java::lang::Integer::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeLong(int64_t v) /* throws(IOException) */
{
    count += ::java::lang::Long::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeShort(int16_t v) /* throws(IOException) */
{
    count += ::java::lang::Short::SIZE / int32_t(8);
}

void rice::p2p::util::rawserialization::SizeChecker::writeUTF(::java::lang::String* str) /* throws(IOException) */
{
    count += npc(str)->length();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::rawserialization::SizeChecker::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.rawserialization.SizeChecker", 42);
    return c;
}

java::lang::Class* rice::p2p::util::rawserialization::SizeChecker::getClass0()
{
    return class_();
}

