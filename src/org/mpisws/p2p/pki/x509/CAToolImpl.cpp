// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/CAToolImpl.java
#include <org/mpisws/p2p/pki/x509/CAToolImpl.hpp>

#include <java/io/EOFException.hpp>
#include <java/io/File.hpp>
#include <java/io/FileInputStream.hpp>
#include <java/io/FileOutputStream.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/RuntimeException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/math/BigInteger.hpp>
#include <java/security/InvalidKeyException.hpp>
#include <java/security/Key.hpp>
#include <java/security/KeyPair.hpp>
#include <java/security/KeyPairGenerator.hpp>
#include <java/security/KeyStore.hpp>
#include <java/security/PrivateKey.hpp>
#include <java/security/PublicKey.hpp>
#include <java/security/SecureRandom.hpp>
#include <java/security/Security.hpp>
#include <java/security/Signature.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <java/security/spec/AlgorithmParameterSpec.hpp>
#include <java/security/spec/RSAKeyGenParameterSpec.hpp>
#include <java/util/Date.hpp>
#include <javax/security/auth/x500/X500Principal.hpp>
#include <org/bouncycastle/asn1/DEREncodable.hpp>
#include <org/bouncycastle/asn1/x509/X509Extensions.hpp>
#include <org/bouncycastle/jce/provider/BouncyCastleProvider.hpp>
#include <org/bouncycastle/x509/X509V1CertificateGenerator.hpp>
#include <org/bouncycastle/x509/X509V3CertificateGenerator.hpp>
#include <org/bouncycastle/x509/extension/AuthorityKeyIdentifierStructure.hpp>
#include <org/bouncycastle/x509/extension/SubjectKeyIdentifierStructure.hpp>
#include <org/mpisws/p2p/pki/x509/CATool.hpp>
#include <org/mpisws/p2p/pki/x509/X509Serializer.hpp>
#include <org/mpisws/p2p/pki/x509/X509SerializerImpl.hpp>
#include <rice/environment/Environment.hpp>
#include <rice/p2p/util/rawserialization/SimpleInputBuffer.hpp>
#include <rice/p2p/util/rawserialization/SimpleOutputBuffer.hpp>
#include <rice/p2p/util/tuples/Tuple.hpp>
#include <rice/pastry/Id.hpp>
#include <rice/pastry/standard/RandomNodeIdFactory.hpp>
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

org::mpisws::p2p::pki::x509::CAToolImpl::CAToolImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::pki::x509::CAToolImpl::CAToolImpl(::java::security::cert::X509Certificate* cert, ::java::security::KeyPair* caPair) 
    : CAToolImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(cert,caPair);
}

java::security::SecureRandom*& org::mpisws::p2p::pki::x509::CAToolImpl::random()
{
    clinit();
    return random_;
}
java::security::SecureRandom* org::mpisws::p2p::pki::x509::CAToolImpl::random_;

java::lang::String*& org::mpisws::p2p::pki::x509::CAToolImpl::DEFAULT_SIGNATURE_ALGORITHM()
{
    clinit();
    return DEFAULT_SIGNATURE_ALGORITHM_;
}
java::lang::String* org::mpisws::p2p::pki::x509::CAToolImpl::DEFAULT_SIGNATURE_ALGORITHM_;

void org::mpisws::p2p::pki::x509::CAToolImpl::ctor(::java::security::cert::X509Certificate* cert, ::java::security::KeyPair* caPair)
{
    super::ctor();
    this->cert = cert;
    this->keyPair = caPair;
}

java::security::cert::X509Certificate* org::mpisws::p2p::pki::x509::CAToolImpl::getCertificate()
{
    return cert;
}

