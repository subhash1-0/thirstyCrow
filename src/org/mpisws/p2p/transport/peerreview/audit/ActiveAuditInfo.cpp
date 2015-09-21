// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/ActiveAuditInfo.java
#include <org/mpisws/p2p/transport/peerreview/audit/ActiveAuditInfo.hpp>

#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/Verifier.hpp>

org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo::ActiveAuditInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo::ActiveAuditInfo(::java::lang::Object* target, bool shouldBeReplayed, bool isReplaying, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* request, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::replay::Verifier* verifier) 
    : ActiveAuditInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,shouldBeReplayed,isReplaying,currentTimeout,request,evidenceSeq,verifier);
}

void org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo::ctor(::java::lang::Object* target, bool shouldBeReplayed, bool isReplaying, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* request, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::replay::Verifier* verifier)
{
    super::ctor();
    this->target = target;
    this->shouldBeReplayed = shouldBeReplayed;
    this->isReplaying = isReplaying;
    this->currentTimeout = currentTimeout;
    this->request = request;
    this->evidenceSeq = evidenceSeq;
    this->verifier = verifier;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.ActiveAuditInfo", 57);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo::getClass0()
{
    return class_();
}

