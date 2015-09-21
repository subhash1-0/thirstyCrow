// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestByteSerialization.hpp>

#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::XMLObjectStreamUnit_TestByteSerialization(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::XMLObjectStreamUnit_TestByteSerialization()
    : XMLObjectStreamUnit_TestByteSerialization(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::init()
{
    bytes_ = new ::int8_tArray({
        static_cast< int8_t >(int32_t(23))
        , static_cast< int8_t >(int32_t(19))
        , static_cast< int8_t >(int32_t(49))
        , static_cast< int8_t >(int32_t(0))
    });
}

int8_tArray* rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::bytes()
{
    return bytes_;
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::readObject(::java::io::ObjectInputStream* oos) /* throws(IOException, ClassNotFoundException) */
{
    bytes_ = new ::int8_tArray(int32_t(5));
    npc(oos)->read(bytes_, int32_t(0), int32_t(5));
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    npc(oos)->write(bytes_);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestByteSerialization", 63);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestByteSerialization::getClass0()
{
    return class_();
}