org::mpisws::p2p::pki::x509::CAToolImpl* org::mpisws::p2p::pki::x509::CAToolImpl::getCATool(::java::lang::String* CN, ::char16_tArray* pw) /* throws(KeyStoreException, NoSuchProviderException, NoSuchAlgorithmException, CertificateException, FileNotFoundException, IOException, UnrecoverableKeyException, InvalidKeyException, IllegalStateException, SignatureException, InvalidAlgorithmParameterException) */
{
    clinit();
    ::java::security::cert::X509Certificate* caCert;
    ::java::security::KeyPair* caPair;
    auto caStoreFile = new ::java::io::File(::java::lang::StringBuilder().append(CN)->append(u"-store"_j)->toString());
    if(npc(caStoreFile)->exists()) {
        auto store = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
        try {
            npc(store)->load(new ::java::io::FileInputStream(caStoreFile), pw);
        } catch (::java::io::EOFException* eof) {
            throw new ::java::lang::RuntimeException(::java::lang::StringBuilder().append(u"Invalid password for "_j)->append(static_cast< ::java::lang::Object* >(caStoreFile))->toString());
        }
        auto pub = java_cast< ::java::security::PublicKey* >(npc(store)->getKey(CA_STORE_PUBLIC_, nullptr));
        auto priv = java_cast< ::java::security::PrivateKey* >(npc(store)->getKey(CA_STORE_PRIVATE_, nullptr));
        caPair = new ::java::security::KeyPair(pub, priv);
        caCert = java_cast< ::java::security::cert::X509Certificate* >(npc(store)->getCertificate(CA_STORE_CERT_));
    } else {
        auto exp = new ::java::util::Date();
        npc(exp)->setYear(npc(exp)->getYear() + int32_t(10));
        auto t = generateNewCA(CN, exp);
        caCert = java_cast< ::java::security::cert::X509Certificate* >(npc(t)->a());
        caPair = java_cast< ::java::security::KeyPair* >(npc(t)->b());
        auto chain = new ::java::security::cert::CertificateArray(int32_t(1));
        chain->set(int32_t(0), caCert);
        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(caCert));
        auto store = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
        npc(store)->load(nullptr, nullptr);
        npc(store)->setKeyEntry(CA_STORE_PRIVATE_, npc(caPair)->getPrivate(), nullptr, chain);
        npc(store)->setKeyEntry(CA_STORE_PUBLIC_, npc(caPair)->getPublic(), nullptr, nullptr);
        npc(store)->setCertificateEntry(CA_STORE_CERT_, caCert);
        npc(store)->store(new ::java::io::FileOutputStream(::java::lang::StringBuilder().append(CN)->append(u"-store"_j)->toString()), pw);
    }
    return new CAToolImpl(caCert, caPair);
}

rice::p2p::util::tuples::Tuple* org::mpisws::p2p::pki::x509::CAToolImpl::generateNewCA(::java::lang::String* CN, ::java::util::Date* expiryDate) /* throws(CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException, InvalidAlgorithmParameterException) */
{
    clinit();
    auto keyPairGen = ::java::security::KeyPairGenerator::getInstance(u"RSA"_j, u"BC"_j);
    npc(keyPairGen)->initialize(static_cast< ::java::security::spec::AlgorithmParameterSpec* >(new ::java::security::spec::RSAKeyGenParameterSpec(int32_t(768), ::java::security::spec::RSAKeyGenParameterSpec::F4())), random_);
    auto caPair = npc(keyPairGen)->generateKeyPair();
    auto cert = generateNewCA(CN, new ::java::util::Date(), expiryDate, 1, caPair, DEFAULT_SIGNATURE_ALGORITHM_);
    return new ::rice::p2p::util::tuples::Tuple(cert, caPair);
}

