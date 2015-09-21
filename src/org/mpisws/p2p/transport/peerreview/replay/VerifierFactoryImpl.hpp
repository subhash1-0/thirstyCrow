// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/replay/VerifierFactoryImpl.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/fwd-pastry-2.1.hpp>
#include <rice/environment/logging/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/replay/VerifierFactory.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::replay::VerifierFactoryImpl
    : public virtual ::java::lang::Object
    , public virtual VerifierFactory
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview {  };
    ::rice::environment::logging::Logger* logger {  };
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview);

public:
    Verifier* getVerifier(::org::mpisws::p2p::transport::peerreview::history::SecureHistory* history, ::rice::p2p::commonapi::rawserialization::RawSerializable* localHandle, int64_t firstEntryToReplay, int64_t initialTime, ::java::lang::Object* extInfo) /* throws(IOException) */ override;

    // Generated
    VerifierFactoryImpl(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview);
protected:
    VerifierFactoryImpl(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
