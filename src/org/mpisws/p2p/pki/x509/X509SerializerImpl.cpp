// Generated from /pastry-2.1/src/org/mpisws/p2p/pki/x509/X509SerializerImpl.java
#include <org/mpisws/p2p/pki/x509/X509SerializerImpl.hpp>

#include <java/io/ByteArrayInputStream.hpp>
#include <java/io/IOException.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/security/cert/Certificate.hpp>
#include <java/security/cert/CertificateEncodingException.hpp>
#include <java/security/cert/CertificateException.hpp>
#include <java/security/cert/CertificateFactory.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <rice/p2p/commonapi/rawserialization/InputBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/OutputBuffer.hpp>
#include <Array.hpp>

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

org::mpisws::p2p::pki::x509::X509SerializerImpl::X509SerializerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::pki::x509::X509SerializerImpl::X509SerializerImpl()  /* throws(CertificateException, NoSuchProviderException) */
    : X509SerializerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void org::mpisws::p2p::pki::x509::X509SerializerImpl::ctor() /* throws(CertificateException, NoSuchProviderException) */
{
    super::ctor();
    certificatefactory = ::java::security::cert::CertificateFactory::getInstance(u"X.509"_j, u"BC"_j);
}

void org::mpisws::p2p::pki::x509::X509SerializerImpl::serialize(::java::security::cert::X509Certificate* cert, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */
{
    try {
        auto encoded = npc(cert)->getEncoded();
        npc(buf)->writeInt(npc(encoded)->length);
        npc(buf)->write(encoded, 0, npc(encoded)->length);
    } catch (::java::security::cert::CertificateEncodingException* cee) {
        auto ioe = new ::java::io::IOException(npc(cee)->getLocalizedMessage());
        npc(ioe)->initCause(cee);
        throw ioe;
    }
}

void org::mpisws::p2p::pki::x509::X509SerializerImpl::serialize(::java::lang::Object* i, ::rice::p2p::commonapi::rawserialization::OutputBuffer* buf)
{ 
    serialize(dynamic_cast< ::java::security::cert::X509Certificate* >(i), buf);
}

java::security::cert::X509Certificate* org::mpisws::p2p::pki::x509::X509SerializerImpl::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    try {
        auto encoded = new ::int8_tArray(npc(buf)->readInt());
        npc(buf)->read(encoded);
        auto bytearrayinputstream = new ::java::io::ByteArrayInputStream(encoded);
        return java_cast< ::java::security::cert::X509Certificate* >(npc(certificatefactory)->generateCertificate(bytearrayinputstream));
    } catch (::java::security::cert::CertificateException* ce) {
        auto ioe = new ::java::io::IOException(npc(ce)->getLocalizedMessage());
        npc(ioe)->initCause(ce);
        throw ioe;
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::pki::x509::X509SerializerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.pki.x509.X509SerializerImpl", 42);
    return c;
}

java::lang::Class* org::mpisws::p2p::pki::x509::X509SerializerImpl::getClass0()
{
    return class_();
}

