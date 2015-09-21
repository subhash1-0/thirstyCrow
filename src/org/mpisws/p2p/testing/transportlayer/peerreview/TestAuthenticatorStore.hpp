// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/AuthenticatorStoreTest.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/AuthenticatorStoreImpl.hpp>

struct default_init_tag;

class org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore
    : public ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl
{

public:
    typedef ::org::mpisws::p2p::transport::peerreview::commitment::AuthenticatorStoreImpl super;
protected:
    void ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs);

public:
    virtual void addAuthenticatorToMemory(MyInetSocketAddress* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authenticator);
    virtual void flushAuthenticatorsFromMemory(MyInetSocketAddress* id, int64_t minseq, int64_t maxseq);
    virtual ::java::util::SortedSet* findSubject(MyInetSocketAddress* id);

    // Generated
    TestAuthenticatorStore(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs);
protected:
    TestAuthenticatorStore(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    virtual void addAuthenticatorToMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authenticator) override;
    virtual ::java::util::SortedSet* findSubject(::rice::p2p::commonapi::rawserialization::RawSerializable* id) override;
    virtual void flushAuthenticatorsFromMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq) override;

private:
    virtual ::java::lang::Class* getClass0();
    friend class AuthenticatorStoreTest;
    friend class TestPeerReview;
};
