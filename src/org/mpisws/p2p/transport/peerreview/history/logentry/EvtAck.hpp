// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtAck.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::EvtAck
    : public HistoryEvent
{

public:
    typedef HistoryEvent super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* remoteId {  };
    int64_t ackedSeq {  };
    int64_t hisSeq {  };
    ::int8_tArray* hTopMinusOne {  };
    ::int8_tArray* signature {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* remoteId, int64_t ackedSeq, int64_t hisSeq, ::int8_tArray* topMinusOne, ::int8_tArray* signature);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize) /* throws(IOException) */;

public:
    int16_t getType() override;
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getRemoteId();
    virtual int64_t getAckedSeq();
    virtual int64_t getHisSeq();
    virtual ::int8_tArray* getHTopMinusOne();
    virtual ::int8_tArray* getSignature();

    // Generated
    EvtAck(::rice::p2p::commonapi::rawserialization::RawSerializable* remoteId, int64_t ackedSeq, int64_t hisSeq, ::int8_tArray* topMinusOne, ::int8_tArray* signature);
    EvtAck(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize, int32_t signatureSize);
protected:
    EvtAck(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::nio::ByteBuffer* serialize();

private:
    virtual ::java::lang::Class* getClass0();
};
