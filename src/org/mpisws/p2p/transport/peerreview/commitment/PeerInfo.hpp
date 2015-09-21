// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/PeerInfo.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::commitment::PeerInfo
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;
    static constexpr int32_t INITIAL_CHALLENGE_INTERVAL_MICROS { int32_t(30000000) };

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* handle {  };
    int32_t numOutstandingPackets {  };
    int64_t lastTransmit {  };
    int64_t currentTimeout {  };
    int32_t retransmitsSoFar {  };
    int64_t lastChallenge {  };
    int64_t currentChallengeInterval {  };
    ::java::util::LinkedList* xmitQueue {  };
    ::java::util::LinkedList* recvQueue {  };
    bool isReceiving_ {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* handle);

public:
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getHandle();
    virtual int64_t getLastTransmit();
    virtual int64_t getCurrentTimeout();
    virtual int32_t getRetransmitsSoFar();
    virtual int64_t getLastChallenge();
    virtual int64_t getCurrentChallengeInterval();
    virtual ::java::util::LinkedList* getXmitQueue();
    virtual ::java::util::LinkedList* getRecvQueue();
    virtual bool isReceiving();
    virtual void clearXmitQueue();

    // Generated
    PeerInfo(::rice::p2p::commonapi::rawserialization::RawSerializable* handle);
protected:
    PeerInfo(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
