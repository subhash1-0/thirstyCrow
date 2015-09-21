// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/commitment/CommitmentProtocol.java

#pragma once

#include <fwd-pastry-2.1.hpp>
#include <java/nio/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/commitment/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/p2p/commonapi/rawserialization/fwd-pastry-2.1.hpp>
#include <rice/p2p/util/tuples/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/infostore/StatusChangeListener.hpp>

struct org::mpisws::p2p::transport::peerreview::commitment::CommitmentProtocol
    : public virtual ::org::mpisws::p2p::transport::peerreview::infostore::StatusChangeListener
{
    virtual ::org::mpisws::p2p::transport::MessageRequestHandle* handleOutgoingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* target, ::java::nio::ByteBuffer* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual void handleIncomingAck(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::AckMessage* ackMessage, ::java::util::Map* options) /* throws(IOException) */ = 0;
    virtual void handleIncomingMessage(::rice::p2p::commonapi::rawserialization::RawSerializable* source, ::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* msg, ::java::util::Map* options) /* throws(IOException) */ = 0;
    virtual void notifyCertificateAvailable(::rice::p2p::commonapi::rawserialization::RawSerializable* id) = 0;
    virtual ::rice::p2p::util::tuples::Tuple* logMessageIfNew(::org::mpisws::p2p::transport::peerreview::message::UserDataMessage* udm) = 0;
    virtual void setTimeToleranceMillis(int64_t timeToleranceMicros) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
