// Generated from /pastry-2.1/src/rice/p2p/util/testing/XMLObjectStreamUnit.java
#include <rice/p2p/util/testing/XMLObjectStreamUnit_TestSerialPersistentFields.hpp>

#include <java/io/ObjectStreamField.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Class.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/String.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
    } // lang

    namespace io
    {
typedef ::SubArray< ::java::io::ObjectStreamField, ::java::lang::ObjectArray, ::java::lang::ComparableArray > ObjectStreamFieldArray;
    } // io
} // java

rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::XMLObjectStreamUnit_TestSerialPersistentFields(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::XMLObjectStreamUnit_TestSerialPersistentFields()
    : XMLObjectStreamUnit_TestSerialPersistentFields(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::ctor()
{
    super::ctor();
    init();
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::init()
{
    num1 = new ::java::lang::Integer(int32_t(1));
    num2 = new ::java::lang::Integer(int32_t(2));
}

java::io::ObjectStreamFieldArray*& rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::serialPersistentFields()
{
    clinit();
    return serialPersistentFields_;
}
java::io::ObjectStreamFieldArray* rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::serialPersistentFields_;

java::lang::Integer* rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::getNum1()
{
    return num1;
}

java::lang::Integer* rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::getNum2()
{
    return num2;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.XMLObjectStreamUnit.TestSerialPersistentFields", 68);
    return c;
}

void rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        serialPersistentFields_ = (new ::java::io::ObjectStreamFieldArray({new ::java::io::ObjectStreamField(u"num1"_j, ::java::lang::Integer::class_())}));
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* rice::p2p::util::testing::XMLObjectStreamUnit_TestSerialPersistentFields::getClass0()
{
    return class_();
}

