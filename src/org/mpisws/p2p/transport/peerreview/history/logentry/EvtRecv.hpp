// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtRecv.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::EvtRecv
    : public HistoryEvent
{

public:
    typedef HistoryEvent super;

public: /* package */
    ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle {  };
    int64_t senderSeq {  };
    ::int8_tArray* payload {  };
    ::int8_tArray* hash {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload);
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload, int32_t relevantLen, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);

public:
    int16_t getType() override;
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    virtual ::rice::p2p::commonapi::rawserialization::RawSerializable* getSenderHandle();
    virtual int64_t getSenderSeq();
    virtual ::int8_tArray* getPayload();
    virtual ::int8_tArray* getHash();

    // Generated
    EvtRecv(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload);
    EvtRecv(::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, int64_t topSeq, ::java::nio::ByteBuffer* payload, int32_t relevantLen, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    EvtRecv(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* serializer, int32_t hashSize);
protected:
    EvtRecv(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::nio::ByteBuffer* serialize();

private:
    virtual ::java::lang::Class* getClass0();
};
