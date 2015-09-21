// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/KeySerializerImpl.java
#include <org/mpisws/p2p/pki/x509/KeySerializerImpl.hpp>

#include <java/io/IOException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/Key.hpp>
#include <java/security/KeyFactory.hpp>
#include <java/security/PrivateKey.hpp>
#include <java/security/PublicKey.hpp>
#include <java/security/spec/KeySpec.hpp>
#include <java/security/spec/PKCS8EncodedKeySpec.hpp>
#include <java/security/spec/X509EncodedKeySpec.hpp>
#include <javax/crypto/spec/SecretKeySpec.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::pki::x509::KeySerializerImpl::KeySerializerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::pki::x509::KeySerializerImpl::KeySerializerImpl()
    : KeySerializerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::pki::x509::KeySerializerImpl::serialize(::java::security::Key* k, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    if(dynamic_cast< ::java::security::PrivateKey* >(k) != nullptr) {
        npc(buf)->writeByte(KEY_PRIVATE);
    } else if(dynamic_cast< ::java::security::PublicKey* >(k) != nullptr) {
        npc(buf)->writeByte(KEY_PUBLIC);
    } else {
        npc(buf)->writeByte(KEY_SECRET);
    }
    npc(buf)->writeUTF(npc(k)->getFormat());
    npc(buf)->writeUTF(npc(k)->getAlgorithm());
    auto encoded = npc(k)->getEncoded();
    npc(buf)->writeInt(npc(encoded)->length);
    npc(buf)->write(encoded, 0, npc(encoded)->length);
}

java::security::Key* org::mpisws::p2p::pki::x509::KeySerializerImpl::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException, InvalidKeySpecException, NoSuchAlgorithmException, NoSuchProviderException) */
{
    auto keyType = npc(buf)->readByte();
    auto format = npc(buf)->readUTF();
    auto algorithm = npc(buf)->readUTF();
    auto encoded = new ::int8_tArray(npc(buf)->readInt());
    npc(buf)->read(encoded);
    ::java::security::spec::KeySpec* spec = nullptr;
    if(npc(format)->equals(static_cast< ::java::lang::Object* >(u"PKCS#8"_j)) || npc(format)->equals(static_cast< ::java::lang::Object* >(u"PKCS8"_j))) {
        spec = new ::java::security::spec::PKCS8EncodedKeySpec(encoded);
    } else if(npc(format)->equals(static_cast< ::java::lang::Object* >(u"X.509"_j)) || npc(format)->equals(static_cast< ::java::lang::Object* >(u"X509"_j))) {
        spec = new ::java::security::spec::X509EncodedKeySpec(encoded);
    } else if(npc(format)->equals(static_cast< ::java::lang::Object* >(u"RAW"_j))) {
        return new ::javax::crypto::spec::SecretKeySpec(encoded, algorithm);
    }
    if(spec == nullptr) {
        throw new ::java::io::IOException(::java::lang::StringBuilder().append(u"Unknown key type. Type: "_j)->append(keyType)
            ->append(u" Format:"_j)
            ->append(format)
            ->append(u" Algorithm:"_j)
            ->append(algorithm)->toString());
    }
    if(keyType == KEY_PRIVATE) {
        return npc(::java::security::KeyFactory::getInstance(algorithm, u"BC"_j))->generatePrivate(spec);
    }
    return npc(::java::security::KeyFactory::getInstance(algorithm, u"BC"_j))->generatePublic(spec);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::pki::x509::KeySerializerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.pki.x509.KeySerializerImpl", 41);
    return c;
}

java::lang::Class* org::mpisws::p2p::pki::x509::KeySerializerImpl::getClass0()
{
    return class_();
}

