// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestPutFields.hpp>

#include <java/io/IOException.hpp>
#include <java/io/ObjectInputStream_GetField.hpp>
#include <java/io/ObjectInputStream.hpp>
#include <java/io/ObjectOutputStream_PutField.hpp>
#include <java/io/ObjectOutputStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::XMLObjectStreamUnit_TestPutFields(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::XMLObjectStreamUnit_TestPutFields()
    : XMLObjectStreamUnit_TestPutFields(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::init()
{
    num = int32_t(0);
    num2 = nullptr;
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::writeObject(::java::io::ObjectOutputStream* oos) /* throws(IOException) */
{
    auto pf = npc(oos)->putFields();
    npc(pf)->put(u"num"_j, int32_t(10001));
    npc(pf)->put(u"num2"_j, static_cast< ::java::lang::Object* >(new ::java::lang::Integer(int32_t(99))));
    npc(pf)->put(u"blah"_j, int32_t(100));
    npc(oos)->writeFields();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::readObject(::java::io::ObjectInputStream* ois) /* throws(IOException, ClassNotFoundException) */
{
    auto gf = npc(ois)->readFields();
    num = npc(gf)->get(u"num"_j, int32_t(0));
    num2 = java_cast< ::java::lang::Integer* >(npc(gf)->get(u"num2"_j, static_cast< ::java::lang::Object* >(new ::java::lang::Integer(int32_t(0)))));
    npc(gf)->get(u"blah"_j, int32_t(0));
    if(!npc(gf)->defaulted(u"monkey"_j))
        throw new ::java::io::IOException(u"Field monkey was not defaulted!"_j);

    if(npc(gf)->defaulted(u"num"_j))
        throw new ::java::io::IOException(u"Field num was defaulted!"_j);

    if(npc(gf)->defaulted(u"num2"_j))
        throw new ::java::io::IOException(u"Field num was defaulted!"_j);

}

int32_t rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::getNum()
{
    return num;
}

int32_t rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::getNum2()
{
    return npc(num2)->intValue();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestPutFields", 55);
    return c;
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestPutFields::getClass0()
{
    return class_();
}

