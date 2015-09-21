// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/audit/ActiveInvestigationInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/audit/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::audit::ActiveInvestigationInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    ::java::lang::Object* target {  };
    int64_t since {  };
    int64_t currentTimeout {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom {  };
    ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo {  };
protected:
    void ctor(::java::lang::Object* target, int64_t since, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo);

    // Generated

public:
    ActiveInvestigationInfo(::java::lang::Object* target, int64_t since, int64_t currentTimeout, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authFrom, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authTo);
protected:
    ActiveInvestigationInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
