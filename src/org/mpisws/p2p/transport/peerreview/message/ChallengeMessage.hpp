// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/ChallengeMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::ChallengeMessage
    : public virtual ::java::lang::Object
    , public virtual PeerReviewMessage
{

public:
    typedef ::java::lang::Object super;

private:
    static int16_t TYPE_;

public:
    ::rice::p2p::commonapi::rawserialization::RawSerializable* originator {  };
    int64_t evidenceSeq {  };
    ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* challenge {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* challenge);

public:
    int16_t getType() override;
    virtual int16_t getChallengeType();
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evidenceSerializer) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* getChallenge();

    // Generated
    ChallengeMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* originator, int64_t evidenceSeq, ::org::mpisws::p2p::transport::peerreview::infostore::Evidence* challenge);
    ChallengeMessage(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, ::org::mpisws::p2p::transport::peerreview::infostore::EvidenceSerializer* evidenceSerializer);
protected:
    ChallengeMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static int16_t& TYPE();

private:
    virtual ::java::lang::Class* getClass0();
};
