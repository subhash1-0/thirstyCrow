// Generated from /pastry-2.1/src/rice/p2p/util/testing/EncryptedStreamUnit.java
#include <rice/p2p/util/testing/EncryptedStreamUnit.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/ByteArrayOutputStream.hpp>
#include <java/io/DataInputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/Cloneable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/SecurityException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/security/KeyPair.hpp>
#include <java/util/Arrays.hpp>
#include <rice/environment/random/RandomSource.hpp>
#include <rice/environment/random/simple/SimpleRandomSource.hpp>
#include <rice/p2p/util/EncryptedInputStream.hpp>
#include <rice/p2p/util/EncryptedOutputStream.hpp>
#include <rice/p2p/util/MathUtils.hpp>
#include <rice/p2p/util/SecurityUtils.hpp>
#include <Array.hpp>
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
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Cloneable, ObjectArray > CloneableArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

namespace 
{
typedef ::SubArray< ::int8_tArray, ::java::lang::CloneableArray, ::java::io::SerializableArray > int8_tArrayArray;
} // 

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

rice::p2p::util::testing::EncryptedStreamUnit::EncryptedStreamUnit(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

rice::p2p::util::testing::EncryptedStreamUnit::EncryptedStreamUnit()
    : EncryptedStreamUnit(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void rice::p2p::util::testing::EncryptedStreamUnit::main(::java::lang::StringArray* argv) /* throws(NoSuchAlgorithmException, IOException, ClassNotFoundException) */
{
    clinit();
    auto BUFFER_SIZE = int32_t(32678);
    npc(::java::lang::System::out())->println(u"EncryptedStream Test Suite"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Initializing Tests"_j);
    npc(::java::lang::System::out())->print(u"    Generating key pairs\t\t\t\t"_j);
    auto pair = ::rice::p2p::util::SecurityUtils::generateKeyAsymmetric();
    auto pair2 = ::rice::p2p::util::SecurityUtils::generateKeyAsymmetric();
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->print(u"    Generating random number generator\t\t\t"_j);
    ::rice::environment::random::RandomSource* r = new ::rice::environment::random::simple::SimpleRandomSource(nullptr);
    npc(::java::lang::System::out())->println(u"[ DONE ]"_j);
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
    npc(::java::lang::System::out())->println(u"  Running Tests"_j);
    npc(::java::lang::System::out())->print(u"    Testing Simple Encryption\t\t\t\t"_j);
    auto bytes = new ::int8_tArray({
        static_cast< int8_t >(int32_t(167))
        , static_cast< int8_t >(int32_t(179))
        , static_cast< int8_t >(int32_t(0))
        , static_cast< int8_t >(int32_t(18))
        , static_cast< int8_t >(int32_t(78))
    });
    auto baos = new ::java::io::ByteArrayOutputStream();
    auto eos = new ::rice::p2p::util::EncryptedOutputStream(npc(pair)->getPublic(), baos, BUFFER_SIZE);
    npc(eos)->write(bytes);
    npc(eos)->close();
    auto bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
    auto dis = new ::java::io::DataInputStream(new ::rice::p2p::util::EncryptedInputStream(npc(pair)->getPrivate(), bais));
    auto read = new ::int8_tArray(npc(bytes)->length);
    npc(dis)->readFully(read);
    if(::java::util::Arrays::equals(read, bytes)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(bytes))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(::rice::p2p::util::MathUtils::toHex(read))->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Multiple Encryption\t\t\t\t"_j);
    baos = new ::java::io::ByteArrayOutputStream();
    eos = new ::rice::p2p::util::EncryptedOutputStream(npc(pair)->getPublic(), baos, BUFFER_SIZE);
    npc(eos)->write(bytes);
    npc(eos)->write(bytes);
    npc(eos)->close();
    bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
    dis = new ::java::io::DataInputStream(new ::rice::p2p::util::EncryptedInputStream(npc(pair)->getPrivate(), bais));
    read = new ::int8_tArray(npc(bytes)->length);
    npc(dis)->readFully(read);
    auto read2 = new ::int8_tArray(npc(bytes)->length);
    npc(dis)->readFully(read2);
    if(::java::util::Arrays::equals(read, bytes) && ::java::util::Arrays::equals(read2, bytes)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(bytes))
            ->append(::rice::p2p::util::MathUtils::toHex(bytes))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(::rice::p2p::util::MathUtils::toHex(read))
            ->append(::rice::p2p::util::MathUtils::toHex(read2))->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Long Encryption\t\t\t\t"_j);
    baos = new ::java::io::ByteArrayOutputStream();
    eos = new ::rice::p2p::util::EncryptedOutputStream(npc(pair)->getPublic(), baos, BUFFER_SIZE);
    bytes = new ::int8_tArray(int32_t(128000));
    npc(r)->nextBytes(bytes);
    npc(eos)->write(bytes);
    npc(eos)->close();
    bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
    dis = new ::java::io::DataInputStream(new ::rice::p2p::util::EncryptedInputStream(npc(pair)->getPrivate(), bais));
    read = new ::int8_tArray(npc(bytes)->length);
    npc(dis)->readFully(read);
    if(::java::util::Arrays::equals(read, bytes)) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    } else {
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(bytes))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(::rice::p2p::util::MathUtils::toHex(read))->toString());
    }
    npc(::java::lang::System::out())->print(u"    Testing Incorrect Decryption\t\t\t"_j);
    baos = new ::java::io::ByteArrayOutputStream();
    eos = new ::rice::p2p::util::EncryptedOutputStream(npc(pair)->getPublic(), baos, BUFFER_SIZE);
    bytes = new ::int8_tArray(int32_t(128000));
    npc(r)->nextBytes(bytes);
    npc(eos)->write(bytes);
    npc(eos)->close();
    try {
        bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
        dis = new ::java::io::DataInputStream(new ::rice::p2p::util::EncryptedInputStream(npc(pair2)->getPrivate(), bais));
        read = new ::int8_tArray(npc(bytes)->length);
        npc(dis)->readFully(read);
        npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(bytes))->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(::rice::p2p::util::MathUtils::toHex(read))->toString());
    } catch (::java::lang::SecurityException* e) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    }
    npc(::java::lang::System::out())->print(u"    Testing Slow Decryption\t\t\t\t"_j);
    baos = new ::java::io::ByteArrayOutputStream();
    eos = new ::rice::p2p::util::EncryptedOutputStream(npc(pair)->getPublic(), baos, BUFFER_SIZE);
    bytes = new ::int8_tArray(int32_t(128000));
    npc(r)->nextBytes(bytes);
    npc(eos)->write(bytes);
    npc(eos)->close();
    bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
    dis = new ::java::io::DataInputStream(new ::rice::p2p::util::EncryptedInputStream(npc(pair)->getPrivate(), bais));
    read = new ::int8_tArray(int32_t(1000));
    auto c = int32_t(0);
    while (c < npc(bytes)->length) {
        npc(dis)->readFully(read);
        auto tmp = new ::int8_tArray(npc(read)->length);
        ::java::lang::System::arraycopy(bytes, c, tmp, 0, npc(read)->length);
        if(!::java::util::Arrays::equals(read, tmp)) {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Iteration: \t"_j)->append(c)->toString());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex(tmp))->toString());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(::rice::p2p::util::MathUtils::toHex(read))->toString());
            break;
        }
        c += npc(read)->length;
    }
    if(c >= npc(bytes)->length) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    }
    npc(::java::lang::System::out())->print(u"    Testing Randon Encryption\t\t\t\t"_j);
    baos = new ::java::io::ByteArrayOutputStream();
    eos = new ::rice::p2p::util::EncryptedOutputStream(npc(pair)->getPublic(), baos, BUFFER_SIZE);
    auto data = new ::int8_tArrayArray(int32_t(1000));
    for (auto i = int32_t(0); i < npc(data)->length; i++) {
        data->set(i, new ::int8_tArray(npc(r)->nextInt(594)));
        npc(r)->nextBytes((*data)[i]);
        npc(eos)->write((*data)[i]);
    }
    npc(eos)->close();
    bais = new ::java::io::ByteArrayInputStream(npc(baos)->toByteArray_());
    dis = new ::java::io::DataInputStream(new ::rice::p2p::util::EncryptedInputStream(npc(pair)->getPrivate(), bais));
    auto j = int32_t(0);
    for (j = 0; j < npc(data)->length; j++) {
        read = new ::int8_tArray(npc((*data)[j])->length);
        npc(dis)->readFully(read);
        if(!::java::util::Arrays::equals(read, (*data)[j])) {
            npc(::java::lang::System::out())->println(u"[ FAILED ]"_j);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Iteration: \t"_j)->append(c)->toString());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Input: \t"_j)->append(::rice::p2p::util::MathUtils::toHex((*data)[j]))->toString());
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"    Output:\t"_j)->append(::rice::p2p::util::MathUtils::toHex(read))->toString());
            break;
        }
    }
    if(j == npc(data)->length) {
        npc(::java::lang::System::out())->println(u"[ PASSED ]"_j);
    }
    npc(::java::lang::System::out())->println(u"-------------------------------------------------------------"_j);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* rice::p2p::util::testing::EncryptedStreamUnit::class_()
{
    static ::java::lang::Class* c = ::class_(u"rice.p2p.util.testing.EncryptedStreamUnit", 41);
    return c;
}

java::lang::Class* rice::p2p::util::testing::EncryptedStreamUnit::getClass0()
{
    return class_();
}

