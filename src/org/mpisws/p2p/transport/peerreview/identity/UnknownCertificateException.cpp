// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/identity/UnknownCertificateException.java
#include <org/mpisws/p2p/transport/peerreview/identity/UnknownCertificateException.hpp>

#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>

org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::UnknownCertificateException(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::UnknownCertificateException(::java::lang::Object* source, ::java::lang::Object* principal) 
    : UnknownCertificateException(*static_cast< ::default_init_tag* >(0))
{
    ctor(source,principal);
}

void org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::ctor(::java::lang::Object* source, ::java::lang::Object* principal)
{
    super::ctor(::java::lang::StringBuilder().append(u"The node "_j)->append(static_cast< ::java::lang::Object* >(source))
        ->append(u" did not have a certificate for "_j)
        ->append(static_cast< ::java::lang::Object* >(principal))
        ->append(u"."_j)->toString());
    this->source = source;
    this->principal = principal;
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::getSource()
{
    return source;
}

java::lang::Object* org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::getPrincipal()
{
    return principal;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.identity.UnknownCertificateException", 72);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::identity::UnknownCertificateException::getClass0()
{
    return class_();
}

