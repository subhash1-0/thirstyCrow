// Generated from /pastry-2.1/src/rice/p2p/util/testing/MathUtilsUnit.java
#include <rice/p2p/util/testing/MathUtilsUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/Long.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <Array.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::MathUtilsUnit::MathUtilsUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::MathUtilsUnit::MathUtilsUnit()
    : MathUtilsUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::MathUtilsUnit::main(::java::lang::StringArray* args)
{
    clinit();
    npc(::java::lang::System::out())->println(u"MathUtils Test Suite"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Running Tests"_j);
    npc(::java::lang::System::out())->print(u"    Testing hexadecimal conversion\t\t\t"_j);
    auto testHexBytes = new ::int8_tArray({
        static_cast< int8_t >(int32_t(167))
        , static_cast< int8_t >(int32_t(179))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(18))
        , static_cast< int8_t >(int32_t(78))
    });
    auto result = ::rice::p2p::util::MathUtils::toHex(testHexBytes);
    if(npc(result)->equals(static_cast< ::java::lang::Object* >(u"a7b300124e"_j))) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(static_cast< ::java::lang::Object* >(testHexBytes))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(result)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing long conversion\t\t\t\t"_j);
    auto testLong = ::java::lang::Long::parseLong(u"0123456789ABCDEF"_j, 16);
    auto testLongByte = ::rice::p2p::util::MathUtils::longToByteArray_(testLong);
    if(((*testLongByte)[int32_t(0)] == static_cast< int8_t >(int32_t(1))) && ((*testLongByte)[int32_t(1)] == static_cast< int8_t >(int32_t(35))) && ((*testLongByte)[int32_t(2)] == static_cast< int8_t >(int32_t(69)))&& ((*testLongByte)[int32_t(3)] == static_cast< int8_t >(int32_t(103)))&& ((*testLongByte)[int32_t(4)] == static_cast< int8_t >(int32_t(137)))&& ((*testLongByte)[int32_t(5)] == static_cast< int8_t >(int32_t(171)))&& ((*testLongByte)[int32_t(6)] == static_cast< int8_t >(int32_t(205)))&& ((*testLongByte)[int32_t(7)] == static_cast< int8_t >(int32_t(239)))) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testLong)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append((*testLongByte)[int32_t(0)])
            ->append(u" "_j)
            ->append((*testLongByte)[int32_t(1)])
            ->append(u" "_j)
            ->append((*testLongByte)[int32_t(2)])
            ->append(u" "_j)
            ->append((*testLongByte)[int32_t(3)])->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing int->byte[]->int conversion\t\t\t"_j);
    ::rice::environment::random::RandomSource* r = new ::rice::environment::random::simple::SimpleRandomSource(nullptr);
    auto passed = true;
    for (auto n = int32_t(0); n < 100000; n++) {
        auto l = npc(r)->nextInt();
        auto ar = ::rice::p2p::util::MathUtils::intToByteArray_(l);
        auto res = ::rice::p2p::util::MathUtils::byteArrayToInt(ar);
        if(res != l) {
            passed = false;
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"input:  "_j)->append(l)->toString());
            npc(::java::lang::System::out())->print(u"byte[]: "_j);
            for (auto i = int32_t(0); i < npc(ar)->length; i++) {
                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append((*ar)[i])->append(u" "_j)->toString());
            }
            npc(::java::lang::System::out())->println();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"output: "_j)->append(result)->toString());
            break;
        }
    }
    if(passed)
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);

    npc(::java::lang::System::out())->print(u"    Testing long->byte[]->long conversion\t\t\t"_j);
    passed = true;
    for (auto n = int32_t(0); n < 100000; n++) {
        auto l = npc(r)->nextLong();
        auto ar = ::rice::p2p::util::MathUtils::longToByteArray_(l);
        auto res = ::rice::p2p::util::MathUtils::byteArrayToLong(ar);
        if(res != l) {
            passed = false;
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"input:  "_j)->append(l)->toString());
            npc(::java::lang::System::out())->print(u"byte[]: "_j);
            for (auto i = int32_t(0); i < npc(ar)->length; i++) {
                npc(::java::lang::System::out())->print(::java::lang::StringBuilder().append((*ar)[i])->append(u" "_j)->toString());
            }
            npc(::java::lang::System::out())->println();
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"output: "_j)->append(result)->toString());
            break;
        }
    }
    if(passed)
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);

    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::MathUtilsUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.MathUtilsUnit", 35);
    return c;
}

java::lang::Class* rice::p2p::util::testing::MathUtilsUnit::getClass0()
{
    return class_();
}

