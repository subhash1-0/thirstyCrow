// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializerImpl.java
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorSerializerImpl.hpp>

#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>

org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::AuthenticatorSerializerImpl(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::AuthenticatorSerializerImpl(int32_t hashLength, int32_t signatureLength) 
    : AuthenticatorSerializerImpl(*static_cast< ::default_init_tag* >(0))
{
    ctor(hashLength,signatureLength);
}

void org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::ctor(int32_t hashLength, int32_t signatureLength)
{
    super::ctor();
    this->hashLength = hashLength;
    this->signatureLength = signatureLength;
}

org::mpisws::p2p::transport::peerreview::commitment::Authenticator* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::deserialize(::rice::p2p::commonapi::rawserialization::InputBuffer* buf) /* throws(IOException) */
{
    return new Authenticator(buf, hashLength, signatureLength);
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::getSerializedSize()
{
    return int32_t(8) + hashLength + signatureLength;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.AuthenticatorSerializerImpl", 74);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorSerializerImpl::getClass0()
{
    return class_();
}

