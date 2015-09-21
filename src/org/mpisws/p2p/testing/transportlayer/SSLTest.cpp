// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/SSLTest.java
#include <org/mpisws/p2p/testing/transportlayer/SSLTest.hpp>

#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/net/InetAddress.hpp>
#include <java/net/InetSocketAddress.hpp>
#include <java/security/KeyPair.hpp>
#include <java/security/KeyPairGenerator.hpp>
#include <java/security/KeyStore.hpp>
#include <java/security/PrivateKey.hpp>
#include <java/security/SecureRandom.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <java/security/spec/AlgorithmParameterSpec.hpp>
#include <java/security/spec/RSAKeyGenParameterSpec.hpp>
#include <java/util/Map.hpp>
#include <org/mpisws/p2p/pki/x509/CATool.hpp>
#include <org/mpisws/p2p/pki/x509/CAToolImpl.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SSLTest_main_1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/SSLTest_main_2.hpp>
#include <org/mpisws/p2p/transport/SocketCallback.hpp>
#include <org/mpisws/p2p/transport/TransportLayerCallback.hpp>
#include <org/mpisws/p2p/transport/ssl/SSLTransportLayerImpl.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayer.hpp>
#include <org/mpisws/p2p/transport/wire/WireTransportLayerImpl.hpp>
#include <rice/environment/Environment.hpp>
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
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang

    namespace security
    {
        namespace cert
        {
typedef ::SubArray< ::java::security::cert::Certificate, ::java::lang::ObjectArray, ::java::io::SerializableArray > CertificateArray;
        } // cert
    } // security
} // java

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::SSLTest::SSLTest(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::SSLTest::SSLTest()
    : SSLTest(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::testing::transportlayer::SSLTest::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto addr = ::java::net::InetAddress::getLocalHost();
    auto rootEnv = new ::rice::environment::Environment();
    auto sRandom = new ::java::security::SecureRandom();
    ::org::mpisws::p2p::pki::x509::CATool* caTool = ::org::mpisws::p2p::pki::x509::CAToolImpl::getCATool(u"MyCA"_j, npc(u"foo"_j)->toCharArray_());
    auto keyPairGen = ::java::security::KeyPairGenerator::getInstance(u"RSA"_j, u"BC"_j);
    npc(keyPairGen)->initialize(static_cast< ::java::security::spec::AlgorithmParameterSpec* >(new ::java::security::spec::RSAKeyGenParameterSpec(int32_t(768), ::java::security::spec::RSAKeyGenParameterSpec::F4())), sRandom);
    ::org::mpisws::p2p::pki::x509::CATool* bogus = ::org::mpisws::p2p::pki::x509::CAToolImpl::getCATool(u"Bogus"_j, npc(u"bar"_j)->toCharArray_());
    auto aliceEnv = npc(rootEnv)->cloneEnvironment(u"alice"_j);
    auto aliceAddr = new ::java::net::InetSocketAddress(addr, int32_t(9001));
    auto alicePair = npc(keyPairGen)->generateKeyPair();
    auto aliceCert = npc(caTool)->sign(u"alice"_j, npc(alicePair)->getPublic());
    auto aliceStore = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
    npc(aliceStore)->load(nullptr, nullptr);
    npc(aliceStore)->setKeyEntry(u"private"_j, npc(alicePair)->getPrivate(), npc(u""_j)->toCharArray_(), new ::java::security::cert::CertificateArray({static_cast< ::java::security::cert::Certificate* >(aliceCert)}));
    npc(aliceStore)->setCertificateEntry(u"cert"_j, npc(caTool)->getCertificate());
    ::org::mpisws::p2p::transport::wire::WireTransportLayer* aliceWire = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(aliceAddr, aliceEnv, nullptr);
    auto aliceSSL = new ::org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl(aliceWire, aliceStore, aliceStore, aliceEnv);
    auto bobEnv = npc(rootEnv)->cloneEnvironment(u"bob"_j);
    auto bobAddr = new ::java::net::InetSocketAddress(addr, int32_t(9002));
    auto bobPair = npc(keyPairGen)->generateKeyPair();
    auto bobCert = npc(caTool)->sign(u"bob"_j, npc(bobPair)->getPublic());
    auto bobStore = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
    npc(bobStore)->load(nullptr, nullptr);
    npc(bobStore)->setKeyEntry(u"private"_j, npc(bobPair)->getPrivate(), npc(u""_j)->toCharArray_(), new ::java::security::cert::CertificateArray({static_cast< ::java::security::cert::Certificate* >(bobCert)}));
    npc(bobStore)->setCertificateEntry(u"cert"_j, npc(caTool)->getCertificate());
    ::org::mpisws::p2p::transport::wire::WireTransportLayer* bobWire = new ::org::mpisws::p2p::transport::wire::WireTransportLayerImpl(bobAddr, bobEnv, nullptr);
    auto bobSSL = new ::org::mpisws::p2p::transport::ssl::SSLTransportLayerImpl(bobWire, bobStore, bobStore, bobEnv);
    npc(aliceSSL)->setCallback(static_cast< ::org::mpisws::p2p::transport::TransportLayerCallback* >(new SSLTest_main_1()));
    npc(bobSSL)->openSocket(static_cast< ::java::lang::Object* >(aliceAddr), static_cast< ::org::mpisws::p2p::transport::SocketCallback* >(new SSLTest_main_2()), static_cast< ::java::util::Map* >(nullptr));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.SSLTest", 45);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::SSLTest::getClass0()
{
    return class_();
}

