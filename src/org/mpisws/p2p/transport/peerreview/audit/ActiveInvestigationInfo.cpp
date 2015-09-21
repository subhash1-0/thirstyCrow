// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/ActiveInvestigationInfo.java
#include <org/mpisws/p2p/transport/peerreview/audit/ActiveInvestigationInfo.hpp>

#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/Authenticator.hpp>

org::mpisws::p2p::transport::peerreview::audit::ActiveInvestigationInfo::ActiveInvestigationInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::audit::ActiveInvestigationInfo::ActiveInvestigationInfo(::java::lang::Object* target, int64_t since, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo) 
    : ActiveInvestigationInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(target,since,currentTimeout,authFrom,authTo);
}

void org::mpisws::p2p::transport::peerreview::audit::ActiveInvestigationInfo::ctor(::java::lang::Object* target, int64_t since, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo)
{
    super::ctor();
    this->target = target;
    this->since = since;
    this->currentTimeout = currentTimeout;
    this->authFrom = authFrom;
    this->authTo = authTo;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::ActiveInvestigationInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.audit.ActiveInvestigationInfo", 65);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::ActiveInvestigationInfo::getClass0()
{
    return class_();
}

