// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestUnreadData.hpp>

#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/Vector.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::XMLObjectStreamUnit_TestUnreadData(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::XMLObjectStreamUnit_TestUnreadData()
    : XMLObjectStreamUnit_TestUnreadData(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::init()
{
    num = int32_t(293);
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    npc(oos)->defaultWriteObject();
    npc(oos)->writeInt(int32_t(10));
    npc(oos)->writeObject(static_cast< ::java::lang::Object* >(u"niondco"_j));
    npc(oos)->writeObject(static_cast< ::java::lang::Object* >(new ::java::util::Vector()));
}

int32_t rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::getNum()
{
    return num;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestUnreadData", 56);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestUnreadData::getClass0()
{
    return class_();
}

