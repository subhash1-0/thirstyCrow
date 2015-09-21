// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestSubExternalizable.hpp>

#include <java/io/ObjectInput.hpp>
#include <java/io/ObjectOutput.hpp>
#include <java/lang/IllegalArgumentException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::XMLObjectStreamUnit_TestSubExternalizable(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::XMLObjectStreamUnit_TestSubExternalizable(::java::lang::Object* o) 
    : XMLObjectStreamUnit_TestSubExternalizable(*static_cast< ::default_init_tag* >(0))
{
    ctor(o);
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::XMLObjectStreamUnit_TestSubExternalizable() 
    : XMLObjectStreamUnit_TestSubExternalizable(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::ctor(::java::lang::Object* o)
{
    super::ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::ctor()
{
    super::ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::writeExternal(::java::io::ObjectOutput* o) /* throws(IOException) */
{
    super::writeExternal(o);
    npc(o)->writeInt(1000);
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::readExternal(::java::io::ObjectInput* i) /* throws(IOException, ClassNotFoundException) */
{
    super::readExternal(i);
    num = npc(i)->readInt();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    throw new ::java::lang::IllegalArgumentException(u"READ OBJECT SHOULD NOT BE CALLED!"_j);
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    throw new ::java::lang::IllegalArgumentException(u"WRITE OBJECT SHOULD NOT BE CALLED!"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestSubExternalizable", 63);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestSubExternalizable::getClass0()
{
    return class_();
}

