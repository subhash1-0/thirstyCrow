// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/challenge/ChallengeHashPolicy.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/challenge/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/HashPolicy.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::challenge::ChallengeHashPolicy
    : public virtual ::java::lang::Object
    , public virtual ::org::mpisws::p2p::transport::peerreview::history::HashPolicy
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    int8_t flags {  };
    ::java::lang::Object* originator {  };
    bool includeNextCheckpoint {  };
    bool includeNextSendSign {  };

private:
    ::org::mpisws::p2p::transport::util::Serializer* idSerializer {  };
protected:
    void ctor(int8_t flags, ::java::lang::Object* originator, ::org::mpisws::p2p::transport::util::Serializer* idSerializer);

public:
    bool hashEntry(int16_t type, ::int8_tArray* content) override;

    // Generated
    ChallengeHashPolicy(int8_t flags, ::java::lang::Object* originator, ::org::mpisws::p2p::transport::util::Serializer* idSerializer);
protected:
    ChallengeHashPolicy(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
