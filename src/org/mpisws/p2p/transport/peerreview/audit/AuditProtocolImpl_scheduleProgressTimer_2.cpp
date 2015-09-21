// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.java
#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl_scheduleProgressTimer_2.hpp>

#include <org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.hpp>

org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl_scheduleProgressTimer_2::AuditProtocolImpl_scheduleProgressTimer_2(AuditProtocolImpl *AuditProtocolImpl_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , AuditProtocolImpl_this(AuditProtocolImpl_this)
{
    clinit();
    ctor();
}

void org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl_scheduleProgressTimer_2::run()
{
    AuditProtocolImpl_this->makeProgressTimerExpired();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl_scheduleProgressTimer_2::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl_scheduleProgressTimer_2::getClass0()
{
    return class_();
}

