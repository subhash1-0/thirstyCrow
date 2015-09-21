// Generated from /pastry-2.1/src/rice/p2p/util/testing/SecurityUtilsUnit.java
#include <rice/p2p/util/testing/SecurityUtilsUnit.hpp>

#include <java/io/PrintStream.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/security/KeyPair.hpp>
#include <java/security/PrivateKey.hpp>
#include <java/security/PublicKey.hpp>
#include <java/util/Arrays.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/SecurityUtils.hpp>
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

rice::p2p::util::testing::SecurityUtilsUnit::SecurityUtilsUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::SecurityUtilsUnit::SecurityUtilsUnit()
    : SecurityUtilsUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::SecurityUtilsUnit::main(::java::lang::StringArray* argv) /* throws(NoSuchAlgorithmException, IOException, ClassNotFoundException) */
{
    clinit();
    npc(::java::lang::System::out())->println(u"SecurityUtils Test Suite"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Initializing Tests"_j);
    npc(::java::lang::System::out())->print(u"    Generating key pairs\t\t\t\t"_j);
    auto pair = ::rice::p2p::util::SecurityUtils::generateKeyAsymmetric();
    auto pair2 = ::rice::p2p::util::SecurityUtils::generateKeyAsymmetric();
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->print(u"    Building cipher\t\t\t\t\t"_j);
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Running Tests"_j);
    npc(::java::lang::System::out())->print(u"    Testing serialization\t\t\t\t"_j);
    auto testString = u"test"_j;
    auto testStringByte = ::rice::p2p::util::SecurityUtils::serialize(testString);
    auto testStringOutput = java_cast< ::java::lang::String* >(::rice::p2p::util::SecurityUtils::deserialize(testStringByte));
    if(npc(testStringOutput)->equals(static_cast< ::java::lang::Object* >(testString))) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(testStringOutput)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing hashing\t\t\t\t\t"_j);
    auto testStringHash = ::rice::p2p::util::SecurityUtils::hash(testStringByte);
    if((testStringHash != nullptr) && (npc(testStringHash)->length == 20)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(static_cast< ::java::lang::Object* >(testStringHash))->toString());
        if(testStringHash != nullptr) {
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Length:\t"_j)->append(npc(testStringHash)->length)->toString());
        }
    }
    npc(::java::lang::System::out())->print(u"    Testing symmetric encryption\t\t\t"_j);
    auto key = ::rice::p2p::util::SecurityUtils::generateKeySymmetric();
    auto testStringCipherText = ::rice::p2p::util::SecurityUtils::encryptSymmetric(testStringByte, key);
    auto testStringPlainText = ::rice::p2p::util::SecurityUtils::decryptSymmetric(testStringCipherText, key);
    if(::java::util::Arrays::equals(testStringByte, testStringPlainText)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Length:\t"_j)->append(npc(testStringByte)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Cipher Len:\t"_j)->append(npc(testStringCipherText)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output Len:\t"_j)->append(npc(testStringPlainText)->length)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing signing and verification (phase 1)\t\t"_j);
    auto testStringSig = ::rice::p2p::util::SecurityUtils::sign(testStringByte, npc(pair)->getPrivate());
    if(::rice::p2p::util::SecurityUtils::verify(testStringByte, testStringSig, npc(pair)->getPublic())) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Length:\t"_j)->append(npc(testStringByte)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Sig Len:\t"_j)->append(npc(testStringSig)->length)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing signing and verification (phase 2)\t\t"_j);
    (*testStringSig)[int32_t(0)]++;
    if(!::rice::p2p::util::SecurityUtils::verify(testStringByte, testStringSig, npc(pair)->getPublic())) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Length:\t"_j)->append(npc(testStringByte)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Sig Len:\t"_j)->append(npc(testStringSig)->length)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing asymmetric encryption\t\t\t"_j);
    auto testStringEncrypted = ::rice::p2p::util::SecurityUtils::encryptAsymmetric(testStringByte, npc(pair)->getPublic());
    auto testStringDecrypted = ::rice::p2p::util::SecurityUtils::decryptAsymmetric(testStringEncrypted, npc(pair)->getPrivate());
    if(::java::util::Arrays::equals(testStringByte, testStringDecrypted)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Length:\t"_j)->append(npc(testStringByte)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Enc Len:\t"_j)->append(npc(testStringEncrypted)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Dec Len:\t"_j)->append(npc(testStringDecrypted)->length)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing hmac algorithm\t\t\t\t"_j);
    auto hmacText = u"<1896.697170952@postoffice.reston.mci.net>"_j;
    auto hmacKey = u"tanstaaftanstaaf"_j;
    auto hmac = ::rice::p2p::util::SecurityUtils::hmac(npc(hmacKey)->getBytes(), npc(hmacText)->getBytes());
    auto hmacResult = new ::int8_tArray({
        static_cast< int8_t >(int32_t(185))
        , static_cast< int8_t >(int32_t(19))
        , static_cast< int8_t >(int32_t(166))
        , static_cast< int8_t >(int32_t(2))
        , static_cast< int8_t >(int32_t(199))
        , static_cast< int8_t >(int32_t(237))
        , static_cast< int8_t >(int32_t(167))
        , static_cast< int8_t >(int32_t(164))
        , static_cast< int8_t >(int32_t(149))
        , static_cast< int8_t >(int32_t(180))
        , static_cast< int8_t >(int32_t(230))
        , static_cast< int8_t >(int32_t(231))
        , static_cast< int8_t >(int32_t(51))
        , static_cast< int8_t >(int32_t(77))
        , static_cast< int8_t >(int32_t(56))
        , static_cast< int8_t >(int32_t(144))
    });
    if(::java::util::Arrays::equals(hmac, hmacResult)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(hmacText)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Key: \t"_j)->append(hmacKey)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Res Len:\t"_j)->append(npc(hmac)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Real Len:\t"_j)->append(npc(hmacResult)->length)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing hmac algorithm again\t\t\t"_j);
    auto hmacText2 = u"<1080369447214@The-Edge.local>"_j;
    auto hmacKey2 = u"monkey"_j;
    auto hmac2 = ::rice::p2p::util::SecurityUtils::hmac(npc(hmacKey2)->getBytes(), npc(hmacText2)->getBytes());
    auto hmacResult2 = new ::int8_tArray({
        static_cast< int8_t >(int32_t(155))
        , static_cast< int8_t >(int32_t(174))
        , static_cast< int8_t >(int32_t(82))
        , static_cast< int8_t >(int32_t(239))
        , static_cast< int8_t >(int32_t(85))
        , static_cast< int8_t >(int32_t(69))
        , static_cast< int8_t >(int32_t(36))
        , static_cast< int8_t >(int32_t(145))
        , static_cast< int8_t >(int32_t(54))
        , static_cast< int8_t >(int32_t(133))
        , static_cast< int8_t >(int32_t(116))
        , static_cast< int8_t >(int32_t(114))
        , static_cast< int8_t >(int32_t(33))
        , static_cast< int8_t >(int32_t(187))
        , static_cast< int8_t >(int32_t(132))
        , static_cast< int8_t >(int32_t(34))
    });
    if(::java::util::Arrays::equals(hmac2, hmacResult2)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(hmacText2)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Key: \t"_j)->append(hmacKey2)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Res Len:\t"_j)->append(npc(hmac2)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Real Len:\t"_j)->append(npc(hmacResult2)->length)->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing asymmetic symmetric key encryption\t\t"_j);
    auto keySym = ::rice::p2p::util::SecurityUtils::generateKeySymmetric();
    if(::java::util::Arrays::equals(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, npc(pair)->getPublic()), ::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, npc(pair2)->getPublic()))) {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(keySym))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output 1: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, npc(pair)->getPublic())))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output 2: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, npc(pair2)->getPublic())))->toString());
    } else {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    }
    npc(::java::lang::System::out())->print(u"    Testing asymmetic public writing\t\t\t"_j);
    auto k = ::rice::p2p::util::SecurityUtils::decodePublicKey(::rice::p2p::util::SecurityUtils::encodePublicKey(npc(pair)->getPublic()));
    if(!::java::util::Arrays::equals(npc(k)->getEncoded(), npc(npc(pair)->getPublic())->getEncoded())) {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"  Output 1: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, k)))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"     Res 1: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(::rice::p2p::util::SecurityUtils::decryptAsymmetric(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, k), npc(pair)->getPrivate())))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"  Output 2: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, npc(pair)->getPublic())))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"     Res 2: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(::rice::p2p::util::SecurityUtils::decryptAsymmetric(::rice::p2p::util::SecurityUtils::encryptAsymmetric(keySym, npc(pair)->getPublic()), npc(pair)->getPrivate())))->toString());
    } else {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    }
    npc(::java::lang::System::out())->print(u"    Testing asymmetic private writing\t\t\t"_j);
    auto k2 = ::rice::p2p::util::SecurityUtils::decodePrivateKey(::rice::p2p::util::SecurityUtils::encodePrivateKey(npc(pair)->getPrivate()));
    if(!::java::util::Arrays::equals(::rice::p2p::util::SecurityUtils::sign(keySym, k2), ::rice::p2p::util::SecurityUtils::sign(keySym, npc(pair)->getPrivate()))) {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"  Output 1: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(npc(k2)->getEncoded()))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"  Output 2: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(npc(npc(pair)->getPrivate())->getEncoded()))->toString());
    } else {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    }
    npc(::java::lang::System::out())->print(u"    Testing asymmetic serialized writing\t\t"_j);
    testStringEncrypted = ::rice::p2p::util::SecurityUtils::encryptAsymmetric(testStringByte, k);
    testStringDecrypted = ::rice::p2p::util::SecurityUtils::decryptAsymmetric(testStringEncrypted, npc(pair)->getPrivate());
    if(::java::util::Arrays::equals(testStringByte, testStringDecrypted)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(testString)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Length:\t"_j)->append(npc(testStringByte)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Enc Len:\t"_j)->append(npc(testStringEncrypted)->length)->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Dec Len:\t"_j)->append(npc(testStringDecrypted)->length)->toString());
    }
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::SecurityUtilsUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.SecurityUtilsUnit", 39);
    return c;
}

java::lang::Class* rice::p2p::util::testing::SecurityUtilsUnit::getClass0()
{
    return class_();
}

