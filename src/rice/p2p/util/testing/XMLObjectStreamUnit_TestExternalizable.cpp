// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestExternalizable.hpp>

#include <java/io/ObjectInput.hpp>
#include <java/io/ObjectOutput.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::XMLObjectStreamUnit_TestExternalizable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::XMLObjectStreamUnit_TestExternalizable()
    : XMLObjectStreamUnit_TestExternalizable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::init()
{
    num = int32_t(199);
}

int32_t rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::getNum()
{
    return num;
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::writeExternal(::java::io::ObjectOutput* o) /* throws(IOException) */
{
    npc(o)->writeInt(num + int32_t(100));
    npc(o)->writeInt(2000);
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::readExternal(::java::io::ObjectInput* i) /* throws(IOException, ClassNotFoundException) */
{
    num = npc(i)->readInt();
    npc(i)->readInt();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestExternalizable", 60);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestExternalizable::getClass0()
{
    return class_();
}

