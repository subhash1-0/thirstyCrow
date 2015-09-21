// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/AuditProtocolImpl.java

#pragma once

#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <rice/selector/TimerTask.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::AuditProtocolImpl_makeProgressTimerExpired_4
    : public ::rice::selector::TimerTask
{

public:
    typedef ::rice::selector::TimerTask super;
    void run() override;

    // Generated
    AuditProtocolImpl_makeProgressTimerExpired_4(AuditProtocolImpl *AuditProtocolImpl_this);
    static ::java::lang::Class *class_();
    AuditProtocolImpl *AuditProtocolImpl_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AuditProtocolImpl;
    friend class AuditProtocolImpl_AuditProtocolImpl_1;
    friend class AuditProtocolImpl_scheduleProgressTimer_2;
    friend class AuditProtocolImpl_startAuditTimer_3;
};
