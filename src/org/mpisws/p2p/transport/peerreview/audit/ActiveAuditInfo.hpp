// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/ActiveAuditInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::ActiveAuditInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* target {  };
    bool shouldBeReplayed {  };
    bool isReplaying {  };
    int64_t currentTimeout {  };
    ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* request {  };
    int64_t evidenceSeq {  };
    ::org::mpisws::p2p::transport::peerreview::replay::Verifier* verifier {  };
protected:
    void ctor(::java::lang::Object* target, bool shouldBeReplayed, bool isReplaying, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* request, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::replay::Verifier* verifier);

    // Generated

public:
    ActiveAuditInfo(::java::lang::Object* target, bool shouldBeReplayed, bool isReplaying, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::message::ChallengeMessage* request, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::replay::Verifier* verifier);
protected:
    ActiveAuditInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
