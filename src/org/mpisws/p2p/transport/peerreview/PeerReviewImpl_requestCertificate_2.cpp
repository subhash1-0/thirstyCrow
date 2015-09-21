// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/PeerReviewImpl.java
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl_requestCertificate_2.hpp>

#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/security/cert/X509Certificate.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewImpl.hpp>
#include <rice/environment/logging/Logger.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2::PeerReviewImpl_requestCertificate_2(PeerReviewImpl *PeerReviewImpl_this, ::rice::p2p::commonapi::rawserialization::RawSerializable* certHolder, ::rice::p2p::commonapi::rawserialization::RawSerializable* source)
    : super(*static_cast< ::default_init_tag* >(0))
    , PeerReviewImpl_this(PeerReviewImpl_this)
    , certHolder(certHolder)
    , source(source)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2::receiveException(::java::lang::Exception* exception)
{
    if(npc(PeerReviewImpl_this->logger)->level <= ::rice::environment::logging::Logger::WARNING)
        npc(PeerReviewImpl_this->logger)->logException(::java::lang::StringBuilder().append(u"error receiving cert for "_j)->append(static_cast< ::java::lang::Object* >(certHolder))
            ->append(u" from "_j)
            ->append(static_cast< ::java::lang::Object* >(source))->toString(), exception);

}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2::receiveResult(::java::security::cert::X509Certificate* result)
{
    PeerReviewImpl_this->notifyCertificateAvailable(certHolder);
}

void org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2::receiveResult(::java::lang::Object* result)
{ 
    receiveResult(dynamic_cast< ::java::security::cert::X509Certificate* >(result));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::PeerReviewImpl_requestCertificate_2::getClass0()
{
    return class_();
}

