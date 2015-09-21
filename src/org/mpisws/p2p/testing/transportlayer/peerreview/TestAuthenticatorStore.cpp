// Generated from /pastry-2.1/src/org/mpisws/p2p/testing/transportlayer/peerreview/AuthenticatorStoreTest.java
#include <org/mpisws/p2p/testing/transportlayer/peerreview/TestAuthenticatorStore.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/util/SortedSet.hpp>
#include <org/mpisws/p2p/testing/transportlayer/peerreview/MyInetSocketAddress.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReview.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::TestAuthenticatorStore(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::TestAuthenticatorStore(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs) 
    : TestAuthenticatorStore(*static_cast< ::default_init_tag* >(0))
{
    ctor(peerreview,allowDuplicateSeqs);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::ctor(::org::mpisws::p2p::transport::peerreview::PeerReview* peerreview, bool allowDuplicateSeqs)
{
    super::ctor(peerreview, allowDuplicateSeqs);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::addAuthenticatorToMemory(MyInetSocketAddress* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authenticator)
{
    super::addAuthenticatorToMemory(id, authenticator);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::addAuthenticatorToMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, ::org::mpisws::p2p::transport::peerreview::commitment::Authenticator* authenticator)
{ 
    addAuthenticatorToMemory(dynamic_cast< MyInetSocketAddress* >(id), authenticator);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::flushAuthenticatorsFromMemory(MyInetSocketAddress* id, int64_t minseq, int64_t maxseq)
{
    super::flushAuthenticatorsFromMemory(id, minseq, maxseq);
}

void org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::flushAuthenticatorsFromMemory(::rice::p2p::commonapi::rawserialization::RawSerializable* id, int64_t minseq, int64_t maxseq)
{ 
    flushAuthenticatorsFromMemory(dynamic_cast< MyInetSocketAddress* >(id), minseq, maxseq);
}

java::util::SortedSet* org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::findSubject(MyInetSocketAddress* id)
{
    return java_cast< ::java::util::SortedSet* >(super::findSubject(id));
}

java::util::SortedSet* org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::findSubject(::rice::p2p::commonapi::rawserialization::RawSerializable* id)
{ 
    return findSubject(dynamic_cast< MyInetSocketAddress* >(id));
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.testing.transportlayer.peerreview.TestAuthenticatorStore", 71);
    return c;
}

java::lang::Class* org::mpisws::p2p::testing::transportlayer::peerreview::TestAuthenticatorStore::getClass0()
{
    return class_();
}

