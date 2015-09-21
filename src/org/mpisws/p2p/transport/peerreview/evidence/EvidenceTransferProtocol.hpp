// Generated from /pastry-2.1/src/org/mpisws/p2p/transport/peerreview/evidence/EvidenceTransferProtocol.java

#pragma once

#include <java/lang/fwd-pastry-2.1.hpp>
#include <java/util/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/evidence/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/message/fwd-pastry-2.1.hpp>
#include <rice/fwd-pastry-2.1.hpp>
#include <org/mpisws/p2p/transport/peerreview/WitnessListener.hpp>

struct org::mpisws::p2p::transport::peerreview::evidence::EvidenceTransferProtocol
    : public virtual ::org::mpisws::p2p::transport::peerreview::WitnessListener
{
    virtual void sendMessageToWitnesses(::java::lang::Object* subject, ::org::mpisws::p2p::transport::peerreview::message::PeerReviewMessage* message, ::org::mpisws::p2p::transport::MessageCallback* deliverAckToMe, ::java::util::Map* options) = 0;
    virtual void requestWitnesses(::java::util::Collection* subjects, ::rice::Continuation* c) = 0;
    virtual void sendEvidence(::java::lang::Object* source, ::java::lang::Object* id) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
