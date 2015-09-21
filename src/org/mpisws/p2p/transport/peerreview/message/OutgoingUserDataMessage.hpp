// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/message/OutgoingUserDataMessage.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/io/fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/UserDataMessage.hpp>
#include <org/mpisws/p2p/transport/MessageRequestHandle.hpp>
#include <java/nio/ByteBuffer.hpp>
#include <rice/p2p/commonapi/rawserialization/RawSerializable.hpp>

struct default_init_tag;

class org::mpisws::p2p::transport::peerreview::message::OutgoingUserDataMessage
    : public UserDataMessage
    , public virtual ::org::mpisws::p2p::transport::MessageRequestHandle
{

public:
    typedef UserDataMessage super;

public: /* package */
    ::org::mpisws::p2p::transport::peerreview::commitment::PeerInfo* pi {  };
    ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe {  };
    ::java::util::Map* options {  };
protected:
    void ctor(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen, ::java::util::Map* options, ::org::mpisws::p2p::transport::peerreview::commitment::PeerInfo* pi, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe);

public:
    ::rice::p2p::commonapi::rawserialization::RawSerializable* getIdentifier() override;
    ::java::nio::ByteBuffer* getMessage() override;
    ::java::util::Map* getOptions() override;
    bool cancel() override;
    virtual void sendComplete();
    virtual void sendFailed(::java::io::IOException* ioe);

    // Generated
    OutgoingUserDataMessage(int64_t topSeq, ::rice::p2p::commonapi::rawserialization::RawSerializable* senderHandle, ::int8_tArray* topMinusOne, ::int8_tArray* sig, ::java::nio::ByteBuffer* message, int32_t relevantlen, ::java::util::Map* options, ::org::mpisws::p2p::transport::peerreview::commitment::PeerInfo* pi, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe);
protected:
    OutgoingUserDataMessage(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
