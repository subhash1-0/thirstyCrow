// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/AckMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <java/lang/Object.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/PeerReviewMessage.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/Evidence.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::AckMessage
    : public virtual ::java::lang::Object
    , public virtual PeerReviewMessage
    , public virtual ::org::mpisws::p2p::transport::peerreview::infostore::Evidence
{

public:
    typedef ::java::lang::Object super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* nodeId {  };
    int64_t sendEntrySeq {  };
    int64_t recvEntrySeq {  };
    ::int8_tArray* hashTopMinusOne {  };
    ::int8_tArray* signature {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* nodeId, int64_t sendEntrySeq, int64_t recvEntrySeq, ::int8_tArray* hashTopMinusOne, ::int8_tArray* signature);

public:
    int16_t getType() override;
    int16_t getEvidenceType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    static /* <Identifier extends RawSerializable> */AckMessage* build(::rice::p2p::commonapi::rawserialization::InputBuffer* sib, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSizeInBytes, int32_t signatureSizeInBytes) /* throws(IOException) */;
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getNodeId();
    virtual int64_t getSendEntrySeq();
    virtual int64_t getRecvEntrySeq();
    virtual ::int8_tArray* getHashTopMinusOne();
    virtual ::int8_tArray* getSignature();

    // Generated
    AckMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* nodeId, int64_t sendEntrySeq, int64_t recvEntrySeq, ::int8_tArray* hashTopMinusOne, ::int8_tArray* signature);
protected:
    AckMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
