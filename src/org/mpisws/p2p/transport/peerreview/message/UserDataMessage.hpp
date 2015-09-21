// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/UserDataMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::UserDataMessage
    : public virtual ::java::lang::Object
    , public virtual PeerReviewMessage
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence
{

public:
    typedef ::java::lang::Object super;
    static constexpr int16_t TYPE { int16_t(16) };

public: /* package */
    int64_t topSeq {  };
    ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle {  };
    ::int8_tArray* hTopMinusOne {  };
    ::int8_tArray* signature {  };
    int32_t relevantLen {  };

private:
    ::int8_tArray* payload {  };
protected:
    void ctor(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen);

public:
    ::java::lang::String* toString() override;
    int16_t getType() override;
    virtual int8_t getRelevantCode();
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static /* <H extends RawSerializable> */UserDataMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize, int32_t sigSize) /* throws(IOException) */;
    virtual int64_t getTopSeq();
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getSenderHandle();
    virtual ::int8_tArray* getHTopMinusOne();
    virtual ::int8_tArray* getSignature();
    virtual int32_t getRelevantLen();
    virtual ::java::nio::ByteBuffer* getPayload();
    virtual ::org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv* getReceiveEvent(::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    virtual ::int8_tArray* getInnerHash(::rice::p2p::commonapi::rawserialization::RawSerializable* myId, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    virtual ::int8_tArray* getInnerHash(::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    virtual ::int8_tArray* getInnerHash(::java::nio::ByteBuffer* header, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    virtual int32_t getPayloadLen();
    int16_t getEvidenceType() override;

    // Generated
    UserDataMessage(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen);
protected:
    UserDataMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
