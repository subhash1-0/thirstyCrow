// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/PeerInfo.java
#include <org/mpisws/p2p/transport/peerreview/commitment/PeerInfo.hpp>

#include <java/lang/ClassCastException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/util/LinkedList.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::PeerInfo(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::PeerInfo(::rice::p2p::commonapi::rawserialization::RawSerializable* handle) 
    : PeerInfo(*static_cast< ::default_init_tag* >(0))
{
    ctor(handle);
}

constexpr int32_t org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::INITIAL_CHALLENGE_INTERVAL_MICROS;

void org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* handle)
{
    super::ctor();
    this->handle = handle;
    lastTransmit = 0;
    xmitQueue = new ::java::util::LinkedList();
    recvQueue = new ::java::util::LinkedList();
    currentTimeout = 0;
    retransmitsSoFar = 0;
    lastChallenge = -int32_t(1);
    currentChallengeInterval = INITIAL_CHALLENGE_INTERVAL_MICROS;
    isReceiving_ = false;
}

rice::p2p::commonapi::rawserialization::RawSerializable* org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getHandle()
{
    return java_cast< ::rice::p2p::commonapi::rawserialization::RawSerializable* >(handle);
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getLastTransmit()
{
    return lastTransmit;
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getCurrentTimeout()
{
    return currentTimeout;
}

int32_t org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getRetransmitsSoFar()
{
    return retransmitsSoFar;
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getLastChallenge()
{
    return lastChallenge;
}

int64_t org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getCurrentChallengeInterval()
{
    return currentChallengeInterval;
}

java::util::LinkedList* org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getXmitQueue()
{
    return xmitQueue;
}

java::util::LinkedList* org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getRecvQueue()
{
    return recvQueue;
}

bool org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::isReceiving()
{
    return isReceiving_;
}

void org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::clearXmitQueue()
{
    npc(xmitQueue)->clear();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::class_()
{
    static ::java::lang::Class* c = ::class_(u"org.mpisws.p2p.transport.peerreview.commitment.PeerInfo", 55);
    return c;
}

java::lang::Class* org::mpisws::p2p::transport::peerreview::commitment::PeerInfo::getClass0()
{
    return class_();
}