java::security::cert::X509Certificate* org::mpisws::p2p::pki::x509::CAToolImpl::generateNewCA(::java::lang::String* CN, ::java::util::Date* startDate, ::java::util::Date* expiryDate, int64_t serialNumber, ::java::security::KeyPair* keyPair, ::java::lang::String* signatureAlgorithm) /* throws(CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */
{
    clinit();
    auto certGen = new ::org::bouncycastle::x509::X509V1CertificateGenerator();
    auto dnName = new ::javax::security::auth::x500::X500Principal(::java::lang::StringBuilder().append(u"CN="_j)->append(CN)->toString());
    npc(certGen)->setSerialNumber(::java::math::BigInteger::valueOf(serialNumber));
    npc(certGen)->setIssuerDN(dnName);
    npc(certGen)->setNotBefore(startDate);
    npc(certGen)->setNotAfter(expiryDate);
    npc(certGen)->setSubjectDN(dnName);
    npc(certGen)->setPublicKey(npc(keyPair)->getPublic());
    npc(certGen)->setSignatureAlgorithm(signatureAlgorithm);
    auto cert = npc(certGen)->generate(npc(keyPair)->getPrivate(), u"BC"_j);
    return cert;
}

java::security::cert::X509Certificate* org::mpisws::p2p::pki::x509::CAToolImpl::sign(::java::lang::String* CN, ::java::security::PublicKey* key) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */
{
    auto exp = new ::java::util::Date();
    npc(exp)->setYear(npc(exp)->getYear() + int32_t(1));
    return sign(CN, key, exp, ::java::lang::System::currentTimeMillis());
}

java::security::cert::X509Certificate* org::mpisws::p2p::pki::x509::CAToolImpl::sign(::java::lang::String* CN, ::java::security::PublicKey* publicKey, ::java::util::Date* expiryDate, int64_t serialNumber, ::java::security::cert::X509Certificate* caCert, ::java::security::PrivateKey* privateKey) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */
{
    clinit();
    auto certGen = new ::org::bouncycastle::x509::X509V3CertificateGenerator();
    auto subjectName = new ::javax::security::auth::x500::X500Principal(::java::lang::StringBuilder().append(u"CN="_j)->append(CN)->toString());
    npc(certGen)->setSerialNumber(::java::math::BigInteger::valueOf(serialNumber));
    npc(certGen)->setIssuerDN(npc(caCert)->getSubjectX500Principal());
    npc(certGen)->setNotBefore(new ::java::util::Date());
    npc(certGen)->setNotAfter(expiryDate);
    npc(certGen)->setSubjectDN(subjectName);
    npc(certGen)->setPublicKey(publicKey);
    npc(certGen)->setSignatureAlgorithm(DEFAULT_SIGNATURE_ALGORITHM_);
    npc(certGen)->addExtension(::org::bouncycastle::asn1::x509::X509Extensions::AuthorityKeyIdentifier(), false, static_cast< ::org::bouncycastle::asn1::DEREncodable* >(new ::org::bouncycastle::x509::extension::AuthorityKeyIdentifierStructure(caCert)));
    npc(certGen)->addExtension(::org::bouncycastle::asn1::x509::X509Extensions::SubjectKeyIdentifier(), false, static_cast< ::org::bouncycastle::asn1::DEREncodable* >(new ::org::bouncycastle::x509::extension::SubjectKeyIdentifierStructure(publicKey)));
    auto cert = npc(certGen)->generate(privateKey, u"BC"_j);
    return cert;
}

java::security::cert::X509Certificate* org::mpisws::p2p::pki::x509::CAToolImpl::sign(::java::lang::String* CN, ::java::security::PublicKey* publicKey, ::java::util::Date* expiryDate, int64_t serialNumber) /* throws(CertificateParsingException, CertificateEncodingException, InvalidKeyException, IllegalStateException, NoSuchProviderException, NoSuchAlgorithmException, SignatureException) */
{
    return sign(CN, publicKey, expiryDate, serialNumber, cert, npc(keyPair)->getPrivate());
}

java::lang::String*& org::mpisws::p2p::pki::x509::CAToolImpl::CA_STORE_PRIVATE()
{
    clinit();
    return CA_STORE_PRIVATE_;
}
java::lang::String* org::mpisws::p2p::pki::x509::CAToolImpl::CA_STORE_PRIVATE_;

