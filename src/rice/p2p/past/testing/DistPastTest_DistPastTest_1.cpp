// Generated from /pastry-2.1/src/rice/p2p/past/testing/DistPastTest.java
#include <rice/p2p/past/testing/DistPastTest_DistPastTest_1.hpp>

#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/p2p/past/testing/DistPastTest.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::Boolean, ObjectArray, ::java::io::SerializableArray, ComparableArray > BooleanArray;
    } // lang
} // java

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

rice::p2p::past::testing::DistPastTest_DistPastTest_1::DistPastTest_DistPastTest_1(DistPastTest *DistPastTest_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , DistPastTest_this(DistPastTest_this)
{
    clinit();
    ctor();
}

void rice::p2p::past::testing::DistPastTest_DistPastTest_1::receiveResult(::java::lang::Object* result)
{
    auto results = (java_cast< ::java::lang::BooleanArray* >(result));
    for (auto ctr = int32_t(0); ctr < npc(results)->length; ctr++) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"got "_j)->append(npc((*results)[ctr])->booleanValue())->toString());
    }
}

void rice::p2p::past::testing::DistPastTest_DistPastTest_1::receiveException(::java::lang::Exception* result)
{
    npc(result)->printStackTrace();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::past::testing::DistPastTest_DistPastTest_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* rice::p2p::past::testing::DistPastTest_DistPastTest_1::getClass0()
{
    return class_();
}

