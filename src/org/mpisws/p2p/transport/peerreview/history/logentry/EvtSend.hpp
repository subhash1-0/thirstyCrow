// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/history/logentry/EvtSend.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/util/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/history/logentry/HistoryEvent.hpp>
#include <org/mpisws/p2p/transport/peerreview/PeerReviewConstants.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::history::logentry::EvtSend
    : public HistoryEvent
    , public virtual ::org::mpisws::p2p::transport::peerreview::PeerReviewConstants
{

public:
    typedef HistoryEvent super;
    ::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId {  };
    ::java::nio::ByteBuffer* payload {  };
    ::int8_tArray* hash {  };
protected:
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload, int32_t relevantPayload, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    void ctor(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload);
    void ctor(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize) /* throws(IOException) */;

public:
    void serialize(::rice::p2p::commonapi::rawserialization::OutputBuffer* buf) /* throws(IOException) */ override;
    int16_t getType() override;

    // Generated
    EvtSend(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload, int32_t relevantPayload, ::org::mpisws::p2p::transport::peerreview::history::HashProvider* hasher);
    EvtSend(::rice::p2p::commonapi::rawserialization::RawSerializable* receiverId, ::java::nio::ByteBuffer* payload);
    EvtSend(::rice::p2p::commonapi::rawserialization::InputBuffer* buf, ::org::mpisws::p2p::transport::util::Serializer* idSerializer, int32_t hashSize);
protected:
    EvtSend(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    virtual ::java::nio::ByteBuffer* serialize();

private:
    virtual ::java::lang::Class* getClass0();
};