java::lang::String*& org::mpisws::p2p::pki::x509::CAToolImpl::CA_STORE_PUBLIC()
{
    clinit();
    return CA_STORE_PUBLIC_;
}
java::lang::String* org::mpisws::p2p::pki::x509::CAToolImpl::CA_STORE_PUBLIC_;

java::lang::String*& org::mpisws::p2p::pki::x509::CAToolImpl::CA_STORE_CERT()
{
    clinit();
    return CA_STORE_CERT_;
}
java::lang::String* org::mpisws::p2p::pki::x509::CAToolImpl::CA_STORE_CERT_;

void org::mpisws::p2p::pki::x509::CAToolImpl::main(::java::lang::StringArray* args) /* throws(Exception) */
{
    clinit();
    auto pw = new ::char16_tArray(int32_t(0));
    auto caName = u"MyCA"_j;
    ::java::lang::String* CN = nullptr;
    auto test = false;
    auto store = false;
    for (auto c = int32_t(0); c < npc(args)->length; c++) {
        if(npc((*args)[c])->equalsIgnoreCase(u"-p"_j)) {
            pw = npc((*args)[c + int32_t(1)])->toCharArray_();
        } else if(npc((*args)[c])->equalsIgnoreCase(u"-ca"_j)) {
            caName = (*args)[c + int32_t(1)];
        } else if(npc((*args)[c])->equalsIgnoreCase(u"-cn"_j)) {
            CN = (*args)[c + int32_t(1)];
        } else if(npc((*args)[c])->equalsIgnoreCase(u"-test"_j)) {
            test = true;
        } else if(npc((*args)[c])->equalsIgnoreCase(u"-store"_j)) {
            store = true;
        }
    }
    ::rice::environment::Environment* env = nullptr;
    if(CN == nullptr) {
        env = new ::rice::environment::Environment();
        auto id = (new ::rice::pastry::standard::RandomNodeIdFactory(env))->generateNodeId();
        CN = npc(id)->toStringFull();
    }
    CATool* caTool = getCATool(caName, pw);
    auto keyPairGen = ::java::security::KeyPairGenerator::getInstance(u"RSA"_j, u"BC"_j);
    npc(keyPairGen)->initialize(static_cast< ::java::security::spec::AlgorithmParameterSpec* >(new ::java::security::spec::RSAKeyGenParameterSpec(int32_t(768), ::java::security::spec::RSAKeyGenParameterSpec::F4())), random_);
    auto pair = npc(keyPairGen)->generateKeyPair();
    auto cert = npc(caTool)->sign(CN, npc(pair)->getPublic());
    if(store) {
        auto clientStore = ::java::security::KeyStore::getInstance(u"UBER"_j, u"BC"_j);
        npc(clientStore)->load(nullptr, nullptr);
        npc(clientStore)->setKeyEntry(u"private"_j, npc(pair)->getPrivate(), npc(u""_j)->toCharArray_(), new ::java::security::cert::CertificateArray({static_cast< ::java::security::cert::Certificate* >(cert)}));
        npc(clientStore)->setCertificateEntry(u"cert"_j, npc(caTool)->getCertificate());
        auto fileName = ::java::lang::StringBuilder().append(CN)->append(u".store"_j)->toString();
        auto fos = new ::java::io::FileOutputStream(fileName);
        npc(clientStore)->store(fos, npc(u""_j)->toCharArray_());
        npc(fos)->close();
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Stored to "_j)->append(fileName)->toString());
    }
    if(test) {
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Cert Type:"_j)->append(npc(cert)->getType())
            ->append(u" len:"_j)
            ->append(npc(npc(cert)->getEncoded())->length)->toString());
        X509Serializer* serializer = new X509SerializerImpl();
        auto sob = new ::rice::p2p::util::rawserialization::SimpleOutputBuffer();
        npc(serializer)->serialize(npc(caTool)->getCertificate(), sob);
        auto sib = new ::rice::p2p::util::rawserialization::SimpleInputBuffer(npc(sob)->getBytes());
        auto caCert = java_cast< ::java::security::cert::X509Certificate* >(npc(serializer)->deserialize(sib));
        npc(cert)->verify(npc(caCert)->getPublicKey());
        npc(::java::lang::System::out())->println(u"cert verified."_j);
        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(caCert));
        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(cert));
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(npc(pair)->getPublic())->getFormat())->append(u" "_j)
            ->append(npc(npc(pair)->getPublic())->getAlgorithm())->toString());
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(npc(npc(pair)->getPrivate())->getFormat())->append(u" "_j)
            ->append(npc(npc(pair)->getPrivate())->getAlgorithm())->toString());
        auto signer = ::java::security::Signature::getInstance(DEFAULT_SIGNATURE_ALGORITHM_, u"BC"_j);
        npc(signer)->initSign(npc(pair)->getPrivate());
        auto msg = new ::int8_tArray(int32_t(400));
        npc(random_)->nextBytes(msg);
        npc(signer)->update(msg);
        auto signature = npc(signer)->sign();
        npc(::java::lang::System::out())->println(static_cast< ::java::lang::Object* >(signer));
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"Signature length:"_j)->append(npc(signature)->length)->toString());
        auto verifier = ::java::security::Signature::getInstance(DEFAULT_SIGNATURE_ALGORITHM_, u"BC"_j);
        npc(verifier)->initVerify(static_cast< ::java::security::cert::Certificate* >(cert));
        npc(verifier)->update(msg);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"verified:"_j)->append(npc(verifier)->verify(signature))->toString());
        if(true) {
            auto kpg = ::java::security::KeyPairGenerator::getInstance(u"RSA"_j, u"BC"_j);
            npc(kpg)->initialize(static_cast< ::java::security::spec::AlgorithmParameterSpec* >(new ::java::security::spec::RSAKeyGenParameterSpec(int32_t(768), ::java::security::spec::RSAKeyGenParameterSpec::F4())), random_);
            auto bogusPair = npc(kpg)->generateKeyPair();
            try {
                npc(cert)->verify(npc(bogusPair)->getPublic());
                npc(::java::lang::System::out())->println(u"WARNING!  Bogus key verified!!!"_j);
            } catch (::java::security::InvalidKeyException* se) {
                npc(::java::lang::System::out())->println(u"bogus didn't verify."_j);
            }
            auto bogusVerifier = ::java::security::Signature::getInstance(DEFAULT_SIGNATURE_ALGORITHM_, u"BC"_j);
            npc(bogusVerifier)->initVerify(npc(bogusPair)->getPublic());
            npc(bogusVerifier)->update(msg);
            npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"bogus verify: "_j)->append(npc(bogusVerifier)->verify(signature))->toString());
        }
        npc(verifier)->update(msg);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"verified 2:"_j)->append(npc(verifier)->verify(signature))->toString());
        (*msg)[int32_t(0)]++;
        npc(verifier)->update(msg);
        npc(::java::lang::System::out())->println(::java::lang::StringBuilder().append(u"verified (should fail):"_j)->append(npc(verifier)->verify(signature))->toString());
    }
    if(env != nullptr)
        npc(env)->destroy();

}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::pki::x509::CAToolImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.pki.x509.CAToolImpl", 34);
    return c;
}

void org::mpisws::p2p::pki::x509::CAToolImpl::clinit()
{
struct string_init_ {
    string_init_() {
    DEFAULT_SIGNATURE_ALGORITHM_ = u"SHA1withRSA"_j;
    CA_STORE_PRIVATE_ = u"private"_j;
    CA_STORE_PUBLIC_ = u"public"_j;
    CA_STORE_CERT_ = u"cert"_j;
    }
};

    static string_init_ string_init_instance;

    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        {
            ::java::security::Security::addProvider(new ::org::bouncycastle::jce::provider::BouncyCastleProvider());
        }
        random_ = new ::java::security::SecureRandom();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* org::mpisws::p2p::pki::x509::CAToolImpl::getClass0()
{
    return class_();
}

